#pragma once
#include "service.h"
class UI {
private:
	Service service;
	string main_menu{
		"-------------------\n"
		"Study contract menu\n"
		"-------------------\n"
		"1. Add subject\n"
		"2. Find subject\n"
		"3. Remove subject\n"
		"4. Edit subject\n"
		"9. Print all subjects\n"
	};

	/**
	 * \brief Reads an integer from console
	 * \param message message to print
	 * \return read integer
	 */
	int readInteger(const string& message) const;

	/**
	 * \brief Reads a string from console
	 * \param message message to print
	 * \return read string
	 */
	string readString(const string& message) const;

	void addSubject();

	void findSubject();

	void removeSubject();

	void updateSubject();

	void printAllSubjects();

public:
	/**
	 * \brief Default constructor in case service is not provided
	 */
	UI() {
		this->service = Service();
	}

	/**
	 * \brief Constructor with provided service
	 * \param service the service to use
	 */
	UI(const Service& service) {
		this->service = service;
	}

	/**
	 * \brief Runs the UI (main menu)
	 */
	void run();
};

