#include "service.h"

Service::Service(const Repository& repo) {
	this->repo = repo;
}

std::vector<Subject> Service::getAll() const {
	return this->repo.getAll();
}

void Service::add(const Subject& subject) {
	this->repo.add(subject);
}

size_t Service::size() const {
	return this->repo.size();
}
