/*
Title : Program in C++ to implement threaded Binary Tree
*/

#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;
class node
{
public:
  int key;
  node *left, *right;
  bool lthread, rthread;
};

class TBST
{
private:
  node *root;

public:
  TBST()
  {
    root = new node();
    root->right = root->left = root;
    root->lthread = true;
    root->key = MAX_VALUE;
  }
  void insert(int key)
  {
    node *p = root;
    for (;;)
    {
      if (p->key < key)
      {
        if (p->rthread)
          break;
        p = p->right;
      }
      else if (p->key > key)
      {
        if (p->lthread)
          break;
        p = p->left;
      }
      else
      {
        return;
      }
    }

    node *tmp = new node;
    tmp->key = key;
    tmp->rthread = tmp->lthread = true;

    if (p->key < key)
    {
      tmp->right = p->right;
      tmp->left = p;
      p->right = tmp;
      p->rthread = false;
    }
    else
    {
      tmp->right = p;
      tmp->left = p->left;
      p->left = tmp;
      p->lthread = false;
    }
  }

  void display()
  {
    node *tmp = root, *p;
    for (;;)
    {
      p = tmp;
      tmp = tmp->right;

      if (!p->rthread)
      {
        while (!tmp->lthread)
        {
          tmp = tmp->left;
        }
      }

      if (tmp == root)
      {
        break;
      }
      cout << tmp->key << "  ";
    }
    cout << endl;
  }

  bool search(int key)
  {
    node *tmp = root->left;
    for (;;)
    {
      if (tmp->key < key)
      {
        if (tmp->rthread)
          return false;
        tmp = tmp->right;
      }
      else if (tmp->lthread)
      {
        if (tmp->lthread)
        {
          return false;
        }
        tmp = tmp->left;
      }
      else
      {
        return true;
      }
    }
  }
};

int main()
{
  int val, k, z, g;
  TBST o;
  do
  {
    cout << "\n Which operation do you want to perform -->";
    cout << "\n\t 1. Insert \n\t 2.Display \n\t 3. Search  -->>  ";
    cin >> k;
    switch (k)
    {
    case 1:
      do
      {
        cout << "\n Enter a Value you want to insert -->> ";
        cin >> val;
        o.insert(val);
        cout << "\n Do you want to ADD--> \n\t 1. YES 2. NO -->> ";
        cin >> g;
      } while (g != 2);
      break;

    case 2:
      cout << "-----------------------* DISPLAY*------------------------------";
      cout << "\n Display --> \n\t||";
      o.display();
      cout << " ||";
      cout << "\n\n---------------------------------------------------------------";
      break;

    case 3:
      cout << "-----------------------* SEARCH *------------------------------";
      cout << "\n\n Enter Key you want to search -->> ";
      cin >> val;
      if (o.search(val) == true)
      {
        cout << "\n --> Key " << val << " is found...." << endl;
      }
      else
      {
        cout << "\n --> Key ||" << val << " ||is NOt-found !!!!!!!!!!" << endl;
      }
      cout << "\n\n---------------------------------------------------------------";
      break;
    }

    cout << "\n Do you want to contineu \n\t 1. YES 2. NO -->> ";
    cin >> z;

  } while (z != 2);

  return 0;
}

/*

 Which operation do you want to perform -->
         1. Insert
         2.Display
         3. Search  -->>  1

 Enter a Value you want to insert -->> 50

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 20

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 10

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 30

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 60

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 40

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 70

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 80

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 90

 Do you want to ADD-->
         1. YES 2. NO -->> 1

 Enter a Value you want to insert -->> 100

 Do you want to ADD-->
         1. YES 2. NO -->> 2

 Do you want to contineu
         1. YES 2. NO -->> 1

 Which operation do you want to perform -->
         1. Insert
         2.Display
         3. Search  -->>  2
-----------------------* DISPLAY*------------------------------
 Display -->
        ||10  20  30  40  50  60  70  80  90  100
 ||

---------------------------------------------------------------
 Do you want to contineu
         1. YES 2. NO -->> 1

 Which operation do you want to perform -->
         1. Insert
         2.Display
         3. Search  -->>  3
-----------------------* SEARCH *------------------------------

 Enter Key you want tot search -->> 10

 --> Key 10 is found....


---------------------------------------------------------------
 Do you want to contineu
         1. YES 2. NO -->> 1

 Which operation do you want to perform -->
         1. Insert
         2.Display
         3. Search  -->>  3
-----------------------* SEARCH *------------------------------

 Enter Key you want tot search -->> 101

 --> Key ||101 ||is NOt-found !!!!!!!!!!


---------------------------------------------------------------
 Do you want to contineu
         1. YES 2. NO -->> 2


*/