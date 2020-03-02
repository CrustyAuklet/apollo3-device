/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: CTIMER
 * Counter/Timer
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace CTIMER {
    
        /// Counter/Timer B0 Function Select.
        enum class TMRB0FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B0, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B0, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B0, assert, count to CMPR1B0, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B0, assert, count to CMPR1B0, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B0 Clock Select.
        enum class TMRB0CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA0 = 0x14, //< Clock source is CTIMERA0 OUT.
            CTMRB1 = 0x15, //< Clock source is CTIMERB1 OUT.
            CTMRA1 = 0x16, //< Clock source is CTIMERA1 OUT.
            CTMRA2 = 0x17, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x18, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x19, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1A, //< Clock source is CTIMERB4 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A0 Function Select.
        enum class TMRA0FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A0, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A0, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A0, assert, count to CMPR1A0, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A0, assert, count to CMPR1A0, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A0 Clock Select.
        enum class TMRA0CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB0 = 0x14, //< Clock source is CTIMERB0 OUT.
            CTMRA1 = 0x15, //< Clock source is CTIMERA1 OUT.
            CTMRB1 = 0x16, //< Clock source is CTIMERB1 OUT.
            CTMRA2 = 0x17, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x18, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x19, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1A, //< Clock source is CTIMERB4 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B0 Trigger Select.
        enum class TMRB0TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A0OUT = 0x1, //< Trigger source is CTIMERA0 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            B2OUT = 0x4, //< Trigger source is CTIMERB2 OUT.
            B5OUT = 0x5, //< Trigger source is CTIMERB5 OUT.
            A4OUT = 0x6, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x7, //< Trigger source is CTIMERB4 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            B7OUT2 = 0xA, //< Trigger source is CTIMERB7 OUT2.
            A2OUT2 = 0xB, //< Trigger source is CTIMERA2 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B5OUT2DUAL = 0xE, //< Trigger source is CTIMERB5 OUT2, dual edge.
            A5OUT2DUAL = 0xF, //< Trigger source is CTIMERA5 OUT2, dual edge.
        };
    
        /// Counter/Timer A0 Trigger Select.
        enum class TMRA0TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            B0OUT = 0x1, //< Trigger source is CTIMERB0 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A1OUT = 0x4, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x5, //< Trigger source is CTIMERB1 OUT.
            A5OUT = 0x6, //< Trigger source is CTIMERA5 OUT.
            B5OUT = 0x7, //< Trigger source is CTIMERB5 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            B6OUT2 = 0xA, //< Trigger source is CTIMERB6 OUT2.
            A2OUT2 = 0xB, //< Trigger source is CTIMERA2 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B4OUT2DUAL = 0xE, //< Trigger source is CTIMERB4 OUT2, dual edge.
            A4OUT2DUAL = 0xF, //< Trigger source is CTIMERA4 OUT2, dual edge.
        };
    
        /// Counter/Timer B1 Function Select.
        enum class TMRB1FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B1, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B1, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B1, assert, count to CMPR1B1, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B1, assert, count to CMPR1B1, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B1 Clock Select.
        enum class TMRB1CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA1 = 0x14, //< Clock source is CTIMERA1 OUT.
            CTMRA0 = 0x15, //< Clock source is CTIMERA0 OUT.
            CTMRB0 = 0x16, //< Clock source is CTIMERB0 OUT.
            CTMRA2 = 0x17, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x18, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x19, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1A, //< Clock source is CTIMERB4 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A1 Function Select.
        enum class TMRA1FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A1, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A1, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A1, assert, count to CMPR1A1, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A1, assert, count to CMPR1A1, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A1 Clock Select.
        enum class TMRA1CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB1 = 0x14, //< Clock source is CTIMERB1 OUT.
            CTMRA0 = 0x15, //< Clock source is CTIMERA0 OUT.
            CTMRB0 = 0x16, //< Clock source is CTIMERB0 OUT.
            CTMRA2 = 0x17, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x18, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x19, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1A, //< Clock source is CTIMERB4 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B1 Trigger Select.
        enum class TMRB1TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A1OUT = 0x1, //< Trigger source is CTIMERA1 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A6OUT = 0x4, //< Trigger source is CTIMERA6 OUT.
            B6OUT = 0x5, //< Trigger source is CTIMERB6 OUT.
            A0OUT = 0x6, //< Trigger source is CTIMERA0 OUT.
            B0OUT = 0x7, //< Trigger source is CTIMERB0 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A4OUT2 = 0xA, //< Trigger source is CTIMERA4 OUT2.
            B4OUT2 = 0xB, //< Trigger source is CTIMERB4 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B5OUT2DUAL = 0xE, //< Trigger source is CTIMERB5 OUT2, dual edge.
            A5OUT2DUAL = 0xF, //< Trigger source is CTIMERA5 OUT2, dual edge.
        };
    
        /// Counter/Timer A1 Trigger Select.
        enum class TMRA1TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            B1OUT = 0x1, //< Trigger source is CTIMERB1 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A0OUT = 0x4, //< Trigger source is CTIMERA0 OUT.
            B0OUT = 0x5, //< Trigger source is CTIMERB0 OUT.
            A5OUT = 0x6, //< Trigger source is CTIMERA5 OUT.
            B5OUT = 0x7, //< Trigger source is CTIMERB5 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A4OUT2 = 0xA, //< Trigger source is CTIMERA4 OUT2.
            B4OUT2 = 0xB, //< Trigger source is CTIMERB4 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B5OUT2DUAL = 0xE, //< Trigger source is CTIMERB5 OUT2, dual edge.
            A5OUT2DUAL = 0xF, //< Trigger source is CTIMERA5 OUT2, dual edge.
        };
    
        /// Counter/Timer B2 Function Select.
        enum class TMRB2FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B2, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B2, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B2, assert, count to CMPR1B2, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B2, assert, count to CMPR1B2, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B2 Clock Select.
        enum class TMRB2CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA2 = 0x14, //< Clock source is CTIMERA2 OUT.
            CTMRB3 = 0x15, //< Clock source is CTIMERA3 OUT.
            CTMRA3 = 0x16, //< Clock source is CTIMERB3 OUT.
            CTMRA4 = 0x17, //< Clock source is CTIMERA4 OUT.
            CTMRB4 = 0x18, //< Clock source is CTIMERB4 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x1A, //< Clock source is CTIMERB1 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A2 Function Select.
        enum class TMRA2FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A2, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A2, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A2, assert, count to CMPR1A2, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A2, assert, count to CMPR1A2, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A2 Clock Select.
        enum class TMRA2CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB2 = 0x14, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x15, //< Clock source is CTIMERA3 OUT.
            CTMRA3 = 0x16, //< Clock source is CTIMERB3 OUT.
            CTMRA4 = 0x17, //< Clock source is CTIMERA4 OUT.
            CTMRB4 = 0x18, //< Clock source is CTIMERB4 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x1A, //< Clock source is CTIMERB1 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B2 Trigger Select.
        enum class TMRB2TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A2OUT = 0x1, //< Trigger source is CTIMERA2 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A1OUT = 0x4, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x5, //< Trigger source is CTIMERB1 OUT.
            A4OUT = 0x6, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x7, //< Trigger source is CTIMERB4 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A5OUT2 = 0xA, //< Trigger source is CTIMERA5 OUT2.
            B5OUT2 = 0xB, //< Trigger source is CTIMERB5 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B4OUT2DUAL = 0xE, //< Trigger source is CTIMERB4 OUT2, dual edge.
            A4OUT2DUAL = 0xF, //< Trigger source is CTIMERA4 OUT2, dual edge.
        };
    
        /// Counter/Timer A2 Trigger Select.
        enum class TMRA2TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            B2OUT = 0x1, //< Trigger source is CTIMERB2 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A0OUT = 0x4, //< Trigger source is CTIMERA0 OUT.
            B0OUT = 0x5, //< Trigger source is CTIMERB0 OUT.
            A4OUT = 0x6, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x7, //< Trigger source is CTIMERB4 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A5OUT2 = 0xA, //< Trigger source is CTIMERA5 OUT2.
            B5OUT2 = 0xB, //< Trigger source is CTIMERB5 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B4OUT2DUAL = 0xE, //< Trigger source is CTIMERB4 OUT2, dual edge.
            A4OUT2DUAL = 0xF, //< Trigger source is CTIMERA4 OUT2, dual edge.
        };
    
        /// Counter/Timer B3 Function Select.
        enum class TMRB3FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B3, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B3, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B3, assert, count to CMPR1B3, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B3, assert, count to CMPR1B3, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B3 Clock Select.
        enum class TMRB3CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA3 = 0x14, //< Clock source is CTIMERA3 OUT.
            CTMRA2 = 0x15, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x16, //< Clock source is CTIMERB2 OUT.
            CTMRA4 = 0x17, //< Clock source is CTIMERA4 OUT.
            CTMRB4 = 0x18, //< Clock source is CTIMERB4 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x1A, //< Clock source is CTIMERB1 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A3 Function Select.
        enum class TMRA3FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A3, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A3, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A3, assert, count to CMPR1A3, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A3, assert, count to CMPR1A3, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A3 Clock Select.
        enum class TMRA3CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB3 = 0x14, //< Clock source is CTIMERB3 OUT.
            CTMRA2 = 0x15, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x16, //< Clock source is CTIMERB2 OUT.
            CTMRA4 = 0x17, //< Clock source is CTIMERA4 OUT.
            CTMRB4 = 0x18, //< Clock source is CTIMERB4 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x1A, //< Clock source is CTIMERB1 OUT.
            CTMRB5 = 0x1B, //< Clock source is CTIMERB5 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B3 Trigger Select.
        enum class TMRB3TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A3OUT = 0x1, //< Trigger source is CTIMERA3 OUT.
            B2OUT = 0x2, //< Trigger source is CTIMERB2 OUT.
            A2OUT = 0x3, //< Trigger source is CTIMERA2 OUT.
            A4OUT = 0x4, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x5, //< Trigger source is CTIMERB4 OUT.
            A6OUT = 0x6, //< Trigger source is CTIMERA6 OUT.
            B6OUT = 0x7, //< Trigger source is CTIMERB6 OUT.
            B5OUT2 = 0x8, //< Trigger source is CTIMERB5 OUT2.
            A5OUT2 = 0x9, //< Trigger source is CTIMERA5 OUT2.
            A1OUT2 = 0xA, //< Trigger source is CTIMERA1 OUT2.
            B1OUT2 = 0xB, //< Trigger source is CTIMERB1 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B2OUT2DUAL = 0xE, //< Trigger source is CTIMERB2 OUT2, dual edge.
            A2OUT2DUAL = 0xF, //< Trigger source is CTIMERA2 OUT2, dual edge.
        };
    
        /// Counter/Timer A3 Trigger Select.
        enum class TMRA3TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            B3OUT = 0x1, //< Trigger source is CTIMERB3 OUT.
            B2OUT = 0x2, //< Trigger source is CTIMERB2 OUT.
            A2OUT = 0x3, //< Trigger source is CTIMERA2 OUT.
            A4OUT = 0x4, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x5, //< Trigger source is CTIMERB4 OUT.
            A7OUT = 0x6, //< Trigger source is CTIMERA7 OUT.
            B7OUT = 0x7, //< Trigger source is CTIMERB7 OUT.
            B5OUT2 = 0x8, //< Trigger source is CTIMERB5 OUT2.
            A5OUT2 = 0x9, //< Trigger source is CTIMERA5 OUT2.
            A1OUT2 = 0xA, //< Trigger source is CTIMERA1 OUT2.
            B1OUT2 = 0xB, //< Trigger source is CTIMERB1 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B2OUT2DUAL = 0xE, //< Trigger source is CTIMERB2 OUT2, dual edge.
            A2OUT2DUAL = 0xF, //< Trigger source is CTIMERA2 OUT2, dual edge.
        };
    
        /// Counter/Timer B4 Function Select.
        enum class TMRB4FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B4, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B4, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B4, assert, count to CMPR1B4, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B4, assert, count to CMPR1B4, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B4 Clock Select.
        enum class TMRB4CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA4 = 0x14, //< Clock source is CTIMERA4 OUT.
            CTMRA1 = 0x15, //< Clock source is CTIMERA1 OUT.
            CTMRB1 = 0x16, //< Clock source is CTIMERB1 OUT.
            CTMRA5 = 0x17, //< Clock source is CTIMERA5 OUT.
            CTMRB5 = 0x18, //< Clock source is CTIMERB5 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB2 = 0x1A, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x1B, //< Clock source is CTIMERB3 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A4 Function Select.
        enum class TMRA4FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A4, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A4, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A4, assert, count to CMPR1A4, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A4, assert, count to CMPR1A4, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A4 Clock Select.
        enum class TMRA4CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4. (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB4 = 0x14, //< Clock source is CTIMERB4 OUT.
            CTMRA1 = 0x15, //< Clock source is CTIMERA1 OUT.
            CTMRB1 = 0x16, //< Clock source is CTIMERB1 OUT.
            CTMRA5 = 0x17, //< Clock source is CTIMERA5 OUT.
            CTMRB5 = 0x18, //< Clock source is CTIMERB5 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB2 = 0x1A, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x1B, //< Clock source is CTIMERB3 OUT.
            CTMRB6 = 0x1C, //< Clock source is CTIMERB6 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B4 Trigger Select.
        enum class TMRB4TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A4OUT = 0x1, //< Trigger source is CTIMERA4 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A7OUT = 0x4, //< Trigger source is CTIMERA7 OUT.
            B7OUT = 0x5, //< Trigger source is CTIMERB7 OUT.
            A1OUT = 0x6, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x7, //< Trigger source is CTIMERB1 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A1OUT2 = 0xA, //< Trigger source is CTIMERA1 OUT2.
            B1OUT2 = 0xB, //< Trigger source is CTIMERB1 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B5OUT2DUAL = 0xE, //< Trigger source is CTIMERB5 OUT2, dual edge.
            A5OUT2DUAL = 0xF, //< Trigger source is CTIMERA5 OUT2, dual edge.
        };
    
        /// Counter/Timer A4 Trigger Select.
        enum class TMRA4TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            STIMER = 0x1, //< Trigger source is STimer Interrupt.  Only Active When CTLINK==1 and TMRB4TRIG!=0.  TMRB4TRIG selects an STIMER interrupt
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A6OUT = 0x4, //< Trigger source is CTIMERA6 OUT.
            B6OUT = 0x5, //< Trigger source is CTIMERB6 OUT.
            A2OUT = 0x6, //< Trigger source is CTIMERA2 OUT.
            B2OUT = 0x7, //< Trigger source is CTIMERB2 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A1OUT2 = 0xA, //< Trigger source is CTIMERA1 OUT2.
            B1OUT2 = 0xB, //< Trigger source is CTIMERB1 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B5OUT2DUAL = 0xE, //< Trigger source is CTIMERB5 OUT2, dual edge.
            A5OUT2DUAL = 0xF, //< Trigger source is CTIMERA5 OUT2, dual edge.
        };
    
        /// Counter/Timer B5 Function Select.
        enum class TMRB5FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B5, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B5, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B5, assert, count to CMPR1B5, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B5, assert, count to CMPR1B5, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B5 Clock Select.
        enum class TMRB5CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA5 = 0x14, //< Clock source is CTIMERA5 OUT.
            CTMRA0 = 0x15, //< Clock source is CTIMERA0 OUT.
            CTMRB0 = 0x16, //< Clock source is CTIMERB0 OUT.
            CTMRA6 = 0x17, //< Clock source is CTIMERA6 OUT.
            CTMRB6 = 0x18, //< Clock source is CTIMERB6 OUT.
            CTMRB1 = 0x19, //< Clock source is CTIMERB1 OUT.
            CTMRB2 = 0x1A, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x1B, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1C, //< Clock source is CTIMERB4 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A5 Function Select.
        enum class TMRA5FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A5, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A5, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A5, assert, count to CMPR1A5, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A5, assert, count to CMPR1A5, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A5 Clock Select.
        enum class TMRA5CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB5 = 0x14, //< Clock source is CTIMERB5 OUT.
            CTMRA0 = 0x15, //< Clock source is CTIMERA0 OUT.
            CTMRB0 = 0x16, //< Clock source is CTIMERB0 OUT.
            CTMRA6 = 0x17, //< Clock source is CTIMERA6 OUT.
            CTMRB6 = 0x18, //< Clock source is CTIMERB6 OUT.
            CTMRB1 = 0x19, //< Clock source is CTIMERB1 OUT.
            CTMRB2 = 0x1A, //< Clock source is CTIMERB2 OUT.
            CTMRB3 = 0x1B, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1C, //< Clock source is CTIMERB4 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B5 Trigger Select.
        enum class TMRB5TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A5OUT = 0x1, //< Trigger source is CTIMERA5 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A6OUT = 0x4, //< Trigger source is CTIMERA6 OUT.
            B6OUT = 0x5, //< Trigger source is CTIMERB6 OUT.
            A1OUT = 0x6, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x7, //< Trigger source is CTIMERB1 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A0OUT2 = 0xA, //< Trigger source is CTIMERA0 OUT2.
            B0OUT2 = 0xB, //< Trigger source is CTIMERB0 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B4OUT2DUAL = 0xE, //< Trigger source is CTIMERB4 OUT2, dual edge.
            A4OUT2DUAL = 0xF, //< Trigger source is CTIMERA4 OUT2, dual edge.
        };
    
        /// Counter/Timer A5 Trigger Select.
        enum class TMRA5TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            STIMER = 0x1, //< Trigger source is STimer Interrupt.  Only Active When CTLINK==1 and TMRB5TRIG!=0.  TMRB5TRIG selects an STIMER interrupt
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A4OUT = 0x4, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x5, //< Trigger source is CTIMERB4 OUT.
            A2OUT = 0x6, //< Trigger source is CTIMERA2 OUT.
            B2OUT = 0x7, //< Trigger source is CTIMERB2 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A0OUT2 = 0xA, //< Trigger source is CTIMERA0 OUT2.
            B0OUT2 = 0xB, //< Trigger source is CTIMERB0 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B4OUT2DUAL = 0xE, //< Trigger source is CTIMERB4 OUT2, dual edge.
            A4OUT2DUAL = 0xF, //< Trigger source is CTIMERA4 OUT2, dual edge.
        };
    
        /// Counter/Timer B6 Function Select.
        enum class TMRB6FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B6, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B6, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B6, assert, count to CMPR1B6, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B6, assert, count to CMPR1B6, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B6 Clock Select.
        enum class TMRB6CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA6 = 0x14, //< Clock source is CTIMERA6 OUT.
            CTMRA3 = 0x15, //< Clock source is CTIMERA3 OUT.
            CTMRB3 = 0x16, //< Clock source is CTIMERB3 OUT.
            CTMRA7 = 0x17, //< Clock source is CTIMERA7 OUT.
            CTMRB7 = 0x18, //< Clock source is CTIMERB7 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x1A, //< Clock source is CTIMERB1 OUT.
            CTMRB2 = 0x1B, //< Clock source is CTIMERB2 OUT.
            CTMRB4 = 0x1C, //< Clock source is CTIMERB4 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A6 Function Select.
        enum class TMRA6FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A6, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A6, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A6, assert, count to CMPR1A6, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A6, assert, count to CMPR1A6, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A6 Clock Select.
        enum class TMRA6CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB6 = 0x14, //< Clock source is CTIMERB6 OUT.
            CTMRA3 = 0x15, //< Clock source is CTIMERA3 OUT.
            CTMRB3 = 0x16, //< Clock source is CTIMERB3 OUT.
            CTMRA7 = 0x17, //< Clock source is CTIMERA7 OUT.
            CTMRB7 = 0x18, //< Clock source is CTIMERB7 OUT.
            CTMRB0 = 0x19, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x1A, //< Clock source is CTIMERB1 OUT.
            CTMRB2 = 0x1B, //< Clock source is CTIMERB2 OUT.
            CTMRB4 = 0x1C, //< Clock source is CTIMERB4 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B6 Trigger Select.
        enum class TMRB6TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A6OUT = 0x1, //< Trigger source is CTIMERA6 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A4OUT = 0x4, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x5, //< Trigger source is CTIMERB4 OUT.
            A1OUT = 0x6, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x7, //< Trigger source is CTIMERB1 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A2OUT2 = 0xA, //< Trigger source is CTIMERA2 OUT2.
            B2OUT2 = 0xB, //< Trigger source is CTIMERB2 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B0OUT2DUAL = 0xE, //< Trigger source is CTIMERB0 OUT2, dual edge.
            A0OUT2DUAL = 0xF, //< Trigger source is CTIMERA0 OUT2, dual edge.
        };
    
        /// Counter/Timer A6 Trigger Select.
        enum class TMRA6TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            B6OUT = 0x1, //< Trigger source is CTIMERB6 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A5OUT = 0x4, //< Trigger source is CTIMERA5 OUT.
            B5OUT = 0x5, //< Trigger source is CTIMERB5 OUT.
            A1OUT = 0x6, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x7, //< Trigger source is CTIMERB1 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A2OUT2 = 0xA, //< Trigger source is CTIMERA2 OUT2.
            B2OUT2 = 0xB, //< Trigger source is CTIMERBb OUT2.
            A5OUT2DUAL = 0xC, //< Trigger source is CTIMERA5 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B0OUT2DUAL = 0xE, //< Trigger source is CTIMERB0 OUT2, dual edge.
            A0OUT2DUAL = 0xF, //< Trigger source is CTIMERA0 OUT2, dual edge.
        };
    
        /// Counter/Timer B7 Function Select.
        enum class TMRB7FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0B7, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0B7, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0B7, assert, count to CMPR1B7, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0B7, assert, count to CMPR1B7, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer B7 Clock Select.
        enum class TMRB7CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINB.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRA7 = 0x14, //< Clock source is CTIMERA7 OUT.
            CTMRA2 = 0x15, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x16, //< Clock source is CTIMERB2 OUT.
            CTMRA0 = 0x17, //< Clock source is CTIMERA0 OUT.
            CTMRB0 = 0x18, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x19, //< Clock source is CTIMERB1 OUT.
            CTMRB3 = 0x1A, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1B, //< Clock source is CTIMERB4 OUT.
            CTMRB5 = 0x1C, //< Clock source is CTIMERB5 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer A7 Function Select.
        enum class TMRA7FNv : uint32_t {
            SINGLECOUNT = 0x0, //< Single count (output toggles and sticks).  Count to CMPR0A7, stop.
            REPEATEDCOUNT = 0x1, //< Repeated count (periodic 1-clock-cycle-wide pulses).  Count to CMPR0A7, restart.
            PULSE_ONCE = 0x2, //< Pulse once (aka one-shot).  Count to CMPR0A7, assert, count to CMPR1A7, deassert, stop.
            PULSE_CONT = 0x3, //< Pulse continously.  Count to CMPR0A7, assert, count to CMPR1A7, deassert, restart.
            SINGLEPATTERN = 0x4, //< Single pattern.
            REPEATPATTERN = 0x5, //< Repeated pattern.
            CONTINUOUS = 0x6, //< Continuous run (aka Free Run).  Count continuously.
            ALTPWN = 0x7, //< Alternate PWM
        };
    
        /// Counter/Timer A7 Clock Select.
        enum class TMRA7CLKv : uint32_t {
            TMRPIN = 0x0, //< Clock source is TMRPINA.
            HFRC_DIV4 = 0x1, //< Clock source is the HFRC / 4
            HFRC_DIV16 = 0x2, //< Clock source is HFRC / 16
            HFRC_DIV256 = 0x3, //< Clock source is HFRC / 256
            HFRC_DIV1024 = 0x4, //< Clock source is HFRC / 1024
            HFRC_DIV4K = 0x5, //< Clock source is HFRC / 4096
            XT = 0x6, //< Clock source is the XT (uncalibrated).
            XT_DIV2 = 0x7, //< Clock source is XT / 2
            XT_DIV16 = 0x8, //< Clock source is XT / 16
            XT_DIV128 = 0x9, //< Clock source is XT / 128
            LFRC_DIV2 = 0xA, //< Clock source is LFRC / 2
            LFRC_DIV32 = 0xB, //< Clock source is LFRC / 32
            LFRC_DIV1K = 0xC, //< Clock source is LFRC / 1024
            LFRC = 0xD, //< Clock source is LFRC
            RTC_100HZ = 0xE, //< Clock source is 100 Hz from the current RTC oscillator.
            HCLK_DIV4 = 0xF, //< Clock source is HCLK / 4 (note: this clock is only available when MCU is in active mode)
            XT_DIV4 = 0x10, //< Clock source is XT / 4
            XT_DIV8 = 0x11, //< Clock source is XT / 8
            XT_DIV32 = 0x12, //< Clock source is XT / 32
            CTMRB7 = 0x14, //< Clock source is CTIMERB7 OUT.
            CTMRA2 = 0x15, //< Clock source is CTIMERA2 OUT.
            CTMRB2 = 0x16, //< Clock source is CTIMERB2 OUT.
            CTMRA0 = 0x17, //< Clock source is CTIMERA0 OUT.
            CTMRB0 = 0x18, //< Clock source is CTIMERB0 OUT.
            CTMRB1 = 0x19, //< Clock source is CTIMERB1 OUT.
            CTMRB3 = 0x1A, //< Clock source is CTIMERB3 OUT.
            CTMRB4 = 0x1B, //< Clock source is CTIMERB4 OUT.
            CTMRB5 = 0x1C, //< Clock source is CTIMERB5 OUT.
            BUCKBLE = 0x1D, //< Clock source is BLE buck converter TON pulses.
            BUCKB = 0x1E, //< Clock source is Memory buck converter TON pulses.
            BUCKA = 0x1F, //< Clock source is CPU buck converter TON pulses.
        };
    
        /// Counter/Timer B7 Trigger Select.
        enum class TMRB7TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            A7OUT = 0x1, //< Trigger source is CTIMERA7 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A5OUT = 0x4, //< Trigger source is CTIMERA5 OUT.
            B5OUT = 0x5, //< Trigger source is CTIMERB5 OUT.
            A2OUT = 0x6, //< Trigger source is CTIMERA2 OUT.
            B2OUT = 0x7, //< Trigger source is CTIMERB2 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A2OUT2 = 0xA, //< Trigger source is CTIMERA2 OUT2.
            B2OUT2 = 0xB, //< Trigger source is CTIMERB2 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A7OUT2DUAL = 0xD, //< Trigger source is CTIMERA7 OUT2, dual edge.
            B1OUT2DUAL = 0xE, //< Trigger source is CTIMERB1 OUT2, dual edge.
            A1OUT2DUAL = 0xF, //< Trigger source is CTIMERA1 OUT2, dual edge.
        };
    
        /// Counter/Timer A7 Trigger Select.
        enum class TMRA7TRIGv : uint32_t {
            DIS = 0x0, //< Trigger source is disabled.
            B7OUT = 0x1, //< Trigger source is CTIMERB7 OUT.
            B3OUT = 0x2, //< Trigger source is CTIMERB3 OUT.
            A3OUT = 0x3, //< Trigger source is CTIMERA3 OUT.
            A1OUT = 0x4, //< Trigger source is CTIMERA1 OUT.
            B1OUT = 0x5, //< Trigger source is CTIMERB1 OUT.
            A4OUT = 0x6, //< Trigger source is CTIMERA4 OUT.
            B4OUT = 0x7, //< Trigger source is CTIMERB4 OUT.
            B3OUT2 = 0x8, //< Trigger source is CTIMERB3 OUT2.
            A3OUT2 = 0x9, //< Trigger source is CTIMERA3 OUT2.
            A2OUT2 = 0xA, //< Trigger source is CTIMERA2 OUT2.
            B2OUT2 = 0xB, //< Trigger source is CTIMERB2 OUT2.
            A6OUT2DUAL = 0xC, //< Trigger source is CTIMERA6 OUT2, dual edge.
            A5OUT2DUAL = 0xD, //< Trigger source is CTIMERA5 OUT2, dual edge.
            B4OUT2DUAL = 0xE, //< Trigger source is CTIMERB4 OUT2, dual edge.
            A4OUT2DUAL = 0xF, //< Trigger source is CTIMERA4 OUT2, dual edge.
        };
    
        /// Pad output 9 configuration
        enum class CFG9v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B0OUT = 0x5, //< Output is B0OUT.
            A4OUT = 0x4, //< Output is A4OUT.
            A2OUT = 0x3, //< Output is A2OUT.
            A2OUT2 = 0x2, //< Output is A2OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 8 configuration
        enum class CFG8v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B6OUT = 0x5, //< Output is B6OUT.
            A4OUT2 = 0x4, //< Output is A4OUT2.
            A3OUT2 = 0x3, //< Output is A3OUT.
            A2OUT = 0x2, //< Output is A2OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 7 configuration
        enum class CFG7v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A7OUT = 0x5, //< Output is A7OUT.
            B5OUT = 0x4, //< Output is B5OUT.
            B1OUT = 0x3, //< Output is B1OUT.
            B1OUT2 = 0x2, //< Output is B1OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 6 configuration
        enum class CFG6v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B7OUT = 0x5, //< Output is B7OUT.
            B5OUT2 = 0x4, //< Output is B5OUT2.
            A1OUT = 0x3, //< Output is A1OUT.
            B1OUT = 0x2, //< Output is B1OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 5 configuration
        enum class CFG5v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A7OUT = 0x5, //< Output is A7OUT.
            B6OUT = 0x4, //< Output is A5OUT.
            A1OUT = 0x3, //< Output is A1OUT.
            A1OUT2 = 0x2, //< Output is A1OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 4 configuration
        enum class CFG4v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B5OUT = 0x5, //< Output is B5OUT.
            A5OUT2 = 0x4, //< Output is A5OUT2.
            A2OUT2 = 0x3, //< Output is A2OUT2.
            A1OUT = 0x2, //< Output is A1OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 3 configuration
        enum class CFG3v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A6OUT = 0x5, //< Output is A6OUT.
            A1OUT = 0x4, //< Output is A1OUT.
            B0OUT = 0x3, //< Output is B0OUT.
            B0OUT2 = 0x2, //< Output is B0OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 2 configuration
        enum class CFG2v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A7OUT = 0x5, //< Output is A7OUT.
            B6OUT2 = 0x4, //< Output is B6OUT2.
            B1OUT2 = 0x3, //< Output is B1OUT2.
            B0OUT = 0x2, //< Output is B0OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 1 configuration
        enum class CFG1v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B7OUT2 = 0x5, //< Output is B7OUT2.
            A5OUT = 0x4, //< Output is A5OUT.
            A0OUT = 0x3, //< Output is A0OUT.
            A0OUT2 = 0x2, //< Output is A0OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 0 configuration
        enum class CFG0v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A6OUT = 0x5, //< Output is A6OUT.
            A5OUT2 = 0x4, //< Output is A5OUT2.
            B2OUT2 = 0x3, //< Output is B2OUT2.
            A0OUT = 0x2, //< Output is A0OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 19 configuration
        enum class CFG19v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B1OUT2 = 0x5, //< Output is B1OUT2.
            B4OUT = 0x4, //< Output is B4OUT.
            A2OUT = 0x3, //< Output is A2OUT.
            B4OUT2 = 0x2, //< Output is B4OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 18 configuration
        enum class CFG18v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A3OUT2 = 0x5, //< Output is A3OUT2.
            A0OUT = 0x4, //< Output is A0OUT.
            B0OUT = 0x3, //< Output is B0OUT.
            B4OUT = 0x2, //< Output is B4OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 17 configuration
        enum class CFG17v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A1OUT2 = 0x5, //< Output is A1OUT2.
            A4OUT = 0x4, //< Output is A4OUT.
            B7OUT = 0x3, //< Output is B7OUT.
            A4OUT2 = 0x2, //< Output is A4OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 16 configuration
        enum class CFG16v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B3OUT2 = 0x5, //< Output is B3OUT2.
            A0OUT2 = 0x4, //< Output is A0OUT2.
            A0OUT = 0x3, //< Output is A0OUT.
            A4OUT = 0x2, //< Output is A4OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 15 configuration
        enum class CFG15v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A4OUT2 = 0x5, //< Output is A4OUT2.
            A7OUT = 0x4, //< Output is A7OUT.
            B3OUT = 0x3, //< Output is B3OUT.
            B3OUT2 = 0x2, //< Output is B3OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 14 configuration
        enum class CFG14v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A7OUT = 0x5, //< Output is A7OUT.
            B7OUT2 = 0x4, //< Output is B7OUT2.
            B1OUT = 0x3, //< Output is B1OUT.
            B3OUT = 0x2, //< Output is B3OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 13 configuration
        enum class CFG13v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B4OUT2 = 0x5, //< Output is B4OUT2.
            A6OUT = 0x4, //< Output is A6OUT.
            A3OUT = 0x3, //< Output is A3OUT.
            A3OUT2 = 0x2, //< Output is A3OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 12 configuration
        enum class CFG12v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B6OUT2 = 0x5, //< Output is B6OUT2.
            B0OUT2 = 0x4, //< Output is B0OUT2.
            B1OUT = 0x3, //< Output is B1OUT.
            A3OUT = 0x2, //< Output is A3OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 11 configuration
        enum class CFG11v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B5OUT2 = 0x5, //< Output is B5OUT2.
            B4OUT = 0x4, //< Output is B4OUT.
            B2OUT = 0x3, //< Output is B2OUT.
            B2OUT2 = 0x2, //< Output is B2OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 10 configuration
        enum class CFG10v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A6OUT = 0x5, //< Output is A6OUT.
            B4OUT2 = 0x4, //< Output is B4OUT2.
            B3OUT2 = 0x3, //< Output is B3OUT2.
            B2OUT = 0x2, //< Output is B2OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 29 configuration
        enum class CFG29v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A3OUT2 = 0x5, //< Output is A3OUT2.
            A7OUT = 0x4, //< Output is A7OUT.
            A1OUT = 0x3, //< Output is A1OUT.
            B5OUT2 = 0x2, //< Output is B5OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 28 configuration
        enum class CFG28v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B0OUT2 = 0x5, //< Output is B0OUT2.
            A5OUT2 = 0x4, //< Output is A5OUT2.
            A3OUT = 0x3, //< Output is A3OUT.
            A7OUT = 0x2, //< Output is A7OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 27 configuration
        enum class CFG27v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B2OUT2 = 0x5, //< Output is B2OUT2.
            B6OUT = 0x4, //< Output is B6OUT.
            A1OUT = 0x3, //< Output is A1OUT.
            B6OUT2 = 0x2, //< Output is B6OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 26 configuration
        enum class CFG26v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A1OUT2 = 0x5, //< Output is A1OUT2.
            A5OUT = 0x4, //< Output is A5OUT.
            B2OUT = 0x3, //< Output is B2OUT.
            B6OUT = 0x2, //< Output is B6OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 25 configuration
        enum class CFG25v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A2OUT2 = 0x5, //< Output is A2OUT2.
            A6OUT = 0x4, //< Output is A6OUT.
            B2OUT = 0x3, //< Output is B2OUT.
            B4OUT2 = 0x2, //< Output is B4OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 24 configuration
        enum class CFG24v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B1OUT2 = 0x5, //< Output is B1OUT2.
            A1OUT = 0x4, //< Output is A1OUT.
            A2OUT = 0x3, //< Output is A2OUT.
            A6OUT = 0x2, //< Output is A6OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 23 configuration
        enum class CFG23v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B0OUT2 = 0x5, //< Output is B0OUT2.
            A5OUT = 0x4, //< Output is A5OUT.
            A7OUT = 0x3, //< Output is A7OUT.
            B5OUT2 = 0x2, //< Output is B5OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 22 configuration
        enum class CFG22v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A2OUT2 = 0x5, //< Output is A2OUT2.
            A1OUT = 0x4, //< Output is A1OUT.
            A6OUT = 0x3, //< Output is A6OUT.
            B5OUT = 0x2, //< Output is B5OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 21 configuration
        enum class CFG21v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A0OUT2 = 0x5, //< Output is A0OUT2.
            B5OUT = 0x4, //< Output is B5OUT.
            A1OUT = 0x3, //< Output is A1OUT.
            A5OUT2 = 0x2, //< Output is A5OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 20 configuration
        enum class CFG20v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B2OUT2 = 0x5, //< Output is B2OUT2.
            A1OUT2 = 0x4, //< Output is A1OUT2.
            A1OUT = 0x3, //< Output is A1OUT.
            A5OUT = 0x2, //< Output is A5OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 31 configuration
        enum class CFG31v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            B3OUT2 = 0x5, //< Output is B3OUT2.
            B7OUT = 0x4, //< Output is B7OUT.
            A6OUT = 0x3, //< Output is A6OUT.
            B7OUT2 = 0x2, //< Output is B7OUT2
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Pad output 30 configuration
        enum class CFG30v : uint32_t {
            A7OUT2 = 0x7, //< Output is A7OUT2.
            A6OUT2 = 0x6, //< Output is A6OUT2.
            A0OUT2 = 0x5, //< Output is A0OUT2.
            A4OUT2 = 0x4, //< Output is A4OUT2.
            B3OUT = 0x3, //< Output is B3OUT.
            B7OUT = 0x2, //< Output is B7OUT
            ONE = 0x1, //< Force output to 1.
            ZERO = 0x0, //< Force output to 0
        };
    
        /// Selects an appropriate clock source and divider to use for the System Timer clock.
        enum class CLKSELv : uint32_t {
            NOCLK = 0x0, //< No clock enabled.
            HFRC_DIV16 = 0x1, //< 3MHz from the HFRC clock divider.
            HFRC_DIV256 = 0x2, //< 187.5KHz from the HFRC clock divider.
            XTAL_DIV1 = 0x3, //< 32768Hz from the crystal oscillator.
            XTAL_DIV2 = 0x4, //< 16384Hz from the crystal oscillator.
            XTAL_DIV32 = 0x5, //< 1024Hz from the crystal oscillator.
            LFRC_DIV1 = 0x6, //< Approximately 1KHz from the LFRC oscillator (uncalibrated).
            CTIMER0A = 0x7, //< Use CTIMER 0 section A as a prescaler for the clock source.
            CTIMER0B = 0x8, //< Use CTIMER 0 section B (or A and B linked together) as a prescaler for the clock source.
        };
    
    }   // namespace CTIMER

    /// Counter/Timer
    template <addressType BASE_ADDRESS>
    struct CTIMER_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * TMR0 - 4 bytes at offset 0
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR0_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B0.
            static constexpr bitfield_t<TMR0_t, 31, 16> CTTMRB0 = {};

            /// Counter/Timer A0.
            static constexpr bitfield_t<TMR0_t, 15, 0> CTTMRA0 = {};
        } TMR0 = {};

        /**
         * CMPRA0 - 4 bytes at offset 4
         * Counter/Timer A0 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA0_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A0 Compare Register 1. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRA0_t, 31, 16> CMPR1A0 = {};

            /// Counter/Timer A0 Compare Register 0. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRA0_t, 15, 0> CMPR0A0 = {};
        } CMPRA0 = {};

        /**
         * CMPRB0 - 4 bytes at offset 8
         * Counter/Timer B0 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB0_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B0 Compare Register 1. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRB0_t, 31, 16> CMPR1B0 = {};

            /// Counter/Timer B0 Compare Register 0. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRB0_t, 15, 0> CMPR0B0 = {};
        } CMPRB0 = {};

        /**
         * CTRL0 - 4 bytes at offset 12
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL0_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A0/B0 Link bit.
            static constexpr bitfield_t<CTRL0_t, 31, 31, bool> CTLINK0 = {};

            /// Counter/Timer B0 output polarity.
            static constexpr bitfield_t<CTRL0_t, 28, 28, bool> TMRB0POL = {};

            /// Counter/Timer B0 Clear bit.
            static constexpr bitfield_t<CTRL0_t, 27, 27, bool> TMRB0CLR = {};

            /// Counter/Timer B0 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL0_t, 26, 26, bool> TMRB0IE1 = {};

            /// Counter/Timer B0 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL0_t, 25, 25, bool> TMRB0IE0 = {};

            /// Counter/Timer B0 Function Select.
            static constexpr bitfield_t<CTRL0_t, 24, 22, CTIMER::TMRB0FNv> TMRB0FN = {};

            /// Counter/Timer B0 Clock Select.
            static constexpr bitfield_t<CTRL0_t, 21, 17, CTIMER::TMRB0CLKv> TMRB0CLK = {};

            /// Counter/Timer B0 Enable bit.
            static constexpr bitfield_t<CTRL0_t, 16, 16, bool> TMRB0EN = {};

            /// Counter/Timer A0 output polarity.
            static constexpr bitfield_t<CTRL0_t, 12, 12, bool> TMRA0POL = {};

            /// Counter/Timer A0 Clear bit.
            static constexpr bitfield_t<CTRL0_t, 11, 11, bool> TMRA0CLR = {};

            /// Counter/Timer A0 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL0_t, 10, 10, bool> TMRA0IE1 = {};

            /// Counter/Timer A0 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL0_t, 9, 9, bool> TMRA0IE0 = {};

            /// Counter/Timer A0 Function Select.
            static constexpr bitfield_t<CTRL0_t, 8, 6, CTIMER::TMRA0FNv> TMRA0FN = {};

            /// Counter/Timer A0 Clock Select.
            static constexpr bitfield_t<CTRL0_t, 5, 1, CTIMER::TMRA0CLKv> TMRA0CLK = {};

            /// Counter/Timer A0 Enable bit.
            static constexpr bitfield_t<CTRL0_t, 0, 0, bool> TMRA0EN = {};
        } CTRL0 = {};

        /**
         * CMPRAUXA0 - 4 bytes at offset 20
         * Counter/Timer A0 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA0_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A0 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA0_t, 31, 16> CMPR3A0 = {};

            /// Counter/Timer A0 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA0_t, 15, 0> CMPR2A0 = {};
        } CMPRAUXA0 = {};

        /**
         * CMPRAUXB0 - 4 bytes at offset 24
         * Counter/Timer B0 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB0_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B0 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB0_t, 31, 16> CMPR3B0 = {};

            /// Counter/Timer B0 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB0_t, 15, 0> CMPR2B0 = {};
        } CMPRAUXB0 = {};

        /**
         * AUX0 - 4 bytes at offset 28
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX0_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B0 Upper compare enable.
            static constexpr bitfield_t<AUX0_t, 30, 30, bool> TMRB0EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX0_t, 29, 29, bool> TMRB0POL23 = {};

            /// Counter/Timer B0 Invert on trigger.
            static constexpr bitfield_t<AUX0_t, 28, 28, bool> TMRB0TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX0_t, 27, 27, bool> TMRB0NOSYNC = {};

            /// Counter/Timer B0 Trigger Select.
            static constexpr bitfield_t<AUX0_t, 26, 23, CTIMER::TMRB0TRIGv> TMRB0TRIG = {};

            /// Counter/Timer B0 Pattern Limit Count.
            static constexpr bitfield_t<AUX0_t, 21, 16> TMRB0LMT = {};

            /// Counter/Timer A0 Upper compare enable.
            static constexpr bitfield_t<AUX0_t, 14, 14, bool> TMRA0EN23 = {};

            /// Counter/Timer A0 Upper output polarity
            static constexpr bitfield_t<AUX0_t, 13, 13, bool> TMRA0POL23 = {};

            /// Counter/Timer A0 Invert on trigger.
            static constexpr bitfield_t<AUX0_t, 12, 12, bool> TMRA0TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX0_t, 11, 11, bool> TMRA0NOSYNC = {};

            /// Counter/Timer A0 Trigger Select.
            static constexpr bitfield_t<AUX0_t, 10, 7, CTIMER::TMRA0TRIGv> TMRA0TRIG = {};

            /// Counter/Timer A0 Pattern Limit Count.
            static constexpr bitfield_t<AUX0_t, 6, 0> TMRA0LMT = {};
        } AUX0 = {};

        /**
         * TMR1 - 4 bytes at offset 32
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR1_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B1.
            static constexpr bitfield_t<TMR1_t, 31, 16> CTTMRB1 = {};

            /// Counter/Timer A1.
            static constexpr bitfield_t<TMR1_t, 15, 0> CTTMRA1 = {};
        } TMR1 = {};

        /**
         * CMPRA1 - 4 bytes at offset 36
         * Counter/Timer A1 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA1_t : reg_t<uint32_t, BASE_ADDRESS + 0x24> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x24>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A1 Compare Register 1.
            static constexpr bitfield_t<CMPRA1_t, 31, 16> CMPR1A1 = {};

            /// Counter/Timer A1 Compare Register 0.
            static constexpr bitfield_t<CMPRA1_t, 15, 0> CMPR0A1 = {};
        } CMPRA1 = {};

        /**
         * CMPRB1 - 4 bytes at offset 40
         * Counter/Timer B1 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB1_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B1 Compare Register 1.
            static constexpr bitfield_t<CMPRB1_t, 31, 16> CMPR1B1 = {};

            /// Counter/Timer B1 Compare Register 0.
            static constexpr bitfield_t<CMPRB1_t, 15, 0> CMPR0B1 = {};
        } CMPRB1 = {};

        /**
         * CTRL1 - 4 bytes at offset 44
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL1_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A1/B1 Link bit.
            static constexpr bitfield_t<CTRL1_t, 31, 31, bool> CTLINK1 = {};

            /// Counter/Timer B1 output polarity.
            static constexpr bitfield_t<CTRL1_t, 28, 28, bool> TMRB1POL = {};

            /// Counter/Timer B1 Clear bit.
            static constexpr bitfield_t<CTRL1_t, 27, 27, bool> TMRB1CLR = {};

            /// Counter/Timer B1 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL1_t, 26, 26, bool> TMRB1IE1 = {};

            /// Counter/Timer B1 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL1_t, 25, 25, bool> TMRB1IE0 = {};

            /// Counter/Timer B1 Function Select.
            static constexpr bitfield_t<CTRL1_t, 24, 22, CTIMER::TMRB1FNv> TMRB1FN = {};

            /// Counter/Timer B1 Clock Select.
            static constexpr bitfield_t<CTRL1_t, 21, 17, CTIMER::TMRB1CLKv> TMRB1CLK = {};

            /// Counter/Timer B1 Enable bit.
            static constexpr bitfield_t<CTRL1_t, 16, 16, bool> TMRB1EN = {};

            /// Counter/Timer A1 output polarity.
            static constexpr bitfield_t<CTRL1_t, 12, 12, bool> TMRA1POL = {};

            /// Counter/Timer A1 Clear bit.
            static constexpr bitfield_t<CTRL1_t, 11, 11, bool> TMRA1CLR = {};

            /// Counter/Timer A1 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL1_t, 10, 10, bool> TMRA1IE1 = {};

            /// Counter/Timer A1 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL1_t, 9, 9, bool> TMRA1IE0 = {};

            /// Counter/Timer A1 Function Select.
            static constexpr bitfield_t<CTRL1_t, 8, 6, CTIMER::TMRA1FNv> TMRA1FN = {};

            /// Counter/Timer A1 Clock Select.
            static constexpr bitfield_t<CTRL1_t, 5, 1, CTIMER::TMRA1CLKv> TMRA1CLK = {};

            /// Counter/Timer A1 Enable bit.
            static constexpr bitfield_t<CTRL1_t, 0, 0, bool> TMRA1EN = {};
        } CTRL1 = {};

        /**
         * CMPRAUXA1 - 4 bytes at offset 52
         * Counter/Timer A1 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA1_t : reg_t<uint32_t, BASE_ADDRESS + 0x34> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x34>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A1 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA1_t, 31, 16> CMPR3A1 = {};

            /// Counter/Timer A1 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA1_t, 15, 0> CMPR2A1 = {};
        } CMPRAUXA1 = {};

        /**
         * CMPRAUXB1 - 4 bytes at offset 56
         * Counter/Timer B1 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB1_t : reg_t<uint32_t, BASE_ADDRESS + 0x38> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x38>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B1 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB1_t, 31, 16> CMPR3B1 = {};

            /// Counter/Timer B1 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB1_t, 15, 0> CMPR2B1 = {};
        } CMPRAUXB1 = {};

        /**
         * AUX1 - 4 bytes at offset 60
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX1_t : reg_t<uint32_t, BASE_ADDRESS + 0x3C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B1 Upper compare enable.
            static constexpr bitfield_t<AUX1_t, 30, 30, bool> TMRB1EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX1_t, 29, 29, bool> TMRB1POL23 = {};

            /// Counter/Timer B1 Invert on trigger.
            static constexpr bitfield_t<AUX1_t, 28, 28, bool> TMRB1TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX1_t, 27, 27, bool> TMRB1NOSYNC = {};

            /// Counter/Timer B1 Trigger Select.
            static constexpr bitfield_t<AUX1_t, 26, 23, CTIMER::TMRB1TRIGv> TMRB1TRIG = {};

            /// Counter/Timer B1 Pattern Limit Count.
            static constexpr bitfield_t<AUX1_t, 21, 16> TMRB1LMT = {};

            /// Counter/Timer A1 Upper compare enable.
            static constexpr bitfield_t<AUX1_t, 14, 14, bool> TMRA1EN23 = {};

            /// Counter/Timer A1 Upper output polarity
            static constexpr bitfield_t<AUX1_t, 13, 13, bool> TMRA1POL23 = {};

            /// Counter/Timer A1 Invert on trigger.
            static constexpr bitfield_t<AUX1_t, 12, 12, bool> TMRA1TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX1_t, 11, 11, bool> TMRA1NOSYNC = {};

            /// Counter/Timer A1 Trigger Select.
            static constexpr bitfield_t<AUX1_t, 10, 7, CTIMER::TMRA1TRIGv> TMRA1TRIG = {};

            /// Counter/Timer A1 Pattern Limit Count.
            static constexpr bitfield_t<AUX1_t, 6, 0> TMRA1LMT = {};
        } AUX1 = {};

        /**
         * TMR2 - 4 bytes at offset 64
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR2_t : reg_t<uint32_t, BASE_ADDRESS + 0x40> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x40>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B2.
            static constexpr bitfield_t<TMR2_t, 31, 16> CTTMRB2 = {};

            /// Counter/Timer A2.
            static constexpr bitfield_t<TMR2_t, 15, 0> CTTMRA2 = {};
        } TMR2 = {};

        /**
         * CMPRA2 - 4 bytes at offset 68
         * Counter/Timer A2 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA2_t : reg_t<uint32_t, BASE_ADDRESS + 0x44> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x44>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A2 Compare Register 1.
            static constexpr bitfield_t<CMPRA2_t, 31, 16> CMPR1A2 = {};

            /// Counter/Timer A2 Compare Register 0.
            static constexpr bitfield_t<CMPRA2_t, 15, 0> CMPR0A2 = {};
        } CMPRA2 = {};

        /**
         * CMPRB2 - 4 bytes at offset 72
         * Counter/Timer B2 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB2_t : reg_t<uint32_t, BASE_ADDRESS + 0x48> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x48>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B2 Compare Register 1.
            static constexpr bitfield_t<CMPRB2_t, 31, 16> CMPR1B2 = {};

            /// Counter/Timer B2 Compare Register 0.
            static constexpr bitfield_t<CMPRB2_t, 15, 0> CMPR0B2 = {};
        } CMPRB2 = {};

        /**
         * CTRL2 - 4 bytes at offset 76
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL2_t : reg_t<uint32_t, BASE_ADDRESS + 0x4C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4C>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A2/B2 Link bit.
            static constexpr bitfield_t<CTRL2_t, 31, 31, bool> CTLINK2 = {};

            /// Counter/Timer B2 output polarity.
            static constexpr bitfield_t<CTRL2_t, 28, 28, bool> TMRB2POL = {};

            /// Counter/Timer B2 Clear bit.
            static constexpr bitfield_t<CTRL2_t, 27, 27, bool> TMRB2CLR = {};

            /// Counter/Timer B2 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL2_t, 26, 26, bool> TMRB2IE1 = {};

            /// Counter/Timer B2 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL2_t, 25, 25, bool> TMRB2IE0 = {};

            /// Counter/Timer B2 Function Select.
            static constexpr bitfield_t<CTRL2_t, 24, 22, CTIMER::TMRB2FNv> TMRB2FN = {};

            /// Counter/Timer B2 Clock Select.
            static constexpr bitfield_t<CTRL2_t, 21, 17, CTIMER::TMRB2CLKv> TMRB2CLK = {};

            /// Counter/Timer B2 Enable bit.
            static constexpr bitfield_t<CTRL2_t, 16, 16, bool> TMRB2EN = {};

            /// Counter/Timer A2 output polarity.
            static constexpr bitfield_t<CTRL2_t, 12, 12, bool> TMRA2POL = {};

            /// Counter/Timer A2 Clear bit.
            static constexpr bitfield_t<CTRL2_t, 11, 11, bool> TMRA2CLR = {};

            /// Counter/Timer A2 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL2_t, 10, 10, bool> TMRA2IE1 = {};

            /// Counter/Timer A2 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL2_t, 9, 9, bool> TMRA2IE0 = {};

            /// Counter/Timer A2 Function Select.
            static constexpr bitfield_t<CTRL2_t, 8, 6, CTIMER::TMRA2FNv> TMRA2FN = {};

            /// Counter/Timer A2 Clock Select.
            static constexpr bitfield_t<CTRL2_t, 5, 1, CTIMER::TMRA2CLKv> TMRA2CLK = {};

            /// Counter/Timer A2 Enable bit.
            static constexpr bitfield_t<CTRL2_t, 0, 0, bool> TMRA2EN = {};
        } CTRL2 = {};

        /**
         * CMPRAUXA2 - 4 bytes at offset 84
         * Counter/Timer A2 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA2_t : reg_t<uint32_t, BASE_ADDRESS + 0x54> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x54>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A2 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA2_t, 31, 16> CMPR3A2 = {};

            /// Counter/Timer A2 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA2_t, 15, 0> CMPR2A2 = {};
        } CMPRAUXA2 = {};

        /**
         * CMPRAUXB2 - 4 bytes at offset 88
         * Counter/Timer B2 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB2_t : reg_t<uint32_t, BASE_ADDRESS + 0x58> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x58>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B2 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB2_t, 31, 16> CMPR3B2 = {};

            /// Counter/Timer B2 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB2_t, 15, 0> CMPR2B2 = {};
        } CMPRAUXB2 = {};

        /**
         * AUX2 - 4 bytes at offset 92
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX2_t : reg_t<uint32_t, BASE_ADDRESS + 0x5C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x5C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B2 Upper compare enable.
            static constexpr bitfield_t<AUX2_t, 30, 30, bool> TMRB2EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX2_t, 29, 29, bool> TMRB2POL23 = {};

            /// Counter/Timer B2 Invert on trigger.
            static constexpr bitfield_t<AUX2_t, 28, 28, bool> TMRB2TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX2_t, 27, 27, bool> TMRB2NOSYNC = {};

            /// Counter/Timer B2 Trigger Select.
            static constexpr bitfield_t<AUX2_t, 26, 23, CTIMER::TMRB2TRIGv> TMRB2TRIG = {};

            /// Counter/Timer B2 Pattern Limit Count.
            static constexpr bitfield_t<AUX2_t, 21, 16> TMRB2LMT = {};

            /// Counter/Timer A2 Upper compare enable.
            static constexpr bitfield_t<AUX2_t, 14, 14, bool> TMRA2EN23 = {};

            /// Counter/Timer A2 Upper output polarity
            static constexpr bitfield_t<AUX2_t, 13, 13, bool> TMRA2POL23 = {};

            /// Counter/Timer A2 Invert on trigger.
            static constexpr bitfield_t<AUX2_t, 12, 12, bool> TMRA2TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX2_t, 11, 11, bool> TMRA2NOSYNC = {};

            /// Counter/Timer A2 Trigger Select.
            static constexpr bitfield_t<AUX2_t, 10, 7, CTIMER::TMRA2TRIGv> TMRA2TRIG = {};

            /// Counter/Timer A2 Pattern Limit Count.
            static constexpr bitfield_t<AUX2_t, 6, 0> TMRA2LMT = {};
        } AUX2 = {};

        /**
         * TMR3 - 4 bytes at offset 96
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR3_t : reg_t<uint32_t, BASE_ADDRESS + 0x60> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x60>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B3.
            static constexpr bitfield_t<TMR3_t, 31, 16> CTTMRB3 = {};

            /// Counter/Timer A3.
            static constexpr bitfield_t<TMR3_t, 15, 0> CTTMRA3 = {};
        } TMR3 = {};

        /**
         * CMPRA3 - 4 bytes at offset 100
         * Counter/Timer A3 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA3_t : reg_t<uint32_t, BASE_ADDRESS + 0x64> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x64>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A3 Compare Register 1.
            static constexpr bitfield_t<CMPRA3_t, 31, 16> CMPR1A3 = {};

            /// Counter/Timer A3 Compare Register 0.
            static constexpr bitfield_t<CMPRA3_t, 15, 0> CMPR0A3 = {};
        } CMPRA3 = {};

        /**
         * CMPRB3 - 4 bytes at offset 104
         * Counter/Timer B3 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB3_t : reg_t<uint32_t, BASE_ADDRESS + 0x68> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x68>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B3 Compare Register 1.
            static constexpr bitfield_t<CMPRB3_t, 31, 16> CMPR1B3 = {};

            /// Counter/Timer B3 Compare Register 0.
            static constexpr bitfield_t<CMPRB3_t, 15, 0> CMPR0B3 = {};
        } CMPRB3 = {};

        /**
         * CTRL3 - 4 bytes at offset 108
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL3_t : reg_t<uint32_t, BASE_ADDRESS + 0x6C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x6C>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF9FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A3/B3 Link bit.
            static constexpr bitfield_t<CTRL3_t, 31, 31, bool> CTLINK3 = {};

            /// Counter/Timer B3 output polarity.
            static constexpr bitfield_t<CTRL3_t, 28, 28, bool> TMRB3POL = {};

            /// Counter/Timer B3 Clear bit.
            static constexpr bitfield_t<CTRL3_t, 27, 27, bool> TMRB3CLR = {};

            /// Counter/Timer B3 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL3_t, 26, 26, bool> TMRB3IE1 = {};

            /// Counter/Timer B3 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL3_t, 25, 25, bool> TMRB3IE0 = {};

            /// Counter/Timer B3 Function Select.
            static constexpr bitfield_t<CTRL3_t, 24, 22, CTIMER::TMRB3FNv> TMRB3FN = {};

            /// Counter/Timer B3 Clock Select.
            static constexpr bitfield_t<CTRL3_t, 21, 17, CTIMER::TMRB3CLKv> TMRB3CLK = {};

            /// Counter/Timer B3 Enable bit.
            static constexpr bitfield_t<CTRL3_t, 16, 16, bool> TMRB3EN = {};

            /// Special Timer A3 enable for ADC function.
            static constexpr bitfield_t<CTRL3_t, 15, 15, bool> ADCEN = {};

            /// Counter/Timer A3 output polarity.
            static constexpr bitfield_t<CTRL3_t, 12, 12, bool> TMRA3POL = {};

            /// Counter/Timer A3 Clear bit.
            static constexpr bitfield_t<CTRL3_t, 11, 11, bool> TMRA3CLR = {};

            /// Counter/Timer A3 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL3_t, 10, 10, bool> TMRA3IE1 = {};

            /// Counter/Timer A3 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL3_t, 9, 9, bool> TMRA3IE0 = {};

            /// Counter/Timer A3 Function Select.
            static constexpr bitfield_t<CTRL3_t, 8, 6, CTIMER::TMRA3FNv> TMRA3FN = {};

            /// Counter/Timer A3 Clock Select.
            static constexpr bitfield_t<CTRL3_t, 5, 1, CTIMER::TMRA3CLKv> TMRA3CLK = {};

            /// Counter/Timer A3 Enable bit.
            static constexpr bitfield_t<CTRL3_t, 0, 0, bool> TMRA3EN = {};
        } CTRL3 = {};

        /**
         * CMPRAUXA3 - 4 bytes at offset 116
         * Counter/Timer A3 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA3_t : reg_t<uint32_t, BASE_ADDRESS + 0x74> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x74>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A3 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA3_t, 31, 16> CMPR3A3 = {};

            /// Counter/Timer A3 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA3_t, 15, 0> CMPR2A3 = {};
        } CMPRAUXA3 = {};

        /**
         * CMPRAUXB3 - 4 bytes at offset 120
         * Counter/Timer B3 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB3_t : reg_t<uint32_t, BASE_ADDRESS + 0x78> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x78>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B3 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB3_t, 31, 16> CMPR3B3 = {};

            /// Counter/Timer B3 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB3_t, 15, 0> CMPR2B3 = {};
        } CMPRAUXB3 = {};

        /**
         * AUX3 - 4 bytes at offset 124
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX3_t : reg_t<uint32_t, BASE_ADDRESS + 0x7C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x7C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B3 Upper compare enable.
            static constexpr bitfield_t<AUX3_t, 30, 30, bool> TMRB3EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX3_t, 29, 29, bool> TMRB3POL23 = {};

            /// Counter/Timer B3 Invert on trigger.
            static constexpr bitfield_t<AUX3_t, 28, 28, bool> TMRB3TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX3_t, 27, 27, bool> TMRB3NOSYNC = {};

            /// Counter/Timer B3 Trigger Select.
            static constexpr bitfield_t<AUX3_t, 26, 23, CTIMER::TMRB3TRIGv> TMRB3TRIG = {};

            /// Counter/Timer B3 Pattern Limit Count.
            static constexpr bitfield_t<AUX3_t, 21, 16> TMRB3LMT = {};

            /// Counter/Timer A3 Upper compare enable.
            static constexpr bitfield_t<AUX3_t, 14, 14, bool> TMRA3EN23 = {};

            /// Counter/Timer A3 Upper output polarity
            static constexpr bitfield_t<AUX3_t, 13, 13, bool> TMRA3POL23 = {};

            /// Counter/Timer A3 Invert on trigger.
            static constexpr bitfield_t<AUX3_t, 12, 12, bool> TMRA3TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX3_t, 11, 11, bool> TMRA3NOSYNC = {};

            /// Counter/Timer A3 Trigger Select.
            static constexpr bitfield_t<AUX3_t, 10, 7, CTIMER::TMRA3TRIGv> TMRA3TRIG = {};

            /// Counter/Timer A3 Pattern Limit Count.
            static constexpr bitfield_t<AUX3_t, 6, 0> TMRA3LMT = {};
        } AUX3 = {};

        /**
         * TMR4 - 4 bytes at offset 128
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR4_t : reg_t<uint32_t, BASE_ADDRESS + 0x80> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x80>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B4.
            static constexpr bitfield_t<TMR4_t, 31, 16> CTTMRB4 = {};

            /// Counter/Timer A4.
            static constexpr bitfield_t<TMR4_t, 15, 0> CTTMRA4 = {};
        } TMR4 = {};

        /**
         * CMPRA4 - 4 bytes at offset 132
         * Counter/Timer A4 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA4_t : reg_t<uint32_t, BASE_ADDRESS + 0x84> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x84>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A4 Compare Register 1. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRA4_t, 31, 16> CMPR1A4 = {};

            /// Counter/Timer A4 Compare Register 0. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRA4_t, 15, 0> CMPR0A4 = {};
        } CMPRA4 = {};

        /**
         * CMPRB4 - 4 bytes at offset 136
         * Counter/Timer B4 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB4_t : reg_t<uint32_t, BASE_ADDRESS + 0x88> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x88>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B4 Compare Register 1. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRB4_t, 31, 16> CMPR1B4 = {};

            /// Counter/Timer B4 Compare Register 0. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRB4_t, 15, 0> CMPR0B4 = {};
        } CMPRB4 = {};

        /**
         * CTRL4 - 4 bytes at offset 140
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL4_t : reg_t<uint32_t, BASE_ADDRESS + 0x8C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8C>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A4/B4 Link bit.
            static constexpr bitfield_t<CTRL4_t, 31, 31, bool> CTLINK4 = {};

            /// Counter/Timer B4 output polarity.
            static constexpr bitfield_t<CTRL4_t, 28, 28, bool> TMRB4POL = {};

            /// Counter/Timer B4 Clear bit.
            static constexpr bitfield_t<CTRL4_t, 27, 27, bool> TMRB4CLR = {};

            /// Counter/Timer B4 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL4_t, 26, 26, bool> TMRB4IE1 = {};

            /// Counter/Timer B4 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL4_t, 25, 25, bool> TMRB4IE0 = {};

            /// Counter/Timer B4 Function Select.
            static constexpr bitfield_t<CTRL4_t, 24, 22, CTIMER::TMRB4FNv> TMRB4FN = {};

            /// Counter/Timer B4 Clock Select.
            static constexpr bitfield_t<CTRL4_t, 21, 17, CTIMER::TMRB4CLKv> TMRB4CLK = {};

            /// Counter/Timer B4 Enable bit.
            static constexpr bitfield_t<CTRL4_t, 16, 16, bool> TMRB4EN = {};

            /// Counter/Timer A4 output polarity.
            static constexpr bitfield_t<CTRL4_t, 12, 12, bool> TMRA4POL = {};

            /// Counter/Timer A4 Clear bit.
            static constexpr bitfield_t<CTRL4_t, 11, 11, bool> TMRA4CLR = {};

            /// Counter/Timer A4 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL4_t, 10, 10, bool> TMRA4IE1 = {};

            /// Counter/Timer A4 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL4_t, 9, 9, bool> TMRA4IE0 = {};

            /// Counter/Timer A4 Function Select.
            static constexpr bitfield_t<CTRL4_t, 8, 6, CTIMER::TMRA4FNv> TMRA4FN = {};

            /// Counter/Timer A4 Clock Select.
            static constexpr bitfield_t<CTRL4_t, 5, 1, CTIMER::TMRA4CLKv> TMRA4CLK = {};

            /// Counter/Timer A4 Enable bit.
            static constexpr bitfield_t<CTRL4_t, 0, 0, bool> TMRA4EN = {};
        } CTRL4 = {};

        /**
         * CMPRAUXA4 - 4 bytes at offset 148
         * Counter/Timer A4 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA4_t : reg_t<uint32_t, BASE_ADDRESS + 0x94> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x94>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A4 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA4_t, 31, 16> CMPR3A4 = {};

            /// Counter/Timer A4 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA4_t, 15, 0> CMPR2A4 = {};
        } CMPRAUXA4 = {};

        /**
         * CMPRAUXB4 - 4 bytes at offset 152
         * Counter/Timer B4 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB4_t : reg_t<uint32_t, BASE_ADDRESS + 0x98> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x98>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B4 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB4_t, 31, 16> CMPR3B4 = {};

            /// Counter/Timer B4 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB4_t, 15, 0> CMPR2B4 = {};
        } CMPRAUXB4 = {};

        /**
         * AUX4 - 4 bytes at offset 156
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX4_t : reg_t<uint32_t, BASE_ADDRESS + 0x9C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x9C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B4 Upper compare enable.
            static constexpr bitfield_t<AUX4_t, 30, 30, bool> TMRB4EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX4_t, 29, 29, bool> TMRB4POL23 = {};

            /// Counter/Timer B4 Invert on trigger.
            static constexpr bitfield_t<AUX4_t, 28, 28, bool> TMRB4TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX4_t, 27, 27, bool> TMRB4NOSYNC = {};

            /// Counter/Timer B4 Trigger Select.
            static constexpr bitfield_t<AUX4_t, 26, 23, CTIMER::TMRB4TRIGv> TMRB4TRIG = {};

            /// Counter/Timer B4 Pattern Limit Count.
            static constexpr bitfield_t<AUX4_t, 21, 16> TMRB4LMT = {};

            /// Counter/Timer A4 Upper compare enable.
            static constexpr bitfield_t<AUX4_t, 14, 14, bool> TMRA4EN23 = {};

            /// Counter/Timer A4 Upper output polarity
            static constexpr bitfield_t<AUX4_t, 13, 13, bool> TMRA4POL23 = {};

            /// Counter/Timer A4 Invert on trigger.
            static constexpr bitfield_t<AUX4_t, 12, 12, bool> TMRA4TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX4_t, 11, 11, bool> TMRA4NOSYNC = {};

            /// Counter/Timer A4 Trigger Select.
            static constexpr bitfield_t<AUX4_t, 10, 7, CTIMER::TMRA4TRIGv> TMRA4TRIG = {};

            /// Counter/Timer A4 Pattern Limit Count.
            static constexpr bitfield_t<AUX4_t, 6, 0> TMRA4LMT = {};
        } AUX4 = {};

        /**
         * TMR5 - 4 bytes at offset 160
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR5_t : reg_t<uint32_t, BASE_ADDRESS + 0xA0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xA0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B5.
            static constexpr bitfield_t<TMR5_t, 31, 16> CTTMRB5 = {};

            /// Counter/Timer A5.
            static constexpr bitfield_t<TMR5_t, 15, 0> CTTMRA5 = {};
        } TMR5 = {};

        /**
         * CMPRA5 - 4 bytes at offset 164
         * Counter/Timer A5 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA5_t : reg_t<uint32_t, BASE_ADDRESS + 0xA4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xA4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A5 Compare Register 1.
            static constexpr bitfield_t<CMPRA5_t, 31, 16> CMPR1A5 = {};

            /// Counter/Timer A5 Compare Register 0.
            static constexpr bitfield_t<CMPRA5_t, 15, 0> CMPR0A5 = {};
        } CMPRA5 = {};

        /**
         * CMPRB5 - 4 bytes at offset 168
         * Counter/Timer B5 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB5_t : reg_t<uint32_t, BASE_ADDRESS + 0xA8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xA8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B5 Compare Register 1.
            static constexpr bitfield_t<CMPRB5_t, 31, 16> CMPR1B5 = {};

            /// Counter/Timer B5 Compare Register 0.
            static constexpr bitfield_t<CMPRB5_t, 15, 0> CMPR0B5 = {};
        } CMPRB5 = {};

        /**
         * CTRL5 - 4 bytes at offset 172
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL5_t : reg_t<uint32_t, BASE_ADDRESS + 0xAC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xAC>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A5/B5 Link bit.
            static constexpr bitfield_t<CTRL5_t, 31, 31, bool> CTLINK5 = {};

            /// Counter/Timer B5 output polarity.
            static constexpr bitfield_t<CTRL5_t, 28, 28, bool> TMRB5POL = {};

            /// Counter/Timer B5 Clear bit.
            static constexpr bitfield_t<CTRL5_t, 27, 27, bool> TMRB5CLR = {};

            /// Counter/Timer B5 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL5_t, 26, 26, bool> TMRB5IE1 = {};

            /// Counter/Timer B5 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL5_t, 25, 25, bool> TMRB5IE0 = {};

            /// Counter/Timer B5 Function Select.
            static constexpr bitfield_t<CTRL5_t, 24, 22, CTIMER::TMRB5FNv> TMRB5FN = {};

            /// Counter/Timer B5 Clock Select.
            static constexpr bitfield_t<CTRL5_t, 21, 17, CTIMER::TMRB5CLKv> TMRB5CLK = {};

            /// Counter/Timer B5 Enable bit.
            static constexpr bitfield_t<CTRL5_t, 16, 16, bool> TMRB5EN = {};

            /// Counter/Timer A5 output polarity.
            static constexpr bitfield_t<CTRL5_t, 12, 12, bool> TMRA5POL = {};

            /// Counter/Timer A5 Clear bit.
            static constexpr bitfield_t<CTRL5_t, 11, 11, bool> TMRA5CLR = {};

            /// Counter/Timer A5 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL5_t, 10, 10, bool> TMRA5IE1 = {};

            /// Counter/Timer A5 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL5_t, 9, 9, bool> TMRA5IE0 = {};

            /// Counter/Timer A5 Function Select.
            static constexpr bitfield_t<CTRL5_t, 8, 6, CTIMER::TMRA5FNv> TMRA5FN = {};

            /// Counter/Timer A5 Clock Select.
            static constexpr bitfield_t<CTRL5_t, 5, 1, CTIMER::TMRA5CLKv> TMRA5CLK = {};

            /// Counter/Timer A5 Enable bit.
            static constexpr bitfield_t<CTRL5_t, 0, 0, bool> TMRA5EN = {};
        } CTRL5 = {};

        /**
         * CMPRAUXA5 - 4 bytes at offset 180
         * Counter/Timer A5 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA5_t : reg_t<uint32_t, BASE_ADDRESS + 0xB4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xB4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A5 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA5_t, 31, 16> CMPR3A5 = {};

            /// Counter/Timer A5 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA5_t, 15, 0> CMPR2A5 = {};
        } CMPRAUXA5 = {};

        /**
         * CMPRAUXB5 - 4 bytes at offset 184
         * Counter/Timer B5 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB5_t : reg_t<uint32_t, BASE_ADDRESS + 0xB8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xB8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B5 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB5_t, 31, 16> CMPR3B5 = {};

            /// Counter/Timer B5 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB5_t, 15, 0> CMPR2B5 = {};
        } CMPRAUXB5 = {};

        /**
         * AUX5 - 4 bytes at offset 188
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX5_t : reg_t<uint32_t, BASE_ADDRESS + 0xBC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xBC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B5 Upper compare enable.
            static constexpr bitfield_t<AUX5_t, 30, 30, bool> TMRB5EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX5_t, 29, 29, bool> TMRB5POL23 = {};

            /// Counter/Timer B5 Invert on trigger.
            static constexpr bitfield_t<AUX5_t, 28, 28, bool> TMRB5TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX5_t, 27, 27, bool> TMRB5NOSYNC = {};

            /// Counter/Timer B5 Trigger Select.
            static constexpr bitfield_t<AUX5_t, 26, 23, CTIMER::TMRB5TRIGv> TMRB5TRIG = {};

            /// Counter/Timer B5 Pattern Limit Count.
            static constexpr bitfield_t<AUX5_t, 21, 16> TMRB5LMT = {};

            /// Counter/Timer A5 Upper compare enable.
            static constexpr bitfield_t<AUX5_t, 14, 14, bool> TMRA5EN23 = {};

            /// Counter/Timer A5 Upper output polarity
            static constexpr bitfield_t<AUX5_t, 13, 13, bool> TMRA5POL23 = {};

            /// Counter/Timer A5 Invert on trigger.
            static constexpr bitfield_t<AUX5_t, 12, 12, bool> TMRA5TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX5_t, 11, 11, bool> TMRA5NOSYNC = {};

            /// Counter/Timer A5 Trigger Select.
            static constexpr bitfield_t<AUX5_t, 10, 7, CTIMER::TMRA5TRIGv> TMRA5TRIG = {};

            /// Counter/Timer A5 Pattern Limit Count.
            static constexpr bitfield_t<AUX5_t, 6, 0> TMRA5LMT = {};
        } AUX5 = {};

        /**
         * TMR6 - 4 bytes at offset 192
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR6_t : reg_t<uint32_t, BASE_ADDRESS + 0xC0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B6.
            static constexpr bitfield_t<TMR6_t, 31, 16> CTTMRB6 = {};

            /// Counter/Timer A6.
            static constexpr bitfield_t<TMR6_t, 15, 0> CTTMRA6 = {};
        } TMR6 = {};

        /**
         * CMPRA6 - 4 bytes at offset 196
         * Counter/Timer A6 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA6_t : reg_t<uint32_t, BASE_ADDRESS + 0xC4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A6 Compare Register 1.
            static constexpr bitfield_t<CMPRA6_t, 31, 16> CMPR1A6 = {};

            /// Counter/Timer A6 Compare Register 0.
            static constexpr bitfield_t<CMPRA6_t, 15, 0> CMPR0A6 = {};
        } CMPRA6 = {};

        /**
         * CMPRB6 - 4 bytes at offset 200
         * Counter/Timer B6 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB6_t : reg_t<uint32_t, BASE_ADDRESS + 0xC8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B6 Compare Register 1.
            static constexpr bitfield_t<CMPRB6_t, 31, 16> CMPR1B6 = {};

            /// Counter/Timer B6 Compare Register 0.
            static constexpr bitfield_t<CMPRB6_t, 15, 0> CMPR0B6 = {};
        } CMPRB6 = {};

        /**
         * CTRL6 - 4 bytes at offset 204
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL6_t : reg_t<uint32_t, BASE_ADDRESS + 0xCC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xCC>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A6/B6 Link bit.
            static constexpr bitfield_t<CTRL6_t, 31, 31, bool> CTLINK6 = {};

            /// Counter/Timer B6 output polarity.
            static constexpr bitfield_t<CTRL6_t, 28, 28, bool> TMRB6POL = {};

            /// Counter/Timer B6 Clear bit.
            static constexpr bitfield_t<CTRL6_t, 27, 27, bool> TMRB6CLR = {};

            /// Counter/Timer B6 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL6_t, 26, 26, bool> TMRB6IE1 = {};

            /// Counter/Timer B6 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL6_t, 25, 25, bool> TMRB6IE0 = {};

            /// Counter/Timer B6 Function Select.
            static constexpr bitfield_t<CTRL6_t, 24, 22, CTIMER::TMRB6FNv> TMRB6FN = {};

            /// Counter/Timer B6 Clock Select.
            static constexpr bitfield_t<CTRL6_t, 21, 17, CTIMER::TMRB6CLKv> TMRB6CLK = {};

            /// Counter/Timer B6 Enable bit.
            static constexpr bitfield_t<CTRL6_t, 16, 16, bool> TMRB6EN = {};

            /// Counter/Timer A6 output polarity.
            static constexpr bitfield_t<CTRL6_t, 12, 12, bool> TMRA6POL = {};

            /// Counter/Timer A6 Clear bit.
            static constexpr bitfield_t<CTRL6_t, 11, 11, bool> TMRA6CLR = {};

            /// Counter/Timer A6 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL6_t, 10, 10, bool> TMRA6IE1 = {};

            /// Counter/Timer A6 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL6_t, 9, 9, bool> TMRA6IE0 = {};

            /// Counter/Timer A6 Function Select.
            static constexpr bitfield_t<CTRL6_t, 8, 6, CTIMER::TMRA6FNv> TMRA6FN = {};

            /// Counter/Timer A6 Clock Select.
            static constexpr bitfield_t<CTRL6_t, 5, 1, CTIMER::TMRA6CLKv> TMRA6CLK = {};

            /// Counter/Timer A6 Enable bit.
            static constexpr bitfield_t<CTRL6_t, 0, 0, bool> TMRA6EN = {};
        } CTRL6 = {};

        /**
         * CMPRAUXA6 - 4 bytes at offset 212
         * Counter/Timer A6 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA6_t : reg_t<uint32_t, BASE_ADDRESS + 0xD4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xD4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A6 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA6_t, 31, 16> CMPR3A6 = {};

            /// Counter/Timer A6 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA6_t, 15, 0> CMPR2A6 = {};
        } CMPRAUXA6 = {};

        /**
         * CMPRAUXB6 - 4 bytes at offset 216
         * Counter/Timer B6 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB6_t : reg_t<uint32_t, BASE_ADDRESS + 0xD8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xD8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B6 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB6_t, 31, 16> CMPR3B6 = {};

            /// Counter/Timer B6 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB6_t, 15, 0> CMPR2B6 = {};
        } CMPRAUXB6 = {};

        /**
         * AUX6 - 4 bytes at offset 220
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX6_t : reg_t<uint32_t, BASE_ADDRESS + 0xDC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xDC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B6 Upper compare enable.
            static constexpr bitfield_t<AUX6_t, 30, 30, bool> TMRB6EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX6_t, 29, 29, bool> TMRB6POL23 = {};

            /// Counter/Timer B6 Invert on trigger.
            static constexpr bitfield_t<AUX6_t, 28, 28, bool> TMRB6TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX6_t, 27, 27, bool> TMRB6NOSYNC = {};

            /// Counter/Timer B6 Trigger Select.
            static constexpr bitfield_t<AUX6_t, 26, 23, CTIMER::TMRB6TRIGv> TMRB6TRIG = {};

            /// Counter/Timer B6 Pattern Limit Count.
            static constexpr bitfield_t<AUX6_t, 21, 16> TMRB6LMT = {};

            /// Counter/Timer A6 Upper compare enable.
            static constexpr bitfield_t<AUX6_t, 14, 14, bool> TMRA6EN23 = {};

            /// Counter/Timer A6 Upper output polarity
            static constexpr bitfield_t<AUX6_t, 13, 13, bool> TMRA6POL23 = {};

            /// Counter/Timer A6 Invert on trigger.
            static constexpr bitfield_t<AUX6_t, 12, 12, bool> TMRA6TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX6_t, 11, 11, bool> TMRA6NOSYNC = {};

            /// Counter/Timer A6 Trigger Select.
            static constexpr bitfield_t<AUX6_t, 10, 7, CTIMER::TMRA6TRIGv> TMRA6TRIG = {};

            /// Counter/Timer A6 Pattern Limit Count.
            static constexpr bitfield_t<AUX6_t, 6, 0> TMRA6LMT = {};
        } AUX6 = {};

        /**
         * TMR7 - 4 bytes at offset 224
         * Counter/Timer Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TMR7_t : reg_t<uint32_t, BASE_ADDRESS + 0xE0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xE0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7.
            static constexpr bitfield_t<TMR7_t, 31, 16> CTTMRB7 = {};

            /// Counter/Timer A7.
            static constexpr bitfield_t<TMR7_t, 15, 0> CTTMRA7 = {};
        } TMR7 = {};

        /**
         * CMPRA7 - 4 bytes at offset 228
         * Counter/Timer A7 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRA7_t : reg_t<uint32_t, BASE_ADDRESS + 0xE4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xE4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A7 Compare Register 1.
            static constexpr bitfield_t<CMPRA7_t, 31, 16> CMPR1A7 = {};

            /// Counter/Timer A7 Compare Register 0.
            static constexpr bitfield_t<CMPRA7_t, 15, 0> CMPR0A7 = {};
        } CMPRA7 = {};

        /**
         * CMPRB7 - 4 bytes at offset 232
         * Counter/Timer B7 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRB7_t : reg_t<uint32_t, BASE_ADDRESS + 0xE8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xE8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B3 Compare Register 1.
            static constexpr bitfield_t<CMPRB7_t, 31, 16> CMPR1B7 = {};

            /// Counter/Timer B3 Compare Register 0.
            static constexpr bitfield_t<CMPRB7_t, 15, 0> CMPR0B7 = {};
        } CMPRB7 = {};

        /**
         * CTRL7 - 4 bytes at offset 236
         * Counter/Timer Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL7_t : reg_t<uint32_t, BASE_ADDRESS + 0xEC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xEC>::operator=;
            static constexpr uint32_t reset_mask  = 0x9FFF1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A7/B7 Link bit.
            static constexpr bitfield_t<CTRL7_t, 31, 31, bool> CTLINK7 = {};

            /// Counter/Timer B7 output polarity.
            static constexpr bitfield_t<CTRL7_t, 28, 28, bool> TMRB7POL = {};

            /// Counter/Timer B7 Clear bit.
            static constexpr bitfield_t<CTRL7_t, 27, 27, bool> TMRB7CLR = {};

            /// Counter/Timer B7 Interrupt Enable bit for COMPR1.
            static constexpr bitfield_t<CTRL7_t, 26, 26, bool> TMRB7IE1 = {};

            /// Counter/Timer B7 Interrupt Enable bit for COMPR0.
            static constexpr bitfield_t<CTRL7_t, 25, 25, bool> TMRB7IE0 = {};

            /// Counter/Timer B7 Function Select.
            static constexpr bitfield_t<CTRL7_t, 24, 22, CTIMER::TMRB7FNv> TMRB7FN = {};

            /// Counter/Timer B7 Clock Select.
            static constexpr bitfield_t<CTRL7_t, 21, 17, CTIMER::TMRB7CLKv> TMRB7CLK = {};

            /// Counter/Timer B7 Enable bit.
            static constexpr bitfield_t<CTRL7_t, 16, 16, bool> TMRB7EN = {};

            /// Counter/Timer A7 output polarity.
            static constexpr bitfield_t<CTRL7_t, 12, 12, bool> TMRA7POL = {};

            /// Counter/Timer A7 Clear bit.
            static constexpr bitfield_t<CTRL7_t, 11, 11, bool> TMRA7CLR = {};

            /// Counter/Timer A7 Interrupt Enable bit based on COMPR1.
            static constexpr bitfield_t<CTRL7_t, 10, 10, bool> TMRA7IE1 = {};

            /// Counter/Timer A7 Interrupt Enable bit based on COMPR0.
            static constexpr bitfield_t<CTRL7_t, 9, 9, bool> TMRA7IE0 = {};

            /// Counter/Timer A7 Function Select.
            static constexpr bitfield_t<CTRL7_t, 8, 6, CTIMER::TMRA7FNv> TMRA7FN = {};

            /// Counter/Timer A7 Clock Select.
            static constexpr bitfield_t<CTRL7_t, 5, 1, CTIMER::TMRA7CLKv> TMRA7CLK = {};

            /// Counter/Timer A7 Enable bit.
            static constexpr bitfield_t<CTRL7_t, 0, 0, bool> TMRA7EN = {};
        } CTRL7 = {};

        /**
         * CMPRAUXA7 - 4 bytes at offset 244
         * Counter/Timer A7 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXA7_t : reg_t<uint32_t, BASE_ADDRESS + 0xF4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xF4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer A7 Compare Register 3. Holds the upper limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA7_t, 31, 16> CMPR3A7 = {};

            /// Counter/Timer A7 Compare Register 2. Holds the lower limit for timer half A.
            static constexpr bitfield_t<CMPRAUXA7_t, 15, 0> CMPR2A7 = {};
        } CMPRAUXA7 = {};

        /**
         * CMPRAUXB7 - 4 bytes at offset 248
         * Counter/Timer B7 Compare Registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMPRAUXB7_t : reg_t<uint32_t, BASE_ADDRESS + 0xF8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xF8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7 Compare Register 3. Holds the upper limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB7_t, 31, 16> CMPR3B7 = {};

            /// Counter/Timer B7 Compare Register 2. Holds the lower limit for timer half B.
            static constexpr bitfield_t<CMPRAUXB7_t, 15, 0> CMPR2B7 = {};
        } CMPRAUXB7 = {};

        /**
         * AUX7 - 4 bytes at offset 252
         * Counter/Timer Auxiliary
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct AUX7_t : reg_t<uint32_t, BASE_ADDRESS + 0xFC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xFC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FBF7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7 Upper compare enable.
            static constexpr bitfield_t<AUX7_t, 30, 30, bool> TMRB7EN23 = {};

            /// Upper output polarity
            static constexpr bitfield_t<AUX7_t, 29, 29, bool> TMRB7POL23 = {};

            /// Counter/Timer B7 Invert on trigger.
            static constexpr bitfield_t<AUX7_t, 28, 28, bool> TMRB7TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX7_t, 27, 27, bool> TMRB7NOSYNC = {};

            /// Counter/Timer B7 Trigger Select.
            static constexpr bitfield_t<AUX7_t, 26, 23, CTIMER::TMRB7TRIGv> TMRB7TRIG = {};

            /// Counter/Timer B7 Pattern Limit Count.
            static constexpr bitfield_t<AUX7_t, 21, 16> TMRB7LMT = {};

            /// Counter/Timer A7 Upper compare enable.
            static constexpr bitfield_t<AUX7_t, 14, 14, bool> TMRA7EN23 = {};

            /// Counter/Timer A7 Upper output polarity
            static constexpr bitfield_t<AUX7_t, 13, 13, bool> TMRA7POL23 = {};

            /// Counter/Timer A7 Invert on trigger.
            static constexpr bitfield_t<AUX7_t, 12, 12, bool> TMRA7TINV = {};

            /// Source clock synchronization control.
            static constexpr bitfield_t<AUX7_t, 11, 11, bool> TMRA7NOSYNC = {};

            /// Counter/Timer A7 Trigger Select.
            static constexpr bitfield_t<AUX7_t, 10, 7, CTIMER::TMRA7TRIGv> TMRA7TRIG = {};

            /// Counter/Timer A7 Pattern Limit Count.
            static constexpr bitfield_t<AUX7_t, 6, 0> TMRA7LMT = {};
        } AUX7 = {};

        /**
         * GLOBEN - 4 bytes at offset 256
         * Counter/Timer Global Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct GLOBEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0xFFFF;

            /// Alternate enable for B7.
            static constexpr bitfield_t<GLOBEN_t, 15, 15, bool> ENB7 = {};

            /// Alternate enable for A7
            static constexpr bitfield_t<GLOBEN_t, 14, 14, bool> ENA7 = {};

            /// Alternate enable for B6
            static constexpr bitfield_t<GLOBEN_t, 13, 13, bool> ENB6 = {};

            /// Alternate enable for A6
            static constexpr bitfield_t<GLOBEN_t, 12, 12, bool> ENA6 = {};

            /// Alternate enable for B5
            static constexpr bitfield_t<GLOBEN_t, 11, 11, bool> ENB5 = {};

            /// Alternate enable for A5
            static constexpr bitfield_t<GLOBEN_t, 10, 10, bool> ENA5 = {};

            /// Alternate enable for B4
            static constexpr bitfield_t<GLOBEN_t, 9, 9, bool> ENB4 = {};

            /// Alternate enable for A4
            static constexpr bitfield_t<GLOBEN_t, 8, 8, bool> ENA4 = {};

            /// Alternate enable for B3.
            static constexpr bitfield_t<GLOBEN_t, 7, 7, bool> ENB3 = {};

            /// Alternate enable for A3
            static constexpr bitfield_t<GLOBEN_t, 6, 6, bool> ENA3 = {};

            /// Alternate enable for B2
            static constexpr bitfield_t<GLOBEN_t, 5, 5, bool> ENB2 = {};

            /// Alternate enable for A2
            static constexpr bitfield_t<GLOBEN_t, 4, 4, bool> ENA2 = {};

            /// Alternate enable for B1
            static constexpr bitfield_t<GLOBEN_t, 3, 3, bool> ENB1 = {};

            /// Alternate enable for A1
            static constexpr bitfield_t<GLOBEN_t, 2, 2, bool> ENA1 = {};

            /// Alternate enable for B0
            static constexpr bitfield_t<GLOBEN_t, 1, 1, bool> ENB0 = {};

            /// Alternate enable for A0
            static constexpr bitfield_t<GLOBEN_t, 0, 0, bool> ENA0 = {};
        } GLOBEN = {};

        /**
         * OUTCFG0 - 4 bytes at offset 260
         * Counter/Timer Output Config 0
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OUTCFG0_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFF7FFF;
            static constexpr uint32_t reset_value = 0x24922292;

            /// Pad output 9 configuration
            static constexpr bitfield_t<OUTCFG0_t, 30, 28, CTIMER::CFG9v> CFG9 = {};

            /// Pad output 8 configuration
            static constexpr bitfield_t<OUTCFG0_t, 27, 25, CTIMER::CFG8v> CFG8 = {};

            /// Pad output 7 configuration
            static constexpr bitfield_t<OUTCFG0_t, 24, 22, CTIMER::CFG7v> CFG7 = {};

            /// Pad output 6 configuration
            static constexpr bitfield_t<OUTCFG0_t, 21, 19, CTIMER::CFG6v> CFG6 = {};

            /// Pad output 5 configuration
            static constexpr bitfield_t<OUTCFG0_t, 18, 16, CTIMER::CFG5v> CFG5 = {};

            /// Pad output 4 configuration
            static constexpr bitfield_t<OUTCFG0_t, 14, 12, CTIMER::CFG4v> CFG4 = {};

            /// Pad output 3 configuration
            static constexpr bitfield_t<OUTCFG0_t, 11, 9, CTIMER::CFG3v> CFG3 = {};

            /// Pad output 2 configuration
            static constexpr bitfield_t<OUTCFG0_t, 8, 6, CTIMER::CFG2v> CFG2 = {};

            /// Pad output 1 configuration
            static constexpr bitfield_t<OUTCFG0_t, 5, 3, CTIMER::CFG1v> CFG1 = {};

            /// Pad output 0 configuration
            static constexpr bitfield_t<OUTCFG0_t, 2, 0, CTIMER::CFG0v> CFG0 = {};
        } OUTCFG0 = {};

        /**
         * OUTCFG1 - 4 bytes at offset 264
         * Counter/Timer Output Config 1
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OUTCFG1_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFF7FFF;
            static constexpr uint32_t reset_value = 0x24922292;

            /// Pad output 19 configuration
            static constexpr bitfield_t<OUTCFG1_t, 30, 28, CTIMER::CFG19v> CFG19 = {};

            /// Pad output 18 configuration
            static constexpr bitfield_t<OUTCFG1_t, 27, 25, CTIMER::CFG18v> CFG18 = {};

            /// Pad output 17 configuration
            static constexpr bitfield_t<OUTCFG1_t, 24, 22, CTIMER::CFG17v> CFG17 = {};

            /// Pad output 16 configuration
            static constexpr bitfield_t<OUTCFG1_t, 21, 19, CTIMER::CFG16v> CFG16 = {};

            /// Pad output 15 configuration
            static constexpr bitfield_t<OUTCFG1_t, 18, 16, CTIMER::CFG15v> CFG15 = {};

            /// Pad output 14 configuration
            static constexpr bitfield_t<OUTCFG1_t, 14, 12, CTIMER::CFG14v> CFG14 = {};

            /// Pad output 13 configuration
            static constexpr bitfield_t<OUTCFG1_t, 11, 9, CTIMER::CFG13v> CFG13 = {};

            /// Pad output 12 configuration
            static constexpr bitfield_t<OUTCFG1_t, 8, 6, CTIMER::CFG12v> CFG12 = {};

            /// Pad output 11 configuration
            static constexpr bitfield_t<OUTCFG1_t, 5, 3, CTIMER::CFG11v> CFG11 = {};

            /// Pad output 10 configuration
            static constexpr bitfield_t<OUTCFG1_t, 2, 0, CTIMER::CFG10v> CFG10 = {};
        } OUTCFG1 = {};

        /**
         * OUTCFG2 - 4 bytes at offset 268
         * Counter/Timer Output Config 2
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OUTCFG2_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFF7FFF;
            static constexpr uint32_t reset_value = 0x24922292;

            /// Pad output 29 configuration
            static constexpr bitfield_t<OUTCFG2_t, 30, 28, CTIMER::CFG29v> CFG29 = {};

            /// Pad output 28 configuration
            static constexpr bitfield_t<OUTCFG2_t, 27, 25, CTIMER::CFG28v> CFG28 = {};

            /// Pad output 27 configuration
            static constexpr bitfield_t<OUTCFG2_t, 24, 22, CTIMER::CFG27v> CFG27 = {};

            /// Pad output 26 configuration
            static constexpr bitfield_t<OUTCFG2_t, 21, 19, CTIMER::CFG26v> CFG26 = {};

            /// Pad output 25 configuration
            static constexpr bitfield_t<OUTCFG2_t, 18, 16, CTIMER::CFG25v> CFG25 = {};

            /// Pad output 24 configuration
            static constexpr bitfield_t<OUTCFG2_t, 14, 12, CTIMER::CFG24v> CFG24 = {};

            /// Pad output 23 configuration
            static constexpr bitfield_t<OUTCFG2_t, 11, 9, CTIMER::CFG23v> CFG23 = {};

            /// Pad output 22 configuration
            static constexpr bitfield_t<OUTCFG2_t, 8, 6, CTIMER::CFG22v> CFG22 = {};

            /// Pad output 21 configuration
            static constexpr bitfield_t<OUTCFG2_t, 5, 3, CTIMER::CFG21v> CFG21 = {};

            /// Pad output 20 configuration
            static constexpr bitfield_t<OUTCFG2_t, 2, 0, CTIMER::CFG20v> CFG20 = {};
        } OUTCFG2 = {};

        /**
         * OUTCFG3 - 4 bytes at offset 276
         * Counter/Timer Output Config 3
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OUTCFG3_t : reg_t<uint32_t, BASE_ADDRESS + 0x114> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x114>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x12;

            /// Pad output 31 configuration
            static constexpr bitfield_t<OUTCFG3_t, 5, 3, CTIMER::CFG31v> CFG31 = {};

            /// Pad output 30 configuration
            static constexpr bitfield_t<OUTCFG3_t, 2, 0, CTIMER::CFG30v> CFG30 = {};
        } OUTCFG3 = {};

        /**
         * INCFG - 4 bytes at offset 280
         * Counter/Timer Input Config
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x118> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x118>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CTIMER B7 input configuration
            static constexpr bitfield_t<INCFG_t, 15, 15, bool> CFGB7 = {};

            /// CTIMER A7 input configuration
            static constexpr bitfield_t<INCFG_t, 14, 14, bool> CFGA7 = {};

            /// CTIMER B6 input configuration
            static constexpr bitfield_t<INCFG_t, 13, 13, bool> CFGB6 = {};

            /// CTIMER A6 input configuration
            static constexpr bitfield_t<INCFG_t, 12, 12, bool> CFGA6 = {};

            /// CTIMER B5 input configuration
            static constexpr bitfield_t<INCFG_t, 11, 11, bool> CFGB5 = {};

            /// CTIMER A5 input configuration
            static constexpr bitfield_t<INCFG_t, 10, 10, bool> CFGA5 = {};

            /// CTIMER B4 input configuration
            static constexpr bitfield_t<INCFG_t, 9, 9, bool> CFGB4 = {};

            /// CTIMER A4 input configuration
            static constexpr bitfield_t<INCFG_t, 8, 8, bool> CFGA4 = {};

            /// CTIMER B3 input configuration
            static constexpr bitfield_t<INCFG_t, 7, 7, bool> CFGB3 = {};

            /// CTIMER A3 input configuration
            static constexpr bitfield_t<INCFG_t, 6, 6, bool> CFGA3 = {};

            /// CTIMER B2 input configuration
            static constexpr bitfield_t<INCFG_t, 5, 5, bool> CFGB2 = {};

            /// CTIMER A2 input configuration
            static constexpr bitfield_t<INCFG_t, 4, 4, bool> CFGA2 = {};

            /// CTIMER B1 input configuration
            static constexpr bitfield_t<INCFG_t, 3, 3, bool> CFGB1 = {};

            /// CTIMER A1 input configuration
            static constexpr bitfield_t<INCFG_t, 2, 2, bool> CFGA1 = {};

            /// CTIMER B0 input configuration
            static constexpr bitfield_t<INCFG_t, 1, 1, bool> CFGB0 = {};

            /// CTIMER A0 input configuration
            static constexpr bitfield_t<INCFG_t, 0, 0, bool> CFGA0 = {};
        } INCFG = {};

        /**
         * STCFG - 4 bytes at offset 320
         * Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x140> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x140>::operator=;
            static constexpr uint32_t reset_mask  = 0xC000FF0F;
            static constexpr uint32_t reset_value = 0x80000000;

            /// Set this bit to one to freeze the clock input to the COUNTER register. Once frozen, the value can be safely written from the MCU.  Unfreeze to resume.
            static constexpr bitfield_t<STCFG_t, 31, 31, bool> FREEZE = {};

            /// Set this bit to one to clear the System Timer register.  If this bit is set to '1', the system timer register will stay cleared.  It needs to be set to '0' for the system timer to start running.
            static constexpr bitfield_t<STCFG_t, 30, 30, bool> CLEAR = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 15, 15, bool> COMPARE_H_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 14, 14, bool> COMPARE_G_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 13, 13, bool> COMPARE_F_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 12, 12, bool> COMPARE_E_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 11, 11, bool> COMPARE_D_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 10, 10, bool> COMPARE_C_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 9, 9, bool> COMPARE_B_EN = {};

            /// Selects whether compare is enabled for the corresponding SCMPR register. If compare is enabled, the interrupt status is set once the comparision is met.
            static constexpr bitfield_t<STCFG_t, 8, 8, bool> COMPARE_A_EN = {};

            /// Selects an appropriate clock source and divider to use for the System Timer clock.
            static constexpr bitfield_t<STCFG_t, 3, 0, CTIMER::CLKSELv> CLKSEL = {};
        } STCFG = {};

        /**
         * STTMR - 4 bytes at offset 324
         * System Timer Count Register (Real Time Counter)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STTMR_t : reg_t<uint32_t, BASE_ADDRESS + 0x144> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x144>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Value of the 32-bit counter as it ticks over.
            static constexpr bitfield_t<STTMR_t, 31, 0> STTMR = {};
        } STTMR = {};

        /**
         * CAPTURECONTROL - 4 bytes at offset 328
         * Capture Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CAPTURECONTROL_t : reg_t<uint32_t, BASE_ADDRESS + 0x148> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x148>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// Selects whether capture is enabled for the specified capture register.
            static constexpr bitfield_t<CAPTURECONTROL_t, 3, 3, bool> CAPTURE3 = {};

            /// Selects whether capture is enabled for the specified capture register.
            static constexpr bitfield_t<CAPTURECONTROL_t, 2, 2, bool> CAPTURE2 = {};

            /// Selects whether capture is enabled for the specified capture register.
            static constexpr bitfield_t<CAPTURECONTROL_t, 1, 1, bool> CAPTURE1 = {};

            /// Selects whether capture is enabled for the specified capture register.
            static constexpr bitfield_t<CAPTURECONTROL_t, 0, 0, bool> CAPTURE0 = {};
        } CAPTURECONTROL = {};

        /**
         * SCMPR0 - 4 bytes at offset 336
         * Compare Register A
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR0_t : reg_t<uint32_t, BASE_ADDRESS + 0x150> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x150>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_A_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR0_t, 31, 0> SCMPR0 = {};
        } SCMPR0 = {};

        /**
         * SCMPR1 - 4 bytes at offset 340
         * Compare Register B
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR1_t : reg_t<uint32_t, BASE_ADDRESS + 0x154> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x154>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_B_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR1_t, 31, 0> SCMPR1 = {};
        } SCMPR1 = {};

        /**
         * SCMPR2 - 4 bytes at offset 344
         * Compare Register C
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR2_t : reg_t<uint32_t, BASE_ADDRESS + 0x158> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x158>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_C_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR2_t, 31, 0> SCMPR2 = {};
        } SCMPR2 = {};

        /**
         * SCMPR3 - 4 bytes at offset 348
         * Compare Register D
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR3_t : reg_t<uint32_t, BASE_ADDRESS + 0x15C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x15C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_D_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR3_t, 31, 0> SCMPR3 = {};
        } SCMPR3 = {};

        /**
         * SCMPR4 - 4 bytes at offset 352
         * Compare Register E
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR4_t : reg_t<uint32_t, BASE_ADDRESS + 0x160> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x160>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_E_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR4_t, 31, 0> SCMPR4 = {};
        } SCMPR4 = {};

        /**
         * SCMPR5 - 4 bytes at offset 356
         * Compare Register F
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR5_t : reg_t<uint32_t, BASE_ADDRESS + 0x164> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x164>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_F_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR5_t, 31, 0> SCMPR5 = {};
        } SCMPR5 = {};

        /**
         * SCMPR6 - 4 bytes at offset 360
         * Compare Register G
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR6_t : reg_t<uint32_t, BASE_ADDRESS + 0x168> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x168>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_G_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR6_t, 31, 0> SCMPR6 = {};
        } SCMPR6 = {};

        /**
         * SCMPR7 - 4 bytes at offset 364
         * Compare Register H
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCMPR7_t : reg_t<uint32_t, BASE_ADDRESS + 0x16C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x16C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Compare this value to the value in the COUNTER register according to the match criterion, as selected in the COMPARE_H_EN bit in the REG_CTIMER_STCGF register.
            static constexpr bitfield_t<SCMPR7_t, 31, 0> SCMPR7 = {};
        } SCMPR7 = {};

        /**
         * SCAPT0 - 4 bytes at offset 480
         * Capture Register A
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCAPT0_t : reg_t<uint32_t, BASE_ADDRESS + 0x1E0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1E0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Whenever the event is detected, the value in the COUNTER is copied into this register and the corresponding interrupt status bit is set.
            static constexpr bitfield_t<SCAPT0_t, 31, 0> SCAPT0 = {};
        } SCAPT0 = {};

        /**
         * SCAPT1 - 4 bytes at offset 484
         * Capture Register B
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCAPT1_t : reg_t<uint32_t, BASE_ADDRESS + 0x1E4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1E4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Whenever the event is detected, the value in the COUNTER is copied into this register and the corresponding interrupt status bit is set.
            static constexpr bitfield_t<SCAPT1_t, 31, 0> SCAPT1 = {};
        } SCAPT1 = {};

        /**
         * SCAPT2 - 4 bytes at offset 488
         * Capture Register C
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCAPT2_t : reg_t<uint32_t, BASE_ADDRESS + 0x1E8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1E8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Whenever the event is detected, the value in the COUNTER is copied into this register and the corresponding interrupt status bit is set.
            static constexpr bitfield_t<SCAPT2_t, 31, 0> SCAPT2 = {};
        } SCAPT2 = {};

        /**
         * SCAPT3 - 4 bytes at offset 492
         * Capture Register D
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCAPT3_t : reg_t<uint32_t, BASE_ADDRESS + 0x1EC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1EC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Whenever the event is detected, the value in the COUNTER is copied into this register and the corresponding interrupt status bit is set.
            static constexpr bitfield_t<SCAPT3_t, 31, 0> SCAPT3 = {};
        } SCAPT3 = {};

        /**
         * SNVR0 - 4 bytes at offset 496
         * System Timer NVRAM_A Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SNVR0_t : reg_t<uint32_t, BASE_ADDRESS + 0x1F0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1F0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Value of the 32-bit counter as it ticks over.
            static constexpr bitfield_t<SNVR0_t, 31, 0> SNVR0 = {};
        } SNVR0 = {};

        /**
         * SNVR1 - 4 bytes at offset 500
         * System Timer NVRAM_B Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SNVR1_t : reg_t<uint32_t, BASE_ADDRESS + 0x1F4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1F4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Value of the 32-bit counter as it ticks over.
            static constexpr bitfield_t<SNVR1_t, 31, 0> SNVR1 = {};
        } SNVR1 = {};

        /**
         * SNVR2 - 4 bytes at offset 504
         * System Timer NVRAM_C Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SNVR2_t : reg_t<uint32_t, BASE_ADDRESS + 0x1F8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1F8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Value of the 32-bit counter as it ticks over.
            static constexpr bitfield_t<SNVR2_t, 31, 0> SNVR2 = {};
        } SNVR2 = {};

        /**
         * SNVR3 - 4 bytes at offset 508
         * System Timer NVRAM_D Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SNVR3_t : reg_t<uint32_t, BASE_ADDRESS + 0x1FC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1FC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Value of the 32-bit counter as it ticks over.
            static constexpr bitfield_t<SNVR3_t, 31, 0> SNVR3 = {};
        } SNVR3 = {};

        /**
         * INTEN - 4 bytes at offset 512
         * Counter/Timer Interrupts: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 31, 31, bool> CTMRB7C1INT = {};

            /// Counter/Timer A7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 30, 30, bool> CTMRA7C1INT = {};

            /// Counter/Timer B6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 29, 29, bool> CTMRB6C1INT = {};

            /// Counter/Timer A6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 28, 28, bool> CTMRA6C1INT = {};

            /// Counter/Timer B5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 27, 27, bool> CTMRB5C1INT = {};

            /// Counter/Timer A5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 26, 26, bool> CTMRA5C1INT = {};

            /// Counter/Timer B4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 25, 25, bool> CTMRB4C1INT = {};

            /// Counter/Timer A4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 24, 24, bool> CTMRA4C1INT = {};

            /// Counter/Timer B3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 23, 23, bool> CTMRB3C1INT = {};

            /// Counter/Timer A3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 22, 22, bool> CTMRA3C1INT = {};

            /// Counter/Timer B2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 21, 21, bool> CTMRB2C1INT = {};

            /// Counter/Timer A2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 20, 20, bool> CTMRA2C1INT = {};

            /// Counter/Timer B1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 19, 19, bool> CTMRB1C1INT = {};

            /// Counter/Timer A1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 18, 18, bool> CTMRA1C1INT = {};

            /// Counter/Timer B0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 17, 17, bool> CTMRB0C1INT = {};

            /// Counter/Timer A0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTEN_t, 16, 16, bool> CTMRA0C1INT = {};

            /// Counter/Timer B7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 15, 15, bool> CTMRB7C0INT = {};

            /// Counter/Timer A7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 14, 14, bool> CTMRA7C0INT = {};

            /// Counter/Timer B6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 13, 13, bool> CTMRB6C0INT = {};

            /// Counter/Timer A6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 12, 12, bool> CTMRA6C0INT = {};

            /// Counter/Timer B5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 11, 11, bool> CTMRB5C0INT = {};

            /// Counter/Timer A5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 10, 10, bool> CTMRA5C0INT = {};

            /// Counter/Timer B4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 9, 9, bool> CTMRB4C0INT = {};

            /// Counter/Timer A4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 8, 8, bool> CTMRA4C0INT = {};

            /// Counter/Timer B3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 7, 7, bool> CTMRB3C0INT = {};

            /// Counter/Timer A3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 6, 6, bool> CTMRA3C0INT = {};

            /// Counter/Timer B2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 5, 5, bool> CTMRB2C0INT = {};

            /// Counter/Timer A2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 4, 4, bool> CTMRA2C0INT = {};

            /// Counter/Timer B1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 3, 3, bool> CTMRB1C0INT = {};

            /// Counter/Timer A1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 2, 2, bool> CTMRA1C0INT = {};

            /// Counter/Timer B0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> CTMRB0C0INT = {};

            /// Counter/Timer A0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> CTMRA0C0INT = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * Counter/Timer Interrupts: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 31, 31, bool> CTMRB7C1INT = {};

            /// Counter/Timer A7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 30, 30, bool> CTMRA7C1INT = {};

            /// Counter/Timer B6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 29, 29, bool> CTMRB6C1INT = {};

            /// Counter/Timer A6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 28, 28, bool> CTMRA6C1INT = {};

            /// Counter/Timer B5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 27, 27, bool> CTMRB5C1INT = {};

            /// Counter/Timer A5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 26, 26, bool> CTMRA5C1INT = {};

            /// Counter/Timer B4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 25, 25, bool> CTMRB4C1INT = {};

            /// Counter/Timer A4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 24, 24, bool> CTMRA4C1INT = {};

            /// Counter/Timer B3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 23, 23, bool> CTMRB3C1INT = {};

            /// Counter/Timer A3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 22, 22, bool> CTMRA3C1INT = {};

            /// Counter/Timer B2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 21, 21, bool> CTMRB2C1INT = {};

            /// Counter/Timer A2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 20, 20, bool> CTMRA2C1INT = {};

            /// Counter/Timer B1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 19, 19, bool> CTMRB1C1INT = {};

            /// Counter/Timer A1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 18, 18, bool> CTMRA1C1INT = {};

            /// Counter/Timer B0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 17, 17, bool> CTMRB0C1INT = {};

            /// Counter/Timer A0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSTAT_t, 16, 16, bool> CTMRA0C1INT = {};

            /// Counter/Timer B7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 15, 15, bool> CTMRB7C0INT = {};

            /// Counter/Timer A7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 14, 14, bool> CTMRA7C0INT = {};

            /// Counter/Timer B6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 13, 13, bool> CTMRB6C0INT = {};

            /// Counter/Timer A6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 12, 12, bool> CTMRA6C0INT = {};

            /// Counter/Timer B5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 11, 11, bool> CTMRB5C0INT = {};

            /// Counter/Timer A5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 10, 10, bool> CTMRA5C0INT = {};

            /// Counter/Timer B4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 9, 9, bool> CTMRB4C0INT = {};

            /// Counter/Timer A4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 8, 8, bool> CTMRA4C0INT = {};

            /// Counter/Timer B3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 7, 7, bool> CTMRB3C0INT = {};

            /// Counter/Timer A3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 6, 6, bool> CTMRA3C0INT = {};

            /// Counter/Timer B2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 5, 5, bool> CTMRB2C0INT = {};

            /// Counter/Timer A2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 4, 4, bool> CTMRA2C0INT = {};

            /// Counter/Timer B1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 3, 3, bool> CTMRB1C0INT = {};

            /// Counter/Timer A1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 2, 2, bool> CTMRA1C0INT = {};

            /// Counter/Timer B0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> CTMRB0C0INT = {};

            /// Counter/Timer A0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> CTMRA0C0INT = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * Counter/Timer Interrupts: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 31, 31, bool> CTMRB7C1INT = {};

            /// Counter/Timer A7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 30, 30, bool> CTMRA7C1INT = {};

            /// Counter/Timer B6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 29, 29, bool> CTMRB6C1INT = {};

            /// Counter/Timer A6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 28, 28, bool> CTMRA6C1INT = {};

            /// Counter/Timer B5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 27, 27, bool> CTMRB5C1INT = {};

            /// Counter/Timer A5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 26, 26, bool> CTMRA5C1INT = {};

            /// Counter/Timer B4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 25, 25, bool> CTMRB4C1INT = {};

            /// Counter/Timer A4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 24, 24, bool> CTMRA4C1INT = {};

            /// Counter/Timer B3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 23, 23, bool> CTMRB3C1INT = {};

            /// Counter/Timer A3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 22, 22, bool> CTMRA3C1INT = {};

            /// Counter/Timer B2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 21, 21, bool> CTMRB2C1INT = {};

            /// Counter/Timer A2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 20, 20, bool> CTMRA2C1INT = {};

            /// Counter/Timer B1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 19, 19, bool> CTMRB1C1INT = {};

            /// Counter/Timer A1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 18, 18, bool> CTMRA1C1INT = {};

            /// Counter/Timer B0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 17, 17, bool> CTMRB0C1INT = {};

            /// Counter/Timer A0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTCLR_t, 16, 16, bool> CTMRA0C1INT = {};

            /// Counter/Timer B7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 15, 15, bool> CTMRB7C0INT = {};

            /// Counter/Timer A7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 14, 14, bool> CTMRA7C0INT = {};

            /// Counter/Timer B6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 13, 13, bool> CTMRB6C0INT = {};

            /// Counter/Timer A6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 12, 12, bool> CTMRA6C0INT = {};

            /// Counter/Timer B5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 11, 11, bool> CTMRB5C0INT = {};

            /// Counter/Timer A5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 10, 10, bool> CTMRA5C0INT = {};

            /// Counter/Timer B4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 9, 9, bool> CTMRB4C0INT = {};

            /// Counter/Timer A4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 8, 8, bool> CTMRA4C0INT = {};

            /// Counter/Timer B3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 7, 7, bool> CTMRB3C0INT = {};

            /// Counter/Timer A3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 6, 6, bool> CTMRA3C0INT = {};

            /// Counter/Timer B2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 5, 5, bool> CTMRB2C0INT = {};

            /// Counter/Timer A2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 4, 4, bool> CTMRA2C0INT = {};

            /// Counter/Timer B1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 3, 3, bool> CTMRB1C0INT = {};

            /// Counter/Timer A1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 2, 2, bool> CTMRA1C0INT = {};

            /// Counter/Timer B0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> CTMRB0C0INT = {};

            /// Counter/Timer A0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> CTMRA0C0INT = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * Counter/Timer Interrupts: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Counter/Timer B7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 31, 31, bool> CTMRB7C1INT = {};

            /// Counter/Timer A7 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 30, 30, bool> CTMRA7C1INT = {};

            /// Counter/Timer B6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 29, 29, bool> CTMRB6C1INT = {};

            /// Counter/Timer A6 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 28, 28, bool> CTMRA6C1INT = {};

            /// Counter/Timer B5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 27, 27, bool> CTMRB5C1INT = {};

            /// Counter/Timer A5 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 26, 26, bool> CTMRA5C1INT = {};

            /// Counter/Timer B4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 25, 25, bool> CTMRB4C1INT = {};

            /// Counter/Timer A4 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 24, 24, bool> CTMRA4C1INT = {};

            /// Counter/Timer B3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 23, 23, bool> CTMRB3C1INT = {};

            /// Counter/Timer A3 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 22, 22, bool> CTMRA3C1INT = {};

            /// Counter/Timer B2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 21, 21, bool> CTMRB2C1INT = {};

            /// Counter/Timer A2 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 20, 20, bool> CTMRA2C1INT = {};

            /// Counter/Timer B1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 19, 19, bool> CTMRB1C1INT = {};

            /// Counter/Timer A1 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 18, 18, bool> CTMRA1C1INT = {};

            /// Counter/Timer B0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 17, 17, bool> CTMRB0C1INT = {};

            /// Counter/Timer A0 interrupt based on COMPR1.
            static constexpr bitfield_t<INTSET_t, 16, 16, bool> CTMRA0C1INT = {};

            /// Counter/Timer B7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 15, 15, bool> CTMRB7C0INT = {};

            /// Counter/Timer A7 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 14, 14, bool> CTMRA7C0INT = {};

            /// Counter/Timer B6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 13, 13, bool> CTMRB6C0INT = {};

            /// Counter/Timer A6 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 12, 12, bool> CTMRA6C0INT = {};

            /// Counter/Timer B5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 11, 11, bool> CTMRB5C0INT = {};

            /// Counter/Timer A5 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 10, 10, bool> CTMRA5C0INT = {};

            /// Counter/Timer B4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 9, 9, bool> CTMRB4C0INT = {};

            /// Counter/Timer A4 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 8, 8, bool> CTMRA4C0INT = {};

            /// Counter/Timer B3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 7, 7, bool> CTMRB3C0INT = {};

            /// Counter/Timer A3 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 6, 6, bool> CTMRA3C0INT = {};

            /// Counter/Timer B2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 5, 5, bool> CTMRB2C0INT = {};

            /// Counter/Timer A2 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 4, 4, bool> CTMRA2C0INT = {};

            /// Counter/Timer B1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 3, 3, bool> CTMRB1C0INT = {};

            /// Counter/Timer A1 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 2, 2, bool> CTMRA1C0INT = {};

            /// Counter/Timer B0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> CTMRB0C0INT = {};

            /// Counter/Timer A0 interrupt based on COMPR0.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> CTMRA0C0INT = {};
        } INTSET = {};

        /**
         * STMINTEN - 4 bytes at offset 768
         * STIMER Interrupt registers: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STMINTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x300> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x300>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CAPTURE register D has grabbed the value in the counter
            static constexpr bitfield_t<STMINTEN_t, 12, 12, bool> CAPTURED = {};

            /// CAPTURE register C has grabbed the value in the counter
            static constexpr bitfield_t<STMINTEN_t, 11, 11, bool> CAPTUREC = {};

            /// CAPTURE register B has grabbed the value in the counter
            static constexpr bitfield_t<STMINTEN_t, 10, 10, bool> CAPTUREB = {};

            /// CAPTURE register A has grabbed the value in the counter
            static constexpr bitfield_t<STMINTEN_t, 9, 9, bool> CAPTUREA = {};

            /// COUNTER over flowed from 0xFFFFFFFF back to 0x00000000.
            static constexpr bitfield_t<STMINTEN_t, 8, 8, bool> OVERFLOW = {};

            /// COUNTER is greater than or equal to COMPARE register H.
            static constexpr bitfield_t<STMINTEN_t, 7, 7, bool> COMPAREH = {};

            /// COUNTER is greater than or equal to COMPARE register G.
            static constexpr bitfield_t<STMINTEN_t, 6, 6, bool> COMPAREG = {};

            /// COUNTER is greater than or equal to COMPARE register F.
            static constexpr bitfield_t<STMINTEN_t, 5, 5, bool> COMPAREF = {};

            /// COUNTER is greater than or equal to COMPARE register E.
            static constexpr bitfield_t<STMINTEN_t, 4, 4, bool> COMPAREE = {};

            /// COUNTER is greater than or equal to COMPARE register D.
            static constexpr bitfield_t<STMINTEN_t, 3, 3, bool> COMPARED = {};

            /// COUNTER is greater than or equal to COMPARE register C.
            static constexpr bitfield_t<STMINTEN_t, 2, 2, bool> COMPAREC = {};

            /// COUNTER is greater than or equal to COMPARE register B.
            static constexpr bitfield_t<STMINTEN_t, 1, 1, bool> COMPAREB = {};

            /// COUNTER is greater than or equal to COMPARE register A.
            static constexpr bitfield_t<STMINTEN_t, 0, 0, bool> COMPAREA = {};
        } STMINTEN = {};

        /**
         * STMINTSTAT - 4 bytes at offset 772
         * STIMER Interrupt registers: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STMINTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x304> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x304>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CAPTURE register D has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSTAT_t, 12, 12, bool> CAPTURED = {};

            /// CAPTURE register C has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSTAT_t, 11, 11, bool> CAPTUREC = {};

            /// CAPTURE register B has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSTAT_t, 10, 10, bool> CAPTUREB = {};

            /// CAPTURE register A has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSTAT_t, 9, 9, bool> CAPTUREA = {};

            /// COUNTER over flowed from 0xFFFFFFFF back to 0x00000000.
            static constexpr bitfield_t<STMINTSTAT_t, 8, 8, bool> OVERFLOW = {};

            /// COUNTER is greater than or equal to COMPARE register H.
            static constexpr bitfield_t<STMINTSTAT_t, 7, 7, bool> COMPAREH = {};

            /// COUNTER is greater than or equal to COMPARE register G.
            static constexpr bitfield_t<STMINTSTAT_t, 6, 6, bool> COMPAREG = {};

            /// COUNTER is greater than or equal to COMPARE register F.
            static constexpr bitfield_t<STMINTSTAT_t, 5, 5, bool> COMPAREF = {};

            /// COUNTER is greater than or equal to COMPARE register E.
            static constexpr bitfield_t<STMINTSTAT_t, 4, 4, bool> COMPAREE = {};

            /// COUNTER is greater than or equal to COMPARE register D.
            static constexpr bitfield_t<STMINTSTAT_t, 3, 3, bool> COMPARED = {};

            /// COUNTER is greater than or equal to COMPARE register C.
            static constexpr bitfield_t<STMINTSTAT_t, 2, 2, bool> COMPAREC = {};

            /// COUNTER is greater than or equal to COMPARE register B.
            static constexpr bitfield_t<STMINTSTAT_t, 1, 1, bool> COMPAREB = {};

            /// COUNTER is greater than or equal to COMPARE register A.
            static constexpr bitfield_t<STMINTSTAT_t, 0, 0, bool> COMPAREA = {};
        } STMINTSTAT = {};

        /**
         * STMINTCLR - 4 bytes at offset 776
         * STIMER Interrupt registers: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STMINTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x308> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x308>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CAPTURE register D has grabbed the value in the counter
            static constexpr bitfield_t<STMINTCLR_t, 12, 12, bool> CAPTURED = {};

            /// CAPTURE register C has grabbed the value in the counter
            static constexpr bitfield_t<STMINTCLR_t, 11, 11, bool> CAPTUREC = {};

            /// CAPTURE register B has grabbed the value in the counter
            static constexpr bitfield_t<STMINTCLR_t, 10, 10, bool> CAPTUREB = {};

            /// CAPTURE register A has grabbed the value in the counter
            static constexpr bitfield_t<STMINTCLR_t, 9, 9, bool> CAPTUREA = {};

            /// COUNTER over flowed from 0xFFFFFFFF back to 0x00000000.
            static constexpr bitfield_t<STMINTCLR_t, 8, 8, bool> OVERFLOW = {};

            /// COUNTER is greater than or equal to COMPARE register H.
            static constexpr bitfield_t<STMINTCLR_t, 7, 7, bool> COMPAREH = {};

            /// COUNTER is greater than or equal to COMPARE register G.
            static constexpr bitfield_t<STMINTCLR_t, 6, 6, bool> COMPAREG = {};

            /// COUNTER is greater than or equal to COMPARE register F.
            static constexpr bitfield_t<STMINTCLR_t, 5, 5, bool> COMPAREF = {};

            /// COUNTER is greater than or equal to COMPARE register E.
            static constexpr bitfield_t<STMINTCLR_t, 4, 4, bool> COMPAREE = {};

            /// COUNTER is greater than or equal to COMPARE register D.
            static constexpr bitfield_t<STMINTCLR_t, 3, 3, bool> COMPARED = {};

            /// COUNTER is greater than or equal to COMPARE register C.
            static constexpr bitfield_t<STMINTCLR_t, 2, 2, bool> COMPAREC = {};

            /// COUNTER is greater than or equal to COMPARE register B.
            static constexpr bitfield_t<STMINTCLR_t, 1, 1, bool> COMPAREB = {};

            /// COUNTER is greater than or equal to COMPARE register A.
            static constexpr bitfield_t<STMINTCLR_t, 0, 0, bool> COMPAREA = {};
        } STMINTCLR = {};

        /**
         * STMINTSET - 4 bytes at offset 780
         * STIMER Interrupt registers: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STMINTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x30C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CAPTURE register D has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSET_t, 12, 12, bool> CAPTURED = {};

            /// CAPTURE register C has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSET_t, 11, 11, bool> CAPTUREC = {};

            /// CAPTURE register B has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSET_t, 10, 10, bool> CAPTUREB = {};

            /// CAPTURE register A has grabbed the value in the counter
            static constexpr bitfield_t<STMINTSET_t, 9, 9, bool> CAPTUREA = {};

            /// COUNTER over flowed from 0xFFFFFFFF back to 0x00000000.
            static constexpr bitfield_t<STMINTSET_t, 8, 8, bool> OVERFLOW = {};

            /// COUNTER is greater than or equal to COMPARE register H.
            static constexpr bitfield_t<STMINTSET_t, 7, 7, bool> COMPAREH = {};

            /// COUNTER is greater than or equal to COMPARE register G.
            static constexpr bitfield_t<STMINTSET_t, 6, 6, bool> COMPAREG = {};

            /// COUNTER is greater than or equal to COMPARE register F.
            static constexpr bitfield_t<STMINTSET_t, 5, 5, bool> COMPAREF = {};

            /// COUNTER is greater than or equal to COMPARE register E.
            static constexpr bitfield_t<STMINTSET_t, 4, 4, bool> COMPAREE = {};

            /// COUNTER is greater than or equal to COMPARE register D.
            static constexpr bitfield_t<STMINTSET_t, 3, 3, bool> COMPARED = {};

            /// COUNTER is greater than or equal to COMPARE register C.
            static constexpr bitfield_t<STMINTSET_t, 2, 2, bool> COMPAREC = {};

            /// COUNTER is greater than or equal to COMPARE register B.
            static constexpr bitfield_t<STMINTSET_t, 1, 1, bool> COMPAREB = {};

            /// COUNTER is greater than or equal to COMPARE register A.
            static constexpr bitfield_t<STMINTSET_t, 0, 0, bool> COMPAREA = {};
        } STMINTSET = {};
    };  // end of struct CTIMER_t

} // namespace sfr