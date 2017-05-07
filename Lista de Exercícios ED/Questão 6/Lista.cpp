/*
 *  Lista.c
 *
 *  Created on: May 7th, 2017.
 *  Author: Rennan Weslley
 */

#include "Lista.h"
#include <sstream>

List::List() {
    this->head = NULL;
    this->size = 0;
}

int List::getSize() {
    return this->size;
}

bool List::empty() {
    return !this->head;
}

int List::visit(int pos) {
    if(pos < 1)
        return 0;
    
    if((pos-1) > this->size)
        pos = this->size;
    
    Node *p = this->head;
    
    for(int i = 1; i < pos; p = p->next, i++);
        
    return p->data;
}

int List::search(int data) {
    Node *p = this->head;
    
    for(int i = 1; p; p = p->next, i++)
        if(p->data == data)
            return i;
        
    return 0;
}

int List::insert(int pos, int data) {
    if(pos < 1)
        return 0;
    
    if((pos-1) > this->size)
        pos = this->size;
    
    if(this->empty() || pos == 1)
        return insertHead(data);
    
    return insertIndx(pos, data);
}

int List::insertHead(int data) {
    Node *node = new Node();
    
    node->data  = data;
    node->next  = this->head;
    this->head  = node;
    
    this->size++;
    
    return 1;
}

int List::insertIndx(int pos, int data) {
    Node *p = this->head;
    Node *node = new Node();
    int i = 2;
    
    /*
    if(pos == this->size)
        i = 1;
    */
    
    for(; i < pos; p = p->next, i++);
    
    node->data = data;
    node->next = p->next;
    p->next    = node;
    
    this->size++;
    
    return 1;
}

/*
int List::insertBack(int data) {
    Node *p = this->head;
    
    for(; p->next; p = p->next);
    
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    p->next    = node;
    
    this->size++;
    
    return 1;
}
*/

int List::del(int pos, int *data) {
    if(this->empty() || pos < 1)
        return 0;
    
    if((pos-1) > this->size)
        pos = this->size;
    
    if(pos == 1)
        return delHead(data);
    
    return delIndx(pos, data);
}

int List::delHead(int *data) {
    Node *p = this->head;
    
    *data      = p->data;
    this->head = p->next;
    
    p->next = NULL;
    delete p;
    
    this->size--;
}

int List::delIndx(int pos, int *data) {
    Node *p = this->head,
         *aux;
    
    for(int i = 2; i < pos; p = p->next, i++);
    
    aux = p->next;
    p->next = aux->next;
    
    *data = aux->data;
    aux->next = NULL;
    delete aux;
}

string List::toString() {
    if(this->empty())
        return "Empty\n";
    
    stringstream data;
    string show = "List: {";
    
    Node *p = this->head;
    
    for(; p; p = p->next) {
        data << p->data;
        
        if(!p->next)
            show += data.str() + "}";
        else
            show += data.str() + ", ";
        
        data.str("");
    }
        
    return show + "\n";    
}