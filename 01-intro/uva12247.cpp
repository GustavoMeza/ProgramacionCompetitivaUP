#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<int> A(3), B(2);

void read_input() {
  for(int i = 0; i < 3; i++) cin >> A[i];
  for(int i = 0; i < 2; i++) cin >> B[i];
}

bool is_in_set(int x) {
  for(int n : A) {
    if(n == x) return true;
  }
  for(int n : B) {
    if(n == x) return true;
  }
  return false;
}

tuple<int, int> two_greatest(vector<int>& v) {
  int gr=-1, gr_2=-1;
  for(int n : v) {
    if(n > gr) {
      gr_2 = gr;
      gr = n;
    } else if(n > gr_2) {
      gr_2 = n;
    }
  }
  return make_tuple(gr, gr_2);
}

tuple<int, int> two_lowest(vector<int>& v) {
  int lo=INF, lo_2=INF;
  for(int n : v) {
    if(n < lo) {
      lo_2 = lo;
      lo = n;
    } else if(n < lo_2) {
      lo_2 = n;
    }
  }
  return make_tuple(lo, lo_2);
}

bool will_win(int x) {
  vector<int> B_copy = B;
  B_copy.emplace_back(x);
  int gr, gr_2, lo, lo_2;
  tie(gr, gr_2) = two_greatest(A);
  tie(lo, lo_2) = two_lowest(B_copy);
  bool can_loose = gr > lo_2 && gr_2 > lo;
  return !can_loose;
}

int main() {
  while(read_input(), A[0] != 0) {
    int sol;
    for(sol=1; sol<=52; sol++) {
      if(!is_in_set(sol) && will_win(sol)) break;
    }
    if(sol == 53) {
      cout << "-1\n";
    } else {
      cout << sol << "\n";
    }
  }
}
