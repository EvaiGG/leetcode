#include "string"
#include "iostream"
#include "unordered_map"
#include "vector"
#include "stack"
using namespace std;

class f12_solution{

public:

    /**
     * 1419 嚎叫的最小🐸数
     * frogNum 正在嚎叫的青蛙数量
     * cnt 正在嚎叫到某一字母时的青蛙数量 "这个状态是会转移的"
     * @param croakOfFrogs
     * @return
     */
    int minNumberOfFrags(string croakOfFrogs){
        if (croakOfFrogs.size() %5 != 0) return -1;
        vector<int> cnt(4);
        unordered_map<char, int> mp = {{'c', 0}, {'r', 1}, {'o',2}, {'a', 3}, {'k', 4}};
        int res = 0, frogNum = 0;
        for (const auto &item : croakOfFrogs){
            int t = mp[item];
            if (t == 0 ) { // 一只青蛙开始嚎叫
                cnt[t]++;
                frogNum ++;
                if (frogNum > res)  res = frogNum;
            } else {
                // 嚎叫到当前字母 的前一个字母没有青蛙发声 错误队列
                if (cnt[t -1] == 0)  return -1;

                cnt[t-1] --; // 状态转移，青蛙从前一个字母嚎叫到现在的字母
                if (t == 4) frogNum--; // 一只青蛙嚎叫过程结束
                else cnt[t] ++;
            }
        }
        if(frogNum>0) return -1;
        return res;
    }



    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m(60);
        for (const auto &item : time)
            m[item%60]++;

        int res = 0;
        // 余数为0 的歌曲 与余数为0 的歌曲组队 ，除了自身
        res += (long long)m[0]*(m[0]-1)/2;
        // 余数30歌曲同上
        res += (long long)m[30]*(m[30]-1)/2;
        // 1-29 匹配31-59
        for (int i = 1; i < 30; ++i) {
            res += m[i]*m[60-i];
        }
        return (int)res;
    }


    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        for (int i = arr1.size() - 1, j = arr2.size() - 1, c = 0; i >= 0 || j >= 0 || c; i--, j--) {
            int a = i >= 0 ? arr1[i] : 0;
            int b = j >= 0 ? arr2[j] : 0;
            int x = a + b + c;
            if (x >= 2) {
                x -= 2;
                c = -1;
            }
            else if (x == -1) {
                x = 1;
                c = 1;
            }
            else {
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
};

int main() {
    vector<int> arr1{1,1,1,1,1};
    vector<int> arr2{1,0,1};

    vector<int> ans(5,0);

    f12_solution solu;
    ans = solu.addNegabinary(arr1, arr2);
}