#include "Task.h"
#include <string>

Task::Task()
:id{nextId++}, status{statusType::UNKNOWN}, priority{priorityType::UNKNOWN}
{
    std::time_t now = std::time(nullptr);
    createdAt = *std::localtime(&now);
}

Task::Task(
    int id,
    const std::string& title, 
    const std::string& description,
    statusType status, 
    priorityType priority,
    std::tm createdAt
)
{
    this->id = id;
    this->title = title;
    this->description = description;
    this->status = status;
    this->priority = priority;
    this->createdAt = createdAt;

    nextId = ++id;
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

