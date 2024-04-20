#pragma once
#include "service.h"
class UI {
private:
	Service& service;
	std::string main_menu{
		"-------------------\n"
		"Study contract menu\n"
		"-------------------\n"
		"1. Add subject\n"
		"2. Find subject\n"
		"3. Remove subject\n"
		"4. Edit subject\n"
		"5. Filter subjects\n"
		"6. Sort subjects\n"
		"7. Report by type\n"
		"8. Undo last action\n"
		"9. Print all subjects\n"
		"-------------------------\n"
		"10. Generate random contract\n"
		"11. Add subject to contract\n"
		"12. Clear contract\n"
		"13. Export contract to file\n"
		"19. Print contract\n"
		"\n"
		"0. Exit\n"
	};

	/**
	 * \brief Reads an integer from console
	 * \param message message to print
	 * \return read integer
	 */
	static int readInteger(const string& message);

	/**
	 * \brief Reads a string from console
	 * \param message message to print
	 * \return read string
	 */
	static string readString(const string& message);

	void addSubject();

	void findSubject();

	void removeSubject();

	void updateSubject();

	void filterSubjects();

	void sortSubjects();

	void printAllSubjects();

	void generateRandomContract();

	void addToContract();

	void clearContract();

	void exportContract();

	void reportByType();

	void undo();

	void printContract();

public:
	/**
	 * \brief Default constructor in case service is not provided
	 */
	UI(Service& serv) : service{ serv } {
		// Adding random subjects
		/*this->service.addSubject("default3", 6, "compulsory", "some dude");
		this->service.addSubject("default1", 2, "optional", "other dude");
		this->service.addSubject("default4", 5, "compulsory", "some other dude");
		this->service.addSubject("default2", 10, "other", "yet another dude");*/
	}

	virtual ~UI() = default;

	/**
	 * \brief Runs the UI (main menu)
	 */
	void run();
};

