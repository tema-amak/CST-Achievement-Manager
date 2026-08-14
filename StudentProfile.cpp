#include "StudentProfile.h"

#include <iostream>
#include <string>

void showStudentProfile(
    const Student& student,
    const std::vector<Achievement>& achievements
)
{
    std::cout << "\nStudent found!\n";
    std::cout << "Student ID: " << student.id << '\n';
    std::cout << "Student Name: " << student.name << '\n';

    showStudentAchievements(achievements, student.id);
}
void searchStudentById(
    const std::vector<Student>& students,
    const std::vector<Achievement>& achievements
)
{
    std::string searchId;
    bool found = false;

    std::cout << "Enter student ID: ";
    std::cin >> searchId;

    for (const Student& student : students)
    {
        if (student.id == searchId)
        {
           showStudentProfile(student, achievements);

            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student not found.\n";
    }
}
void searchStudentByName(
    const std::vector<Student>& students,
    const std::vector<Achievement>& achievements
)
{
    std::string searchName;
    bool found = false;

    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, searchName);

    for (const Student& student : students)
    {
        if (student.name == searchName)
        {
            showStudentProfile(student, achievements);

            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student not found.\n";
    }
}