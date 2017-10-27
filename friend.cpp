#include <stdio.h>

class Node   
{  
public:
	int num;
    private:   
       int data;  
       int key;  
       // ...  
  
    friend class BinaryTree; // class BinaryTree can now access data directly  
};  

class BinaryTree  
{  
    private:  
       Node *root;  
  
    int find(int key);  
};  

int BinaryTree::find(int key)  
{  
    // check root for NULL...  
    if(root->key == key || root->num == key)  
    {  
        // no need to go through an accessor function  
        return root->data;  
    }  
    // perform rest of find  
} 

int main()
{
	return 1;
}
