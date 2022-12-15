#include <iostream>
#include "board.hpp"

/*
Board::Board(std::string boardname)
{
    // read from json file
}
*/

Board::~Board()
{
    // write to json file
}

void Board::printBoard()
{
    
}

void Board::printTask(std::string taskname)
{
    auto idx = this->getTaskId(taskname);

    if (idx != -1)
    {
        this->tasks[idx]->printTask();
        return;
    }

    std::cout << "Could not find task with name " << taskname << std::endl;
}

void Board::addColumn(std::string colname)
{
    this->columns.push_back(colname);
}

void Board::addTask(std::string taskname, std::string colname)
{
    this->tasks.push_back(std::make_unique<Task>(taskname, colname));
}

void Board::moveTask(std::string taskname, std::string colname)
{
    auto idx = this->getTaskId(taskname);
    
    if (idx != -1)
    {
        this->tasks[idx]->moveTask(colname);
    }

    std::cout << "Could not move task " << taskname << " to column " << colname << std::endl;
}

size_t Board::getTaskId(std::string taskname)
{
    auto it = std::find_if(this->tasks.begin(), this->tasks.end(), [&taskname](std::unique_ptr<Task>& task) {return task->getName() == taskname;});

    if (it != this->tasks.end())
    {
        size_t index = std::distance(this->tasks.begin(), it);
        return index;
    }
    return -1;
}