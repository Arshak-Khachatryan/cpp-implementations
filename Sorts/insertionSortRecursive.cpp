#include <iostream>
#include <vector>

void printarr(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void insertionSort(std::vector<int>& arr,int n){
    if(n >= 1){
        insertionSort(arr,n-1);
        int key = arr[n];
        int j = n-1;
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}


int main(){
    std::vector<int> arr = {2,35,1,0,-100,900,2,56};
    insertionSort(arr,arr.size());

    printarr(arr);
    return 0;
}