set(CURRENT_PROJECT_NAME ${PROJECT_NAME}UnitTests)

include_directories(${source_dir}/include)
include_directories(${source_dir}/gtest/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(${CURRENT_PROJECT_NAME} main.cpp
                                       CharUtilTest.cpp
                                       SoundexTest.cpp
                                       StringUtilTest.cpp
                                       ${PROJECT_SOURCE_DIR}/src/Soundex.h)
add_dependencies(${CURRENT_PROJECT_NAME} googlemock ${PROJECT_NAME})

target_link_libraries(${CURRENT_PROJECT_NAME}
                      debug ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Soundex${CMAKE_DEBUG_POSTFIX}.lib
                      debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES}
                      optimized ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Soundex.lib
                      optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES})

add_test(NAME unittest COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)
