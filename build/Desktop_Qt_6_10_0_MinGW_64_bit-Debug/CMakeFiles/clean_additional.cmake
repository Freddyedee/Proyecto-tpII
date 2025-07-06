# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appinterfaz-proyecto_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appinterfaz-proyecto_autogen.dir\\ParseCache.txt"
  "appinterfaz-proyecto_autogen"
  )
endif()
