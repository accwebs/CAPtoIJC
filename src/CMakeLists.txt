
# we need the GlobalPlatform includes
find_package(GLOBALPLATFORM REQUIRED)



SET(header_files  stdafx.h
                  CAPtoIJC.h)

SET(SOURCES       CAPtoIJC.cpp
                  ${header_files})

source_group("Headers" FILES ${header_files})



# we need the GlobalPlatform includes (#defines and types)
INCLUDE_DIRECTORIES(${GLOBALPLATFORM_INCLUDE_DIRS})

# on *NIX, it seems we need PCSC for GlobalPlatform.h to include nicely
IF(UNIX)
  find_package(PCSC REQUIRED)
  INCLUDE_DIRECTORIES(${PCSC_INCLUDE_DIRS})
ENDIF()



ADD_EXECUTABLE(CAPtoIJC ${SOURCES})



TARGET_LINK_LIBRARIES(CAPtoIJC ${GLOBALPLATFORM_LIBRARIES})



INSTALL(TARGETS CAPtoIJC DESTINATION bin)
