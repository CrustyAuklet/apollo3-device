cmake_minimum_required(VERSION 3.15)

# default part name, will be used to choose the correct startup files and CMSIS headers
set(DEVICE_TYPE "AMA3B1KK_KBR" CACHE STRING "Manufacturer Part Number of the processor")
set(DEVICE_FAMILY "AMA3B" CACHE STRING "Manufacturer family name of the chosen part")

# declare this library and set it as an INTERFACE library.
# this means we don't actually compile anything, we just provide files and properties to consumers
add_library(device INTERFACE)
add_library(seal::device ALIAS device)

target_compile_features(device INTERFACE cxx_std_20)

# all consumers should use these include directories
target_include_directories(device INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# all consumers should use these sources
target_sources(device INTERFACE device.hpp)

# all consumers should link to these modules
target_link_libraries(device INTERFACE
)

# create some definitions for the consumer based on the device type.
# these are added just like a -D of #define command
target_compile_definitions(device INTERFACE
        __${DEVICE_TYPE}__
        __${DEVICE_FAMILY}__
        # define the correct clock speed based on device type, using CMake Generator expressions (just ugly ternaries)
        #    $<$<STREQUAL:$<UPPER_CASE:"${DEVICE_FAMILY}">,"SAML21">:__SYSTEM_CLOCK=4000000>
        #    $<$<STREQUAL:$<UPPER_CASE:"${DEVICE_FAMILY}">,"SAMD21">:__SYSTEM_CLOCK=1000000>
        #    $<$<STREQUAL:$<UPPER_CASE:"${DEVICE_FAMILY}">,"SAMD51">:__SYSTEM_CLOCK=48000000>
)

#set(MCPU_FLAGS "-mthumb""-mcpu=cortex-m4")
#set(VFP_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")

target_compile_options(device INTERFACE
    "-mthumb"
    "-mcpu=cortex-m4"
    "-mfloat-abi=hard"
    "-mfpu=fpv4-sp-d16"
)

target_link_options(device INTERFACE
    "-mthumb"
    "-mcpu=cortex-m4"
    "-mfloat-abi=hard"
    "-mfpu=fpv4-sp-d16"
)