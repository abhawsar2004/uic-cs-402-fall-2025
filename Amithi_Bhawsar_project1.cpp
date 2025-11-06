
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


//BUBBLE SORT-  it looks at two neighbors at a time and if they are in the wrong order it switches them
//keeps doing this again and again till list is sorted  
template<typename T>  //template is to make sure that bubble sort works on any data type
void bubble_sort(vector<T> &list, bool descending) {
    int n = list.size(); //this tells us how many things are in the list 

    //will go through the list many times 
    for (int i = 0; i < n - 1; i++) {
        //compare the neighbors one by one 
        for (int j = 0; j < n - i - 1; j++) {

        //if we are sorting small-big we check is the left number > right number or big-small we check is left < right number 
            if ((!descending && list[j] > list[j+1]) ||
                (descending && list[j] < list[j+1])) {

                //if they are in the wrong order swap them 
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

//SELECTION SORT- goes though the list one spot at a time
//for each spot it finds the smallest or biggest thing is the rest of the list
//it than swaps it to the front till the whole list is sorted 
template<typename T>  // can work on numbers, letters, etc. 
void selection_sort(vector<T> &list, bool descending) {
    int n = list.size(); //how many things are in the list

for (int i = 0; i < n - 1; i++) {    //go throught the list one at a time    
    int minIndex = i;  // pretend if the first one is the smallet or the biggest
    for (int j = i + 1; j < n; j++) {  // look at all the other items after it 

        //if sorting small-big, find smalller one 
        //if sorting big-small, find bigger one 
        if ((!descending && list[j] < list[minIndex]) ||
            (descending && list[j] > list[minIndex])) {
            minIndex = j;  // found a better one, remember where it is 
        }
    }
    if (minIndex != i) {
        swap(list[i], list[minIndex]); // if we found a better one we swap it 
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

//INSERTION SORT- takes one item at a time and puts it where it belongs 
//starts with second item - compares it to things before, and shifts them over if needed
//keeps going till list is sorted 
template<typename T> //works on numbers, letters, etc. 
void insertion_sort(vector<T> &list, bool descending) {
    int n = list.size(); //counts how many items are in the list 
    
for (int i = 1; i < n; i++) {  //starts at the 2nd item(index1), go through the list 
    T key = list[i]; //remeber the currect item 
    int j = i - 1; //look at item before

    // Ascending - sorting small-big
    if (!descending) {
        //moving bigger numbers one step to the right 
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
    }
    // Descending sorting big-small
    else {
        //keep moving smaller numbers one step to the right 
        while (j >= 0 && list[j] < key) { 
            list[j + 1] = list[j];
            j--;
        }
    }

    list[j + 1] = key; // put current item is right place 
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

/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */

//Partition helps quicksort do its job 
// it picks a pivot and puts smaller stuff on one side and bigger on the other 
template<typename T>
int partition(vector<T> &list, int low, int high, bool descending) {
    T pivot = list[high]; // choose the last item as "pivot" 
    int i = low - 1; // place for where the small-big item go 

    for (int j = low; j < high; j++) { //look at each item between low and high 
        if ((!descending && list[j] <= pivot) || //if sorting small-big put smaller items before pivot
            (descending && list[j] >= pivot)) { //if sorting big-small put bigger items before pivot 
            i++;     //move divider forward
            swap(list[i], list[j]); //swap currect item into left side 
        }
    }
    swap(list[i + 1], list[high]); //put pivot in middle(its current spot)
    return i + 1; //return the pivots new position 
}


//QUICKSORT- picks a pivot toy and puts that in the right spot 
//toys to the left are smaller and toys to right are bigger 
//repeats this on the left pile and the right pile until everything is sorted 




template<typename T>
void quicksort_helper(vector<T> &list, int low, int high, bool descending) {
    if (low < high) { //if their is more than 1 item in this part of the list
        int pi = partition(list, low, high, descending); //put one number(pivot) in the right spot 
        //everything smaller (or bigger if descending)on the left 
        //eveyything bigger (or smaller if descending)on the right 
        quicksort_helper(list, low, pi - 1, descending); //sort thr left half(stuff smaller than pivot)
        quicksort_helper(list, pi + 1, high, descending);//sort right half(stuff bigger than pivot)
    }
}

template<typename T>
void quicksort(vector<T> &list, bool descending) {
    if (!list.empty()) { //only sort if the list has something in it 
        quicksort_helper(list, 0, list.size() - 1, descending); //start by sorting the whole list
    }
}







//this function takes two halves of a list and merges them into one sorted list 

template<typename T>
void merge(vector<T> &list, int left, int mid, int right, bool descending) {
    //figure out how many items are in the left hald and right half 
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2); //make two small lists to hold the left and right halves 

    for (int i = 0; i < n1; i++) //copy the left half of the list into L
        L[i] = list[left + i];
    for (int j = 0; j < n2; j++) //copy the right half of the list into R
        R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = left; //i=index for left list, j=index for right list, k=index for where we are in the big list 

    //compare items from L and R and put smaller/bigger on into list 

    while (i < n1 && j < n2) {
        if ((!descending && L[i] <= R[j]) ||  //if sorting small-big
            (descending && L[i] >= R[j])) {   //if sorting big-small
            list[k] = L[i];  //take from left side 
            i++;
        } else {
            list[k] = R[j]; //take from right side 
            j++;
        }
        k++;
    }
    //if there are leftovers in the left list than copy them back 
    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }
   //if there are leftovers in the right list than copy them back 
    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }
}
//it splits into two (left/right)
//picks smaller each time and puts it back in the main box 
//keeps doing that until its sorted 








/* Merge Sort  -  Break the list into smaller pieces, sort each piece, then glue them back together.
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
    //only keep going if list has more than 1 item 
    if (left < right) {
        //find the middle point of list
        int mid = left + (right - left) / 2;

        //sort the left half 
        merge_sort_helper(list, left, mid, descending);

        //sort the right half 
        merge_sort_helper(list, mid + 1, right, descending);

        //merge the two sorted halves back together 
        merge(list, left, mid, right, descending);
    }
}

template<typename T>
void merge_sort(vector<T> &list, bool descending) {

    //only work if the list is not empty 
    if (!list.empty()) {
        //sort the whole list from  first item to last 
        merge_sort_helper(list, 0, list.size() - 1, descending);
    }
}












/* Bucket Merge Sort - break the list into small 'buckets'
//sort each bucket than glue them back all together 
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
    if (n <= 1) return; //if list is empty or has 1 thing, do not do anything 

    // choose bucket size (5 items each)
    int bucketSize = 5;

    //figure out how many buckets we need 
    int numBuckets = (n + bucketSize - 1) / bucketSize;

    // make the buckets 
    vector<vector<T>> buckets(numBuckets);

    //put each item ftom the list into the bucket 
    for (int i = 0; i < n; i++) {
        int b = i / bucketSize; //figure out which bucket it goes in 
        buckets[b].push_back(list[i]);
    }

    // sort each bucket with insertion_sort
    for (int i = 0; i < numBuckets; i++) {
        insertion_sort(buckets[i], descending);
    }

    // glue back all buckets together 
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
// BINARY RADIX SORT - looks at numbers as 0s and 1s (like switches)
// Sorts numbers by checking each "bit" (binary digit) from smallest to biggest.
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
    if (list.empty()) return; //nothing to sort if list is empty 

    // find max to know how many bits to check
    T maxVal = *max_element(list.begin(), list.end());
    int bits = sizeof(T) * 8; //how many switches a number has 


    //look at each switch one at a time 
    for (int b = 0; b < bits; b++) {
        vector<T> zeroBucket, oneBucket; //two groups: one for 0, one for 1 


        //check the b-th switch of every number 
        for (T val : list) { 
            if ((val >> b) & 1)  //if switch is ON (1)
                oneBucket.push_back(val); //put in 1 bucket
            else                        //if switch is OFF (0)
                zeroBucket.push_back(val); //put in 0 bucket
        }


        //put buckets back into the list 
        if (!descending) {

            //small to big - 0 bucket first, then 1 bucket 
            list.clear();
            list.insert(list.end(), zeroBucket.begin(), zeroBucket.end());
            list.insert(list.end(), oneBucket.begin(), oneBucket.end());
        } else {
            //big to small - 1 bucket first, than 0 bucket 
            list.clear();
            list.insert(list.end(), oneBucket.begin(), oneBucket.end());
            list.insert(list.end(), zeroBucket.begin(), zeroBucket.end());
        }
    }
}








/* Your Hybrid Sort - mix of two sorting methods to be faster 
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
    const int THRESHOLD = 10; //if a group is too small we use insertion sort 

    if (low < high) {
        if (high - low + 1 <= THRESHOLD) {
            vector<T> sub(list.begin() + low, list.begin() + high + 1);
            insertion_sort(sub, descending); //sort the small piece 
            for (int i = 0; i < sub.size(); i++) {
                list[low + i] = sub[i]; //copy it back to the list 
            }
            //if the piece is bigger we use quicksort
        } else {
            int pi = partition(list, low, high, descending); //put pivot in right spot 
            hybrid_helper(list, low, pi - 1, descending); //sort left side 
            hybrid_helper(list, pi + 1, high, descending); //sort right side 
        }
    }
}

template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    if (!list.empty()) { //only sort if list has stuff 
        hybrid_helper(list, 0, list.size() - 1, descending); //start a whole list 
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









