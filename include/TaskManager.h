#pragma once
#include "Task.h"
#include <vector>

class TaskManager
{
private:
    std::vector<Task> tasks;

public:
    TaskManager();
    
    //const std::vector<Task>& getTasksList() const { return tasks; }

    void addTask();
    void showTasks();
    
    void saveToFile(std::string filePath);
    void loadFromFile(std::string filePath);
};