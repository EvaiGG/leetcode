#include "demo.hpp"

BitBuffer::BitBuffer() : std::vector<bool>(){}

void BitBuffer::appendBits(std::uint32_t val, int len) {
    if (len <0 || len >31 || val >> len != 0)
        throw std::domain_error("Value out of range");

    for (int i = len -1; i>=0 ; i--)
        this->push_back(((val >> i) &1) != 0);

}