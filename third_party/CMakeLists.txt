
if (NOT TARGET Eigen3)
  add_library(Eigen3 INTERFACE)
  target_include_directories(Eigen3 SYSTEM INTERFACE "eigen/")
  target_compile_definitions(Eigen3 INTERFACE "-DEIGEN_MATRIX_PLUGIN=<Matrix_initializer_list.h>")
  target_include_directories(Eigen3 SYSTEM INTERFACE "eigen_util/")
endif ()

if (NOT TARGET easyloggingpp)
  add_library(easyloggingpp STATIC "easyloggingpp/easylogging++.cc")
  target_include_directories(easyloggingpp SYSTEM PUBLIC "easyloggingpp/include" SYSTEM PRIVATE "easyloggingpp/include/easyloggingpp")
  target_compile_definitions(easyloggingpp PUBLIC "-DELPP_NO_DEFAULT_LOG_FILE"
      "-DELPP_FEATURE_PERFORMANCE_TRACKING"
      "-DELPP_PERFORMANCE_MICROSECONDS"
      "-DELPP_WINSOCK2"
      "-DELPP_STL_LOGGING"
      "-DELPP_LOG_STD_ARRAY"
      "-DELPP_MULTI_LOGGER_SUPPORT"
      "-DELPP_THREAD_SAFE")

  # Might be required for ELPP_THREAD_SAFE?
  # set(THREADS_PREFER_PTHREAD_FLAG ON)
  # find_package(Threads REQUIRED)
  # target_link_libraries(easyloggingpp PUBLIC Threads::Threads)

  if (CMAKE_COMPILER_IS_GNUXX)
    target_compile_definitions(easyloggingpp PRIVATE "-Wno-unused-variable")
  endif ()
  set_target_properties(easyloggingpp PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
  if (MSVC)
    target_compile_definitions(easyloggingpp PUBLIC "-DWIN32_LEAN_AND_MEAN" "-DNOMINMAX")
  endif ()
  target_compile_features(easyloggingpp PUBLIC cxx_std_11)
endif ()

if (NOT TARGET Catch2)
  add_library(Catch2 INTERFACE)
  target_include_directories(Catch2 SYSTEM INTERFACE "catch2/")
endif ()
