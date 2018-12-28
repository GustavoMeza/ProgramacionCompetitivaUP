#include <bits/stdc++.h>

using namespace std;

const int MAX_INST = 75;

int TC;
vector<vector<bool> > board;
vector<vector<int> > A;
vector<int> instruction(75);

bool des_diag_has_bingo() {
  int marked = 0;
  for(int i = 0; i < 5; i++) {
    if(board[i][i]) {
      marked++;
    }
  }
  return marked == 5;
}

bool asc_diag_has_bingo() {
  int marked = 0;
  for(int i = 0; i < 5; i++) {
    if(board[i][4-i]) {
      marked++;
    }
  }
  return marked == 5;
}

bool col_has_bingo(int c) {
  int marked = 0;
  for(int i = 0; i < 5; i++) {
    if(board[i][c]) {
      marked++;
    }
  }
  return marked == 5;
}

bool row_has_bingo(int r) {
  int marked = 0;
  for(int i = 0; i < 5; i++) {
    if(board[r][i]) {
      marked++;
    }
  }
  return marked == 5;
}

bool has_bingo() {
  for(int i = 0; i < 5; i++) {
    if(row_has_bingo(i)) return true;
  }
  for(int i = 0; i < 5; i++) {
    if(col_has_bingo(i)) return true;
  }
  if(asc_diag_has_bingo()) return true;
  if(des_diag_has_bingo()) return true;
  return false;
}

tuple<int, int> find_in_board(int x) {
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      if(A[i][j] == x)
        return make_tuple(i, j);
  return make_tuple(-1, -1);
}

void mark_board(int x) {
  int r, c;
  tie(r, c) = find_in_board(x);
  if(r != -1) {
    board[r][c] = true;
  }
}

void setup_board() {
  board.clear();
  board.assign(5, vector<bool>(5, false));
  board[2][2] = true;
}

int main() {
  cin >> TC;
  while(TC--) {
    A.clear();
    A.assign(5, vector<int>(5));
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        if(i != 2 || j != 2) {
          cin >> A[i][j];
        }
      }
    }
    setup_board();
    instruction.clear();
    instruction.resize(MAX_INST);
    for(int i = 0; i < MAX_INST; i++) {
      cin >> instruction[i];
    }
    int sol;
    for(sol = 0; !has_bingo(); sol++) {
      mark_board(instruction[sol]);
    }
    cout << "BINGO after " << sol << " numbers announced\n";
  }
}
