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
   int thresholdVal;	

   void 	 printInOrder	( BSTNode *subTree ) const;			//prints a subtree via In Order Tree Traversal
   void 	 printLevelOrder( BSTNode *subTree ) const;			//prints a subtree via Level Order Tree Traversal
   void 	 makeEmpty		( BSTNode *&subTree );				//deletes subtree and sets reference to null  
   void 	 insert			( const T& v, BSTNode *&subTree );	//inserts a node v into a subtree
   void 	 remove			( const T& v, BSTNode *&subTree );	
   bool 	 contains		( const T& v, BSTNode *&subTree, BSTNode *&subTreeParent  );
   int  	 numOfNodes		( BSTNode *root ) const;
   int  	 height			( BSTNode *root ) const;
   BSTNode*  clone			( BSTNode *subTree ) const;
   BSTNode*  findMin		( BSTNode *subTree ) const;
   void 	 leftRotate		( BSTNode *&subTreeParent );
   void 	 rightRotate	( BSTNode *&subTreeParent );
   
public:

   BST	(int th = default_thresholdValue);		  
   BST	(string input , int th = default_thresholdValue );
   BST	(const BST& bst);					  
   ~BST();						  
   void 		 buildFromInputString(const string input);	  
   const BST<T>& operator=			 (const BST<T>&);	
   bool 		 empty				 ();				
   void 		 printInOrder		 () const;			
   void 		 printLevelOrder	 () const; 			
   int 			 numOfNodes			 () const;      	
   int 			 height				 () const;			
   void 		 makeEmpty			 ();				
   void 		 insert				 (const T& v);    	
   void 		 remove				 (const T& v);    	
   bool 		 contains			 (const T& v);  	

};
#include "bst.hpp"
}
#endif

