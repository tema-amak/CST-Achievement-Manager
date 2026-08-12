#include <iostream>
#include <string>
#include <vector>
#include <limits>


// A Student contains an ID and a name.
struct Student
{
    std::string id;
    std::string name;
};


// This function only displays the menu.
// It does not return a value, so we use void.
void showMenu()
{
    std::cout << "====================================\n";
    std::cout << " CST Achievement Manager\n";
    std::cout << "====================================\n";
    std::cout << '\n';

    std::cout << "Welcome!\n";
    std::cout << " 1. Show all students\n";
    std::cout << " 2. Search student by ID\n";
    std::cout << " 3. Search student by name\n";
    std::cout << " 4. Exit\n";
}


// This function gets a valid NUMBER from the user.
int getChoice()
{
    int choice;

    while (true)
    {
        std::cout << "Enter your choice: ";

        // If the user successfully enters an integer:
        if (std::cin >> choice)
        {
            return choice;
        }

        // If the user types something like "hello":
        std::cout << "Invalid input. Please enter a number.\n";

        // Remove cin's error state.
        std::cin.clear();

        // Remove the bad input from the input buffer.
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

void showAllStudents(const std::vector<Student>& students)
{
    for (const Student& student : students)
    {
        std::cout << "Student ID: " << student.id << '\n';
        std::cout << "Student Name: " << student.name << '\n';
        std::cout << '\n';
    }
}

void searchStudentById(const std::vector<Student>& students)
{
    std::string searchId;
    bool found = false;

    std::cout << "Enter student ID: ";
    std::cin >> searchId;

    for (const Student& student : students)
    {
        if (student.id == searchId)
        {
            std::cout << "Student found!\n";
            std::cout << "Student ID: " << student.id << '\n';
            std::cout << "Student Name: " << student.name << '\n';

            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student not found.\n";
    }
}

void searchStudentByName(const std::vector<Student>& students)
{
    std::string searchName;
    bool found = false;

    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, searchName);

    for (const Student& student : students)
    {
        if (student.name == searchName)
        {
            std::cout << "Student found!\n";
            std::cout << "Student ID: " << student.id << '\n';
            std::cout << "Student Name: " << student.name << '\n';

            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student not found.\n";
    }
}

int main()
{
    // -------------------------
    // Temporary sample students
    // -------------------------

    std::vector<Student> students;

    Student student1;
    student1.id = "S001";
    student1.name = "Alice";
    students.push_back(student1);

    Student student2;
    student2.id = "S002";
    student2.name = "Bob Smith";
    students.push_back(student2);

    Student student3;
    student3.id = "S003";
    student3.name = "Charlie";
    students.push_back(student3);


    // Controls whether the program should keep running.
    bool running = true;


    while (running)
    {
        showMenu();

        int choice = getChoice();


        switch (choice)
        {
            // -------------------------
            // Option 1: Show all students
            // -------------------------
            case 1:

                showAllStudents(students);
                break;
            
            // -------------------------
            // Option 2: Search by ID
            // -------------------------
            case 2:
                searchStudentById(students);
                break;

            // -------------------------
            // Option 3: Search by name
            // -------------------------
            case 3:
                searchStudentByName(students);
                break;
        


            // -------------------------
            // Option 4: Exit
            // -------------------------
            case 4:
            {
                std::cout << "Exiting program...\n";

                running = false;

                break;
            }


            // -------------------------
            // Numbers other than 1-4
            // -------------------------
            default:
            {
                std::cout << "Invalid choice. Please choose 1-4.\n";

                break;
            }
        }


        std::cout << '\n';
    }


    return 0;
}