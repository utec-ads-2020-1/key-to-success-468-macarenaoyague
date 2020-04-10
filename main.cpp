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

bool sortFromMax(const pair<char, int> &vec1,
               const pair<char, int> &vec2)
{
    return (vec1.second < vec2.second);
}

vector <pair<char, int>> lettersOrderedFromMax(string &line){
    map<char, int> letters;
    vector <pair<char, int>> orderedLetters;
    for (auto character: line)
        letters[character]++;
    for (auto value: letters)
        orderedLetters.push_back(value);
    sort(orderedLetters.begin(), orderedLetters.end(), sortFromMax);

    return orderedLetters;
}

int searchIndex(vector <pair<char, int>> &valueLetters, char &letter){
    for (int i = 0; i<valueLetters.size(); i++)
        if (letter == valueLetters[i].first)
            return i;
}

void UVa468(){
    int cases;
    string line;
    cin>>cases;
    for (int i = 0; i<cases; i++)
    {
        getline(cin, line);
        cin>>line;
        vector <pair<char, int>> codeLetters = lettersOrderedFromMax(line);
        cin>>line;
        vector <pair<char, int>> valueLetters = lettersOrderedFromMax(line);
        for (int j = 0; j<line.size(); j++)
            line [j] = codeLetters[searchIndex(valueLetters, line[j])].first;
        cout<<line<<endl<<endl;
    }
}
