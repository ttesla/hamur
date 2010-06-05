#include "hamurColor.h"

namespace hamur
{
    HamurColor::HamurColor(float _R, float _G, float _B)
    {
        R = _R; G = _G; B = _B;
    }

    HamurColor HamurColor::RED(1, 0, 0);
    HamurColor HamurColor::GREEN(0, 1, 0);
    HamurColor HamurColor::BLUE(0, 0, 1);
    HamurColor HamurColor::BLACK(0, 0, 0);
    HamurColor HamurColor::WHITE(1, 1, 1);
    HamurColor HamurColor::YELLOW(1, 1, 0);
    HamurColor HamurColor::CYAN(0, 1, 1);
    HamurColor HamurColor::MAGENTA(1, 0, 1);
    HamurColor HamurColor::GREY(0.5, 0.5, 0.5);
}