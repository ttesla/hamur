#include "hamurObject.h"
#include "../hamurTexMR.h"
#include "../helper/hamurMath.h"
#include "../helper/hamurLog.h"
#include "hamurWorld.h"
#include "../hamurDefinitions.h"


namespace hamur
{
    
HamurObject::HamurObject(const string& name) 
    :mName(name), mVisible(true), mInteractive(true)
{
    mPos.x = 0;
    mPos.y = 0;
    mPos.z = 0;
    mRotation = 0;
    HAMURWORLD->AddObject(this);
    HAMURLOG->WriteLogln("Object created: " + mName);
}

HamurObject::HamurObject(const string& name, const string& spritePath)
    :mName(name), mVisible(true), mInteractive(true)
{
    mPos.x = 0;
    mPos.y = 0;
    mPos.z = 0;
    mRotation = 0;
    SetSprite(spritePath);
    HAMURWORLD->AddObject(this);
    HAMURLOG->WriteLogln("Object created: " + mName + ", " + spritePath);
}

HamurObject::~HamurObject()
{
    HAMURLOG->WriteLogln("Object deleted: " + mName);
}

void HamurObject::Draw()
{
    HAMURTEXMR->BlitTexture(mSpriteID, mPos, mRotation);
}

void HamurObject::RotateDegree(float rotationAngle)
{
    mRotation = rotationAngle;
}

void HamurObject::RotateRadian(float rotationRadian)
{
    mRotation = HamurMath::Converter::RadianToDegree(rotationRadian);
}

// GETTERS & SETTERS
string HamurObject::GetName() const             { return mName; }
HamurVec3 HamurObject::GetPosition() const      { return mPos; }
float HamurObject::GetRotation() const          { return mRotation; }
bool HamurObject::IsActive() const              { return mVisible; }
bool HamurObject::IsInteractive() const         { return mInteractive; }
unsigned HamurObject::GetSpriteID() const       { return mSpriteID; }
void HamurObject::SetName(const string& name)   { mName = name; }


void HamurObject::SetPosition(const HamurVec3& pos)
{
    mPos = pos;
}

void HamurObject::SetPosition(const HamurVec2& pos)
{
    mPos.x = pos.x;
    mPos.y = pos.y;
    mPos.z = 0;
}

void HamurObject::SetPosition(float x, float y, float z)
{
    mPos.x = x;
    mPos.y = y;
    mPos.z = z;
}

void HamurObject::SetVisible(bool visible)          { mVisible = visible; }
void HamurObject::SetInteraction(bool interactive)  { mInteractive = interactive; }

void HamurObject::SetSprite(const string& path)
{
    mSpriteID = HAMURTEXMR->AddTexture(path);
}

b2Body* HamurObject::GetBody() const
{
    return mBody;
}

b2BodyDef HamurObject::GetBodyDef() const
{
    return mBodyDef;
}

void HamurObject::SetBodyDef(const b2BodyDef& bodyDef)
{
    mBodyDef = bodyDef;
}

b2PolygonShape HamurObject::GetPolygonShape() const
{
    return mBox;
}

void HamurObject::SetPolygonShape(const b2PolygonShape& box)
{
    mBox = box;
}

b2FixtureDef HamurObject::GetFixDef() const
{
    return mFixtureDef;
}

void HamurObject::SetFixDef(const b2FixtureDef& fixDef)
{
    mFixtureDef = fixDef;
}

} // namespace hamur
