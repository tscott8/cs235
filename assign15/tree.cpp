/******************************************************************************
 * Program:
 *    Assignment 13, BTree class methods
 *    Brother Ercanbrack, CS 235
 * Author:
 *    Tyler Scott
 * Summary:
 *    This program defines the member functions for the BTree class
 *
 *  Estimated time: 8.0hrs
 *  Actual time: 2.0hrs
 ******************************************************************************/
#include "tree.h"
#include <iostream>
using namespace std;

/*****************************************************************************
 * Default BTree constructor
 *****************************************************************************/
BTree :: BTree(int data)
{
   this->data = data;
   left = NULL;//= NULL;
   right = NULL; //= NULL;
   parent = NULL;// = NULL;
}

/*****************************************************************************
 * Deconstructor left blank because it is not used
 *****************************************************************************/
BTree :: ~BTree(void)
{

}

/*****************************************************************************
 * Inserts a node on the left pointer of the current node
 *****************************************************************************/
void BTree :: insertLeft(int item)
{  
   BTree* insert = new BTree(item);
   left = insert;  
   insert->parent = this;
}

/*****************************************************************************
 * Inserts a node on the right pointer of the current node
 *****************************************************************************/
void BTree :: insertRight(int item)
{
   BTree* insert = new BTree(item);
   right = insert;
   insert->parent = this;
}

/*****************************************************************************
 * grants access to the private BTree node "left" 
 *****************************************************************************/
BTree* BTree :: getLeftChild(void)
{
   return left;
}

/*****************************************************************************
 * grants access to the private BTree node "right"
 *****************************************************************************/
BTree* BTree :: getRightChild(void)
{
   return right;
}

/*****************************************************************************
 * grants access to "parent"
 *****************************************************************************/
BTree* BTree :: getParent(void)
{
   return parent;
}

/*****************************************************************************
 * grants access to "data"
 *****************************************************************************/
int BTree :: getData(void)
{
   return data;
}

/*****************************************************************************
 * sets the value of data to what is passed in
 *****************************************************************************/
void BTree :: setData(int item)
{
   data = item;
}

/*****************************************************************************
 * sets left to the tree that is passed in
 *****************************************************************************/
void BTree :: setLeft(BTree* tree)
{
   left = tree;
   if (tree != NULL)
      left->parent = this;
}

/*****************************************************************************
 * sets the right to the tree that is passed in
 *****************************************************************************/
void BTree :: setRight(BTree* tree)
{
   right = tree;
   if (tree != NULL)
      right->parent = this;
}

/*****************************************************************************
 * left visit right traversal
 *****************************************************************************/
void BTree :: infix(void)
{
   if (left != NULL) left->infix();
   cout << data << " ";
   if (right != NULL) right->infix();
}

/*****************************************************************************
 * visit left right traversal
 *****************************************************************************/
void BTree :: prefix(void)
{
   cout << data << " ";
   if (left != NULL) left->prefix();
   if (right != NULL) right->prefix();
}

/*****************************************************************************
 * left right visit traversal
 *****************************************************************************/
void BTree :: postfix(void)
{
   if (left != NULL) left->postfix();
   if (right != NULL) right->postfix();
   cout << data << " ";
}

/*****************************************************************************
 * level order traversal.
 *****************************************************************************/
void BTree :: level(void)
{
 const int MAX = 50;
  BTree *queue[MAX];
  BTree *temp;
  int front = 0;
  int back = 0;

  queue[back++] = this;

  while (front != back)
  {
    temp = queue[front];
    front = (front + 1) % MAX;
    if (temp != NULL)
    {
      // visit
      cout.width(4);
      cout << temp->data << " ";
      if (temp->parent == NULL)
         cout << " Parent = NULL! " << endl;
      else
         cout << " Parent = " << temp->parent->data << "   " << endl;
      // end Visit        
      queue[back] = temp->left;
      back = (back + 1) % MAX;
      queue[back] = temp->right;
      back = (back + 1) % MAX;

    }
  }
}
