#pragma once
#include <string>
#include <vector>

class Book {
private:
	int bookNumber;
	std::string bookName;
	std::string authorName;
	bool onLoan = false;
public:
	Book(int num, std::string name, std::string author, bool loan);
	Book();
	bool getOnLoan();
	void setOnLoan(bool flag);
	void showDetails();
	std::string getbookName();
	friend void writeBookRecords(std::vector<Book*> books);
};