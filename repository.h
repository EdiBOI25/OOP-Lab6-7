#pragma once
#include <vector>
#include "subject.h"

typedef Subject Element;

class Repository {
private:
	std::vector<Element> list{};
public:
	/**
	 * \brief Repository constructor
	 */
	Repository() {
		this->list = {};
	}

	/**
	 * \brief Returns the list of elements in repository
	 * \return list of elements in repository
	 */
	std::vector<Element> getAll() const {
		return this->list;
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
			if (this->list[i] == element) {
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
		int index = this->find(element);
		if (index == -1) {
			return;
		}
		this->list.erase(this->list.begin() + index);
	}

	/**
	 * \brief Removes an element found at given index
	 * \param index index of element to remove
	 */
	void remove(const int& index) {
		if (index < 0 || index >= this->list.size()) {
			return;
		}
		this->list.erase(this->list.begin() + index);
	}

	/**
	 * \brief Replaces element found at given index with a new one
	 * \param index position to update element
	 * \param element element to replace the old one with
	 */
	void update(const int& index, const Element& element) {
		if (index < 0 || index >= this->list.size()) {
			return;
		}
		this->list[index] = element;
	}

	/**
	 * \brief Returns the size of the repository list
	 * \return size of repository list
	 */
	size_t size() const {
		return this->list.size();
	}

	Element& operator[](const size_t& index) {
		// if (index < 0 || index >= this->list.size())
		return this->list[index];
	}
};
