const int MXN = 1e5+10;
int n;
struct node
{
   int v = 0, p = 0;
}seg[MXN*4];

void add(int l, int r, int x, int nd = 1, int nl = 0, int nr = n-1)
{
   if(l > nr or r < nl) return;
   if(l <= nl and r >= nr){
      seg[nd].v += (nr - nl +1)*x;
      seg[nd].p += x;
      return;
   }
   int mid = (nl + nr) / 2;
   add(l, r, x, nd*2, nl, mid);
   add(l, r, x, nd*2+1, mid+1, nr);
   seg[nd].v = seg[nd].p*(nr-nl+1) + seg[nd*2].v + seg[nd*2+1].v;
}

int sum(int l, int r, int pp = 0, int nd = 1, int nl = 0, int nr = n-1)
{
   if(l > nr or r < nl) return 0;
   if(l <= nl and r>= nr){
      return pp*(nr-nl+1) + seg[nd].v;
   }
   int mid = (nl + nr) / 2;
   int x = sum(l, r, pp+seg[nd].p, nd*2, nl, mid);
   int y = sum(l, r, pp+seg[nd].p, nd*2 + 1, mid + 1, nr);
   return x + y;
}
