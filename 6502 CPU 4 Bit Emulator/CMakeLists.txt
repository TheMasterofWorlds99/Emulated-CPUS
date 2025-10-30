# Add source to this project's executable.
add_executable (CMakeTarget "main.cpp"  "CPU.cpp" "memory.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 23)
endif()