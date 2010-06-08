#include "hamurWorld.h"


namespace hamur
{

    HamurWorld::HamurWorld()
    {
        // Empty
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


    bool HamurWorld::addObject(HamurObject *_newObject)
    {
        // Look in the map if the object is already added. If not found, then add.
        if(hasObject(_newObject->getName()))
            return false;

        worldObjects[_newObject->getName()] = _newObject;
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
            HAMURLOG->writeLogln("Error!: Can't find the object: " + _objectName);
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
}
