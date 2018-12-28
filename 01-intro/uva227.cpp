#include <tuple>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> board;
string line;
string instructions;
map<char, tuple<int, int> > directions;

void generar_direcciones() {
  directions['A'] = make_tuple(-1, 0);
  directions['B'] = make_tuple(1, 0);
  directions['L'] = make_tuple(0, -1);
  directions['R'] = make_tuple(0, 1);
  directions['0'] = make_tuple(0, 0);
}

// O(N^2)
tuple<int, int> obtener_hueco() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(board[i][j] == ' ') {
        // cout << i << " " << j << "\n";
        return make_tuple(i, j);
      }
    }
  }
}

// O(N^2)
bool procesar_instruccion(char instruction) {
  // cout << "instruction " << instruction << "\n";
  if(!directions.count(instruction)) return false;
  int r, c, newr, newc, dr, dc;
  tie(r, c) = obtener_hueco();
  tie(dr, dc) = directions[instruction];
  newr = r + dr, newc = c + dc;
  // cout << r << " " << c << " " << newr << " " << newc << "\n";
  if(newr >= 5 || newr < 0 || newc >= 5 || newc < 0) return false;
  swap(board[r][c], board[newr][newc]);
  return true;
}

// O(N^2)
void print_board() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(j > 0) cout << " ";
      cout << board[i][j];
    }
    cout << "\n";
  }
}

// O(N)
void corregir_tablero() {
  for(string &line : board) {
    if(line.length() < 5) {
      line += ' ';
    }
  }
}

// O(N^2 * M * T)
int main() {
  generar_direcciones();
  int tc = 0;
  while(getline(cin, line), line != "Z") {
    board.clear();
    board.emplace_back(line);
    for(int i = 0; i < 4; i++) {
      getline(cin, line);
      board.emplace_back(line);
    }
    corregir_tablero();
    /*for(string line : board)
      cout << line << "\n";
    */
    instructions = "";
    do {
      getline(cin, line);
      instructions += line;
    } while (line[line.length()-1] != '0');
    // cout << instructions << "\n";
    bool global_valid = true;
    // O(N^2 * M)
    for(char instruction : instructions) {
      bool valid = procesar_instruccion(instruction);
      if(!valid) {
        global_valid = false;
      }
    }

    if(tc > 0) {
      cout << "\n";
    }
    cout << "Puzzle #" << ++tc << ":\n";
    if(global_valid) {
      print_board();
    } else {
      cout << "This puzzle has no final configuration.\n";
    }
  }
}
