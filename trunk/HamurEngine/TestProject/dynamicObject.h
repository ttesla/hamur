#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "hamur.h"

using namespace hamur;

class dynamicObject : public HamurObject
{
    public:
    dynamicObject(const string& name, const HamurVec2& pos);

    void setPhysics();
    void setColor(float x, float y, float z);
    virtual void draw();

    protected:

    private:
        HamurColor color;

};

#endif