#ifndef HAMURCOLOR_H
#define HAMURCOLOR_H
#include <string>


namespace hamur
{

class HamurColor
{
    public:

        HamurColor() {};

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

class HamurColorRGB
{
public:

    HamurColorRGB() {};

    // Red, Green, Blue color values.
    HamurColorRGB(int R, int G, int B);

    static HamurColorRGB RED;
    static HamurColorRGB GREEN;
    static HamurColorRGB BLUE;
    static HamurColorRGB BLACK;
    static HamurColorRGB WHITE;
    static HamurColorRGB YELLOW;
    static HamurColorRGB CYAN;
    static HamurColorRGB MAGENTA;
    static HamurColorRGB GREY;
    static HamurColorRGB COLORKEY; /**< Default colorkey of Hamur Engine (255, 0, 255) */

    int R;
    int G;
    int B;
};

} // namespace hamur

#endif // HAMURCOLOR_H