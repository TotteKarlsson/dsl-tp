cmake_minimum_required(VERSION 2.8)


project(DSL_THIRD_PARTIES)

if(NOT CMAKE_BUILD_TYPE)
  set( CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE )
endif()

#----- ThirdParties
OPTION(BUILD_STATIC_LIBS        "Build STATIC libs"	                    OFF)
OPTION(BUILD_SHARED_LIBS        "Build SHARED libs"	                    ON)
OPTION(BUILD_TINYXML2           "Build TINYXML2"	                    OFF)
OPTION(BUILD_SQLITE	            "Build SQLite"	                        OFF)
OPTION(BUILD_POCO	            "Build POCO"	                        ON)
OPTION(BUILD_CURL	            "Build cURL"	                        OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/bin)

#=== OTHER DEFINITIONS 
if( ${BORLAND} )

    message("Compiling using a BORLAND Compiler")

    if(CMAKE_BASE_NAME STREQUAL "bcc32c")
        message("Compiling using bcc32c")
    endif()
    if(CMAKE_BASE_NAME STREQUAL "bcc32x")
        message("Compiling using bcc32x")
    endif()

    if(CMAKE_BASE_NAME STREQUAL "cpp32")
    add_definitions(
                 -w-8012                     #Comparing signed /unsigned
                 -w-8057                     #Parameter never used
                 -w-8004                     #'var' is assigned a value that is never used
                 -w-8123                     #Path not found
                 -w-8066                     #Unreachable code
                 -w-8104                     #Local static with constructor...
                 -w-8008                     #Condition is always false..
            )
    endif()

    #SET(CMAKE_C_USE_RESPONSE_FILE_FOR_OBJECTS 1)
    #SET(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS 1)

    #SET(CMAKE_C_RESPONSE_FILE_LINK_FLAG "@")
    #SET(CMAKE_CXX_RESPONSE_FILE_LINK_FLAG "@")
    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -tM -tR -DPOCO_DLL")
    set(CMAKE_C_FLAGS "-tM -tR")
    set(CMAKE_SHARED_LINKER_FLAGS "-tM -tR -lS:1048576 -lSc:4098 -lH:1048576 -lHc:8192")
    set(CMAKE_MODULE_LINKER_FLAGS "-tM -tR -lS:1048576 -lSc:4098 -lH:1048576 -lHc:8192") 
    set(CMAKE_EXE_LINKER_FLAGS "-tM -tR -lS:1048576 -lSc:4098 -lH:1048576 -lHc:8192")

    option(ENABLE_DATA ON)
    option(ENABLE_MONGODB OFF)
    option(ENABLE_DATA_MYSQL ON)
    option(ENABLE_DATA_SQLITE ON)
    option(ENABLE_DATA_ODBC OFF)
    option(ENABLE_TESTS OFF)
    option(ENABLE_PAGECOMPILER OFF)
    option(ENABLE_CRYPTO ON)
    option(ENABLE_LONG_RUNNING_TESTS OFF)
    option(ENABLE_PAGECOMPILER_FILE2PAGE OFF)
    set(CMAKE_INSTALL_PREFIX "p:\\build")
    option(ENABLE_REDIS OFF)
    option(ENABLE_NETSSL OFF)

    message("CMake flags: " ${CMAKE_CXX_FLAGS}) 
endif()

if(${MSVC})
    add_subdirectory(dirent)
    add_definitions(
    -D_CRT_SECURE_NO_WARNINGS 
    -D_CRT_NONSTDC_NO_DEPRECATE
    "-wd4244"
    "-wd4554" #use paranthesis to clarify precedence
    )
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -D_SCL_SECURE_NO_WARNINGS /MP")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_SCL_SECURE_NO_WARNINGS /MP")
    #set(CMAKE_CXX_MP_FLAG           ON CACHE BOOL "")
    #set(CMAKE_CXX_MP_NUM_PROCESSORS 8 CACHE INTEGER "")
endif()

#Add Third Party Folders
if(${BUILD_SQLITE})
    add_subdirectory(SQLite)
endif()

if(${BUILD_POCO})
    add_subdirectory(Poco_1.9.3)
endif()

if(${BUILD_TINYXML2})
    add_subdirectory(tinyxml2)
endif()

if(${BUILD_CURL})
    add_subdirectory(curl)
endif()

#add_subdirectory(tclap)
#add_subdirectory(mkjson)
