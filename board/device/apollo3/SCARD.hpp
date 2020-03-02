/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: SCARD
 * Serial ISO7816
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace SCARD {
    
    }   // namespace SCARD

    /// Serial ISO7816
    template <addressType BASE_ADDRESS>
    struct SCARD_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * SR - 4 bytes at offset 0
         * ISO7816 interrupt status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SR_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x7F;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO Half Full.
            static constexpr bitfield_t<SR_t, 6, 6, bool> FHF = {};

            /// TX to RX finished.
            static constexpr bitfield_t<SR_t, 5, 5, bool> FT2REND = {};

            /// Parity Error.
            static constexpr bitfield_t<SR_t, 4, 4, bool> PE = {};

            /// RX FIFO overflow.
            static constexpr bitfield_t<SR_t, 3, 3, bool> OVR = {};

            /// Framing error.
            static constexpr bitfield_t<SR_t, 2, 2, bool> FER = {};

            /// FIFO empty (transmit) or full (receive).
            static constexpr bitfield_t<SR_t, 1, 1, bool> TBERBF = {};

            /// RX FIFO not empty.
            static constexpr bitfield_t<SR_t, 0, 0, bool> FNE = {};
        } SR = {};

        /**
         * IER - 4 bytes at offset 4
         * ISO7816 interrupt enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IER_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x7F;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO Half Full interrupt enable.
            static constexpr bitfield_t<IER_t, 6, 6, bool> FHFEN = {};

            /// TX to RX finished interrupt enable.
            static constexpr bitfield_t<IER_t, 5, 5, bool> FT2RENDEN = {};

            /// Parity Error interrupt enable.
            static constexpr bitfield_t<IER_t, 4, 4, bool> PEEN = {};

            /// RX FIFOI overflow interrupt enable.
            static constexpr bitfield_t<IER_t, 3, 3, bool> OVREN = {};

            /// Framing error interrupt enable.
            static constexpr bitfield_t<IER_t, 2, 2, bool> FEREN = {};

            /// FIFO empty (transmit) or full (receive) interrupt enable.
            static constexpr bitfield_t<IER_t, 1, 1, bool> TBERBFEN = {};

            /// RX FIFO not empty interrupt enable.
            static constexpr bitfield_t<IER_t, 0, 0, bool> FNEEN = {};
        } IER = {};

        /**
         * TCR - 4 bytes at offset 8
         * ISO7816 transmit control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TCR_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x2;

            /// DMA direction.
            static constexpr bitfield_t<TCR_t, 7, 7, bool> DMAMD = {};

            /// Parity select.
            static constexpr bitfield_t<TCR_t, 6, 6, bool> FIP = {};

            /// Automatic conversion.
            static constexpr bitfield_t<TCR_t, 5, 5, bool> AUTOCONV = {};

            /// PROT control.
            static constexpr bitfield_t<TCR_t, 4, 4, bool> PROT = {};

            /// Transmit/receive mode.
            static constexpr bitfield_t<TCR_t, 3, 3, bool> TR = {};

            /// Fast TX to RX.
            static constexpr bitfield_t<TCR_t, 2, 2, bool> LCT = {};

            /// Use first byte to configure conversion.
            static constexpr bitfield_t<TCR_t, 1, 1, bool> SS = {};

            /// Conversion inversion control.
            static constexpr bitfield_t<TCR_t, 0, 0, bool> CONV = {};
        } TCR = {};

        /**
         * UCR - 4 bytes at offset 12
         * ISO7816 user control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct UCR_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x8;

            /// Enable TX/RX time configuration.
            static constexpr bitfield_t<UCR_t, 3, 3, bool> RETXEN = {};

            /// Reset polarity.
            static constexpr bitfield_t<UCR_t, 2, 2, bool> RSTIN = {};

            /// ISO7816 reset.  This bit is write-only.
            static constexpr bitfield_t<UCR_t, 1, 1, bool> RIU = {};

            /// Clock control.
            static constexpr bitfield_t<UCR_t, 0, 0, bool> CST = {};
        } UCR = {};

        /**
         * DR - 4 bytes at offset 16
         * ISO7816 data
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DR_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Data register.
            static constexpr bitfield_t<DR_t, 7, 0> DR = {};
        } DR = {};

        /**
         * BPRL - 4 bytes at offset 20
         * ISO7816 baud rate low
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BPRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x74;

            /// Baud rate low
            static constexpr bitfield_t<BPRL_t, 7, 0> BPRL = {};
        } BPRL = {};

        /**
         * BPRH - 4 bytes at offset 24
         * ISO7816 baud rate high
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BPRH_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x1;

            /// Baud rate high
            static constexpr bitfield_t<BPRH_t, 3, 0> BPRH = {};
        } BPRH = {};

        /**
         * UCR1 - 4 bytes at offset 28
         * ISO7816 user control 1
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct UCR1_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3D;
            static constexpr uint32_t reset_value = 0x30;

            /// Enable last byte function.
            static constexpr bitfield_t<UCR1_t, 5, 5, bool> ENLASTB = {};

            /// Output clock level.
            static constexpr bitfield_t<UCR1_t, 4, 4, bool> CLKIOV = {};

            /// Parity check control.
            static constexpr bitfield_t<UCR1_t, 3, 3, bool> T1PAREN = {};

            /// ETU counter control.  This bit is write-only.
            static constexpr bitfield_t<UCR1_t, 2, 2, bool> STSP = {};

            /// Query Card Detect.
            static constexpr bitfield_t<UCR1_t, 0, 0, bool> PR = {};
        } UCR1 = {};

        /**
         * SR1 - 4 bytes at offset 32
         * ISO7816 interrupt status 1
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SR1_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x8;

            /// ISO7816 idle.
            static constexpr bitfield_t<SR1_t, 3, 3, bool> IDLE = {};

            /// Write complete synchronization.
            static constexpr bitfield_t<SR1_t, 2, 2, bool> SYNCEND = {};

            /// Card insert/remove.
            static constexpr bitfield_t<SR1_t, 1, 1, bool> PRL = {};

            /// ETU counter overflow.
            static constexpr bitfield_t<SR1_t, 0, 0, bool> ECNTOVER = {};
        } SR1 = {};

        /**
         * IER1 - 4 bytes at offset 36
         * ISO7816 interrupt enable 1
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IER1_t : reg_t<uint32_t, BASE_ADDRESS + 0x24> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x24>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// Write complete synchronization interrupt enable.
            static constexpr bitfield_t<IER1_t, 2, 2, bool> SYNCENDEN = {};

            /// Card insert/remove interrupt enable.
            static constexpr bitfield_t<IER1_t, 1, 1, bool> PRLEN = {};

            /// ETU counter overflow interrupt enable.
            static constexpr bitfield_t<IER1_t, 0, 0, bool> ECNTOVEREN = {};
        } IER1 = {};

        /**
         * ECNTL - 4 bytes at offset 40
         * ETU counter low
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ECNTL_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// ETU counter low register.
            static constexpr bitfield_t<ECNTL_t, 7, 0> ECNTL = {};
        } ECNTL = {};

        /**
         * ECNTH - 4 bytes at offset 44
         * ETU counter high
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ECNTH_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// ETU counter high register.
            static constexpr bitfield_t<ECNTH_t, 7, 0> ECNTH = {};
        } ECNTH = {};

        /**
         * GTR - 4 bytes at offset 48
         * ISO7816 guard time configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct GTR_t : reg_t<uint32_t, BASE_ADDRESS + 0x30> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0xFF;

            /// Guard time configuration register.
            static constexpr bitfield_t<GTR_t, 7, 0> GTR = {};
        } GTR = {};

        /**
         * RETXCNT - 4 bytes at offset 52
         * ISO7816 resend count
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RETXCNT_t : reg_t<uint32_t, BASE_ADDRESS + 0x34> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x34>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x4;

            /// Resend count register.
            static constexpr bitfield_t<RETXCNT_t, 3, 0> RETXCNT = {};
        } RETXCNT = {};

        /**
         * RETXCNTRMI - 4 bytes at offset 56
         * ISO7816 resent count inquiry
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RETXCNTRMI_t : reg_t<uint32_t, BASE_ADDRESS + 0x38> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x38>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// Resent count inquiry register.
            static constexpr bitfield_t<RETXCNTRMI_t, 3, 0> RETXCNTRMI = {};
        } RETXCNTRMI = {};

        /**
         * CLKCTRL - 4 bytes at offset 256
         * Clock Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLKCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// Enable the SCARD APB clock to run continuously.
            static constexpr bitfield_t<CLKCTRL_t, 1, 1, bool> APBCLKEN = {};

            /// Enable the serial source clock for SCARD.
            static constexpr bitfield_t<CLKCTRL_t, 0, 0, bool> CLKEN = {};
        } CLKCTRL = {};
    };  // end of struct SCARD_t

} // namespace sfr