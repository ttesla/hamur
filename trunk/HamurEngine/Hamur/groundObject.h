#ifndef GROUNDOBJECT_H
#define GROUNDOBJECT_H

#include "src/hamur.h"

using namespace hamur;

class groundObject : public HamurObject
{
    public:
        groundObject(const string& name);
        void setPhysics();
        virtual void draw();

    protected:
        
    private:
};

#endif

