/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: RTC
 * Real Time Clock
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace RTC {
    
        /// Alarm repeat interval
        enum class RPTv : uint32_t {
            DIS = 0x0, //< Alarm interrupt disabled
            YEAR = 0x1, //< Interrupt every year
            MONTH = 0x2, //< Interrupt every month
            WEEK = 0x3, //< Interrupt every week
            DAY = 0x4, //< Interrupt every day
            HR = 0x5, //< Interrupt every hour
            MIN = 0x6, //< Interrupt every minute
            SEC = 0x7, //< Interrupt every second/10th/100th
        };
    
    }   // namespace RTC

    /// Real Time Clock
    template <addressType BASE_ADDRESS>
    struct RTC_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CTRLOW - 4 bytes at offset 64
         * RTC Counters Lower
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRLOW_t : reg_t<uint32_t, BASE_ADDRESS + 0x40> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x40>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F7F7FFF;
            static constexpr uint32_t reset_value = 0x1000000;

            /// Hours Counter
            static constexpr bitfield_t<CTRLOW_t, 29, 24> CTRHR = {};

            /// Minutes Counter
            static constexpr bitfield_t<CTRLOW_t, 22, 16> CTRMIN = {};

            /// Seconds Counter
            static constexpr bitfield_t<CTRLOW_t, 14, 8> CTRSEC = {};

            /// 100ths of a second Counter
            static constexpr bitfield_t<CTRLOW_t, 7, 0> CTR100 = {};
        } CTRLOW = {};

        /**
         * CTRUP - 4 bytes at offset 68
         * RTC Counters Upper
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRUP_t : reg_t<uint32_t, BASE_ADDRESS + 0x44> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x44>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1F3F;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter read error status. Error is triggered when software reads the lower word of the counters, and fails to read the upper counter within 1/100 second.  This is because when the lower counter is read, the upper counter is held off from incrementing until it is read so that the full time stamp can be read.
            static constexpr bitfield_t<CTRUP_t, 31, 31, bool> CTERR = {};

            /// Century enable
            static constexpr bitfield_t<CTRUP_t, 28, 28, bool> CEB = {};

            /// Century
            static constexpr bitfield_t<CTRUP_t, 27, 27, bool> CB = {};

            /// Weekdays Counter
            static constexpr bitfield_t<CTRUP_t, 26, 24> CTRWKDY = {};

            /// Years Counter
            static constexpr bitfield_t<CTRUP_t, 23, 16> CTRYR = {};

            /// Months Counter
            static constexpr bitfield_t<CTRUP_t, 12, 8> CTRMO = {};

            /// Date Counter
            static constexpr bitfield_t<CTRUP_t, 5, 0> CTRDATE = {};
        } CTRUP = {};

        /**
         * ALMLOW - 4 bytes at offset 72
         * RTC Alarms Lower
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALMLOW_t : reg_t<uint32_t, BASE_ADDRESS + 0x48> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x48>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F7F7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Hours Alarm
            static constexpr bitfield_t<ALMLOW_t, 29, 24> ALMHR = {};

            /// Minutes Alarm
            static constexpr bitfield_t<ALMLOW_t, 22, 16> ALMMIN = {};

            /// Seconds Alarm
            static constexpr bitfield_t<ALMLOW_t, 14, 8> ALMSEC = {};

            /// 100ths of a second Alarm
            static constexpr bitfield_t<ALMLOW_t, 7, 0> ALM100 = {};
        } ALMLOW = {};

        /**
         * ALMUP - 4 bytes at offset 76
         * RTC Alarms Upper
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALMUP_t : reg_t<uint32_t, BASE_ADDRESS + 0x4C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4C>::operator=;
            static constexpr uint32_t reset_mask  = 0x71F3F;
            static constexpr uint32_t reset_value = 0x0;

            /// Weekdays Alarm
            static constexpr bitfield_t<ALMUP_t, 18, 16> ALMWKDY = {};

            /// Months Alarm
            static constexpr bitfield_t<ALMUP_t, 12, 8> ALMMO = {};

            /// Date Alarm
            static constexpr bitfield_t<ALMUP_t, 5, 0> ALMDATE = {};
        } ALMUP = {};

        /**
         * RTCCTL - 4 bytes at offset 80
         * RTC Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RTCCTL_t : reg_t<uint32_t, BASE_ADDRESS + 0x50> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x50>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x0;

            /// Hours Counter mode
            static constexpr bitfield_t<RTCCTL_t, 5, 5, bool> HR1224 = {};

            /// RTC input clock control
            static constexpr bitfield_t<RTCCTL_t, 4, 4, bool> RSTOP = {};

            /// Alarm repeat interval
            static constexpr bitfield_t<RTCCTL_t, 3, 1, RTC::RPTv> RPT = {};

            /// Counter write control
            static constexpr bitfield_t<RTCCTL_t, 0, 0, bool> WRTC = {};
        } RTCCTL = {};

        /**
         * INTEN - 4 bytes at offset 256
         * RTC Interrupt Register: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// RTC Alarm interrupt
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> ALM = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 260
         * RTC Interrupt Register: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// RTC Alarm interrupt
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> ALM = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 264
         * RTC Interrupt Register: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// RTC Alarm interrupt
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> ALM = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 268
         * RTC Interrupt Register: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// RTC Alarm interrupt
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> ALM = {};
        } INTSET = {};
    };  // end of struct RTC_t

} // namespace sfr