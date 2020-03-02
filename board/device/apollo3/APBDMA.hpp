/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: APBDMA
 * APB DMA Register Interfaces
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace APBDMA {
    
        /// Debug Enable
        enum class DEBUGENv : uint32_t {
            OFF = 0x0, //< Debug Disabled
            ARB = 0x1, //< Debug Arb values
        };
    
    }   // namespace APBDMA

    /// APB DMA Register Interfaces
    template <addressType BASE_ADDRESS>
    struct APBDMA_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * BBVALUE - 4 bytes at offset 0
         * Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BBVALUE_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF00FF;
            static constexpr uint32_t reset_value = 0x0;

            /// PIO values
            static constexpr bitfield_t<BBVALUE_t, 23, 16> PIN = {};

            /// Data Output Values
            static constexpr bitfield_t<BBVALUE_t, 7, 0> DATAOUT = {};
        } BBVALUE = {};

        /**
         * BBSETCLEAR - 4 bytes at offset 4
         * Set/Clear Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BBSETCLEAR_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF00FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Write 1 to Clear PIO value
            static constexpr bitfield_t<BBSETCLEAR_t, 23, 16> CLEAR = {};

            /// Write 1 to Set PIO value (set hier priority than clear if both bit set)
            static constexpr bitfield_t<BBSETCLEAR_t, 7, 0> SET = {};
        } BBSETCLEAR = {};

        /**
         * BBINPUT - 4 bytes at offset 8
         * PIO Input Values
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BBINPUT_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// PIO values
            static constexpr bitfield_t<BBINPUT_t, 7, 0> DATAIN = {};
        } BBINPUT = {};

        /**
         * DEBUGDATA - 4 bytes at offset 32
         * PIO Input Values
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEBUGDATA_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Debug Data
            static constexpr bitfield_t<DEBUGDATA_t, 31, 0> DEBUGDATA = {};
        } DEBUGDATA = {};

        /**
         * DEBUG - 4 bytes at offset 64
         * PIO Input Values
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEBUG_t : reg_t<uint32_t, BASE_ADDRESS + 0x40> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x40>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// Debug Enable
            static constexpr bitfield_t<DEBUG_t, 3, 0, APBDMA::DEBUGENv> DEBUGEN = {};
        } DEBUG = {};
    };  // end of struct APBDMA_t

} // namespace sfr