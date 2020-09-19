#include "Student.h"
#include <iostream>

//student constructor, takes three parameters and sets bookloaned and loanedbookname to default values
Student::Student(int ID, std::string fName, std::string lName){
	studentID = ID;
	firstName = fName;
	lastName = lName;
}

//student constructor, takes parameters for all member variabes and sets them accordingly
Student::Student(int ID, std::string fName, std::string lName, bool bLoaned, Book* loanedB) {
	studentID = ID;
	firstName = fName;
	lastName = lName;
	bookLoaned = bLoaned;
	loanedBook = loanedB;
}

//students destructor
Student::~Student() {
	std::cout << "Student record deleted.\n";
}

//loanBook function
void Student::loanBook(Book* book)
{
	//Checking to see whether the student currently has a book on loan or whether the book is already loaned
	if (bookLoaned == false && book->getOnLoan() == false) {
		//setting variables for the student and the book
		loanedBook = book;
		bookLoaned = true;
		book->setOnLoan(true);
	}
	else {
		std::cout << "Student has not returned their previous book or book is already loaned.\n";
	}
}

//returnBook function
void Student::returnBook() {
	//If the student has a book on loan
	if (bookLoaned != false) {
		//setting the variables for the student and the book
		loanedBook->setOnLoan(false);
		bookLoaned = false;
		loanedBook = nullptr;
	}
	else {
		std::cout << "Student does not have a book on loan.\n\n";
	}
}

void Student::showStudentDetails() {
	//outputting details of the student
	std::cout << "\tStudent ID = " << studentID << "\n\tFirst Name = " << firstName << "\n\tLast Name = " << lastName << "\n\tBook Loaned? = ";
	if (bookLoaned) {
		std::cout << "Yes\n";
		std::cout << "Book name = " << loanedBook->getbookName();
	}
	else {
		std::cout << "No\n\n";
	}
}

//displaying the loan details
void Student::showLoanDetails() {
	//if the student has a book on loan
	if (bookLoaned) {
		//calling the showDetails function for the loaned book
		loanedBook->showDetails();
	}
	else {
		std::cout << "No book is loaned.\n";
	}
}

//student ID getter
int Student::getStuID() {
	return studentID;
}
