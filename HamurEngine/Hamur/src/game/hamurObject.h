#ifndef HAMUR_OBJECT
#define HAMUR_OBJECT

#include "Box2D/Box2D.h"
#include "../helper/hamurVec3.h"
#include "../helper/hamurVec2.h"

#include <string>

using std::string;


namespace hamur
{

// Forward declerations
class HamurTexMR;

enum bodyType
{
    StaticBody = 0,
    KinematicBody,
    DynamicBody,
};

/**
* Hamur Object base class.
* Everything in the Hamur game environment is a Hamur object. 
*/
class HamurObject
{
    public:

        HamurObject(const string& name);

        HamurObject(const string& name, const string& spritePath);

        ~HamurObject();

        /**
        * update function of the object. 
        * All update logic should be written here.
        */
        virtual void Update() {};

        /**
        * draw function of the object. 
        * All drawings should be written here.
        */
        virtual void Draw();

        /**
        * Set rotation angle of the object
        * @param rotationAngle Rotation value in degrees.
        */
        void RotateDegree(float rotationAngle);

        /**
        * Set rotation radian of the object
        * @param rotationRadian Rotation value in radians.
        */
        void RotateRadian(float rotationRadian);

	   
        // GETTER & SETTERS

        /** @return Name of the object */
	    string GetName() const;
        
        /** @return Position of the object */
	    HamurVec3 GetPosition() const;

        /** @return Rotation angle of the object */
        float GetRotation() const;
        
        /** @return If the object active or not */
	    bool IsActive() const;

        /** @return If the object has interaction or not */
	    bool IsInteractive() const;

        /** @return Sprite ID of the object */
        unsigned int GetSpriteID() const;
	   
        /** 
        * Set name of the object. 
        * @param name Name of the object.
        */
	    void SetName(const string& name);
	    
        /**
        * Set position of the object.
        * @param pos Position of the object.
        */
        void SetPosition(const HamurVec3& pos);

        /**
        * Set position of the object.
        * @param pos Position of the object. 
        */
        void SetPosition(const HamurVec2& pos);

        /**
        * Set position of the object.
        * @param x X coordinate of the object.
        * @param y Y coordinate of the object.
        * @param z Z coordinate of the object. Default = 0.
        */
        void SetPosition(float x, float y, float z = 0);

        /**
        * Set if the object is active or not.
        * @param active True or False
        */
	    void SetActive(bool active);

        /**
        * Set if the object has interaction or not.
        * @param interactive True or False
        */
	    void SetInteraction(bool interactive);

        void SetSprite(const string& path);

        b2Body* GetBody() const;
        b2BodyDef GetBodyDef() const;
        void SetBodyDef(const b2BodyDef& body);
        b2PolygonShape GetPolygonShape() const;
        void SetPolygonShape(const b2PolygonShape& box);
        b2FixtureDef GetFixDef() const;
        void SetFixDef(const b2FixtureDef& fixDef);

        float mWidth;
        float mHeight;

    protected:
	    string mName;      /**< Name of the object. */
	    HamurVec3 mPos;    /**< Position of the object. */
        float mRotation;   /**< Rotation angle of the object */
	    bool mActive;      /**< Object is active or not. */
	    bool mInteractive; /**< Object has interaction or not. */
        unsigned int mSpriteID; /**< Sprite ID of the game object. */

        // Box2D Attributes
        b2BodyDef mBodyDef;
        b2Body* mBody;
        b2PolygonShape mBox;
        b2FixtureDef mFixtureDef;

     
    private:
        // Inner Attributes of Box2D
};

/** Writes the Object to the stream. (pointer version) */
inline std::ostream &operator<<(std::ostream& os, HamurObject* object)
{
    os << object->GetName() << ", " << object->GetPosition() << " Active:" << object->IsActive() << " Inter.:" 
       << object->IsInteractive() << " SpriteID:" << object->GetSpriteID();
    
    return os;
}

/** Writes the Object to the stream. (reference version) */
inline std::ostream &operator<<(std::ostream& os, HamurObject& object)
{
    os << object.GetName() << ", " << object.GetPosition() << " Active:" << object.IsActive() << " Inter.:" 
        << object.IsInteractive() << " SpriteID:" << object.GetSpriteID();

    return os;
}

} // namespace hamur

#endif // HAMUR_OBJECT
