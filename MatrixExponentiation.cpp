typedef long long ll;
const int N = 60;
const int MOD = 1e9+7;

ll Mat[N][N], I[N][N];

void MatMul(ll C[][N], ll D[][N], int dim)
{
   ll ret[dim][dim];
   for (int i = 0; i < dim; ++i)
   {
      for (int j = 0; j < dim; ++j)
      {
         ret[i][j] = 0;
         for (int k = 0; k < dim; ++k)
         {
            ret[i][j] += C[i][k] * D[k][j];
            ret[i][j] %= MOD;
         }
      }
   }
   for (int i = 0; i < dim; ++i)
   {
      for (int j = 0; j < dim; ++j)
      {
         C[i][j] = ret[i][j];
      }
   }
}

void PowerOfMat(ll A[][N], int dim, int n)
{
   for (int i = 0; i < dim; ++i)
   {
      for (int j = 0; j < dim; ++j)
      {
         if(i == j) I[i][j] = 1;
         else I[i][j] = 0;
      }
   }

   while(n){
      if(n%2) MatMul(I, A, dim), n--;
      else MatMul(A, A, dim), n /= 2;
   } 

   for (int i = 0; i < dim; ++i)
   {
      for (int j = 0; j < dim; ++j)
      {
         A[i][j] = I[i][j];
      }
   }
}

void PrintMat(ll A[][N], int dim)
{
   for (int i = 0; i < dim; ++i)
   {
      for (int j = 0; j < dim; ++j)
      {
         cout<<A[i][j]<<" ";
      }
      cout<<endl;
   }
}
