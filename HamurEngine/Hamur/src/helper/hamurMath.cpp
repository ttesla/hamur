#include "hamurMath.h"

namespace hamur
{

float HamurMath::Converter::DegreeToRadian(float degree)
{
   return (float)((degree / 180) * PI);

}

float HamurMath::Converter::RadianToDegree(float radian)
{
    return (float)((radian / PI) * 180);
}

} // namespace hamur