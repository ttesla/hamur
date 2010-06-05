#include "hamurPlotter.h"

#include "hamurVec2.h"
#include "hamurVec3.h"
#include "../hamurGL.h"
#include "../hamurTexMR.h"
#include "hamurConsole.h"
#include "../hamurDefinitions.h"
#include "hamurColor.h"

namespace hamur
{
    void HamurPlotter::drawRectangle(const HamurVec3 &_pos, float _width, float _height, const HamurColor& _color)
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
    }

    void HamurPlotter::drawRectangle(const HamurVec2 &_pos, float _width, float _height, const HamurColor& _color)
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
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex3f(_vertice1.x, _vertice1.y, _vertice1.z);
        glVertex3f(_vertice2.x, _vertice2.y, _vertice2.z);
        glVertex3f(_vertice3.x, _vertice3.y, _vertice3.z);
        glVertex3f(_vertice4.x, _vertice4.y, _vertice4.z);
        glEnd();
        glEnable(GL_TEXTURE_2D);
    }

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
        glColor3f(_color.R, _color.G, _color.B);
        glBegin(GL_LINE_LOOP);
        glVertex2f(_vertice1.x, _vertice1.y);
        glVertex2f(_vertice2.x, _vertice2.y);
        glVertex2f(_vertice3.x, _vertice3.y);
        glVertex2f(_vertice4.x, _vertice4.y);
        glEnd();
        glEnable(GL_TEXTURE_2D);
    }

    void HamurPlotter::drawPolygon()
    {

    }

    void HamurPlotter::drawSolidPolygon()
    {

    }

    void HamurPlotter::drawCircle()
    {

    }

    void HamurPlotter::drawSolidCircle()
    {

    }

    void HamurPlotter::drawLine()
    {

    }

    void HamurPlotter::drawPoint()
    {

    }
}