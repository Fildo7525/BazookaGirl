cmake_minimum_required(VERSION 3.22.1)
project(sfmlBasics VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
	main.cpp
)
set(HEADERS
)

find_package(SFML 2.5 COMPONENTS graphics audio window system network REQUIRED)

add_subdirectory(src)

add_executable(${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
)

target_link_libraries(
	${PROJECT_NAME}
PUBLIC
	lib
)

