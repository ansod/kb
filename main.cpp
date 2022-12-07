#include <iostream>
#include <vector>

#include "program_options.hpp"

/*

Usage:

kb myboard // create board if it doesn't exist and show board if it exists

kb myboard -d col1

kb myboard -t task1 col1

kb myboard -m task1 col1

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

    cout << "bname: " << cmds.bname << endl;
    cout << "flag: " << cmds.flag << endl;
    cout << "tname: " << cmds.tname << endl;
    cout << "cname: " << cmds.cname << endl;


    if (cmds.bname == "")
    {
        cout << "[insert help message here]" << endl;
        return 0;
    }

    if (cmds.flag ==  "-t")
    {
        if (cmds.tname == "" || cmds.cname == "")
        {
            cout << "Missing name of task to add or name of column to add to" << endl;
            return 0;
        }

    } else if (cmds.flag == "-c")
    {
        if (cmds.cname == "")
        {
            cout << "Missing name of column to add" << endl;
            return 0;
        }

    } else if (cmds.flag == "-m")
    {
        if (cmds.tname == "" || cmds.cname == "")
        {
            cout << "Missing name of task to move or name of column to move to" << endl;
            return 0;
        }

    } else 
    {
        if (cmds.tname != "")
        {
            // show task
        } else
        {
            // show board
        }
    }

    return 0;
}