# LAB 03: Benjamin Nimmerrichter

1. Calculate the overflow times for three Timer/Counter modules that contain ATmega328P if CPU clock frequency is 16&nbsp;MHz. Complete the following table for given prescaler values. Note that, Timer/Counter2 is able to set 7 prescaler values, including 32 and 128 and other timers have only 5 prescaler values.

   | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16u | 128u | -- | 1 024u | -- | 4 094u | 16 384u |
   | Timer/Counter1 | 16 | 4 096u | 32 768u | -- | 262 144u | -- | 1 044,5m | 4 194,3m |
   | Timer/Counter2 | 8  | 16u | 128u | 512u | 1 024u |2 048 | 4 094u | 16 384u |