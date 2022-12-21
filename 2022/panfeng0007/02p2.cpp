
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

static unordered_map<char, int> convert_map
{
    {'A', 1},
    {'B', 2},
    {'C', 3},
    {'X', 0},
    {'Y', 3},
    {'Z', 6}
};

static unordered_map<char, int> win_map
{
    {'A', 2},
    {'B', 3},
    {'C', 1}
};

static unordered_map<char, int> lose_map
{
    {'A', 3},
    {'B', 1},
    {'C', 2}
};

int score(char oppo, char intended_result)
{
    switch(intended_result)
    {
        case 'X':
            return lose_map[oppo] + convert_map[intended_result];
        case 'Y':
            return convert_map[oppo] + convert_map[intended_result];
        case 'Z':
            return win_map[oppo] + convert_map[intended_result];
        default:
            return 0;
    }
}

int main()
{
    int total_score = 0;
    ifstream infile("02.input");
    char oppo, self;
    while (infile >> oppo >> self)
    {
        total_score += score(oppo, self);
    }
    cout << total_score << endl;
    return 0;
}