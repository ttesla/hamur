#ifndef HAMURPLOTTER_H
#define HAMURPLOTTER_H

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

            static void drawCircle(float xCenter, float yCenter, float radius, const HamurColor& color);
            static void drawCircle(float xCenter, float yCenter, float zCenter, float radius, const HamurColor& color);
            static void drawCircle(const HamurVec2& position, float radius, const HamurColor& color);
            static void drawCircle(const HamurVec3& position, float radius, const HamurColor& color);

            static void drawSolidCircle(float xCenter, float yCenter, float radius, const HamurColor& color);
            static void drawSolidCircle(float xCenter, float yCenter, float zCenter, float radius, const HamurColor& color);
            static void drawSolidCircle(const HamurVec2& position, float radius, const HamurColor& color);
            static void drawSolidCircle(const HamurVec3& position, float radius, const HamurColor& color);

            static void drawLine(float firstX, float firstY, float secondX, float secondY, const HamurColor& color);
            static void drawLine(float firstX, float firstY, float firstZ, float secondX, float secondY, float secondZ, const HamurColor& color);
            static void drawLine(const HamurVec2& pos1, const HamurVec2& pos2, const HamurColor& color);
            static void drawLine(const HamurVec3& pos1, const HamurVec3& pos2, const HamurColor& color);

            static void drawPoint(float pointX, float pointY, const HamurColor& color);
            static void drawPoint(float pointX, float pointY, float pointZ, const HamurColor& color);
            static void drawPoint(const HamurVec2& position, const HamurColor& color);
            static void drawPoint(const HamurVec3& position, const HamurColor& color);
    };
}

#endif // HAMURPLOTTER_H
