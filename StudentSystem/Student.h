#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int NUM_ASSIGNMENTS = 5;
const int NUM_COURSES = 3;

struct SillyStudent {

	string firstName;
	string lastName;
	int id;
	
	double assignments[NUM_ASSIGNMENTS];
	double average;

	string courses[NUM_COURSES];
};

void menu();

void lightBlue(string value);

void loadAllStudents(SillyStudent sillyStudents[], int& count);
void displayEveryStudentInfo(SillyStudent sillyStudents[], int count);

void calculatingAllAverages(SillyStudent sillyStudents[], int count);
void calculatingAverage(SillyStudent* s);
void showAssignmentAverage(SillyStudent sillyStudents[], int count);
void sortByAverage(SillyStudent sillyStudent[], int count);

void searchByCourse(SillyStudent sillyStudents[], int count);
void showMostDifficultAssignemnt(SillyStudent sillyStudent[], int count);
void courseEnrollment(SillyStudent sillyStudent[], int count);

void addingStudents(SillyStudent sillyStudents[], int& count);
void studentsAtRisk(SillyStudent sillyStudents[], int count);
void savingStudents(SillyStudent sillyStudents[], int count);
