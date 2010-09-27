#ifndef HAMURMATH_H
#define HAMURMATH_H

#define PI 3.14159265359f

namespace hamur
{

class HamurMath
{
    public:
        struct Converter
        {
            static float DegreeToRadian(float degree);
            static float RadianToDegree(float radian);
        };
};

} // namespace hamur

#endif // HAMURMATH_H