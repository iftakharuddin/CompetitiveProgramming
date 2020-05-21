#include<bits/stdc++.h>
using namespace std;
#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'
typedef long long ll;
const double PI = acos(-1.0);
const int MXN = 10000005;
int firstFactor[MXN];

void sieve(){
   memset(firstFactor, -1, sizeof(firstFactor));
   for (int i = 2; i*i < MXN; ++i)
   {
      if(firstFactor[i] == -1){
         for (int j = i*i; j < MXN; j += i)
         {
            if(firstFactor[j] == -1) firstFactor[j] = i;
         }
      }
   }
}  

vector<int> PrimeFactorization(int n)
{
   vector<int> ret;
   while(n > 1){
      int ff = firstFactor[n];
      if(ff == -1){
         ret.push_back(n);
         break;
      }
      else ret.push_back(ff);
      n /= ff;
   }

   return ret;
}


int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef  ONLINE_JUDGE
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   #endif
   sieve();
   int n; cin>>n;
   vector<int> vv = PrimeFactorization(n);
   map<int, int> mp;
   for(auto a: vv) mp[a]++;
   for(auto a: mp){
      printf("(%d, %d)\n", a.first, a.second);
   }
   
   return 0;
}
