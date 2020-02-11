#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
#include "Book.h"
#include "Student.h"

//Still a work in progress!!

std::vector<Book*> books;
std::vector<Student*> students;

std::vector<Student*> readStudentRecords() {
    std::vector<Student*> students;
    std::fstream fIn;
    fIn.open("BookRecords.csv", std::ios::in);

    std::vector<std::string> row;
    std::string line, token, temp;

    while (fIn >> temp) {
        row.clear();

        getline(fIn, line);
        std::istringstream ss(line);

        while (getline(ss, token, ',')) {
            row.push_back(token);
        }
        int stuID = stoi(row[0]);
        std::string stuFName = row[1];
        std::string stuLName = row[2];
        bool bookLoaned;
        if (row[3] == "1") { bookLoaned = true; }
        else { bookLoaned = false; };
        std::string loanedBookName = row[4];

        students.push_back(new Student(stuID, stuFName, stuLName, bookLoaned, loanedBookName));
    }

    return students;
}

std::vector<Book*> readBookRecords() {
    std::vector<Book*> books;
    std::fstream fIn;
    fIn.open("BookRecords.csv", std::ios::in);

    std::vector<std::string> row;
    std::string line, token, temp;

    while (fIn >> temp) {
        row.clear();

        getline(fIn, line);
        std::istringstream ss(line);

        while (getline(ss, token, ',')) {
            row.push_back(token);
        }

        int bookNumber = stoi(row[0]);
        std::string bookName = row[1];
        std::string authorName = row[2];
        bool onLoan;
        if (row[3] == "1") { onLoan = true; }
        else { onLoan = false; }

        books.push_back(new Book(bookNumber, bookName, authorName, onLoan));
    }
    return books;
}

void writeStudentRecords(std::vector<Student*> students) {
    std::fstream fOut;

    fOut.open("StudentRecords.csv", std::ios::out | std::ios::app);

    for (int i = 0; i < students.size(); i++) {
        fOut << students[i]->studentID << ","
            << students[i]->firstName << ","
            << students[i]->lastName << ","
            << students[i]->bookLoaned << ","
            << students[i]->loanedBookName << "\n";
    }
}

void writeBookRecords(std::vector<Book*> books) {
    std::fstream fOut;

    fOut.open("BookRecords.csv", std::ios::out | std::ios::app);

    for (int i = 0; i < books.size(); i++) {
        fOut << books[i]->bookNumber << ","
            << books[i]->bookName << ","
            << books[i]->authorName << ","
            << books[i]->onLoan << "\n";
    }
}


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
    std::fstream fout;
    fout.open("StudentRecords.csv", std::ios::out | std::ios::app);


    //userChoice variable to get input from the user
    std::string userChoice;
    while (userChoice != "0") {
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
            while (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number\n";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> stuID;
            }

            Student* stuLoan = getStudent(stuID);
            if (stuLoan == NULL) {
                std::cout << "Student not found. Please try again.\n\n";
                continue;
            }

            std::cout << "Please enter the name of the book to be loaned\n";
            std::cin >> bookToLoanName;

            Book* toLoan = getBook(bookToLoanName);
            if (toLoan == NULL) {
                std::cout << "Book not found. Please try again.\n\n";
                continue;
            }

            stuLoan->loanBook(toLoan);
            std::cout << "\nLoaned book:\n";
            stuLoan->showLoanDetails();
        }
        //if they choose to return a book
        else if (userChoice == "2") {
            int stuID;

            std::cout << "Please enter the ID of the student who will be returning the book'\n";
            std::cin >> stuID;
            while (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number\n";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> stuID;
            }

            Student* stuReturn = getStudent(stuID);
            if (stuReturn == NULL) {
                std::cout << "Student not found. Please try again.\n\n";
                continue;
            }

            stuReturn->returnBook();
        }
        //If they choose to modify details of books
        else if (userChoice == "3") {
            std::cout << "What would you like to do>:\n"
                << "[1] Add a book\n"
                << "[2] Remove a book\n";
            std::string userChoiceBooks;
            std::cin >> userChoiceBooks;

            if (userChoiceBooks == "1") {
                float bookIDNum;
                std::string bookName;
                std::string authName;

                std::cout << "Please enter the ISBN number of the book\n";
                std::cin >> bookIDNum;
                while (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid number\n";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cin >> bookIDNum;
                }

                std::cout << "Please enter the name of the book\n";
                std::cin >> bookName;
                std::cout << "Please enter the name of the author\n";
                std::cin >> authName;

                books.push_back(new Book(bookIDNum, bookName, authName, false));
            }
            else if (userChoiceBooks == "2") {
                std::string bookName;

                std::cout << "Please enter the name of the book you wish to delete\n";
                std::cin >> bookName;

                Book* book = getBook(bookName);
                if (book == NULL) {
                    std::cout << "Book not found. Please try again\n\n";
                    continue;
                }
                
                delete book;
            }
        }
        //If they choose to modify details of students
        else if (userChoice == "4") {
            std::cout << "What would you like to do?:\n"
                << "[1] Add a student\n"
                << "[2] Remove a student\n";

            std::string userChoiceStudents;
            std::cin >> userChoiceStudents;

            if (userChoiceStudents == "1") {
                float stuID;
                std::string stuFName;
                std::string stuLName;

                std::cout << "Please enter the ID number to be assigned to the new student.\n";
                std::cin >> stuID;
                while (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid number\n";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cin >> stuID;
                }

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
                while (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid number\n";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cin >> stuID;
                }

                Student* stu = getStudent(stuID);
                if (stu == NULL) {
                    std::cout << "Student not found. Please try again\n\n";
                    continue;
                }

                delete stu;
            }
        }
        else {
            std::cout << "\nPlease enter a valid response.\n\n";
        }
        userChoice = "";
    }
}