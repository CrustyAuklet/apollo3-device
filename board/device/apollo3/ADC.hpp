/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: ADC
 * Analog Digital Converter Control
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace ADC {
    
        /// Select the source and frequency for the ADC clock.  All values not enumerated below are undefined.
        enum class CLKSELv : uint32_t {
            OFF = 0x0, //< Off mode. The HFRC or HFRC_DIV2 clock must be selected for the ADC to function. The ADC controller automatically shuts off the clock in it's low power modes.  When setting ADCEN to '0', the CLKSEL should remain set to one of the two clock selects for proper power down sequencing.
            HFRC = 0x1, //< HFRC Core Clock divided by (CORESEL+1)
            HFRC_DIV2 = 0x2, //< HFRC Core Clock / 2 further divided by (CORESEL+1)
        };
    
        /// Select the ADC trigger source.
        enum class TRIGSELv : uint32_t {
            EXT0 = 0x0, //< Off chip External Trigger0 (ADC_ET0)
            EXT1 = 0x1, //< Off chip External Trigger1 (ADC_ET1)
            EXT2 = 0x2, //< Off chip External Trigger2 (ADC_ET2)
            EXT3 = 0x3, //< Off chip External Trigger3 (ADC_ET3)
            VCOMP = 0x4, //< Voltage Comparator Output
            SWT = 0x7, //< Software Trigger
        };
    
        /// Select the ADC reference voltage.
        enum class REFSELv : uint32_t {
            INT2P0 = 0x0, //< Internal 2.0V Bandgap Reference Voltage
            INT1P5 = 0x1, //< Internal 1.5V Bandgap Reference Voltage
            EXT2P0 = 0x2, //< Off Chip 2.0V Reference
            EXT1P5 = 0x3, //< Off Chip 1.5V Reference
        };
    
        /// Writing 0x37 to this register generates a software trigger.
        enum class SWTv : uint32_t {
            GEN_SW_TRIGGER = 0x37, //< Writing this value generates a software trigger.
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL0v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE0v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL0v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL1v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE1v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL1v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL2v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE2v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL2v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL3v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE3v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL3v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL4v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE4v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL4v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL5v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE5v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL5v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL6v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE6v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL6v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
        /// Select the number of measurements to average in the accumulate divide module for this slot.
        enum class ADSEL7v : uint32_t {
            AVG_1_MSRMT = 0x0, //< Average in 1 measurement in the accumulate divide module for this slot.
            AVG_2_MSRMTS = 0x1, //< Average in 2 measurements in the accumulate divide module for this slot.
            AVG_4_MSRMTS = 0x2, //< Average in 4 measurements in the accumulate divide module for this slot.
            AVG_8_MSRMT = 0x3, //< Average in 8 measurements in the accumulate divide module for this slot.
            AVG_16_MSRMTS = 0x4, //< Average in 16 measurements in the accumulate divide module for this slot.
            AVG_32_MSRMTS = 0x5, //< Average in 32 measurements in the accumulate divide module for this slot.
            AVG_64_MSRMTS = 0x6, //< Average in 64 measurements in the accumulate divide module for this slot.
            AVG_128_MSRMTS = 0x7, //< Average in 128 measurements in the accumulate divide module for this slot.
        };
    
        /// Set the Precision Mode For Slot.
        enum class PRMODE7v : uint32_t {
            P14B = 0x0, //< 14-bit precision mode
            P12B = 0x1, //< 12-bit precision mode
            P10B = 0x2, //< 10-bit precision mode
            P8B = 0x3, //< 8-bit precision mode
        };
    
        /// Select one of the 14 channel inputs for this slot.
        enum class CHSEL7v : uint32_t {
            SE0 = 0x0, //< single ended external GPIO connection to pad16.
            SE1 = 0x1, //< single ended external GPIO connection to pad29.
            SE2 = 0x2, //< single ended external GPIO connection to pad11.
            SE3 = 0x3, //< single ended external GPIO connection to pad31.
            SE4 = 0x4, //< single ended external GPIO connection to pad32.
            SE5 = 0x5, //< single ended external GPIO connection to pad33.
            SE6 = 0x6, //< single ended external GPIO connection to pad34.
            SE7 = 0x7, //< single ended external GPIO connection to pad35.
            SE8 = 0x8, //< single ended external GPIO connection to pad13.
            SE9 = 0x9, //< single ended external GPIO connection to pad12.
            DF0 = 0xA, //< differential external GPIO connections to pad12(N) and pad13(P).
            DF1 = 0xB, //< differential external GPIO connections to pad15(N) and pad14(P).
            TEMP = 0xC, //< internal temperature sensor.
            BATT = 0xD, //< internal voltage divide-by-3 connection.
            VSS = 0xE, //< Input VSS
        };
    
    }   // namespace ADC

    /// Analog Digital Converter Control
    template <addressType BASE_ADDRESS>
    struct ADC_t {
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
            static constexpr uint32_t reset_mask  = 0x30F131D;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the source and frequency for the ADC clock.  All values not enumerated below are undefined.
            static constexpr bitfield_t<CFG_t, 25, 24, ADC::CLKSELv> CLKSEL = {};

            /// This bit selects the ADC trigger polarity for external off chip triggers.
            static constexpr bitfield_t<CFG_t, 19, 19, bool> TRIGPOL = {};

            /// Select the ADC trigger source.
            static constexpr bitfield_t<CFG_t, 18, 16, ADC::TRIGSELv> TRIGSEL = {};

            /// Destructive FIFO Read Enable. Setting this will enable FIFO pop upon reading the FIFOPR register.
            static constexpr bitfield_t<CFG_t, 12, 12, bool> DFIFORDEN = {};

            /// Select the ADC reference voltage.
            static constexpr bitfield_t<CFG_t, 9, 8, ADC::REFSELv> REFSEL = {};

            /// Clock mode register
            static constexpr bitfield_t<CFG_t, 4, 4, bool> CKMODE = {};

            /// Select power mode to enter between active scans.
            static constexpr bitfield_t<CFG_t, 3, 3, bool> LPMODE = {};

            /// This bit enables Repeating Scan Mode.
            static constexpr bitfield_t<CFG_t, 2, 2, bool> RPTEN = {};

            /// This bit enables the ADC module. While the ADC is enabled, the ADCCFG and SLOT Configuration regsiter settings must remain stable and unchanged. All configuration register settings, slot configuration settings and window comparison settings should be written prior to setting the ADCEN bit to '1'.
            static constexpr bitfield_t<CFG_t, 0, 0, bool> ADCEN = {};
        } CFG = {};

        /**
         * STAT - 4 bytes at offset 4
         * ADC Power Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Indicates the power-status of the ADC.
            static constexpr bitfield_t<STAT_t, 0, 0, bool> PWDSTAT = {};
        } STAT = {};

        /**
         * SWT - 4 bytes at offset 8
         * Software trigger
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SWT_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Writing 0x37 to this register generates a software trigger.
            static constexpr bitfield_t<SWT_t, 7, 0, ADC::SWTv> SWT = {};
        } SWT = {};

        /**
         * SL0CFG - 4 bytes at offset 12
         * Slot 0 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL0CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL0CFG_t, 26, 24, ADC::ADSEL0v> ADSEL0 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL0CFG_t, 17, 16, ADC::PRMODE0v> PRMODE0 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL0CFG_t, 11, 8, ADC::CHSEL0v> CHSEL0 = {};

            /// This bit enables the window compare function for slot 0.
            static constexpr bitfield_t<SL0CFG_t, 1, 1, bool> WCEN0 = {};

            /// This bit enables slot 0 for ADC conversions.
            static constexpr bitfield_t<SL0CFG_t, 0, 0, bool> SLEN0 = {};
        } SL0CFG = {};

        /**
         * SL1CFG - 4 bytes at offset 16
         * Slot 1 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL1CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL1CFG_t, 26, 24, ADC::ADSEL1v> ADSEL1 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL1CFG_t, 17, 16, ADC::PRMODE1v> PRMODE1 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL1CFG_t, 11, 8, ADC::CHSEL1v> CHSEL1 = {};

            /// This bit enables the window compare function for slot 1.
            static constexpr bitfield_t<SL1CFG_t, 1, 1, bool> WCEN1 = {};

            /// This bit enables slot 1 for ADC conversions.
            static constexpr bitfield_t<SL1CFG_t, 0, 0, bool> SLEN1 = {};
        } SL1CFG = {};

        /**
         * SL2CFG - 4 bytes at offset 20
         * Slot 2 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL2CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL2CFG_t, 26, 24, ADC::ADSEL2v> ADSEL2 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL2CFG_t, 17, 16, ADC::PRMODE2v> PRMODE2 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL2CFG_t, 11, 8, ADC::CHSEL2v> CHSEL2 = {};

            /// This bit enables the window compare function for slot 2.
            static constexpr bitfield_t<SL2CFG_t, 1, 1, bool> WCEN2 = {};

            /// This bit enables slot 2 for ADC conversions.
            static constexpr bitfield_t<SL2CFG_t, 0, 0, bool> SLEN2 = {};
        } SL2CFG = {};

        /**
         * SL3CFG - 4 bytes at offset 24
         * Slot 3 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL3CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL3CFG_t, 26, 24, ADC::ADSEL3v> ADSEL3 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL3CFG_t, 17, 16, ADC::PRMODE3v> PRMODE3 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL3CFG_t, 11, 8, ADC::CHSEL3v> CHSEL3 = {};

            /// This bit enables the window compare function for slot 3.
            static constexpr bitfield_t<SL3CFG_t, 1, 1, bool> WCEN3 = {};

            /// This bit enables slot 3 for ADC conversions.
            static constexpr bitfield_t<SL3CFG_t, 0, 0, bool> SLEN3 = {};
        } SL3CFG = {};

        /**
         * SL4CFG - 4 bytes at offset 28
         * Slot 4 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL4CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL4CFG_t, 26, 24, ADC::ADSEL4v> ADSEL4 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL4CFG_t, 17, 16, ADC::PRMODE4v> PRMODE4 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL4CFG_t, 11, 8, ADC::CHSEL4v> CHSEL4 = {};

            /// This bit enables the window compare function for slot 4.
            static constexpr bitfield_t<SL4CFG_t, 1, 1, bool> WCEN4 = {};

            /// This bit enables slot 4 for ADC conversions.
            static constexpr bitfield_t<SL4CFG_t, 0, 0, bool> SLEN4 = {};
        } SL4CFG = {};

        /**
         * SL5CFG - 4 bytes at offset 32
         * Slot 5 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL5CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL5CFG_t, 26, 24, ADC::ADSEL5v> ADSEL5 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL5CFG_t, 17, 16, ADC::PRMODE5v> PRMODE5 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL5CFG_t, 11, 8, ADC::CHSEL5v> CHSEL5 = {};

            /// This bit enables the window compare function for slot 5.
            static constexpr bitfield_t<SL5CFG_t, 1, 1, bool> WCEN5 = {};

            /// This bit enables slot 5 for ADC conversions.
            static constexpr bitfield_t<SL5CFG_t, 0, 0, bool> SLEN5 = {};
        } SL5CFG = {};

        /**
         * SL6CFG - 4 bytes at offset 36
         * Slot 6 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL6CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x24> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x24>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL6CFG_t, 26, 24, ADC::ADSEL6v> ADSEL6 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL6CFG_t, 17, 16, ADC::PRMODE6v> PRMODE6 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL6CFG_t, 11, 8, ADC::CHSEL6v> CHSEL6 = {};

            /// This bit enables the window compare function for slot 6.
            static constexpr bitfield_t<SL6CFG_t, 1, 1, bool> WCEN6 = {};

            /// This bit enables slot 6 for ADC conversions.
            static constexpr bitfield_t<SL6CFG_t, 0, 0, bool> SLEN6 = {};
        } SL6CFG = {};

        /**
         * SL7CFG - 4 bytes at offset 40
         * Slot 7 Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SL7CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0x7030F03;
            static constexpr uint32_t reset_value = 0x0;

            /// Select the number of measurements to average in the accumulate divide module for this slot.
            static constexpr bitfield_t<SL7CFG_t, 26, 24, ADC::ADSEL7v> ADSEL7 = {};

            /// Set the Precision Mode For Slot.
            static constexpr bitfield_t<SL7CFG_t, 17, 16, ADC::PRMODE7v> PRMODE7 = {};

            /// Select one of the 14 channel inputs for this slot.
            static constexpr bitfield_t<SL7CFG_t, 11, 8, ADC::CHSEL7v> CHSEL7 = {};

            /// This bit enables the window compare function for slot 7.
            static constexpr bitfield_t<SL7CFG_t, 1, 1, bool> WCEN7 = {};

            /// This bit enables slot 7 for ADC conversions.
            static constexpr bitfield_t<SL7CFG_t, 0, 0, bool> SLEN7 = {};
        } SL7CFG = {};

        /**
         * WULIM - 4 bytes at offset 44
         * Window Comparator Upper Limits Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WULIM_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Sets the upper limit for the window comparator.
            static constexpr bitfield_t<WULIM_t, 19, 0> ULIM = {};
        } WULIM = {};

        /**
         * WLLIM - 4 bytes at offset 48
         * Window Comparator Lower Limits Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WLLIM_t : reg_t<uint32_t, BASE_ADDRESS + 0x30> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Sets the lower limit for the window comparator.
            static constexpr bitfield_t<WLLIM_t, 19, 0> LLIM = {};
        } WLLIM = {};

        /**
         * SCWLIM - 4 bytes at offset 52
         * Scale Window Comparator Limits
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCWLIM_t : reg_t<uint32_t, BASE_ADDRESS + 0x34> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x34>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// Scale the window limits compare values per precision mode. When set to 0x0 (default), the values in the 20-bit limits registers will compare directly with the FIFO values regardless of the precision mode the slot is configured to.  When set to 0x1, the compare values will be divided by the difference in precision bits while performing the window limit comparisons.
            static constexpr bitfield_t<SCWLIM_t, 0, 0, bool> SCWLIMEN = {};
        } SCWLIM = {};

        /**
         * FIFO - 4 bytes at offset 56
         * FIFO Data and Valid Count Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFO_t : reg_t<uint32_t, BASE_ADDRESS + 0x38> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x38>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// RESERVED.
            static constexpr bitfield_t<FIFO_t, 31, 31, bool> RSVD = {};

            /// Slot number associated with this FIFO data.
            static constexpr bitfield_t<FIFO_t, 30, 28> SLOTNUM = {};

            /// Number of valid entries in the ADC FIFO.
            static constexpr bitfield_t<FIFO_t, 27, 20> COUNT = {};

            /// Oldest data in the FIFO.
            static constexpr bitfield_t<FIFO_t, 19, 0> DATA = {};
        } FIFO = {};

        /**
         * FIFOPR - 4 bytes at offset 60
         * FIFO Data and Valid Count Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOPR_t : reg_t<uint32_t, BASE_ADDRESS + 0x3C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// RESERVED.
            static constexpr bitfield_t<FIFOPR_t, 31, 31, bool> RSVDPR = {};

            /// Slot number associated with this FIFO data.
            static constexpr bitfield_t<FIFOPR_t, 30, 28> SLOTNUMPR = {};

            /// Number of valid entries in the ADC FIFO.
            static constexpr bitfield_t<FIFOPR_t, 27, 20> COUNT = {};

            /// Oldest data in the FIFO.
            static constexpr bitfield_t<FIFOPR_t, 19, 0> DATA = {};
        } FIFOPR = {};

        /**
         * INTEN - 4 bytes at offset 512
         * ADC Interrupt registers: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error Condition
            static constexpr bitfield_t<INTEN_t, 7, 7, bool> DERR = {};

            /// DMA Transfer Complete
            static constexpr bitfield_t<INTEN_t, 6, 6, bool> DCMP = {};

            /// Window comparator voltage incursion interrupt.
            static constexpr bitfield_t<INTEN_t, 5, 5, bool> WCINC = {};

            /// Window comparator voltage excursion interrupt.
            static constexpr bitfield_t<INTEN_t, 4, 4, bool> WCEXC = {};

            /// FIFO 100 percent full interrupt.
            static constexpr bitfield_t<INTEN_t, 3, 3, bool> FIFOOVR2 = {};

            /// FIFO 75 percent full interrupt.
            static constexpr bitfield_t<INTEN_t, 2, 2, bool> FIFOOVR1 = {};

            /// ADC scan complete interrupt.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> SCNCMP = {};

            /// ADC conversion complete interrupt.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> CNVCMP = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * ADC Interrupt registers: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error Condition
            static constexpr bitfield_t<INTSTAT_t, 7, 7, bool> DERR = {};

            /// DMA Transfer Complete
            static constexpr bitfield_t<INTSTAT_t, 6, 6, bool> DCMP = {};

            /// Window comparator voltage incursion interrupt.
            static constexpr bitfield_t<INTSTAT_t, 5, 5, bool> WCINC = {};

            /// Window comparator voltage excursion interrupt.
            static constexpr bitfield_t<INTSTAT_t, 4, 4, bool> WCEXC = {};

            /// FIFO 100 percent full interrupt.
            static constexpr bitfield_t<INTSTAT_t, 3, 3, bool> FIFOOVR2 = {};

            /// FIFO 75 percent full interrupt.
            static constexpr bitfield_t<INTSTAT_t, 2, 2, bool> FIFOOVR1 = {};

            /// ADC scan complete interrupt.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> SCNCMP = {};

            /// ADC conversion complete interrupt.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> CNVCMP = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * ADC Interrupt registers: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error Condition
            static constexpr bitfield_t<INTCLR_t, 7, 7, bool> DERR = {};

            /// DMA Transfer Complete
            static constexpr bitfield_t<INTCLR_t, 6, 6, bool> DCMP = {};

            /// Window comparator voltage incursion interrupt.
            static constexpr bitfield_t<INTCLR_t, 5, 5, bool> WCINC = {};

            /// Window comparator voltage excursion interrupt.
            static constexpr bitfield_t<INTCLR_t, 4, 4, bool> WCEXC = {};

            /// FIFO 100 percent full interrupt.
            static constexpr bitfield_t<INTCLR_t, 3, 3, bool> FIFOOVR2 = {};

            /// FIFO 75 percent full interrupt.
            static constexpr bitfield_t<INTCLR_t, 2, 2, bool> FIFOOVR1 = {};

            /// ADC scan complete interrupt.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> SCNCMP = {};

            /// ADC conversion complete interrupt.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> CNVCMP = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * ADC Interrupt registers: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error Condition
            static constexpr bitfield_t<INTSET_t, 7, 7, bool> DERR = {};

            /// DMA Transfer Complete
            static constexpr bitfield_t<INTSET_t, 6, 6, bool> DCMP = {};

            /// Window comparator voltage incursion interrupt.
            static constexpr bitfield_t<INTSET_t, 5, 5, bool> WCINC = {};

            /// Window comparator voltage excursion interrupt.
            static constexpr bitfield_t<INTSET_t, 4, 4, bool> WCEXC = {};

            /// FIFO 100 percent full interrupt.
            static constexpr bitfield_t<INTSET_t, 3, 3, bool> FIFOOVR2 = {};

            /// FIFO 75 percent full interrupt.
            static constexpr bitfield_t<INTSET_t, 2, 2, bool> FIFOOVR1 = {};

            /// ADC scan complete interrupt.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> SCNCMP = {};

            /// ADC conversion complete interrupt.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> CNVCMP = {};
        } INTSET = {};

        /**
         * DMATRIGEN - 4 bytes at offset 576
         * DMA Trigger Enable Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATRIGEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x240> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x240>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// Trigger DMA upon FIFO 100 percent Full
            static constexpr bitfield_t<DMATRIGEN_t, 1, 1, bool> DFIFOFULL = {};

            /// Trigger DMA upon FIFO 75 percent Full
            static constexpr bitfield_t<DMATRIGEN_t, 0, 0, bool> DFIFO75 = {};
        } DMATRIGEN = {};

        /**
         * DMATRIGSTAT - 4 bytes at offset 580
         * DMA Trigger Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATRIGSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x244> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x244>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// Triggered DMA from FIFO 100 percent Full
            static constexpr bitfield_t<DMATRIGSTAT_t, 1, 1, bool> DFULLSTAT = {};

            /// Triggered DMA from FIFO 75 percent Full
            static constexpr bitfield_t<DMATRIGSTAT_t, 0, 0, bool> D75STAT = {};
        } DMATRIGSTAT = {};

        /**
         * DMACFG - 4 bytes at offset 640
         * DMA Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMACFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x280> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x280>::operator=;
            static constexpr uint32_t reset_mask  = 0x70305;
            static constexpr uint32_t reset_value = 0x0;

            /// Power Off the ADC System upon DMACPL.
            static constexpr bitfield_t<DMACFG_t, 18, 18, bool> DPWROFF = {};

            /// Mask the FIFOCNT and SLOTNUM when transferring FIFO contents to memory
            static constexpr bitfield_t<DMACFG_t, 17, 17, bool> DMAMSK = {};

            /// Halt New ADC conversions until DMA Status DMAERR and DMACPL Cleared.
            static constexpr bitfield_t<DMACFG_t, 16, 16, bool> DMAHONSTAT = {};

            /// Enables dynamic priority based on FIFO fullness.  When FIFO is full, priority is automatically set to HIGH.  Otherwise, DMAPRI is used.
            static constexpr bitfield_t<DMACFG_t, 9, 9, bool> DMADYNPRI = {};

            /// Sets the Priority of the DMA request
            static constexpr bitfield_t<DMACFG_t, 8, 8, bool> DMAPRI = {};

            /// Direction
            static constexpr bitfield_t<DMACFG_t, 2, 2, bool> DMADIR = {};

            /// DMA Enable
            static constexpr bitfield_t<DMACFG_t, 0, 0, bool> DMAEN = {};
        } DMACFG = {};

        /**
         * DMATOTCOUNT - 4 bytes at offset 648
         * DMA Total Transfer Count
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATOTCOUNT_t : reg_t<uint32_t, BASE_ADDRESS + 0x288> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x288>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFC;
            static constexpr uint32_t reset_value = 0x0;

            /// Total Transfer Count
            static constexpr bitfield_t<DMATOTCOUNT_t, 17, 2> TOTCOUNT = {};
        } DMATOTCOUNT = {};

        /**
         * DMATARGADDR - 4 bytes at offset 652
         * DMA Target Address Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATARGADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x28C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x20000000;

            /// SRAM Target
            static constexpr bitfield_t<DMATARGADDR_t, 31, 19> UTARGADDR = {};

            /// DMA Target Address
            static constexpr bitfield_t<DMATARGADDR_t, 18, 0> LTARGADDR = {};
        } DMATARGADDR = {};

        /**
         * DMASTAT - 4 bytes at offset 656
         * DMA Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMASTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x290> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x290>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error
            static constexpr bitfield_t<DMASTAT_t, 2, 2, bool> DMAERR = {};

            /// DMA Transfer Complete
            static constexpr bitfield_t<DMASTAT_t, 1, 1, bool> DMACPL = {};

            /// DMA Transfer In Progress
            static constexpr bitfield_t<DMASTAT_t, 0, 0, bool> DMATIP = {};
        } DMASTAT = {};
    };  // end of struct ADC_t

} // namespace sfr