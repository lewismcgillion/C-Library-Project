#include <iostream>
#include <vector>
#include "Book.h"
#include "Student.h"

std::vector<Book*> books;
std::vector<Student*> students;

Book* getBook(std::string bookName) {
    for (int i = 0; i < books.size();i++) {
        if (books[i]->getbookName() == bookName) {
            return books[i];
        }
    }
    return NULL;
}

Student* getStudent(int ID) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getStuID == ID) {
            return students[i];
        }
    }
    return NULL;
}

int main()
{
    std::string userChoice;
    while (userChoice != "Exit") {
        std::cout << "What would you like to do?\n"
            << "[1] Loan a book\n"
            << "[2] Return a book\n"
            << "[3] Modify the details of books\n"
            << "[4] Modify the details of students\n"
            << "[0] Exit\n";
        std::cin >> userChoice;
        if (userChoice == "1") {
            int stuID;
            std::string bookToLoanName;

            std::cout << "Please enter the ID of the student the book will be loaned to.\n";
            std::cin >> stuID;

            Student* stuLoan = getStudent(stuID);

            std::cout << "Please enter the name of the book to be loaned\n";
            std::cin >> bookToLoanName;

            Book* toLoan = getBook(bookToLoanName);

            stuLoan->loanBook(toLoan);
        }
        else if (userChoice == "2") {
            int stuID;

            std::cout << "Please enter the ID of the student who will be returning the book'\n";
            std::cin >> stuID;

            Student* stuReturn = getStudent(stuID);

            stuReturn->returnBook();
        }
        else if (userChoice == "3") {
            std::cout << "What would you like to do>:\n"
                << "[1] Add a book\n"
                << "[2] Remove a book\n"
                << "[3] Edit the details of a book\n";
            std::cin >> userChoice;

            if (userChoice == "1") {
                float bookIDNum;
                std::string bookName;
                std::string authName;

                std::cout << "Please enter the ISBN number of the book\n";
                std::cin >> bookIDNum;
                std::cout << "Please enter the name of the book\n";
                std::cin >> bookName;
                std::cout << "Please enter the name of the author\n";
                std::cin >> authName;

                books.push_back(new Book(bookIDNum, bookName, authName));
            }
            else if (userChoice == "2") {
                std::string bookName;

                std::cout << "Please enter the name of the book you wish to delete\n";
                std::cin >> bookName;

                for (int i = 0; i < sizeof(books)/sizeof(books[0]); i++){
                    if (books[i]->getbookName() == bookName) {
                        delete books[i];
                    }
                }
            }


        }
        else if (userChoice == "4") {
            std::cout << "What would you like to do?:\n"
                << "[1] Add a student\n"
                << "[2] Remove a student\n"
                << "[3] Edit the details of a student\n";

            //if 1
            float stuID;
            std::string stuFName;
            std::string stuLName;

            std::cout << "Please enter the ID number to be assigned to the new student.\n";
            std::cin >> stuID;
            std::cout << "Please enter the first name of the student.\n";
            std::cin >> stuFName;
            std::cout << "Please enter the last name of the student.\n";
            std::cin >> stuLName;

            students.push_back(new Student(stuID, stuFName, stuLName));
        }
        userChoice = "";
    }
}