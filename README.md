# STynth

![CI](https://github.com/XDeschuyteneer/STynth/workflows/CI/badge.svg)

## Intro

The goal is to play around with a ST32 nucleo board

## Setup

Install toolchain

```
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi openocd gcc-multilib
sudo apt install python3-pip
pip3 install pyserial
```

## Compile

```
make BOARD=nucleo-f767zi flash term
```