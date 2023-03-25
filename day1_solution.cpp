//
// Created by Tony on 2023/3/24.
//
#include "iostream"
#include "vector"
#include "set"
#include "unordered_set"
#include "string"
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 关闭掉C++为了向下兼容C的标准输入输出 提高运行速度
 */
static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
};
class Solution {
public:

    vector<int> towSum(vector<int> &nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;

            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }

//    Solution();
};

int lengthOfLongestSubstring(string s) {
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        // count是内置函数 返回元素在集合的出现次数 存在返回1 不存在返回0
        // 如果还有下一个单位 并且下一个元素不重复
        while (rk + 1 < n && !occ.count(s[rk + 1])) {
            // 不断地移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = max(ans, rk - i + 1);
    }
    return ans;
}

int lengthOfLongestSubString(string s) {
    unordered_set<char> set;
    int len = s.size();
    char chars[len + 1];
    strcpy(chars, s.c_str());
    int max = 0;
    for (int i = 0; i < len; ++i) {
        int tempLen = 0;
//            "pwwkew"
        cout << "最外部的for循环i is: " << i << endl;
        for (int j = i; j < len; ++j) {
            if (!set.insert(chars[j]).second) {
                max = tempLen > max ? tempLen : max;
                cout << "now I is: " << i << endl;
                cout << "now j is: " << j << endl;
                cout << " max is: " << max << endl;

                cout << "本次筛选出字符串" << s.substr(i, j) << endl;
                break;
            } else {
                ++tempLen;
            }
        }
        set.clear();
    }
    return max;
}

int findLengthOfShortestSubarray(vector<int> &arr) {
    int len = arr.size();
    int j = len -1;
    while(j > 0 && arr[j-1] <= arr[j]) {
        j--;
    }
    if(j == 0) return 0;
    int res = j;
    for(int i =0; i< len ; i++) {
        while(j<len && arr[i] > arr[j]) {
            j++;
        }
        res = min(res, j-i+1);
        if(i+1 < len && arr[i] > arr[i+1]) {
            break;
        }
    }

    return res;
}

// 这个算法无法处理超过long int类型值的字符串数值 可使用addString 字符串加法
long int stringToNumber(string num){
    long int res = 0;
    int n = num.size();
    for (int i = n-1; i >=0; --i) {
        int pows = pow(10, n -i -1);
        int base = (num[i]-48);
//        cout << "10倍数:" << pows << " , 位数:" << base << ", 原res: " << res <<  endl;
        res = res + base*pows;
//        cout << "现res: " << res << endl;
    }
    return res;
}

// 字符串加法
string addString(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size();
    int maxLen;
    string res;
    if (l1 > l2) {
        maxLen = l1;
        res = num1;
    } else {
        maxLen = l2;
        res = num2;
    }
    int gap = abs(l1 - l2);
    int carry = 0;
    for (int i = maxLen -1; i >= 0 ; i--) {
        int a, b;
        if(l1 > l2) {
            a = num1[i] -48;
            if (i-gap >= 0) {
                b = num2[i-gap] -48;
            } else {
                b = 0;
            }
        } else {
            b = num2[i] -48;
            if (i- gap >= 0) {
                a = num1[i-gap] - 48;
            } else {
                a = 0;
            }
        }

        int sum = a+b+carry;
        int temp = (sum %10);
        res[i] = temp + 48;
//        cout<< "a = " << a << ", b = " << b << endl;
//        cout<< "int sum = "<< sum << endl;
//        cout<< "temp = "<< temp << endl;
//        cout<< "res[" << i <<"]=" << res[i] << endl;
        carry = sum /10;
    }
    if (carry >0) return to_string(carry)+ res;
    return res;
}

string multiply(string num1, string num2) {

    if (num1 == "0" || num2 == "0") return "0";
    int m = num1.size(), n = num2.size();
    auto ansArr = vector<int>(m+n);
    for (int i = m-1; i >= 0 ; i--) {
        int x = num1.at(i) - '0';
        for (int j = n-1; j >=0 ; j--) {
            int y = num2.at(i) - '0';
            ansArr[i+j +1] = x*y;
        }
    }
    for (int i = m+n-1; i >0 ; i--) {
        ansArr[i - 1] += ansArr[i] / 10;
        ansArr[i] %= 10;
    }
    int index = ansArr[0] == 0 ? 1 : 0;
    string ans;
    while (index < m + n) {
        ans.push_back(ansArr[index]);
        index++;
    }
    for (auto &c: ans) {
        c += '0';
    }
    return ans;


}

string addBinary(string a, string b) {
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size()), carry = 0;
    for (int i = 0; i < n; ++i) {
        carry += i<a.size()?(a.at(i) == '1'): 0;
        carry += i < b.size()?(b.at(i) == '1'): 0;
        ans.push_back((carry %2)? '1': '0');
        carry /= 2;
    }
    if (carry != 0) {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {

//    string num = "12345";
//    stringToNumber(num);
//    string res = multiply("123456789","987654321");
//    cout << res << endl;

    string res =  addString("1","9");
    cout << res << endl;
//    string a = "1234";
//    cout << a[3] << endl;
}