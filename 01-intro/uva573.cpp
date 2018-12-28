#include <bits/stdc++.h>

using namespace std;

double H, U, D, F;

int main() {
  while(cin >> H >> U >> D >> F, H != 0) {
    double snail = 0, deltau = U * F / 100.0;
    int t=0;
    while(true) {
      if(t%2 == 0) {
        if(U > 0) {
          snail += U;
        }
        U -= deltau;
      } else {
        snail -= D;
      }
      if(snail > H || snail < 0) break;
      t++;
    }
    int day = 1+t/2;
    if(snail > H) {
      cout << "success on day " << day << "\n";
    } else {
      cout << "failure on day " << day << "\n";
    }
  }
}
