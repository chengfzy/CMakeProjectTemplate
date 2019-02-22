project(${PRJ_LIB} VERSION ${CMAKE_PROJECT_VERSION})

# build project
file(GLOB_RECURSE FILE_SRCS ./src/*.*)
add_library(${PROJECT_NAME} SHARED ${FILE_SRCS})
target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${PUBLIC_DEPEND_INCLUDES}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PRIVATE_DEPEND_INCLUDES}
        )
target_link_libraries(${PROJECT_NAME}
        PUBLIC ${PUBLIC_DEPEND_LIBS}
        PRIVATE ${PRIVATE_DEPEND_LIBS})

# target properties
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME feaext)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${CMAKE_PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR})

# create ConfigVersion.cmake file
#include(CMakePackageConfigHelpers)
#write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/feaextConfigVersion.cmake
#        VERSION ${PROJECT_VERSION}
#        COMPATIBILITY AnyNewerVersion)

# install
# default usage
#install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR})
#install(TARGETS ${PROJECT_NAME}
#        RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
# if you want install in other directory other than /usr/local
install(DIRECTORY include DESTINATION include)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)