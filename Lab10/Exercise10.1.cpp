// *****
// Build tree

// Tree node ??
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode (int v): val(v), left(nullptr), right(nullptr) {}
};

// Build tree from level traversal sequence.
TreeNode * build_tree_level(std::vector<std::string> v) {
    TreeNode * root = nullptr;
    int index = 0;
    if (!v.empty()) {
        root = new TreeNode(stoi(v[index]));
    }
    else
        return nullptr;

    std::queue<TreeNode*> q;  // ????????
    q.push(root);
    index++;
    while (index < v.size()) {
        if (!q.empty()) {
            TreeNode * cur = q.front();

            if (index < v.size()) {
                if (v[index] != "null") {
                    cur->left = new TreeNode(stoi(v[index]));
                    q.push(cur->left);
                }
                index++;
            }
            if (index < v.size()) {
                if (v[index] != "null") {
                    cur->right = new TreeNode(stoi(v[index]));
                    q.push(cur->right);
                }
                index++;
            }

            q.pop();
        }
    }

    return root;
}

int getMinimumDifference(TreeNode* root) {
    int min = 99999;
    vector<int> in;
    in_order(root, in);
    for (auto it = in.begin()+1; it < in.end(); it++) {
        if (*it - *(it-1) < min) min = *it - *(it - 1);
    }
    return min;
}

void in_order(TreeNode * root, vector<int>&in) {
    if (root->left) in_order(root->left, in);
    in.push_back(root->val);
    if (root->right) in_order(root->right, in);
}

