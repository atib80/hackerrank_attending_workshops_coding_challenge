# hackerrank_attending_workshops_coding_challenge

Hackerrank -> C++ Other Concepts -> Attending Workshops

One possible solution to Hackerrank's Attending Workshops (C++ Other Concepts -> Attending Workshops) coding challenge 
developed using C++ and a couple of STL containers and algorithms.

A student signed up for workshops and wants to attend the maximum number of workshops where no two workshops overlap. You must do the following:

Implement 2 structures:

    struct Workshop having the following members:
        
        The workshop's start time: start_time (int)
        The workshop's duration: duration (int)
        The workshop's end time: end_time (int)

    struct Available_Workshops having the following members:
    
        The number of workshops the student signed up for : n (int)
        An array of type Workshop array having size n : Workshop workshops[n]

Implement the following 2 functions as well:

    Available_Workshops* initialize (const int *start_time, const int *duration, int n)
    Creates an Available_Workshops object and initializes its elements using the values stored in the start_time 
    and duration int arrays (both are of size n). Here, start_time[i] and duration[i] are the respective start_time and duration 
    for the workshop. This function must return a pointer to an Available_Workshops object.

    int CalculateMaxWorkshops(Available_Workshops* ptr)
    Returns the maximum number of workshops a student can attend whose time durations do not overlap. 
    The next workshop cannot be attended until the previous workshop ends.

Note: A dynamically allocated array of type DataType* with size (n) should be declared as follows:

DataType* arrayName = new DataType[n];

Input format:
Input from stdin is handled by the locked code in the editor; you simply need to write your functions to meet the specifications of the problem statement above.

Constraints:

1 <= N <= 10E+5
0 <= start_time <= 10E+5
0 <= duration <= 10E+5

Output format:
Output to stdout is handled for you.

Your initialize function must return a pointer to an Available_Workshops object.
Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops the student can attend.

Sample input:

6

1 3 0 5 5 8

1 1 6 2 4 1

Sample output

CalculateMaxWorkshops should return 4.

Explanation:

The first line denotes n, the number of workshops.
The next line contains n space-separated integers where the integer with index i is the workshop's start time.
The next line contains n space-separated integers where the integer with index i is the workshop's duration.

A student can attend the following workshops: 0, 1, 3 and 5 without overlap, so CalculateMaxWorkshops returns 4 to main 
(which is then printed to stdout).
