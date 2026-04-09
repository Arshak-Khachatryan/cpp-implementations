#include <iostream>
#include <vector>

void printarr(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

std::vector<int>& insertionSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 1;i < n;i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
    return arr;
}

int main(){
    std::vector<int> arr = {2,35,1,0,-100,900,2,56};
    insertionSort(arr);

    printarr(arr);
    return 0;
}