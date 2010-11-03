#include "hamurPlotter.h"

#include "hamurVec2.h"
#include "hamurVec3.h"
#include "../hamurOpenGL.h"
#include "../hamurTextureManager.h"
#include "hamurConsole.h"
#include "../hamurDefinitions.h"
//#include "hamurColor.h"
#include "hamurMath.h"

namespace hamur
{

void HamurPlotter::DrawRectangle(float x, float y, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec2 vertex1, vertex2, vertex3, vertex4;

	// For World to OpenGL coordinate conversions 
	vertex1.x = x - width / 2;
	vertex1.y = y - height / 2;

	vertex2.x = x - width / 2;
	vertex2.y = y + height / 2;

	vertex3.x = x + width / 2;
	vertex3.y = y + height / 2;

	vertex4.x = x + width / 2;
	vertex4.y = y - height / 2;

    // Here World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix.
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex2f(vertex1.x, vertex1.y);
        glVertex2f(vertex2.x, vertex2.y);
        glVertex2f(vertex3.x, vertex3.y);
        glVertex2f(vertex4.x, vertex4.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawRectangle(float x, float y, float z, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec3 vertex1, vertex2, vertex3, vertex4;

	// For World to OpenGL coordinate conversions 
	vertex1.x = x - width / 2;
	vertex1.y = y - height / 2;
	vertex1.z = z;

	vertex2.x = x - width / 2;
	vertex2.y = y + height / 2;
	vertex2.z = z;

	vertex3.x = x + width / 2;
	vertex3.y = y + height / 2;
	vertex3.z = z;

	vertex4.x = x + width / 2;
	vertex4.y = y - height / 2;
	vertex4.z = z;

    // Here World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix.
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, vertex1.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, vertex1.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex3f(vertex1.x, vertex1.y, vertex1.z);
        glVertex3f(vertex2.x, vertex2.y, vertex2.z);
        glVertex3f(vertex3.x, vertex3.y, vertex3.z);
        glVertex3f(vertex4.x, vertex4.y, vertex4.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawRectangle(const HamurVec2& pos, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec2 vertex1, vertex2, vertex3, vertex4;

    // Here World to OpenGL coordinate conversions
    vertex1.x = pos.x - width / 2;
    vertex1.y = pos.y - height / 2;

    vertex2.x = pos.x - width / 2;
    vertex2.y = pos.y + height / 2;

    vertex3.x = pos.x + width / 2;
    vertex3.y = pos.y + height / 2;

    vertex4.x = pos.x + width / 2;
    vertex4.y = pos.y - height / 2;

    // For World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex2f(vertex1.x, vertex1.y);
        glVertex2f(vertex2.x, vertex2.y);
        glVertex2f(vertex3.x, vertex3.y);
        glVertex2f(vertex4.x, vertex4.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawRectangle(const HamurVec3& pos, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec3 vertex1, vertex2, vertex3, vertex4;

	// Here World to OpenGL coordinate conversions
	vertex1.x = pos.x - width / 2;
	vertex1.y = pos.y - height / 2;
	vertex1.z = pos.z;

	vertex2.x = pos.x - width / 2;
	vertex2.y = pos.y + height / 2;
	vertex2.z = pos.z;

	vertex3.x = pos.x + width / 2;
	vertex3.y = pos.y + height / 2;
	vertex3.z = pos.z;

	vertex4.x = pos.x + width / 2;
	vertex4.y = pos.y - height / 2;
	vertex4.z = pos.z;

    // For World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, vertex1.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, vertex1.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex3f(vertex1.x, vertex1.y, vertex1.z);
        glVertex3f(vertex2.x, vertex2.y, vertex2.z);
        glVertex3f(vertex3.x, vertex3.y, vertex3.z);
        glVertex3f(vertex4.x, vertex4.y, vertex4.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

     // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawSolidRectangle(float x, float y, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec2 vertex1, vertex2, vertex3, vertex4;

	// For World to OpenGL coordinate conversions 
	vertex1.x = x - width / 2;
	vertex1.y = y - height / 2;

	vertex2.x = x - width / 2;
	vertex2.y = y + height / 2;

	vertex3.x = x + width / 2;
	vertex3.y = y + height / 2;

	vertex4.x = x + width / 2;
	vertex4.y = y - height / 2;

    // For World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(vertex1.x, vertex1.y);
        glVertex2f(vertex2.x, vertex2.y);
        glVertex2f(vertex3.x, vertex3.y);
        glVertex2f(vertex4.x, vertex4.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawSolidRectangle(float x, float y, float z, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec3 vertex1, vertex2, vertex3, vertex4;

	// For World to OpenGL coordinate conversions 
	vertex1.x = x - width / 2;
	vertex1.y = y - height / 2;
	vertex1.z = z;

	vertex2.x = x - width / 2;
	vertex2.y = y + height / 2;
	vertex2.z = z;

	vertex3.x = x + width / 2;
	vertex3.y = y + height / 2;
	vertex3.z = z;

	vertex4.x = x + width / 2;
	vertex4.y = y - height / 2;
	vertex4.z = z;

    // Here World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, vertex1.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, vertex1.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(vertex1.x, vertex1.y, vertex1.z);
        glVertex3f(vertex2.x, vertex2.y, vertex2.z);
        glVertex3f(vertex3.x, vertex3.y, vertex3.z);
        glVertex3f(vertex4.x, vertex4.y, vertex4.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawSolidRectangle(const HamurVec2& pos, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec2 vertex1, vertex2, vertex3, vertex4;

	// Here World to OpenGL coordinate conversions
	vertex1.x = pos.x - width / 2;
	vertex1.y = pos.y - height / 2;

	vertex2.x = pos.x - width / 2;
	vertex2.y = pos.y + height / 2;

	vertex3.x = pos.x + width / 2;
	vertex3.y = pos.y + height / 2;

	vertex4.x = pos.x + width / 2;
	vertex4.y = pos.y - height / 2;

    // Here World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(vertex1.x, vertex1.y);
        glVertex2f(vertex2.x, vertex2.y);
        glVertex2f(vertex3.x, vertex3.y);
        glVertex2f(vertex4.x, vertex4.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawSolidRectangle(const HamurVec3& pos, float width, float height, const HamurColor& color, float rotationAngle)
{
    // All vertices of the Rectangle
    HamurVec3 vertex1, vertex2, vertex3, vertex4;

	// Here World to OpenGL coordinate conversions
	vertex1.x = pos.x - width / 2;
	vertex1.y = pos.y - height / 2;
	vertex1.z = pos.z;

	vertex2.x = pos.x - width / 2;
	vertex2.y = pos.y + height / 2;
	vertex2.z = pos.z;

	vertex3.x = pos.x + width / 2;
	vertex3.y = pos.y + height / 2;
	vertex3.z = pos.z;

	vertex4.x = pos.x + width / 2;
	vertex4.y = pos.y - height / 2;
	vertex4.z = pos.z;

    // Here World to OpenGL coordinate conversions
    vertex1 = HAMURTEXMR->WorldToGL(vertex1);
    vertex2 = HAMURTEXMR->WorldToGL(vertex2);
    vertex3 = HAMURTEXMR->WorldToGL(vertex3);
    vertex4 = HAMURTEXMR->WorldToGL(vertex4);

    // Find the middle of vertices
    float middleX = vertex1.x + ((vertex4.x - vertex1.x) / 2);
    float middleY = vertex1.y + ((vertex2.y - vertex1.y) / 2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(middleX, middleY, vertex1.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-middleX, -middleY, vertex1.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(vertex1.x, vertex1.y, vertex1.z);
        glVertex3f(vertex2.x, vertex2.y, vertex2.z);
        glVertex3f(vertex3.x, vertex3.y, vertex3.z);
        glVertex3f(vertex4.x, vertex4.y, vertex4.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawPolygon(const HamurVec2* verticeList, int verticeCount, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVector;

    // Polygon's centroid calculations
    HamurVec2 centroid;
    float sumX = 0;
    float sumY = 0;

    // Calculate the centroid of the Polygon
    for(int i = 0; i < verticeCount; i++)
    {
       sumX += verticeList[i].x;
       sumY += verticeList[i].y;
    }

    // Set the centroid
    centroid.x = sumX / verticeCount;
    centroid.y = sumY / verticeCount;

    // World to OpenGL coordinate conversion
    centroid = HAMURTEXMR->WorldToGL(centroid);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(centroid.x, centroid.y, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-centroid.x, -centroid.y, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < verticeCount; i++)
        {
            transformVector = HAMURTEXMR->WorldToGL(verticeList[i]);
            glVertex2f(transformVector.x, transformVector.y);
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);
 
    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}

void HamurPlotter::DrawPolygon(const HamurVec3* verticeList, int verticeCount, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVector;

    // Polygon's centroid calculations
    HamurVec3 centroid;
    float sumX = 0;
    float sumY = 0;

    // Calculate the centroid of the Polygon
    for(int i = 0; i < verticeCount; i++)
    {
        sumX += verticeList[i].x;
        sumY += verticeList[i].y;
    }

    // Set the centroid
    centroid.x = sumX / verticeCount;
    centroid.y = sumY / verticeCount;
    centroid.z = verticeList[0].z; // Same for all vertices

    // World to OpenGL coordinate conversion
    centroid = HAMURTEXMR->WorldToGL(centroid);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(centroid.x, centroid.y, centroid.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-centroid.x, -centroid.y, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

     // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < verticeCount; i++)
        {
            transformVector = HAMURTEXMR->WorldToGL(verticeList[i]);
            glVertex3f(transformVector.x, transformVector.y, transformVector.z);
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}

void HamurPlotter::DrawSolidPolygon(const HamurVec2* verticeList, int verticeCount, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVector;

    // Polygon's centroid calculations
    HamurVec2 centroid;
    float sumX = 0;
    float sumY = 0;

    // Calculate the centroid of the Polygon
    for(int i = 0; i < verticeCount; i++)
    {
        sumX += verticeList[i].x;
        sumY += verticeList[i].y;
    }

    // Set the centroid
    centroid.x = sumX / verticeCount;
    centroid.y = sumY / verticeCount;

    // World to OpenGL coordinate conversion
    centroid = HAMURTEXMR->WorldToGL(centroid);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(centroid.x, centroid.y, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-centroid.x, -centroid.y, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < verticeCount; i++)
        {
            transformVector = HAMURTEXMR->WorldToGL(verticeList[i]);
            glVertex2f(transformVector.x, transformVector.y);
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}

void HamurPlotter::DrawSolidPolygon(const HamurVec3* verticeList, int verticeCount, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVector;

    // Polygon's centroid calculations
    HamurVec3 centroid;
    float sumX = 0;
    float sumY = 0;

    // Calculate the centroid of the Polygon
    for(int i = 0; i < verticeCount; i++)
    {
        sumX += verticeList[i].x;
        sumY += verticeList[i].y;
    }

    // Set the centroid
    centroid.x = sumX / verticeCount;
    centroid.y = sumY / verticeCount;
    centroid.z = verticeList[0].z; // Same for all vertices

    // World to OpenGL coordinate conversion
    centroid = HAMURTEXMR->WorldToGL(centroid);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(centroid.x, centroid.y, centroid.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-centroid.x, -centroid.y, centroid.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < verticeCount; i++)
        {
            transformVector = HAMURTEXMR->WorldToGL(verticeList[i]);
            glVertex3f(transformVector.x, transformVector.y, transformVector.z);
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawCircle(float xCenter, float yCenter, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec(xCenter, yCenter);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2 * PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(xCenter + radius * cosf(angle),
                                                 yCenter + radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawCircle(float xCenter, float yCenter, float zCenter, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec(xCenter, yCenter, zCenter);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2 * PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(xCenter + radius * cosf(angle),
                yCenter + radius * sinf(angle), zCenter);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawCircle(const HamurVec2& pos, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec(pos.x, pos.y);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2*PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(pos.x + radius * cosf(angle),
                pos.y + radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawCircle(const HamurVec3& pos, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec(pos.x, pos.y, pos.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2*PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(pos.x + radius * cosf(angle),
                pos.y + radius * sinf(angle), pos.z);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);
   
    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawSolidCircle(float xCenter, float yCenter, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec(xCenter, yCenter);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2*PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(xCenter + radius * cosf(angle),
                yCenter + radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawSolidCircle(float xCenter, float yCenter, float zCenter, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec(xCenter, yCenter,zCenter);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2*PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(xCenter + radius * cosf(angle),
                yCenter + radius * sinf(angle), zCenter);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawSolidCircle(const HamurVec2& pos, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec(pos.x, pos.y);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2*PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(pos.x + radius * cosf(angle),
                pos.y + radius * sinf(angle));
            glVertex2f(transformVec.x, transformVec.y);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawSolidCircle(const HamurVec3& pos, float radius, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec(pos.x, pos.y,pos.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Circle Attributes calculations
    float angle = 0.0f;
    float angleIncrement = PI / ((radius / 8.0f ) + 8.0f);
    float loopCount = 2*PI / angleIncrement;

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < loopCount; i++)
        {
            transformVec = HAMURTEXMR->WorldToGL(pos.x + radius * cosf(angle),
                pos.y + radius * sinf(angle), pos.z);
            glVertex3f(transformVec.x, transformVec.y, transformVec.z);
            angle += angleIncrement;
        }
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawLine(float firstX, float firstY, float secondX, float secondY, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec1;
    HamurVec2 transformVec2;

    // For finding center of the line
    HamurVec2 lineCenter;

    // Find the center of the line
    lineCenter.x = firstX + secondX / 2.0f;
    lineCenter.y = firstY + secondY / 2.0f;

    // World to OpenGL coordinate conversion
    lineCenter = HAMURTEXMR->WorldToGL(lineCenter);

    // Here World to OpenGL coordinate conversion
    transformVec1 = HAMURTEXMR->WorldToGL(firstX, firstY);
    transformVec2 = HAMURTEXMR->WorldToGL(secondX, secondY);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(lineCenter.x, lineCenter.y, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-lineCenter.x, -lineCenter.y, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex2f(transformVec1.x, transformVec1.y);
        glVertex2f(transformVec2.x, transformVec2.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}

void HamurPlotter::DrawLine(float firstX, float firstY, float firstZ, float secondX, float secondY, float secondZ, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec1;
    HamurVec3 transformVec2;

    // For finding center of the line
    HamurVec3 lineCenter;

    // Find the center of the line
    lineCenter.x = (firstX + secondX) / 2.0f;
    lineCenter.y = (firstY + secondY) / 2.0f;
    lineCenter.z = firstZ; // Same for both

    // World to OpenGL coordinate conversion
    lineCenter = HAMURTEXMR->WorldToGL(lineCenter);

    // Here World to OpenGL coordinate conversion
    transformVec1 = HAMURTEXMR->WorldToGL(firstX, firstY, firstZ);
    transformVec2 = HAMURTEXMR->WorldToGL(secondX, secondY, secondZ);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(lineCenter.x, lineCenter.y, lineCenter.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-lineCenter.x, -lineCenter.y, lineCenter.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex3f(transformVec1.x, transformVec1.y, transformVec1.z);
        glVertex3f(transformVec2.x, transformVec2.y, transformVec2.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}

void HamurPlotter::DrawLine(const HamurVec2& pos1, const HamurVec2& pos2, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec1;
    HamurVec2 transformVec2;

    // For finding center of the line
    HamurVec2 lineCenter;

    // Find the center of the line
    lineCenter.x = (pos1.x + pos2.x) / 2.0f;
    lineCenter.y = (pos1.y + pos2.y) / 2.0f;

    // World to OpenGL coordinate conversion
    lineCenter = HAMURTEXMR->WorldToGL(lineCenter);

    // Here World to OpenGL coordinate conversion
    transformVec1 = HAMURTEXMR->WorldToGL(pos1);
    transformVec2 = HAMURTEXMR->WorldToGL(pos2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(lineCenter.x, lineCenter.y, 0.0f);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-lineCenter.x, -lineCenter.y, 0.0f);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex2f(transformVec1.x, transformVec1.y);
        glVertex2f(transformVec2.x, transformVec2.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}

void HamurPlotter::DrawLine(const HamurVec3& pos1, const HamurVec3& pos2, const HamurColor& color, float rotationAngle)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec1;
    HamurVec3 transformVec2;

    // For finding center of the line
    HamurVec3 lineCenter;

    // Find the center of the line
    lineCenter.x = (pos1.x + pos2.x) / 2.0f;
    lineCenter.y = (pos1.y + pos2.y) / 2.0f;
    lineCenter.z = pos1.z;

    // World to OpenGL coordinate conversion
    lineCenter = HAMURTEXMR->WorldToGL(lineCenter);

    // Here World to OpenGL coordinate conversion
    transformVec1 = HAMURTEXMR->WorldToGL(pos1);
    transformVec2 = HAMURTEXMR->WorldToGL(pos2);

    // Save current matrix. 
    // Perform translation to geometric shape's middle
    // and rotate from middle around Z axis.
    // Translate back and draw the shape.
    glPushMatrix();
    glTranslatef(lineCenter.x, lineCenter.y, lineCenter.z);
    glRotatef(rotationAngle, 0, 0, 1.0f); 
    glTranslatef(-lineCenter.x, -lineCenter.y, lineCenter.z);

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // For Anti-aliasing
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Set color
    glColor3f(color.R, color.G, color.B);

    // Drawing here
    glBegin(GL_LINE_LOOP);
        glVertex3f(transformVec1.x, transformVec1.y, transformVec1.z);
        glVertex3f(transformVec2.x, transformVec2.y, transformVec2.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Restore matrix
    glPopMatrix();
}


void HamurPlotter::DrawPoint(float pointX, float pointY, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec;

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Drawing here
    glBegin(GL_POINTS);
        glColor3f(color.R, color.G, color.B);
        transformVec = HAMURTEXMR->WorldToGL(pointX, pointY);
        glVertex2f(transformVec.x, transformVec.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawPoint(float pointX, float pointY, float pointZ, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec;

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Drawing here
    glBegin(GL_POINTS);
        glColor3f(color.R, color.G, color.B);
        transformVec = HAMURTEXMR->WorldToGL(pointX, pointY, pointZ);
        glVertex3f(transformVec.x, transformVec.y, transformVec.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawPoint(const HamurVec2& pos, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec2 transformVec;

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Drawing here
    glBegin(GL_POINTS);
        glColor3f(color.R, color.G, color.B);
        transformVec = HAMURTEXMR->WorldToGL(pos);
        glVertex2f(transformVec.x, transformVec.y);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

void HamurPlotter::DrawPoint(const HamurVec3& pos, const HamurColor& color)
{
    // For World to OpenGL coordinate conversions
    HamurVec3 transformVec;

    // Disable Texture Mode to draw geometry
    glDisable(GL_TEXTURE_2D);

    // Drawing here
    glBegin(GL_POINTS);
        glColor3f(color.R, color.G, color.B);
        transformVec = HAMURTEXMR->WorldToGL(pos);
        glVertex3f(transformVec.x, transformVec.y, transformVec.z);
    glEnd();

    // OpenGL State Machine Reset
    glEnable(GL_TEXTURE_2D);

    // Clear color to white
    glColor3f(1.0f, 1.0f, 1.0f);
}

} // namespace hamur