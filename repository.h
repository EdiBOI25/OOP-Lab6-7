﻿#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "DynamicArray.h"
#include "subject.h"

typedef Subject Element;

class Repository {
private:
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
	~Repository() = default;

	/**
	 * \brief Returns the list of elements in repository
	 * \return list of elements in repository
	 */
	const std::vector<Element>* getAll() const noexcept{
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
	void remove(const Element& element) {
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
	void remove(const size_t& index) {
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
	void update(const int& index, const Element& element) {
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
		for (const auto& s : *repo.getAll()) {
			out << index << ": " << s << '\n';
			index++;
		}
		return out;
	}
};
