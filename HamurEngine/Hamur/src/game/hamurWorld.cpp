#include "hamurWorld.h"
#include "hamurObject.h"
#include "../helper/hamurLog.h"
#include "../helper/hamurMath.h"
#include "../hamurEvent.h"
#include "../hamurDefinitions.h"


namespace hamur
{

HamurWorld::HamurWorld()
{
    mObjectCount = 0;
    InitializePhysics();
}

HamurWorld::~HamurWorld()
{
    ClearAll();
    HAMURLOG->writeTerminateLog("HamurWorld");
}

// Initialize Hamur World
bool HamurWorld::Init()
{
    HAMURLOG->writeInitLog("HamurWorld");
    return true;
}


bool HamurWorld::AddObject(HamurObject* newObject)
{
    // Look in the map if the object is already added. If not found, then add.
    if(HasObject(newObject->GetName()))
        return false;

    mWorldObjects[newObject->GetName()] = newObject;
    mObjectCount++;
    return true;
}


bool HamurWorld::DeleteObject(const string& objectName)
{
    // Look in the map if the object exists.
    map<string, HamurObject*>::iterator iter = mWorldObjects.find(objectName);

    // If found, delete it and return success.
    if(iter != mWorldObjects.end())
    {
        if(iter->second)
            delete iter->second;

        mWorldObjects.erase(iter);
        mObjectCount--;
        return true;
    }

    return false;
}


bool HamurWorld::HasObject(const string& name) const
{
    // Look in the map if the object exists.
    map<string, HamurObject*>::const_iterator iter = mWorldObjects.find(name);

    // If not found, return failure.
    if(iter == mWorldObjects.end())
        return false;

    return true;
}



HamurObject* HamurWorld::GetObject(const string& objectName) const
{
    // Look in the map if the object exists..
    map<string, HamurObject*>::const_iterator iter = mWorldObjects.find(objectName);

    // If not found, return failure.
    if(iter == mWorldObjects.end())
    {
        HAMURLOG->writeLogln("Error!: Can't find the object: " + objectName, 
            HamurLog::ALWAYS);
        return NULL;
    }

    return iter->second;
}




// Delete all objects in the Hamur World
void HamurWorld::ClearAll()
{
    map<string, HamurObject*>::iterator iter;

    for(iter = mWorldObjects.begin(); iter != mWorldObjects.end(); iter++)
    {
        if(iter->second)
            delete iter->second;
    }

    mObjectCount = 0;
    HAMURLOG->writeLogln("All world objects deleted.");
}

HamurObject* HamurWorld::GetObjectbyIndex(int index) const
{
    map<string, HamurObject*>::const_iterator iter;
    int i = 0;

    bool bFound;

    for(iter = mWorldObjects.begin(); iter != mWorldObjects.end(); iter++, i++)
    {
        if (i == index)
        {
            bFound = true;
            break;
        }
    }

    if (bFound)
        return iter->second;
    else
        return NULL;
}

int HamurWorld::GetWorldSize() const
{
    return mObjectCount;
}

b2World* HamurWorld::Getb2World() const
{
    return mWorld;
}

void HamurWorld::RunPhysicSimulation()
{
    static bool keyPressed1 = false;

    //if(HAMUREVENT->isKeyPressed(SDLK_DOWN) && !keyPressed1)
    //{

        mWorld->Step(mTimeStep, mVelocityIterations, mPositionIterations);
        mWorld->ClearForces();
        keyPressed1 = true;
    //}

    //if(! HAMUREVENT->isKeyPressed(SDLK_DOWN))
        keyPressed1 = false;

    /*
    b2Vec2 position1 = GetObject("Dynamic")->GetBody()->GetPosition();

    float32 angle1 = GetObject("Dynamic")->GetBody()->GetAngle();

    b2Vec2 position2 = GetObject("Ground")->GetBody()->GetPosition();

    float32 angle2 = GetObject("Ground")->GetBody()->GetAngle();

    b2Vec2 position3 = GetObject("Dynamic2")->GetBody()->GetPosition();

    float32 angle3 = GetObject("Dynamic2")->GetBody()->GetAngle();


    HAMURCONSOLE << GetObject("Dynamic") << "\n" << GetObject("Ground") << "\n"
    << GetObject("Dynamic2") << "\n";
    

    printf("%4.2f %4.2f %4.2f\n", position1.x, position1.y, angle1);
    printf("%4.2f %4.2f %4.2f\n", position2.x, position2.y, angle2);
    printf("%4.2f %4.2f %4.2f\n", position3.x, position3.y, angle3);
    
    GetObject("Dynamic")->SetPosition(position1.x*100, position1.y*100, 0);
    GetObject("Dynamic")->RotateRadian(angle1);

    GetObject("Ground")->SetPosition(position2.x*100, position2.y*100, 0);
    GetObject("Ground")->RotateRadian(angle2);

    GetObject("Dynamic2")->SetPosition(position3.x*100, position3.y*100, 0);
    GetObject("Dynamic2")->RotateRadian(angle3);
    */
    

    
    map<string, HamurObject*>::iterator iter;
    b2Vec2 tempVec;
    float tempAngle;

    for(iter = mWorldObjects.begin(); iter != mWorldObjects.end(); iter++)
    {
        tempVec = iter->second->GetBody()->GetPosition();
        tempAngle = iter->second->GetBody()->GetAngle();

        iter->second->SetPosition((tempVec.x - (iter->second->mWidth / 200)) * 100, (tempVec.y - (iter->second->mHeight / 200)) *100);
        iter->second->RotateRadian(-tempAngle);
    }  
}

void HamurWorld::InitializePhysics()
{
    mGravity.Set(0.0f, 0.12f);
    mDoSleep = true;
    mWorld = new b2World(mGravity, mDoSleep);
    mTimeStep = 1.0f / 60.0f;
    mVelocityIterations = 10;
    mPositionIterations = 10;
}

} // namespace hamur
