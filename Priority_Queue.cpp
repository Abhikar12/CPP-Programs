/*
Title  : Program to implement Priority Queue using Heap Data Structure.
*/

#include <iostream>
using namespace std;
#define MAX 100

int H[50];
int val = -1;

// parent node of a given node
int parent(int i)
{

  return ((i - 1) / 2);
}

// left child
int leftChild(int i)
{

  return ((2 * i) + 1);
}

// right child
int rightChild(int i)
{

  return ((2 * i) + 2);
}

// Function to shift up
void shiftUp(int i)
{
  while (i > 0 && H[parent(i)] < H[i])
  {

    swap(H[parent(i)], H[i]);

    i = parent(i);
  }
}

// Function to shift Down
void shiftDown(int i)
{
  int maxIndex = i;

  int l = leftChild(i);

  if (l <= val && H[l] > H[maxIndex])
  {
    maxIndex = l;
  }

  int r = rightChild(i);

  if (r <= val && H[r] > H[maxIndex])
  {
    maxIndex = r;
  }

  if (i != maxIndex)
  {
    swap(H[i], H[maxIndex]);
    shiftDown(maxIndex);
  }
}

// Function to insert
void insert(int p)
{
  val = val + 1;
  H[val] = p;

  shiftUp(val);
}

// Function to extract Maximum Value
int extractMax()
{
  int result = H[0];

  H[0] = H[val];
  val = val - 1;

  shiftDown(0);
  return result;
}

// Function to change the priority
void changePriority(int i, int p)
{
  int oldp = H[i];
  H[i] = p;

  if (p > oldp)
  {
    shiftUp(i);
  }
  else
  {
    shiftDown(i);
  }
}

// Function to get max value
int getMax()
{
  return H[0];
}

// Function to remove the element
void remove(int i)
{
  H[i] = getMax() + 1;

  shiftUp(i);

  extractMax();
}

void swap(int *p, int *q)
{
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}

int main()
{

  int choice, p, i = 0;

  cout << "\n\n<<---Insert Elements Into Heap--->>\n";
  do
  {
    cout << "\nEnter The Number -->>    ";
    cin >> p;
    insert(p);
    cout << "\n\nDo You Want To Add More Elements ->> 1.Yes 2.No ";
    cout << "\nEnter Your Choice Here -->>";
    cin >> choice;
  } while (choice != 2);

  // Priority queue before extracting max
  cout << "\n\nPriority Queue -->> ";
  while (i <= val)
  {
    cout << H[i] << " ";
    i++;
  }

  // Node with maximum priority
  cout << "\n\nNode With Maximum Priority -->> "
       << extractMax() << "\n";

  // Priority queue after extracting max
  cout << "\n\nPriority Queue After Extracting Maximum -->> ";
  int j = 0;
  while (j <= val)
  {
    cout << H[j] << " ";
    j++;
  }

  // Change the priority of element

  cout << "\n\nEnter Number To change Priority : ";
  cin >> p;
  cout << "\n<<--x-- Index Starts From 0 --x-->> ";
  cout << "\n\nEnter Index Where You Want To Insert -->> ";
  cin >> i;
  changePriority(i, p);
  cout << "\n\nPriority Queue After Priority Change -->> ";

  int k = 0;
  while (k <= val)
  {
    cout << H[k] << " ";
    k++;
  }

  // Remove element at index
  cout << "\n\nEnter Number Index To Remove -->> ";
  cin >> i;
  remove(i);

  cout << "\n\nPriority Queue After Removing The Element -->> ";
  int l = 0;
  while (l <= val)
  {
    cout << H[l] << " ";
    l++;
  }
  cout << "\n";

  return 0;
}

/* OutPut -

<<---Insert Elements Into Heap--->>

Enter The Number -->>    45


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    20


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    14


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    12


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    31


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    7


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    11


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    13


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>1

Enter The Number -->>    7


Do You Want To Add More Elements ->> 1.Yes 2.No
Enter Your Choice Here -->>2


Priority Queue -->> 45 31 14 13 20 7 11 12 7

Node With Maximum Priority -->> 45


Priority Queue After Extracting Maximum -->> 31   20   14   13   7   7   11   12

Enter Number To change Priority : 49

<<--x-- Index Starts From 0 --x-->>

Enter Index Where You Want To Insert -->> 2


Priority Queue After Priority Change -->> 49 20 31 13 7 7 11 12

Enter Number Index To Remove -->> 3


Priority Queue After Removing The Element -->> 49 20 31 12 7 7 11

*/