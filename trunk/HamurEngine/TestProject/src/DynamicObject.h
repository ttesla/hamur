#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "hamur.h"

using namespace hamur;

class DynamicObject : public HamurObject
{
    public:
    DynamicObject(const string& name, const HamurVec2& pos);

    //void setPhysics();
    virtual void Draw();

    protected:

    private:

};

#endif