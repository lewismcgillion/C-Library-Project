#pragma once
#include <string>

class Book {
private:
	int bookNumber;
	std::string bookName;
	std::string authorName;
	bool onLoan;
public:
	Book(int num,std::string name, std::string author);
	~Book();
	bool getOnLoan();
	void setOnLoan(bool flag);
	void showDetails();
	std::string getbookName();
};