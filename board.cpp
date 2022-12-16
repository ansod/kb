#include <iostream>
#include <fstream>

#include "board.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;


Board::~Board()
{
    // write to json file
}


void Board::loadBoard()
{
    std::ifstream f(this->name + ".json");

    if (!f.good())
    {
        return;
    }

    json data = json::parse(f);

    if (data.contains("columns"))
    {
        for (auto & col : data["columns"])
        {
            this->columns.push_back(col["name"]);
            if (!col["tasks"].is_null())
            {
                for (auto & task : col["tasks"])
                {
                    Priority priority = (task["priority"] == "high") ? Priority::HIGH : Priority::NORMAL;
                    this->tasks.push_back(std::make_unique<Task>(task["name"], col["name"], task["desc"], task["assignee"], priority));
                }
            }
        }
    }
}

void Board::saveBoard()
{
    json data;

    data["name"] = this->name;
    for (auto & col : this->columns)
    {
        json c = {{"name", col}, {"tasks", {}}};
        data["columns"].push_back({c});
    }

    for (auto & task : this->tasks)
    {
        json t = {
            {"name", task->getName()}, 
            {"desc", task->getDesc()},
            {"priority", task->getPriority()},
            {"assignee", task->getAssignee()}
        };
        std::string c = task->getColumn();
        auto it = std::find(this->columns.begin(), this->columns.end(), c);
        if (it != this->columns.end())
        {
            auto index = std::distance(this->columns.begin(), it);
            data["columns"][index]["tasks"].push_back({t});
        }
        
    }

    std::ofstream o(this->name + ".json");
    o << std::setw(4) << data << std::endl;

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
        return;
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