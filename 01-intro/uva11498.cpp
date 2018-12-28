#include <bits/stdc++.h>

using namespace std;

int N, a, b, x, y;
string messagge[] = {"SO", "SE", "NO", "NE", "divisa"};

int main() {
  while(cin >> N, N) {
    cin >> a >> b;
    for(int i = 0; i < N; i++) {
      int ans = 0;
      cin >> x >> y;
      if(x > a) ans += 1;
      if(y > b) ans += 2;
      if(x == a || y == b) ans = 4;
      cout << messagge[ans] << "\n";
    }
  }
}
