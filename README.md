# spotting_the_hacker

A program to detect errors in the transmissions from the White House to the United Nations.

Author: Hasan Zaidi

Overview
The White House is exploring various error detection algorithms to ensure the accuracy of their transmission data stream. This program implements three different error detection algorithms, allowing for a comparative study to choose the most effective approach.

Error Detection Algorithms
The program implements the following error detection algorithms:

Checksum

Calculates the checksum for the data stream and verifies its integrity.
Vertical Parity

Applies vertical parity checking to detect errors in the data stream.
2D Parity

Utilizes 2D parity checking for error detection.

Usage
To use the program, compile the source code and run the executable.
gcc -o error_detection error_detection.c
./error_detection

File Structure
error_detection.c: Contains the source code for the error detection algorithms.
White House Transmission Data - Parity.txt: Input file for the parity error detection.
White House Transmission Data - Checksum.txt: Input file for the checksum error detection.
White House Transmission Data - 2D Parity.txt: Input file for the 2D parity error detection.


