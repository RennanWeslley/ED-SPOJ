#include "Lista.h"

int main() {
    List list;
    
    /* cout << "Lista vazia? -> "; list.empty()? cout << ("Sim") : cout << ("Nao"); cout << endl; */
    
    list.insert(1, 2);
    cout << list.toString();
    
    /* cout << "Lista vazia? -> "; list.empty()? cout << ("Sim") : cout << ("Nao"); cout << endl; */
    
    list.insert(2, 3);
    cout << list.toString();
    
    list.insert(1, 1);
    cout << list.toString();
    
    list.insert(4, 5);
    cout << list.toString();
    
    list.insert(4, 4);
    cout << list.toString();
    
    cout << endl;
    
    int data = list.visit(1);
    cout << "Dado " << data << " encontrado na posicao informada" << endl;
    
    data = list.search(1);
    data? cout << "Dado encontrado na posição " << data : cout << "Dado não encontrado"; cout << endl;
    
    cout << endl;
    
    list.del(5, &data);
    cout << list.toString();
    
    list.del(1, &data);
    cout << list.toString();
    
    list.del(2, &data);
    cout << list.toString();
    
    cout << endl;
    
    return 0;
}