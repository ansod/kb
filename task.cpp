#include <iostream>

#include "task.hpp"


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

void Task::setPriority(std::string priority)
{   
    if (priority == "high")
    {
         this->priority = Priority::HIGH;
    } else {
        this->priority = Priority::NORMAL;
    }
   
}

void Task::setDescription(std::string desc)
{
    this->desc = desc;
}

std::string Task::getName()
{
    return this->name;
}

std::string Task::getColumn()
{
    return this->column;
}

std::string Task::getDesc()
{
    return this->desc;
}

std::string Task::getPriority()
{
    switch (this->priority)
    {
    case Priority::NORMAL:
        return "normal";
        break;
    case Priority::HIGH:
        return "high";
        break;
    default:
        return "normal";
        break;
    };
}

std::string Task::getAssignee()
{
    return this->assignee;
}