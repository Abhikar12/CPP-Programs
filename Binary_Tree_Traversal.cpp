/*
Name : Abhishek Laxman Kusalkar
Title : Program to implement Binary Tree Traversals in Recursive and Non Recursive way.
*/

// Program -

#include <iostream>
using namespace std;
struct BinaryTree
{
  BinaryTree *left;
  BinaryTree *right;
  int data;
};
class BT
{
  BinaryTree *root, *newnode, *temp, *parent, *stack[20];
  int top;

public:
  BT() // Constuctor
  {
    root = NULL;
    top = -1;
  }
  int isempty();
  int isfull();
  void push(BinaryTree *);
  BinaryTree *pop();
  void create();
  void display();
  void insert(BinaryTree *, BinaryTree *);
  void inorder(BinaryTree *);
  void preorder(BinaryTree *);
  void postorder(BinaryTree *);
  void inorder_nonrec(BinaryTree *);
  void preorder_nonrec(BinaryTree *);
  void postorder_nonrec(BinaryTree *);
};
int BT::isempty()
{
  if (top == -1)
    return 1;
  return 0;
}
int BT::isfull()
{
  if (top == 19)
    return 1;
  return 0;
}
void BT::push(BinaryTree *d)
{
  if (!isfull())
    stack[++top] = d;
}
BinaryTree *BT::pop()
{
  BinaryTree *temp = stack[top];
  top--;
  return temp;
}
void BT::inorder_nonrec(BinaryTree *root)
{
  BT s;
  while (!s.isempty() || root != NULL)
  {
    while (root != NULL)
    {
      s.push(root);
      root = root->left;
    }
    root = s.pop();
    cout << "  " << root->data << "     ";
    root = root->right;
  }
}
void BT::preorder_nonrec(BinaryTree *root)
{
  BT s;
  while (!s.isempty() || root != NULL)
  {
    while (root != NULL)
    {
      cout << " " << root->data << " ";
      s.push(root);
      root = root->left;
    }
    root = s.pop();
    root = root->right;
  }
}
void BT::postorder_nonrec(BinaryTree *root)
{
  BT s;
  int i = 0;
  int str[20];
  while (!s.isempty() || root != NULL)
  {
    while (root != NULL)
    {
      str[i++] = root->data;
      s.push(root);
      root = root->right;
    }
    root = s.pop();
    root = root->left;
  }
  while (--i >= 0)
    cout << str[i] << "    ";
}
void BT::create()
{
  newnode = new BinaryTree; // dynamically creating new BinaryTree
  newnode->left = NULL;     // intialiing the tree
  newnode->right = NULL;
  cout << "Enter a element::";
  cin >> newnode->data;
  if (root == NULL)
  {
    root = newnode;
    cout << "Root is Created";
  }
  else
  {
    insert(root, newnode);
  }
}
void BT::insert(BinaryTree *root, BinaryTree *newnode)
{
  char choice;

  cout << "\t 	" << root->data;
  cout << "\n\t  /";
  cout << "		\\";
  cout << "\n\tLeft";
  cout << "		  Right\n\n";
  cout << "\nEnter Your Choice Here -->> ";
  cin >> choice;

  if (choice == 'L' || choice == 'l')
  {
    if (root->left == NULL)
    {
      root->left = newnode;
    }
    else
    {
      insert(root->left, newnode);
    }
  }
  else
  {
    if (root->right == NULL)
    {
      root->right = newnode;
    }
    else
    {
      insert(root->right, newnode);
    }
  }
}

void BT::display() // to display the BT
{
  int t, m;
  if (root == NULL)
  {
    cout << "\nTree Is Empty !!";
  }
  else
  {
    do
    {
      cout << "Which Traversal U want ? \n======RECURSIVE======\n1.Inorder \n2.Preorder \n3.Postorder\n====NON RECURSIVE====\n4.Inorder \n5.Preorder \n6.Postorder";
      cin >> t;
      switch (t)
      {
      case 1:
        cout << "\nInorder By Recursive";
        inorder(root);
        break;
      case 2:
        cout << "\npreorder By Recursive";
        preorder(root);
        break;
      case 3:
        cout << "\npostorder By Recursive";
        postorder(root);
        break;
      case 4:
        cout << "\nInorder By Non Recursive";
        inorder_nonrec(root);
        break;
      case 5:
        cout << "\npreorder By Non Recursive";
        preorder_nonrec(root);
        break;
      case 6:
        cout << "\npostorder By Non Recursive";
        postorder_nonrec(root);
        break;
      }

      cout << "\nDo U want another traversal\n1.YES\n2.NO";
      cin >> m;
    } while (m != 2);
  }
}
void BT::inorder(BinaryTree *ptr) // inorder by recursive method
{
  if (ptr != NULL)
  {
    inorder(ptr->left);
    cout << " " << ptr->data << "  ";
    inorder(ptr->right);
  }
}
void BT ::postorder(BinaryTree *ptr) // postorder by recursive
{
  if (ptr != NULL)
  {
    postorder(ptr->left);
    postorder(ptr->right);
    cout << " " << ptr->data << " ";
  }
}

void BT::preorder(BinaryTree *ptr) // preorder by recursive
{
  if (ptr != NULL)
  {
    cout << " " << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
  }
}
int main()
{
  int ch1, ch2, o;
  BT obj;
  do
  {
    cout << "\nWhich operation do you want perform \n\t 1.Insert Element :: \n\t 2.Display Tree::";
    cin >> ch1;
    switch (ch1)
    {
    case 1:
      do
      {

        obj.create();
        cout << "\n\nDo you want to Add more BinaryTree\n\t 1. Yes 2. No ::";
        cin >> o;

      } while (o != 2);
      break;

    case 2:

      obj.display();
      break;
    }
    cout << "\nDo you want to continue \n\t 1.Yes 2.No ::";
    cin >> ch2;
  } while (ch2 != 2);
  return 0;
}
/* OutPut -
Which operation do you want perform
         1.Insert Element ::
         2.Display Tree::1
Enter a element::15
Root is Created

Do you want to Add more BinaryTree
         1. Yes 2. No ::1
Enter a element::10
                15
          /             \
        Left              Right


Enter Your Choice Here -->> l


Do you want to Add more BinaryTree
         1. Yes 2. No ::1
Enter a element::8
                15
          /             \
        Left              Right


Enter Your Choice Here -->> l
                10
          /             \
        Left              Right


Enter Your Choice Here -->> l


Do you want to Add more BinaryTree
         1. Yes 2. No ::1
Enter a element::12
                15
          /             \
        Left              Right


Enter Your Choice Here -->> l
                10
          /             \
        Left              Right


Enter Your Choice Here -->> r


Do you want to Add more BinaryTree
         1. Yes 2. No ::1
Enter a element::19
                15
          /             \
        Left              Right


Enter Your Choice Here -->> r


Do you want to Add more BinaryTree
         1. Yes 2. No ::1
Enter a element::18
                15
          /             \
        Left              Right


Enter Your Choice Here -->> r
                19
          /             \
        Left              Right


Enter Your Choice Here -->> l


Do you want to Add more BinaryTree
         1. Yes 2. No ::1
Enter a element::30
                15
          /             \
        Left              Right


Enter Your Choice Here -->> r
                19
          /             \
        Left              Right


Enter Your Choice Here -->> r


Do you want to Add more BinaryTree
         1. Yes 2. No ::2

Do you want to continue
         1.Yes 2.No ::1

Which operation do you want perform
         1.Insert Element ::
         2.Display Tree::2
Which Traversal U want ?
======RECURSIVE======
1.Inorder
2.Preorder
3.Postorder
====NON RECURSIVE====
4.Inorder
5.Preorder
6.Postorder1

Inorder By Recursive 8   10   12   15   18   19   30
Do U want another traversal
1.YES
2.NO1
Which Traversal U want ?
======RECURSIVE======
1.Inorder
2.Preorder
3.Postorder
====NON RECURSIVE====
4.Inorder
5.Preorder
6.Postorder2

preorder By Recursive 15  10  8  12  19  18  30
Do U want another traversal
1.YES
2.NO1
Which Traversal U want ?
======RECURSIVE======
1.Inorder
2.Preorder
3.Postorder
====NON RECURSIVE====
4.Inorder
5.Preorder
6.Postorder3

postorder By Recursive 8  12  10  18  30  19  15
Do U want another traversal
1.YES
2.NO1
Which Traversal U want ?
======RECURSIVE======
1.Inorder
2.Preorder
3.Postorder
====NON RECURSIVE====
4.Inorder
5.Preorder
6.Postorder4

Inorder By Non Recursive  8       10       12       15       18       19       30
Do U want another traversal
1.YES
2.NO1
Which Traversal U want ?
======RECURSIVE======
1.Inorder
2.Preorder
3.Postorder
====NON RECURSIVE====
4.Inorder
5.Preorder
6.Postorder5

preorder By Non Recursive 15  10  8  12  19  18  30
Do U want another traversal
1.YES
2.NO1
Which Traversal U want ?
======RECURSIVE======
1.Inorder
2.Preorder
3.Postorder
====NON RECURSIVE====
4.Inorder
5.Preorder
6.Postorder6

postorder By Non Recursive8    12    10    18    30    19    15
Do U want another traversal
1.YES
2.NO2

Do you want to continue
         1.Yes 2.No ::2

*/