#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool ShouldIgnore (char c)
{
    return  c == ' ' ||
            c == ',' ||
            c == '.' ||
            c == '!' ||
            c == '?';
}

void ParseSentence (string& sentence)
{
    sentence.erase(remove_if(sentence.begin(), sentence.end(), ShouldIgnore), sentence.end());
    transform (sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
}

int main ()
{
    string sentence;

    while (getline (cin, sentence))
    {
        if (sentence == "DONE") break;

        ParseSentence (sentence);

        if (sentence == string(sentence.rbegin(), sentence.rend()))
            cout << "You won't be eaten!" << endl;
        else
            cout << "Uh oh.." << endl;
    }
    return 0;
}