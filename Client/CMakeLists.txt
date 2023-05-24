set(TARGET Client)

set(SOURCE_FILES
    MainClient.cpp)

add_executable(${TARGET} ${SOURCE_FILES})

target_link_libraries(${TARGET} PUBLIC ${EXTRA_LIBS} CONAN_PKG::asio)
