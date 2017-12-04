//
// Created by Alex on 12/3/2017.
//
template <class T>
LinkedNode<T>::LinkedNode(T item){
    this->item = item;
    next = nullptr;
}
template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode<T>& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
template <class T>
T LinkedNode<T>::getItem(){
    return item;
}

template <class T>
LinkedNode<T>::~LinkedNode(){
    delete item;
}
template <class T>
LinkedNode<T>* LinkedNode<T>::getNext(){
    return next;
}
template <class T>
void LinkedNode<T>::setItem(T newItem){
    item = newItem;
}
template <class T>
void LinkedNode<T>::setNext(LinkedNode<T>* newNext){
    next = newNext;
}
