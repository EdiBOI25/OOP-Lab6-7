#pragma once
#include "repository.h"

class Service {
private:
	Repository repo;

public:
	/**
	 * \brief Constructor in case no repository is provided
	 */
	Service() {
		this->repo = Repository();
	}

	/**
	 * \brief Service constructor
	 * \param repo repository to hold elements
	 */
	Service(const Repository& repo);

	/**
	 * \brief Returns all elements in list
	 * \return list of elements
	 */
	std::vector<Subject> getAll() const;

	/**
	 * \brief Adds a subject to the list
	 * \param name name of subject
	 * \param hours number of hours per week of subject
	 * \param type type of subject
	 * \param teacher teacher's name of subject
	 */
	void addSubject(const string& name, const int& hours, const string& type, const string& teacher);

	/**
	 * \brief Returns the number of elements in list
	 * \return number of elements in list
	 */
	size_t size() const;
};
