/*
Title  : Program to implement Hash Table Using Linear Probing Without Replacement.
*/

#include <iostream>
using namespace std;
#define MAX 10
#define SIZE 10

struct hashtable
{
  int chain;
  long key;
  string name;

} s[MAX];

class hasht
{
public:
  int hash(int telno);
};

int hasht::hash(int telno)
{
  int h;
  h = telno % MAX;
  return h;
}

int main()
{
  int i, flag1 = 0, ch, ch1, no1, h, c, index, k, temp, ch3;
  int data[SIZE], flag[SIZE], chain[SIZE], j, x;
  string sname;
  char name1[SIZE];

  hasht t;
  for (i = 0; i < MAX; i++)
  {
    s[i].key = -1;
    s[i].chain = -1;
    s[i].name = '-';
  }

  do
  {
    for (j = 0; j < MAX; j++)
    {
      if (s[j].key == -1)
        break;
    }

    if (j == MAX)
    {
      cout << "Hash Table is Full";
      break;
    }

    cout << "Enter The Name -->> ";
    cin >> sname;

    cout << "Enter The Age -->> ";
    cin >> no1;

    h = t.hash(no1);
    c = -1;
    index = h;

    do
    {
      if (s[h].key == -1)
      {
        flag1 = 1;
        s[h].key = no1;
        s[h].name = sname;
        if (c != -1)
          s[c].chain = h;
      }

      else if (t.hash(s[h].key) == index)
        c = h;
      h = t.hash(h + 1);

    } while (flag1 == 0 && h < MAX);

    flag1 = 0;
    cout << "\nINDEX"
         << "\t"
         << "AGE"
         << "\t"
         << "NAME"
         << "\t"
         << "CHAIN"
         << "\t" << endl;
    for (i = 0; i < MAX; i++)
      cout << i << "\t" << s[i].key << "\t\t" << s[i].name << "\t" << s[i].chain << "\n";

    cout << "__________________________________________________________________________" << endl;

    cout << "Do you wish to continue? Press(1/2)  " << endl;
    cin >> ch;
  } while (ch == 1);
  return 0;
}

/* OutPut -->>

Enter The Name -->> Abhi
Enter The Age -->> 31

INDEX   AGE     NAME     CHAIN
0       -1        -       -1
1       31        Abhi    -1
2       -1        -       -1
3       -1        -       -1
4       -1        -       -1
5       -1        -       -1
6       -1        -       -1
7       -1        -       -1
8       -1        -       -1
9       -1        -       -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> Abhishek
Enter The Age -->> 21

INDEX   AGE       NAME      CHAIN
0       -1        -          -1
1       31        Abhi        2
2       21        Abhishek   -1
3       -1        -          -1
4       -1        -          -1
5       -1        -          -1
6       -1        -          -1
7       -1        -          -1
8       -1        -          -1
9       -1        -          -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> Kabhi
Enter The Age -->> 02

INDEX   AGE        NAME        CHAIN
0       -1         -            -1
1       31         Abhi         2
2       21         Abhishek     -1
3       2          Kabhi        -1
4       -1         -            -1
5       -1         -            -1
6       -1         -            -1
7       -1         -            -1
8       -1         -            -1
9       -1         -            -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> Meinbhi
Enter The Age -->> 55

INDEX   AGE     NAME           CHAIN
0       -1       -              -1
1       31       Abhi            2
2       21       Abhishek       -1
3       2        Kabhi          -1
4       -1       -              -1
5       55       Meinbhi        -1
6       -1       -              -1
7       -1       -              -1
8       -1       -              -1
9       -1       -              -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> Lazy
Enter The Age -->> 5

INDEX   AGE     NAME            CHAIN
0       -1      -               -1
1       31      Abhi            2
2       21      Abhishek        -1
3       2       Kabhi           -1
4       -1      -               -1
5       55      Meinbhi         6
6       5       Lazy            -1
7       -1      -               -1
8       -1      -               -1
9       -1      -               -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> tubhi
Enter The Age -->> 98

INDEX   AGE     NAME            CHAIN
0       -1       -                 -1
1       31       Abhi              2
2       21       Abhishek        -1
3       2        Kabhi             -1
4       -1       -                 -1
5       55       Meinbhi           6
6       5        Lazy              -1
7       -1       -                 -1
8       98       tubhi             -1
9       -1       -                 -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> yehbhi
Enter The Age -->> 8

INDEX   AGE     NAME        CHAIN
0       -1       -            -1
1       31       Abhi         2
2       21       Abhishek     -1
3       2        Kabhi        -1
4       -1       -            -1
5       55       Meinbhi      6
6       5        Lazy         -1
7       -1       -            -1
8       98       tubhi        9
9       8        yehbhi       -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> kuchbhi
Enter The Age -->> 84

INDEX   AGE       NAME      CHAIN
0       -1          -        -1
1       31        Abhi        2
2       21        Abhishek   -1
3       2         Kabhi      -1
4       84        kuchbhi    -1
5       55        Meinbhi     6
6       5         Lazy       -1
7       -1           -       -1
8       98        tubhi       9
9       8         yehbhi     -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)
1
Enter The Name -->> aapbhi
Enter The Age -->> 4

INDEX   AGE     NAME      CHAIN
0       -1         -       -1
1       31      Abhi        2
2       21      Abhishek   -1
3       2       Kabhi      -1
4       84      kuchbhi     7
5       55      Meinbhi     6
6       5       Lazy       -1
7       4       aapbhi     -1
8       98      tubhi       9
9       8       yehbhi     -1
__________________________________________________________________________
Do you wish to continue? Press(1/2)

*/