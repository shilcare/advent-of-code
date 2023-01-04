#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("05.input");
    int ans = 0;
    if(fin.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }
    string tempString;
    int inputLines = 8;
    int stackNumber = 9;
    vector<stack<char>> reverseSt(stackNumber);
    vector<stack<char>> st(stackNumber);
// save the input like this
//     [T] [V]                     [W]    
// [V] [C] [P] [D]             [B]    
// [J] [P] [R] [N] [B]         [Z]    
// [W] [Q] [D] [M] [T]     [L] [T]    
// [N] [J] [H] [B] [P] [T] [P] [L]    
// [R] [D] [F] [P] [R] [P] [R] [S] [G]
// [M] [W] [J] [R] [V] [B] [J] [C] [S]
// [S] [B] [B] [F] [H] [C] [B] [N] [L]
//  1   2   3   4   5   6   7   8   9 
    while(inputLines--)
    {
        getline(fin, tempString);
        for(int i = 0; i < stackNumber; i++)
        {
            if(tempString[i*4 + 1] != ' ')
                reverseSt[i].push(tempString[i*4 + 1]);
        }
    }
    for(int i = 0; i < stackNumber; i++)
    {
        while(!reverseSt[i].empty())
        {
            st[i].push(reverseSt[i].top());
            reverseSt[i].pop();
        }
    }
    //save the input in reverse order
    getline(fin, tempString);
    getline(fin, tempString);
    while(getline(fin, tempString))
    {
        int moveNumber, from, to;
        sscanf(tempString.c_str(), "move %d from %d to %d", &moveNumber, &from, &to);
        from--;
        to--;
        // cout<<moveNumber<<" "<<from<<" "<<to<<endl;
        stack<char> temp;
        for(int i = 0; i < moveNumber; i++)
        {
            temp.push(st[from].top());
            st[from].pop();
        }
        while(!temp.empty())
        {
            st[to].push(temp.top());
            temp.pop();
        }

    }
    for(int i = 0; i < stackNumber; i++)
    {
        if(!st[i].empty())
        {
            cout<<st[i].top();
        }
    }
    cout << endl;
    return 0;
}