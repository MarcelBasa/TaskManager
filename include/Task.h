#pragma once
#include <iostream>
#include <ctime>

enum class statusType
{
    TODO,
    INPROGRESS,
    DONE,
    FAIL,

    MAX_status
};

enum class priorityType
{
    LOW,
    MEDIUM,
    HIGH,

    MAX_priority
};

class Task
{
private:
    inline static int nextId = 1;
    
    int id;
    std::string title;
    std::string description;
    statusType status;
    priorityType priority;
    std::tm createdAt{};

public:
    Task() = delete;
    Task(
        const std::string& title, 
        const std::string& description,
         statusType status, 
         priorityType priority
    );

    int getId() const { return id; }
    friend std::ostream& operator<<(std::ostream& os, const Task& task);

};