/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: IOSLAVE
 * I2C/SPI Slave
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace IOSLAVE {
    
    }   // namespace IOSLAVE

    /// I2C/SPI Slave
    template <addressType BASE_ADDRESS>
    struct IOSLAVE_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * FIFOPTR - 4 bytes at offset 256
         * Current FIFO Pointer
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOPTR_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// The number of bytes currently in the hardware FIFO.
            static constexpr bitfield_t<FIFOPTR_t, 15, 8> FIFOSIZ = {};

            /// Current FIFO pointer.
            static constexpr bitfield_t<FIFOPTR_t, 7, 0> FIFOPTR = {};
        } FIFOPTR = {};

        /**
         * FIFOCFG - 4 bytes at offset 260
         * FIFO Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F003F1F;
            static constexpr uint32_t reset_value = 0x20000000;

            /// Defines the read-only area.  The IO Slave read-only area is situated in LRAM at (ROBASE*8) to (FIFOBASE*8-1)
            static constexpr bitfield_t<FIFOCFG_t, 29, 24> ROBASE = {};

            /// These bits hold the maximum FIFO address in 8 byte segments.  It is also the beginning of the RAM area of the LRAM.  Note that no RAM area is configured if FIFOMAX is set to 0x1F.
            static constexpr bitfield_t<FIFOCFG_t, 13, 8> FIFOMAX = {};

            /// These bits hold the base address of the I/O FIFO in 8 byte segments. The IO Slave FIFO is situated in LRAM at (FIFOBASE*8) to (FIFOMAX*8-1).
            static constexpr bitfield_t<FIFOCFG_t, 4, 0> FIFOBASE = {};
        } FIFOCFG = {};

        /**
         * FIFOTHR - 4 bytes at offset 264
         * FIFO Threshold Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOTHR_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO size interrupt threshold.
            static constexpr bitfield_t<FIFOTHR_t, 7, 0> FIFOTHR = {};
        } FIFOTHR = {};

        /**
         * FUPD - 4 bytes at offset 268
         * FIFO Update Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FUPD_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// This bitfield indicates an IO read is active.
            static constexpr bitfield_t<FUPD_t, 1, 1, bool> IOREAD = {};

            /// This bit indicates that a FIFO update is underway.
            static constexpr bitfield_t<FUPD_t, 0, 0, bool> FIFOUPD = {};
        } FUPD = {};

        /**
         * FIFOCTR - 4 bytes at offset 272
         * Overall FIFO Counter
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOCTR_t : reg_t<uint32_t, BASE_ADDRESS + 0x110> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x110>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Virtual FIFO byte count
            static constexpr bitfield_t<FIFOCTR_t, 9, 0> FIFOCTR = {};
        } FIFOCTR = {};

        /**
         * FIFOINC - 4 bytes at offset 276
         * Overall FIFO Counter Increment
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOINC_t : reg_t<uint32_t, BASE_ADDRESS + 0x114> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x114>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Increment the Overall FIFO Counter by this value on a write
            static constexpr bitfield_t<FIFOINC_t, 9, 0> FIFOINC = {};
        } FIFOINC = {};

        /**
         * CFG - 4 bytes at offset 280
         * I/O Slave Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x118> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x118>::operator=;
            static constexpr uint32_t reset_mask  = 0x800FFF17;
            static constexpr uint32_t reset_value = 0x0;

            /// IOSLAVE interface enable.
            static constexpr bitfield_t<CFG_t, 31, 31, bool> IFCEN = {};

            /// 7-bit or 10-bit I2C device address.
            static constexpr bitfield_t<CFG_t, 19, 8> I2CADDR = {};

            /// This bit holds the cycle to initiate an I/O RAM read.
            static constexpr bitfield_t<CFG_t, 4, 4, bool> STARTRD = {};

            /// This bit selects the transfer bit ordering.
            static constexpr bitfield_t<CFG_t, 2, 2, bool> LSB = {};

            /// This bit selects SPI polarity.
            static constexpr bitfield_t<CFG_t, 1, 1, bool> SPOL = {};

            /// This bit selects the I/O interface.
            static constexpr bitfield_t<CFG_t, 0, 0, bool> IFCSEL = {};
        } CFG = {};

        /**
         * PRENC - 4 bytes at offset 284
         * I/O Slave Interrupt Priority Encode
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PRENC_t : reg_t<uint32_t, BASE_ADDRESS + 0x11C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x11C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// These bits hold the priority encode of the REGACC interrupts.
            static constexpr bitfield_t<PRENC_t, 4, 0> PRENC = {};
        } PRENC = {};

        /**
         * IOINTCTL - 4 bytes at offset 288
         * I/O Interrupt Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOINTCTL_t : reg_t<uint32_t, BASE_ADDRESS + 0x120> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x120>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF01FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// These bits set the IOINT interrupts when written with a 1.
            static constexpr bitfield_t<IOINTCTL_t, 31, 24> IOINTSET = {};

            /// This bit clears all of the IOINT interrupts when written with a 1.
            static constexpr bitfield_t<IOINTCTL_t, 16, 16, bool> IOINTCLR = {};

            /// These bits read the IOINT interrupts.
            static constexpr bitfield_t<IOINTCTL_t, 15, 8> IOINT = {};

            /// These read-only bits indicate whether the IOINT interrupts are enabled.
            static constexpr bitfield_t<IOINTCTL_t, 7, 0> IOINTEN = {};
        } IOINTCTL = {};

        /**
         * GENADD - 4 bytes at offset 292
         * General Address Data
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct GENADD_t : reg_t<uint32_t, BASE_ADDRESS + 0x124> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x124>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// The data supplied on the last General Address reference.
            static constexpr bitfield_t<GENADD_t, 7, 0> GADATA = {};
        } GENADD = {};

        /**
         * INTEN - 4 bytes at offset 512
         * IO Slave Interrupts: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Transfer complete interrupt, write to register space.
            static constexpr bitfield_t<INTEN_t, 9, 9, bool> XCMPWR = {};

            /// Transfer complete interrupt, write to FIFO space.
            static constexpr bitfield_t<INTEN_t, 8, 8, bool> XCMPWF = {};

            /// Transfer complete interrupt, read from register space.
            static constexpr bitfield_t<INTEN_t, 7, 7, bool> XCMPRR = {};

            /// Transfer complete interrupt, read from FIFO space.
            static constexpr bitfield_t<INTEN_t, 6, 6, bool> XCMPRF = {};

            /// IO Write interrupt.
            static constexpr bitfield_t<INTEN_t, 5, 5, bool> IOINTW = {};

            /// I2C General Address interrupt.
            static constexpr bitfield_t<INTEN_t, 4, 4, bool> GENAD = {};

            /// FIFO Read Error interrupt.
            static constexpr bitfield_t<INTEN_t, 3, 3, bool> FRDERR = {};

            /// FIFO Underflow interrupt.
            static constexpr bitfield_t<INTEN_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Overflow interrupt.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> FOVFL = {};

            /// FIFO Size interrupt.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> FSIZE = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * IO Slave Interrupts: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Transfer complete interrupt, write to register space.
            static constexpr bitfield_t<INTSTAT_t, 9, 9, bool> XCMPWR = {};

            /// Transfer complete interrupt, write to FIFO space.
            static constexpr bitfield_t<INTSTAT_t, 8, 8, bool> XCMPWF = {};

            /// Transfer complete interrupt, read from register space.
            static constexpr bitfield_t<INTSTAT_t, 7, 7, bool> XCMPRR = {};

            /// Transfer complete interrupt, read from FIFO space.
            static constexpr bitfield_t<INTSTAT_t, 6, 6, bool> XCMPRF = {};

            /// IO Write interrupt.
            static constexpr bitfield_t<INTSTAT_t, 5, 5, bool> IOINTW = {};

            /// I2C General Address interrupt.
            static constexpr bitfield_t<INTSTAT_t, 4, 4, bool> GENAD = {};

            /// FIFO Read Error interrupt.
            static constexpr bitfield_t<INTSTAT_t, 3, 3, bool> FRDERR = {};

            /// FIFO Underflow interrupt.
            static constexpr bitfield_t<INTSTAT_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Overflow interrupt.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> FOVFL = {};

            /// FIFO Size interrupt.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> FSIZE = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * IO Slave Interrupts: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Transfer complete interrupt, write to register space.
            static constexpr bitfield_t<INTCLR_t, 9, 9, bool> XCMPWR = {};

            /// Transfer complete interrupt, write to FIFO space.
            static constexpr bitfield_t<INTCLR_t, 8, 8, bool> XCMPWF = {};

            /// Transfer complete interrupt, read from register space.
            static constexpr bitfield_t<INTCLR_t, 7, 7, bool> XCMPRR = {};

            /// Transfer complete interrupt, read from FIFO space.
            static constexpr bitfield_t<INTCLR_t, 6, 6, bool> XCMPRF = {};

            /// IO Write interrupt.
            static constexpr bitfield_t<INTCLR_t, 5, 5, bool> IOINTW = {};

            /// I2C General Address interrupt.
            static constexpr bitfield_t<INTCLR_t, 4, 4, bool> GENAD = {};

            /// FIFO Read Error interrupt.
            static constexpr bitfield_t<INTCLR_t, 3, 3, bool> FRDERR = {};

            /// FIFO Underflow interrupt.
            static constexpr bitfield_t<INTCLR_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Overflow interrupt.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> FOVFL = {};

            /// FIFO Size interrupt.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> FSIZE = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * IO Slave Interrupts: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Transfer complete interrupt, write to register space.
            static constexpr bitfield_t<INTSET_t, 9, 9, bool> XCMPWR = {};

            /// Transfer complete interrupt, write to FIFO space.
            static constexpr bitfield_t<INTSET_t, 8, 8, bool> XCMPWF = {};

            /// Transfer complete interrupt, read from register space.
            static constexpr bitfield_t<INTSET_t, 7, 7, bool> XCMPRR = {};

            /// Transfer complete interrupt, read from FIFO space.
            static constexpr bitfield_t<INTSET_t, 6, 6, bool> XCMPRF = {};

            /// IO Write interrupt.
            static constexpr bitfield_t<INTSET_t, 5, 5, bool> IOINTW = {};

            /// I2C General Address interrupt.
            static constexpr bitfield_t<INTSET_t, 4, 4, bool> GENAD = {};

            /// FIFO Read Error interrupt.
            static constexpr bitfield_t<INTSET_t, 3, 3, bool> FRDERR = {};

            /// FIFO Underflow interrupt.
            static constexpr bitfield_t<INTSET_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Overflow interrupt.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> FOVFL = {};

            /// FIFO Size interrupt.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> FSIZE = {};
        } INTSET = {};

        /**
         * REGACCINTEN - 4 bytes at offset 528
         * Register Access Interrupts: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct REGACCINTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x210> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x210>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Register access interrupts.
            static constexpr bitfield_t<REGACCINTEN_t, 31, 0> REGACC = {};
        } REGACCINTEN = {};

        /**
         * REGACCINTSTAT - 4 bytes at offset 532
         * Register Access Interrupts: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct REGACCINTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x214> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x214>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Register access interrupts.
            static constexpr bitfield_t<REGACCINTSTAT_t, 31, 0> REGACC = {};
        } REGACCINTSTAT = {};

        /**
         * REGACCINTCLR - 4 bytes at offset 536
         * Register Access Interrupts: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct REGACCINTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x218> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x218>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Register access interrupts.
            static constexpr bitfield_t<REGACCINTCLR_t, 31, 0> REGACC = {};
        } REGACCINTCLR = {};

        /**
         * REGACCINTSET - 4 bytes at offset 540
         * Register Access Interrupts: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct REGACCINTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x21C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x21C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Register access interrupts.
            static constexpr bitfield_t<REGACCINTSET_t, 31, 0> REGACC = {};
        } REGACCINTSET = {};
    };  // end of struct IOSLAVE_t

} // namespace sfr