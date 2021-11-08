// 使用数组模拟栈
public class ArrayStack {

  // 栈的大小
  private int maxStack;

 // 用数组来模拟栈
  private int[] stack;

  // 表示栈顶所在位置，默认情况下如果没有数据时，使用-1
  private int top = -1;

  public ArrayStack(int maxStack) {
    this.maxStack = maxStack;
  }

  // 判断是否已经满栈
  public boolean isFull() {
    // 栈顶位置是否等于数组长度，等于则满栈
    return this.top == this.maxStack - 1;
  }

  // 判断是否是空栈
  public boolean isEmpty() {
    // 如果返回值为-1，则表示该栈没有存储过数据
    return this.top == -1;
  }

  // 压栈
  public void push(int value) {
    // 是否满栈
    if (isFull()) {
      throw new RuntimeException("此栈已满");
    }
    // 栈顶先向上移一个位置
    top ++;
    stack[top] = value;

  }

  // 弹栈
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

  // 查看栈中所有的元素
  public void list() {
    // 判断是否空栈
    if (isEmpty()) {
      throw new RuntimeException("空栈，无数据");
    }

    for (int i = 0; i < stack.length; i ++) {
      System.out.printf("stack[%d] = %d\n", i, stack[i]);
    }

  }

}