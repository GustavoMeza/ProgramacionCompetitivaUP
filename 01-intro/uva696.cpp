#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
  while(cin >> a >> b, a!=0 || b!=0) {
    int _a = a, _b = b;
    if(_a > _b) swap(_a, _b);
    int ans = 0;
    if(_a == 1) ans = _b;
    else if(_a == 2) ans = 2*(_b/4*2 + min(2, _b%4));
    else ans = (_a*_b+1)/2;
    cout << ans << " knights may be placed on a " << a << " row " << b << " column board.\n";
  }
}
