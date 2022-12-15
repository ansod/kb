#include <string>

#include "priority.hpp"


class Task
{
private:
    std::string name;
    std::string column;
    std::string desc;
    std::string assignee;
    Priority priority;

public:
    Task(std::string taskname, std::string colname) : name{taskname}, column{colname}, desc{}, assignee{}, priority{Priority::NORMAL} {};
    ~Task();
    void printTask();
    void moveTask(std::string newcol);
    void assignTask(std::string assignee);
    void setPriority(Priority);
    void setDescription(std::string desc);
    std::string getName();
};
