################################################################################
### Test Sources
################################################################################
set(TEST_SOURCES
      main.cpp
      saxpy.cpp
    )

################################################################################
### Test Target
################################################################################
add_executable(fuzzy-test ${TEST_SOURCES})
target_link_libraries(fuzzy-test PRIVATE fuzzy::core Catch2 easyloggingpp)
add_test(fuzzy-test fuzzy--test)




