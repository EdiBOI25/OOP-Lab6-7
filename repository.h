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
