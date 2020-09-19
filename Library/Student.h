#pragma once
#include "Book.h"
#include <string>
#include <vector>

class Student {
private:
	int studentID;
	std::string firstName;
	std::string lastName;
	bool bookLoaned;
	Book* loanedBook;
public:
	Student(int ID, std::string fName, std::string lName);
	Student(int ID, std::string fName, std::string lName, bool bLoaned, Book* loanedB);
	~Student();
	void loanBook(Book* book);
	void returnBook();
	void showStudentDetails();
	void showLoanDetails();
	int getStuID();
	friend void writeStudentRecords(std::vector<Student*> students);
};