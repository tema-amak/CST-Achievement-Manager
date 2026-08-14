#include "Achievement.h"

#include <iostream>
#include <fstream>
#include <sstream>

void loadAchievements(std::vector<Achievement>& achievements)
{
    std::ifstream file("achievements.csv");

    if (!file.is_open())
    {
        std::cout << "Could not open achievements.csv\n";
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::stringstream stream(line);

        Achievement achievement;

        if (!std::getline(stream, achievement.studentId, ','))
            continue;

        if (!std::getline(stream, achievement.academicYear, ','))
            continue;

        if (!std::getline(stream, achievement.category, ','))
            continue;

        if (!std::getline(stream, achievement.title, ','))
            continue;

        if (!std::getline(stream, achievement.result, ','))
            continue;

        if (!std::getline(stream, achievement.level, ','))
            continue;

        if (!std::getline(stream, achievement.certificate, ','))
            continue;

        if (!std::getline(stream, achievement.remarks))
            continue;

        achievements.push_back(achievement);
    }
}
void saveAchievements(const std::vector<Achievement>& achievements)
{
    std::ofstream file("achievements.csv");

    if (!file.is_open())
    {
        std::cout << "Could not save achievements.csv\n";
        return;
    }

    for (const Achievement& achievement : achievements)
    {
        file << achievement.studentId << ','
             << achievement.academicYear << ','
             << achievement.category << ','
             << achievement.title << ','
             << achievement.result << ','
             << achievement.level << ','
             << achievement.certificate << ','
             << achievement.remarks << '\n';
    }
}
void showStudentAchievements(
    const std::vector<Achievement>& achievements,
    const std::string& studentId
)
{
    int count = 0;

    std::cout << "\nAchievements:\n";

    for (const Achievement& achievement : achievements)
    {
        if (achievement.studentId == studentId)
        {
            count++;

            std::cout << "\nAchievement #" << count << '\n';
            std::cout << "Academic Year: " << achievement.academicYear << '\n';
            std::cout << "Category: " << achievement.category << '\n';
            std::cout << "Title: " << achievement.title << '\n';
            std::cout << "Result: " << achievement.result << '\n';
            std::cout << "Level: " << achievement.level << '\n';
            std::cout << "Certificate: " << achievement.certificate << '\n';
            std::cout << "Remarks: " << achievement.remarks << '\n';
        }
    }

    if (count == 0)
    {
        std::cout << "No achievements found for this student.\n";
    }
}
void addAchievement(
    const std::vector<Student>& students,
    std::vector<Achievement>& achievements
)
{
    Achievement newAchievement;

    std::cout << "Enter student ID: ";
    std::cin >> newAchievement.studentId;

    if (!studentIdExists(students, newAchievement.studentId))
    {
        std::cout << "Student does not exist.\n";
        return;
    }

    std::cout << "Enter academic year: ";
    std::getline(std::cin >> std::ws, newAchievement.academicYear);

    std::cout << "Enter category: ";
    std::getline(std::cin, newAchievement.category);

    std::cout << "Enter achievement title: ";
    std::getline(std::cin, newAchievement.title);

    std::cout << "Enter result: ";
    std::getline(std::cin, newAchievement.result);

    std::cout << "Enter level: ";
    std::getline(std::cin, newAchievement.level);

    std::cout << "Enter certificate status: ";
    std::getline(std::cin, newAchievement.certificate);

    std::cout << "Enter remarks: ";
    std::getline(std::cin, newAchievement.remarks);

    achievements.push_back(newAchievement);

    saveAchievements(achievements);

    std::cout << "Achievement added successfully.\n";
}