#include "hamurObject.h"
//#include "hamurWorld.h"


namespace hamur
{
    
    HamurObject::HamurObject(string _name)
    {
        name = _name;
        active = true;
        interaction = false;

        HAMURWORLD->addObject(this);
    }
    

    // GETTERS & SETTERS
    string HamurObject::getName()        { return name; }
    HamurVec3 HamurObject::getPosition() { return pos; }
    bool HamurObject::isActive()        { return active; }
    bool HamurObject::hasInteraction()   { return interaction; }
    void HamurObject::setName(const string& _name)       { name = _name; }
    void HamurObject::setPosition(const HamurVec3& _pos) { pos = _pos; }
    void HamurObject::setActive(bool _active)            { active = _active; }
    void HamurObject::setInteraction(bool _interaction)  { interaction = _interaction; }
}
