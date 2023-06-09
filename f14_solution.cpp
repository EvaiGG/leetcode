#include <vector>
#include <iostream>

using namespace std;

class f14_solution {
public:

    vector<vector<int>> res;
    vector<int> temp;

    vector<vector<int>> combine(int n, int k) {
        dfs(0, 1, n, k);
        return res;
    }
    /**
     * 回溯所有的组合
     * @param begin [1,n] 子字符串开头的数字
     * @param index 子字符串的第index个数字
     * @param n
     * @param k
     */
    void dfs(int begin, int index, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = index; i <= n; ++i) {
            if (i > begin) {
                temp.push_back(i);
                dfs(i, i + 1, n, k);
                temp.pop_back();
            }
        }
    }
};


int main() {

    f14_solution solu;
    auto res =  solu.combine(5,4);
    for (const auto &vec: res) {
        for (const auto &item: vec) {
            cout << item << "\t";
        }
        cout << "\n";
    }
}