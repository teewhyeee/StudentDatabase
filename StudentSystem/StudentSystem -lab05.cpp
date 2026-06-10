#include "Student.h"

int main() {

	srand(time(0));

	int count = 0;
	SillyStudent sillyStudents[MAX_STUDENTS];
	double grades[MAX_STUDENTS][NUM_ASSIGNMENTS];
	int chooseWisely;

	allStudents(sillyStudents, count);
	generatingGreatGrades(grades, count);
	calculatingAverage(grades, sillyStudents, count);

	do {
		menu();

		cout << "Choose an option, please... ";
		cin >> chooseWisely;

		switch (chooseWisely) {
		case 1:

			displayEveryStudentInfo(grades, sillyStudents, count);

			break;

		case 2:
			cout << endl << "===== You chose to UPDATE an Assignment =====" << endl << endl;
			updateGreatAssignments(grades, sillyStudents, count);

			break;

		case 3:
			cout << endl << "===== You chose to ADD a Student =====" << endl;

			addingStudents(sillyStudents, count, grades);
			calculatingAverage(grades, sillyStudents, count);
			displayEveryStudentInfo(grades, sillyStudents, count);
			break;

		case 4:
			savingStudents(sillyStudents, count);
			break;

		case 5:
			search(grades, sillyStudents, count);
			break;

		case 6:
			cout << endl << "See ya!" << endl;
			break;

		default:
			cout << endl << "You're inputting something incorrect..." << endl;


		} // end of switch

	} while (chooseWisely != 6);


	return 0;
}