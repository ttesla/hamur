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
		static T *getInstance()
		{
			if(Singleton<T>::_singleton == NULL)
				Singleton<T>::_singleton = new T();

			return Singleton<T>::_singleton;
		}

        /**
        * Deletes the current singleton object.
        * Assigns the current template object to NULL.
        */
		static void drop();

	protected:

		static T* _singleton; /**< Static template object */

		explicit Singleton(){}
		~Singleton(){}

	private:

		Singleton(const Singleton<T>&){}
		Singleton &operator =(const Singleton&){}
	};


	template<typename T>
	void Singleton<T>::drop()
	{
		if(Singleton<T>::_singleton != NULL)
		{
			delete Singleton<T>::_singleton;
			Singleton<T>::_singleton = 0;
		}
	}

	template<typename T>
	typename T* Singleton<T>::_singleton = NULL;
}
#endif // HAMURSINGLETON_H