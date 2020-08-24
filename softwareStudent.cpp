#include <iostream>
#include "softwareStudent.h"
using std::cout;
using std::endl;

SoftwareStudent::SoftwareStudent() :Student()
{
	dtype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, string age, double days[], Degree Degree)
	:Student(studentId, firstName, lastName, emailAddress, age, days)
{
	dtype = SOFTWARE;
}

Degree SoftwareStudent::GetDegree()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}