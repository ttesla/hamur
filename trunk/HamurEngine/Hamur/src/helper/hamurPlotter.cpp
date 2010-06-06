#include "hamurPlotter.h"

#include "hamurVec2.h"
#include "hamurVec3.h"
#include "../hamurGL.h"
#include "../hamurTexMR.h"
#include "hamurConsole.h"
#include "../hamurDefinitions.h"
#include "hamurColor.h"
#include "hamurMath.h"

namespace hamur
{
    void HamurPlotter::drawRectangle(float _x, float _y, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec2 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _x;
        _vertice1.y = _y;

        _vertice2.x = _x;
        _vertice2.y = _y + _height;

        _vertice3.x = _x + _width;
        _vertice3.y = _y + _height;

        _vertice4.x = _x + _width;
        _vertice4.y = _y;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);


        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex2f(_vertice1.x, _vertice1.y);
        glVertex2f(_vertice2.x, _vertice2.y);
        glVertex2f(_vertice3.x, _vertice3.y);
        glVertex2f(_vertice4.x, _vertice4.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawRectangle(float _x, float _y, float _z, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec3 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _x;
        _vertice1.y = _y;
        _vertice1.z = _z;

        _vertice2.x = _x;
        _vertice2.y = _y + _height;
        _vertice2.z = _z;

        _vertice3.x = _x + _width;
        _vertice3.y = _y + _height;
        _vertice3.z = _z;

        _vertice4.x = _x + _width;
        _vertice4.y = _y;
        _vertice4.z = _z;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);


        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex3f(_vertice1.x, _vertice1.y, _vertice1.z);
        glVertex3f(_vertice2.x, _vertice2.y, _vertice2.z);
        glVertex3f(_vertice3.x, _vertice3.y, _vertice3.z);
        glVertex3f(_vertice4.x, _vertice4.y, _vertice4.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    
    void HamurPlotter::drawRectangle(const HamurVec2& _pos, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec2 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _pos.x;
        _vertice1.y = _pos.y;

        _vertice2.x = _pos.x;
        _vertice2.y = _pos.y + _height;

        _vertice3.x = _pos.x + _width;
        _vertice3.y = _pos.y + _height;

        _vertice4.x = _pos.x + _width;
        _vertice4.y = _pos.y;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);



        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex2f(_vertice1.x, _vertice1.y);
        glVertex2f(_vertice2.x, _vertice2.y);
        glVertex2f(_vertice3.x, _vertice3.y);
        glVertex2f(_vertice4.x, _vertice4.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawRectangle(const HamurVec3& _pos, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec3 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _pos.x;
        _vertice1.y = _pos.y;
        _vertice1.z = _pos.z;

        _vertice2.x = _pos.x;
        _vertice2.y = _pos.y + _height;
        _vertice2.z = _pos.z;

        _vertice3.x = _pos.x + _width;
        _vertice3.y = _pos.y + _height;
        _vertice3.z = _pos.z;

        _vertice4.x = _pos.x + _width;
        _vertice4.y = _pos.y;
        _vertice4.z = _pos.z;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);



        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex3f(_vertice1.x, _vertice1.y, _vertice1.z);
        glVertex3f(_vertice2.x, _vertice2.y, _vertice2.z);
        glVertex3f(_vertice3.x, _vertice3.y, _vertice3.z);
        glVertex3f(_vertice4.x, _vertice4.y, _vertice4.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawSolidRectangle(float _x, float _y, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec2 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _x;
        _vertice1.y = _y;

        _vertice2.x = _x;
        _vertice2.y = _y + _height;

        _vertice3.x = _x + _width;
        _vertice3.y = _y + _height;

        _vertice4.x = _x + _width;
        _vertice4.y = _y;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);


        glDisable(GL_TEXTURE_2D);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(_vertice1.x, _vertice1.y);
        glVertex2f(_vertice2.x, _vertice2.y);
        glVertex2f(_vertice3.x, _vertice3.y);
        glVertex2f(_vertice4.x, _vertice4.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawSolidRectangle(float _x, float _y, float _z, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec3 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _x;
        _vertice1.y = _y;
        _vertice1.z = _z;

        _vertice2.x = _x;
        _vertice2.y = _y + _height;
        _vertice2.z = _z;

        _vertice3.x = _x + _width;
        _vertice3.y = _y + _height;
        _vertice3.z = _z;

        _vertice4.x = _x + _width;
        _vertice4.y = _y;
        _vertice4.z = _z;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);


        glDisable(GL_TEXTURE_2D);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex3f(_vertice1.x, _vertice1.y, _vertice1.z);
        glVertex3f(_vertice2.x, _vertice2.y, _vertice2.z);
        glVertex3f(_vertice3.x, _vertice3.y, _vertice3.z);
        glVertex3f(_vertice4.x, _vertice4.y, _vertice4.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawSolidRectangle(const HamurVec2& _pos, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec2 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _pos.x;
        _vertice1.y = _pos.y;

        _vertice2.x = _pos.x;
        _vertice2.y = _pos.y + _height;

        _vertice3.x = _pos.x + _width;
        _vertice3.y = _pos.y + _height;

        _vertice4.x = _pos.x + _width;
        _vertice4.y = _pos.y;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);



        glDisable(GL_TEXTURE_2D);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex2f(_vertice1.x, _vertice1.y);
        glVertex2f(_vertice2.x, _vertice2.y);
        glVertex2f(_vertice3.x, _vertice3.y);
        glVertex2f(_vertice4.x, _vertice4.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawSolidRectangle(const HamurVec3& _pos, float _width, float _height, const HamurColor& _color)
    {
        // All vertices of our square
        HamurVec3 _vertice1, _vertice2, _vertice3, _vertice4;

        _vertice1.x = _pos.x;
        _vertice1.y = _pos.y;
        _vertice1.z = _pos.z;

        _vertice2.x = _pos.x;
        _vertice2.y = _pos.y + _height;
        _vertice2.z = _pos.z;

        _vertice3.x = _pos.x + _width;
        _vertice3.y = _pos.y + _height;
        _vertice3.z = _pos.z;

        _vertice4.x = _pos.x + _width;
        _vertice4.y = _pos.y;
        _vertice4.z = _pos.z;

        // For world to OpenGL coordinate conversions
        _vertice1 = HAMURTEXMR->worldToGL(_vertice1);
        _vertice2 = HAMURTEXMR->worldToGL(_vertice2);
        _vertice3 = HAMURTEXMR->worldToGL(_vertice3);
        _vertice4 = HAMURTEXMR->worldToGL(_vertice4);



        glDisable(GL_TEXTURE_2D);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex3f(_vertice1.x, _vertice1.y, _vertice1.z);
        glVertex3f(_vertice2.x, _vertice2.y, _vertice2.z);
        glVertex3f(_vertice3.x, _vertice3.y, _vertice3.z);
        glVertex3f(_vertice4.x, _vertice4.y, _vertice4.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawPolygon(const HamurVec2* _verticeList, int _verticeCount, const HamurColor& _color)
    {
        HamurVec2 _transformVertice;

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < _verticeCount; i++)
        {
            _transformVertice = HAMURTEXMR->worldToGL(_verticeList[i]);
            glVertex2f(_transformVertice.x, _transformVertice.y);
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPolygon(const HamurVec3* _verticeList, int _verticeCount, const HamurColor& _color)
    {
        HamurVec3 _transformVertice;

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < _verticeCount; i++)
        {
            _transformVertice = HAMURTEXMR->worldToGL(_verticeList[i]);
            glVertex3f(_transformVertice.x, _transformVertice.y, _transformVertice.z);
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidPolygon(const HamurVec2* _verticeList, int _verticeCount, const HamurColor& _color)
    {
        HamurVec2 _transformVertice;

        glDisable(GL_TEXTURE_2D);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < _verticeCount; i++)
        {
            _transformVertice = HAMURTEXMR->worldToGL(_verticeList[i]);
            glVertex2f(_transformVertice.x, _transformVertice.y);
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidPolygon(const HamurVec3* _verticeList, int _verticeCount, const HamurColor& _color)
    {
        HamurVec3 _transformVertice;

        glDisable(GL_TEXTURE_2D);
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < _verticeCount; i++)
        {
            _transformVertice = HAMURTEXMR->worldToGL(_verticeList[i]);
            glVertex3f(_transformVertice.x, _transformVertice.y, _transformVertice.z);
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawCircle(float _xCenter, float _yCenter, float _radius, const HamurColor& _color)
    {
        HamurVec2 transformVec(_xCenter, _yCenter);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);


        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(angle),
                                                 _yCenter + _radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawCircle(float _xCenter, float _yCenter, float _zCenter, float _radius, const HamurColor& _color)
    {
        HamurVec3 transformVec(_xCenter, _yCenter, _zCenter);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(angle),
                _yCenter + _radius * sinf(angle), _zCenter);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawCircle(const HamurVec2& _pos, float _radius, const HamurColor& _color)
    {
        HamurVec2 transformVec(_pos.x, _pos.y);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(angle),
                _pos.y + _radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawCircle(const HamurVec3& _pos, float _radius, const HamurColor& _color)
    {
        HamurVec3 transformVec(_pos.x, _pos.y, _pos.z);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(angle),
                _pos.y + _radius * sinf(angle), _pos.z);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(float _xCenter, float _yCenter, float _radius, const HamurColor& _color)
    {
        HamurVec2 transformVec(_xCenter, _yCenter);
        glDisable(GL_TEXTURE_2D);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(angle),
                _yCenter + _radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(float _xCenter, float _yCenter, float _zCenter, float _radius, const HamurColor& _color)
    {
        HamurVec3 transformVec(_xCenter, _yCenter,_zCenter);
        glDisable(GL_TEXTURE_2D);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(angle),
                _yCenter + _radius * sinf(angle), _zCenter);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(const HamurVec2& _pos, float _radius, const HamurColor& _color)
    {
        HamurVec2 transformVec(_pos.x, _pos.y);
        glDisable(GL_TEXTURE_2D);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(angle),
                _pos.y + _radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(const HamurVec3& _pos, float _radius, const HamurColor& _color)
    {
        HamurVec3 transformVec(_pos.x, _pos.y,_pos.z);
        glDisable(GL_TEXTURE_2D);
        float angle = 0.0f;
        float angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float loopCount = 2*pi / angleIncrement;
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(angle),
                _pos.y + _radius * sinf(angle), _pos.z);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawLine(float _firstX, float _firstY, float _secondX, float _secondY, const HamurColor& _color)
    {
        HamurVec2 transformVec1;
        HamurVec2 transformVec2;

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glBegin(GL_LINE_LOOP);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec1 = HAMURTEXMR->worldToGL(_firstX, _firstY);
        transformVec2 = HAMURTEXMR->worldToGL(_secondX, _secondY);
        glVertex2f(transformVec1.x, transformVec1.y);
        glVertex2f(transformVec2.x, transformVec2.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawLine(float _firstX, float _firstY, float _firstZ, float _secondX, float _secondY, float _secondZ, const HamurColor& _color)
    {
        HamurVec3 transformVec1;
        HamurVec3 transformVec2;

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glBegin(GL_LINE_LOOP);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec1 = HAMURTEXMR->worldToGL(_firstX, _firstY, _firstZ);
        transformVec2 = HAMURTEXMR->worldToGL(_secondX, _secondY, _secondZ);
        glVertex3f(transformVec1.x, transformVec1.y, transformVec1.z);
        glVertex3f(transformVec2.x, transformVec2.y, transformVec2.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawLine(const HamurVec2& _pos1, const HamurVec2& _pos2, const HamurColor& _color)
    {
        HamurVec2 transformVec1;
        HamurVec2 transformVec2;

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glBegin(GL_LINE_LOOP);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec1 = HAMURTEXMR->worldToGL(_pos1);
        transformVec2 = HAMURTEXMR->worldToGL(_pos2);
        glVertex2f(transformVec1.x, transformVec1.y);
        glVertex2f(transformVec2.x, transformVec2.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawLine(const HamurVec3& _pos1, const HamurVec3& _pos2, const HamurColor& _color)
    {
        HamurVec3 transformVec1;
        HamurVec3 transformVec2;

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glBegin(GL_LINE_LOOP);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec1 = HAMURTEXMR->worldToGL(_pos1);
        transformVec2 = HAMURTEXMR->worldToGL(_pos2);
        glVertex3f(transformVec1.x, transformVec1.y, transformVec1.z);
        glVertex3f(transformVec2.x, transformVec2.y, transformVec2.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);
        glColor3f(1.0f, 1.0f, 1.0f);
    }


    void HamurPlotter::drawPoint(float _pointX, float _pointY, const HamurColor& _color)
    {
        HamurVec2 transformVec;
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_POINTS);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec = HAMURTEXMR->worldToGL(_pointX, _pointY);
        glVertex2f(transformVec.x, transformVec.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPoint(float _pointX, float _pointY, float _pointZ, const HamurColor& _color)
    {
        HamurVec3 transformVec;
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_POINTS);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec = HAMURTEXMR->worldToGL(_pointX, _pointY, _pointZ);
        glVertex3f(transformVec.x, transformVec.y, transformVec.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPoint(const HamurVec2& _pos, const HamurColor& _color)
    {
        HamurVec2 transformVec;
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_POINTS);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec = HAMURTEXMR->worldToGL(_pos);
        glVertex2f(transformVec.x, transformVec.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPoint(const HamurVec3& _pos, const HamurColor& _color)
    {
        HamurVec3 transformVec;
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_POINTS);
        glColor3f(_color.R, _color.G, _color.B);
        transformVec = HAMURTEXMR->worldToGL(_pos);
        glVertex3f(transformVec.x, transformVec.y, transformVec.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0f, 1.0f, 1.0f);
    }
}