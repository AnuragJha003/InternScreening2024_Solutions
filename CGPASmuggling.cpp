#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> zeroes(31,0),ones(31,0);
    for(int i=0;i<31;i++)
    {
        int temp=(1<<i);
        for(int j=0;j<n;j++)
        {
            if((v[j]&temp)>0)
            ones[i]++;
            else
            zeroes[i]++;
        }
    }
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            for(int i=0;i<31;i++)
            {
                int temp=(1<<i);
                if((v[x]&temp)>0)
                ones[i]--;
                else
                zeroes[i]--;
            }
            v[x]=y;
            for(int i=0;i<31;i++)
            {
                int temp=(1<<i);
                if((v[x]&temp)>0)
                ones[i]++;
                else
                zeroes[i]++;
            }
        }
        else
        {
            int ans=0;
            for(int i=0;i<31;i++)
            {
                ans+=zeroes[i]*ones[i]*(1LL<<i);
            }
            cout<<ans<<endl;
        }
    }
}

signed main(){
    FastIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}