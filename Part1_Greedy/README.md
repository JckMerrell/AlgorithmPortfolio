# Part 1: Greedy Algorithms
## Jack Merrell
### 10/13/26

Language: C++

The program can be compiled by running g++ on main.cpp, fileinput.h, and algorithms.h. 
The test data files are lazily hardcoded into fileinput folder. All provided test data files must be local to the executable. 

File input format: 
ID STARTTIME ENDTIME

For custom tests, modify the test7_custom.txt file

The driver, including the menu selector, is located in the main. 
Logic for reading from the files, file locations, and sorting algorithms are located in fileinput.h.
Algorithm implementations are in algorithms.h.

Responses:

Task A
1. The greedy choice made by this algorithm is to select the compatible delivery with the earliest finish time first.
2. This is optimal because it guarantees that the driver is available for another delivery as soon as possible.
   When all jobs are equal, there is no reason not to pick the job that occupies a driver for the least time.
3. My algorithm runs on O(n log n) time, dominated by the sorting algorithm. Sorting by soonest end time takes O(n log n).
   The algorithm itself takes O(n) time, as it always runs through the array of deliveries exactly once and all other operations are O(1).

Task B
1. The priority queue stores the soonest end-time of jobs assigned to drivers. For the purposes of keeping track of output,
   my implementation also stores the Driver itself, but this does not affect the algorithm.
2. Deliveries are sorted in ascending order of start time. Deliveries are assigned, in order, by first checking the priority Queue.
   If the top of the priority queue (the end time of the driver who will be available the soonest) is less than or equal to the start time of the delivery
   (That is, if the delivery starts at or after the driver will be available) then that delivery is assigned to that driver, the old end time is removed from
   the queue, and the new end time is pushed into the queue. As it is a min-heap, the driver with the earliest end time will always be the top element. If
   the top element is greater than the start time of the delivery (that is, the soonest available driver will not be available for this delivery), a new
   driver is created, the delivery is assigned to them, and the new driver with their new end time is pushed onto the queue. 
3. The minimum number of drivers required for a set of orders is equal to the depth of that set, or the greatest number of orders which occupy the same interval.
   This algorithm follows that by creating new drivers only when all other drivers are currently occupied, i.e., when there is overlap.
4. This algorithm runs in O(n log n) time, dominated by the sorting. The sorting takes O(n log n) time.
   The algorithm itself takes O(n) time, as it is guaranteed to go through the array of deliveries exactly once, and the only comparison used is a single
   check on the top of the queue, which is O(1), and insertion to both the queue and the vectors are also O(1).

Task C
1. This problem is nearly identical in implementation to Task A, requiring us to find the greatest number of deliveries possible for one driver (exactly task A)
   and then determine how many deliveries remain and must be rejected.
2. If the maximum possible deliveries from a set of n deliveries is k, then the number of deliveries which must be rejected is n-k.
3. This algorithm runs in O(n log n) time, dominated by the sorting. The sorting takes O(n log n) time.
   The algorithm is identical to the one in Task A, and so runs in the same amount of time. The extra step to keep track of what deliveries are rejected
   is O(1), and so makes no difference. 
