package com.algorithm.linkedList;

public class DLLinkedList {

    private GoodsNode node = new GoodsNode(0, "", 0.0);

    /**
     * 往链表中尾部添加节点
     * @param goodsNode
     */
    public void add(GoodsNode goodsNode) {
        GoodsNode temp = node;
        while (true) {
            if (temp.next == null) {
                break;
            }
            temp = temp.next;
        }
        temp.next = goodsNode;
    }

    /**
     * 按从小到大顺序进行添加
     * @param goodsNode
     */
    public void addOrder(GoodsNode goodsNode) {
        GoodsNode temp = node;
        boolean flag = false;
        while (true) {
            if (temp.next == null) {
                break;
            }
            if (temp.next.id > goodsNode.id) {
                break;
            } else if (temp.next.id == goodsNode.id){
                flag = true;
                break;
            }
            temp = temp.next;
        }
        if (flag) {
            System.out.println("已经存在该商品，不能添加重复商品");
        } else {
            goodsNode.next = temp.next;
            temp.next = goodsNode;
        }
    }
}
