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
 
            static void DrawRectangle(float xCor, float yCor, float width, float height, const HamurColor& color, float rotationAngle = 0);
            static void DrawRectangle(float xCor, float yCor, float zCor, float width, float height, const HamurColor& color, float rotationAngle = 0);
            static void DrawRectangle(const HamurVec2& position, float width, float height, const HamurColor& color, float rotationAngle = 0);
            static void DrawRectangle(const HamurVec3& position, float width, float height, const HamurColor& color, float rotationAngle = 0);

            static void DrawSolidRectangle(float xCor, float yCor, float width, float height, const HamurColor& color, float rotationAngle = 0);
            static void DrawSolidRectangle(float xCor, float yCor, float zCor, float width, float height, const HamurColor& color, float rotationAngle = 0);
            static void DrawSolidRectangle(const HamurVec2& position, float width, float height, const HamurColor& color, float rotationAngle = 0);
            static void DrawSolidRectangle(const HamurVec3& position, float width, float height, const HamurColor& color, float rotationAngle = 0);

            static void DrawPolygon(const HamurVec2* verticeList, int verticeCount, const HamurColor& color, float rotationAngle = 0);
            static void DrawPolygon(const HamurVec3* verticeList, int verticeCount, const HamurColor& color, float rotationAngle = 0);

            static void DrawSolidPolygon(const HamurVec2* verticeList, int verticeCount, const HamurColor& color, float rotationAngle = 0);
            static void DrawSolidPolygon(const HamurVec3* verticeList, int verticeCount, const HamurColor& color, float rotationAngle = 0);

            static void DrawCircle(float xCenter, float yCenter, float radius, const HamurColor& color);
            static void DrawCircle(float xCenter, float yCenter, float zCenter, float radius, const HamurColor& color);
            static void DrawCircle(const HamurVec2& position, float radius, const HamurColor& color);
            static void DrawCircle(const HamurVec3& position, float radius, const HamurColor& color);

            static void DrawSolidCircle(float xCenter, float yCenter, float radius, const HamurColor& color);
            static void DrawSolidCircle(float xCenter, float yCenter, float zCenter, float radius, const HamurColor& color);
            static void DrawSolidCircle(const HamurVec2& position, float radius, const HamurColor& color);
            static void DrawSolidCircle(const HamurVec3& position, float radius, const HamurColor& color);

            static void DrawLine(float firstX, float firstY, float secondX, float secondY, const HamurColor& color, float rotationAngle = 0);
            static void DrawLine(float firstX, float firstY, float firstZ, float secondX, float secondY, float secondZ, const HamurColor& color, float rotationAngle = 0);
            static void DrawLine(const HamurVec2& pos1, const HamurVec2& pos2, const HamurColor& color, float rotationAngle = 0);
            static void DrawLine(const HamurVec3& pos1, const HamurVec3& pos2, const HamurColor& color, float rotationAngle = 0);

            static void DrawPoint(float pointX, float pointY, const HamurColor& color);
            static void DrawPoint(float pointX, float pointY, float pointZ, const HamurColor& color);
            static void DrawPoint(const HamurVec2& position, const HamurColor& color);
            static void DrawPoint(const HamurVec3& position, const HamurColor& color);
    };
}

#endif // HAMURPLOTTER_H
