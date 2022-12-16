#include <iostream>
#include <vector>

#include "program_options.hpp"
#include "board.hpp"

/*

Usage:

kb myboard  //create board if it doesn't exist and show board if it exists

kb myboard -c col1  // add column  

kb myboard -t task1 col1    // add task to column

kb myboard task1 -m col1    // move task to column

kb myboard task1 -a assignee1   // assign task to assignee

kb myboard task1 -p [normal | high] // set task priority

kb myboard task1 -d "some description" // set task description

kb myboard task1

*/

using namespace std;


int main(int argc, char *argv[]) 
{

    if (argc == 1)
    {
        cout << "[insert help message here]" << endl;
        return 0;
    }

    program_options::parse(argc, argv); // parse args
    program_options::Commands cmds = program_options::commands(); // retrieve parsed args as a struct

    /*
    cout << "bname: " << cmds.bname << endl;
    cout << "flag: " << cmds.flag << endl;
    cout << "tname: " << cmds.tname << endl;
    cout << "cname: " << cmds.cname << endl;
    cout << "info: " << cmds.info << endl;
    */

    if (cmds.bname == "")
    {
        cout << "[insert help message here]" << endl;
        return 0;
    }

    Board board{cmds.bname};
    board.loadBoard();
    if (cmds.flag ==  "-t")
    {
        if (cmds.tname == "" || cmds.cname == "")
        {
            cout << "Missing name of task to add or name of column to add to" << endl;
            return 0;
        }

        board.addTask(cmds.tname, cmds.cname);
    } else if (cmds.flag == "-c")
    {
        if (cmds.cname == "")
        {
            cout << "Missing name of column to add" << endl;
            return 0;
        }

        board.addColumn(cmds.cname);
    } else if (cmds.flag == "-m")
    {
        if (cmds.tname == "" || cmds.cname == "")
        {
            cout << "Missing name of task to move or name of column to move to" << endl;
            return 0;
        }

        board.moveTask(cmds.tname, cmds.cname);
    } else if (cmds.flag == "-a")
    {
        if (cmds.tname == "" || cmds.info == "")
        {
            cout << "Missing name of task or name of assignee" << endl;
            return 0;
        }

        board.assignTask(cmds.tname, cmds.info);
    } else if (cmds.flag == "-p")
    {
        if (cmds.tname == "" || cmds.info == "")
        {
            cout << "Missing name of task or priority" << endl;
            return 0;
        }

        board.setTaskPriority(cmds.tname, cmds.info);
    } else if (cmds.flag == "-d")
    {
        if (cmds.tname == "" || cmds.info == "")
        {
            cout << "Missing name of task or description" << endl;
            return 0;
        }
        board.setTaskDescription(cmds.tname, cmds.info);
    } else 
    {
        if (cmds.tname != "")
        {
            // show task
            board.printTask(cmds.tname);
        } else
        {
            // show board or create board
            board.printBoard();
        }
    }

    board.saveBoard();
    return 0;
}