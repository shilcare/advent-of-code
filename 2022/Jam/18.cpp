#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("18.input");
    int ans = 0;
    if(fin.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }
    string tempString;
    set<tuple<int,int,int>> s;
    while(getline(fin, tempString))
    {
        int a,b,c;
        sscanf(tempString.c_str(), "%d,%d,%d", &a, &b, &c);
        s.insert(make_tuple(a,b,c));
    }
    for(auto i : s)
    {
        int a,b,c;
        tie(a,b,c) = i;
        if(s.find(make_tuple(a-1,b,c)) == s.end())
        {
            ans++;
        }
        if(s.find(make_tuple(a+1,b,c)) == s.end())
        {
            ans++;
        }
        if(s.find(make_tuple(a,b-1,c)) == s.end())
        {
            ans++;
        }
        if(s.find(make_tuple(a,b+1,c)) == s.end())
        {
            ans++;
        }
        if(s.find(make_tuple(a,b,c-1)) == s.end())
        {
            ans++;
        }
        if(s.find(make_tuple(a,b,c+1)) == s.end())
        {
            ans++;
        }


    }

    cout << ans << endl;
    return 0;
}