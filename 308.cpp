/*
Range Sum Query 2D - Mutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner 
(row1, col1) and lower right corner (row2, col2).

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class SegTreeNode2D {
public:
    int val;
    SegTreeNode2D* children[4];
    pair<int, int> xrange;
    pair<int, int> yrange;
    SegTreeNode2D(pair<int, int> a, pair<int, int> b): xrange(a), yrange(b) {
        val = 0;
        for (int i = 0; i < 4; i++) { children[i] = NULL; }
    }
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) root = NULL;
        else root = buildTree(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
    void update(int row, int col, int val) {
        SegTreeNode2D* curr = root;
        SegTreeNode2D* next;
        while(curr) {
           if (row == curr->xrange.first && row == curr->xrange.second && col == curr->yrange.first && col == curr->yrange.second) break;
           next = NULL;
           for (int i = 0; i < 4; i++) {
               next = curr->children[i];
               if (next != NULL && next->xrange.first <= row && row <= next->xrange.second && next->yrange.first <= col && col <= next->yrange.second) break;
           }
           curr = next;
        }
        int oldval = curr->val;
        if (val == oldval) return;
        curr = root;
        while(curr) {
            curr->val += (val - oldval);
            if (curr->xrange.first == row && row == curr->xrange.second && curr->yrange.first == col && col == curr->yrange.second) break;
            next = NULL;
            for (int i = 0; i < 4; i++) {
                next = curr->children[i];
                if (next != NULL && next->xrange.first <= row && row <= next->xrange.second && next->yrange.first <= col && col <= next->yrange.second) break;
            }
            curr = next;
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumHelper(root, row1, col1, row2, col2);
    }
private:
    SegTreeNode2D* root;
    SegTreeNode2D* buildTree(vector<vector<int>> &matrix, int xstart, int xend, int ystart, int yend) {
        SegTreeNode2D* res = new SegTreeNode2D(make_pair(xstart, xend), make_pair(ystart, yend));
        if (xstart == xend && ystart == yend) {
            res->val += matrix[xstart][ystart];
            return res;
        }
        int xmid = xstart + (xend - xstart) / 2;
        int ymid = ystart + (yend - ystart) / 2;
        res->children[0] = buildTree(matrix, xstart, xmid, ystart, ymid);
        res->val += res->children[0]->val;
        if (ymid + 1 <= yend) {
            res->children[1] = buildTree(matrix, xstart, xmid, ymid + 1, yend);
            res->val += res->children[1]->val;
        }
        if (xmid + 1 <= xend) {
            res->children[2] = buildTree(matrix, xmid + 1, xend, ystart, ymid);
            res->val += res->children[2]->val;
        }
        if (xmid + 1 <= xend && ymid + 1 <= yend) {
            res->children[3] = buildTree(matrix, xmid + 1, xend, ymid + 1, yend);
            res->val += res->children[3]->val;
        }
        return res;
    }
    int sumHelper(SegTreeNode2D* node, int row1, int col1, int row2, int col2) {
        if (!node) return 0;
        if (row1 == node->xrange.first && row2 == node->xrange.second && col1 == node->yrange.first && col2 == node->yrange.second) return node->val;
        int xmid = node->xrange.first + (node->xrange.second - node->xrange.first) / 2;
        int ymid = node->yrange.first + (node->yrange.second - node->yrange.first) / 2;
        if (row1 <= xmid && col1 <= ymid) {
            if (row2 <= xmid) {
                if (col2 <= ymid) return sumHelper(node->children[0], row1, col1, row2, col2);
                else return sumHelper(node->children[0], row1, col1, row2, ymid) + sumHelper(node->children[1], row1, ymid + 1, row2, col2);
            }
            else {
                if (col2 <= ymid) return sumHelper(node->children[0], row1, col1, xmid, col2) + sumHelper(node->children[2], xmid + 1, col1, row2, col2);
                else return sumHelper(node->children[0], row1, col1, xmid, ymid) + sumHelper(node->children[1], row1, ymid + 1, xmid, col2) + sumHelper(node->children[2], xmid + 1, col1, row2, ymid) + sumHelper(node->children[3], xmid + 1, ymid + 1, row2, col2);
            } 
        }
        else if (row1 <= xmid && col1 > ymid) {
            if (row2 <= xmid) return sumHelper(node->children[1], row1, col1, row2, col2);
            else return sumHelper(node->children[1], row1, col1, xmid, col2) + sumHelper(node->children[3], xmid + 1, col1, row2, col2);
        }
        else if (row1 > xmid && col1 <= ymid) {
            if (col2 <= ymid) return sumHelper(node->children[2], row1, col1, row2, col2);
            else return sumHelper(node->children[2], row1, col1, row2, ymid) + sumHelper(node->children[3], row1, ymid + 1, row2, col2);
        }
        else return sumHelper(node->children[3], row1, col1, row2, col2);
    }
};
