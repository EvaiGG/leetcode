//
// Created by Tony on 2023/4/29.
//

#include "map"
#include "string"
#include "iostream"
#include "algorithm"
#include "unordered_set"
#include "vector"
#include "unordered_map"
#include "algorithm"

class day11_solution {

public:



    bool equal_map(std::map<char, int> m) {
        std::vector<int> v;
        for (const auto &item : m){
            v.push_back(item.second);
        }
        std::sort(v.begin(),  v.end());
        if (v[0] != v[v.size()-1]) {
            return false;
        }
        return true;
    }

    /**
     * 字符串删掉一个字母后余下字母出现的频率是否相等
     * 一次遍历统计出每个字符的出现次数 形成charCount
     * 遍历charCount 将每一个遍历中的字符做-- 操作 , 然后新建一个set ，子遍历charCount 对>0 既存在的字母做插入操作，如果剩下的字母出现次数相同，那么set的长度应该是为1的 return true
     * 否则说明删减这个字符次数1达不到效果 对当前字符加一还原 继续遍历
     * @param word
     * @return
     */
    bool equalFrequency(std::string word) {
        int charCount[26] = {0};
        for (char& c : word) {
            charCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            std::unordered_set<int> frequency;
            for (int f : charCount) {
                if (f > 0) {
                    frequency.insert(f);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }


    // 1376
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {

        // 领导与下属之间的有向图
        std::unordered_map<int , std::vector<int>> employers;
        for (int i = 0; i < manager.size(); ++i) {
            employers[manager[i]].emplace_back(i);
        }

        std::function<int(int)> dfs = [&](int employers_id) ->int {
            int res = 0;

            // 找到代通知员工中通知时长最大的员工
            for (const auto &item : employers[employers_id]){
                res = std::max(res, dfs(item));
            }
            return informTime[employers_id] + res;
        };

        return dfs(headID);
    }

    // 2563 ugly
    bool isUgly(int n) {
        if (n <1) return false;
        while( n%2 == 0) {
            n >>=1;
        }
        while (n %3 == 0)
            n /= 3;
        while (n %5 == 0)
            n /=5;
        return n == 1;
    }
};

int main() {
    day11_solution solu;

    std::string str = "aazz";
    bool res =  solu.equalFrequency(str);
    std::cout << res << std::endl;
}
