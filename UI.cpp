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

void UI::removeSubject() {
	this->printAllSubjects();
	const int index{ readInteger("Index of subject to remove: ") };
	this->service.removeSubject(index);
}

void UI::updateSubject() {
	this->printAllSubjects();
	const int index{ readInteger("Index of subject to update: ") };
	const string name{ readString("New name: ") };
	const int hours_per_week{ readInteger("New number of hours per week: ") };
	const string type{ readString("New type: ") };
	const string teacher{ readString("New teacher's name: ") };

	this->service.updateSubject(index, name, hours_per_week, type, teacher);
}

void UI::printAllSubjects() {
	if (this->service.size() == 0) {
		cout << "No subjects to print\n";
		return;
	}
	const vector<Subject> subjects = this->service.getAll();
	for (size_t i = 0; i < subjects.size(); ++i) {
				cout << i << ": " << subjects[i] << '\n';
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
		case 3:
			this->removeSubject();
			break;
		case 4:
			this->updateSubject();
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
