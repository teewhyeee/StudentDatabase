#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

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

struct SillyStudentNode {

	SillyStudent data;
	SillyStudentNode* next;
};

void menu();

void lightBlue(string value);

void loadAllStudents(SillyStudentNode*& head);
void displayEveryStudentInfo(SillyStudentNode* head);

void calculatingAllAverages(SillyStudentNode* head);
void calculateOneAverage(SillyStudent* s);
void showAssignmentAverage(SillyStudentNode* head);
void sortByAverage(SillyStudentNode* head);

void searchByCourse(SillyStudentNode* head);
void showMostDifficultAssignemnt(SillyStudentNode* head);
void courseEnrollment(SillyStudentNode* head);

void addingStudents(SillyStudentNode*& head);
void studentsAtRisk(SillyStudentNode* head);
void savingStudents(SillyStudentNode* head);

void youFailedBro(SillyStudentNode* head);
void sortAlphabeticalOrder(SillyStudentNode* head);

void deleteList(SillyStudentNode*& head);
