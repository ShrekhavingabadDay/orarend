#ifndef FILEREADER
#define FILEREADER

#include<sstream>
#include<fstream>
#include<string>
#include<vector>

#include "lesson.hpp"

class FileReader {
    private:
        std::string line;
        std::vector<std::string> tokens;

    public:
        std::vector<Lesson> parse_file(const char *filename);
};

#endif
