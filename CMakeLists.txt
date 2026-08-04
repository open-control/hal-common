cmake_minimum_required(VERSION 3.29)

project(open_control_hal_common VERSION 0.2.0 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/OpenControlHalCommonSources.cmake")

add_library(oc_hal_common INTERFACE)
if(OC_HAL_COMMON_SOURCES)
    target_sources(oc_hal_common INTERFACE ${OC_HAL_COMMON_SOURCES})
endif()
target_include_directories(oc_hal_common
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_features(oc_hal_common INTERFACE cxx_std_17)
