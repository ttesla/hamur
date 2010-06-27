#ifndef HAMUR_WORLD
#define HAMUR_WORLD

#include "../hamurSingleton.h"
#include "../helper/hamurLog.h"
#include "hamurObject.h"
#include "Box2D/Box2D.h"
#include <map>
#include <string>

// KALDIR
#include "../hamurEvent.h"
#include "../hamurDefinitions.h"
// KALDIR


using std::map;
using std::string;


namespace hamur
{
    class HamurWorld : public Singleton<HamurWorld>
    {
        public:

            friend Singleton<HamurWorld>;

            /**
            * Initialize Hamur World, object world.
            * @return True if initialization is successful else return False
            */
            bool init();

            bool addObject(HamurObject* newObject);
            bool deleteObject(const string& objectName);
            bool hasObject(const string &objectName);

            HamurObject* getObject(const string &_objectName);
            HamurObject* getObjectbyIndex(int index);
            int getWorldSize();
            b2World* getb2World();
            void runPhysicSimulation();

            /**
            * Clear and delete all objects in the World. 
            */
            void clearAll();

        protected:
            HamurWorld();
            ~HamurWorld();

        private:
            void initializePhysics();
            map<string, HamurObject*> worldObjects;
            int objectCount;
            // BOX2D Attributes
            b2Vec2 gravity;
            bool doSleep;
            b2World* world;
            float32 timeStep;
            int32 velocityIterations;
            int32 positionIterations;
    };
}


#endif // HAMURWORLD_H