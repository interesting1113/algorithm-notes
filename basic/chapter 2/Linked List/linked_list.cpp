#include <iostream>

using namespace std;

const int N = 100010;
int m, head, index;
int value[N], ne[N];

void init () {
    index = 0, head = -1;
}

void add_head(int x) {
    
    value[index] = x;
    ne[index] = head;
    head = index;
    index ++;
    
}

void remove (int k) {
    ne[k] = ne[ne[k]]; 
}

void insert (int k , int x) {
    
    value [index] = x;
    ne[index] = ne[k];
    ne[k] = index;
    index ++;
}

int main () {
    
    init ();
    
    cin >> m;
    
    char op;
   
    while (m --) {
        cin >> op;
        int k, x;
        if (op == 'H') {
            
            cin >> x;
            add_head(x) ;
        } else if (op == 'D') {
           
            cin >> k;
            if (k == 0) head = ne[head]; 
            else remove (k - 1);
        } else if (op == 'I') {
    
            cin >> k >> x;
            insert (k - 1, x);
        }
    }
    
    for (int i = head; i != -1; i = ne[i]) cout << value[i] << ' ';
    cout << endl;
    
    return 0;
}