#include <cassert>
#include <iostream>

#include "subject.h"
#include "repository.h"
#include "service.h"

void test_domain() {
	Subject empty_subject;
	
	assert(std::empty(empty_subject.getName()));
	assert(empty_subject.getHours() == 0);
	assert(std::empty(empty_subject.getType()));
	assert(std::empty(empty_subject.getTeacher()));

	Subject maths{ "math", 5, "compulsory", "some dude" };

	assert(maths.getName() == "math");
	assert(maths.getHours() == 5);
	assert(maths.getType() == "compulsory");
	assert(maths.getTeacher() == "some dude");

	maths.setName("math2");
	assert(maths.getName() == "math2");
	maths.setHours(10);
	assert(maths.getHours() == 10);
	maths.setTeacher("other dude");
	assert(maths.getTeacher() == "other dude");
	maths.setType("optional");
	assert(maths.getType() == "optional");

	std::cout << maths << '\n';
}

void test_repository() {
	Repository repo;

	repo.add(Subject("math", 5, "compulsory", "some dude"));
	repo.add(Subject("english", 3, "optional", "other dude"));
	repo.add(Subject("physics", 4, "compulsory", "another dude"));

	assert(repo.size() == 3);

	std::vector<Subject> subjects = repo.getAll();
	assert(subjects[0].getName() == "math");
}

void test_service() {
	Repository repo;
	Service service(repo);

	service.addSubject("math", 5, "compulsory", "some dude");
	service.addSubject("english", 3, "optional", "other dude");
	service.addSubject("physics", 4, "compulsory", "another dude");

	assert(service.size() == 3);

	std::vector<Subject> subjects = service.getAll();
	assert(subjects[0].getName() == "math");
}
