// https://leetcode.com/problems/sudoku-solver/

#include<bits/stdc++.h>
using namespace std;


/*
backtrack(state){
    if(solution-found(state){
        - add state to answer
        - return
       }
       for all valid candidates:
        - add candidate to state
        - backtrack(state)
        - remove candidate from state
}


*/

const int N = 9;
char sudoku_bord[N][N];
vector<vector<char>> solution_bord;


 /*
    return true if the sudoku bord doesnt have any empty cess
 */
bool solution_found(vector<vector<char>>sudoku_bord){

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        if(sudoku_bord[i][j] == '.'){
            return false;
        }
    }

  }
    return true;
}

pair<int, int> get_first_free_cell(vector<vector<char>> sudoku_bord){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        if(sudoku_bord[i][j] == '.'){
            return {i,j};
        }
    }

  }
  return {-1, -1};
}


//// return the position of the first encountered '.' chracter in the suduko bored as pair
//vector<char> get_candidate(vector<vector<char>> sudoku_bord, pair<int, int> free_cell){
//  int ro = free_cell.first;
//  int col = free_cell.second;
//  vector<char>valid_candidates;
//
//
//  for(char digit = '1'; digit <= '9'; digit++){
//    bool is_candidate = true;
//    // check the row
//    for(int j = 0; j <N; j++){
//        if(sudoku_bord[ro][j] == digit){
//            is_candidate = false;
//            break;
//        }
//    }
//    // check the column
//    for(int i = 0; i < N; i++){
//        if(sudoku_bord[i][col] == digit){
//            is_candidate = false;
//            break;
//        }
//    }
//
//    // check the sub matrix
//    int r = (ro/3) * 3;
//    int c = (col/3) * 3;
//
//    for(int i = r; i < r+3; i++){
//        for(int j = c; j < j+3; j++){
//            if(sudoku_bord[i][j] == digit){
//                is_candidate = false;
//                break;
//            }
//        }
//    }
//    if(is_candidate){
//        valid_candidates.push_back(digit);
//    }
//
//  }
//  return valid_candidates;
//
//}

vector<char> get_candidate(vector<vector<char>> sudoku_bord, pair<int, int> free_cell){
  int ro = free_cell.first;
  int col = free_cell.second;
  vector<char> valid_candidates;

  for (char digit = '1'; digit <= '9'; digit++) {
    bool is_candidate = true;

    // check the row
    for (int j = 0; j < N; j++) {
      if (sudoku_bord[ro][j] == digit) {
        is_candidate = false;
        break;
      }
    }

    // check the column
    for (int i = 0; i < N; i++) {
      if (sudoku_bord[i][col] == digit) {
        is_candidate = false;
        break;
      }
    }

    // check the sub matrix
    int r = (ro / 3) * 3;
    int c = (col / 3) * 3;

    for (int i = r; i < r + 3; i++) {
      for (int j = c; j < c + 3; j++) {
        if (sudoku_bord[i][j] == digit) {
          is_candidate = false;
          break;
        }
      }
      if (!is_candidate) {
        break;
      }
    }

    if (is_candidate) {
      valid_candidates.push_back(digit);
    }
  }

  return valid_candidates;
}


bool backtrack(vector<vector<char>> sudoku_bord){
    if(solution_found(sudoku_bord)){
        solution_bord = sudoku_bord;
        return true;
    }

    pair<int , int> free_cell = get_first_free_cell(sudoku_bord);
    vector<char> candidates = get_candidate(sudoku_bord,free_cell);
    for(char candidat: candidates){
        int ro = free_cell.first;
        int col = free_cell.second;
        // add candidate to state
        sudoku_bord[ro][col] = candidat;
        // backtrack(state)
        bool solution_found = backtrack(sudoku_bord);
        if(solution_found){
            return true;
        }

        sudoku_bord[ro][col] = '.';
    }
    return false;
}


int main(){

vector<vector<char>> sudoku_bord(N, vector<char>(N));
for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        cin>>sudoku_bord[i][j];
    }
}

backtrack(sudoku_bord);

for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        cout<<solution_bord[i][j]<< " ";
    }
    cout<<endl;
}



 return 0;
}


/*




5 3 . . . 7 . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

*/
