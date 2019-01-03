# Computational Complexity

When we talk about the complexity of an algorithm, we generally refer to the **worst-case scenario**.

* We refer to this as O.

We sometimes also care about the **best-case scenario** (also known as Ω).

A data set can vary in definition depending on context. If we're talking about files, a data set would be the KBs of that file. If we're talking arrays, a data set would be the amount of elements in that array.

We can measure an algorithm based on how it handles data set inputs. Measure: f(n) means for any n units of a data set it takes f resources (mbs of RAM, time etc).

We don't actually care about what f(n) is precisely. Rather we only care about its **tendency**, which is dictated by its highest order term. E.g. What is the worst case scenario for how many resources will be taken up by a given algorithm.

## Big O notation

Noted from generally fastest to slowest run-time.

| Notation | Description | Example
| ---| ---| --- |
| O(1) | constant time | An alorithim that always runs a set number of steps always. Always takes a single operation in the worst-case. |
| O(log n) | logarithmic time | Example: binary search - cutting the problem in half each time to find the value you are looking for. |
| O(n) | linear time | An algorithim that steps through all of its data set once. |
| O(n log n) | linearithmic time |
| O(n^2) | quadratic time | An algorithim that steps through all of n units of its data set n number of times. |
| O(n^c) | polynomial time | An algorithm that raises n units of a data set by a constant number. |
| O(c^n) | exponential time | An alogrithm that has a constant number raised by the n units of a data set. |
| O(n!) | factorial time | |
| O(∞) | infinite time | An algorithim that potential never resolves itself. For example, an array that gets shuffled ever iteration with a check to see if it is sorted after the shuffle. |

### O(1)

Constant number of steps.

Code example:

```c
int four_for_you(int array[100])
{
    return 4;
}
int add_two_nums(int a, int b)
{
    return a + b;
}
```

### O(n)

Always takes n operations in worst case.

Code example:

```c
char array[3] = {'1', '2', '3'};
char match[1] = '3';

for( int x = 0; x < strlen(array); x++);
{
    if (array[x] == match)
    {
        printf("Match found!\n");
        return;
    }
}
```

### O(n^2)

Code example:

```c

for (int j = 0; j < p; j++)
{
    for (int k =0; k < p; k++)
    {
        // loop that runs in O(1)
    }
}

```

# Sorting algorithms

## Selection Sort

In selection sort, the idea of the algorithm is to find the smallest unsorted element and add it to the end of the sorted list.

### In pseudocode:

Repeat until no unsorted elements remain:

* Search the unsorted part of the data to find the smallest value.
* Swap the smallest found value with the first element of the unsorted part.

**Worst-case scenario**: We have to iterate over each of the n elements of the array(to find the smallest unsorted element) and we must repeat the process n times, since only the one element gets sorted on each pass. Notation: O(n^2).

**Best-case scenario**: Exactly the same! There's no way to guarantee the array is sorted until we go through this process for all the elements. Notation: Ω(n^2).

## Bubble Sort

In bubble sort, the idea of the algorithm is to move higher valued elements generally towards the right and lower value elements towards the left.

### In pseudocode:

Set swap counter to a non-zero value. Repeat until the swap counter is 0:

* Reset swap counter to 0
* Look at each adjacent pair
* If two adjacent elements are not in order, swap them and add 1 to the swap counter.

**Worst-case scenario**: The array is in reverse order; we have to "bubble" each of the n elements all the way across the array and since we can only bubble one element into position per pass, we must do this n times. Notation: O(n^2).

**Best-case scenario**: The array is already perfectly sorted, and we make no swaps on the first pass. Notation: Ω(n).

## Insertion Sort

In insertion sort, the idea of the algorithm is to build your sorted array in place, shifting elements out of the way if necessary to make room as you go.

### In pseudocode:

Call the first element of the array "sorted". Repeat until all elements are sorted:

* Look at the next unsorted element. Insert into the "sorted" portion by shifting the requisite number of elements.

**Worst-case scenario**: The array is in reverse order; we have to shift each of the n elements n positions each time we make an insertion. Notation: O(n^2).

**Best-case scenario**: The array is already perfectly sorted, and we simply keep moving the line between "unsorted" and "sorted" as we examine each element. Notation: Ω(n).

# Search algorithms

## Linear Search

In linear search, the idea of the algorithm is to iterate across the array from left to right, searching for a specified element.

### In pseudocode:

Repeat, starting at the first element:

* If the first element is what you're looking for (the target), stop. Otherwise, move to the next element.

**Worst-case scenario**: We have to look through the entire array of n elements, either because the target element is the last element of the array or doesn't exist in the array at all. Notation: O(n).

**Best-case scenario**: The target element is the first element of the array, an d so we can stop looking immediately after we start. Notation: Ω(1).

## Binary Search

In binary search, the idea of the algorithm is to divide and conquer, reducing the search area by half each time, trying to find a target number.

* In order to leverage this power however, our array must first be sorted, else we cannot make assumptions about the array's contents.

### In pseudocode:

Repeat until the (sub)array is of size 0:

*  Calculate the middle point of the current (sub)array.
*  If the target is at the middle, stop.
*  Otherwise if the target is less than what's at the middle, repeat, changing the end point to be just left of the middle.
*  Otherwise if the target is greater than what's at the middle, repeat, changing the start point to be just right of the middle.

**Worst-case scenario**: We have to divide a list of n elements in half repeatedly to find the target element, either because the target element will be found at the end of the last division or doesn't exist in the array at all. Notation: O(log n).

**Best-case scenario**: The target element is at the midpoint of the full array, and so we can stop looking immediately after we start. Notation: Ω(1).

