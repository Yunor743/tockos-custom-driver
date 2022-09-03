# Rust Tock 

## Getting Started

Make sure you have set up all the tools required to 
build [Tock](https://github.com/tock/tock) and [libtock-c applications](https://github.com/tock/libtock-c).

This template is a companian for the [Getting Started with Secure Embedded Systems](https://link.springer.com/book/10.1007/978-1-4842-7789-8#toc) book.

Both projects provide really good getting started tutorials ([Tock](https://github.com/tock/tock/blob/master/doc/Getting_Started.md), 
[libtock-c](https://github.com/tock/libtock-c/blob/master/README.md))

To set up the workspace, run:

```bash
git submodule update --init
```

To run Tock with renode use `renode stm32f4.resc`.

## Drivers

Write a driver that performs arithemtic and logic functions:
 - addition, substraction, multiplication, division and reminder
 - logic and, or

Each action has a seperate command number. Numbers are sent using
the command parameters.


## Applications

Write the user space library for the driver

