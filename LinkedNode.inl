//
// Created by Alex on 12/3/2017.
//
template <class T>
LinkedNode::LinkedNode<T>(T item){
    this->item = item;
    next = nullptr;
}
template <class T>
LinkedNode::LinkedNode<T>(const LinkedNode<T>& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
template <class T>
T LinkedNode::getItem(){
    return item;
}

LinkedNode<T>* LinkedNode::getNext(){
    return next;
}
template <class T>
void LinkedNode::setItem(T newItem){
    item = newItem;
}

void LinkedNode::setNext(LinkedNode<T>* newNext){
    next = newNext;
}
