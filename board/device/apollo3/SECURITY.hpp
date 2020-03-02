/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: SECURITY
 * Security Interfaces
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace SECURITY {
    
        /// Function Select
        enum class FUNCTIONv : uint32_t {
            CRC32 = 0x0, //< Perform CRC32 operation
        };
    
        /// LOCK Function Select register.
        enum class SELECTv : uint32_t {
            CUSTOMER_KEY = 0x1, //< Unlock Customer Key (access to top half of info0)
            NONE = 0x0, //< Lock Control should be set to NONE when not in use.
        };
    
        /// LOCK Status register.  This register is a bitmask for which resources are currently unlocked.  These bits are one-hot per resource.
        enum class STATUSv : uint32_t {
            CUSTOMER_KEY = 0x1, //< Customer Key is unlocked (access is granted to top half of info0)
            NONE = 0x0, //< No resources are unlocked
        };
    
    }   // namespace SECURITY

    /// Security Interfaces
    template <addressType BASE_ADDRESS>
    struct SECURITY_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        /**
         * CTRL - 4 bytes at offset 0
         * Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x800000F1;
            static constexpr uint32_t reset_value = 0x0;

            /// CRC Error Status - Set to 1 if an error occurs during a CRC operation.  Cleared when CTRL register is written (with any value).  Usually indicates an invalid address range.
            static constexpr bitfield_t<CTRL_t, 31, 31, bool> CRCERROR = {};

            /// Function Select
            static constexpr bitfield_t<CTRL_t, 7, 4, SECURITY::FUNCTIONv> FUNCTION = {};

            /// Function Enable.  Software should set the ENABLE bit to initiate a CRC operation.  Hardware will clear the ENABLE bit upon completion.
            static constexpr bitfield_t<CTRL_t, 0, 0, bool> ENABLE = {};
        } CTRL = {};

        /**
         * SRCADDR - 4 bytes at offset 16
         * Source Addresss
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SRCADDR_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Source Buffer Address.  Address may be byte aligned, but the length must be a multiple of 4 bits.
            static constexpr bitfield_t<SRCADDR_t, 31, 0> ADDR = {};
        } SRCADDR = {};

        /**
         * LEN - 4 bytes at offset 32
         * Length
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct LEN_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFC;
            static constexpr uint32_t reset_value = 0x0;

            /// Buffer size (bottom two bits assumed to be zero to ensure a multiple of 4 bytes)
            static constexpr bitfield_t<LEN_t, 19, 2> LEN = {};
        } LEN = {};

        /**
         * RESULT - 4 bytes at offset 48
         * CRC Seed/Result Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RESULT_t : reg_t<uint32_t, BASE_ADDRESS + 0x30> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// CRC Seed/Result.  Software must seed the CRC with 0xFFFFFFFF before starting a CRC operation (unless the CRC is continued from a previous operation).
            static constexpr bitfield_t<RESULT_t, 31, 0> CRC = {};
        } RESULT = {};

        /**
         * LOCKCTRL - 4 bytes at offset 120
         * LOCK Control Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct LOCKCTRL_t : reg_t<uint32_t, BASE_ADDRESS + 0x78> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x78>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// LOCK Function Select register.
            static constexpr bitfield_t<LOCKCTRL_t, 7, 0, SECURITY::SELECTv> SELECT = {};
        } LOCKCTRL = {};

        /**
         * LOCKSTAT - 4 bytes at offset 124
         * LOCK Status Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct LOCKSTAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x7C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x7C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// LOCK Status register.  This register is a bitmask for which resources are currently unlocked.  These bits are one-hot per resource.
            static constexpr bitfield_t<LOCKSTAT_t, 31, 0, SECURITY::STATUSv> STATUS = {};
        } LOCKSTAT = {};

        /**
         * KEY0 - 4 bytes at offset 128
         * Key0 Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct KEY0_t : reg_t<uint32_t, BASE_ADDRESS + 0x80> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x80>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Bits [31:0] of the 128-bit key should be written to this register.  To protect key values, the register always returns 0x00000000.
            static constexpr bitfield_t<KEY0_t, 31, 0> KEY0 = {};
        } KEY0 = {};

        /**
         * KEY1 - 4 bytes at offset 132
         * Key1 Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct KEY1_t : reg_t<uint32_t, BASE_ADDRESS + 0x84> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x84>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Bits [63:32] of the 128-bit key should be written to this register.  To protect key values, the register always returns 0x00000000.
            static constexpr bitfield_t<KEY1_t, 31, 0> KEY1 = {};
        } KEY1 = {};

        /**
         * KEY2 - 4 bytes at offset 136
         * Key2 Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct KEY2_t : reg_t<uint32_t, BASE_ADDRESS + 0x88> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x88>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Bits [95:64] of the 128-bit key should be written to this register.  To protect key values, the register always returns 0x00000000.
            static constexpr bitfield_t<KEY2_t, 31, 0> KEY2 = {};
        } KEY2 = {};

        /**
         * KEY3 - 4 bytes at offset 140
         * Key3 Register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct KEY3_t : reg_t<uint32_t, BASE_ADDRESS + 0x8C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Bits [127:96] of the 128-bit key should be written to this register.  To protect key values, the register always returns 0x00000000.
            static constexpr bitfield_t<KEY3_t, 31, 0> KEY3 = {};
        } KEY3 = {};
    };  // end of struct SECURITY_t

} // namespace sfr