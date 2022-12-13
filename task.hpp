#include <string>

#include "priority.hpp"


class Task
{
private:
    std::string name;
    std::string desc;
    std::string colname;
    Priority priority{Priority::NORMAL};

public:
    Task(std::string name);
    ~Task();
    void printTask();
    void moveTask(std::string newcol);
    void assignTask(std::string assignee);
    void setPriority(Priority);
};
