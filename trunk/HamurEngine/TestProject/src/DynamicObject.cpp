#include "dynamicObject.h"

dynamicObject::dynamicObject(const string &name, const HamurVec2& _pos):HamurObject(name)
{
    mPos.x = _pos.x;
    mPos.y = _pos.y;
    mWidth = 100;
    mHeight = 5;
    setPhysics();
}

void dynamicObject::setPhysics()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set((mPos.x + mWidth / 2) / 100.0f, (mPos.y + mHeight /2) / 100.0f);
    bodyDef.userData = this;
    //setBodyDef(bodyDef);

    mBody = HAMURWORLD->Getb2World()->CreateBody(&bodyDef);

    mBox.SetAsBox(mWidth / 200.0f, mHeight / 200.0f);
    /*
    b2Vec2 _center(0.20f, 0.20f);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.20f, 0.20f, _center, rotation);
    setShape(dynamicBox);
    */

    /*
    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(0.0f, -0.4f);
    vertices[2].Set(0.4f, -0.4f);
    vertices[3].Set(0.4, 0.0f);

    int vertexCount = 4;
    */
    

    /*
    b2Vec2 vertices[3];

    vertices[0].Set(0.0f, 0.0f);

    vertices[1].Set(1.0f, 0.0f);

    vertices[2].Set(0.0f, 1.0f);

    int32 count = 3;
    

    mBox.Set(vertices, 4);
    //setShape(dynamicBox);
    */

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &mBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution = 1.0f;
   // setFixDef(fixtureDef);

    mBody->CreateFixture(&fixtureDef);
}

void dynamicObject::setColor(float _R, float _G, float _B)
{
    color.R = _R;
    color.G = _G;
    color.B = _B;
}


void dynamicObject::Draw()
{
    HamurPlotter::drawRectangle(mPos, mWidth, mHeight, HamurColor::GREEN, mRotation);
}
