//
// Created by Tony on 2023/4/21.
//

//#include "string"
#include "algorithm"
#include "iostream"
#include "unordered_map"
//#include ""
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class day8_solution{
public:
    int smallestEvenMultiple(int n) {
        if (n %2 == 0) return 0;
        if (n < 2) return n;
        return n*2;
    }

    /**
     * 2414 最长的字母序连续子字符串的长度 双指针
     * @param s
     * @return
     */
    int longestContinuousSubstring(string s) {

        int res = 0, len = s.size();
        for (int left = 0, right = 0; right < len-1;) {
            int curr = 0;
            while(right < len-1 && s.at(right+1) - s.at(right) == 1) {
                right++;
            }
            curr = right - left;
            right++;
            left = right;
            res =std::max(curr, res);
//            std::stoi();
        }
        return res+1;
    }

    /**
     * 1027 最长等差数列
     * @param nums  nums.length >= 2;
     * @return
     */
    // 1027
    int longestArithSeqLength(vector<int>& nums) {
        auto [minit, maxit] = minmax_element(nums.begin(),  nums.end());

        int diff =  *maxit - *minit;
        int ans = 1;
        for (int d = -diff; d <= diff; ++d) {
            vector<int> f(*maxit+1, -1);
            for (const auto &num : nums){
                int prev = num -d;
                if (prev >= *minit && prev <= *maxit && f[prev] != -1) {
                    f[num] = max(f[num], f[prev] +1);
                    ans = max(f[num], ans);
                }
                f[num] = max(f[num], 1);
            }
        }
        return ans;

    }

    /**
     * dfs 1026
     * @param root
     * @return
     */
    int maxAncestorDiff(TreeNode *root){
        return maxDiff(root, root->val, root->val);
    }

    /**
     *
     * @param root  当前节点
     * @param mi 当前继承路径上最大节点值
     * @param ma 当前继承路径上最小节点值
     * @return
     */
    int maxDiff(TreeNode *root, int mi, int ma) {
        if (root == nullptr) return 0;
        int diff = max(abs(root->val - mi), abs(root->val - ma));
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        diff = max(diff, maxDiff(root->left, mi, ma));
        diff = max(diff, maxDiff(root->right, mi, ma));
        return diff;
    }

    // 1105
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        int n = books.size();
        vector<int> dp(n+1, 1000000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int maxHeight = 0,curWidth = 0;
            for (int j = i; j >= 0 ; --j) {
                curWidth +=books[j][0];
                if( curWidth > shelfWidth) {
                    break;
                }
                maxHeight = max( maxHeight, books[j][1]);
                dp[i+1] = min(dp[i+1] , dp[j] + maxHeight);
            }
        }
        return dp[n];
    }

    /**
     * 同构字符串 s t 长度相等
     * @param s
     * @param t
     * @return
     */
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> containerS;
        std::unordered_map<char, char> containerT;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            // 如果两个容器里面还没有这个映射 加入这个映射
            if (containerS.count(s[i])== 0 && containerT.count(t[i])==0) {
                containerS[s[i]] = t[i];
                containerT[t[i]] = s[i];
            } else {
                if(containerS[s[i]]!= t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    day8_solution solu;
//    int n =  solu.longestContinuousSubstring("abcdefg");
//    std::cout << n << endl;

    vector<vector<int>> v{
            {1,1},
            {2,3},
            {2,3},
            {1,1},
            {1,1,},
            {1,1},
            {1,2}
    };
    int res =  solu.minHeightShelves(v, 4);
    cout << res << endl;
}
