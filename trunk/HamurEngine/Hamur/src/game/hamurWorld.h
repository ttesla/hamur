#ifndef HAMUR_WORLD
#define HAMUR_WORLD

#include "../hamurSingleton.h"
#include "../helper/hamurLog.h"
#include "hamurObject.h"
#include <map>


using std::map;


namespace hamur
{
    class HamurWorld : public Singleton<HamurWorld>
    {
        public:

            friend Singleton<HamurWorld>;

            bool addObject(HamurObject* _newObject);
            bool removeObject(HamurObject* _givenObject);
            bool hasObject(const string &_name);

            HamurObject* getObject(const string &_objectName);

        protected:

        private:
            map<string, HamurObject*> worldObjects;
    };
}


#endif // HAMURWORLD_H