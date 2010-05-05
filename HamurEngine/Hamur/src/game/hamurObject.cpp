#include "hamurObject.h"


namespace hamur
{
    
    HamurObject::HamurObject(const string &_name) 
        :name(_name), active(true), interaction(false)
    {
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        rotation = 0;
    }

    HamurObject::HamurObject(const string &_name, const string &spritePath)
        :name(_name), active(true), interaction(false)
    {
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        rotation = 0;
        setSprite(spritePath);
    }

    void HamurObject::draw()
    {
        HAMURTEXMR->blitTexture(spriteID, pos, rotation);
    }

    void HamurObject::rotate(float rotationAngle)
    {
        rotation = rotationAngle;
    }

    // GETTERS & SETTERS
    string HamurObject::getName()        { return name; }
    HamurVec3 HamurObject::getPosition() { return pos; }
    float HamurObject::getRotation()     { return rotation; }
    bool HamurObject::isActive()         { return active; }
    bool HamurObject::hasInteraction()   { return interaction; }
    unsigned HamurObject::getSpriteID()  { return spriteID; }
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

    void HamurObject::setSprite(const string &_path)
    {
        spriteID = HAMURTEXMR->addTexture(_path);
    }
}
