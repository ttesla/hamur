#ifndef HAMUR_VEC3_H
#define HAMUR_VEC3_H 

#include <cmath>
#include <iostream>

using std::ostream;

namespace hamur
{

/** Hamur 3D Vector Class. */
class HamurVec3
{
public:

	float x;
	float y;
	float z;

	HamurVec3() : x(0), y(0), z(0) { }

	HamurVec3(float xc, float yc, float zc) : x(xc), y(yc), z(zc)  { }

    ~HamurVec3() { }

	/** Normalizes the vector to length 1. */
	void Normalize ()
	{
		float l = 1.0f / (float)(sqrt(x*x + y*y + z*z));
		x*=l; y*=l; z*=l;
	}

	/** Returns the length of the vector. */
	float GetLength () const { return sqrt(x*x + y*y + z*z); }

	/** Returns the squared length of the vector. */
	float GetSquaredLength () const { return (x*x + y*y + z*z); }

    /** Sets the vector elements to zero*/
    void SetZero() { x = 0.0f; y = 0.0f; z = 0.0f;}

	/** Flips the signs of all coordinates. */
	void Flip() { x=-x; y=-y; z=-z; }

    /** Returns the vector with the signs of all coordinates flipped. */
    const HamurVec3 operator- () const{ return HamurVec3(-x, -y, -z); }

	/** Subtracts \a vec from the vector. */
	const HamurVec3 operator-(const HamurVec3 &vec) const { return HamurVec3 (x-vec.x, y-vec.y, z-vec.z); }
	
	/** Adds \a vec to the vector. */
	const HamurVec3 operator+(const HamurVec3 &vec) const { return HamurVec3 (x+vec.x, y+vec.y, z+vec.z); }

	/** Returns the vector scaled by \a fact. */
	const HamurVec3 operator*(float fact) const { return HamurVec3 (x*fact, y*fact, z*fact); }

	/** Returns the vector scaled by \a fact. */
	const HamurVec3 operator/(float fact) const { float xfact = 1.0f/fact; return HamurVec3 (x*xfact, y*xfact, z*xfact); }

	/** Scales the vector by \a fact. */
	HamurVec3 &operator*=(float fact){ x*=fact; y*=fact; z*=fact; return *this; }

	/** Returns the dot product of \a v1 and \a v2.*/
	inline float DotProduct(const HamurVec3 &v1, const HamurVec3 &v2)
	{
		return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}

	/** Returns the cross product of \a a and \a b.*/
	inline HamurVec3 CrossProduct(const HamurVec3 &a, const HamurVec3 &b)
	{
		return HamurVec3 (a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	}

};

/** Writes the Vector to the stream */
inline std::ostream &operator<<(std::ostream &os, const HamurVec3 &v)
{
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

} // namespace hamur

#endif // HAMURVEC3_H