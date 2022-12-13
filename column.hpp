#include <string>
#include <vector>

#include "task.hpp"

class Column
{
private:
    std::string name;
    std::vector<std::unique_ptr<Task>> tasks;
public:
    
    Column(std::string name);
    ~Column();
    std::string getName();
};
