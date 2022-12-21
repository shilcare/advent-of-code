#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int get_priority(char item)
{
    if (item >= 'a' && item <= 'z')
    {
        return 1 + item - 'a';
    }
    else if (item >= 'A' && item <= 'Z')
    {
        return 27 + item - 'A';
    }
    else
    {
        return -1;
    }
}

char get_dup_item(vector<string> items)
{
    auto pack1 = items[0];
    auto pack2 = items[1];
    auto pack3 = items[2];

    unordered_set<char> temp;

    for (auto &i : pack1)
    {
        for (auto &j : pack2)
        {
            if (i == j) temp.insert(i);
        }
    }

    for (auto &i : temp)
    {
        for (auto &j : pack3)
        {
            if (i == j)
            {
                return i;
            }
        }
    }
    return 0;
}

int main()
{
    string line;
    vector<string> group;
    ifstream ifs("03.input");
    int total_priorities = 0;
    int count = 0;
    while (getline(ifs, line))
    {
        group.push_back(line);
        ++count;

        if (count == 3)
        {
            count = 0;
            char dup = get_dup_item(group);
            total_priorities += get_priority(dup);
            group.clear();
        }
    }

    cout << total_priorities << endl;
    return 0;
}