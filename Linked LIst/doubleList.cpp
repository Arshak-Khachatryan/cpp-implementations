#include <doubleList.h>

template<class T>
DLList<T>::DLList():head(nullptr),tail(nullptr){}

template<class T>
DLList<T>::DLList(size_type len):head(nullptr),tail(nullptr){
    if(len){
        head = new Node;
        Node* tmp = head;
        for(size_type i = 1;i<len;++i){
            tmp->next = new Node;
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }
        tail = tmp;
    }
}

template<class T> 
DLList<T>::DLList(size_type count,const_ref_val val):head(nullptr),tail(nullptr){
    if(count){
        head = new Node(val);
        Node* tmp = head;
        for(size_type i = 1;i<count;++i){
            tmp->next = new Node(val);
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }
        tail = tmp;
    }
}

template<class T>
DLList<T>::DLList(const DLList<T> &rhv):head(nullptr),tail(nullptr){
    if(rhv.head){
        Node* tmp1 = rhv.head;
        
        head = new Node(tmp1->val);
        tmp1 = tmp1->next;

        Node* tmp2 = head;
        while(tmp1){
            tmp2->next = new Node(tmp1->val);
            tmp2->next->prev = tmp2;
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
        tail = tmp2;
    }
}

template<class T>
DLList<T>::DLList(DLList<T> &&rhv):head(rhv.head),tail(rhv.tail){
    rhv.head = nullptr;
    rhv.tail = nullptr;
}

template<class T>
DLList<T>::DLList(std::initializer_list<T> arr):head(nullptr),tail(nullptr){
    auto it = arr.begin();
    auto end = arr.end();

    if(it == end)return;

    head = new Node(*it++);
    Node* tmp = head;

    for(;it != end;++it){
        tmp->next = new Node(*it);
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }

    tail = tmp;
}

template<class T>
void DLList<T>::clear(){
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T> 
DLList<T>::~DLList(){
    clear();
}

template<class T>
bool DLList<T>::empty() const{
    return head == nullptr;
}

template<class T>
DLList<T>& DLList<T>::operator=(const DLList<T>& ob){
    if(this != &ob){
        clear();
        if(ob.head){
            Node* tmp2 = ob.head;

            head = new Node(tmp2->val);
            Node* tmp1 = head;

            tmp2 = tmp2->next;
            while(tmp2){
                tmp1->next = new Node(tmp2->val);
                tmp1->next->prev = tmp1;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            tail = tmp1;
        }
    }
    return *this;
}

template<class T>
DLList<T>& DLList<T>::operator=(DLList<T>&& ob){
    if(this != &ob){
        clear();
        head = ob.head;
        tail = ob.tail;
        ob.head = nullptr;
        ob.tail = nullptr;
    }
    return *this;
}

template<class T>
std::size_t DLList<T>::_size() const{
    size_type s = 0;
    Node* tmp = head;
    while(tmp){
        ++s;
        tmp = tmp->next;
    }
    return s;
}

template<class T> 
void DLList<T>::push_back(const_ref_val val){
    if(head){
        tail->next = new Node(val);
        tail->next->prev = tail;
        tail = tail->next;
    }else{
        head = new Node(val);
        tail = head;
    }
}

template<class T>
void DLList<T>::pop_back(){
    if(!head)return;

    if(head == tail){
        clear();
        return;
    }

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
}

template<class T> 
void DLList<T>::push_front(const_ref_val val){
    if(!head){
        head = new Node(val);
        tail = head;
        return;
    }

    head->prev = new Node(val);
    head->prev->next = head;
    head = head->prev;
}

template<class T> 
void DLList<T>::pop_front(){
    if(!head)return;

    if(head == tail){
        clear();
        return;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
}

template<class T>
void DLList<T>::insert(const_ref_val val,size_type pos){
    size_type s = size();

    if(pos > s){
        throw std::out_of_range("Out of range");
    }

    if(pos == 0){
        push_front(val);
        return;
    }

    if(pos == s){
        push_back(val);
        return;
    }

    Node* tmp = head;
    while(pos){
        tmp = tmp->next;
        --pos;
    }

    Node* new_node = new Node(val);
    tmp->prev->next = new_node;
    new_node->prev = tmp->prev;
    new_node->next = tmp;
    tmp->prev = new_node;
}

template<class T>
void DLList<T>::insert(const DLList<T>& other, size_type pos){
    if (pos > size()) {
        throw std::out_of_range("Out of range");
    }

    // Special case: if other is empty, do nothing
    if (!other.head) return;

    // Step 1: deep copy other's nodes
    Node* copied_head = new Node(other.head->val);
    Node* copied_tail = copied_head;
    Node* tmp_other = other.head->next;

    while (tmp_other) {
        copied_tail->next = new Node(tmp_other->val);
        copied_tail->next->prev = copied_tail;
        copied_tail = copied_tail->next;
        tmp_other = tmp_other->next;
    }

    // Step 2: insert the copied list into *this
    if (pos == 0) {
        copied_tail->next = head;
        if (head) head->prev = copied_tail;
        head = copied_head;
        if (!tail) tail = copied_tail; // in case *this was empty
        return;
    }

    if (pos == size()) {
        copied_head->prev = tail;
        if (tail) tail->next = copied_head;
        tail = copied_tail;
        return;
    }

    // Insert in the middle
    Node* current = head;
    for (size_type i = 0; i < pos; ++i) {
        current = current->next;
    }

    Node* prev_node = current->prev;
    prev_node->next = copied_head;
    copied_head->prev = prev_node;

    copied_tail->next = current;
    current->prev = copied_tail;
}

template<class T>
void DLList<T>::del(size_type pos){
    size_type s = size();

    if(pos >= s){
        throw std::out_of_range("Out of range");
    }
    
    if(pos == 0){
        pop_front();
        return;
    }

    if(pos == s-1){
        pop_back();
        return;
    }

    Node* tmp = head;
    while(pos){
        tmp = tmp->next;
        --pos;
    }

    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    delete tmp;
}

template<class T>
bool DLList<T>::search(const_ref_val val) const{
    if(!head)return false;

    Node* tmp = head;
    while(tmp && tmp->val != val){
        tmp = tmp->next;
    }

    return tmp != nullptr;
}

template<class T>
std::size_t DLList<T>::getMiddleElement() const{
    if(!head){
        throw std::logic_error("Your array is empty");
    }
    Node* fast = head;
    size_type s = 0;
    while(fast->next){
        ++s;
        fast = fast->next->next;
    }
    return s;
}
