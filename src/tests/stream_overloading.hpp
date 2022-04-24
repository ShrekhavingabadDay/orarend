#include<iostream>
#include "../include/interval.hpp"

std::ostream& operator<<(std::ostream& stream, const Interval &other){
        stream << other.get_start() << ", " << other.get_end();
        return stream;
}

