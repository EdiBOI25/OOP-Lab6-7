#include "UI.h"

#include <iostream>

using namespace std;

void clearBuffer() {
	// Aparent, mereu cand se citeste un numar, ramane caracterul '\n' in buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int UI::readInteger(const string& message) const {
	int number;
	cout << message;
	cin >> number;
	clearBuffer();
	return number;
}

string UI::readString(const string& message) const {
	string text;
	cout << message;
	getline(cin, text);
	return text;
}

void UI::addSubject() {
	const string name {readString("Name: ")};
	const int hours_per_week {readInteger("Number of hours per week: ")};
	const string type{readString("Type: ")};
	const string teacher{readString("Teacher's name: ")};

	this->service.addSubject(name, hours_per_week, type, teacher);
}

void UI::findSubject() {
	const string name{ readString("Name: ") };
	const int hours_per_week{ readInteger("Number of hours per week: ") };
	const string type{ readString("Type: ") };
	const string teacher{ readString("Teacher's name: ") };

	int pos = this->service.findSubject(name, hours_per_week, type, teacher);
	if (pos == -1) {
		std::cout << "Subject not found\n";
		return;
	}
	std::cout << "Subject found at position " << pos << '\n';
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
		case 2:
			this->findSubject();
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
