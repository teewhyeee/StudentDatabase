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

void calculatingAllAverages(SillyStudent sillyStudents[], int count) {

	for (int i = 0; i < count; i++) {

		double calculate = 0;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			calculate += sillyStudents[i].assignments[j];

		}

		sillyStudents[i].average = calculate / NUM_ASSIGNMENTS;
	 }
}

void calculateOneAverage(SillyStudent* s) {

		double one = 0;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			one += s->assignments[j];

		}

		s->average = one / NUM_ASSIGNMENTS;
	
}

void searchByCourse(SillyStudent sillyStudents[], int count) {

	string searchCourse;
	bool courseFound = false;

	cout << endl << "Please enter course name: ";
	cin >> searchCourse;

	for (int i = 0; i < count; i++) {

		for (int j = 0; j < NUM_COURSES; j++) {

			if (sillyStudents[i].courses[j] == searchCourse) {

				if (!courseFound) {

					cout << endl << "Here are the Students in " << searchCourse << ":" << endl;
				}

				cout << sillyStudents[i].id << " "
					<< sillyStudents[i].firstName << " "
					<< sillyStudents[i].lastName << endl;

				courseFound = true;
			}
		}

	}
	if (!courseFound) {

		cout << endl << "Invalid course..." << endl;
	}
}

void showAssignmentAverage(SillyStudent sillyStudents[], int count) {

	cout << endl << "===== Here is the AVERAGE of each assignment =====" << endl;

	for (int u = 0; u < NUM_ASSIGNMENTS; u++) {
		
		double sum = 0;

		for (int v = 0; v < count; v++) {

			sum += sillyStudents[v].assignments[u];
		}

		double averageAssign = sum / count;

		cout << "A" << u + 1 << ": " << averageAssign << endl;
	}

}

void showMostDifficultAssignemnt(SillyStudent sillyStudents[], int count) {

	double lowest = 101;
	int hardest = 0;

	for (int u = 0; u < NUM_ASSIGNMENTS; u++) {

		double sum = 0;

		for (int v = 0; v < count; v++) {

			sum += sillyStudents[v].assignments[u];
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

void courseEnrollment(SillyStudent sillyStudents[], int count) {

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

		for (int i = 0; i < count; i++) {

			for (int j = 0; j < NUM_COURSES; j++) {

				if (sillyStudents[i].courses[j] == courseNames[c]) {

					enrolled++;
				}
			}
		}

		cout << courseNames[c] << ": " << enrolled << endl;
	}
}

void sortByAverage(SillyStudent sillyStudents[], int count) {

	for (int i = 0; i < count - 1; i++) {

		int highest = i;

		for (int h = i + 1; h < count; h++) {

			if (sillyStudents[h].average > sillyStudents[highest].average) {

				highest = h;
			}
		}

		SillyStudent temp = sillyStudents[i];
		sillyStudents[i] = sillyStudents[highest];
		sillyStudents[highest] = temp;

	}

	displayEveryStudentInfo(sillyStudents, count);
}

void sortAlphabeticalOrder(SillyStudent sillyStudents[], int count) {

	cout << endl << "======= Students Sorted Alphabetically =======" << endl;

	for (int i = 0; i < count - 1; i++) {

		int alpha = i;

		for (int x = i + 1; x < count; x++) {

			if (sillyStudents[x].firstName < sillyStudents[alpha].firstName) {

				alpha = x;
			}
		}

		SillyStudent temp = sillyStudents[i];
		sillyStudents[i] = sillyStudents[alpha];
		sillyStudents[alpha] = temp;
	}

	lightBlue("ID\tFName\t\tLName\t\t");
	cout << endl;

	for (int j = 0; j < count; j++) {

		cout << sillyStudents[j].id << "\t";
		cout << left << setw(16) << sillyStudents[j].firstName;
		cout << sillyStudents[j].lastName << "      \t" << endl;
	}


}

void studentsAtRisk(SillyStudent sillyStudents[], int count) {

	cout << endl << "===== STUDENTS AT RISK =====" << endl;

	lightBlue("ID\tLName\t\tFName\t\t");

	cout << endl;

	for (int i = 0; i < count; i++) {

		bool risky = false;

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			if (sillyStudents[i].assignments[j] < 50) {

				risky = true;
			}
		}

		if (risky &&
			sillyStudents[i].average >= 50 &&
			sillyStudents[i].average <= 59)

			cout << sillyStudents[i].id << "\t"
			<< sillyStudents[i].lastName << "      \t"
			<< sillyStudents[i].firstName << "      \t" << endl;
	}
}

void youFailedBro(SillyStudent sillyStudents[], int count) {

	cout << endl << "=========== A BUNCH OF FAILURES ===========" << endl;

	lightBlue("ID\tLName\t\tFName\t\tAVG");

	cout << endl;

	for (int i = 0; i < count; i++) {

		if (sillyStudents[i].average <= 49) {

			cout << sillyStudents[i].id << "\t"
				<< sillyStudents[i].lastName << "      \t"
				<< sillyStudents[i].firstName << "      \t" 
				<< sillyStudents[i].average << "\t" << endl;
		}
	}
}

void addingStudents(SillyStudent sillyStudents[], int& count) {

	if (count >= MAX_STUDENTS) {
		cout << endl << "You can not add anymore students!" << endl;
		return;
	}
	
	cout << "What is their..." << endl << endl;

	cout << "First Name: ";
	cin >> sillyStudents[count].firstName;

	cout << "Last Name: ";
	cin >> sillyStudents[count].lastName;

	cout << "ID Number: ";
	cin >> sillyStudents[count].id;

	cout << endl << "What are their markes??" << endl;

	for (int r = 0; r < NUM_ASSIGNMENTS; r++) {

		cout << "A" << r + 1 << ": ";
		cin >> sillyStudents[count].assignments[r];
	}

	cout << endl << "What courses are they in?" << endl;

	for (int c = 0; c < NUM_COURSES; c++) {

		cout << "Course " << c + 1 << ": ";
		cin >> sillyStudents[count].courses[c];
	}

	calculateOneAverage(&sillyStudents[count]);

	count++;

	cout << endl << "Student successfully added!" << endl;
}

void savingStudents(SillyStudent sillyStudents[], int count) {

	ofstream outputFile("Students90.txt");

	for (int i = 0; i < count; i++) {

		outputFile
			<< sillyStudents[i].firstName << " "
			<< sillyStudents[i].lastName << " "
			<< sillyStudents[i].id << " ";

		for (int j = 0; j < NUM_ASSIGNMENTS; j++) {

			outputFile << sillyStudents[i].assignments[j] << " ";
		}

		outputFile << sillyStudents[i].average << " ";

		for (int k = 0; k < NUM_COURSES; k++) {

			outputFile << sillyStudents[i].courses[k] << " ";
		}

		outputFile << endl;
		
	}

	outputFile.close();

	cout << "Data has been saved!" << endl;
}