#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Achievement.h"
#include "StudentProfile.h"

void showMenu()
{
    std::cout << "====================================\n";
    std::cout << " CST Achievement Manager\n";
    std::cout << "====================================\n\n";

    std::cout << "Welcome!\n";
    
std::cout << " 1. Show all students\n";
std::cout << " 2. Search student by ID\n";
std::cout << " 3. Search student by name\n";
std::cout << " 4. Add student\n";
std::cout << " 5. Add achievement\n";
std::cout << " 6. Edit achievement\n";
std::cout << " 7. Delete achievement\n";
std::cout << " 8. Edit student\n";
std::cout << " 9. Delete student\n";
std::cout << " 10. Filter achievements\n";
std::cout << " 11. Exit\n";
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


int main()
{
    // -------------------------
    // Temporary sample students
    // -------------------------

    std::vector<Student> students;
    std::vector<Achievement> achievements;

     loadStudents(students);
     loadAchievements(achievements);
     std::cout << "Loaded "
          << achievements.size()
          << " achievements.\n\n";
   
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

                searchStudentById(students, achievements);
                break;

            // -------------------------
            // Option 3: Search by name
            // -------------------------
            case 3:
                searchStudentByName(students, achievements);
                break;
        


            // -------------------------
            // Option 4: Exit
            // -------------------------
           case 4:
           addStudent(students);
           break;

          case 5:
    addAchievement(students, achievements);
    break;

case 6:
    editAchievement(achievements);
    break;

case 7:
    deleteAchievement(achievements);
    break;

case 8:
    editStudent(students);
    break;

case 9:
    deleteStudent(students, achievements);
    break;

case 10:
    filterAchievements(achievements);
    break;

case 11:
    std::cout << "Exiting program...\n";
    running = false;
    break;

default:
    std::cout << "Invalid choice. Please choose 1-11.\n";
    break;
         }
         std::cout << '\n';
     }

    
    return 0;
    }