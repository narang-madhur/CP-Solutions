    #include<iostream>
    #include<map>
    using namespace std;
    #define INT_MAX 1000000000
     
    map<int,map<int,bool> > mp;
    map<int,map<int,int> > dp;
     
    int countw(int n,int m)
    {
        if(mp[n][m])
        {
            return INT_MAX;
        }
        if(n <= 0)
        {
            return INT_MAX;
        }
        if(n > m)
        {
            return n-m;
        }
        if(n == m)
        {
            return 0;
        }
        if(dp[n][m])
        {
            return dp[n][m];
        }
        mp[n][m] = true;
        int count1,count2;
        count1 = countw(n<<1,m) + 1;
        count2 = countw(n-1,m) + 1;
        mp[n][m] = false;
        dp[n][m] = min(count1,count2);
        return dp[n][m];
    }
     
    int main()
    {
        int n,m;
        cin>>n>>m;
        cout<<countw(n,m)<<endl;
        return 0;
    }