#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "Book.h"
#include "Student.h"

//Still a work in progress!!

//function declarations
std::vector<Student*> readStudentRecords();
std::vector<Book*> readBookRecords();
void writeStudentRecords(std::vector<Student*> students);
void writeBookRecords(std::vector<Book*> books);
Book* getBook(std::string bookName);
Student* getStudent(int ID);

//global variables for the books and students vectors
std::vector<Book*> books = readBookRecords();
std::vector<Student*> students = readStudentRecords();

int main()
{
    //userChoice variable to get input from the user
    std::string userChoice;

    //while the user hasn't chose to exit
    while (userChoice != "0") {
        std::cout << "What would you like to do?\n"
            << "[1] Loan a book\n"
            << "[2] Return a book\n"
            << "[3] Modify the details of books\n"
            << "[4] Modify the details of students\n"
            << "[5] Write book and student records to file\n"
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
        //If they choose to modify details of books
        else if (userChoice == "3") {
            std::string userChoiceBooks;

            //deciding whether the user wants to add or remove a book
            std::cout << "What would you like to do>:\n"
                << "[1] Add a book\n"
                << "[2] Remove a book\n";
            std::cin >> userChoiceBooks;

            //if they chose to add a book
            if (userChoiceBooks == "1") {
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
            //if they chose to remove a book
            else if (userChoiceBooks == "2") {
                std::string bookName;

                //getting user input for the name of the book to be deleted
                std::cout << "Please enter the name of the book you wish to delete\n";
                std::cin >> bookName;

                //using getBook to find the book
                Book* book = getBook(bookName);
                //checking to see if the book was found
                if (book == NULL) {
                    std::cout << "Book not found. Please try again\n\n";
                    continue;
                }
                
                //deleting a book !!This may not work!!
                delete book;
            }
        }
        //If they choose to modify details of students
        else if (userChoice == "4") {
            //deciding whether the user wants to add or remove a student
            std::cout << "What would you like to do?:\n"
                << "[1] Add a student\n"
                << "[2] Remove a student\n";

            //getting the user input
            std::string userChoiceStudents;
            std::cin >> userChoiceStudents;

            //if they decide to add a student
            if (userChoiceStudents == "1") {
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
            //if the user decides to delete a student record
            else if (userChoiceStudents == "2") {
                float stuID;

                //getting user input for the student ID
                std::cout << "Please enter the ID of the student you wish to delete.\n";
                std::cin >> stuID;
                //error checking
                while (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid number\n";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cin >> stuID;
                }

                //finding the student using getStudent function
                Student* stu = getStudent(stuID);
                //checking to see if the student was found
                if (stu == NULL) {
                    std::cout << "Student not found. Please try again\n\n";
                    continue;
                }

                //deleting the student !!May not work!!
                delete stu;
            }
        }
        else if (userChoice == "5") {
            writeStudentRecords(students);
            writeBookRecords(books);
        }
        else if(userChoice != "0") {
            std::cout << "\nPlease enter a valid response.\n\n";
        }
    }
}

//function to read the student records from csv file
std::vector<Student*> readStudentRecords() {
    //creating students vector and fstream
    std::vector<Student*> students;
    std::fstream fIn;

    //opening the csv file
    fIn.open("StudentRecords.csv", std::ios::in);

    std::vector<std::string> row;
    std::string line, token, temp;
    
    //while there are still lines to read
    while (fIn >> temp) {
        //Clearing the previous row
        row.clear();
        getline(fIn, line);

        //Creating a stringstream from the temp input
        std::stringstream ss(temp);

        while (std::getline(ss, token, ',')) {
            row.push_back(token);
        }

        //setting variables from the row vector
        //setting ID and name
        int stuID = stoi(row[0]);
        std::string stuFName = row[1];
        std::string stuLName = row[2];

        //setting bookLoaned depending on whether 0 or 1 is written in the file
        bool bookLoaned;
        if (row[3] == "1") { bookLoaned = true; }
        else { bookLoaned = false; };

        //setting the name of the loaned book, if there is one
        Book* loanedBook = getBook(row[4]);


        std::cout << row[0] << std::endl << row[1] << std::endl << row[2] << std::endl << row[3] << std::endl << row[4] << std::endl << std::endl;
        //adding the student to the vector of students
        students.push_back(new Student(stuID, stuFName, stuLName, bookLoaned, loanedBook));
    }
    //returning the vector
    return students;
}

//function to read the book records from the csv file
std::vector<Book*> readBookRecords() {
    //creating books vector and fstream
    std::vector<Book*> books;
    std::fstream fIn;

    //opening the csv file
    fIn.open("BookRecords.csv", std::ios::in);

    std::vector<std::string> row;
    std::string line,token, temp;

    //while there are lines to read
    while (fIn >> temp) {
        //clearing the previous row
        row.clear();
        getline(fIn, line);

        //creating a stringstream from the temp input
        std::stringstream ss(temp);

        //splitting the line by commas
        while (getline(ss, token, ',')) {
            row.push_back(token);
        }

        //setting the book number, book name and author name
        int bookNumber = stoi(row[0]);
        std::string bookName = row[1];
        std::string authorName = row[2];

        //setting onLoan depending on whether 1 or 0 is written in the csv file
        bool onLoan;
        if (row[3] == "1") { onLoan = true; }
        else { onLoan = false; }

        //adding the book to the vector of books
        books.push_back(new Book(bookNumber, bookName, authorName, onLoan));
    }

    //returning the books vector
    return books;
}

void writeStudentRecords(std::vector<Student*> students) {
    //creating fstream
    std::fstream fOut;

    //opening the csv file to be written to
    fOut.open("StudentRecords.csv", std::ios::out | std::ios::trunc);

    //writing each member variable to the csv file, split by commas
    for (int i = 0; i < students.size(); i++) {
        std::string bookName = "NoBook";
        if (students[i]->loanedBook != NULL) {
            bookName = students[i]->loanedBook->getbookName();
        }

        fOut << students[i]->studentID << ","
            << students[i]->firstName << ","
            << students[i]->lastName << ","
            << students[i]->bookLoaned << ","
            << bookName << "\n";
    }
}

void writeBookRecords(std::vector<Book*> books) {
    //creating fstream
    std::fstream fOut;

    //opening the csv file to be written to
    fOut.open("BookRecords.csv", std::ios::out | std::ios::trunc);

    //writing each member variable to the csv file, split by commas
    for (int i = 0; i < books.size(); i++) {
        fOut << books[i]->bookNumber << ","
            << books[i]->bookName << ","
            << books[i]->authorName << ","
            << books[i]->onLoan << "\n";
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

