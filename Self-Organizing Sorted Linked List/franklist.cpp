#include <iostream>
#include "franklist.h"


int main(){
    return 0;
}
template<class T>
std::ostream &vhuk::operator<<(std::ostream &out, const vhuk::FrankList<T> &rhv){
    for(auto it = rhv.begin();it!=rhv.end();it++){
        out<<*it<<" ";
    }
    return out;
}

template<class T> 
vhuk::FrankList<T>::Node::Node(){
    next = nullptr;
    prev = nullptr;
    asc = nullptr;
    desc = nullptr;
} 

template<class T> 
vhuk::FrankList<T>::Node::Node(T val){
    next = nullptr;
    prev = nullptr;
    asc = nullptr;
    desc = nullptr; 
    this->val = val;
}

//---base Iterator---
template<class T> 
vhuk::FrankList<T>::base_iterator::base_iterator(vhuk::FrankList<T>::Node *ptr){
    this->ptr = ptr;
}

template<class T> 
bool vhuk::FrankList<T>::base_iterator::operator==(const vhuk::FrankList<T>::base_iterator &rhv) const{
    return rhv.ptr == this->ptr;
}

template<class T> 
bool vhuk::FrankList<T>::base_iterator::operator!=(const vhuk::FrankList<T>::base_iterator &rhv) const{
    return rhv.ptr != this->ptr;
}

template<class T> 
vhuk::FrankList<T>::base_iterator::~base_iterator(){
    ptr = nullptr;     
}

// --- const_iterator : public base_iterator ---
template<class T> 
vhuk::FrankList<T>::const_iterator::const_iterator(vhuk::FrankList<T>::Node *ptr):base_iterator(ptr){}


template<class T> 
vhuk::FrankList<T>::const_iterator::const_iterator(const vhuk::FrankList<T>::base_iterator &rhv):base_iterator(rhv.ptr){}

template<class T>
vhuk::FrankList<T>::const_iterator::const_iterator(vhuk::FrankList<T>::base_iterator &&rhv):base_iterator(rhv.ptr){
    rhv.ptr = nullptr;
}

template<class T> 
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if (this != &rhv){
        this->ptr = rhv.ptr;   
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_iterator &vhuk::FrankList<T>::const_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }
    return *this;
}

template<class T> 
const T& vhuk::FrankList<T>::const_iterator::operator*() const{
    return this->ptr->val;
}

template<class T>  
const T* vhuk::FrankList<T>::const_iterator::operator->() const{
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator++(){
    this->ptr = this->ptr->next;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::const_iterator::operator++(value_type){
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T> 
const typename vhuk::FrankList<T>::const_iterator &vhuk::FrankList<T>::const_iterator::operator--(){
    this->ptr = this->ptr->prev;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::const_iterator::operator--(value_type){
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

// --- Iterator : public const_Iterator ---

template<class T>  
vhuk::FrankList<T>::iterator::iterator(vhuk::FrankList<T>::Node *ptr):const_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::iterator::iterator(const vhuk::FrankList<T>::base_iterator &rhv):const_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::iterator::iterator(vhuk::FrankList<T>::base_iterator &&rhv):const_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
T& vhuk::FrankList<T>::iterator::operator*(){
    return this->ptr->val;
}

template<class T> 
T* vhuk::FrankList<T>::iterator::operator->(){
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::iterator& vhuk::FrankList<T>::iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if (this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::iterator &vhuk::FrankList<T>::iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}

// --- const_reverse_iterator : public base_iterator ---

template<class T> 
vhuk::FrankList<T>::const_reverse_iterator::const_reverse_iterator(vhuk::FrankList<T>::Node *ptr):base_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::const_reverse_iterator::const_reverse_iterator(const vhuk::FrankList<T>::base_iterator &rhv):base_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::const_reverse_iterator::const_reverse_iterator(vhuk::FrankList<T>::base_iterator &&rhv):base_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}
template<class T> 
const typename vhuk::FrankList<T>::const_reverse_iterator &vhuk::FrankList<T>::const_reverse_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this != &rhv)
        this->ptr = rhv.ptr;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_reverse_iterator &vhuk::FrankList<T>::const_reverse_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}


template<class T> 
const T& vhuk::FrankList<T>::const_reverse_iterator::operator*() const{
    return this->ptr->val;
}

template<class T> 
const T* vhuk::FrankList<T>::const_reverse_iterator::operator->() const{
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::const_reverse_iterator &vhuk::FrankList<T>::const_reverse_iterator::operator++(){
    this->ptr = this->ptr->prev;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::const_reverse_iterator::operator++(value_type){
    const_reverse_iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T> 
const typename vhuk::FrankList<T>::const_reverse_iterator &vhuk::FrankList<T>::const_reverse_iterator::operator--(){
    this->ptr = this->ptr->next;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::const_reverse_iterator::operator--(value_type){
    const_reverse_iterator temp = *this;
    --(*this); 
    return *this;
}


// --- reverse_iterator: public const_reverse_iterator ---


template<class T>  
vhuk::FrankList<T>::reverse_iterator::reverse_iterator(vhuk::FrankList<T>::Node *ptr):const_reverse_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::reverse_iterator::reverse_iterator(const vhuk::FrankList<T>::base_iterator &rhv):const_reverse_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::reverse_iterator::reverse_iterator(vhuk::FrankList<T>::base_iterator &&rhv):const_reverse_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
T &vhuk::FrankList<T>::reverse_iterator::operator*(){
    return this->ptr->val;
}

template<class T> 
T *vhuk::FrankList<T>::reverse_iterator::operator->(){
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::reverse_iterator& vhuk::FrankList<T>::reverse_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if (this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::reverse_iterator &vhuk::FrankList<T>::reverse_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if (this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}


// --- const_asc_iterator :public base_iterator --- 


template<class T> 
vhuk::FrankList<T>::const_asc_iterator::const_asc_iterator(vhuk::FrankList<T>::Node *ptr):base_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::const_asc_iterator::const_asc_iterator(const vhuk::FrankList<T>::base_iterator &rhv):base_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::const_asc_iterator::const_asc_iterator(vhuk::FrankList<T>::base_iterator &&rhv):base_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
const typename vhuk::FrankList<T>::const_asc_iterator &vhuk::FrankList<T>::const_asc_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this!=&rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}
template<class T> 
const typename vhuk::FrankList<T>::const_asc_iterator &vhuk::FrankList<T>::const_asc_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this!=&rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}

template<class T> 
const T &vhuk::FrankList<T>::const_asc_iterator::operator*() const{
    return this->ptr->val;
}

template<class T> 
const T *vhuk::FrankList<T>::const_asc_iterator::operator->() const{
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::const_asc_iterator &vhuk::FrankList<T>::const_asc_iterator::operator++(){
    this->ptr = this->ptr->asc;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::const_asc_iterator::operator++(value_type){
    const_asc_iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T> 
const typename vhuk::FrankList<T>::const_asc_iterator &vhuk::FrankList<T>::const_asc_iterator::operator--(){
    this->ptr = this->ptr->desc;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::const_asc_iterator::operator--(value_type){
    const_asc_iterator temp{*this};
    --(*this);
    return temp;
}

// --- asc-iterator :public const_asc_iterator ---

template<class T> 
vhuk::FrankList<T>::asc_iterator::asc_iterator(vhuk::FrankList<T>::Node *ptr):const_asc_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::asc_iterator::asc_iterator(const vhuk::FrankList<T>::base_iterator &rhv):const_asc_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::asc_iterator::asc_iterator(vhuk::FrankList<T>::base_iterator &&rhv):const_asc_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
T &vhuk::FrankList<T>::asc_iterator::operator*(){
    return this->ptr->val;
}

template<class T> 
T *vhuk::FrankList<T>::asc_iterator::operator->(){
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::asc_iterator &vhuk::FrankList<T>::asc_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::asc_iterator &vhuk::FrankList<T>::asc_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }
    return *this;
}

// ---const_desc_iterator : public base_iterator ---

template<class T>  
vhuk::FrankList<T>::const_desc_iterator::const_desc_iterator(vhuk::FrankList<T>::Node *ptr):base_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::const_desc_iterator::const_desc_iterator(const vhuk::FrankList<T>::base_iterator &rhv):base_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::const_desc_iterator::const_desc_iterator(vhuk::FrankList<T>::base_iterator &&rhv):base_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
const typename vhuk::FrankList<T>::const_desc_iterator &vhuk::FrankList<T>::const_desc_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this!=&rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_desc_iterator &vhuk::FrankList<T>::const_desc_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this!=&rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}
template<class T> 
const T &vhuk::FrankList<T>::const_desc_iterator::operator*() const{
    return this->ptr->val;
}

template<class T> 
const T* vhuk::FrankList<T>::const_desc_iterator::operator->() const{
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::const_desc_iterator &vhuk::FrankList<T>::const_desc_iterator::operator++(){
    this->ptr = this->ptr->desc;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::const_desc_iterator::operator++(value_type){
    const_desc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T> 
const typename vhuk::FrankList<T>::const_desc_iterator &vhuk::FrankList<T>::const_desc_iterator::operator--(){
    this->ptr = this->ptr->asc;
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::const_desc_iterator::operator--(value_type){
    const_desc_iterator temp = *this;
    --(*this);
    return temp;
}

// --- desc_iterator :public const_desc_iterator ---

template<class T> 
vhuk::FrankList<T>::desc_iterator::desc_iterator(vhuk::FrankList<T>::Node *ptr):const_desc_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::desc_iterator::desc_iterator(const vhuk::FrankList<T>::base_iterator &rhv):const_desc_iterator(rhv.ptr){}

template<class T>
vhuk::FrankList<T>::desc_iterator::desc_iterator(vhuk::FrankList<T>::base_iterator &&rhv):const_desc_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
T &vhuk::FrankList<T>::desc_iterator::operator*(){
    return this->ptr->val;
}

template<class T> 
T *vhuk::FrankList<T>::desc_iterator::operator->(){
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::desc_iterator &vhuk::FrankList<T>::desc_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T>
const typename vhuk::FrankList<T>::desc_iterator &vhuk::FrankList<T>::desc_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}

// --- const_multi_iterator : public base_iterator ---

template<class T>  
vhuk::FrankList<T>::const_multi_iterator::const_multi_iterator(vhuk::FrankList<T>::Node *ptr):base_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::const_multi_iterator::const_multi_iterator(const vhuk::FrankList<T>::base_iterator &rhv):base_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::const_multi_iterator::const_multi_iterator(vhuk::FrankList<T>::base_iterator &&rhv):base_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_iterator &vhuk::FrankList<T>::const_multi_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_iterator &vhuk::FrankList<T>::const_multi_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}
template<class T> 
const T &vhuk::FrankList<T>::const_multi_iterator::operator*() const{
    return this->ptr->val;
}

template<class T> 
const T *vhuk::FrankList<T>::const_multi_iterator::operator->() const{
    return &(this->ptr->val);
}

template<class T> 
void vhuk::FrankList<T>::const_multi_iterator::chmod(){mode = !mode;}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_iterator &vhuk::FrankList<T>::const_multi_iterator::operator++(){
    if(mode){
        this->ptr = this->ptr->next;
    }else{
        this->ptr = this->ptr->asc;
    }

    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::const_multi_iterator::operator++(value_type){
    const_multi_iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_iterator &vhuk::FrankList<T>::const_multi_iterator::operator--(){
    if(mode){
        this->ptr = this->ptr->prev;
    }
    else{
        this->ptr = this->ptr->desc;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::const_multi_iterator::operator--(value_type){
    const_multi_iterator temp = *this;
    --(*this);
    return temp;
}

// --- multi_iterator : public const_multi_iterator --- 

template<class T> 
vhuk::FrankList<T>::multi_iterator::multi_iterator(vhuk::FrankList<T>::Node *ptr):const_multi_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::multi_iterator::multi_iterator(const vhuk::FrankList<T>::base_iterator &rhv):const_multi_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::multi_iterator::multi_iterator(vhuk::FrankList<T>::base_iterator &&rhv):const_multi_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
T &vhuk::FrankList<T>::multi_iterator::operator*(){
    return this->ptr->val;
}
template<class T> 
T *vhuk::FrankList<T>::multi_iterator::operator->(){
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::multi_iterator &vhuk::FrankList<T>::multi_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}
template<class T> 
const typename vhuk::FrankList<T>::multi_iterator &vhuk::FrankList<T>::multi_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}

// --- const_multi_reverse_iterator :public base_iterator ---
template<class T>  
vhuk::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(vhuk::FrankList<T>::Node *ptr):base_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const vhuk::FrankList<T>::base_iterator &rhv):base_iterator(rhv.ptr){}

template<class T> 
vhuk::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(vhuk::FrankList<T>::base_iterator &&rhv):base_iterator(std::move(rhv.ptr)){
    rhv.ptr = nullptr;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_reverse_iterator &vhuk::FrankList<T>::const_multi_reverse_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if (this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_reverse_iterator &vhuk::FrankList<T>::const_multi_reverse_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if (this != &rhv){
        this->ptr = std::move(rhv.ptr);
        rhv.ptr = nullptr;
    }
    return *this;
}

template<class T> 
const T &vhuk::FrankList<T>::const_multi_reverse_iterator::operator*() const{
    return this->ptr->val;
}

template<class T> 
const T *vhuk::FrankList<T>::const_multi_reverse_iterator::operator->() const{
    return &(this->ptr->val);
}

template<class T> 
void vhuk::FrankList<T>::const_multi_reverse_iterator::chmod(){mode = !mode;}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_reverse_iterator &vhuk::FrankList<T>::const_multi_reverse_iterator::operator++(){
    if (mode == true){
        this->ptr = this->ptr->prev;
    }
    else{
        this->ptr = this->ptr->desc;
    }
    return *this;

}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::const_multi_reverse_iterator::operator++(value_type){
    const_multi_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T> 
const typename vhuk::FrankList<T>::const_multi_reverse_iterator &vhuk::FrankList<T>::const_multi_reverse_iterator::operator--(){
    if (mode){
        this->ptr = this->ptr->next;
    }
    else{
        this->ptr = this->ptr->asc;
    }
    return *this;
}

// --- multi_reverse_iterator : public const_multi_reverse_iterator ---

template<class T> 
vhuk::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(vhuk::FrankList<T>::Node *ptr):const_multi_reverse_iterator(ptr){}

template<class T> 
vhuk::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const vhuk::FrankList<T>::base_iterator &rhv):const_multi_reverse_iterator(rhv.ptr){}

template<class T>
vhuk::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(vhuk::FrankList<T>::base_iterator &&rhv):const_multi_reverse_iterator(std::move(rhv.ptr)){}

template<class T> 
T &vhuk::FrankList<T>::multi_reverse_iterator::operator*(){
    return this->ptr->val;
}
template<class T> 
T *vhuk::FrankList<T>::multi_reverse_iterator::operator->(){
    return &(this->ptr->val);
}

template<class T> 
const typename vhuk::FrankList<T>::multi_reverse_iterator &vhuk::FrankList<T>::multi_reverse_iterator::operator=(const vhuk::FrankList<T>::base_iterator &rhv){
    if (this != &rhv){
        this->ptr = rhv.ptr;
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T>::multi_reverse_iterator &vhuk::FrankList<T>::multi_reverse_iterator::operator=(vhuk::FrankList<T>::base_iterator &&rhv){
    if(this != &rhv){
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }
    return *this;
}

// ---------------------------Franklist------------------------------

template<class T> vhuk::FrankList<T>::FrankList(){
    head = nullptr;
    tail = nullptr;
    ahead = nullptr;
    atail = nullptr;   
}

template<class T>  
vhuk::FrankList<T>::FrankList(size_type size){
    head = nullptr;
    tail = nullptr;
    ahead = nullptr;
    atail = nullptr;

    for (int i = 0; i<size; i++){
        push_back(T()); 
    }
}

template<class T> 
vhuk::FrankList<T>::FrankList(size_type size, const_reference init){
    head = nullptr;
    tail = nullptr;
    ahead = nullptr;
    atail = nullptr;

    for(int i = 0;i<size;i++){
        push_back(init);
    }    
}
//-----------------------------------------------------------------------

template<class T> 
void vhuk::FrankList<T>::push_back(const_reference elem){
    Node* node = new Node(elem);
    if (head == nullptr){
        head = tail = node;
    }else{
        node->prev = tail;
        tail->next = node; 
        tail = node;
    }
    put_in_sorted_order(node); 
}

template<class T> 
void vhuk::FrankList<T>::clear() noexcept{
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    atail = nullptr;
    ahead = nullptr;
}

template<class T> 
void vhuk::FrankList<T>::pop_back(){
    if(head == nullptr){
        throw std::out_of_range("No element in list");
    }

    if (head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }

    if (tail->asc != nullptr){
        (tail->asc)->desc = tail->desc;
    }
    if (tail->desc != nullptr){
        tail->desc->asc = tail->asc;
    }
    
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}

template<class T> 
void vhuk::FrankList<T>::push_front(const_reference elem){
    Node* node = new Node(elem);

    if (head == nullptr){
        head = tail = node;
    }
    else{
        node->next = head;
        head->prev = node;
        head = node;
    }
    put_in_sorted_order(node);
}

template<class T> 
void vhuk::FrankList<T>::pop_front(){
    if(head == nullptr){
        throw std::out_of_range("No element");
    }
    if (head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }

    if (head->asc != nullptr){ 
        head->asc->desc = head->desc;
    }
    if (head->desc != nullptr){
        head->desc->asc = head->asc;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
}

template<class T> 
bool vhuk::FrankList<T>::empty() const{
    if (head == nullptr){
        return true;
    }
    return false;
}

template<class T> 
void vhuk::FrankList<T>::resize(size_type s, const_reference init ){
    size_type listSize = size(); 
    if (s == listSize){
        return;
    }else if(s<listSize){
        for(int i = 0; i < listSize - s;i++){
            pop_back();
        }
    }else{
        for(int i = 0; i<s-listSize;i++){
            push_back(init);
        }
    }
}

template<class T> 
void vhuk::FrankList<T>::swap(vhuk::FrankList<T> &rhv){
    Node* temp = nullptr;
    
    temp = head;
    head = rhv.head;    
    rhv.head = temp;

    temp = tail;
    tail = rhv.tail;
    rhv.tail = temp;

    temp = ahead;
    ahead = rhv.ahead;
    rhv.ahead = temp;

    temp = atail;
    atail = rhv.atail;
    rhv.atail = temp;

}

template<class T> 
const T &vhuk::FrankList<T>::front() const{
    if (head == nullptr){
        throw std::out_of_range("No element");
    }
    return head->val;
}

template<class T>  
T &vhuk::FrankList<T>::front(){
    if (head == nullptr) {
        throw std::out_of_range("No element");
    }
    return head->val;
}

template<class T> 
const T &vhuk::FrankList<T>::back() const{
    if (tail == nullptr){
        throw std::out_of_range("No element");
    }
    return tail->val;
}
template<class T> 
T &vhuk::FrankList<T>::back(){
    if (tail == nullptr){
        throw std::out_of_range("No element");
    }
    return tail->val;
}

template<class T> 
const T &vhuk::FrankList<T>::min() const{
    if (ahead == nullptr){
        throw std::out_of_range("No element");
    }
    return ahead->val;
}

template<class T> 
T &vhuk::FrankList<T>::min(){
    if (ahead == nullptr){
        throw std::out_of_range("No element");
    }
    return ahead->val;
}

template<class T> 
const T &vhuk::FrankList<T>::max() const{
    if (atail == nullptr){
        throw std::out_of_range("No element");
    }
    return atail->val;
}

template<class T> 
T &vhuk::FrankList<T>::max(){
    if(atail == nullptr){
        throw std::out_of_range("No element");
    }
    return atail->val;
}

// --- Franklist`s const Iterators ---

template<class T> 
typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::cbegin() const{
    return const_iterator(head);
}

template<class T> 
typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::cend() const{
    return const_iterator(tail->next);
}

template<class T> 
typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::crbegin() const{
    return const_reverse_iterator(tail);
}

template<class T> 
typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::crend() const{
    return const_reverse_iterator(head->prev); 
}

template<class T> 
typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::cabegin() const{
    return const_asc_iterator(ahead);
}

template<class T> 
typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::caend() const{
    return const_asc_iterator(atail->asc);
}

template<class T> 
typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::cdbegin() const{
    return const_desc_iterator(atail);
}
template<class T> 
typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::cdend() const{
    return const_desc_iterator(ahead->desc);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmbegin() const{
    return const_multi_iterator(head);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmend() const{
    return const_multi_iterator(tail->next);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmabegin() const{
    return const_multi_iterator(ahead);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmaend() const{
    return const_multi_iterator(atail->asc);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrbegin() const{
    return const_multi_reverse_iterator(tail);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrend() const{
    return const_multi_reverse_iterator(head->prev);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrdbegin() const{
    return const_multi_reverse_iterator(atail);
}

template<class T> 
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrdend() const{
    return const_multi_reverse_iterator(ahead->desc);
}

// --- Franklist`s Iterators ---

template<class T> 
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::begin(){
    return iterator(head);
}

template<class T> 
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::end(){
    return iterator(tail->next);
}

template<class T> 
typename vhuk::FrankList<T>::reverse_iterator vhuk::FrankList<T>::rbegin(){
    return reverse_iterator(tail);
}

template<class T> 
typename vhuk::FrankList<T>::reverse_iterator vhuk::FrankList<T>::rend(){
    return reverse_iterator(head->prev);
}

template<class T> 
typename vhuk::FrankList<T>::asc_iterator vhuk::FrankList<T>::abegin(){
    return asc_iterator(ahead);
}

template<class T> 
typename vhuk::FrankList<T>::asc_iterator vhuk::FrankList<T>::aend(){
    return asc_iterator(atail->asc);
}

template<class T> 
typename vhuk::FrankList<T>::desc_iterator vhuk::FrankList<T>::dbegin(){
    return desc_iterator(atail);
}

template<class T> 
typename vhuk::FrankList<T>::desc_iterator vhuk::FrankList<T>::dend(){
    return desc_iterator(ahead->desc);
}

template<class T> 
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mbegin(){
    return multi_iterator(head);
}

template<class T> 
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mend(){
    return multi_iterator(tail->next);
}

template<class T> 
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mabegin(){
    return multi_iterator(ahead);
}

template<class T> 
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::maend(){
    return multi_iterator(atail->asc);
}

template<class T> 
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrbegin(){
    return multi_reverse_iterator(tail);
}

template<class T> 
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrend(){
    return multi_reverse_iterator(head->prev);
}

template<class T> 
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrdbegin(){
    return multi_reverse_iterator(atail);
}

template<class T> 
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrdend(){
    return multi_reverse_iterator(ahead->desc);
}

// -------------------------------------------------------


template<class T> 
std::size_t vhuk::FrankList<T>::size() const{
    std::size_t s = 0;
    for(auto it = begin(); it!=cend();it++){
        ++s;
    }
    return s;
}

template<class T> 
const typename vhuk::FrankList<T>& vhuk::FrankList<T>::operator=(const vhuk::FrankList<T> &rhv){
    if (this != &rhv){
        clear();
        for(auto it = rhv.begin();it != rhv.end();it++){
            push_back(*it);
        }
    }
    return *this;
}

template<class T> 
const typename vhuk::FrankList<T> &vhuk::FrankList<T>::operator=(vhuk::FrankList<T> &&rhv){
    if (this != &rhv){
        clear();

        head = rhv.head;
        tail = rhv.tail;
        ahead = rhv.ahead;
        atail = rhv.atail;

        rhv.head = nullptr;
        rhv.tail = nullptr;
        rhv.ahead = nullptr;
        rhv.atail = nullptr;
    }
    return *this;
}


template<class T> 
const typename vhuk::FrankList<T> &vhuk::FrankList<T>::operator=(std::initializer_list<T> init){
    auto it = begin();
    auto lit = init.begin();

    for(;it!=end() && lit!=init.end();it++,lit++){
        *it = *lit;
    }
    return *this;
}

template<class T> 
bool vhuk::FrankList<T>::operator==(const vhuk::FrankList<value_type> &rhv) const{
    if (size() == rhv.size()){
            // 1,2,3 != 3,2,1
        auto it1 = begin();
        auto it2 = rhv.begin();
        for(;it1!=end();it1++,it2++){
                if(*it1 != *it2){
                    return false;
                }
        } 
        // 1,2,3 == 3,2,1
        // auto it1 = abegin();
        // auto it2 = rhv.abegin();
        // for(;it1!=aend();it1++,it2++){
        //     if(*it1 != *it2){
        //         return false;
        //     }
        // }
    }
   return false;
}


template<class T> 
bool vhuk::FrankList<T>::operator!=(const vhuk::FrankList<T> &rhv) const{
    return !(*this == rhv);
}

template<class T> 
bool vhuk::FrankList<T>::operator<(const vhuk::FrankList<T> &rhv) const{
    auto it1 = begin();
    auto it2 = rhv.begin();

    for(;it1 != end() && it2 != rhv.end();++it1,++it2){
        if(*it1 > *it2){
            return false;
        }
    }
    
    return size() < rhv.size();
}



template<class T> 
bool vhuk::FrankList<T>::operator<=(const vhuk::FrankList<T> &rhv) const{
    return (*this < rhv || *this == rhv);
}

template<class T> 
bool vhuk::FrankList<T>::operator>(const vhuk::FrankList<T> &rhv) const{
    return !(*this <= rhv);
}

template<class T> 
bool vhuk::FrankList<T>::operator>=(const vhuk::FrankList<T> &rhv) const{
    return !(*this < rhv);
}

// ----- Franklist ----

template<class T> 
vhuk::FrankList<T>::FrankList(const vhuk::FrankList<T> &rhv):head(nullptr),tail(nullptr),ahead(nullptr),atail(nullptr){
    auto it = rhv.begin();

    for(;it != rhv.end();++it){
        push_back(*it);
    }
}

template<class T> 
vhuk::FrankList<T>::FrankList(vhuk::FrankList<T> &&rhv):head(rhv.head),tail(rhv.tail),ahead(rhv.ahead),atail(rhv.atail){
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}

template<class T> 
vhuk::FrankList<T>::FrankList(std::initializer_list<T> init):head(nullptr),tail(nullptr),ahead(nullptr),atail(nullptr){
    auto it = init.begin();
    for(;it!=end();it++){
        push_back(*it);
    }
}

template<class T> 
template<class input_iterator> 
vhuk::FrankList<T>::FrankList(input_iterator f, input_iterator l):head(nullptr),tail(nullptr),ahead(nullptr),atail(nullptr){
    for(input_iterator it = f;it!=l;it++){
        push_back(*it);
    }
}


template<class T> 
vhuk::FrankList<T>::~FrankList(){
    clear();
}

template<class T> 
template<class unary_predicate> 
void vhuk::FrankList<T>::traverse(unary_predicate func, bool sorted , bool reversed ){
    if (head == nullptr){
        return;
    }
    if(sorted == false && reversed == false){
        for(auto it = begin();it!=end();it++){
            func(*it);
        }
    }else if(!reversed){
        for(auto it = abegin();it!=aend();it++){
            func(*it);
        }
    }else if(!sorted){
        for(auto it = rbegin();it!=rend();it++){
            func(*it);
        }
    }else{
        for(auto it = dbegin();it!=dend();it++){
            func(*it);
        }
    }
    
}

template<class T> 
void vhuk::FrankList<T>::print(bool sorted , bool reversed){
   if (head == nullptr){
        return;
    }
    if(sorted == false && reversed == false){
        for(auto it = begin();it!=end();it++){
            std::cout<<*it<<" ";
        }
    }else if(!reversed){
        for(auto it = abegin();it!=aend();it++){
            std::cout<<*it<<" ";
        }
    }else if(!sorted){
        for(auto it = rbegin();it!=rend();it++){
            std::cout<<*it<<" "; 
        }
    }else{
        for(auto it = dbegin();it!=dend();it++){
            std::cout<<*it<<" ";  
        }
    } 
}

template<class T> 
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::find(const_reference elem){
    iterator it = begin();
    for(;it!=end();it++){
        if (*it == elem){
            organize_left(it.ptr);
            return it;
        }
    }
    throw std::invalid_argument("No such element");
}

template<class T> 
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::rfind(const_reference elem){
    reverse_iterator it = rbegin();
    for(;it!=end();it++){
        if(*it == elem){
            organize_right(it.ptr);
            return iterator(it);
        }
    }
    throw std::invalid_argument("No such element");
}


template<class T> 
void vhuk::FrankList<T>::reverse(){ 
    if (head == nullptr){
        throw std::out_of_range("No elements");
    } 
    else if(head == tail){
        return;
    }

    Node* tmp = head;
    head = tail;
    tail = tmp;

    tmp = head;

    while(tmp != nullptr){
        Node* x = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev = x;

        tmp=tmp->next;
    }
}


template<class T> 
template<class iter> 
iter vhuk::FrankList<T>::erase(iter pos) {
    if (head == nullptr) {
        throw std::out_of_range("No elements");
    }

    iter temp = pos;
    temp++;

    if (pos.ptr == head) {
        pop_front();
    } else if (pos.ptr == tail) {
        pop_back();
    } else {
        pos.ptr->next->prev = pos.ptr->prev;
        pos.ptr->prev->next = pos.ptr->next;

        if (pos.ptr->asc != nullptr) {
            pos.ptr->asc->desc = pos.ptr->desc;
        }

        if (pos.ptr->desc != nullptr) {
            pos.ptr->desc->asc = pos.ptr->asc;
        }

        delete pos.ptr;
    }

    return temp;
}


template<class T> 
template<class iter> 
iter vhuk::FrankList<T>::erase(iter f, iter l){
    while(f!=l){
        f = erase(f);
    }
    return f;
}

template<class T> 
std::size_t vhuk::FrankList<T>::remove(const_reference val){
    size_t rs = 0;
    for(auto it = begin();it!=end();){
        if(*it == val){
            it = erase(it); 
            rs++;
        }else{
            it++;
        }
    }
    return rs;
}

template<class T> 
template<class unary_predicate> 
std::size_t vhuk::FrankList<T>::remove_if(unary_predicate func){
    size_t rs = 0;
    for(auto it = begin();it!=end();){
        if (func(*it)){
            it = erase(it);
            rs++;
        }else{
            it++;
        }
    }
    return rs;
}

template<class T> 
void vhuk::FrankList<T>::sort(bool reversed ){
    if (head == nullptr){
        return;
    }
   
    Node* ptr = ahead;
    
    head = ahead;
    tail = atail;
    
    if(ptr->prev != nullptr){
        ptr->prev->next = nullptr;
    }
    ptr->prev = nullptr;

    for(;ptr!=nullptr;ptr=ptr->next){
        ptr->next = ptr->asc;
        if(ptr->next != nullptr){
            ptr->next->prev = ptr;
        }
    }

    if(reversed){
        reverse();    
    }
    
}


template<class T> 
void vhuk::FrankList<T>::put_in_sorted_order(vhuk::FrankList<T>::Node *ptr){
    if (!ahead) {
        ahead = atail = ptr;
        return;
    }

    if (ptr->val <= ahead->val) {
        ptr->asc = ahead;
        ahead->desc = ptr;
        ahead = ptr;
        return;
    }

    if (ptr->val >= atail->val) {
        ptr->desc = atail;
        atail->asc = ptr;
        atail = ptr;
        return;
    }

    Node* tmp = ahead;
    while (tmp->asc && tmp->asc->val < ptr->val) {
        tmp = tmp->asc;
    }

    ptr->asc = tmp->asc;
    ptr->desc = tmp;
    tmp->asc = ptr;
    ptr->asc->desc = ptr;
}


template<class T> 
void vhuk::FrankList<T>::organize_left(Node *ptr){
    if (head == nullptr){
        return;
    }

    Node* tmp = ptr->prev;
    
    ptr->prev->next = ptr->next; 
    ptr->next->prev = tmp;
    ptr->next = tmp;
    if(tmp->prev == nullptr){
        ptr->prev = nullptr;
        head = ptr;
        return;
    }
    ptr->prev = tmp->prev;
    tmp->prev->next = ptr;
    tmp->prev = ptr;

}

template<class T> 
void vhuk::FrankList<T>::organize_right(Node *ptr){
    if (tail == nullptr){
        return;
    }
    Node* tmp = ptr->next;
    ptr->prev->next = ptr->next; 
    ptr->next->prev = ptr->prev;
    ptr->prev = tmp;

    if(tmp->next == nullptr){
        ptr->next = nullptr;
        tail = ptr;
        return;
    }
    ptr->next = tmp->next;
    tmp->next = ptr;
    ptr->next->prev = ptr;
    
}

template<class T> 
template<class iter> 
iter vhuk::FrankList<T>::insert_def(iter pos, const_reference val){
    if (pos.ptr == nullptr){
        throw std::invalid_argument("nullptr");
    }
    if(pos.ptr == head){
        push_front(val);
    }else if(pos.ptr == tail){
        push_back(val);
    }else{
        Node* node = new Node(val);
        pos.ptr->prev->next = node;
        node->prev = pos.ptr->prev;
        pos.ptr->prev = node;
        node->next = pos.ptr;

        put_in_sorted_order(node);
    }
    return pos;

}

template<class T>  ///
template<class iter> 
iter vhuk::FrankList<T>::insert_rev(iter pos, const_reference val){
    if (pos.ptr == nullptr ){
        throw std::invalid_argument("nullptr");
    } 
    insert_def(pos,val);
    pos++;
    return pos;
}

template<class T> 
template<class iter> 
iter vhuk::FrankList<T>::insert(iter pos, size_type size, const_reference val){
    if(pos.ptr == nullptr){
        throw std::invalid_argument("nullptr");
    }
    for(std::size_t count = 0; count<size;count++){
        pos = insert(pos,val);
    }
    return pos;
}

template<class T> 
template<class iter> 
iter vhuk::FrankList<T>::insert(iter pos, std::initializer_list<T> init){
    if(pos.ptr == nullptr){
        throw std::invalid_argument("nullptr");
    }
    for(auto it = init.begin();it!=init.end();it++){
        pos = insert(pos,*it);
    }
    return pos;

}

template<class T>
template<class iter, class input_iterator> 
iter vhuk::FrankList<T>::insert(iter pos, input_iterator f, input_iterator l){
    if(pos.ptr == nullptr){
        throw std::invalid_argument("nullptr");
    }
    for(auto it = f;it!=l;it++){
        pos = insert(pos,*it);
    }
    return pos;
}
