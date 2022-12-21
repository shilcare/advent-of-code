
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main()
{
    ifstream infile("01.input");
    string line;
    int c = 0;
    int cal_elf = 0;
    priority_queue<int> max_q;

    while (getline(infile, line))
    {
        if (!line.empty())
        {
            istringstream iss(line);
            iss >> c;
            cal_elf += c;
        }
        else
        {
            max_q.push(cal_elf);
            cal_elf = 0;
            c = 0;
        }
    }

    int top1 = max_q.top();
    max_q.pop();
    int top2 = max_q.top();
    max_q.pop();
    int top3 = max_q.top();

    cout << (top1 + top2 + top3) << endl;
    return 0;
}