#include "subject.h"

#include <fstream>

Subject::Subject(const string& name, const int& hours_per_week, const string& type, const string& teacher) {
	this->name = name;
	this->hours_per_week = hours_per_week;
	this->type = type;
	this->teacher = teacher;
}

//Subject::~Subject() {
//	// destructor
//}

string Subject::getName() const {
	return this->name;
}

int Subject::getHours() const {
	return this->hours_per_week;
}

string Subject::getType() const {
	return this->type;
}

string Subject::getTeacher() const {
	return this->teacher;
}

void Subject::setName(const string& new_name) {
	this->name = new_name;
}

void Subject::setHours(const int& new_hours) {
	this->hours_per_week = new_hours;
}

void Subject::setType(const string& new_type) {
	this->type = new_type;
}

void Subject::setTeacher(const string& new_teacher) {
	this->teacher = new_teacher;
}

std::ostream& operator<<(std::ostream& out, const Subject& subject)
{
	out << "Name: " << subject.name << "\tHours per week: " << subject.hours_per_week << "\tType: " << subject.type << "\tTeacher: " << subject.teacher;
	return out;
}
