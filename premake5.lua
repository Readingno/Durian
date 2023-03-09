workspace "Durian"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Durian"
	location "Durian"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DR_PLATFORM_WINDOWS",
			"DR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DR_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Durian/vendor/spdlog/include",
		"Durian/src"
	}

	links
	{
		"Durian"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DR_DIST"
		optimize "On"