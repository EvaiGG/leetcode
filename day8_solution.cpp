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
            res =max(curr, res);
        }
        return res+1;
    }
};

int main() {
    day8_solution solu;
    int n =  solu.longestContinuousSubstring("abcdefg");
    cout << n << endl;
}
