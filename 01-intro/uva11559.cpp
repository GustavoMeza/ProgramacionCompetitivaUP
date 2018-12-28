#include <bits/stdc++.h>

using namespace std;

int N, B, H, W, p, a;

int main() {
  while(cin >> N >> B >> H >> W) {
    int ans = B+1;
    for(int i = 0; i < H; i++) {
      cin >> p;
      for(int j = 0; j < W; j++) {
        cin >> a;
        if(a >= N) {
          ans = min(ans, N*p);
        }
      }
    }
    if(ans <= B) {
      cout << ans << "\n";
    } else {
      cout << "stay home\n";
    }
  }
}
