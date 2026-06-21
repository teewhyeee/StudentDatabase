#include "Student.h"

int main() {

	SillyStudentNode* head = nullptr;
	int chooseWisely;

	loadAllStudents(head);
	calculatingAllAverages(head);

	do {
		menu();

		cout << "Choose an option, please... ";
		cin >> chooseWisely;

		switch (chooseWisely) {
		case 1:

			displayEveryStudentInfo(head);

			break;

		case 2:
			searchByCourse(head);
			break;

		case 3:
			showAssignmentAverage(head);
			break;

		case 4:
			showMostDifficultAssignemnt(head);
			break;

		case 5:
			courseEnrollment(head);
			break;

		case 6:
			sortByAverage(head);
			break;

		case 7:
			sortAlphabeticalOrder(head);
			break;

		case 8:
			youFailedBro(head);
			break;

		case 9:
			studentsAtRisk(head);
			break;

		case 10:
			addingStudents(head);
			displayEveryStudentInfo(head);
			break;

		case 11:
			savingStudents(head);
			displayEveryStudentInfo(head);
			break;

		case 12:
			break;

		default:
			cout << endl << "You're inputting something incorrect..." << endl;


		} // end of switch

	} while (chooseWisely != 12);

	deleteList(head);
	cout << "Memory cleared safely. See ya!!" << endl;

	return 0;

}