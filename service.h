#pragma once
#include <functional>

#include "repository.h"

class Service {
private:
	Repository repo{};

public:
	/**
	 * \brief Constructor in case no repository is provided
	 */
	Service() = default;

	/**
	 * \brief Service constructor
	 * \param repo repository to hold elements
	 */
	//Service(const Repository& repo);

	~Service() = default;

	/**
	 * \brief Returns all elements in list
	 * \return list of elements
	 */
	const DynamicArray<Subject>* getAll() const noexcept;

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
	size_t size() const noexcept;

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

	friend std::ostream& operator<<(std::ostream& out, const Service& serv);

	/**
	 * \brief Filters list with given method
	 * \param condition method to filter by
	 * \return filtered list
	 */
	DynamicArray<Subject> filter(const std::function<bool(const Subject& subject)>& condition) const;

	DynamicArray<Subject> sort(const std::function<bool(const Subject& s1, const Subject& s2)>& condition, bool reverse) const;
};
