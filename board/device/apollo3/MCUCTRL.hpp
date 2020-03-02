/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: MCUCTRL
 * MCU Miscellaneous Control Logic
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace MCUCTRL {
    
        /// BCD part number.
        enum class PARTNUMv : uint32_t {
            APOLLO3 = 0x6000000, //< Apollo3 Blue part number is 0x06xxxxxx.
            APOLLO2 = 0x3000000, //< Apollo2 part number is 0x03xxxxxx.
            APOLLO = 0x1000000, //< Apollo part number is 0x01xxxxxx.
            PN_M = 0xFF000000, //< Mask for the part number field.
            PN_S = 0x18, //< Bit position for the part number field.
            FLASHSIZE_M = 0xF00000, //< Mask for the FLASH_SIZE field. Values: 0: 16KB 1: 32KB 2: 64KB 3: 128KB 4: 256KB 5: 512KB 6: 1MB 7: 2MB
            FLASHSIZE_S = 0x14, //< Bit position for the FLASH_SIZE field.
            SRAMSIZE_M = 0xF0000, //< Mask for the SRAM_SIZE field. Values: 0: 16KB 1: 32KB 2: 64KB 3: 128KB 4: 256KB 5: 512KB 6: 1MB 7: 384KB 8: 768KB
            SRAMSIZE_S = 0x10, //< Bit position for the SRAM_SIZE field.
            REV_M = 0xFF00, //< Mask for the revision field. Bits [15:12] are major rev, [11:8] are minor rev. Values: 0: Major Rev A, Minor Rev 0 1: Major Rev B, Minor Rev 1
            REV_S = 0x8, //< Bit position for the revision field.
            PKG_M = 0xC0, //< Mask for the package field. Values: 0: SIP 1: QFN 2: BGA 3: CSP
            PKG_S = 0x6, //< Bit position for the package field.
            PINS_M = 0x38, //< Mask for the pins field. Values: 0: 25 pins 1: 49 pins 2: 64 pins 3: 81 pins 4: 104 pins
            PINS_S = 0x3, //< Bit position for the pins field.
            TEMP_S = 0x1, //< Bit position for the temperature field.
            QUAL_S = 0x0, //< Bit position for the qualified field.
        };
    
        /// Unique chip ID 0.
        enum class CHIPID0v : uint32_t {
            APOLLO3 = 0x0, //< Apollo3 Blue Plus CHIPID0.
        };
    
        /// Unique chip ID 1.
        enum class CHIPID1v : uint32_t {
            APOLLO3 = 0x0, //< Apollo3 Blue Plus CHIPID1.
        };
    
        /// Major Revision ID.
        enum class REVMAJv : uint32_t {
            B = 0x2, //< Apollo3 Blue revision B
            A = 0x1, //< Apollo3 Blue revision A
        };
    
        /// Minor Revision ID.
        enum class REVMINv : uint32_t {
            REV1 = 0x2, //< Apollo3 Blue minor rev 1.
            REV0 = 0x1, //< Apollo3 Blue minor rev 0.  Minor revision value, succeeding minor revisions will increment from this value.
        };
    
        /// Unique Vendor ID
        enum class VENDORIDv : uint32_t {
            AMBIQ = 0x414D4251, //< Ambiq Vendor ID 'AMBQ'
        };
    
        /// Auto-calibration delay control
        enum class ACWARMUPv : uint32_t {
            SEC1 = 0x0, //< Warm-up period of 1-2 seconds
            SEC2 = 0x1, //< Warm-up period of 2-4 seconds
            SEC4 = 0x2, //< Warm-up period of 4-8 seconds
            SEC8 = 0x3, //< Warm-up period of 8-16 seconds
        };
    
        /// Indicates whether the secure boot on warm reset is enabled
        enum class SECBOOTONRSTv : uint32_t {
            DISABLED = 0x0, //< Secure boot disabled
            ENABLED = 0x1, //< Secure boot enabled
            ERROR = 0x2, //< Error in secure boot configuration
        };
    
        /// Indicates whether the secure boot on cold reset is enabled
        enum class SECBOOTv : uint32_t {
            DISABLED = 0x0, //< Secure boot disabled
            ENABLED = 0x1, //< Secure boot enabled
            ERROR = 0x2, //< Error in secure boot configuration
        };
    
        /// Indicates whether the secure boot feature is enabled.
        enum class SECBOOTFEATUREv : uint32_t {
            DISABLED = 0x0, //< Secure boot disabled
            ENABLED = 0x1, //< Secure boot enabled
            ERROR = 0x2, //< Error in secure boot configuration
        };
    
        /// This field selects the frequency of the ARM M4 TPIU port.
        enum class CLKSELv : uint32_t {
            LOWPWR = 0x0, //< Low power state.
            HFRCDIV2 = 0x1, //< Selects HFRC divided by 2 as the source TPIU clock
            HFRCDIV8 = 0x2, //< Selects HFRC divided by 8 as the source TPIU clock
            HFRCDIV16 = 0x3, //< Selects HFRC divided by 16 as the source TPIU clock
            HFRCDIV32 = 0x4, //< Selects HFRC divided by 32 as the source TPIU clock
        };
    
        /// Key register value.
        enum class KEXTCLKSELv : uint32_t {
            Key = 0x53, //< Key
        };
    
    }   // namespace MCUCTRL

    /// MCU Miscellaneous Control Logic
    template <addressType BASE_ADDRESS>
    struct MCUCTRL_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CHIPPN - 4 bytes at offset 0
         * Chip Information Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CHIPPN_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x4000000;

            /// BCD part number.
            static constexpr bitfield_t<CHIPPN_t, 31, 0, MCUCTRL::PARTNUMv> PARTNUM = {};
        } CHIPPN = {};

        /**
         * CHIPID0 - 4 bytes at offset 4
         * Unique Chip ID 0
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CHIPID0_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Unique chip ID 0.
            static constexpr bitfield_t<CHIPID0_t, 31, 0, MCUCTRL::CHIPID0v> CHIPID0 = {};
        } CHIPID0 = {};

        /**
         * CHIPID1 - 4 bytes at offset 8
         * Unique Chip ID 1
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CHIPID1_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Unique chip ID 1.
            static constexpr bitfield_t<CHIPID1_t, 31, 0, MCUCTRL::CHIPID1v> CHIPID1 = {};
        } CHIPID1 = {};

        /**
         * CHIPREV - 4 bytes at offset 12
         * Chip Revision
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CHIPREV_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFF;
            static constexpr uint32_t reset_value = 0x1;

            /// Silicon Part ID
            static constexpr bitfield_t<CHIPREV_t, 19, 8> SIPART = {};

            /// Major Revision ID.
            static constexpr bitfield_t<CHIPREV_t, 7, 4, MCUCTRL::REVMAJv> REVMAJ = {};

            /// Minor Revision ID.
            static constexpr bitfield_t<CHIPREV_t, 3, 0, MCUCTRL::REVMINv> REVMIN = {};
        } CHIPREV = {};

        /**
         * VENDORID - 4 bytes at offset 16
         * Unique Vendor ID
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct VENDORID_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Unique Vendor ID
            static constexpr bitfield_t<VENDORID_t, 31, 0, MCUCTRL::VENDORIDv> VENDORID = {};
        } VENDORID = {};

        /**
         * SKU - 4 bytes at offset 20
         * Unique Chip SKU
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SKU_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// Secure boot feature allowed
            static constexpr bitfield_t<SKU_t, 2, 2, bool> SECBOOT = {};

            /// Allow BLE feature
            static constexpr bitfield_t<SKU_t, 1, 1, bool> ALLOWBLE = {};

            /// Allow Burst feature
            static constexpr bitfield_t<SKU_t, 0, 0, bool> ALLOWBURST = {};
        } SKU = {};

        /**
         * FEATUREENABLE - 4 bytes at offset 24
         * Feature Enable on Burst and BLE
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FEATUREENABLE_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x77;
            static constexpr uint32_t reset_value = 0x1;

            /// Availability of Burst functionality
            static constexpr bitfield_t<FEATUREENABLE_t, 6, 6, bool> BURSTAVAIL = {};

            /// ACK for BURSTREQ
            static constexpr bitfield_t<FEATUREENABLE_t, 5, 5, bool> BURSTACK = {};

            /// Controls the Burst functionality
            static constexpr bitfield_t<FEATUREENABLE_t, 4, 4, bool> BURSTREQ = {};

            /// AVAILABILITY of the BLE functionality
            static constexpr bitfield_t<FEATUREENABLE_t, 2, 2, bool> BLEAVAIL = {};

            /// ACK for BLEREQ
            static constexpr bitfield_t<FEATUREENABLE_t, 1, 1, bool> BLEACK = {};

            /// Controls the BLE functionality
            static constexpr bitfield_t<FEATUREENABLE_t, 0, 0, bool> BLEREQ = {};
        } FEATUREENABLE = {};

        /**
         * DEBUGGER - 4 bytes at offset 32
         * Debugger Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEBUGGER_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Lockout of debugger (SWD).
            static constexpr bitfield_t<DEBUGGER_t, 0, 0, bool> LOCKOUT = {};
        } DEBUGGER = {};

        /**
         * BODCTRL - 4 bytes at offset 256
         * BOD control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BODCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x0;

            /// BODH External Reference Select. Note: the SWE mux select in PWRSEQ2SWE must be set for this to take effect.
            static constexpr bitfield_t<BODCTRL_t, 5, 5, bool> BODHVREFSEL = {};

            /// BODL External Reference Select. Note: the SWE mux select in PWRSEQ2SWE must be set for this to take effect.
            static constexpr bitfield_t<BODCTRL_t, 4, 4, bool> BODLVREFSEL = {};

            /// BODF Power Down.
            static constexpr bitfield_t<BODCTRL_t, 3, 3, bool> BODFPWD = {};

            /// BODC Power Down.
            static constexpr bitfield_t<BODCTRL_t, 2, 2, bool> BODCPWD = {};

            /// BODH Power Down.
            static constexpr bitfield_t<BODCTRL_t, 1, 1, bool> BODHPWD = {};

            /// BODL Power Down.
            static constexpr bitfield_t<BODCTRL_t, 0, 0, bool> BODLPWD = {};
        } BODCTRL = {};

        /**
         * ADCPWRDLY - 4 bytes at offset 260
         * ADC Power Up Delay Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADCPWRDLY_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// ADC Reference Keeper enable delay in 16 ADC CLK increments for ADC_CLKSEL = 0x1, 8 ADC CLOCK increments for ADC_CLKSEL = 0x2.
            static constexpr bitfield_t<ADCPWRDLY_t, 15, 8> ADCPWR1 = {};

            /// ADC Reference Buffer Power Enable delay in 64 ADC CLK increments for ADC_CLKSEL = 0x1, 32 ADC CLOCK increments for ADC_CLKSEL = 0x2.
            static constexpr bitfield_t<ADCPWRDLY_t, 7, 0> ADCPWR0 = {};
        } ADCPWRDLY = {};

        /**
         * ADCCAL - 4 bytes at offset 268
         * ADC Calibration Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADCCAL_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x1;

            /// Status for ADC Calibration
            static constexpr bitfield_t<ADCCAL_t, 1, 1, bool> ADCCALIBRATED = {};

            /// Run ADC Calibration on initial power up sequence
            static constexpr bitfield_t<ADCCAL_t, 0, 0, bool> CALONPWRUP = {};
        } ADCCAL = {};

        /**
         * ADCBATTLOAD - 4 bytes at offset 272
         * ADC Battery Load Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADCBATTLOAD_t : reg_t<uint32_t, BASE_ADDRESS + 0x110> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x110>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Enable the ADC battery load resistor
            static constexpr bitfield_t<ADCBATTLOAD_t, 0, 0, bool> BATTLOAD = {};
        } ADCBATTLOAD = {};

        /**
         * ADCTRIM - 4 bytes at offset 280
         * ADC Trims
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADCTRIM_t : reg_t<uint32_t, BASE_ADDRESS + 0x118> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x118>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FC3;
            static constexpr uint32_t reset_value = 0x200;

            /// ADC reference buffer input bias trim
            static constexpr bitfield_t<ADCTRIM_t, 12, 11> ADCRFBUFIBTRIM = {};

            /// ADC Reference buffer trim
            static constexpr bitfield_t<ADCTRIM_t, 10, 6> ADCREFBUFTRIM = {};

            /// ADC Reference Ibias trim
            static constexpr bitfield_t<ADCTRIM_t, 1, 0> ADCREFKEEPIBTRIM = {};
        } ADCTRIM = {};

        /**
         * ADCREFCOMP - 4 bytes at offset 284
         * ADC Reference Keeper and Comparator Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADCREFCOMP_t : reg_t<uint32_t, BASE_ADDRESS + 0x11C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x11C>::operator=;
            static constexpr uint32_t reset_mask  = 0x11F01;
            static constexpr uint32_t reset_value = 0x0;

            /// ADC Reference comparator power down
            static constexpr bitfield_t<ADCREFCOMP_t, 16, 16, bool> ADCRFCMPEN = {};

            /// ADC Reference Keeper Trim
            static constexpr bitfield_t<ADCREFCOMP_t, 12, 8> ADCREFKEEPTRIM = {};

            /// Output of the ADC reference comparator
            static constexpr bitfield_t<ADCREFCOMP_t, 0, 0, bool> ADC_REFCOMP_OUT = {};
        } ADCREFCOMP = {};

        /**
         * XTALCTRL - 4 bytes at offset 288
         * XTAL Oscillator Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct XTALCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x120> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x120>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x358;

            /// XTAL ICOMP trim
            static constexpr bitfield_t<XTALCTRL_t, 9, 8> XTALICOMPTRIM = {};

            /// XTAL IBUFF trim
            static constexpr bitfield_t<XTALCTRL_t, 7, 6> XTALIBUFTRIM = {};

            /// XTAL Power down on brown out.
            static constexpr bitfield_t<XTALCTRL_t, 5, 5, bool> PWDBODXTAL = {};

            /// XTAL Oscillator Power Down Comparator.
            static constexpr bitfield_t<XTALCTRL_t, 4, 4, bool> PDNBCMPRXTAL = {};

            /// XTAL Oscillator Power Down Core.
            static constexpr bitfield_t<XTALCTRL_t, 3, 3, bool> PDNBCOREXTAL = {};

            /// XTAL Oscillator Bypass Comparator.
            static constexpr bitfield_t<XTALCTRL_t, 2, 2, bool> BYPCMPRXTAL = {};

            /// XTAL Oscillator Disable Feedback.
            static constexpr bitfield_t<XTALCTRL_t, 1, 1, bool> FDBKDSBLXTAL = {};

            /// XTAL Software Override Enable.
            static constexpr bitfield_t<XTALCTRL_t, 0, 0, bool> XTALSWE = {};
        } XTALCTRL = {};

        /**
         * XTALGENCTRL - 4 bytes at offset 292
         * XTAL Oscillator General Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct XTALGENCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x124> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x124>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFF;
            static constexpr uint32_t reset_value = 0x100;

            /// XTAL IBIAS Kick start trim. This trim value is used during the startup process to enable a faster lock.
            static constexpr bitfield_t<XTALGENCTRL_t, 13, 8> XTALKSBIASTRIM = {};

            /// XTAL BIAS trim
            static constexpr bitfield_t<XTALGENCTRL_t, 7, 2> XTALBIASTRIM = {};

            /// Auto-calibration delay control
            static constexpr bitfield_t<XTALGENCTRL_t, 1, 0, MCUCTRL::ACWARMUPv> ACWARMUP = {};
        } XTALGENCTRL = {};

        /**
         * MISCCTRL - 4 bytes at offset 408
         * Miscellaneous control register.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MISCCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x198> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x198>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x0;

            /// BLE reset signal.
            static constexpr bitfield_t<MISCCTRL_t, 5, 5, bool> BLE_RESETN = {};
        } MISCCTRL = {};

        /**
         * BOOTLOADER - 4 bytes at offset 416
         * Bootloader and secure boot functions
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BOOTLOADER_t : reg_t<uint32_t, BASE_ADDRESS + 0x1A0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1A0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFC000007;
            static constexpr uint32_t reset_value = 0x7;

            /// Indicates whether the secure boot on warm reset is enabled
            static constexpr bitfield_t<BOOTLOADER_t, 31, 30, MCUCTRL::SECBOOTONRSTv> SECBOOTONRST = {};

            /// Indicates whether the secure boot on cold reset is enabled
            static constexpr bitfield_t<BOOTLOADER_t, 29, 28, MCUCTRL::SECBOOTv> SECBOOT = {};

            /// Indicates whether the secure boot feature is enabled.
            static constexpr bitfield_t<BOOTLOADER_t, 27, 26, MCUCTRL::SECBOOTFEATUREv> SECBOOTFEATURE = {};

            /// Flash protection lock.  Always resets to 1, write 1 to clear.  Enables writes to flash protection register set.
            static constexpr bitfield_t<BOOTLOADER_t, 2, 2, bool> PROTLOCK = {};

            /// Secure boot lock.  Always resets to 1, write 1 to clear.  Enables system visibility to bootloader until set.
            static constexpr bitfield_t<BOOTLOADER_t, 1, 1, bool> SBLOCK = {};

            /// Determines whether the bootloader code is visible at address 0x00000000 or not.  Resets to 1, write 1 to clear.
            static constexpr bitfield_t<BOOTLOADER_t, 0, 0, bool> BOOTLOADERLOW = {};
        } BOOTLOADER = {};

        /**
         * SHADOWVALID - 4 bytes at offset 420
         * Register to indicate whether the shadow registers have been successfully loaded from the Flash Information Space.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SHADOWVALID_t : reg_t<uint32_t, BASE_ADDRESS + 0x1A4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1A4>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x7;

            /// Indicates whether INFO0 contains valid data
            static constexpr bitfield_t<SHADOWVALID_t, 2, 2, bool> INFO0_VALID = {};

            /// Indicates whether the bootloader should sleep or deep sleep if no image loaded.
            static constexpr bitfield_t<SHADOWVALID_t, 1, 1, bool> BLDSLEEP = {};

            /// Indicates whether the shadow registers contain valid data from the Flash Information Space.
            static constexpr bitfield_t<SHADOWVALID_t, 0, 0, bool> VALID = {};
        } SHADOWVALID = {};

        /**
         * SCRATCH0 - 4 bytes at offset 432
         * Scratch register that is not reset by any reset
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCRATCH0_t : reg_t<uint32_t, BASE_ADDRESS + 0x1B0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1B0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scratch register 0.
            static constexpr bitfield_t<SCRATCH0_t, 31, 0> SCRATCH0 = {};
        } SCRATCH0 = {};

        /**
         * SCRATCH1 - 4 bytes at offset 436
         * Scratch register that is not reset by any reset
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCRATCH1_t : reg_t<uint32_t, BASE_ADDRESS + 0x1B4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1B4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scratch register 1.
            static constexpr bitfield_t<SCRATCH1_t, 31, 0> SCRATCH1 = {};
        } SCRATCH1 = {};

        /**
         * ICODEFAULTADDR - 4 bytes at offset 448
         * ICODE bus address which was present when a bus fault occurred.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ICODEFAULTADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// The ICODE bus address observed when a Bus Fault occurred. Once an address is captured in this field, it is held until the corresponding Fault Observed bit is cleared in the FAULTSTATUS register.
            static constexpr bitfield_t<ICODEFAULTADDR_t, 31, 0> ICODEFAULTADDR = {};
        } ICODEFAULTADDR = {};

        /**
         * DCODEFAULTADDR - 4 bytes at offset 452
         * DCODE bus address which was present when a bus fault occurred.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DCODEFAULTADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// The DCODE bus address observed when a Bus Fault occurred. Once an address is captured in this field, it is held until the corresponding Fault Observed bit is cleared in the FAULTSTATUS register.
            static constexpr bitfield_t<DCODEFAULTADDR_t, 31, 0> DCODEFAULTADDR = {};
        } DCODEFAULTADDR = {};

        /**
         * SYSFAULTADDR - 4 bytes at offset 456
         * System bus address which was present when a bus fault occurred.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SYSFAULTADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// SYS bus address observed when a Bus Fault occurred. Once an address is captured in this field, it is held until the corresponding Fault Observed bit is cleared in the FAULTSTATUS register.
            static constexpr bitfield_t<SYSFAULTADDR_t, 31, 0> SYSFAULTADDR = {};
        } SYSFAULTADDR = {};

        /**
         * FAULTSTATUS - 4 bytes at offset 460
         * Reflects the status of the bus decoders' fault detection. Any write to this register will clear all of the status bits within the register.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FAULTSTATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x1CC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1CC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// SYS Bus Decoder Fault Detected bit. When set, a fault has been detected, and the SYSFAULTADDR register will contain the bus address which generated the fault.
            static constexpr bitfield_t<FAULTSTATUS_t, 2, 2, bool> SYSFAULT = {};

            /// DCODE Bus Decoder Fault Detected bit. When set, a fault has been detected, and the DCODEFAULTADDR register will contain the bus address which generated the fault.
            static constexpr bitfield_t<FAULTSTATUS_t, 1, 1, bool> DCODEFAULT = {};

            /// The ICODE Bus Decoder Fault Detected bit. When set, a fault has been detected, and the ICODEFAULTADDR register will contain the bus address which generated the fault.
            static constexpr bitfield_t<FAULTSTATUS_t, 0, 0, bool> ICODEFAULT = {};
        } FAULTSTATUS = {};

        /**
         * FAULTCAPTUREEN - 4 bytes at offset 464
         * Enable the fault capture registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FAULTCAPTUREEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x1D0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1D0>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Fault Capture Enable field. When set, the Fault Capture monitors are enabled and addresses which generate a hard fault are captured into the FAULTADDR registers.
            static constexpr bitfield_t<FAULTCAPTUREEN_t, 0, 0, bool> FAULTCAPTUREEN = {};
        } FAULTCAPTUREEN = {};

        /**
         * DBGR1 - 4 bytes at offset 512
         * Read-only debug register 1
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DBGR1_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x12345678;

            /// Read-only register for communication validation
            static constexpr bitfield_t<DBGR1_t, 31, 0> ONETO8 = {};
        } DBGR1 = {};

        /**
         * DBGR2 - 4 bytes at offset 516
         * Read-only debug register 2
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DBGR2_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0xC001C0DE;

            /// Read-only register for communication validation
            static constexpr bitfield_t<DBGR2_t, 31, 0> COOLCODE = {};
        } DBGR2 = {};

        /**
         * PMUENABLE - 4 bytes at offset 544
         * Control bit to enable/disable the PMU
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PMUENABLE_t : reg_t<uint32_t, BASE_ADDRESS + 0x220> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x220>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x1;

            /// PMU Enable Control bit. When set, the MCU's PMU will place the MCU into the lowest power consuming Deep Sleep mode upon execution of a WFI instruction (dependent on the setting of the SLEEPDEEP bit in the ARM SCR register). When cleared, regardless of the requested sleep mode, the PMU will not enter the lowest power Deep Sleep mode, instead entering the Sleep mode.
            static constexpr bitfield_t<PMUENABLE_t, 0, 0, bool> ENABLE = {};
        } PMUENABLE = {};

        /**
         * TPIUCTRL - 4 bytes at offset 592
         * TPIU Control Register. Determines the clock enable and frequency for the M4's TPIU interface.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TPIUCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x250> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x250>::operator=;
            static constexpr uint32_t reset_mask  = 0x701;
            static constexpr uint32_t reset_value = 0x0;

            /// This field selects the frequency of the ARM M4 TPIU port.
            static constexpr bitfield_t<TPIUCTRL_t, 10, 8, MCUCTRL::CLKSELv> CLKSEL = {};

            /// TPIU Enable field. When set, the ARM M4 TPIU is enabled and data can be streamed out of the MCU's SWO port using the ARM ITM and TPIU modules.
            static constexpr bitfield_t<TPIUCTRL_t, 0, 0, bool> ENABLE = {};
        } TPIUCTRL = {};

        /**
         * OTAPOINTER - 4 bytes at offset 612
         * OTA (Over the Air) Update Pointer/Status.  Reset only by POA
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OTAPOINTER_t : reg_t<uint32_t, BASE_ADDRESS + 0x264> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x264>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Flash page pointer with updated OTA image
            static constexpr bitfield_t<OTAPOINTER_t, 31, 2> OTAPOINTER = {};

            /// Indicates that the sbl_init has been updated
            static constexpr bitfield_t<OTAPOINTER_t, 1, 1, bool> OTASBLUPDATE = {};

            /// Indicates that an OTA update is valid
            static constexpr bitfield_t<OTAPOINTER_t, 0, 0, bool> OTAVALID = {};
        } OTAPOINTER = {};

        /**
         * APBDMACTRL - 4 bytes at offset 640
         * DMA Control Register. Determines misc settings for DMA operation
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct APBDMACTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x280> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x280>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF03;
            static constexpr uint32_t reset_value = 0x203;

            /// This field determines how long the DMA will remain active during deep sleep before shutting down and returning the system to full deep sleep. Values are based on a 94KHz clock and are roughly 10 us increments for a range of ~10 us to 2.55 ms
            static constexpr bitfield_t<APBDMACTRL_t, 15, 8> HYSTERESIS = {};

            /// APB Decode Abort. When set, the APB bridge will issue a data abort (bus fault) on transactions to peripherals that are powered down. When set to 0, writes are quietly discarded and reads return 0.
            static constexpr bitfield_t<APBDMACTRL_t, 1, 1, bool> DECODEABORT = {};

            /// Enable the DMA controller.  When disabled, DMA requests will be ignored by the controller
            static constexpr bitfield_t<APBDMACTRL_t, 0, 0, bool> DMA_ENABLE = {};
        } APBDMACTRL = {};

        /**
         * SRAMMODE - 4 bytes at offset 644
         * SRAM Controller mode bits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SRAMMODE_t : reg_t<uint32_t, BASE_ADDRESS + 0x284> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x284>::operator=;
            static constexpr uint32_t reset_mask  = 0x33;
            static constexpr uint32_t reset_value = 0x0;

            /// Secondary pre-fetch feature that will cache pre-fetched data across bus wait states (requires DPREFETCH to be set).
            static constexpr bitfield_t<SRAMMODE_t, 5, 5, bool> DPREFETCH_CACHE = {};

            /// When set, data bus accesses to the SRAM banks will be pre-fetched (normally 2 cycle read access).  Use of this mode bit is only recommended if the work flow has a large number of sequential accesses.
            static constexpr bitfield_t<SRAMMODE_t, 4, 4, bool> DPREFETCH = {};

            /// Secondary pre-fetch feature that will cache pre-fetched data across bus wait states (requires IPREFETCH to be set).
            static constexpr bitfield_t<SRAMMODE_t, 1, 1, bool> IPREFETCH_CACHE = {};

            /// When set, instruction accesses to the SRAM banks will be pre-fetched (normally 2 cycle read access).  Generally, this mode bit should be set for improved performance when executing instructions from SRAM.
            static constexpr bitfield_t<SRAMMODE_t, 0, 0, bool> IPREFETCH = {};
        } SRAMMODE = {};

        /**
         * KEXTCLKSEL - 4 bytes at offset 840
         * Key Register to enable the use of external clock selects via the EXTCLKSEL reg
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct KEXTCLKSEL_t : reg_t<uint32_t, BASE_ADDRESS + 0x348> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x348>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Key register value.
            static constexpr bitfield_t<KEXTCLKSEL_t, 31, 0, MCUCTRL::KEXTCLKSELv> KEXTCLKSEL = {};
        } KEXTCLKSEL = {};

        /**
         * SIMOBUCK2 - 4 bytes at offset 852
         * SIMO Buck Control Reg 2
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SIMOBUCK2_t : reg_t<uint32_t, BASE_ADDRESS + 0x354> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x354>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0xAA0000;

            /// simobuck_core_lp_low_ton_trim
            static constexpr bitfield_t<SIMOBUCK2_t, 23, 20> SIMOBUCKCORELPLOWTONTRIM = {};

            /// simobuck_core_lp_high_ton_trim
            static constexpr bitfield_t<SIMOBUCK2_t, 19, 16> SIMOBUCKCORELPHIGHTONTRIM = {};
        } SIMOBUCK2 = {};

        /**
         * SIMOBUCK3 - 4 bytes at offset 856
         * SIMO Buck Control Reg 3
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SIMOBUCK3_t : reg_t<uint32_t, BASE_ADDRESS + 0x358> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x358>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x5000AAAA;

            /// simobuck_mem_lp_high_ton_trim
            static constexpr bitfield_t<SIMOBUCK3_t, 30, 27> SIMOBUCKMEMLPHIGHTONTRIM = {};

            /// simobuck_mem_lp_low_toff_trim
            static constexpr bitfield_t<SIMOBUCK3_t, 15, 12> SIMOBUCKMEMLPLOWTOFFTRIM = {};

            /// simobuck_mem_lp_high_toff_trim
            static constexpr bitfield_t<SIMOBUCK3_t, 11, 8> SIMOBUCKMEMLPHIGHTOFFTRIM = {};

            /// simobuck_core_lp_low_toff_trim
            static constexpr bitfield_t<SIMOBUCK3_t, 7, 4> SIMOBUCKCORELPLOWTOFFTRIM = {};

            /// simobuck_core_lp_high_toff_trim
            static constexpr bitfield_t<SIMOBUCK3_t, 3, 0> SIMOBUCKCORELPHIGHTOFFTRIM = {};
        } SIMOBUCK3 = {};

        /**
         * SIMOBUCK4 - 4 bytes at offset 860
         * SIMO Buck Control Reg 4
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SIMOBUCK4_t : reg_t<uint32_t, BASE_ADDRESS + 0x35C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x35C>::operator=;
            static constexpr uint32_t reset_mask  = 0x160000F;
            static constexpr uint32_t reset_value = 0x3C8D80AA;

            /// simobuck_comp2_timeout_en
            static constexpr bitfield_t<SIMOBUCK4_t, 24, 24, bool> SIMOBUCKCOMP2TIMEOUTEN = {};

            /// simobuck_clkdiv_sel
            static constexpr bitfield_t<SIMOBUCK4_t, 22, 21> SIMOBUCKCLKDIVSEL = {};

            /// simobuck_mem_lp_low_ton_trim
            static constexpr bitfield_t<SIMOBUCK4_t, 3, 0> SIMOBUCKMEMLPLOWTONTRIM = {};
        } SIMOBUCK4 = {};

        /**
         * BLEBUCK2 - 4 bytes at offset 872
         * BLEBUCK2 Control Reg
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BLEBUCK2_t : reg_t<uint32_t, BASE_ADDRESS + 0x368> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x368>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x4E;

            /// blebuck_ton_trim
            static constexpr bitfield_t<BLEBUCK2_t, 17, 12> BLEBUCKTOND2ATRIM = {};

            /// blebuck_ton_hi_trim
            static constexpr bitfield_t<BLEBUCK2_t, 11, 6> BLEBUCKTONHITRIM = {};

            /// blebuck_ton_low_trim
            static constexpr bitfield_t<BLEBUCK2_t, 5, 0> BLEBUCKTONLOWTRIM = {};
        } BLEBUCK2 = {};

        /**
         * FLASHWPROT0 - 4 bytes at offset 928
         * Flash Write Protection Bits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FLASHWPROT0_t : reg_t<uint32_t, BASE_ADDRESS + 0x3A0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3A0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Write protect flash 0x00000000 - 0x0007FFFF. Each bit provides write protection for 16KB chunks of flash data space.  Bits are cleared by writing a 1 to the bit.  When read, 0 indicates the region is protected.   Bits are sticky (can be set when PROTLOCK is 1, but only cleared by reset)
            static constexpr bitfield_t<FLASHWPROT0_t, 31, 0> FW0BITS = {};
        } FLASHWPROT0 = {};

        /**
         * FLASHWPROT1 - 4 bytes at offset 932
         * Flash Write Protection Bits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FLASHWPROT1_t : reg_t<uint32_t, BASE_ADDRESS + 0x3A4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3A4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Write protect flash 0x00080000 - 0x000FFFFF. Each bit provides write protection for 16KB chunks of flash data space.  Bits are cleared by writing a 1 to the bit.  When read, 0 indicates the region is protected. Bits are sticky (can be set when PROTLOCK is 1, but only cleared by reset)
            static constexpr bitfield_t<FLASHWPROT1_t, 31, 0> FW1BITS = {};
        } FLASHWPROT1 = {};

        /**
         * FLASHRPROT0 - 4 bytes at offset 944
         * Flash Read Protection Bits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FLASHRPROT0_t : reg_t<uint32_t, BASE_ADDRESS + 0x3B0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3B0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Copy (read) protect flash 0x00000000 - 0x0007FFFF. Each bit provides read protection for 16KB chunks of flash.  Bits are cleared by writing a 1 to the bit.  When read, 0 indicates the region is protected. Bits are sticky (can be set when PROTLOCK is 1, but only cleared by reset)
            static constexpr bitfield_t<FLASHRPROT0_t, 31, 0> FR0BITS = {};
        } FLASHRPROT0 = {};

        /**
         * FLASHRPROT1 - 4 bytes at offset 948
         * Flash Read Protection Bits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FLASHRPROT1_t : reg_t<uint32_t, BASE_ADDRESS + 0x3B4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3B4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Copy (read) protect flash 0x00080000 - 0x000FFFFF. Each bit provides read protection for 16KB chunks of flash.  Bits are cleared by writing a 1 to the bit.  When read, 0 indicates the region is protected. Bits are sticky (can be set when PROTLOCK is 1, but only cleared by reset)
            static constexpr bitfield_t<FLASHRPROT1_t, 31, 0> FR1BITS = {};
        } FLASHRPROT1 = {};

        /**
         * DMASRAMWRITEPROTECT0 - 4 bytes at offset 960
         * SRAM write-protection bits.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMASRAMWRITEPROTECT0_t : reg_t<uint32_t, BASE_ADDRESS + 0x3C0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3C0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Write protect SRAM from DMA.  Each bit provides write protection for an 8KB region of memory.  When set to 1, the region will be protected from DMA writes, when set to 0, DMA may write the region.
            static constexpr bitfield_t<DMASRAMWRITEPROTECT0_t, 31, 0> DMA_WPROT0 = {};
        } DMASRAMWRITEPROTECT0 = {};

        /**
         * DMASRAMWRITEPROTECT1 - 4 bytes at offset 964
         * SRAM write-protection bits.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMASRAMWRITEPROTECT1_t : reg_t<uint32_t, BASE_ADDRESS + 0x3C4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3C4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Write protect SRAM from DMA.  Each bit provides write protection for an 8KB region of memory.  When set to 1, the region will be protected from DMA writes, when set to 0, DMA may write the region.
            static constexpr bitfield_t<DMASRAMWRITEPROTECT1_t, 15, 0> DMA_WPROT1 = {};
        } DMASRAMWRITEPROTECT1 = {};

        /**
         * DMASRAMREADPROTECT0 - 4 bytes at offset 976
         * SRAM read-protection bits.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMASRAMREADPROTECT0_t : reg_t<uint32_t, BASE_ADDRESS + 0x3D0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3D0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Read protect SRAM from DMA.  Each bit provides write protection for an 8KB region of memory.  When set to 1, the region will be protected from DMA reads, when set to 0, DMA may read the region.
            static constexpr bitfield_t<DMASRAMREADPROTECT0_t, 31, 0> DMA_RPROT0 = {};
        } DMASRAMREADPROTECT0 = {};

        /**
         * DMASRAMREADPROTECT1 - 4 bytes at offset 980
         * SRAM read-protection bits.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMASRAMREADPROTECT1_t : reg_t<uint32_t, BASE_ADDRESS + 0x3D4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3D4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Read protect SRAM from DMA.  Each bit provides write protection for an 8KB region of memory.  When set to 1, the region will be protected from DMA reads, when set to 0, DMA may read the region.
            static constexpr bitfield_t<DMASRAMREADPROTECT1_t, 15, 0> DMA_RPROT1 = {};
        } DMASRAMREADPROTECT1 = {};
    };  // end of struct MCUCTRL_t

} // namespace sfr