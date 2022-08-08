#include "ssr/PS4Operation.hpp"

uint8_t ssr::PS4Operation::_generateID() {
    static uint8_t nextID = 0;
    uint8_t id = nextID;
    ++nextID;
    return id;
}

ssr::PS4Operation::PS4Operation() : id(_generateID()) {}

void ssr::PS4Operation::operate(const PS4Value & value) {}

bool operator==(const ssr::PS4Operation & lh, const ssr::PS4Operation & rh) {
    return lh.id == rh.id;
}
