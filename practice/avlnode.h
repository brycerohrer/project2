template<class elemType>
struct AVLNode
{
elemType info;
int bfactor; //balance factor
AVLNode<elemType> *llink;
AVLNode<elemType> *rlink;
};

template <class elemType>
void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
binaryTreeNode<elemType>* otherTreeRoot)
{
if (otherTreeRoot == NULL)                 
copiedTreeRoot = NULL;
else
{
copiedTreeRoot = new binaryTreeNode<elemType>;
copiedTreeRoot->info = otherTreeRoot->info;
copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
}
}//end copyTree