#include "Student.h"
#include <iostream>

Student::Student(int ID, std::string fName, std::string lName){
	studentID = ID;
	firstName = fName;
	lastName = lName;
}

Student::Student(int ID, std::string fName, std::string lName, bool bLoaned, std::string loanedBName) {
	studentID = ID;
	firstName = fName;
	lastName = lName;
	bookLoaned = bLoaned;
	loanedBookName = loanedBName;
}

Student::~Student() {
	std::cout << "Student record deleted.\n";
}

void Student::loanBook(Book* book)
{
	if (bookLoaned == false && book->getOnLoan() == false) {
		loanedBookName = book->getbookName;
		bookLoaned = true;
		book->setOnLoan(true);
	}
	else {
		std::cout << "Student has not returned their previous book or book is already loaned.\n";
	}
}

void Student::returnBook() {
	if (bookLoaned != false) {
		loanedBook->setOnLoan(false);
		bookLoaned = false;
		loanedBook = nullptr;
	}
	else {
		std::cout << "Student does not have a book on loan.\n\n";
	}
}

void Student::showLoanDetails() {
	if (bookLoaned) {
		loanedBook->showDetails();
	}
	else {
		std::cout << "No book is loaned.\n";
	}
}

int Student::getStuID() {
	return studentID;
}
