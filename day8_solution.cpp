//
// Created by Tony on 2023/4/21.
//
class day8_solution{

    int smallestEvenMultiple(int n) {
        if (n %2 == 0) return 0;
        if (n < 2) return n;
        return n*2;
    }
};
