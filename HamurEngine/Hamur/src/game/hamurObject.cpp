#include "hamurObject.h"
#include "../helper/hamurMath.h"
#include "../helper/hamurLog.h"
#include "../hamurTexMR.h"
#include "../hamurDefinitions.h"



namespace hamur
{
    
HamurObject::HamurObject(const string& name) 
    :mName(name), mActive(true), mInteractive(false)
{
    mPos.x = 0;
    mPos.y = 0;
    mPos.z = 0;
    mRotation = 0;
    HAMURLOG->writeLogln("Object created: " + mName);
}

HamurObject::HamurObject(const string& name, const string& spritePath)
    :mName(name), mActive(true), mInteractive(false)
{
    mPos.x = 0;
    mPos.y = 0;
    mPos.z = 0;
    mRotation = 0;
    SetSprite(spritePath);
    HAMURLOG->writeLogln("Object created: " + mName + ", " + spritePath);
}

HamurObject::~HamurObject()
{
    HAMURLOG->writeLogln("Object deleted: " + mName);
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
bool HamurObject::IsActive() const              { return mActive; }
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

void HamurObject::SetActive(bool active)            { mActive = active; }
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
