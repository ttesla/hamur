#ifndef HAMURSINGLETON_H
#define HAMURSINGLETON_H

namespace hamur
{

	template<typename T>
	class Singleton
	{
	public:

		static T *getInstance()
		{
			if(Singleton<T>::_singleton == NULL)
				Singleton<T>::_singleton = new T();

			return Singleton<T>::_singleton;
		}

		static void drop();

	protected:

		static T* _singleton;

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