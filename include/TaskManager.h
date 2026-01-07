#pragma once
#include "Task.h"
#include <vector>

class TaskManager
{
private:
    std::vector<Task> tasks;

    Task* findTaskById(int id);
    std::tm parseDate(const std::string& dateStr);
    Task formateTask(std::vector<std::string>::iterator task);

public:
    TaskManager() = default;
    
    //const std::vector<Task>& getTasksList() const { return tasks; }

    void addTask(const Task& task) { tasks.push_back(task); }
    void showTasks();

    bool editTask(int id, const std::string& newTitle, const std::string& newDescription, statusType newStatus, priorityType newPriority);
    
    bool saveToFile(std::string filePath);
    bool loadFromFile(std::string filePath);
};