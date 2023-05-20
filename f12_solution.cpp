#include "string"
#include "iostream"
#include "unordered_map"
#include "vector"
#include "stack"
#include "unordered_set"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class f12_solution {

public:

    /**
     * 1419 嚎叫的最小🐸数
     * frogNum 正在嚎叫的青蛙数量
     * cnt 正在嚎叫到某一字母时的青蛙数量 "这个状态是会转移的"
     * @param croakOfFrogs
     * @return
     */
    int minNumberOfFrags(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) return -1;
        vector<int> cnt(4);
        unordered_map<char, int> mp = {{'c', 0},
                                       {'r', 1},
                                       {'o', 2},
                                       {'a', 3},
                                       {'k', 4}};
        int res = 0, frogNum = 0;
        for (const auto &item: croakOfFrogs) {
            int t = mp[item];
            if (t == 0) { // 一只青蛙开始嚎叫
                cnt[t]++;
                frogNum++;
                if (frogNum > res) res = frogNum;
            } else {
                // 嚎叫到当前字母 的前一个字母没有青蛙发声 错误队列
                if (cnt[t - 1] == 0) return -1;

                cnt[t - 1]--; // 状态转移，青蛙从前一个字母嚎叫到现在的字母
                if (t == 4) frogNum--; // 一只青蛙嚎叫过程结束
                else cnt[t]++;
            }
        }
        if (frogNum > 0) return -1;
        return res;
    }


    int numPairsDivisibleBy60(vector<int> &time) {
        unordered_map<int, int> m(60);
        for (const auto &item: time)
            m[item % 60]++;

        int res = 0;
        // 余数为0 的歌曲 与余数为0 的歌曲组队 ，除了自身
        res += (long long) m[0] * (m[0] - 1) / 2;
        // 余数30歌曲同上
        res += (long long) m[30] * (m[30] - 1) / 2;
        // 1-29 匹配31-59
        for (int i = 1; i < 30; ++i) {
            res += m[i] * m[60 - i];
        }
        return (int) res;
    }


    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
        vector<int> ans;
        for (int i = arr1.size() - 1, j = arr2.size() - 1, c = 0; i >= 0 || j >= 0 || c; i--, j--) {
            int a = i >= 0 ? arr1[i] : 0;
            int b = j >= 0 ? arr2[j] : 0;
            int x = a + b + c;
            if (x >= 2) {
                x -= 2;
                c = -1;
            } else if (x == -1) {
                x = 1;
                c = 1;
            } else {
                c = 0;
            }
            ans.push_back(x);
        }
        // vector.back()返回最后一个元素， end返回最后一个内容元素后边的结尾元素 例如`\0`
        // !ans.back()  将会删除掉结尾多余的0元素
        while (ans.size() > 1 && !ans.back()) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    /**
     * 1079_dfs
     * @param tiles
     * @return
     */
    int numTilePossibilities(std::string tiles) {
        unordered_map<char, int> alpha_map;
        unordered_set<char> tile;
        for (const auto &item: tiles) {
            alpha_map[item]++;
            tile.insert(item);
        }
        return numDfs(alpha_map, tile, tiles.size()) - 1;
    }

    int numDfs(unordered_map<char, int> &count, unordered_set<char> &tile, int i) {
        if (i == 0) return 1;
        int res = 1;
        for (const auto &item: tile) {
            if (count[item] > 0) {
                count[item]--;
                res += numDfs(count, tile, i - 1);
                count[item]++;
            }
        }
        return res;
    }

    static const int inf = 0x3f3f3f;
    int res;
    /**
     * 用这个结构体来描述当前节点的情况
     */
    struct subTree{
        bool isBST; // 是否是搜索二叉树
        int minValue; // 该树中最小值
        int maxValue;
        int sumValue; // 累计数值
        subTree(bool isBST, int minValue, int maxValue, int sumValue):isBST(isBST), minValue(minValue), maxValue(maxValue), sumValue(sumValue){}
    };

    subTree dfs(TreeNode *root) {
        if (root == nullptr) return subTree(true, inf, -inf, 0);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // 满足搜索二叉树的条件
        if (left.isBST && right.isBST &&
            root->val > left.maxValue &&
            root->val < right.minValue
        ) {
            int sum = root->val + left.sumValue + right.sumValue;
            res = max(res, sum);
            return subTree(true, min(left.minValue, root->val), max(root->val, right.maxValue), sum);
        } else {
            return subTree(false, 0, 0, 0);
        }
    }
    //1373-二叉搜索子树的最大键值和-dfs
    int maxSumBST(TreeNode *root) {
        res = 0;
        dfs(root);
        return res;
    }

    bool isBST(TreeNode *root) {
        if (root == nullptr) return true;
        if (root->left && root->left->val > root->val) {
            return false;
        }
        if (root->right && root->right->val < root->val) {
            return false;
        }
        return isBST(root->left) && isBST(root->right);
    }
};

int main() {

    f12_solution solu;

    TreeNode *root = new TreeNode(7);
    auto rootLeft =  root->left = new TreeNode(4);
    auto r1 = rootLeft->left = new TreeNode(1);
    auto r2 = rootLeft->right = new TreeNode(5);
    auto rootRight = root->right = new TreeNode(10);

    bool res =  solu.isBST(root);
    cout << res << endl;
}