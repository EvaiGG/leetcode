//
// Created by Tony on 2023/4/11.
//
#include "iostream"
#include <cstdlib>
#include "string"

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
};

template<typename t1, typename t2>
t1 day6_solution<t1, t2>::add(t1 &first) {
    return first;
}

int main () {
    day6_solution<std::string , std::int64_t > solu;
    solu.first = "sweeter";
    solu.second = 90;
    std::string res = solu.add(solu.first);
    std::cout << res << std::endl;
}
