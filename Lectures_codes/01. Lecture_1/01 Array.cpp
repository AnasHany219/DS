#include <iostream>
using namespace std;

int main()
{
    int arr[100];                       //array
    int nElems = 0;                     //number of items
    int j;                              //loop counter
    int searchKey;                      //key of item to search for

    arr[0] = 77;                        //insert 10 items
    arr[1] = 99;
    arr[2] = 44;
    arr[3] = 55;
    arr[4] = 22;
    arr[5] = 88;
    arr[6] = 11;
    arr[7] = 00;
    arr[8] = 66;
    arr[9] = 33;
    nElems = 10;                        //now 10 items in array

    for(j=0; j<nElems; j++)             //display items
        cout << arr[j] << " ";
    cout << endl;
    searchKey = 66;                     //find item with key 66
    for(j=0; j<nElems; j++)             //for each element,
        if(arr[j] == searchKey)         //found item?  break; yes, exit before end
            if(j == nElems)             //at the end?
                cout << "Can’t find "
                     << searchKey
                     << endl;           //yes
            else
                cout << "Found "
                     << searchKey
                     << endl;           //no
    searchKey = 55;                     //delete item with key 55
    cout << "Deleting " << searchKey << endl;
    for(j=0; j<nElems; j++)             //look for it
        if(arr[j] == searchKey)
            break;
    for(int k=j; k<nElems; k++)         //move higher ones  down
        arr[k] = arr[k+1];
    nElems--;                           //decrement size
    for(j=0; j<nElems; j++)             //display items
        cout << arr[j] << " ";
    cout << endl;
    return 0;
}
//end main()

/*
-----------Output-----------
77 99 44 55 22 88 11 0 66 33
Found 66
Deleting 55
77 99 44 22 88 11 0 66 33
*/
