# CMakeList.txt : CMake project for 2D-GameEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2D-GameEngine")

include_directories(${PROJECT_SOURCE_DIR}/include)

# Set up vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find SFML packages
find_package(SFML CONFIG REQUIRED COMPONENTS system window graphics network)
# Find Box2D package
find_package(box2d CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (2D-GameEngine   "include/Engine/GameEngine.h" "src/Engine/GameEngine.cpp" "include/Utils/utils.h")


# Link libraries
target_link_libraries(2D-GameEngine PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
target_link_libraries(2D-GameEngine PRIVATE box2d::box2d)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2D-GameEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
