#ifndef FILEREADER
#define FILEREADER

#include<sstream>
#include<fstream>
#include<string>
#include<vector>

#include "lesson.hpp"

class FileReader {
    private:
	std::ifstream file;
    public:
	FileReader(const char *filename);
	std::vector<Lesson> parse_file(void);
};

#endif
