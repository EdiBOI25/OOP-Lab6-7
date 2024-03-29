#include "service.h"

#include <iostream>

Service::Service(const Repository& repo) {
	this->repo = repo;
}

std::vector<Subject> Service::getAll() const {
	return this->repo.getAll();
}

void Service::addSubject(const string& name, const int& hours, const string& type, const string& teacher) {
	const Subject subject{ name, hours, type, teacher };
	this->repo.add(subject);
}

size_t Service::size() const {
	return this->repo.size();
}

int Service::findSubject(const string& name, const int& hours, const string& type, const string& teacher) const {
	const Subject subject{ name, hours, type, teacher };
	std::cout << subject << '\n';
	return this->repo.find(subject);
}
