#include "board.hpp"


Board::Board(std::string name)
{
    // read from json file
}

Board::~Board()
{
    // write to json file
}

void Board::printBoard()
{
    
}

void Board::printTask(std::string taskname)
{

}

void Board::addColumn(std::string colname)
{
    std::unique_ptr<Column> c = std::make_unique<Column>(colname);
    this->columns.push_back(c);
}

void Board::addTask(std::string taskname, std::string colname)
{

}

void Board::moveTask(std::string taskname, std::string colname)
{

}

std::unique_ptr<Task> Board::getTask(std::string taskname)
{

}

std::unique_ptr<Column> Board::getColumn(std::string colname)
{
    auto it = std::find_if(this->columns.begin(), this->columns.end(), [&colname](const std::unique_ptr<Column> col) {return col->getName() == colname;});

    if (it != this->columns.end())
    {
        auto index = std::distance(this->columns.begin(), it);
        return this->columns[index];
    }

}