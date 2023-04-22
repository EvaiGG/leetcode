//
// Created by Tony on 2023/4/21.
//

//#include "string"
#include "algorithm"
#include "iostream"
using namespace std;

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
};

int main() {
//    day8_solution solu;
//    int n =  solu.longestContinuousSubstring("abcdefg");
//    std::cout << n << endl;

    int n;
    cin >> n;
}
