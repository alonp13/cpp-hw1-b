#pragma once
#include<iostream>
#include<string>
#include <stdexcept>
#include <vector>
using namespace std;
namespace utils
{
    size_t split(const string &txt, vector<string> &strs);
    string to_lower(string str);
    bool char_permutation(char given_char, char original_char);
};

namespace phonetic
{
    string find(string text,string word);
};
