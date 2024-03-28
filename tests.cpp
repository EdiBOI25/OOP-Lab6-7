#include <cassert>

#include "subject.h"
#include "repository.h"

void test_domain() {
	Subject maths("math", 5, "compulsory", "some dude");

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
}

void test_repository() {
	Repository repo;

	repo.add(Subject("math", 5, "compulsory", "some dude"));
	repo.add(Subject("english", 3, "optional", "other dude"));
	repo.add(Subject("physics", 4, "compulsory", "another dude"));

	assert(repo.size() == 3);
}
