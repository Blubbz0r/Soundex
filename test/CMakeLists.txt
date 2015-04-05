include_directories(${source_dir}/include)
include_directories(${source_dir}/gtest/include)

add_executable(${PROJECT_NAME}Test main.cpp)
add_dependencies(${PROJECT_NAME}Test googlemock)

target_link_libraries(${PROJECT_NAME}Test
                      debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES}
                      optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${CMAKE_FIND_LIBRARY_SUFFIXES})
