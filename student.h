#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{
public:
	const static int daysInCourse = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	double days[daysInCourse];
	Degree dtype;

public:

	Student();
	Student(string ID, string firstName, string lastName, string emailAddress, string age, double days[]);

	//Setters
	void SetID(string ID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(string age);
	void SetDays(double daysInCourse[]);
	//void SetDegree();

	//Getters
	string GetID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	string GetAge();
	double* GetDays();
	//string GetDegreeType();
	virtual Degree GetDegree() = 0;

	virtual void print() = 0;

	//Destructor
	~Student();
};
