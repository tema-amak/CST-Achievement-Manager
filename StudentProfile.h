#pragma once

#include <vector>

#include "Student.h"
#include "Achievement.h"

void showStudentProfile(
    const Student& student,
    const std::vector<Achievement>& achievements
);

void searchStudentById(
    const std::vector<Student>& students,
    const std::vector<Achievement>& achievements
);

void searchStudentByName(
    const std::vector<Student>& students,
    const std::vector<Achievement>& achievements
);