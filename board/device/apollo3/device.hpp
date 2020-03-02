/**
 * Vendor : Ambiq Micro
 * Device : apollo3
 * SVD Verison : 1.0
 * CPU : CM4-r1p0
 * Ultra-Low power ARM Cortex-M4 MCU from Ambiq Micro
 */
#ifndef CPP_DEVICE_DESCRIPTION_HEADER
#define CPP_DEVICE_DESCRIPTION_HEADER

#include "ADC.hpp"    // Analog Digital Converter Control
#include "APBDMA.hpp"    // APB DMA Register Interfaces
#include "BLEIF.hpp"    // BLE Interface
#include "CACHECTRL.hpp"    // Flash Cache Controller
#include "CLKGEN.hpp"    // Clock Generator
#include "CTIMER.hpp"    // Counter/Timer
#include "GPIO.hpp"    // General Purpose IO
#include "IOM0.hpp"    // IO Peripheral Master
#include "IOM1.hpp"    // IO Peripheral Master
#include "IOM2.hpp"    // IO Peripheral Master
#include "IOM3.hpp"    // IO Peripheral Master
#include "IOM4.hpp"    // IO Peripheral Master
#include "IOM5.hpp"    // IO Peripheral Master
#include "IOSLAVE.hpp"    // I2C/SPI Slave
#include "MCUCTRL.hpp"    // MCU Miscellaneous Control Logic
#include "MSPI.hpp"    // Multi-bit SPI Master
#include "PDM.hpp"    // PDM Audio
#include "PWRCTRL.hpp"    // PWR Controller Register Bank
#include "RSTGEN.hpp"    // MCU Reset Generator
#include "RTC.hpp"    // Real Time Clock
#include "SCARD.hpp"    // Serial ISO7816
#include "SECURITY.hpp"    // Security Interfaces
#include "UART0.hpp"    // Serial UART
#include "UART1.hpp"    // Serial UART
#include "VCOMP.hpp"    // Voltage Comparator
#include "WDT.hpp"    // Watchdog Timer

#include "pin_types.hpp"
#include <cstdint>
#include <string_view>

namespace device {
    struct memory_section { uint32_t start; uint32_t size; };

    enum class CPUType {
        CM0, CM0PLUS, CM1, SC000, CM23, CM3, CM33, CM35P,
        SC300, CM4, CM7, ARMV8MML, ARMV8MBL, CA5, CA7, CA8, CA9,
        CA15, CA17, CA53, CA57, CA72, other
    };

    enum class EndianType { little, big, selectable, other };

    constexpr std::string_view name = "Ambiq-apollo3";
    constexpr CPUType cpu_type = CPUType::CM4;
    constexpr EndianType endianess = EndianType::little;
    constexpr auto width = 4;
    constexpr auto addressable = 1;
    constexpr auto nvic_bits = 3;
    constexpr bool mpu_present = true;
    constexpr bool fpu_present = true;
    constexpr bool vendor_systick = false;

    /********** Peripheral Instances. Mapped to memory. **********/
    constexpr sfr::ADC_t< 0x50010000 > ADC{};    // Analog Digital Converter Control
    constexpr sfr::APBDMA_t< 0x40011000 > APBDMA{};    // APB DMA Register Interfaces
    constexpr sfr::BLEIF_t< 0x5000C000 > BLEIF{};    // BLE Interface
    constexpr sfr::CACHECTRL_t< 0x40018000 > CACHECTRL{};    // Flash Cache Controller
    constexpr sfr::CLKGEN_t< 0x40004000 > CLKGEN{};    // Clock Generator
    constexpr sfr::CTIMER_t< 0x40008000 > CTIMER{};    // Counter/Timer
    constexpr sfr::GPIO_t< 0x40010000 > GPIO{};    // General Purpose IO
    constexpr sfr::IOM0_t< 0x50004000 > IOM0{};    // IO Peripheral Master
    constexpr sfr::IOM1_t< 0x50005000 > IOM1{};    // IO Peripheral Master
    constexpr sfr::IOM2_t< 0x50006000 > IOM2{};    // IO Peripheral Master
    constexpr sfr::IOM3_t< 0x50007000 > IOM3{};    // IO Peripheral Master
    constexpr sfr::IOM4_t< 0x50008000 > IOM4{};    // IO Peripheral Master
    constexpr sfr::IOM5_t< 0x50009000 > IOM5{};    // IO Peripheral Master
    constexpr sfr::IOSLAVE_t< 0x50000000 > IOSLAVE{};    // I2C/SPI Slave
    constexpr sfr::MCUCTRL_t< 0x40020000 > MCUCTRL{};    // MCU Miscellaneous Control Logic
    constexpr sfr::MSPI_t< 0x50014000 > MSPI{};    // Multi-bit SPI Master
    constexpr sfr::PDM_t< 0x50011000 > PDM{};    // PDM Audio
    constexpr sfr::PWRCTRL_t< 0x40021000 > PWRCTRL{};    // PWR Controller Register Bank
    constexpr sfr::RSTGEN_t< 0x40000000 > RSTGEN{};    // MCU Reset Generator
    constexpr sfr::RTC_t< 0x40004200 > RTC{};    // Real Time Clock
    constexpr sfr::SCARD_t< 0x40080000 > SCARD{};    // Serial ISO7816
    constexpr sfr::SECURITY_t< 0x40030000 > SECURITY{};    // Security Interfaces
    constexpr sfr::UART0_t< 0x4001C000 > UART0{};    // Serial UART
    constexpr sfr::UART1_t< 0x4001D000 > UART1{};    // Serial UART
    constexpr sfr::VCOMP_t< 0x4000C000 > VCOMP{};    // Voltage Comparator
    constexpr sfr::WDT_t< 0x40024000 > WDT{};    // Watchdog Timer

    /********** GPIO PINS **********/
    inline constexpr GPIO::pin< decltype(GPIO), 0 > P0 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 1 > P1 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 2 > P2 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 3 > P3 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 4 > P4 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 5 > P5 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 6 > P6 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 7 > P7 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 8 > P8 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 9 > P9 = {};

    inline constexpr GPIO::pin< decltype(GPIO), 10 > P10 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 11 > P11 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 12 > P12 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 13 > P13 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 14 > P14 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 15 > P15 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 16 > P16 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 17 > P17 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 18 > P18 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 19 > P19 = {};

    inline constexpr GPIO::pin< decltype(GPIO), 20 > P20 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 21 > P21 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 22 > P22 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 23 > P23 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 24 > P24 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 25 > P25 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 26 > P26 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 27 > P27 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 28 > P28 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 29 > P29 = {};

    inline constexpr GPIO::pin< decltype(GPIO), 30 > P30 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 31 > P31 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 32 > P32 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 33 > P33 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 34 > P34 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 35 > P35 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 36 > P36 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 37 > P37 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 38 > P38 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 39 > P39 = {};

    inline constexpr GPIO::pin< decltype(GPIO), 40 > P40 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 41 > P41 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 42 > P42 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 43 > P43 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 44 > P44 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 45 > P45 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 46 > P46 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 47 > P47 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 48 > P48 = {};
    inline constexpr GPIO::pin< decltype(GPIO), 49 > P49 = {};
}  // namespace device

#endif // CPP_DEVICE_DESCRIPTION_HEADER