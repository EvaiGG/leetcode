//
// Created by Tony on 2023/4/24.
//

#include "string"
#include "set"
#include "iostream"

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
};

int main() {
    day9_solution solu ;

    string s = "zrziy";

    string res = solu.lastSubstring(s);
    cout << res << endl;
}