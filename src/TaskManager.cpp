#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void TaskManager::showTasks()
 {
    for(const Task& t : tasks)
    {
        std::cout<<std::endl<<t<<std::endl;
    }
 }

 bool TaskManager::saveToFile(std::string filePath)
 {
    std::ofstream MyFile(filePath, std::ios::trunc);
    if (!MyFile.is_open())
        return false;

    for(const Task& t : tasks)
    {
        MyFile << t << std::endl << std::endl;
    }

    MyFile.close();
    return true;
 }

 bool TaskManager::loadFromFile(std::string filePath)
 {
    std::ifstream MyFile(filePath);
    if (!MyFile.is_open()) 
        return false;

    tasks.clear();
    std::string line;
    std::vector<std::string> valuesForTask;

    while (std::getline(MyFile, line)) 
    {
        if (line.empty()) 
        {
            Task formatedTask = formateTask(valuesForTask.begin());
            tasks.push_back(formatedTask); 

            valuesForTask.clear(); 
            continue;
        }
        auto pos = line.find(": ");
        if (pos != std::string::npos)
        {
            valuesForTask.push_back(line.substr(pos + 2));
        }
    }

    MyFile.close();
    return true;
 }

 Task TaskManager::formateTask(std::vector<std::string>::iterator task)
{
    int id = std::stoi(*task++);
    std::string title = *task++;
    std::string description = *task++;
    
    statusType status = statusType::UNKNOWN;
    if (*task == "TODO") status = statusType::TODO;
    else if (*task == "IN_PROGRESS") status = statusType::IN_PROGRESS;
    else if (*task == "DONE") status = statusType::DONE;
    else if (*task == "FAIL") status = statusType::FAIL;
    task++;

    priorityType priority = priorityType::UNKNOWN;
    if (*task == "LOW") priority = priorityType::LOW;
    else if (*task == "MEDIUM") priority = priorityType::MEDIUM;
    else if (*task == "HIGH") priority = priorityType::HIGH;
    task++;

    std::tm createdAt = parseDate(*task);

    return Task(id, title, description, status, priority, createdAt);
}

std::tm TaskManager::parseDate(const std::string& dateStr)
{
    std::tm tm{};
    int year, month, day;

    if (sscanf(dateStr.c_str(), "%d-%d-%d", &day, &month, &year) == 3)
    {
        tm.tm_year = year - 1900;
        tm.tm_mon  = month - 1;
        tm.tm_mday = day;
    }
    else
    {
        std::cerr << "Error during parsing: " << dateStr << std::endl;
    }

    return tm;
}

 Task* TaskManager::findTaskById(int id)
 {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& t) {
        return t.getId() == id;
    });

    if (it != tasks.end()) 
        return &(*it);
    else 
        return nullptr;
 }

bool TaskManager::editTask(int id, const std::string& newTitle, const std::string& newDescription, statusType newStatus, priorityType newPriority)
{
    Task* task = findTaskById(id);
    if (!task)
        return false;

    task->setTitle(newTitle);
    task->setDescription(newDescription);
    task->setStatus(newStatus);
    task->setPriority(newPriority);

    return true;
}

void TaskManager::addTask(const Task& task) 
{ 
    tasks.push_back(task); 
}

void TaskManager::addTask(const std::string& title, const std::string& description, statusType status, priorityType priority)
{
    tasks.push_back(Task(title, description, status, priority)); 
}