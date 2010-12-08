#ifndef HAMUR_RECT_H
#define HAMUR_RECT_H 

#include <iostream>

using std::ostream;


namespace hamur
{

/** 
*   Hamur Rectangle Class. 
*/
class HamurRect
{
    public:

        float x;      /**< Rectangle starting X position */
        float y;      /**< Rectangle starting Y position */
        float width;  /**< Rectangle Width  */
        float height; /**< Rectangle Height */

        HamurRect() : x(0), y(0), width(0), height(0)  { }

        HamurRect(float X, float Y, float Width, float Height) 
            : x(X), y(Y), width(Width), height(Height) 
        { 
            // Empty
        }

        ~HamurRect() { }

        /** Set this rectangle to specified coordinates, Width and Height*/
        void Set(float X, float Y, float Width, float Height);
};


inline void HamurRect::Set(float X, float Y, float Width, float Height)
{
    x = X;
    y = Y;
    width = Width;
    height = Height;
}


/** Writes the HamurRect to the stream */
inline ostream &operator<<(ostream &os, const HamurRect &rect)
{
    os << rect.x << ", " << rect.y << ", " << rect.width << ", " << rect.height;
    return os;
} 


} // namespace hamur


#endif // HAMUR_RECT_H