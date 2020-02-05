#include "Book.h"
#include <iostream>

Book::Book(int num, std::string name, std::string author) {
	bookNumber = num;
	bookName = name;
	authorName = author;
}

Book::Book() {
	bookNumber = 0;
	bookName = "";
	authorName = "";
}

bool Book::getOnLoan() {
	return onLoan;
}

void Book::setOnLoan(bool flag) {
	onLoan = flag;
}

void Book::showDetails() {
	std::cout << "Book number : " << bookNumber << "\nBook name : " << bookName << "\nAuthor name : " << authorName;
}

std::string Book::getbookName() {
	return bookName;
}