#ifndef FILEREADER
#define FILEREADER

#include<sstream>
#include<fstream>
#include<string>
#include<vector>

#include "timetable.hpp"

class FileReader {
    private:
        std::string line;
        std::vector<std::string> tokens;

    public:
        TimeTable parse_file(const char *filename);
};

#endif
