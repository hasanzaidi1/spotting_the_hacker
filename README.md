# Spotting The Hacker

Spotting The Hacker is a program designed to detect errors in transmissions between the White House and the United Nations. This project implements three different error detection algorithms, providing a comparative study for choosing the most effective approach.

## Table of Contents

- [**Overview**](#overview)
- [**Error Detection Algorithms**](#error-detection-algorithms)
- [**Usage**](#usage)
- [**File Structure**](#file-structure)
- [**Contributing**](#contributing)
- [**License**](#license)

## Overview

The White House is exploring various error detection algorithms to ensure the accuracy of their transmission data stream. This program offers three error detection algorithms:

1. **Checksum**: Calculates the checksum for the data stream and verifies its integrity.

2. **Vertical Parity**: Applies vertical parity checking to detect errors in the data stream.

3. **2D Parity**: Utilizes 2D parity checking for error detection.

## Error Detection Algorithms

### Checksum Algorithm

The checksum algorithm calculates the checksum for the given data stream and validates its integrity. It prints the binary representation of the checksum and verifies the data using this checksum.

### Vertical Parity Algorithm

This algorithm applies vertical parity checking on the data stream and validates its correctness. It determines whether the number of ones in each byte is even or odd, providing error detection.

### 2D Parity Algorithm

The 2D parity algorithm applies parity checks both vertically and horizontally, allowing for enhanced error detection. It analyzes the given 2D data stream and reports any detected errors.

## Usage

1. Clone this repository to your local machine.

2. Compile the source code using your preferred C compiler:

   ```bash
   gcc -o error_detection error_detection.c

