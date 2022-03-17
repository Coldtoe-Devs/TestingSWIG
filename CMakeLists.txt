
set(CMAKE_SWIG_OUTDIR mypackage/)


FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")


## FOR EACH .c/.h FILE PAIR:
# cameron
swig_add_library(cameron TYPE SHARED LANGUAGE python SOURCES mypackage/cameron.i mypackage/cameron.c)
set_target_properties(_cameron PROPERTIES LIBRARY_OUTPUT_DIRECTORY "mypackage/")
SWIG_LINK_LIBRARIES(cameron ${PYTHON_LIBRARIES})

# demo
swig_add_library(demo TYPE SHARED LANGUAGE python SOURCES mypackage/demo.i mypackage/demo.c)
set_target_properties(_demo PROPERTIES LIBRARY_OUTPUT_DIRECTORY "mypackage/")
SWIG_LINK_LIBRARIES(demo ${PYTHON_LIBRARIES})
