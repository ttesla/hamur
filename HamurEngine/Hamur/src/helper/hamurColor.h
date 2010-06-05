#ifndef HAMURCOLOR_H
#define HAMURCOLOR_H

namespace hamur
{
    class HamurColor
    {
        public:

            // Red, Green, Blue color values.
            HamurColor(float R, float G, float B);

            static HamurColor RED;
            static HamurColor GREEN;
            static HamurColor BLUE;
            static HamurColor BLACK;
            static HamurColor WHITE;
            static HamurColor YELLOW;
            static HamurColor CYAN;
            static HamurColor MAGENTA;
            static HamurColor GREY;

            float R;
            float G;
            float B;
    };

    /*
    HamurColor HamurColor::RED(1, 0, 0);
    HamurColor HamurColor::GREEN(0, 1, 0);
    HamurColor HamurColor::BLUE(0, 0, 1);
    HamurColor HamurColor::BLACK(0, 0, 0);
    HamurColor HamurColor::WHITE(1, 1, 1);
    HamurColor HamurColor::YELLOW(1, 1, 0);
    HamurColor HamurColor::CYAN(0, 1, 1);
    HamurColor HamurColor::MAGENTA(1, 0, 1);
    HamurColor HamurColor::GREY(0.5, 0.5, 0.5);
    */
}

#endif // HAMURCOLOR_H