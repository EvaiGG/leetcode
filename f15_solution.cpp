//
// Created by Tony on 2023/7/14.
//

#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class f15_solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<int> path ;

        dfs(root, target, res, path);
        return res;
    }

    void dfs(TreeNode* root, int target, vector<vector<int>> &res, vector<int> &path) {
        if (root == nullptr) return;
        target -= root->val;
        path.push_back(root->val);

        if(target == 0 && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        dfs(root->left, target, res, path);
        dfs(root->right, target, res, path);
        path.pop_back();
    }

    /**
     * 2554. 从一个范围内选择最多整数 I
     * @param banned 禁选数组
     * @param n 选择数的范围 [1, n]
     * @param maxSum 选择数之和不得超过maxSum
     * @return
     */
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        std::unordered_set<int> bannedSet;
        for (const auto &item : banned){
            bannedSet.insert(item);
        }

        int count = 0;
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.count(i)) continue;
            if (sum + i > maxSum) break;

            count ++;
            sum += i;
        }
        return count;
    }
};



