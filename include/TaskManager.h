#pragma once
#include "Task.h"
#include <vector>

class TaskManager
{
private:
    std::vector<Task> tasks;

    std::tm parseDate(const std::string& dateStr);
    Task formateTask(std::vector<std::string>::iterator task);

public:
    TaskManager() = default;
    ~TaskManager() = default;

    Task* findTaskById(int id);
    std::vector<Task> getTasks() const { return tasks; }

    void addTask(const Task& task);
    void addTask(const std::string& title, const std::string& description, statusType status, priorityType priority);

    void showTasks();

    bool editTask(int id, const std::string& newTitle, const std::string& newDescription, statusType newStatus, priorityType newPriority);
    
    bool saveToFile(std::string filePath);
    bool loadFromFile(std::string filePath);
};