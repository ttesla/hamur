#include "groundObject.h"


groundObject::groundObject(const string &name):HamurObject(name)
{
    mPos.x = 2.0f;
    mPos.y = 500.0f;
    mPos.z = 0;
    mWidth = 796;
    mHeight = 98;
    setPhysics();
}

void groundObject::setPhysics()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set((mPos.x + mWidth / 2) / 100.0f, (mPos.y + mHeight /2) / 100.0f);
    groundBodyDef.userData = this;
    SetBodyDef(groundBodyDef);
    
    
   // b2Vec2 _center(3.5f, 0.25f);

    mBox.SetAsBox(mWidth / 200.0f, mHeight / 200.0f);
    //setShape(mBox);
    
    

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
    fixtureDef.shape = &mBox;
    SetFixDef(fixtureDef);

    mBody = HAMURWORLD->Getb2World()->CreateBody(&mBodyDef);
    mBody->CreateFixture(&fixtureDef);
}

void groundObject::Draw()
{

    /*
    HAMURCONSOLE << "Vertice1: " << mBox.GetVertex(0).x << "," << mBox.GetVertex(0).y << "\n"
        << "Vertice2: " << mBox.GetVertex(1).x << "," << mBox.GetVertex(1).y << "\n"
        << "Vertice3: " << mBox.GetVertex(2).x << "," << mBox.GetVertex(2).y << "\n"
        << "Vertice4: " << mBox.GetVertex(3).x << "," << mBox.GetVertex(3).y << "\n\n\n";

    HAMURCONSOLE << "POS: " << pos << "\n";
    */

    //HamurVec3 temp(body->GetPosition().x, body->GetPosition().y, 0.0f);
    //HAMURCONSOLE << "BODY POS: " << temp << "\n";
    HamurPlotter::drawSolidRectangle(mPos, mWidth, mHeight, HamurColor::GREY);
}