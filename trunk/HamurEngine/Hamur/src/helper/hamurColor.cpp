#include "hamurColor.h"

namespace hamur
{

HamurColor::HamurColor(float colorRed, float colorGreen, float colorBlue)
{
    R = colorRed; G = colorGreen; B = colorBlue;
}

HamurColor HamurColor::RED(1, 0, 0);
HamurColor HamurColor::GREEN(0, 1, 0);
HamurColor HamurColor::BLUE(0, 0, 1);
HamurColor HamurColor::BLACK(0, 0, 0);
HamurColor HamurColor::WHITE(1, 1, 1);
HamurColor HamurColor::YELLOW(1, 1, 0);
HamurColor HamurColor::CYAN(0, 1, 1);
HamurColor HamurColor::MAGENTA(1, 0, 1);
HamurColor HamurColor::GREY(0.5f, 0.5f, 0.5f);

} // namespace hamur