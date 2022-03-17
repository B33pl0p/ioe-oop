/*Create class student to store Name, Age and CRN of students. Write a program to write records of N numbers of students into the
file. And your program should search complete information of students from file
according to CRN entered by user and display it */
#include <fstream>
#include <iostream>
using namespace std;
class student {
public:
  char name[20];
  char address[20];
  char section[2];
  int crn;
  void input() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter section: ";
    cin >> section;
    cout << "enter CRN  number:";
    cin >> crn;
    cout << "saved.. \n\n";
  }
  void display() {
    cout << "Name :" << name << endl
         << "Address :" << address << endl
         << "Section " << section << endl
         << "CRN " << crn << endl;
    }
};
int main() {
  fstream student_file;
  student_file.open("stdfile.txt", ios::out);
  student s[50], s1;
  int n;
  cout << "Enter the number of students :";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "student " << i + 1 << endl;
    s[i].input();
    student_file.write((char *)&s[i], sizeof(s[i]));
  }
  student_file.close();
  int crn_to_search;
  //system("clear");
  system("cls");
  cout << "enter the crn number of student to search :";
  cin >> crn_to_search;
  student_file.open("stdfile.txt", ios::in);
  cout << "the detail of student with crn matching is :" << endl;
  while (student_file.read((char *)&s1, sizeof(s1))) {
    if (crn_to_search == s1.crn) {
      s1.display();
    }
  }
}
