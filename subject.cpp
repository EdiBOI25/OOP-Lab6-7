#include "subject.h"

Subject::Subject(const std::string& name, const int& hours_per_week, const std::string& type, const std::string& teacher) {
	this->name = name;
	this->hours_per_week = hours_per_week;
	this->type = type;
	this->teacher = teacher;
}

//Subject::~Subject() {
//	// destructor
//}

std::string Subject::getName() const {
	return this->name;
}

int Subject::getHours() const {
	return this->hours_per_week;
}

std::string Subject::getType() const {
	return this->type;
}

std::string Subject::getTeacher() const {
	return this->teacher;
}

void Subject::setName(const std::string& new_name) {
	this->name = new_name;
}

void Subject::setHours(const int& new_hours) {
	this->hours_per_week = new_hours;
}

void Subject::setType(const std::string& new_type) {
	this->type = new_type;
}

void Subject::setTeacher(const std::string& new_teacher) {
	this->teacher = new_teacher;
}
