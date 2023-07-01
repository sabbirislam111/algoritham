#include<bits/stdc++.h>
using namespace std;

const int N = 9;
char sudoku_board[N][N];
vector<vector<char>> solution_board;

// Checks if the given Sudoku board is complete
bool is_board_complete(vector<vector<char>> board) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

// Finds the first empty cell (with value '.') in the board and returns its coordinates
pair<int, int> get_first_empty_cell(vector<vector<char>> board) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '.') {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Checks if the given digit can be placed in the given cell in the board
bool is_valid_placement(vector<vector<char>> board, int row, int col, char digit) {
    // Check the row and column for the same digit
    for(int i = 0; i < N; i++) {
        if(board[row][i] == digit || board[i][col] == digit) {
            return false;
        }
    }

    // Check the 3x3 box for the same digit
    int box_start_row = (row / 3) * 3;
    int box_start_col = (col / 3) * 3;
    for(int i = box_start_row; i < box_start_row + 3; i++) {
        for(int j = box_start_col; j < box_start_col + 3; j++) {
            if(board[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

// Recursively backtracks through the board to find a solution
bool backtrack(vector<vector<char>> board) {
    if(is_board_complete(board)) {
        solution_board = board;
        return true;
    }

    pair<int, int> empty_cell = get_first_empty_cell(board);
    int row = empty_cell.first;
    int col = empty_cell.second;

    for(char digit = '1'; digit <= '9'; digit++) {
        if(is_valid_placement(board, row, col, digit)) {
            board[row][col] = digit;
            if(backtrack(board)) {
                return true;
            }
            board[row][col] = '.';
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board(N, vector<char>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    backtrack(board);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << solution_board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

