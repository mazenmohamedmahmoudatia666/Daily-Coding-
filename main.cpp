#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#define endl "\n"
using namespace std;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

// ---------------------------------------------------------------------------
//                    Solution
// ---------------------------------------------------------------------------
void solve()
{
  int n;
  cin >> n;
   vector < int > a(n) , b(n)   ;
   for(int i =0; i < n; i++)
    cin >> a[i];
     for(int i =0; i < n; i++)
    cin >> b[i];
    vector <int > c(2*n);
    for(int i = 0; i < 2*n; i++){
      if(a.size || b.size()){
        c.insert(a[i]);
        c.insert(b[i]);
      }

      
    }
     

   




}

// ---------------------------------------------------------------------------
//                     Main
// ---------------------------------------------------------------------------
int main()
{
    fastio();
    int t = 1;
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
