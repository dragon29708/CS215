#include <iostream>
#include <iomanip>
#include "userint.h"

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
// initializes the objects (data members) used by the class
userint::userint() {
	// read the starting student, catalog and schedule data
	// into the list objects
	stuList.read();
	cat.read();
	scList.read();

	// configure the main menu object
	mainMenu.setTitle("===== Welcome to the new Link Blue! =====");
	mainMenu.setErrorMessage("Invalid option! Try again!");
	mainMenu.addOption('C', "Print course catalog");
	mainMenu.addOption('L', "Print student list");
	mainMenu.addOption('S', "Print all schedules");
	mainMenu.addOption('R', "Register student");
	mainMenu.addOption('X', "Exit");

	// configure the registration menu object
	regMenu.setTitle("Student Registration");
	regMenu.setErrorMessage("Invalid option! Try again!");
	regMenu.addOption('A', "Add course");
	regMenu.addOption('D', "Drop course");
	regMenu.addOption('C', "Print course catalog");
	regMenu.addOption('X', "Exit");
} // constructor()

//-------------------------------------------------------------------
//                                 go
//-------------------------------------------------------------------
// this is the "main" function of the Student Registration System
void userint::go() {
	char opt = ' ';
	while (opt != 'X') {
		opt = mainMenu.doMenu();
		switch (opt) {
		case 'C': cat.print(); break;
		case 'L': stuList.print(); break;
		case 'S': scList.print(); break;
		case 'R': registerStudent(); break;
		case 'X': scList.write();
			cout << "Schedule data written to output file.\n";
		}
	}
	cout << "Thank you for using New Link Blue!\n";
} // go()

//-------------------------------------------------------------------
//                         printSchedule
//-------------------------------------------------------------------
// Print the given schedule, along with data from the student object
// Sum and print total number of credit hours for all courses
void userint::printSchedule(student stu, schedule sched) {
	// print student information at the top of the schedule
	int totHours = 0;
	cout << "\n------------------------------------------\n";
	stu.print();
	cout << "------------------------------------------\n";

	// for each course registered:
	for (int i = 0; i < sched.getNumCourses(); i++) {
		string crsId = sched.getCourseId(i);	// get course ID from the schedule
		int    crsNdx = cat.search(crsId);      // find the Course in the Catalog
		course crs = cat.getCourse(crsNdx);     // get a copy of the Course data from the cat
		totHours += crs.getCreditHours();             // add up number of credits for all courses
		crs.print();                            // print a line with course info
	}
	cout << "Total hours: " << totHours << endl << endl;
} // printSchedule()

//-------------------------------------------------------------------
//                         addCourse
//-------------------------------------------------------------------
// The user selected "ADD COURSE" from the registration menu
void userint::addCourse(student stu, schedule& sched) {
	// ask the user for the course ID
	string crsId;
	cout << "Enter course id: ";
	cin >> crsId;

	// find the course in the catalog
	int cndx = cat.search(crsId);
	if (cndx == CRS_NOT_FOUND)
		cout << "No course with id=" << crsId << " in the catalog.\n";
	else {
		// add the course to the schedule
		int rc = sched.addCourse(crsId);
		if (rc == 0)
			cout << "Course added.\n";
		else
			cout << "Max number of courses exceeded for this student.\n";
	}
} // addCourse()

//-------------------------------------------------------------------
//                         dropCourse
//-------------------------------------------------------------------
// The user selected "DROP COURSE" from the registration menu
void userint::dropCourse(student stu, schedule & sched) {
	// ask the user for the course id of the course to drop
	string crsId;
	cout << "Enter course id: ";
	cin >> crsId;

	// drop the course from the schedule object
	int rc = sched.dropCourse(crsId);
	if (rc == 0)
		cout << "Course dropped.\n";
	else
		cout << "No course id=" << crsId << " on the student schedule.\n";
} // dropCourse()


//-------------------------------------------------------------------
//                         registerStudent
//-------------------------------------------------------------------
void userint::registerStudent() {
	// ask the user for the student id
	string stuId;
	cout << "Enter student id: ";
	cin >> stuId;

	// search the student list for the id given
	student stu = stuList.search(stuId);
	if (stu.getId() == "") {
		cout << "No student with that id.\n\n";
		return;
	}

	// get the student's schedule from the schedule list
	// if the student hasn't registered yet,
	// getSchedule() will return an empty schedule
	schedule sched = scList.getSchedule(stuId);
	if (sched.getStudentId() == "") // new schedule
		sched.setStudentId(stuId);

	// allow the user to repeat drop/add
	char opt;
	do {
		printSchedule(stu, sched);
		opt = regMenu.doMenu();
		switch (opt) {
		case 'A': addCourse(stu, sched); break;
		case 'D': dropCourse(stu, sched); break;
		case 'C': cat.print();
		case 'X': scList.addSchedule(sched);
			// (commented out case 'X' since it was wrongly appending to my schedList)
			// if the student doesn't already have a schedule,
			//     the sched will be added to the list;
			// otherwise, the schedule will be updated in the list
		}
	} while (opt != 'X');
} // registerStudent()
