#include <iostream>
#include <vector>

void printarr(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void countingSort(std::vector<int>& arr,int index){
    int n = arr.size();
    std::vector<int> tmp(n);
    std::vector<int> count(10,0);

    for(int i = 0;i < n;i++){
        ++count[(arr[i]/index)%10];
    }

    for(int i = 1;i < count.size();i++){
        count[i] += count[i-1];
    }

    for(int i = n-1;i>=0;i--){
        tmp[count[(arr[i]/index)%10]-1] = arr[i];
        --count[(arr[i]/index)%10];
    }

    for(int i = 0;i<n;i++){
        arr[i] = tmp[i];
    }
}

void radixSort(std::vector<int>& arr){
    int n = arr.size();

    int m = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i]>m){
            m = arr[i];
        }
    }

    for(int i = 1; m/i > 0;i*=10){
        countingSort(arr,i);
    }
}

int main(){
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    printarr(arr);
    radixSort(arr);
    printarr(arr);
    return 0;
}