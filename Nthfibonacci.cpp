#include<bits/stdc++.h>
using namespace std;
#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'
typedef long long ll;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int N = 3;
ll a, b;

void mul(ll A[][N], ll B[][N]){
   ll ret[N][N];
   for (int i = 0; i < 2; ++i)
   {
      for (int j = 0; j < 2; ++j)
      {
         ret[i][j] = 0;
         for (int k = 0; k < 2; ++k)
         {
            ret[i][j] += A[i][k]*B[j][k];
            ret[i][j] %= MOD;
         }
      }
   }

   for (int i = 0; i < 2; ++i)
   {
      for (int j = 0; j < 2; ++j)
      {
         A[i][j] = ret[i][j];
      }
   }
}


ll findFn(int n){
   if(n == 1) return b;
   ll T[N][N], I[N][N];
   I[0][0] = I[1][1] = 1;
   I[0][1] = I[1][0] = 0;
   T[0][1] = T[1][1] = T[1][0] = 1;
   T[0][0] = 0;

   while(n){
      if(n%2){
         mul(I, T);
         n--;
      }
      else {
         mul(T, T);
         n /= 2;
      }
   }
   ll ret = (I[0][0] * a + I[1][0] * b) % MOD;
   return ret;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef  ONLINE_JUDGE
   freopen("in", "r", stdin);
   freopen("out", "w", stdout);
   #endif
   int T, tc = 0; cin>>T;
   while(T--){
      int n;
      cin>>a>>b>>n;
      int ans = findFn(n);
      cout<< ans << endl;
   }
   return 0;
}
