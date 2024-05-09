#include <iostream>
#include <vector>
using namespace std;
int cnt = 1;
void display(const vector<vector<bool>> &board) {
    for (const auto &row : board) {
        for (bool cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(const vector<vector<bool>> &board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }
    // Left Diagonal
    int shiftLeft = min(row, col);
    for (int i = 1; i <= shiftLeft; i++) {
        if (board[row - i][col - i]) {
            return false;
        }
    }
    // Right Diagonal
    int shiftRight = min(row, n - col - 1);
    for (int i = 1; i <= shiftRight; i++) {
        if (board[row - i][col + i]) {
            return false;
        }
    }
    return true;
}

int queensB(vector<vector<bool>> &board, int row) {
    if (row == board.size()) {
        display(board);
        cout << endl;
        return 1;
    }
    int count = 0;
    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = true;
            display(board); 
            count += queensB(board, row + 1);
            board[row][col] = false;
        }
    }
    return count;
}

void queensBNB(vector<vector<bool>> &board, int row, vector<bool> &colCheck, vector<bool> &leftDiagonal, vector<bool> &rightDiagonal) {
    if (row == board.size()) {
        cout << "FINAL Arrangement " << cnt << endl;
        cnt += 1;
        display(board);
        return;
    }
    int n = board[row].size();
    for (int col = 0; col < n; col++) {
        if (!colCheck[col] && !leftDiagonal[row + col] && !rightDiagonal[row - col + n - 1]) {
            board[row][col] = true;
            colCheck[col] = true;
            leftDiagonal[row + col] = true;
            rightDiagonal[row - col + n - 1] = true;
            display(board); 
            queensBNB(board, row + 1, colCheck, leftDiagonal, rightDiagonal);
            board[row][col] = false;
            colCheck[col] = false;
            leftDiagonal[row + col] = false;
            rightDiagonal[row - col + n - 1] = false;
        }
    }
}

void backtracking(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    cout << queensB(board, 0) << endl;
}

void branchAndBound(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<bool> colCheck(n, false);
    vector<bool> rightDiagonal(2 * n - 1, false);
    vector<bool> leftDiagonal(2 * n - 1, false);
    queensBNB(board, 0, colCheck, leftDiagonal, rightDiagonal);
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    cout << "Backtracking" << endl;
    backtracking(n);

    cnt = 1; 

    cout << "Branch And Bound" << endl;
    branchAndBound(n);

    return 0;
}
