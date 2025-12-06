#pragma once
#include<memory>

#ifdef GENERATE_SINGLETON_BODY
#undef GENERATE_SINGLETON_BODY
#endif // GENERATE_SINGLETON_BODY

#define GENERATE_SINGLETON_BODY(Class)\
friend class Singleton<Class>;\
Class()noexcept = default;\
virtual ~Class()noexcept = default;\
Class(const Class&) = delete;\
Class(Class&&) = delete;\
Class& operator=(const Class&) = delete;\
Class& operator=(Class&&) = delete;\

/// <summary>
/// シングルトンステート
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class Singleton
{
public:
	static bool Create()
	{
		if (Instance == nullptr)
		{
			Instance = new T();
			Instance->OnCreate();
			return true;
		}
		return false;
	}

	static void Release()
	{
		if (Instance != nullptr)
		{
			Instance->OnDestory();
			delete Instance;
			Instance = nullptr;
		}
	}

	static T* GetInstance()
	{
		return Instance;
	}

protected:
	Singleton() noexcept = default;

	virtual ~Singleton() noexcept = default;

	virtual void OnCreate()
	{
	}

	virtual void OnDestory()
	{
	}
private:

	static T* Instance;

	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;
};

template<typename T>
T* Singleton<T>::Instance = nullptr;