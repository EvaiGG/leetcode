//
// Created by Tony on 2023/3/26.
//

#include <stdlib.h>
#include "iostream"
#include "vector"
#include "stack"
#include <map>
#include "math.h"
#include "algorithm"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class day2 {
public:
    vector<int> gerter(vector<int> &nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        int len = nums.size();
        for (int i = len - 1; i >= 0; i--) {
            int gap = 0;
            if (!st.empty() && st.top() <= nums[i]) {
                st.pop();
                gap++;
            }
            ans[i] = st.empty() ? 0 : gap;
        }
        return vector<int>();
    }

    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> t = gerter(temperatures);
        return t;
    }

};

void swap(int a, int b, vector<int> &nums) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

// 最稠密的情况下 返回n+1 否则必定是[1,n]之间
// 先将所有负数变为n+1 这个情况下就只剩下[1,n] 之间的数 和 n+1了
// 接着遍历数组 遇到[1,n] 之间的数 就将索引为n 的值变号变为负数 不必关心具体的值，只需要关注数组中的正负号标志
// 遍历数组，遇到的第一个正数 它的索引加1就是返回的结果，因为第一个经过标记 这个索引之前的值都有间歇值
int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (auto &item: nums) {
        if (item < 0) item = n + 1;
    }
    for (int i = 0; i < n; ++i) {
        int num = abs(nums[i]);
        if (num < n) {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) return i + 1;
    }
    return n + 1;
}

int countSubStrings(string s, string t) {
    int m = s.size(), n = t.size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            int diff = 0;
            for (int k = 0; i + k < m && j + k < n; ++k) {
                diff += s[i + k] == t[j + k] ? 0 : 1;
                if (diff > 1) break;
                else if (diff == 1) ans++;
            }
        }
    }
    return ans;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    // write code here
    ListNode *dummy = head;
    int count = 0;
    stack<ListNode *> s;
    while (head) {
        s.push(head);
        head = head->next;
        count++;
    }
    int pops = 0;
    while (pops < n) {
        pops++;
        s.pop();
    }

    if (s.empty()) {
        return dummy->next;
    }
    ListNode *mid = s.top();
    mid->next = mid->next->next;
    return dummy;
}

ListNode *findFirstCommonNode(ListNode *p1, ListNode *p2) {
    ListNode *d1 = p1;
    ListNode *d2 = p2;
    while (d1 != d2) {
        d1 = d1 ? d1->next : p1;
        d2 = d2 ? d2->next : p2;
    }
    return d1;
}


ListNode *reverseNode(ListNode *l) {
    ListNode *res;
    ListNode *curr = l;
    while (curr) {
        ListNode *tail = curr->next;
        curr->next = res;
        res = curr;
        curr = tail;
    }
    return res;
}

ListNode addList(ListNode l1, ListNode l2) {
    ListNode *p1 = reverseNode(&l1);
    ListNode *p2 = reverseNode(&l2);
    ListNode *ans;
    int carry = 0;
    while (p1 || p2) {
        int sum = carry;
        if (p1) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2) {
            sum += p2->val;
            p2 = p2->next;
        }

        ans->next = new ListNode(sum % 10);
        carry = sum / 10;
        ans = ans->next;
    }
    if (carry > 0) {
        ans->next = new ListNode(carry);
    }
    ListNode *t = reverseNode(ans);
    return *t;

}

void backTrace(vector<vector<int>> &res, vector<int> &nums, int first, int len) {
    if (first == len) {
        res.emplace_back(nums);
    }
    for (int i = first; i < len; ++i) {
        swap(nums[i], nums[first]);
        backTrace(res, nums, first + 1, len);
        swap(nums[first], nums[i]);
    }
}

vector<vector<int>> premute(vector<int> &nums) {
    vector<vector<int>> res;
    backTrace(res, nums, 0, nums.size());
    return res;
}

vector<int> nextGreaterElement(vector<int> &nums) {
    int len = nums.size();
    vector<int> res(len);
    stack<int> s;
    std::map<int, int> tmpMap;
    for (int i = len - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        int temp = s.empty() ? -1 : s.top();
        res[i] = temp;
//        tmpMap.insert(pair<int, int>(nums[i], res[i]));
        s.push(nums[i]);
    }
    int second = tmpMap.find(3)->second;
    int first = tmpMap.find(3)->first;
    return res;
}

vector<int> nextGreaterElem(vector<int> &nums1, vector<int> &nums2) {
    vector<int> greater = nextGreaterElement(nums2);
    map<int, int> m;
    for (int i = 0; i < greater.size(); ++i) {
        m[nums2[i]] = greater[i];
    }
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
        res[i] = m[nums1[i]];
    }
    return res;
}

vector<int> gg(vector<int> &nums1, vector<int> &nums2) {
    int size = nums2.size();
    stack<int> tmpStack;
    vector<int> proxy(size);
    map<int, int> tmpMap;
    for (int i = size - 1; i >= 0; i--) {
        while (!tmpStack.empty() && tmpStack.top() <= nums2[i]) {
            tmpStack.pop();
        }
        proxy[i] = tmpStack.empty() ? -1 : tmpStack.top();
        tmpMap.insert(pair<int, int>(nums2[i], proxy[i]));
        tmpStack.push(nums2[i]);
    }
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
        res[i] = tmpMap[nums1[i]];
    }
    return res;
}

void bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int maxV = nums[i];
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap(j, j - 1, nums);
            }
        }
    }
}

int maxWidthOfVerticalArea(vector<vector<int>> &points) {
//    int len = points.size();
//    vector<int> x (len);
//    for (int i = 0; i < len; ++i) {
//        x[i] = points[i][0];
//    }
//    bubbleSort(x);
//    vector<int> gap(len-1);
//    for (int i = 1; i < len -1; ++i) {
//        gap[i] = x[i] - x[i-1];
//    }
//    int res = 0;
//    for (int i = 0; i < len-1; ++i) {
//        res = max(res, gap[i]);
//    }
//    return res;
    sort(points.begin(), points.end());
    int mx = 0;
    for (int i = 0; i < points.size(); ++i) {
        mx = max(mx, points[i][0] - points[i - 1][0]);
    }
    return mx;
}

double sum = 1;
double myPow(double x, int n) {
    if (n == 0) return x;
    sum = sum*x;
    myPow(x, --n);
    return sum;
}



int main() {
//    ListNode* p1 = new ListNode(1);
//    ListNode* p2 = p1 -> next = new ListNode(2);
//    ListNode* p3 = p2 -> next = new ListNode(3);
//    ListNode* p4 = p3 -> next = new ListNode(4);
//    ListNode* p5 = p4 -> next = new ListNode(5);

//    std::vector<int> v = {2,1,2,4,3};
//    std::vector<int> v = {2,5,3,6,8,4,7,1};
//    std::vector<int> res = nextGreaterElement(v);
//
//    for (const auto &item : res){
//        cout << item << endl;
//    }

    vector<vector<int>> dumbs = {{1, 2},
                                 {2, 3},
                                 {6, 1},
                                 {7, 1},
                                 {5, 4},
                                 {1, 3}};

//    int size = dumbs.size();
//    vector<int> tmp{size};
//    for(int i = 0; i< size; i++){
//        tmp[i] = dumbs[i][0];
//    }
//    for (int i = 0; i < size; ++i) {
//        cout<< tmp[i] << endl;
//    }

//    vector<int> ints = {1,3,4,1,6,7,4,2};
//    bubbleSort(ints);
//    for (int i = 0; i < ints.size(); ++i) {
//        cout << ints[i] << endl;
//    }

    int res = myPow(3, 4);
    cout << res << endl;
}