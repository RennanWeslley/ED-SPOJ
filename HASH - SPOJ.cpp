#include <iostream>
#include <string>

#define SIZE 101

using namespace std;

class Hash {
    public:
        string table[SIZE];
        int size;
        
        Hash() {
            for(int i = 0; i < SIZE; i++)
                this->table[i] = "Empty";
            
            this->size = 0;
        }
        
        bool empty() {
            return !this->size;
        }

        bool full() {
            return this->size >= SIZE;
        }

        int hashK(string key) {
            int pos = 0;
            
            for(int i = 0; i < key.size(); i++)
                pos += key[i] * (i+1);
            
            pos *= 19;
            
            return pos % SIZE;
        }

        void print() {
            cout << this->size << endl;
            
            for(int i = 0; i < SIZE; i++)
                if((this->table[i]).compare("Empty")) {
                    cout << i << ":" << this->table[i] << endl;
                }
        }
        
        void clear() {
            if(this->empty())
                return;
            
            for(int i = 0; i < SIZE; i++)
                this->table[i] = "Empty";
            
            this->size = 0;
        }

        int find(string name) {
            if(this->empty())
                return -1;
            
            int pos = hashK(name);
            int value = pos;
            
            for(int i = 1, j = 0 ; j < 20; j++) {
                if(!name.compare(this->table[pos]))
                    return pos;
                
                if(i < 20) {
                    pos = ((value + (i*i) + 23 * i) % SIZE);
                    i++;
                }
            }
                
            return -1;
        }

        int insert(string name) {
            if(this->full() || this->find(name) > -1)
                return 0;
            
            int pos = hashK(name);
            int value = pos;
            
            for(int i = 1, j = 0 ; j < 20; j++) {
                if(!(this->table[pos]).compare("Empty")) {
                    this->table[pos] = name;
                    this->size++;
                    return 1;
                }
                
                if(i < 20) {
                    pos = ((value + (i*i) + 23 * i) % SIZE);
                    i++;
                }
            }
            
            return 0;
        }

        int del(string name) {
            if(this->empty())
                return 0;
            
            int pos = this->find(name);
            
            if(pos < 0)
                return 0;
            
            this->table[pos] = "Empty";
            this->size--;
            return 1;
        }
};

int main() {
    Hash hash;
    int n, t;
    string op, aux;  
    
   cin >> n;
   cin.ignore();
    
    do {
        cin >> t;
        cin.ignore();
        
        if(t)
            do {
                cin >> op;
                cin.ignore();
                
                switch(op[0]) {
                    case 'A':
                        aux  = op.substr(4);
                        
                        if(aux.compare(""))
                            hash.insert(aux);
                        break;
                    
                    case 'D':
                        aux  = op.substr(4);
                        
                        if(aux.compare(""))
                            hash.del(aux);
                        break;
                }
                
                aux = "";
                
            }while(--t);
        
        hash.print();
        hash.clear();
        
    }while(--n);
}

