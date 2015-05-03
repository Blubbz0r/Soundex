project(Soundex)

cmake_minimum_required(VERSION 2.8)

include(CTest)

# enable C++11 support
if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++0x)
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()

# set output directories of executables and libraries
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
# in case multiple configurations exist, we will still put the
# executables and librariers into one common folder, instead
# of e.g. Release or Debug subfolders.
# The CMAKE_DEBUG_POSTFIX will take care of separating between the different configs.
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${OUTPUT_DIR})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

set(CMAKE_DEBUG_POSTFIX "d")

# Enable ExternalProject CMake module
include(ExternalProject)

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${PROJECT_BINARY_DIR}/ext/gmock)

# Add gmock
ExternalProject_Add(
    googlemock
    SVN_REPOSITORY http://googlemock.googlecode.com/svn/trunk/
    TIMEOUT 30
    # Force separate output paths for debug and release builds to allow easy
    # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir for googlemock and googletest
ExternalProject_Get_Property(googlemock source_dir)
ExternalProject_Get_Property(googlemock binary_dir)

if(MSVC_VERSION EQUAL 1700)
  add_definitions(-D_VARIADIC_MAX=10)
endif()

add_subdirectory(src)
add_subdirectory(test)
