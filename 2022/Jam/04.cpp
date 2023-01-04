#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("04.input");
    int ans = 0;
    if(fin.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }
    string tempString;
    while(getline(fin, tempString))
    {
        int fl,fr,sl,sr;
        sscanf(tempString.c_str(), "%d-%d,%d-%d", &fl, &fr, &sl, &sr);


        if(fl<=sl && fr>=sr)
        {
            ans += 1;
        }
        else if(sl<=fl && sr>=fr)
        {
            ans += 1;
        }
        else if(fl<=sl && fr>=sl && fr<=sr)
        {
            ans += 1;
        }
        else if(sl<=fl && sr>=fl && sr<=fr)
        {
            ans += 1;
        }
        
    }

    cout << ans << endl;
    return 0;
}