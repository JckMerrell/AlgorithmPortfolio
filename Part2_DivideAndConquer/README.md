# Part 1: Greedy Algorithms
## Jack Merrell
### 10/28/26

Language: C++

All dependencies are included in the header files or are testcase files. Ensure that the TestCases folder is local to the executable. 

All that is needed to run the program is to compile and run the main. A compiled executable, Part2, is included in the repo. 

## Input formats
All inputs are from text files, and should be placed in the TestCases folder. Input file names are hardcoded into fileInput2.h. 
Adding or removing test cases requires modifying the corresponding string vector in fileInput2. 
All test cases can be freely customized, following the format. 

Part A:
One location per line, in the form
DELIVERYID XPOS YPOS
Any number of locations per file.

Part B:
Planned array on the first line, actual array on the second. 
ID1 ID2 ID3 IDE4
ID4 ID3 ID2 ID1 

Part C:
Space-separated list of times on first line. No other lines. 
TIME1 TIME2 TIME3 ...

Special note for part C: Target position is also hardcoded into fileInput2. Those must be modified there. 
