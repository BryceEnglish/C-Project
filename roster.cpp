#include <iostream>
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
using std::cout;
using std::cerr;
using std::endl;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student*[capacity];
}

Student * Roster::GetStudentAt(int index)
{
	return students[index];
}

void Roster::parse(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degree;

		if (row.back() == 'Y') degree = SECURITY;
		else if (row.back() == 'K') degree = NETWORKING;
		else if (row.back() == 'E') degree = SOFTWARE;
		else
		{
			cerr << "INVALID Degree TYPE!  EXITING NOW!\n";
			exit(-1);
		}
		
			//Get Id
			int rhs = row.find(",");
			string dID = row.substr(0, rhs);

			//Read FirstName
			int lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string dfirstName = row.substr(lhs, rhs - lhs);

			//Read LastName
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string dlastName = row.substr(lhs, rhs - lhs);

			//Read emailaddress
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string demailAddress = row.substr(lhs, rhs - lhs);

			//Read Age
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string dage = row.substr(lhs, rhs - lhs);

			//Read days in course
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			double days1 = stod(row.substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			double days2 = stod(row.substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			double days3 = stod(row.substr(lhs, rhs - lhs));

			//Read Degree
			lhs = rhs + 1;
			rhs = row.find(",", lhs);
			string dp = row.substr(lhs, rhs - lhs);

			add(dID, dfirstName, dlastName, demailAddress, dage, days1, days2, days3, degree);
	}
	else
	{
		cerr << "Exceeded capacity";
		exit(-1);
	}
}

void Roster::add(string dID, string dfirstName, string dlastName, string demailAddress, string dage, double dp1, double dp2, double dp3, Degree dp)
{
	double days[Student::daysInCourse];
	days[0] = dp1;
	days[1] = dp2;
	days[2] = dp3;
	if (dp == NETWORKING) students[lastIndex] = new NetworkStudent(dID, dfirstName, dlastName, demailAddress, dage, days, dp);
	else if (dp == SECURITY) students[lastIndex] = new SecurityStudent(dID, dfirstName, dlastName, demailAddress, dage, days, dp);
	else students[lastIndex] = new SoftwareStudent(dID, dfirstName, dlastName, demailAddress, dage, days, dp);
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; ++i) (this->students)[i]->print();
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->GetID() == ID)
		{
			found = true;
			delete this->students[i];
			this->students[i] = this->students[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printavgDaysInCourse(string dstudentId)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->GetID() == dstudentId)
		{
			found = true;
			double* d = students[i]->GetDays();
			cout << "Average days for " << dstudentId << " to complete a course is " << (d[0] + d[1] + d[2]) / 3 << endl;
		}
	}
	if (!found) cout << "Student not found" << endl;
}

void Roster::printInvalidEmails() //make valid emails have @ and . and invalid have " "
{
	cout << "Displaying invalid email entries:" << endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		string email = students[i]->GetEmailAddress();
		

		if (email.find(' ') != string::npos)
		{
			cout << "Student " << students[i]->GetID() << " has an invalid email" << endl;
		}
		else if (email.find('.') == string::npos)
		{
			cout << "Student " << students[i]->GetID() << " has an invalid email" << endl;
		}
		else if (email.find('@') == string::npos)
		{
			cout << "Student " << students[i]->GetID() << " has an invalid email" << endl;
		}
	}
}

void Roster::printByDegree(Degree d)
{
	cout << "Printing students with degree type " << degreeProgram[d] << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->GetDegree() == d) this->students[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->students[i];
	}
	delete students;
}

int main()
{
	cout << "Course Title: Scripting and Programming - Applications - C867" << " Programming Language: C++" << " Student ID: #001083927" << " Name: Bryce English" << endl;

	int numStudents = 5;
	string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Bryce,English,bengl12@wgu.edu,23,60,30,50,SOFTWARE"
	};

	Roster * ros = new Roster(numStudents);
	cout << "Parsing and adding students:" << endl;
	for (int i = 0; i < numStudents; ++i)
	{
		ros->parse(studentData[i]);
	}
	cout << "Done" << endl;
	cout << "Displaying all students" << endl;
	ros->print_All();
	cout << endl;

	ros->printInvalidEmails();
	cout << endl;

	cout << "Printing average days in course:" << endl;
	for (int i = 0; i < numStudents; i++) {
		ros->printavgDaysInCourse(ros->GetStudentAt(i)->GetID());
	}
	cout << endl;

	for (int i = 0; i < 3; i++) ros->printByDegree((Degree)i);
	cout << endl;

	cout << "Removing A3:" << endl;
	if (ros->remove("A3")) {
		ros->print_All();
		numStudents--;
	}
	else cout << "Student with that ID not found" << endl;
	cout << endl;

	cout << "Removing A3:\n";
	if (ros->remove("A3")) ros->print_All();
	else cout << "Student with that ID not found\n";
	
	

	//system("pause");
	return 0;
}