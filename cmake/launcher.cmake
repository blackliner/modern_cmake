# Must be before the first project call
find_program(LAUNCHER_EXECUTABLE ccache)
mark_as_advanced(LAUNCHER_EXECUTABLE)
if(LAUNCHER_EXECUTABLE)
  foreach(LANG C CXX)
    if(NOT DEFINED CMAKE_${LANG}_COMPILER_LAUNCHER
       AND NOT CMAKE_${LANG}_COMPILER MATCHES ".*/ccache")
      message(STATUS "Enabling ${LAUNCHER_EXECUTABLE} for ${LANG}")
      set(CMAKE_${LANG}_COMPILER_LAUNCHER
          ${LAUNCHER_EXECUTABLE}
          CACHE STRING "")
    endif()
  endforeach()
endif()
