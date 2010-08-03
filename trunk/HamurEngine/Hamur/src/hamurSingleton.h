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
	    static T* getInstance()
	    {
		    if(Singleton<T>::mSingleton == NULL)
			    Singleton<T>::mSingleton = new T();

		    return Singleton<T>::mSingleton;
	    }

        /**
        * Deletes the current singleton object.
        * Do not call this explicitly. Call HAMURENGINE->terminate() instead.
        * Assigns the current template object to NULL.
        */
	    static void drop();

    protected:

	    static T* mSingleton; /**< Static template object */

	    explicit Singleton(){}
	    ~Singleton(){}

    private:

	    Singleton(const Singleton<T>&){}
	    Singleton& operator =(const Singleton&){}
};


template<typename T>
void Singleton<T>::drop()
{
	if(Singleton<T>::mSingleton != NULL)
	{
		delete Singleton<T>::mSingleton;
		Singleton<T>::mSingleton = NULL;
	}
}

template<typename T>
typename T* Singleton<T>::mSingleton = NULL;

} // namespace hamur

#endif // HAMURSINGLETON_H
