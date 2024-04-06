#pragma once
#include <iostream>
#include <vector>
#include "DynamicArray.h"
#include "subject.h"

typedef Subject Element;

class Repository {
private:
	//std::vector<Element> list{};
	DynamicArray<Element> list{10};
public:
	/**
	 * \brief Repository constructor
	 */
	Repository() = default;

	/**
	 * \brief Repository deconstructor
	 */
	~Repository() = default;

	/**
	 * \brief Returns the list of elements in repository
	 * \return list of elements in repository
	 */
	const DynamicArray<Element>* getAll() const noexcept{
		return &this->list;
	}

	/**
	 * \brief Adds an element to the list
	 * \param element the element to be added
	 */
	void add(const Element& element) {
		this->list.push_back(element);
	}


	/**
	 * \brief Returns the first foun position of the element in the list
	 * \param element element to search for
	 * \return position of first found element or -1 if not found
	 */
	int find(const Element& element) const {
		for (int i = 0; i < this->list.size(); i++) {
			if (this->list.at(i) == element) {
				return i;
			}
		}
		return  -1;
	}

	/**
	 * \brief Removes an element from the list
	 * \param element element to remove
	 */
	void remove(const Element& element) {
		const int index = this->find(element);
		if (index == -1) {
			throw std::exception("Couldn't find element to remove");
		}
		this->list.erase(index);
	}

	/**
	 * \brief Removes an element found at given index
	 * \param index index of element to remove
	 */
	void remove(const size_t& index) {
		if (index < 0 || index >= this->list.size()) {
			throw std::out_of_range("Index out of range");
		}
		this->list.erase(index);
	}

	/**
	 * \brief Replaces element found at given index with a new one
	 * \param index position to update element
	 * \param element element to replace the old one with
	 */
	void update(const int& index, const Element& element) const {
		if (index < 0 || index >= this->list.size()) {
			throw std::out_of_range("Index out of range");
		}
		this->list.at(index) = element;
	}

	/**
	 * \brief Returns the size of the repository list
	 * \return size of repository list
	 */
	size_t size() const noexcept{
		return this->list.size();
	}

	Element& operator[](const int& index) const {
		// if (index < 0 || index >= this->list.size())
		return this->list.at(index);
	}

	friend std::ostream& operator<<(std::ostream& out, const Repository& repo) {
		for(int i = 0; i < repo.size(); ++i) {
			out << i << ": " << repo.list.at(i) << '\n';
		}
		return out;
	}
};
