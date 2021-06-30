#--------------------------------------------------------
# The CMakeLists.txt for: pCamera
# Author(s): David Battle, Mission Systems Pty Ltd
#--------------------------------------------------------
cmake_minimum_required(VERSION 3.5)
project(pCamera)

set(EXEC_NAME pCamera)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $ENV{BIN_HOME})

# This allows us to use the header-only JSON library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Switching on C++11 has unleashed deprecation warnings for MOOS
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations" )

#===============================================================================
# FINDING MOOS' HEADERS AND LIBRARIES...
#===============================================================================

# moos - http://www.robots.ox.ac.uk/~mobile/MOOS/wiki/pmwiki.php
find_package(MOOS 10.0)

message("+++++++++++++++++++++++++++++++++++++++++")
message("FIND_PACKAGE CONSIDERED:" ${MOOS_CONSIDERED_CONFIGS})
message("+++++++++++++++++++++++++++++++++++++++++")

if(NOT DEFINED MOOS_LIBRARIES)
	message("Defining MOOS_LIBRARIES")
  	set(MOOS_LIBRARIES MOOS)
endif()

message("+++++++++++++++++++++++++++++++++++++++++")
message("MOOS_INCLUDE_DIRS:" ${MOOS_INCLUDE_DIRS})
message("MOOS_LIBRARIES:   " ${MOOS_LIBRARIES})
message("+++++++++++++++++++++++++++++++++++++++++")

#===============================================================================
# FINDING MOOSGeodesy' HEADERS AND LIBRARIES...
#===============================================================================
# moos - http://www.robots.ox.ac.uk/~mobile/MOOS/wiki/pmwiki.php
find_package(MOOSGeodesy)
find_package( OpenCV REQUIRED )

#link_directories(${MOOSGeodesy_LIBRARY_PATH})

message("+++++++++++++++++++++++++++++++++++++++++")
message("MOOSGeodesy_INCLUDE_DIRS:" ${MOOSGeodesy_INCLUDE_DIRS})
message("MOOSGeodesy_LIBRARY_PATH:" ${MOOSGeodesy_LIBRARY_PATH})
message("+++++++++++++++++++++++++++++++++++++++++")

include_directories(./
        $ENV{MOOSIVP_SOURCE_TREE_BASE}/include/ivp
	    ${OpenCV_INCLUDE_DIRS}
        ${MOOS_INCLUDE_DIRS}
        ${MOOSGeodesy_INCLUDE_DIRS})

SET(SRC
  Camera.cpp
  Camera_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(${EXEC_NAME} ${SRC})

TARGET_LINK_LIBRARIES(${EXEC_NAME}
	$ENV{MOOSIVP_SOURCE_TREE_BASE}/lib/libmbutil.a
    ${MOOSGeodesy_LIBRARIES}
    ${MOOS_LIBRARIES}
    ${OpenCV_LIBS})
