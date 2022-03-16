# This is a CMake example for Python

SET(SWIG_OUTFILE_DIR mypackage/)

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")

SET_SOURCE_FILES_PROPERTIES(mypackage/cameron.i PROPERTIES C ON)
SET_SOURCE_FILES_PROPERTIES(mypackage/cameron.i PROPERTIES SWIG_FLAGS "-includeall")
swig_add_library(cameron TYPE SHARED LANGUAGE python SOURCES mypackage/cameron.i)
SWIG_LINK_LIBRARIES(cameron ${PYTHON_LIBRARIES})














# # Just a placeholder to suppress a warning, NO idea how low this can actually go
# cmake_minimum_required(VERSION 3.20)
# project(mypackage C)

# # set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)

# # FIND_PACKAGE(SWIG REQUIRED)
# # INCLUDE(${SWIG_USE_FILE})

# # FIND_PACKAGE(PythonLibs)
# # INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

# # INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# # set(CMAKE C FLAGS "-std=c99")

# SET(MYPACKAGE_CONFIG
#     mypackage/cameron.i
#     mypackage/demo.i
# )

# SET(MYPACKAGE_SOURCE
#     mypackage/cameron.c
#     mypackage/demo.c
# )

# # swig_add_library(mypackage TYPE SHARED LANGUAGE python SOURCES ${MYPACKAGE_CONFIG})
# # set_target_properties(mypackage PROPERTIES LIBRARY OUTPUT DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/mypackage) 
# # target_link_libraries(mypackage ${PYTHON_LIBRARIES})



# # This is a CMake example for Python

# FIND_PACKAGE(SWIG REQUIRED)
# INCLUDE(${SWIG_USE_FILE})

# FIND_PACKAGE(PythonLibs)
# INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

# INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# SET(CMAKE_SWIG_FLAGS "")

# # SET_SOURCE_FILES_PROPERTIES(example.i PROPERTIES CPLUSPLUS ON)
# SET_SOURCE_FILES_PROPERTIES(${MYPACKAGE_CONFIG} PROPERTIES SWIG_FLAGS "-includeall")
# SWIG_ADD_MODULE(mypackage python ${MYPACKAGE_CONFIG} ${MYPACKAGE_SOURCE})
# SWIG_LINK_LIBRARIES(mypackage ${PYTHON_LIBRARIES})