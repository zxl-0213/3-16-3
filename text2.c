/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 ////向下调整
 void adJust(int* a,int n,int root)
 {
     int parent=root;
     int child=2*parent+1;
     while(child<n)
     {
         if(child+1<n&&a[child]<a[child+1])
         {
             child++;
         }
         if(a[parent]<a[child])
         {
             int temp=a[child];
             a[child]=a[parent];
             a[parent]=temp;
             parent=child;
             child=2*parent+1;
         }
         else
         {
             break;
         }
     }
 }

 int* HeapSort(int* a,int n,int root)
 {
     for(int root=(n-2)/2;root>=0;root--)
     {
         adJust(a,n,root);
     }
     int end=n-1;
     while(end>0)
     {
         int temp=a[end];
         a[end]=a[0];
         a[0]=temp;
         adJust(a,end,root);
         end--;
     }
     return a;
 }
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    return HeapSort(nums,numsSize,0);
}