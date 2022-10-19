# Lab 4: Benjamin Nimmerrichter


## Pre-Lab preparation

1. Use schematic of the [LCD keypad shield](https://oshwlab.com/tomas.fryza/arduino-shields) and find out the connection of LCD display. What data and control signals are used? What is the meaning of these signals?

   | **LCD signal(s)** | **AVR pin(s)** | **Description** |
   | :-: | :-: | :-- |
   | RS | PB0 | Register selection signal. Selection between Instruction register (RS=0) and Data register (RS=1) |
   | R/W | GND |read/write, controls if we read (R/W = 1) or write values (R/W = 0)|
   | E | PB1 | enable signal, triggers on falling edge |
   | D[3:0] | unused | data input 4 bits second symbol |
   | D[7:4] | PB[7:4] | data input 4 bits first symbol |
   | K | PB2 | backlight cathode |

2. What is the ASCII table? What are the codes/values for uppercase letters `A` to `Z`, lowercase letters `a` to `z`, and numbers `0` to `9` in this table?

   | **Char** | **Decimal** | **Hexadecimal** |
   | :-: | :-: | :-: |
   | `A` | 65 | 0x41 |
   | `B` | 66 | 0x42 |
   | `C` | 67 | 0x43 |
   | `D` | 68 | 0x44 |
   | `E` | 69 | 0x45 |
   | `F` | 70 | 0x46 |
   | `G` | 71 | 0x47 |
   | `H` | 72 | 0x48 |
   | `I` | 73 | 0x49 |
   | `J` | 74 | 0x4A |
   | `K` | 75 | 0x4B |
   | `L` | 76 | 0x4C |
   | `M` | 77 | 0x4D |
   | `N` | 78 | 0x4E |
   | `O` | 79 | 0x4F |
   | `P` | 80 | 0x50 |
   | `Q` | 81 | 0x51 |
   | `R` | 82 | 0x52 |
   | `S` | 83 | 0x53 |
   | `T` | 84 | 0x54 |
   | `U` | 85 | 0x55 |
   | `V` | 86 | 0x56 |
   | `W` | 87 | 0x57 |
   | `X` | 88 | 0x58 |
   | `Y` | 89 | 0x59 |
   | `Z` | 90 | 0x5A |
   | ... |  |  |
   | `a` | 97 | 0x61 |
   | `b` | 98 | 0x62 |
   | `c` | 99 | 0x63 |
   | `d` | 100 | 0x64 |
   | `e` | 101 | 0x65 |
   | `f` | 102 | 0x66 |
   | `g` | 103 | 0x67 |
   | `h` | 104 | 0x68 |
   | `i` | 105 | 0x69 |
   | `j` | 106 | 0x6A |
   | `k` | 107 | 0x6B |
   | `l` | 108 | 0x6C |
   | `m` | 109 | 0x6D |
   | `n` | 110 | 0x6E |
   | `o` | 111 | 0x6F |
   | `9` | 112 | 0x70 |
   | `q` | 113 | 0x71 |
   | `r` | 114 | 0x72 |
   | `s` | 115 | 0x73 |
   | `t` | 116 | 0x74 |
   | `u` | 117 | 0x75 |
   | `v` | 118 | 0x76 |
   | `w` | 119 | 0x77 |
   | `x` | 120 | 0x78 |
   | `y` | 121 | 0x79 |
   | `z` | 122 | 0x7A |
   | ... |  |  |
   | `0` | 48 | 0x30 |
   | `1` | 49 | 0x31 |
   | `2` | 50 | 0x32 |
   | `3` | 51 | 0x33 |
   | `4` | 52 | 0x34 |
   | `5` | 53 | 0x35 |
   | `6` | 54 | 0x36 |
   | `7` | 55 | 0x37 |
   | `8` | 56 | 0x38 |
   | `9` | 57 | 0x39 |
   | ... |  |  |



### Stopwatch

1. Draw a flowchart for `TIMER2_OVF_vect` interrupt service routine which overflows every 16&nbsp;ms but it updates the stopwatch LCD screen approximately every 100&nbsp;ms (6 x 16&nbsp;ms = 100&nbsp;ms). Display tenths of a second, seconds, and minutes and let the stopwatch counts from `00:00.0` to `59:59.9` and then starts again. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()

### Kitchen alarm

2. Draw a schema of the kitchen alarm application that counts down the time with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure]()
