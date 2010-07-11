#ifndef HAMUR_WORLD
#define HAMUR_WORLD

#ifdef GetObject
#undef GetObject
#endif

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
        bool HasObject(const string& objectName) const;

        HamurObject* GetObject(const string& objectName) const;
        HamurObject* GetObjectbyIndex(int index) const;
        int GetWorldSize() const;
        b2World* Getb2World() const;
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