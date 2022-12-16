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
    Task(std::string tname, std::string cname) : name{tname}, column{cname}, desc{}, assignee{}, priority{Priority::NORMAL} {};
    Task(std::string tname, std::string cname, std::string d, std::string a, Priority p) : name{tname}, column{cname}, desc{d}, assignee{a}, priority{p} {};
    ~Task();
    void printTask();
    void moveTask(std::string newcol);
    void assignTask(std::string assignee);
    void setPriority(std::string priority);
    void setDescription(std::string desc);
    std::string getName();
    std::string getColumn();
    std::string getDesc();
    std::string getPriority();
    std::string getAssignee();
};
