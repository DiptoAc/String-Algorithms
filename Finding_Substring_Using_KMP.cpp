#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//uniform_int_distribution<int> random(1, 1000000);
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e16
const ll M =1e9+7;
const ll N =4e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<ll>prefix_function(string &s)   //Kpm's algorithm to efficiently match prefix.(KMP function)
{
    ll i,j,k,n= s.size();
    vector<ll>pi(n);
    for(i=1;i<n;i++)
    {
        j=pi[i-1];
        while(j && s[i]!=s[j])
        {
            j=pi[j-1];
        }
        if(s[i]==s[j]){j++;}
        pi[i]=j;
    }
    return pi;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        string s,ss;
        cin>>s>>ss;
        s=ss+" "+s;
        ll ans=0;
        vector<ll>v=prefix_function(s);
        //debug(v);for(auto it:s){cout<<it<<" ";}cout<<endl;
        for(i=2*ss.size();i<s.size();i++)
        {
            if(v[i]>=ss.size()){ans++;}
        }cout<<ans<<endl;
    }
}
/*
Problem: String Matching(CSES)
Link: https://cses.fi/problemset/task/1753

Input1:
abababbab
ab

Expected output:
4


Input2:
saippuakauppias
pp

Expected output:
2
*/

/*
Logic:
1) Append the substring to the beginning of the main string.
2) Calculate the prefix matches using KMP.
3) Count positions where the matched prefix length is greater than the size of the substring.

Discussion:
If you use s.find(ss, x) here, it may result in TLE (Time Limit Exceeded).
Although s.find() utilizes KMP, it also tries to implement other algorithms to optimize search time.
In certain cases, these optimizations can backfire, causing a TLE.
It’s better to implement your own KMP function to avoid this issue.
*/
