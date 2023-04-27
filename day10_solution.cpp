//
// Created by Tony on 2023/4/27.
//

#include "string"
#include "vector"
#include "stack"
#include "iostream"
#include "algorithm"
#include "unordered_map"

using namespace std;

class day10_solution{

public:

    /**
     * 对words按照长度排序
     * 创建一个map 存储每个word时的最大长链
     * 对于每一个word 随意删减一个字符得到它的一个前身
     * map中是否有这个前身映射
     *  如果有就更新word的映射
     *
     * 每次跌打更新当前最大长链长度
     * @param words
     * @return
     */
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),  words.end(), [](string &i,  string  &j) {
            return i.size() < j.size();
        });
        unordered_map<string, int> cnt;
        int res = 0;
        for (const auto &word : words) {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); ++i) {
                string prev = word.substr(0, i) + word.substr(i+1);
                if (cnt.count(prev)) {
                    cnt[word] = max(cnt[word], cnt[prev] + 1);
                }
            }
            res = max( res, cnt[word]);
        }
        return res;
    }

    /**
     * 判断b是否是a的前身
     * @param a
     * @param b
     * @return
     */
    bool isQs(string a, string b) {
        if (a.size() != b.size()-1) return false;
        stack<char> stk;
        int n = b.size();
        int cnt_diff = 0;
        for (int i = 0, j = 0; j < n-1; ) {
            while(a[i] == b[j]) {
                i++, j++;
            }
            if(a[i] != b[j]){
                cnt_diff ++;
                j++;
                if (cnt_diff >1) return false;
            }
        }
        return true;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
//        for (int left = 0; left < n; ++left) {
//            string str;
//            str += to_string(nums[left]);
//            int temp = nums[left];
//            int ans = temp;
//            while(left < n -1 && temp+1 == nums[left+1]) {
//                temp = nums[left+1];
//                left++;
//            }
//            str+= (ans!=temp? "->"+ to_string(nums[left]): "");
//            res.push_back(str);
//        }
//        return res;

        int l =0, r= 1;
        while(r < n) {
            while(r < n && nums[r] - nums[r-1] == 1) r++;
            if (r-l == 1) {
                res.push_back(to_string(nums[l]));
            } else {
                string child = to_string(nums[l]) + "->" + to_string(nums[r-1]);
                res.push_back(child);
            }
            l = r++;
        }
        if (nums.size() == r) res.push_back(to_string(nums[l]));
        return res;
    }
};

int main() {
    day10_solution solu;


    vector<string> v = {
//            {"a"}, {"b"} ,{"ba"}, {"bca"}, {"bda"}, {"bdca"}
            "a", "b", "ba", "bca", "bda", "bdca"
    };

//    for (int i = 1; i < v.size(); ++i) {
//        bool res = solu.isQs(v[i-1][0], v[i][0]);
//        cout << v[i-1][0] << " : " << v[i][0] << endl;
//        cout << res << endl;
//    }

//    vector<int> nums{1,4,7,8,9,89, 90, 100,101,102,104};
    vector<int> nums{1,4};
    vector<string> res =  solu.summaryRanges(nums);
    for (const auto &item : res){
        cout << item << endl;
    }

}
