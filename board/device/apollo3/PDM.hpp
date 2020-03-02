/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: PDM
 * PDM Audio
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace PDM {
    
        /// Right channel PGA gain.
        enum class PGARIGHTv : uint32_t {
            P405DB = 0x1F, //< 40.5 db gain.
            P390DB = 0x1E, //< 39.0 db gain.
            P375DB = 0x1D, //< 37.5 db gain.
            P360DB = 0x1C, //< 36.0 db gain.
            P345DB = 0x1B, //< 34.5 db gain.
            P330DB = 0x1A, //< 33.0 db gain.
            P315DB = 0x19, //< 31.5 db gain.
            P300DB = 0x18, //< 30.0 db gain.
            P285DB = 0x17, //< 28.5 db gain.
            P270DB = 0x16, //< 27.0 db gain.
            P255DB = 0x15, //< 25.5 db gain.
            P240DB = 0x14, //< 24.0 db gain.
            P225DB = 0x13, //< 22.5 db gain.
            P210DB = 0x12, //< 21.0 db gain.
            P195DB = 0x11, //< 19.5 db gain.
            P180DB = 0x10, //< 18.0 db gain.
            P165DB = 0xF, //< 16.5 db gain.
            P150DB = 0xE, //< 15.0 db gain.
            P135DB = 0xD, //< 13.5 db gain.
            P120DB = 0xC, //< 12.0 db gain.
            P105DB = 0xB, //< 10.5 db gain.
            P90DB = 0xA, //< 9.0 db gain.
            P75DB = 0x9, //< 7.5 db gain.
            P60DB = 0x8, //< 6.0 db gain.
            P45DB = 0x7, //< 4.5 db gain.
            P30DB = 0x6, //< 3.0 db gain.
            P15DB = 0x5, //< 1.5 db gain.
            v0DB = 0x4, //< 0.0 db gain.
            M15DB = 0x3, //< -1.5 db gain.
            M300DB = 0x2, //< -3.0 db gain.
            M45DB = 0x1, //< -4.5 db gain.
            M60DB = 0x0, //< -6.0 db gain.
        };
    
        /// Left channel PGA gain.
        enum class PGALEFTv : uint32_t {
            P405DB = 0x1F, //< 40.5 db gain.
            P390DB = 0x1E, //< 39.0 db gain.
            P375DB = 0x1D, //< 37.5 db gain.
            P360DB = 0x1C, //< 36.0 db gain.
            P345DB = 0x1B, //< 34.5 db gain.
            P330DB = 0x1A, //< 33.0 db gain.
            P315DB = 0x19, //< 31.5 db gain.
            P300DB = 0x18, //< 30.0 db gain.
            P285DB = 0x17, //< 28.5 db gain.
            P270DB = 0x16, //< 27.0 db gain.
            P255DB = 0x15, //< 25.5 db gain.
            P240DB = 0x14, //< 24.0 db gain.
            P225DB = 0x13, //< 22.5 db gain.
            P210DB = 0x12, //< 21.0 db gain.
            P195DB = 0x11, //< 19.5 db gain.
            P180DB = 0x10, //< 18.0 db gain.
            P165DB = 0xF, //< 16.5 db gain.
            P150DB = 0xE, //< 15.0 db gain.
            P135DB = 0xD, //< 13.5 db gain.
            P120DB = 0xC, //< 12.0 db gain.
            P105DB = 0xB, //< 10.5 db gain.
            P90DB = 0xA, //< 9.0 db gain.
            P75DB = 0x9, //< 7.5 db gain.
            P60DB = 0x8, //< 6.0 db gain.
            P45DB = 0x7, //< 4.5 db gain.
            P30DB = 0x6, //< 3.0 db gain.
            P15DB = 0x5, //< 1.5 db gain.
            v0DB = 0x4, //< 0.0 db gain.
            M15DB = 0x3, //< -1.5 db gain.
            M300DB = 0x2, //< -3.0 db gain.
            M45DB = 0x1, //< -4.5 db gain.
            M60DB = 0x0, //< -6.0 db gain.
        };
    
        /// PDM_CLK frequency divisor.
        enum class MCLKDIVv : uint32_t {
            MCKDIV4 = 0x3, //< Divide input clock by 4
            MCKDIV3 = 0x2, //< Divide input clock by 3
            MCKDIV2 = 0x1, //< Divide input clock by 2
            MCKDIV1 = 0x0, //< Divide input clock by 1
        };
    
        /// Select the PDM input clock.
        enum class PDMCLKSELv : uint32_t {
            DISABLE = 0x0, //< Static value.
            v12MHz = 0x1, //< PDM clock is 12 MHz.
            v6MHz = 0x2, //< PDM clock is 6 MHz.
            v3MHz = 0x3, //< PDM clock is 3 MHz.
            v1_5MHz = 0x4, //< PDM clock is 1.5 MHz.
            v750KHz = 0x5, //< PDM clock is 750 KHz.
            v375KHz = 0x6, //< PDM clock is 375 KHz.
            v187KHz = 0x7, //< PDM clock is 187.5 KHz.
        };
    
        /// Set PCM channels.
        enum class CHSETv : uint32_t {
            DIS = 0x0, //< Channel disabled.
            LEFT = 0x1, //< Mono left channel.
            RIGHT = 0x2, //< Mono right channel.
            STEREO = 0x3, //< Stereo channels.
        };
    
    }   // namespace PDM

    /// PDM Audio
    template <addressType BASE_ADDRESS>
    struct PDM_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * PCFG - 4 bytes at offset 0
         * PDM Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFE7FFFF;
            static constexpr uint32_t reset_value = 0xC365;

            /// Left/right channel swap.
            static constexpr bitfield_t<PCFG_t, 31, 31, bool> LRSWAP = {};

            /// Right channel PGA gain.
            static constexpr bitfield_t<PCFG_t, 30, 26, PDM::PGARIGHTv> PGARIGHT = {};

            /// Left channel PGA gain.
            static constexpr bitfield_t<PCFG_t, 25, 21, PDM::PGALEFTv> PGALEFT = {};

            /// PDM_CLK frequency divisor.
            static constexpr bitfield_t<PCFG_t, 18, 17, PDM::MCLKDIVv> MCLKDIV = {};

            /// SINC decimation rate.
            static constexpr bitfield_t<PCFG_t, 16, 10> SINCRATE = {};

            /// High pass filter control.
            static constexpr bitfield_t<PCFG_t, 9, 9, bool> ADCHPD = {};

            /// High pass filter coefficients.
            static constexpr bitfield_t<PCFG_t, 8, 5> HPCUTOFF = {};

            /// Number of clocks during gain-setting changes.
            static constexpr bitfield_t<PCFG_t, 4, 2> CYCLES = {};

            /// Soft mute control.
            static constexpr bitfield_t<PCFG_t, 1, 1, bool> SOFTMUTE = {};

            /// Data Streaming Control.
            static constexpr bitfield_t<PCFG_t, 0, 0, bool> PDMCOREEN = {};
        } PCFG = {};

        /**
         * VCFG - 4 bytes at offset 4
         * Voice Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct VCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFC1B0118;
            static constexpr uint32_t reset_value = 0x8;

            /// Enable the IO clock.
            static constexpr bitfield_t<VCFG_t, 31, 31, bool> IOCLKEN = {};

            /// Reset the IP core.
            static constexpr bitfield_t<VCFG_t, 30, 30, bool> RSTB = {};

            /// Select the PDM input clock.
            static constexpr bitfield_t<VCFG_t, 29, 27, PDM::PDMCLKSELv> PDMCLKSEL = {};

            /// Enable the serial clock.
            static constexpr bitfield_t<VCFG_t, 26, 26, bool> PDMCLKEN = {};

            /// I2S interface enable.
            static constexpr bitfield_t<VCFG_t, 20, 20, bool> I2SEN = {};

            /// I2S BCLK input inversion.
            static constexpr bitfield_t<VCFG_t, 19, 19, bool> BCLKINV = {};

            /// PDM clock sampling delay.
            static constexpr bitfield_t<VCFG_t, 17, 17, bool> DMICKDEL = {};

            /// Select PDM input clock source.
            static constexpr bitfield_t<VCFG_t, 16, 16, bool> SELAP = {};

            /// PCM data packing enable.
            static constexpr bitfield_t<VCFG_t, 8, 8, bool> PCMPACK = {};

            /// Set PCM channels.
            static constexpr bitfield_t<VCFG_t, 4, 3, PDM::CHSETv> CHSET = {};
        } VCFG = {};

        /**
         * VOICESTAT - 4 bytes at offset 8
         * Voice Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct VOICESTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x0;

            /// Valid 32-bit entries currently in the FIFO.
            static constexpr bitfield_t<VOICESTAT_t, 5, 0> FIFOCNT = {};
        } VOICESTAT = {};

        /**
         * FIFOREAD - 4 bytes at offset 12
         * FIFO Read
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOREAD_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO read data.
            static constexpr bitfield_t<FIFOREAD_t, 31, 0> FIFOREAD = {};
        } FIFOREAD = {};

        /**
         * FIFOFLUSH - 4 bytes at offset 16
         * FIFO Flush
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOFLUSH_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0x1;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO FLUSH.
            static constexpr bitfield_t<FIFOFLUSH_t, 0, 0, bool> FIFOFLUSH = {};
        } FIFOFLUSH = {};

        /**
         * FIFOTHR - 4 bytes at offset 20
         * FIFO Threshold
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOTHR_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x10;

            /// FIFO Threshold value.   When the FIFO count is equal to, or larger than this value (in words), a THR interrupt is generated (if enabled)
            static constexpr bitfield_t<FIFOTHR_t, 4, 0> FIFOTHR = {};
        } FIFOTHR = {};

        /**
         * INTEN - 4 bytes at offset 512
         * IO Master Interrupts: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error receieved
            static constexpr bitfield_t<INTEN_t, 4, 4, bool> DERR = {};

            /// DMA completed a transfer
            static constexpr bitfield_t<INTEN_t, 3, 3, bool> DCMP = {};

            /// This is the FIFO underflow interrupt.
            static constexpr bitfield_t<INTEN_t, 2, 2, bool> UNDFL = {};

            /// This is the FIFO overflow interrupt.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> OVF = {};

            /// This is the FIFO threshold interrupt.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> THR = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * IO Master Interrupts: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error receieved
            static constexpr bitfield_t<INTSTAT_t, 4, 4, bool> DERR = {};

            /// DMA completed a transfer
            static constexpr bitfield_t<INTSTAT_t, 3, 3, bool> DCMP = {};

            /// This is the FIFO underflow interrupt.
            static constexpr bitfield_t<INTSTAT_t, 2, 2, bool> UNDFL = {};

            /// This is the FIFO overflow interrupt.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> OVF = {};

            /// This is the FIFO threshold interrupt.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> THR = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * IO Master Interrupts: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error receieved
            static constexpr bitfield_t<INTCLR_t, 4, 4, bool> DERR = {};

            /// DMA completed a transfer
            static constexpr bitfield_t<INTCLR_t, 3, 3, bool> DCMP = {};

            /// This is the FIFO underflow interrupt.
            static constexpr bitfield_t<INTCLR_t, 2, 2, bool> UNDFL = {};

            /// This is the FIFO overflow interrupt.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> OVF = {};

            /// This is the FIFO threshold interrupt.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> THR = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * IO Master Interrupts: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA Error receieved
            static constexpr bitfield_t<INTSET_t, 4, 4, bool> DERR = {};

            /// DMA completed a transfer
            static constexpr bitfield_t<INTSET_t, 3, 3, bool> DCMP = {};

            /// This is the FIFO underflow interrupt.
            static constexpr bitfield_t<INTSET_t, 2, 2, bool> UNDFL = {};

            /// This is the FIFO overflow interrupt.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> OVF = {};

            /// This is the FIFO threshold interrupt.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> THR = {};
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

            /// Trigger DMA at FIFO 90 percent full.  This signal is also used internally for AUTOHIP function
            static constexpr bitfield_t<DMATRIGEN_t, 1, 1, bool> DTHR90 = {};

            /// Trigger DMA upon when FIFO iss filled to level indicated by the FIFO THRESHOLD,at granularity of 16 bytes only
            static constexpr bitfield_t<DMATRIGEN_t, 0, 0, bool> DTHR = {};
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

            /// Triggered DMA from FIFO reaching 90 percent full
            static constexpr bitfield_t<DMATRIGSTAT_t, 1, 1, bool> DTHR90STAT = {};

            /// Triggered DMA from FIFO reaching threshold
            static constexpr bitfield_t<DMATRIGSTAT_t, 0, 0, bool> DTHRSTAT = {};
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
            static constexpr uint32_t reset_mask  = 0x705;
            static constexpr uint32_t reset_value = 0x0;

            /// Power Off the ADC System upon DMACPL.
            static constexpr bitfield_t<DMACFG_t, 10, 10, bool> DPWROFF = {};

            /// Raise priority to high on fifo full, and DMAPRI set to low
            static constexpr bitfield_t<DMACFG_t, 9, 9, bool> DAUTOHIP = {};

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
            static constexpr uint32_t reset_mask  = 0xFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Total Transfer Count. The transfer count must be a multiple of the THR setting to avoid DMA overruns.
            static constexpr bitfield_t<DMATOTCOUNT_t, 19, 0> TOTCOUNT = {};
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
            static constexpr uint32_t reset_value = 0x10000000;

            /// SRAM Target
            static constexpr bitfield_t<DMATARGADDR_t, 31, 20> UTARGADDR = {};

            /// DMA Target Address. This register is not updated with the current address of the DMA, but will remain static with the original address during the DMA transfer.
            static constexpr bitfield_t<DMATARGADDR_t, 19, 0> LTARGADDR = {};
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
    };  // end of struct PDM_t

} // namespace sfr