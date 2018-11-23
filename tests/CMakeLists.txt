################################################################################
### Test Sources
################################################################################
set(TEST_SOURCES
      main.cpp
      saxpy.cpp
    )

set(TEST_SOURCES_VTK
    main.cpp
    vtk/hello_world.cpp
    )
################################################################################
### Test Target
################################################################################
add_executable(fuzzy-test ${TEST_SOURCES})
target_link_libraries(fuzzy-test PRIVATE fuzzy::core Catch2 easyloggingpp)
add_test(fuzzy-test fuzzy--test)


################################################################################
### VTK Test Target
################################################################################
if (FUZZY_ENABLE_VTK)
  add_executable(fuzzy-vtk-test ${TEST_SOURCES_VTK})
  target_link_libraries(fuzzy-vtk-test PRIVATE fuzzy::core fuzzy::vtk Catch2 easyloggingpp)
  add_test(fuzzy-vtk-test fuzzy-vtk-test)
endif ()





