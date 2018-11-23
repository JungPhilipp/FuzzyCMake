set(SOURCES_FUZZY_VTK
    initialize_logging.cpp
    fuzzyHelloWorld.cpp
    )

  find_package(ParaView REQUIRED)
  include(${PARAVIEW_USE_FILE})

add_library(fuzzy_vtk SHARED ${SOURCES_FUZZY_VTK})
target_link_libraries(fuzzy_vtk PRIVATE fuzzy_common fuzzy_core easyloggingpp)
set_target_properties(fuzzy_vtk PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(fuzzy_vtk PRIVATE ${FUZZY_VTK_INCLUDE_DIR})

target_compile_definitions(fuzzy_vtk PUBLIC ${VTK_DEFINITIONS})
target_link_libraries(fuzzy_vtk PUBLIC ${VTK_LIBRARIES})
target_include_directories(fuzzy_vtk PUBLIC ${VTK_INCLUDE_DIRS})
target_compile_options(fuzzy_vtk PUBLIC
    $<$<COMPILE_LANGUAGE:CXX>:${VTK_REQUIRED_CXX_FLAGS}>
    $<$<COMPILE_LANGUAGE:C>:${VTK_REQUIRED_C_FLAGS}>)

if (FUZZY_ENABLE_OPENMP)
  target_link_libraries(fuzzy_vtk PRIVATE OpenMP::OpenMP_CXX)
  target_compile_definitions(fuzzy_vtk PRIVATE -DFUZZY_ENABLE_OPENMP)
endif ()

add_library(fuzzy::vtk ALIAS fuzzy_vtk)