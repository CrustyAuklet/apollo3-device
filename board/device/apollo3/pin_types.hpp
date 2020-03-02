#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <algorithm>

namespace GPIO {
    template <class PORT, unsigned PIN>
    struct pin {
        static_assert(PIN < 49, "PIN value in gpio_pin must be a number 0-49");
        static constexpr PORT Port{};           // GPIO instance or port this pin uses

        /// sets the pin to the expected startup state. Base class version does nothing.
        constexpr void init() const noexcept {
        }

        /// Set the pin as an output
        constexpr void set_output() const noexcept {
        }

        /// Set the pin as in input
        constexpr void set_input() const noexcept {
        }

        /// Set the output level of the pin to low. Pin must be set as Output.
        constexpr void set_low() const noexcept {
        }

        /// Set the output level of the pin to high. Pin must be set as Output.
        constexpr void set_high() const noexcept {
        }

        /// Toggle the output level of the pin. Pin must be set as Output.
        constexpr void toggle() const noexcept {
        }

        /// set the level of the pin using a boolean argument
        constexpr void set_value(const bool level) const noexcept {
            if(level) { set_high(); }
            else { set_low(); }
        }

        /// get the current state of the pin. Digital input buffer must be enabled.
        [[nodiscard]] constexpr volatile bool get_value() const noexcept {
            return Port.IN & PIN_MASK;
        }

        /// return the state of the pin
        constexpr operator volatile bool&() noexcept {
            return get_value();
        }

        /// return the state of the pin as a constant value
        constexpr operator const volatile bool&() const noexcept {
            return get_value();
        }

        template <uint8_t INT_NUM>
        constexpr void enable_interrupt() const noexcept {
        }

        template <uint8_t INT_NUM>
        constexpr void disable_interrupt() const noexcept {
        }

        /// set the pin to a low-power state, enabling any settings that prevent leakage for an unused pin
        constexpr void set_lowpower() const noexcept { }
        /// set pin to an analog mode
        constexpr void set_analog() const noexcept { }

    };  // struct pin

    template <typename... Pins>
    struct PinGroup {
        static constexpr std::tuple<Pins...> m_pins{};  // tuple of all the pins used in this group
        static constexpr unsigned pin_count = std::tuple_size_v<decltype(m_pins)>;  // number of pins in this group
        static constexpr decltype( std::tuple_element_t<0, decltype(m_pins)>::Port ) m_port{};  // find underlying GPIO instance

//        static constexpr uint8_t m_shift = [](){ return std::min( {Pins::PIN_NUM...} ); }();
//        static constexpr uint8_t m_mask  = [](){ return std::apply([](auto&&... args){ return ((args.PIN_MASK) | ...); }, m_pins); }();

        static_assert(all_same_type(Pins::Port...), "All pins in a pin group must be on the same port!");
        static_assert(pin_count <= 8, "Only 8 or less pins can be in a pin group?");
        static_assert(pin_count > 1, "Only use a pin group for GROUPS of pins please!");

        /// constructor mainly to allow CTAD
        constexpr PinGroup(Pins... p) {};

        /// sets all pins to the expected startup state. Base class version does nothing.
        constexpr void init() const noexcept {
            std::apply([](auto&&... args){((args.init()), ...);}, m_pins);
        }

        /// configure all the pins with some OR value of flags in device::io::PinConfig
        constexpr void configure(const GPIO::PinConfig config) const noexcept {
            std::apply([config](auto&&... args){((args.configure(config)), ...);}, m_pins);
        }

        /// Set all pins as output
        constexpr void set_output() const noexcept {
//            m_port.DIRSET = m_mask;
        }

        /// Set all pins as input
        constexpr void set_input() const noexcept {
//            m_port.DIRCLR = m_mask;
        }

        /// reads the value of the pin set. The value is masked and shifted to be left aligned. No consideration is taken for non-contiguous pins.
        [[nodiscard]] constexpr volatile uint8_t read() const noexcept {
//            return (m_port.IN & m_mask) >> m_shift;
        }

        /// writes the given value to the pin set. Input value is masked and shifted. No consideration is taken for non-contiguous pins.
        constexpr void write(const uint8_t v) const noexcept {
//            const uint8_t temp = m_port.OUT;
//            m_port.OUT = (temp & ~m_mask) | ((v << m_shift) & m_mask);
        }
    };  // struct PinGroup

    /***************************************  PIN TYPE BUILDING BLOCKS  ******************************************/

    struct no_pin {
        constexpr void init() const noexcept { }
    };

    template <typename PIN_INSTANCE>
    struct no_init {
        PIN_INSTANCE m_pin;
        explicit constexpr no_init(const PIN_INSTANCE pin) : m_pin(pin) { }
        constexpr void init() const noexcept { }
    };

    template <typename PIN_INSTANCE>
    struct Unused {
        PIN_INSTANCE m_pin;
        explicit constexpr Unused(const PIN_INSTANCE pin) : m_pin(pin) { }
        constexpr void init() const noexcept {
            m_pin.set_lowpower();
        }
    };

//    template <typename PIN_INSTANCE>
//    struct output_low {
//        PIN_INSTANCE m_pin;
//        explicit constexpr output_low(const PIN_INSTANCE pin) : m_pin(pin) { }
//        constexpr void init() const noexcept {
//            m_pin.set_output();
//            m_pin.configure(GPIO::PinConfig::MODE_TOTEM);
//            m_pin.set_low();
//        }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct output_high {
//        PIN_INSTANCE m_pin;
//        explicit constexpr output_high(const PIN_INSTANCE pin) : m_pin(pin) { }
//        constexpr void init() const noexcept {
//            m_pin.set_output();
//            m_pin.configure(GPIO::PinConfig::MODE_TOTEM);
//            m_pin.set_high();
//        }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct input_floating {
//        PIN_INSTANCE m_pin;
//        explicit constexpr input_floating(const PIN_INSTANCE pin) : m_pin(pin) { }
//        constexpr void init() const noexcept {
//            m_pin.set_input();
//            m_pin.configure(GPIO::PinConfig::MODE_TOTEM);
//        }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct input_buskeeper {
//        PIN_INSTANCE m_pin;
//        explicit constexpr input_buskeeper(const PIN_INSTANCE pin) : m_pin(pin) { }
//        constexpr void init() const noexcept {
//            m_pin.set_input();
//            m_pin.configure(GPIO::PinConfig::MODE_BUSKEEPER);
//        }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct input_pullup {
//        PIN_INSTANCE m_pin;
//        explicit constexpr input_pullup(const PIN_INSTANCE pin) : m_pin(pin) { }
//        constexpr void init() const noexcept {
//            m_pin.set_input();
//            m_pin.configure(GPIO::PinConfig::MODE_PULLUP);
//        }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct input_pulldown {
//        PIN_INSTANCE m_pin;
//        explicit constexpr input_pulldown(const PIN_INSTANCE pin) : m_pin(pin) { }
//        constexpr void init() const noexcept {
//            m_pin.set_input();
//            m_pin.configure(GPIO::PinConfig::MODE_PULLDOWN);
//        }
//    };

    /***************************************  PERIPHERAL SPECIFIC PIN TYPES  ******************************************/

//    template <typename PIN_INSTANCE>
//    struct SDA : public no_init<PIN_INSTANCE> {
//        /// NOTE: for some reason initializing TWI pins causes the first few transmissions to fail. Override with empty init()
//        explicit constexpr SDA(const PIN_INSTANCE pin) : no_init<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct SCL : public no_init<PIN_INSTANCE> {
//        /// NOTE: for some reason initializing TWI pins causes the first few transmissions to fail. Override with empty init()
//        explicit constexpr SCL(const PIN_INSTANCE pin) : no_init<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct MOSI : public output_low<PIN_INSTANCE> {
//        explicit constexpr MOSI(const PIN_INSTANCE pin) : output_low<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct MISO : public input_floating<PIN_INSTANCE> {
//        explicit constexpr MISO(const PIN_INSTANCE pin) : input_floating<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct SCK : public output_low<PIN_INSTANCE> {
//        explicit constexpr SCK(const PIN_INSTANCE pin) : output_low<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct USART_RX : public input_floating<PIN_INSTANCE> {
//        explicit constexpr USART_RX(const PIN_INSTANCE pin) : input_floating<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    struct USART_TX : public output_low<PIN_INSTANCE> {
//        explicit constexpr USART_TX(const PIN_INSTANCE pin) : output_low<PIN_INSTANCE>(pin) { }
//    };
//
//    template <typename PIN_INSTANCE>
//    class Led : public output_low<PIN_INSTANCE> {
//    public:
//        using base = output_low<PIN_INSTANCE>;
//        explicit constexpr Led(const PIN_INSTANCE pin) : output_low<PIN_INSTANCE>(pin) { }
//
//        constexpr void toggle() const noexcept {
//            base::m_pin.toggle();
//        }
//
//        constexpr void on() const noexcept {
//            base::m_pin.set_high();
//        }
//
//        constexpr void off() const noexcept {
//            base::m_pin.set_low();
//        }
//
//        constexpr void set(const bool enable) const noexcept {
//            base::m_pin.set_value(enable);
//        }
//    };
//
//    template <typename PIN_INSTANCE>
//    class LedInverted : public Led<PIN_INSTANCE> {
//    public:
//        explicit constexpr LedInverted(const PIN_INSTANCE pin) : Led<PIN_INSTANCE>(pin) { }
//        constexpr void init() const noexcept {
//            Led<PIN_INSTANCE>::m_pin.set_output();
//            Led<PIN_INSTANCE>::m_pin.configure(GPIO::PinConfig::INVERT_PIN | GPIO::PinConfig::MODE_TOTEM);
//        }
//    };
//
//    template<typename... Pins>
//    class BoardVersion : private PinGroup<Pins...> {
//        using base = PinGroup<Pins...>;
//    public:
//        /// CTAD constructor
//        constexpr BoardVersion(Pins... p) : base(p...) {};
//        /// default init to pulldown inputs
//        constexpr void init() const noexcept {
//            base::set_input();
//            base::configure(GPIO::PinConfig::MODE_PULLDOWN);
//        }
//
//        /// read the board version by enabling pullups and reading the pins, then returning the pins to pulldown state
//        constexpr operator uint8_t() const noexcept {
//            base::configure(GPIO::PinConfig::MODE_PULLUP);
//            const uint8_t temp = base::read();
//            base::configure(GPIO::PinConfig::MODE_PULLDOWN);
//            return temp;
//        }
//    };

}   // namespace GPIO