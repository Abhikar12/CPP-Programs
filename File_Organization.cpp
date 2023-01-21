/*

Title  : Program in C++ to implement file organizations.

*/

//Program 

#include <iostream>
#include <fstream>
using namespace std;
struct student
{
  int rollno;
  char name[50];
  float per;
} s;

int main()
{
  int ch, c, rno, flag;
  ofstream outf, outf1;
  outf.open("stud.txt");
  ifstream inf;
  do
  {
    cout << "\n1.ADD RECORD\n2.DISPLAY\n3.DELETE RECORD\n4.MODIFY RECORD\n";
    cout << "\nEnter your choice:";
    cin >> ch;
    switch (ch)
    {
    case 1:
      do
      {
        cout << "\n";
        cout << "\nEnter the RollNo,:";
        cin >> s.rollno;
        cout << "\nEnter theName";
        cin >> s.name;
        cout << "\nEnter the Percentage:";
        cin >> s.per;
        outf << "\t" << s.rollno;
        outf << "\t" << s.name;
        outf << "\t" << s.per;
        cout << "\nDo you want to continue :";
        cin >> c;
      } while (c == 1);
      cout << "\nRecord added sucessfully:";
      outf.close();
      break;
    case 2:
      inf.open("stud.txt");
      while (!inf.eof())
      {
        inf >> s.rollno;
        inf >> s.name;
        inf >> s.per;
        cout << "\nRoll NO is:" << s.rollno;
        cout << "\nName: is:" << s.name;
        cout << "\nPercentage is:" << s.per;
      }
      inf.close();
      break;
    case 3:
      outf1.open("student.txt");
      inf.open("stud.txt");
      cout << "\nEnter the roll no which you want to delete:";
      cin >> rno;
      flag = 0;
      while (!inf.eof())
      {
        inf >> s.rollno;
        inf >> s.name;
        inf >> s.per;
        if (rno == s.rollno)
        {
          flag = 1;
          cout << "\nRecord deleted:";
        }
        else if (rno != s.rollno)
        {
          outf1 << "\t" << s.rollno;
          outf1 << "\t" << s.name;
          outf1 << "\t" << s.per;
        }
      }
      if (flag == 0)
      {
        cout << "Record is not present";
      }
      inf.close();
      outf1.close();
      remove("stud.txt");
      rename("student.txt", "stud.txt");
      break;
    case 4:
      outf1.open("student.txt");
      inf.open("stud.txt");
      cout << "\nEnter the roll no which you want to modify:";
      cin >> rno;
      flag = 0;
      while (!inf.eof())
      {
        inf >> s.rollno;
        inf >> s.name;
        inf >> s.per;
        if (rno == s.rollno)
        {
          cout << "\nEnter the RollNo,Name,and Percentage:";
          cin >> s.rollno >> s.name >> s.per;
          outf1 << "\t" << s.rollno;
          outf1 << "\t" << s.name;
          outf1 << "\t" << s.per;
          flag = 1;
        }
        else if (rno != s.rollno)
        {
          outf1 << "\t" << s.rollno;
          outf1 << "\t" << s.name;
          outf1 << "\t" << s.per;
        }
      }
      inf.close();
      outf1.close();
      if (flag == 0)
      {
        cout << "Record is not present";
      }
      remove("stud.txt");
      rename("student.txt", "stud.txt");
      break;
    }
    cout << "\nwant to continue:";
    cin >> c;
  } while (c == 1);
  return 0;
}
