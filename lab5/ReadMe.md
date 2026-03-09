https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html
first run random creator
then run bubble sort (record time)
re_Run radndom now for a file size of 60000
re-run bubble sort (will still have the same time)
change variable(array_size in bubble sort)

then proceeed to each of the sortings in the task2 file.
https://www.youtube.com/watch?v=8mJ-OhcfpYg (insertion sort)

---

## TIME COMPLEXITY ANALYSIS

### 1. Bubble Sort
**Best Case: O(n)** | **Worst/Average Case: O(n²)**

Pseudocode:
```
Repeat n-1 times
    For i from 0 to n-2
        If numbers[i] and numbers[i+1] out of order
            Swap them
```
Comparisons: (n-1) + (n-2) + (n-3) + ... + 1 = n(n-1)/2 = O(n²)

---

### 2. Selection Sort
**Best/Worst/Average Case: O(n²)**

Pseudocode:
```
For i from 0 to n-1
    Find minimum element from i to n-1
    Swap minimum with position i
```
Comparisons: (n-1) + (n-2) + (n-3) + ... + 1 = n(n-1)/2 = (n² - n)/2 = O(n²)

---

### 3. Insertion Sort
**Best Case: O(n)** | **Worst/Average Case: O(n²)**

Pseudocode:
```
For i from 1 to n-1
    key = arr[i]
    j = i - 1
    While j >= 0 and arr[j] > key
        arr[j+1] = arr[j]
        j--
    arr[j+1] = key
```
Worst case: Inner loop runs up to i times for each i = n(n-1)/2 = O(n²)

---

### 4. Merge Sort
**Best/Worst/Average Case: O(n log n)**

Pseudocode:
```
If array length > 1
    Divide array in half
    Recursively sort left half
    Recursively sort right half
    Merge the two sorted halves
```
Recursion depth: log n | Each level merges: n comparisons = O(n log n)

---

### 5. Quick Sort
**Best/Average Case: O(n log n)** | **Worst Case: O(n²)**

Pseudocode:
```
If low < high
    pi = partition(arr, low, high)
    Recursively sort arr[low...pi-1]
    Recursively sort arr[pi+1...high]
    
partition:
    pivot = arr[high]
    For j from low to high-1
        If arr[j] < pivot
            Swap and move pointer
    Return partition position
```
Best case pivot divides evenly: O(n log n) | Worst case pivot is always smallest/largest: O(n²)

