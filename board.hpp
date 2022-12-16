#include <string>
#include <vector>

#include "task.hpp"

class Board
{
private:
    std::string name;
    std::vector<std::string> columns;
    std::vector<std::unique_ptr<Task>> tasks;

    size_t getTaskId(std::string taskname);

public:
    Board(std::string boardname) : name{boardname} {};
    ~Board();
    void loadBoard();
    void saveBoard();
    void printBoard();
    void printTask(std::string taskname);
    void addColumn(std::string colname);
    void addTask(std::string taskname, std::string colname);
    void moveTask(std::string taskname, std::string colname);
    void assignTask(std::string taskname, std::string assignee);
    void setTaskPriority(std::string taskname, std::string priority);
    void setTaskDescription(std::string taskname, std::string desc);
};
