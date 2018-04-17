# include <stdio.h>

struct TreeNode
{
    struct TreeNode * left ;
    struct TreeNode * right ;
    int data;
    
} ;

struct TreeNode* root = NULL ;

struct TreeNode* getTheNewNode(int newNodeValue)
{
    struct TreeNode* node1 = (struct TreeNode*)(malloc(sizeof(struct TreeNode)));
    
    (*node1).data = newNodeValue ;
    
    (*node1).left= NULL ;
    
    (*node1).right = NULL ;
    
    return node1;
};

struct TreeNode* Search(struct TreeNode * nodeUnderConsideration , int data)
{
    struct TreeNode* returningNode = NULL ;
    
    if(nodeUnderConsideration == NULL)
    {
        return NULL;
    }
    else if(data == (nodeUnderConsideration->data))
    {
        return nodeUnderConsideration ;
    }
    else if( data < (nodeUnderConsideration ->data) )
    {
        //go left
        returningNode = Search(nodeUnderConsideration->left,data);
        
    }
    else if( data > (nodeUnderConsideration->data))
    {
        //go right
        returningNode = Search(nodeUnderConsideration->right , data);
    }
    return returningNode ;
};

struct TreeNode * Insert(struct TreeNode * nodeUnderConsideration , int data)
{
    if(nodeUnderConsideration == NULL)
    {
        //As the node is NULL. Returning
        struct TreeNode *  returnNode = getTheNewNode(data) ;
        
        if(root == NULL)
        {
            root = returnNode ;
        }
        
        return returnNode;
    }
    else if( data < (nodeUnderConsideration ->data) )
    {
        //go right
        
        nodeUnderConsideration ->left = Insert(nodeUnderConsideration->left,data);
        
        return nodeUnderConsideration;
        
    }
    else if( data > (nodeUnderConsideration->data))
    {
        //go left
        
        nodeUnderConsideration->right = Insert(nodeUnderConsideration->right , data);
        
        return nodeUnderConsideration;
    }
    return nodeUnderConsideration;
};



int main()
{
    root = NULL ;
    
    Insert(root,11);
    
    Insert(root,50);
    
    Insert(root,2);
    
    Insert(root,100);
    
    Insert(root,-110);
    
    Insert(root,34);
    
    Insert(root,555);
    
    Insert(root,-990);
    
    Insert(root,-1090);
    
    Insert(root,-1190);
    
    Insert(root,-1290);
    
    Insert(root,-1390);
    
    struct TreeNode * node = Search(root,556) ;
    
    if( NULL != node )
    {
        printf("%s\n", "The Element was found");
    }
    else
    {
        printf("%s\n", "The Element could not be found");
    }
    return 0;
}

