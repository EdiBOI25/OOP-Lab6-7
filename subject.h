#pragma once
#include <string>

class Subject {
private:
	std::string name;
	int hours_per_week;
	std::string type; // compulsory or optional
	std::string teacher;

public:
	/**
	 * \brief Subject class constructor: initializes subject
	 * \param name name of subject
	 * \param hours_per_week hours per week of subject
	 * \param type type of subject (compulsory, optional or other)
	 * \param teacher name of teacher who teaches the subject
	 */
	Subject(const std::string& name, const int& hours_per_week, const std::string& type, const std::string& teacher);

	/**
	 * \brief Subject class destructor
	 */
	~Subject() = default;

	/**
	 * \brief Returns the name of the subject
	 * \return name of subject
	 */
	std::string getName() const;

	/**
	 * \brief Returns the number of hours per week of the subject
	 * \return hours per week of subject
	 */
	int getHours() const;

	/**
	 * \brief Returns the type of the subject
	 * \return type of subject
	 */
	std::string getType() const;

	/**
	 * \brief Returns the name of the teacher of the subject
	 * \return name of teacher of subject
	 */
	std::string getTeacher() const;

	/**
	 * \brief Sets new name of subject
	 * \param new_name new name to replace the old one
	 */
	void setName(const std::string& new_name);
	/**
	 * \brief Sets a new number of hours per week
	 * \param new_hours new number of hours per week
	 */
	void setHours(const int& new_hours);
	/**
	 * \brief Sets new type of subject
	 * \param new_type new type to replace the old one
	 */
	void setType(const std::string& new_type);
	/**
	 * \brief Sets new teacher of subject
	 * \param new_teacher new teacher name to replace the old one
	 */
	void setTeacher(const std::string& new_teacher);
};
