#include<bits/stdc++.h>
using namespace std;
#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'
typedef long long ll;
const double PI = acos(-1.0);

vector<int> primeFatorization(int x)
{
   vector<int> ret;
   for (int i = 2; i*i <= x; ++i)
   {
      if(x%i == 0){
         while(x%i == 0){
            x /= i;
            ret.push_back(i);
         }
      }
   }
   if(x > 1) ret.push_back(x);
   return ret;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef  ONLINE_JUDGE
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   #endif
   int n; cin>>n;
   vector<int> vv = primeFatorization(n);
   map<int, int>mp;
   for(auto a: vv){
      mp[a]++;
   } 

   for(auto a: mp){
      cout<<"("<<a.first<<", "<<a.second<<")\n";
   }
   
   return 0;
}
