project(${PRJ_APP} VERSION ${CMAKE_PROJECT_VERSION})

# build project
file(GLOB FILE_SRCS "./*.*")
add_executable(${PROJECT_NAME} ${FILE_SRCS})
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PUBLIC_DEPEND_INCLUDES}
        ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${PUBLIC_DEPEND_LIBS}
        ${PRIVATE_DEPEND_LIBS}
        ${PRJ_LIB})

# install
# default usage
#install(TARGETS ${PROJECT_NAME}
#        RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
# if you want install in other directory other than /usr/local
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)