/*
304. Range Sum Query 2D - Immutable
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner 
(row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), 
which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size();
        int m = matrix[0].size();
        partial = vector<vector<int>>(n, vector<int>(m, 0));
        partial[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            partial[0][i] += partial[0][i - 1] + matrix[0][i]; 
        }
        for (int i = 1; i < n; i++) {
            int psum = 0;
            for (int j = 0; j < m; j++) {
                psum += matrix[i][j];
                partial[i][j] = partial[i - 1][j] + psum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) return partial[row2][col2];
        else if (row1 == 0) return partial[row2][col2] - partial[row2][col1 - 1];
        else if (col1 == 0) return partial[row2][col2] - partial[row1 - 1][col2];
        else return partial[row2][col2] - partial[row1 - 1][col2] - partial[row2][col1 - 1] + partial[row1 - 1][col1 - 1];
    }
private:
    vector<vector<int>> partial;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
