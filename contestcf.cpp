#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[2001][2001][2][2];

int f(string &s,ll low,ll high,bool fg,bool prev)
{
      if(low>high)
      {
            return 2;
      }

      if(dp[low][high][fg][prev]!=-1)
      {
            return dp[low][high][fg][prev];
      }
      int ans=(fg^1);
      if(fg)
      {
            ll a=f(s,low+1,high,0,1);
            ll b=f(s,low,high-1,0,0);
            if(a==1 || b==1)
            {
                  ans=1;
            }
            else 
            {
                  if(a==2 || b==2)
                  {
                        ans=2;
                  }
                  else {
                      ans=0;
                  }
            }

      }
      else
      {
          ll prevx=(prev) ? (s[low-1]-'a') : (s[high+1]-'a');
          ll a=f(s,low+1,high,1,0);
          if(a==0)
          {
              ans=0;
          }
          else if(a==2)
          {
              if(prevx<s[low]-'a')
              {
                  ans=0;
                  
              }
              else if(prevx==s[low]-'a')
              {
                  ans=2;
                  
              }
              
          }
          
          ll b=f(s,low,high-1,1,0);
          
          if(b==0)
          {
              ans=0;
          }
          else if(b==2)
          {
              if(prevx<s[high]-'a')
              {
                  ans=0;
                  
              }
              else if(prevx==s[high]-'a')
              {
                  ans=2;
                  
              }
              
          }
      }
      return dp[low][high][fg][prev]=ans;
}

void solve()
{
    string s;
    cin>>s;
    ll n=s.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++) {
        for(int k=0;k<2;k++)
        {
            dp[i][j][0][k]=-1;
            dp[i][j][1][k]=-1;
        }
        }
    }
    int ans=f(s,0,n-1,1,0);
    if(ans==1)
    {
        cout<<"Alice\n";
    }
    else if(ans==2)
    {
        cout<<"Draw\n";
    }
    else 
    {
        cout<<"Bob\n";
    }
}


int main()
{
    ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

