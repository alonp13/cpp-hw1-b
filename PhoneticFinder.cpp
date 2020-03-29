#include "PhoneticFinder.hpp"
using namespace utils;

size_t utils::split(const string &txt, vector<string> &strs)
{
    char ch = ' ';
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != string::npos)
    {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}

string utils::to_lower(string str)
{
    string ans = str;
    for(int i = 0 ; i < str.size(); i++)
    {
        ans[i] = tolower(str[i]);
    }
    return ans;
}

bool utils::char_permutation(char given_char, char original_char)
{
    if(given_char == original_char) return true;

    switch (given_char)
    {
        //v,w
        case 'v':
            if(original_char == 'w') return true;
            break;
        case 'w':
            if(original_char == 'v') return true;
            break; 
        //b,f,p
        case 'b':
            if(original_char == 'f') return true;
            if(original_char == 'p') return true;
            break; 
        case 'f':
            if(original_char == 'b') return true;
            if(original_char == 'p') return true;
            break;
        case 'p':
            if(original_char == 'f') return true;
            if(original_char == 'b') return true;
            break;
        //g,j
        case 'g':
            if(original_char == 'j') return true;
            break;      
        case 'j':
            if(original_char == 'g') return true;
            break;
        //c,k,q
        case 'c':
            if(original_char == 'k') return true;
            if(original_char == 'q') return true;
            break; 
        case 'k':
            if(original_char == 'c') return true;
            if(original_char == 'q') return true;
        case 'q':
            if(original_char == 'k') return true;
            if(original_char == 'c') return true;  
            break;     
        //s,z
        case 's':
            if(original_char == 'z') return true;
            break;      
        case 'z':
            if(original_char == 's') return true;
            break;
        //d,t
        case 'd':
            if(original_char == 't') return true;
            break;      
        case 't':
            if(original_char == 'd') return true;
            break;
        //o,u
        case 'o':
            if(original_char == 'u') return true;
            break;      
        case 'u':
            if(original_char == 'o') return true;
            break;
        //i,y
        case 'i':
            if(original_char == 'y') return true;
            break;      
        case 'y':
            if(original_char == 'i') return true;
            break;
    }
    return false;
}

string phonetic::find(string text,string given_word)
{
    if(given_word.find(' ') != string::npos || given_word == "")
    {
        throw exception();
    }

    //to lower case:

    string lower_given_word = to_lower(given_word);

    //split:
    vector<string> words;
    split(text,words);

    for(string word : words)
    {
        string lower_word = to_lower(word);
        if(lower_given_word.size() != word.size()) continue;
        bool is_equal = true;
        for(int i = 0 ; i < word.size(); i++)
        {
            if(!char_permutation(lower_word[i],lower_given_word[i])) 
            {
                is_equal = false;
                break;
            }
        }
        if(!is_equal) continue;
        return word;
    }
    throw exception();
    return "Not Found";
}