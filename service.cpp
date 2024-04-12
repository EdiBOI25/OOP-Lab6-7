#include "service.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

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

void Service::addToContract(const string& name) {
	vector<Subject> subjects = this->filter([name](const Subject& s) {
		return s.getName() == name;
		});

	if (subjects.empty())
		throw std::exception("There are no subjects with given name");

	for (const auto& s : subjects) {
		this->contract.add(s);
	}
}

void Service::clearContract() noexcept {
	this->contract.clear();
}

void Service::generateRandomContract(const int& number) {
	if (number <= 0)
		throw std::exception("Number of subjects must be positive");

	if (number > this->size())
		throw std::exception("Number of subjects must be less than total number of subjects");

	this->contract.clear();
	vector<Subject> subjects = *this->getAll();


	const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 rng(seed); // ???
	std::shuffle(subjects.begin(), subjects.end(), rng);

	for (int i = 0; i < number; ++i) {
		this->contract.add(subjects.at(i));
	}
}

void Service::printContract() const {
	std::cout << this->contract;
}


std::ostream& operator<<(std::ostream& out, const Service& serv) {
	out << serv.repo;
	return out;
}
