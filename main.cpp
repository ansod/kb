#include <iostream>
#include <vector>

#include "program_options.hpp"

/*

Usage:

kb myboard // create board if it doesn't exist and show board if it exists

kb myboard -d col1

kb myboard -t task1

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


    return 0;
}