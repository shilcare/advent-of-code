#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

using namespace std;


string get_top_crates(string input_filename)
{
    string ret;
    vector<deque<char>> stacks(9, deque<char>{});
    ifstream ifs(input_filename);
    string line;
    bool init_stacks_processed = false;

    while (getline(ifs, line))
    {
        if (line.empty()) init_stacks_processed = true;

        if (!init_stacks_processed)
        {
            auto stack_i = 0;
            for (auto i = 1; i < line.size(); i += 4)
            {
                if (line[i] >= '0' && line[i] <= '9') break;

                if (line[i] != ' ')
                {
                    stacks[stack_i].push_front(line[i]);
                }
                stack_i++;
            }
        }
        else
        {
            if (line.empty()) continue;

            int n_crates = 0;
            int from_stack = 0;
            int to_stack = 0;
            string token("");

            istringstream iss(line);
            iss >> token;
            iss >> n_crates;
            iss >> token;
            iss >> from_stack;
            iss >> token;
            iss >> to_stack;

            for (auto i = 0; i < n_crates; i++)
            {
                char crate = stacks[from_stack - 1].back();
                stacks[to_stack - 1].push_back(crate);
                stacks[from_stack - 1].pop_back();
            }
        }
    }

    for (auto &s : stacks)
    {
        ret.push_back(s.back());
    }

    ifs.close();
    return ret;
}

int main()
{
    cout << get_top_crates("05.input") << endl;
    return 0;
}