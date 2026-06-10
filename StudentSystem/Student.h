#pragma once

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
