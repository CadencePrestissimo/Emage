#include <bits/stdc++.h> 
using namespace std; 
#define mo 1000000007

//int mo = 1000000007;
int main() 
{ 
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int fre[n + 5] = {0};
        int a[n + 5];
        for(int i = 1; i <= n; i++)
            cin >> a[i], fre[a[i]]++;
        int mex = 0;
        int i = 0;
        while(fre[i])
            mex++, i++;
        multiset<int> s;
        int last_pos[mex + 5];
        for(int i = 0; i < mex; i++)
            last_pos[i] = -1, s.insert(-1);
        if(mex == 0)
            s.insert(0);
        int dp[n + 5] = {0}, pre[n + 5] = {0};
        dp[0] = 1, pre[0] = 1;
        for(int i = 1;i <= n; i++)
        {
            if(a[i] < mex)
            {
                s.erase(s.find(last_pos[a[i]]));
                last_pos[a[i]] = i;
                s.insert(last_pos[a[i]]);
            }
            else if(mex == 0)
            {
                s.erase(s.begin());
                s.insert(i);
            }
            if(*s.begin() >= 1)
            {
                dp[i] = pre[*s.begin() - 1]; 
            }
            pre[i] = (pre[i - 1] + dp[i])%mo;
            cout<<"pre["<<i<<"]="<<pre[i]<<" "<<"dp["<<i<<"]="<<dp[i]<<"\n";
        }
        cout <<"ans="<< dp[n] << "\n";
    }
} 
