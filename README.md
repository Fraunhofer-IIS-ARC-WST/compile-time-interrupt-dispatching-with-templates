# Compile time interrupt dispatching with templates

## Contents

- [What](#what)
- [Building](#building)
- [Get Involved](#getinvolved)

## What

Source code examples for the article published in the magazine iX about compile time interrupt dispatching with templates.

The "Variant 1" folder contains the examples where the main function and the handler for the __bad_interrupt are each implemented as a simple endless loop. Example *a* is the conventional implementation (for comparison), example *b* uses the presented InterruptHandler and example *c* additionally uses own startup files.

The folder "Variant 2" contains the examples where the interrupt of timer B0 is used to increment a counter every millisecond. Example *a* is the conventional implementation (again for comparison), example *b* uses the presented InterruptHandler and example *c* additionally uses own startup files.

## Building

The examples can easily be opened and compiled in Atmel Studio 7.

## Get Involved
+ Report bugs/issues by submitting a [GitHub issue](https://github.com/Fraunhofer-IIS-ARC-WST/compile-time-interrupt-dispatching-with-templates/issues).
+ Submit contributions using [pull requests](https://github.com/Fraunhofer-IIS-ARC-WST/compile-time-interrupt-dispatching-with-templates/pulls).