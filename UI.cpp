#include "UI.h"

#include <iostream>

using namespace std;

//namespace {
//	void clearBuffer() {
//		// Aparent, mereu cand se citeste un numar, ramane caracterul '\n' in buffer
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
//	}
//}

int UI::readInteger(const string& message) {
	/*int number;
	cout << message;
	cin >> number;
	clearBuffer();*/
	const string text = readString(message);
	try {
		const int number = stoi(text);
		return number;
	}
	catch(std::exception&) {
		throw std::exception("Invalid number");
	}
}

string UI::readString(const string& message) {
	string text;
	cout << message;
	getline(cin, text);
	return text;
}

void UI::addSubject() {
	try {
		const string name {readString("Name: ")};
		const int hours_per_week {readInteger("Number of hours per week: ")};
		const string type{readString("Type: ")};
		const string teacher{readString("Teacher's name: ")};

		this->service.addSubject(name, hours_per_week, type, teacher);

		std::cout << "Subject added!\n";
	}
	catch(const std::exception& e) {
		std::cout << "Couldn't add subject: ";
		std::cout << string(e.what()) << '\n';
	}
}

void UI::findSubject() {
	const string name{ readString("Name: ") };
	const int hours_per_week{ readInteger("Number of hours per week: ") };
	const string type{ readString("Type: ") };
	const string teacher{ readString("Teacher's name: ") };

	const int pos = this->service.findSubject(name, hours_per_week, type, teacher);
	if (pos == -1) {
		std::cout << "Subject not found\n";
		return;
	}
	std::cout << "Subject found at position " << pos << '\n';
}

void UI::removeSubject() {
	this->printAllSubjects();
	try {
		const int index{ readInteger("Index of subject to remove: ") };
		this->service.removeSubject(index);
		std::cout << "Subject removed!\n";
	}
	catch(const std::exception& e) {
		std::cout << "Couldn't remove subject: " << string(e.what()) << '\n';
	}
}

void UI::updateSubject() {
	this->printAllSubjects();
	try {
		const int index{ readInteger("Index of subject to update: ") };
		const string name{ readString("New name: ") };
		const int hours_per_week{ readInteger("New number of hours per week: ") };
		const string type{ readString("New type: ") };
		const string teacher{ readString("New teacher's name: ") };

		this->service.updateSubject(index, name, hours_per_week, type, teacher);
		std::cout << "Subject updated!\n";
	}
	catch(const std::exception& e) {
		std::cout << "Couldn't update subject: " << string(e.what()) << '\n';
	}
}

void UI::filterSubjects() {
	std::cout << "Choose how to filter:\n"
		"1. Hours per week less than given number\n"
		"2. Teacher name\n";
	try {
		const int option{ readInteger("Choose an option: ") };
		if (option == 1) {
			const int hours = readInteger("Enter number of hours: ");
			const std::vector<Subject> result = this->service.filter([=](const Subject& s) {
				return s.getHours() <= hours;
				});
			if (result.size() == 0) {
				std::cout << "No subject matches criteria\n";
				return;
			}
			for (int i = 0; i < result.size(); ++i) {
				std::cout << result.at(i) << '\n';
			}
		}

		else if (option == 2) {
			const string teacher = readString("Enter teacher: ");
			const std::vector<Subject> result = this->service.filter([=](const Subject& s) {
				return s.getTeacher() == teacher;
				});
			if (result.size() == 0) {
				std::cout << "No subject match criteria\n";
				return;
			}
			for (int i = 0; i < result.size(); ++i) {
				std::cout << result.at(i) << '\n';
			}
		}
		else {
			std::cout << "Invalid option\n";
		}
	}
	catch(std::exception& e) {
		std::cout << string(e.what()) << '\n';
		return;
	}
}

void UI::sortSubjects() {
	std::cout << "Choose how to sort:\n"
		"1. By name\n"
		"2. By number of hours per week\n"
		"3. By teacher and type\n";
	try {
		const int option{ readInteger("Choose an option: ") };
		const int reverse{ readInteger("Reverse order? (0 or 1): ") };
		if (option == 1) {
			const std::vector<Subject> result = this->service.sort([=](const Subject& s1, const Subject& s2) {
				return s1.getName() > s2.getName();
				}, reverse);
			for (int i = 0; i < result.size(); ++i) {
				std::cout << result.at(i) << '\n';
			}
		}

		else if (option == 2) {
			const std::vector<Subject> result = this->service.sort([=](const Subject& s1, const Subject& s2) {
				return s1.getHours() > s2.getHours();
				}, reverse);
			for (int i = 0; i < result.size(); ++i) {
				std::cout << result.at(i) << '\n';
			}
		}
		else if (option == 3) {
			const std::vector<Subject> result = this->service.sort([=](const Subject& s1, const Subject& s2) {
				if (s1.getTeacher() > s2.getTeacher()) {
					return true;
				}
				return s1.getType() > s2.getType();
				}, reverse);
			for (int i = 0; i < result.size(); ++i) {
				std::cout << result.at(i) << '\n';
			}
		}
		else {
			std::cout << "Invalid option\n";
		}
	}
	catch (std::exception& e) {
		std::cout << string(e.what()) << '\n';
		return;
	}
}

void UI::printAllSubjects() {
	if (this->service.size() == 0) {
		cout << "No subjects to print\n";
		return;
	}
	/*const vector<Subject> subjects = *this->service.getAll();
	for (size_t i = 0; i < subjects.size(); ++i) {
				cout << i << ": " << subjects.at(i) << '\n';
	}*/
	cout << this->service;
}

void UI::run() {
	int option{ -1 };
	while(true) {
		cout << this->main_menu << '\n';
		try {	
			option = this->readInteger("Choose an option: ");
		}
		catch(const std::exception& e) {
			std::cout << string(e.what()) << '\n';
			continue;
		}

		switch (option) {
		case 1:
			this->addSubject();
			break;
		case 2:
			this->findSubject();
			break;
		case 3:
			this->removeSubject();
			break;
		case 4:
			this->updateSubject();
			break;
		case 5:
			this->filterSubjects();
			break;
		case 6:
			this->sortSubjects();
			break;
		case 9:
			this->printAllSubjects();
			break;
		case 0:
			cout << "Bye bye!\n";
			return;
		default:
			cout << "Invalid option\n";
		}
	}
}