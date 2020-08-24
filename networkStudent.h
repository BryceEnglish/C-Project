#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class NetworkStudent : public Student
{

public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();
};
