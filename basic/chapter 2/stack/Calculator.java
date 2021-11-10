package com.algorithm.stack;

public class Calculator {

    /**
     * 1. 遍历字符串，获取每一个字符
     * 2. 判断当前字符是一个运算符还是一个数字
     * 3. 把数字放进数字栈， 把字符放进符号栈
     * 4. 运算符栈：
     *      如果是一个空栈则直接运算符入栈
     *      如果运算符栈中已经有其他的运算符，则需要先对比运算符优先级
     *      如果新运算符的优先级小于栈中原运算符的优先级，那么需先把原运算符和数字栈中的数字弹栈，进行运算后将结果放入栈中后，再将新运算符放入栈中
     *      如果新运算符的优先级大于原运算符的优先级，那么新运算符直接入栈
     */
    public static void main(String[] args) {
        String str = "4+3+2*3-1";

        // 数字栈
        Stack numStack = new Stack(10);
        // 运算符栈
        Stack symbolStack = new Stack(10);

        int temp1 = 0;
        int temp2 = 0;
        int symbolChar = 0;
        int result = 0;

        String values = "";
        // 获取字符串的长度
        int length = str.length();
        // 遍历字符串，获取每一个字符
        for (int i = 0; i < length; i ++) {
            // 判断当前字符是一个运算符还是一个数字
            char c = str.charAt(i);

            if (symbolStack.isOperator(c)) {
                // 如果不是一个空的符号栈
                if (!symbolStack.isEmpty()) {
                    // 比较运算符的优先级
                    if (symbolStack.priority(c) <= symbolStack.priority(symbolStack.peek())) {
                        // 获取符号栈中栈顶的符号
                        symbolChar = symbolStack.pop();
                        // 获取数字栈中的两个数字
                        temp1 = numStack.pop();
                        temp2 = numStack.pop();
                        result = numStack.calculate(temp1, temp2, symbolChar);
                        // 把运算结果再次放入数字栈中
                        numStack.push(result);
                        // 把新运算符放入符号栈中
                        symbolStack.push(c);
                    } else {
                        symbolStack.push(c);
                    }
                } else {
                    // 如果是空符号栈，运算符直接入栈
                    symbolStack.push(c);
                }
            } else  {
                //　拼接字符，比如12
                values += c;

                // 最后一个数字直接入栈
                if (i == length - 1) {
                    numStack.push(Integer.parseInt(values));
                } else {
                    char data = str.substring(i + 1, i + 2).charAt(0);
                    if (symbolStack.isOperator(data)) {
                        numStack.push(Integer.parseInt(values));
                        values = "";
                    }
                }
            }
        }

        while (true) {
            if (symbolStack.isEmpty()) {
                break;
            }
            temp1 = numStack.pop();
            temp2 = numStack.pop();
            symbolChar = symbolStack.pop();

            result = numStack.calculate(temp1, temp2, symbolChar);

            numStack.push(result);
        }

        int finalResult = numStack.pop();

        System.out.println("结果是" + finalResult);
    }
}
