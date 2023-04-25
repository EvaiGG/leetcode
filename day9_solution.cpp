//
// Created by Tony on 2023/4/24.
//

#include "string"
#include "set"
#include "iostream"
#include "map"
#include "numeric"

using namespace std;

class day9_solution {

public:
    string lastSubstring(string s) {
        int i = 0, j= 1, n = s.size();
        while (j < n) {
            int k = 0;
            while(j + k < n && s[i+k] == s[j +k]){
                k++;
            }
            if (j+k < n && s[i+k] <s[j+k]) {
                int t = i;
                i = j;
                j = max(j+1, t+k +1);
            } else {
                j = j+k+1;
            }
        }
        return s.substr(i, n-i);
    }

    /**
     * 2418 给定名称数组与对应的身高数组 ， 建立一个索引数组idx [0, 1, 2, 3, ..., n-1]
     * 定义比较算法 对索引代表的身高排序（9，1，3，4，11，。。。。） 就是索引9代表身高最大 依次排序
     * for循环对返回数组赋值 names[idx[i]]
     * @param names
     * @param heights
     * @return
     */
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> res;
        vector<int> idx(n);


        iota(idx.begin(),  idx.end(), 0);

        // 自定义比较算法，对索引排序
        sort(idx.begin(),  idx.end(), [&](int x, int y){
            return heights[x] > heights[y];
        });

        for (int i = 0; i < n; ++i) {
            res[i] = names[idx[i]];
        }
        return res;
    }

    void bubbleSort(vector<int> &v) {
        int n = v.size();
        int i, j;
        vector<int> idx;
        for ( i = 0; i < n-1; ++i) {
            int cur = i;
            for ( j = i+1; j < n ; ++j) {
                if (v[j] >v[i]) {
                    swap(v, i, j);
                    cout << i << " : " << j << endl;
                }
            }
            idx.push_back(cur);
        }
    }

    void swap(vector<int> &v, int i, int j) {
        int temp =  v[i];
        v[i] = v[j];
        v[j] = temp;
    }
};

int main() {
    day9_solution solu ;

//    string s = "zrziy";
//
//    string res = solu.lastSubstring(s);
//    cout << res << endl;

    vector<int> v{190,11,140,12,14,15,210,32};
    solu.bubbleSort(v);

//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << endl;
//    }
}