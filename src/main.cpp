#include "TaskManager.h"
#include <iostream>
#include <string>

void showMenu() {
    std::cout << "\n===== TASK MANAGER =====\n";
    std::cout << "1. Show all tasks\n";
    std::cout << "2. Add new task\n";
    std::cout << "3. Edit task\n";
    std::cout << "4. Save tasks to file\n";
    std::cout << "5. Load tasks from file\n";
    std::cout << "6. Delete task\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main() 
{
    TaskManager manager;
    bool running = true;

    while (running) 
    {
        showMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); 

        switch(choice) {
            case 1: 
            { 
                manager.showTasks();
                break;
            }
            case 2: 
            { 
                std::string title, description, statusStr, priorityStr;

                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);

statusType status = statusType::UNKNOWN;
                while (status == statusType::UNKNOWN) 
                {
                    std::cout << "Select status:\n";
                    std::cout << "1. TODO\n2. IN_PROGRESS\n3. DONE\n4. FAIL\n";
                    std::cout << "Choice: ";
                    int sChoice;
                    std::cin >> sChoice;
                    std::cin.ignore(); 

                    switch(sChoice) 
                    {
                        case 1: status = statusType::TODO; break;
                        case 2: status = statusType::IN_PROGRESS; break;
                        case 3: status = statusType::DONE; break;
                        case 4: status = statusType::FAIL; break;
                        default: std::cout << "Invalid choice! Try again.\n"; break;
                    }
                }

                priorityType priority = priorityType::UNKNOWN;
                while (priority == priorityType::UNKNOWN) 
                {
                    std::cout << "Select priority:\n";
                    std::cout << "1. LOW\n2. MEDIUM\n3. HIGH\n";
                    std::cout << "Choice: ";
                    int pChoice;
                    std::cin >> pChoice;
                    std::cin.ignore();

                    switch(pChoice) 
                    {
                        case 1: priority = priorityType::LOW; break;
                        case 2: priority = priorityType::MEDIUM; break;
                        case 3: priority = priorityType::HIGH; break;
                        default: std::cout << "Invalid choice! Try again.\n"; break;
                    }
                }
                
                manager.addTask(title, description, status, priority);

                std::cout << "Task added" << std::endl;
                break;
            }
            case 3: 
            { 
                int id;
                std::cout << "Enter task ID to edit: ";
                std::cin >> id;
                std::cin.ignore();

                std::string title, description;
                std::cout << "New title: ";
                std::getline(std::cin, title);
                std::cout << "New description: ";
                std::getline(std::cin, description);

                statusType status = statusType::UNKNOWN;
                while (status == statusType::UNKNOWN) 
                {
                    std::cout << "Select status:\n";
                    std::cout << "1. TODO\n2. IN_PROGRESS\n3. DONE\n4. FAIL\n";
                    std::cout << "Choice: ";
                    int sChoice;
                    std::cin >> sChoice;
                    std::cin.ignore(); 

                    switch(sChoice) 
                    {
                        case 1: status = statusType::TODO; break;
                        case 2: status = statusType::IN_PROGRESS; break;
                        case 3: status = statusType::DONE; break;
                        case 4: status = statusType::FAIL; break;
                        default: std::cout << "Invalid choice! Try again.\n"; break;
                    }
                }

                priorityType priority = priorityType::UNKNOWN;
                while (priority == priorityType::UNKNOWN) 
                {
                    std::cout << "Select priority:\n";
                    std::cout << "1. LOW\n2. MEDIUM\n3. HIGH\n";
                    std::cout << "Choice: ";
                    int pChoice;
                    std::cin >> pChoice;
                    std::cin.ignore();

                    switch(pChoice) 
                    {
                        case 1: priority = priorityType::LOW; break;
                        case 2: priority = priorityType::MEDIUM; break;
                        case 3: priority = priorityType::HIGH; break;
                        default: std::cout << "Invalid choice! Try again.\n"; break;
                    }
                }

                if(manager.editTask(id, title, description, status, priority))
                    std::cout << "Task updated!\n";
                else
                    std::cout << "Failed to update task!\n";

                break;
            }
            case 4: 
            {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::getline(std::cin, filename);

                if(manager.saveToFile(filename))
                    std::cout << "Tasks saved!\n";
                else
                    std::cout << "Failed to save tasks!\n";

                break;
            }
            case 5: 
            {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::getline(std::cin, filename);

                if(manager.loadFromFile(filename))
                    std::cout << "Tasks loaded!\n";
                else
                    std::cout << "Failed to load tasks!\n";

                break;
            }
            case 6: 
            {
                int id;
                std::cout << "Enter task ID to edit: ";
                std::cin >> id;
                std::cin.ignore();

                if(manager.deleteTask(id))
                    std::cout << "Task deleted!\n";
                else
                    std::cout << "Failed to delete task!\n";

                break;
            }
            case 0: 
            {
                running = false;
                break;
            }
            default:
                std::cout << "Invalid option!\n";
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
