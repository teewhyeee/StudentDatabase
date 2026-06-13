#include "Student.h"

int main() {

	int count = 0;
	SillyStudent sillyStudents[MAX_STUDENTS];
	int chooseWisely;

	loadAllStudents(sillyStudents, count);
	calculatingAllAverages(sillyStudents, count);

	do {
		menu();

		cout << "Choose an option, please... ";
		cin >> chooseWisely;

		switch (chooseWisely) {
		case 1:

			displayEveryStudentInfo(sillyStudents, count);

			break;

		case 2:
			searchByCourse(sillyStudents, count);
			break;

		case 3:
			showAssignmentAverage(sillyStudents, count);
			break;

		case 4:
			showMostDifficultAssignemnt(sillyStudents, count);
			break;

		case 5:
			courseEnrollment(sillyStudents, count);
			break;

		case 6:
			sortByAverage(sillyStudents, count);
			break;

		case 7:
			studentsAtRisk(sillyStudents, count);
			break;

		case 8:
			addingStudents(sillyStudents, count);
			displayEveryStudentInfo(sillyStudents, count);
			break;

		case 9:
			savingStudents(sillyStudents, count);
			count = 0;
			loadAllStudents(sillyStudents, count);
			displayEveryStudentInfo(sillyStudents, count);
			break;

		case 10:
			cout << endl << "See ya!" << endl;
			break;

		default:
			cout << endl << "You're inputting something incorrect..." << endl;


		} // end of switch

	} while (chooseWisely != 10);


	return 0;
}