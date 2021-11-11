package com.algorithm.linkedList;

public class LinkedList<T> {

    // 记录头节点
    public Node head;
    // 链表的长度
    private int N;

    private class Node {
        // 存储的元素
        T item;
        // 下一个节点
        Node next;

        public Node(T item, Node next) {
            this.item = item;
            this.next = next;
        }
    }

    /**
     *  初始化链表
     */
    public LinkedList() {
        // 创建头节点
        this.head = new Node(null, null);
        // 初始化元素个数
        this.N = 0;
    }

    /**
     * 清空链表
     */
    public void clear() {
        head.next = null;
        this.N = 0;
    }

    /**
     * 获取链表长度
     * @return
     */
    public int length() {
        return N;
    }

    /**
     * 判读链表是否为空
     * @return
     */
    public boolean isEmpty() {
        return N == 0;
    }

    /**
     * 获取指定i位置的元素
     * @param i
     * @return
     */
    public T get(int i) {
        // 通过循环，从头节点开始往后找，依次找i次就可以找到对应的元素
        Node n = head.next; // 使用n记录一下第一个存储数据的节点
        for (int index = 0; index < i; index++) {
            n = n.next;
        }
        // 返回i位置储存的元素
        return n.item;
    }

    /**
     * 向链表尾部添加元素
     * @param t
     */
    public void insert(T t) {
        // 找到当前最后一个节点
        Node n = head;
        while (n.next != null) {
            n = n.next;
        }
        // 创建新节点， 保存元素t
        Node newNode = new Node(t, null);
        // 让当前最后一个节点指向新节点
        n.next = newNode;
        // 元素的个数+1
        N ++;
    }

    /**
     * 向指定位置添加元素
     * @param i
     * @param t
     */
    public void insert(int i, T t) {
        // 找到i位置的前一个节点
        Node pre = head;
        for (int index = 0; index <= i - 1 ; index++) {
            pre = pre.next;
        }
        // 找到i位置的节点
        Node cur = pre.next;
        // 创建新节点，并且新节点需要指向原来i位置的节点
        Node newNode = new Node(t, cur);
        // 原来i位置的前一个节点指向新节点
        pre.next = newNode;
        // 元素个数+1
        N ++;
    }

    /**
     * 删除指定位置的节点，并返回被删除的元素
     * @param i
     * @return
     */
    public T remove(int i) {
        // 找到i位置的前一个节点
        Node pre = head;
        for (int index = 0; index <= i - 1 ; index++) {
            pre = pre.next;
        }
        // 找到i位置的节点
        Node curNode = pre.next;
        // 找到i位置的下一个节点
        Node nextnode = curNode.next;
        // 前一个节点指向下一个节点
        pre.next = nextnode;
        // 元素个数-1
        N --;
        return curNode.item;
    }

    /**
     * 查找元素在链表中第一次出现的位置
     * @param t
     * @return
     */
    public int indexOf(T t) {
        // 从头节点开始，依次找到每一个极点，取出item和t比较，如果相同表示则找到
        Node n = head;
        for (int i = 0; n.next != null ; i++) {
            n = n.next;
            if (n.item.equals(t)) {
                return i;
            }
        }
        return -1;
    }
}