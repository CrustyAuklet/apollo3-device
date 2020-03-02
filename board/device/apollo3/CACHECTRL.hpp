/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: CACHECTRL
 * Flash Cache Controller
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace CACHECTRL {
    
        /// Sets the cache configuration
        enum class CONFIGv : uint32_t {
            W1_128B_512E = 0x4, //< Direct mapped, 128-bit linesize, 512 entries (4 SRAMs active)
            W2_128B_512E = 0x5, //< Two-way set associative, 128-bit linesize, 512 entries (8 SRAMs active)
            W1_128B_1024E = 0x8, //< Direct mapped, 128-bit linesize, 1024 entries (8 SRAMs active)
        };
    
        /// Controls flash low power modes (control of LPM pin).
        enum class LPMMODEv : uint32_t {
            NEVER = 0x0, //< High power mode (LPM not used).
            STANDBY = 0x1, //< Fast Standby mode.  LPM deasserted for read operations, but asserted while flash IDLE.
            ALWAYS = 0x2, //< Low Power mode.  LPM always asserted for reads.  LPM_RD_WAIT must be programmed to accomodate longer read access times.
        };
    
    }   // namespace CACHECTRL

    /// Flash Cache Controller
    template <addressType BASE_ADDRESS>
    struct CACHECTRL_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CACHECFG - 4 bytes at offset 0
         * Flash Cache Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CACHECFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x1100FFF;
            static constexpr uint32_t reset_value = 0x100C50;

            /// Enable Cache Monitoring Stats.  Cache monitoring consumes additional power and should only be enabled when profiling code and counters will increment when this bit is set.  Counter values will be retained when this is set to 0, allowing software to enable/disable counting for multiple code segments.
            static constexpr bitfield_t<CACHECFG_t, 24, 24, bool> ENABLE_MONITOR = {};

            /// Enable aggressive clock gating of entire data array.  This bit should be set to 1 for optimal power efficiency.
            static constexpr bitfield_t<CACHECFG_t, 20, 20, bool> DATA_CLKGATE = {};

            /// Enable LS (light sleep) of cache RAMs.  Software should DISABLE this bit since cache activity is too high to benefit from LS usage.
            static constexpr bitfield_t<CACHECFG_t, 11, 11, bool> CACHE_LS = {};

            /// Enable clock gating of cache TAG RAM.  Software should enable this bit for optimal power efficiency.
            static constexpr bitfield_t<CACHECFG_t, 10, 10, bool> CACHE_CLKGATE = {};

            /// Enable Flash Data Caching.
            static constexpr bitfield_t<CACHECFG_t, 9, 9, bool> DCACHE_ENABLE = {};

            /// Enable Flash Instruction Caching
            static constexpr bitfield_t<CACHECFG_t, 8, 8, bool> ICACHE_ENABLE = {};

            /// Sets the cache configuration
            static constexpr bitfield_t<CACHECFG_t, 7, 4, CACHECTRL::CONFIGv> CONFIG = {};

            /// Enable Non-cacheable region 1.  See NCR1 registers to define the region.
            static constexpr bitfield_t<CACHECFG_t, 3, 3, bool> ENABLE_NC1 = {};

            /// Enable Non-cacheable region 0.  See NCR0 registers to define the region.
            static constexpr bitfield_t<CACHECFG_t, 2, 2, bool> ENABLE_NC0 = {};

            /// Sets the cache repleacment policy.  0=LRR (least recently replaced), 1=LRU (least recently used).  LRR minimizes writes to the TAG SRAM.
            static constexpr bitfield_t<CACHECFG_t, 1, 1, bool> LRU = {};

            /// Enables the flash cache controller and enables power to the cache SRAMs.  The ICACHE_ENABLE and DCACHE_ENABLE should be set to enable caching for each type of access.
            static constexpr bitfield_t<CACHECFG_t, 0, 0, bool> ENABLE = {};
        } CACHECFG = {};

        /**
         * FLASHCFG - 4 bytes at offset 4
         * Flash Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FLASHCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F7F;
            static constexpr uint32_t reset_value = 0x873;

            /// Controls flash low power modes (control of LPM pin).
            static constexpr bitfield_t<FLASHCFG_t, 13, 12, CACHECTRL::LPMMODEv> LPMMODE = {};

            /// Sets flash waitstates when in LPM Mode 2 (RD_WAIT in LPM mode 2 only)
            static constexpr bitfield_t<FLASHCFG_t, 11, 8> LPM_RD_WAIT = {};

            /// Sets SE delay (flash address setup).  A value of 5 is recommended.
            static constexpr bitfield_t<FLASHCFG_t, 6, 4> SEDELAY = {};

            /// Sets read waitstates for normal (fast) operation.  A value of 1 is recommended.
            static constexpr bitfield_t<FLASHCFG_t, 3, 0> RD_WAIT = {};
        } FLASHCFG = {};

        /**
         * CTRL - 4 bytes at offset 8
         * Cache Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0x777;
            static constexpr uint32_t reset_value = 0x0;

            /// Enable Flash Sleep Mode.  Write to 1 to put flash 1 into sleep mode.  NOTE: there is a 5us latency after waking flash until the first access will be returned.
            static constexpr bitfield_t<CTRL_t, 10, 10, bool> FLASH1_SLM_ENABLE = {};

            /// Disable Flash Sleep Mode.  Write 1 to wake flash1 from sleep mode (reading the array will also automatically wake it).
            static constexpr bitfield_t<CTRL_t, 9, 9, bool> FLASH1_SLM_DISABLE = {};

            /// Flash Sleep Mode Status.  1 indicates that flash1 is in sleep mode, 0 indicates flash1 is in normal mode.
            static constexpr bitfield_t<CTRL_t, 8, 8, bool> FLASH1_SLM_STATUS = {};

            /// Enable Flash Sleep Mode.  Write to 1 to put flash 0 into sleep mode.  NOTE: there is a 5us latency after waking flash until the first access will be returned.
            static constexpr bitfield_t<CTRL_t, 6, 6, bool> FLASH0_SLM_ENABLE = {};

            /// Disable Flash Sleep Mode.  Write 1 to wake flash0 from sleep mode (reading the array will also automatically wake it).
            static constexpr bitfield_t<CTRL_t, 5, 5, bool> FLASH0_SLM_DISABLE = {};

            /// Flash Sleep Mode Status.  1 indicates that flash0 is in sleep mode, 0 indicates flash0 is in normal mode.
            static constexpr bitfield_t<CTRL_t, 4, 4, bool> FLASH0_SLM_STATUS = {};

            /// Cache Ready Status (enabled and not processing an invalidate operation)
            static constexpr bitfield_t<CTRL_t, 2, 2, bool> CACHE_READY = {};

            /// Reset Cache Statistics.  When written to a 1, the cache monitor counters will be cleared.  The monitor counters can be reset only when the CACHECFG.ENABLE_MONITOR bit is set.
            static constexpr bitfield_t<CTRL_t, 1, 1, bool> RESET_STAT = {};

            /// Writing a 1 to this bitfield invalidates the flash cache contents.
            static constexpr bitfield_t<CTRL_t, 0, 0, bool> INVALIDATE = {};
        } CTRL = {};

        /**
         * NCR0START - 4 bytes at offset 16
         * Flash Cache Noncachable Region 0 Start
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct NCR0START_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFFFF0;
            static constexpr uint32_t reset_value = 0x0;

            /// Start address for non-cacheable region 0
            static constexpr bitfield_t<NCR0START_t, 26, 4> ADDR = {};
        } NCR0START = {};

        /**
         * NCR0END - 4 bytes at offset 20
         * Flash Cache Noncachable Region 0 End
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct NCR0END_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFFFF0;
            static constexpr uint32_t reset_value = 0x0;

            /// End address for non-cacheable region 0
            static constexpr bitfield_t<NCR0END_t, 26, 4> ADDR = {};
        } NCR0END = {};

        /**
         * NCR1START - 4 bytes at offset 24
         * Flash Cache Noncachable Region 1 Start
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct NCR1START_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFFFF0;
            static constexpr uint32_t reset_value = 0x0;

            /// Start address for non-cacheable region 1
            static constexpr bitfield_t<NCR1START_t, 26, 4> ADDR = {};
        } NCR1START = {};

        /**
         * NCR1END - 4 bytes at offset 28
         * Flash Cache Noncachable Region 1 End
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct NCR1END_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFFFF0;
            static constexpr uint32_t reset_value = 0x0;

            /// End address for non-cacheable region 1
            static constexpr bitfield_t<NCR1END_t, 26, 4> ADDR = {};
        } NCR1END = {};

        /**
         * DMON0 - 4 bytes at offset 64
         * Data Cache Total Accesses
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMON0_t : reg_t<uint32_t, BASE_ADDRESS + 0x40> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x40>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Total accesses to data cache.  All performance metrics should be relative to the number of accesses performed.
            static constexpr bitfield_t<DMON0_t, 31, 0> DACCESS_COUNT = {};
        } DMON0 = {};

        /**
         * DMON1 - 4 bytes at offset 68
         * Data Cache Tag Lookups
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMON1_t : reg_t<uint32_t, BASE_ADDRESS + 0x44> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x44>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Total tag lookups from data cache.
            static constexpr bitfield_t<DMON1_t, 31, 0> DLOOKUP_COUNT = {};
        } DMON1 = {};

        /**
         * DMON2 - 4 bytes at offset 72
         * Data Cache Hits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMON2_t : reg_t<uint32_t, BASE_ADDRESS + 0x48> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x48>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Cache hits from lookup operations.
            static constexpr bitfield_t<DMON2_t, 31, 0> DHIT_COUNT = {};
        } DMON2 = {};

        /**
         * DMON3 - 4 bytes at offset 76
         * Data Cache Line Hits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMON3_t : reg_t<uint32_t, BASE_ADDRESS + 0x4C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Cache hits from line cache
            static constexpr bitfield_t<DMON3_t, 31, 0> DLINE_COUNT = {};
        } DMON3 = {};

        /**
         * IMON0 - 4 bytes at offset 80
         * Instruction Cache Total Accesses
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IMON0_t : reg_t<uint32_t, BASE_ADDRESS + 0x50> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x50>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Total accesses to Instruction cache
            static constexpr bitfield_t<IMON0_t, 31, 0> IACCESS_COUNT = {};
        } IMON0 = {};

        /**
         * IMON1 - 4 bytes at offset 84
         * Instruction Cache Tag Lookups
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IMON1_t : reg_t<uint32_t, BASE_ADDRESS + 0x54> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x54>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Total tag lookups from Instruction cache
            static constexpr bitfield_t<IMON1_t, 31, 0> ILOOKUP_COUNT = {};
        } IMON1 = {};

        /**
         * IMON2 - 4 bytes at offset 88
         * Instruction Cache Hits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IMON2_t : reg_t<uint32_t, BASE_ADDRESS + 0x58> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x58>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Cache hits from lookup operations
            static constexpr bitfield_t<IMON2_t, 31, 0> IHIT_COUNT = {};
        } IMON2 = {};

        /**
         * IMON3 - 4 bytes at offset 92
         * Instruction Cache Line Hits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IMON3_t : reg_t<uint32_t, BASE_ADDRESS + 0x5C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x5C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Cache hits from line cache
            static constexpr bitfield_t<IMON3_t, 31, 0> ILINE_COUNT = {};
        } IMON3 = {};
    };  // end of struct CACHECTRL_t

} // namespace sfr