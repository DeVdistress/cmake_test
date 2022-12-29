cmake_minimum_required(VERSION 3.1...3.23)

set(PJ_NAME "cmake_test")
set(PRJ_VER_FULL "1.0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX) 
    message(STATUS ">>> Working on Linux")
    # set(CMAKE_CXX_COMPILER "clang++")
    # set(CMAKE_C_COMPILER "clang")
	if(CMAKE_GENERATOR STREQUAL "Ninja")
		message(STATUS "... preparing for the Ninja's build system")
	elseif (CMAKE_GENERATOR STREQUAL "Unix Makefiles")
		message(STATUS "... preparing for the Make's build system")
	endif()
	if(CMAKE_CXX_COMPILER STREQUAL "clang++" OR CMAKE_CXX_COMPILER STREQUAL "clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
		add_compile_options("-stdlib=libc++")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi")
	endif()

    add_compile_options(
      "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
      "$<$<CONFIG:DEBUG>:-O0;-g3>"
      "$<$<CONFIG:RELEASE>:-O2;-g0>"
    )
else()
    if (WIN32 OR MSVC)
	
	set(CMAKE_CXX_EXTENSIONS OFF)
	message(STATUS ">>> Working on Windows")
        
	if (MSVC_VERSION GREATER_EQUAL "1900")
            include(CheckCXXCompilerFlag)
            CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
            if (_cpp_latest_flag_supported)
                add_compile_options("/std:c++latest")
            endif()
        endif()
    endif()
endif()

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
        ${PJ_NAME}
        VERSION ${PRJ_VER_FULL}
        LANGUAGES CXX)

add_custom_target(print_config ALL
  # Prints "Config is Debug" in this single-config case
  COMMAND ${CMAKE_COMMAND} -E echo "Config is $<CONFIG>"
  # to make quotes printable,for example
  VERBATIM
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
  add_custom_command(TARGET print_config
    PRE_BUILD
    COMMAND echo -e "This is Debug BaBy !!!"
    COMMENT "This command will be executed before building print_config"
    VERBATIM # to support \t for example
  )
endif()

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# You should usually split this into folders, but this is a simple example

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
#add_library(MyLibExample simple_lib.cpp simple_lib.hpp)

# Link each target with other targets or add options, etc.

# Adding something we can run - Output name matches target name
file(GLOB
        CPP_SOURCES "src/*.cpp"
        C_SOURCES "src/*.c")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${CPP_SOURCES} ${C_SOURCES})

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
#target_link_libraries(MyExample PRIVATE MyLibExample)
