cmake_minimum_required (VERSION 3.8)

file(GLOB SRC_CORE	"../core/*.cpp" "../core/*.h"
"../core/Asset/*.cpp" "../core/Asset/*.h"
"../core/Behaviour/*.cpp" "../core/Behaviour/*.h"
"../core/Input/*.cpp" "../core/Input/*.h"
"../core/Material/*.cpp" "../core/Material/*.h"
"../core/Objects/*.cpp" "../core/Objects/*.h"
"../core/Render/*.cpp" "../core/Render/*.h"
"../core/Scene/*.cpp" "../core/Scene/*.h"
"../core/TagManager/*.cpp" "../core/TagManager/*.h"
"../core/Timer/*.cpp" "../core/Timer/*.h"
"../core/Window/*.cpp" "../core/Window/*.h")

if(MSVC)
	add_compile_options("/permissive")
	link_libraries(SDL2 SDL2_image GLEW32 opengl32)
	add_executable(space "main.cpp" "MyGame.cpp" "MyGame.h" ${SRC_CORE})
else()
	add_compile_options("-fpermissive")
	link_libraries(SDL2 SDL2_image GLEW GLU GL)
	add_executable(space "main.cpp" "MyGame.cpp" "MyGame.h" ${SRC_CORE})
endif()