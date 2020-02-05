#include <iostream>
#include <vector>
#include "Book.h"
#include "Student.h"

std::vector<Book*> books;
std::vector<Student*> students;

//getBook function to query book by name and return book pointer
Book* getBook(std::string bookName) {
    for (int i = 0; i < books.size();i++) {
        if (books[i]->getbookName() == bookName) {
            return books[i];
        }
    }
    return NULL;
}

//getStudent function to query student by student ID and return student pointer
Student* getStudent(int ID) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getStuID() == ID) {
            return students[i];
        }
    }
    return NULL;
}

int main()
{
    //userChoice variable to get input from the user
    std::string userChoice;
    while (userChoice != "Exit") {
        std::cout << "What would you like to do?\n"
            << "[1] Loan a book\n"
            << "[2] Return a book\n"
            << "[3] Modify the details of books\n"
            << "[4] Modify the details of students\n"
            << "[0] Exit\n";
        std::cin >> userChoice;

        //using if statements to decide what to do based on the user's choice
        //if they choose to loan a book
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
            std::cout << "\nLoaned book:\n";
            stuLoan->showLoanDetails();
        }
        //if they choose to return a book
        else if (userChoice == "2") {
            int stuID;

            std::cout << "Please enter the ID of the student who will be returning the book'\n";
            std::cin >> stuID;

            Student* stuReturn = getStudent(stuID);

            stuReturn->returnBook();
        }
        //If they choose to modify details of books
        else if (userChoice == "3") {
            std::cout << "What would you like to do>:\n"
                << "[1] Add a book\n"
                << "[2] Remove a book\n"
                << "[3] Edit the details of a book\n";
            std::string userChoiceBooks;
            std::cin >> userChoiceBooks;

            if (userChoiceBooks == "1") {
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
            else if (userChoiceBooks == "2") {
                std::string bookName;

                std::cout << "Please enter the name of the book you wish to delete\n";
                std::cin >> bookName;

                for (int i = 0; i < sizeof(books)/sizeof(books[0]); i++){
                    if (books[i]->getbookName() == bookName) {
                        delete books[i];
                    }
                }
            }
            else if (userChoiceBooks == "3") {
                std::string bookName;
                Book* toEdit = new Book();

                std::cout << "Please enter the name of the book you wish to change the details of.\n";
                std::cin >> bookName;

                Book* toEdit = getBook(bookName);
                toEdit->showDetails();
            }
        }
        //If they choose to modify details of students
        else if (userChoice == "4") {
            std::cout << "What would you like to do?:\n"
                << "[1] Add a student\n"
                << "[2] Remove a student\n"
                << "[3] Edit the details of a student\n";

            std::string userChoiceStudents;
            std::cin >> userChoiceStudents;

            if (userChoiceStudents == "1") {
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
            else if (userChoiceStudents == "2") {
                float stuID;

                std::cout << "Please enter the ID of the student you wish to delete.\n";
                std::cin >> stuID;

                Student* stu = getStudent(stuID);
                delete stu;
            }
            else if (userChoice == "3") {
                float stuID;
                std::cout << "Please enter the ID of the student you wish to change the details of\n";
                std::cin >> stuID;

                Student* stu = getStudent(stuID);
            }
        }
        userChoice = "";
    }
}