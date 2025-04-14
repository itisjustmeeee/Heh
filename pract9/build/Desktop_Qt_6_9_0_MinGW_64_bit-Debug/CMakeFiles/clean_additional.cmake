# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\pract9_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\pract9_autogen.dir\\ParseCache.txt"
  "pract9_autogen"
  )
endif()
