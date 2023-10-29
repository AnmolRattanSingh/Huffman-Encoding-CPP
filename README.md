# Huffman-Encoding-CPP

Huffman Encoding implementation in CPP

## Overview

We aim to implement the Huffman coding algorithm in C++ to compress and decompress data efficiently. Huffman coding is a widely used technique in data compression, and this project aims to demonstrate a solid understanding of the algorithm's principles and its practical application.

## File Structure

- `src` folder contains the source code for the project.
  - `huffman.cpp`: contains the main function.
  - `min_heap.cpp`: implementation of the min heap data structure. Includes functions to manipulate and print the heap.
  - `min_heap.hpp`: header file for the min heap data structure.
  - `huffman_helper.cpp`: implementation of the helper functions for the Huffman coding algorithm. Includes functions to build the Huffman tree, create the frequency table, and print the Huffman codes.
  - `huffman_helper.hpp`: header file for the helper functions for the Huffman coding algorithm.
  - `timing_charts.cpp`: implementation of the functions to find worst case time complexity of the Huffman coding algorithm. Runs multiple iterations of the algorithm for different sized inputs and finds the average time taken.
  - `timing_charts.hpp`: header file for the timing functions.
- `plot_timing.py`: Python script to plot the output of the `huffman` executable. Can be customized based on the output of `huffman` to stdout.

## Usage

- To compile the program, create a `build` folder in the root directory using the following command:

   ```bash
   mkdir build
   ```

- Navigate to the `build` folder and run the following command to compile the program:

   ```bash
   cmake ..
   ```

- Run the following command in the `build` folder to finish compiling the program:

   ```bash
   make
   ```

- To create the compression ratio plot, run the following command from the root directory:

   ```bash
   python3 plot_timing.py
   ```

## References
Huffman coding. Programiz. From [https://www.programiz.com/dsa/huffman-coding](https://www.programiz.com/dsa/huffman-coding)

3.4 Huffman Coding - Greedy Method. Abdul Bari. From [https://www.youtube.com/watch?v=co4_ahEDCho](https://www.youtube.com/watch?v=co4_ahEDCho)
