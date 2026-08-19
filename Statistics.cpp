#include "Statistics.h"

#include <iostream>

void showStatistics(
    const std::vector<Student>& students,
    const std::vector<Achievement>& achievements
)
{
    std::cout << "\n===== Statistics =====\n";

    std::cout << "Total students: "
              << students.size()
              << '\n';

    std::cout << "Total achievements: "
              << achievements.size()
              << '\n';

    if (!students.empty())
    {
        double average =
            static_cast<double>(achievements.size())
            / students.size();

        std::cout << "Average achievements per student: "
                  << average
                  << '\n';
    }
    else
    {
        std::cout << "Average achievements per student: 0\n";
    }
}