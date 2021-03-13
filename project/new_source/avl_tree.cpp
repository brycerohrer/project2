#include <iostream>
#include "avl_tree.h"
using namespace std;

void AVLTree::insert(const int newValue) {

  bool isTaller = false;
  AVLNode *newNode;
  newNode = new AVLNode(newValue);
  insertIntoAVL(root,newNode,isTaller);
  
}

void AVLTree::insertIntoAVL(AVLNode* &root, AVLNode *newNode, bool& isTaller){
  if (root == NULL){
    root = newNode;
    isTaller = true;
  }
  else if (root->value == newNode->value){
    cout << "Duplicate" << endl;
  }
  else if (root->value > newNode->value){

    insertIntoAVL(root->left, newNode,isTaller);

    if (isTaller){
      switch (root->bf)
	{
	case -1:
	  balanceFromLeft(root);
	  isTaller = false;
	  break;

	case 0:
	  root->bf = -1;
	  isTaller = true;
	  break;

	case 1:
	  root->bf = 0;
	  isTaller = false;
	}
    }
  }
  else{

    insertIntoAVL(root->right, newNode, isTaller);

    if(isTaller){
      switch(root->bf)
	{
	case -1:
	  root->bf = 0;
	  isTaller = false;
	  break;
	  
	case 0:
	  root->bf = 1;
	  isTaller = true;
	  break;
	  
	case 1:
	  balanceFromRight(root);
	  isTaller = false;
	}
    }
  }
}

void AVLTree::rotateToLeft(AVLNode* &root){
  AVLNode *p;
  
  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->right == NULL)
    cout << "Error in the tree: No right subtree to rotate." << endl;
  else{
    p = root->right;
    root->right = p->left;
    p->left = root;
    root = p; 
  }
}

void AVLTree::rotateToRight(AVLNode* &root){
  AVLNode *p;

  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->left == NULL)
    cout << "Error in the tree: No left subtree to rotate." << endl;
  else{
    p = root->left;
    root->left = p->right; 
    p->right = root;
    root = p; 
  }
}

void AVLTree::balanceFromLeft(AVLNode* &root){  // handle the case 0 

  AVLNode *p;
  AVLNode *w;

  p = root->left;

  switch (p->bf)
    {
    case -1:
      root->bf = 0;
      p->bf = 0;
      rotateToRight(root);
      break;

    case 0:  // You need to handle this case; possible in AVL deletion
      
      cout << "You need to handle this case, as it is possible in AVL deletion. " << endl;
      break; 

    case 1:
      w = p->right;

      switch (w->bf)
	{
	case -1:
	  root->bf = 1;
	  p->bf = 0;
	  break;
	case 0:
	  root->bf = 0;
	  p->bf = 0;
	  break;
	case 1:
	  root->bf = 0;
	  p->bf = -1;
	}
      
      w->bf = 0;
      rotateToLeft(p);
      root->left = p;
      rotateToRight(root);
    }
}


void AVLTree::balanceFromRight(AVLNode* &root){ // handle the case 0 
  AVLNode *p;
  AVLNode *w;

  
  p = root->right;
  switch (p->bf)
    {
    case -1:
      
      w = p->left;
      switch (w->bf)
	{
	case -1:
	  root->bf = 0;
	  p->bf = 1;
	  break;
	case 0:
	  root->bf = 0;
	  p->bf = 0;
	  break;
	case 1:
	  root->bf = -1;
	  p->bf = 0;
	}
      
      w->bf = 0;
      rotateToRight(p);
      root->right = p;
      rotateToLeft(root);
      break;

    case 0:  // You need to handle this case; possible in AVL deletion
      
      cout << "You need to handle this case, as it possible in AVL deletion. " << endl;
      break;

    case 1:
      root->bf = 0;
      p->bf = 0;
      rotateToLeft(root);
    }
}

void AVLTree::print(char letter){
if (letter == 'p') {
   if(root == NULL){
     cout<<"list is empty"<<endl;
     return;
   }
  //     {
        if(root->left != NULL){
          printtree(root->left);
        }
          std::cout << root->value << " ";
        if(root->right != NULL){
          printtree(root->right);
}
}
if (letter == 'h'){
          printheight(root->left, 1);
          printheight(root, 0);
          printheight(root->right, 1);
          std::cout<<endl;
}
}
void AVLTree::printtree(AVLNode* node){

            if(node->left != NULL){
            printtree(node->left);
}
            std::cout << node->value << " ";

            if(node->right != NULL){
            printtree(node->right);
}

          return;
}
void AVLTree::printheight(AVLNode* node, int count){


            // if(node->left != NULL && node->right != NULL){
            //   count ++;
            //   printheight(node->left, count);
            //   printheight(node->right, count);
            //
            // }
            if(node->left != NULL){
            count ++;
            printheight(node->left, count);
          }
            else if (node->right != NULL){
            count++;
            printheight(node->right, count);
}
            else{
              if (count > 0) {
              std::cout<<count<<" ";
              count = 0;
              return;
            }}
//
//             if(node->right != NULL){
//             count++;
//             printheight(node->right, count);
// }
//             else if (node->left != NULL){
//             count ++;
//             printheight(node->left, count);
//           }
          // else{
            if (count > 0) {
            std::cout<<count<<" ";
            count = 0;
            return;
          }
          count = 0;
        return;
 }

AVLNode* AVLTree::getPred(AVLNode* node){ // get predecesor function needs implemented

  cout << "Need to implement this getPred() function \n";
  return NULL; 

}

void AVLTree::remove(int badValue){
  bool isShorter = false;
  remove(root,badValue, isShorter);
}

void AVLTree::remove(AVLNode* &root, int badValue, bool& isShorter){  // implement remove function (not sure what this does)

  cout << "Need to implement this remove() function \n";
  return; 

}

