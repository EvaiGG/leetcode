#include "vector"

class BitBuffer :public std::vector<bool> {

public:
    BitBuffer();

    void appendBits(std::uint32_t val, int len);

};