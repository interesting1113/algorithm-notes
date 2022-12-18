#include <iostream>

using namespace std;

const int N = 100010;
int stk[N], top;

int main() {

    int m;
    string op;

    cin >> m;

    while (m --) {
        cin >> op;
        int x;

        if (op == "push") {

            cin >> x;
            stk[++ top] = x; //插入

        } else if (op == "query") {

            cout << stk[top] << endl;//栈顶

        } else if (op == "empty") {

           //判断栈是否为空
           if (top > 0) cout << "NO" << endl;  
           else cout << "YES" << endl;
        } else if (op == "pop") {

            top --;//弹出
        }
    }
    return 0;
}