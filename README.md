# JPEG File Recovery Tool
## By James Hill
## Purpose:
## This program recovers JPEG files from a memory card image. It reads a forensic image of a memory card (in raw format) and searches for JPEG images within it. It then extracts these images and saves them as separate files.

## Usage
### 1. Compile the program using a C compiler such as `gcc`.
### 2. The program will search for JPEG files within the memory card image and save them as separate files with filenames in the format ###.jpg, where ### is a three-digit number starting from 000.

## Requirements
### C compiler (e.g., gcc)

## Functionality
### Reads a memory card image file.
### Searches for JPEG file signatures within the image.
### Extracts and saves JPEG files found in the image.
### Saves JPEG files with filenames in the format ###.jpg.

## File Structure
### recover.c: Contains the main program logic.
### README.md: Instructions and information about the program.