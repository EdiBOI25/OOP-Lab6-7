#include <algorithm>
#include <cassert>
#include <iostream>
#include <exception>

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

	const Subject math_copy = maths2;
	assert(math_copy == maths2);
}

//void test_dynamic_array() {
//	DynamicArray<int> list{-3};
//
//	list.push_back(1);
//	list.push_back(5);
//	list.push_back(4);
//	list.push_back(7);
//	list.push_back(2);
//
//	assert(list.size() == 5);
//	assert(list.at(3) == 7);
//	try {
//		const int k = list.at(100);
//		std::cout << k << '\n';
//	}
//	catch(const std::exception& e) {
//		assert(string(e.what()) == "Index out of range");
//	}
//
//	try {
//		list.erase(100);
//	}
//	catch(const std::exception& e) {
//		assert(string(e.what()) == "Index out of range");
//	}
//	list.erase(1);
//	assert(list.size() == 4);
//	assert(list.at(1) == 4);
//}

void test_repository() {
	Repository repo;

	repo.add(Subject("math", 5, "compulsory", "some dude"));
	repo.add(Subject("english", 3, "optional", "other dude"));
	repo.add(Subject("physics", 4, "compulsory", "another dude"));

	assert(repo.size() == 3);

	const std::vector<Subject>* subjects = repo.getAll();
	std::cout << subjects->at(0);
	assert(subjects->at(0).getName() == "math");

	Element ceva = repo[1];
	assert(ceva.getHours() == 3);

	assert(repo.find(ceva) == 1);
	assert(repo.find(Subject("aksjdh", 10, "kasjdh", "sjhrgb")) == -1);

	Subject new_s = Subject("aaaa", 10, "aa", "asdasd");
	try {
		repo.update(100, new_s);
	}
	catch (const std::exception& e) {
		assert(string(e.what()) == "Index out of range");
	}
	repo.update(0, new_s);
	assert(repo[0].getName() == "aaaa");

	try {
		repo.remove(10);
	}
	catch(const std::exception& e) {
		assert(string(e.what()) == "Index out of range");
	}
	assert(repo.size() == 3);
	try {
		repo.remove(Subject("surjfskjrf", 50, "sjfh", "ksjdfh"));
	}
	catch(const std::exception& e) {
		assert(string(e.what()) == "Couldn't find element to remove");
	}
	assert(repo.size() == 3);
	repo.remove(ceva);
	assert(repo.size() == 2);
	repo.remove(1);
	assert(repo.size() == 1);

	std::cout << repo << '\n';
}

void test_service() {
	Service service;

	service.addSubject("math", 5, "compulsory", "some dude");
	service.addSubject("english", 3, "optional", "other dude");
	service.addSubject("physics", 4, "compulsory", "another dude");
	try {
		service.addSubject("physics", 4, "compulsory", "another dude");
	}
	catch(const std::exception& e) {
		assert(string(e.what()) == "Subject already exists");
	}

	assert(service.size() == 3);

	const std::vector<Subject>* subjects = service.getAll();
	assert(subjects->at(0).getName() == "math");

	assert(service.findSubject("english", 3, "optional", "other dude") == 1);
	assert(service.findSubject("skfdjhg", 3, "optional", "other dude") == -1);

	try {
		service.updateSubject(100, "aaaa", 10, "aa", "asdasd");
	}
	catch(const std::exception& e) {
		assert(string(e.what()) == "Index out of range");
	}
	service.updateSubject(0, "aaaa", 10, "aa", "asdasd");
	assert(service.getAll()->at(0).getName() == "aaaa");
	try {
		service.updateSubject(0, "aaaa", 10, "aa", "asdasd");
	}
	catch (const std::exception& e) {
		assert(string(e.what()) == "Subject already exists");
	}

	try {
		service.removeSubject(10);
	}
	catch (const std::exception& e) {
		assert(string(e.what()) == "Index out of range");
	}
	assert(service.size() == 3);
	service.removeSubject(1);
	assert(service.size() == 2);

	std::vector<Subject> filtered_array = service.filter([](const Subject& subject) {
		return subject.getType() == "compulsory";
		});
	assert(filtered_array.size() == 1);

	service.addSubject("s5", 30, "shliefushdf", "aoidsj sdfjh");
	service.addSubject("s1", 14, "aosidushidufh", "ndrkgj sdfjh");
	service.addSubject("s3", 12, "skvjdbvk", "awkjnd sdfjh");
	service.addSubject("s7", 40, "oe8ufows", "blfg sdfjh");
	service.addSubject("s2", 12, "bndiufnb", "soeuif sdfjh");
	service.addSubject("s10", 2, "shliefushdf", "aoidsj sdfjh");

	std::vector<Subject> sorted_array1 = service.sort([](const Subject& s1, const Subject& s2) {
		return s1.getHours() < s2.getHours();
		}, false);

	assert(sorted_array1.at(0).getName() == "s10");
	assert(sorted_array1.at(3).getName() == "s3");

	std::vector<Subject> sorted_array2 = service.sort([](const Subject& s1, const Subject& s2) {
		return s1.getName() < s2.getName();
		}, true);
	assert(sorted_array2.at(0).getName() == "s7");
	assert(sorted_array2.at(3).getName() == "s2");

	std::cout << service;
}