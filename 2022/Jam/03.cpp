#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("03.input");
    if(fin.fail())
    {
        cout << "File not found" << endl;
        return 0;
    }
    string s1,s2,s3;
    int ans = 0;
    while(getline(fin, s1))
    {
        getline(fin,s2);
        getline(fin,s3);
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        // find the common letter of two strings
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        sort(s3.begin(), s3.end());
        // cout<<"s1 = "<<s1<<endl;
        // cout<<"s2 = "<<s2<<endl;
        // cout<<"s3 = "<<s3<<endl;

        int i = 0, j = 0, k = 0;
        char c;
        while(i < s1.length()&& j < s2.length() && k < s3.length())
        {
            // cout<<"i = "<<i<<" ,j = "<<j<<", k = "<<k<<endl;
            if(s1[i] == s2[j] && s1[i] == s3[k])
            {
                c = s1[i];
                break;
            }
            else if(s1[i] <= s2[j] && s1[i] <= s3[k])
            {
                i++;
            }
            else if(s2[j] <= s1[i] && s2[j] <= s3[k])
            {
                j++;
            }
            else if(s3[k] <= s1[i] && s3[k] <= s2[j])
            {
                k++;
            }
        }
            
        if(c>='a' && c<='z')
        {
            
            ans += c - 'a' + 1;
            // cout<<"c = "<<c<<endl;
        }
        else if(c>='A' && c<='Z')
        {
            ans += c - 'A' + 26 + 1;
            // cout<<"c = "<<c<<endl;
        }
    }
    cout << ans << endl;
    return 0;
}