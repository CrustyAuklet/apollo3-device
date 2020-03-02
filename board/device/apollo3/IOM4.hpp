/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: IOM4
 * IO Peripheral Master
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace IOM4 {
    
        /// Select the input clock frequency.
        enum class FSELv : uint32_t {
            MIN_PWR = 0x0, //< Selects the minimum power clock.  This setting should be used whenever the IOM is not active.
            HFRC = 0x1, //< Selects the HFRC as the input clock.
            HFRC_DIV2 = 0x2, //< Selects the HFRC / 2 as the input clock.
            HFRC_DIV4 = 0x3, //< Selects the HFRC / 4 as the input clock.
            HFRC_DIV8 = 0x4, //< Selects the HFRC / 8 as the input clock.
            HFRC_DIV16 = 0x5, //< Selects the HFRC / 16 as the input clock.
            HFRC_DIV32 = 0x6, //< Selects the HFRC / 32 as the input clock.
            HFRC_DIV64 = 0x7, //< Selects the HFRC / 64 as the input clock.
        };
    
        /// Submodule 0 module type.  This is the I2C Master interface
        enum class SMOD1TYPEv : uint32_t {
            MSPI = 0x0, //< SPI Master submodule
            I2C_MASTER = 0x1, //< MI2C submodule
            SSPI = 0x2, //< SPI Slave submodule
            SI2C = 0x3, //< I2C Slave submodule
            NA = 0x7, //< NOT INSTALLED
        };
    
        /// Submodule 0 module type.  This is the SPI Master interface.
        enum class SMOD0TYPEv : uint32_t {
            SPI_MASTER = 0x0, //< MSPI submodule
            I2C_MASTER = 0x1, //< I2C Master submodule
            SSPI = 0x2, //< SPI Slave submodule
            SI2C = 0x3, //< I2C Slave submodule
            NA = 0x7, //< NOT INSTALLED
        };
    
        /// Command for submodule.
        enum class CMDv : uint32_t {
            WRITE = 0x1, //< Write command using count of offset bytes specified in the OFFSETCNT field
            READ = 0x2, //< Read command using count of offset bytes specified in the OFFSETCNT field
            TMW = 0x3, //< SPI only. Test mode to do constant write operations. Useful for debug and power measurements. Will continually send data in OFFSET field
            TMR = 0x4, //< SPI Only. Test mode to do constant read operations. Useful for debug and power measurements. Will continually read data from external input
        };
    
        /// The current status of the command execution.
        enum class CMDSTATv : uint32_t {
            ERR = 0x1, //< Error encountered with command
            ACTIVE = 0x2, //< Actively processing command
            IDLE = 0x4, //< Idle state, no active command, no error
            WAIT = 0x6, //< Command in progress, but waiting on data from host
        };
    
        /// Enables the specified event to pause command processing when active
        enum class CQPENv : uint32_t {
            IDXEQ = 0x8000, //< Pauses the command queue when the current index matches the last index
            BLEXOREN = 0x4000, //< Pause command queue when input BLE bit XORed with SWFLAG4 is '1'
            IOMXOREN = 0x2000, //< Pause command queue when input IOM bit XORed with SWFLAG3 is '1'
            GPIOXOREN = 0x1000, //< Pause command queue when input GPIO irq_bit XORed with SWFLAG2 is '1'
            MSPI1XNOREN = 0x800, //< Pause command queue when input MSPI1 bit XNORed with SWFLAG1 is '1'
            MSPI0XNOREN = 0x400, //< Pause command queue when input MSPI0 bit XNORed with SWFLAG0 is '1'
            MSPI1XOREN = 0x200, //< Pause command queue when input MSPI1 bit XORed with SWFLAG1 is '1'
            MSPI0XOREN = 0x100, //< Pause command queue when input MSPI0 bit XORed with SWFLAG0 is '1'
            SWFLAGEN7 = 0x80, //< Pause the command queue when software flag bit 7 is '1'.
            SWFLAGEN6 = 0x40, //< Pause the command queue when software flag bit 6 is '1'
            SWFLAGEN5 = 0x20, //< Pause the command queue when software flag bit 5 is '1'
            SWFLAGEN4 = 0x10, //< Pause the command queue when software flag bit 4 is '1'
            SWFLAGEN3 = 0x8, //< Pause the command queue when software flag bit 3 is '1'
            SWFLAGEN2 = 0x4, //< Pause the command queue when software flag bit 2 is '1'
            SWFLAGEN1 = 0x2, //< Pause the command queue when software flag bit 1 is '1'
            SWFLAGEN0 = 0x1, //< Pause the command queue when software flag bit 0 is '1'
        };
    
    }   // namespace IOM4

    /// IO Peripheral Master
    template <addressType BASE_ADDRESS>
    struct IOM4_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * FIFO - 4 bytes at offset 0
         * FIFO Access Port
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFO_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO direct access. Only locations 0 - 3F will return valid information.
            static constexpr bitfield_t<FIFO_t, 31, 0> FIFO = {};
        } FIFO = {};

        /**
         * FIFOPTR - 4 bytes at offset 256
         * FIFO size and remaining slots open values
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOPTR_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// The number of remaining data bytes slots currently in FIFO 1 (written by interface, read by MCU)
            static constexpr bitfield_t<FIFOPTR_t, 31, 24> FIFO1REM = {};

            /// The number of valid data bytes currently in FIFO 1 (written by interface, read by MCU)
            static constexpr bitfield_t<FIFOPTR_t, 23, 16> FIFO1SIZ = {};

            /// The number of remaining data bytes slots currently in FIFO 0 (written by MCU, read by interface)
            static constexpr bitfield_t<FIFOPTR_t, 15, 8> FIFO0REM = {};

            /// The number of valid data bytes currently in the FIFO 0 (written by MCU, read by interface)
            static constexpr bitfield_t<FIFOPTR_t, 7, 0> FIFO0SIZ = {};
        } FIFOPTR = {};

        /**
         * FIFOTHR - 4 bytes at offset 260
         * FIFO Threshold Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOTHR_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F;
            static constexpr uint32_t reset_value = 0x0;

            /// FIFO write threshold in bytes.  A value of 0 will disable the write FIFO level from activating the threshold interrupt. If this field is non-zero, it will trigger a threshold interrupt when the write fifo contains FIFOWTHR free bytes, as indicated by the FIFO0REM field.  This is intended to signal when a transfer of FIFOWTHR bytes can be done from the host to the IOM write fifo to support large IOM write operations.
            static constexpr bitfield_t<FIFOTHR_t, 13, 8> FIFOWTHR = {};

            /// FIFO read threshold in bytes.  A value of 0 will disable the read FIFO level from activating the threshold interrupt. If this field is non-zero, it will trigger a threshold interrupt when the read fifo contains FIFORTHR valid bytes of data, as indicated by the FIFO1SIZ field.  This is intended to signal when a data transfer of FIFORTHR bytes can be done from the IOM module to the host via the read fifo to support large IOM read operations.
            static constexpr bitfield_t<FIFOTHR_t, 5, 0> FIFORTHR = {};
        } FIFOTHR = {};

        /**
         * FIFOPOP - 4 bytes at offset 264
         * FIFO POP register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOPOP_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// This register will return the read data indicated by the current read pointer on reads. If the POPWR control bit in the FIFOCTRL register is reset (0), the fifo read pointer will be advanced by one word as a result of the read. If the POPWR bit is set (1), the fifo read pointer will only be advanced after a write operation to this register.  The write data is ignored for this register. If less than a even word multiple is available, and the command is completed, the module will return the word containing these bytes and undetermined data in the unused fields of the word.
            static constexpr bitfield_t<FIFOPOP_t, 31, 0> FIFODOUT = {};
        } FIFOPOP = {};

        /**
         * FIFOPUSH - 4 bytes at offset 268
         * FIFO PUSH register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOPUSH_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// This register is used to write the FIFORAM in FIFO mode and will cause a push event to occur to the next open slot within the FIFORAM.  Writing to this register will cause the write point to increment by 1 word(4 bytes).
            static constexpr bitfield_t<FIFOPUSH_t, 31, 0> FIFODIN = {};
        } FIFOPUSH = {};

        /**
         * FIFOCTRL - 4 bytes at offset 272
         * FIFO Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x110> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x110>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x2;

            /// Active low manual reset of the fifo.  Write to 0 to reset fifo, and then write to 1 to remove the reset.
            static constexpr bitfield_t<FIFOCTRL_t, 1, 1, bool> FIFORSTN = {};

            /// Selects the mode in which 'pop' events are done for the fifo read operations.  A value of '1' will prevent a pop event on a read operation, and will require a write to the FIFOPOP register to create a pop event. A value of '0' in this register will allow a pop event to occur on the read of the FIFOPOP register, and may cause inadvertant fifo pops when used in a debugging mode.
            static constexpr bitfield_t<FIFOCTRL_t, 0, 0, bool> POPWR = {};
        } FIFOCTRL = {};

        /**
         * FIFOLOC - 4 bytes at offset 276
         * FIFO Pointers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FIFOLOC_t : reg_t<uint32_t, BASE_ADDRESS + 0x114> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x114>::operator=;
            static constexpr uint32_t reset_mask  = 0xF0F;
            static constexpr uint32_t reset_value = 0x0;

            /// Current FIFO read pointer.  Used to index into the incoming FIFO (FIFO1), which is used to store read data returned from external devices during a read operation.
            static constexpr bitfield_t<FIFOLOC_t, 11, 8> FIFORPTR = {};

            /// Current FIFO write pointer. Value is the index into the outgoing FIFO (FIFO0), which is used during write operations to external devices.
            static constexpr bitfield_t<FIFOLOC_t, 3, 0> FIFOWPTR = {};
        } FIFOLOC = {};

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
            static constexpr uint32_t reset_mask  = 0x7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Error during command queue operations
            static constexpr bitfield_t<INTEN_t, 14, 14, bool> CQERR = {};

            /// CQ write operation performed a register write with the register address bit 0 set to 1.  The low address bits in the CQ address fields are unused and bit 0 can be used to trigger an interrupt to indicate when this register write is performed by the CQ operation.
            static constexpr bitfield_t<INTEN_t, 13, 13, bool> CQUPD = {};

            /// Command queue is paused due to an active event enabled in the PAUSEEN register.  The interrupt is posted when the event is enabled within the PAUSEEN register, the mask is active in the CQIRQMASK field and the event occurs.
            static constexpr bitfield_t<INTEN_t, 12, 12, bool> CQPAUSED = {};

            /// DMA Error encountered during the processing of the DMA command.  The DMA error could occur when the memory access specified in the DMA operation is not available or incorrectly specified.
            static constexpr bitfield_t<INTEN_t, 11, 11, bool> DERR = {};

            /// DMA Complete. Processing of the DMA operation has completed and the DMA submodule is returned into the idle state
            static constexpr bitfield_t<INTEN_t, 10, 10, bool> DCMP = {};

            /// Arbitration loss interrupt. Asserted when arbitration is enabled and has been lost to another master on the bus.
            static constexpr bitfield_t<INTEN_t, 9, 9, bool> ARB = {};

            /// STOP command interrupt. Asserted when another master on the bus has signaled a STOP command.
            static constexpr bitfield_t<INTEN_t, 8, 8, bool> STOP = {};

            /// START command interrupt. Asserted when another master on the bus has signaled a START command.
            static constexpr bitfield_t<INTEN_t, 7, 7, bool> START = {};

            /// illegal command interrupt. Asserted when a command is written when an active command is in progress.
            static constexpr bitfield_t<INTEN_t, 6, 6, bool> ICMD = {};

            /// illegal FIFO access interrupt. Asserted when there is a overflow or underflow event
            static constexpr bitfield_t<INTEN_t, 5, 5, bool> IACC = {};

            /// I2C NAK interrupt. Asserted when an unexpected NAK has been received on the I2C bus.
            static constexpr bitfield_t<INTEN_t, 4, 4, bool> NAK = {};

            /// Write FIFO Overflow interrupt. This occurs when software tries to write to a full fifo.  The current operation does not stop.
            static constexpr bitfield_t<INTEN_t, 3, 3, bool> FOVFL = {};

            /// Read FIFO Underflow interrupt. This occurs when software tries to pop from an empty fifo.
            static constexpr bitfield_t<INTEN_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Threshold interrupt. For write operations, asserted when the number of free bytes in the write FIFO equals or exceeds the WTHR field. For read operations, asserted when the number of valid bytes in the read FIFO equals of exceeds the value set in the RTHR field.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> THR = {};

            /// Command Complete interrupt. Asserted when the current operation has completed.   For repeated commands, this will only be asserted when the final repeated command is completed.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> CMDCMP = {};
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
            static constexpr uint32_t reset_mask  = 0x7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Error during command queue operations
            static constexpr bitfield_t<INTSTAT_t, 14, 14, bool> CQERR = {};

            /// CQ write operation performed a register write with the register address bit 0 set to 1.  The low address bits in the CQ address fields are unused and bit 0 can be used to trigger an interrupt to indicate when this register write is performed by the CQ operation.
            static constexpr bitfield_t<INTSTAT_t, 13, 13, bool> CQUPD = {};

            /// Command queue is paused due to an active event enabled in the PAUSEEN register.  The interrupt is posted when the event is enabled within the PAUSEEN register, the mask is active in the CQIRQMASK field and the event occurs.
            static constexpr bitfield_t<INTSTAT_t, 12, 12, bool> CQPAUSED = {};

            /// DMA Error encountered during the processing of the DMA command.  The DMA error could occur when the memory access specified in the DMA operation is not available or incorrectly specified.
            static constexpr bitfield_t<INTSTAT_t, 11, 11, bool> DERR = {};

            /// DMA Complete. Processing of the DMA operation has completed and the DMA submodule is returned into the idle state
            static constexpr bitfield_t<INTSTAT_t, 10, 10, bool> DCMP = {};

            /// Arbitration loss interrupt. Asserted when arbitration is enabled and has been lost to another master on the bus.
            static constexpr bitfield_t<INTSTAT_t, 9, 9, bool> ARB = {};

            /// STOP command interrupt. Asserted when another master on the bus has signaled a STOP command.
            static constexpr bitfield_t<INTSTAT_t, 8, 8, bool> STOP = {};

            /// START command interrupt. Asserted when another master on the bus has signaled a START command.
            static constexpr bitfield_t<INTSTAT_t, 7, 7, bool> START = {};

            /// illegal command interrupt. Asserted when a command is written when an active command is in progress.
            static constexpr bitfield_t<INTSTAT_t, 6, 6, bool> ICMD = {};

            /// illegal FIFO access interrupt. Asserted when there is a overflow or underflow event
            static constexpr bitfield_t<INTSTAT_t, 5, 5, bool> IACC = {};

            /// I2C NAK interrupt. Asserted when an unexpected NAK has been received on the I2C bus.
            static constexpr bitfield_t<INTSTAT_t, 4, 4, bool> NAK = {};

            /// Write FIFO Overflow interrupt. This occurs when software tries to write to a full fifo.  The current operation does not stop.
            static constexpr bitfield_t<INTSTAT_t, 3, 3, bool> FOVFL = {};

            /// Read FIFO Underflow interrupt. This occurs when software tries to pop from an empty fifo.
            static constexpr bitfield_t<INTSTAT_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Threshold interrupt. For write operations, asserted when the number of free bytes in the write FIFO equals or exceeds the WTHR field. For read operations, asserted when the number of valid bytes in the read FIFO equals of exceeds the value set in the RTHR field.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> THR = {};

            /// Command Complete interrupt. Asserted when the current operation has completed.   For repeated commands, this will only be asserted when the final repeated command is completed.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> CMDCMP = {};
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
            static constexpr uint32_t reset_mask  = 0x7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Error during command queue operations
            static constexpr bitfield_t<INTCLR_t, 14, 14, bool> CQERR = {};

            /// CQ write operation performed a register write with the register address bit 0 set to 1.  The low address bits in the CQ address fields are unused and bit 0 can be used to trigger an interrupt to indicate when this register write is performed by the CQ operation.
            static constexpr bitfield_t<INTCLR_t, 13, 13, bool> CQUPD = {};

            /// Command queue is paused due to an active event enabled in the PAUSEEN register.  The interrupt is posted when the event is enabled within the PAUSEEN register, the mask is active in the CQIRQMASK field and the event occurs.
            static constexpr bitfield_t<INTCLR_t, 12, 12, bool> CQPAUSED = {};

            /// DMA Error encountered during the processing of the DMA command.  The DMA error could occur when the memory access specified in the DMA operation is not available or incorrectly specified.
            static constexpr bitfield_t<INTCLR_t, 11, 11, bool> DERR = {};

            /// DMA Complete. Processing of the DMA operation has completed and the DMA submodule is returned into the idle state
            static constexpr bitfield_t<INTCLR_t, 10, 10, bool> DCMP = {};

            /// Arbitration loss interrupt. Asserted when arbitration is enabled and has been lost to another master on the bus.
            static constexpr bitfield_t<INTCLR_t, 9, 9, bool> ARB = {};

            /// STOP command interrupt. Asserted when another master on the bus has signaled a STOP command.
            static constexpr bitfield_t<INTCLR_t, 8, 8, bool> STOP = {};

            /// START command interrupt. Asserted when another master on the bus has signaled a START command.
            static constexpr bitfield_t<INTCLR_t, 7, 7, bool> START = {};

            /// illegal command interrupt. Asserted when a command is written when an active command is in progress.
            static constexpr bitfield_t<INTCLR_t, 6, 6, bool> ICMD = {};

            /// illegal FIFO access interrupt. Asserted when there is a overflow or underflow event
            static constexpr bitfield_t<INTCLR_t, 5, 5, bool> IACC = {};

            /// I2C NAK interrupt. Asserted when an unexpected NAK has been received on the I2C bus.
            static constexpr bitfield_t<INTCLR_t, 4, 4, bool> NAK = {};

            /// Write FIFO Overflow interrupt. This occurs when software tries to write to a full fifo.  The current operation does not stop.
            static constexpr bitfield_t<INTCLR_t, 3, 3, bool> FOVFL = {};

            /// Read FIFO Underflow interrupt. This occurs when software tries to pop from an empty fifo.
            static constexpr bitfield_t<INTCLR_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Threshold interrupt. For write operations, asserted when the number of free bytes in the write FIFO equals or exceeds the WTHR field. For read operations, asserted when the number of valid bytes in the read FIFO equals of exceeds the value set in the RTHR field.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> THR = {};

            /// Command Complete interrupt. Asserted when the current operation has completed.   For repeated commands, this will only be asserted when the final repeated command is completed.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> CMDCMP = {};
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
            static constexpr uint32_t reset_mask  = 0x7FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Error during command queue operations
            static constexpr bitfield_t<INTSET_t, 14, 14, bool> CQERR = {};

            /// CQ write operation performed a register write with the register address bit 0 set to 1.  The low address bits in the CQ address fields are unused and bit 0 can be used to trigger an interrupt to indicate when this register write is performed by the CQ operation.
            static constexpr bitfield_t<INTSET_t, 13, 13, bool> CQUPD = {};

            /// Command queue is paused due to an active event enabled in the PAUSEEN register.  The interrupt is posted when the event is enabled within the PAUSEEN register, the mask is active in the CQIRQMASK field and the event occurs.
            static constexpr bitfield_t<INTSET_t, 12, 12, bool> CQPAUSED = {};

            /// DMA Error encountered during the processing of the DMA command.  The DMA error could occur when the memory access specified in the DMA operation is not available or incorrectly specified.
            static constexpr bitfield_t<INTSET_t, 11, 11, bool> DERR = {};

            /// DMA Complete. Processing of the DMA operation has completed and the DMA submodule is returned into the idle state
            static constexpr bitfield_t<INTSET_t, 10, 10, bool> DCMP = {};

            /// Arbitration loss interrupt. Asserted when arbitration is enabled and has been lost to another master on the bus.
            static constexpr bitfield_t<INTSET_t, 9, 9, bool> ARB = {};

            /// STOP command interrupt. Asserted when another master on the bus has signaled a STOP command.
            static constexpr bitfield_t<INTSET_t, 8, 8, bool> STOP = {};

            /// START command interrupt. Asserted when another master on the bus has signaled a START command.
            static constexpr bitfield_t<INTSET_t, 7, 7, bool> START = {};

            /// illegal command interrupt. Asserted when a command is written when an active command is in progress.
            static constexpr bitfield_t<INTSET_t, 6, 6, bool> ICMD = {};

            /// illegal FIFO access interrupt. Asserted when there is a overflow or underflow event
            static constexpr bitfield_t<INTSET_t, 5, 5, bool> IACC = {};

            /// I2C NAK interrupt. Asserted when an unexpected NAK has been received on the I2C bus.
            static constexpr bitfield_t<INTSET_t, 4, 4, bool> NAK = {};

            /// Write FIFO Overflow interrupt. This occurs when software tries to write to a full fifo.  The current operation does not stop.
            static constexpr bitfield_t<INTSET_t, 3, 3, bool> FOVFL = {};

            /// Read FIFO Underflow interrupt. This occurs when software tries to pop from an empty fifo.
            static constexpr bitfield_t<INTSET_t, 2, 2, bool> FUNDFL = {};

            /// FIFO Threshold interrupt. For write operations, asserted when the number of free bytes in the write FIFO equals or exceeds the WTHR field. For read operations, asserted when the number of valid bytes in the read FIFO equals of exceeds the value set in the RTHR field.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> THR = {};

            /// Command Complete interrupt. Asserted when the current operation has completed.   For repeated commands, this will only be asserted when the final repeated command is completed.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> CMDCMP = {};
        } INTSET = {};

        /**
         * CLKCFG - 4 bytes at offset 528
         * I/O Clock Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CLKCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x210> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x210>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF1F01;
            static constexpr uint32_t reset_value = 0x0;

            /// Clock total clock count minus 1. This provides the total period of the divided clock -1 when the DIVEN is active. The source clock is selected by FSEL.  Only applicable when DIVEN = 1.
            static constexpr bitfield_t<CLKCFG_t, 31, 24> TOTPER = {};

            /// Clock low clock count minus 1. This provides the number of clocks the divided clock will be low when the DIVEN = 1. Only applicable when DIVEN = 1.
            static constexpr bitfield_t<CLKCFG_t, 23, 16> LOWPER = {};

            /// Enable clock division by TOTPER and LOWPER
            static constexpr bitfield_t<CLKCFG_t, 12, 12, bool> DIVEN = {};

            /// Enable divide by 3 of the source IOCLK.  Division by 3 is done before the DIVEN programmable divider, and if enabled will provide the divided by 3 clock as the source to the programmable divider.
            static constexpr bitfield_t<CLKCFG_t, 11, 11, bool> DIV3 = {};

            /// Select the input clock frequency.
            static constexpr bitfield_t<CLKCFG_t, 10, 8, IOM4::FSELv> FSEL = {};

            /// Enable for the interface clock.  Must be enabled prior to executing any IO operations.
            static constexpr bitfield_t<CLKCFG_t, 0, 0, bool> IOCLKEN = {};
        } CLKCFG = {};

        /**
         * SUBMODCTRL - 4 bytes at offset 532
         * Submodule control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SUBMODCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x214> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x214>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x20;

            /// Submodule 0 module type.  This is the I2C Master interface
            static constexpr bitfield_t<SUBMODCTRL_t, 7, 5, IOM4::SMOD1TYPEv> SMOD1TYPE = {};

            /// Submodule 1 enable (1) or disable (0)
            static constexpr bitfield_t<SUBMODCTRL_t, 4, 4, bool> SMOD1EN = {};

            /// Submodule 0 module type.  This is the SPI Master interface.
            static constexpr bitfield_t<SUBMODCTRL_t, 3, 1, IOM4::SMOD0TYPEv> SMOD0TYPE = {};

            /// Submodule 0 enable (1) or disable (0)
            static constexpr bitfield_t<SUBMODCTRL_t, 0, 0, bool> SMOD0EN = {};
        } SUBMODCTRL = {};

        /**
         * CMD - 4 bytes at offset 536
         * Command and offset Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMD_t : reg_t<uint32_t, BASE_ADDRESS + 0x218> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x218>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF3FFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// This register holds the low order byte of offset to be used in the transaction. The number of offset bytes to use is set with bits 1:0 of the command.
            static constexpr bitfield_t<CMD_t, 31, 24> OFFSETLO = {};

            /// Command Specific selection information. Not used in Master I2C.  Used as CEn select for Master SPI transactions
            static constexpr bitfield_t<CMD_t, 21, 20> CMDSEL = {};

            /// Defines the transaction size in bytes.  The offset transfer is not included in this size.
            static constexpr bitfield_t<CMD_t, 19, 8> TSIZE = {};

            /// Contine to hold the bus after the current transaction if set to a 1 with a new command issued.
            static constexpr bitfield_t<CMD_t, 7, 7, bool> CONT = {};

            /// Number of offset bytes to use for the command - 0, 1, 2, 3 are valid selections. The second (byte 1) and third byte (byte 2) are read from the OFFSETHI register, and the low order byte is pulled from this register in the OFFSETLO field. Offset bytes are transmitted highest byte first.  EG if offsetcnt == 3, OFFSETHI[15:8] will be transmitted first, then OFFSETHI[7:0] then OFFSETLO. If offsetcnt == 2, OFFSETHI[7:0] will be transmitted, then OFFSETLO. If offsetcnt == 1, only OFFSETLO will be transmitted. Offset bytes are always transmitted MSB first, regardless of the value of the LSB control bit within the module configuration.
            static constexpr bitfield_t<CMD_t, 6, 5> OFFSETCNT = {};

            /// Command for submodule.
            static constexpr bitfield_t<CMD_t, 4, 0, IOM4::CMDv> CMD = {};
        } CMD = {};

        /**
         * DCX - 4 bytes at offset 540
         * DCX Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DCX_t : reg_t<uint32_t, BASE_ADDRESS + 0x21C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x21C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// Revision A: MUST NOT be programmed!  Revision B: Bit 4: DCX Signaling Enable via other CE signals. The selected DCX signal (unused CE pin) will be driven low during write of offset byte, and high during transmission of data bytes.
            static constexpr bitfield_t<DCX_t, 4, 4, bool> DCXEN = {};

            /// Revision A: MUST NOT be programmed!  Revision B: Enable DCX output for CE3 output.
            static constexpr bitfield_t<DCX_t, 3, 3, bool> CE3OUT = {};

            /// Revision A: MUST NOT be programmed!  Revision B: Enable DCX output for CE2 output.
            static constexpr bitfield_t<DCX_t, 2, 2, bool> CE2OUT = {};

            /// Revision A: MUST NOT be programmed!  Revision B: Enable DCX output for CE1 output.
            static constexpr bitfield_t<DCX_t, 1, 1, bool> CE1OUT = {};

            /// Revision A: MUST NOT be programmed!  Revision B: Enable DCX output for CE0 output.
            static constexpr bitfield_t<DCX_t, 0, 0, bool> CE0OUT = {};
        } DCX = {};

        /**
         * OFFSETHI - 4 bytes at offset 544
         * High order 2 bytes of 3 byte offset for IO transaction
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct OFFSETHI_t : reg_t<uint32_t, BASE_ADDRESS + 0x220> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x220>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Holds the high order 2 bytes of the 3 byte addressing/offset field to use with IO commands.  The number of offset bytes to use is specified in the command register
            static constexpr bitfield_t<OFFSETHI_t, 15, 0> OFFSETHI = {};
        } OFFSETHI = {};

        /**
         * CMDSTAT - 4 bytes at offset 548
         * Command status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CMDSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x224> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x224>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// The current number of bytes still to be transferred with this command.  This field will count down to zero.
            static constexpr bitfield_t<CMDSTAT_t, 19, 8> CTSIZE = {};

            /// The current status of the command execution.
            static constexpr bitfield_t<CMDSTAT_t, 7, 5, IOM4::CMDSTATv> CMDSTAT = {};

            /// current command that is being executed
            static constexpr bitfield_t<CMDSTAT_t, 4, 0> CCMD = {};
        } CMDSTAT = {};

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

            /// Trigger DMA upon THR level reached. For M2P DMA operations (IOM writes), the trigger will assert when the write FIFO has (WTHR/4) number of words free in the write FIFO, and will transfer (WTHR/4) number of words or, if the number of words left to transfer is less than the WTHR value, will transfer the remaining byte count. For P2M DMA operations, the trigger will assert when the read FIFO has (RTHR/4) words available in the read FIFO, and will transfer (RTHR/4) words to SRAM. This trigger will NOT assert when the transaction completes and there are less than RTHR bytes left in the fifo, since the RTHR has not been reached.  In this case, the CMDCMP trigger must also be enabled to transfer the remaining read FIFO data to SRAM.
            static constexpr bitfield_t<DMATRIGEN_t, 1, 1, bool> DTHREN = {};

            /// Trigger DMA upon command complete.  Enables the trigger of the DMA when a command is completed.  When this event is triggered, the number of words transferred will be the lesser of the remaining TOTCOUNT bytes, or
            static constexpr bitfield_t<DMATRIGEN_t, 0, 0, bool> DCMDCMPEN = {};
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
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// DMA triggered when DCMDCMP = 0, and the amount of data in the FIFO was enough to complete the DMA operation (greater than or equal to current TOTCOUNT) when the command completed. This trigger is default active when the DCMDCMP trigger is disabled and there is enough data in the FIFO to complete the DMA operation.
            static constexpr bitfield_t<DMATRIGSTAT_t, 2, 2, bool> DTOTCMP = {};

            /// Triggered DMA from THR event. Bit is read only and can be cleared by disabling the DTHR trigger enable or by disabling DMA.
            static constexpr bitfield_t<DMATRIGSTAT_t, 1, 1, bool> DTHR = {};

            /// Triggered DMA from Command complete event.   Bit is read only and can be cleared by disabling the DCMDCMP trigger enable or by disabling DMA.
            static constexpr bitfield_t<DMATRIGSTAT_t, 0, 0, bool> DCMDCMP = {};
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
            static constexpr uint32_t reset_mask  = 0x303;
            static constexpr uint32_t reset_value = 0x0;

            /// Power off module after DMA is complete.  If this bit is active, the module will request to power off the supply it is attached to. If there are other units still requiring power from the same domain, power down will not be performed.
            static constexpr bitfield_t<DMACFG_t, 9, 9, bool> DPWROFF = {};

            /// Sets the Priority of the DMA request
            static constexpr bitfield_t<DMACFG_t, 8, 8, bool> DMAPRI = {};

            /// Direction
            static constexpr bitfield_t<DMACFG_t, 1, 1, bool> DMADIR = {};

            /// DMA Enable. Setting this bit to EN will start the DMA operation. This should be the last DMA related register set prior to issuing the command
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
            static constexpr uint32_t reset_mask  = 0xFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Triggered DMA from Command complete event occured.   Bit is read only and can be cleared by disabling the DTHR trigger enable or by disabling DMA.
            static constexpr bitfield_t<DMATOTCOUNT_t, 11, 0> TOTCOUNT = {};
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
            static constexpr uint32_t reset_mask  = 0x100FFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Bit 28 of the target byte address for source of DMA (either read or write). In cases of non-word aligned addresses, the DMA logic will take care for ensuring only the target bytes are read/written. Setting to '1' will select the SRAM.  Setting to '0' will select the flash
            static constexpr bitfield_t<DMATARGADDR_t, 28, 28, bool> TARGADDR28 = {};

            /// Bits [19:0] of the target byte address for source of DMA (either read or write). The address can be any byte alignment, and does not have to be word aligned.  In cases of non-word aligned addresses, the DMA logic will take care for ensuring only the target bytes are read/written.
            static constexpr bitfield_t<DMATARGADDR_t, 19, 0> TARGADDR = {};
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

            /// DMA Error. This active high bit signals an error was encountered during the DMA operation. The bit can be cleared by writing to 0.  Once set, this bit will remain set until cleared by software.
            static constexpr bitfield_t<DMASTAT_t, 2, 2, bool> DMAERR = {};

            /// DMA Transfer Complete. This signals the end of the DMA operation.  This bit can be cleared by writing to 0, and will also be cleared when a new DMA is started.
            static constexpr bitfield_t<DMASTAT_t, 1, 1, bool> DMACPL = {};

            /// DMA Transfer In Progress indicator.  1 will indicate that a DMA transfer is active.  The DMA transfer may be waiting on data, transferring data, or waiting for priority. All of these will be indicated with a 1.  A 0 will indicate that the DMA is fully complete and no further transactions will be done.  This bit is read only.
            static constexpr bitfield_t<DMASTAT_t, 0, 0, bool> DMATIP = {};
        } DMASTAT = {};

        /**
         * CQCFG - 4 bytes at offset 660
         * Command Queue Configuration Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x294> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x294>::operator=;
            static constexpr uint32_t reset_mask  = 0x3;
            static constexpr uint32_t reset_value = 0x0;

            /// Sets the Priority of the command queue dma request
            static constexpr bitfield_t<CQCFG_t, 1, 1, bool> CQPRI = {};

            /// Command queue enable. When set, will enable the processing of the command queue and fetches of address/data pairs will proceed from the word address within the CQADDR register.  Can be disabled using a CQ executed write to this bit as well.
            static constexpr bitfield_t<CQCFG_t, 0, 0, bool> CQEN = {};
        } CQCFG = {};

        /**
         * CQADDR - 4 bytes at offset 664
         * CQ Target Read Address Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x298> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x298>::operator=;
            static constexpr uint32_t reset_mask  = 0x100FFFFC;
            static constexpr uint32_t reset_value = 0x0;

            /// Bit 28 of target byte address for source of CQ.  Used to denote Flash (0) or SRAM (1) access
            static constexpr bitfield_t<CQADDR_t, 28, 28, bool> CQADDR28 = {};

            /// Bits 19:2 of target byte address for source of CQ. The buffer must be aligned on a word boundary
            static constexpr bitfield_t<CQADDR_t, 19, 2> CQADDR = {};
        } CQADDR = {};

        /**
         * CQSTAT - 4 bytes at offset 668
         * Command Queue Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x29C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x29C>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// Command queue processing  Error. This active high bit signals that an error was encountered during the CQ  operation.
            static constexpr bitfield_t<CQSTAT_t, 2, 2, bool> CQERR = {};

            /// Command queue operation is currently paused.
            static constexpr bitfield_t<CQSTAT_t, 1, 1, bool> CQPAUSED = {};

            /// Command queue Transfer In Progress indicator.  1 will indicate that a CQ transfer is active and this will remain active even when paused waiting for external event.
            static constexpr bitfield_t<CQSTAT_t, 0, 0, bool> CQTIP = {};
        } CQSTAT = {};

        /**
         * CQFLAGS - 4 bytes at offset 672
         * Command Queue Flag Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQFLAGS_t : reg_t<uint32_t, BASE_ADDRESS + 0x2A0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2A0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Mask the bits used to generate the command queue interrupt.  A '1' in the bit position will enable the pause event to trigger the interrupt, if the CQWT_int interrupt is enabled. Bits definitions are the same as CQPAUSE
            static constexpr bitfield_t<CQFLAGS_t, 31, 16> CQIRQMASK = {};

            /// Current flag status (read-only).  Bits [7:0] are software controllable and bits [15:8] are hardware status.
            static constexpr bitfield_t<CQFLAGS_t, 15, 0> CQFLAGS = {};
        } CQFLAGS = {};

        /**
         * CQSETCLEAR - 4 bytes at offset 676
         * Command Queue Flag Set/Clear Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQSETCLEAR_t : reg_t<uint32_t, BASE_ADDRESS + 0x2A4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2A4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clear CQFlag status bits. Will clear to 0 any SWFLAG with a '1' in the corresponding bit position of this field
            static constexpr bitfield_t<CQSETCLEAR_t, 23, 16> CQFCLR = {};

            /// Toggle the indicated bit. Will toggle the value of any SWFLAG with a '1' in the corresponding bit position of this field
            static constexpr bitfield_t<CQSETCLEAR_t, 15, 8> CQFTGL = {};

            /// Set CQFlag status bits.  Will set to 1 the value of any SWFLAG with a '1' in the corresponding bit position of this field
            static constexpr bitfield_t<CQSETCLEAR_t, 7, 0> CQFSET = {};
        } CQSETCLEAR = {};

        /**
         * CQPAUSEEN - 4 bytes at offset 680
         * Command Queue Pause Enable Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQPAUSEEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x2A8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2A8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables the specified event to pause command processing when active
            static constexpr bitfield_t<CQPAUSEEN_t, 15, 0, IOM4::CQPENv> CQPEN = {};
        } CQPAUSEEN = {};

        /**
         * CQCURIDX - 4 bytes at offset 684
         * IOM Command Queue current index value . Compared to the CQENDIDX reg contents to generate the IDXEQ Pause event for command queue
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQCURIDX_t : reg_t<uint32_t, BASE_ADDRESS + 0x2AC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2AC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Holds 8 bits of data that will be compared with the CQENDIX register field.  If the values match, the IDXEQ pause event will be activated, which will cause the pausing of command quue operation if the IDXEQ bit is enabled in CQPAUSEEN.
            static constexpr bitfield_t<CQCURIDX_t, 7, 0> CQCURIDX = {};
        } CQCURIDX = {};

        /**
         * CQENDIDX - 4 bytes at offset 688
         * IOM Command Queue current index value . Compared to the CQCURIDX reg contents to generate the IDXEQ Pause event for command queue
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQENDIDX_t : reg_t<uint32_t, BASE_ADDRESS + 0x2B0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2B0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Holds 8 bits of data that will be compared with the CQCURIX register field.  If the values match, the IDXEQ pause event will be activated, which will cause the pausing of command quue operation if the IDXEQ bit is enabled in CQPAUSEEN.
            static constexpr bitfield_t<CQENDIDX_t, 7, 0> CQENDIDX = {};
        } CQENDIDX = {};

        /**
         * STATUS - 4 bytes at offset 692
         * IOM Module Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STATUS_t : reg_t<uint32_t, BASE_ADDRESS + 0x2B4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2B4>::operator=;
            static constexpr uint32_t reset_mask  = 0x7;
            static constexpr uint32_t reset_value = 0x0;

            /// indicates if the active I/O state machine is IDLE. Note - The state machine could be in idle state due to holdoffs from data availability, or as the command gets propagated into the logic from the registers.
            static constexpr bitfield_t<STATUS_t, 2, 2, bool> IDLEST = {};

            /// Indicates if the active I/O Command is currently processing a transaction, or command is complete, but the FIFO pointers are still syncronizing internally.  This bit will go high at the start of the transaction, and will go low when the command is complete, and the data and pointers within the FIFO have been syncronized.
            static constexpr bitfield_t<STATUS_t, 1, 1, bool> CMDACT = {};

            /// Bit has been deprecated.  Please refer to the other error indicators.  This will always return 0.
            static constexpr bitfield_t<STATUS_t, 0, 0, bool> ERR = {};
        } STATUS = {};

        /**
         * MSPICFG - 4 bytes at offset 768
         * SPI module master configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MSPICFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x300> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x300>::operator=;
            static constexpr uint32_t reset_mask  = 0x7FF70007;
            static constexpr uint32_t reset_value = 0x200000;

            /// Not used.  To reset the module, toggle the SMOD_EN for the module
            static constexpr bitfield_t<MSPICFG_t, 30, 30, bool> MSPIRST = {};

            /// Delay tap to use for the output signal (MOSI).  This give more hold time on the output data
            static constexpr bitfield_t<MSPICFG_t, 29, 27> DOUTDLY = {};

            /// Delay tap to use for the input signal (MISO).  This gives more hold time on the input data.
            static constexpr bitfield_t<MSPICFG_t, 26, 24> DINDLY = {};

            /// Selects data transfer as MSB first (0) or LSB first (1) for the data portion of the SPI transaction.   The offset bytes are always transmitted MSB first.
            static constexpr bitfield_t<MSPICFG_t, 23, 23, bool> SPILSB = {};

            /// selects the read flow control signal polarity.
            static constexpr bitfield_t<MSPICFG_t, 22, 22, bool> RDFCPOL = {};

            /// selects the write flow control signal polarity. The transfers are halted when the selected flow control signal is OPPOSITE polarity of bit. (For example: WTFCPOL = 0 will allow a IRQ=1 to pause transfers).
            static constexpr bitfield_t<MSPICFG_t, 21, 21, bool> WTFCPOL = {};

            /// selects the write mode flow control signal.
            static constexpr bitfield_t<MSPICFG_t, 20, 20, bool> WTFCIRQ = {};

            /// inverts MOSI when flow control is enabled.
            static constexpr bitfield_t<MSPICFG_t, 18, 18, bool> MOSIINV = {};

            /// enables read mode flow control.
            static constexpr bitfield_t<MSPICFG_t, 17, 17, bool> RDFC = {};

            /// enables write mode flow control.
            static constexpr bitfield_t<MSPICFG_t, 16, 16, bool> WTFC = {};

            /// Enables full duplex mode for Master SPI write operations.  Data will be captured simultaneously into the read fifo
            static constexpr bitfield_t<MSPICFG_t, 2, 2, bool> FULLDUP = {};

            /// selects SPI phase.
            static constexpr bitfield_t<MSPICFG_t, 1, 1, bool> SPHA = {};

            /// selects SPI polarity.
            static constexpr bitfield_t<MSPICFG_t, 0, 0, bool> SPOL = {};
        } MSPICFG = {};

        /**
         * MI2CCFG - 4 bytes at offset 1024
         * I2C Master configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MI2CCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x400> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x400>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFFF77;
            static constexpr uint32_t reset_value = 0x0;

            /// Disable detection of clock stretch events smaller than 1 cycle
            static constexpr bitfield_t<MI2CCFG_t, 24, 24, bool> STRDIS = {};

            /// Number of Base clk cycles to wait before sampling the SCL clock to determine if a clock stretch event has occured
            static constexpr bitfield_t<MI2CCFG_t, 23, 16> SMPCNT = {};

            /// Number of IOCLK cycles to delay the SDA output en (all transitions affected). Used to delay data relative to clock
            static constexpr bitfield_t<MI2CCFG_t, 15, 12> SDAENDLY = {};

            /// Number of IOCLK cycles to delay the rising edge of the SCL output en (clock will go low on this edge). Used to allow clock shaping.
            static constexpr bitfield_t<MI2CCFG_t, 11, 8> SCLENDLY = {};

            /// Not used.  To reset the module, toggle the SMOD_EN for the module
            static constexpr bitfield_t<MI2CCFG_t, 6, 6, bool> MI2CRST = {};

            /// Delay to enable on the SDA output.  Values are 0x0-0x3.
            static constexpr bitfield_t<MI2CCFG_t, 5, 4> SDADLY = {};

            /// Enables multi-master arbitration for the I2C master.  If the bus is known to have only a single master, this function can be disabled to save clock cycles on I2C transactions
            static constexpr bitfield_t<MI2CCFG_t, 2, 2, bool> ARBEN = {};

            /// Direction of data transmit and receive, MSB(0) or LSB(1) first.  Default per I2C specification is MSB first. This applies to both read and write data, and read data will be bit
            static constexpr bitfield_t<MI2CCFG_t, 1, 1, bool> I2CLSB = {};

            /// Sets the I2C master device address size to either 7b (0) or 10b (1).
            static constexpr bitfield_t<MI2CCFG_t, 0, 0, bool> ADDRSZ = {};
        } MI2CCFG = {};

        /**
         * DEVCFG - 4 bytes at offset 1028
         * I2C Device Configuration register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DEVCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x404> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x404>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FF;
            static constexpr uint32_t reset_value = 0x0;

            /// I2C address of the device that the Master will use to target for read/write operations.  This can be either a 7b or 10b address.
            static constexpr bitfield_t<DEVCFG_t, 9, 0> DEVADDR = {};
        } DEVCFG = {};

        /**
         * IOMDBG - 4 bytes at offset 1040
         * IOM Debug Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOMDBG_t : reg_t<uint32_t, BASE_ADDRESS + 0x410> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x410>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Debug control for various options.   DBGDATA[1:0] is used to select between different debug data available in the DBG0 and DBG1 registers.
            static constexpr bitfield_t<IOMDBG_t, 31, 3> DBGDATA = {};

            /// APBCLK debug clock control.  Enable APB_CLK to be active when this bit is '1'.  Otherwise, the clock is controlled with gating from the logic as needed.
            static constexpr bitfield_t<IOMDBG_t, 2, 2, bool> APBCLKON = {};

            /// IOCLK debug clock control.  Enable IO_CLK to be active when this bit is '1'.  Otherwise, the clock is controlled with gating from the logic as needed.
            static constexpr bitfield_t<IOMDBG_t, 1, 1, bool> IOCLKON = {};

            /// Debug Enable.  Setting bit will enable the update of data within this register, otherwise it is clock gated for power savings
            static constexpr bitfield_t<IOMDBG_t, 0, 0, bool> DBGEN = {};
        } IOMDBG = {};
    };  // end of struct IOM4_t

} // namespace sfr