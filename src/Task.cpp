#include "Task.h"
#include <string>

Task::Task()
:id{nextId++}, status{statusType::UNKNOWN}, priority{priorityType::UNKNOWN}
{
    std::time_t now = std::time(nullptr);
    createdAt = *std::localtime(&now);
}

Task::Task(const std::string& title, const std::string& description,
           statusType status, priorityType priority)
    : title(title), description(description), status(status), priority(priority)
{
    id = nextId++;
    std::time_t now = std::time(nullptr);
    createdAt = *std::localtime(&now);
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << "ID: " << task.id << "\n"
       << "Title: " << task.title << "\n"
       << "Description: " << task.description << "\n"
       << "Status: " << statusToString(task.status) << "\n"
       << "Priority: " << priorityToString(task.priority) << "\n"
       << "Created At: " << task.createdAt.tm_mday << "-" 
       << task.createdAt.tm_mon + 1 << "-" 
       << task.createdAt.tm_year + 1900;
    return os;
}

void Task::create() 
{
    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter description: ";
    std::getline(std::cin, description);

    int s;
    std::cout << "Enter status (1=TODO, 2=IN_PROGRESS, 3=DONE): ";
    std::cin >> s;
    status = static_cast<statusType>(s);

    int p;
    std::cout << "Enter priority (1=LOW, 2=MEDIUM, 3=HIGH): ";
    std::cin >> p;
    priority = static_cast<priorityType>(p);

    std::cin.ignore(); 
}

void Task::editTitle() 
{
    std::cout << "Current title: " << title << "\n";
    std::cout << "Enter new title: ";
    std::getline(std::cin, title);
}

void Task::editDescription() 
{
    std::cout << "Current description: " << description << "\n";
    std::cout << "Enter new description: ";
    std::getline(std::cin, description);
}

void Task::editStatus() 
{
    int s;
    std::cout << "Current status: " << static_cast<int>(status) << "\n";
    std::cout << "Enter new status (1=TODO, 2=IN_PROGRESS, 3=DONE): ";
    std::cin >> s;
    status = static_cast<statusType>(s);
    std::cin.ignore();
}

void Task::editPriority() 
{
    int p;
    std::cout << "Current priority: " << static_cast<int>(priority) << "\n";
    std::cout << "Enter new priority (1=LOW, 2=MEDIUM, 3=HIGH): ";
    std::cin >> p;
    priority = static_cast<priorityType>(p);
    std::cin.ignore();
}