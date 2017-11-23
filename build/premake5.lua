workspace "test"
    configurations { "Debug", "Release" }
    platforms { "x64" }
    targetdir "../bin/%{cfg.buildcfg}"
    language "C++"
    includedirs {
        "../libfixmath",
    }
    flags {
        "C++11",
        "StaticRuntime",
    }
    libdirs {
    }

    filter "configurations:Debug"
    defines { "_DEBUG" }
    flags { "Symbols" }
    libdirs { }
    filter "configurations:Release"
    defines { "NDEBUG" }
    libdirs { }
    optimize "On"
    filter { }
    
project "testfixint"
    kind "ConsoleApp"
    targetname "testfixint"
    files {
        "../**.h",
        "../**.cpp",
        "../libfixmath/**.h",
        "../libfixmath/**.c",
    }
