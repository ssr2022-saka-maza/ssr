#include "ssr/Vector2D.hpp"
#include "ssr/PS4Value.hpp"

// 正直必要ない
// ssr::PS4Value::PS4Value(
//     ssr::Vector2D<uint8_t> lstick = {0, 0}, ssr::Vector2D<uint8_t> rstick = {0, 0},
//     bool up       = false, bool right  = false, bool down  = false, bool left   = false,
//     bool triangle = false, bool circle = false, bool cross = false, bool square = false,
//     bool l1 = false, uint8_t l2 = 0, bool l3 = false,
//     bool r1 = false, uint8_t r2 = 0, bool r3 = false,
//     bool ps = false, bool share = false, bool options = false,
//     bool finger1Touch = false, ssr::Vector2D<uint16_t> finger1Pos = {0, 0},
//     bool finger2Touch = false, ssr::Vector2D<uint16_t> finger2Pos = {0, 0},
//     float pitch = 0, float roll = 0
// ) : lstick(lstick), rstick(rstick),
//     up(up), right(right), down(down), left(left),
//     triangle(triangle), circle(circle), cross(cross), square(square),
//     l1(l1), l2(l2), l3(l3),
//     r1(r1), r2(r2), r3(r3),
//     ps(ps), share(share), options(options),
//     finger1Touch(finger1Touch), finger1Pos(finger1Pos),
//     finger2Touch(finger2Touch), finger2Pos(finger2Pos),
//     pitch(pitch), roll(roll)
// {}

ssr::PS4Value::PS4Value(
    uint8_t lstick_x, uint8_t lstick_y, uint8_t rstick_x, uint8_t rstick_y,
    bool up,       bool right,  bool down,  bool left,
    bool triangle, bool circle, bool cross, bool square,
    bool l1, uint8_t l2, bool l3,
    bool r1, uint8_t r2, bool r3,
    bool ps, bool share, bool options,
    bool finger1Touch, uint16_t finger1Pos_x, uint16_t finger1Pos_y,
    bool finger2Touch, uint16_t finger2Pos_x, uint16_t finger2Pos_y,
    float pitch, float roll
) : lstick(lstick_x, lstick_y), rstick(rstick_x, rstick_y),
    up(up), right(right), down(down), left(left),
    triangle(triangle), circle(circle), cross(cross), square(square),
    l1(l1), l2(l2), l3(l3),
    r1(r1), r2(r2), r3(r3),
    ps(ps), share(share), options(options),
    finger1Touch(finger1Touch), finger1Pos(finger1Pos_x, finger1Pos_y),
    finger2Touch(finger2Touch), finger2Pos(finger2Pos_x, finger2Pos_y),
    pitch(pitch), roll(roll)
{}

bool operator==(const ssr::PS4Value& lhs, const ssr::PS4Value& rhs) {
    return (
        lhs.lstick == rhs.lstick && lhs.rstick == rhs.rstick
        && lhs.up == rhs.up && lhs.right == rhs.right && lhs.down == rhs.down && lhs.left == rhs.left
        && lhs.triangle == rhs.triangle && lhs.circle == rhs.circle && lhs.cross == rhs.cross && lhs.square == rhs.square
        && lhs.l1 == rhs.l1 && lhs.l2 == rhs.l2 && lhs.l3 == rhs.l3
        && lhs.r1 == rhs.r1 && lhs.r2 == rhs.r2 && lhs.r3 == rhs.r3
        && lhs.ps == rhs.ps && lhs.share == rhs.share && lhs.options == rhs.options
        && lhs.finger1Touch == rhs.finger1Touch && lhs.finger1Pos == rhs.finger1Pos
        && lhs.finger2Touch == rhs.finger2Touch && lhs.finger2Pos == rhs.finger2Pos
        && lhs.pitch == rhs.pitch && lhs.roll == rhs.roll
    );
}

bool operator!=(const ssr::PS4Value& lhs, const ssr::PS4Value& rhs) {
    return !(lhs == rhs);
}
