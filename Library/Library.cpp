#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"

//function declarations
Book* getBook(std::string bookName);
Student* getStudent(int ID);

//global variables for the books and students vectors
std::vector<Book*> books;
std::vector<Student*> students;

int main()
{
    //userChoice variable to get input from the user
    std::string userChoice;

    //while the user hasn't chose to exit
    while (userChoice != "0") {
        std::cout << "What would you like to do?\n"
            << "[1] Loan a book\n"
            << "[2] Return a book\n"
            << "[3] View the details of books\n"
            << "[4] Add a new book\n"
            << "[5] View the details of students\n"
            << "[6] Add a new student\n"
            << "[7] Delete all records\n"
            << "[0] Exit\n";
        std::cin >> userChoice;

        //using if statements to decide what to do based on the user's choice
        //if they choose to loan a book
        if (userChoice == "1") {
            int stuID;
            std::string bookToLoanName;

            //getting input for the student ID
            std::cout << "Please enter the ID of the student the book will be loaned to.\n";
            std::cin >> stuID;

            //error checking 
            while (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number\n";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> stuID;
            }

            //finding the student using the getStudent function
            Student* stuLoan = getStudent(stuID);

            //checking to see if the student was found
            if (stuLoan == NULL) {
                std::cout << "Student not found. Please try again.\n\n";
                continue;
            }

            //getting user input for the book name
            std::cout << "Please enter the name of the book to be loaned\n";
            std::cin >> bookToLoanName;

            //finding the book using the getBook function
            Book* toLoan = getBook(bookToLoanName);

            //checking to see if the book was found
            if (toLoan == NULL) {
                std::cout << "Book not found. Please try again.\n\n";
                continue;
            }

            //calling the loanbook function and calling showloandetails
            stuLoan->loanBook(toLoan);
            std::cout << "\nLoaned book:\n";
            stuLoan->showLoanDetails();
        }
        //if they choose to return a book
        else if (userChoice == "2") {
            int stuID;

            //getting user input for the student ID
            std::cout << "Please enter the ID of the student who will be returning the book'\n";
            std::cin >> stuID;

            //error checking
            while (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number\n";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> stuID;
            }

            //finding the student using the getStudent function
            Student* stuReturn = getStudent(stuID);
            if (stuReturn == NULL) {
                std::cout << "Student not found. Please try again.\n\n";
                continue;
            }

            //calling the returnbook function
            stuReturn->returnBook();
        }
        else if (userChoice == "3") {
            //view details of books
            for (int i = 0; i < books.size(); i++) {
                books[i]->showDetails();
            }
        }
        //If they choose to add a book
        else if (userChoice == "4") {
            float bookIDNum;
            std::string bookName;
            std::string authName;

            //getting user input for the ISBN number
            std::cout << "Please enter the ISBN number of the book\n";
            std::cin >> bookIDNum;

            //error checking
            while (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number\n";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> bookIDNum;
            }

            //getting user input for the name of the book
            std::cout << "Please enter the name of the book\n";
            std::cin >> bookName;

            //getting user input for the name of the author
            std::cout << "Please enter the name of the author\n";
            std::cin >> authName;

            //creating a new book and pushing it to the books vector
            books.push_back(new Book(bookIDNum, bookName, authName, false));
        }
        else if (userChoice == "5") {
            //view details of students
            for (int i = 0; i < students.size(); i++)
                students[i]->showStudentDetails();
        }   
        //If they choose to add a student
        else if (userChoice == "6") {
            float stuID;
            std::string stuFName;
            std::string stuLName;

            //getting user input for the student's ID number
            std::cout << "Please enter the ID number to be assigned to the new student.\n";
            std::cin >> stuID;

            //error checking
            while (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number\n";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> stuID;
            }

            //getting user input for the first name of the student
            std::cout << "Please enter the first name of the student.\n";
            std::cin >> stuFName;

            //getting user input for the last name of the student
            std::cout << "Please enter the last name of the student.\n";
            std::cin >> stuLName;

            //creating a new student and pushing it to the students vector
            students.push_back(new Student(stuID, stuFName, stuLName));
        }
        else if (userChoice == "7") {
            //deleting all objects in students vector
            for (auto it = students.begin(); it != students.end(); it++)
                delete* it;

            //clearing the vector
            students.clear();
            std::cout << "Students vector cleared.\n";

            //deleting all objects in books vector
            for (auto it = books.begin(); it != books.end(); it++)
                delete* it;

            //clearing the vector
            books.clear();
            std::cout << "Books vector cleared.\n";

        }
        else if(userChoice != "0") {
            std::cout << "\nPlease enter a valid response.\n\n";
        }
    }
}

//getBook function to query book by name and return book pointer
Book* getBook(std::string bookName) {
    //checking each book in the vector to see if the book name matches
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getbookName() == bookName) {
            return books[i];
        }
    }
    //if it is not found then the function returns NULL
    return NULL;
}

//getStudent function to query student by student ID and return student pointer
Student* getStudent(int ID) {
    //checking each book in the vector to see if the student ID matches
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getStuID() == ID) {
            return students[i];
        }
    }
    //if it is not found then the function returns NULL
    return NULL;
}

