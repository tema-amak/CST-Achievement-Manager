#pragma once

#include <string>
#include <vector>

#include "Student.h"

struct Achievement
{
    std::string studentId;
    std::string academicYear;
    std::string category;
    std::string title;
    std::string result;
    std::string level;
    std::string certificate;
    std::string remarks;
};

void loadAchievements(
    std::vector<Achievement>& achievements
);

void saveAchievements(
    const std::vector<Achievement>& achievements
);

void showStudentAchievements(
    const std::vector<Achievement>& achievements,
    const std::string& studentId
);

void addAchievement(
    const std::vector<Student>& students,
    std::vector<Achievement>& achievements
);

void editAchievement(
    std::vector<Achievement>& achievements
);

void deleteAchievement(
    std::vector<Achievement>& achievements
);

void displayAchievement(
    const Achievement& achievement,
    int number
);

std::string toLowerCase(std::string text);

void showFilteredAchievements(
    const std::vector<Achievement>& achievements,
    int filterChoice,
    const std::string& filterValue
);

void filterAchievements(
    const std::vector<Achievement>& achievements
);