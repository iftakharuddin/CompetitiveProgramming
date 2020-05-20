const int MXN = 1e5+10;
int n, seg[MXN*4];
 
void build(int idx, int val, int nd = 1, int nl = 0, int nr = n-1){
    if(idx < nl or idx > nr) return;
    if(nl == nr){
        seg[nd] = val;
        return;
    }
    int mid = (nl + nr) / 2;
    int left = nd*2; int  right = left + 1;
    build(idx, val, left, nl, mid);
    build(idx, val, right, mid+1, nr);
    seg[nd] = min(seg[left], seg[right]);
}
 
int query(int i, int j, int nd = 1, int nl = 0, int nr = n-1){
    if(i > nr or j < nl) return MXN;
    if(nl >= i and nr <= j){
        return seg[nd];
    }
    int mid = (nl + nr) / 2;
    int left = nd*2; int right = left + 1;
    int x = query(i, j, left, nl, mid);
    int y = query(i, j, right, mid+1, nr);
    return min(x, y);
}
