#include <iostream>
#include <vector>

void printarr(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void merge(std::vector<int>& arr,int s,int m,int e){
    std::vector<int> tmp(arr.size());
    int index = s;
    int i = s;
    int j = m+1;
    while(i <= m && j <= e){
        if(arr[i] < arr[j]){
            tmp[index++] = arr[i++];
        }else{
            tmp[index++] = arr[j++];
        }
    }

    while(i <= m){
        tmp[index++] = arr[i++];
    }
    while(j <= e){
        tmp[index++] = arr[j++];
    }
    for(int k = s;k <= e;k++){
        arr[k] = tmp[k];
    }
}

void mergeSort(std::vector<int>& arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        mergeSort(arr,s,m);
        mergeSort(arr,m+1,e);
        merge(arr,s,m,e);
        std::cout<<s<<" "<<e<<std::endl;
        printarr(arr);
        std::cout<<"--------------"<<std::endl;
    }
}

int main(){
    std::vector<int> arr = {2,3,1,-10,400,46,0,100};
    mergeSort(arr,0,arr.size()-1);
    printarr(arr);
    return 0;
}