//
// Created by Tony on 2023/4/6.
//

#include "string"
#include "iostream"
#include "vector"
#include "algorithm"

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

    uint32_t reverseBits(uint32_t n) {
        uint32_t rec = 0;
        for (int i = 0; i < 32 && n> 0; ++i) {
            rec |= (n &1) << (31-i);
            n >>=1;
        }
        return rec;
    }

    Node* dfs(vector<int> &nums, int left, int right) {
        if (left >= right) return nullptr;
        int mid = (left + right) /2;
        Node *root = new Node(nums[mid]);
        root->left =  dfs(nums, left, mid);
        root->right = dfs(nums, mid+1, right);
        return root;
    }

    Node* sortedArrayToBST(vector<int> &nums) {
        int size = nums.size();
        return dfs(nums, 0, size);
    }
    int dfsFindMinDepth(Node* root, int &res, int dfsMin) {
        if (root->left == nullptr && root->right == nullptr) {
            res = dfsMin < res? dfsMin: res;
            return res;
        }
//        dfsMin ++;
        if (root->left) {
            dfsFindMinDepth(root->left, res, ++dfsMin);
        }
        --dfsMin;
        if(root->right) {
            dfsFindMinDepth(root->right, res, ++dfsMin);
        }
        --dfsMin;
        return res;
    }
    int minDepth(Node* root) {
        int res = 0x3f3f3f3f, dfsMin = 1;
//        Node* dummy = root;
        if(!root) return 0;
        return dfsFindMinDepth(root, res, dfsMin );
    }

    /**
     * leetcode 1041
     * @param instructions 指令数组 G 直走一个单位 L:左转90度 R:右转90度
     * @return
     */
    bool isRobotBounded(string instructions) {
        string ins = instructions + instructions + instructions + instructions;
        // 方向 逆时针排列
        vector<char> direction{'N', 'W', 'S', 'E'};
        vector<int> cursor{0,0};
        int currentDirection = 1;
        for (int i = 0; i < ins.size() ; ++i) {
            char in = ins.at(i);
            if (in == 'R') {
                currentDirection = currentDirection-1>0? currentDirection-1:4;
            }
            if (in == 'L') {
                currentDirection = currentDirection+1<=4?currentDirection+1:1;
            }
            if (in == 'G') {
                switch (currentDirection) {
                    case 1:
                        cursor[1]+=1;
                        break;
                    case 2:
                        cursor[0]-=1;
                        break;
                    case 3:
                        cursor[1]-=1;
                        break;
                    case 4:
                        cursor[0]+=1;
                        break;
                }
            }
        }
        if (cursor[0] == 0 && cursor[1] == 0) return true;
        return false;
    }
};



int main() {
    day5_solution *solution = new day5_solution;
//    string res = solution->baseNeg2(9);
//    cout << res << endl;

    Node* head = new Node(1);
    Node *p2 = head->left = new Node(2);
    Node *p3 = head->right = new Node(3);
    Node *p4 = p2->left = new Node(4);
    Node *p5 = p2->right = new Node(5);

    int res = solution->minDepth(head);

    cout << res << endl;
}