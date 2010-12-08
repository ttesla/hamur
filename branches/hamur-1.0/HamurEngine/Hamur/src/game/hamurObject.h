#ifndef HAMUROBJECT_H
#define HAMUROBJECT_H

#include "../helper/hamurVec3.h"
#include "../helper/hamurVec2.h"
#include "../helper/hamurColor.h"
#include "../helper/hamurRect.h"
//#include "hamurPhysics.h"

#include <string>

using std::string;


namespace hamur
{

// Forward declerations
class HamurTextureManager;


/**
* Hamur Object base class.
* Everything in the Hamur game environment is a Hamur object. 
*/
class HamurObject
{
    public:

        friend class HamurWorld;

        HamurObject(const string& name);

        HamurObject(const string& name, const string& spritePath);

        HamurObject(const string& name, const string& spritePath, const HamurColorRGB& colorkey);


        /**
        * update function of the object. 
        * All update logic should be written here.
        * @param deltaTime Delta time is passed as parameter by the engine
        */
        virtual void Update(float deltaTime) {};

        /**
        * draw function of the object. 
        * All drawings should be written here.
        * @param deltaTime Delta time is passed as parameter by the engine
        */
        virtual void Draw(float deltaTime);

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
	    bool IsVisible() const;

        /** @return If the object has interaction or not */
	    bool IsActive() const;

        /** @return Sprite ID of the object */
        unsigned int GetSpriteID() const;

        float GetWidth() const;

        float GetHeight() const;
	   
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
        * Set if the object is visible or not.
        * @param visible True or False
        */
	    void SetVisible(bool visible);

        /**
        * Set if the object is active or not.
        * @param active True or False
        */
	    void SetActive(bool active);

        /**
        * Set object's sprite with the given image path
        * @param path Path of the texture file
        */
        void SetSprite(const string& path);

        /**
        * Set object's sprite with the given image and colorkey
        * @param path Path of the texture file
        * @param colorkey Colorkey of the image, colorkeyed pixels will be fully transparent
        */
        void SetSprite(const string& path, const HamurColorRGB& colorkey);

        /**
        * Set object's sprite with the given image and colorkey
        * @param path Path of the texture file
        * @param redKey
        * @param greenKey
        * @param blueKey
        */
        void SetSprite(const string& path, int redKey, int greenKey, int blueKey);

        /**
        * Set the width of the hamur object.
        * @param width Width value of the object
        */
        void SetWidth(float width);

        /**
        * Set the height of the hamur object.
        * @param height Height value of the object
        */
        void SetHeight(float height);

        /**
        * Scale sprite
        * ex: (0.5, 0.5) will scale down the sprite into half size
        * @param scale Scaling factor of sprite
        */
        void ScaleSprite(const HamurVec2& scale);

        /**
        * Scale sprite
        * ex: (0.5, 0.5) will scale down the sprite into half size
        * @param scaleX Scaling factor of sprite in X direction
        * @param scaleY Scaling factor of sprite in Y direction
        */
        void ScaleSprite(float scaleX, float scaleY);

        /**
        * Scale sprite uniformly, equal amounts from each direction
        * ex: (0.5) will scale down the sprite into half size
        * @param scale Scaling factor of sprite in both X and Y direction
        */
        void ScaleSpriteUniform(float scale);

        /**
        * Sets transparency of the object sprite, 
        * modifies sprite texture alpha color.
        */
        void SetTransparency(float transparency);

    protected:
        
        virtual ~HamurObject();
    
        string mName;      /**< Name of the object. */
	    HamurVec3 mPos;    /**< Position of the object. */
        float mRotation;   /**< Rotation angle of the object */
	    bool mVisible;      /**< Object is visible or not. */
	    bool mActive;       /**< Object is active or not. */
        unsigned int mSpriteID; /**< Sprite ID of the game object. */
        float mWidth;   /**< Width of the game object. */
        float mHeight;  /**< Height of the game object. */
        HamurVec2 mScale; /**< Scaling factor of object texture, 1 by default */
        float mTransparency; /**< Sprite transparency of the object */
        

        // HamurObject Physic Component
        //HamurPhysics* mPhysicComponent;
     
    private:
        // Inner Attributes of Box2D
};

/** Writes the Object to the stream. (pointer version) */
inline std::ostream &operator<<(std::ostream& os, HamurObject* object)
{
    os << object->GetName() << ", " << object->GetPosition() << " Active:" << object->IsActive() << " SpriteID:" << object->GetSpriteID();
    
    return os;
}

/** Writes the Object to the stream. (reference version) */
inline std::ostream &operator<<(std::ostream& os, HamurObject& object)
{
    os << object.GetName() << ", " << object.GetPosition() << " Active:" << object.IsActive() 
        << " SpriteID:" << object.GetSpriteID();

    return os;
}

} // namespace hamur

#endif // HAMUR_OBJECT
