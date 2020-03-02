/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: CLKGEN
 * Clock Generator
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace CLKGEN {
    
        /// Autocalibration control.  This selects the source to be used in the autocalibration flow.  This flow can also be used to measure an internal clock against an external clock source, with the external clock normally used as the reference.
        enum class ACALv : uint32_t {
            DIS = 0x0, //< Disable Autocalibration
            v1024SEC = 0x2, //< Autocalibrate every 1024 seconds.  Once autocalibration is done, an interrupt will be triggered at the end of 1024 seconds.
            v512SEC = 0x3, //< Autocalibrate every 512 seconds.  Once autocalibration is done, an interrupt will be trigged at the end of 512 seconds.
            XTFREQ = 0x6, //< Frequency measurement using XT.  The XT clock is normally considered much more accurate than the LFRC clock source.
            EXTFREQ = 0x7, //< Frequency measurement using external clock.
        };
    
        /// CLKOUT signal select
        enum class CKSELv : uint32_t {
            LFRC = 0x0, //< LFRC
            XT_DIV2 = 0x1, //< XT / 2
            XT_DIV4 = 0x2, //< XT / 4
            XT_DIV8 = 0x3, //< XT / 8
            XT_DIV16 = 0x4, //< XT / 16
            XT_DIV32 = 0x5, //< XT / 32
            RTC_1Hz = 0x10, //< 1 Hz as selected in RTC
            XT_DIV2M = 0x16, //< XT / 2^21
            XT = 0x17, //< XT
            CG_100Hz = 0x18, //< 100 Hz as selected in CLKGEN
            HFRC = 0x19, //< HFRC
            HFRC_DIV4 = 0x1A, //< HFRC / 4
            HFRC_DIV8 = 0x1B, //< HFRC / 8
            HFRC_DIV16 = 0x1C, //< HFRC / 16
            HFRC_DIV64 = 0x1D, //< HFRC / 64
            HFRC_DIV128 = 0x1E, //< HFRC / 128
            HFRC_DIV256 = 0x1F, //< HFRC / 256
            HFRC_DIV512 = 0x20, //< HFRC / 512
            FLASH_CLK = 0x22, //< Flash Clock
            LFRC_DIV2 = 0x23, //< LFRC / 2
            LFRC_DIV32 = 0x24, //< LFRC / 32
            LFRC_DIV512 = 0x25, //< LFRC / 512
            LFRC_DIV32K = 0x26, //< LFRC / 32768
            XT_DIV256 = 0x27, //< XT / 256
            XT_DIV8K = 0x28, //< XT / 8192
            XT_DIV64K = 0x29, //< XT / 2^16
            ULFRC_DIV16 = 0x2A, //< Uncal LFRC / 16
            ULFRC_DIV128 = 0x2B, //< Uncal LFRC / 128
            ULFRC_1Hz = 0x2C, //< Uncal LFRC / 1024
            ULFRC_DIV4K = 0x2D, //< Uncal LFRC / 4096
            ULFRC_DIV1M = 0x2E, //< Uncal LFRC / 2^20
            HFRC_DIV64K = 0x2F, //< HFRC / 2^16
            HFRC_DIV16M = 0x30, //< HFRC / 2^24
            LFRC_DIV1M = 0x31, //< LFRC / 2^20
            HFRCNE = 0x32, //< HFRC (not autoenabled)
            HFRCNE_DIV8 = 0x33, //< HFRC / 8 (not autoenabled)
            XTNE = 0x35, //< XT (not autoenabled)
            XTNE_DIV16 = 0x36, //< XT / 16 (not autoenabled)
            LFRCNE_DIV32 = 0x37, //< LFRC / 32 (not autoenabled)
            LFRCNE = 0x39, //< LFRC (not autoenabled) - Default for undefined values
        };
    
        /// Key register value.
        enum class CLKKEYv : uint32_t {
            Key = 0x47, //< Key
        };
    
        /// Gain control for HFRC adjustment
        enum class HFADJGAINv : uint32_t {
            Gain_of_1 = 0x0, //< HF Adjust with Gain of 1
            Gain_of_1_in_2 = 0x1, //< HF Adjust with Gain of 0.5
            Gain_of_1_in_4 = 0x2, //< HF Adjust with Gain of 0.25
            Gain_of_1_in_8 = 0x3, //< HF Adjust with Gain of 0.125
            Gain_of_1_in_16 = 0x4, //< HF Adjust with Gain of 0.0625
            Gain_of_1_in_32 = 0x5, //< HF Adjust with Gain of 0.03125
        };
    
        /// Repeat period for HFRC adjustment
        enum class HFADJCKv : uint32_t {
            v4SEC = 0x0, //< Autoadjust repeat period = 4 seconds
            v16SEC = 0x1, //< Autoadjust repeat period = 16 seconds
            v32SEC = 0x2, //< Autoadjust repeat period = 32 seconds
            v64SEC = 0x3, //< Autoadjust repeat period = 64 seconds
            v128SEC = 0x4, //< Autoadjust repeat period = 128 seconds
            v256SEC = 0x5, //< Autoadjust repeat period = 256 seconds
            v512SEC = 0x6, //< Autoadjust repeat period = 512 seconds
            v1024SEC = 0x7, //< Autoadjust repeat period = 1024 seconds
        };
    
        /// Clock enable status
        enum class CLOCKENSTATv : uint32_t {
            ADC_CLKEN = 0x1, //< Clock enable for the ADC.
            APBDMA_ACTIVITY_CLKEN = 0x2, //< Clock enable for the APBDMA ACTIVITY
            APBDMA_AOH_CLKEN = 0x4, //< Clock enable for the APBDMA AOH DOMAIN
            APBDMA_AOL_CLKEN = 0x8, //< Clock enable for the APBDMA AOL DOMAIN
            APBDMA_APB_CLKEN = 0x10, //< Clock enable for the APBDMA_APB
            APBDMA_BLEL_CLKEN = 0x20, //< Clock enable for the APBDMA_BLEL
            APBDMA_HCPA_CLKEN = 0x40, //< Clock enable for the APBDMA_HCPA
            APBDMA_HCPB_CLKEN = 0x80, //< Clock enable for the APBDMA_HCPB
            APBDMA_HCPC_CLKEN = 0x100, //< Clock enable for the APBDMA_HCPC
            APBDMA_MSPI_CLKEN = 0x200, //< Clock enable for the APBDMA_MSPI
            APBDMA_PDM_CLKEN = 0x400, //< Clock enable for the APBDMA_PDM
            BLEIF_CLK_CLKEN = 0x800, //< Clock enable for the BLEIF
            BLEIF_CLK32K_CLKEN = 0x1000, //< Clock enable for the BLEIF 32khZ CLOCK
            CTIMER_CLKEN = 0x2000, //< Clock enable for the CTIMER BLOCK
            CTIMER0A_CLKEN = 0x4000, //< Clock enable for the CTIMER0A
            CTIMER0B_CLKEN = 0x8000, //< Clock enable for the CTIMER0B
            CTIMER1A_CLKEN = 0x10000, //< Clock enable for the CTIMER1A
            CTIMER1B_CLKEN = 0x20000, //< Clock enable for the CTIMER1B
            CTIMER2A_CLKEN = 0x40000, //< Clock enable for the CTIMER2A
            CTIMER2B_CLKEN = 0x80000, //< Clock enable for the CTIMER2B
            CTIMER3A_CLKEN = 0x100000, //< Clock enable for the CTIMER3A
            CTIMER3B_CLKEN = 0x200000, //< Clock enable for the CTIMER3B
            CTIMER4A_CLKEN = 0x400000, //< Clock enable for the CTIMER4A
            CTIMER4B_CLKEN = 0x800000, //< Clock enable for the CTIMER4B
            CTIMER5A_CLKEN = 0x1000000, //< Clock enable for the CTIMER5A
            CTIMER5B_CLKEN = 0x2000000, //< Clock enable for the CTIMER5B
            CTIMER6A_CLKEN = 0x4000000, //< Clock enable for the CTIMER6A
            CTIMER6B_CLKEN = 0x8000000, //< Clock enable for the CTIMER6B
            CTIMER7A_CLKEN = 0x10000000, //< Clock enable for the CTIMER7A
            CTIMER7B_CLKEN = 0x20000000, //< Clock enable for the CTIMER7B
            DAP_CLKEN = 0x40000000, //< Clock enable for the DAP
            IOMSTRIFC0_CLKEN = 0x80000000, //< Clock enable for the IOMSTRIFC0
        };
    
        /// Clock enable status 2
        enum class CLOCKEN2STATv : uint32_t {
            IOMSTRIFC1_CLKEN = 0x1, //< Clock enable for the IO MASTER 1 IFC INTERFACE
            IOMSTRIFC2_CLKEN = 0x2, //< Clock enable for the IO MASTER 2 IFC INTERFACE
            IOMSTRIFC3_CLKEN = 0x4, //< Clock enable for the IO MASTER 3 IFC INTERFACE
            IOMSTRIFC4_CLKEN = 0x8, //< Clock enable for the IO MASTER 4 IFC INTERFACE
            IOMSTRIFC5_CLKEN = 0x10, //< Clock enable for the IO MASTER 5 IFC INTERFACE
            PDM_CLKEN = 0x20, //< Clock enable for the PDM
            PDMIFC_CLKEN = 0x40, //< Clock enable for the PDM INTERFACE
            PWRCTRL_CLKEN = 0x80, //< Clock enable for the PWRCTRL
            PWRCTRL_COUNT_CLKEN = 0x100, //< Clock enable for the PWRCTRL counter
            RSTGEN_CLKEN = 0x200, //< Clock enable for the RSTGEN
            SCARD_CLKEN = 0x400, //< Clock enable for the SCARD
            SCARD_ALTAPB_CLKEN = 0x800, //< Clock enable for the SCARD ALTAPB
            STIMER_CNT_CLKEN = 0x1000, //< Clock enable for the STIMER_CNT_CLKEN
            TPIU_CLKEN = 0x2000, //< Clock enable for the TPIU_CLKEN
            UART0HF_CLKEN = 0x4000, //< Clock enable for the UART0 HF
            UART1HF_CLKEN = 0x8000, //< Clock enable for the UART1 HF
            XT_32KHZ_EN = 0x40000000, //< Clock enable for the XT 32KHZ
            FORCEHFRC = 0x80000000, //< HFRC is forced on Status.
        };
    
        /// Clock enable status 3
        enum class CLOCKEN3STATv : uint32_t {
            DAP_enabled = 0x20000, //< DAP clock is enabled [17]
            VCOMP_enabled = 0x40000, //< VCOMP powerdown indicator [18]
            XTAL_enabled = 0x1000000, //< XTAL is enabled [24]
            HFRC_enabled = 0x2000000, //< HFRC is enabled [25]
            HFADJEN = 0x4000000, //< HFRC Adjust enabled [26]
            HFRC_en_out = 0x8000000, //< HFRC Enabled out [27]
            RTC_XT = 0x10000000, //< RTC use XT [28]
            clkout_xtal_en = 0x20000000, //< XTAL clkout enabled [29]
            clkout_hfrc_en = 0x40000000, //< HFRC clkout enabled [30]
            flashclk_en = 0x80000000, //< Flash clk is enabled [31]
        };
    
        /// BLEBUCK ZERO LENGTH DETECT TRIM
        enum class ZEROLENDETECTTRIMv : uint32_t {
            SetF = 0xF, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 81us (10 percent margin of error) or more
            SetE = 0xE, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 75.6us (10 percent margin of error) or more
            SetD = 0xD, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 70.2us (10 percent margin of error) or more
            SetC = 0xC, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 64.8us (10 percent margin of error) or more
            SetB = 0xB, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 59.4us (10 percent margin of error) or more
            SetA = 0xA, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 54.0us (10 percent margin of error) or more
            Set9 = 0x9, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 48.6us (10 percent margin of error) or more
            Set8 = 0x8, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 43.2us (10 percent margin of error) or more
            Set7 = 0x7, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 37.8us (10 percent margin of error) or more
            Set6 = 0x6, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 32.4us (10 percent margin of error) or more
            Set5 = 0x5, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 27.0us (10 percent margin of error) or more
            Set4 = 0x4, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 21.6us (10 percent margin of error) or more
            Set3 = 0x3, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 16.2us (10 percent margin of error) or more
            Set2 = 0x2, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 10.8us (10 percent margin of error) or more
            Set1 = 0x1, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 5.4us (10 percent margin of error) or more
            Set0 = 0x0, //< Indicator send when the BLE BUCK asserts blebuck_comp1 for about 2.0us (10 percent margin of error) or more
        };
    
        /// TON ADJUST PERIOD
        enum class TONADJUSTPERIODv : uint32_t {
            HFRC_3KHz = 0x3, //< Adjust done for every 1 3KHz period
            HFRC_12KHz = 0x2, //< Adjust done for every 1 12KHz period
            HFRC_47KHz = 0x1, //< Adjust done for every 1 47KHz period
            HFRC_94KHz = 0x0, //< Adjust done for every 1 94KHz period
        };
    
    }   // namespace CLKGEN

    /// Clock Generator
    template <addressType BASE_ADDRESS>
    struct CLKGEN_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CALXT - 4 bytes at offset 0
         * XT Oscillator Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CALXT_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FF;
            static constexpr uint32_t reset_value = 0x0;

            /// XT Oscillator calibration value.  This register will enable the hardware to increase or decrease the number of cycles in a 16KHz clock derived from the original 32KHz version.  The most significant bit is the sign.  A '1' is a reduction, and a '0' is an addition.  This calibration value will add or reduce the number of cycles programmed here across a 32 second interval.  The maximum value that is effective is from -1024 to 1023.
            static constexpr bitfield_t<CALXT_t, 10, 0> CALXT = {};
        } CALXT = {};

        /**
         * CALRC - 4 bytes at offset 4
         * RC Oscillator Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CALRC_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// LFRC Oscillator calibration value.   This register will enable the hardware to increase or decrease the number of cycles in a 512 Hz clock derived from the original 1024 version.  The most significant bit is the sign.  A '1' is a reduction, and a '0' is an addition.  This calibration value will add or reduce the number of cycles programmed here across a 32 second interval.  The range is from -131072 (decimal) to 131071 (decimal).  This register is normally used in conjuction with ACALCTR register.  The CALRC register will load the ACALCTR register (bits 17:0) if the ACALCTR register is set to measure the LFRC with the XT clock.
            static constexpr bitfield_t<CALRC_t, 17, 0> CALRC = {};
        } CALRC = {};

        /**
         * ACALCTR - 4 bytes at offset 8
         * Autocalibration Counter
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ACALCTR_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Autocalibration Counter result. Bits 17 down to 0 of this is feed directly to the CALRC register if ACAL register in OCTRL register is set to 1024SEC or 512SEC.
            static constexpr bitfield_t<ACALCTR_t, 23, 0> ACALCTR = {};
        } ACALCTR = {};

        /**
         * OCTRL - 4 bytes at offset 12
         * Oscillator Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7C3;
            static constexpr uint32_t reset_value = 0x0;

            /// Autocalibration control.  This selects the source to be used in the autocalibration flow.  This flow can also be used to measure an internal clock against an external clock source, with the external clock normally used as the reference.
            static constexpr bitfield_t<OCTRL_t, 10, 8, CLKGEN::ACALv> ACAL = {};

            /// Selects the RTC oscillator (1 => LFRC, 0 => XT)
            static constexpr bitfield_t<OCTRL_t, 7, 7, bool> OSEL = {};

            /// Oscillator switch on failure function.  If this is set, then LFRC clock source will switch from XT to RC.
            static constexpr bitfield_t<OCTRL_t, 6, 6, bool> FOS = {};

            /// Stop the LFRC Oscillator to the RTC
            static constexpr bitfield_t<OCTRL_t, 1, 1, bool> STOPRC = {};

            /// Stop the XT Oscillator to the RTC
            static constexpr bitfield_t<OCTRL_t, 0, 0, bool> STOPXT = {};
        } OCTRL = {};

        /**
         * CLKOUT - 4 bytes at offset 16
         * CLKOUT Frequency Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLKOUT_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0xBF;
            static constexpr uint32_t reset_value = 0x0;

            /// Enable the CLKOUT signal
            static constexpr bitfield_t<CLKOUT_t, 7, 7, bool> CKEN = {};

            /// CLKOUT signal select
            static constexpr bitfield_t<CLKOUT_t, 5, 0, CLKGEN::CKSELv> CKSEL = {};
        } CLKOUT = {};

        /**
         * CLKKEY - 4 bytes at offset 20
         * Key Register for Clock Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLKKEY_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Key register value.
            static constexpr bitfield_t<CLKKEY_t, 31, 0, CLKGEN::CLKKEYv> CLKKEY = {};
        } CLKKEY = {};

        /**
         * CCTRL - 4 bytes at offset 24
         * HFRC Clock Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x1;

            /// Core Clock divisor
            static constexpr bitfield_t<CCTRL_t, 0, 0, bool> CORESEL = {};
        } CCTRL = {};

        /**
         * STATUS - 4 bytes at offset 28
         * Clock Generator Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// XT Oscillator is enabled but not oscillating
            static constexpr bitfield_t<STATUS_t, 1, 1, bool> OSCF = {};

            /// Current RTC oscillator (1 => LFRC, 0 => XT).  After an RTC oscillator change, it may take up to 2 seconds for this field to reflect the new oscillator.
            static constexpr bitfield_t<STATUS_t, 0, 0, bool> OMODE = {};
        } STATUS = {};

        /**
         * HFADJ - 4 bytes at offset 32
         * HFRC Adjustment
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct HFADJ_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF0F;
            static constexpr uint32_t reset_value = 0x25B800;

            /// Gain control for HFRC adjustment
            static constexpr bitfield_t<HFADJ_t, 23, 21, CLKGEN::HFADJGAINv> HFADJGAIN = {};

            /// XT warmup period for HFRC adjustment
            static constexpr bitfield_t<HFADJ_t, 20, 20, bool> HFWARMUP = {};

            /// Target HFRC adjustment value.
            static constexpr bitfield_t<HFADJ_t, 19, 8> HFXTADJ = {};

            /// Repeat period for HFRC adjustment
            static constexpr bitfield_t<HFADJ_t, 3, 1, CLKGEN::HFADJCKv> HFADJCK = {};

            /// HFRC adjustment control
            static constexpr bitfield_t<HFADJ_t, 0, 0, bool> HFADJEN = {};
        } HFADJ = {};

        /**
         * CLOCKENSTAT - 4 bytes at offset 40
         * Clock Enable Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLOCKENSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clock enable status
            static constexpr bitfield_t<CLOCKENSTAT_t, 31, 0, CLKGEN::CLOCKENSTATv> CLOCKENSTAT = {};
        } CLOCKENSTAT = {};

        /**
         * CLOCKEN2STAT - 4 bytes at offset 44
         * Clock Enable Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLOCKEN2STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clock enable status 2
            static constexpr bitfield_t<CLOCKEN2STAT_t, 31, 0, CLKGEN::CLOCKEN2STATv> CLOCKEN2STAT = {};
        } CLOCKEN2STAT = {};

        /**
         * CLOCKEN3STAT - 4 bytes at offset 48
         * Clock Enable Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLOCKEN3STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x30> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clock enable status 3
            static constexpr bitfield_t<CLOCKEN3STAT_t, 31, 0, CLKGEN::CLOCKEN3STATv> CLOCKEN3STAT = {};
        } CLOCKEN3STAT = {};

        /**
         * FREQCTRL - 4 bytes at offset 52
         * HFRC Frequency Control register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FREQCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x34> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x34>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// This represents frequency burst status.
            static constexpr bitfield_t<FREQCTRL_t, 2, 2, bool> BURSTSTATUS = {};

            /// Frequency Burst Request Acknowledge. Frequency burst requested is always acknowledged whether burst is granted or not depending on feature enable.
            static constexpr bitfield_t<FREQCTRL_t, 1, 1, bool> BURSTACK = {};

            /// Frequency Burst Enable Request
            static constexpr bitfield_t<FREQCTRL_t, 0, 0, bool> BURSTREQ = {};
        } FREQCTRL = {};

        /**
         * BLEBUCKTONADJ - 4 bytes at offset 60
         * BLE BUCK TON ADJUST
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BLEBUCKTONADJ_t : reg_t<uint32_t, BASE_ADDRESS + 0x3C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// BLEBUCK ZERO LENGTH DETECT ENABLE
            static constexpr bitfield_t<BLEBUCKTONADJ_t, 27, 27, bool> ZEROLENDETECTEN = {};

            /// BLEBUCK ZERO LENGTH DETECT TRIM
            static constexpr bitfield_t<BLEBUCKTONADJ_t, 26, 23, CLKGEN::ZEROLENDETECTTRIMv> ZEROLENDETECTTRIM = {};

            /// TON ADJUST ENABLE
            static constexpr bitfield_t<BLEBUCKTONADJ_t, 22, 22, bool> TONADJUSTEN = {};

            /// TON ADJUST PERIOD
            static constexpr bitfield_t<BLEBUCKTONADJ_t, 21, 20, CLKGEN::TONADJUSTPERIODv> TONADJUSTPERIOD = {};

            /// TON ADJUST HIGH THRESHOLD.  Suggested values are #15(94KHz) #2A(47Khz) #A6(12Khz) #29A(3Khz)
            static constexpr bitfield_t<BLEBUCKTONADJ_t, 19, 10> TONHIGHTHRESHOLD = {};

            /// TON ADJUST LOW THRESHOLD.  Suggested values are #A(94KHz) #15(47KHz) #53(12Khz) #14D(3Khz)
            static constexpr bitfield_t<BLEBUCKTONADJ_t, 9, 0> TONLOWTHRESHOLD = {};
        } BLEBUCKTONADJ = {};

        /**
         * INTRPTEN - 4 bytes at offset 256
         * CLKGEN Interrupt Register: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTRPTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// XT Oscillator Fail interrupt
            static constexpr bitfield_t<INTRPTEN_t, 2, 2, bool> OF = {};

            /// Autocalibration Complete interrupt
            static constexpr bitfield_t<INTRPTEN_t, 1, 1, bool> ACC = {};

            /// Autocalibration Fail interrupt
            static constexpr bitfield_t<INTRPTEN_t, 0, 0, bool> ACF = {};
        } INTRPTEN = {};

        /**
         * INTRPTSTAT - 4 bytes at offset 260
         * CLKGEN Interrupt Register: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTRPTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// XT Oscillator Fail interrupt
            static constexpr bitfield_t<INTRPTSTAT_t, 2, 2, bool> OF = {};

            /// Autocalibration Complete interrupt
            static constexpr bitfield_t<INTRPTSTAT_t, 1, 1, bool> ACC = {};

            /// Autocalibration Fail interrupt
            static constexpr bitfield_t<INTRPTSTAT_t, 0, 0, bool> ACF = {};
        } INTRPTSTAT = {};

        /**
         * INTRPTCLR - 4 bytes at offset 264
         * CLKGEN Interrupt Register: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTRPTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// XT Oscillator Fail interrupt
            static constexpr bitfield_t<INTRPTCLR_t, 2, 2, bool> OF = {};

            /// Autocalibration Complete interrupt
            static constexpr bitfield_t<INTRPTCLR_t, 1, 1, bool> ACC = {};

            /// Autocalibration Fail interrupt
            static constexpr bitfield_t<INTRPTCLR_t, 0, 0, bool> ACF = {};
        } INTRPTCLR = {};

        /**
         * INTRPTSET - 4 bytes at offset 268
         * CLKGEN Interrupt Register: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTRPTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// XT Oscillator Fail interrupt
            static constexpr bitfield_t<INTRPTSET_t, 2, 2, bool> OF = {};

            /// Autocalibration Complete interrupt
            static constexpr bitfield_t<INTRPTSET_t, 1, 1, bool> ACC = {};

            /// Autocalibration Fail interrupt
            static constexpr bitfield_t<INTRPTSET_t, 0, 0, bool> ACF = {};
        } INTRPTSET = {};
    };  // end of struct CLKGEN_t

} // namespace sfr