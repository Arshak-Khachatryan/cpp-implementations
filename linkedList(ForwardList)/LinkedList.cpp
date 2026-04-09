#include "LinkedList.h"
// using namespace vhuk;

template<class T> 
vhuk::List<T>::List(){
    head = nullptr;
};

template<class T> 
vhuk::List<T>::List(const size_type size){
    if(size >= 1){
        head = new Node;
        Node* tmp = head;
        for(int i = 2;i <= size;i++){
            tmp->next = new Node;
            tmp = tmp->next;
        }
    }else{
        head = nullptr;
    }
}

template<class T> 
vhuk::List<T>::List(const size_type size, const_reference init){
    if(size >= 1){
        head = new Node(init);
        Node* tmp = head;
        for(int i = 2;i <= size;i++){
            tmp->next = new Node(init);
            tmp = tmp->next;
        }
    }else{
        head = nullptr;
    }
}

template<class T> 
vhuk::List<T>::List(const vhuk::List<T> &rhv){
    if(rhv.head != nullptr){
        head = new Node(rhv.head->data_);
        Node* tmp1 = head;
        Node* tmp2 = rhv.head->next;
        while (tmp2->next != nullptr)
        {
            tmp1->next = new Node(tmp2->data_);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        
    }else{
        head = nullptr;
    }
}

template<class T> 
vhuk::List<T>::List(vhuk::List<T> &&rhv)noexcept{
    head = rhv.head;
    rhv.head = nullptr;
}

template<class T> 
vhuk::List<T>::List(std::initializer_list<value_type> init){
    if (init.size() == 0) {
        head = nullptr;
        return;
    }

    auto it = init.begin();
    head = new Node(*it++);
    Node* tmp = head;

    for (; it != init.end(); ++it) {
        tmp->next = new Node(*it);
        tmp = tmp->next;
    }
}

template<class T> 
template<class InputIterator> 
vhuk::List<T>::List(InputIterator f, InputIterator l){
    if (f == l) {
        head = nullptr;
        return;
    }

    head = new Node(*f++);
    Node* tmp = head;

    for (; f != l; ++f) {
        tmp->next = new Node(*f);
        tmp = tmp->next;
    }
    
}

template<class T> 
void vhuk::List<T>::reverse(){
    // Node* next = nullptr;
    // Node* current = head;
    // Node* prev = nullptr;
    // while(current != nullptr){
    //     next = current->next;
    //     current->next = prev;
    //     prev = current;
    //     current = next;
    // }
    // head = prev;
}
