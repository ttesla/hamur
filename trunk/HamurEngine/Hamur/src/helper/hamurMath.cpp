#include "hamurMath.h"

namespace hamur
{
    float HamurMath::converter::degreeToRadian(float _degree)
    {
       return (_degree / 180) * pi;

    }

    float HamurMath::converter::radianToDegree(float _radian)
    {
        return (_radian / pi) * 180;
    }
}