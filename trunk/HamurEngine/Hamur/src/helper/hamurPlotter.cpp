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
    void HamurPlotter::drawRectangle(float _x, float _y, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec2 _vertex1, _vertex2, _vertex3, _vertex4;

        // For World to OpenGL coordinate conversions 
        _vertex1.x = _x;
        _vertex1.y = _y;

        _vertex2.x = _x;
        _vertex2.y = _y + _height;

        _vertex3.x = _x + _width;
        _vertex3.y = _y + _height;

        _vertex4.x = _x + _width;
        _vertex4.y = _y;

        // Here World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix.
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex2f(_vertex1.x, _vertex1.y);
            glVertex2f(_vertex2.x, _vertex2.y);
            glVertex2f(_vertex3.x, _vertex3.y);
            glVertex2f(_vertex4.x, _vertex4.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawRectangle(float _x, float _y, float _z, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec3 _vertex1, _vertex2, _vertex3, _vertex4;

        // For World to OpenGL coordinate conversions 
        _vertex1.x = _x;
        _vertex1.y = _y;
        _vertex1.z = _z;

        _vertex2.x = _x;
        _vertex2.y = _y + _height;
        _vertex2.z = _z;

        _vertex3.x = _x + _width;
        _vertex3.y = _y + _height;
        _vertex3.z = _z;

        _vertex4.x = _x + _width;
        _vertex4.y = _y;
        _vertex4.z = _z;

        // Here World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix.
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, _vertex1.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, _vertex1.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex3f(_vertex1.x, _vertex1.y, _vertex1.z);
            glVertex3f(_vertex2.x, _vertex2.y, _vertex2.z);
            glVertex3f(_vertex3.x, _vertex3.y, _vertex3.z);
            glVertex3f(_vertex4.x, _vertex4.y, _vertex4.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    
    void HamurPlotter::drawRectangle(const HamurVec2& _pos, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec2 _vertex1, _vertex2, _vertex3, _vertex4;

        // Here World to OpenGL coordinate conversions
        _vertex1.x = _pos.x;
        _vertex1.y = _pos.y;

        _vertex2.x = _pos.x;
        _vertex2.y = _pos.y + _height;

        _vertex3.x = _pos.x + _width;
        _vertex3.y = _pos.y + _height;

        _vertex4.x = _pos.x + _width;
        _vertex4.y = _pos.y;

        // For World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex2f(_vertex1.x, _vertex1.y);
            glVertex2f(_vertex2.x, _vertex2.y);
            glVertex2f(_vertex3.x, _vertex3.y);
            glVertex2f(_vertex4.x, _vertex4.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawRectangle(const HamurVec3& _pos, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec3 _vertex1, _vertex2, _vertex3, _vertex4;

        // Here World to OpenGL coordinate conversions
        _vertex1.x = _pos.x;
        _vertex1.y = _pos.y;
        _vertex1.z = _pos.z;

        _vertex2.x = _pos.x;
        _vertex2.y = _pos.y + _height;
        _vertex2.z = _pos.z;

        _vertex3.x = _pos.x + _width;
        _vertex3.y = _pos.y + _height;
        _vertex3.z = _pos.z;

        _vertex4.x = _pos.x + _width;
        _vertex4.y = _pos.y;
        _vertex4.z = _pos.z;

        // For World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        /*
        HAMURCONSOLE << "Vertice1: " << _vertice1.x << " " << _vertice1.y << "\n";
        HAMURCONSOLE << "Vertice2: " << _vertice2.x << " " << _vertice2.y << "\n";
        HAMURCONSOLE << "Vertice3: " << _vertice3.x << " " << _vertice3.y << "\n";
        HAMURCONSOLE << "Vertice4: " << _vertice4.x << " " << _vertice4.y << "\n";
        */

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, _vertex1.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, _vertex1.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex3f(_vertex1.x, _vertex1.y, _vertex1.z);
            glVertex3f(_vertex2.x, _vertex2.y, _vertex2.z);
            glVertex3f(_vertex3.x, _vertex3.y, _vertex3.z);
            glVertex3f(_vertex4.x, _vertex4.y, _vertex4.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

         // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawSolidRectangle(float _x, float _y, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec2 _vertex1, _vertex2, _vertex3, _vertex4;

        // Here World to OpenGL coordinate conversions
        _vertex1.x = _x;
        _vertex1.y = _y;

        _vertex2.x = _x;
        _vertex2.y = _y + _height;

        _vertex3.x = _x + _width;
        _vertex3.y = _y + _height;

        _vertex4.x = _x + _width;
        _vertex4.y = _y;

        // For World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(_vertex1.x, _vertex1.y);
            glVertex2f(_vertex2.x, _vertex2.y);
            glVertex2f(_vertex3.x, _vertex3.y);
            glVertex2f(_vertex4.x, _vertex4.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawSolidRectangle(float _x, float _y, float _z, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec3 _vertex1, _vertex2, _vertex3, _vertex4;

        // For World to OpenGL coordinate conversions
        _vertex1.x = _x;
        _vertex1.y = _y;
        _vertex1.z = _z;

        _vertex2.x = _x;
        _vertex2.y = _y + _height;
        _vertex2.z = _z;

        _vertex3.x = _x + _width;
        _vertex3.y = _y + _height;
        _vertex3.z = _z;

        _vertex4.x = _x + _width;
        _vertex4.y = _y;
        _vertex4.z = _z;

        // Here World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, _vertex1.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, _vertex1.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(_vertex1.x, _vertex1.y, _vertex1.z);
            glVertex3f(_vertex2.x, _vertex2.y, _vertex2.z);
            glVertex3f(_vertex3.x, _vertex3.y, _vertex3.z);
            glVertex3f(_vertex4.x, _vertex4.y, _vertex4.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawSolidRectangle(const HamurVec2& _pos, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec2 _vertex1, _vertex2, _vertex3, _vertex4;

        // For World to OpenGL coordinate conversions
        _vertex1.x = _pos.x;
        _vertex1.y = _pos.y;

        _vertex2.x = _pos.x;
        _vertex2.y = _pos.y + _height;

        _vertex3.x = _pos.x + _width;
        _vertex3.y = _pos.y + _height;

        _vertex4.x = _pos.x + _width;
        _vertex4.y = _pos.y;

        // Here World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(_vertex1.x, _vertex1.y);
            glVertex2f(_vertex2.x, _vertex2.y);
            glVertex2f(_vertex3.x, _vertex3.y);
            glVertex2f(_vertex4.x, _vertex4.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawSolidRectangle(const HamurVec3& _pos, float _width, float _height, const HamurColor& _color, float _rotationAngle)
    {
        // All vertices of the Rectangle
        HamurVec3 _vertex1, _vertex2, _vertex3, _vertex4;

        // For World to OpenGL coordinate conversions
        _vertex1.x = _pos.x;
        _vertex1.y = _pos.y;
        _vertex1.z = _pos.z;

        _vertex2.x = _pos.x;
        _vertex2.y = _pos.y + _height;
        _vertex2.z = _pos.z;

        _vertex3.x = _pos.x + _width;
        _vertex3.y = _pos.y + _height;
        _vertex3.z = _pos.z;

        _vertex4.x = _pos.x + _width;
        _vertex4.y = _pos.y;
        _vertex4.z = _pos.z;

        // Here World to OpenGL coordinate conversions
        _vertex1 = HAMURTEXMR->worldToGL(_vertex1);
        _vertex2 = HAMURTEXMR->worldToGL(_vertex2);
        _vertex3 = HAMURTEXMR->worldToGL(_vertex3);
        _vertex4 = HAMURTEXMR->worldToGL(_vertex4);

        // Find the middle of vertices
        float _middleX = _vertex1.x + ((_vertex4.x - _vertex1.x) / 2);
        float _middleY = _vertex1.y + ((_vertex2.y - _vertex1.y) / 2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_middleX, _middleY, _vertex1.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_middleX, -_middleY, _vertex1.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(_vertex1.x, _vertex1.y, _vertex1.z);
            glVertex3f(_vertex2.x, _vertex2.y, _vertex2.z);
            glVertex3f(_vertex3.x, _vertex3.y, _vertex3.z);
            glVertex3f(_vertex4.x, _vertex4.y, _vertex4.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawPolygon(const HamurVec2* _verticeList, int _verticeCount, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVector;

        // Polygon's centroid calculations
        HamurVec2 _centroid;
        float _sumX = 0;
        float _sumY = 0;

        // Calculate the centroid of the Polygon
        for(int i = 0; i < _verticeCount; i++)
        {
           _sumX += _verticeList[i].x;
           _sumY += _verticeList[i].y;
        }

        // Set the centroid
        _centroid.x = _sumX / _verticeCount;
        _centroid.y = _sumY / _verticeCount;

        // World to OpenGL coordinate conversion
        _centroid = HAMURTEXMR->worldToGL(_centroid);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_centroid.x, _centroid.y, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_centroid.x, -_centroid.y, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < _verticeCount; i++)
            {
                _transformVector = HAMURTEXMR->worldToGL(_verticeList[i]);
                glVertex2f(_transformVector.x, _transformVector.y);
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    void HamurPlotter::drawPolygon(const HamurVec3* _verticeList, int _verticeCount, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVector;

        // Polygon's centroid calculations
        HamurVec3 _centroid;
        float _sumX = 0;
        float _sumY = 0;

        // Calculate the centroid of the Polygon
        for(int i = 0; i < _verticeCount; i++)
        {
            _sumX += _verticeList[i].x;
            _sumY += _verticeList[i].y;
        }

        // Set the centroid
        _centroid.x = _sumX / _verticeCount;
        _centroid.y = _sumY / _verticeCount;
        _centroid.z = _verticeList[0].z; // Same for all vertices

        // World to OpenGL coordinate conversion
        _centroid = HAMURTEXMR->worldToGL(_centroid);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_centroid.x, _centroid.y, _centroid.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_centroid.x, -_centroid.y, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

         // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < _verticeCount; i++)
            {
                _transformVector = HAMURTEXMR->worldToGL(_verticeList[i]);
                glVertex3f(_transformVector.x, _transformVector.y, _transformVector.z);
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    void HamurPlotter::drawSolidPolygon(const HamurVec2* _verticeList, int _verticeCount, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVector;

        // Polygon's centroid calculations
        HamurVec2 _centroid;
        float _sumX = 0;
        float _sumY = 0;

        // Calculate the centroid of the Polygon
        for(int i = 0; i < _verticeCount; i++)
        {
            _sumX += _verticeList[i].x;
            _sumY += _verticeList[i].y;
        }

        // Set the centroid
        _centroid.x = _sumX / _verticeCount;
        _centroid.y = _sumY / _verticeCount;

        // World to OpenGL coordinate conversion
        _centroid = HAMURTEXMR->worldToGL(_centroid);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_centroid.x, _centroid.y, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_centroid.x, -_centroid.y, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < _verticeCount; i++)
            {
                _transformVector = HAMURTEXMR->worldToGL(_verticeList[i]);
                glVertex2f(_transformVector.x, _transformVector.y);
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    void HamurPlotter::drawSolidPolygon(const HamurVec3* _verticeList, int _verticeCount, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVector;

        // Polygon's centroid calculations
        HamurVec3 _centroid;
        float _sumX = 0;
        float _sumY = 0;

        // Calculate the centroid of the Polygon
        for(int i = 0; i < _verticeCount; i++)
        {
            _sumX += _verticeList[i].x;
            _sumY += _verticeList[i].y;
        }

        // Set the centroid
        _centroid.x = _sumX / _verticeCount;
        _centroid.y = _sumY / _verticeCount;
        _centroid.z = _verticeList[0].z; // Same for all vertices

        // World to OpenGL coordinate conversion
        _centroid = HAMURTEXMR->worldToGL(_centroid);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_centroid.x, _centroid.y, _centroid.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_centroid.x, -_centroid.y, _centroid.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < _verticeCount; i++)
            {
                _transformVector = HAMURTEXMR->worldToGL(_verticeList[i]);
                glVertex3f(_transformVector.x, _transformVector.y, _transformVector.z);
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawCircle(float _xCenter, float _yCenter, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVec(_xCenter, _yCenter);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2 * pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(_angle),
                                                     _yCenter + _radius * sinf(_angle));
                glVertex2f(_transformVec.x, _transformVec.y);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawCircle(float _xCenter, float _yCenter, float _zCenter, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVec(_xCenter, _yCenter, _zCenter);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2 * pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(_angle),
                    _yCenter + _radius * sinf(_angle), _zCenter);
                glVertex3f(_transformVec.x, _transformVec.y, _transformVec.z);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawCircle(const HamurVec2& _pos, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVec(_pos.x, _pos.y);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2*pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(_angle),
                    _pos.y + _radius * sinf(_angle));
                glVertex2f(_transformVec.x, _transformVec.y);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawCircle(const HamurVec3& _pos, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVec(_pos.x, _pos.y, _pos.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2*pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(_angle),
                    _pos.y + _radius * sinf(_angle), _pos.z);
                glVertex3f(_transformVec.x, _transformVec.y, _transformVec.z);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(float _xCenter, float _yCenter, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVec(_xCenter, _yCenter);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2*pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(_angle),
                    _yCenter + _radius * sinf(_angle));
                glVertex2f(_transformVec.x, _transformVec.y);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(float _xCenter, float _yCenter, float _zCenter, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVec(_xCenter, _yCenter,_zCenter);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2*pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_xCenter + _radius * cosf(_angle),
                    _yCenter + _radius * sinf(_angle), _zCenter);
                glVertex3f(_transformVec.x, _transformVec.y, _transformVec.z);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(const HamurVec2& _pos, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVec(_pos.x, _pos.y);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2*pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(_angle),
                    _pos.y + _radius * sinf(_angle));
                glVertex2f(_transformVec.x, _transformVec.y);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawSolidCircle(const HamurVec3& _pos, float _radius, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVec(_pos.x, _pos.y,_pos.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Circle Attributes calculations
        float _angle = 0.0f;
        float _angleIncrement = pi / ((_radius / 8.0f ) + 8.0f);
        float _loopCount = 2*pi / _angleIncrement;

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i < _loopCount; i++)
            {
                _transformVec = HAMURTEXMR->worldToGL(_pos.x + _radius * cosf(_angle),
                    _pos.y + _radius * sinf(_angle), _pos.z);
                glVertex3f(_transformVec.x, _transformVec.y, _transformVec.z);
                _angle += _angleIncrement;
            }
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawLine(float _firstX, float _firstY, float _secondX, float _secondY, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVec1;
        HamurVec2 _transformVec2;

        // For finding center of the line
        HamurVec2 _lineCenter;

        // Find the center of the line
        _lineCenter.x = _firstX + _secondX / 2.0f;
        _lineCenter.y = _firstY + _secondY / 2.0f;

        // World to OpenGL coordinate conversion
        _lineCenter = HAMURTEXMR->worldToGL(_lineCenter);

        // Here World to OpenGL coordinate conversion
        _transformVec1 = HAMURTEXMR->worldToGL(_firstX, _firstY);
        _transformVec2 = HAMURTEXMR->worldToGL(_secondX, _secondY);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_lineCenter.x, _lineCenter.y, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_lineCenter.x, -_lineCenter.y, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex2f(_transformVec1.x, _transformVec1.y);
            glVertex2f(_transformVec2.x, _transformVec2.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    void HamurPlotter::drawLine(float _firstX, float _firstY, float _firstZ, float _secondX, float _secondY, float _secondZ, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVec1;
        HamurVec3 _transformVec2;

        // For finding center of the line
        HamurVec3 _lineCenter;

        // Find the center of the line
        _lineCenter.x = (_firstX + _secondX) / 2.0f;
        _lineCenter.y = (_firstY + _secondY) / 2.0f;
        _lineCenter.z = _firstZ; // Same for both

        // World to OpenGL coordinate conversion
        _lineCenter = HAMURTEXMR->worldToGL(_lineCenter);

        // Here World to OpenGL coordinate conversion
        _transformVec1 = HAMURTEXMR->worldToGL(_firstX, _firstY, _firstZ);
        _transformVec2 = HAMURTEXMR->worldToGL(_secondX, _secondY, _secondZ);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_lineCenter.x, _lineCenter.y, _lineCenter.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_lineCenter.x, -_lineCenter.y, _lineCenter.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex3f(_transformVec1.x, _transformVec1.y, _transformVec1.z);
            glVertex3f(_transformVec2.x, _transformVec2.y, _transformVec2.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    void HamurPlotter::drawLine(const HamurVec2& _pos1, const HamurVec2& _pos2, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 _transformVec1;
        HamurVec2 _transformVec2;

        // For finding center of the line
        HamurVec2 _lineCenter;

        // Find the center of the line
        _lineCenter.x = (_pos1.x + _pos2.x) / 2.0f;
        _lineCenter.y = (_pos1.y + _pos2.y) / 2.0f;

        // World to OpenGL coordinate conversion
        _lineCenter = HAMURTEXMR->worldToGL(_lineCenter);

        // Here World to OpenGL coordinate conversion
        _transformVec1 = HAMURTEXMR->worldToGL(_pos1);
        _transformVec2 = HAMURTEXMR->worldToGL(_pos2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_lineCenter.x, _lineCenter.y, 0.0f);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_lineCenter.x, -_lineCenter.y, 0.0f);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex2f(_transformVec1.x, _transformVec1.y);
            glVertex2f(_transformVec2.x, _transformVec2.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }

    void HamurPlotter::drawLine(const HamurVec3& _pos1, const HamurVec3& _pos2, const HamurColor& _color, float _rotationAngle)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 _transformVec1;
        HamurVec3 _transformVec2;

        // For finding center of the line
        HamurVec3 _lineCenter;

        // Find the center of the line
        _lineCenter.x = (_pos1.x + _pos2.x) / 2.0f;
        _lineCenter.y = (_pos1.y + _pos2.y) / 2.0f;
        _lineCenter.z = _pos1.z;

        // World to OpenGL coordinate conversion
        _lineCenter = HAMURTEXMR->worldToGL(_lineCenter);

        // Here World to OpenGL coordinate conversion
        _transformVec1 = HAMURTEXMR->worldToGL(_pos1);
        _transformVec2 = HAMURTEXMR->worldToGL(_pos2);

        // Save current matrix. 
        // Perform translation to geometric shape's middle
        // and rotate from middle around Z axis.
        // Translate back and draw the shape.
        glPushMatrix();
        glTranslatef(_lineCenter.x, _lineCenter.y, _lineCenter.z);
        glRotatef(_rotationAngle, 0, 0, 1.0f); 
        glTranslatef(-_lineCenter.x, -_lineCenter.y, _lineCenter.z);

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // For Anti-aliasing
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

        // Set color
        glColor3f(_color.R, _color.G, _color.B);

        // Drawing here
        glBegin(GL_LINE_LOOP);
            glVertex3f(_transformVec1.x, _transformVec1.y, _transformVec1.z);
            glVertex3f(_transformVec2.x, _transformVec2.y, _transformVec2.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glDisable(GL_LINE_SMOOTH);
        glEnable(GL_ALPHA_TEST);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);

        // Restore matrix
        glPopMatrix();
    }


    void HamurPlotter::drawPoint(float _pointX, float _pointY, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 transformVec;

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Drawing here
        glBegin(GL_POINTS);
            glColor3f(_color.R, _color.G, _color.B);
            transformVec = HAMURTEXMR->worldToGL(_pointX, _pointY);
            glVertex2f(transformVec.x, transformVec.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPoint(float _pointX, float _pointY, float _pointZ, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 transformVec;

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Drawing here
        glBegin(GL_POINTS);
            glColor3f(_color.R, _color.G, _color.B);
            transformVec = HAMURTEXMR->worldToGL(_pointX, _pointY, _pointZ);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPoint(const HamurVec2& _pos, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec2 transformVec;

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Drawing here
        glBegin(GL_POINTS);
            glColor3f(_color.R, _color.G, _color.B);
            transformVec = HAMURTEXMR->worldToGL(_pos);
            glVertex2f(transformVec.x, transformVec.y);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }

    void HamurPlotter::drawPoint(const HamurVec3& _pos, const HamurColor& _color)
    {
        // For World to OpenGL coordinate conversions
        HamurVec3 transformVec;

        // Disable Texture Mode to draw geometry
        glDisable(GL_TEXTURE_2D);

        // Drawing here
        glBegin(GL_POINTS);
            glColor3f(_color.R, _color.G, _color.B);
            transformVec = HAMURTEXMR->worldToGL(_pos);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
        glEnd();

        // OpenGL State Machine Reset
        glEnable(GL_TEXTURE_2D);

        // Clear color to white
        glColor3f(1.0f, 1.0f, 1.0f);
    }
}