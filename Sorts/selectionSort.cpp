#include <iostream>
#include <vector>

std::vector<int>& selectionSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        int k = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        std::swap(arr[i],arr[k]);
    }
    return arr;
}


int main(){
    std::vector<int> arr = {2,35,1,0,-10,900,2,56};
    selectionSort(arr);

    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}