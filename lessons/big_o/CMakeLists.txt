project(big_o)

# Extract subdirectory name as the base target name
get_filename_component(lesson_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Collect all source files
file(GLOB_RECURSE lesson_sources CONFIGURE_DEPENDS
  src/*.cpp
)

file(GLOB_RECURSE lesson_headers CONFIGURE_DEPENDS
  includes/**/*.h
)

# Create a library target for the lesson's source files
add_library(${lesson_name}_lib ${lesson_sources} ${lesson_headers})

target_include_directories(${lesson_name}_lib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_compile_options(${lesson_name}_lib
  PRIVATE -Wall -Wextra -Wpedantic
)

# Create the executable using main.cpp
add_executable(${lesson_name} main.cpp)

target_link_libraries(${lesson_name}
  PRIVATE ${lesson_name}_lib
)
