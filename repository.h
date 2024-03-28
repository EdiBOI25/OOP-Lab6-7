#pragma once
#include <vector>
#include "subject.h"

typedef Subject Element;

class Repository {
private:
	std::vector<Element> list;
public:
	Repository() {
		this->list = {};
	}

	std::vector<Element> getAll() const {
		return this->list;
	}

	void add(const Element& element) {
		this->list.push_back(element);
	}

	size_t size() const {
		return this->list.size();
	}
};
