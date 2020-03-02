/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: MSPI
 * Multi-bit SPI Master
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace MSPI {
    
        /// Address Size. Address bytes to send from ADDR register
        enum class ASIZEv : uint32_t {
            A1 = 0x0, //< Send one address byte
            A2 = 0x1, //< Send two address bytes
            A3 = 0x2, //< Send three address bytes
            A4 = 0x3, //< Send four address bytes
        };
    
        /// Flash configuration for XIP and AUTO DMA operations. Controls value for SER (Slave Enable) for XIP operations and address generation for DMA/XIP modes. Also used to configure SPIFRF (frame format).
        enum class DEVCFGv : uint32_t {
            SERIAL0 = 0x1, //< Single bit SPI flash on chip select 0
            SERIAL1 = 0x2, //< Single bit SPI flash on chip select 1
            DUAL0 = 0x5, //< Dual SPI flash on chip select 0
            DUAL1 = 0x6, //< Dual bit SPI flash on chip select 1
            QUAD0 = 0x9, //< Quad SPI flash on chip select 0
            QUAD1 = 0xA, //< Quad SPI flash on chip select 1
            OCTAL0 = 0xD, //< Octal SPI flash on chip select 0
            OCTAL1 = 0xE, //< Octal SPI flash on chip select 1
            QUADPAIRED = 0xF, //< Dual Quad SPI flash on chip selects 0/1.
            QUADPAIRED_SERIAL = 0x3, //< Dual Quad SPI flash on chip selects 0/1, but transmit in serial mode for initialization operations
        };
    
        /// Clock Divider. Allows dividing 48 MHz base clock by integer multiples. Enumerations are provided for common frequency, but any integer divide from 48 MHz is allowed. Odd divide ratios will result in a 33/66 percent duty cycle with a long low clock pulse (to allow longer round-trip for read data).
        enum class CLKDIVv : uint32_t {
            CLK48 = 0x1, //< 48 MHz MSPI clock
            CLK24 = 0x2, //< 24 MHz MSPI clock
            CLK12 = 0x4, //< 12 MHz MSPI clock
            CLK6 = 0x8, //< 6 MHz MSPI clock
            CLK3 = 0x10, //< 3 MHz MSPI clock
            CLK1_5 = 0x20, //< 1.5 MHz MSPI clock
        };
    
        /// Selects which IOM is selected for CQ handshake status.
        enum class IOMSELv : uint32_t {
            IOM0 = 0x0, //< IOM0
            IOM1 = 0x1, //< IOM1
            IOM2 = 0x2, //< IOM2
            IOM3 = 0x3, //< IOM3
            IOM4 = 0x4, //< IOM4
            IOM5 = 0x5, //< IOM5
            DISABLED = 0x7, //< No IOM selected. Signals always zero.
        };
    
        /// Output pad enable configuration. Indicates which pads should be driven. Bits [3:0] are Quad0 data, [7:4] are Quad1 data, and [8] is clock.
        enum class OUTENv : uint32_t {
            QUAD0 = 0x10F, //< Quad0 (4 data + 1 clock)
            QUAD1 = 0x1F0, //< Quad1 (4 data + 1 clock)
            OCTAL = 0x1FF, //< Octal (8 data + 1 clock)
            SERIAL0 = 0x103, //< Serial (2 data + 1 clock)
        };
    
        /// Controls transmission of Micron XIP acknowledge cycles (Micron Flash devices only)
        enum class XIPACKv : uint32_t {
            NOACK = 0x0, //< No acknowledgment sent. Data IOs are tri-stated the first turnaround cycle
            ACK = 0x2, //< Positive acknowledgment sent. Data IOs are driven to 0 the first turnaround cycle to acknowledge XIP mode
            TERMINATE = 0x3, //< Negative acknowledgment sent. Data IOs are driven to 1 the first turnaround cycle to terminate XIP mode. XIPSENDI should be re-enabled for the next transfer
        };
    
        /// Sets the Priority of the DMA request
        enum class DMAPRIv : uint32_t {
            LOW = 0x0, //< Low Priority (service as best effort)
            HIGH = 0x1, //< High Priority (service immediately)
            AUTO = 0x2, //< Auto Priority (priority raised once TX FIFO empties or RX FIFO fills)
        };
    
        /// DMA Enable. Setting this bit to EN will start the DMA operation
        enum class DMAENv : uint32_t {
            DIS = 0x0, //< Disable DMA Function
            EN = 0x3, //< Enable HW controlled DMA Function to manage DMA to flash devices. HW will automatically handle issuance of instruction/address bytes based on settings in the FLASH register.
        };
    
        /// Current flag status (read-only). Bits [7:0] are software controllable and bits [15:8] are hardware status.
        enum class CQFLAGSv : uint32_t {
            STOP = 0x8000, //< CQ Stop Flag. When set, CQ processing will complete.
            CQIDX = 0x4000, //< CQ Index Pointers (CURIDX/ENDIDX) match.
            DMACPL = 0x800, //< DMA Complete Status (hardwired DMACPL bit in DMASTAT)
            CMDCPL = 0x400, //< PIO Operation completed (STATUS bit in CTRL register)
            IOM1READY = 0x200, //< IOM Buffer 1 Ready Status (from selected IOM). This status is the result of XNOR'ing the IOM0START with the incoming status from the IOM. When high, MSPI can send to the buffer.
            IOM0READY = 0x100, //< IOM Buffer 0 Ready Status (from selected IOM). This status is the result of XNOR'ing the IOM0START with the incoming status from the IOM. When high, MSPI can send to the buffer.
            SWFLAG7 = 0x80, //< Software flag 7. Can be used by software to start/pause operations.
            SWFLAG6 = 0x40, //< Software flag 6. Can be used by software to start/pause operations.
            SWFLAG5 = 0x20, //< Software flag 5. Can be used by software to start/pause operations.
            SWFLAG4 = 0x10, //< Software flag 4. Can be used by software to start/pause operations.
            SWFLAG3 = 0x8, //< Software flag 3. Can be used by software to start/pause operations.
            SWFLAG2 = 0x4, //< Software flag 2. Can be used by software to start/pause operations.
            SWFLAG1 = 0x2, //< Software flag 1. Can be used by software to start/pause operations.
            SWFLAG0 = 0x1, //< Software flag 0. Can be used by software to start/pause operations.
        };
    
        /// CQ will pause processing when ALL specified events are satisfied -- i.e. when (CQMASK and CQPAUSE)==CQMASK.
        enum class CQMASKv : uint32_t {
            STOP = 0x8000, //< CQ Stop Flag. When set, CQ processing will complete.
            CQIDX = 0x4000, //< CQ Index Pointers (CURIDX/ENDIDX) match.
            DMACPL = 0x800, //< DMA Complete Status (hardwired DMACPL bit in DMASTAT)
            CMDCPL = 0x400, //< PIO Operation completed (STATUS bit in CTRL register)
            IOM1READY = 0x200, //< IOM Buffer 1 Ready Status (from selected IOM). This status is the result of XNOR'ing the IOM0START with the incoming status from the IOM. When high, MSPI can send to the buffer.
            IOM0READY = 0x100, //< IOM Buffer 0 Ready Status (from selected IOM). This status is the result of XNOR'ing the IOM0START with the incoming status from the IOM. When high, MSPI can send to the buffer.
            SWFLAG7 = 0x80, //< Software flag 7. Can be used by software to start/pause operations.
            SWFLAG6 = 0x40, //< Software flag 6. Can be used by software to start/pause operations.
            SWFLAG5 = 0x20, //< Software flag 5. Can be used by software to start/pause operations.
            SWFLAG4 = 0x10, //< Software flag 4. Can be used by software to start/pause operations.
            SWFLAG3 = 0x8, //< Software flag 3. Can be used by software to start/pause operations.
            SWFLAG2 = 0x4, //< Software flag 2. Can be used by software to start/pause operations.
            SWFLAG1 = 0x2, //< Software flag 1. Can be used by software to start/pause operations.
            SWFLAG0 = 0x1, //< Software flag 0. Can be used by software to start/pause operations.
        };
    
    }   // namespace MSPI

    /// Multi-bit SPI Master
    template <addressType BASE_ADDRESS>
    struct MSPI_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CTRL - 4 bytes at offset 0
         * MSPI PIO Transfer Control/Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF0FCF;
            static constexpr uint32_t reset_value = 0x0;

            /// Number of bytes to transmit or receive (based on TXRX bit)
            static constexpr bitfield_t<CTRL_t, 31, 16> XFERBYTES = {};

            /// Enables data scrambling for PIO operations. This should only be used for data operations and never for commands to a device.
            static constexpr bitfield_t<CTRL_t, 11, 11, bool> PIOSCRAMBLE = {};

            /// 1 Indicates a TX operation, 0 indicates an RX operation of XFERBYTES
            static constexpr bitfield_t<CTRL_t, 10, 10, bool> TXRX = {};

            /// Indicates whether an instruction phase should be sent (see INSTR field and ISIZE field in CFG register)
            static constexpr bitfield_t<CTRL_t, 9, 9, bool> SENDI = {};

            /// Indicates whether an address phase should be sent (see ADDR register and ASIZE field in CFG register)
            static constexpr bitfield_t<CTRL_t, 8, 8, bool> SENDA = {};

            /// Indicates whether TX->RX turnaround cycles should be enabled for this operation (see TURNAROUND field in CFG register).
            static constexpr bitfield_t<CTRL_t, 7, 7, bool> ENTURN = {};

            /// 1 indicates data in FIFO is in big endian format (MSB first); 0 indicates little endian data (default, LSB first).
            static constexpr bitfield_t<CTRL_t, 6, 6, bool> BIGENDIAN = {};

            /// Flag indicating that the operation is a command that should be replicated to both devices in paired QUAD mode. This is typically only used when reading/writing configuration registers in paired flash devices (do not set for memory transfers).
            static constexpr bitfield_t<CTRL_t, 3, 3, bool> QUADCMD = {};

            /// Command status:  1 indicates controller is busy (command in progress)
            static constexpr bitfield_t<CTRL_t, 2, 2, bool> BUSY = {};

            /// Command status:  1 indicates command has completed. Cleared by writing 1 to this bit or starting a new transfer.
            static constexpr bitfield_t<CTRL_t, 1, 1, bool> STATUS = {};

            /// Write to 1 to initiate a PIO transaction on the bus (typically the entire register should be written at once with this bit set).
            static constexpr bitfield_t<CTRL_t, 0, 0, bool> START = {};
        } CTRL = {};

        /**
         * CFG - 4 bytes at offset 4
         * MSPI Transfer Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x33FFF;
            static constexpr uint32_t reset_value = 0x1;

            /// Serial clock polarity.
            static constexpr bitfield_t<CFG_t, 17, 17, bool> CPOL = {};

            /// Serial clock phase.
            static constexpr bitfield_t<CFG_t, 16, 16, bool> CPHA = {};

            /// Number of turnaround cycles (for TX->RX transitions). Qualified by ENTURN or XIPENTURN bit field.
            static constexpr bitfield_t<CFG_t, 13, 8> TURNAROUND = {};

            /// Separate IO configuration. This bit should be set when the target device has separate MOSI and MISO pins. Respective IN/OUT bits below should be set to map pins.
            static constexpr bitfield_t<CFG_t, 7, 7, bool> SEPIO = {};

            /// Instruction Size enum   name    =   I8   value   =   0x0   desc    =   Instruction is 1 byte enum   name    =   I16   value   =   0x1   desc    =   Instruction is 2 bytes
            static constexpr bitfield_t<CFG_t, 6, 6, bool> ISIZE = {};

            /// Address Size. Address bytes to send from ADDR register
            static constexpr bitfield_t<CFG_t, 5, 4, MSPI::ASIZEv> ASIZE = {};

            /// Flash configuration for XIP and AUTO DMA operations. Controls value for SER (Slave Enable) for XIP operations and address generation for DMA/XIP modes. Also used to configure SPIFRF (frame format).
            static constexpr bitfield_t<CFG_t, 3, 0, MSPI::DEVCFGv> DEVCFG = {};
        } CFG = {};

        /**
         * ADDR - 4 bytes at offset 8
         * MSPI Transfer Address
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Optional Address field to send (after optional instruction field) - qualified by ASIZE in CMD register. NOTE:  This register is aliased to DMADEVADDR.
            static constexpr bitfield_t<ADDR_t, 31, 0> ADDR = {};
        } ADDR = {};

        /**
         * INSTR - 4 bytes at offset 12
         * MSPI Transfer Instruction
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INSTR_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Optional Instruction field to send (1st byte) - qualified by ISEND/ISIZE
            static constexpr bitfield_t<INSTR_t, 15, 0> INSTR = {};
        } INSTR = {};

        /**
         * TXFIFO - 4 bytes at offset 16
         * TX Data FIFO
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TXFIFO_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Data to be transmitted. Data should normally be aligned to the LSB (pad the upper bits with zeros) unless BIGENDIAN is set.
            static constexpr bitfield_t<TXFIFO_t, 31, 0> TXFIFO = {};
        } TXFIFO = {};

        /**
         * RXFIFO - 4 bytes at offset 20
         * RX Data FIFO
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RXFIFO_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Receive data. Data is aligned to the LSB (padded zeros on upper bits) unless BIGENDIAN is set.
            static constexpr bitfield_t<RXFIFO_t, 31, 0> RXFIFO = {};
        } RXFIFO = {};

        /**
         * TXENTRIES - 4 bytes at offset 24
         * TX FIFO Entries
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct TXENTRIES_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// Number of 32-bit words/entries in TX FIFO
            static constexpr bitfield_t<TXENTRIES_t, 4, 0> TXENTRIES = {};
        } TXENTRIES = {};

        /**
         * RXENTRIES - 4 bytes at offset 28
         * RX FIFO Entries
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RXENTRIES_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F;
            static constexpr uint32_t reset_value = 0x0;

            /// Number of 32-bit words/entries in RX FIFO
            static constexpr bitfield_t<RXENTRIES_t, 4, 0> RXENTRIES = {};
        } RXENTRIES = {};

        /**
         * THRESHOLD - 4 bytes at offset 32
         * TX/RX FIFO Threshold Levels
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct THRESHOLD_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0x1F1F;
            static constexpr uint32_t reset_value = 0x0;

            /// Number of entries in TX FIFO that cause RXE interrupt
            static constexpr bitfield_t<THRESHOLD_t, 12, 8> RXTHRESH = {};

            /// Number of entries in TX FIFO that cause TXF interrupt
            static constexpr bitfield_t<THRESHOLD_t, 4, 0> TXTHRESH = {};
        } THRESHOLD = {};

        /**
         * MSPICFG - 4 bytes at offset 256
         * MSPI Module Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct MSPICFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0xE0003F7F;
            static constexpr uint32_t reset_value = 0xC0000200;

            /// Peripheral reset. Master reset to the entire MSPI module (DMA, XIP, and transfer state machines). 1=normal operation, 0=in reset.
            static constexpr bitfield_t<MSPICFG_t, 31, 31, bool> PRSTN = {};

            /// IP block reset. Write to 0 to put the transfer module in reset or 1 for normal operation. This may be required after error conditions to clear the transfer on the bus.
            static constexpr bitfield_t<MSPICFG_t, 30, 30, bool> IPRSTN = {};

            /// Reset MSPI FIFO (active high). 1=reset FIFO, 0=normal operation. May be used to manually flush the FIFO in error handling.
            static constexpr bitfield_t<MSPICFG_t, 29, 29, bool> FIFORESET = {};

            /// Clock Divider. Allows dividing 48 MHz base clock by integer multiples. Enumerations are provided for common frequency, but any integer divide from 48 MHz is allowed. Odd divide ratios will result in a 33/66 percent duty cycle with a long low clock pulse (to allow longer round-trip for read data).
            static constexpr bitfield_t<MSPICFG_t, 13, 8, MSPI::CLKDIVv> CLKDIV = {};

            /// Selects which IOM is selected for CQ handshake status.
            static constexpr bitfield_t<MSPICFG_t, 6, 4, MSPI::IOMSELv> IOMSEL = {};

            /// Launches TX data a half clock cycle (~10 ns) early. This should normally be programmed to zero (NORMAL).
            static constexpr bitfield_t<MSPICFG_t, 3, 3, bool> TXNEG = {};

            /// Adjusts the RX capture phase to the negedge of the 48MHz internal clock (~10 ns early). For normal operation, it is expected that RXNEG will be set to 0.
            static constexpr bitfield_t<MSPICFG_t, 2, 2, bool> RXNEG = {};

            /// Controls RX data capture phase. A setting of 0 (NORMAL) captures read data at the normal capture point relative to the internal clock launch point. However, to accommodate chip/pad/board delays, a setting of RXCAP of 1 is expected to be used to align the capture point with the return data window. This bit is used in conjunction with RXNEG to provide 4 unique capture points, all about 10 ns apart.
            static constexpr bitfield_t<MSPICFG_t, 1, 1, bool> RXCAP = {};

            /// Enable continuous APB clock. For power-efficient operation, APBCLK should be set to 0.
            static constexpr bitfield_t<MSPICFG_t, 0, 0, bool> APBCLK = {};
        } MSPICFG = {};

        /**
         * PADCFG - 4 bytes at offset 260
         * MSPI Output Pad Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F001F;
            static constexpr uint32_t reset_value = 0x0;

            /// Reverse CS connections. Allows CS1 to be associated with lower data lanes and CS0 to be associated with upper data lines
            static constexpr bitfield_t<PADCFG_t, 21, 21, bool> REVCS = {};

            /// Data Input pad 3 pin muxing: 0=pad[3] 1=pad[7]
            static constexpr bitfield_t<PADCFG_t, 20, 20, bool> IN3 = {};

            /// Data Input pad 2 pin muxing: 0=pad[2] 1=pad[6]
            static constexpr bitfield_t<PADCFG_t, 19, 19, bool> IN2 = {};

            /// Data Input pad 1 pin muxing: 0=pad[1] 1=pad[5]
            static constexpr bitfield_t<PADCFG_t, 18, 18, bool> IN1 = {};

            /// Data Input pad 0 pin muxing:  0=pad[0] 1=pad[4] 2=pad[1] 3=pad[5]
            static constexpr bitfield_t<PADCFG_t, 17, 16> IN0 = {};

            /// Output pad 7 configuration. 0=data[7] 1=data[3]
            static constexpr bitfield_t<PADCFG_t, 4, 4, bool> OUT7 = {};

            /// Output pad 6 configuration. 0=data[6] 1=data[2]
            static constexpr bitfield_t<PADCFG_t, 3, 3, bool> OUT6 = {};

            /// Output pad 5 configuration. 0=data[5] 1=data[1]
            static constexpr bitfield_t<PADCFG_t, 2, 2, bool> OUT5 = {};

            /// Output pad 4 configuration. 0=data[4] 1=data[0]
            static constexpr bitfield_t<PADCFG_t, 1, 1, bool> OUT4 = {};

            /// Output pad 3 configuration. 0=data[3] 1=CLK
            static constexpr bitfield_t<PADCFG_t, 0, 0, bool> OUT3 = {};
        } PADCFG = {};

        /**
         * PADOUTEN - 4 bytes at offset 264
         * MSPI Output Enable Pad Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADOUTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Output pad enable configuration. Indicates which pads should be driven. Bits [3:0] are Quad0 data, [7:4] are Quad1 data, and [8] is clock.
            static constexpr bitfield_t<PADOUTEN_t, 8, 0, MSPI::OUTENv> OUTEN = {};
        } PADOUTEN = {};

        /**
         * FLASH - 4 bytes at offset 268
         * Configuration for XIP/DMA support of SPI flash modules.
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct FLASH_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF07FD;
            static constexpr uint32_t reset_value = 0xB060000;

            /// Read command sent to flash for DMA/XIP operations
            static constexpr bitfield_t<FLASH_t, 31, 24> READINSTR = {};

            /// Write command sent for DMA operations
            static constexpr bitfield_t<FLASH_t, 23, 16> WRITEINSTR = {};

            /// Reserved. Set to 0x0
            static constexpr bitfield_t<FLASH_t, 10, 8> XIPMIXED = {};

            /// Indicates whether XIP/AUTO DMA operations should send an instruction (see READINSTR field and ISIZE field in CFG)
            static constexpr bitfield_t<FLASH_t, 7, 7, bool> XIPSENDI = {};

            /// Indicates whether XIP/AUTO DMA operations should send an an address phase (see DMADEVADDR register and ASIZE field in CFG)
            static constexpr bitfield_t<FLASH_t, 6, 6, bool> XIPSENDA = {};

            /// Indicates whether XIP/AUTO DMA operations should enable TX->RX turnaround cycles
            static constexpr bitfield_t<FLASH_t, 5, 5, bool> XIPENTURN = {};

            /// Indicates whether XIP/AUTO DMA data transfers are in big or little endian format
            static constexpr bitfield_t<FLASH_t, 4, 4, bool> XIPBIGENDIAN = {};

            /// Controls transmission of Micron XIP acknowledge cycles (Micron Flash devices only)
            static constexpr bitfield_t<FLASH_t, 3, 2, MSPI::XIPACKv> XIPACK = {};

            /// Enable the XIP (eXecute In Place) function which effectively enables the address decoding of the MSPI device in the flash/cache address space at address 0x04000000-0x07FFFFFF.
            static constexpr bitfield_t<FLASH_t, 0, 0, bool> XIPEN = {};
        } FLASH = {};

        /**
         * SCRAMBLING - 4 bytes at offset 288
         * External Flash Scrambling Controls
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCRAMBLING_t : reg_t<uint32_t, BASE_ADDRESS + 0x120> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x120>::operator=;
            static constexpr uint32_t reset_mask  = 0x83FF03FF;
            static constexpr uint32_t reset_value = 0x0;

            /// Enables Data Scrambling Region. When 1 reads and writes to the range will be scrambled. When 0, data will be read/written unmodified. Address range is specified in 64K granularity and the START/END ranges are included within the range.
            static constexpr bitfield_t<SCRAMBLING_t, 31, 31, bool> SCRENABLE = {};

            /// Scrambling region end address [25:16] (64K block granularity). The END block is the LAST block included in the scrambled address range.
            static constexpr bitfield_t<SCRAMBLING_t, 25, 16> SCREND = {};

            /// Scrambling region start address [25:16] (64K block granularity). The START block is the FIRST block included in the scrambled address range.
            static constexpr bitfield_t<SCRAMBLING_t, 9, 0> SCRSTART = {};
        } SCRAMBLING = {};

        /**
         * INTEN - 4 bytes at offset 512
         * MSPI Master Interrupts: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scrambling Alignment Error. Scrambling operations must be aligned to word (4-byte) start address.
            static constexpr bitfield_t<INTEN_t, 12, 12, bool> SCRERR = {};

            /// Command Queue Error Interrupt
            static constexpr bitfield_t<INTEN_t, 11, 11, bool> CQERR = {};

            /// Command Queue is Paused.
            static constexpr bitfield_t<INTEN_t, 10, 10, bool> CQPAUSED = {};

            /// Command Queue Update Interrupt. Issued whenever the CQ performs an operation where address bit[0] is set. Useful for triggering CURIDX interrupts.
            static constexpr bitfield_t<INTEN_t, 9, 9, bool> CQUPD = {};

            /// Command Queue Complete Interrupt
            static constexpr bitfield_t<INTEN_t, 8, 8, bool> CQCMP = {};

            /// DMA Error Interrupt
            static constexpr bitfield_t<INTEN_t, 7, 7, bool> DERR = {};

            /// DMA Complete Interrupt
            static constexpr bitfield_t<INTEN_t, 6, 6, bool> DCMP = {};

            /// Receive FIFO full
            static constexpr bitfield_t<INTEN_t, 5, 5, bool> RXF = {};

            /// Receive FIFO overflow (cannot happen in MSPI design -- MSPI bus pins will stall)
            static constexpr bitfield_t<INTEN_t, 4, 4, bool> RXO = {};

            /// Receive FIFO underflow (only occurs when SW reads from an empty FIFO)
            static constexpr bitfield_t<INTEN_t, 3, 3, bool> RXU = {};

            /// Transmit FIFO Overflow (only occurs when SW writes to a full FIFO).
            static constexpr bitfield_t<INTEN_t, 2, 2, bool> TXO = {};

            /// Transmit FIFO empty.
            static constexpr bitfield_t<INTEN_t, 1, 1, bool> TXE = {};

            /// Transfer complete. Note that DMA and CQ operations are layered, so CMDCMP, DCMP, and CQ* can all be signaled simultaneously.
            static constexpr bitfield_t<INTEN_t, 0, 0, bool> CMDCMP = {};
        } INTEN = {};

        /**
         * INTSTAT - 4 bytes at offset 516
         * MSPI Master Interrupts: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scrambling Alignment Error. Scrambling operations must be aligned to word (4-byte) start address.
            static constexpr bitfield_t<INTSTAT_t, 12, 12, bool> SCRERR = {};

            /// Command Queue Error Interrupt
            static constexpr bitfield_t<INTSTAT_t, 11, 11, bool> CQERR = {};

            /// Command Queue is Paused.
            static constexpr bitfield_t<INTSTAT_t, 10, 10, bool> CQPAUSED = {};

            /// Command Queue Update Interrupt. Issued whenever the CQ performs an operation where address bit[0] is set. Useful for triggering CURIDX interrupts.
            static constexpr bitfield_t<INTSTAT_t, 9, 9, bool> CQUPD = {};

            /// Command Queue Complete Interrupt
            static constexpr bitfield_t<INTSTAT_t, 8, 8, bool> CQCMP = {};

            /// DMA Error Interrupt
            static constexpr bitfield_t<INTSTAT_t, 7, 7, bool> DERR = {};

            /// DMA Complete Interrupt
            static constexpr bitfield_t<INTSTAT_t, 6, 6, bool> DCMP = {};

            /// Receive FIFO full
            static constexpr bitfield_t<INTSTAT_t, 5, 5, bool> RXF = {};

            /// Receive FIFO overflow (cannot happen in MSPI design -- MSPI bus pins will stall)
            static constexpr bitfield_t<INTSTAT_t, 4, 4, bool> RXO = {};

            /// Receive FIFO underflow (only occurs when SW reads from an empty FIFO)
            static constexpr bitfield_t<INTSTAT_t, 3, 3, bool> RXU = {};

            /// Transmit FIFO Overflow (only occurs when SW writes to a full FIFO).
            static constexpr bitfield_t<INTSTAT_t, 2, 2, bool> TXO = {};

            /// Transmit FIFO empty.
            static constexpr bitfield_t<INTSTAT_t, 1, 1, bool> TXE = {};

            /// Transfer complete. Note that DMA and CQ operations are layered, so CMDCMP, DCMP, and CQ* can all be signaled simultaneously.
            static constexpr bitfield_t<INTSTAT_t, 0, 0, bool> CMDCMP = {};
        } INTSTAT = {};

        /**
         * INTCLR - 4 bytes at offset 520
         * MSPI Master Interrupts: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTCLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scrambling Alignment Error. Scrambling operations must be aligned to word (4-byte) start address.
            static constexpr bitfield_t<INTCLR_t, 12, 12, bool> SCRERR = {};

            /// Command Queue Error Interrupt
            static constexpr bitfield_t<INTCLR_t, 11, 11, bool> CQERR = {};

            /// Command Queue is Paused.
            static constexpr bitfield_t<INTCLR_t, 10, 10, bool> CQPAUSED = {};

            /// Command Queue Update Interrupt. Issued whenever the CQ performs an operation where address bit[0] is set. Useful for triggering CURIDX interrupts.
            static constexpr bitfield_t<INTCLR_t, 9, 9, bool> CQUPD = {};

            /// Command Queue Complete Interrupt
            static constexpr bitfield_t<INTCLR_t, 8, 8, bool> CQCMP = {};

            /// DMA Error Interrupt
            static constexpr bitfield_t<INTCLR_t, 7, 7, bool> DERR = {};

            /// DMA Complete Interrupt
            static constexpr bitfield_t<INTCLR_t, 6, 6, bool> DCMP = {};

            /// Receive FIFO full
            static constexpr bitfield_t<INTCLR_t, 5, 5, bool> RXF = {};

            /// Receive FIFO overflow (cannot happen in MSPI design -- MSPI bus pins will stall)
            static constexpr bitfield_t<INTCLR_t, 4, 4, bool> RXO = {};

            /// Receive FIFO underflow (only occurs when SW reads from an empty FIFO)
            static constexpr bitfield_t<INTCLR_t, 3, 3, bool> RXU = {};

            /// Transmit FIFO Overflow (only occurs when SW writes to a full FIFO).
            static constexpr bitfield_t<INTCLR_t, 2, 2, bool> TXO = {};

            /// Transmit FIFO empty.
            static constexpr bitfield_t<INTCLR_t, 1, 1, bool> TXE = {};

            /// Transfer complete. Note that DMA and CQ operations are layered, so CMDCMP, DCMP, and CQ* can all be signaled simultaneously.
            static constexpr bitfield_t<INTCLR_t, 0, 0, bool> CMDCMP = {};
        } INTCLR = {};

        /**
         * INTSET - 4 bytes at offset 524
         * MSPI Master Interrupts: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INTSET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scrambling Alignment Error. Scrambling operations must be aligned to word (4-byte) start address.
            static constexpr bitfield_t<INTSET_t, 12, 12, bool> SCRERR = {};

            /// Command Queue Error Interrupt
            static constexpr bitfield_t<INTSET_t, 11, 11, bool> CQERR = {};

            /// Command Queue is Paused.
            static constexpr bitfield_t<INTSET_t, 10, 10, bool> CQPAUSED = {};

            /// Command Queue Update Interrupt. Issued whenever the CQ performs an operation where address bit[0] is set. Useful for triggering CURIDX interrupts.
            static constexpr bitfield_t<INTSET_t, 9, 9, bool> CQUPD = {};

            /// Command Queue Complete Interrupt
            static constexpr bitfield_t<INTSET_t, 8, 8, bool> CQCMP = {};

            /// DMA Error Interrupt
            static constexpr bitfield_t<INTSET_t, 7, 7, bool> DERR = {};

            /// DMA Complete Interrupt
            static constexpr bitfield_t<INTSET_t, 6, 6, bool> DCMP = {};

            /// Receive FIFO full
            static constexpr bitfield_t<INTSET_t, 5, 5, bool> RXF = {};

            /// Receive FIFO overflow (cannot happen in MSPI design -- MSPI bus pins will stall)
            static constexpr bitfield_t<INTSET_t, 4, 4, bool> RXO = {};

            /// Receive FIFO underflow (only occurs when SW reads from an empty FIFO)
            static constexpr bitfield_t<INTSET_t, 3, 3, bool> RXU = {};

            /// Transmit FIFO Overflow (only occurs when SW writes to a full FIFO).
            static constexpr bitfield_t<INTSET_t, 2, 2, bool> TXO = {};

            /// Transmit FIFO empty.
            static constexpr bitfield_t<INTSET_t, 1, 1, bool> TXE = {};

            /// Transfer complete. Note that DMA and CQ operations are layered, so CMDCMP, DCMP, and CQ* can all be signaled simultaneously.
            static constexpr bitfield_t<INTSET_t, 0, 0, bool> CMDCMP = {};
        } INTSET = {};

        /**
         * DMACFG - 4 bytes at offset 592
         * DMA Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMACFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x250> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x250>::operator=;
            static constexpr uint32_t reset_mask  = 0x4001F;
            static constexpr uint32_t reset_value = 0x0;

            /// Power off MSPI domain upon completion of DMA operation.
            static constexpr bitfield_t<DMACFG_t, 18, 18, bool> DMAPWROFF = {};

            /// Sets the Priority of the DMA request
            static constexpr bitfield_t<DMACFG_t, 4, 3, MSPI::DMAPRIv> DMAPRI = {};

            /// Direction
            static constexpr bitfield_t<DMACFG_t, 2, 2, bool> DMADIR = {};

            /// DMA Enable. Setting this bit to EN will start the DMA operation
            static constexpr bitfield_t<DMACFG_t, 1, 0, MSPI::DMAENv> DMAEN = {};
        } DMACFG = {};

        /**
         * DMASTAT - 4 bytes at offset 596
         * DMA Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMASTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x254> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x254>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// Scrambling Access Alignment Error. This active high bit signals that a scrambling operation was specified for a non-word aligned DEVADDR.
            static constexpr bitfield_t<DMASTAT_t, 3, 3, bool> SCRERR = {};

            /// DMA Error. This active high bit signals that an error was encountered during the DMA operation.
            static constexpr bitfield_t<DMASTAT_t, 2, 2, bool> DMAERR = {};

            /// DMA Transfer Complete. This signals the end of the DMA operation.
            static constexpr bitfield_t<DMASTAT_t, 1, 1, bool> DMACPL = {};

            /// DMA Transfer In Progress indicator. 1 will indicate that a DMA transfer is active. The DMA transfer may be waiting on data, transferring data, or waiting for priority. All of these will be indicated with a 1. A 0 will indicate that the DMA is fully complete and no further transactions will be done.
            static constexpr bitfield_t<DMASTAT_t, 0, 0, bool> DMATIP = {};
        } DMASTAT = {};

        /**
         * DMATARGADDR - 4 bytes at offset 600
         * DMA Target Address
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATARGADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x258> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x258>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Target byte address for source of DMA (either read or write). In cases of non-word aligned addresses, the DMA logic will take care for ensuring only the target bytes are read/written.
            static constexpr bitfield_t<DMATARGADDR_t, 31, 0> TARGADDR = {};
        } DMATARGADDR = {};

        /**
         * DMADEVADDR - 4 bytes at offset 604
         * DMA Device Address
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMADEVADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x25C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x25C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// SPI Device address for automated DMA transactions (both read and write).
            static constexpr bitfield_t<DMADEVADDR_t, 31, 0> DEVADDR = {};
        } DMADEVADDR = {};

        /**
         * DMATOTCOUNT - 4 bytes at offset 608
         * DMA Total Transfer Count
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATOTCOUNT_t : reg_t<uint32_t, BASE_ADDRESS + 0x260> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x260>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Total Transfer Count in bytes.
            static constexpr bitfield_t<DMATOTCOUNT_t, 15, 0> TOTCOUNT = {};
        } DMATOTCOUNT = {};

        /**
         * DMABCOUNT - 4 bytes at offset 612
         * DMA BYTE Transfer Count
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMABCOUNT_t : reg_t<uint32_t, BASE_ADDRESS + 0x264> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x264>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Burst transfer size in bytes. This is the number of bytes transferred when a FIFO trigger event occurs. Recommended values are 16 or 32.
            static constexpr bitfield_t<DMABCOUNT_t, 7, 0> BCOUNT = {};
        } DMABCOUNT = {};

        /**
         * DMATHRESH - 4 bytes at offset 632
         * DMA Transmit Trigger Threshold
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct DMATHRESH_t : reg_t<uint32_t, BASE_ADDRESS + 0x278> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x278>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x8;

            /// DMA transfer FIFO level trigger. For read operations, DMA is triggered when the FIFO level is greater than this value. For write operations, DMA is triggered when the FIFO level is less than this level. Each DMA operation will consist of BCOUNT bytes.
            static constexpr bitfield_t<DMATHRESH_t, 3, 0> DMATHRESH = {};
        } DMATHRESH = {};

        /**
         * CQCFG - 4 bytes at offset 672
         * Command Queue Configuration
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x2A0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2A0>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// Enable clear of CQMASK after each pause operation. This may be useful when using software flags to pause CQ.
            static constexpr bitfield_t<CQCFG_t, 3, 3, bool> CQAUTOCLEARMASK = {};

            /// Power off MSPI domain upon completion of DMA operation.
            static constexpr bitfield_t<CQCFG_t, 2, 2, bool> CQPWROFF = {};

            /// Sets the Priority of the command queue DMA request
            static constexpr bitfield_t<CQCFG_t, 1, 1, bool> CQPRI = {};

            /// Command queue enable. When set, will enable the processing of the command queue
            static constexpr bitfield_t<CQCFG_t, 0, 0, bool> CQEN = {};
        } CQCFG = {};

        /**
         * CQADDR - 4 bytes at offset 680
         * CQ Target Read Address
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x2A8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2A8>::operator=;
            static constexpr uint32_t reset_mask  = 0x1FFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Address of command queue buffer in SRAM or flash. The buffer address must be aligned to a word boundary.
            static constexpr bitfield_t<CQADDR_t, 28, 0> CQADDR = {};
        } CQADDR = {};

        /**
         * CQSTAT - 4 bytes at offset 684
         * Command Queue Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x2AC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2AC>::operator=;
            static constexpr uint32_t reset_mask  = 0xF;
            static constexpr uint32_t reset_value = 0x0;

            /// Command queue is currently paused status.
            static constexpr bitfield_t<CQSTAT_t, 3, 3, bool> CQPAUSED = {};

            /// Command queue processing  Error. This active high bit signals that an error was encountered during the CQ  operation.
            static constexpr bitfield_t<CQSTAT_t, 2, 2, bool> CQERR = {};

            /// Command queue operation Complete. This signals the end of the command queue operation.
            static constexpr bitfield_t<CQSTAT_t, 1, 1, bool> CQCPL = {};

            /// Command queue Transfer In Progress indicator. 1 will indicate that a CQ transfer is active and this will remain active even when paused waiting for external event.
            static constexpr bitfield_t<CQSTAT_t, 0, 0, bool> CQTIP = {};
        } CQSTAT = {};

        /**
         * CQFLAGS - 4 bytes at offset 688
         * Command Queue Flags
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQFLAGS_t : reg_t<uint32_t, BASE_ADDRESS + 0x2B0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2B0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Current flag status (read-only). Bits [7:0] are software controllable and bits [15:8] are hardware status.
            static constexpr bitfield_t<CQFLAGS_t, 15, 0, MSPI::CQFLAGSv> CQFLAGS = {};
        } CQFLAGS = {};

        /**
         * CQSETCLEAR - 4 bytes at offset 692
         * Command Queue Flag Set/Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQSETCLEAR_t : reg_t<uint32_t, BASE_ADDRESS + 0x2B4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2B4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clear CQFlag status bits.
            static constexpr bitfield_t<CQSETCLEAR_t, 23, 16> CQFCLR = {};

            /// Toggle CQFlag status bits
            static constexpr bitfield_t<CQSETCLEAR_t, 15, 8> CQFTOGGLE = {};

            /// Set CQFlag status bits. Set has priority over clear if both are high.
            static constexpr bitfield_t<CQSETCLEAR_t, 7, 0> CQFSET = {};
        } CQSETCLEAR = {};

        /**
         * CQPAUSE - 4 bytes at offset 696
         * Command Queue Pause Mask
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQPAUSE_t : reg_t<uint32_t, BASE_ADDRESS + 0x2B8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2B8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CQ will pause processing when ALL specified events are satisfied -- i.e. when (CQMASK and CQPAUSE)==CQMASK.
            static constexpr bitfield_t<CQPAUSE_t, 15, 0, MSPI::CQMASKv> CQMASK = {};
        } CQPAUSE = {};

        /**
         * CQCURIDX - 4 bytes at offset 704
         * Command Queue Current Index
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQCURIDX_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Can be used to indicate the current position of the command  queue by having CQ operations write this field. A CQ hardware status flag indicates when CURIDX and ENDIDX are not equal, allowing SW to pause the CQ processing until the end index is updated.
            static constexpr bitfield_t<CQCURIDX_t, 7, 0> CQCURIDX = {};
        } CQCURIDX = {};

        /**
         * CQENDIDX - 4 bytes at offset 708
         * Command Queue End Index
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CQENDIDX_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Can be used to indicate the end position of the command queue. A CQ hardware status bit indices when CURIDX != ENDIDX so that the CQ can be paused when it reaches the end pointer.
            static constexpr bitfield_t<CQENDIDX_t, 7, 0> CQENDIDX = {};
        } CQENDIDX = {};
    };  // end of struct MSPI_t

} // namespace sfr