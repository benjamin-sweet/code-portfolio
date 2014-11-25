#ifndef BST_H
#define BST_H

const int default_thresholdValue = 1;

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

namespace cop4530{

/******************************************************************************/
/*BINARY SEARCH TREE CLASS - This is a generic Bianry Search Tree, implemented*/
/*By use of templates.														  */
/******************************************************************************/
template <typename T>
class BST{

private:

	//The Bianry Search Tree data structure is composed of a 
   class BSTNode{
   public:

      int searchCount;	//Tracks the number of times a node has been searched. The tree restructures itself to put commonly searched elements near the root.
      T data;			//Generic data type
      BSTNode* left;	//pointer to left node (lesser)
      BSTNode* right; 	//pointer to right node (greater)

      BSTNode( const T& element, BSTNode* lt, BSTNode* rt) :
	     data( element), left( lt ), right( rt ), searchCount(0){}		//contstructor for BSTNode class.
   };

   BSTNode* root;		//Node pointer pointing to root of Binary Search Tree.
   int thresholdVal;	//maximum number of searches on a node before the tree restructures.	

   void 	 printInOrder	( BSTNode *subTree ) const;			//prints a subtree via In Order Tree Traversal
   void 	 printLevelOrder( BSTNode *subTree ) const;			//prints a subtree via Level Order Tree Traversal
   void 	 makeEmpty		( BSTNode *&subTree );				//deletes subtree and sets reference to null  
   void 	 insert			( const T& v, BSTNode *&subTree );	//inserts a node v into a subtree
   void 	 remove			( const T& v, BSTNode *&subTree );	//removes a node of value v from a subtree.
   bool 	 contains		( const T& v, BSTNode *&subTree, BSTNode *&subTreeParent  );	//returns true if subtree contains value v
   int  	 numOfNodes		( BSTNode *root ) const;			//returns the number of nodes in the tree
   int  	 height			( BSTNode *root ) const;			//calculates height of tree.
   BSTNode*  clone			( BSTNode *subTree ) const;			//clones a subtree to a copy.
   BSTNode*  findMin		( BSTNode *subTree ) const;			//finds lowest value node
   void 	 leftRotate		( BSTNode *&subTreeParent );		//restructures a subtree via pointer swap
   void 	 rightRotate	( BSTNode *&subTreeParent );		//restructures a subtree via pointer swap
   
public:

   BST	(int th = default_thresholdValue);		  				//default constructor
   BST	(string input , int th = default_thresholdValue );		//constructor -- creates tree from input string
   BST	(const BST& bst);					  					//copy constructor
   ~BST();						  								//destructor
   void 		 buildFromInputString(const string input);	  	//called by secondary constructor to build tree
   const BST<T>& operator=			 (const BST<T>&);			//overloaded assignment operator	
   bool 		 empty				 ();						//returns true if tree is empty
   void 		 printInOrder		 () const;					//public in order print wrapper function
   void 		 printLevelOrder	 () const; 					//public wrapper function
   int 			 numOfNodes			 () const;      			//public wrapper function
   int 			 height				 () const;					//public wrapper function
   void 		 makeEmpty			 ();						//public wrapper function
   void 		 insert				 (const T& v);    			//public wrapper function
   void 		 remove				 (const T& v);    			//public wrapper function
   bool 		 contains			 (const T& v);  			//public wrapper function

};
#include "bst.hpp"	//appends implementation file
}
#endif

