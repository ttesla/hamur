#ifndef HAMURPLOTTER_H
#define HAMURPLOTTER_H

#include "hamurColor.h"



namespace hamur
{
    class HamurVec3;
    class HamurVec2;
    class HamurColor;

    class HamurPlotter
    {
        public:
 
            static void drawRectangle(float xCor, float yCor, float width, float height, const HamurColor& color);
            static void drawRectangle(float xCor, float yCor, float zCor, float width, float height, const HamurColor& color);
            static void drawRectangle(const HamurVec2& position, float width, float height, const HamurColor& color);
            static void drawRectangle(const HamurVec3& position, float width, float height, const HamurColor& color);

            static void drawSolidRectangle(float xCor, float yCor, float width, float height, const HamurColor& color);
            static void drawSolidRectangle(float xCor, float yCor, float zCor, float width, float height, const HamurColor& color);
            static void drawSolidRectangle(const HamurVec2& position, float width, float height, const HamurColor& color);
            static void drawSolidRectangle(const HamurVec3& position, float width, float height, const HamurColor& color);

            static void drawPolygon(const HamurVec2* verticeList, int verticeCount, const HamurColor& color);
            static void drawPolygon(const HamurVec3* verticeList, int verticeCount, const HamurColor& color);

            static void drawSolidPolygon(const HamurVec2* verticeList, int verticeCount, const HamurColor& color);
            static void drawSolidPolygon(const HamurVec3* verticeList, int verticeCount, const HamurColor& color);

            static void drawTriangle();
            static void drawSolidTriangle();

            static void drawCircle();
            static void drawSolidCircle();

            static void drawLine();
            static void drawPoint();
    };
}

#endif // HAMURPLOTTER_H
