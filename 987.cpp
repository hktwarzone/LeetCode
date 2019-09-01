/*
987. Vertical Order Traversal of a Binary Tree

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will 
be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical 
line touches some nodes, we report the values of the nodes in order from top to 
bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported 
first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will 
have a list of values of nodes.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        map<int, map<int, vector<int>>> m;
        queue<Node*> q;
        q.push(new Node{root, 0, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->n->left) q.push(new Node{p->n->left, p->x - 1, p->y + 1});
            if (p->n->right) q.push(new Node{p->n->right, p->x + 1, p->y + 1});
            m[p->x][p->y].push_back(p->n->val);
        }
        vector<vector<int>> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back({});
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                auto v = it2->second;
                sort(v.begin(), v.end());
                res.back().insert(res.back().end(), v.begin(), v.end());
            }
        }
        return res;
    }
private:
    struct Node {
        TreeNode* n;
        int x;
        int y;
    };
};
