#pragma once
#include <iostream>
#include <ctime>

enum class statusType
{
    TODO=0,
    IN_PROGRESS,
    DONE,
    FAIL,

    UNKNOWN
};

enum class priorityType
{
    LOW=0,
    MEDIUM,
    HIGH,

    UNKNOWN
};

    inline std::string statusToString(statusType status) {
        switch (status) {
            case statusType::TODO: return "TODO";
            case statusType::IN_PROGRESS: return "IN_PROGRESS";
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
        int id,
        const std::string& title, 
        const std::string& description,
        statusType status, 
        priorityType priority,
        std::tm createdAt
    );

    Task(
        const std::string& title, 
        const std::string& description,
        statusType status, 
        priorityType priority
    );

    int getId() const { return id; }
    const std::string& getTitle() const { return title; }
    const std::string& getDescription() const { return description; }
    statusType getStatus() const { return status; }
    priorityType getPriority() const { return priority; }
    const std::tm& getCreatedAt() const { return createdAt; }

    void setId(int newId) { id = newId; }
    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setDescription(const std::string& newDescription) { description = newDescription; }
    void setStatus(statusType newStatus) { status = newStatus; }
    void setPriority(priorityType newPriority) { priority = newPriority; }
    void setCreatedAt(const std::tm& newCreatedAt) { createdAt = newCreatedAt; }

    friend std::ostream& operator<<(std::ostream& os, const Task& task);
};