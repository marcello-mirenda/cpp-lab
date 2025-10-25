cmake_minimum_required(VERSION 3.22.1)

project(cpp-lab VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CURRENT_SOURCE_DIR "./src")

include(CTest)
enable_testing()

add_executable(cpp-lab)

target_sources(cpp-lab
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fibApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gridTravelerApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/canSumApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/howSumApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bestSumApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/canConstructApp.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
