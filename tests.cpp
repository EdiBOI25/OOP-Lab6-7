﻿#include <cassert>
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

	Subject maths2{ "math2", 10, "optional", "other dude" };
	Subject maths3{ "math", 10, "compulsory", "some dude" };
	std::cout << maths << '\n';

	assert(maths == maths2);
	assert(maths != maths3);

	Subject math_copy = maths2;
	assert(math_copy == maths2);
}

void test_repository() {
	Repository repo;

	repo.add(Subject("math", 5, "compulsory", "some dude"));
	repo.add(Subject("english", 3, "optional", "other dude"));
	repo.add(Subject("physics", 4, "compulsory", "another dude"));

	assert(repo.size() == 3);

	const std::vector<Subject> subjects = *repo.getAll();
	std::cout << subjects[0];
	assert(subjects[0].getName() == "math");

	Element ceva = repo[1];
	assert(ceva.getHours() == 3);

	assert(repo.find(ceva) == 1);
	assert(repo.find(Subject("aksjdh", 10, "kasjdh", "sjhrgb")) == -1);

	Subject new_s = Subject("aaaa", 10, "aa", "asdasd");
	repo.update(100, new_s);
	repo.update(0, new_s);
	assert(repo[0].getName() == "aaaa");

	repo.remove(10);
	assert(repo.size() == 3);
	repo.remove(Subject("surjfskjrf", 50, "sjfh", "ksjdfh"));
	assert(repo.size() == 3);
	repo.remove(ceva);
	assert(repo.size() == 2);
	repo.remove(1);
	assert(repo.size() == 1);
}

void test_service() {
	Service service;

	service.addSubject("math", 5, "compulsory", "some dude");
	service.addSubject("english", 3, "optional", "other dude");
	service.addSubject("physics", 4, "compulsory", "another dude");

	assert(service.size() == 3);

	const std::vector<Subject> subjects = *service.getAll();
	assert(subjects.at(0).getName() == "math");

	assert(service.findSubject("english", 3, "optional", "other dude") == 1);
	assert(service.findSubject("skfdjhg", 3, "optional", "other dude") == -1);

	service.updateSubject(100, "aaaa", 10, "aa", "asdasd");
	service.updateSubject(0, "aaaa", 10, "aa", "asdasd");
	assert(service.getAll()->at(0).getName() == "aaaa");

	service.removeSubject(10);
	assert(service.size() == 3);
	service.removeSubject(1);
	assert(service.size() == 2);
}