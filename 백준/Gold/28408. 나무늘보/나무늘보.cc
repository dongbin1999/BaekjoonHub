#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<int, int> postorderIndex;
int preIndex = 0;
vector<pair<int, int>> edges;
int singleChildNodes = 0;
const int MOD = 998244353;

TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder, int left, int right) {
    if (left > right) return nullptr;

    TreeNode* root = new TreeNode(preorder[preIndex++]);

    if (left == right || preIndex >= preorder.size()) return root;

    int postIndex = postorderIndex[preorder[preIndex]];

    if (postIndex <= right) {
        root->left = constructTree(preorder, postorder, left, postIndex);
        root->right = constructTree(preorder, postorder, postIndex + 1, right - 1);
    }

    if (root->left) {
        if (root->left->val < 1 || root->left->val > preorder.size()) {
            cout << 0 << endl;
            exit(0);
        }
        edges.push_back({root->val, root->left->val});
    }
    if (root->right) {
        if (root->right->val < 1 || root->right->val > preorder.size()) {
            cout << 0 << endl;
            exit(0);
        }
        edges.push_back({root->val, root->right->val});
    }

    if ((root->left && !root->right) || (!root->left && root->right)) {
        singleChildNodes++;
    }

    return root;
}

bool validateInput(int n, vector<int>& preorder, vector<int>& postorder) {
    if (preorder.size() != n || postorder.size() != n) return false;
    vector<bool> seen(n + 1, false);
    for (int num : preorder) {
        if (num < 1 || num > n || seen[num]) return false;
        seen[num] = true;
    }
    fill(seen.begin(), seen.end(), false);
    for (int num : postorder) {
        if (num < 1 || num > n || seen[num]) return false;
        seen[num] = true;
    }
    return true;
}

void createTreeFromEdges(TreeNode*& root, unordered_map<int, TreeNode*>& nodeMap, int rootVal) {
    for (const auto& edge : edges) {
        int parent = edge.first;
        int child = edge.second;
        if (!nodeMap[parent]) {
            nodeMap[parent] = new TreeNode(parent);
        }
        if (!nodeMap[child]) {
            nodeMap[child] = new TreeNode(child);
        }
        if (!nodeMap[parent]->left) {
            nodeMap[parent]->left = nodeMap[child];
        } else {
            nodeMap[parent]->right = nodeMap[child];
        }
    }
    root = nodeMap[rootVal]; // root is preorder[0]
}

void getPreorder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->val);
    getPreorder(node->left, result);
    getPreorder(node->right, result);
}

void getPostorder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    getPostorder(node->left, result);
    getPostorder(node->right, result);
    result.push_back(node->val);
}

int main() {
    int n;
    cin >> n;
    if(n==1)return !printf("1");
    vector<int> preorder(n), postorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> postorder[i];

    if (!validateInput(n, preorder, postorder)) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < postorder.size(); ++i) {
        postorderIndex[postorder[i]] = i;
    }

    TreeNode* root = constructTree(preorder, postorder, 0, postorder.size() - 1);

    unordered_map<int, TreeNode*> nodeMap;
    createTreeFromEdges(root, nodeMap, preorder[0]);

    vector<int> newPreorder, newPostorder;
    getPreorder(root, newPreorder);
    getPostorder(root, newPostorder);

    if (preorder != newPreorder || postorder != newPostorder) {
        cout << 0 << endl;
        return 0;
    }

    long long result = 1;
    for (int i = 0; i < singleChildNodes; ++i) {
        result = (result * 2) % MOD;
    }

    cout << result << endl;

    return 0;
}