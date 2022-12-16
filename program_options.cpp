#include "program_options.hpp"

#include <iostream>
#include <string>
#include <vector>


namespace {
    static program_options::Commands _commands;
    static bool exp_cname = false; // expect column name
    static bool exp_tname = false; // expect task name
    static bool exp_flag = false; // expect flag [-t | -c | -m | -a | -p | -d]
    static bool exp_bname = true; // expect board name
    static bool exp_info = false; // expect info (assignee, description, priority)
    static bool exp_any = false; // expect any value or nothing
}


void program_options::parse(int argc, char* argv[])
{
    const std::vector<std::string> args(argv + 1, argv + argc);

    for (const auto& arg : args) 
    {
        if (exp_bname)
        {
            _commands.bname = arg;
            exp_bname = false;
            exp_any = true;
            continue;
        }

        if (exp_flag || exp_any)
        {
            
            exp_flag = false;
            if (arg == "-t" || arg == "--task")
            {
                _commands.flag = "-t";
                exp_tname = true;
                exp_cname = true;
                exp_any = false;
                continue;
            }

            if (arg == "-c" || arg == "--column")
            {
                _commands.flag = "-c";
                exp_cname = true;
                exp_any = false;
                continue;
            }

            if (arg == "-m" || arg == "--move")
            {
                _commands.flag = "-m";
                exp_cname = true;
                exp_any = false;
                continue;
            }

            if (arg == "-a" || arg == "--assign")
            {
                _commands.flag = "-a";
                exp_info = true;
                exp_any = false;
                continue;
            }

            if (arg == "-p" || arg == "--priority")
            {
                _commands.flag = "-p";
                exp_info = true;
                exp_any = false;
                continue;
            }

            if (arg == "-d" || arg == "--description")
            {
                _commands.flag = "-d";
                exp_info = true;
                exp_any = false;
                continue;
            }
        }

        if (exp_tname || exp_any)
        {
            _commands.tname = arg;
            exp_tname = false;
            exp_flag = true;
            continue;
        }

        if (exp_cname)
        {
            _commands.cname = arg;
            exp_cname = false;
            continue;
        }

        if (exp_info)
        {
            _commands.info = arg;
            exp_info = false;
        }
    }
}


const program_options::Commands& program_options::commands()
{
    return _commands;
}