#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>

// A Student contains an ID and a name.
struct Student
{
    std::string id;
    std::string name;
};
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

// This function only displays the menu.
// It does not return a value, so we use void.
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
    std::cout << " 6. Exit\n";
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
           std::cout << "Exiting program...\n";
           running = false;
           break;

           default:
           std::cout << "Invalid choice. Please choose 1-6.\n";
           break;
        }
         std::cout << '\n';
     }

    
    return 0;
    }