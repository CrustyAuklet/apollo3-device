/**
 * Device: apollo3
 * Vendor: Ambiq Micro
 * Version: 1.0
 * Peripheral: GPIO
 * General Purpose IO
 */
#pragma once

#include "register.hpp"
#include <cstdint>

namespace sfr {

    namespace GPIO {

        /// Pad pullup resistor selection.
        enum class PADRSELv : uint32_t {
            PULL1_5K = 0x0, //< Pullup is ~1.5 KOhms
            PULL6K = 0x1, //< Pullup is ~6 KOhms
            PULL12K = 0x2, //< Pullup is ~12 KOhms
            PULL24K = 0x3, //< Pullup is ~24 KOhms
        };

        /// GPIO output configuration.
        enum class GPIOOUTCFGv : uint32_t {
            DIS      = 0x0, //< FNCSEL = 0x3 - Output disabled
            PUSHPULL = 0x1, //< FNCSEL = 0x3 - Output is push-pull
            OD       = 0x2, //< FNCSEL = 0x3 - Output is open drain
            TS       = 0x3, //< FNCSEL = 0x3 - Output is tri-state
        };

        /// Key register value.
        enum class PADKEYv : uint32_t {
            Key = 0x73, //< Key
        };

        /// Pad 0 function select
        enum class PAD0FNCSELv : uint32_t {
            SLSCL = 0x0, //< Configure as the IOSLAVE I2C SCL signal
            SLSCK = 0x1, //< Configure as the IOSLAVE SPI SCK signal
            CLKOUT = 0x2, //< Configure as the CLKOUT signal
            GPIO0 = 0x3, //< Configure as GPIO0
            MSPI4 = 0x5, //< MSPI data connection 4
            NCE0 = 0x7, //< IOM/MSPI nCE group 0
        };

        /// Pad 1 function select
        enum class PAD1FNCSELv : uint32_t {
            SLSDAWIR3 = 0x0, //< Configure as the IOSLAVE I2C SDA or SPI WIR3 signal
            SLMOSI = 0x1, //< Configure as the IOSLAVE SPI MOSI signal
            UART0TX = 0x2, //< Configure as the UART0 TX output signal
            GPIO1 = 0x3, //< Configure as GPIO1
            MSPI5 = 0x5, //< MSPI data connection 5
            NCE1 = 0x7, //< IOM/MSPI nCE group 1
        };

        /// Pad 2 function select
        enum class PAD2FNCSELv : uint32_t {
            UART1RX = 0x0, //< Configure as the UART1 RX input.
            SLMISO = 0x1, //< Configure as the IOSLAVE SPI MISO signal.
            UART0RX = 0x2, //< Configure as the UART0 RX input.
            GPIO2 = 0x3, //< Configure as GPIO2.
            MSPI6 = 0x5, //< MSPI data connection 6.
            NCE2 = 0x7, //< IOM/MSPI nCE group 2
        };

        /// Pad 3 function select
        enum class PAD3FNCSELv : uint32_t {
            UA0RTS = 0x0, //< Configure as the UART0 RTS output
            SLnCE = 0x1, //< Configure as the IOSLAVE SPI nCE signal
            NCE3 = 0x2, //< IOM/MSPI nCE group 3
            GPIO3 = 0x3, //< Configure as GPIO3
            MSPI7 = 0x5, //< MSPI data connection 7
            TRIG1 = 0x6, //< Configure as the ADC Trigger 1 signal
            I2S_WCLK = 0x7, //< Configure as the PDM I2S Word Clock input
        };

        /// Pad 4 function select
        enum class PAD4FNCSELv : uint32_t {
            UA0CTS = 0x0, //< Configure as the UART0 CTS input signal
            SLINT = 0x1, //< Configure as the IOSLAVE interrupt out signal
            NCE4 = 0x2, //< IOM/SPI nCE group 4
            GPIO4 = 0x3, //< Configure as GPIO4
            UART0RX = 0x5, //< Configure as the UART0 RX input
            CT17 = 0x6, //< CTIMER connection 17
            MSPI2 = 0x7, //< MSPI data connection 2
        };

        /// Pad 5 function select
        enum class PAD5FNCSELv : uint32_t {
            M0SCL = 0x0, //< Configure as the IOMSTR0 I2C SCL signal
            M0SCK = 0x1, //< Configure as the IOMSTR0 SPI SCK signal
            UA0RTS = 0x2, //< Configure as the UART0 RTS signal output
            GPIO5 = 0x3, //< Configure as GPIO5
            EXTHFA = 0x5, //< Configure as the External HFA input clock
            CT8 = 0x7, //< CTIMER connection 8
        };

        /// Pad 6 function select
        enum class PAD6FNCSELv : uint32_t {
            M0SDAWIR3 = 0x0, //< Configure as the IOMSTR0 I2C SDA or SPI WIR3 signal
            M0MISO = 0x1, //< Configure as the IOMSTR0 SPI MISO signal
            UA0CTS = 0x2, //< Configure as the UART0 CTS input signal
            GPIO6 = 0x3, //< Configure as GPIO6
            CT10 = 0x5, //< CTIMER connection 10
            I2S_DAT = 0x7, //< Configure as the PDM I2S Data output signal
        };
    
        /// Pad 7 function select
        enum class PAD7FNCSELv : uint32_t {
            NCE7 = 0x0, //< IOM/MSPI nCE group 7
            M0MOSI = 0x1, //< Configure as the IOMSTR0 SPI MOSI signal
            CLKOUT = 0x2, //< Configure as the CLKOUT signal
            GPIO7 = 0x3, //< Configure as GPIO7
            TRIG0 = 0x4, //< Configure as the ADC Trigger 0 signal
            UART0TX = 0x5, //< Configure as the UART0 TX output signal
            CT19 = 0x7, //< CTIMER connection 19
        };

        /// Pad 8 function select
        enum class PAD8FNCSELv : uint32_t {
            M1SCL = 0x0, //< Configure as the IOMSTR1 I2C SCL signal
            M1SCK = 0x1, //< Configure as the IOMSTR1 SPI SCK signal
            NCE8 = 0x2, //< IOM/MSPI nCE group 8
            GPIO8 = 0x3, //< Configure as GPIO8
            SCCLK = 0x4, //< SCARD serial clock output
            UART1TX = 0x6, //< Configure as the UART1 TX output signal
        };

        /// Pad 9 function select
        enum class PAD9FNCSELv : uint32_t {
            M1SDAWIR3 = 0x0, //< Configure as the IOMSTR1 I2C SDA or SPI WIR3 signal
            M1MISO = 0x1, //< Configure as the IOMSTR1 SPI MISO signal
            NCE9 = 0x2, //< IOM/MSPI nCE group 9
            GPIO9 = 0x3, //< Configure as GPIO9
            SCCIO = 0x4, //< SCARD data I/O connection
            UART1RX = 0x6, //< Configure as UART1 RX input signal
        };

        /// Pad 10 function select
        enum class PAD10FNCSELv : uint32_t {
            M1MOSI = 0x1, //< Configure as the IOMSTR1 SPI MOSI signal
            NCE10 = 0x2, //< IOM/MSPI nCE group 10
            GPIO10 = 0x3, //< Configure as GPIO10
            PDMCLK = 0x4, //< PDM serial clock out
            UA1RTS = 0x5, //< Configure as the UART1 RTS output signal
        };
    
        /// Pad 11 function select
        enum class PAD11FNCSELv : uint32_t {
            ADCSE2 = 0x0, //< Configure as the analog input for ADC single ended input 2
            NCE11 = 0x1, //< IOM/MSPI nCE group 11
            CT31 = 0x2, //< CTIMER connection 31
            GPIO11 = 0x3, //< Configure as GPIO11
            SLINT = 0x4, //< Configure as the IOSLAVE interrupt out signal
            UA1CTS = 0x5, //< Configure as the UART1 CTS input signal
            UART0RX = 0x6, //< Configure as the UART0 RX input signal
            PDM_DATA = 0x7, //< Configure as the PDM Data input signal
        };

        /// Pad 12 function select
        enum class PAD12FNCSELv : uint32_t {
            ADCD0NSE9 = 0x0, //< Configure as the ADC Differential pair 0 N, or Single Ended input 9 analog input signal. Determination of the D0N vs SE9 usage is done when the particular channel is selected within the ADC module
            NCE12 = 0x1, //< IOM/MSPI nCE group 12
            CT0 = 0x2, //< CTIMER connection 0
            GPIO12 = 0x3, //< Configure as GPIO12
            PDMCLK = 0x5, //< PDM serial clock output
            UA0CTS = 0x6, //< Configure as the UART0 CTS input signal
            UART1TX = 0x7, //< Configure as the UART1 TX output signal
        };

        /// Pad 13 function select
        enum class PAD13FNCSELv : uint32_t {
            ADCD0PSE8 = 0x0, //< Configure as the ADC Differential pair 0 P, or Single Ended input 8 analog input signal. Determination of the D0P vs SE8 usage is done when the particular channel is selected within the ADC module
            NCE13 = 0x1, //< IOM/MSPI nCE group 13
            CT2 = 0x2, //< CTIMER connection 2
            GPIO13 = 0x3, //< Configure as GPIO13
            I2SBCLK = 0x4, //< I2C interface bit clock
            EXTHFB = 0x5, //< Configure as the external HFRC oscillator input
            UA0RTS = 0x6, //< Configure as the UART0 RTS signal output
            UART1RX = 0x7, //< Configure as the UART1 RX input signal
        };

        /// Pad 14 function select
        enum class PAD14FNCSELv : uint32_t {
            ADCD1P = 0x0, //< Configure as the analog ADC differential pair 1 P input signal
            NCE14 = 0x1, //< IOM/MSPI nCE group 14
            UART1TX = 0x2, //< Configure as the UART1 TX output signal
            GPIO14 = 0x3, //< Configure as GPIO14
            PDMCLK = 0x4, //< PDM serial clock output
            EXTHFS = 0x5, //< Configure as the External HFRC oscillator input select
            SWDCK = 0x6, //< Configure as the alternate input for the SWDCK input signal
            v32kHzXT = 0x7, //< Configure as the 32kHz crystal output signal
        };
    
        /// Pad 15 function select
        enum class PAD15FNCSELv : uint32_t {
            ADCD1N = 0x0, //< Configure as the analog ADC differential pair 1 N input signal
            NCE15 = 0x1, //< IOM/MSPI nCE group 15
            UART1RX = 0x2, //< Configure as the UART1 RX signal
            GPIO15 = 0x3, //< Configure as GPIO15
            PDMDATA = 0x4, //< PDM serial data input
            EXTXT = 0x5, //< Configure as the external XTAL oscillator input
            SWDIO = 0x6, //< Configure as an alternate port for the SWDIO I/O signal
            SWO = 0x7, //< Configure as an SWO (Serial Wire Trace output)
        };

        /// Pad 16 function select
        enum class PAD16FNCSELv : uint32_t {
            ADCSE0 = 0x0, //< Configure as the analog ADC single ended port 0 input signal
            NCE16 = 0x1, //< IOM/MSPI nCE group 16
            TRIG0 = 0x2, //< Configure as the ADC Trigger 0 signal
            GPIO16 = 0x3, //< Configure as GPIO16
            SCCRST = 0x4, //< SCARD reset output
            CMPIN0 = 0x5, //< Configure as comparator input 0 signal
            UART0TX = 0x6, //< Configure as UART0 TX output signal
            UA1RTS = 0x7, //< Configure as UART1 RTS output signal
        };

        /// Pad 17 function select
        enum class PAD17FNCSELv : uint32_t {
            CMPRF1 = 0x0, //< Configure as the analog comparator reference signal 1 input signal
            NCE17 = 0x1, //< IOM/MSPI nCE group 17
            TRIG1 = 0x2, //< Configure as the ADC Trigger 1 signal
            GPIO17 = 0x3, //< Configure as GPIO17
            SCCCLK = 0x4, //< SCARD serial clock output
            UART0RX = 0x6, //< Configure as UART0 RX input signal
            UA1CTS = 0x7, //< Configure as UART1 CTS input signal
        };

        /// Pad 18 function select
        enum class PAD18FNCSELv : uint32_t {
            CMPIN1 = 0x0, //< Configure as the analog comparator input 1 signal
            NCE18 = 0x1, //< IOM/MSPI nCE group 18
            CT4 = 0x2, //< CTIMER connection 4
            GPIO18 = 0x3, //< Configure as GPIO18
            UA0RTS = 0x4, //< Configure as UART0 RTS output signal
            ANATEST2 = 0x5, //< Configure as ANATEST2 I/O signal
            UART1TX = 0x6, //< Configure as UART1 TX output signal
            SCCIO = 0x7, //< SCARD data input/output connectin
        };
    
        /// Pad 19 function select
        enum class PAD19FNCSELv : uint32_t {
            CMPRF0 = 0x0, //< Configure as the analog comparator reference 0 signal
            NCE19 = 0x1, //< IOM/MSPI nCE group 19
            CT6 = 0x2, //< CTIMER conenction 6
            GPIO19 = 0x3, //< Configure as GPIO19
            SCCLK = 0x4, //< SCARD serial clock
            ANATEST1 = 0x5, //< Configure as the ANATEST1 I/O signal
            UART1RX = 0x6, //< Configure as the UART1 RX input signal
            I2SBCLK = 0x7, //< Configure as the PDM I2S bit clock input signal
        };

        /// Pad 20 function select
        enum class PAD20FNCSELv : uint32_t {
            SWDCK = 0x0, //< Configure as the serial wire debug clock signal
            NCE20 = 0x1, //< IOM/MSPI nCE group 20
            GPIO20 = 0x3, //< Configure as GPIO20
            UART0TX = 0x4, //< Configure as UART0 TX output signal
            UART1TX = 0x5, //< Configure as UART1 TX output signal
            I2SBCLK = 0x6, //< I2S byte clock input
            UA1RTS = 0x7, //< Configure as UART1 RTS output signal
        };

        /// Pad 21 function select
        enum class PAD21FNCSELv : uint32_t {
            SWDIO = 0x0, //< Configure as the serial wire debug data signal
            NCE21 = 0x1, //< IOM/MSPI nCE group 21
            GPIO21 = 0x3, //< Configure as GPIO21
            UART0RX = 0x4, //< Configure as UART0 RX input signal
            UART1RX = 0x5, //< Configure as UART1 RX input signal
            I2SBCLK = 0x6, //< I2S byte clock input
            UA1CTS = 0x7, //< Configure as UART1 CTS input signal
        };

        /// Pad 22 function select
        enum class PAD22FNCSELv : uint32_t {
            UART0TX = 0x0, //< Configure as the UART0 TX signal
            NCE22 = 0x1, //< IOM/MSPI nCE group 22
            CT12 = 0x2, //< CTIMER connection 12
            GPIO22 = 0x3, //< Configure as GPIO22
            PDM_CLK = 0x4, //< Configure as the PDM CLK output
            EXTLF = 0x5, //< External LFRC input
            MSPI0 = 0x6, //< MSPI data connection 0
            SWO = 0x7, //< Configure as the serial trace data output signal
        };
    
        /// Pad 23 function select
        enum class PAD23FNCSELv : uint32_t {
            UART0RX = 0x0, //< Configure as the UART0 RX signal
            NCE23 = 0x1, //< IOM/MSPI nCE group 23
            CT14 = 0x2, //< CTIMER connection 14
            GPIO23 = 0x3, //< Configure as GPIO23
            I2SWCLK = 0x4, //< I2S word clock input
            CMPOUT = 0x5, //< Configure as voltage comparitor output
            MSPI3 = 0x6, //< MSPI data connection 3
            EXTXT = 0x7, //< External XTAL osacillatgor input
        };

        /// Pad 24 function select
        enum class PAD24FNCSELv : uint32_t {
            UART1TX = 0x0, //< Configure as UART1 TX output signal
            NCE24 = 0x1, //< IOM/MSPI nCE group 24
            MSPI8 = 0x2, //< MSPI data connection 8
            GPIO24 = 0x3, //< Configure as GPIO24
            UA0CTS = 0x4, //< Configure as UART0 CTS input signal
            CT21 = 0x5, //< CTIMER connection 21
            v32kHzXT = 0x6, //< Configure as the 32kHz crystal output signal
            SWO = 0x7, //< Configure as the serial trace data output signal
        };

        /// Pad 25 function select
        enum class PAD25FNCSELv : uint32_t {
            UART1RX = 0x0, //< Configure as UART1 RX input signal
            NCE25 = 0x1, //< IOM/MSPI nCE group 25
            CT1 = 0x2, //< CTIMER connection 1
            GPIO25 = 0x3, //< Configure as GPIO25
            M2SDAWIR3 = 0x4, //< Configure as the IOMSTR2 I2C SDA or SPI WIR3 signal
            M2MISO = 0x5, //< Configure as the IOMSTR2 SPI MISO input signal
        };

        /// Pad 26 function select
        enum class PAD26FNCSELv : uint32_t {
            EXTHF = 0x0, //< Configure as the external HFRC oscillator input
            NCE26 = 0x1, //< IOM/MSPI nCE group 26
            CT3 = 0x2, //< CTIMER connection 3
            GPIO26 = 0x3, //< Configure as GPIO26
            SCCRST = 0x4, //< SCARD reset output
            MSPI1 = 0x5, //< MSPI data connection 1
            UART0TX = 0x6, //< Configure as UART0 TX output signal
            UA1CTS = 0x7, //< Configure as UART1 CTS input signal
        };
    
        /// Pad 27 function select
        enum class PAD27FNCSELv : uint32_t {
            UART0RX = 0x0, //< Configure as UART0 RX input signal
            NCE27 = 0x1, //< IOM/MSPI nCE group 27
            CT5 = 0x2, //< CTIMER connection 5
            GPIO27 = 0x3, //< Configure as GPIO27
            M2SCL = 0x4, //< Configure as I2C clock I/O signal from IOMSTR2
            M2SCK = 0x5, //< Configure as SPI clock output signal from IOMSTR2
        };

        /// Pad 28 function select
        enum class PAD28FNCSELv : uint32_t {
            I2S_WCLK = 0x0, //< Configure as the PDM I2S Word Clock input
            NCE28 = 0x1, //< IOM/MSPI nCE group 28
            CT7 = 0x2, //< CTIMER connection 7
            GPIO28 = 0x3, //< Configure as GPIO28
            M2MOSI = 0x5, //< Configure as the IOMSTR2 SPI MOSI output signal
            UART0TX = 0x6, //< Configure as the UART0 TX output signal
        };

        /// Pad 29 function select
        enum class PAD29FNCSELv : uint32_t {
            ADCSE1 = 0x0, //< Configure as the analog input for ADC single ended input 1
            NCE29 = 0x1, //< IOM/MSPI nCE group 29
            CT9 = 0x2, //< CTIMER connection 9
            GPIO29 = 0x3, //< Configure as GPIO29
            UA0CTS = 0x4, //< Configure as the UART0 CTS input signal
            UA1CTS = 0x5, //< Configure as the UART1 CTS input signal
            UART0RX = 0x6, //< Configure as the UART0 RX input signal
            PDM_DATA = 0x7, //< Configure as PDM DATA input
        };

        /// Pad 30 function select
        enum class PAD30FNCSELv : uint32_t {
            ANATEST1 = 0x0, //< Configure as the ANATEST1 I/O signal
            NCE30 = 0x1, //< IOM/MSPI nCE group 30
            CT11 = 0x2, //< CTIMER connection 11
            GPIO30 = 0x3, //< Configure as GPIO30
            UART0TX = 0x4, //< Configure as UART0 TX output signal
            UA1RTS = 0x5, //< Configure as UART1 RTS output signal
            I2S_DAT = 0x7, //< Configure as the PDM I2S Data output signal
        };
    
        /// Pad 31 function select
        enum class PAD31FNCSELv : uint32_t {
            ADCSE3 = 0x0, //< Configure as the analog input for ADC single ended input 3
            NCE31 = 0x1, //< IOM/MSPI nCE group 31
            CT13 = 0x2, //< CTIMER connection 13
            GPIO31 = 0x3, //< Configure as GPIO31
            UART0RX = 0x4, //< Configure as the UART0 RX input signal
            SCCCLK = 0x5, //< SCARD serial clock output
            UA1RTS = 0x7, //< Configure as UART1 RTS output signal
        };

        /// Pad 32 function select
        enum class PAD32FNCSELv : uint32_t {
            ADCSE4 = 0x0, //< Configure as the analog input for ADC single ended input 4
            NCE32 = 0x1, //< IOM/MSPI nCE group 32
            CT15 = 0x2, //< CTIMER connection 15
            GPIO32 = 0x3, //< Configure as GPIO32
            SCCIO = 0x4, //< SCARD serial data input/output
            EXTLF = 0x5, //< External input to the LFRC oscillator
            UA1CTS = 0x7, //< Configure as the UART1 CTS input
        };

        /// Pad 33 function select
        enum class PAD33FNCSELv : uint32_t {
            ADCSE5 = 0x0, //< Configure as the analog ADC single ended port 5 input signal
            NCE33 = 0x1, //< IOM/MSPI nCE group 33
            v32kHzXT = 0x2, //< Configure as the 32kHz crystal output signal
            GPIO33 = 0x3, //< Configure as GPIO33
            UA0CTS = 0x5, //< Configure as the UART0 CTS input
            CT23 = 0x6, //< CTIMER connection 23
            SWO = 0x7, //< Configure as the serial trace data output signal
        };

        /// Pad 34 function select
        enum class PAD34FNCSELv : uint32_t {
            ADCSE6 = 0x0, //< Configure as the analog input for ADC single ended input 6
            NCE34 = 0x1, //< IOM/MSPI nCE group 34
            UA1RTS = 0x2, //< Configure as the UART1 RTS output
            GPIO34 = 0x3, //< Configure as GPIO34
            CMPRF2 = 0x4, //< Configure as the analog comparator reference 2 signal
            UA0RTS = 0x5, //< Configure as the UART0 RTS output
            UART0RX = 0x6, //< Configure as the UART0 RX input
            PDMDATA = 0x7, //< PDM serial data input
        };
    
        /// Pad 35 function select
        enum class PAD35FNCSELv : uint32_t {
            ADCSE7 = 0x0, //< Configure as the analog input for ADC single ended input 7
            NCE35 = 0x1, //< IOM/MSPI nCE group 35
            UART1TX = 0x2, //< Configure as the UART1 TX signal
            GPIO35 = 0x3, //< Configure as GPIO35
            I2SDAT = 0x4, //< I2S serial data output
            CT27 = 0x5, //< CTIMER connection 27
            UA0RTS = 0x6, //< Configure as the UART0 RTS output
        };

        /// Pad 36 function select
        enum class PAD36FNCSELv : uint32_t {
            TRIG1 = 0x0, //< Configure as the ADC Trigger 1 signal
            NCE36 = 0x1, //< IOM/MSPI nCE group 36
            UART1RX = 0x2, //< Configure as the UART1 RX input signal
            GPIO36 = 0x3, //< Configure as GPIO36
            v32kHzXT = 0x4, //< Configure as the 32kHz output clock from the crystal
            UA1CTS = 0x5, //< Configure as the UART1 CTS input signal
            UA0CTS = 0x6, //< Configure as the UART0 CTS input signal
            PDMDATA = 0x7, //< PDM serial data input
        };

        /// Pad 37 function select
        enum class PAD37FNCSELv : uint32_t {
            TRIG2 = 0x0, //< Configure as the ADC Trigger 2 signal
            NCE37 = 0x1, //< IOM/MSPI nCE group 37
            UA0RTS = 0x2, //< Configure as the UART0 RTS output signal
            GPIO37 = 0x3, //< Configure as GPIO37
            SCCIO = 0x4, //< SCARD serial data input/output
            UART1TX = 0x5, //< Configure as the UART1 TX output signal
            PDMCLK = 0x6, //< Configure as the PDM CLK output signal
            CT29 = 0x7, //< CTIMER connection 29
        };

        /// Pad 38 function select
        enum class PAD38FNCSELv : uint32_t {
            TRIG3 = 0x0, //< Configure as the ADC Trigger 3 signal
            NCE38 = 0x1, //< IOM/MSPI nCE group 38
            UA0CTS = 0x2, //< Configure as the UART0 CTS signal
            GPIO38 = 0x3, //< Configure as GPIO38
            M3MOSI = 0x5, //< Configure as the IOMSTR3 SPI MOSI output signal
            UART1RX = 0x6, //< Configure as the UART1 RX input signal
        };
    
        /// Pad 39 function select
        enum class PAD39FNCSELv : uint32_t {
            UART0TX = 0x0, //< Configure as the UART0 TX output signal
            UART1TX = 0x1, //< Configure as the UART1 TX output signal
            CT25 = 0x2, //< CTIMER connection 25
            GPIO39 = 0x3, //< Configure as GPIO39
            M4SCL = 0x4, //< Configure as the IOMSTR4 I2C SCL signal
            M4SCK = 0x5, //< Configure as the IOMSTR4 SPI SCK signal
        };

        /// Pad 40 function select
        enum class PAD40FNCSELv : uint32_t {
            UART0RX = 0x0, //< Configure as the UART0 RX input signal
            UART1RX = 0x1, //< Configure as the UART1 RX input signal
            TRIG0 = 0x2, //< Configure as the ADC Trigger 0 signal
            GPIO40 = 0x3, //< Configure as GPIO40
            M4SDAWIR3 = 0x4, //< Configure as the IOMSTR4 I2C SDA or SPI WIR3 signal
            M4MISO = 0x5, //< Configure as the IOMSTR4 SPI MISO input signal
        };

        /// Pad 41 function select
        enum class PAD41FNCSELv : uint32_t {
            NCE41 = 0x0, //< IOM/MSPI nCE group 41
            SWO = 0x2, //< Configure as the serial wire debug SWO signal
            GPIO41 = 0x3, //< Configure as GPIO41
            I2SWCLK = 0x4, //< I2S word clock input
            UA1RTS = 0x5, //< Configure as the UART1 RTS output signal
            UART0TX = 0x6, //< Configure as the UART0 TX output signal
            UA0RTS = 0x7, //< Configure as the UART0 RTS output signal
        };

        /// Pad 42 function select
        enum class PAD42FNCSELv : uint32_t {
            UART1TX = 0x0, //< Configure as the UART1 TX output signal
            NCE42 = 0x1, //< IOM/MSPI nCE group 42
            CT16 = 0x2, //< CTIMER connection 16
            GPIO42 = 0x3, //< Configure as GPIO42
            M3SCL = 0x4, //< Configure as the IOMSTR3 I2C SCL clock I/O signal
            M3SCK = 0x5, //< Configure as the IOMSTR3 SPI SCK output
        };
    
        /// Pad 43 function select
        enum class PAD43FNCSELv : uint32_t {
            UART1RX = 0x0, //< Configure as the UART1 RX input signal
            NCE43 = 0x1, //< IOM/MSPI nCE group 43
            CT18 = 0x2, //< CTIMER connection 18
            GPIO43 = 0x3, //< Configure as GPIO43
            M3SDAWIR3 = 0x4, //< Configure as the IOMSTR3 I2C SDA or SPI WIR3 signal
            M3MISO = 0x5, //< Configure as the IOMSTR3 SPI MISO signal
        };

        /// Pad 44 function select
        enum class PAD44FNCSELv : uint32_t {
            UA1RTS = 0x0, //< Configure as the UART1 RTS output signal
            NCE44 = 0x1, //< IOM/MSPI nCE group 44
            CT20 = 0x2, //< CTIMER connection 20
            GPIO44 = 0x3, //< Configure as GPIO44
            M4MOSI = 0x5, //< Configure as the IOMSTR4 SPI MOSI signal
            M5nCE6 = 0x6, //< Configure as the SPI channel 6 nCE signal from IOMSTR5
        };

        /// Pad 45 function select
        enum class PAD45FNCSELv : uint32_t {
            UA1CTS = 0x0, //< Configure as the UART1 CTS input signal
            NCE45 = 0x1, //< IOM/MSPI nCE group 45
            CT22 = 0x2, //< CTIMER connection 22
            GPIO45 = 0x3, //< Configure as GPIO45
            I2SDAT = 0x4, //< I2S serial data output
            PDMDATA = 0x5, //< PDM serial data input
            UART0RX = 0x6, //< Configure as the SPI channel 5 nCE signal from IOMSTR5
            SWO = 0x7, //< Configure as the serial wire debug SWO signal
        };

        /// Pad 46 function select
        enum class PAD46FNCSELv : uint32_t {
            v32khz_XT = 0x0, //< Configure as the 32kHz output clock from the crystal
            NCE46 = 0x1, //< IOM/MSPI nCE group 46
            CT24 = 0x2, //< CTIMER connection 24
            GPIO46 = 0x3, //< Configure as GPIO46
            SCCRST = 0x4, //< SCARD reset output
            PDMCLK = 0x5, //< PDM serial clock output
            UART1TX = 0x6, //< Configure as the UART1 TX output signal
            SWO = 0x7, //< Configure as the serial wire debug SWO signal
        };
    
        /// Pad 47 function select
        enum class PAD47FNCSELv : uint32_t {
            v32kHzXT = 0x0, //< Configure as the 32kHz output clock from the crystal
            NCE47 = 0x1, //< IOM/MSPI nCE group 47
            CT26 = 0x2, //< CTIMER connection 26
            GPIO47 = 0x3, //< Configure as GPIO47
            M5MOSI = 0x5, //< Configure as the IOMSTR5 SPI MOSI output signal
            UART1RX = 0x6, //< Configure as the UART1 RX input signal
        };

        /// Pad 48 function select
        enum class PAD48FNCSELv : uint32_t {
            UART0TX = 0x0, //< Configure as the UART0 TX output signal
            NCE48 = 0x1, //< IOM/MSPI nCE group 48
            CT28 = 0x2, //< CTIMER conenction 28
            GPIO48 = 0x3, //< Configure as GPIO48
            M5SCL = 0x4, //< Configure as the IOMSTR5 I2C SCL clock I/O signal
            M5SCK = 0x5, //< Configure as the IOMSTR5 SPI SCK output
        };
    
        /// Pad 49 function select
        enum class PAD49FNCSELv : uint32_t {
            UART0RX = 0x0, //< Configure as the UART0 RX input signal
            NCE49 = 0x1, //< IOM/MSPPI nCE group 49
            CT30 = 0x2, //< CTIMER connection 30
            GPIO49 = 0x3, //< Configure as GPIO49
            M5SDAWIR3 = 0x4, //< Configure as the IOMSTR5 I2C SDA or SPI WIR3 signal
            M5MISO = 0x5, //< Configure as the IOMSTR5 SPI MISO input signal
        };

        template<unsigned pin>
        concept HasPullups = pin == 0 || pin == 1 || pin == 5 || pin == 6 || pin == 8;

        template<unsigned pin>
        concept LowSideSwitch = pin == 37 || pin == 41;

    }   // namespace GPIO

    /// General Purpose IO
    template <addressType BASE_ADDRESS>
    struct GPIO_t {
        static constexpr addressType BaseAddress = BASE_ADDRESS;

        template <unsigned PinOffset>
        struct PADREG_t : reg_t<uint8_t, BASE_ADDRESS + 0x0 + PinOffset> {
            using reg_t<uint8_t, BASE_ADDRESS + PinOffset>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x18;

            /// Pad pullup resistor selection.
            /// Available on: 0, 1, 5, 6, 8, 9, 25, 27, 39, 40, 42, 43, 48 and 49
            static constexpr bitfield_t<PADREG_t<PinOffset>, 7, 6, GPIO::PADRSELv> RSEL = {};

            /// Pad 37/41 VDD low side power switch enable - ONLY PAD 37 and 41!
            static constexpr bitfield_t<PADREG_t<PinOffset>, 7, 7, GPIO::PADRSELv> PWRDN = {};
            /// Pad 3/36 VDD high side power switch enable - ONLY PAD 3 and 36!
            static constexpr bitfield_t<PADREG_t<PinOffset>, 6, 6, GPIO::PADRSELv> PWRUP = {};

            /// Pad function select
            static constexpr bitfield_t<PADREG_t<PinOffset>, 5, 3, GPIO::PAD0FNCSELv> FNCSEL = {};

            /// Pad drive strength
            static constexpr bitfield_t<PADREG_t<PinOffset>, 2, 2, bool> STRNG = {};

            /// Pad input enable
            static constexpr bitfield_t<PADREG_t<PinOffset>, 1, 1, bool> INPEN = {};

            /// Pad pullup enable - PullUp on all pins except 20, pin 20 has a pulldown!
            static constexpr bitfield_t<PADREG_t<PinOffset>, 0, 0, bool> PULL = {};
        };

        template <GPIO::LowSideSwitch PinOffset>
        struct PADREG_t<GPIO::LowSideSwitch> : reg_t<uint8_t, BASE_ADDRESS + 0x0 + PinOffset> {
            using reg_t<uint8_t, BASE_ADDRESS + PinOffset>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x18;
            /// Pad 37/41 VDD low side power switch enable - ONLY PAD 37 and 41!
            static constexpr bitfield_t<PADREG_t<PinOffset>, 7, 7, GPIO::PADRSELv> PWRDN = {};
            /// Pad function select
            static constexpr bitfield_t<PADREG_t<PinOffset>, 5, 3, GPIO::PAD0FNCSELv> FNCSEL = {};
            /// Pad drive strength
            static constexpr bitfield_t<PADREG_t<PinOffset>, 2, 2, bool> STRNG = {};
            /// Pad input enable
            static constexpr bitfield_t<PADREG_t<PinOffset>, 1, 1, bool> INPEN = {};
            /// Pad pullup enable - PullUp on all pins except 20, pin 20 has a pulldown!
            static constexpr bitfield_t<PADREG_t<PinOffset>, 0, 0, bool> PULL = {};
        };

        /**
         * PADREGA - 4 bytes at offset 0
         * Pad Configuration Register A (Pads 3-0)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGA_t : reg_t<uint32_t, BASE_ADDRESS + 0x0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x0>::operator=;
            static constexpr uint32_t reset_mask  = 0x7F3FFFFF;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 3 VDD power switch enable
            static constexpr bitfield_t<PADREGA_t, 30, 30, bool> PAD3PWRUP = {};

            /// Pad 3 function select
            static constexpr bitfield_t<PADREGA_t, 29, 27, GPIO::PAD3FNCSELv> PAD3FNCSEL = {};

            /// Pad 3 drive strength.
            static constexpr bitfield_t<PADREGA_t, 26, 26, bool> PAD3STRNG = {};

            /// Pad 3 input enable.
            static constexpr bitfield_t<PADREGA_t, 25, 25, bool> PAD3INPEN = {};

            /// Pad 3 pullup enable
            static constexpr bitfield_t<PADREGA_t, 24, 24, bool> PAD3PULL = {};

            /// Pad 2 function select
            static constexpr bitfield_t<PADREGA_t, 21, 19, GPIO::PAD2FNCSELv> PAD2FNCSEL = {};

            /// Pad 2 drive strength
            static constexpr bitfield_t<PADREGA_t, 18, 18, bool> PAD2STRNG = {};

            /// Pad 2 input enable
            static constexpr bitfield_t<PADREGA_t, 17, 17, bool> PAD2INPEN = {};

            /// Pad 2 pullup enable
            static constexpr bitfield_t<PADREGA_t, 16, 16, bool> PAD2PULL = {};

            /// Pad 1 pullup resistor selection.
            static constexpr bitfield_t<PADREGA_t, 15, 14, GPIO::PADRSELv> PAD1RSEL = {};

            /// Pad 1 function select
            static constexpr bitfield_t<PADREGA_t, 13, 11, GPIO::PAD1FNCSELv> PAD1FNCSEL = {};

            /// Pad 1 drive strength
            static constexpr bitfield_t<PADREGA_t, 10, 10, bool> PAD1STRNG = {};

            /// Pad 1 input enable
            static constexpr bitfield_t<PADREGA_t, 9, 9, bool> PAD1INPEN = {};

            /// Pad 1 pullup enable
            static constexpr bitfield_t<PADREGA_t, 8, 8, bool> PAD1PULL = {};

            /// Pad 0 pullup resistor selection.
            static constexpr bitfield_t<PADREGA_t, 7, 6, GPIO::PADRSELv> PAD0RSEL = {};

            /// Pad 0 function select
            static constexpr bitfield_t<PADREGA_t, 5, 3, GPIO::PAD0FNCSELv> PAD0FNCSEL = {};

            /// Pad 0 drive strength
            static constexpr bitfield_t<PADREGA_t, 2, 2, bool> PAD0STRNG = {};

            /// Pad 0 input enable
            static constexpr bitfield_t<PADREGA_t, 1, 1, bool> PAD0INPEN = {};

            /// Pad 0 pullup enable
            static constexpr bitfield_t<PADREGA_t, 0, 0, bool> PAD0PULL = {};
        } PADREGA = {};

        /**
         * PADREGB - 4 bytes at offset 4
         * Pad Configuration Register B (Pads 7-4)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGB_t : reg_t<uint32_t, BASE_ADDRESS + 0x4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFFF3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 7 function select
            static constexpr bitfield_t<PADREGB_t, 29, 27, GPIO::PAD7FNCSELv> PAD7FNCSEL = {};

            /// Pad 7 drive strength
            static constexpr bitfield_t<PADREGB_t, 26, 26, bool> PAD7STRNG = {};

            /// Pad 7 input enable
            static constexpr bitfield_t<PADREGB_t, 25, 25, bool> PAD7INPEN = {};

            /// Pad 7 pullup enable
            static constexpr bitfield_t<PADREGB_t, 24, 24, bool> PAD7PULL = {};

            /// Pad 6 pullup resistor selection.
            static constexpr bitfield_t<PADREGB_t, 23, 22, GPIO::PADRSELv> PAD6RSEL = {};

            /// Pad 6 function select
            static constexpr bitfield_t<PADREGB_t, 21, 19, GPIO::PAD6FNCSELv> PAD6FNCSEL = {};

            /// Pad 6 drive strength
            static constexpr bitfield_t<PADREGB_t, 18, 18, bool> PAD6STRNG = {};

            /// Pad 6 input enable
            static constexpr bitfield_t<PADREGB_t, 17, 17, bool> PAD6INPEN = {};

            /// Pad 6 pullup enable
            static constexpr bitfield_t<PADREGB_t, 16, 16, bool> PAD6PULL = {};

            /// Pad 5 pullup resistor selection.
            static constexpr bitfield_t<PADREGB_t, 15, 14, GPIO::PADRSELv> PAD5RSEL = {};

            /// Pad 5 function select
            static constexpr bitfield_t<PADREGB_t, 13, 11, GPIO::PAD5FNCSELv> PAD5FNCSEL = {};

            /// Pad 5 drive strength
            static constexpr bitfield_t<PADREGB_t, 10, 10, bool> PAD5STRNG = {};

            /// Pad 5 input enable
            static constexpr bitfield_t<PADREGB_t, 9, 9, bool> PAD5INPEN = {};

            /// Pad 5 pullup enable
            static constexpr bitfield_t<PADREGB_t, 8, 8, bool> PAD5PULL = {};

            /// Pad 4 function select
            static constexpr bitfield_t<PADREGB_t, 5, 3, GPIO::PAD4FNCSELv> PAD4FNCSEL = {};

            /// Pad 4 drive strength
            static constexpr bitfield_t<PADREGB_t, 2, 2, bool> PAD4STRNG = {};

            /// Pad 4 input enable
            static constexpr bitfield_t<PADREGB_t, 1, 1, bool> PAD4INPEN = {};

            /// Pad 4 pullup enable
            static constexpr bitfield_t<PADREGB_t, 0, 0, bool> PAD4PULL = {};
        } PADREGB = {};

        /**
         * PADREGC - 4 bytes at offset 8
         * Pad Configuration Register C (Pads 11-8)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGC_t : reg_t<uint32_t, BASE_ADDRESS + 0x8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3FFFFF;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 11 function select
            static constexpr bitfield_t<PADREGC_t, 29, 27, GPIO::PAD11FNCSELv> PAD11FNCSEL = {};

            /// Pad 11 drive strength
            static constexpr bitfield_t<PADREGC_t, 26, 26, bool> PAD11STRNG = {};

            /// Pad 11 input enable
            static constexpr bitfield_t<PADREGC_t, 25, 25, bool> PAD11INPEN = {};

            /// Pad 11 pullup enable
            static constexpr bitfield_t<PADREGC_t, 24, 24, bool> PAD11PULL = {};

            /// Pad 10 function select
            static constexpr bitfield_t<PADREGC_t, 21, 19, GPIO::PAD10FNCSELv> PAD10FNCSEL = {};

            /// Pad 10 drive strength
            static constexpr bitfield_t<PADREGC_t, 18, 18, bool> PAD10STRNG = {};

            /// Pad 10 input enable
            static constexpr bitfield_t<PADREGC_t, 17, 17, bool> PAD10INPEN = {};

            /// Pad 10 pullup enable
            static constexpr bitfield_t<PADREGC_t, 16, 16, bool> PAD10PULL = {};

            /// Pad 9 pullup resistor selection
            static constexpr bitfield_t<PADREGC_t, 15, 14, GPIO::PADRSELv> PAD9RSEL = {};

            /// Pad 9 function select
            static constexpr bitfield_t<PADREGC_t, 13, 11, GPIO::PAD9FNCSELv> PAD9FNCSEL = {};

            /// Pad 9 drive strength
            static constexpr bitfield_t<PADREGC_t, 10, 10, bool> PAD9STRNG = {};

            /// Pad 9 input enable
            static constexpr bitfield_t<PADREGC_t, 9, 9, bool> PAD9INPEN = {};

            /// Pad 9 pullup enable
            static constexpr bitfield_t<PADREGC_t, 8, 8, bool> PAD9PULL = {};

            /// Pad 8 pullup resistor selection.
            static constexpr bitfield_t<PADREGC_t, 7, 6, GPIO::PADRSELv> PAD8RSEL = {};

            /// Pad 8 function select
            static constexpr bitfield_t<PADREGC_t, 5, 3, GPIO::PAD8FNCSELv> PAD8FNCSEL = {};

            /// Pad 8 drive strength
            static constexpr bitfield_t<PADREGC_t, 2, 2, bool> PAD8STRNG = {};

            /// Pad 8 input enable
            static constexpr bitfield_t<PADREGC_t, 1, 1, bool> PAD8INPEN = {};

            /// Pad 8 pullup enable
            static constexpr bitfield_t<PADREGC_t, 0, 0, bool> PAD8PULL = {};
        } PADREGC = {};

        /**
         * PADREGD - 4 bytes at offset 12
         * Pad Configuration Register D (Pads 15-12)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGD_t : reg_t<uint32_t, BASE_ADDRESS + 0xC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F3F3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 15 function select
            static constexpr bitfield_t<PADREGD_t, 29, 27, GPIO::PAD15FNCSELv> PAD15FNCSEL = {};

            /// Pad 15 drive strength
            static constexpr bitfield_t<PADREGD_t, 26, 26, bool> PAD15STRNG = {};

            /// Pad 15 input enable
            static constexpr bitfield_t<PADREGD_t, 25, 25, bool> PAD15INPEN = {};

            /// Pad 15 pullup enable
            static constexpr bitfield_t<PADREGD_t, 24, 24, bool> PAD15PULL = {};

            /// Pad 14 function select
            static constexpr bitfield_t<PADREGD_t, 21, 19, GPIO::PAD14FNCSELv> PAD14FNCSEL = {};

            /// Pad 14 drive strength
            static constexpr bitfield_t<PADREGD_t, 18, 18, bool> PAD14STRNG = {};

            /// Pad 14 input enable
            static constexpr bitfield_t<PADREGD_t, 17, 17, bool> PAD14INPEN = {};

            /// Pad 14 pullup enable
            static constexpr bitfield_t<PADREGD_t, 16, 16, bool> PAD14PULL = {};

            /// Pad 13 function select
            static constexpr bitfield_t<PADREGD_t, 13, 11, GPIO::PAD13FNCSELv> PAD13FNCSEL = {};

            /// Pad 13 drive strength
            static constexpr bitfield_t<PADREGD_t, 10, 10, bool> PAD13STRNG = {};

            /// Pad 13 input enable
            static constexpr bitfield_t<PADREGD_t, 9, 9, bool> PAD13INPEN = {};

            /// Pad 13 pullup enable
            static constexpr bitfield_t<PADREGD_t, 8, 8, bool> PAD13PULL = {};

            /// Pad 12 function select
            static constexpr bitfield_t<PADREGD_t, 5, 3, GPIO::PAD12FNCSELv> PAD12FNCSEL = {};

            /// Pad 12 drive strength
            static constexpr bitfield_t<PADREGD_t, 2, 2, bool> PAD12STRNG = {};

            /// Pad 12 input enable
            static constexpr bitfield_t<PADREGD_t, 1, 1, bool> PAD12INPEN = {};

            /// Pad 12 pullup enable
            static constexpr bitfield_t<PADREGD_t, 0, 0, bool> PAD12PULL = {};
        } PADREGD = {};

        /**
         * PADREGE - 4 bytes at offset 16
         * Pad Configuration Register E (Pads 19-16)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGE_t : reg_t<uint32_t, BASE_ADDRESS + 0x10> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F3F3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 19 function select
            static constexpr bitfield_t<PADREGE_t, 29, 27, GPIO::PAD19FNCSELv> PAD19FNCSEL = {};

            /// Pad 19 drive strength
            static constexpr bitfield_t<PADREGE_t, 26, 26, bool> PAD19STRNG = {};

            /// Pad 19 input enable
            static constexpr bitfield_t<PADREGE_t, 25, 25, bool> PAD19INPEN = {};

            /// Pad 19 pullup enable
            static constexpr bitfield_t<PADREGE_t, 24, 24, bool> PAD19PULL = {};

            /// Pad 18 function select
            static constexpr bitfield_t<PADREGE_t, 21, 19, GPIO::PAD18FNCSELv> PAD18FNCSEL = {};

            /// Pad 18 drive strength
            static constexpr bitfield_t<PADREGE_t, 18, 18, bool> PAD18STRNG = {};

            /// Pad 18 input enable
            static constexpr bitfield_t<PADREGE_t, 17, 17, bool> PAD18INPEN = {};

            /// Pad 18 pullup enable
            static constexpr bitfield_t<PADREGE_t, 16, 16, bool> PAD18PULL = {};

            /// Pad 17 function select
            static constexpr bitfield_t<PADREGE_t, 13, 11, GPIO::PAD17FNCSELv> PAD17FNCSEL = {};

            /// Pad 17 drive strength
            static constexpr bitfield_t<PADREGE_t, 10, 10, bool> PAD17STRNG = {};

            /// Pad 17 input enable
            static constexpr bitfield_t<PADREGE_t, 9, 9, bool> PAD17INPEN = {};

            /// Pad 17 pullup enable
            static constexpr bitfield_t<PADREGE_t, 8, 8, bool> PAD17PULL = {};

            /// Pad 16 function select
            static constexpr bitfield_t<PADREGE_t, 5, 3, GPIO::PAD16FNCSELv> PAD16FNCSEL = {};

            /// Pad 16 drive strength
            static constexpr bitfield_t<PADREGE_t, 2, 2, bool> PAD16STRNG = {};

            /// Pad 16 input enable
            static constexpr bitfield_t<PADREGE_t, 1, 1, bool> PAD16INPEN = {};

            /// Pad 16 pullup enable
            static constexpr bitfield_t<PADREGE_t, 0, 0, bool> PAD16PULL = {};
        } PADREGE = {};

        /**
         * PADREGF - 4 bytes at offset 20
         * Pad Configuration Register F (Pads 23-20)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGF_t : reg_t<uint32_t, BASE_ADDRESS + 0x14> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x14>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F3F3F;
            static constexpr uint32_t reset_value = 0x18180202;

            /// Pad 23 function select
            static constexpr bitfield_t<PADREGF_t, 29, 27, GPIO::PAD23FNCSELv> PAD23FNCSEL = {};

            /// Pad 23 drive strength
            static constexpr bitfield_t<PADREGF_t, 26, 26, bool> PAD23STRNG = {};

            /// Pad 23 input enable
            static constexpr bitfield_t<PADREGF_t, 25, 25, bool> PAD23INPEN = {};

            /// Pad 23 pullup enable
            static constexpr bitfield_t<PADREGF_t, 24, 24, bool> PAD23PULL = {};

            /// Pad 22 function select
            static constexpr bitfield_t<PADREGF_t, 21, 19, GPIO::PAD22FNCSELv> PAD22FNCSEL = {};

            /// Pad 22 drive strength
            static constexpr bitfield_t<PADREGF_t, 18, 18, bool> PAD22STRNG = {};

            /// Pad 22 input enable
            static constexpr bitfield_t<PADREGF_t, 17, 17, bool> PAD22INPEN = {};

            /// Pad 22 pullup enable
            static constexpr bitfield_t<PADREGF_t, 16, 16, bool> PAD22PULL = {};

            /// Pad 21 function select
            static constexpr bitfield_t<PADREGF_t, 13, 11, GPIO::PAD21FNCSELv> PAD21FNCSEL = {};

            /// Pad 21 drive strength
            static constexpr bitfield_t<PADREGF_t, 10, 10, bool> PAD21STRNG = {};

            /// Pad 21 input enable
            static constexpr bitfield_t<PADREGF_t, 9, 9, bool> PAD21INPEN = {};

            /// Pad 21 pullup enable
            static constexpr bitfield_t<PADREGF_t, 8, 8, bool> PAD21PULL = {};

            /// Pad 20 function select
            static constexpr bitfield_t<PADREGF_t, 5, 3, GPIO::PAD20FNCSELv> PAD20FNCSEL = {};

            /// Pad 20 drive strength
            static constexpr bitfield_t<PADREGF_t, 2, 2, bool> PAD20STRNG = {};

            /// Pad 20 input enable
            static constexpr bitfield_t<PADREGF_t, 1, 1, bool> PAD20INPEN = {};

            /// Pad 20 pulldown enable
            static constexpr bitfield_t<PADREGF_t, 0, 0, bool> PAD20PULL = {};
        } PADREGF = {};

        /**
         * PADREGG - 4 bytes at offset 24
         * Pad Configuration Register G (Pads 27-24)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGG_t : reg_t<uint32_t, BASE_ADDRESS + 0x18> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x18>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF3FFF3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 27 pullup resistor selection.
            static constexpr bitfield_t<PADREGG_t, 31, 30, GPIO::PADRSELv> PAD27RSEL = {};

            /// Pad 27 function select
            static constexpr bitfield_t<PADREGG_t, 29, 27, GPIO::PAD27FNCSELv> PAD27FNCSEL = {};

            /// Pad 27 drive strength
            static constexpr bitfield_t<PADREGG_t, 26, 26, bool> PAD27STRNG = {};

            /// Pad 27 input enable
            static constexpr bitfield_t<PADREGG_t, 25, 25, bool> PAD27INPEN = {};

            /// Pad 27 pullup enable
            static constexpr bitfield_t<PADREGG_t, 24, 24, bool> PAD27PULL = {};

            /// Pad 26 function select
            static constexpr bitfield_t<PADREGG_t, 21, 19, GPIO::PAD26FNCSELv> PAD26FNCSEL = {};

            /// Pad 26 drive strength
            static constexpr bitfield_t<PADREGG_t, 18, 18, bool> PAD26STRNG = {};

            /// Pad 26 input enable
            static constexpr bitfield_t<PADREGG_t, 17, 17, bool> PAD26INPEN = {};

            /// Pad 26 pullup enable
            static constexpr bitfield_t<PADREGG_t, 16, 16, bool> PAD26PULL = {};

            /// Pad 25 pullup resistor selection.
            static constexpr bitfield_t<PADREGG_t, 15, 14, GPIO::PADRSELv> PAD25RSEL = {};

            /// Pad 25 function select
            static constexpr bitfield_t<PADREGG_t, 13, 11, GPIO::PAD25FNCSELv> PAD25FNCSEL = {};

            /// Pad 25 drive strength
            static constexpr bitfield_t<PADREGG_t, 10, 10, bool> PAD25STRNG = {};

            /// Pad 25 input enable
            static constexpr bitfield_t<PADREGG_t, 9, 9, bool> PAD25INPEN = {};

            /// Pad 25 pullup enable
            static constexpr bitfield_t<PADREGG_t, 8, 8, bool> PAD25PULL = {};

            /// Pad 24 function select
            static constexpr bitfield_t<PADREGG_t, 5, 3, GPIO::PAD24FNCSELv> PAD24FNCSEL = {};

            /// Pad 24 drive strength
            static constexpr bitfield_t<PADREGG_t, 2, 2, bool> PAD24STRNG = {};

            /// Pad 24 input enable
            static constexpr bitfield_t<PADREGG_t, 1, 1, bool> PAD24INPEN = {};

            /// Pad 24 pullup enable
            static constexpr bitfield_t<PADREGG_t, 0, 0, bool> PAD24PULL = {};
        } PADREGG = {};

        /**
         * PADREGH - 4 bytes at offset 28
         * Pad Configuration Register H (Pads 31-28)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGH_t : reg_t<uint32_t, BASE_ADDRESS + 0x1C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x1C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F3F3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 31 function select
            static constexpr bitfield_t<PADREGH_t, 29, 27, GPIO::PAD31FNCSELv> PAD31FNCSEL = {};

            /// Pad 31 drive strength
            static constexpr bitfield_t<PADREGH_t, 26, 26, bool> PAD31STRNG = {};

            /// Pad 31 input enable
            static constexpr bitfield_t<PADREGH_t, 25, 25, bool> PAD31INPEN = {};

            /// Pad 31 pullup enable
            static constexpr bitfield_t<PADREGH_t, 24, 24, bool> PAD31PULL = {};

            /// Pad 30 function select
            static constexpr bitfield_t<PADREGH_t, 21, 19, GPIO::PAD30FNCSELv> PAD30FNCSEL = {};

            /// Pad 30 drive strength
            static constexpr bitfield_t<PADREGH_t, 18, 18, bool> PAD30STRNG = {};

            /// Pad 30 input enable
            static constexpr bitfield_t<PADREGH_t, 17, 17, bool> PAD30INPEN = {};

            /// Pad 30 pullup enable
            static constexpr bitfield_t<PADREGH_t, 16, 16, bool> PAD30PULL = {};

            /// Pad 29 function select
            static constexpr bitfield_t<PADREGH_t, 13, 11, GPIO::PAD29FNCSELv> PAD29FNCSEL = {};

            /// Pad 29 drive strength
            static constexpr bitfield_t<PADREGH_t, 10, 10, bool> PAD29STRNG = {};

            /// Pad 29 input enable
            static constexpr bitfield_t<PADREGH_t, 9, 9, bool> PAD29INPEN = {};

            /// Pad 29 pullup enable
            static constexpr bitfield_t<PADREGH_t, 8, 8, bool> PAD29PULL = {};

            /// Pad 28 function select
            static constexpr bitfield_t<PADREGH_t, 5, 3, GPIO::PAD28FNCSELv> PAD28FNCSEL = {};

            /// Pad 28 drive strength
            static constexpr bitfield_t<PADREGH_t, 2, 2, bool> PAD28STRNG = {};

            /// Pad 28 input enable
            static constexpr bitfield_t<PADREGH_t, 1, 1, bool> PAD28INPEN = {};

            /// Pad 28 pullup enable
            static constexpr bitfield_t<PADREGH_t, 0, 0, bool> PAD28PULL = {};
        } PADREGH = {};

        /**
         * PADREGI - 4 bytes at offset 32
         * Pad Configuration Register I (Pads 35-32)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGI_t : reg_t<uint32_t, BASE_ADDRESS + 0x20> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F3F3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 35 function select
            static constexpr bitfield_t<PADREGI_t, 29, 27, GPIO::PAD35FNCSELv> PAD35FNCSEL = {};

            /// Pad 35 drive strength
            static constexpr bitfield_t<PADREGI_t, 26, 26, bool> PAD35STRNG = {};

            /// Pad 35 input enable
            static constexpr bitfield_t<PADREGI_t, 25, 25, bool> PAD35INPEN = {};

            /// Pad 35 pullup enable
            static constexpr bitfield_t<PADREGI_t, 24, 24, bool> PAD35PULL = {};

            /// Pad 34 function select
            static constexpr bitfield_t<PADREGI_t, 21, 19, GPIO::PAD34FNCSELv> PAD34FNCSEL = {};

            /// Pad 34 drive strength
            static constexpr bitfield_t<PADREGI_t, 18, 18, bool> PAD34STRNG = {};

            /// Pad 34 input enable
            static constexpr bitfield_t<PADREGI_t, 17, 17, bool> PAD34INPEN = {};

            /// Pad 34 pullup enable
            static constexpr bitfield_t<PADREGI_t, 16, 16, bool> PAD34PULL = {};

            /// Pad 33 function select
            static constexpr bitfield_t<PADREGI_t, 13, 11, GPIO::PAD33FNCSELv> PAD33FNCSEL = {};

            /// Pad 33 drive strength
            static constexpr bitfield_t<PADREGI_t, 10, 10, bool> PAD33STRNG = {};

            /// Pad 33 input enable
            static constexpr bitfield_t<PADREGI_t, 9, 9, bool> PAD33INPEN = {};

            /// Pad 33 pullup enable
            static constexpr bitfield_t<PADREGI_t, 8, 8, bool> PAD33PULL = {};

            /// Pad 32 function select
            static constexpr bitfield_t<PADREGI_t, 5, 3, GPIO::PAD32FNCSELv> PAD32FNCSEL = {};

            /// Pad 32 drive strength
            static constexpr bitfield_t<PADREGI_t, 2, 2, bool> PAD32STRNG = {};

            /// Pad 32 input enable
            static constexpr bitfield_t<PADREGI_t, 1, 1, bool> PAD32INPEN = {};

            /// Pad 32 pullup enable
            static constexpr bitfield_t<PADREGI_t, 0, 0, bool> PAD32PULL = {};
        } PADREGI = {};

        /**
         * PADREGJ - 4 bytes at offset 36
         * Pad Configuration Register J (Pads 39-36)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGJ_t : reg_t<uint32_t, BASE_ADDRESS + 0x24> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x24>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF3FBF7F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 39 pullup resistor selection.
            static constexpr bitfield_t<PADREGJ_t, 31, 30, GPIO::PADRSELv> PAD39RSEL = {};

            /// Pad 39 function select
            static constexpr bitfield_t<PADREGJ_t, 29, 27, GPIO::PAD39FNCSELv> PAD39FNCSEL = {};

            /// Pad 39 drive strength
            static constexpr bitfield_t<PADREGJ_t, 26, 26, bool> PAD39STRNG = {};

            /// Pad 39 input enable
            static constexpr bitfield_t<PADREGJ_t, 25, 25, bool> PAD39INPEN = {};

            /// Pad 39 pullup enable
            static constexpr bitfield_t<PADREGJ_t, 24, 24, bool> PAD39PULL = {};

            /// Pad 38 function select
            static constexpr bitfield_t<PADREGJ_t, 21, 19, GPIO::PAD38FNCSELv> PAD38FNCSEL = {};

            /// Pad 38 drive strength
            static constexpr bitfield_t<PADREGJ_t, 18, 18, bool> PAD38STRNG = {};

            /// Pad 38 input enable
            static constexpr bitfield_t<PADREGJ_t, 17, 17, bool> PAD38INPEN = {};

            /// Pad 38 pullup enable
            static constexpr bitfield_t<PADREGJ_t, 16, 16, bool> PAD38PULL = {};

            /// Pad 37 VSS power switch enable
            static constexpr bitfield_t<PADREGJ_t, 15, 15, bool> PAD37PWRDN = {};

            /// Pad 37 function select
            static constexpr bitfield_t<PADREGJ_t, 13, 11, GPIO::PAD37FNCSELv> PAD37FNCSEL = {};

            /// Pad 37 drive strength
            static constexpr bitfield_t<PADREGJ_t, 10, 10, bool> PAD37STRNG = {};

            /// Pad 37 input enable
            static constexpr bitfield_t<PADREGJ_t, 9, 9, bool> PAD37INPEN = {};

            /// Pad 37 pullup enable
            static constexpr bitfield_t<PADREGJ_t, 8, 8, bool> PAD37PULL = {};

            /// Pad 36 VDD power switch enable
            static constexpr bitfield_t<PADREGJ_t, 6, 6, bool> PAD36PWRUP = {};

            /// Pad 36 function select
            static constexpr bitfield_t<PADREGJ_t, 5, 3, GPIO::PAD36FNCSELv> PAD36FNCSEL = {};

            /// Pad 36 drive strength
            static constexpr bitfield_t<PADREGJ_t, 2, 2, bool> PAD36STRNG = {};

            /// Pad 36 input enable
            static constexpr bitfield_t<PADREGJ_t, 1, 1, bool> PAD36INPEN = {};

            /// Pad 36 pullup enable
            static constexpr bitfield_t<PADREGJ_t, 0, 0, bool> PAD36PULL = {};
        } PADREGJ = {};

        /**
         * PADREGK - 4 bytes at offset 40
         * Pad Configuration Register K (Pads 43-40)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGK_t : reg_t<uint32_t, BASE_ADDRESS + 0x28> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x28>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFBFFF;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 43 pullup resistor selection.
            static constexpr bitfield_t<PADREGK_t, 31, 30, GPIO::PADRSELv> PAD43RSEL = {};

            /// Pad 43 function select
            static constexpr bitfield_t<PADREGK_t, 29, 27, GPIO::PAD43FNCSELv> PAD43FNCSEL = {};

            /// Pad 43 drive strength
            static constexpr bitfield_t<PADREGK_t, 26, 26, bool> PAD43STRNG = {};

            /// Pad 43 input enable
            static constexpr bitfield_t<PADREGK_t, 25, 25, bool> PAD43INPEN = {};

            /// Pad 43 pullup enable
            static constexpr bitfield_t<PADREGK_t, 24, 24, bool> PAD43PULL = {};

            /// Pad 42 pullup resistor selection.
            static constexpr bitfield_t<PADREGK_t, 23, 22, GPIO::PADRSELv> PAD42RSEL = {};

            /// Pad 42 function select
            static constexpr bitfield_t<PADREGK_t, 21, 19, GPIO::PAD42FNCSELv> PAD42FNCSEL = {};

            /// Pad 42 drive strength
            static constexpr bitfield_t<PADREGK_t, 18, 18, bool> PAD42STRNG = {};

            /// Pad 42 input enable
            static constexpr bitfield_t<PADREGK_t, 17, 17, bool> PAD42INPEN = {};

            /// Pad 42 pullup enable
            static constexpr bitfield_t<PADREGK_t, 16, 16, bool> PAD42PULL = {};

            /// Pad 41 power switch enable
            static constexpr bitfield_t<PADREGK_t, 15, 15, bool> PAD41PWRDN = {};

            /// Pad 41 function select
            static constexpr bitfield_t<PADREGK_t, 13, 11, GPIO::PAD41FNCSELv> PAD41FNCSEL = {};

            /// Pad 41 drive strength
            static constexpr bitfield_t<PADREGK_t, 10, 10, bool> PAD41STRNG = {};

            /// Pad 41 input enable
            static constexpr bitfield_t<PADREGK_t, 9, 9, bool> PAD41INPEN = {};

            /// Pad 41 pullup enable
            static constexpr bitfield_t<PADREGK_t, 8, 8, bool> PAD41PULL = {};

            /// Pad 40 pullup resistor selection.
            static constexpr bitfield_t<PADREGK_t, 7, 6, GPIO::PADRSELv> PAD40RSEL = {};

            /// Pad 40 function select
            static constexpr bitfield_t<PADREGK_t, 5, 3, GPIO::PAD40FNCSELv> PAD40FNCSEL = {};

            /// Pad 40 drive strength
            static constexpr bitfield_t<PADREGK_t, 2, 2, bool> PAD40STRNG = {};

            /// Pad 40 input enable
            static constexpr bitfield_t<PADREGK_t, 1, 1, bool> PAD40INPEN = {};

            /// Pad 40 pullup enable
            static constexpr bitfield_t<PADREGK_t, 0, 0, bool> PAD40PULL = {};
        } PADREGK = {};

        /**
         * PADREGL - 4 bytes at offset 44
         * Pad Configuration Register L (Pads 47-44)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGL_t : reg_t<uint32_t, BASE_ADDRESS + 0x2C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x2C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F3F3F3F;
            static constexpr uint32_t reset_value = 0x18181818;

            /// Pad 47 function select
            static constexpr bitfield_t<PADREGL_t, 29, 27, GPIO::PAD47FNCSELv> PAD47FNCSEL = {};

            /// Pad 47 drive strength
            static constexpr bitfield_t<PADREGL_t, 26, 26, bool> PAD47STRNG = {};

            /// Pad 47 input enable
            static constexpr bitfield_t<PADREGL_t, 25, 25, bool> PAD47INPEN = {};

            /// Pad 47 pullup enable
            static constexpr bitfield_t<PADREGL_t, 24, 24, bool> PAD47PULL = {};

            /// Pad 46 function select
            static constexpr bitfield_t<PADREGL_t, 21, 19, GPIO::PAD46FNCSELv> PAD46FNCSEL = {};

            /// Pad 46 drive strength
            static constexpr bitfield_t<PADREGL_t, 18, 18, bool> PAD46STRNG = {};

            /// Pad 46 input enable
            static constexpr bitfield_t<PADREGL_t, 17, 17, bool> PAD46INPEN = {};

            /// Pad 46 pullup enable
            static constexpr bitfield_t<PADREGL_t, 16, 16, bool> PAD46PULL = {};

            /// Pad 45 function select
            static constexpr bitfield_t<PADREGL_t, 13, 11, GPIO::PAD45FNCSELv> PAD45FNCSEL = {};

            /// Pad 45 drive strength
            static constexpr bitfield_t<PADREGL_t, 10, 10, bool> PAD45STRNG = {};

            /// Pad 45 input enable
            static constexpr bitfield_t<PADREGL_t, 9, 9, bool> PAD45INPEN = {};

            /// Pad 45 pullup enable
            static constexpr bitfield_t<PADREGL_t, 8, 8, bool> PAD45PULL = {};

            /// Pad 44 function select
            static constexpr bitfield_t<PADREGL_t, 5, 3, GPIO::PAD44FNCSELv> PAD44FNCSEL = {};

            /// Pad 44 drive strength
            static constexpr bitfield_t<PADREGL_t, 2, 2, bool> PAD44STRNG = {};

            /// Pad 44 input enable
            static constexpr bitfield_t<PADREGL_t, 1, 1, bool> PAD44INPEN = {};

            /// Pad 44 pullup enable
            static constexpr bitfield_t<PADREGL_t, 0, 0, bool> PAD44PULL = {};
        } PADREGL = {};

        /**
         * PADREGM - 4 bytes at offset 48
         * Pad Configuration Register M (Pads 49-48)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADREGM_t : reg_t<uint32_t, BASE_ADDRESS + 0x30> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x30>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x1818;

            /// Pad 49 pullup resistor selection.
            static constexpr bitfield_t<PADREGM_t, 15, 14, GPIO::PADRSELv> PAD49RSEL = {};

            /// Pad 49 function select
            static constexpr bitfield_t<PADREGM_t, 13, 11, GPIO::PAD49FNCSELv> PAD49FNCSEL = {};

            /// Pad 49 drive strength
            static constexpr bitfield_t<PADREGM_t, 10, 10, bool> PAD49STRNG = {};

            /// Pad 49 input enable
            static constexpr bitfield_t<PADREGM_t, 9, 9, bool> PAD49INPEN = {};

            /// Pad 49 pullup enable
            static constexpr bitfield_t<PADREGM_t, 8, 8, bool> PAD49PULL = {};

            /// Pad 48 pullup resistor selection.
            static constexpr bitfield_t<PADREGM_t, 7, 6, GPIO::PADRSELv> PAD48RSEL = {};

            /// Pad 48 function select
            static constexpr bitfield_t<PADREGM_t, 5, 3, GPIO::PAD48FNCSELv> PAD48FNCSEL = {};

            /// Pad 48 drive strength
            static constexpr bitfield_t<PADREGM_t, 2, 2, bool> PAD48STRNG = {};

            /// Pad 48 input enable
            static constexpr bitfield_t<PADREGM_t, 1, 1, bool> PAD48INPEN = {};

            /// Pad 48 pullup enable
            static constexpr bitfield_t<PADREGM_t, 0, 0, bool> PAD48PULL = {};
        } PADREGM = {};

        /**
         * CFGA - 4 bytes at offset 64
         * GPIO Configuration Register A (Pads 7-0)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGA_t : reg_t<uint32_t, BASE_ADDRESS + 0x40> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x40>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO7 interrupt direction, nCE polarity.
            static constexpr bitfield_t<CFGA_t, 31, 31, bool> GPIO7INTD = {};

            /// GPIO7 output configuration.
            static constexpr bitfield_t<CFGA_t, 30, 29, GPIO::GPIOOUTCFGv> GPIO7OUTCFG = {};

            /// GPIO7 input enable.
            static constexpr bitfield_t<CFGA_t, 28, 28, bool> GPIO7INCFG = {};

            /// GPIO6 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 27, 27, bool> GPIO6INTD = {};

            /// GPIO6 output configuration.
            static constexpr bitfield_t<CFGA_t, 26, 25, GPIO::GPIOOUTCFGv> GPIO6OUTCFG = {};

            /// GPIO6 input enable.
            static constexpr bitfield_t<CFGA_t, 24, 24, bool> GPIO6INCFG = {};

            /// GPIO5 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 23, 23, bool> GPIO5INTD = {};

            /// GPIO5 output configuration.
            static constexpr bitfield_t<CFGA_t, 22, 21, GPIO::GPIOOUTCFGv> GPIO5OUTCFG = {};

            /// GPIO5 input enable.
            static constexpr bitfield_t<CFGA_t, 20, 20, bool> GPIO5INCFG = {};

            /// GPIO4 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 19, 19, bool> GPIO4INTD = {};

            /// GPIO4 output configuration.
            static constexpr bitfield_t<CFGA_t, 18, 17, GPIO::GPIOOUTCFGv> GPIO4OUTCFG = {};

            /// GPIO4 input enable.
            static constexpr bitfield_t<CFGA_t, 16, 16, bool> GPIO4INCFG = {};

            /// GPIO3 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 15, 15, bool> GPIO3INTD = {};

            /// GPIO3 output configuration.
            static constexpr bitfield_t<CFGA_t, 14, 13, GPIO::GPIOOUTCFGv> GPIO3OUTCFG = {};

            /// GPIO3 input enable.
            static constexpr bitfield_t<CFGA_t, 12, 12, bool> GPIO3INCFG = {};

            /// GPIO2 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 11, 11, bool> GPIO2INTD = {};

            /// GPIO2 output configuration.
            static constexpr bitfield_t<CFGA_t, 10, 9, GPIO::GPIOOUTCFGv> GPIO2OUTCFG = {};

            /// GPIO2 input enable.
            static constexpr bitfield_t<CFGA_t, 8, 8, bool> GPIO2INCFG = {};

            /// GPIO1 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 7, 7, bool> GPIO1INTD = {};

            /// GPIO1 output configuration.
            static constexpr bitfield_t<CFGA_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO1OUTCFG = {};

            /// GPIO1 input enable.
            static constexpr bitfield_t<CFGA_t, 4, 4, bool> GPIO1INCFG = {};

            /// GPIO0 interrupt direction.
            static constexpr bitfield_t<CFGA_t, 3, 3, bool> GPIO0INTD = {};

            /// GPIO0 output configuration.
            static constexpr bitfield_t<CFGA_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO0OUTCFG = {};

            /// GPIO0 input enable.
            static constexpr bitfield_t<CFGA_t, 0, 0, bool> GPIO0INCFG = {};
        } CFGA = {};

        /**
         * CFGB - 4 bytes at offset 68
         * GPIO Configuration Register B (Pads 15-8)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGB_t : reg_t<uint32_t, BASE_ADDRESS + 0x44> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x44>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO15 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 31, 31, bool> GPIO15INTD = {};

            /// GPIO15 output configuration.
            static constexpr bitfield_t<CFGB_t, 30, 29, GPIO::GPIOOUTCFGv> GPIO15OUTCFG = {};

            /// GPIO15 input enable.
            static constexpr bitfield_t<CFGB_t, 28, 28, bool> GPIO15INCFG = {};

            /// GPIO14 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 27, 27, bool> GPIO14INTD = {};

            /// GPIO14 output configuration.
            static constexpr bitfield_t<CFGB_t, 26, 25, GPIO::GPIOOUTCFGv> GPIO14OUTCFG = {};

            /// GPIO14 input enable.
            static constexpr bitfield_t<CFGB_t, 24, 24, bool> GPIO14INCFG = {};

            /// GPIO13 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 23, 23, bool> GPIO13INTD = {};

            /// GPIO13 output configuration.
            static constexpr bitfield_t<CFGB_t, 22, 21, GPIO::GPIOOUTCFGv> GPIO13OUTCFG = {};

            /// GPIO13 input enable.
            static constexpr bitfield_t<CFGB_t, 20, 20, bool> GPIO13INCFG = {};

            /// GPIO12 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 19, 19, bool> GPIO12INTD = {};

            /// GPIO12 output configuration.
            static constexpr bitfield_t<CFGB_t, 18, 17, GPIO::GPIOOUTCFGv> GPIO12OUTCFG = {};

            /// GPIO12 input enable.
            static constexpr bitfield_t<CFGB_t, 16, 16, bool> GPIO12INCFG = {};

            /// GPIO11 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 15, 15, bool> GPIO11INTD = {};

            /// GPIO11 output configuration.
            static constexpr bitfield_t<CFGB_t, 14, 13, GPIO::GPIOOUTCFGv> GPIO11OUTCFG = {};

            /// GPIO11 input enable.
            static constexpr bitfield_t<CFGB_t, 12, 12, bool> GPIO11INCFG = {};

            /// GPIO10 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 11, 11, bool> GPIO10INTD = {};

            /// GPIO10 output configuration.
            static constexpr bitfield_t<CFGB_t, 10, 9, GPIO::GPIOOUTCFGv> GPIO10OUTCFG = {};

            /// GPIO10 input enable.
            static constexpr bitfield_t<CFGB_t, 8, 8, bool> GPIO10INCFG = {};

            /// GPIO9 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 7, 7, bool> GPIO9INTD = {};

            /// GPIO9 output configuration.
            static constexpr bitfield_t<CFGB_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO9OUTCFG = {};

            /// GPIO9 input enable.
            static constexpr bitfield_t<CFGB_t, 4, 4, bool> GPIO9INCFG = {};

            /// GPIO8 interrupt direction.
            static constexpr bitfield_t<CFGB_t, 3, 3, bool> GPIO8INTD = {};

            /// GPIO8 output configuration.
            static constexpr bitfield_t<CFGB_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO8OUTCFG = {};

            /// GPIO8 input enable.
            static constexpr bitfield_t<CFGB_t, 0, 0, bool> GPIO8INCFG = {};
        } CFGB = {};

        /**
         * CFGC - 4 bytes at offset 72
         * GPIO Configuration Register C (Pads 23-16)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGC_t : reg_t<uint32_t, BASE_ADDRESS + 0x48> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x48>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x110000;

            /// GPIO23 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 31, 31, bool> GPIO23INTD = {};

            /// GPIO23 output configuration.
            static constexpr bitfield_t<CFGC_t, 30, 29, GPIO::GPIOOUTCFGv> GPIO23OUTCFG = {};

            /// GPIO23 input enable.
            static constexpr bitfield_t<CFGC_t, 28, 28, bool> GPIO23INCFG = {};

            /// GPIO22 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 27, 27, bool> GPIO22INTD = {};

            /// GPIO22 output configuration.
            static constexpr bitfield_t<CFGC_t, 26, 25, GPIO::GPIOOUTCFGv> GPIO22OUTCFG = {};

            /// GPIO22 input enable.
            static constexpr bitfield_t<CFGC_t, 24, 24, bool> GPIO22INCFG = {};

            /// GPIO21 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 23, 23, bool> GPIO21INTD = {};

            /// GPIO21 output configuration.
            static constexpr bitfield_t<CFGC_t, 22, 21, GPIO::GPIOOUTCFGv> GPIO21OUTCFG = {};

            /// GPIO21 input enable.
            static constexpr bitfield_t<CFGC_t, 20, 20, bool> GPIO21INCFG = {};

            /// GPIO20 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 19, 19, bool> GPIO20INTD = {};

            /// GPIO20 output configuration.
            static constexpr bitfield_t<CFGC_t, 18, 17, GPIO::GPIOOUTCFGv> GPIO20OUTCFG = {};

            /// GPIO20 input enable.
            static constexpr bitfield_t<CFGC_t, 16, 16, bool> GPIO20INCFG = {};

            /// GPIO19 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 15, 15, bool> GPIO19INTD = {};

            /// GPIO19 output configuration.
            static constexpr bitfield_t<CFGC_t, 14, 13, GPIO::GPIOOUTCFGv> GPIO19OUTCFG = {};

            /// GPIO19 input enable.
            static constexpr bitfield_t<CFGC_t, 12, 12, bool> GPIO19INCFG = {};

            /// GPIO18 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 11, 11, bool> GPIO18INTD = {};

            /// GPIO18 output configuration.
            static constexpr bitfield_t<CFGC_t, 10, 9, GPIO::GPIOOUTCFGv> GPIO18OUTCFG = {};

            /// GPIO18 input enable.
            static constexpr bitfield_t<CFGC_t, 8, 8, bool> GPIO18INCFG = {};

            /// GPIO17 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 7, 7, bool> GPIO17INTD = {};

            /// GPIO17 output configuration.
            static constexpr bitfield_t<CFGC_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO17OUTCFG = {};

            /// GPIO17 input enable.
            static constexpr bitfield_t<CFGC_t, 4, 4, bool> GPIO17INCFG = {};

            /// GPIO16 interrupt direction.
            static constexpr bitfield_t<CFGC_t, 3, 3, bool> GPIO16INTD = {};

            /// GPIO16 output configuration.
            static constexpr bitfield_t<CFGC_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO16OUTCFG = {};

            /// GPIO16 input enable.
            static constexpr bitfield_t<CFGC_t, 0, 0, bool> GPIO16INCFG = {};
        } CFGC = {};

        /**
         * CFGD - 4 bytes at offset 76
         * GPIO Configuration Register D (Pads 31-24)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGD_t : reg_t<uint32_t, BASE_ADDRESS + 0x4C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x4C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 31, 31, bool> GPIO31INTD = {};

            /// GPIO31 output configuration.
            static constexpr bitfield_t<CFGD_t, 30, 29, GPIO::GPIOOUTCFGv> GPIO31OUTCFG = {};

            /// GPIO31 input enable.
            static constexpr bitfield_t<CFGD_t, 28, 28, bool> GPIO31INCFG = {};

            /// GPIO30 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 27, 27, bool> GPIO30INTD = {};

            /// GPIO30 output configuration.
            static constexpr bitfield_t<CFGD_t, 26, 25, GPIO::GPIOOUTCFGv> GPIO30OUTCFG = {};

            /// GPIO30 input enable.
            static constexpr bitfield_t<CFGD_t, 24, 24, bool> GPIO30INCFG = {};

            /// GPIO29 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 23, 23, bool> GPIO29INTD = {};

            /// GPIO29 output configuration.
            static constexpr bitfield_t<CFGD_t, 22, 21, GPIO::GPIOOUTCFGv> GPIO29OUTCFG = {};

            /// GPIO29 input enable.
            static constexpr bitfield_t<CFGD_t, 20, 20, bool> GPIO29INCFG = {};

            /// GPIO28 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 19, 19, bool> GPIO28INTD = {};

            /// GPIO28 output configuration.
            static constexpr bitfield_t<CFGD_t, 18, 17, GPIO::GPIOOUTCFGv> GPIO28OUTCFG = {};

            /// GPIO28 input enable.
            static constexpr bitfield_t<CFGD_t, 16, 16, bool> GPIO28INCFG = {};

            /// GPIO27 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 15, 15, bool> GPIO27INTD = {};

            /// GPIO27 output configuration.
            static constexpr bitfield_t<CFGD_t, 14, 13, GPIO::GPIOOUTCFGv> GPIO27OUTCFG = {};

            /// GPIO27 input enable.
            static constexpr bitfield_t<CFGD_t, 12, 12, bool> GPIO27INCFG = {};

            /// GPIO26 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 11, 11, bool> GPIO26INTD = {};

            /// GPIO26 output configuration.
            static constexpr bitfield_t<CFGD_t, 10, 9, GPIO::GPIOOUTCFGv> GPIO26OUTCFG = {};

            /// GPIO26 input enable.
            static constexpr bitfield_t<CFGD_t, 8, 8, bool> GPIO26INCFG = {};

            /// GPIO25 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 7, 7, bool> GPIO25INTD = {};

            /// GPIO25 output configuration.
            static constexpr bitfield_t<CFGD_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO25OUTCFG = {};

            /// GPIO25 input enable.
            static constexpr bitfield_t<CFGD_t, 4, 4, bool> GPIO25INCFG = {};

            /// GPIO24 interrupt direction.
            static constexpr bitfield_t<CFGD_t, 3, 3, bool> GPIO24INTD = {};

            /// GPIO24 output configuration.
            static constexpr bitfield_t<CFGD_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO24OUTCFG = {};

            /// GPIO24 input enable.
            static constexpr bitfield_t<CFGD_t, 0, 0, bool> GPIO24INCFG = {};
        } CFGD = {};

        /**
         * CFGE - 4 bytes at offset 80
         * GPIO Configuration Register E (Pads 39-32)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGE_t : reg_t<uint32_t, BASE_ADDRESS + 0x50> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x50>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO39 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 31, 31, bool> GPIO39INTD = {};

            /// GPIO39 output configuration.
            static constexpr bitfield_t<CFGE_t, 30, 29, GPIO::GPIOOUTCFGv> GPIO39OUTCFG = {};

            /// GPIO39 input enable.
            static constexpr bitfield_t<CFGE_t, 28, 28, bool> GPIO39INCFG = {};

            /// GPIO38 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 27, 27, bool> GPIO38INTD = {};

            /// GPIO38 output configuration.
            static constexpr bitfield_t<CFGE_t, 26, 25, GPIO::GPIOOUTCFGv> GPIO38OUTCFG = {};

            /// GPIO38 input enable.
            static constexpr bitfield_t<CFGE_t, 24, 24, bool> GPIO38INCFG = {};

            /// GPIO37 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 23, 23, bool> GPIO37INTD = {};

            /// GPIO37 output configuration.
            static constexpr bitfield_t<CFGE_t, 22, 21, GPIO::GPIOOUTCFGv> GPIO37OUTCFG = {};

            /// GPIO37 input enable.
            static constexpr bitfield_t<CFGE_t, 20, 20, bool> GPIO37INCFG = {};

            /// GPIO36 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 19, 19, bool> GPIO36INTD = {};

            /// GPIO36 output configuration.
            static constexpr bitfield_t<CFGE_t, 18, 17, GPIO::GPIOOUTCFGv> GPIO36OUTCFG = {};

            /// GPIO36 input enable.
            static constexpr bitfield_t<CFGE_t, 16, 16, bool> GPIO36INCFG = {};

            /// GPIO35 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 15, 15, bool> GPIO35INTD = {};

            /// GPIO35 output configuration.
            static constexpr bitfield_t<CFGE_t, 14, 13, GPIO::GPIOOUTCFGv> GPIO35OUTCFG = {};

            /// GPIO35 input enable.
            static constexpr bitfield_t<CFGE_t, 12, 12, bool> GPIO35INCFG = {};

            /// GPIO34 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 11, 11, bool> GPIO34INTD = {};

            /// GPIO34 output configuration.
            static constexpr bitfield_t<CFGE_t, 10, 9, GPIO::GPIOOUTCFGv> GPIO34OUTCFG = {};

            /// GPIO34 input enable.
            static constexpr bitfield_t<CFGE_t, 8, 8, bool> GPIO34INCFG = {};

            /// GPIO33 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 7, 7, bool> GPIO33INTD = {};

            /// GPIO33 output configuration.
            static constexpr bitfield_t<CFGE_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO33OUTCFG = {};

            /// GPIO33 input enable.
            static constexpr bitfield_t<CFGE_t, 4, 4, bool> GPIO33INCFG = {};

            /// GPIO32 interrupt direction.
            static constexpr bitfield_t<CFGE_t, 3, 3, bool> GPIO32INTD = {};

            /// GPIO32 output configuration.
            static constexpr bitfield_t<CFGE_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO32OUTCFG = {};

            /// GPIO32 input enable.
            static constexpr bitfield_t<CFGE_t, 0, 0, bool> GPIO32INCFG = {};
        } CFGE = {};

        /**
         * CFGF - 4 bytes at offset 84
         * GPIO Configuration Register F (Pads 47-40)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGF_t : reg_t<uint32_t, BASE_ADDRESS + 0x54> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x54>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO47 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 31, 31, bool> GPIO47INTD = {};

            /// GPIO47 output configuration.
            static constexpr bitfield_t<CFGF_t, 30, 29, GPIO::GPIOOUTCFGv> GPIO47OUTCFG = {};

            /// GPIO47 input enable.
            static constexpr bitfield_t<CFGF_t, 28, 28, bool> GPIO47INCFG = {};

            /// GPIO46 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 27, 27, bool> GPIO46INTD = {};

            /// GPIO46 output configuration.
            static constexpr bitfield_t<CFGF_t, 26, 25, GPIO::GPIOOUTCFGv> GPIO46OUTCFG = {};

            /// GPIO46 input enable.
            static constexpr bitfield_t<CFGF_t, 24, 24, bool> GPIO46INCFG = {};

            /// GPIO45 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 23, 23, bool> GPIO45INTD = {};

            /// GPIO45 output configuration.
            static constexpr bitfield_t<CFGF_t, 22, 21, GPIO::GPIOOUTCFGv> GPIO45OUTCFG = {};

            /// GPIO45 input enable.
            static constexpr bitfield_t<CFGF_t, 20, 20, bool> GPIO45INCFG = {};

            /// GPIO44 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 19, 19, bool> GPIO44INTD = {};

            /// GPIO44 output configuration.
            static constexpr bitfield_t<CFGF_t, 18, 17, GPIO::GPIOOUTCFGv> GPIO44OUTCFG = {};

            /// GPIO44 input enable.
            static constexpr bitfield_t<CFGF_t, 16, 16, bool> GPIO44INCFG = {};

            /// GPIO43 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 15, 15, bool> GPIO43INTD = {};

            /// GPIO43 output configuration.
            static constexpr bitfield_t<CFGF_t, 14, 13, GPIO::GPIOOUTCFGv> GPIO43OUTCFG = {};

            /// GPIO43 input enable.
            static constexpr bitfield_t<CFGF_t, 12, 12, bool> GPIO43INCFG = {};

            /// GPIO42 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 11, 11, bool> GPIO42INTD = {};

            /// GPIO42 output configuration.
            static constexpr bitfield_t<CFGF_t, 10, 9, GPIO::GPIOOUTCFGv> GPIO42OUTCFG = {};

            /// GPIO42 input enable.
            static constexpr bitfield_t<CFGF_t, 8, 8, bool> GPIO42INCFG = {};

            /// GPIO41 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 7, 7, bool> GPIO41INTD = {};

            /// GPIO41 output configuration.
            static constexpr bitfield_t<CFGF_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO41OUTCFG = {};

            /// GPIO41 input enable.
            static constexpr bitfield_t<CFGF_t, 4, 4, bool> GPIO41INCFG = {};

            /// GPIO40 interrupt direction.
            static constexpr bitfield_t<CFGF_t, 3, 3, bool> GPIO40INTD = {};

            /// GPIO40 output configuration.
            static constexpr bitfield_t<CFGF_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO40OUTCFG = {};

            /// GPIO40 input enable.
            static constexpr bitfield_t<CFGF_t, 0, 0, bool> GPIO40INCFG = {};
        } CFGF = {};

        /**
         * CFGG - 4 bytes at offset 88
         * GPIO Configuration Register G (Pads 49-48)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CFGG_t : reg_t<uint32_t, BASE_ADDRESS + 0x58> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x58>::operator=;
            static constexpr uint32_t reset_mask  = 0xFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49 interrupt direction.
            static constexpr bitfield_t<CFGG_t, 7, 7, bool> GPIO49INTD = {};

            /// GPIO49 output configuration.
            static constexpr bitfield_t<CFGG_t, 6, 5, GPIO::GPIOOUTCFGv> GPIO49OUTCFG = {};

            /// GPIO49 input enable.
            static constexpr bitfield_t<CFGG_t, 4, 4, bool> GPIO49INCFG = {};

            /// GPIO48 interrupt direction.
            static constexpr bitfield_t<CFGG_t, 3, 3, bool> GPIO48INTD = {};

            /// GPIO48 output configuration.
            static constexpr bitfield_t<CFGG_t, 2, 1, GPIO::GPIOOUTCFGv> GPIO48OUTCFG = {};

            /// GPIO48 input enable.
            static constexpr bitfield_t<CFGG_t, 0, 0, bool> GPIO48INCFG = {};
        } CFGG = {};

        /**
         * PADKEY - 4 bytes at offset 96
         * Key Register for all pad configuration registers
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct PADKEY_t : reg_t<uint32_t, BASE_ADDRESS + 0x60> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x60>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Key register value.
            static constexpr bitfield_t<PADKEY_t, 31, 0, GPIO::PADKEYv> PADKEY = {};
        } PADKEY = {};

        /**
         * RDA - 4 bytes at offset 128
         * GPIO Input Register A
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RDA_t : reg_t<uint32_t, BASE_ADDRESS + 0x80> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x80>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31-0 read data.
            static constexpr bitfield_t<RDA_t, 31, 0> RDA = {};
        } RDA = {};

        /**
         * RDB - 4 bytes at offset 132
         * GPIO Input Register B
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct RDB_t : reg_t<uint32_t, BASE_ADDRESS + 0x84> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x84>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49-32 read data.
            static constexpr bitfield_t<RDB_t, 17, 0> RDB = {};
        } RDB = {};

        /**
         * WTA - 4 bytes at offset 136
         * GPIO Output Register A
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WTA_t : reg_t<uint32_t, BASE_ADDRESS + 0x88> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x88>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31-0 write data.
            static constexpr bitfield_t<WTA_t, 31, 0> WTA = {};
        } WTA = {};

        /**
         * WTB - 4 bytes at offset 140
         * GPIO Output Register B
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WTB_t : reg_t<uint32_t, BASE_ADDRESS + 0x8C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x8C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49-32 write data.
            static constexpr bitfield_t<WTB_t, 17, 0> WTB = {};
        } WTB = {};

        /**
         * WTSA - 4 bytes at offset 144
         * GPIO Output Register A Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WTSA_t : reg_t<uint32_t, BASE_ADDRESS + 0x90> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x90>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Set the GPIO31-0 write data.
            static constexpr bitfield_t<WTSA_t, 31, 0> WTSA = {};
        } WTSA = {};

        /**
         * WTSB - 4 bytes at offset 148
         * GPIO Output Register B Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WTSB_t : reg_t<uint32_t, BASE_ADDRESS + 0x94> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x94>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Set the GPIO49-32 write data.
            static constexpr bitfield_t<WTSB_t, 17, 0> WTSB = {};
        } WTSB = {};

        /**
         * WTCA - 4 bytes at offset 152
         * GPIO Output Register A Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WTCA_t : reg_t<uint32_t, BASE_ADDRESS + 0x98> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x98>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clear the GPIO31-0 write data.
            static constexpr bitfield_t<WTCA_t, 31, 0> WTCA = {};
        } WTCA = {};

        /**
         * WTCB - 4 bytes at offset 156
         * GPIO Output Register B Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct WTCB_t : reg_t<uint32_t, BASE_ADDRESS + 0x9C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x9C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clear the GPIO49-32 write data.
            static constexpr bitfield_t<WTCB_t, 17, 0> WTCB = {};
        } WTCB = {};

        /**
         * ENA - 4 bytes at offset 160
         * GPIO Enable Register A
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ENA_t : reg_t<uint32_t, BASE_ADDRESS + 0xA0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xA0>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31-0 output enables
            static constexpr bitfield_t<ENA_t, 31, 0> ENA = {};
        } ENA = {};

        /**
         * ENB - 4 bytes at offset 164
         * GPIO Enable Register B
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ENB_t : reg_t<uint32_t, BASE_ADDRESS + 0xA4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xA4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49-32 output enables
            static constexpr bitfield_t<ENB_t, 17, 0> ENB = {};
        } ENB = {};

        /**
         * ENSA - 4 bytes at offset 168
         * GPIO Enable Register A Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ENSA_t : reg_t<uint32_t, BASE_ADDRESS + 0xA8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xA8>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Set the GPIO31-0 output enables
            static constexpr bitfield_t<ENSA_t, 31, 0> ENSA = {};
        } ENSA = {};

        /**
         * ENSB - 4 bytes at offset 172
         * GPIO Enable Register B Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ENSB_t : reg_t<uint32_t, BASE_ADDRESS + 0xAC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xAC>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Set the GPIO49-32 output enables
            static constexpr bitfield_t<ENSB_t, 17, 0> ENSB = {};
        } ENSB = {};

        /**
         * ENCA - 4 bytes at offset 180
         * GPIO Enable Register A Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ENCA_t : reg_t<uint32_t, BASE_ADDRESS + 0xB4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xB4>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clear the GPIO31-0 output enables
            static constexpr bitfield_t<ENCA_t, 31, 0> ENCA = {};
        } ENCA = {};

        /**
         * ENCB - 4 bytes at offset 184
         * GPIO Enable Register B Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ENCB_t : reg_t<uint32_t, BASE_ADDRESS + 0xB8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xB8>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Clear the GPIO49-32 output enables
            static constexpr bitfield_t<ENCB_t, 17, 0> ENCB = {};
        } ENCB = {};

        /**
         * STMRCAP - 4 bytes at offset 188
         * STIMER Capture Control
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct STMRCAP_t : reg_t<uint32_t, BASE_ADDRESS + 0xBC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xBC>::operator=;
            static constexpr uint32_t reset_mask  = 0x7F7F7F7F;
            static constexpr uint32_t reset_value = 0x3F3F3F3F;

            /// STIMER Capture 3 Polarity.
            static constexpr bitfield_t<STMRCAP_t, 30, 30, bool> STPOL3 = {};

            /// STIMER Capture 3 Select.
            static constexpr bitfield_t<STMRCAP_t, 29, 24> STSEL3 = {};

            /// STIMER Capture 2 Polarity.
            static constexpr bitfield_t<STMRCAP_t, 22, 22, bool> STPOL2 = {};

            /// STIMER Capture 2 Select.
            static constexpr bitfield_t<STMRCAP_t, 21, 16> STSEL2 = {};

            /// STIMER Capture 1 Polarity.
            static constexpr bitfield_t<STMRCAP_t, 14, 14, bool> STPOL1 = {};

            /// STIMER Capture 1 Select.
            static constexpr bitfield_t<STMRCAP_t, 13, 8> STSEL1 = {};

            /// STIMER Capture 0 Polarity.
            static constexpr bitfield_t<STMRCAP_t, 6, 6, bool> STPOL0 = {};

            /// STIMER Capture 0 Select.
            static constexpr bitfield_t<STMRCAP_t, 5, 0> STSEL0 = {};
        } STMRCAP = {};

        /**
         * IOM0IRQ - 4 bytes at offset 192
         * IOM0 Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOM0IRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xC0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC0>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// IOMSTR0 IRQ pad select.
            static constexpr bitfield_t<IOM0IRQ_t, 5, 0> IOM0IRQ = {};
        } IOM0IRQ = {};

        /**
         * IOM1IRQ - 4 bytes at offset 196
         * IOM1 Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOM1IRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xC4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// IOMSTR1 IRQ pad select.
            static constexpr bitfield_t<IOM1IRQ_t, 5, 0> IOM1IRQ = {};
        } IOM1IRQ = {};

        /**
         * IOM2IRQ - 4 bytes at offset 200
         * IOM2 Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOM2IRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xC8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xC8>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// IOMSTR2 IRQ pad select.
            static constexpr bitfield_t<IOM2IRQ_t, 5, 0> IOM2IRQ = {};
        } IOM2IRQ = {};

        /**
         * IOM3IRQ - 4 bytes at offset 204
         * IOM3 Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOM3IRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xCC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xCC>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// IOMSTR3 IRQ pad select.
            static constexpr bitfield_t<IOM3IRQ_t, 5, 0> IOM3IRQ = {};
        } IOM3IRQ = {};

        /**
         * IOM4IRQ - 4 bytes at offset 208
         * IOM4 Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOM4IRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xD0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xD0>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// IOMSTR4 IRQ pad select.
            static constexpr bitfield_t<IOM4IRQ_t, 5, 0> IOM4IRQ = {};
        } IOM4IRQ = {};

        /**
         * IOM5IRQ - 4 bytes at offset 212
         * IOM5 Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct IOM5IRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xD4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xD4>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// IOMSTR5 IRQ pad select.
            static constexpr bitfield_t<IOM5IRQ_t, 5, 0> IOM5IRQ = {};
        } IOM5IRQ = {};

        /**
         * BLEIFIRQ - 4 bytes at offset 216
         * BLEIF Flow Control IRQ Select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct BLEIFIRQ_t : reg_t<uint32_t, BASE_ADDRESS + 0xD8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xD8>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// BLEIF IRQ pad select.
            static constexpr bitfield_t<BLEIFIRQ_t, 5, 0> BLEIFIRQ = {};
        } BLEIFIRQ = {};

        /**
         * GPIOOBS - 4 bytes at offset 220
         * GPIO Observation Mode Sample register
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct GPIOOBS_t : reg_t<uint32_t, BASE_ADDRESS + 0xDC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xDC>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// Sample of the data output on the GPIO observation port.  May have async sampling issues, as the data is not synronized to the read operation.  Intended for debug purposes only
            static constexpr bitfield_t<GPIOOBS_t, 15, 0> OBS_DATA = {};
        } GPIOOBS = {};

        /**
         * ALTPADCFGA - 4 bytes at offset 224
         * Alternate Pad Configuration reg0 (Pads 0-3)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGA_t : reg_t<uint32_t, BASE_ADDRESS + 0xE0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xE0>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 3 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGA_t, 28, 28, bool> PAD3_SR = {};

            /// Pad 3 high order drive strength selection.  Used in conjunction with PAD3STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGA_t, 24, 24, bool> PAD3_DS1 = {};

            /// Pad 2 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGA_t, 20, 20, bool> PAD2_SR = {};

            /// Pad 2 high order drive strength selection.  Used in conjunction with PAD2STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGA_t, 16, 16, bool> PAD2_DS1 = {};

            /// Pad 1 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGA_t, 12, 12, bool> PAD1_SR = {};

            /// Pad 1 high order drive strength selection.  Used in conjunction with PAD1STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGA_t, 8, 8, bool> PAD1_DS1 = {};

            /// Pad 0 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGA_t, 4, 4, bool> PAD0_SR = {};

            /// Pad 0 high order drive strength selection.  Used in conjunction with PAD0STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGA_t, 0, 0, bool> PAD0_DS1 = {};
        } ALTPADCFGA = {};

        /**
         * ALTPADCFGB - 4 bytes at offset 228
         * Alternate Pad Configuration reg1 (Pads 4-7)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGB_t : reg_t<uint32_t, BASE_ADDRESS + 0xE4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xE4>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 7 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGB_t, 28, 28, bool> PAD7_SR = {};

            /// Pad 7 high order drive strength selection.  Used in conjunction with PAD7STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGB_t, 24, 24, bool> PAD7_DS1 = {};

            /// Pad 6 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGB_t, 20, 20, bool> PAD6_SR = {};

            /// Pad 6 high order drive strength selection.  Used in conjunction with PAD6STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGB_t, 16, 16, bool> PAD6_DS1 = {};

            /// Pad 5 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGB_t, 12, 12, bool> PAD5_SR = {};

            /// Pad 5 high order drive strength selection.  Used in conjunction with PAD5STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGB_t, 8, 8, bool> PAD5_DS1 = {};

            /// Pad 4 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGB_t, 4, 4, bool> PAD4_SR = {};

            /// Pad 4 high order drive strength selection.  Used in conjunction with PAD4STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGB_t, 0, 0, bool> PAD4_DS1 = {};
        } ALTPADCFGB = {};

        /**
         * ALTPADCFGC - 4 bytes at offset 232
         * Alternate Pad Configuration reg2 (Pads 8-11)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGC_t : reg_t<uint32_t, BASE_ADDRESS + 0xE8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xE8>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 11 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGC_t, 28, 28, bool> PAD11_SR = {};

            /// Pad 11 high order drive strength selection.  Used in conjunction with PAD11STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGC_t, 24, 24, bool> PAD11_DS1 = {};

            /// Pad 10 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGC_t, 20, 20, bool> PAD10_SR = {};

            /// Pad 10 high order drive strength selection.  Used in conjunction with PAD10STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGC_t, 16, 16, bool> PAD10_DS1 = {};

            /// Pad 9 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGC_t, 12, 12, bool> PAD9_SR = {};

            /// Pad 9 high order drive strength selection.  Used in conjunction with PAD9STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGC_t, 8, 8, bool> PAD9_DS1 = {};

            /// Pad 8 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGC_t, 4, 4, bool> PAD8_SR = {};

            /// Pad 8 high order drive strength selection.  Used in conjunction with PAD8STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGC_t, 0, 0, bool> PAD8_DS1 = {};
        } ALTPADCFGC = {};

        /**
         * ALTPADCFGD - 4 bytes at offset 236
         * Alternate Pad Configuration reg3 (Pads 12-15)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGD_t : reg_t<uint32_t, BASE_ADDRESS + 0xEC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xEC>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 15 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGD_t, 28, 28, bool> PAD15_SR = {};

            /// Pad 15 high order drive strength selection.  Used in conjunction with PAD15STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGD_t, 24, 24, bool> PAD15_DS1 = {};

            /// Pad 14 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGD_t, 20, 20, bool> PAD14_SR = {};

            /// Pad 14 high order drive strength selection.  Used in conjunction with PAD14STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGD_t, 16, 16, bool> PAD14_DS1 = {};

            /// Pad 13 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGD_t, 12, 12, bool> PAD13_SR = {};

            /// Pad 13 high order drive strength selection.  Used in conjunction with PAD13STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGD_t, 8, 8, bool> PAD13_DS1 = {};

            /// Pad 12 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGD_t, 4, 4, bool> PAD12_SR = {};

            /// Pad 12 high order drive strength selection.  Used in conjunction with PAD12STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGD_t, 0, 0, bool> PAD12_DS1 = {};
        } ALTPADCFGD = {};

        /**
         * ALTPADCFGE - 4 bytes at offset 240
         * Alternate Pad Configuration reg4 (Pads 16-19)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGE_t : reg_t<uint32_t, BASE_ADDRESS + 0xF0> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xF0>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 19 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGE_t, 28, 28, bool> PAD19_SR = {};

            /// Pad 19 high order drive strength selection.  Used in conjunction with PAD19STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGE_t, 24, 24, bool> PAD19_DS1 = {};

            /// Pad 18 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGE_t, 20, 20, bool> PAD18_SR = {};

            /// Pad 18 high order drive strength selection.  Used in conjunction with PAD18STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGE_t, 16, 16, bool> PAD18_DS1 = {};

            /// Pad 17 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGE_t, 12, 12, bool> PAD17_SR = {};

            /// Pad 17 high order drive strength selection.  Used in conjunction with PAD17STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGE_t, 8, 8, bool> PAD17_DS1 = {};

            /// Pad 16 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGE_t, 4, 4, bool> PAD16_SR = {};

            /// Pad 16 high order drive strength selection.  Used in conjunction with PAD16STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGE_t, 0, 0, bool> PAD16_DS1 = {};
        } ALTPADCFGE = {};

        /**
         * ALTPADCFGF - 4 bytes at offset 244
         * Alternate Pad Configuration reg5 (Pads 20-23)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGF_t : reg_t<uint32_t, BASE_ADDRESS + 0xF4> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xF4>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 23 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGF_t, 28, 28, bool> PAD23_SR = {};

            /// Pad 23 high order drive strength selection.  Used in conjunction with PAD23STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGF_t, 24, 24, bool> PAD23_DS1 = {};

            /// Pad 22 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGF_t, 20, 20, bool> PAD22_SR = {};

            /// Pad 22 high order drive strength selection.  Used in conjunction with PAD22STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGF_t, 16, 16, bool> PAD22_DS1 = {};

            /// Pad 21 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGF_t, 12, 12, bool> PAD21_SR = {};

            /// Pad 21 high order drive strength selection.  Used in conjunction with PAD21STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGF_t, 8, 8, bool> PAD21_DS1 = {};

            /// Pad 20 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGF_t, 4, 4, bool> PAD20_SR = {};

            /// Pad 20 high order drive strength selection.  Used in conjunction with PAD20STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGF_t, 0, 0, bool> PAD20_DS1 = {};
        } ALTPADCFGF = {};

        /**
         * ALTPADCFGG - 4 bytes at offset 248
         * Alternate Pad Configuration reg6 (Pads 24-27)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGG_t : reg_t<uint32_t, BASE_ADDRESS + 0xF8> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xF8>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 27 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGG_t, 28, 28, bool> PAD27_SR = {};

            /// Pad 27 high order drive strength selection.  Used in conjunction with PAD27STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGG_t, 24, 24, bool> PAD27_DS1 = {};

            /// Pad 26 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGG_t, 20, 20, bool> PAD26_SR = {};

            /// Pad 26 high order drive strength selection.  Used in conjunction with PAD26STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGG_t, 16, 16, bool> PAD26_DS1 = {};

            /// Pad 25 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGG_t, 12, 12, bool> PAD25_SR = {};

            /// Pad 25 high order drive strength selection.  Used in conjunction with PAD25STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGG_t, 8, 8, bool> PAD25_DS1 = {};

            /// Pad 24 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGG_t, 4, 4, bool> PAD24_SR = {};

            /// Pad 24 high order drive strength selection.  Used in conjunction with PAD24STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGG_t, 0, 0, bool> PAD24_DS1 = {};
        } ALTPADCFGG = {};

        /**
         * ALTPADCFGH - 4 bytes at offset 252
         * Alternate Pad Configuration reg7 (Pads 28-31)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGH_t : reg_t<uint32_t, BASE_ADDRESS + 0xFC> {
            using reg_t<uint32_t, BASE_ADDRESS + 0xFC>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 31 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGH_t, 28, 28, bool> PAD31_SR = {};

            /// Pad 31 high order drive strength selection.  Used in conjunction with PAD31STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGH_t, 24, 24, bool> PAD31_DS1 = {};

            /// Pad 30 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGH_t, 20, 20, bool> PAD30_SR = {};

            /// Pad 30 high order drive strength selection.  Used in conjunction with PAD30STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGH_t, 16, 16, bool> PAD30_DS1 = {};

            /// Pad 29 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGH_t, 12, 12, bool> PAD29_SR = {};

            /// Pad 29 high order drive strength selection.  Used in conjunction with PAD29STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGH_t, 8, 8, bool> PAD29_DS1 = {};

            /// Pad 28 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGH_t, 4, 4, bool> PAD28_SR = {};

            /// Pad 28 high order drive strength selection.  Used in conjunction with PAD28STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGH_t, 0, 0, bool> PAD28_DS1 = {};
        } ALTPADCFGH = {};

        /**
         * ALTPADCFGI - 4 bytes at offset 256
         * Alternate Pad Configuration reg8 (Pads 32-35)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGI_t : reg_t<uint32_t, BASE_ADDRESS + 0x100> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x100>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 35 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGI_t, 28, 28, bool> PAD35_SR = {};

            /// Pad 35 high order drive strength selection.  Used in conjunction with PAD35STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGI_t, 24, 24, bool> PAD35_DS1 = {};

            /// Pad 34 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGI_t, 20, 20, bool> PAD34_SR = {};

            /// Pad 34 high order drive strength selection.  Used in conjunction with PAD34STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGI_t, 16, 16, bool> PAD34_DS1 = {};

            /// Pad 33 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGI_t, 12, 12, bool> PAD33_SR = {};

            /// Pad 33 high order drive strength selection.  Used in conjunction with PAD33STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGI_t, 8, 8, bool> PAD33_DS1 = {};

            /// Pad 32 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGI_t, 4, 4, bool> PAD32_SR = {};

            /// Pad 32 high order drive strength selection.  Used in conjunction with PAD32STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGI_t, 0, 0, bool> PAD32_DS1 = {};
        } ALTPADCFGI = {};

        /**
         * ALTPADCFGJ - 4 bytes at offset 260
         * Alternate Pad Configuration reg9 (Pads 36-39)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGJ_t : reg_t<uint32_t, BASE_ADDRESS + 0x104> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x104>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 39 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGJ_t, 28, 28, bool> PAD39_SR = {};

            /// Pad 39 high order drive strength selection.  Used in conjunction with PAD39STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGJ_t, 24, 24, bool> PAD39_DS1 = {};

            /// Pad 38 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGJ_t, 20, 20, bool> PAD38_SR = {};

            /// Pad 38 high order drive strength selection.  Used in conjunction with PAD38STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGJ_t, 16, 16, bool> PAD38_DS1 = {};

            /// Pad 37 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGJ_t, 12, 12, bool> PAD37_SR = {};

            /// Pad 37 high order drive strength selection.  Used in conjunction with PAD37STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGJ_t, 8, 8, bool> PAD37_DS1 = {};

            /// Pad 36 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGJ_t, 4, 4, bool> PAD36_SR = {};

            /// Pad 36 high order drive strength selection.  Used in conjunction with PAD36STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGJ_t, 0, 0, bool> PAD36_DS1 = {};
        } ALTPADCFGJ = {};

        /**
         * ALTPADCFGK - 4 bytes at offset 264
         * Alternate Pad Configuration reg10 (Pads 40-43)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGK_t : reg_t<uint32_t, BASE_ADDRESS + 0x108> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x108>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 43 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGK_t, 28, 28, bool> PAD43_SR = {};

            /// Pad 43 high order drive strength selection.  Used in conjunction with PAD43STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGK_t, 24, 24, bool> PAD43_DS1 = {};

            /// Pad 42 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGK_t, 20, 20, bool> PAD42_SR = {};

            /// Pad 42 high order drive strength selection.  Used in conjunction with PAD42STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGK_t, 16, 16, bool> PAD42_DS1 = {};

            /// Pad 41 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGK_t, 12, 12, bool> PAD41_SR = {};

            /// Pad 41 high order drive strength selection.  Used in conjunction with PAD41STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGK_t, 8, 8, bool> PAD41_DS1 = {};

            /// Pad 40 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGK_t, 4, 4, bool> PAD40_SR = {};

            /// Pad 40 high order drive strength selection.  Used in conjunction with PAD40STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGK_t, 0, 0, bool> PAD40_DS1 = {};
        } ALTPADCFGK = {};

        /**
         * ALTPADCFGL - 4 bytes at offset 268
         * Alternate Pad Configuration reg11 (Pads 44-47)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGL_t : reg_t<uint32_t, BASE_ADDRESS + 0x10C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x10C>::operator=;
            static constexpr uint32_t reset_mask  = 0x11111111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 47 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGL_t, 28, 28, bool> PAD47_SR = {};

            /// Pad 47 high order drive strength selection.  Used in conjunction with PAD47STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGL_t, 24, 24, bool> PAD47_DS1 = {};

            /// Pad 46 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGL_t, 20, 20, bool> PAD46_SR = {};

            /// Pad 46 high order drive strength selection.  Used in conjunction with PAD46STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGL_t, 16, 16, bool> PAD46_DS1 = {};

            /// Pad 45 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGL_t, 12, 12, bool> PAD45_SR = {};

            /// Pad 45 high order drive strength selection.  Used in conjunction with PAD45STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGL_t, 8, 8, bool> PAD45_DS1 = {};

            /// Pad 44 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGL_t, 4, 4, bool> PAD44_SR = {};

            /// Pad 44 high order drive strength selection.  Used in conjunction with PAD44STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGL_t, 0, 0, bool> PAD44_DS1 = {};
        } ALTPADCFGL = {};

        /**
         * ALTPADCFGM - 4 bytes at offset 272
         * Alternate Pad Configuration reg12 (Pads 48-49)
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct ALTPADCFGM_t : reg_t<uint32_t, BASE_ADDRESS + 0x110> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x110>::operator=;
            static constexpr uint32_t reset_mask  = 0x1111;
            static constexpr uint32_t reset_value = 0x0;

            /// Pad 49 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGM_t, 12, 12, bool> PAD49_SR = {};

            /// Pad 49 high order drive strength selection.  Used in conjunction with PAD49STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGM_t, 8, 8, bool> PAD49_DS1 = {};

            /// Pad 48 slew rate selection.
            static constexpr bitfield_t<ALTPADCFGM_t, 4, 4, bool> PAD48_SR = {};

            /// Pad 48 high order drive strength selection.  Used in conjunction with PAD48STRNG field to set the pad drive strength.
            static constexpr bitfield_t<ALTPADCFGM_t, 0, 0, bool> PAD48_DS1 = {};
        } ALTPADCFGM = {};

        /**
         * SCDET - 4 bytes at offset 276
         * SCARD Card Detect select
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct SCDET_t : reg_t<uint32_t, BASE_ADDRESS + 0x114> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x114>::operator=;
            static constexpr uint32_t reset_mask  = 0x3F;
            static constexpr uint32_t reset_value = 0x3F;

            /// SCARD card detect pad select.
            static constexpr bitfield_t<SCDET_t, 5, 0> SCDET = {};
        } SCDET = {};

        /**
         * CTENCFG - 4 bytes at offset 280
         * Counter/Timer Enable Config
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct CTENCFG_t : reg_t<uint32_t, BASE_ADDRESS + 0x118> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x118>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0xFFFFFFFF;

            /// CT31 Enable
            static constexpr bitfield_t<CTENCFG_t, 31, 31, bool> EN31 = {};

            /// CT30 Enable
            static constexpr bitfield_t<CTENCFG_t, 30, 30, bool> EN30 = {};

            /// CT29 Enable
            static constexpr bitfield_t<CTENCFG_t, 29, 29, bool> EN29 = {};

            /// CT28 Enable
            static constexpr bitfield_t<CTENCFG_t, 28, 28, bool> EN28 = {};

            /// CT27 Enable
            static constexpr bitfield_t<CTENCFG_t, 27, 27, bool> EN27 = {};

            /// CT26 Enable
            static constexpr bitfield_t<CTENCFG_t, 26, 26, bool> EN26 = {};

            /// CT25 Enable
            static constexpr bitfield_t<CTENCFG_t, 25, 25, bool> EN25 = {};

            /// CT24 Enable
            static constexpr bitfield_t<CTENCFG_t, 24, 24, bool> EN24 = {};

            /// CT23 Enable
            static constexpr bitfield_t<CTENCFG_t, 23, 23, bool> EN23 = {};

            /// CT22 Enable
            static constexpr bitfield_t<CTENCFG_t, 22, 22, bool> EN22 = {};

            /// CT21 Enable
            static constexpr bitfield_t<CTENCFG_t, 21, 21, bool> EN21 = {};

            /// CT20 Enable
            static constexpr bitfield_t<CTENCFG_t, 20, 20, bool> EN20 = {};

            /// CT19 Enable
            static constexpr bitfield_t<CTENCFG_t, 19, 19, bool> EN19 = {};

            /// CT18 Enable
            static constexpr bitfield_t<CTENCFG_t, 18, 18, bool> EN18 = {};

            /// CT17 Enable
            static constexpr bitfield_t<CTENCFG_t, 17, 17, bool> EN17 = {};

            /// CT16 Enable
            static constexpr bitfield_t<CTENCFG_t, 16, 16, bool> EN16 = {};

            /// CT15 Enable
            static constexpr bitfield_t<CTENCFG_t, 15, 15, bool> EN15 = {};

            /// CT14 Enable
            static constexpr bitfield_t<CTENCFG_t, 14, 14, bool> EN14 = {};

            /// CT13 Enable
            static constexpr bitfield_t<CTENCFG_t, 13, 13, bool> EN13 = {};

            /// CT12 Enable
            static constexpr bitfield_t<CTENCFG_t, 12, 12, bool> EN12 = {};

            /// CT11 Enable
            static constexpr bitfield_t<CTENCFG_t, 11, 11, bool> EN11 = {};

            /// CT10 Enable
            static constexpr bitfield_t<CTENCFG_t, 10, 10, bool> EN10 = {};

            /// CT9 Enable
            static constexpr bitfield_t<CTENCFG_t, 9, 9, bool> EN9 = {};

            /// CT8 Enable
            static constexpr bitfield_t<CTENCFG_t, 8, 8, bool> EN8 = {};

            /// CT7 Enable
            static constexpr bitfield_t<CTENCFG_t, 7, 7, bool> EN7 = {};

            /// CT6 Enable
            static constexpr bitfield_t<CTENCFG_t, 6, 6, bool> EN6 = {};

            /// CT5 Enable
            static constexpr bitfield_t<CTENCFG_t, 5, 5, bool> EN5 = {};

            /// CT4 Enable
            static constexpr bitfield_t<CTENCFG_t, 4, 4, bool> EN4 = {};

            /// CT3 Enable
            static constexpr bitfield_t<CTENCFG_t, 3, 3, bool> EN3 = {};

            /// CT2 Enable
            static constexpr bitfield_t<CTENCFG_t, 2, 2, bool> EN2 = {};

            /// CT1 Enable
            static constexpr bitfield_t<CTENCFG_t, 1, 1, bool> EN1 = {};

            /// CT0 Enable
            static constexpr bitfield_t<CTENCFG_t, 0, 0, bool> EN0 = {};
        } CTENCFG = {};

        /**
         * INT0EN - 4 bytes at offset 512
         * GPIO Interrupt Registers 31-0: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT0EN_t : reg_t<uint32_t, BASE_ADDRESS + 0x200> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x200>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31 interrupt.
            static constexpr bitfield_t<INT0EN_t, 31, 31, bool> GPIO31 = {};

            /// GPIO30 interrupt.
            static constexpr bitfield_t<INT0EN_t, 30, 30, bool> GPIO30 = {};

            /// GPIO29 interrupt.
            static constexpr bitfield_t<INT0EN_t, 29, 29, bool> GPIO29 = {};

            /// GPIO28 interrupt.
            static constexpr bitfield_t<INT0EN_t, 28, 28, bool> GPIO28 = {};

            /// GPIO27 interrupt.
            static constexpr bitfield_t<INT0EN_t, 27, 27, bool> GPIO27 = {};

            /// GPIO26 interrupt.
            static constexpr bitfield_t<INT0EN_t, 26, 26, bool> GPIO26 = {};

            /// GPIO25 interrupt.
            static constexpr bitfield_t<INT0EN_t, 25, 25, bool> GPIO25 = {};

            /// GPIO24 interrupt.
            static constexpr bitfield_t<INT0EN_t, 24, 24, bool> GPIO24 = {};

            /// GPIO23 interrupt.
            static constexpr bitfield_t<INT0EN_t, 23, 23, bool> GPIO23 = {};

            /// GPIO22 interrupt.
            static constexpr bitfield_t<INT0EN_t, 22, 22, bool> GPIO22 = {};

            /// GPIO21 interrupt.
            static constexpr bitfield_t<INT0EN_t, 21, 21, bool> GPIO21 = {};

            /// GPIO20 interrupt.
            static constexpr bitfield_t<INT0EN_t, 20, 20, bool> GPIO20 = {};

            /// GPIO19 interrupt.
            static constexpr bitfield_t<INT0EN_t, 19, 19, bool> GPIO19 = {};

            /// GPIO18interrupt.
            static constexpr bitfield_t<INT0EN_t, 18, 18, bool> GPIO18 = {};

            /// GPIO17 interrupt.
            static constexpr bitfield_t<INT0EN_t, 17, 17, bool> GPIO17 = {};

            /// GPIO16 interrupt.
            static constexpr bitfield_t<INT0EN_t, 16, 16, bool> GPIO16 = {};

            /// GPIO15 interrupt.
            static constexpr bitfield_t<INT0EN_t, 15, 15, bool> GPIO15 = {};

            /// GPIO14 interrupt.
            static constexpr bitfield_t<INT0EN_t, 14, 14, bool> GPIO14 = {};

            /// GPIO13 interrupt.
            static constexpr bitfield_t<INT0EN_t, 13, 13, bool> GPIO13 = {};

            /// GPIO12 interrupt.
            static constexpr bitfield_t<INT0EN_t, 12, 12, bool> GPIO12 = {};

            /// GPIO11 interrupt.
            static constexpr bitfield_t<INT0EN_t, 11, 11, bool> GPIO11 = {};

            /// GPIO10 interrupt.
            static constexpr bitfield_t<INT0EN_t, 10, 10, bool> GPIO10 = {};

            /// GPIO9 interrupt.
            static constexpr bitfield_t<INT0EN_t, 9, 9, bool> GPIO9 = {};

            /// GPIO8 interrupt.
            static constexpr bitfield_t<INT0EN_t, 8, 8, bool> GPIO8 = {};

            /// GPIO7 interrupt.
            static constexpr bitfield_t<INT0EN_t, 7, 7, bool> GPIO7 = {};

            /// GPIO6 interrupt.
            static constexpr bitfield_t<INT0EN_t, 6, 6, bool> GPIO6 = {};

            /// GPIO5 interrupt.
            static constexpr bitfield_t<INT0EN_t, 5, 5, bool> GPIO5 = {};

            /// GPIO4 interrupt.
            static constexpr bitfield_t<INT0EN_t, 4, 4, bool> GPIO4 = {};

            /// GPIO3 interrupt.
            static constexpr bitfield_t<INT0EN_t, 3, 3, bool> GPIO3 = {};

            /// GPIO2 interrupt.
            static constexpr bitfield_t<INT0EN_t, 2, 2, bool> GPIO2 = {};

            /// GPIO1 interrupt.
            static constexpr bitfield_t<INT0EN_t, 1, 1, bool> GPIO1 = {};

            /// GPIO0 interrupt.
            static constexpr bitfield_t<INT0EN_t, 0, 0, bool> GPIO0 = {};
        } INT0EN = {};

        /**
         * INT0STAT - 4 bytes at offset 516
         * GPIO Interrupt Registers 31-0: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT0STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x204> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x204>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 31, 31, bool> GPIO31 = {};

            /// GPIO30 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 30, 30, bool> GPIO30 = {};

            /// GPIO29 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 29, 29, bool> GPIO29 = {};

            /// GPIO28 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 28, 28, bool> GPIO28 = {};

            /// GPIO27 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 27, 27, bool> GPIO27 = {};

            /// GPIO26 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 26, 26, bool> GPIO26 = {};

            /// GPIO25 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 25, 25, bool> GPIO25 = {};

            /// GPIO24 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 24, 24, bool> GPIO24 = {};

            /// GPIO23 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 23, 23, bool> GPIO23 = {};

            /// GPIO22 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 22, 22, bool> GPIO22 = {};

            /// GPIO21 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 21, 21, bool> GPIO21 = {};

            /// GPIO20 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 20, 20, bool> GPIO20 = {};

            /// GPIO19 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 19, 19, bool> GPIO19 = {};

            /// GPIO18interrupt.
            static constexpr bitfield_t<INT0STAT_t, 18, 18, bool> GPIO18 = {};

            /// GPIO17 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 17, 17, bool> GPIO17 = {};

            /// GPIO16 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 16, 16, bool> GPIO16 = {};

            /// GPIO15 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 15, 15, bool> GPIO15 = {};

            /// GPIO14 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 14, 14, bool> GPIO14 = {};

            /// GPIO13 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 13, 13, bool> GPIO13 = {};

            /// GPIO12 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 12, 12, bool> GPIO12 = {};

            /// GPIO11 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 11, 11, bool> GPIO11 = {};

            /// GPIO10 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 10, 10, bool> GPIO10 = {};

            /// GPIO9 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 9, 9, bool> GPIO9 = {};

            /// GPIO8 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 8, 8, bool> GPIO8 = {};

            /// GPIO7 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 7, 7, bool> GPIO7 = {};

            /// GPIO6 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 6, 6, bool> GPIO6 = {};

            /// GPIO5 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 5, 5, bool> GPIO5 = {};

            /// GPIO4 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 4, 4, bool> GPIO4 = {};

            /// GPIO3 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 3, 3, bool> GPIO3 = {};

            /// GPIO2 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 2, 2, bool> GPIO2 = {};

            /// GPIO1 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 1, 1, bool> GPIO1 = {};

            /// GPIO0 interrupt.
            static constexpr bitfield_t<INT0STAT_t, 0, 0, bool> GPIO0 = {};
        } INT0STAT = {};

        /**
         * INT0CLR - 4 bytes at offset 520
         * GPIO Interrupt Registers 31-0: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT0CLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x208> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x208>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 31, 31, bool> GPIO31 = {};

            /// GPIO30 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 30, 30, bool> GPIO30 = {};

            /// GPIO29 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 29, 29, bool> GPIO29 = {};

            /// GPIO28 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 28, 28, bool> GPIO28 = {};

            /// GPIO27 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 27, 27, bool> GPIO27 = {};

            /// GPIO26 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 26, 26, bool> GPIO26 = {};

            /// GPIO25 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 25, 25, bool> GPIO25 = {};

            /// GPIO24 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 24, 24, bool> GPIO24 = {};

            /// GPIO23 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 23, 23, bool> GPIO23 = {};

            /// GPIO22 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 22, 22, bool> GPIO22 = {};

            /// GPIO21 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 21, 21, bool> GPIO21 = {};

            /// GPIO20 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 20, 20, bool> GPIO20 = {};

            /// GPIO19 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 19, 19, bool> GPIO19 = {};

            /// GPIO18interrupt.
            static constexpr bitfield_t<INT0CLR_t, 18, 18, bool> GPIO18 = {};

            /// GPIO17 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 17, 17, bool> GPIO17 = {};

            /// GPIO16 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 16, 16, bool> GPIO16 = {};

            /// GPIO15 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 15, 15, bool> GPIO15 = {};

            /// GPIO14 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 14, 14, bool> GPIO14 = {};

            /// GPIO13 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 13, 13, bool> GPIO13 = {};

            /// GPIO12 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 12, 12, bool> GPIO12 = {};

            /// GPIO11 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 11, 11, bool> GPIO11 = {};

            /// GPIO10 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 10, 10, bool> GPIO10 = {};

            /// GPIO9 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 9, 9, bool> GPIO9 = {};

            /// GPIO8 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 8, 8, bool> GPIO8 = {};

            /// GPIO7 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 7, 7, bool> GPIO7 = {};

            /// GPIO6 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 6, 6, bool> GPIO6 = {};

            /// GPIO5 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 5, 5, bool> GPIO5 = {};

            /// GPIO4 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 4, 4, bool> GPIO4 = {};

            /// GPIO3 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 3, 3, bool> GPIO3 = {};

            /// GPIO2 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 2, 2, bool> GPIO2 = {};

            /// GPIO1 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 1, 1, bool> GPIO1 = {};

            /// GPIO0 interrupt.
            static constexpr bitfield_t<INT0CLR_t, 0, 0, bool> GPIO0 = {};
        } INT0CLR = {};

        /**
         * INT0SET - 4 bytes at offset 524
         * GPIO Interrupt Registers 31-0: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT0SET_t : reg_t<uint32_t, BASE_ADDRESS + 0x20C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x20C>::operator=;
            static constexpr uint32_t reset_mask  = 0xFFFFFFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO31 interrupt.
            static constexpr bitfield_t<INT0SET_t, 31, 31, bool> GPIO31 = {};

            /// GPIO30 interrupt.
            static constexpr bitfield_t<INT0SET_t, 30, 30, bool> GPIO30 = {};

            /// GPIO29 interrupt.
            static constexpr bitfield_t<INT0SET_t, 29, 29, bool> GPIO29 = {};

            /// GPIO28 interrupt.
            static constexpr bitfield_t<INT0SET_t, 28, 28, bool> GPIO28 = {};

            /// GPIO27 interrupt.
            static constexpr bitfield_t<INT0SET_t, 27, 27, bool> GPIO27 = {};

            /// GPIO26 interrupt.
            static constexpr bitfield_t<INT0SET_t, 26, 26, bool> GPIO26 = {};

            /// GPIO25 interrupt.
            static constexpr bitfield_t<INT0SET_t, 25, 25, bool> GPIO25 = {};

            /// GPIO24 interrupt.
            static constexpr bitfield_t<INT0SET_t, 24, 24, bool> GPIO24 = {};

            /// GPIO23 interrupt.
            static constexpr bitfield_t<INT0SET_t, 23, 23, bool> GPIO23 = {};

            /// GPIO22 interrupt.
            static constexpr bitfield_t<INT0SET_t, 22, 22, bool> GPIO22 = {};

            /// GPIO21 interrupt.
            static constexpr bitfield_t<INT0SET_t, 21, 21, bool> GPIO21 = {};

            /// GPIO20 interrupt.
            static constexpr bitfield_t<INT0SET_t, 20, 20, bool> GPIO20 = {};

            /// GPIO19 interrupt.
            static constexpr bitfield_t<INT0SET_t, 19, 19, bool> GPIO19 = {};

            /// GPIO18interrupt.
            static constexpr bitfield_t<INT0SET_t, 18, 18, bool> GPIO18 = {};

            /// GPIO17 interrupt.
            static constexpr bitfield_t<INT0SET_t, 17, 17, bool> GPIO17 = {};

            /// GPIO16 interrupt.
            static constexpr bitfield_t<INT0SET_t, 16, 16, bool> GPIO16 = {};

            /// GPIO15 interrupt.
            static constexpr bitfield_t<INT0SET_t, 15, 15, bool> GPIO15 = {};

            /// GPIO14 interrupt.
            static constexpr bitfield_t<INT0SET_t, 14, 14, bool> GPIO14 = {};

            /// GPIO13 interrupt.
            static constexpr bitfield_t<INT0SET_t, 13, 13, bool> GPIO13 = {};

            /// GPIO12 interrupt.
            static constexpr bitfield_t<INT0SET_t, 12, 12, bool> GPIO12 = {};

            /// GPIO11 interrupt.
            static constexpr bitfield_t<INT0SET_t, 11, 11, bool> GPIO11 = {};

            /// GPIO10 interrupt.
            static constexpr bitfield_t<INT0SET_t, 10, 10, bool> GPIO10 = {};

            /// GPIO9 interrupt.
            static constexpr bitfield_t<INT0SET_t, 9, 9, bool> GPIO9 = {};

            /// GPIO8 interrupt.
            static constexpr bitfield_t<INT0SET_t, 8, 8, bool> GPIO8 = {};

            /// GPIO7 interrupt.
            static constexpr bitfield_t<INT0SET_t, 7, 7, bool> GPIO7 = {};

            /// GPIO6 interrupt.
            static constexpr bitfield_t<INT0SET_t, 6, 6, bool> GPIO6 = {};

            /// GPIO5 interrupt.
            static constexpr bitfield_t<INT0SET_t, 5, 5, bool> GPIO5 = {};

            /// GPIO4 interrupt.
            static constexpr bitfield_t<INT0SET_t, 4, 4, bool> GPIO4 = {};

            /// GPIO3 interrupt.
            static constexpr bitfield_t<INT0SET_t, 3, 3, bool> GPIO3 = {};

            /// GPIO2 interrupt.
            static constexpr bitfield_t<INT0SET_t, 2, 2, bool> GPIO2 = {};

            /// GPIO1 interrupt.
            static constexpr bitfield_t<INT0SET_t, 1, 1, bool> GPIO1 = {};

            /// GPIO0 interrupt.
            static constexpr bitfield_t<INT0SET_t, 0, 0, bool> GPIO0 = {};
        } INT0SET = {};

        /**
         * INT1EN - 4 bytes at offset 528
         * GPIO Interrupt Registers 49-32: Enable
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT1EN_t : reg_t<uint32_t, BASE_ADDRESS + 0x210> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x210>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49 interrupt.
            static constexpr bitfield_t<INT1EN_t, 17, 17, bool> GPIO49 = {};

            /// GPIO48 interrupt.
            static constexpr bitfield_t<INT1EN_t, 16, 16, bool> GPIO48 = {};

            /// GPIO47 interrupt.
            static constexpr bitfield_t<INT1EN_t, 15, 15, bool> GPIO47 = {};

            /// GPIO46 interrupt.
            static constexpr bitfield_t<INT1EN_t, 14, 14, bool> GPIO46 = {};

            /// GPIO45 interrupt.
            static constexpr bitfield_t<INT1EN_t, 13, 13, bool> GPIO45 = {};

            /// GPIO44 interrupt.
            static constexpr bitfield_t<INT1EN_t, 12, 12, bool> GPIO44 = {};

            /// GPIO43 interrupt.
            static constexpr bitfield_t<INT1EN_t, 11, 11, bool> GPIO43 = {};

            /// GPIO42 interrupt.
            static constexpr bitfield_t<INT1EN_t, 10, 10, bool> GPIO42 = {};

            /// GPIO41 interrupt.
            static constexpr bitfield_t<INT1EN_t, 9, 9, bool> GPIO41 = {};

            /// GPIO40 interrupt.
            static constexpr bitfield_t<INT1EN_t, 8, 8, bool> GPIO40 = {};

            /// GPIO39 interrupt.
            static constexpr bitfield_t<INT1EN_t, 7, 7, bool> GPIO39 = {};

            /// GPIO38 interrupt.
            static constexpr bitfield_t<INT1EN_t, 6, 6, bool> GPIO38 = {};

            /// GPIO37 interrupt.
            static constexpr bitfield_t<INT1EN_t, 5, 5, bool> GPIO37 = {};

            /// GPIO36 interrupt.
            static constexpr bitfield_t<INT1EN_t, 4, 4, bool> GPIO36 = {};

            /// GPIO35 interrupt.
            static constexpr bitfield_t<INT1EN_t, 3, 3, bool> GPIO35 = {};

            /// GPIO34 interrupt.
            static constexpr bitfield_t<INT1EN_t, 2, 2, bool> GPIO34 = {};

            /// GPIO33 interrupt.
            static constexpr bitfield_t<INT1EN_t, 1, 1, bool> GPIO33 = {};

            /// GPIO32 interrupt.
            static constexpr bitfield_t<INT1EN_t, 0, 0, bool> GPIO32 = {};
        } INT1EN = {};

        /**
         * INT1STAT - 4 bytes at offset 532
         * GPIO Interrupt Registers 49-32: Status
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT1STAT_t : reg_t<uint32_t, BASE_ADDRESS + 0x214> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x214>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 17, 17, bool> GPIO49 = {};

            /// GPIO48 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 16, 16, bool> GPIO48 = {};

            /// GPIO47 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 15, 15, bool> GPIO47 = {};

            /// GPIO46 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 14, 14, bool> GPIO46 = {};

            /// GPIO45 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 13, 13, bool> GPIO45 = {};

            /// GPIO44 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 12, 12, bool> GPIO44 = {};

            /// GPIO43 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 11, 11, bool> GPIO43 = {};

            /// GPIO42 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 10, 10, bool> GPIO42 = {};

            /// GPIO41 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 9, 9, bool> GPIO41 = {};

            /// GPIO40 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 8, 8, bool> GPIO40 = {};

            /// GPIO39 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 7, 7, bool> GPIO39 = {};

            /// GPIO38 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 6, 6, bool> GPIO38 = {};

            /// GPIO37 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 5, 5, bool> GPIO37 = {};

            /// GPIO36 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 4, 4, bool> GPIO36 = {};

            /// GPIO35 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 3, 3, bool> GPIO35 = {};

            /// GPIO34 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 2, 2, bool> GPIO34 = {};

            /// GPIO33 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 1, 1, bool> GPIO33 = {};

            /// GPIO32 interrupt.
            static constexpr bitfield_t<INT1STAT_t, 0, 0, bool> GPIO32 = {};
        } INT1STAT = {};

        /**
         * INT1CLR - 4 bytes at offset 536
         * GPIO Interrupt Registers 49-32: Clear
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT1CLR_t : reg_t<uint32_t, BASE_ADDRESS + 0x218> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x218>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 17, 17, bool> GPIO49 = {};

            /// GPIO48 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 16, 16, bool> GPIO48 = {};

            /// GPIO47 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 15, 15, bool> GPIO47 = {};

            /// GPIO46 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 14, 14, bool> GPIO46 = {};

            /// GPIO45 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 13, 13, bool> GPIO45 = {};

            /// GPIO44 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 12, 12, bool> GPIO44 = {};

            /// GPIO43 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 11, 11, bool> GPIO43 = {};

            /// GPIO42 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 10, 10, bool> GPIO42 = {};

            /// GPIO41 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 9, 9, bool> GPIO41 = {};

            /// GPIO40 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 8, 8, bool> GPIO40 = {};

            /// GPIO39 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 7, 7, bool> GPIO39 = {};

            /// GPIO38 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 6, 6, bool> GPIO38 = {};

            /// GPIO37 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 5, 5, bool> GPIO37 = {};

            /// GPIO36 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 4, 4, bool> GPIO36 = {};

            /// GPIO35 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 3, 3, bool> GPIO35 = {};

            /// GPIO34 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 2, 2, bool> GPIO34 = {};

            /// GPIO33 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 1, 1, bool> GPIO33 = {};

            /// GPIO32 interrupt.
            static constexpr bitfield_t<INT1CLR_t, 0, 0, bool> GPIO32 = {};
        } INT1CLR = {};

        /**
         * INT1SET - 4 bytes at offset 540
         * GPIO Interrupt Registers 49-32: Set
         * Access: read-write
         * Protection: None
         * Write side-effects: None
         * Read side-effects: None
         */
        static constexpr struct INT1SET_t : reg_t<uint32_t, BASE_ADDRESS + 0x21C> {
            using reg_t<uint32_t, BASE_ADDRESS + 0x21C>::operator=;
            static constexpr uint32_t reset_mask  = 0x3FFFF;
            static constexpr uint32_t reset_value = 0x0;

            /// GPIO49 interrupt.
            static constexpr bitfield_t<INT1SET_t, 17, 17, bool> GPIO49 = {};

            /// GPIO48 interrupt.
            static constexpr bitfield_t<INT1SET_t, 16, 16, bool> GPIO48 = {};

            /// GPIO47 interrupt.
            static constexpr bitfield_t<INT1SET_t, 15, 15, bool> GPIO47 = {};

            /// GPIO46 interrupt.
            static constexpr bitfield_t<INT1SET_t, 14, 14, bool> GPIO46 = {};

            /// GPIO45 interrupt.
            static constexpr bitfield_t<INT1SET_t, 13, 13, bool> GPIO45 = {};

            /// GPIO44 interrupt.
            static constexpr bitfield_t<INT1SET_t, 12, 12, bool> GPIO44 = {};

            /// GPIO43 interrupt.
            static constexpr bitfield_t<INT1SET_t, 11, 11, bool> GPIO43 = {};

            /// GPIO42 interrupt.
            static constexpr bitfield_t<INT1SET_t, 10, 10, bool> GPIO42 = {};

            /// GPIO41 interrupt.
            static constexpr bitfield_t<INT1SET_t, 9, 9, bool> GPIO41 = {};

            /// GPIO40 interrupt.
            static constexpr bitfield_t<INT1SET_t, 8, 8, bool> GPIO40 = {};

            /// GPIO39 interrupt.
            static constexpr bitfield_t<INT1SET_t, 7, 7, bool> GPIO39 = {};

            /// GPIO38 interrupt.
            static constexpr bitfield_t<INT1SET_t, 6, 6, bool> GPIO38 = {};

            /// GPIO37 interrupt.
            static constexpr bitfield_t<INT1SET_t, 5, 5, bool> GPIO37 = {};

            /// GPIO36 interrupt.
            static constexpr bitfield_t<INT1SET_t, 4, 4, bool> GPIO36 = {};

            /// GPIO35 interrupt.
            static constexpr bitfield_t<INT1SET_t, 3, 3, bool> GPIO35 = {};

            /// GPIO34 interrupt.
            static constexpr bitfield_t<INT1SET_t, 2, 2, bool> GPIO34 = {};

            /// GPIO33 interrupt.
            static constexpr bitfield_t<INT1SET_t, 1, 1, bool> GPIO33 = {};

            /// GPIO32 interrupt.
            static constexpr bitfield_t<INT1SET_t, 0, 0, bool> GPIO32 = {};
        } INT1SET = {};
    };  // end of struct GPIO_t

} // namespace sfr