#pragma once

#ifdef HM_PLATFORM_WINDOWS
	#ifdef HM_BUILD_DLL
		#define HAMMER_API __declspec(dllexport)
	#else
		#define HAMMER_API __declspec(dllimport)
	#endif 
#else
	#error Hammer only support Windows!
#endif 

#define BIT(x) (1 << x)