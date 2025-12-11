# Chapter 9 排序

关键字：是数据元素中的某个数据项。如果某个数据项可以唯一地确定一个数据元素，就将其称为主关键字；否则称为次关键字。

排序算法的稳定性：如果在待排序的记录序列中有多个数据元素的关键字值相同，经过排序后这些数据元素的相对次序仍然不变，则称这种排序算法是稳定的。

## 插入排序

### 直接插入排序

![insertsort](resources/insertsort.png)

时间复杂度：$O(n^2)$。

### 希尔排序

![shellsort](resources/shellsort.gif)

## 交换排序

### 冒泡排序

![bubblesort](resources/bubblesort.gif)

时间复杂度：在最好和最坏情况下的时间复杂度都是 $O(n^2)$。

### 快速排序

步骤：

1. 初始化指针与枢轴，选数组第一个元素作为枢轴 pivot，左指针 i 从左端开始，右指针 j 从右端开始
2. 先移动右指针 j，向左找第一个小于 pivot 的元素；再移动左指针 i，向右找第一个大于 pivot 的元素
   - 当 i 指向的元素小于 j 指向的元素时，交换两个元素的位置，然后继续重复步骤 2
   - 当 i 指向的元素大于等于 j 指向的元素时停止扫描，此时 j 指向的位置就是枢轴的最终位置，交换枢轴和 j 的位置
3. 此时左区域 $[left, j-1]$ 和右区域 $[j+1, right]$ 分别再次进行快速排序

![Quicksort-example](resources/Quicksort-example.gif)

时间复杂度：$O(n\log_2n)$。

特点：

- 快速排序的递归次数和初始数列本身的顺序有关

## 选择排序

### 简单选择排序

步骤：

- 第 $i$ 趟简单选择排序是指通过 $n-i$ 次关键字的比较，从 $n-i+1$ 个记录中选出关键字最小的记录，并与第 $i$ 个记录进行交换

![selectionsort](resources/selectionsort.gif)

### 堆排序

大顶堆：大顶堆满足如下要求，

- 大顶堆是完全二叉树结构
- 父节点大于子节点

小顶堆：小顶堆满足如下要求，

- 小顶堆是完全二叉树结构
- 父节点小于子节点

![Heap_sort_example](/Users/yzhbradoodrrpurp/Desktop/DataStructure/Notes/resources/Heap_sort_example.gif)

具体讲解看 YouTube：

<iframe width="560" height="315" src="https://www.youtube.com/embed/2DmK_H7IdTo?si=psd7tbCgjCbiD_lB" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

时间复杂度：$O(n\log_2n)$。

## 归并排序

![combinationsort](resources/combinationsort.png)

时间复杂度：$O(n\log_2n)$

## 基数排序

### 多关键字排序

分为：

- 最高位优先法 MSD
- 最低位优先法 LSD

![lsd](resources/lsd.png)

### 链式基数排序

![linkedsort1](resources/linkedsort1.png)

![linkedsort2](resources/linkedsort2.png)
