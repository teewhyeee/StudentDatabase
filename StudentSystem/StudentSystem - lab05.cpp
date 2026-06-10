#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct SillyStudent {

	string firstName;
	string lastName;
	int id;
	double grade;
};

const int MAX_STUDENTS = 24;
const int NUM_ASSIGNMENTS = 5;

void menu();

void red(string value);

void allStudents(SillyStudent sillyStudents[], int& count);
void displayEveryStudentInfo(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count);

void generatingGreatGrades(double grades[][NUM_ASSIGNMENTS], int count);
void calculatingAverage(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count);

void updateGreatAssignments(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count);
void addingStudents(SillyStudent sillyStudents[], int& count, double grades[][NUM_ASSIGNMENTS]);
void savingStudents(SillyStudent sillyStudents[], int count);

void search(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count);

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

void menu() {

	cout << endl << "====== STUDENT MENU ======" << endl;
	cout << "1. Display Student Info" << endl;
	cout << "2. Update Assignment" << endl;
	cout << "3. Add a Student" << endl;
	cout << "4. Save to File" << endl;
	cout << "5. Highlight Student / Assignment" << endl;
	cout << "6. Exit" << endl << endl;
}

void red(string value) {
	cout << "\033[31m" << value << "\033[0m";
}

void allStudents(SillyStudent sillyStudents[], int& count) {

	ifstream inputFile("students.txt");

	while (count < MAX_STUDENTS &&
		inputFile >> sillyStudents[count].firstName
		>> sillyStudents[count].lastName
		>> sillyStudents[count].id
		>> sillyStudents[count].grade) {

		count++;
	}

	inputFile.close();

}

void generatingGreatGrades(double grades[][NUM_ASSIGNMENTS], int count) {

	for (int i = 0; i < count; i++) {

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			grades[i][j] = rand() % 41 + 60;
		}
	}
}

void calculatingAverage(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count) {

	for (int i = 0; i < count; i++) {

		double average = 0;

		for (int u = 0; u < NUM_ASSIGNMENTS; u++) {

			average += grades[i][u];
		}

		sillyStudents[i].grade = average / NUM_ASSIGNMENTS;
	}
}

void displayEveryStudentInfo(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count) {

	cout << endl << "===== HERE ARE ALL STUDENTS =====" << endl;

	red("ID\tFName\t\tLName\t\tA1\tA2\tA3\tA4\tA5\tAVG");
	cout << endl;

	for (int i = 0; i < count; i++) {

		cout << left << setw(8) << sillyStudents[i].id;
		cout << left << setw(16) << sillyStudents[i].firstName;
		cout << left << setw(16) << sillyStudents[i].lastName;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {
			cout << grades[i][j] << "\t";
		}

		cout << sillyStudents[i].grade << endl;
	}
}

void updateGreatAssignments(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count) {

	int theID;
	int assignment;
	double updatedGrade;

	cout << "What is the student ID?: ";
	cin >> theID;

	int found = -1;

	for (int i = 0; i < count; i++) {

		if (sillyStudents[i].id == theID) {

			found = i;
			break;
		}
	}

	if (found == -1) {

		cout << endl << "That student doesn't exist" << endl;
		return;
	}

	cout << "Which assignment?: ";
	cin >> assignment;

	cout << "What is the updated grade?: ";
	cin >> updatedGrade;

	grades[found][assignment - 1] = updatedGrade;

	calculatingAverage(grades, sillyStudents, count);

	cout << endl << "The assignment has been updated!" << endl;
	displayEveryStudentInfo(grades, sillyStudents, count);

}

void addingStudents(SillyStudent sillyStudents[], int& count, double grades[][NUM_ASSIGNMENTS]) {

	if (count >= MAX_STUDENTS) {
		cout << endl << "You can not add anymore students!" << endl;
		return;
	}
	cout << "What is their..." << endl;
	
	cout << "First Name: ";
	cin >> sillyStudents[count].firstName;

	cout << "Last Name: ";
	cin >> sillyStudents[count].lastName;

	cout << "ID Number: ";
	cin >> sillyStudents[count].id;

	for (int r = 0; r < NUM_ASSIGNMENTS; r++) {

		grades[count][r] = rand() % 41 + 60;
	}

	count++;

	cout << endl << "Student successfully added!" << endl;

}

void savingStudents(SillyStudent sillyStudents[], int count) {

	ofstream outputFile("students.txt");

	for (int i = 0; i < count; i++) {

		outputFile
			<< sillyStudents[i].firstName << " "
			<< sillyStudents[i].lastName << " "
			<< sillyStudents[i].id << " "
			<< sillyStudents[i].grade << endl;
	}

	outputFile.close();

	cout << "Data has been saved!" << endl;
}

void search(double grades[][NUM_ASSIGNMENTS], SillyStudent sillyStudents[], int count) {

	int choice;

	cout << endl << "1. Highlight Student Row" << endl;
	cout << "2. Highlight Assignment Column" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	if (choice == 1) {

		int theStudentID;

		cout << "Enter the student ID: ";
		cin >> theStudentID;

		red("ID\tFName\t\tLName\t\tA1\tA2\tA3\tA4\tA5\tAVG");
		cout << endl;

		for (int i = 0; i < count; i++) {

			bool yellowFlash = (sillyStudents[i].id == theStudentID);

			if (yellowFlash)
				cout << "\033[6;93m";

			cout << left << setw(8) << sillyStudents[i].id;
			cout << left << setw(16) << sillyStudents[i].firstName;
			cout << left << setw(16) << sillyStudents[i].lastName;

			for (int j = 0; j < NUM_ASSIGNMENTS; j++) 
				cout << grades[i][j] << "\t";

			cout << sillyStudents[i].grade;

			if (yellowFlash)
				cout << "\033[0m";

			cout << endl;
		}
	}
	else if (choice == 2) {

		int column;

		cout << "Which column would you like (1-5): ";
		cin >> column;

		red("ID\tFName\t\tLName\t\tA1\tA2\tA3\tA4\tA5\tAVG");
		cout << endl;

		for (int k = 0; k < count; k++) {

			cout << left << setw(8) << sillyStudents[k].id;
			cout << left << setw(16) << sillyStudents[k].firstName;
			cout << left << setw(16) << sillyStudents[k].lastName;

			for (int l = 0; l < NUM_ASSIGNMENTS; l++) {

				if (l == column - 1)
					cout << "\033[6;93m";

				cout << grades[k][l];

				if(l == column - 1)
					cout << "\033[0m";

				cout << "\t";
			}

			cout << sillyStudents[k].grade << endl;
		}
	}
}