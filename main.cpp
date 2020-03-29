#include "PhoneticFinder.hpp"

int main() 
{
    bool a = utils::char_permutation('q','z');
    cout << a << endl;
    string text1 = "xxx abcdefghijklmnopqrstuvwxyz yyy";
    string ans = phonetic::find(text1, "abcdefghijklmnopzrstuvwxyz");
    cout << ans << endl;
    return 0;
}