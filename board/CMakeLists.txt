cmake_minimum_required(VERSION 3.15)

# configuration setting to define the board type
set(BOARD_NAME "BlackBoardATP" CACHE STRING "The hardware to compile for")
set(APOLLO3_BOARDS "BlackBoardATP")
set(VALID_BOARDS ${APOLLO3_BOARDS})
set_property(CACHE BOARD_NAME PROPERTY STRINGS ${VALID_BOARDS})

# is this a simulation build? if so build for desktop.
option(SIMULATION_BUILD "This is a simulation build" OFF)

if(BOARD_NAME IN_LIST APOLLO3_BOARDS)
    set(SEAL_SYSTEM_PROCESSOR "apollo3")
    message("Configuring for ${BOARD_NAME} hardware with Apollo3 processor...")
elseif(BOARD_NAME STREQUAL "" )
    message(SEND_ERROR "No Board defined for the BSP layer!")
else()
    message(SEND_ERROR "Unknown board: ${BOARD_NAME}")
endif()

# if we are cross compiling for an embedded target then system name will be Generic
if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
    set(SIMULATION_BUILD OFF CACHE BOOL "indicates if this is a simulation build" FORCE)
    message("${CMAKE_SYSTEM_NAME} System, Building for hardware...")
else()
    set(SIMULATION_BUILD ON CACHE BOOL "indicates if this is a simulation build" FORCE)
    message("${CMAKE_SYSTEM_NAME} System, Building for simulation...")
endif()

add_library(bsp INTERFACE)
add_library(seal::bsp ALIAS bsp)

add_subdirectory(device)

target_compile_definitions(bsp INTERFACE
        __${SEAL_SYSTEM_PROCESSOR}__            # system processor
        __${BOARD_NAME}__                       # name of the hardware board
        #$<$<CONFIG:Debug>:DEBUG>
        SIMULATION_BUILD=$<IF:$<BOOL:${SIMULATION_BUILD}>,1,0>
)

target_compile_options(bsp INTERFACE
    "-fdata-sections"
    "-ffunction-sections"
    "-mlong-calls"
    "-g3"
)

target_link_options(bsp INTERFACE
    #-T${CMAKE_CURRENT_LIST_DIR}/device/script/RE01_1500KB.ld
    "-Wl,--gc-sections"
    "-Wl,-Map=${PROJECT_NAME}.map"
    #"-nostartfiles"
)

target_link_libraries(bsp INTERFACE seal::device)

add_dependencies(bsp seal::device)

target_include_directories(bsp INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_sources(bsp INTERFACE board.hpp board.cpp)
