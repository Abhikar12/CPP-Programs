/*
Title  : Program to implement Hash Table Using Linear Probing with and Without Replacement.
*/

#include <iostream>
#include <string.h>
using namespace std;
int MAX;
class hashing
{
  struct student
  {
    char name[20];
    long mobile;
    int link;
    student()
    {
      strcpy(name, "\0");
      mobile = link = -1;
    }
    void accept()
    {
      cout << "\nEnter name : ";
      cin >> name;
      cout << "Enter mobile number : ";
      cin >> mobile;
    }
    void display()
    {
      cout << name << "\t" << mobile << "\t" << link;
    }
  } * hashtable;

public:
  hashing()
  {
    hashtable = new student[MAX];
    for (int i = 0; i < MAX; i++)
    {
      hashtable[i].mobile = -1;
      hashtable[i].link = -1;
    }
  }
  int hash(long key)
  {
    int sum = 0;
    for (; key > 0; key = key / 10)
      sum += key % 10;
    return (sum % MAX);
  }
  int empty(int loc)
  {
    int i = loc;
    do
    {
      i++;
      i = i % MAX;
    } while (hashtable[i].mobile != -1 && i != loc);
    return i;
  }
  void chaining_wo_replacement()
  {
    int i = 0, loc = -1, pos = -1, flag = 0;
    char ans;
    student s;
    s.accept();
    loc = hash(s.mobile);
    if (hashtable[loc].mobile == -1)
      hashtable[loc] = s;
    else
    {
      pos = empty(loc);
      if (pos == loc)
        cout << "Hash table full\n";
      else
      {
        if (hash(hashtable[loc].mobile) == hash(s.mobile))
        {
          i = loc;
          while (hashtable[i].link != -1)
            i = hashtable[i].link;
          hashtable[pos] = s;
          hashtable[i].link = pos;
        }
        else
        {
          for (i = loc + 1; (i % MAX) != loc; i++)
          {
            if (i == MAX)
              i = 0;
            if (hash(hashtable[i].mobile) == hash(s.mobile))
            {
              flag = 1;
              break;
            }
          }
          if (flag != 1)
            hashtable[pos] = s;
          else
          {
            while (hashtable[i].link != -1)
              i = hashtable[i].link;
            hashtable[pos] = s;
            hashtable[i].link = pos;
          }
        }
      }
    }
    display();
  }
  void chaining_w_replacement()
  {
    int i = 0, loc = -1, pos = -1, flag = 0;
    char ans;
    student s;
    s.accept();
    loc = hash(s.mobile);
    if (hashtable[loc].mobile == -1)
      hashtable[loc] = s;
    else
    {
      pos = empty(loc);
      if (pos == loc)
        cout << "Hash table full\n";
      else
      {
        if (hash(hashtable[loc].mobile) == hash(s.mobile))
        {
          i = loc;
          while (hashtable[i].link != -1)
            i = hashtable[i].link;
          hashtable[pos] = s;
          hashtable[i].link = pos;
        }
        else
        {
          int j;
          i = hash(hashtable[loc].mobile);
          while (i != loc)
          {
            j = i;
            i = hashtable[i].link;
          }
          hashtable[pos] = hashtable[loc];
          hashtable[j].link = pos;
          hashtable[loc] = s;
        }
      }
    }
    display();
  }
  void display()
  {
    cout << "Hash key\tname\tmobile\tlink:";
    for (int i = 0; i < MAX; i++)
    {
      cout << endl
           << i << " ";
      hashtable[i].display();
    }
  }
};
int main()
{
  for (int ch = 0, n = 0; ch < 3;)
  {
    cout << "\n1.Chaining without replacement \n2.Chaining with replacement \n3.Exit: ";
    cin >> ch;
    if (ch == 3)
      continue;
    cout << "Enter size of table: ";
    cin >> MAX;
    hashing h;
    cout << "Enter the number of records: ";
    cin >> n;
    for (int i = 0; i < n; i++)
      if (ch == 1)
        h.chaining_wo_replacement();
      else if (ch == 2)
        h.chaining_w_replacement();
  }
}