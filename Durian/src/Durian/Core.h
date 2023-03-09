#pragma once

#ifdef DR_PLATFORM_WINDOWS
	#ifdef DR_BUILD_DLL
		#define DURIAN_API __declspec(dllexport)
	#else
		#define DURIAN_API __declspec(dllimport)
	#endif // DR_BUILD_DLL
#else
	#error Durian Engine Only Support Windows
#endif // DR_PLATFORM_WINDOWS

#define BIT(x) (1 << x)