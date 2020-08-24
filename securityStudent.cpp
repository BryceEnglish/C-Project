#include <iostream>
#include "securityStudent.h"
using std::cout;
using std::endl;

SecurityStudent::SecurityStudent() :Student()
{
	dtype = SECURITY;
}

SecurityStudent::SecurityStudent(string ID, string firstName, string lastName, string emailAddress, string age, double days[], Degree Degree)
	:Student(ID, firstName, lastName, emailAddress, age, days)
{
	dtype = SECURITY;
}

Degree SecurityStudent::GetDegree()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}