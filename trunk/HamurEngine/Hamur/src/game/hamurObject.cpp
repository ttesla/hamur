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
float HamurObject::GetWidth() const             { return mWidth;}
float HamurObject::GetHeight() const            { return mHeight;}
void HamurObject::SetName(const string& name)   { mName   = name;  }
void HamurObject::SetWidth(float width)         { mWidth  = width; }
void HamurObject::SetHeight(float height)       { mHeight = height;}


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



} // namespace hamur
