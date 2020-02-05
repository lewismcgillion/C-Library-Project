#pragma once
#include "Book.h"
#include <string>

class Student {
private:
	int studentID;
	std::string firstName;
	std::string lastName;
	bool bookLoaned;
	Book* loanedBook;
public:
	Student(int ID, std::string fName, std::string lName);
	Student();
	~Student();
	void loanBook(Book* book);
	void returnBook();
	void showLoanDetails();
	int getStuID();
};