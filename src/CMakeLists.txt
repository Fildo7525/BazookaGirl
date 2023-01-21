add_library(lib
	sfmlBasics.cpp
	Hero.cpp
	Enemy.cpp
)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
	lib
PUBLIC
	sfml-graphics
	sfml-audio
	sfml-window
	sfml-system
	sfml-network
)

