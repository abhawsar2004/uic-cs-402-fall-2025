
#include "Amithi_Bhawsar_project1.h"
#include "testing.h"

#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */



/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Worked alone 



/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((!descending && list[j] > list[j+1]) ||
                (descending && list[j] < list[j+1])) {
                swap(list[j], list[j+1]);
            }
        }
    }
}














/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    int n = list.size();
for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
        if ((!descending && list[j] < list[minIndex]) ||
            (descending && list[j] > list[minIndex])) {
            minIndex = j;
        }
    }
    if (minIndex != i) {
        swap(list[i], list[minIndex]);
    }
}

}















/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    int n = list.size();
for (int i = 1; i < n; i++) {
    T key = list[i];
    int j = i - 1;

    // Ascending
    if (!descending) {
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
    }
    // Descending
    else {
        while (j >= 0 && list[j] < key) {
            list[j + 1] = list[j];
            j--;
        }
    }

    list[j + 1] = key;
}
}












/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */


template<typename T>
int partition(vector<T> &list, int low, int high, bool descending) {
    T pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((!descending && list[j] <= pivot) ||
            (descending && list[j] >= pivot)) {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[high]);
    return i + 1;
}







template<typename T>
void quicksort_helper(vector<T> &list, int low, int high, bool descending) {
    if (low < high) {
        int pi = partition(list, low, high, descending);
        quicksort_helper(list, low, pi - 1, descending);
        quicksort_helper(list, pi + 1, high, descending);
    }
}

template<typename T>
void quicksort(vector<T> &list, bool descending) {
    if (!list.empty()) {
        quicksort_helper(list, 0, list.size() - 1, descending);
    }
}



/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */






template<typename T>
void merge(vector<T> &list, int left, int mid, int right, bool descending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = list[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if ((!descending && L[i] <= R[j]) ||
            (descending && L[i] >= R[j])) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }
}





















/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort_helper(vector<T> &list, int left, int right, bool descending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_helper(list, left, mid, descending);
        merge_sort_helper(list, mid + 1, right, descending);
        merge(list, left, mid, right, descending);
    }
}

template<typename T>
void merge_sort(vector<T> &list, bool descending) {
    if (!list.empty()) {
        merge_sort_helper(list, 0, list.size() - 1, descending);
    }
}












/* Bucket Merge Sort
 *
 * 20 points
 * 
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending) {
    int n = list.size();
    if (n <= 1) return;

    // choose bucket size
    int bucketSize = 5;
    int numBuckets = (n + bucketSize - 1) / bucketSize;

    // split into buckets
    vector<vector<T>> buckets(numBuckets);
    for (int i = 0; i < n; i++) {
        int b = i / bucketSize;
        buckets[b].push_back(list[i]);
    }

    // sort each bucket with insertion_sort
    for (int i = 0; i < numBuckets; i++) {
        insertion_sort(buckets[i], descending);
    }

    // merge buckets back into the original list
    int idx = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (T val : buckets[i]) {
            list[idx++] = val;
        }
    }

    // final merge sort across buckets
    merge_sort(list, descending);
}




/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template<Integral T>
void binary_radix_sort(vector<T> &list, bool descending) {
    if (list.empty()) return;

    // find max to know how many bits to check
    T maxVal = *max_element(list.begin(), list.end());
    int bits = sizeof(T) * 8;

    for (int b = 0; b < bits; b++) {
        vector<T> zeroBucket, oneBucket;

        for (T val : list) {
            if ((val >> b) & 1)
                oneBucket.push_back(val);
            else
                zeroBucket.push_back(val);
        }

        // ascending: 0’s first, then 1’s
        // descending: reverse order
        if (!descending) {
            list.clear();
            list.insert(list.end(), zeroBucket.begin(), zeroBucket.end());
            list.insert(list.end(), oneBucket.begin(), oneBucket.end());
        } else {
            list.clear();
            list.insert(list.end(), oneBucket.begin(), oneBucket.end());
            list.insert(list.end(), zeroBucket.begin(), zeroBucket.end());
        }
    }
}








/* Your Hybrid Sort
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void hybrid_helper(vector<T> &list, int low, int high, bool descending) {
    const int THRESHOLD = 10;

    if (low < high) {
        // if subarray is small, use insertion sort
        if (high - low + 1 <= THRESHOLD) {
            vector<T> sub(list.begin() + low, list.begin() + high + 1);
            insertion_sort(sub, descending);
            for (int i = 0; i < sub.size(); i++) {
                list[low + i] = sub[i];
            }
        } else {
            int pi = partition(list, low, high, descending);
            hybrid_helper(list, low, pi - 1, descending);
            hybrid_helper(list, pi + 1, high, descending);
        }
    }
}

template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    if (!list.empty()) {
        hybrid_helper(list, 0, list.size() - 1, descending);
    }
}




/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
}






int main() {

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    vector<int> test_list {1, 2, 3, 4, 5};
    bubble_sort(test_list);
    selection_sort(test_list);
    insertion_sort(test_list);
    quicksort(test_list);
    merge_sort(test_list);
    bucket_merge_sort(test_list);
    binary_radix_sort(test_list);
    my_hybrid_sort(test_list);
    radix_sort(test_list);


    return 0;
}









