# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProyectoPL_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProyectoPL_autogen.dir\\ParseCache.txt"
  "ProyectoPL_autogen"
  )
endif()
