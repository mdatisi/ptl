set(MD_CMAKE_MINIMUM_VERSION_REQUIRED 3.0.0)
cmake_minimum_required(VERSION ${MD_CMAKE_MINIMUM_VERSION_REQUIRED} FATAL_ERROR)
set(MD_GNU_ALL_PERMISSIVE_LICENSE [=[
--------------------------------------------------------------------------------
Copyright(C)2014 Modus Datisi
This CMake script file is licensed under the GNU All-Permissive license.

--------------------------------------------------------------------------------
CMake is a cross-platform, open-source make system.

CMake is used to control the software compilation process using simple platform-
independent and compiler-independent configuration files. CMake generates native
makefiles and workspaces that can be used in the compiler environment of your
choice. CMake is quite sophisticated: it is possible to support complex
environments requiring system configuration, preprocessor generation,
code generation, and template instantiation.

Please go to http://www.cmake.org/HTML/About.html to learn more about CMake.
--------------------------------------------------------------------------------
Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.  This file is offered as-is,
without any warranty.
--------------------------------------------------------------------------------
]=])
#-------------------------------------------------------------------------------
#This script Layout :
#
#    1)
#    2)
#    3) 
#    4) 
#-------------------------------------------------------------------------------

#TODO : Delete the line below
set(MD_VERBOSE ON)

#-------------------------------------------------------------------------------
# 1) CMake configuration
#-------------------------------------------------------------------------------
#CMAKE configuration
if (MD_VERBOSE)
    message(STATUS "-> Minimum CMake version required : ${MD_CMAKE_MINIMUM_VERSION_REQUIRED}")
    message(STATUS "-> Actual  CMake version          : ${CMAKE_VERSION}")
    message(STATUS "-> CMAKE_BINARY_DIR               : ${CMAKE_BINARY_DIR}")
endif()

#AUTHORS
file(READ "AUTHORS" MD_AUTHORS)

#COPYING
file(READ "COPYING" MD_COPYING)

#Colored Makefile
set(CMAKE_COLOR_MAKEFILE TRUE)


#-------------------------------------------------------------------------------
# 2) Environment configuration
#-------------------------------------------------------------------------------
#
#Linux Kernel
#TODO : Portability Issue here
EXECUTE_PROCESS(COMMAND uname -r OUTPUT_VARIABLE os_release OUTPUT_STRIP_TRAILING_WHITESPACE)

if (MD_VERBOSE)
    message(STATUS "-> CMAKE_SYSTEM                   : ${CMAKE_SYSTEM}")
    message(STATUS "-> CMAKE_SYSTEM_NAME              : ${CMAKE_SYSTEM_NAME}")
    message(STATUS "-> CMAKE_SYSTEM_VERSION           : ${CMAKE_SYSTEM_VERSION}")
    message(STATUS "-> CMAKE_SYSTEM_PROCESSOR         : ${CMAKE_SYSTEM_PROCESSOR}")
    message(STATUS "-> Linux Kernel                   : ${os_release}")
endif()


#-------------------------------------------------------------------------------
# 2) Project structure
#-------------------------------------------------------------------------------
project(ptl VERSION 1.0 LANGUAGES CXX)

#"root" absolute dir
get_filename_component(MD_PROJECT_ROOT_ABSDIR 
                       "${CMAKE_SOURCE_DIR}" ABSOLUTE)
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_ROOT_ABSDIR})

#"root"/3rdparty absolute subdir
set(MD_PROJECT_3RDPARTY_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/3rdparty")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_3RDPARTY_ABSDIR})

#"root"/doc absolute subdir
set(MD_PROJECT_DOC_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/doc")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_DOC_ABSDIR})

#"root"/etc absolute subdir
set(MD_PROJECT_ETC_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/etc")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_ETC_ABSDIR})

#"root"/include absolute subdir
set(MD_PROJECT_INCLUDE_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/include")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_INCLUDE_ABSDIR})

#"root"/src absolute subdir
set(MD_PROJECT_SRC_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/src")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_SRC_ABSDIR})

#"root"/test absolute subdir
set(MD_PROJECT_TEST_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/test")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_TEST_ABSDIR})

#"root"/tools absolute subdir
set(MD_PROJECT_TOOLS_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/tools")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_TOOLS_ABSDIR})

#"root"/var absolute subdir
set(MD_PROJECT_VAR_ABSDIR "${MD_PROJECT_ROOT_ABSDIR}/var")
set(MD_ABSDIRS ${MD_ABSDIRS} ${MD_PROJECT_VAR_ABSDIR})

if (MD_VERBOSE)
    message(STATUS "-> MD_PROJECT_ROOT_ABSDIR     : ${MD_PROJECT_ROOT_ABSDIR}")
    message(STATUS "-> MD_PROJECT_3RDPARTY_ABSDIR : ${MD_PROJECT_3RDPARTY_ABSDIR}")
    message(STATUS "-> MD_PROJECT_DOC_ABSDIR      : ${MD_PROJECT_DOC_ABSDIR}")
    message(STATUS "-> MD_PROJECT_ETC_ABSDIR      : ${MD_PROJECT_ETC_ABSDIR}")
    message(STATUS "-> MD_PROJECT_INCLUDE_ABSDIR  : ${MD_PROJECT_INCLUDE_ABSDIR}")
    message(STATUS "-> MD_PROJECT_SRC_ABSDIR      : ${MD_PROJECT_SRC_ABSDIR}")
    message(STATUS "-> MD_PROJECT_TEST_ABSDIR     : ${MD_PROJECT_TEST_ABSDIR}")
    message(STATUS "-> MD_PROJECT_TOOLS_ABSDIR    : ${MD_PROJECT_TOOLS_ABSDIR}")
    message(STATUS "-> MD_PROJECT_VAR_ABSDIR      : ${MD_PROJECT_VAR_ABSDIR}")
endif()

#Checking existence of the directories
foreach(d ${MD_ABSDIRS})
    if (NOT IS_DIRECTORY ${d})
        message(FATAL_ERROR "${d} check failed")
    endif()
endforeach()

#This files contains the MDATISI options for the project
include(options.cmake OPTIONAL RESULT_VARIABLE MD_OPTIONS_FILE)
if (MD_OPTIONS_FILE)
    if (NOT MD_USE_OPTIONS_FILE)
        unset(MD_OPTIONS_FILE)
    endif()    
endif()


#Documentation
option(BUILD_DOCUMENTATION "Use Doxygen to create documentation" ON)
if (BUILD_DOCUMENTATION)
    find_package(Doxygen)
    if (!DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation")
    endif()
endif()

#Packages
#find_package(Boost 1.55 COMPONENTS program_options log log_setup thread date_time chrono system filesystem REQUIRED)

#Flags for GNU G++ Compiler 
if (CMAKE_COMPILER_IS_GNUCXX)
    
    #C++ standard version
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9)
    set(MD_CPP_STANDARD -std=c++14  )
    elseif (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.7)
        set(MD_CPP_STANDARD -std=c++11 ) 
    endif()
    set(MD_MESSAGES ${MD_MESSAGES} "--> C++ standard : " ${MD_CPP_STANDARD} "\n")    

    #Optimization level
    set(MD_OPTIMIZATION_LEVEL -O2)   
    set(MD_MESSAGES ${MD_MESSAGES} "--> Level of optimization : " ${MD_OPTIMIZATION_LEVEL} "\n")

    #Architecture
    #TODO: set(MD_ARCHITECTURE "(default/unknown)")
    set(MD_MESSAGES ${MD_MESSAGES} "--> Compiling for architecture : " ${MD_ARCHITECTURE} "\n")
    #Diagnostics
    
    set(MD_DIAGNOSTICS -Wall -Wextra -pedantic )
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9)
        #Extra Coloring for GCC > 4.9
        set(MD_DIAGNOSTICS ${MD_DIAGNOSTICS} -fdiagnostics-color=auto)
    endif()
    set(MD_MESSAGES ${MD_MESSAGES} "--> Diagnostics flags : " ${MD_DIAGNOSTICS} "\n")

    #Compiler verbosity
    set(CMAKE_VERBOSE_MAKEFILE ON)
    set(MD_MESSAGES ${MD_MESSAGES} "--> Compiler verbosity : " ${CMAKE_VERBOSE_MAKEFILE} "\n")

    #Debugging Information
    set(MD_DEBUGGING -g)
    
    set(MD_COMPILE_OPTIONS 
        ${MD_CPP_STANDARD}
        ${MD_OPTIMIZATION_LEVEL}
        ${MD_ARCHITECTURE}
        ${MD_DIAGNOSTICS}
        ${MD_DEBUGGING})
endif()

message("--------------------------------------------------")
message("Modus Datisi Messages:")
message(${MD_MESSAGES})
message("--------------------------------------------------")
add_compile_options(${MD_COMPILE_OPTIONS})

message(STATUS "Build Type ???? " ${CMAKE_BUILD_TYPE})
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

#Source files    
#Default policy is to build all source files
set(DO_GLOBAL_RECURSE ON)
if (DO_GLOBAL_RECURSE)
    file(GLOB SRCFILES "${MD_PROJECT_SRC_ABSDIR}/*")

    #Declare excluded files below
    #set(EXCLUDED_FROM_BUILD )
    foreach(efb ${EXCLUDED_FROM_BUILD})
        set(efb "${CMAKE_CURRENT_LIST_DIR}/${efb}")
        list(REMOVE_ITEM SRCFILES ${efb})
    endforeach()
#"File by File" policy
else()
    #Add files manually here
    #
    # ...
    #
endif()

add_executable(ptl ${SRCFILES})

configure_file( ${MD_PROJECT_SRC_ABSDIR}/version.hpp.in ${MD_PROJECT_SRC_ABSDIR}/version.hpp)

#target_link_libraries(hellocmake ${Boost_LIBRARIES} armadillo pthread)

enable_testing()

#Test 1
#set(TEST1_SRCFILES test1.cpp)
#add_executable(test1 ${TEST1_SRCFILES})
#add_test(NAME RunTests COMMAND test1)
#add_test(NAME ListTests COMMAND test1 --list-tests)
#add_test(NAME ListTags COMMAND test1 --list-tags)


function (main)
    message( STATUS "This is the main function")
endfunction()

main()
