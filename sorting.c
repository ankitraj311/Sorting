#include<stdio.h>
#include<stdlib.h>
void bubble_sort_no_optimize();
void bubble_sort_optimize();
void bubble_sort_full_optimize();
void insertion_sort();
void selection_sort();
void merge_sort();
int  min_value();





int main()
{
  int *arr, *arr_cpy, i = 0, j = 0, no = 0, temp = 0, LOC = 0;
  printf("Enter how many numbers you want to enter in Array\n");
  scanf("%d",&no);
  arr = (int *)malloc(sizeof(int) * no);
  arr_cpy = arr;
  printf("Enter value of array\n");
  for(i=0; i<no; i++)
  {
    scanf("%d",&arr[i]);
  }

  printf("Array before sorting is\n");

  for(i=0; i<no; i++)
  {
    printf("%d ",arr[i]);
  }

  //bubble_sort_no_optimize(arr_cpy, no); 
  //bubble_sort_optimize(arr_cpy, no); 
 // bubble_sort_full_optimize(arr_cpy, no);
  //insertion_sort(arr_cpy,no);
  //selection_sort(arr_cpy, no);
   merge_sort(arr_cpy, no);
   printf("\nAfter Sorting Array is :-");

  for(i=0; i<no; i++)
  {
    printf("%d ",arr[i]);
  }
}

void bubble_sort_no_optimize(int *arr_cpy, int no)
{
  int i, j, temp;
  for(i=0; i<no; i++)
  {
    for(j=i+1; j<no; j++)
    {
      if(arr_cpy[i] > arr_cpy[j])
      {
        temp = arr_cpy[i];
        arr_cpy[i] = arr_cpy[j];
	arr_cpy[j] = temp;
      }
    }
  }
}


void bubble_sort_optimize(int *arr_cpy, int no)
{
  int i, j, temp;
  for(i=1; i<=no-1; i++)
  {
    for(j=0; j<=no-1-i; j++) // If no = 4 then in that situation we only needed j till 2
    {
      if(arr_cpy[j] > arr_cpy[j+1])
      {
        temp = arr_cpy[j];
        arr_cpy[j] = arr_cpy[j+1];
	arr_cpy[j+1] = temp;
      }
    }
  }
}


void bubble_sort_full_optimize(int *arr_cpy, int no)
{
  int i, j, temp, flag = 0;
  for(i=1; i<=no-1; i++)
  {
    flag = 0;    //Extra added to skip  rounds if array is already sorted from initial or after some time
    for(j=0; j<=no-1-i; j++) // If no = 4 then in that situation we only needed j till 2
    {
      if(arr_cpy[j] > arr_cpy[j+1])
      {
	flag = 1;
        temp = arr_cpy[j];
        arr_cpy[j] = arr_cpy[j+1];
	arr_cpy[j+1] = temp;
      }
    }
    if(flag == 0)
    {
      printf("\nI is %d",i);
      return ; //This will break the loop if array is already sorted
    }
  }
}

void insertion_sort(int *arr_cpy, int no)
{
  int i, j, temp;
  for(i = 1; i<no; i++)
  {
    temp = arr_cpy[i];
    for(j=i-1; j>=0 && arr_cpy[j]>temp; j--)
    {
      arr_cpy[j+1] = arr_cpy[j];
    }
    arr_cpy[j+1] = temp;
  }
}

int min_value(int *arr_cpy, int no, int k)
{
  int i, j = 0, min = arr_cpy[k], loc = k;
  for(i=k+1; i<=no-1; i++)
  {
    if(min > arr_cpy[i])
    {
      min = arr_cpy[i];
      loc = i;
    }
  }
  return loc;
}

void selection_sort(int *arr_cpy, int no)
{
  int  i = 0, indx = 0, k = 0, temp;
  for(i=0; i<no-1; i++)
  {
    indx = min_value(arr_cpy,no,i);
    temp = arr_cpy[i];
    arr_cpy[i] = arr_cpy[indx];
    arr_cpy[indx] = temp;
  }
}


void merge(int *A, int n1, int index1, int *B, int n2, int index2, int *C, int index)
{
  while(n1&&n2)
  {
    if(A[index1] < B[index2])
    {
      C[index] = A[index1];
      index++;
      index1++;
      n1--;
    }
    else
    {
      C[index] = B[index2];
      index++;
      index2++;
      n2--;
    }
  } //End of WHile

  while(n1)
  {
    C[index] = A[index1];
    index++;
    index1++;
    n1--;
  }
  while(n2)
  {
    C[index] = B[index2];
    index++;
    index2++;
    n2--;
  }
}

void mergepass(int *A, int N, int L, int *B)
{
  int j, LB;
  int Q,S,R;
  Q = N/(2*L); //Q is the part of array to be marged
  S = 2*L*Q;   //S is total no of Elemnts
  R = N-S;     //R Residual Element which are left pairing

  for(j=0; j<Q; j++)
  {
    LB = (2*j)*L; //Lower Band index for First array
    merge(A,L,LB,A,L,LB+L,B,LB); ///Merging to array
  }

  if(R<=L)
  {
    for(j=0; j<R; j++)
    {
      B[S+j] = A[S+j];
    }
  }
  else
  {
    merge(A,L,S,A,R-L,S+L,B,S);
  }

 }
void merge_sort(int *A, int N)
{
  int L = 1, B[11];
  while(L<N)
  {
    mergepass(A,N,L,B);
    mergepass(B,N,2*L,A);
    L=4*L;
  }
}
