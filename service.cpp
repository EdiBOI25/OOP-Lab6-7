#include "service.h"

#include <iostream>

Service::Service(const Repository& repo) {
	this->repo = repo;
}

const std::vector<Subject>* Service::getAll() const {
	return this->repo.getAll();
}

void Service::addSubject(const string& name, const int& hours, const string& type, const string& teacher) {
	const Subject subject{ name, hours, type, teacher };
	this->repo.add(subject);
}

size_t Service::size() const noexcept{
	return this->repo.size();
}

int Service::findSubject(const string& name, const int& hours, const string& type, const string& teacher) const {
	const Subject subject{ name, hours, type, teacher };
	return this->repo.find(subject);
}

void Service::removeSubject(const int& index) {
	this->repo.remove(index);
}

void Service::updateSubject(const int& index, const string& name, const int& hours, const string& type, const string& teacher) {
	const Subject subject{ name, hours, type, teacher };
	this->repo.update(index, subject);
}

std::ostream& operator<<(std::ostream& out, const Service& serv) {
	out << serv.repo;
	return out;
}
