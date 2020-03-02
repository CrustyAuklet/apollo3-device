/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: PWRCTRL
 * PWR Controller Register Bank
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace PWRCTRL {
    
        /// Selects which SRAM banks are powered down in deep sleep mode, causing the contents of the bank to be lost.
        enum class SRAMPWDSLPv : uint32_t {
            NONE = 0x0, //< All banks retained
            GROUP0 = 0x1, //< SRAM GROUP0 powered down (64KB-96KB)
            GROUP1 = 0x2, //< SRAM GROUP1 powered down (96KB-128KB)
            GROUP2 = 0x4, //< SRAM GROUP2 powered down (128KB-160KB)
            GROUP3 = 0x8, //< SRAM GROUP3 powered down (160KB-192KB)
            GROUP4 = 0x10, //< SRAM GROUP4 powered down (192KB-224KB)
            GROUP5 = 0x20, //< SRAM GROUP5 powered down (224KB-256KB)
            GROUP6 = 0x40, //< SRAM GROUP6 powered down (256KB-288KB)
            GROUP7 = 0x80, //< SRAM GROUP7 powered down (288KB-320KB)
            GROUP8 = 0x100, //< SRAM GROUP8 powered down (320KB-352KB)
            GROUP9 = 0x200, //< SRAM GROUP9 powered down (352KB-384KB)
            SRAM64K = 0x3, //< Powerdown lower 64k SRAM (64KB-128KB)
            SRAM128K = 0xF, //< Powerdown lower 128k SRAM (64KB-192KB)
            ALLBUTLOWER32K = 0x3FE, //< All SRAM banks but lower 32k powered down (96KB-384KB).
            ALLBUTLOWER64K = 0x3FC, //< All banks but lower 64k powered down.
            ALLBUTLOWER128K = 0x3F0, //< All banks but lower 128k powered down.
            ALL = 0x3FF, //< All banks powered down.
        };
    
        /// power down DTCM in deep sleep
        enum class DTCMPWDSLPv : uint32_t {
            NONE = 0x0, //< All DTCM retained
            GROUP0DTCM0 = 0x1, //< Group0_DTCM0 powered down in deep sleep (0KB-8KB)
            GROUP0DTCM1 = 0x2, //< Group0_DTCM1 powered down in deep sleep (8KB-32KB)
            GROUP0 = 0x3, //< Both DTCMs in group0 are powered down in deep sleep (0KB-32KB)
            ALLBUTGROUP0DTCM0 = 0x6, //< Group1 and Group0_DTCM1 are powered down in deep sleep (8KB-64KB)
            GROUP1 = 0x4, //< Group1 DTCM powered down in deep sleep (32KB-64KB)
            ALL = 0x7, //< All DTCMs powered down in deep sleep (0KB-64KB)
        };
    
        /// Power up SRAM groups
        enum class SRAMv : uint32_t {
            NONE = 0x0, //< Do not power ON any of the SRAM banks
            GROUP0 = 0x1, //< Power ON only SRAM group0 (0KB-32KB)
            GROUP1 = 0x2, //< Power ON only SRAM group1 (32KB-64KB)
            GROUP2 = 0x4, //< Power ON only SRAM group2 (64KB-96KB)
            GROUP3 = 0x8, //< Power ON only SRAM group3 (96KB-128KB)
            GROUP4 = 0x10, //< Power ON only SRAM group4 (128KB-160KB)
            GROUP5 = 0x20, //< Power ON only SRAM group5 (160KB-192KB)
            GROUP6 = 0x40, //< Power ON only SRAM group6 (192KB-224KB)
            GROUP7 = 0x80, //< Power ON only SRAM group7 (224KB-256KB)
            GROUP8 = 0x100, //< Power ON only SRAM group8 (256KB-288KB)
            GROUP9 = 0x200, //< Power ON only SRAM group9 (288KB-320KB)
            SRAM64K = 0x3, //< Power ON only lower 64k
            SRAM128K = 0xF, //< Power ON only lower 128k
            SRAM256K = 0xFF, //< Power ON only lower 256k
            ALL = 0x3FF, //< All SRAM banks (320K) powered ON
        };
    
        /// Power up DTCM
        enum class DTCMv : uint32_t {
            NONE = 0x0, //< Do not enable power to any DTCMs
            GROUP0DTCM0 = 0x1, //< Power ON only GROUP0_DTCM0
            GROUP0DTCM1 = 0x2, //< Power ON only GROUP0_DTCM1
            GROUP0 = 0x3, //< Power ON only DTCMs in group0
            GROUP1 = 0x4, //< Power ON only DTCMs in group1
            ALL = 0x7, //< Power ON all DTCMs
        };
    
        /// Light Sleep enable for each TCM/SRAM bank.  When 1, corresponding bank will be put into light sleep.  For optimal power, banks should be put into light sleep while the system is active but the bank has minimal or no accesses.
        enum class SRAMLIGHTSLEEPv : uint32_t {
            ALL = 0xFF, //< Enable LIGHT SLEEP for ALL SRAMs
            DIS = 0x0, //< Disables LIGHT SLEEP for ALL SRAMs
        };
    
        /// Control SRAM power-on status event
        enum class SRAMENv : uint32_t {
            NONE = 0x0, //< Disable SRAM power-on status event
            GROUP0EN = 0x1, //< Enable SRAM group0 (0KB-32KB) power on status event
            GROUP1EN = 0x2, //< Enable SRAM group1 (32KB-64KB) power on status event
            GROUP2EN = 0x4, //< Enable SRAM group2 (64KB-96KB) power on status event
            GROUP3EN = 0x8, //< Enable SRAM group3 (96KB-128KB) power on status event
            GROUP4EN = 0x10, //< Enable SRAM group4 (128KB-160KB) power on status event
            GROUP5EN = 0x20, //< Enable SRAM group5 (160KB-192KB) power on status event
            GROUP6EN = 0x40, //< Enable SRAM group6 (192KB-224KB) power on status event
            GROUP7EN = 0x80, //< Enable SRAM group7 (224KB-256KB) power on status event
            GROUP8EN = 0x100, //< Enable SRAM group8 (256KB-288KB) power on status event
            GROUP9EN = 0x200, //< Enable SRAM group9 (288KB-320KB) power on status event
        };
    
        /// Enable DTCM power-on status event
        enum class DTCMENv : uint32_t {
            NONE = 0x0, //< Do not enable DTCM power-on status event
            GROUP0DTCM0EN = 0x1, //< Enable GROUP0_DTCM0 power on status event
            GROUP0DTCM1EN = 0x2, //< Enable GROUP0_DTCM1 power on status event
            GROUP0EN = 0x3, //< Enable DTCMs in group0 power on status event
            GROUP1EN = 0x4, //< Enable DTCMs in group1 power on status event
            ALL = 0x7, //< Enable all DTCM power on status event
        };
    
    }   // namespace PWRCTRL

    /// PWR Controller Register Bank
    template <addressType BASE_ADDRESS>
    struct PWRCTRL_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * SUPPLYSRC - 4 bytes at offset 0
         * Voltage Regulator Select Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SUPPLYSRC_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables and Selects the BLE Buck as the supply for the BLE power domain or for Burst LDO. It takes the initial value from Customer INFO space. Buck will be powered up only if there is an active request for BLEH domain or Burst mode and appropriate feature is allowed.
            static constexpr bitfield_t<SUPPLYSRC_t, 0, 0, bool> BLEBUCKEN = {};
        } SUPPLYSRC = {};

        /**
         * SUPPLYSTATUS - 4 bytes at offset 4
         * Voltage Regulators status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SUPPLYSTATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// Indicates whether the BLE (if supported) domain and burst (if supported) domain is supplied from the LDO or the Buck. Buck will be powered up only if there is an active request for BLEH domain or Burst mode and appropriate reature is allowed.
            static constexpr bitfield_t<SUPPLYSTATUS_t, 1, 1, bool> BLEBUCKON = {};

            /// Indicates whether the Core/Mem low-voltage domains are supplied from the LDO or the Buck.
            static constexpr bitfield_t<SUPPLYSTATUS_t, 0, 0, bool> SIMOBUCKON = {};
        } SUPPLYSTATUS = {};

        /**
         * DEVPWREN - 4 bytes at offset 8
         * Device Power Enables
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEVPWREN_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Power up BLE controller
            static constexpr bitfield_t<DEVPWREN_t, 13, 13, bool> PWRBLEL = {};

            /// Power up PDM block
            static constexpr bitfield_t<DEVPWREN_t, 12, 12, bool> PWRPDM = {};

            /// Power up MSPI Controller
            static constexpr bitfield_t<DEVPWREN_t, 11, 11, bool> PWRMSPI = {};

            /// Power up SCARD Controller
            static constexpr bitfield_t<DEVPWREN_t, 10, 10, bool> PWRSCARD = {};

            /// Power up ADC Digital Controller
            static constexpr bitfield_t<DEVPWREN_t, 9, 9, bool> PWRADC = {};

            /// Power up UART Controller 1
            static constexpr bitfield_t<DEVPWREN_t, 8, 8, bool> PWRUART1 = {};

            /// Power up UART Controller 0
            static constexpr bitfield_t<DEVPWREN_t, 7, 7, bool> PWRUART0 = {};

            /// Power up IO Master 5
            static constexpr bitfield_t<DEVPWREN_t, 6, 6, bool> PWRIOM5 = {};

            /// Power up IO Master 4
            static constexpr bitfield_t<DEVPWREN_t, 5, 5, bool> PWRIOM4 = {};

            /// Power up IO Master 3
            static constexpr bitfield_t<DEVPWREN_t, 4, 4, bool> PWRIOM3 = {};

            /// Power up IO Master 2
            static constexpr bitfield_t<DEVPWREN_t, 3, 3, bool> PWRIOM2 = {};

            /// Power up IO Master 1
            static constexpr bitfield_t<DEVPWREN_t, 2, 2, bool> PWRIOM1 = {};

            /// Power up IO Master 0
            static constexpr bitfield_t<DEVPWREN_t, 1, 1, bool> PWRIOM0 = {};

            /// Power up IO Slave
            static constexpr bitfield_t<DEVPWREN_t, 0, 0, bool> PWRIOS = {};
        } DEVPWREN = {};

        /**
         * MEMPWDINSLEEP - 4 bytes at offset 12
         * Powerdown SRAM banks in Deep Sleep mode
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MEMPWDINSLEEP_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0x80007FFF;
            static constexpr uint32_t reset_value = 0x6000;

            /// power down cache in deep sleep
            static constexpr bitfield_t<MEMPWDINSLEEP_t, 31, 31, bool> CACHEPWDSLP = {};

            /// Powerdown flash1 in deep sleep
            static constexpr bitfield_t<MEMPWDINSLEEP_t, 14, 14, bool> FLASH1PWDSLP = {};

            /// Powerdown flash0 in deep sleep
            static constexpr bitfield_t<MEMPWDINSLEEP_t, 13, 13, bool> FLASH0PWDSLP = {};

            /// Selects which SRAM banks are powered down in deep sleep mode, causing the contents of the bank to be lost.
            static constexpr bitfield_t<MEMPWDINSLEEP_t, 12, 3, PWRCTRL::SRAMPWDSLPv> SRAMPWDSLP = {};

            /// power down DTCM in deep sleep
            static constexpr bitfield_t<MEMPWDINSLEEP_t, 2, 0, PWRCTRL::DTCMPWDSLPv> DTCMPWDSLP = {};
        } MEMPWDINSLEEP = {};

        /**
         * MEMPWREN - 4 bytes at offset 16
         * Enables individual banks of the MEMORY array
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MEMPWREN_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0xC0007FFF;
            static constexpr uint32_t reset_value = 0xC0007FFF;

            /// Power up Cache Bank 2. This works in conjunction with Cache enable from flash_cache module. To power up cache bank2, cache has to be enabled and this bit has to be set.
            static constexpr bitfield_t<MEMPWREN_t, 31, 31, bool> CACHEB2 = {};

            /// Power up Cache Bank 0. This works in conjunction with Cache enable from flash_cache module. To power up cache bank0, cache has to be enabled and this bit has to be set.
            static constexpr bitfield_t<MEMPWREN_t, 30, 30, bool> CACHEB0 = {};

            /// Power up Flash1
            static constexpr bitfield_t<MEMPWREN_t, 14, 14, bool> FLASH1 = {};

            /// Power up Flash0
            static constexpr bitfield_t<MEMPWREN_t, 13, 13, bool> FLASH0 = {};

            /// Power up SRAM groups
            static constexpr bitfield_t<MEMPWREN_t, 12, 3, PWRCTRL::SRAMv> SRAM = {};

            /// Power up DTCM
            static constexpr bitfield_t<MEMPWREN_t, 2, 0, PWRCTRL::DTCMv> DTCM = {};
        } MEMPWREN = {};

        /**
         * MEMPWRSTATUS - 4 bytes at offset 20
         * Mem Power ON Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MEMPWRSTATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFFF;
            static constexpr uint32_t reset_value = 0x7FFF;

            /// This bit is 1 if power is supplied to Cache Bank 2
            static constexpr bitfield_t<MEMPWRSTATUS_t, 16, 16, bool> CACHEB2 = {};

            /// This bit is 1 if power is supplied to Cache Bank 0
            static constexpr bitfield_t<MEMPWRSTATUS_t, 15, 15, bool> CACHEB0 = {};

            /// This bit is 1 if power is supplied to FLASH 1
            static constexpr bitfield_t<MEMPWRSTATUS_t, 14, 14, bool> FLASH1 = {};

            /// This bit is 1 if power is supplied to FLASH 0
            static constexpr bitfield_t<MEMPWRSTATUS_t, 13, 13, bool> FLASH0 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP9
            static constexpr bitfield_t<MEMPWRSTATUS_t, 12, 12, bool> SRAM9 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP8
            static constexpr bitfield_t<MEMPWRSTATUS_t, 11, 11, bool> SRAM8 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP7
            static constexpr bitfield_t<MEMPWRSTATUS_t, 10, 10, bool> SRAM7 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP6
            static constexpr bitfield_t<MEMPWRSTATUS_t, 9, 9, bool> SRAM6 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP5
            static constexpr bitfield_t<MEMPWRSTATUS_t, 8, 8, bool> SRAM5 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP4
            static constexpr bitfield_t<MEMPWRSTATUS_t, 7, 7, bool> SRAM4 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP3
            static constexpr bitfield_t<MEMPWRSTATUS_t, 6, 6, bool> SRAM3 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP2
            static constexpr bitfield_t<MEMPWRSTATUS_t, 5, 5, bool> SRAM2 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP1
            static constexpr bitfield_t<MEMPWRSTATUS_t, 4, 4, bool> SRAM1 = {};

            /// This bit is 1 if power is supplied to SRAM GROUP0
            static constexpr bitfield_t<MEMPWRSTATUS_t, 3, 3, bool> SRAM0 = {};

            /// This bit is 1 if power is supplied to DTCM GROUP1
            static constexpr bitfield_t<MEMPWRSTATUS_t, 2, 2, bool> DTCM1 = {};

            /// This bit is 1 if power is supplied to DTCM GROUP0_1
            static constexpr bitfield_t<MEMPWRSTATUS_t, 1, 1, bool> DTCM01 = {};

            /// This bit is 1 if power is supplied to DTCM GROUP0_0
            static constexpr bitfield_t<MEMPWRSTATUS_t, 0, 0, bool> DTCM00 = {};
        } MEMPWRSTATUS = {};

        /**
         * DEVPWRSTATUS - 4 bytes at offset 24
         * Device Power ON Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEVPWRSTATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x3;

            /// This bit is 1 if power is supplied to BLEH
            static constexpr bitfield_t<DEVPWRSTATUS_t, 9, 9, bool> BLEH = {};

            /// This bit is 1 if power is supplied to BLEL
            static constexpr bitfield_t<DEVPWRSTATUS_t, 8, 8, bool> BLEL = {};

            /// This bit is 1 if power is supplied to PDM
            static constexpr bitfield_t<DEVPWRSTATUS_t, 7, 7, bool> PWRPDM = {};

            /// This bit is 1 if power is supplied to MSPI
            static constexpr bitfield_t<DEVPWRSTATUS_t, 6, 6, bool> PWRMSPI = {};

            /// This bit is 1 if power is supplied to ADC
            static constexpr bitfield_t<DEVPWRSTATUS_t, 5, 5, bool> PWRADC = {};

            /// This bit is 1 if power is supplied to HCPC domain (IO MASTER4, 5, 6)
            static constexpr bitfield_t<DEVPWRSTATUS_t, 4, 4, bool> HCPC = {};

            /// This bit is 1 if power is supplied to HCPB domain (IO MASTER 0, 1, 2)
            static constexpr bitfield_t<DEVPWRSTATUS_t, 3, 3, bool> HCPB = {};

            /// This bit is 1 if power is supplied to HCPA domain (IO SLAVE, UART0, UART1, SCARD)
            static constexpr bitfield_t<DEVPWRSTATUS_t, 2, 2, bool> HCPA = {};

            /// This bit is 1 if power is supplied to MCUH
            static constexpr bitfield_t<DEVPWRSTATUS_t, 1, 1, bool> MCUH = {};

            /// This bit is 1 if power is supplied to MCUL
            static constexpr bitfield_t<DEVPWRSTATUS_t, 0, 0, bool> MCUL = {};
        } DEVPWRSTATUS = {};

        /**
         * SRAMCTRL - 4 bytes at offset 28
         * SRAM Control register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SRAMCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFF06;
            static constexpr uint32_t reset_value = 0x0;

            /// Light Sleep enable for each TCM/SRAM bank.  When 1, corresponding bank will be put into light sleep.  For optimal power, banks should be put into light sleep while the system is active but the bank has minimal or no accesses.
            static constexpr bitfield_t<SRAMCTRL_t, 19, 8, PWRCTRL::SRAMLIGHTSLEEPv> SRAMLIGHTSLEEP = {};

            /// This bit is 1 when the master clock gate is enabled (top-level clock gate for entire SRAM block)
            static constexpr bitfield_t<SRAMCTRL_t, 2, 2, bool> SRAMMASTERCLKGATE = {};

            /// This bit is 1 if clock gating is allowed for individual system SRAMs
            static constexpr bitfield_t<SRAMCTRL_t, 1, 1, bool> SRAMCLKGATE = {};
        } SRAMCTRL = {};

        /**
         * ADCSTATUS - 4 bytes at offset 32
         * Power Status Register for ADC Block
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADCSTATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// This bit indicates that the ADC REFBUF is powered down
            static constexpr bitfield_t<ADCSTATUS_t, 5, 5, bool> REFBUFPWD = {};

            /// This bit indicates that the ADC REFKEEP is powered down
            static constexpr bitfield_t<ADCSTATUS_t, 4, 4, bool> REFKEEPPWD = {};

            /// This bit indicates that the ADC VBAT resistor divider is powered down
            static constexpr bitfield_t<ADCSTATUS_t, 3, 3, bool> VBATPWD = {};

            /// This bit indicates that the ADC temperature sensor input buffer is powered down
            static constexpr bitfield_t<ADCSTATUS_t, 2, 2, bool> VPTATPWD = {};

            /// This bit indicates that the ADC Band Gap is powered down
            static constexpr bitfield_t<ADCSTATUS_t, 1, 1, bool> BGTPWD = {};

            /// This bit indicates that the ADC is powered down
            static constexpr bitfield_t<ADCSTATUS_t, 0, 0, bool> ADCPWD = {};
        } ADCSTATUS = {};

        /**
         * MISC - 4 bytes at offset 36
         * Power Optimization Control Bits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MISC_t : reg_t<uint32_t, BASE_ADDRESS + 0x24> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x24>::operator=;
            static constexpr uint32_t reset_mask  = 0x48;
            static constexpr uint32_t reset_value = 0x0;

            /// Control Bit to let Mem VR go to lp mode in deep sleep even when BLEL or BLEH is powered on given none of the other domains require it.
            static constexpr bitfield_t<MISC_t, 6, 6, bool> MEMVRLPBLE = {};

            /// Control Bit to force Mem VR to LP mode in deep sleep even when hfrc based ctimer or stimer is running.
            static constexpr bitfield_t<MISC_t, 3, 3, bool> FORCEMEMVRLPTIMERS = {};
        } MISC = {};

        /**
         * DEVPWREVENTEN - 4 bytes at offset 40
         * Event enable register to control which DEVPWRSTATUS bits are routed to event input of CPU.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEVPWREVENTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0xE00001FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Control BURST status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 31, 31, bool> BURSTEVEN = {};

            /// Control BURSTFEATURE status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 30, 30, bool> BURSTFEATUREEVEN = {};

            /// Control BLEFEATURE status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 29, 29, bool> BLEFEATUREEVEN = {};

            /// Control BLE power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 8, 8, bool> BLELEVEN = {};

            /// Control PDM power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 7, 7, bool> PDMEVEN = {};

            /// Control MSPI power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 6, 6, bool> MSPIEVEN = {};

            /// Control ADC power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 5, 5, bool> ADCEVEN = {};

            /// Control HCPC power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 4, 4, bool> HCPCEVEN = {};

            /// Control HCPB power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 3, 3, bool> HCPBEVEN = {};

            /// Control HCPA power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 2, 2, bool> HCPAEVEN = {};

            /// Control MCUH power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 1, 1, bool> MCUHEVEN = {};

            /// Control MCUL power-on status event
            static constexpr bitfield_t<DEVPWREVENTEN_t, 0, 0, bool> MCULEVEN = {};
        } DEVPWREVENTEN = {};

        /**
         * MEMPWREVENTEN - 4 bytes at offset 44
         * Event enable register to control which MEMPWRSTATUS bits are routed to event input of CPU.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MEMPWREVENTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0xC0007FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Control CACHEB2 power-on status event
            static constexpr bitfield_t<MEMPWREVENTEN_t, 31, 31, bool> CACHEB2EN = {};

            /// Control CACHE BANK 0 power-on status event
            static constexpr bitfield_t<MEMPWREVENTEN_t, 30, 30, bool> CACHEB0EN = {};

            /// Control Flash power-on status event
            static constexpr bitfield_t<MEMPWREVENTEN_t, 14, 14, bool> FLASH1EN = {};

            /// Control Flash power-on status event
            static constexpr bitfield_t<MEMPWREVENTEN_t, 13, 13, bool> FLASH0EN = {};

            /// Control SRAM power-on status event
            static constexpr bitfield_t<MEMPWREVENTEN_t, 12, 3, PWRCTRL::SRAMENv> SRAMEN = {};

            /// Enable DTCM power-on status event
            static constexpr bitfield_t<MEMPWREVENTEN_t, 2, 0, PWRCTRL::DTCMENv> DTCMEN = {};
        } MEMPWREVENTEN = {};
    };  // end of struct PWRCTRL_t

} // namespace sfr