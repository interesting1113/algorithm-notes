package com.algorithm.stack;

// 使用数组模拟栈
public class Stack {
    // 栈的大小
    private int maxStack;

    // 用数组来模拟栈
    private int[] stack;

    // 表示栈顶所在位置，默认情况下如果没有数据时，使用-1
    private int top = -1;

    public Stack(int maxStack) {
        this.maxStack = maxStack;
        stack = new int[maxStack];
    }

    /**
     * 判断是否已经满栈
     * @return
     */
    public boolean isFull() {
        // 栈顶位置是否等于数组长度，等于则满栈
        return this.top == this.maxStack - 1;
    }

    /**
     * 判断是否是空栈
     * @return
     */
    public boolean isEmpty() {
        // 如果返回值为-1，则表示该栈没有存储过数据
        return this.top == -1;
    }

    /**
     * 压栈
     * @param value
     */
    public void push(int value) {
        // 是否满栈
        if (isFull()) {
            throw new RuntimeException("此栈已满");
        }
        // 栈顶先向上移一个位置
        top ++;
        stack[top] = value;

    }

    /**
     * 弹栈
     * @return
     */
    public int pop() {
        // 如果空栈
        if (isEmpty()) {
            throw new RuntimeException("空栈，无数据");
        }
        // 弹出栈顶数据
        int value = stack[top];
        // 栈顶向下移一个位置
        top --;
        return value;
    }

    /**
     * 查看栈中所有的元素
     */
    public void list() {
        // 判断是否空栈
        if (isEmpty()) {
            throw new RuntimeException("空栈，无数据");
        }

        for (int i = 0; i < stack.length; i ++) {
            System.out.printf("stack[%d] = %d\n", i, stack[i]);
        }

    }

    /**
     * 查看栈顶数据
     * @return
     */
    public int peek() {
        return this.stack[top];
    }

    /**
     * 获取栈的容量
     * @return
     */
    public int stackLength() {
        return this.stack.length;
    }

    /**
     * 判断是否是一个运算符
     * @param v
     * @return
     */
    public boolean isOperator(char v) {
        return v == '+' || v == '-' || v == '*' || v == '/';
    }

    /**
     * 判断运算符的优先级
     * 使用数字表示优先级的大小，数字越大优先级越大
     * @param oper
     * @return
     */
    public int priority(int oper) {
        if (oper == '*' || oper == '/') {
            return 1;
        } else if (oper == '+' || oper == '-') {
            return 0;
        } else {
            return -1;
        }
    }

    /**
     * 计算两个数进行运算后的结果
     * @param num1
     * @param num2
     * @param oper
     * @return
     */
    public int calculate(int num1, int num2, int oper) {
        int result = 0;
        switch (oper) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num2 / num1;
                break;
            default:
                break;
        }
        return result;
    }
}
