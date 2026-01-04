#include <iostream>
#include "Task.h"

int main()
{
    Task t1(
        "Clean room", 
        "Vacuum and dust the room", 
        statusType::TODO, 
        priorityType::HIGH
    );

    std::cout<<t1<<std::endl;

    return 0;
}