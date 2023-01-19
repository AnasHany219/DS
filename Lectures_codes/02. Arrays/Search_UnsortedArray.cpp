#include <iostream>
using namespace std;
int findElement(int arr[], int n, int key){
    int i;
    for(int i = 0; i < n; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

int main(){
    int arr[] = {12, 34, 10, 6, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Using a last element as search element
    int key = 40;
    int index = findElement(arr, n, key);
    if(index == -1)
        cout << "Element not found";
    else
        cout << "Element Found at index: " << index;
    return 0;
}
//end main()

/*
---------Output----------
Element Found at index: 4
*/
