cmake_minimum_required(VERSION 3.8)
project(Dupa)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SFML_STATIC_LIBRARIES TRUE)
add_subdirectory(SFML)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true code/*.h code/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-system
        sfml-window)