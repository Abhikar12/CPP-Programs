/*
Title :Program to implement Binary tree operations.

1.Create Tree
2.Tree Traversal - Inorder, Preorder, Postorder
3.Display Leaves of Tree
4.Longest Path Of Tree

*/

// Program -

#include <iostream>
using namespace std;

struct BinaryTree
{
  int data;
  BinaryTree *left;
  BinaryTree *right;
} * newnode, *root, *ptr;

class BT
{
public:
  void create();
  void insert(BinaryTree *, BinaryTree *);
  void displayTraversal();
  void inorder(BinaryTree *);
  void preorder(BinaryTree *);
  void postorder(BinaryTree *);
  void leaf();
  void Display_Leaves(BinaryTree *temp);
  void Longest_Path();
  int depth(BinaryTree *);

  BT()
  {
    root = NULL;
  }
};

void BT::create()
{
  newnode = new BinaryTree;

  newnode->left = NULL;
  newnode->right = NULL;

  cout << "\nEnter Node Data -->>  ";
  cin >> newnode->data;

  if (root == NULL)
  {
    root = newnode;
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

void BT::displayTraversal()
{
  int choice3;

  if (root == NULL)
  {
    cout << "Tree Is Empty";
  }
  else
  {
    cout << "INORDER";
    inorder(root);
    cout << endl;
    cout << "PREORDER";
    preorder(root);
    cout << endl;
    cout << "POSTORDER";
    postorder(root);
  }
}

void BT::inorder(BinaryTree *ptr)
{

  if (ptr != NULL)
  {

    inorder(ptr->left);
    cout << "	" << ptr->data;
    inorder(ptr->right);
  }
}

void BT::preorder(BinaryTree *ptr)
{

  if (ptr != NULL)
  {
    cout << "	" << ptr->data;
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

void BT::postorder(BinaryTree *ptr)
{

  if (ptr != NULL)
  {

    postorder(ptr->left);
    postorder(ptr->right);
    cout << "	" << ptr->data;
  }
}

void BT::leaf()
{
  Display_Leaves(root);
}

void BT::Display_Leaves(BinaryTree *temp)
{
  if (root == NULL)
  {
    cout << "Tree Is Empty";
  }
  if (temp != NULL)
  {
    if ((temp->left == NULL) && (temp->right == NULL))
    {
      cout << "	" << temp->data;
    }
    else
    {
      Display_Leaves(temp->left);
      Display_Leaves(temp->right);
    }
  }
}

void BT::Longest_Path()
{
  if (root == NULL)
  {
    cout << "\nTree Is Empty";
  }
  else
  {
    int ldepth = depth(root);
    int rdepth = depth(root);
    if (ldepth > rdepth)
      cout << "\nLongest Path Of Tree	" << ldepth;
    else
      cout << "\nLongest Path Of Tree	" << rdepth;
  }
}

int BT::depth(BinaryTree *root)
{
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    int ldepth = depth(root->left);
    int rdepth = depth(root->right);

    if (ldepth > rdepth)
      return (ldepth + 1);

    else
      return (rdepth + 1);
  }
}

int main()
{
  BT B;
  int choice, choice2, choice3;

  do
  {
    cout << "\n1.Create Tree";
    cout << "\n2.Tree Traversal";
    cout << "\n3.Display Leaves of Tree ";
    cout << "\n4.Longest Path Of Tree ";
    cout << "\nEnter Your Choice Here -->>";
    cin >> choice;

    switch (choice)
    {
    case 1:
      do
      {
        B.create();
        cout << "\nDo You Want Add More Node -->>1.Yes 2.No ";
        cin >> choice3;
      } while (choice3 != 2);
      break;

    case 2:
      B.displayTraversal();
      break;

    case 3:
      B.leaf();
      break;

    case 4:
      B.Longest_Path();
      break;
    }

    cout << "\n\nEnter Your Choice Here -->>1.Yes 2.No ";
    cin >> choice2;
  } while (choice2 != 2);

  return 0;
}

/* OutPut -
1.Create Tree
2.INORDER
3.Display Leaves of Tree
4.Longest Path Of Tree
Enter Your Choice Here -->>1

Enter Node Data -->>  50

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  40
        50
      /             \
    Left              Right


Enter Your Choice Here -->> l

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  30
        50
      /             \
    Left              Right


Enter Your Choice Here -->> l
        40
      /             \
    Left              Right


Enter Your Choice Here -->> l

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  20
        50
      /             \
    Left              Right


Enter Your Choice Here -->> l
        40
      /             \
    Left              Right


Enter Your Choice Here -->> l
        30
      /             \
    Left              Right


Enter Your Choice Here -->> l

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  35
        50
      /             \
    Left              Right


Enter Your Choice Here -->> l
        40
      /             \
    Left              Right


Enter Your Choice Here -->> l
        30
      /             \
    Left              Right


Enter Your Choice Here -->> r

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  45
        50
      /             \
    Left              Right


Enter Your Choice Here -->> l
        40
      /             \
    Left              Right


Enter Your Choice Here -->> r

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  60
        50
      /             \
    Left              Right


Enter Your Choice Here -->> r

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  55
        50
      /             \
    Left              Right


Enter Your Choice Here -->> r
        60
      /             \
    Left              Right


Enter Your Choice Here -->> l

Do You Want Add More Node -->>1.Yes 2.No 1

Enter Node Data -->>  70
        50
      /             \
    Left              Right


Enter Your Choice Here -->> r
        60
      /             \
    Left              Right


Enter Your Choice Here -->> r

Do You Want Add More Node -->>1.Yes 2.No 2


Enter Your Choice Here -->>1.Yes 2.No 1

1.Create Tree
2.INORDER
3.Display Leaves of Tree
4.Longest Path Of Tree
Enter Your Choice Here -->>2
INORDER 20      30      35      40      45      50      55      60      70

Enter Your Choice Here -->>1.Yes 2.No 1

1.Create Tree
2.INORDER
3.Display Leaves of Tree
4.Longest Path Of Tree
Enter Your Choice Here -->>3
    20      35      45      55      70

Enter Your Choice Here -->>1.Yes 2.No 1

1.Create Tree
2.INORDER
3.Display Leaves of Tree
4.Longest Path Of Tree
Enter Your Choice Here -->>4

Longest Path Of Tree   4

Enter Your Choice Here -->>1.Yes 2.No 2
*/