#include "hamurWorld.h"
#include "../helper/hamurMath.h"


namespace hamur
{

    HamurWorld::HamurWorld()
    {
        objectCount = 0;
        initializePhysics();
    }

    HamurWorld::~HamurWorld()
    {
        clearAll();
        HAMURLOG->writeTerminateLog("HamurWorld");
    }

    // Initialize Hamur World
    bool HamurWorld::init()
    {
        HAMURLOG->writeInitLog("HamurWorld");
        return true;
    }

        HAMURLOG->writeInitLog("HamurWorld");

    }



    bool HamurWorld::addObject(HamurObject *_newObject)
    {
        // Look in the map if the object is already added. If not found, then add.
        if(hasObject(_newObject->getName()))
            return false;

        worldObjects[_newObject->getName()] = _newObject;
        objectCount++;
        return true;
    }


    bool HamurWorld::deleteObject(const string& _objectName)
    {
        // Look in the map if the object exists.
        map<string, HamurObject*>::iterator iter = worldObjects.find(_objectName);

        // If found, delete it and return success.
        if(iter != worldObjects.end())
        {
            if(iter->second)
                delete iter->second;

            worldObjects.erase(iter);
            objectCount--;
            return true;
        }

        return false;
    }


    bool HamurWorld::hasObject(const string &_name)
    {
        // Look in the map if the object exists.
        map<string, HamurObject*>::iterator iter = worldObjects.find(_name);

        // If not found, return failure.
        if(iter == worldObjects.end())
            return false;

        return true;
    }


    HamurObject* HamurWorld::getObject(const string &_objectName)
    {
        // Look in the map if the object exists..
        map<string, HamurObject*>::iterator iter = worldObjects.find(_objectName);

        // If not found, return failure.
        if(iter == worldObjects.end())
        {
            HAMURLOG->writeLogln("Error!: Can't find the object: " + _objectName, 
                HamurLog::ALWAYS);
            return NULL;
        }

        return iter->second;
    }



    // Delete all objects in the Hamur World
    void HamurWorld::clearAll()
    {
        map<string, HamurObject*>::iterator iter;

        for(iter = worldObjects.begin(); iter != worldObjects.end(); iter++)
        {
            if(iter->second)
                delete iter->second;
        }

        HAMURLOG->writeLogln("All world objects deleted.");
    }
    HamurObject* HamurWorld::getObjectbyIndex(int index)
    {
        map<string, HamurObject*>::iterator iter;
        int i = 0;

        bool bFound;

        for(iter = worldObjects.begin(); iter != worldObjects.end(); iter++, i++)
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

    int HamurWorld::getWorldSize()
    {
        return objectCount;
    }

    b2World* HamurWorld::getb2World()
    {
        return world;
    }

    void HamurWorld::runPhysicSimulation()
    {
        static bool keyPressed1 = false;

        //if(HAMUREVENT->isKeyPressed(SDLK_DOWN) && !keyPressed1)
        //{

            world->Step(timeStep, velocityIterations, positionIterations);
            world->ClearForces();
            keyPressed1 = true;
        //}

        //if(! HAMUREVENT->isKeyPressed(SDLK_DOWN))
            keyPressed1 = false;

        /*
        b2Vec2 position1 = getObject("Dynamic")->getBody()->GetPosition();

        float32 angle1 = getObject("Dynamic")->getBody()->GetAngle();

        b2Vec2 position2 = getObject("Ground")->getBody()->GetPosition();

        float32 angle2 = getObject("Ground")->getBody()->GetAngle();

        b2Vec2 position3 = getObject("Dynamic2")->getBody()->GetPosition();

        float32 angle3 = getObject("Dynamic2")->getBody()->GetAngle();


        HAMURCONSOLE << getObject("Dynamic") << "\n" << getObject("Ground") << "\n"
        << getObject("Dynamic2") << "\n";
        

        printf("%4.2f %4.2f %4.2f\n", position1.x, position1.y, angle1);
        printf("%4.2f %4.2f %4.2f\n", position2.x, position2.y, angle2);
        printf("%4.2f %4.2f %4.2f\n", position3.x, position3.y, angle3);
        
        getObject("Dynamic")->setPosition(position1.x*100, position1.y*100, 0);
        getObject("Dynamic")->rotateRadian(angle1);

        getObject("Ground")->setPosition(position2.x*100, position2.y*100, 0);
        getObject("Ground")->rotateRadian(angle2);

        getObject("Dynamic2")->setPosition(position3.x*100, position3.y*100, 0);
        getObject("Dynamic2")->rotateRadian(angle3);
        */
        

        
        map<string, HamurObject*>::iterator iter;
        b2Vec2 tempVec;
        float tempAngle;

        for(iter = worldObjects.begin(); iter != worldObjects.end(); iter++)
        {
            tempVec = iter->second->getBody()->GetPosition();
            tempAngle = iter->second->getBody()->GetAngle();

            iter->second->setPosition((tempVec.x - (iter->second->width / 200)) * 100, (tempVec.y - (iter->second->height / 200)) *100);
            iter->second->rotateRadian(-tempAngle);
//             HAMURCONSOLE << "Object: " << iter->second->getName() << "  Position: " << iter->second->getPosition() <<"\n"; 
//             HAMURCONSOLE << "Box2D position: " << tempVec.x << "   " << tempVec.y << "\n";
            //HAMURCONSOLE << "Box2D Angle:" << tempAngle << "\n";
            //HAMURCONSOLE << "hamur Angle:" << HamurMath::Converter::degreeToRadian(iter->second->getRotation()) << "\n";
        //printf("%4.2f %4.2f %4.2f\n", tempVec.x, tempVec.y, tempAngle);
        }

        //HAMURCONSOLE << getObject("Dynamic") << "\n" << getObject("Ground") << "\n"
          //  << getObject("Dynamic2") << "\n";
        
    }

    void HamurWorld::initializePhysics()
    {
        gravity.Set(0.0f, 0.12f);
        doSleep = true;
        world = new b2World(gravity, doSleep);
        timeStep = 1.0f / 60.0f;
        velocityIterations = 10;
        positionIterations = 10;
    }
}
