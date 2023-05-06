#include "string"
#include "iostream"
#include "unordered_map"
#include "vector"
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
};

int main() {

}