#pragma once
#pragma GCC diagnostic ignored "-Wreturn-local-addr"

#include <cstdint>
#include <utility>
#include <algorithm>

namespace sfr {

    using registerType = uint32_t;
    using addressType  = uint32_t;

    // Define access rights. Access rights can be redefined at any lower level.
    enum class AccessType {
        read_only,      ///< Read access is permitted. Write operations have an undefined result.
        write_only,     ///< Read operations have an undefined result. Write access is permitted.
        read_write,     ///< Read and write accesses are permitted. Writes affect the state of the register and reads return the register value.
        write_once,     ///< Read operations have an undefined results. Only the first write after reset has an effect.
        read_write_once ///< Read access is always permitted. Only the first write access after a reset will have an effect on the content. Other write operations have an undefined result.
    };

    // Specify the security privilege to access an address region. This information is relevant for the
    // programmer as well as the debugger when no universal access permissions have been granted.
    // If no specific information is provided, an address region is accessible in any mode.
    // The following values can be used to protect accesses by the programmer or debugger
    enum class Protection {
        secure,     ///< "s" - secure permission required for access
        privilaged, ///< "p" - privileged permission required for access
        none        ///< "n" - non-secure or secure permission required for access
    };

    // If set, it specifies the side effect following a read operation.
    enum class ReadEffect {
        none,           ///< No side effects from reading
        clear,          ///< The register/field is set to zeros following a read operation
        set,            ///< The register/field is set to ones following a read operation
        modify,         ///< The register/field is modified in some device specific way after a read operation
        modifyExternal  ///< One or more dependent resources are immediately affected by a read operation
    };

    // Element to describe the manipulation of data written to a register.
    enum class WriteEffect {
        none,          ///< No side effects from writing
        oneToClear,    ///< write data bits of one shall clear (set to zero) the corresponding bit in the register.
        oneToSet,      ///< write data bits of one shall set (set to one) the corresponding bit in the register.
        oneToToggle,   ///< write data bits of one shall toggle (invert) the corresponding bit in the register.
        zeroToClear,   ///< write data bits of zero shall clear (set to zero) the corresponding bit in the register.
        zeroToSet,     ///< write data bits of zero shall set (set to one) the corresponding bit in the register.
        zeroToToggle,  ///< write data bits of zero shall toggle (invert) the corresponding bit in the register.
        clear,         ///< after a write operation all bits in the field are cleared (set to zero).
        set,           ///< after a write operation all bits in the field are set (set to one).
        modify         ///< after a write operation all bit in the field may be modified (default).
    };

    template<typename reg_t, typename ...bitfield_t>
    void set(reg_t reg, bitfield_t... bitfields) {
        // TODO find a way to set many fields at once
        //static_assert((std::is_same_v<reg_t,decltype (bitfields)> & ...),"");
    }

    template <typename T>
    struct bitfield_value_t {
        T value;
        T mask;
        friend inline constexpr auto operator|(const bitfield_value_t& lhs, const bitfield_value_t& rhs) {
            return bitfield_value_t<T>{static_cast<T>(lhs.value | rhs.value), static_cast<T>(lhs.mask|rhs.mask)};
        }

        friend inline constexpr auto operator|=(const bitfield_value_t& lhs, const bitfield_value_t& rhs) {
            return bitfield_value_t<T>{static_cast<T>(lhs.value | rhs.value), static_cast<T>(lhs.mask|rhs.mask)};
        }

        friend inline constexpr auto operator|(T lhs, const bitfield_value_t& rhs) {
            return lhs | rhs.value;
        }
    };

    template <typename T, const uint32_t addr, AccessType access_type=AccessType::read_write>
    struct reg_t {
        static constexpr uint32_t address = addr;
        static constexpr AccessType access = access_type;
        using type = T;

        static inline volatile T& value() noexcept;

        static inline T read() noexcept {
            static_assert (access != AccessType::write_only, "this register is write-only, and can not be read!");
            static_assert (access != AccessType::read_write_once, "this register is read-write-once!");
            static_assert (access != AccessType::write_once, "this register may only be accessed once, and can not be read!");
            return *reinterpret_cast<volatile T *>(address);
        }

        static inline void write(const T val) noexcept {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once, "this register may only be accessed once!");
            static_assert (access != AccessType::read_write_once, "this register is read-write-once!");
            *reinterpret_cast<volatile T *>(address) = val;
        }

        inline constexpr reg_t operator=(const T& value) const noexcept {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            reg_t::value() = value;
            return reg_t<T,address>{};
        }

        template<typename U>
        inline constexpr auto operator=(const U& bit_field_value) const noexcept -> decltype (std::declval<U>().value, std::declval<U>().mask, std::declval<reg_t<T,address>>())
        {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            reg_t::value() = bit_field_value.value;
            return reg_t<T,address>{};
        }

        template<typename U>
        inline constexpr auto operator|=(const U& bit_field_value) const noexcept -> decltype (std::declval<U>().value, std::declval<U>().mask, std::declval<reg_t<T,address>>())
        {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            reg_t::value() = (reg_t::value() & ~bit_field_value.mask) | bit_field_value.value;
            return reg_t<T,address>{};
        }

        inline constexpr reg_t operator|=(const T& value) const noexcept {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            reg_t::value() |= value;
            return reg_t<T,address>{};
        }

        inline constexpr reg_t operator&=(const T& value) const noexcept {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            reg_t::value() &= value;
            return reg_t<T,address>{};
        }

        constexpr operator volatile T&() noexcept {
            static_assert (access != AccessType::read_only, "this register is read-only, and may not be written!");
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            return value();
        }

        constexpr operator const volatile T&() const noexcept {
            static_assert (access != AccessType::write_once && access != AccessType::read_write_once, "this register may only be accessed once!");
            static_assert (access != AccessType::write_only, "this register can only be written, not read!");
            return *reinterpret_cast<volatile T*>(address);
        }
    };

    template<typename T, uint32_t addr, AccessType access_type>
    volatile T &reg_t<T, addr, access_type>::value() noexcept  {
        return *reinterpret_cast<volatile T *>(address);
    }

    namespace details {
        template<typename T, unsigned start, unsigned stop>
        constexpr T compute_mask() {
            static_assert(start < 32,"start bit index must be < 32");
            static_assert(stop < 32,"stop bit index must be < 32");
            constexpr unsigned long long all_one = ~0ull;
            if constexpr(start == stop) {
                return static_cast<T>(1U << stop);
            }
            else {
                return static_cast<T>((all_one<<(stop+1)) xor (all_one<<start));
            }
        }
    }

    template <typename reg_type, int start_index, int stop_index=start_index, typename value_t=registerType, AccessType access_type=AccessType::read_write>
    struct bitfield_t {
        using reg_t = reg_type;
        using type = typename reg_t::type;

        static_assert(start_index < 32,"start bit index must be < 32");
        static_assert(stop_index < 32,"stop bit index must be < 32");
        static constexpr const int start = std::min(start_index, stop_index);
        static constexpr const int stop = std::max(start_index, stop_index);

        static constexpr const type mask = details::compute_mask<type, start, stop>();
        static constexpr AccessType access = access_type;

        static constexpr bitfield_value_t<type> shift(const value_t value) noexcept {
            return {static_cast<type>((static_cast<type>(value)<<start) & mask), mask};
        }

        inline constexpr bitfield_t operator=(const value_t& value) const noexcept {
            static_assert (access != AccessType::read_only, "this bit field is read-only, and may not be written!");
            typename reg_t::type tmp = shift(value).value;
            reg_t::value() = (reg_t::value() &  ~mask)|tmp;
            return bitfield_t<reg_t, start_index, stop_index, value_t>{};
        }

        constexpr operator value_t() noexcept {
            static_assert (access != AccessType::read_only, "this bit field is read-only, and may not be written!");
            return value_t(( static_cast<int>(reg_t::value()) & mask ) >> start);
        }

        constexpr operator value_t() const noexcept {
            return value_t(( static_cast<int>(reg_t::value()) & mask ) >> start);
        }
    };

    namespace  {

        template <int N>
        inline unsigned long long bitfield_cat(unsigned long long value, unsigned int width) {
            return (value<<(N*width)) | bitfield_cat<N-1>(value, width);
        }

        template <>
        inline unsigned long long bitfield_cat<0>(unsigned long long value, unsigned int width) {
            return value;
        }

    }

    template <std::size_t start_index, std::size_t width, typename reg_t, std::size_t count, typename value_t=int>
    struct bitfield_array_t {
        static constexpr const typename reg_t::type field_mask = details::compute_mask<typename reg_t::type, start_index, start_index + width-1>();
        static constexpr const typename reg_t::type mask = details::compute_mask<typename reg_t::type, start_index, start_index + (width*count)-1>();

        template<std::size_t i>
        using field_t = bitfield_t<reg_t, (i*width)+start_index, ((i+1)*width)+start_index-1, value_t>;

        template<std::size_t i>
        static constexpr auto get() noexcept {
            static_assert ((i>=0)and(i<count), "Bitfield index is out of bounds");
            return field_t<i>{};
        }

        template<typename T>
        inline constexpr bitfield_array_t operator=(const T& value) const noexcept {
            if constexpr(std::is_integral_v<T>)
                reg_t::write( mask & (value << start_index) );
            else if constexpr(std::conjunction_v<std::is_enum<T>, std::is_same<T,value_t>>) {
                auto v = bitfield_cat<count-1>(static_cast<unsigned long long>(value), width);
                reg_t::write( mask & (v << start_index) );
            }
            return bitfield_array_t<start_index,width,reg_t,count,value_t>{};
        }

        constexpr operator typename reg_t::type() noexcept {
            return typename reg_t::type((int(reg_t::read())& mask)>>start_index);
        }

        constexpr operator typename reg_t::type() const noexcept {
            return typename reg_t::type((int(reg_t::read())& mask)>>start_index);
        }
    };

}
