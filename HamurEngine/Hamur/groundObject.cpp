#include "groundObject.h"


groundObject::groundObject(const string &name):HamurObject(name)
{
    pos.x = 2.0f;
    pos.y = 500.0f;
    pos.z = 0;
    width = 796;
    height = 98;
    setPhysics();
}

void groundObject::setPhysics()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set((pos.x + width / 2) / 100.0f, (pos.y + height /2) / 100.0f);
    groundBodyDef.userData = this;
    setBodyDef(groundBodyDef);
    
    
   // b2Vec2 _center(3.5f, 0.25f);

    box.SetAsBox(width / 200.0f, height / 200.0f);
    //setShape(box);
    
    

    /*
    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, height / 100.0f);
    vertices[1].Set(width / 100.0f, height / 100.0f);
    vertices[2].Set(width / 100.0f, 0.0f);
    vertices[3].Set(0.0f, 0.0f);

    int vertexCount = 4;

    b2PolygonShape groundBox;
    groundBox.Set(vertices, 4);
    setShape(groundBox);
    */
    

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    setFixDef(fixtureDef);

    body = HAMURWORLD->getb2World()->CreateBody(&bodyDef);
    body->CreateFixture(&fixtureDef);
}

void groundObject::draw()
{

    /*
    HAMURCONSOLE << "Vertice1: " << box.GetVertex(0).x << "," << box.GetVertex(0).y << "\n"
        << "Vertice2: " << box.GetVertex(1).x << "," << box.GetVertex(1).y << "\n"
        << "Vertice3: " << box.GetVertex(2).x << "," << box.GetVertex(2).y << "\n"
        << "Vertice4: " << box.GetVertex(3).x << "," << box.GetVertex(3).y << "\n\n\n";

    HAMURCONSOLE << "POS: " << pos << "\n";
    */

    //HamurVec3 temp(body->GetPosition().x, body->GetPosition().y, 0.0f);
    //HAMURCONSOLE << "BODY POS: " << temp << "\n";
    HamurPlotter::drawSolidRectangle(pos, width, height, HamurColor::GREY);
}