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

   class BSTNode{
   public:

      int searchCount;
      T data;
      BSTNode* left;
      BSTNode* right;

      BSTNode( const T& element, BSTNode* lt, BSTNode* rt) :
	 data( element), left( lt ), right( rt ), searchCount(0){}
   };

   BSTNode* root;
   int thresholdVal;

   void printInOrder( BSTNode *subTree ) const;
   void printLevelOrder( BSTNode *subTree ) const;
   void makeEmpty( BSTNode *&subTree );
   void insert( const T& v, BSTNode *&subTree );
   void remove( const T& v, BSTNode *&subTree );
   bool contains( const T& v, BSTNode *&subTree, BSTNode *&subTreeParent  );
   int numOfNodes( BSTNode *root ) const;
   int height( BSTNode *root ) const;
   BSTNode* clone( BSTNode *subTree ) const;
   BSTNode* findMin( BSTNode *subTree ) const;
   void leftRotate( BSTNode *&subTreeParent );
   void rightRotate( BSTNode *&subTreeParent );
public:

   BST(int th = default_thresholdValue);		  //done
   BST( string input , int th = default_thresholdValue ); //done
   BST(const BST& bst);					  //done
   ~BST();						  //done
   void buildFromInputString(const string input);	  //done
   const BST<T>& operator=(const BST<T>&);		  //done
   bool empty();					  //done
   void printInOrder() const;				  //done
   void printLevelOrder() const; 			  //done
   int numOfNodes() const;      			  //done
   int height() const;					  //done	
   void makeEmpty();					  //done
   void insert(const T& v);    				  //done
   void remove(const T& v);    				  //done
   bool contains(const T& v);  				  //NEEDS ROTATE

};

#include "bst.hpp"

}

#endif

