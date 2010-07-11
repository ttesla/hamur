#ifndef HAMUR_WORLD
#define HAMUR_WORLD

#include "../hamurSingleton.h"
#include "Box2D/Box2D.h"

#include <map>
#include <string>

using std::map;
using std::string;


namespace hamur
{

class HamurObject;

class HamurWorld : public Singleton<HamurWorld>
{
    public:

        friend Singleton<HamurWorld>;

        /**
        * Initialize Hamur World, object world.
        * @return True if initialization is successful else return False
        */
        bool Init();

        bool AddObject(HamurObject* newObject);
        bool DeleteObject(const string& objectName);
        bool HasObject(const string &objectName);

        HamurObject* GetObject(const string &_objectName);
        HamurObject* GetObjectbyIndex(int index);
        int GetWorldSize();
        b2World* Getb2World();
        void RunPhysicSimulation();

        /**
        * Clear and delete all objects in the World. 
        */
        void ClearAll();

    protected:
        HamurWorld();
        ~HamurWorld();

    private:
        void InitializePhysics();
        map<string, HamurObject*> mWorldObjects;
        int mObjectCount;
        // BOX2D Attributes
        b2Vec2 mGravity;
        bool mDoSleep;
        b2World* mWorld;
        float mTimeStep;
        int mVelocityIterations;
        int mPositionIterations;
};

} // namespace hamur


#endif // HAMURWORLD_H