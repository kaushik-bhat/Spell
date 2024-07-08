#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include<string>
#include<vector>

class levenshtein{
    public:
        static int distance(const std::string& s1, const std::string& s2);
};

#endif