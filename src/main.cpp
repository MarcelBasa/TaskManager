#include "TaskManager.h"
//#include <gtest/gtest.h>

int main()
{
    TaskManager taskManager;

    taskManager.loadFromFile("data.txt");
    // taskManager.addTask(Task("Task 1", "Opis 1", statusType::TODO, priorityType::LOW));
    // taskManager.showTasks();
    // taskManager.editTask(1, "Nowy ", "Nowy opis", statusType::DONE, priorityType::HIGH);
     taskManager.showTasks();
     taskManager.saveToFile("data.txt");

    return 0;
}