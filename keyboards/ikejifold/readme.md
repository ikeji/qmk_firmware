# ikejifold

![ikejifold](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Shun Ikejima](https://github.com/Shun Ikejima)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make ikejifold:default

Flashing example for this keyboard:

    make ikejifold:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available


## Matrix

      A0 A1 A2 A3 A4 A5 A6    A6 A5 A4 A3 A2 A1 A0
      0  1  2  3  4  5  6     10 9  8  7  6  5  4
B9(3)                   x  10 x
B8(2)                   x  9  x
B7(1)                      8
B6(0)                      7

