//
// Created by Tony on 2023/3/31.
//
#include <stdlib.h>
#include "iostream"
#include "vector"
#include "stack"
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "math.h"
#include "algorithm"

using namespace std;

int arithmeticTriplet(vector<int> &nums, int diff) {
    int cnt = 0;
    int len = nums.size();
    for (int i = 0, j = 1, k = 2; i < len - 2 && j < len - 1 && k < len; ++i) {
        j = max(j, i + 1);
        while (j < len - 1 && nums[i] + diff > nums[j]) {
            j++;
        }
        if (j > len - 1 || nums[i] + diff > nums[j]) {
            continue;
        }
        k = max(k, j + 1);
        while (k < len && nums[j] + diff > nums[k]) {
            k++;
        }
        if (k < len && nums[j] + diff == nums[k]) {
            cnt++;
        }
        return cnt;
    }
}

bool validPartition(vector<int> &nums) {
    int l = nums.size();
    int f[l + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i < l; ++i) {
        if (
                (f[i - 1] && nums[i] == nums[i - 1]) ||
                (f[i - 2] && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) ||
                ((f[i - 2]) && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
                ) f[i+1] = true;
    }
    return f[l];
}

class Solution {
public:
    int visited[50];

    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (visited[n] != 0) return visited[n];
        int temp = climbStairs(n - 1) + climbStairs(n - 2);
        visited[n] = temp;
        return temp;
    }

};

void swap(vector<vector<int>> & matrix, int x, int y) {
    int temp = matrix[x][y];
    matrix[x][y] = matrix[y][x];
    matrix[y][x] = temp;
}

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < (n+1)/2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

int minScoreTriangulation(vector<int> & values){
    int n = values.size();
//    unordered_map
    std::unordered_map<int, int> memory;
    // 可以用auto dp 表示
    function<int(int, int)> dp = [&] (int i, int j) -> int {
        if(i+2 > j) return 0;
        if(i + 2 == j) return values[i]*values[i+1]*values[i+2];

        int key = i*n + j;
        cout << "key = " << key << endl;
        if (!memory[key]) {
            int MIN_VALUE = INT_MAX;
            for (int k = i+1; k < j ; ++k) {
                MIN_VALUE = min(MIN_VALUE, values[i]*values[j]*values[k] + dp(i, k) + dp(k, j) );
            }
            memory[key] = MIN_VALUE;
        }
        return memory[key];
    };
    int res = dp(0,n-1);
    return res;
}

int countCharacters(vector<string>& words, string chars) {
    std::unordered_map<char, int> chars_cnt;
    for (const auto &item : chars){
        chars_cnt[item]++;
    }
    int ans = 0;
    for (const auto &word : words){
        std::unordered_map<char, int> word_cnt;
        for (const auto &item : word){
            word_cnt[item] ++;
        }

        bool is_true = true;
        for (const auto &item : word){
            if(chars_cnt[item] > word_cnt[item]){
                is_true = false;
                break;
            }
        }
        if(is_true) {
            ans += word.size();
        }
    }
    return ans;
}

void swap(vector<int> & arr,int i,int j) {
    cout << "arr[" << i << "] = "<< arr[i] << endl;
    cout << "arr[" << j << "] =" << arr[j] << endl;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] =tmp;
}
vector<int> prevPermOpt1(vector<int>& arr) {
   int n = arr.size();
    int i;
    int j;

    for ( i = n-2; i >=0 ; i--) {
        if( arr[i] > arr[i+1]) {
            j = n-1;
            while(arr[j] >= arr[i] || arr[j] == arr[j-1])
                j--;
            swap(arr, i, j);
            return arr;
        }
    }
    cout<< i<< endl;
    return arr;
}
int main() {


//    vector<int> nums = {0,0,1,1,1,1,2,2,3,3,4, 5,6,7, 8,9,10};
//    bool res = validPartition(nums);
//    cout << "df" << endl;
//    cout << res << endl;


//    vector<vector<int>> v = {
//            {1,2,3,4},
//            {5,6,7,8},
//            {9,10,11,12},
//            {13,14,15,16}
//    };
//    swap(v, 1,0);
//    cout << v[1][0] << endl;
//    cout << v[0][1] << endl;

//    vector<int> v = {1,3,1,4,15};
//    minScoreTriangulation(v);

//    vector<std::string> s = {
//            "cat",
//            "bt",
//            "hat",
//            "tree"
//    };
//    std::string chars = "atach";
//    int count = countCharacters(s, chars);
//    cout << count << endl;

    vector<int> intV = {3,1,1,3};
    vector<int> res = prevPermOpt1(intV);
    for (const auto &item : res) {
        cout << item << "\t";
    }
    cout << "lanhua" << endl;
}
