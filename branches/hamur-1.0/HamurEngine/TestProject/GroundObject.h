#ifndef GROUNDOBJECT_H
#define GROUNDOBJECT_H

#include "hamur.h"

using namespace hamur;

class GroundObject : public HamurObject
{
    public:
        GroundObject(const string& name);
        //void setPhysics();
        virtual void Draw(float deltaTime);

    protected:
        
    private:
};

#endif

