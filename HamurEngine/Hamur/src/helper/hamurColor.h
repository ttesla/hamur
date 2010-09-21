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

} // namespace hamur

#endif // HAMURCOLOR_H