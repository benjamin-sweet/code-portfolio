/*****************************************************************************/
/*DEFAULT CONSTRUCTOR - Creates empty tree with a defined threshold value for*/
/*restructuring based on search frequency of a value.						 */
/*****************************************************************************/
template <typename T>
BST<T>::BST(int th) : thresholdVal(th), root(NULL){}

/*****************************************************************************/
/*PRIMARY CONSTRUCTOR - constructs a tree based on a string of input values  */
/*by calling buildFromInputString Function. 								 */
/*****************************************************************************/
template <typename T>
BST<T>::BST( string input , int th ) : root(NULL), thresholdVal(th) {
   buildFromInputString( input );
}

/*****************************************************************************/
/*Overloaded Assignment Operator											 */
/*****************************************************************************/
template <typename T>
const BST<T>& BST<T>::operator=(const BST& rhs){

   if( this != &rhs ){ 			//IF this object != reference of right hand side
      makeEmpty();	  			//empty THIS tree
      root = clone(rhs.root); 	//clone the right hand side to THIS
   }
   return *this; 	   			//return this object.
}

/*****************************************************************************/
/*CLONE FUNCTION - Clones a subtree by making deep copies.					 */
/*****************************************************************************/
template <typename T>
typename BST<T>::BSTNode* BST<T>::clone( BSTNode* subTree ) const{

   if( subTree == NULL )
      return NULL;

   return new BSTNode( subTree->data, clone(subTree->left), clone(subTree->right));
}

/*****************************************************************************/
/*BUILDFROMINPUTSTRING - Empties THIS of all data then builds a new tree by  */
/*parsing the input string with a whitespace delimiter. 					 */
/*****************************************************************************/
template <typename T>
void BST<T>::buildFromInputString( string input ){

   if(root != NULL){
      makeEmpty();   
   }

   istringstream ss(input);
   T element;
   ss >> element;
   root = new BSTNode(element, NULL, NULL);
   
   ss >> element;
   while(ss){
      insert(element, root);
      ss >> element;
   }
}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
BST<T>::BST(const BST<T>& bst) : root(NULL), thresholdVal(bst.thresholdVal){

   operator=(bst);
}

/*****************************************************************************/
/*DESTRUCTOR - calls makeEmpty() to delete the tree.						 */
/*****************************************************************************/
template <typename T>
BST<T>::~BST(){

   makeEmpty();
}
/*****************************************************************************/
/*makeEmpty() - public wrapper function of makeEmpty(BSTNoed<T>*& subTree)		 */
/*empties the entire Binary Search Tree and reclaims memory.				 */
/*****************************************************************************/
template <typename T>
void BST<T>::makeEmpty(){
   makeEmpty(root);
}
/*****************************************************************************/
/*makeEmpty(BSTNode<T>*& subTree) - empties all branches under a given 	 	 */
/*root node of a tree. 														 */
/*****************************************************************************/
template <typename T>
void BST<T>::makeEmpty(BSTNode *&subTree){

   if( subTree != NULL ){
        makeEmpty( subTree->left);
        makeEmpty( subTree->right );
        delete subTree;
   }
   subTree = NULL;

}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
void BST<T>::insert( const T& v, BSTNode *&subTree ){

   if( subTree == NULL )
      subTree = new BSTNode( v, NULL, NULL );
   else if( v < subTree->data )
      insert( v, subTree->left );
   else if( subTree->data < v )
      insert( v, subTree->right );
   else
      ;
}

template <typename T>
void BST<T>::insert( const T& v ){

   insert( v, root );
}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/

template <typename T>
void BST<T>::printInOrder( BSTNode *subTree ) const{

   if(subTree == NULL)
     return;
   if(subTree != NULL){
      printInOrder( subTree->left );
      cout << subTree->data << " ";
      printInOrder( subTree->right );
   }
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
void BST<T>::printInOrder() const{
   printInOrder( root );
   cout << endl;
}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/

template <typename T>
typename BST<T>::BSTNode* BST<T>::findMin( BSTNode* subTree ) const{

   if( subTree == NULL )
      return NULL;
   if( subTree->left == NULL )
      return subTree;

   return findMin(subTree->left);

}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/

template <typename T>
void BST<T>::remove( const T& v, BSTNode *& subTree ){

   if( subTree == NULL )
      return;
   if( v < subTree->data )
      remove( v, subTree->left );
   else if( subTree->data < v )
      remove( v, subTree->right );
   else if( subTree->left != NULL && subTree->right != NULL ){
      subTree->data = findMin( subTree->right )->data;
      remove( subTree->data, subTree->right );
   }
   else{
      BSTNode *oldNode = subTree;
      subTree = (subTree->left != NULL ) ? subTree->left : subTree->right;
      delete oldNode;
   }     
}
/*****************************************************************************/
/*****************************************************************************/
template <typename T>
void BST<T>::remove( const T& v ){
   remove(v, root);
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/

template <typename T>
bool BST<T>::contains( const T& v, BSTNode *&subTree, BSTNode *&subTreeParent ){

   if( subTree == NULL)
      return false;
   else if( v < subTree->data )
      return contains( v, subTree->left, subTree );
   else if( subTree->data < v )
      return contains( v, subTree->right, subTree );
   else
      subTree->searchCount++;

      if(subTree == root){
         subTree->searchCount = 0;
         return true;
      }

      if(subTree->searchCount == thresholdVal){

         if(subTreeParent->left == subTree){
            //subTree->data = findMin( subTree->left)->data;
            leftRotate( subTreeParent );
         }
         else{
            rightRotate( subTreeParent );
         }
       subTreeParent->searchCount = 0;
   }
   return true;     
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
bool BST<T>::contains( const T& v ){

   return contains( v, root, root );
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/

template <typename T>
bool BST<T>::empty(){

   if(root == NULL)
      return true;
   else
      return false;
}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/

template <typename T>
int BST<T>::numOfNodes(BSTNode* subTree) const{

   if( subTree == NULL )
      return 0;
   else
      return ( numOfNodes( subTree->left ) + numOfNodes(subTree->right) + 1);
   
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
int BST<T>::numOfNodes() const{

   return numOfNodes( root );
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
int BST<T>::height( BSTNode* subTree ) const{

   int lCount, rCount;

   if( subTree == NULL )
      return -1;
   else if (subTree->left == NULL && subTree->right == NULL)
      return 0;
   else
   {
      lCount = height( subTree->left );
      rCount = height( subTree->right);
      if( lCount >= rCount )
         return lCount + 1;
      else
         return rCount + 1;
    }
}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
int BST<T>::height() const{

   return height( root );
}

/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
void BST<T>::printLevelOrder( BSTNode* subTree) const {

   queue<BSTNode*> Q, nextQ;
   BSTNode* currentNode;
   vector<T> nodeVec;

   if( subTree == NULL )
      return;
   else
      Q.push(subTree);
      while(!Q.empty()){
         currentNode = Q.front();
         Q.pop();
         if(currentNode != NULL){
            nodeVec.push_back(currentNode->data);
            nextQ.push(currentNode->left);
            nextQ.push(currentNode->right);
         }
         if(Q.empty())
         swap(Q, nextQ);
      }

   for(int i = 0; i < nodeVec.size(); ++i){
      cout << nodeVec[i] << " ";
   }
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
void BST<T>::printLevelOrder() const {
   printLevelOrder(root);
   cout << endl;
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
void BST<T>::leftRotate( BSTNode *&subTreeParent ){

   BSTNode* tempNode = subTreeParent->left;
   subTreeParent->left = tempNode->right;
   tempNode->right = subTreeParent;
   subTreeParent = tempNode;      
}
/*****************************************************************************/
/*COPY CONSTRUCTOR - calls the overloaded assignment operator. 				 */
/*****************************************************************************/
template <typename T>
void BST<T>::rightRotate( BSTNode *&subTreeParent ){

   BSTNode* tempNode = subTreeParent->right;
   subTreeParent->right = tempNode->left;
   tempNode->left = subTreeParent;
   subTreeParent = tempNode;
}
