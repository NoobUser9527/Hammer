workspace "Hammer" 
	architecture "x64"
	startproject "Chess"
	
	configurations
	{
	"Debug",
	"Release",
	"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hammer"
	location "Hammer"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp"
	}

	includedirs
	{
		"%{prj.name}/vendor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"HM_BUILD_DLL",
			"_WINDLL",
			"_UNICODE",
            "UNICODE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Chess")
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		optimize "On"

project "Chess"
	location "Chess"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp"
	}

	includedirs
	{
		"Hammer/vendor",
		"Hammer/src"
	}

	links
	{
		"Hammer"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"_UNICODE",
            "UNICODE"
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		optimize "On"