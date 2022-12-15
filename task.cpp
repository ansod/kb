#include <iostream>

#include "task.hpp"

/*
Task::Task(std::string taskname, std::string colname)
{

}
*/

Task::~Task()
{
}

void Task::printTask()
{
    std::cout << this->name << std::endl;
    std::cout << this->desc << std::endl;
    std::cout << std::endl;
    if (!this->assignee.empty())
    {
        std::cout << "Assigned to: " << this->assignee << std::endl;
    }
    switch (this->priority)
    {
    case Priority::NORMAL:
        std::cout << "Priority: Normal" << std::endl;
        break;
    case Priority::HIGH:
        std::cout << "Priority: High" << std::endl;
    default:
        break;
    }
    
}

void Task::moveTask(std::string newcol)
{
    this->column = newcol;
}

void Task::assignTask(std::string assignee)
{
    this->assignee = assignee;
}

void Task::setPriority(Priority priority)
{
    this->priority = priority;
}

void Task::setDescription(std::string desc)
{
    this->desc = desc;
}

std::string Task::getName()
{
    return this->name;
}