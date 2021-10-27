# 42Cursus project Level2 "fractol"

## Description

This project is a program to draw a fractal.

A fractal is a figure with a geometric structure that has a special property called "self-similarity". In this program, you can experience "self-similarity" by drawing fractals using the C language, and expanding and contracting them.

There are three fractals that can be drawn: Mandelbrot set, Julia set, and Burningship.

## Runnable Environment

- Linux
- MacOS

## Available Functions

- open, close, read, write, printf, malloc, free, perror, strerror, exit
- All functions of the math library (-lm man 3 math)
- All functions of the MinilibX

## Usage

```bash
make
```
```bash
./fractol <name>
```
The following three fractals can be entered in \<name\>.
- mandelbrot
- julia
- burningship

### Example

```bash
./fractol julia
```
## Images
### Mandelbrot
<img src=images/mand.png>

### Julia
<img src=images/julia.png>

### Burningship
<img src=images/burn.png>
