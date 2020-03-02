/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: WDT
 * Watchdog Timer
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace WDT {
    
        /// Select the frequency for the WDT.  All values not enumerated below are undefined.
        enum class CLKSELv : uint32_t {
            OFF = 0x0, //< Low Power Mode.  This setting disables the watch dog timer.
            v128HZ = 0x1, //< 128 Hz LFRC clock.
            v16HZ = 0x2, //< 16 Hz LFRC clock.
            v1HZ = 0x3, //< 1 Hz LFRC clock.
            v1_16HZ = 0x4, //< 1/16th Hz LFRC clock.
        };
    
        /// Writing 0xB2 to WDTRSTRT restarts the watchdog timer.  This is a write only register.  Reading this register will only provide all 0.
        enum class RSTRTv : uint32_t {
            KEYVALUE = 0xB2, //< This is the key value to write to WDTRSTRT to restart the WDT.  This is a write only register.
        };
    
        /// Writing 0x3A locks the watchdog timer. Once locked, the WDTCFG reg cannot be written and WDTEN is set.
        enum class LOCKv : uint32_t {
            KEYVALUE = 0x3A, //< This is the key value to write to WDTLOCK to lock the WDT.
        };
    
    }   // namespace WDT

    /// Watchdog Timer
    template <addressType BASE_ADDRESS>
    struct WDT_t {
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
            static constexpr uint32_t reset_mask  = 0x7FFFF07;
            static constexpr uint32_t reset_value = 0xFFFF00;

            /// Select the frequency for the WDT.  All values not enumerated below are undefined.
            static constexpr bitfield_t<CFG_t, 26, 24, WDT::CLKSELv> CLKSEL = {};

            /// This bitfield is the compare value for counter bits 7:0 to generate a watchdog interrupt.
            static constexpr bitfield_t<CFG_t, 23, 16> INTVAL = {};

            /// This bitfield is the compare value for counter bits 7:0 to generate a watchdog reset.  This will cause a software reset.
            static constexpr bitfield_t<CFG_t, 15, 8> RESVAL = {};

            /// This bitfield enables the WDT reset.  This needs to be set together with the WDREN bit in REG_RSTGEN_CFG register (in reset gen) to trigger the reset.
            static constexpr bitfield_t<CFG_t, 2, 2, bool> RESEN = {};

            /// This bitfield enables the WDT interrupt. Note : This bit must be set before the interrupt status bit will reflect a watchdog timer expiration.  The IER interrupt register must also be enabled for a WDT interrupt to be sent to the NVIC.
            static constexpr bitfield_t<CFG_t, 1, 1, bool> INTEN = {};

            /// This bitfield enables the WDT.
            static constexpr bitfield_t<CFG_t, 0, 0, bool> WDTEN = {};
        } CFG = {};

        /**
         * RSTRT - 4 bytes at offset 4
         * Restart the watchdog timer.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RSTRT_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Writing 0xB2 to WDTRSTRT restarts the watchdog timer.  This is a write only register.  Reading this register will only provide all 0.
            static constexpr bitfield_t<RSTRT_t, 7, 0, WDT::RSTRTv> RSTRT = {};
        } RSTRT = {};

        /**
         * LOCK - 4 bytes at offset 8
         * Locks the WDT
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct LOCK_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Writing 0x3A locks the watchdog timer. Once locked, the WDTCFG reg cannot be written and WDTEN is set.
            static constexpr bitfield_t<LOCK_t, 7, 0, WDT::LOCKv> LOCK = {};
        } LOCK = {};

        /**
         * COUNT - 4 bytes at offset 12
         * Current Counter Value for WDT
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct COUNT_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Read-Only current value of the WDT counter
            static constexpr bitfield_t<COUNT_t, 7, 0> COUNT = {};
        } COUNT = {};

        /**
         * INTEN - 4 bytes at offset 512
         * WDT Interrupt register: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Watchdog Timer Interrupt.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> WDTINT = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * WDT Interrupt register: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Watchdog Timer Interrupt.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> WDTINT = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * WDT Interrupt register: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Watchdog Timer Interrupt.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> WDTINT = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * WDT Interrupt register: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Watchdog Timer Interrupt.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> WDTINT = {};
        } INTSET = {};
    };  // end of struct WDT_t

} // namespace sfr