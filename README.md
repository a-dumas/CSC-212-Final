## CSC-212-Final

A [Knuth-Morris-Pratt](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) and [Boyer Moore] (https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm) implementation in C++

## Knuth-Morris-Pratt
  
## Boyer Moore

  This algorithm preforms it's matching backwards, from right to left, and proceeds by continuously matching and shifting the pattern. The shift amount is detemined by applying either:

  1. The bad character rule
  2. The good suffix rule
  
  An actual shifting offset is determined by the `max` function

  `badChar` will return a vector populated with the leftmost value for any character in the string or -1 if the character is not present
  
  `goodSuffix` will not return a table, but instead it will speficy how far the current string position should shift to the right when the pattern [j - 1] does not match but the suffic at [j....pattern_length - 1] does match.
  
  `BM` will complete the actual search using the above two functions

  
## Usage

  This program has been tested in both Visual Studio 2019 and the CS50 ide. No additional dependancies or packages are neded.

  To compile and execute all of the tests

    $g++ -std=c++11 -Wall main.cpp KMP.cpp Bmoore.cpp BruteForce.cpp -o main
    $./main
    
  Follow the prompts in the command line to select what input type and which algorithm to use. The easy to read output file will bold every instance of the searched word, where the command line will output the index at which every match occurs.

(put in image)
 
