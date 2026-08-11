#include <iostream>
void showMenu(){ 
// We use a void function when we want the function to do a task
// but not return any value, such as printing something or changing a variable.

     std::cout << "====================================\n";
        std::cout << " CST Achievement Manager\n";
        std::cout << "====================================\n";
        std::cout << '\n';

        std::cout << "Welcome!\n";
        std::cout << " 1. Show all students\n";
        std::cout << " 2. Search student by ID\n";
        std::cout << " 3. Search student by name\n";
        std::cout << " 4. Exit\n";

}
int getChoise(){
    int choice;
    std::cout<<"Enter your choise: ";
    std::cin>>choice;
    return choice;
}
int main()
{
    bool running = true;

    while (running)
    {
        showMenu();
        int choice = getChoise();
        switch (choice)
        {
            case 1:
                std::cout << "Showing all students...\n";
                break;

            case 2:
                std::cout << "Searching student by ID...\n";
                break;

            case 3:
                std::cout << "Searching student by name...\n";
                break;

            case 4:
                std::cout << "Exiting program...\n";
                running = false;
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

        std::cout << '\n';
    }

    return 0;
}