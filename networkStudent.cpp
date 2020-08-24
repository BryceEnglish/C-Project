#include <iostream>
#include "networkStudent.h"
using std::cout;
using std::endl;

NetworkStudent::NetworkStudent():Student()
{
	dtype = NETWORKING;
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, string age, double days[], Degree Degree)
	:Student(studentId, firstName, lastName, emailAddress, age, days)
{
	dtype = NETWORKING;
}

Degree NetworkStudent::GetDegree()
{
	return NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}