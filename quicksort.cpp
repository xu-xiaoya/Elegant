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
  // ���������������begin��λ����С��pivot�����һ�����֣�������left����׼ֵ����ֵ����
  // ��ʱbegin��ߵĶ���С�ڻ�׼ֵ�����֣��ұ߶��Ǵ��ڻ�׼ֵ�����֣��ɹ������ַָ�
  swap(a, begin, left);
  return begin;
}
void quicksort(int a[], int left, int right) {
  if (left >= right) {//���鳤��С��1ʱreturn 
    return;
  }
  int pindex = partition(a, left, right);//��ȡ��Ԫ�±�
  
  /*�ݹ鷽������partition�������Ϊ��������С���飬��ͬ���ķ�����С����ָ
  ֱ��С����Ԫ�ظ���С�ڵ���1*/
  quicksort(a, left, pindex-1);
  quicksort(a, pindex+1, right); 
}

int main() {
  
  for (int i = 0; i < 10; i++) {
    a[i] = rand()%100;
  }
  cout << "ԭ���飺";
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  quicksort(a, 0, 9);
  cout << "��������飺"; 
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
//this is a test
111