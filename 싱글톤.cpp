#include <iostream>

void main()
{
	class Singleton
	{
	private:
		static Singleton* m_pInstance;

	private:
		Singleton(){}

	public:
		~Singleton(){}
		static Singleton* get_instanse()
		{
			if (NULL == m_pInstance) m_pInstance = new Singleton;
			return m_pInstance;
		}
	};

	Singleton* Singleton::m_pInstance = NULL;
	Singleton::get_instanse()->
}