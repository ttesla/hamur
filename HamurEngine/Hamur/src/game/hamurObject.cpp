#include "hamurObject.h"
#include "hamurWorld.h"


namespace hamur
{
    
    HamurObject::HamurObject(string _name)
    {
        name = _name;
        active = true;
        interaction = false;

        HAMURWORLD->addObject(this);
    }

    void HamurObject::draw()
    {
        HAMURTEXMR->blitTexture(spriteID, pos.x, pos.y, pos.z);
    }
    

    // GETTERS & SETTERS
    string HamurObject::getName()        { return name; }
    HamurVec3 HamurObject::getPosition() { return pos; }
    bool HamurObject::isActive()        { return active; }
    bool HamurObject::hasInteraction()   { return interaction; }
    unsigned HamurObject::getSpriteID() { return spriteID; }
    void HamurObject::setName(const string& _name)       { name = _name; }


    void HamurObject::setPosition(const HamurVec3& _pos)
    {
        pos = _pos;
    }

    void HamurObject::setPosition(float _x, float _y, float _z)
    {
        pos.x = _x;
        pos.y = _y;
        pos.z = _z;
    }

    void HamurObject::setActive(bool _active)            { active = _active; }
    void HamurObject::setInteraction(bool _interaction)  { interaction = _interaction; }

    void HamurObject::setSprite(string _path)
    {
        spriteID = HAMURTEXMR->addTexture(_path);
    }
}
