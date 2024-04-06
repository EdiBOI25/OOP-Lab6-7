#include "service.h"

#include <iostream>

//Service::Service(const Repository& repo) {
//	this->repo = repo;
//}

const DynamicArray<Subject>* Service::getAll() const noexcept{
	return this->repo.getAll();
}

void Service::addSubject(const string& name, const int& hours, const string& type, const string& teacher) {
	const Subject subject{ name, hours, type, teacher };
	if (this->repo.find(subject) != -1)
		throw std::exception("Subject already exists");
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
	if (this->repo.find(subject) != -1)
		throw std::exception("Subject already exists");
	this->repo.update(index, subject);
}

DynamicArray<Subject> Service::filter(const std::function<bool(const Subject& subject)>& condition) const {
	DynamicArray<Subject> result(10);
	for(int i = 0; i < this->repo.size(); ++i) {
		if(condition(this->repo[i])) {
			result.push_back(this->repo[i]);
		}
	}
	return result;
}

DynamicArray<Subject> Service::sort(const std::function<bool(const Subject& s1, const Subject& s2)>& condition,
	bool reverse) const {
	DynamicArray<Subject> result{2};
	for(int i = 0; i < this->getAll()->size(); ++i) {
		result.push_back(this->getAll()->at(i));
	}

	for(int i = 0; i < result.size() - 1; ++i) {
		for(int j = i + 1; j < result.size(); ++j) {
			if(condition(result.at(i), result.at(j)) && !reverse) {
				std::swap(result.at(i), result.at(j));
				continue;
			}
			if(!condition(result.at(i), result.at(j)) && reverse) {
				std::swap(result.at(i), result.at(j));
			}
		}
	}

	return result;
}

std::ostream& operator<<(std::ostream& out, const Service& serv) {
	out << serv.repo;
	return out;
}
