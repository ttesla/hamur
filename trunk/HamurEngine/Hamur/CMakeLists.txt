# HAMUR ENGINE Static Lib Cmake script
# created by inspire13 - www.inspire13.com

# Additional include and library directories
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries)			    # Box2D
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/fmod/include)# Fmod
include_directories (${HamurEngine_SOURCE_DIR}/Hamur/libraries/sdl/include) # SDL

# Hamur source files

# Hamur Audio
set(HAMUR_AUDIO_SRC     
src/audio/hamurAuMR.cpp
src/audio/hamurAuMR.h
src/audio/hamurFX.cpp
src/audio/hamurFX.h
src/audio/hamurSong.cpp
src/audio/hamurSong.h
src/audio/hamurStream.cpp
src/audio/hamurStream.h
)
# Hamur Game
set(HAMUR_GAME_SRC
src/game/hamurObject.cpp
src/game/hamurObject.h
src/game/hamurState.cpp
src/game/hamurState.h
src/game/hamurStateMR.cpp
src/game/hamurStateMR.h
src/game/hamurWorld.cpp
src/game/hamurWorld.h
)
# Hamur Helper
set(HAMUR_HELPER_SRC
src/helper/hamurColor.cpp
src/helper/hamurColor.h
src/helper/hamurConsole.cpp
src/helper/hamurConsole.h
src/helper/hamurFile.cpp
src/helper/hamurFile.h
src/helper/hamurHash.h
src/helper/hamurLog.cpp
src/helper/hamurLog.h
src/helper/hamurMath.cpp
src/helper/hamurMath.h
src/helper/hamurPlotter.cpp
src/helper/hamurPlotter.h
src/helper/hamurString.cpp
src/helper/hamurString.h
src/helper/hamurVec2.h
src/helper/hamurVec3.h
)
# Hamur
set(HAMUR_SRC
src/hamur.h
src/hamurDefinitions.h
src/hamurEngine.cpp
src/hamurEngine.h
src/hamurEvent.cpp
src/hamurEvent.h
src/hamurFont.cpp
src/hamurFont.h
src/hamurGL.cpp
src/hamurGL.h
src/hamurGP.cpp
src/hamurGP.h
src/hamurSingleton.h
src/hamurTex.cpp
src/hamurTex.h
src/hamurTexMR.cpp
src/hamurTexMR.h
)

# Hamur ALL - combine all sources
set(HAMUR_ALL_SRC
${HAMUR_AUDIO_SRC}
${HAMUR_GAME_SRC}
${HAMUR_HELPER_SRC}
${HAMUR_SRC}
)

# Source grouping for Visual Studio (or for any other editors which supports)
source_group(Hamur\\Audio  FILES ${HAMUR_AUDIO_SRC})  # Hamur Audio
source_group(Hamur\\Game   FILES ${HAMUR_GAME_SRC})   # Hamur Game
source_group(Hamur\\Helper FILES ${HAMUR_HELPER_SRC}) # Hamur Helper
source_group(Hamur  	   FILES ${HAMUR_SRC})	      # Hamur

# Box2D source
set(BOX2D_SRC
libraries/Box2D/Collision/Shapes/b2PolygonShape.h
libraries/Box2D/Collision/Shapes/b2Shape.h
libraries/Box2D/Collision/Shapes/b2CircleShape.cpp
libraries/Box2D/Collision/Shapes/b2CircleShape.h
libraries/Box2D/Collision/Shapes/b2PolygonShape.cpp
libraries/Box2D/Collision/b2BroadPhase.cpp
libraries/Box2D/Collision/b2BroadPhase.h
libraries/Box2D/Collision/b2CollideCircle.cpp
libraries/Box2D/Collision/b2CollidePolygon.cpp
libraries/Box2D/Collision/b2Collision.cpp
libraries/Box2D/Collision/b2Collision.h
libraries/Box2D/Collision/b2Distance.cpp
libraries/Box2D/Collision/b2Distance.h
libraries/Box2D/Collision/b2DynamicTree.cpp
libraries/Box2D/Collision/b2DynamicTree.h
libraries/Box2D/Collision/b2TimeOfImpact.cpp
libraries/Box2D/Collision/b2TimeOfImpact.h
libraries/Box2D/Common/b2Settings.cpp
libraries/Box2D/Common/b2Settings.h
libraries/Box2D/Common/b2StackAllocator.cpp
libraries/Box2D/Common/b2StackAllocator.h
libraries/Box2D/Common/b2BlockAllocator.cpp
libraries/Box2D/Common/b2BlockAllocator.h
libraries/Box2D/Common/b2Math.cpp
libraries/Box2D/Common/b2Math.h
libraries/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h
libraries/Box2D/Dynamics/Contacts/b2PolygonContact.cpp
libraries/Box2D/Dynamics/Contacts/b2PolygonContact.h
libraries/Box2D/Dynamics/Contacts/b2TOISolver.cpp
libraries/Box2D/Dynamics/Contacts/b2TOISolver.h
libraries/Box2D/Dynamics/Contacts/b2CircleContact.cpp
libraries/Box2D/Dynamics/Contacts/b2CircleContact.h
libraries/Box2D/Dynamics/Contacts/b2Contact.cpp
libraries/Box2D/Dynamics/Contacts/b2Contact.h
libraries/Box2D/Dynamics/Contacts/b2ContactSolver.cpp
libraries/Box2D/Dynamics/Contacts/b2ContactSolver.h
libraries/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
libraries/Box2D/Dynamics/Joints/b2PrismaticJoint.h
libraries/Box2D/Dynamics/Joints/b2PulleyJoint.cpp
libraries/Box2D/Dynamics/Joints/b2PulleyJoint.h
libraries/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp
libraries/Box2D/Dynamics/Joints/b2RevoluteJoint.h
libraries/Box2D/Dynamics/Joints/b2WeldJoint.cpp
libraries/Box2D/Dynamics/Joints/b2WeldJoint.h
libraries/Box2D/Dynamics/Joints/b2DistanceJoint.cpp
libraries/Box2D/Dynamics/Joints/b2DistanceJoint.h
libraries/Box2D/Dynamics/Joints/b2FrictionJoint.cpp
libraries/Box2D/Dynamics/Joints/b2FrictionJoint.h
libraries/Box2D/Dynamics/Joints/b2GearJoint.cpp
libraries/Box2D/Dynamics/Joints/b2GearJoint.h
libraries/Box2D/Dynamics/Joints/b2Joint.cpp
libraries/Box2D/Dynamics/Joints/b2Joint.h
libraries/Box2D/Dynamics/Joints/b2LineJoint.cpp
libraries/Box2D/Dynamics/Joints/b2LineJoint.h
libraries/Box2D/Dynamics/Joints/b2MouseJoint.cpp
libraries/Box2D/Dynamics/Joints/b2MouseJoint.h
libraries/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp
libraries/Box2D/Dynamics/b2Fixture.cpp
libraries/Box2D/Dynamics/b2Fixture.h
libraries/Box2D/Dynamics/b2Island.cpp
libraries/Box2D/Dynamics/b2Island.h
libraries/Box2D/Dynamics/b2TimeStep.h
libraries/Box2D/Dynamics/b2World.cpp
libraries/Box2D/Dynamics/b2World.h
libraries/Box2D/Dynamics/b2WorldCallbacks.cpp
libraries/Box2D/Dynamics/b2WorldCallbacks.h
libraries/Box2D/Dynamics/b2Body.cpp
libraries/Box2D/Dynamics/b2Body.h
libraries/Box2D/Dynamics/b2ContactManager.cpp
libraries/Box2D/Dynamics/b2ContactManager.h
libraries/Box2D/Box2D.h
)

# Source grouping for Box2D
source_group(Box2D FILES ${BOX2D_SRC})

# Set library output directory (works for both Debug and Release in MSVC)
set(LIBRARY_OUTPUT_PATH ${HamurEngine_SOURCE_DIR}/Hamur/libraries/hamur/)

# Make a static lib of Hamur
add_library(Hamur STATIC ${HAMUR_ALL_SRC} ${BOX2D_SRC})
