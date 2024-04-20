#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "DynamicArray.h"
#include "subject.h"
#include <fstream>
#include <sstream>

typedef Subject Element;
using std::vector;
using std::string;

class Repository {
protected:
	std::vector<Element> list{};
	//DynamicArray<Element> list{10};
public:
	/**
	 * \brief Repository constructor
	 */
	Repository() = default;

	/**
	 * \brief Repository deconstructor
	 */
	virtual ~Repository() = default;

	/**
	 * \brief Returns the list of elements in repository
	 * \return list of elements in repository
	 */
	const std::vector<Element>& getAll() const noexcept{
		return this->list;
	}
	/*const std::vector<Element>* getAll() const noexcept{
		return &this->list;
	}*/

	/**
	 * \brief Adds an element to the list
	 * \param element the element to be added
	 */
	virtual void add(const Element& element) {
		this->list.push_back(element);
	}


	/**
	 * \brief Returns the first foun position of the element in the list
	 * \param element element to search for
	 * \return position of first found element or -1 if not found
	 */
	int find(const Element& element) const {
		/*for (int i = 0; i < this->list.size(); i++) {
			if (this->list.at(i) == element) {
				return i;
			}
		}
		return  -1;*/

		const auto it = std::find(this->list.begin(), this->list.end(), element);
		if (it != this->list.end()) {
			return static_cast<int>(std::distance(this->list.begin(), it));
		}
		return -1;
	}

	/**
	 * \brief Removes an element from the list
	 * \param element element to remove
	 */
	virtual void remove(const Element& element) {
		const int index = this->find(element);
		if (index == -1) {
			throw std::exception("Couldn't find element to remove");
		}
		this->list.erase(this->list.begin() + index);
	}

	/**
	 * \brief Removes an element found at given index
	 * \param index index of element to remove
	 */
	virtual void remove(const size_t& index) {
		if (index < 0 || index >= this->list.size()) {
			throw std::out_of_range("Index out of range");
		}
		this->list.erase(this->list.begin() + index);
	}

	/**
	 * \brief Replaces element found at given index with a new one
	 * \param index position to update element
	 * \param element element to replace the old one with
	 */
	virtual void update(const int& index, const Element& element) {
		if (index < 0 || index >= this->list.size()) {
			throw std::out_of_range("Index out of range");
		}
		this->list[index] = element;
	}

	/**
	 * \brief Returns the size of the repository list
	 * \return size of repository list
	 */
	size_t size() const noexcept{
		return this->list.size();
	}

	const Element& operator[](const int& index) const{
		if (index < 0 || index >= this->list.size()) {
			throw std::out_of_range("Index out of range");
		}
		return this->list[index];
	}

	friend std::ostream& operator<<(std::ostream& out, const Repository& repo) {
		/*for(int i = 0; i < repo.size(); ++i) {
			out << i << ": " << repo.list.at(i) << '\n';
		}*/
		int index = 0;
		for (const auto& s : repo.getAll()) {
			out << index << ": " << s << '\n';
			index++;
		}
		return out;
	}
};


class RepoWithFile: public Repository {
private:
	string file_name;
	void loadFromFile() {
		std::ifstream file(this->file_name);
		if(!file.is_open()) {
			throw std::exception("File not found");
		}		

		string line{};
		while(std::getline(file, line)) {
			if(line.empty()) {
				continue;
			}
			std::stringstream ss(line);
			string token{};
			std::vector<string> params{};
			while(std::getline(ss, token, ';')) {
				params.push_back(token);
			}

			const Subject s(params[0], std::stoi(params[1]), params[2], params[3]);
			Repository::add(s);
		}
	}

	void storeToFile() const{
		std::ofstream fout(this->file_name);
		for(const auto& s: this->list) {
			fout << s.getName() << ";" << s.getHours() << ";" << s.getType() << ";" << s.getTeacher() << '\n';
		}
		fout.close();
	}
public:
	RepoWithFile(const string& file) : Repository() {
		this->file_name = file;
		loadFromFile();
	}

	void add(const Element& element) override {
		Repository::add(element);
		storeToFile();
	}

	void remove(const Element& element) override {
		Repository::remove(element);
		storeToFile();
	}

	void remove(const size_t& index) override {
		Repository::remove(index);
		storeToFile();
	}

	void update(const int& index, const Element& element) override {
		Repository::update(index, element);
		storeToFile();
	}
};
