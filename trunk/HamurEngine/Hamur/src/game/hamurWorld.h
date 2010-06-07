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

            bool addObject(HamurObject* newObject);
            bool deleteObject(const string& objectName);
            bool hasObject(const string &objectName);

            HamurObject* getObject(const string &_objectName);

        protected:
            HamurWorld();

        private:
            map<string, HamurObject*> worldObjects;
    };
}


#endif // HAMURWORLD_H