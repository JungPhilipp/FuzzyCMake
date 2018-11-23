# Add your paraview plugin
fuzzy_add_paraview_plugin(fuzzyHelloWorld
    SOURCES ${FUZZY_VTK_SOURCE_DIR}/fuzzyHelloWorld.cpp ${FUZZY_VTK_INCLUDE_DIR}/fuzzyHelloWorld.h
    PLUGIN_VERSION 1.0
    PLUGIN_XML HelloWorld.xml)