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

	/**
	 * \brief Returns the position of a subject in the list
	 * \param name name of subject
	 * \param hours number of hours per week of subject
	 * \param type type of subject
	 * \param teacher teacher of subject
	 * \return position at which subject is found or -1 otherwise
	 */
	int findSubject(const string& name, const int& hours, const string& type, const string& teacher) const;

	/**
	 * \brief Removes the subject at a given index
	 * \param index index of subject to remove
	 */
	void removeSubject(const int& index);

	/**
	 * \brief Updates subject at a given index with new parameters
	 * \param index index of element to replace with new one
	 * \param name new name
	 * \param hours new number of hours per week
	 * \param type new type
	 * \param teacher new teacher name
	 */
	void updateSubject(const int& index, const string& name, const int& hours, const string& type, const string& teacher);
};
