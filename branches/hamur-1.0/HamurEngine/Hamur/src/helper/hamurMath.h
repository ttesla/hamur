#ifndef HAMURMATH_H
#define HAMURMATH_H

#ifndef PI
#define PI 3.14159265359f
#endif

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#include "hamurVec2.h"
#include "hamurVec3.h"
#include <cstdlib>
#include <ctime>


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

		static inline int Random(int bottom, int top)
		{
			if(bottom < top)
				return rand()%(top-bottom) + bottom;
			else
				return INT_MAX;
		}

		static inline float Distance(const HamurVec2& a, const HamurVec2& b)
		{
			HamurVec2 c = a - b;
			return c.Length();
		}

		static inline float Distance(const HamurVec3& a, const HamurVec3& b)
		{
			HamurVec3 c = a - b;
			return c.Length();
		}

		static inline float DistanceSquared(const HamurVec2& a, const HamurVec2& b)
		{
			HamurVec2 c = a - b;
			return Dot(c, c);
		}

		static inline float DistanceSquared(const HamurVec3& a, const HamurVec3& b)
		{
			HamurVec3 c = a - b;
			return Dot(c, c);
		}


		/// Perform the dot product on two vectors.
		static inline float Dot(const HamurVec3& a, const HamurVec3& b)
		{
			return a.x * b.x + a.y * b.y + a.z * b.z;
		}

		/// Perform the dot product on two vectors.
		static inline float Dot(const HamurVec2& a, const HamurVec2& b)
		{
			return a.x * b.x + a.y * b.y;
		}

		/// Perform the cross product on two vectors.
		static inline HamurVec3 Cross(const HamurVec3& a, const HamurVec3& b)
		{
			return HamurVec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
		}

		static inline float Abs(float a)
		{
			return a > 0.0f ? a : -a;
		}

		static inline HamurVec2 Abs(const HamurVec2& a)
		{
			return HamurVec2(Abs(a.x), Abs(a.y));
		}

		static inline HamurVec3 Abs(const HamurVec3& a)
		{
			return HamurVec3(Abs(a.x), Abs(a.y), Abs(a.z));
		}

		template <typename T>
		static inline T Min(T a, T b)
		{
			return a < b ? a : b;
		}

		static inline HamurVec2 Min(const HamurVec2& a, const HamurVec2& b)
		{
			return HamurVec2(Min(a.x, b.x), Min(a.y, b.y));
		}

		static inline HamurVec3 Min(const HamurVec3& a, const HamurVec3& b)
		{
			return HamurVec3(Min(a.x, b.x), Min(a.y, b.y), Min(a.z, b.z));
		}

		template <typename T>
		static inline T Max(T a, T b)
		{
			return a > b ? a : b;
		}

		static inline HamurVec2 Max(const HamurVec2& a, const HamurVec2& b)
		{
			return HamurVec2(Max(a.x, b.x), Max(a.y, b.y));
		}

		static inline HamurVec3 Max(const HamurVec3& a, const HamurVec3& b)
		{
			return HamurVec3(Max(a.x, b.x), Max(a.y, b.y), Max(a.z, b.z));
		}

		template <typename T>
		static inline T Clamp(T a, T low, T high)
		{
			return Max(low, Min(a, high));
		}

		static inline HamurVec2 Clamp(const HamurVec2& a, const HamurVec2& low, const HamurVec2& high)
		{
			return Max(low, Min(a, high));
		}

		template<typename T>
		static inline void Swap(T& a, T& b)
		{
			T tmp = a;
			a = b;
			b = tmp;
		}

		static inline bool IsPowerOfTwo(unsigned int x)
		{
			bool result = x > 0 && (x & (x - 1)) == 0;
			return result;
		}
};

inline HamurVec2 operator * (float s, const HamurVec2& a)
{
	return HamurVec2(s * a.x, s * a.y);
}


inline HamurVec3 operator * (float s, const HamurVec3& a)
{
	return HamurVec3(s * a.x, s * a.y, s * a.z);
}

inline bool operator == (const HamurVec2& a, const HamurVec2& b)
{
	return a.x == b.x && a.y == b.y;
}

inline bool operator == (const HamurVec3& a, const HamurVec3& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

} // namespace hamur

#endif // HAMURMATH_H
