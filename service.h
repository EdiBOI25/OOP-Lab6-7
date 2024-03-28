#pragma once
#include "repository.h"

class Service {
private:
	Repository repo;

public:

	Service(const Repository& repo);

	std::vector<Subject> getAll() const;

	void add(const Subject& subject);

	size_t size() const;
};
