#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int get_overlaps(string filename_in)
{
    int overlaps = 0;
    ifstream ifs(filename_in);
    string line;
    char pair_sep = ',';
    char range_sep = '-';
    while (getline(ifs, line))
    {
        int p1_lb = 0;
        int p2_lb = 0;
        int p1_ub = 0;
        int p2_ub = 0;

        auto pair_sep_pos = line.find(',');
        auto p1_range_sep_pos = line.find_first_of('-');
        auto p2_range_sep_pos = line.find_last_of('-');

        istringstream iss(line);
        iss >> p1_lb;
        iss.seekg(p1_range_sep_pos + 1);
        iss >> p1_ub;
        iss.seekg(pair_sep_pos + 1);
        iss >> p2_lb;
        iss.seekg(p2_range_sep_pos + 1);
        iss >> p2_ub;

        if ((p1_lb <= p2_ub && p1_ub >= p2_lb) || (p2_lb <= p1_ub && p2_ub >= p1_lb))
        {
            ++overlaps;
        }
    }

    return overlaps;
}

int main()
{
    cout << get_overlaps("04.input") << endl;
    return 0;
}