# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appbug_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appbug_autogen.dir\\ParseCache.txt"
  "appbug_autogen"
  )
endif()
