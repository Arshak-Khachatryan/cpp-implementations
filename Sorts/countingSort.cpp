#include <iostream>
#include <vector>

void printarr(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void countingSort(std::vector<int>& arr){
    int n = arr.size();
    std::vector<int> tmp(n);

    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    
    std::vector<int> count(max-min+1,0);

    for(int i = 0;i < n;i++){
        ++count[arr[i]-min];
    }

    for(int i = 1;i < count.size();i++){
        count[i] += count[i-1];
    }

    for(int i = n-1;i>=0;i--){
        tmp[count[arr[i]-min]-1] = arr[i];
        --count[arr[i]-min];
    }

    for(int i = 0;i<n;i++){
        arr[i] = tmp[i];
    }
}

int main(){
    std::vector<int> arr = {-2,3,-5};
    printarr(arr);
    countingSort(arr);
    printarr(arr);
    return 0;
}