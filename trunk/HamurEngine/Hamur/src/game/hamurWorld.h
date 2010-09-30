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

        friend class Singleton<HamurWorld>;

        /**
        * Initialize Hamur World, object world.
        * @return True if initialization is successful else return False
        */
        bool Init();

        bool AddObject(HamurObject* newObject);
        bool DeleteObject(const string& objectName);
        bool HasObject(const string& objectName) const;
        void UpdateAllObjects(float deltaTime);
        void DrawAllObjects(float deltaTime);

        HamurObject* GetHamurObject(const string& objectName) const;
        HamurObject* GetHamurObjectByIndex(int index) const;
        int GetWorldSize() const;
        b2World* GetPhysicWorld() const;
       // void RunPhysicSimulation();

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
        b2World* mPhysicWorld;
        float mTimeStep;
        int mVelocityIterations;
        int mPositionIterations;
};

} // namespace hamur


#endif // HAMURWORLD_H
