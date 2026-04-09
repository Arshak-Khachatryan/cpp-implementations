#include <iostream>
#include <vector>

void printarr(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int partition(int s,int e,std::vector<int>& arr){
    int p_i = e;
    int pivot = arr[p_i];
    int i = s-1;
    for(int j = s;j<=e;j++){
        if(arr[j] <= pivot && j != p_i){
            i++;
            std::swap(arr[j],arr[i]);
        }
    }
    std::swap(arr[i+1],arr[p_i]);
    return i+1;
}

void quickSort(int s,int e,std::vector<int>& arr){
    if(s<e){
        int p_i = partition(s,e,arr);
        quickSort(s,p_i-1,arr);
        quickSort(p_i+1,e,arr);
    }
}

int main(){
    std::vector<int> arr = {2,3,1,-10,400,46,0,100};
    quickSort(0,arr.size()-1,arr);
    printarr(arr);
    return 0;
}