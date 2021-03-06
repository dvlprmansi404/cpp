//Longest Consecutive Sequence 

Naive Approach: The idea is to first sort the array and find the longest subarray with 
consecutive elements.
After sorting the array run a loop and keep a count and max (both initially zero). 
Run a loop from start to end and if the current element is not equal to the previous (element+1) 
then set the count to 1 else increase the count. Update max with a maximum of count and max.

// Returns length of the longest 
// contiguous subsequence 
int findLongestConseqSubseq(int arr[], int n) 
{ 
    int ans = 0, count = 0; 
  
    // sort the array 
    sort(arr, arr + n); 
  
    // find the maximum length 
    // by traversing the array 
    for (int i = 0; i < n; i++) { 
        // if the current element is equal 
        // to previous element +1 
        if (i > 0 && arr[i] == arr[i - 1] + 1) 
            count++; 
        // reset the count 
        else
            count = 1; 
  
        // update the maximum 
        ans = max(ans, count); 
    } 
    return ans; 
} 


Efficient solution:
This problem can be solved in O(n) time using an Efficient Solution. 
The idea is to use Hashing. We first insert all elements in a Set. Then check 
all the possible starts of consecutive subsequences.

Algorithm:

    Create an empty hash.
    Insert all array elements to hash.
    Do following for every element arr[i]
    Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element a subsequence.
    If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
    If the count is more than the previous longest subsequence found, then update this.


// Returns length of the longest 
// contiguous subsequence 
int findLongestConseqSubseq(int arr[], int n) 
{ 
    unordered_set<int> S; 
    int ans = 0; 
  
    // Hash all the array elements 
    for (int i = 0; i < n; i++) 
        S.insert(arr[i]); 
  
    // check each possible sequence from 
    // the start then update optimal length 
    for (int i = 0; i < n; i++) { 
        // if current element is the starting 
        // element of a sequence 
        if (S.find(arr[i] - 1) == S.end()) { 
            // Then check for next elements 
            // in the sequence 
            int j = arr[i]; 
            while (S.find(j) != S.end()) 
                j++; 
  
            // update  optimal length if 
            // this length is more 
            ans = max(ans, j - arr[i]); 
        } 
    } 
    return ans; 
} 