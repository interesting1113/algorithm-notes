#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<int> op;

// 优先级表
unordered_map<char, int> pr{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };

//求值
void eval() {
    //第二个操作数
    int a = num.top();
    num.pop();
    
    //第一个操作数
    int b = num.top();
    num.pop();
    
    //运算符
    char p = op.top();
    op.pop();
    
    // 结果
    int result = 0;
    
    // 计算结果
    if (p == '+') result = b + a;
    if (p == '-') result = b - a;
    if (p == '*') result = b * a;
    if (p == '/') result = b / a;
    
    num.push(result);
    
}

int main() {
    string s;
    
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        // 数字入栈
        if (isdigit(s[i])) {
            int x = 0, j = i;
            
            while (j < s.size() && isdigit(s[j])) {
                x = x * 10 + s[j] - '0';
                j ++;
            }
            num.push(x);
            i = j - 1;
        }
        //左括号无优先级，直接入栈
        else if (s[i] == '(') op.push(s[i]);
        //括号特殊，遇到左括号直接入栈，遇到右括号计算括号里面的
        else if (s[i] == ')') {
            //一直计算到左括号
            while(op.top() != '(') {
                eval();
            }
            //左括号出栈
            op.pop();
        } 
        else {
            //待入栈运算符优先级低，则先计算
            while(op.size() && pr[op.top()] >= pr[s[i]]) {
                eval();
            }
            //操作符入栈
            op.push(s[i]);
        }
    }
    //剩余的进行计算
    while(op.size()) eval();
    cout << num.top() << endl;
    
    return 0;
}

