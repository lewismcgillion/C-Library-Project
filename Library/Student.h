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
	std::string loanedBookName;
public:
	Student(int ID, std::string fName, std::string lName);
	Student(int ID, std::string fName, std::string lName, bool bLoaned, std::string loanedBName);
	~Student();
	void loanBook(Book* book);
	void returnBook();
	void showLoanDetails();
	int getStuID();
	friend void writeStudentRecords(std::vector<Student*> students);
};