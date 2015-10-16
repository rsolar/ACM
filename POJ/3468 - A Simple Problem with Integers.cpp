#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 100005;

int n, m;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
template<typename T> struct SegmentTree {
  T sum[N << 2], add[N << 2];
  void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  }
  void push_down(int rt, int len) {
    if (add[rt]) {
      add[rt << 1] += add[rt]; add[rt << 1 | 1] += add[rt];
      sum[rt << 1] += add[rt] * (len - (len >> 1));
      sum[rt << 1 | 1] += add[rt] * (len >> 1);
      add[rt] = 0;
    }
  }
  //初始化 + 建树
  void build(int l, int r, int rt) {
    add[rt] = 0;
    if (l == r) { scanf("%I64d", &sum[rt]); return; }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
  }
  //区间增减
  void update(int L, int R, T val, int l, int r, int rt) {
    if (L <= l && r <= R) {
      add[rt] += val;
      sum[rt] += val * (r - l + 1);
      return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if (L <= m) { update(L, R, val, lson); }
    if (m < R) { update(L, R, val, rson); }
    push_up(rt);
  }
  //区间和
  T query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) { return sum[rt]; }
    push_down(rt, r - l + 1);
    int m = l + r >> 1; T ret = 0;
    if (L <= m) { ret += query(L, R, lson); }
    if (m < R) { ret += query(L, R, rson); }
    return ret;
  }
};
SegmentTree<ll> st;

int main() {
  int x, y, v; char o[2];
  scanf("%d %d", &n, &m);
  st.build(1, n, 1);
  while (m--) {
    scanf("%s %d %d", o, &x, &y);
    if (o[0] == 'C') {
      scanf("%d", &v);
      st.update(x, y, v, 1, n, 1);
    } else {
      printf("%I64d\n", st.query(x, y, 1, n, 1));
    }
  }
}
