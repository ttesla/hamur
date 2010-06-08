#ifndef HAMUR_VEC2_H
#define HAMUR_VEC2_H 

#include <cmath>
#include <iostream>

using std::ostream;

namespace hamur
{
	/** 
        Hamur 2D Vector Class. 
        - Taken from somewhere from internet
    */
	class HamurVec2
	{
	public:

		float x;
		float y;

		HamurVec2() {}
		HamurVec2(float xc, float yc) : x(xc), y(yc){}
        ~HamurVec2() {}

		/** Normalizes the vector to length 1. */
		void normalize ()
		{
			float l = 1.0f / (float)(sqrt(x*x + y*y));
			x*=l; y*=l;
		}

		/** Returns the length of the vector. */
		float getLength () const { return sqrt(x*x + y*y); }

		/** Returns the squared length of the vector. */
		float getSquaredLength () const { return (x*x + y*y); }

		/** Returns the vector with the signs of all coordinates flipped. */
		const HamurVec2 operator- () const{ return HamurVec2(-x, -y); }

		/** Flips the signs of all coordinates. */
		void flip() { x=-x; y=-y; }

		/** Subtracts \a vec from the vector. */
		const HamurVec2 operator-(const HamurVec2 &vec) const { return HamurVec2 (x-vec.x, y-vec.y); }
		
		/** Adds \a vec to the vector. */
		const HamurVec2 operator+(const HamurVec2 &vec) const { return HamurVec2 (x+vec.x, y+vec.y); }

		/** Returns the vector scaled by \a fact. */
		const HamurVec2 operator*(float fact) const { return HamurVec2 (x*fact, y*fact); }

		/** Returns the vector scaled by \a fact. */
		const HamurVec2 operator/(float fact) const { float xfact = 1.0f/fact; return HamurVec2 (x*xfact, y*xfact); }

		/** Scales the vector by \a fact. */
		HamurVec2 &operator*=(float fact){ x*=fact; y*=fact; return *this; }

		/** Returns the dot product of \a v1 and \a v2.*/
		inline float dotProduct(const HamurVec2 &v1, const HamurVec2 &v2)
		{
			return v1.x*v2.x + v1.y*v2.y;
		}

	};

	/** Writes the Vector to the stream */
	inline std::ostream &operator<<(std::ostream &os, const HamurVec2 &v)
	{
		os << v.x << ", " << v.y;
		return os;
	}
}

#endif