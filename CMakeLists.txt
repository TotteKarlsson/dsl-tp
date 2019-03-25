cmake_minimum_required(VERSION 2.8)
project(DSL_THIRD_PARTIES)

if(NOT CMAKE_BUILD_TYPE)
  set( CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE )
endif()

#----- ThirdParties
OPTION(BUILD_STATIC_LIBS        "Build STATIC libs"	                    OFF)
OPTION(BUILD_SHARED_LIBS        "Build SHARED libs"	                    ON)
OPTION(BUILD_TINYXML2           "Build TINYXML2"	                    ON)
OPTION(BUILD_SQLITE	            "Build SQLite"	                        ON)
OPTION(BUILD_POCO	            "Build POCO"	                        ON)
OPTION(BUILD_CURL	            "Build cURL"	                        ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 	${PROJECT_BINARY_DIR}/bin)

#=== OTHER DEFINITIONS 
if(${BORLAND})
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

add_subdirectory(tclap)
add_subdirectory(mkjson)

if(${BUILD_SQLITE})
    add_subdirectory(SQLite)
endif()

if(${BUILD_POCO})
    add_subdirectory(Poco)
endif()

if(${BUILD_TINYXML2})
    add_subdirectory(tinyxml2)
endif()

if(${BUILD_CURL})
    add_subdirectory(curl)
endif()
