#include "dynamicObject.h"

DynamicObject::DynamicObject(const string &name, const HamurVec2& _pos):HamurObject(name)
{
    mPos.x = _pos.x;
    mPos.y = _pos.y;
    mWidth = 100;
    mHeight = 5;
//    setPhysics();
}

/*
void DynamicObject::setPhysics()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set((mPos.x + mWidth / 2) / 100.0f, (mPos.y + mHeight /2) / 100.0f);
    bodyDef.userData = this;

    mBody = HAMURWORLD->Getb2World()->CreateBody(&bodyDef);

    mBox.SetAsBox(mWidth / 200.0f, mHeight / 200.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &mBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution = 1.0f;

    mBody->CreateFixture(&fixtureDef);
}
*/

void DynamicObject::Draw()
{
    HamurPlotter::DrawRectangle(mPos, mWidth, mHeight, HamurColor::GREEN, mRotation);
}
