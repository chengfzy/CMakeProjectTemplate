cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 14)
project(CMakeProjectTemplate)

# cmake modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


###############################################################################
# Libraries
###############################################################################
find_package(Gflags REQUIRED)                                   # gflags
find_package(Glog REQUIRED)                                     # glog
find_package(Boost COMPONENTS filesystem date_time REQUIRED)    # boost
find_package(Eigen3 REQUIRED)                                   # Eigen
find_package(OpenCV 4 REQUIRED)                                 # OpenCV
include_directories(
        ${GFLAGS_INCLUDE_DIRS}
        ${GLOG_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS})
set(EXTERNAL_LIBS ${EXTERNAL_LIBS}
        ${GFLAGS_LIBRARIES}
        ${GLOG_LIBRARIES}
        ${Boost_LIBRARIES}
        ${OpenCV_LIBRARIES})


###############################################################################
# Project Setting
###############################################################################
#default built type
IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE RELEASE)
ENDIF ()
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# build setting
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


###############################################################################
# Application
###############################################################################
# include folder
include_directories(.)

# main app
aux_source_directory(./ FILE_SRCS)
add_executable(${PROJECT_NAME} ${FILE_SRCS})
target_link_libraries(${PROJECT_NAME} ${EXTERNAL_LIBS})
