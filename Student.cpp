#include "Student.h"

#include <iostream>
#include <fstream>

void loadStudents(std::vector<Student>& students)
{
    std::ifstream file("students.csv");

    if (!file.is_open())
    {
        std::cout << "Could not open students.csv\n";
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::size_t commaPosition = line.find(',');

        if (commaPosition == std::string::npos)
        {
            continue;
        }

        Student student;

        student.id = line.substr(0, commaPosition);
        student.name = line.substr(commaPosition + 1);

        students.push_back(student);
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

bool studentIdExists(
    const std::vector<Student>& students,
    const std::string& id
)
{
    for (const Student& student : students)
    {
        if (student.id == id)
        {
            return true;
        }
    }

    return false;
}
void saveStudents(const std::vector<Student>& students)
{
    std::ofstream file("students.csv");

    if (!file.is_open())
    {
        std::cout << "Could not save students.csv\n";
        return;
    }

    for (const Student& student : students)
    {
        file << student.id << ','
             << student.name << '\n';
    }
}
void addStudent(std::vector<Student>& students)
{
    Student newStudent;

    std::cout << "Enter student ID: ";
    std::cin >> newStudent.id;

    if (studentIdExists(students, newStudent.id))
    {
        std::cout << "A student with this ID already exists.\n";
        return;
    }

    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, newStudent.name);

    students.push_back(newStudent);

    saveStudents(students);

    std::cout << "Student added successfully.\n";
}
void editStudent(std::vector<Student>& students)
{
    std::string studentId;

    std::cout << "Enter student ID: ";
    std::cin >> studentId;

    for (Student& student : students)
    {
        if (student.id == studentId)
        {
            std::cout << "Current name: "
                      << student.name << '\n';

            std::cout << "Enter new name: ";
            std::getline(std::cin >> std::ws, student.name);

            saveStudents(students);

            std::cout << "Student updated successfully.\n";
            return;
        }
    }

    std::cout << "Student not found.\n";
}
