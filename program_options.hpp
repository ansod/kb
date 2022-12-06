

#include <string>
#include <vector>

namespace program_options {

    struct Commands {
        std::string bname;
        std::string flag;
        std::string tname;
        std::string cname;
    };

    void parse(int argc, char* argv[]);

    const Commands& commands();

}