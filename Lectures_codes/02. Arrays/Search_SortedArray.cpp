#include<iostream>
using namespace std;

// Binary Search deals with sorted array
int BinarySearch(int arr[], int low, int high, int key){

    if(high < low)
        return -1;
    int mid = (high + low) / 2;
    if(arr[mid] == key)
        return mid;
    if(arr[mid] < key)
        return BinarySearch(arr, mid + 1, high, key);
    else
        return BinarySearch(arr, low, mid - 1, key);
}
int main(){

    int arr[] = {5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 10;

    int index = BinarySearch(arr, 0, n-1, key);
    cout << "Index: " << index;
    return 0;
}

//end main()
/*
-----------Output-----------
Index: 5
*/
