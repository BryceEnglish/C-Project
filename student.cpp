#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	for (int i = 0; i < daysInCourse; i++) this->days[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, string age, double days[])
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i<daysInCourse; i++) this->days[i] = days[i];
}

//getters
string Student::GetID()
{
	return studentId;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}

string Student::GetEmailAddress()
{
	return emailAddress;
}

string Student::GetAge()
{
	return age;
}

double * Student::GetDays()
{
	return days;
}

//Setters
void Student::SetID(string ID)
{
	this->studentId = studentId;
}

void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::SetAge(string age)
{
	this->age = age;
}

void Student::SetDays(double days[])
{
	for (int i = 0; i<daysInCourse; i++) this->days[i] = days[i];
}

void Student::print()
{
	cout << left << setw(5) << studentId << " ";
	cout << left << setw(5) << firstName << " ";
	cout << left << setw(5) << lastName << " ";
	cout << left << setw(5) << emailAddress << " ";
	cout << left << setw(5) << age << " ";
	cout << left << setw(5) << days[0] << " ";
	cout << left << setw(5) << days[1] << " ";
	cout << left << setw(5) << days[2] << " ";
}

Student::~Student()
{
}

	