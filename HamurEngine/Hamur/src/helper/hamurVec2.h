#ifndef HAMUR_VEC2_H
#define HAMUR_VEC2_H 

#include <cmath>
#include <iostream>

using std::ostream;

namespace hamur
{

/** 
*    Hamur 2D Vector Class. 
*/
class HamurVec2
{

    public:

	    float x;
	    float y;

	    HamurVec2() : x(0), y(0)  { }

	    HamurVec2(float xc, float yc) : x(xc), y(yc) { }
    
        ~HamurVec2() { }

	    /** Normalizes the vector to length 1. */
	    void Normalize ()
	    {
		    float l = 1.0f / (float)(sqrt(x*x + y*y));
		    x*=l; y*=l;
	    }

	    /** Returns the length of the vector. */
	    float Length () const { return sqrt(x*x + y*y); }

	    /** Returns the squared length of the vector. */
	    float SquaredLength () const { return (x*x + y*y); }

	    /** Set this vector to some specified coordinates */
	    void Set(float xc, float yc) { x = xc; y = yc; }

		/** Set all vector elements to zero. */
		void SetZero() { x = 0.0f; y = 0.0f; }

        /** Set all vector elements with the given value. */
        void SetAll(float xy) { x = xy; y = xy; }

	    /** Flips the signs of all coordinates. */
	    void Flip() { x=-x; y=-y; }

        /** Returns the vector with the signs of all coordinates flipped. */
        const HamurVec2 operator-() const{ return HamurVec2(-x, -y); }

	    /** Subtracts \a vec from the vector. */
	    const HamurVec2 operator-(const HamurVec2 &vec) const { return HamurVec2 (x-vec.x, y-vec.y); }
	
	    /** Adds \a vec to the vector. */
	    const HamurVec2 operator+(const HamurVec2 &vec) const { return HamurVec2 (x+vec.x, y+vec.y); }

	    /** Returns the vector scaled by \a scalar. */
	    const HamurVec2 operator*(float fact) const { return HamurVec2 (x*fact, y*fact); }

	    /** Returns the vector scaled by \a scalar. */
	    const HamurVec2 operator/(float fact) const { float xfact = 1.0f/fact; return HamurVec2 (x*xfact, y*xfact); }

	    /** Scales the vector by \a scalar. */
	    HamurVec2& operator*=(float fact){ x*=fact; y*=fact; return *this; }

	    /** Returns the dot product of \a v1 and \a v2.*/
	    inline float DotProduct(const HamurVec2 &v1, const HamurVec2 &v2)
	    {
		    return v1.x*v2.x + v1.y*v2.y;
	    }

};

/** Writes the Vector to the stream */
inline ostream &operator<<(ostream &os, const HamurVec2 &v)
{
	os << v.x << ", " << v.y;
	return os;
} 

} // namespace hamur

#endif // HAMURVEC2_H
