#pragma once
#include <iostream>
#include <ctime>

enum class statusType
{
    TODO=1,
    INPROGRESS,
    DONE,
    FAIL,

    UNKNOWN
};

enum class priorityType
{
    LOW=1,
    MEDIUM,
    HIGH,

    UNKNOWN
};

    inline std::string statusToString(statusType status) {
        switch (status) {
            case statusType::TODO: return "TODO";
            case statusType::INPROGRESS: return "INPROGRESS";
            case statusType::DONE: return "DONE";
            case statusType::FAIL: return "FAIL";
            case statusType::UNKNOWN: return "UNKNOWN";
            default: return "UNKNOWN";
        }
    }

    inline std::string priorityToString(priorityType priority) {
        switch (priority) {
            case priorityType::LOW: return "LOW";
            case priorityType::MEDIUM: return "MEDIUM";
            case priorityType::HIGH: return "HIGH";
            case priorityType::UNKNOWN: return "UNKNOWN";
            default: return "UNKNOWN";
        }
    }

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
    Task();
    Task(
        const std::string& title, 
        const std::string& description,
         statusType status, 
         priorityType priority
    );

    int getId() const { return id; }
    void create();
    void editTitle();
    void editDescription();
    void editStatus();
    void editPriority();

    friend std::ostream& operator<<(std::ostream& os, const Task& task);
};