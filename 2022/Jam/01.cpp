#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    ifstream fin("01.input");
    int curNumber = 0, tempNumber;
    string tempString;
    
    while(getline(fin, tempString))
    {
        // cout<<tempString<<endl;
        if(tempString == "")
        {
            pq.push(curNumber);
            // cout<<curNumber<<endl;
            curNumber = 0;
            continue;
        }
        tempNumber = stoi(tempString,0,10);
        curNumber += tempNumber;
        
    }
    int ans = 0;
    for(int i = 0; i < 3; i++)
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}