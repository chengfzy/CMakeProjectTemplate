cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)

# project
set(PRJ_VERSION_MAJOR 1)
set(PRJ_VERSION_MINOR 2)
set(PRJ_VERSION_PATCH 3)
set(PRJ_VESION ${PRJ_VERSION_MAJOR}.${PRJ_VERSION_MINOR}.${PRJ_VERSION_PATCH})
project(CMakeProjectTemplate VERSION 1.2.3)

# parse project version info
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    set(CMAKE_PROJECT_VERSION ${PRJ_VESION})
    set(CMAKE_PROJECT_VERSION_MAJOR ${PRJ_VERSION_MAJOR})
    set(CMAKE_PROJECT_VERSION_MINOR ${PRJ_VERSION_MINOR})
    set(CMAKE_PROJECT_VERSION_PATCH ${PRJ_VERSION_PATCH})
endif ()
message(STATUS "Project Version: ${CMAKE_PROJECT_VERSION}")

#cmake modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


###############################################################################
# Libraries
###############################################################################
find_package(Gflags REQUIRED)                                   # gflags
find_package(Glog REQUIRED)                                     # glog
find_package(Boost COMPONENTS filesystem date_time REQUIRED)    # boost
find_package(Eigen3 REQUIRED)                                   # Eigen
find_package(OpenCV 4 REQUIRED)                                 # OpenCV
find_package(SQLiteCpp REQUIRED)                                # SQLiteCpp

#public and prive dependency include directories
list(APPEND PUBLIC_DEPEND_INCLUDES
        ${GFLAGS_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        )
list(APPEND PRIVATE_DEPEND_INCLUDES
        ${GLOG_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        SQLiteCpp
        )

#public and private dependency libraries
list(APPEND PUBLIC_DEPEND_LIBS
        ${GFLAGS_LIBRARIES}
        )
list(APPEND PRIVATE_DEPEND_LIBS
        ${GLOG_LIBRARIES}
        ${Boost_LIBRARIES}
        ${OpenCV_LIBRARIES}
        SQLiteCpp sqlite3
        )

###############################################################################
# Project Setting
###############################################################################
#default built type
IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE RELEASE)
ENDIF ()
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

#build setting
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#project name
set(PRJ_LIB FeatureExtract)
set(PRJ_APP FeatureExtractApp)
#add project directory
add_subdirectory(module)

###############################################################################
# Install
###############################################################################
#include(GNUInstallDirs)

# install prefix if want to install in other dir, NOTE this couldn't work if use CMAKE_INSTALL_FULL_BINDIR, etc.
set(CMAKE_INSTALL_PREFIX $ENV{HOME}/Downloads/usr)


