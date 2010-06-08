#ifndef HAMUR_OBJECT
#define HAMUR_OBJECT

#include "../helper/hamurVec3.h"
#include "../helper/hamurVec2.h"

#include <vector>
#include <string>
#include "../hamurDefinitions.h"
#include "../hamurTexMR.h"

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

            HamurObject(const string &name);

            HamurObject(const string &name, const string &spritePath);

            ~HamurObject();

            /**
            * Pure virtual update function of the object. 
            * All update logic should be written here.
            */
            virtual void update() {};

            /**
            * Pure virtual draw function of the object. 
            * All drawings should be written here.
            */
            virtual void draw();

            /**
            * Set rotation angle of the object
            * @param rotationAngle Rotation value in degrees.
            */
            void rotateDegree(float rotationAngle);

            /**
            * Set rotation radian of the object
            * @param rotationRadian Rotation value in radians.
            */
            void rotateRadian(float rotatinRadian);

		   
            // GETTER & SETTERS

            /** @return Name of the object */
		    string getName();
            
            /** @return Position of the object */
		    HamurVec3 getPosition();

            /** @return Rotation angle of the object */
            float getRotation();
            
            /** @return If the object active or not */
		    bool isActive();

            /** @return If the object has interaction or not */
		    bool hasInteraction();

            /** @return Sprite ID of the object */
            unsigned int getSpriteID();
		   
            /** 
            * Set name of the object. 
            * @param _name Name of the object.
            */
		    void setName(const string& _name);
		    
            /**
            * Set position of the object.
            * @param pos Position of the object.
            */
            void setPosition(const HamurVec3& pos);

            /**
            * Set position of the object.
            * @param pos Position of the object. 
            */
            void setPosition(const HamurVec2& pos);

            /**
            * Set position of the object.
            * @param x X coordinate of the object.
            * @param y Y coordinate of the object.
            * @param z Z coordinate of the object. Default = 0.
            */
            void setPosition(float x, float y, float z = 0);

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

            void setSprite(const string &_path);

	    protected:
		    string name;      /**< Name of the object. */
		    HamurVec3 pos;    /**< Position of the object. */
            float rotation;   /**< Rotation angle of the object */
		    bool active;      /**< Object is active or not. */
		    bool interaction; /**< Object has interaction or not. */
            unsigned int spriteID; /**< Sprite ID of the game object. */

	    private:
	};

    /** Writes the Object to the stream. (pointer version) */
    inline std::ostream &operator<<(std::ostream &os, HamurObject *object)
    {
        os << object->getName() << ", " << object->getPosition() << " Active:" << object->isActive() << " Inter.:" 
           << object->hasInteraction() << " SpriteID:" << object->getSpriteID();
        
        return os;
    }

    /** Writes the Object to the stream. (reference version) */
    inline std::ostream &operator<<(std::ostream &os, HamurObject &object)
    {
        os << object.getName() << ", " << object.getPosition() << " Active:" << object.isActive() << " Inter.:" 
            << object.hasInteraction() << " SpriteID:" << object.getSpriteID();

        return os;
    }
}

#endif // HAMUR_OBJECT
