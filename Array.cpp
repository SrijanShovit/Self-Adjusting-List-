#include<bits/stdc++.h>
using namespace std;

const int limit = 10e5+10;
int arr[limit];


bool Find(int n,int num){
    int i,index=0;
    for (i=0;i<n;i++){
        //traversing through the array to find the searched element
        if (arr[i]==num){
            index = i; 
            break;
        } 
    }   //O(n)

    //if found then shift all elements to right before the index at which searched element is found and put the searched  element in front of list
    if (index){
        for (i=index;i>0;i--){
            arr[i] = arr[i-1];
        }
        arr[0] = num;
        
        return true;
    }      //O(n)
    else return false;
}


int main()
{
    cout << "Enter number of elements in list" << endl;
    int n;
    cin >> n;
    cout << "Enter elements of list" << endl;
    for (int i=0;i<n;i++){
        
        cin >> arr[i];             //O(n)
       
    }

    cout << "Enter element to be searched" << endl;
    int find;
    cin >> find;
    bool found = Find(n,find);
    if  (found) {

        cout << find << " is present in the list"<< endl;
    } 
    else {
        cout << find << " is not present in the list"<< endl;

    } 

    for (int i=0;i<n;i++) cout << arr[i] << endl;  //O(n)
  
    
    return 0;
}


//MAin work time complexity : O(n) + O(n) = O(2n) = o(n)