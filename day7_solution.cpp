//
// Created by Tony on 2023/4/14.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "stack"
#include "set"
#include "math.h"

using namespace std;

class day7_solution {

public:
    // 1023_驼峰式匹配
    bool camel(string query, string pattern) {
        int p1 = 0, p2;
        for (p2 = 0; p2 < pattern.size(); ++p2) {
            if (pattern[p2] == query[p1]) {
                // 相同，继续下一个匹配符号
                ++p1;
                continue;
//                break;
            }
            // 小写字母
            if (pattern[p2] >= 'a' && pattern[p2] <= 'z') {
                // 停下的情况 超出长度 找到匹配符 找到大写字母
                while (p1 < query.size() && query[p1] != pattern[p2] && query[p1] >= 'a') {
                    cout << "小写：p1" << p1 << " query[p1]" << query[p1] << endl;
                    p1++;
                }
                cout << query[p1] << endl;
                if (query[p1] == pattern[p2]) {
                    p1++;
                    continue;
                }
//                if (p1 > query.size() || )
                return false;
            }
            if (pattern[p2] >= 'A' && pattern[p2] <= 'Z') {
                while (p1 < query.size() && query[p1] != pattern[p2] && query[p1] >= 'a') {
                    p1++;
                }
                if (query[p1] == pattern[p2]) {
                    p1++;
                    continue;
                }
                return false;
            }
        }
        while (p1 < query.size()) {
            if (query[p1] <= 'Z') {
                return false;
            }
            p1++;
        }
        return true;
    }

    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        vector<bool> res(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = camel(queries[i], pattern);
        }
        return res;
    }

    // 169 多数元素
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> map;
        for (const auto &item: nums) {
            map[item]++;
        }
        int maxIndex = 0, maxCnt = 0;
        for (const auto &item: map) {
            if (item.second > maxCnt) {
                maxCnt = item.second;
                maxIndex = item.first;
            }
        }
        return maxIndex;
    }

//    string convertToTitle(int columnNumber) {
//        stack<char> v ;
//        while((double)columnNumber /26 >1.0 ) {
//            char ch = 65 + columnNumber % 26;
//            columnNumber = columnNumber /26;
//            v.push(ch);
//            cout << "逆序 ch: " << ch << endl;
//        }
//        v.push(65  + columnNumber%26);
//        string res;
//
//        while (!v.empty()) {
//            res += v.top();
//            v.pop();
//        }
//        return res;
//    }

    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            --columnNumber;
            int re = columnNumber % 26;
            ans.push_back('A' + re);
            columnNumber /=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 171
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        for (auto &item : columnTitle){
            res += (item - 'A' +1)* pow(26, n-- -1);
//            --n;
        }
        return res;
    }

    // 1042 邻接表
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> G[N];
        for (int i = 0; i < paths.size(); ++i) {
            G[paths[i][0] -1].push_back(paths[i][1] -1);
            G[paths[i][1] -1].push_back(paths[i][0] -1);
        }
        vector<int> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            set<int> color{1,2,3,4};
            for (int j = 0; j < G[i].size(); ++j) {
                color.erase(ans[G[i][j]]);
            }
            ans[i] = *(color.begin());
        }
        return ans;
    }

    //202
    bool isHappy(int n) {
        unordered_set<int> myset;
        while(n!= 1) {
//            n = nextVal(n);
            if(!myset.count(n)){
                myset.insert(n);
                n = nextVal(n);
            } else {
                return false;
            }

        }
        return true;
    }

    int nextVal(int n) {
        int res = 0;
        while(n /10 != 0) {
            res += pow((n%10),2);
            n /= 10;
        }
        return res + n*n;
    }

};

int main() {
    auto *solu = new day7_solution();

//    bool res = solu->camel("ForceFeedBack", "FoBa");
//    cout << res << endl;

//    string res = solu->convertToTitle(52);

    vector<vector<int>> v {{1,2}, {2,3}, {3,4}, {4, 1}, {1,3}, {2,4}};
    vector<int> res = solu->gardenNoAdj(4, v);

}