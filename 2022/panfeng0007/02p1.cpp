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
    {'X', 1},
    {'Y', 2},
    {'Z', 3}
};

int score(char oppo, char self)
{
    int game_result = convert_map[self] - convert_map[oppo];
    switch(game_result)
    {
        case -1:
        case 2:
            return convert_map[self];
        case 1:
        case -2:
            return convert_map[self] + 6;
        case 0:
            return convert_map[self] + 3;
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