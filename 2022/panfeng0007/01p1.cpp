#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    std::ifstream infile("01.input");
    std::string line;
    int c = 0;
    int cal_elf = 0;
    int max_cal = INT32_MIN;
    while (std::getline(infile, line))
    {
        if (!line.empty())
        {
            std::istringstream iss(line);
            iss >> c;
            cal_elf += c;
        }
        else
        {
            if (cal_elf > max_cal)
            {
                max_cal = cal_elf;
            }
            cal_elf = 0;
            c = 0;
        }
    }
    std::cout << max_cal << std::endl;
    return 0;
}