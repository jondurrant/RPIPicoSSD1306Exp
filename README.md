# RPIPicoSSD1306Exp
Demonstrate OLED SSD1306  Display using Raspberry PI Pico. This code supports a Tutorial on my [YouTube Channel](https://youtube.com/@drjonea).

Two examples using the [Pico-SSD1306 library]( https://github.com/daschr/pico-ssd1306).

I use submodules for libraries so clone with the command:
```
git clone --recurse-submodules https://github.com/jondurrant/RPIPicoSSD1306Exp
```

## OLED Connection
Examples use a I2C OLED Module using the SSD1306 driver. The Module is connected to 3.3V, Gnd and I2C0 channel on the Pico via GPIO12 and GPIO13.

## Oled128x64
A simple example that flashes an LED on GPIO 2 and displays the word blink in parallel on the OLED display.

## Animation128x64
This displays the animation of a little 64x64 bitmap which is moved across the display.


## Build
To build the examples end the top level folder, either Animation128x64 or Oled128x64:
```
mkdir build
cd build
cmake ..
make
```
The binary is called build/src/Oled.elf or build/src/Oled.uf2 depending on if you will flash via SWD or Bootsel.

