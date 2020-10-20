//
//  QSInterface.cpp
//  QuickSort
//
//  Created by apple on 12/8/19.
//  Copyright © 2019 apple. All rights reserved.
//
#include "QSInterface.h"
#include<iomanip>
#include <sstream>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <list>
#include <queue>
using namespace std;

QuickSort::QuickSort(string Filename)
{
    name = Filename;
}

void QuickSort::taskInstruction()
{
   // cout << "your are going to implement: " << name << endl;
    string instruction;
    ifstream openFile;  // copy is ifstream
    openFile.open(name);
    
    if(openFile.is_open())
    {
        //cout << "Scucessfully opened the file: " << name << endl;
    }
    
    ofstream outputFile;
    if(name == "file1.txt")
    {
        outputFile.open("out_file1.txt");
    }
    
    if(name == "file2.txt")
    {
        outputFile.open("out_file2.txt");
    }
    
    if(name == "file3.txt")
    {
        outputFile.open("out_file3.txt");
    }
    
    if(name == "file4.txt")
    {
        outputFile.open("out_file4.txt");
    }
    
    if(name == "file5.txt")
    {
        outputFile.open("out_file5.txt");
    }
    
    
    
    while(!openFile.eof())
    {
        openFile >> instruction;
         
        if(!openFile.fail())
        {
            //cout << instruction << endl;
            
            if(instruction == "createArray")
            {
                int numberOfArray;
                openFile >> numberOfArray;
                maxSize = numberOfArray;
                currentIndex = -1;
                outputFile << instruction << " " << numberOfArray << " True" << endl;
                
                
               
                //cout << "******** " << numberOfArray << " *******\n";
            }
            
            if(instruction == "partition")
            {
                int first;
                int last;
                int pivot;
                
                openFile >> first;
                openFile >> last;
                openFile >> pivot;
            
                int returnValue;
                
                if(first < last && pivot >= first && pivot <= last && first>=0 && last >= 0 && last <= currentIndex && currentIndex >=0)    // Okay to
                {
                returnValue = partition( first, last,pivot);
                outputFile << instruction << " " << first << " " << last << " " << pivot << " " << returnValue << endl;
                }
                
                else  // something out of range
                {
                    returnValue = -1;
                    outputFile << instruction << " " << first << " " << last << " " << pivot << " " << returnValue << endl;
                }
            }
            
            
            if(instruction == "medianOfThree")
            {
                int first ;
                int last ;
                int medium;
               openFile >> first;
            openFile >> last;
                
               
                
               if(first < last && first>=0 && last >= 0 && last <= currentIndex && currentIndex >=0)
                {
                    medium = medianOfThree(first, last);
                }
                
                else
                {
                   medium = -1;
                }
                
                outputFile << instruction << " " << first << " " << last << " " << medium << endl; 
                
                
                
            }
            
            if(instruction == "addToArray")
            {
                int numberToAdd;
                openFile >> numberToAdd;
                if(maxSize > 0)
                {
                if(currentIndex + 1 < maxSize) /// current index is the last index of an array;;;;
                {
                    // currentIndex++;
    
                    
                    currentIndex++;
                    
                array[currentIndex] = numberToAdd;
             
                    outputFile << instruction << " " << numberToAdd << " True" << endl;
                }
                else
                {
                     outputFile << instruction << " " << numberToAdd << " False" << endl;
                }
                }
               
                
            }
            
            if(instruction == "getArray")
            {
                if(currentIndex != -1)
                {
                    outputFile << instruction << endl;
                    outputFile << " " ;
                for(int i = 0 ; i < currentIndex+1 ; i++)
                {
                    if( i != currentIndex)
                    {
                    outputFile <<array[i] << ",";
                    }
                    else
                    {
                    outputFile <<array[i] << endl;
                     }
                }
                }
                    
                else
                {
                    outputFile << instruction  << endl <<" " <<endl;
                    
                }
            }
            
            if(instruction == "clear")
            {
                maxSize = 0 ;
                currentIndex = -1;
                outputFile << "clear " << endl;
            }
            
             if(instruction == "sortAll")
             {
                 outputFile <<  instruction << endl;
                 sortAll(0, currentIndex);
             }
            
            if(instruction == "getSize")
            {
                if(currentIndex != -1)
                {
                    int size = currentIndex;
                    size++;
                outputFile <<  instruction << " " << size << endl ;
               
                }
                else
                {
                    outputFile <<  instruction << " " << 0 << endl;
                }
            }
            
            
        }
    }  /// while loop
    
    openFile.close();
    outputFile.close();
}



int QuickSort::medianOfThree(int first , int last)
{
    int medium;
       medium = (first + last) / 2 ;
   // cout << " medium is " << medium << endl ;
    
       bubbleSort(first, medium, last);
       
       return medium;
}

int QuickSort::partition(int m, int n , int pivot)
{
    int temp = array[pivot];
        array[pivot]  = array[m];
       array[m] = temp;
       //cout << "** array pipot is: " << array[m] << "  ****\n";
      // cout << "** array middle is: " << array[pivot] << "  ****\n";./
       int up = m + 1;
       int down = n;
       int size = n + 1;
       cout << "pivot is " << array[m] << " ***\n";
      
     
       
       while(up < down)
       {
           while(array[up] <= array[m] && up <= n)
           {
               up++;
           }
           cout << "upIndex is " << up << " ***\n";
           // cout << "array dow=n is " << array[down] << " ***\n";
           cout << " downIndex is " << down << " ***\n\n\n";
           
           while(array[down] >array[m] && down>= m )
           {
               //cout << "some thing wrong\n";
               down--;
           }
           cout << "upIndex is " << up << " ***\n";
            cout << "downIndex is " << down << " ***\n\n\n";
           
           if(down > up )
           {
           temp = array[up];
           array[up] = array[down];
           array[down] = temp;
         //  up++;
          // down--;
                //printArray[array, 5];
           }
          
           if(down <= up)
           {
               temp = array[m];
               array[m] = array[down];
               array[down] = temp;
           }
       }
           
       //cout << "Hi\n";
       return down;
}

void QuickSort:: sortAll(int p , int q )
{
   if (p < q) {
       int a = medianOfThree(p, q);
   int r = partition(p, q,a);
   sortAll( p, r - 1);
   sortAll( r + 1, q);

}
}
