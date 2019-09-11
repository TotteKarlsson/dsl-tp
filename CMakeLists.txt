cmake_minimum_required(VERSION 2.8)
project(DSL_THIRD_PARTIES)

#----- ThirdParties
set(LIBRARY_POSTFIX  "" CACHE STRING "Appended to library name")
OPTION(BUILD_SHARED_LIBS        "Build SHARED libs"	                    ON)
OPTION(BUILD_STATIC_LIBS        "Build STATIC libs"	                    OFF)

#--Components
OPTION(BUILD_TINYXML2           "Build TINYXML2"	                    OFF)
OPTION(BUILD_SQLITE	            "Build SQLite"	                        OFF)
OPTION(BUILD_POCO	            "Build POCO"	                        OFF)
OPTION(BUILD_CURL	            "Build cURL"	                        OFF)
OPTION(BUILD_MKJSON             "Build MKJSON"	                        OFF)
OPTION(INSTALL_TCLAP            "Install tclap"                         OFF)
OPTION(INSTALL_DIRENT_HEADER    "Install dirent header"                 OFF)

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

#Add library folders
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

if(${BUILD_MKJSON})
    add_subdirectory(mkjson)
endif()

if(${INSTALL_TCLAP})
    add_subdirectory(tclap)
endif()

if(${INSTALL_DIRENT_HEADER})
    add_subdirectory(dirent)
endif()
