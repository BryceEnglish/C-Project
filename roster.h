#pragma once
#include <string>
#include <iostream>
#include "student.h"


class Roster {
private:
	int lastIndex;
	int capacity;
	Student** students;
public:
	Roster();
	Roster(int capacity);

	Student* GetStudentAt(int index);
	void parse(string datarow);
	void add(string dID, string dfirstName, string dlastName, string demailAddress, string dage, double dp1, double dp2, double dp3, Degree dp);
	bool remove(string studentId);
	void print_All();
	void printavgDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegree(Degree d);
	~Roster();
};


