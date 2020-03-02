/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: VCOMP
 * Voltage Comparator
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace VCOMP {
    
        /// When the reference input NSEL is set to NSEL_DAC, this bitfield selects the voltage level for the negative input to the comparator.
        enum class LVLSELv : uint32_t {
            v0P58V = 0x0, //< Set Reference input to 0.58 Volts.
            v0P77V = 0x1, //< Set Reference input to 0.77 Volts.
            v0P97V = 0x2, //< Set Reference input to 0.97 Volts.
            v1P16V = 0x3, //< Set Reference input to 1.16 Volts.
            v1P35V = 0x4, //< Set Reference input to 1.35 Volts.
            v1P55V = 0x5, //< Set Reference input to 1.55 Volts.
            v1P74V = 0x6, //< Set Reference input to 1.74 Volts.
            v1P93V = 0x7, //< Set Reference input to 1.93 Volts.
            v2P13V = 0x8, //< Set Reference input to 2.13 Volts.
            v2P32V = 0x9, //< Set Reference input to 2.32 Volts.
            v2P51V = 0xA, //< Set Reference input to 2.51 Volts.
            v2P71V = 0xB, //< Set Reference input to 2.71 Volts.
            v2P90V = 0xC, //< Set Reference input to 2.90 Volts.
            v3P09V = 0xD, //< Set Reference input to 3.09 Volts.
            v3P29V = 0xE, //< Set Reference input to 3.29 Volts.
            v3P48V = 0xF, //< Set Reference input to 3.48 Volts.
        };
    
        /// This bitfield selects the negative input to the comparator.
        enum class NSELv : uint32_t {
            VREFEXT1 = 0x0, //< Use external reference 1 for reference input.
            VREFEXT2 = 0x1, //< Use external reference 2 for reference input.
            VREFEXT3 = 0x2, //< Use external reference 3 for reference input.
            DAC = 0x3, //< Use DAC output selected by LVLSEL for reference input.
        };
    
        /// This bitfield selects the positive input to the comparator.
        enum class PSELv : uint32_t {
            VDDADJ = 0x0, //< Use VDDADJ for the positive input.
            VTEMP = 0x1, //< Use the temperature sensor output for the positive input.  Note: If this channel is selected for PSEL, the bandap circuit required for temperature comparisons will automatically turn on.  The bandgap circuit requires 11us to stabalize.
            VEXT1 = 0x2, //< Use external voltage 0 for positive input.
            VEXT2 = 0x3, //< Use external voltage 1 for positive input.
        };
    
        /// Key register value.
        enum class PWDKEYv : uint32_t {
            Key = 0x37, //< Key
        };
    
    }   // namespace VCOMP

    /// Voltage Comparator
    template <addressType BASE_ADDRESS>
    struct VCOMP_t {
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
            static constexpr uint32_t reset_mask  = 0xF0303;
            static constexpr uint32_t reset_value = 0x0;

            /// When the reference input NSEL is set to NSEL_DAC, this bitfield selects the voltage level for the negative input to the comparator.
            static constexpr bitfield_t<CFG_t, 19, 16, VCOMP::LVLSELv> LVLSEL = {};

            /// This bitfield selects the negative input to the comparator.
            static constexpr bitfield_t<CFG_t, 9, 8, VCOMP::NSELv> NSEL = {};

            /// This bitfield selects the positive input to the comparator.
            static constexpr bitfield_t<CFG_t, 1, 0, VCOMP::PSELv> PSEL = {};
        } CFG = {};

        /**
         * STAT - 4 bytes at offset 4
         * Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit indicates the power down state of the voltage comparator.
            static constexpr bitfield_t<STAT_t, 1, 1, bool> PWDSTAT = {};

            /// This bit is 1 if the positive input of the comparator is greater than the negative input.
            static constexpr bitfield_t<STAT_t, 0, 0, bool> CMPOUT = {};
        } STAT = {};

        /**
         * PWDKEY - 4 bytes at offset 8
         * Key Register for Powering Down the Voltage Comparator
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PWDKEY_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Key register value.
            static constexpr bitfield_t<PWDKEY_t, 31, 0, VCOMP::PWDKEYv> PWDKEY = {};
        } PWDKEY = {};

        /**
         * INTEN - 4 bytes at offset 512
         * Voltage Comparator Interrupt registers: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit is the vcompout high interrupt.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> OUTHI = {};

            /// This bit is the vcompout low interrupt.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> OUTLOW = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * Voltage Comparator Interrupt registers: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit is the vcompout high interrupt.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> OUTHI = {};

            /// This bit is the vcompout low interrupt.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> OUTLOW = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * Voltage Comparator Interrupt registers: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit is the vcompout high interrupt.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> OUTHI = {};

            /// This bit is the vcompout low interrupt.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> OUTLOW = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * Voltage Comparator Interrupt registers: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit is the vcompout high interrupt.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> OUTHI = {};

            /// This bit is the vcompout low interrupt.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> OUTLOW = {};
        } INTSET = {};
    };  // end of struct VCOMP_t

} // namespace sfr