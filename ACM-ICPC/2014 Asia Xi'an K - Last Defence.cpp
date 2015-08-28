#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
using namespace std;

typedef long long ll;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define N 200005
#define M 1000000007
#define judge(x,y) ((x)>=0&&(x)<h&&(y)>=0&&(y)<w)

template<class T> inline bool getInt(T &x) {
	char c = 0; T sign = 1;
	if ((c = getchar()) == EOF) { return false; }
	while ((c < '0' || c > '9') && c != '-') { c = getchar(); };
	if (c == '-') { sign = -1; c = getchar(); }
	x = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') { x = x * 10 + c - '0'; }
	x *= sign;
	return true;
}

int main() {
	int C = 0, T; ll a, b, t;
	getInt(T);
	while (++C <= T) {
		getInt(a); getInt(b);
		ll ans = 1 + ((a != 0 && b == 0) || (a == 0 && b != 0));
		while (b != 0) {
			t = a % b;
			ans += a / b;
			a = b;
			b = t;
		}
		printf("Case #%d: %I64d\n", C, ans);
	}
}
