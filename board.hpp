#include <string>
#include <vector>

#include "column.hpp"

class Board
{
private:
    std::string name;
    std::vector<Column> columns;
public:
    Board(std::string name);
    ~Board();
    void printBoard();
    void addColumn(std::string colname);
    void addTask(std::string taskname);
};
