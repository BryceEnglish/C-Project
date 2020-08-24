#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class SecurityStudent : public Student
{

public:
	SecurityStudent();
	SecurityStudent(
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

	~SecurityStudent();
};