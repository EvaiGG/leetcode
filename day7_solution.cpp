//
// Created by Tony on 2023/4/14.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "stack"

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


};

int main() {
    auto *solu = new day7_solution();

//    bool res = solu->camel("ForceFeedBack", "FoBa");
//    cout << res << endl;

    string res = solu->convertToTitle(52);
    cout << res << endl;
}