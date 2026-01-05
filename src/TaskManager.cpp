#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <string>

TaskManager::TaskManager() 
    :tasks{}
{
}

void TaskManager::addTask()
{
    std::string title, description;
    statusType status;
    priorityType priority;

    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Description: ";
    std::getline(std::cin, description);
    
    // Status
int s;
std::cout << "Status (0=TODO, 1=IN_PROGRESS, 2=DONE): ";
std::cin >> s;
switch(s) {
    case 0: status = statusType::TODO; break;
    case 1: status = statusType::IN_PROGRESS; break;
    case 2: status = statusType::DONE; break;
    default: status = statusType::UNKNOWN;
}

int p;
std::cout << "Priority (0=LOW, 1=MEDIUM, 2=HIGH): ";
std::cin >> p;
switch(p) {
    case 0: priority = priorityType::LOW; break;
    case 1: priority = priorityType::MEDIUM; break;
    case 2: priority = priorityType::HIGH; break;
    default: priority = priorityType::UNKNOWN;
}

    Task newTask(title, description, static_cast<statusType>(s), static_cast<priorityType>(p));
    tasks.push_back(newTask);
}

void TaskManager::showTasks()
 {
    for(const Task& t : tasks)
    {
        std::cout<<t<<std::endl;
    }
 }

 void TaskManager::saveToFile(std::string filePath)
 {
    std::ofstream MyFile(filePath, std::ios::app);
    if (!MyFile.is_open()) {
        std::cerr << "Cannot open file: " << filePath << "\n";
        return;
    }

    for(const Task& t : tasks)
    {
        MyFile << t << std::endl << std::endl;
    }

    MyFile.close();
 }

 void TaskManager::loadFromFile(std::string filePath)
 {
    std::ifstream MyFile(filePath);
        if (!MyFile.is_open()) {
        std::cerr << "Cannot open file: " << filePath << "\n";
        return;
    }

    std::string line;
    int iterator = 0;
    std::string value;
    while (std::getline(MyFile, line)) 
    {
        if (line.empty()) continue;
        iterator = 0;
        while(line[iterator] != ':')
        {
            iterator++;
        }
        value = line.substr(iterator+2);
        std::cout<<value<<std::endl;
    }

    MyFile.close();
 }