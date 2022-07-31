#include "ssr/PS4Value.hpp"
#include "ssr/PS4.hpp"

PS4Parser * ssr::PS4::_getParser() {
    if (_connect_usb) {
        return _ps4usb;
    }
    return _ps4bt;
}

ssr::PS4::~PS4() {
    if (_btd != nullptr) delete _btd;
    if (_connect_usb) {
        if (_ps4usb != nullptr) delete _ps4usb;
    } else {
        if (_ps4bt != nullptr) delete _ps4bt;
    }
}

int ssr::PS4::begin() {
    return _usb.Init();
}

void ssr::PS4::update() {
    _usb.Task();
}

bool ssr::PS4::connected() {
    if (_connect_usb) {
        return _ps4usb->connected();
    }
    return _ps4bt->connected();
}

void ssr::PS4::read(ssr::PS4Value * output) {
    if (output == nullptr || output == NULL) return;
    PS4Parser * parser = _getParser();
    output->lstick.x = parser->getAnalogHat(LeftHatX);
    output->lstick.y = parser->getAnalogHat(LeftHatY);
    output->rstick.x = parser->getAnalogHat(RightHatX);
    output->rstick.y = parser->getAnalogHat(RightHatY);
    output->up = parser->getButtonClick(UP);
    output->right = parser->getButtonClick(RIGHT);
    output->down = parser->getButtonClick(DOWN);
    output->left = parser->getButtonClick(LEFT);
    output->triangle = parser->getButtonClick(TRIANGLE);
    output->circle = parser->getButtonClick(CIRCLE);
    output->cross = parser->getButtonClick(CROSS);
    output->square = parser->getButtonClick(SQUARE);
    output->l1 = parser->getButtonClick(L1);
    output->l2 = parser->getAnalogButton(L2);
    output->l3 = parser->getButtonClick(L3);
    output->r1 = parser->getButtonClick(R1);
    output->r2 = parser->getAnalogButton(R2);
    output->r3 = parser->getButtonClick(R3);
    output->ps = parser->getButtonClick(PS);
    output->share = parser->getButtonClick(SHARE);
    output->options = parser->getButtonClick(OPTIONS);
    output->finger1Touch = parser->isTouching(0);
    if (output->finger1Touch) {
        output->finger1Pos.x = parser->getX(0);
        output->finger1Pos.y = parser->getY(0);
    } else {
        output->finger1Pos.x = 0;
        output->finger1Pos.y = 0;
    }
    output->finger2Touch = parser->isTouching(1);
    if (output->finger2Touch) {
        output->finger2Pos.x = parser->getX(1);
        output->finger2Pos.y = parser->getY(1);
    } else {
        output->finger2Pos.x = 0;
        output->finger2Pos.y = 0;
    }
    output->pitch = parser->getAngle(Pitch);
    output->roll = parser->getAngle(Roll);
}

ssr::PS4Value * ssr::PS4::read() {
    PS4Parser * parser = _getParser();
    ssr::PS4Value * value = new ssr::PS4Value(
        parser->getAnalogHat(LeftHatX),  parser->getAnalogHat(LeftHatY),
        parser->getAnalogHat(RightHatX), parser->getAnalogHat(RightHatY),
        parser->getButtonClick(UP),
        parser->getButtonClick(RIGHT),
        parser->getButtonClick(DOWN),
        parser->getButtonClick(LEFT),
        parser->getButtonClick(TRIANGLE),
        parser->getButtonClick(CIRCLE),
        parser->getButtonClick(CROSS),
        parser->getButtonClick(SQUARE),
        parser->getButtonClick(L1),
        parser->getAnalogButton(L2),
        parser->getButtonClick(L3),
        parser->getButtonClick(R1),
        parser->getAnalogButton(R2),
        parser->getButtonClick(R3),
        parser->getButtonClick(PS),
        parser->getButtonClick(SHARE),
        parser->getButtonClick(OPTIONS),
        parser->isTouching(0),
        0, 0,
        parser->isTouching(1),
        0, 0,
        parser->getAngle(Pitch),
        parser->getAngle(Roll)
    );
    if (value->finger1Touch) {
        value->finger1Pos.x = parser->getX(0);
        value->finger1Pos.y = parser->getY(0);
    }
    if (value->finger2Touch) {
        value->finger2Pos.x = parser->getX(1);
        value->finger2Pos.y = parser->getY(1);
    }
    return value;
}

ssr::PS4 * ssr::PS4::usb() {
    ssr::PS4 * ps4 = new ssr::PS4();
    ps4->_connect_usb = true;
    ps4->_ps4usb = new PS4USB(&ps4->_usb);
    return ps4;
}

ssr::PS4 * ssr::PS4::bluetooth(bool pair) {
    ssr::PS4 * ps4 = new ssr::PS4;
    ps4->_btd = new BTD(&ps4->_usb);
    ps4->_connect_usb = false;
    ps4->_ps4bt = new PS4BT(ps4->_btd, pair);
    return ps4;
}
