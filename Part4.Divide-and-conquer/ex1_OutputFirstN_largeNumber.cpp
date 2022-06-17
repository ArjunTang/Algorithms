/*
题目:
    ex1:输出前m大的数
    --描述--
        给定一个数组包含n个元素,统计前m大的数并且把这m个数从大到小输出.
    --输入--
        第一行包含一个整数n,表示数组的大小(n<100000);
        第二行包含n个整数,表示数组的元素,整数之间以一个空格分开.
            每个整数的绝对值不超过100000000.
        第三行包含一个整数m(m<n).
    --输出--
        从大到小输出前m大的数,每个数一行.
*/

/*
分析:
    如果直接快速排序后输出,时间复杂度为O(nlogn);
    如果使用分治处理,时间复杂度为O(n+mlogm).
    若m足够小则可以使时间复杂度降至O(n),下面使用分治处理.
*/

//把数组前k大的都弄到最右边
void arrangeRight(){

}