#-------------------------------------------------------------------------------
# Copyright(C)2014 Modus Datisi
#-------------------------------------------------------------------------------
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ptl VERSION 1.0 LANGUAGES CXX)

#This files contains the MDATISI options for the project
include(options.cmake OPTIONAL RESULT_VARIABLE MD_OPTIONS_FILE)
if (MD_OPTIONS_FILE)
    if (NOT MD_USE_OPTIONS_FILE)
        unset(MD_OPTIONS_FILE)
    endif()    
endif()

#Source files    
#Default policy is to build all source files
set(DO_GLOBAL_RECURSE ON)

if (DO_GLOBAL_RECURSE)
    file(GLOB SRCFILES . *.cpp)

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


#configure_file( version.hpp.in version.hpp)

add_executable(ptl ${SRCFILES})
#target_link_libraries(hellocmake ${Boost_LIBRARIES} armadillo pthread)

enable_testing()

#Test 1
#set(TEST1_SRCFILES test1.cpp)
#add_executable(test1 ${TEST1_SRCFILES})
#add_test(NAME RunTests COMMAND test1)
#add_test(NAME ListTests COMMAND test1 --list-tests)
#add_test(NAME ListTags COMMAND test1 --list-tags)

