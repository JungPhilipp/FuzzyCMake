

function(fuzzy_add_paraview_plugin library)
  cmake_parse_arguments(ARG "NO_DEPENDENCIES" "PLUGIN_XML;PLUGIN_VERSION"
      "SOURCES;LINK;ADDITIONAL_SOURCES" ${ARGN})

  set(plugin_name "${library}Plugin")

  if (ARG_NO_DEPENDENCIES)
    # NO_DEPENDENCIES was passed: wrap simple call to add_paraview_plugin
    add_paraview_plugin(${plugin_name} ${ARG_PLUGIN_VERSION}
        SERVER_MANAGER_XML ${ARG_PLUGIN_XML}
        SERVER_MANAGER_SOURCES ${ARG_SOURCES}
        SERVER_SOURCES ${ARG_ADDITIONAL_SOURCES})
  else ()
    add_paraview_plugin(${plugin_name} ${ARG_PLUGIN_VERSION}
        SERVER_MANAGER_XML ${ARG_PLUGIN_XML}
        SERVER_MANAGER_SOURCES ${ARG_SOURCES}
        SERVER_SOURCES "../plugin_main.cpp" ${ARG_ADDITIONAL_SOURCES})

    # link against fuzzy
    target_include_directories(${plugin_name} PRIVATE ${FUZZY_VTK_INCLUDE_DIR})
    target_link_libraries(${plugin_name} PRIVATE fuzzy::common fuzzy::core easyloggingpp ${VTK_LIBRARIES} ${ARG_LINK})

    # configuration for plugin_main.cpp
    target_compile_definitions(${plugin_name} PRIVATE -DFUZZY_BUILD_AS_PLUGIN)
    target_compile_definitions(${plugin_name} PRIVATE -DFUZZY_CURRENT_PLUGIN_NAME=${library})

    if (FUZZY_ENABLE_OPENMP)
      target_link_libraries(${plugin_name} PRIVATE OpenMP::OpenMP_CXX)
      target_compile_definitions(${plugin_name} PRIVATE -DFUZZY_ENABLE_OPENMP)
    endif ()

    # include source directories at build time
     target_include_directories(${plugin_name} PUBLIC
        $<BUILD_INTERFACE:${FUZZY_VTK_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

  endif ()

  # check for undefined symbols
  set_target_properties(${plugin_name} PROPERTIES LINK_FLAGS "-Wl,--no-undefined")

  # add plugin to
  add_dependencies(ParaViewPlugins ${plugin_name})

endfunction()

find_package(ParaView REQUIRED)
include(${PARAVIEW_USE_FILE})

# dummy target, that depends on all paraview plugins
add_custom_target(ParaViewPlugins)

add_subdirectory(HelloWorld)


