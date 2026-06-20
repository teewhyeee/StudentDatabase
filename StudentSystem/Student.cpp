#include "Student.h"

void menu() {

	cout << endl << "====== STUDENT MENU ======" << endl;
	cout << "1. Display ALL Students" << endl;
	cout << "2. Search by Course" << endl;
	cout << "3. Assignment Averages" << endl;
	cout << "4. Hardest Assignment" << endl;
	cout << "5. Course Enrollment" << endl;
	cout << "6. Sort by Averages" << endl;
	cout << "7. Sort Names in Alphabetical Order" << endl;
	cout << "8. Failed Students" << endl;
	cout << "9. Students At Risk" << endl;
	cout << "10. Add a Student" << endl;
	cout << "11. Save Student" << endl;
	cout << "12. Exit" << endl << endl;
}

void lightBlue(string value) {
	cout << "\033[96m" << value << "\033[0m";
}

void loadAllStudents(SillyStudentNode*& head) {

	ifstream file("Students90.txt");
	if (!file) {
		cout << "Error opening file!" << endl;
		return;
	}

	SillyStudent tempStudent;

	while (file >> tempStudent.firstName
		>> tempStudent.lastName
		>> tempStudent.id) {

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {
			
			file >> tempStudent.assignments[j];
		}

		file >> tempStudent.average;

		for (int j = 0; j < NUM_COURSES; j++) {

			file >> tempStudent.courses[j];
		}

		SillyStudentNode* newNode = new SillyStudentNode();
		newNode->data = tempStudent;

		newNode->next = head;

		head = newNode;
	}

	file.close();
}

void displayEveryStudentInfo(SillyStudentNode* head) {

	cout << endl << "============================================ HERE ARE ALL STUDENTS ============================================" << endl;

	lightBlue("ID\tLName\t\t  FName\t\t  ");

	for (int j = 0; j < NUM_ASSIGNMENTS; j++)
		cout << "\033[96mA" << j + 1 << "\033[0m\t ";

	lightBlue("AVG\tC1\tC2\tC3");
	cout << endl;

	SillyStudentNode* current = head;

	while (current != nullptr) {

		cout << current->data.id << "\t";
		cout << left << setw(18) << current->data.lastName;
		cout << left << setw(16) << current->data.firstName;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++)
			cout << current->data.assignments[j] << "\t ";

		cout << current->data.average << "\t";

		for (int j = 0; j < NUM_COURSES; j++)
			cout << current->data.courses[j] << "\t";

		cout << endl;

		current = current->next;
	}

}

void calculatingAllAverages(SillyStudentNode* head) {

	SillyStudentNode* current = head;

	while (current != nullptr) {

		calculateOneAverage(&current->data);

		current = current->next;
	}
}

void calculateOneAverage(SillyStudent* s) {

		double one = 0;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			one += s->assignments[j];

		}

		s->average = one / NUM_ASSIGNMENTS;
	
}

void searchByCourse(SillyStudentNode* head) {

	string searchCourse;
	bool courseFound = false;

	cout << endl << "Please enter course name: ";
	cin >> searchCourse;

	SillyStudentNode* current = head;

	while (current != nullptr) {

		for (int j = 0; j < NUM_COURSES; j++) {

			if (current->data.courses[j] == searchCourse) {

				if (!courseFound) {

					cout << endl << "Here are the Students in " << searchCourse << ":" << endl;
				}

				cout << current->data.id << " "
					<< current->data.firstName << " "
					<< current->data.lastName << endl;

				courseFound = true;
			}
		}

		current = current->next;
	}
	if (!courseFound) {

		cout << endl << "Invalid course..." << endl;
	}
}

void showAssignmentAverage(SillyStudentNode* head) {

	cout << endl << "===== Here is the AVERAGE of each assignment =====" << endl;

	for (int u = 0; u < NUM_ASSIGNMENTS; u++) {
		
		double sum = 0;
		int count = 0;

		SillyStudentNode* current = head;

		while (current != nullptr) {

			sum += current->data.assignments[u];
			count++;

			current = current->next;

		}

		double averageAssign = sum / count;

		cout << "A" << u + 1 << ": " << averageAssign << endl;
	}

}

void showMostDifficultAssignemnt(SillyStudentNode* head) {

	double lowest = 101;
	int hardest = 0;

	for (int u = 0; u < NUM_ASSIGNMENTS; u++) {

		double sum = 0;
		int count = 0;

		SillyStudentNode* current = head;

		while (current != nullptr) {

			sum += current->data.assignments[u];
			count++;

			current = current->next;
		}
		double averageAssign = sum / count;

		if (averageAssign < lowest) {

			lowest = averageAssign;
			hardest = u + 1;
		}
	}

	cout << endl << "Hardest Assignment is: A" << hardest 
		<< " (" << "\033[31m" << lowest << "\033[0m" << ")" << endl;

}

void courseEnrollment(SillyStudentNode* head) {

	cout << endl << "===== Here are the number of STUDENTS in each COURSE =====" << endl;

	string courseNames[7] = {
		"COMP220",
		"MATH102",
		"STAT110",
		"ENGL150",
		"HIST210",
		"BIOL120",
		"CSCI101"
	};

	for (int c = 0; c < 7; c++) {

		int enrolled = 0;

		SillyStudentNode* current = head;

		while (current != nullptr) {

			for (int j = 0; j < NUM_COURSES; j++) {

				if (current->data.courses[j] == courseNames[c]) {

					enrolled++;
				}
			}

			current = current->next;
		}

		cout << courseNames[c] << ": " << enrolled << endl;
	}
}

void sortByAverage(SillyStudentNode* head) {

	SillyStudentNode* current = head;

	while (current != nullptr) {

		SillyStudentNode* highest = current;
		SillyStudentNode* sort = current->next;

		while (sort != nullptr) {

			if (sort->data.average > highest->data.average) {

				highest = sort;
			}
			sort = sort->next;
		}

		SillyStudent temp = current->data;
		current->data = highest->data;
		highest->data = temp;

		current = current->next;
	}

	displayEveryStudentInfo(head);
}

void sortAlphabeticalOrder(SillyStudentNode* head) {

	cout << endl << "======= Students Sorted Alphabetically =======" << endl;

	SillyStudentNode* current = head;

	while (current != nullptr) {

		SillyStudentNode* alpha = current;
		SillyStudentNode* sort = current->next;

		while (sort != nullptr) {

			if (sort->data.firstName < alpha->data.firstName) {

				alpha = sort;
			}

			sort = sort->next;
		}

		SillyStudent temp = current->data;
		current->data = alpha->data;
		alpha->data = temp;

		current = current->next;
	}

	SillyStudentNode* show = head;

	lightBlue("ID\tFName\t\tLName\t\t");
	cout << endl;

	while (show != nullptr) {

		cout << show->data.id << "\t";
		cout << left << setw(16) << show->data.firstName;
		cout << show->data.lastName << "      \t" << endl;

		show = show->next;
	}

}

void studentsAtRisk(SillyStudentNode* head) {

	cout << endl << "===== STUDENTS AT RISK =====" << endl;

	lightBlue("ID\tLName\t\tFName\t\t");

	cout << endl;

	SillyStudentNode* current = head;

	while (current != nullptr) {

		bool risky = false;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			if (current->data.assignments[j] < 50) {

				risky = true;
			}
		}

		if (risky &&
			current->data.average >= 50 &&
			current->data.average <= 59) {
		
			cout << current->data.id << "\t"
				<< current->data.lastName << "      \t"
				<< current->data.firstName << "      \t" << endl;
		}

		current = current->next;			
	}
}

void youFailedBro(SillyStudentNode* head) {

	cout << endl << "=========== A BUNCH OF FAILURES ===========" << endl;

	lightBlue("ID\tLName\t\tFName\t\tAVG");
	cout << endl;

	SillyStudentNode* current = head;

	while (current != nullptr) {

		if (current->data.average <= 49) {

			cout << current->data.id << "\t"
				<< current->data.lastName << "      \t"
				<< current->data.firstName << "      \t"
				<< current->data.average << "\t" << endl;
		}

		current = current->next;
	}
}

void addingStudents(SillyStudentNode*& head) {

	SillyStudentNode* newNode = new SillyStudentNode;
	
	cout << "What is their..." << endl << endl;

	cout << "First Name: ";
	cin >> newNode->data.firstName;

	cout << "Last Name: ";
	cin >> newNode->data.lastName;

	cout << "ID Number: ";
	cin >> newNode->data.id;

	cout << endl << "What are their markes??" << endl;

	for (int r = 0; r < NUM_ASSIGNMENTS; r++) {

		cout << "A" << r + 1 << ": ";
		cin >> newNode->data.assignments[r];
	}

	cout << endl << "What courses are they in?" << endl;

	for (int c = 0; c < NUM_COURSES; c++) {

		cout << "Course " << c + 1 << ": ";
		cin >> newNode->data.courses[c];
	}

	calculateOneAverage(&newNode->data);

	newNode->next = head;
	head = newNode;

	cout << endl << "Student successfully added!" << endl;
}

void savingStudents(SillyStudentNode* head) {

	ofstream outputFile("Students90.txt");

	SillyStudentNode* current = head;

	while (current != nullptr) {

		outputFile
			<< current->data.firstName << " "
			<< current->data.lastName << " "
			<< current->data.id << " ";

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			outputFile << current->data.assignments[j] << " ";
		}

		outputFile << current->data.average << " ";

		for (int k = 0; k < NUM_COURSES; k++) {

			outputFile << current->data.courses[k] << " ";
		}

		outputFile << endl;

		current = current->next;
	}						

	outputFile.close();

	cout << "Data has been saved!" << endl;
}