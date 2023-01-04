#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("02.input");
    if(fin.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }
    string tempString;
    int score = 0;
    map<char, int> chooseScoreMap;
    map<pair<char,char>,int> winScoreMap;
    // chooseScoreMap['X'] = 1;
    // chooseScoreMap['Y'] = 2;
    // chooseScoreMap['Z'] = 3;
    // winScoreMap[make_pair('A','X')] = 3;
    // winScoreMap[make_pair('A','Y')] = 6;
    // winScoreMap[make_pair('A','Z')] = 0;
    // winScoreMap[make_pair('B','X')] = 0;
    // winScoreMap[make_pair('B','Y')] = 3;
    // winScoreMap[make_pair('B','Z')] = 6;
    // winScoreMap[make_pair('C','X')] = 6;
    // winScoreMap[make_pair('C','Y')] = 0;
    // winScoreMap[make_pair('C','Z')] = 3;
    // 石头布剪刀 1 2 3
    chooseScoreMap['X'] = 0;
    chooseScoreMap['Y'] = 3;
    chooseScoreMap['Z'] = 6;
    winScoreMap[make_pair('A','X')] = 3;
    winScoreMap[make_pair('A','Y')] = 1;
    winScoreMap[make_pair('A','Z')] = 2;

    winScoreMap[make_pair('B','X')] = 1;
    winScoreMap[make_pair('B','Y')] = 2;
    winScoreMap[make_pair('B','Z')] = 3;

    winScoreMap[make_pair('C','X')] = 2;
    winScoreMap[make_pair('C','Y')] = 3;  
    winScoreMap[make_pair('C','Z')] = 1;
    while(getline(fin, tempString))
    {
        // cout<<tempString<<endl;
        char firstChar = tempString[0];
        char secondChar = tempString[2];
        int roundScore = 0;
        roundScore += chooseScoreMap[secondChar];
        roundScore += winScoreMap[make_pair(firstChar,secondChar)];
        score += roundScore;
    }
    
    cout << score << endl;
    return 0;
}