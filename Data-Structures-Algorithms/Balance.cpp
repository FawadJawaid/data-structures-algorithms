#include<iostream>
#include<cmath>

using namespace std;

class BSTNode
{
   public:
   int key;
   BSTNode *left, *right;
   
   BSTNode()
   {
      left=right=NULL;
   }
   BSTNode(int n, BSTNode *lft=NULL, BSTNode *r=NULL)
   {
       key=n;
       left=lft;
       right=r;
   }
};

class BST 
{
   public:
   BSTNode *root;
   int nodecount;
   
   BST()
   {
        root=NULL;
        nodecount=0;
   }
   
   bool isEmpty() const
   {
        return root==NULL;
   }
   
   void visit(BSTNode* p)
   {
        cout<<p->key<<' ';
   }
   
   
   void insert1(int el)
   {
        BSTNode *p=root, *prev=NULL;
        
        while(p!=NULL)
        {
            prev=p;
            if(p->key<el)
               p=p->right;
            else p=p->left;
        }
        
        if(root==NULL)
            root =new BSTNode(el);
        else if(prev->key<el)
            prev->right = new BSTNode(el);
        else prev->left = new BSTNode(el);
   }
   
    void Choice1() 
   { 
        int c;
         
        cout<<"\n1.Count Nodes\n2.Count left children\n3.Count no. of right children\n4.Balance?\nChoice: ";  
        cin>>c;
         
        switch(c) 
        { 
           case 1: 
              cout << Count_Nodes1(root) << endl; 
              break; 
           case 2: 
              cout << Leftheight(root) << endl; 
              break; 
           case 3: 
              cout << Rightheight(root) << endl; 
              break;
           case 4:               
               cout << Balanced(root) << endl;
               break;
           /*case 5:
                cout<<Absolute(root)<<endl;
                break;*/    
        } 
   }
   
   int Count_Nodes1(BSTNode *t)
   {
        //int nodecount=0;
        
        if(t!=NULL)
        {
            nodecount++;
            
            Count_Nodes1(t->right);
            Count_Nodes1(t->left);
        }
        
        return nodecount;
   }
   
   int Count_right_children1(BSTNode *t)
   {
       if(t->right!=NULL)
       {
         Count_Nodes1(t->right);
       }
   }  
   
   int Count_left_children1(BSTNode *t)
   {
      if(t->left!=NULL)
      {
       Count_Nodes1(t->left);
      } 
   }
   
   int Leftheight(BSTNode *t)
   {
       int lh=0;
       
       lh=(Count_left_children1(t)-1);
       
       return lh;
    }
    
    int Rightheight(BSTNode *t)
    {
       int rh=0;
       
       rh=(Count_right_children1(t)-1);
       
       return rh;
    }
    
    int Balance1(BSTNode *t)
    {
         int rht=0;
         
         if(t==NULL)
           return true;
         
         rht = Rightheight(t);
         //lht = Leftheight(t);
           
         return rht;
    }
    
    int Balance2(BSTNode *t)
    {
         int lht=0;
         
         if(t==NULL)
           return true;
         
         //rht = Rightheight(t);
         lht = Leftheight(t);
           
         return lht;
    }
    
    int Balanced(BSTNode *t)
    {
         int l=0,h=0;
         
         if(t==NULL)
           return true;
         
         //rht = Rightheight(t);
         
           
         return abs(Balance1(t)-Balance2(t));
    }
    
    
    /*int Absolute(BSTNode *t)
    {
        return (Leftheight(t)-Rightheight(t));
    }*/
   
   /*bool IsBalanced1(BSTNode *t)
   {
        //int lh=0;
        //int rh=0;
        
        if(t==NULL)
          return true;
        
        //if(t!=NULL)
        //{
        //lh = (Count_left_children1(t)-1);
        //rh = (Count_right_children1(t)-1);
        //lh = (Count_left_children1(t)-1);
        else{
        if((abs(Leftheight(t)-Rightheight(t)) > 1) /*&& IsBalanced1(t->left) && IsBalanced1(t->right)*///)
        /*{  return false;
        }
        }*/
        
        //IsBalanced(t->left); 
        //IsBalanced(t->right);
        /*return true;
        //}
   }*/
   
   
};

int main()
{
    BST B1;
    
    int data[]={8,6,9,5,7,10};
        for(int i=0;i<6;i++)
           B1.insert1(data[i]);
           
        B1.Choice1();
    
    
    system("pause");
    return 0;
}                 
