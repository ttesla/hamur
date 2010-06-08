#ifndef HAMUR_WORLD
#define HAMUR_WORLD

#include "../hamurSingleton.h"
#include "../helper/hamurLog.h"
#include "hamurObject.h"
#include <map>
#include <string>

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

            /**
            * Clear and delete all objects in the World. 
            */
            void clearAll();

        protected:
            HamurWorld();
            ~HamurWorld();

        private:
            map<string, HamurObject*> worldObjects;
    };
}


#endif // HAMURWORLD_H