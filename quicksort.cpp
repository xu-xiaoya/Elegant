#include<bits/stdc++.h>
using namespace std;
int a[10];
void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}
int partition(int a[], int left, int right) {
  int begin = left;
  int end = right;
  int p = a[left];
  while (begin < end) {
    while (begin < end && a[end] >= p) end--;
    while (begin < end && a[begin] <= p) begin++;
    swap(a, begin, end);
  }
  // 遍历完整个数组后，begin的位置是小于pivot的最后一个数字，将其与left（基准值）的值交换
  // 此时begin左边的都是小于基准值的数字，右边都是大于基准值的数字，成功将数字分割
  swap(a, begin, left);
  return begin;
}
void quicksort(int a[], int left, int right) {
  if (left >= right) {//数组长度小于1时return 
    return;
  }
  int pindex = partition(a, left, right);//获取主元下标
  
  /*递归方法，用partition将数组分为左右俩个小数组，用同样的方法将小数组分割，
  直至小数组元素个数小于等于1*/
  quicksort(a, left, pindex-1);
  quicksort(a, pindex+1, right); 
}

int main() {
  
  for (int i = 0; i < 10; i++) {
    a[i] = rand()%100;
  }
  cout << "原数组：";
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  quicksort(a, 0, 9);
  cout << "排序后数组："; 
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
