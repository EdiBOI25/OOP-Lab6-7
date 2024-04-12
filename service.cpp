#include "service.h"

#include <iostream>
#include <algorithm>

//Service::Service(const Repository& repo) {
//	this->repo = repo;
//}

const std::vector<Subject>* Service::getAll() const noexcept{
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

std::vector<Subject> Service::filter(const std::function<bool(const Subject& subject)>& condition) const {
	std::vector<Subject> result;
	/*for(int i = 0; i < this->repo.size(); ++i) {
		if(condition(this->repo[i])) {
			result.push_back(this->repo[i]);
		}
	}*/
	std::copy_if(this->repo.getAll()->begin(), this->repo.getAll()->end(), std::back_inserter(result), condition);
	return result;
}

std::vector<Subject> Service::sort(const std::function<bool(const Subject& s1, const Subject& s2)>& condition,
	bool reverse) const {
	std::vector<Subject> result{*this->getAll()};
	/*for(int i = 0; i < this->getAll()->size(); ++i) {
		result.push_back(this->getAll()->at(i));
	}*/

	/*for(int i = 0; i < result.size() - 1; ++i) {
		for(int j = i + 1; j < result.size(); ++j) {
			if(condition(result.at(i), result.at(j)) && !reverse) {
				std::swap(result.at(i), result.at(j));
				continue;
			}
			if(!condition(result.at(i), result.at(j)) && reverse) {
				std::swap(result.at(i), result.at(j));
			}
		}
	}*/
	if (reverse == false) {
		std::sort(result.begin(), result.end(), condition);
	}
	else {
		std::sort(result.begin(), result.end(), [condition](const Subject& s1, const Subject& s2) {
			return !condition(s1, s2);
			});
	}

	return result;
}

std::ostream& operator<<(std::ostream& out, const Service& serv) {
	out << serv.repo;
	return out;
}
