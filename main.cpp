#include <iostream>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

void UVa468();

int main() {
    UVa468();
    return 0;
}

void UVa468(){
    int cases;
    string line;
    cin>>cases;
    for (int i = 0; i<cases; i++)
    {
        getline(cin, line);
        cin>>line;
        map<char, int> codeLetters;
        for (auto character: line)
            codeLetters[character]++;
        cin>>line;
        map<char, int> valueLetters;
        for (auto character: line)
            valueLetters[character]++;

        int maxNumber = 0;
        char maxNameCode, maxNameValue;
        map<char, char> encoding;

        while (true){
            maxNumber = 0;
            for (auto character: codeLetters)
                if (character.second > maxNumber)
                {
                    maxNumber = character.second;
                    maxNameCode = character.first;
                }
            codeLetters[maxNameCode] = 0;
            if (maxNumber == 0)
                break;
            maxNumber = 0;
            for (auto character: valueLetters)
                if (character.second > maxNumber)
                {
                    maxNumber = character.second;
                    maxNameValue = character.first;
                }
            valueLetters[maxNameValue] = 0;
            encoding[maxNameCode] = maxNameValue;
        }

        for (int j = 0; j<line.size(); j++)
            for (auto character: encoding)
                if (line[j] == character.second)
                {
                    line [j] = character.first;
                    break;
                }

        i < cases - 1 ? cout<<line<<endl<<endl : cout<<line<<endl;
    }
}
