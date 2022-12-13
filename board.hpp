#include <string>
#include <vector>

#include "column.hpp"

class Board
{
private:
    std::string name;
    std::vector<std::unique_ptr<Column>> columns;

    std::unique_ptr<Task> getTask(std::string taskname);
    std::unique_ptr<Column> getColumn(std::string colname);

public:
    Board(std::string name);
    ~Board();
    void printBoard();
    void printTask(std::string taskname);
    void addColumn(std::string colname);
    void addTask(std::string taskname, std::string colname);
    void moveTask(std::string taskname, std::string colname);
};
