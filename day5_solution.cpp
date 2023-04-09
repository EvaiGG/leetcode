//
// Created by Tony on 2023/4/6.
//

#include "string"
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr){}
    Node(int x): val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right){}
};
class day5_solution{


public:
    string baseNeg2(int n){
        if (n == 0 || n == 1) {
            return to_string(n);
        }
        string res;
        while (n != 0) {
            int remainder =n & 1;
            res.push_back('0' + remainder);
            n -= remainder;
            n /= -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        if (stones.back() - stones[0] + 1 == n) {
            return {0, 0};
        }
        int ma = max(stones[n - 2] - stones[0] + 1, stones[n - 1] - stones[1] + 1) - (n - 1);
        int mi = n;
        for (int i = 0, j = 0; i < n && j + 1 < n; ++i) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) {
                ++j;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                mi = min(mi, 2);
            } else {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return {mi, ma};
    }

    // 83
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy  = new ListNode;
        ListNode *res = dummy;
        dummy->next = head;
        while(dummy->next != nullptr) {
            ListNode *tmp = dummy->next;
            while(tmp->next != nullptr && tmp->next->val == tmp->val) {
                tmp = tmp->next;
            }
            dummy ->next = tmp;
            dummy = dummy->next;
        }
        return res->next;
    }

    //110 是否是平衡二叉树
    bool isBalanced(Node *root) {
        if (root == nullptr) return true;
        return abs(maxDep(root->left) - maxDep(root->right)) <=1
        && isBalanced(root->left)
        && isBalanced(root->right);
    }
    int maxDep(Node *root) {
        if (root == nullptr) return 0;
        return max(maxDep(root->left) , maxDep(root->right))+1;
    }

    bool isSameTree(Node *p, Node *q) {
        if(p == nullptr && q == nullptr) return true;
        if((p!= nullptr && q == nullptr) || (p == nullptr && q!= nullptr) || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};



int main() {
//    day5_solution *solution = new day5_solution;
//    string res = solution->baseNeg2(9);
//    cout << res << endl;


}