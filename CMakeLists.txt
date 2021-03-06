#cmake_minimum_required(VERSION 3.15)
#project(gtest_sample)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(gtest_sample main.cpp)

CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 11)

SET(BASE_PROJECT_NAME "gtest_sample")

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release")
SET(ENV_C_FLAGS $ENV{CFLAGS})
SET(ENV_CXX_FLAGS $ENV{CXXFLAGS})

SET(BUILDTYPE_DOCSTRING "Choose the type of build, options are: Debug Release")
IF (NOT DEFINED CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "Debug" CACHE STRING ${BUILDTYPE_DOCSTRING} FORCE)
ENDIF ()

SET(PROJECTNAME_DOCSTRING "BASE project name")
IF (DEFINED BASE_PROJECT_NAME)
    SET(BASE_PROJECT_NAME ${BASE_PROJECT_NAME} CACHE STRING ${PROJECTNAME_DOCSTRING} FORCE)
ELSE ()
    SET(BASE_PROJECT_NAME "BASE_PROJECT" CACHE STRING ${PROJECTNAME_DOCSTRING} FORCE)
    MARK_AS_ADVANCED(BASE_PROJECT_NAME)
ENDIF ()

PROJECT(${BASE_PROJECT_NAME})

# include directories
SET(BASE_HOME ${CMAKE_SOURCE_DIR})
SET(BASE_BIN_DIR "${BASE_HOME}/bin")
SET(BASE_LIB_DIR "${BASE_HOME}/lib")
SET(BASE_INC_DIR "${BASE_HOME}/include")
SET(BASE_DOC_DIR "${BASE_HOME}/doc")
SET(BASE_CMAKE_SCRIPT_DIR "${BASE_HOME}/cmake")

#SET(BASE_DEFAULT_HOME ${CMAKE_INSTALL_PREFIX})
#SET(DEFAULT_BASEDIR "${NOVA_DEFAULT_HOME}")

IF (NOT EXECUTABLE_OUTPUT_PATH)
    SET(EXECUTABLE_OUTPUT_PATH ${BASE_BIN_DIR})
ENDIF ()

IF (NOT LIBRARY_OUTPUT_PATH)
    SET(LIBRARY_OUTPUT_PATH ${BASE_LIB_DIR})
ENDIF ()

SET(SRCTARGET ${BASE_PROJECT_NAME})
ADD_SUBDIRECTORY(src)

SET(TESTTARGET "${BASE_PROJECT_NAME}_Test")
ADD_SUBDIRECTORY(test)