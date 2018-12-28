#include <bits/stdc++.h>

using namespace std;

int h, m;

void read() {
  cin >> h;
  cin.ignore(INT_MAX, ':');
  cin >> m;
}

tuple<double, double> get_angles() {
  double _h, _m;
  _m = 360.0 / 60 * m;
  _h = 360.0 / 12 * (h + m / 60.0);
  return make_tuple(_h, _m);
}

double clean_angle(double theta) {
  while(theta < 0) theta += 360;
  while(theta > 360) theta -= 360;
  if(theta > 180) theta = 360 - theta;
  return theta;
}

int main() {
  while(read(), h != 0 || m != 0) {
    double angle_h, angle_m;
    tie(angle_h, angle_m) = get_angles();
    double diff = angle_h - angle_m;
    double ans = clean_angle(diff);
    cout << fixed << setprecision(3) << ans << "\n";
  }
}
