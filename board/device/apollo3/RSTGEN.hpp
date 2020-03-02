/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: RSTGEN
 * MCU Reset Generator
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace RSTGEN {
    
        /// 0x1B generates a software POI reset.  This is a write-only register.  Reading from this register will yield only all 0s.
        enum class SWPOIKEYv : uint32_t {
            KEYVALUE = 0x1B, //< Writing 0x1B key value generates a software POI reset.
        };
    
        /// 0xD4 generates a software POR reset.
        enum class SWPORKEYv : uint32_t {
            KEYVALUE = 0xD4, //< Writing 0xD4 key value generates a software POR reset.
        };
    
    }   // namespace RSTGEN

    /// MCU Reset Generator
    template <addressType BASE_ADDRESS>
    struct RSTGEN_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CFG - 4 bytes at offset 0
         * Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// Watchdog Timer Reset Enable.  NOTE: The WDT module must also be configured for WDT reset.  This includes enabling the RESEN bit in WDTCFG register in Watch dog timer block.
            static constexpr bitfield_t<CFG_t, 1, 1, bool> WDREN = {};

            /// Brown out high (2.1v) reset enable.
            static constexpr bitfield_t<CFG_t, 0, 0, bool> BODHREN = {};
        } CFG = {};

        /**
         * SWPOI - 4 bytes at offset 4
         * Software POI Reset
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SWPOI_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// 0x1B generates a software POI reset.  This is a write-only register.  Reading from this register will yield only all 0s.
            static constexpr bitfield_t<SWPOI_t, 7, 0, RSTGEN::SWPOIKEYv> SWPOIKEY = {};
        } SWPOI = {};

        /**
         * SWPOR - 4 bytes at offset 8
         * Software POR Reset
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SWPOR_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// 0xD4 generates a software POR reset.
            static constexpr bitfield_t<SWPOR_t, 7, 0, RSTGEN::SWPORKEYv> SWPORKEY = {};
        } SWPOR = {};

        /**
         * TPIURST - 4 bytes at offset 20
         * TPIU reset
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TPIURST_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Static reset for the TPIU. Write to '1' to assert reset to TPIU. Write to '0' to clear the reset.
            static constexpr bitfield_t<TPIURST_t, 0, 0, bool> TPIURST = {};
        } TPIURST = {};

        /**
         * INTEN - 4 bytes at offset 512
         * Reset Interrupt register: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables an interrupt that triggers when VCC is below BODH level.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> BODH = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * Reset Interrupt register: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables an interrupt that triggers when VCC is below BODH level.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> BODH = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * Reset Interrupt register: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables an interrupt that triggers when VCC is below BODH level.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> BODH = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * Reset Interrupt register: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables an interrupt that triggers when VCC is below BODH level.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> BODH = {};
        } INTSET = {};

        /**
         * STAT - 4 bytes at offset 268431360
         * Status Register (SBL)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0xFFFF000> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xFFFF000>::operator=;
            static constexpr uint32_t reset_mask  = 0xC00007FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Set when booting securely (SBL).
            static constexpr bitfield_t<STAT_t, 31, 31, bool> SBOOT = {};

            /// Set if current boot was initiated by soft reset and resulted in Fast Boot (SBL).
            static constexpr bitfield_t<STAT_t, 30, 30, bool> FBOOT = {};

            /// A BLE/Burst Regulator Brownout Event occurred (SBL).
            static constexpr bitfield_t<STAT_t, 10, 10, bool> BOBSTAT = {};

            /// A Memory Regulator Brownout Event occurred (SBL).
            static constexpr bitfield_t<STAT_t, 9, 9, bool> BOFSTAT = {};

            /// A Core Regulator Brownout Event occurred (SBL).
            static constexpr bitfield_t<STAT_t, 8, 8, bool> BOCSTAT = {};

            /// An Unregulated Supply Brownout Event occurred (SBL).
            static constexpr bitfield_t<STAT_t, 7, 7, bool> BOUSTAT = {};

            /// Reset was initiated by a Watchdog Timer Reset (SBL).
            static constexpr bitfield_t<STAT_t, 6, 6, bool> WDRSTAT = {};

            /// Reset was a initiated by Debugger Reset (SBL).
            static constexpr bitfield_t<STAT_t, 5, 5, bool> DBGRSTAT = {};

            /// Reset was a initiated by Software POI Reset (SBL).
            static constexpr bitfield_t<STAT_t, 4, 4, bool> POIRSTAT = {};

            /// Reset was a initiated by SW POR or AIRCR Reset (SBL).
            static constexpr bitfield_t<STAT_t, 3, 3, bool> SWRSTAT = {};

            /// Reset was initiated by a Brown-Out Reset (SBL).
            static constexpr bitfield_t<STAT_t, 2, 2, bool> BORSTAT = {};

            /// Reset was initiated by a Power-On Reset (SBL).
            static constexpr bitfield_t<STAT_t, 1, 1, bool> PORSTAT = {};

            /// Reset was initiated by an External Reset (SBL).
            static constexpr bitfield_t<STAT_t, 0, 0, bool> EXRSTAT = {};
        } STAT = {};
    };  // end of struct RSTGEN_t

} // namespace sfr