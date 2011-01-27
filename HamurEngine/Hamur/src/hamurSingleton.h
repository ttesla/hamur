#ifndef HAMURSINGLETON_H
#define HAMURSINGLETON_H

#ifndef NULL
#define NULL 0
#endif

namespace hamur
{

template<typename T>

/**
* Template class for being base of all singleton classes.
*/
class Singleton
{
    public:
        /**
        * If object is not created yet, creates a new one
        * else returns the current object.
        */
	    static T* GetInstance()
	    {
		    if(mInstance == NULL)
			    mInstance = new T();

		    return mInstance;
	    }

        /**
        * Deletes the current singleton object.
        * Do not call this explicitly. Call HAMURENGINE->terminate() instead.
        * Assigns the current template object to NULL.
        */
	    static void Drop();

    protected:

        Singleton() {}
        ~Singleton(){}

	    static T* mInstance; /**< Static template object */

    private:

	    Singleton(const Singleton<T>&);         /**< Disable copy constructor, no definition provided */
	    Singleton& operator =(const Singleton&);/**< Disable assignment, no definition provided */
};


template<typename T>
void Singleton<T>::Drop()
{
	if(mInstance != NULL)
	{
		delete mInstance;
		mInstance = NULL;
	}
}

template<typename T>
T* Singleton<T>::mInstance = NULL;

} // namespace hamur

#endif // HAMURSINGLETON_H
