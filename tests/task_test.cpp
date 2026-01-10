#include <gtest/gtest.h>
#include "TaskManager.h"
#include "memory.h"

class taskTestFixture : public testing::Test
{
public:
    std::unique_ptr<TaskManager> TM; 


    taskTestFixture()
    {
        TM = std::make_unique<TaskManager>();
    }
};

TEST_F(taskTestFixture, AddTask) 
{
    Task task("Test task", "Description", statusType::TODO, priorityType::MEDIUM);
    EXPECT_EQ(TM->getTasks().size(), 0);
    TM->addTask(task);
    EXPECT_EQ(TM->getTasks()[0].getId(), 1);
    EXPECT_EQ(TM->getTasks().size(), 1);
    EXPECT_EQ(TM->getTasks()[0].getTitle(), "Test task");
}

TEST_F(taskTestFixture, FindTaskByIdReturnsCorrectTask) 
{
    Task task("Task 1", "Desc", statusType::TODO, priorityType::LOW);
    TM->addTask(task);
    int id = TM->getTasks()[0].getId();

    std::vector<Task>::iterator found = TM->findTaskById(id);
    ASSERT_NE(found, TM->getTasks().end());
    EXPECT_EQ(found->getTitle(), "Task 1");
}

TEST_F(taskTestFixture, EditTaskChangesFields) 
{
    Task task("Old title", "Old desc", statusType::TODO, priorityType::LOW);
    TM->addTask(task);
    int id = TM->getTasks()[0].getId();

    bool success = TM->editTask(id, "New title", "New desc", statusType::DONE, priorityType::HIGH);
    EXPECT_TRUE(success);

    std::vector<Task>::iterator edited = TM->findTaskById(id);
    ASSERT_NE(edited, TM->getTasks().end());
    EXPECT_EQ(edited->getId(), task.getId());
    EXPECT_EQ(edited->getTitle(), "New title");
    EXPECT_EQ(edited->getDescription(), "New desc");
    EXPECT_EQ(edited->getStatus(), statusType::DONE);
    EXPECT_EQ(edited->getPriority(), priorityType::HIGH);
}

TEST_F(taskTestFixture, EditNonExistingTaskReturnsFalse) 
{
    bool success = TM->editTask(999, "Title", "Desc", statusType::DONE, priorityType::HIGH);
    EXPECT_FALSE(success);
}

TEST_F(taskTestFixture, DeleteTask) 
{
    Task task("Old title", "Old desc", statusType::TODO, priorityType::LOW);
    TM->addTask(task);
    int id = TM->getTasks()[0].getId();
    int sizeBefore = TM->getTasks().size();

    bool success = TM->deleteTask(id);
    EXPECT_TRUE(success);
    EXPECT_EQ(TM->getTasks().size(), sizeBefore - 1);

    auto it = std::find_if(TM->getTasks().begin(), TM->getTasks().end(),
                           [id](const Task& t){ return t.getId() == id; });
    EXPECT_EQ(it, TM->getTasks().end());
}

TEST_F(taskTestFixture, SaveAndLoadFile) 
{
    Task task1("Task1", "Desc1", statusType::TODO, priorityType::LOW);
    Task task2("Task2", "Desc2", statusType::DONE, priorityType::HIGH);

    TM->addTask(task1);
    TM->addTask(task2);

    std::string filename = "data.txt";
    EXPECT_TRUE(TM->saveToFile(filename));

    TaskManager TM2;
    EXPECT_TRUE(TM2.loadFromFile(filename));

    EXPECT_EQ(TM2.getTasks().size(), 2);
    EXPECT_EQ(TM2.getTasks()[0].getTitle(), "Task1");
    EXPECT_EQ(TM2.getTasks()[1].getTitle(), "Task2");
}