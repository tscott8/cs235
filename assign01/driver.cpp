/***********************************************************************
* Program:
*    Assignment 01, Set of Integers         
*    Brother Ercanbrack, CS235
* Author:
*    Tyler Scott
* Summary:
*    
*    
*    
*
*    Estimated:  5.0 hrs
*    Actual:     10 hrs
*
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

/******************************************************
 * This is where the class is stated
 ******************************************************/   
class Set//New class! YAY!
{
   private:
      int * data;//pointer to array of intergers
      int arraySize;//declares an variable to hold array size
      int setSize;//the position and length of the data set

   public: 

/******************************************************
* Default constructor, allocates memory and sets default values
******************************************************/   
   Set(int passSize=10);
   Set(const Set &Set2);
   ~Set();
   
   int growArray();
   int addData(int newElement);//should function as a linked list?
   bool checkData(int newElement);//use a string compare?
   void display();

   Set operator && (const Set &rhs);
   Set operator || (const Set &rhs);
   Set operator - (const Set &rhs);
   Set operator = (const Set &rhs);
};

/**************************************************************
* Methods here.
***********************************************************/   
Set::Set(int passSize)//default constructor
   {
      passSize = 10;
      data = new int[passSize];//sets it as a new dynamically
                        //allocated array
      arraySize = passSize;//sets the size to 10
      setSize = 0;
   }

/******************************************************
* copies to a new constructor object
******************************************************/
Set::Set(const Set &Set2)//copy
   {
      arraySize = Set2.arraySize;
      setSize = Set2.setSize;
      data = new int[Set2.arraySize];
      for(int i=0; i < Set2.setSize; i++)
      {
         data[i] = Set2.data[i];
         //body of copy constructor
      }
   }

/******************************************************
* Destruction
******************************************************/   
Set::~Set()//destructor       
   {
      delete[] data;
      data = NULL;
   }

int Set::growArray()
   {
      int *tempData;
      if (setSize >= arraySize)
      {
         this->arraySize = arraySize + 10;
      }      
      tempData = new int[arraySize];
      for(int i=0; i < setSize; i++)
      {
         tempData[i] = data[i];
      }
      delete[] data;
      data = tempData; 
   }

void readFile(string filename, Set &objectA, Set &objectB)//opens the file and reads in the data
{
   ifstream fin;
   fin.open(filename.c_str());
   if(fin.fail())
   {
      cout << "Error reading File...";
      return;
   }
   int numeros;
   int length;
   fin >> length;
   for(int i = 0;i < length; i++)
   {    
      fin >> numeros;
     objectA.addData(numeros);      
   }
   fin >> length;
   for(int j = 0; j< length; j++)
   {
      fin >> numeros;
      objectB.addData(numeros);
   }

   fin.close();
}
   
int Set::addData(int newElement)//should function as a linked list?
{
    if(checkData(newElement))
   {
      growArray();
      data[setSize] = newElement;
      setSize++;
   }
}

bool Set::checkData(int newElement)
{
   for(int i =0; i< setSize; i++)
   {
      if(newElement == data[i])
         return false;
   }
   return true;
}

void Set::display()
{
   sort(data, data+setSize);
   for(int i = 0; i < setSize; i++)
   {
      if(i % 10 == 0)
      {
         cout  << endl << "  ";
      }  
      cout << setw(2) << setfill(' ') << data[i] << " ";
   }
    cout << endl;
}

Set Set::operator && (const Set &rhs)
{
  Set C;
  for(int i = 0; i < setSize; i++)
  {
     for(int j = 0; j < rhs.setSize; j++)
     {
        if(this->data[i] == rhs.data[j])
           C.addData(data[i]);
     }
  }  
  return C;
}

Set Set::operator || (const Set &rhs)
{
   Set C;
  for(int i = 0; i < setSize; i++)
  {
     C.addData(data[i]);
  }
  for(int j = 0; j < rhs.setSize; j++)
  {
      C.addData(rhs.data[j]);
  }
  return C;
}

Set Set::operator - (const Set &rhs)
{
  Set C(arraySize + rhs.arraySize);
  for(int k = 0; k < this->setSize; k++)
  {
     for(int l = 0; l < rhs.setSize; l++)
     {
        if(this->data[k] == rhs.data[l])
           break;
        else if ((l+1) == rhs.setSize)
                     C.addData(data[k]);     
     }    
  }
  return C;
}

Set Set::operator = (const Set &rhs)
{
   if(this == &rhs)
    {
       return *this;
    }
   if(rhs.setSize > arraySize)
   {
      delete[] data;
      data = new int[rhs.arraySize];
      arraySize = rhs.arraySize;
   }
  
   for(int i = 0; i < rhs.setSize; i++)
   {
      data[i] = rhs.data[i];
//      addData(rhs.data[i]);
   }
   setSize = rhs.setSize;
   return *this; 
}

/*************************************************************
 * Heres the main part that controls all the action.
 ************************************************************/
int main(int argc, char** argv)
{
   string inFile = "";
   if( argc == 2 )
   {
      inFile = argv[1];
   }
   else
   {
      getline(cin, inFile);
   }
    
   Set mainSetA;
   Set mainSetB;
   Set mainSetC;
   Set mainSetD;
   Set mainSetE;

   readFile(inFile, mainSetA, mainSetB);//argstuff
   cout << "\nSet A:";
   mainSetA.display();

   cout << "\nSet B:";
   mainSetB.display();

   cout << "\nIntersection of A and B: ";
   mainSetC = mainSetA && mainSetB;
   mainSetC.display();

   cout << "\nUnion of A and B:";
   mainSetC = mainSetA || mainSetB;
   mainSetC.display();

   cout << "\nDifference of A and B:";
   mainSetD = mainSetA - mainSetB;
   mainSetD.display();

   cout << "\nDifference of B and A:";
   mainSetE = mainSetB - mainSetA;
   mainSetE.display();
   
   return 0;
}
   
