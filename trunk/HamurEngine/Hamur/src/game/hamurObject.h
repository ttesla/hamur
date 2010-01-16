#ifndef HAMUR_OBJECT
#define HAMUR_OBJECT

#include "../helper/hamurVec3.h"

#include <vector>
#include <string>
#include "../hamurDefinitions.h"

#include "hamurWorld.h"


using std::vector;
using std::string;


namespace hamur
{
    /**
    * Hamur Object base class.
    * Everything in the Hamur game environment is a Hamur object. 
    */
	class HamurObject
	{
	    public:

            HamurObject(string _name);

            /**
            * Pure virtual update function of the object. 
            * All update logic should be written here.
            */
		    virtual void update() = 0;

            /**
            * Pure virtual draw function of the object. 
            * All drawings should be written here.
            */
		    virtual void draw() = 0;

		   
            // GETTER & SETTERS

            /** @return Name of the object */
		    string getName();
            
            /** @return Position of the object */
		    HamurVec3 getPosition();
            
            /** @return If the object active or not */
		    bool isActive();

            /** @return If the object has interaction or not */
		    bool hasInteraction();
		   
            /** 
            * Set name of the object. 
            * @param _name Name of the object.
            */
		    void setName(const string& _name);
		    
            /**
            * Set position of the object.
            * @param _pos Position of the object.
            */
            void setPosition(const HamurVec3& _pos);

            /**
            * Set if the object is active or not.
            * @param _active True or False
            */
		    void setActive(bool _active);

            /**
            * Set if the object has interaction or not.
            * @param _interaction True or False
            */
		    void setInteraction(bool _interaction);

	    protected:
		    string name;      /**< Name of the object. */
		    HamurVec3 pos;    /**< Position of the object. */
		    bool active;      /**< Object is active or not. */
		    bool interaction; /**< Object has interaction or not. */

	    private:
	};
}

#endif // HAMUR_OBJECT
