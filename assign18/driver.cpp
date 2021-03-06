/******************************************************************************
* Program:
*    Assignment 18, Merge Sort
*    Brother Ercanbrack, CS 235
* Author:
*    Tyler Scott
* Summary:
*    This program implements a merge sort
*
*  Estimated time: 8.0hrs
*  Actual time: 4.0hrs
******************************************************************************/
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

/******************************************************************************
 *
 *****************************************************************************/
void split(list <int> &listIn, list <int> &listA, list <int> &listB)
{
   for (list <int> :: iterator it = listIn.begin(); it != listIn.end();)
   {
      do
      {
         listA.push_back(*it);
         it++;
      }while(*it >= listA.back() && it != listIn.end());

      if (it == listIn.end())
         break;
      do
      {
         listB.push_back(*it);
         it++;
      }while(*it >= listB.back() && it != listIn.end());    
   }
   listIn.erase(listIn.begin(), listIn.end());
   return;
}

/******************************************************************************
 *
 *****************************************************************************/
void merge(list <int> &listIn, list <int> &listA, list <int> &listB,
           int &numSub)
{
   list <int> :: iterator itA = listA.begin();
   list <int> :: iterator itB = listB.begin();
   numSub = 0;
   while(itA != listA.end() && itB != listB.end())
   {
//      cerr << "before do while 1\n";
      // do
      // {
      //       cerr<< "before if1\n";
     
      if (*itA < *itB)
      {
         // cerr << "in if1";
         listIn.push_back(*itA);
         // cout << *itA << " ";
         itA++;
         //  numSub++;
      }
      else// if (*itA >= *itB)
      {
//            cerr << "in else1";
         listIn.push_back(*itB);
         //          cout << *itB << "  ";
         itB++;
         //  numSub++;
      }
     
      //  numSub++;
      // 
//      }while ((/**itA < listIn.back() ||*/itA != listA.end())
      //             (/**itB < listIn.back() || */itB != listB.end()));

      
       if (*itB <= listIn.back())// && *itA >= listIn.back())
      {
         //if (*itB < listIn.back() && itA != listA.end())
         
         // do FML i hate this shiz
         //        {
            listIn.push_back(*itA);
            itA++;
//          } while(*itA >= listIn.back() && itA != listA.end());
            numSub++;
      }

       else// (*itA < listIn.back())// && *itB >= listIn.back())
      {
//      do
         //       {
            listIn.push_back(*itB);
            itB++;
            // } while(*itB >= listIn.back() && itB != listB.end());
                numSub++;
      }
      numSub++;
   }
//these are good
   
   if (itA == listA.end() && itB != listB.end())
   {
       do
       {
         listIn.push_back(*itB);
         itB++;
           }while (*itB >= listIn.back() && itB != listB.end());
      numSub++;
   }
   
   if (itB == listB.end() && itA != listA.end())
   {
      do
      {
         listIn.push_back(*itA);
         itA++;
      }while (*itA >= listIn.back() && itA != listA.end());
      numSub++;
   }
   
   listA.erase(listA.begin(), listA.end());
   listB.erase(listB.begin(), listB.end());                 
    
   return;
}

/******************************************************************************
 * 
 *****************************************************************************/
void mergeSort(list <int> &listIn)
{
   list <int> listA;
   list <int> listB;
   int count = 0; 
   do
   // for (int i = 0; count != 1/*i <100*/; i++)
   {
      //temp = listIn;
      split(listIn, listA, listB);
      //  for (list <int> :: iterator it1 = listA.begin(); it1 != listA.end(); it1++)
      // {
       //   cout << *it1 << " ";
      // }
        // cout << endl;
      // for (list <int> :: iterator it2 = listB.begin(); it2 != listB.end(); it2++)
      //   {
       // cout << *it2 << " ";
      // }
//    cout << endl;
    merge(listIn, listA, listB, count);


    //    listA.erase(listA.begin(), listA.end());
    // listB.erase(listB.begin(), listB.end());                 

   }while(count > 1);
   return;  
}

/******************************************************************************
 * Main handles everything in this program
 *****************************************************************************/
int main(int argc, char* argv[])
{
   // open the file from command line
   ifstream fin;
   fin.open(argv[argc - 1]);
   if (fin.fail())
   {
      cout << "open file error " << argv[argc - 1] << endl;
      return 0;
   }
   list<int> listIn;
   int dataIn;
   while(fin >> dataIn)
   {
      listIn.push_back(dataIn);
   }
   fin.close();
   mergeSort(listIn);
  
   for (list <int> :: iterator it = listIn.begin(); it != listIn.end(); it++)
   {
     cout << *it << " ";
   }
   cout << endl;
   
   return 0;
}

