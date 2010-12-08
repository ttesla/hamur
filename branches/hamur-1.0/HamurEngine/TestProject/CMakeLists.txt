# HAMUR ENGINE Test Project Cmake script
# created by inspire13 - www.inspire13.com

# Include directories
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries)			   	# Box2D
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/fmod/include)# Fmod
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/sdl/include) # SDL
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/src/) 					# Hamur

# Library directories
link_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries)	     # Box2D
link_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/fmod/lib)# Fmod
link_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/sdl/lib) # SDL

# Hamur link directory (Works for both Debug and Release in MSVC)
link_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/hamur/) 

#if(MSVC)
find_package(OpenGL)
set(SDL_LIBS SDLmain SDL SDL_image ${OPENGL_LIBRARIES})
set(FMOD_LIBS fmodvc)
#endif(MSVC)

# Find link libraries - for LINUX
#find_package(SDL)
#find_package(SDL_image)
#find_package(OpenGL)
# Use with:
# ${SDL_LIBRARY}
# ${SDLIMAGE_LIBRARY}
# ${OPENGL_LIBRARIES}

# TestProject source files
set(TEST_PROJECT_SRC
src/GroundObject.cpp
src/GroundObject.h
src/main.cpp
src/MainState.cpp
src/MainState.h
src/DynamicObject.cpp
src/DynamicObject.h
src/ExampleState.cpp
src/ExampleState.h
)

# Linker flags for Visual Studio
if(MSVC)
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT ")
endif(MSVC)

# Set executable output directory 
if(MSVC)
set(EXECUTABLE_OUTPUT_PATH ${HamurEngine_BINARY_DIR})
else(MSVC)
set(EXECUTABLE_OUTPUT_PATH ${HamurEngine_BINARY_DIR}/Debug)
endif(MSVC)

# Make TestProject
add_executable (TestProject ${TEST_PROJECT_SRC}) 

# Link with Hamur and other libraries
target_link_libraries (TestProject Hamur ${SDL_LIBS} ${FMOD_LIBS})

# Visual Studio dependent settings
if(MSVC)
   set_target_properties(TestProject PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
   set_target_properties(TestProject PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
   set_target_properties(TestProject PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
   set_target_properties(TestProject PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
   set_target_properties(TestProject PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
   set_target_properties(TestProject PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif(MSVC)
