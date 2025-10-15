#pragma once

#ifdef TARGET_PLATFORM_WINDOWS
	#ifdef KMINIENGINE_BUILD_DLL
		#define KMINIENGINE_API __declspec(dllexport)
	#else
		#define KMINIENGINE_API __declspec(dllimport)
	#endif
#else 
	#error Windows is the only supported platform!
#endif 
