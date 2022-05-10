# Universal ARM-based Traffic Light Controller
A liquid-crystal display (LCD) is programmed (using 8-bit mode) to allow a user to select between four modes of traffic operation (urban, rural, and two crosswalk modes) using a four-position dual in-line package (DIP) switch.States of traffic lights are simulated using light-emitting diodes (LEDs), while a seven-segment display is used to simulate a crosswalk countdown. Various other shelf components are also used. Utilizing the STM32’s nested vector interrupt controller (NVIC), low-latency exception and (external) interrupt handling was shown to be a feasible and tractable solution to processing crosswalk requests. 

[Inputs & Outputs](https://github.com/nigelcaprotti/Universal-ARM-based-Traffic-Light-Controller#inputs-and-outputs)
Code developed and tested by Nigel Caprotti & Han Lin in Keil uVision v5.24.

## Inputs & Outputs 
One can refer to the associated block diagram in this repository for inputs to the MCU; outputs are the seven-segment display as well as the LEDs.

## Functionality
One can refer to the associated flow diagram concerning the functionality of the C language software (and associated interrupts).

## Improvements/Future Works
While dynamic control was achieved in the context of “mode switching”, further improvements to the posited design could be made in terms of mode switching as well as (SysTick) delays; future work includes using the internal SYSCFG peripheral to implement mode switching and delays as prioritized interrupts.


[1] Mazidi, Muhammad Ali, et al. ARM Assembly Language Programming & Architecture. Www.MicroDigitalEd.com, 2016.
