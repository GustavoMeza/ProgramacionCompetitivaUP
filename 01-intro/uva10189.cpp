#include <bits/stdc++.h>

using namespace std;

int R, C, tc;
vector<string> B, ans;

bool in_board(int x, int y) {
  bool ans = 0 <= x && x < R && 0 <= y && y < C;
  return ans;
}

int count_mines(int x, int y) {
  int ans = 0;
  for(int k = x-1; k <= x+1; k++) {
    for(int l = y-1; l <= y+1; l++) {
      if(in_board(k, l) && B[k][l] == '*') {
        ans++;
      }
    }
  }
  return ans;
}

void fill_ans() {
  ans = B;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(B[i][j] == '*') {
        ans[i][j] = '*';
      } else {
        ans[i][j] = count_mines(i, j) + '0';
      }
    }
  }
}

int main() {
  while(cin>>R>>C, R != 0 || C != 0) {
    B.clear(); B.resize(R);
    for(int i = 0; i < R; i++) cin >> B[i];
    fill_ans();
    if(tc) cout << "\n";
    cout << "Field #" << ++tc << ":\n";
    for(int i = 0; i < R; i++) cout << ans[i] << "\n";
  }
}
