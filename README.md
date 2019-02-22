# CMakeProjectTemplate
CMake Project Template.

I create a shared feature extractor library named `feaext`, which open image from file, and then extract keypoints from image. Then create a app named `FeatureExtractApp` to call the library function.

## ToDO
1. Test

## Some Notes
1. When building a shared library, mark all external libraries as `PRIVATE` so they don't show up as a dependency. When building a static library, all external libraries are `PUBLIC`(default) since the user needs to link to them. They will be listed in CeresTargets.cmake.
    ```cmake
    if (BUILD_SHARED_LIBS)
      target_link_libraries(ceres
            LINK_PUBLIC ${CERES_LIBRARY_PUBLIC_DEPENDENCIES}
            LINK_PRIVATE ${CERES_LIBRARY_PRIVATE_DEPENDENCIES})
    else (BUILD_SHARED_LIBS)
      set(CERES_LIBRARY_DEPENDENCIES
            ${CERES_LIBRARY_PUBLIC_DEPENDENCIES}
            ${CERES_LIBRARY_PRIVATE_DEPENDENCIES})
      target_link_libraries(ceres ${CERES_LIBRARY_DEPENDENCIES})
    endif (BUILD_SHARED_LIBS)
    ```

1. If you want to install library to other directory other than `/usr/local`, you could set `CMAKE_INSTALL_PREFIX`, and use install directory `lib` or `include` instead, please note that install directory like `CMAKE_INSTALL_FULL_BINDIR` etc will not work.


## Reference
1. https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
1. https://github.com/ceres-solver/ceres-solver
1. http://ceres-solver.org/installation.html?highlight=cmake#using-ceres-with-cmake

