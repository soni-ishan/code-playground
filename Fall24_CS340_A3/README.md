Name: Ishan Nimeshkumar Soni
Username: isx183
Student ID: 200485414
Course: CS 340
Instructor: Dr. Malek Mouhoub
Assignment #: 3

----------------------------------------------------------------------

1 - List of submitted files:
* README.txt 
* assign3isx183.cpp
* Header Files (.h):   <Include all relevant header files used in your program>
    None
* Implementation Files (.cpp): <Include all implementation files with a brief description of each>
    None - the main cpp file assign3isx183.cpp has all the code
* Makefile
* A screenshot showing your command line for execution and the execution results for 5 different
examples.
......................................................................

2- List used libraries:
* C++ standard library (<iostream>, <array>, <stack>, ...)
    <iostream>
    <vector>
    <random>
    <chrono>
    <iomanip>
    <unordered_set>
* C++ external libraries

......................................................................

3- List your execution commands:
 -Ensure the generated executable is named assign1username (replace username with your actual username).
 -The marker will run make to compile your program and assign1username to execute it.
- Make sure your Makefile and executable both run properly on Titan
g++ -Wall -std=c++11 assign3isx183.cpp -o assign3isx183.exe

.......................................................................

4- Input requirements - format of the input string:
 To assist your TA in running your code, specify the accepted format(s) of input strings your code will process.
 The program will first ask you to enter the value of N (number of random naturals).
 After that, you will be prompted to enter the value of K for quick-insertion sort.

......................................................................

5- Program Description
 * Briefly explain the goal and functionality of  your program.
 The goal here is a comparative experimental study, in terms of running time, of the following 4 sorting algorithms:
    - Insertion sort
    - Mergesort
    - Quicksort
    - Quick-insertion sort

.....................................................................

6- Bonus (additional features improving functionality and/or presentation):
    - Error handling for invalid inputs for N and K
    - Neat presentation of output sorted arrays and the runtimes
    - random generation of naturals while preventing duplicates

.....................................................................

7- Find the pair of values (N, K) in each of the following scenarios, and record it in the README file.
(a) Quick-insertion outperforms all the other algorithms. (10000, 11)
(b) Insertion Sort outperforms all the other algorithms. (11, 5)
(c) Quicksort outperforms all the other algorithms. (200, 1)

--------------------- END --------------