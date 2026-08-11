#include <iostream>
void showMenu(){ //we use void 
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
int main()
{
    bool running = true;

    while (running)
    {
        showMenu();
        int choice;

        std::cout << "Enter Your Choice: ";
        std::cin >> choice;

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