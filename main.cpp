#include<iomanip>
#include <sstream>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <list>
#include <queue>
#include "QSInterface.cpp"
using namespace std;

int main()
{
    cout << "I am happy!!!!!\n";
   
    QuickSort task1("file1.txt");
    task1.taskInstruction();
    
    
    
   QuickSort task2("file2.txt");
   task2.taskInstruction();
    
    
    
   QuickSort task3("file3.txt");
    task3.taskInstruction();
    
    
   QuickSort task4("file4.txt");
    task4.taskInstruction();
    
    QuickSort task5("file5.txt");
    task5.taskInstruction();
    
}
