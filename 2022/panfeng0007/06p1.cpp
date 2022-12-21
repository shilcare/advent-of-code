#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int get_marker_pos(string input_filename)
{
    ifstream ifs(input_filename);
    string buffer;
    getline(ifs, buffer);
    for (size_t i = 0, j = 3; j < buffer.size(); i++, j++)
    {
        unordered_set<char> temp;
        for (int k = i; k <= j; k++)
        {
            temp.insert(buffer[k]);
        }

        if (temp.size() == 4) return j + 1;
    }

    return buffer.size();
}

int main()
{
    cout << get_marker_pos("06.input") << endl;
    return 0;
}