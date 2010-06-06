#ifndef HAMURMATH_H
#define HAMURMATH_H

#define pi 3.14159265359f

namespace hamur
{
    class HamurMath
    {
        public:
            typedef struct converter
            {
                static float degreeToRadian(float degree);
                static float radianToDegree(float radian);

            }Converter;

    };
}
#endif