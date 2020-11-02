# sx126x_driver
Portable driver for Semtech SX126x series

Supported chips: `SX1261`, `SX1262`, `SX1268`.

## Requirements
- C++14

## Features
- Easy to use
- Should work on nearly all platforms
- Multiple instances
- No macros, no global scope shit, and thus no collisions with other libs

## Usage

Write your own hardware abstraction layer (HAL) class and implement the `Hal*` functions below:

- `HalGpioRead`
- `HalGpioWrite`
- `HalSpiTransfer` - This should take care of chip select signal

**It's very simple. Right?**

And these if you have RF switches / external RF PA (optional): 

- `HalPreTx` - Called before a TX operation
- `HalPreRx` - Called before a RX operation
- `HalPostTx` - Called when (1) `TX_DONE` (2) `TX_TIMEOUT` (3) before a RX operation
- `HalPostRx` - Called when (1) `RX_TIMEOUT` (2) before a TX operation


**Enable DIOs & process GPIO interrupts by yourself.** When DIO fires, simply call `SX126x::ProcessIrqs()`. Everything is thread-safe.
 
That's all. The code is well documented. Most usages are exactly same as the SX1280 mbed driver.

## License
LGPLv3

## Acknowledgements
This library is based on the SX126x mbed driver by Semtech S.A. See `LICENSE-SEMTECH.txt` for details.