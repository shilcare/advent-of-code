#include <iostream>
#include <fstream>
#include <string>

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

char get_dup_item(string items)
{
    string firsthalf = items.substr(0, items.size() / 2);
    string secondhalf = items.substr(items.size() / 2);

    for (auto &i : firsthalf)
    {
        for (auto &j : secondhalf)
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
    ifstream ifs("03.input");
    int total_priorities = 0;
    while (getline(ifs, line))
    {
        char dup = get_dup_item(line);
        total_priorities += get_priority(dup);
    }
    cout << total_priorities << endl;
    return 0;
}