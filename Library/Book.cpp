#include "Book.h"
#include <iostream>

//constructor for book
Book::Book(int num, std::string name, std::string author, bool loan) {
	bookNumber = num;
	bookName = name;
	authorName = author;
	onLoan = loan;
}

//default constructor for book which sets the variables to default values
Book::Book() {
	bookNumber = 0;
	bookName = "";
	authorName = "";
	onLoan = false;
}

//onloan getter
bool Book::getOnLoan() {
	return onLoan;
}

//onloan setter
void Book::setOnLoan(bool flag) {
	onLoan = flag;
}

//function to show the details of the book
void Book::showDetails() {
	std::cout << "Book number : " << bookNumber << "\nBook name : " << bookName << "\nAuthor name : " << authorName << std::endl;
}

//book name getter
std::string Book::getbookName() {
	return bookName;
}