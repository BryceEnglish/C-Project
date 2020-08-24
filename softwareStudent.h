#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student
{

public:
	SoftwareStudent();
	SoftwareStudent(
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		string age,
		double days[],
		Degree Degree
	);
	Degree GetDegree();
	void print();

	~SoftwareStudent();
};

