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

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), k = k1+k2;
        long ans = 0l, sum = 0L;
        for (int i = 0; i < n; ++i) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            sum += nums1[i];
            ans += nums1[i]*nums1[i];
        }
        if (sum <= k) return 0; // 所有nums1[i]均可以为0；
        sort(nums1.begin(),  nums1.end());
        nums1.push_back(0);

        for (int i = 0; ; ++i) {
            long j = i+1, v= nums1[i], c = j*(v-nums1[j]);
            ans -= v*v;
            if (c < k){
                k -= c;
                continue;
            }
            v -= k/j;
            return ans + k%j*(v-1)*(v-1) + (j-k%j)*v*v;
        }
    }

    /**
     * 返回 x - y 的最大距离 x/y 可在k1/k2得范围内移动
     * @param x
     * @param y
     * @param k1
     * @param k2
     * @return
     */
    int maxDiff(int x, int y, int k1, int k2) {
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
            int temp1 = k1;
            k1 = k2;
            k2 = temp1;
        } else if(x == y) {
            return k1 + k2;
        }
        return (y+k2) - (x - k1);
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

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