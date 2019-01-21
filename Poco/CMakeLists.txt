cmake_minimum_required(VERSION 2.6)
project(poco)

OPTION(BUILD_POCO_NET "Build poco NET library" OFF)
OPTION(BUILD_POCO_XML "Build poco XML library" OFF)
OPTION(BUILD_POCO_DATA "Build poco DATA library" OFF)

#add_definitions(
#    #-DPCRE_STATIC
#    #-DPOCO_STATIC
#)
#
#if(WIN32)
#    add_definitions(
#        -D_WIN32
#        )
#endif()

#Always build foundation..
add_subdirectory(Foundation)

if (BUILD_POCO_NET)
    add_subdirectory(Net)
endif()

if (BUILD_POCO_XML)
    add_subdirectory(XML)
endif()    

if (BUILD_POCO_DATA)
    add_subdirectory(DATA)
endif()    
