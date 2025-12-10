#pragma once

#ifndef PTR_DEFINE
#define PTR_DEFINE

//	ptr null check
#define pSUCCESS(ptr) ptr != nullptr
#define pFAILED(ptr) ptr == nullptr

//	Debug Only Break
#include <intrin.h>
#ifdef _DEBUG
#define DEBUG_BREAK __debugbreak();
#else
#define DEBUG_BREAK 
#endif // _DEBUG

//	CancelƒAƒNƒVƒ‡ƒ“


#endif // !PTR_DEFINE
