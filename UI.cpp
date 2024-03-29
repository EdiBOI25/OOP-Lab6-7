#include "UI.h"

#include <iostream>

using namespace std;

int UI::readInteger(const string& message) const {
	int number;
	cout << message;
	cin >> number;
	return number;
}

string UI::readString(const string& message) const {
	string text;
	cout << message;
	cin >> text;
	return text;
}

void UI::addSubject() {
	const string name {readString("Name: ")};
	const int hours_per_week {readInteger("Number of hours per week: ")};
	const string type{readString("Type: ")};
	const string teacher{readString("Teacher's name: ")};

	this->service.addSubject(name, hours_per_week, type, teacher);
}

void UI::printAllSubjects() {
	if (this->service.size() == 0) {
		cout << "No subjects to print\n";
		return;
	}
	const vector<Subject> subjects = this->service.getAll();
	for (const auto& subject : subjects) {
				cout << subject << '\n';
	}
}

void UI::run() {
	int option{ -1 };
	while(true) {
		cout << this->main_menu << '\n';
		option = this->readInteger("Choose an option: ");

		switch (option) {
		case 1:
			this->addSubject();
			cout << "Subject added\n";
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
