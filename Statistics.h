#pragma once

#include <vector>

#include "Student.h"
#include "Achievement.h"

void showStatistics(
    const std::vector<Student>& students,
    const std::vector<Achievement>& achievements
);