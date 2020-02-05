#include "Student.h"
#include <iostream>

Student::Student(int ID, std::string fName, std::string lName){
	studentID = ID;
	firstName = fName;
	lastName = lName;
}

Student::Student() {

}

Student::~Student() {
	std::cout << "Student record deleted.\n";
}

void Student::loanBook(Book* book)
{
	if (bookLoaned == false && book->getOnLoan() == false) {
		loanedBook = book;
		bookLoaned = true;
		book->setOnLoan(true);
	}
	else {
		std::cout << "Student has not returned their previous book or book is already loaned.\n";
	}
}

void Student::returnBook() {
	loanedBook->setOnLoan(false);
	bookLoaned = false;
	loanedBook = nullptr;
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
