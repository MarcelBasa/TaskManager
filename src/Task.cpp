#include "Task.h"

Task::Task(const std::string& title, const std::string& description,
           statusType status, priorityType priority)
    : title(title), description(description), status(status), priority(priority)
{
    id = nextId++;
    std::time_t now = std::time(nullptr);
    createdAt = *std::localtime(&now);
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << "Id: " << task.id << "\n"
       << "Title: " << task.title << "\n"
       << "Description: " << task.description << "\n"
       << "Status: " << static_cast<int>(task.status) << "\n"
       << "Priority: " << static_cast<int>(task.priority) << "\n"
       << "Created At: " << task.createdAt.tm_mday << "-" 
       << task.createdAt.tm_mon+1 << "-" 
       << task.createdAt.tm_year+1900;
    return os;
}