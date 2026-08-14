#pragma once

#include <string>
#include <vector>

struct Student
{
    std::string id;
    std::string name;
};

void loadStudents(std::vector<Student>& students);

void showAllStudents(const std::vector<Student>& students);

bool studentIdExists(
    const std::vector<Student>& students,
    const std::string& id
);

void saveStudents(const std::vector<Student>& students);

void addStudent(std::vector<Student>& students);