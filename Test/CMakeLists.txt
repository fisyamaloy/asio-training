set(TARGET Test)

set(SOURCE_FILES
    MainTest.cpp)

add_executable(${TARGET} ${SOURCE_FILES})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

target_include_directories(${TARGET} PRIVATE ${CONAN_INCLUDE_DIRS_GTEST})

target_link_libraries(${TARGET} PUBLIC ${EXTRA_LIBS} Network)
target_link_libraries(${TARGET} PRIVATE CONAN_PKG::gtest)
