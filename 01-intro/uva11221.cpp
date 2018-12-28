#include <bits/stdc++.h>

using namespace std;

int TC, len, sqrt_len;
string line;
vector<string> square;

bool is_alpha(const char& c) {
  bool ans = 'a' <= c && c <= 'z';
  return ans;
}

void fill_square() {
  square.clear();
  square.resize(sqrt_len);
  for(int i = 0; i < sqrt_len; i++) {
    square[i] = line.substr(i*sqrt_len, sqrt_len);
  }
}

string build_str_2() {
  string str_2 = "";
  for(int i = 0; i < sqrt_len; i++) {
    for(int j = 0; j < sqrt_len; j++) {
      str_2 += square[j][i];
    }
  }
  return str_2;
}

string build_str_3() {
  string str_3 = "";
  for(int i = sqrt_len-1; i >= 0; i--) {
    for(int j = sqrt_len-1; j >= 0; j--) {
      str_3 += square[i][j];
    }
  }
  return str_3;
}

string build_str_4() {
  string str_4 = "";
  for(int i = sqrt_len-1; i >= 0; i--) {
    for(int j = sqrt_len-1; j >= 0; j--) {
      str_4 += square[j][i];
    }
  }
  return str_4;
}

bool solve() {
  len = line.size();
  sqrt_len = sqrt(len);
  if(sqrt_len * sqrt_len != len) return false;
  fill_square();
  string str_2 = build_str_2();
  string str_3 = build_str_3();
  string str_4 = build_str_4();
  if(line == str_2 && line == str_3 && line == str_4) return true;
  return false;
}

void clean_line() {
  string str = "";
  for(char c : line) {
    if(is_alpha(c)) {
      str += c;
    }
  }
  line = str;
}

int main() {
  cin >> TC;
  cin.ignore();
  for(int tc = 1; tc <= TC; tc++) {
    getline(cin, line);
    clean_line();

    bool sol = solve();

    cout << "Case #" << tc << ":\n";
    if(sol) {
      cout << sqrt_len << "\n";
    } else {
        cout << "No magic :(\n";
    }
  }
}
