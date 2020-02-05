#pragma once
#include <string>

class Book {
private:
	int bookNumber;
	std::string bookName;
	std::string authorName;
	bool onLoan = false;
public:
	Book();
	Book(int num,std::string name, std::string author);
	bool getOnLoan();
	void setOnLoan(bool flag);
	void showDetails();
	std::string getbookName();
};