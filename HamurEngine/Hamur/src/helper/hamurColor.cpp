#include "hamurColor.h"

namespace hamur
{

HamurColor::HamurColor(float colorRed, float colorGreen, float colorBlue) : R(colorRed), G(colorGreen), B(colorBlue)
{

}

void HamurColor::SetDefaultColor(float colorRed, float colorGreen, float colorBlue)
{
	DEFAULT_COLOR.R = colorRed;
	DEFAULT_COLOR.G = colorGreen;
	DEFAULT_COLOR.B = colorBlue;
}

void HamurColor::SetDefaultColor(const HamurColor& color)
{
	DEFAULT_COLOR = color;
}

HamurColor HamurColor::RED(1.0f, 0, 0);
HamurColor HamurColor::GREEN(0, 1.0f, 0);
HamurColor HamurColor::BLUE(0, 0, 1.0f);
HamurColor HamurColor::BLACK(0, 0, 0);
HamurColor HamurColor::WHITE(1.0f, 1.0f, 1.0f);
HamurColor HamurColor::YELLOW(1.0f, 1.0f, 0);
HamurColor HamurColor::CYAN(0, 1.0f, 1.0f);
HamurColor HamurColor::MAGENTA(1.0f, 0, 1.0f);
HamurColor HamurColor::GREY(0.5f, 0.5f, 0.5f);
HamurColor HamurColor::DEFAULT_COLOR(1.0f, 0, 1.0f);

HamurColorRGB::HamurColorRGB(int colorRed, int colorGreen, int colorBlue) : R(colorRed), G(colorGreen), B(colorBlue)
{

}

HamurColorRGB HamurColorRGB::RED      (255, 0,   0  );
HamurColorRGB HamurColorRGB::GREEN    (0,   255, 0  );
HamurColorRGB HamurColorRGB::BLUE     (0,   0,   255);
HamurColorRGB HamurColorRGB::BLACK    (0,   0,   0  );
HamurColorRGB HamurColorRGB::WHITE    (255, 255, 255);
HamurColorRGB HamurColorRGB::YELLOW   (255, 255, 0  );
HamurColorRGB HamurColorRGB::CYAN     (0,   255, 255);
HamurColorRGB HamurColorRGB::MAGENTA  (255, 0,   255);
HamurColorRGB HamurColorRGB::GREY     (128, 128, 128);
HamurColorRGB HamurColorRGB::COLORKEY (255, 0,   255);

} // namespace hamur