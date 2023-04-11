//
// Created by Tony on 2023/4/11.
//
#include "iostream"
#include <cstdlib>
#include "string"
#include "vector"
#include "algorithm"

using namespace std;
template<typename t1, typename t2>
class day6_solution {
public:
    t1 first;
    t2 second;

    t1 add(t1 &first );

    //1147
    int longestDecomposition(string text) {
        int len = text.size();
        if (len == 0) return 0;
        for (int i = 0; i <= len/2; ++i) {
            if(text.substr(0,i) == text.substr(len-i)) {
                return 2+ longestDecomposition(text.substr(i, len-i*2));
            }
        }
        return 1;
    }
    vector<vector<int>> minPathMemo;

    //64
    int minPathSum(vector<vector<int>> &grid) {
        int height = grid.size();
        int width = grid[0].size();

        for (int i = 1; i < height; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < width; ++i) {
            grid[0][i] += grid[0][i-1];
        }

        for (int i = 1; i < height ; ++i) {
            for (int j = 1; j < width; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[height-1][width-1];

    }
};

template<typename t1, typename t2>
t1 day6_solution<t1, t2>::add(t1 &first) {
    return first;
}

int main () {
    day6_solution<std::string , std::int64_t > solu;
//    solu.first = "sweeter";
//    solu.second = 90;
//    std::string res = solu.add(solu.first);
//    std::cout << res << std::endl;

    vector<vector<int>> t = {{1,2,3}, {4,5,6}, {7,8,9}};
    solu.minPathSum(t);
}
