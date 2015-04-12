include_directories(${source_dir}/include)
include_directories(${source_dir}/gtest/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}Test main.cpp SoundexTest.cpp CharUtilTest.cpp StringUtilTest.cpp ${PROJECT_SOURCE_DIR}/src/Soundex.h)
add_dependencies(${PROJECT_NAME}Test googlemock)

target_link_libraries(${PROJECT_NAME}Test
                      ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Soundex.lib
                      debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES}
                      optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES})
