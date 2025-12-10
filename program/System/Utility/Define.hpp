#pragma once

#ifndef PTR_DEFINE
#define PTR_DEFINE

//-------------------------------------------------------------------------------------------------------
// Debug
//-------------------------------------------------------------------------------------------------------

//	ptr null check
#define pSUCCESS(ptr) ptr != nullptr
#define pFAILED(ptr) ptr == nullptr

//-------------------------------------------------------------------------------------------------------
// Debug
//-------------------------------------------------------------------------------------------------------

//	Debug Only Break
#include <intrin.h>
#ifdef _DEBUG
#define DEBUG_BREAK __debugbreak();
#else
#define DEBUG_BREAK 
#endif // _DEBUG

//-------------------------------------------------------------------------------------------------------
// Accessor
//-------------------------------------------------------------------------------------------------------

//	Setter
#define SETTER(Type,Value)\
public:\
void Set##Value(Type value){\
	Value = value;\
};\

//	Getter
#define GETTER(Type,Value)\
public:\
Type Get##Value()const{\
	return Value;\
};\

// Setter & Getter
#define PROPERTY(Type,Value)\
public:\
void Set##Value(Type value){\
	Value = value;\
};\
Type Get##Value()const{\
	return Value;\
};\


#endif // !PTR_DEFINE
