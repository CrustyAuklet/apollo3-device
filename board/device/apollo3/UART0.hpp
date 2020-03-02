/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: UART0
 * Serial UART
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace UART0 {
    
        /// This bitfield is the UART clock select.
        enum class CLKSELv : uint32_t {
            NOCLK = 0x0, //< No UART clock.  This is the low power default.
            v24MHZ = 0x1, //< 24 MHz clock.
            v12MHZ = 0x2, //< 12 MHz clock.
            v6MHZ = 0x3, //< 6 MHz clock.
            v3MHZ = 0x4, //< 3 MHz clock.
        };
    
    }   // namespace UART0

    /// Serial UART
    template <addressType BASE_ADDRESS>
    struct UART0_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * DR - 4 bytes at offset 0
         * UART Data Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DR_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// This is the overrun error indicator.
            static constexpr bitfield_t<DR_t, 11, 11, bool> OEDATA = {};

            /// This is the break error indicator.
            static constexpr bitfield_t<DR_t, 10, 10, bool> BEDATA = {};

            /// This is the parity error indicator.
            static constexpr bitfield_t<DR_t, 9, 9, bool> PEDATA = {};

            /// This is the framing error indicator.
            static constexpr bitfield_t<DR_t, 8, 8, bool> FEDATA = {};

            /// This is the UART data port.
            static constexpr bitfield_t<DR_t, 7, 0> DATA = {};
        } DR = {};

        /**
         * RSR - 4 bytes at offset 4
         * UART Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RSR_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// This is the overrun error indicator.
            static constexpr bitfield_t<RSR_t, 3, 3, bool> OESTAT = {};

            /// This is the break error indicator.
            static constexpr bitfield_t<RSR_t, 2, 2, bool> BESTAT = {};

            /// This is the parity error indicator.
            static constexpr bitfield_t<RSR_t, 1, 1, bool> PESTAT = {};

            /// This is the framing error indicator.
            static constexpr bitfield_t<RSR_t, 0, 0, bool> FESTAT = {};
        } RSR = {};

        /**
         * FR - 4 bytes at offset 24
         * Flag Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FR_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FF;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit holds the transmit BUSY indicator.
            static constexpr bitfield_t<FR_t, 8, 8, bool> TXBUSY = {};

            /// This bit holds the transmit FIFO empty indicator.
            static constexpr bitfield_t<FR_t, 7, 7, bool> TXFE = {};

            /// This bit holds the receive FIFO full indicator.
            static constexpr bitfield_t<FR_t, 6, 6, bool> RXFF = {};

            /// This bit holds the transmit FIFO full indicator.
            static constexpr bitfield_t<FR_t, 5, 5, bool> TXFF = {};

            /// This bit holds the receive FIFO empty indicator.
            static constexpr bitfield_t<FR_t, 4, 4, bool> RXFE = {};

            /// This bit holds the busy indicator.
            static constexpr bitfield_t<FR_t, 3, 3, bool> BUSY = {};

            /// This bit holds the data carrier detect indicator.
            static constexpr bitfield_t<FR_t, 2, 2, bool> DCD = {};

            /// This bit holds the data set ready indicator.
            static constexpr bitfield_t<FR_t, 1, 1, bool> DSR = {};

            /// This bit holds the clear to send indicator.
            static constexpr bitfield_t<FR_t, 0, 0, bool> CTS = {};
        } FR = {};

        /**
         * ILPR - 4 bytes at offset 32
         * IrDA Counter
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ILPR_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// These bits hold the IrDA counter divisor.
            static constexpr bitfield_t<ILPR_t, 7, 0> ILPDVSR = {};
        } ILPR = {};

        /**
         * IBRD - 4 bytes at offset 36
         * Integer Baud Rate Divisor
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IBRD_t : reg_t<uint32_t, BASE_ADDRESS + 0x24> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x24>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// These bits hold the baud integer divisor.
            static constexpr bitfield_t<IBRD_t, 15, 0> DIVINT = {};
        } IBRD = {};

        /**
         * FBRD - 4 bytes at offset 40
         * Fractional Baud Rate Divisor
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FBRD_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x0;

            /// These bits hold the baud fractional divisor.
            static constexpr bitfield_t<FBRD_t, 5, 0> DIVFRAC = {};
        } FBRD = {};

        /**
         * LCRH - 4 bytes at offset 44
         * Line Control High
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct LCRH_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit holds the stick parity select.
            static constexpr bitfield_t<LCRH_t, 7, 7, bool> SPS = {};

            /// These bits hold the write length.
            static constexpr bitfield_t<LCRH_t, 6, 5> WLEN = {};

            /// This bit holds the FIFO enable.
            static constexpr bitfield_t<LCRH_t, 4, 4, bool> FEN = {};

            /// This bit holds the two stop bits select.
            static constexpr bitfield_t<LCRH_t, 3, 3, bool> STP2 = {};

            /// This bit holds the even parity select.
            static constexpr bitfield_t<LCRH_t, 2, 2, bool> EPS = {};

            /// This bit holds the parity enable.
            static constexpr bitfield_t<LCRH_t, 1, 1, bool> PEN = {};

            /// This bit holds the break set.
            static constexpr bitfield_t<LCRH_t, 0, 0, bool> BRK = {};
        } LCRH = {};

        /**
         * CR - 4 bytes at offset 48
         * Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CR_t : reg_t<uint32_t, BASE_ADDRESS + 0x30> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x300;

            /// This bit enables CTS hardware flow control.
            static constexpr bitfield_t<CR_t, 15, 15, bool> CTSEN = {};

            /// This bit enables RTS hardware flow control.
            static constexpr bitfield_t<CR_t, 14, 14, bool> RTSEN = {};

            /// This bit holds modem Out2.
            static constexpr bitfield_t<CR_t, 13, 13, bool> OUT2 = {};

            /// This bit holds modem Out1.
            static constexpr bitfield_t<CR_t, 12, 12, bool> OUT1 = {};

            /// This bit enables request to send.
            static constexpr bitfield_t<CR_t, 11, 11, bool> RTS = {};

            /// This bit enables data transmit ready.
            static constexpr bitfield_t<CR_t, 10, 10, bool> DTR = {};

            /// This bit is the receive enable.
            static constexpr bitfield_t<CR_t, 9, 9, bool> RXE = {};

            /// This bit is the transmit enable.
            static constexpr bitfield_t<CR_t, 8, 8, bool> TXE = {};

            /// This bit is the loopback enable.
            static constexpr bitfield_t<CR_t, 7, 7, bool> LBE = {};

            /// This bitfield is the UART clock select.
            static constexpr bitfield_t<CR_t, 6, 4, UART0::CLKSELv> CLKSEL = {};

            /// This bit is the UART clock enable.
            static constexpr bitfield_t<CR_t, 3, 3, bool> CLKEN = {};

            /// This bit is the SIR low power select.
            static constexpr bitfield_t<CR_t, 2, 2, bool> SIRLP = {};

            /// This bit is the SIR ENDEC enable.
            static constexpr bitfield_t<CR_t, 1, 1, bool> SIREN = {};

            /// This bit is the UART enable.
            static constexpr bitfield_t<CR_t, 0, 0, bool> UARTEN = {};
        } CR = {};

        /**
         * IFLS - 4 bytes at offset 52
         * FIFO Interrupt Level Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IFLS_t : reg_t<uint32_t, BASE_ADDRESS + 0x34> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x34>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x12;

            /// These bits hold the receive FIFO interrupt level.
            static constexpr bitfield_t<IFLS_t, 5, 3> RXIFLSEL = {};

            /// These bits hold the transmit FIFO interrupt level.
            static constexpr bitfield_t<IFLS_t, 2, 0> TXIFLSEL = {};
        } IFLS = {};

        /**
         * IER - 4 bytes at offset 56
         * Interrupt Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IER_t : reg_t<uint32_t, BASE_ADDRESS + 0x38> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x38>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FF;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit holds the overflow interrupt enable.
            static constexpr bitfield_t<IER_t, 10, 10, bool> OEIM = {};

            /// This bit holds the break error interrupt enable.
            static constexpr bitfield_t<IER_t, 9, 9, bool> BEIM = {};

            /// This bit holds the parity error interrupt enable.
            static constexpr bitfield_t<IER_t, 8, 8, bool> PEIM = {};

            /// This bit holds the framing error interrupt enable.
            static constexpr bitfield_t<IER_t, 7, 7, bool> FEIM = {};

            /// This bit holds the receive timeout interrupt enable.
            static constexpr bitfield_t<IER_t, 6, 6, bool> RTIM = {};

            /// This bit holds the transmit interrupt enable.
            static constexpr bitfield_t<IER_t, 5, 5, bool> TXIM = {};

            /// This bit holds the receive interrupt enable.
            static constexpr bitfield_t<IER_t, 4, 4, bool> RXIM = {};

            /// This bit holds the modem DSR interrupt enable.
            static constexpr bitfield_t<IER_t, 3, 3, bool> DSRMIM = {};

            /// This bit holds the modem DCD interrupt enable.
            static constexpr bitfield_t<IER_t, 2, 2, bool> DCDMIM = {};

            /// This bit holds the modem CTS interrupt enable.
            static constexpr bitfield_t<IER_t, 1, 1, bool> CTSMIM = {};

            /// This bit holds the modem TXCMP interrupt enable.
            static constexpr bitfield_t<IER_t, 0, 0, bool> TXCMPMIM = {};
        } IER = {};

        /**
         * IES - 4 bytes at offset 60
         * Interrupt Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IES_t : reg_t<uint32_t, BASE_ADDRESS + 0x3C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x3C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FF;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit holds the overflow interrupt status.
            static constexpr bitfield_t<IES_t, 10, 10, bool> OERIS = {};

            /// This bit holds the break error interrupt status.
            static constexpr bitfield_t<IES_t, 9, 9, bool> BERIS = {};

            /// This bit holds the parity error interrupt status.
            static constexpr bitfield_t<IES_t, 8, 8, bool> PERIS = {};

            /// This bit holds the framing error interrupt status.
            static constexpr bitfield_t<IES_t, 7, 7, bool> FERIS = {};

            /// This bit holds the receive timeout interrupt status.
            static constexpr bitfield_t<IES_t, 6, 6, bool> RTRIS = {};

            /// This bit holds the transmit interrupt status.
            static constexpr bitfield_t<IES_t, 5, 5, bool> TXRIS = {};

            /// This bit holds the receive interrupt status.
            static constexpr bitfield_t<IES_t, 4, 4, bool> RXRIS = {};

            /// This bit holds the modem DSR interrupt status.
            static constexpr bitfield_t<IES_t, 3, 3, bool> DSRMRIS = {};

            /// This bit holds the modem DCD interrupt status.
            static constexpr bitfield_t<IES_t, 2, 2, bool> DCDMRIS = {};

            /// This bit holds the modem CTS interrupt status.
            static constexpr bitfield_t<IES_t, 1, 1, bool> CTSMRIS = {};

            /// This bit holds the modem TXCMP interrupt status.
            static constexpr bitfield_t<IES_t, 0, 0, bool> TXCMPMRIS = {};
        } IES = {};

        /**
         * MIS - 4 bytes at offset 64
         * Masked Interrupt Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MIS_t : reg_t<uint32_t, BASE_ADDRESS + 0x40> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x40>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FF;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit holds the overflow interrupt status masked.
            static constexpr bitfield_t<MIS_t, 10, 10, bool> OEMIS = {};

            /// This bit holds the break error interrupt status masked.
            static constexpr bitfield_t<MIS_t, 9, 9, bool> BEMIS = {};

            /// This bit holds the parity error interrupt status masked.
            static constexpr bitfield_t<MIS_t, 8, 8, bool> PEMIS = {};

            /// This bit holds the framing error interrupt status masked.
            static constexpr bitfield_t<MIS_t, 7, 7, bool> FEMIS = {};

            /// This bit holds the receive timeout interrupt status masked.
            static constexpr bitfield_t<MIS_t, 6, 6, bool> RTMIS = {};

            /// This bit holds the transmit interrupt status masked.
            static constexpr bitfield_t<MIS_t, 5, 5, bool> TXMIS = {};

            /// This bit holds the receive interrupt status masked.
            static constexpr bitfield_t<MIS_t, 4, 4, bool> RXMIS = {};

            /// This bit holds the modem DSR interrupt status masked.
            static constexpr bitfield_t<MIS_t, 3, 3, bool> DSRMMIS = {};

            /// This bit holds the modem DCD interrupt status masked.
            static constexpr bitfield_t<MIS_t, 2, 2, bool> DCDMMIS = {};

            /// This bit holds the modem CTS interrupt status masked.
            static constexpr bitfield_t<MIS_t, 1, 1, bool> CTSMMIS = {};

            /// This bit holds the modem TXCMP interrupt status masked.
            static constexpr bitfield_t<MIS_t, 0, 0, bool> TXCMPMMIS = {};
        } MIS = {};

        /**
         * IEC - 4 bytes at offset 68
         * Interrupt Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IEC_t : reg_t<uint32_t, BASE_ADDRESS + 0x44> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x44>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FF;
            static constexpr uint32_t reset_value = 0x0;

            /// This bit holds the overflow interrupt clear.
            static constexpr bitfield_t<IEC_t, 10, 10, bool> OEIC = {};

            /// This bit holds the break error interrupt clear.
            static constexpr bitfield_t<IEC_t, 9, 9, bool> BEIC = {};

            /// This bit holds the parity error interrupt clear.
            static constexpr bitfield_t<IEC_t, 8, 8, bool> PEIC = {};

            /// This bit holds the framing error interrupt clear.
            static constexpr bitfield_t<IEC_t, 7, 7, bool> FEIC = {};

            /// This bit holds the receive timeout interrupt clear.
            static constexpr bitfield_t<IEC_t, 6, 6, bool> RTIC = {};

            /// This bit holds the transmit interrupt clear.
            static constexpr bitfield_t<IEC_t, 5, 5, bool> TXIC = {};

            /// This bit holds the receive interrupt clear.
            static constexpr bitfield_t<IEC_t, 4, 4, bool> RXIC = {};

            /// This bit holds the modem DSR interrupt clear.
            static constexpr bitfield_t<IEC_t, 3, 3, bool> DSRMIC = {};

            /// This bit holds the modem DCD interrupt clear.
            static constexpr bitfield_t<IEC_t, 2, 2, bool> DCDMIC = {};

            /// This bit holds the modem CTS interrupt clear.
            static constexpr bitfield_t<IEC_t, 1, 1, bool> CTSMIC = {};

            /// This bit holds the modem TXCMP interrupt clear.
            static constexpr bitfield_t<IEC_t, 0, 0, bool> TXCMPMIC = {};
        } IEC = {};
    };  // end of struct UART0_t

} // namespace sfr