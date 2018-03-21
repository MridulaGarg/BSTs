#include<iostream>
#include<conio.h>

using namespace std;

template <class T>
class node
{
    public:
        T data;
        node *left;
        node *right;
};

template <class T>
class quenode
{
	public:
		node<T>* info;
		quenode *next;
};

template <class T>
class que
{
	public:
		quenode<T> *f;
		quenode<T> *r;
		que()
		{
			f=NULL;
			r=NULL;
		}
		
		int isempty()
		{
			if(f=='\0')
				return 1;
			else
				return 0;
		}
		
		void enque(node<T> *p)
		{
			quenode<T> *t=new quenode<T>;
			t->info=p;
			t->next='\0';
			if(isempty() && f==r)
			{
				f=t;
				r=t;
			}
			else
			{
				r->next=t;
				r=t;
			}
		}
		
		node<T> *deque()
		{
			if(isempty())
			{
				cout<<"\nElement can't be deleted...";
				getch();
				return 0;
			}
			else
			{
				quenode<T> *t=f;
				node<T> *m=f->info;
				if(f!=r)
				{
					f=f->next;
					delete t;
				}
				else
				{
					f='\0';
					r='\0';
					delete t;
				}
				return m;
			}
		}
};

template <class T>
class sta
{
	public:
		node<T>* info;
		sta *next;
};

template <class T>
class stack
{
	public:
		sta<T>* top;
		stack()
		{
			top=NULL;
		}
		
		int isempty()
		{
			if(top==NULL)
				return 1;
			else
				return 0;
		}
		
		void push(node<T> *p)
		{
			sta<T> *t=new sta<T>;
			t->info=p;
			t->next='\0';
			if(top=='\0')
				top=t;
			else
			{
				t->next=top;
				top=t;
			}
		}
		
		node<T>* pop()
		{
			if(isempty())
			{
				cout<<"\nElement can't be deleted...";
				getch();
				return 0;
			}
			else
			{
				sta<T> *t=top;
				node<T> *r=top->info;
				if(top->next=='\0')
					top='\0';
				else
					top=top->next;
				delete t;
				return r;
			}
		}
};

template <class T>
class tree
{
    public:
        node<T> *root;
        node<T> *temp;
        tree()
        {
            root=NULL;
        }
        void insert(T);
        void inordert(node<T> *p);
        void preordert(node<T> *p);
        void postordert(node<T> *p);
        node<T>* search(T);
        node<T>* predecessor(T);
        node<T>* successor(T);
        void deletmerp(T);
        void deletmers(T);
        void deletcpyp(T);
        void deletcpys(T);
        void mirror_imagei(node<T> *);
        void mirror_imagepost(node<T> *);
        void mirror_imagepre(node<T> *);
        void count(node<T> *,int &,int &);
        int height(node<T> *);
        void breadthfirstraversal();
        void iter_inorder();
		void iter_preorder();
		void iter_postorder();
};

template <class T>
void tree<T>::insert(T val)
{
    temp=new node<T>;
    temp->data=val;
    temp->left='\0';
    temp->right='\0';
    if(root==NULL)
        root=temp;
    else
    {
        node<T> *p=root;
        node<T> *previous;
        while(p!=NULL)
        {
            previous=p;
            if(val==p->data)
            {
                cout<<"\nRepeated values are not allowed...";
                getch();
                return;
            }
            else if(val<p->data)
                p=p->left;
            else if(val>p->data)
                p=p->right;
        }
        if(val<previous->data)
            previous->left=temp;
        else if(val>previous->data)
            previous->right=temp;
    }
    cout<<"\nElement inserted successfully...";
}

template <class T>
void tree<T>::inordert(node<T> *p)
{
    if(p!='\0')
    {
        inordert(p->left);
        cout<<p->data<<" ";
        inordert(p->right);
    }
}

template <class T>
void tree<T>::preordert(node<T> *p)
{
    if(p!='\0')
    {
        cout<<p->data<<" ";
        preordert(p->left);
        preordert(p->right);
    }
}

template <class T>
void tree<T>::postordert(node<T> *p)
{
    if(p!='\0')
    {
        postordert(p->left);
        postordert(p->right);
        cout<<p->data<<" ";
    }
}

template <class T>
node<T>* tree<T>::search(T val)
{
    node<T> *temp;
    temp=root;
    node<T> *pp=temp;
    while(temp!='\0')
    {
        if(val<temp->data)
        {
            pp=temp;
            temp=temp->left;
        }
        else if(val>temp->data)
        {
            pp=temp;
            temp=temp->right;
        }
        else if(val==temp->data)
        {
            cout<<"\nThe parent of "<<val<<" is "<<pp->data;
            cout<<"\nElement found!!!";
            getch();
            return temp;
        }
    }
    if(temp=='\0')
    {
        cout<<"\nElement not found!!!";
        getch();
        return temp;
    }
}

template <class T>
node<T>* tree<T>::predecessor(T ele)
{
    node<T> *p=search(ele);
    if(p=='\0')
    {
        cout<<"\nPredecessor can't be found...";
        return p;
    }
    cout<<"\nThe predecessor is:";
    if(p->left!='\0')
        p=p->left;
    while(p->right!='\0')
        p=p->right;
    cout<<p->data;
    return p;
}

template <class T>
node<T>* tree<T>::successor(T ele)
{
    node<T> *p=search(ele);
    if(p=='\0')
    {
        cout<<"\nSuccessor can't be found...";
        getch();
        return p;
    }
    cout<<"\nThe successor is:";
    if(p->right!='\0')
        p=p->right;
    while(p->left!='\0')
        p=p->left;
    cout<<p->data;
    getch();
    return p;
}

template <class T>
void tree<T>::deletmerp(T val)
{
    node<T> *temp;
    temp=root;
    node<T> *pp=temp;
    while(temp!='\0')
    {
        if(val<temp->data)
        {
            pp=temp;
            temp=temp->left;
        }
        else if(val>temp->data)
        {
            pp=temp;
            temp=temp->right;
        }
        else if(val==temp->data)
        {
            if(temp->left=='\0' && temp->right=='\0')
            {
                if(temp->data<pp->data)
                    pp->left='\0';
                else
                    pp->right='\0';
                delete temp;
                break;
            }
            else if(temp->left!='\0' && temp->right=='\0')
            {
                if(temp==pp->left)
                    pp->left=temp->left;
                else
                    pp->right=temp->left;
                delete temp;
                break;
            }
            else if(temp->left=='\0' && temp->right!='\0')
            {
                if(temp==pp->right)
                    pp->right=temp->right;
                else
                    pp->left=temp->right;
                delete temp;
                break;
            }
            else
            {
                node<T> *lc=temp->left;
                node<T> *rc=temp->right;
                node<T>* pred=predecessor(val);
                if(pred=='\0')
                {
                    cout<<"\nElement can't be deleted...";
                    return;
                }
                else if(pp->left==temp)
                {
                    pred->right=rc;
                    pp->left=lc;
                }
            	else if(pp==temp)
            	{
            		pred->right=rc;
            		root=lc;
            	}
                else 
                {
					pred->right=rc;
                    pp->right=lc;
                }
                delete temp;
                break;
            }
        }
    }
    cout<<"\nElement deleted successfully...";
}

template <class T>
void tree<T>::deletmers(T val)
{
    node<T> *temp;
    temp=root;
    node<T> *pp=temp;
    while(temp!='\0')
    {
        if(val<temp->data)
        {
            pp=temp;
            temp=temp->left;
        }
        else if(val>temp->data)
        {
            pp=temp;
            temp=temp->right;
        }
        else if(val==temp->data)
        {
            if(temp->left=='\0' && temp->right=='\0')
            {
                if(temp->data<pp->data)
                    pp->left='\0';
                else
                    pp->right='\0';
                delete temp;
                break;
            }
            else if(temp->left!='\0' && temp->right=='\0')
            {
                if(temp==pp->left)
                    pp->left=temp->left;
                else
                    pp->right=temp->left;
                delete temp;
                break;
            }
            else if(temp->left=='\0' && temp->right!='\0')
            {
                if(temp==pp->right)
                    pp->right=temp->right;
                else
                    pp->left=temp->right;
                delete temp;
                break;
            }
            else
            {
                node<T> *lc=temp->left;
                node<T> *rc=temp->right;
                node<T>* suc=successor(val);
                if(suc=='\0')
                {
                    cout<<"\nElement can't be deleted...";
                    return;
                }
                else if(pp->left==temp)
                {
                    suc->left=lc;
                    pp->left=rc;
                }
                else if(pp=temp)
                {
                	suc->left=lc;
                	root=rc;
                }
                else 
                {
					suc->left=lc;
                    pp->right=rc;
                }
                delete temp;
                break;
            }
        }
    }
    cout<<"\nElement deleted successfully...";
}

template <class T>
void tree<T>::deletcpyp(T val)
{
    node<T> *temp;
    temp=root;
    node<T> *pp=temp;
    while(temp!='\0')
    {
        if(val<temp->data)
        {
            pp=temp;
            temp=temp->left;
        }
        else if(val>temp->data)
        {
            pp=temp;
            temp=temp->right;
        }
        else if(val==temp->data)
        {
            if(temp->left=='\0' && temp->right=='\0')
            {
                if(temp->data<pp->data)
                    pp->left='\0';
                else
                    pp->right='\0';
                delete temp;
                break;
            }
            else if(temp->left!='\0' && temp->right=='\0')
            {
                if(temp==pp->left)
                    pp->left=temp->left;
                else
                    pp->right=temp->left;
                delete temp;
                break;
            }
            else if(temp->left=='\0' && temp->right!='\0')
            {
                if(temp==pp->right)
                    pp->right=temp->right;
                else
                    pp->left=temp->right;
                delete temp;
                break;
            }
            else
            {
                node<T>* pred=predecessor(val);
                if(pred=='\0')
                {
                    cout<<"\nElement can't be deleted...";
                    return;
                }
                node<T>* lc=pred->left;
                node<T>* pt;
                pt=temp;
                if(pt->left==pred)
                    pt=temp;
                else
                {
                    pt=pt->left;
                    while(pt->right!=pred)
                        pt=pt->right;
                }
                temp->data=pred->data;
                if(lc=='\0')
                    pt->right='\0';
                else
                    pt->right=lc;
                delete pred;
                break;
            }
        }
    }
    cout<<"\nElement deleted successfully...";              
}

template <class T>
void tree<T>::deletcpys(T val)
{
    node<T> *temp;
    temp=root;
    node<T> *pp=temp;
    while(temp!='\0')
    {
        if(val<temp->data)
        {
            pp=temp;
            temp=temp->left;
        }
        else if(val>temp->data)
        {
            pp=temp;
            temp=temp->right;
        }
        else if(val==temp->data)
        {
            if(temp->left=='\0' && temp->right=='\0')
            {
                if(temp->data<pp->data)
                    pp->left='\0';
                else
                    pp->right='\0';
                delete temp;
                break;
            }
            else if(temp->left!='\0' && temp->right=='\0')
            {
                if(temp==pp->left)
                    pp->left=temp->left;
                else
                    pp->right=temp->left;
                delete temp;
                break;
            }
            else if(temp->left=='\0' && temp->right!='\0')
            {
                if(temp==pp->right)
                    pp->right=temp->right;
                else
                    pp->left=temp->right;
                delete temp;
                break;
            }
            else
            {
                node<T>* suc=successor(val);
                if(suc=='\0')
                {
                    cout<<"\nElement can't be deleted...";
                    return;
                }
                node<T>* rc=suc->right;
                node<T>* pt;
                pt=temp;
                if(pt->right==suc)
                    pt=temp;
                else
                {
                    pt=pt->right;
                    while(pt->left!=suc)
                        pt=pt->left;
                }
                temp->data=suc->data;
                if(rc=='\0')
                    pt->left='\0';
                else
                    pt->left=rc;
                delete suc;
                break;
            }
        }
    }
    cout<<"\nElement deleted successfully...";
}

template <class T>
void tree<T>::mirror_imagei(node<T> *p)
{
    if(p!='\0')
    {
        mirror_imagei(p->left);
        node<T> *t=p->left;
        p->left=p->right;
        p->right=t;
        mirror_imagei(p->left);
    }
}

template <class T>
void tree<T>::mirror_imagepost(node<T> *p)
{
    if(p!='\0')
    {
        mirror_imagepost(p->left);
        mirror_imagepost(p->right);
        node<T> *t=p->left;
        p->left=p->right;
        p->right=t;
    }
}

template <class T>
void tree<T>::mirror_imagepre(node<T> *p)
{
    if(p!='\0')
    {
        node<T> *t=p->left;
        p->left=p->right;
        p->right=t;
        mirror_imagepre(p->left);
        mirror_imagepre(p->right);
    }
} 

template <class T>
void tree<T>::count(node<T> *p,int &cl,int &cnl)
{
	if(p!='\0')
	{
		if(p->left!='\0' || p->right!='\0')
			cnl++;
		else
			cl++;
		count(p->left,cl,cnl);
		count(p->right,cl,cnl);
	}
}


template <class T>
int tree<T>::height(node<T> *p)
{
	if(p!='\0')
	{
		int lh=height(p->left);
		int rh=height(p->right);
		if(lh>rh)
			return 1+lh;
		else
			return 1+rh;
	}
	else
		return 0;
}

template <class T>
void tree<T>::breadthfirstraversal()
{
	node<T> *p=root;
	que<T> q;
	if(p=='\0')
	{
		cout<<"Tree doesn't exists...";
		return;
	} 
	else
	{
		q.enque(p);
		while(!q.isempty())
		{
			p=q.deque();
			cout<<p->data<<" ";
			if(p->left!='\0')
				q.enque(p->left);
			if(p->right!='\0')
				q.enque(p->right);
		}
	}
}

template <class T>
void tree<T>::iter_inorder()
{
	node<T> *p=root;
	stack<T> s;
	if(p=='\0')
	{
		cout<<"\nTree doesn't exist...";
		getch();
		return;
	}
	else
	{
		while(p!='\0')
		{
			while(p!='\0')
			{
				if(p->right!='\0')
					s.push(p->right);
				s.push(p);
				p=p->left;
			}
			p=s.pop();
			while(!s.isempty() && p->right=='\0')
			{
				cout<<p->data<<" ";
				p=s.pop();
			}
			cout<<p->data<<" ";
			if(!s.isempty())
				p=s.pop();
			else
				p='\0';
		}
	}
}

template <class T>
void tree<T>::iter_preorder()
{
	node<T> *p=root;
	stack<T> s;
	if(p!='\0')
	{
		s.push(p);
		while(!s.isempty())
		{
			p=s.pop();
			cout<<p->data<<" ";
			if(p->right!='\0')
				s.push(p->right);
			if(p->left!='\0')
				s.push(p->left);
		}
	}
}

template <class T>
void tree<T>::iter_postorder()
{
	node<T> *p=root;
	node<T> *q=root;
	stack<T> s;
	while(p!='\0')
	{
		for(;p->left!='\0';p=p->left)
			s.push(p);
		while(p!='\0' && (p->right=='\0' || p->right==q))
		{
			cout<<p->data<<" ";
			q=p;
			if(s.isempty())
				return;
			else
				p=s.pop();
		}
		s.push(p);
		p=p->right;
	}
}

int main()
{
    tree<int> obj;
    int a,b,z,val,h;
    int cl=0;
	int cnl=0;
    do
    {
        system("cls");
        cout<<"The menu is:"
            <<"\n1.Insert in the tree and Display the tree"
            <<"\n\t(1)inorder(LNR)"
            <<"\n\t(2)preorder(NLR)"
            <<"\n\t(3)postordder(LRN)"
            <<"\n2.Search an element in the tree"
            <<"\n3.Finding predecessor "
            <<"& successor of element in the tree"
            <<"\n4.Delete an element from the tree(merging)"
            <<"\n\t(1)using predecessor"
            <<"\n\t(2)using successor"
            <<"\n5.Delete an element from the tree(copy)"
            <<"\n\t(1)using predecessor"
            <<"\n\t(2)using successor"
            <<"\n6.Find mirror image of tree according to"
            <<"\n\t(1)inorder"
            <<"\n\t(2)postorder"
            <<"\n\t(3)preorder"
            <<"\n7.Count no. of leaf and non-leaf nodes in the tree"
            <<"\n8.Determine height of the tree"
            <<"\n9.Breadth first traverse the tree"
            <<"\n10.Display the tree(iteratively)"
			<<"\n\t(1)inorder(LNR)"
            <<"\n\t(2)preorder(NLR)"
            <<"\n\t(3)postordder(LRN)"
			<<"\n11.Exit";
        cout<<"\nEnter your choice:";
        cin>>a;
        switch(a)
        {
            case 1:cout<<"\nEnter the element to be inserted:";
                    cin>>z;
                    obj.insert(z);
                    cout<<endl;
                    obj.inordert(obj.root);
                    cout<<endl;
                    obj.preordert(obj.root);
                    cout<<endl;
                    obj.postordert(obj.root);
                    cout<<endl;
                    getch();
                    break;
            case 2:cout<<"\nEnter the element to be searched:";
                    cin>>val;
                    obj.search(val);
                    break;
            case 3:cout<<"\nEnter the element whose predecessor & successor is to be found:";
                    cin>>val;
                    obj.predecessor(val);
                    obj.successor(val);
                    break;
            case 4:cout<<"\nEnter the element to be deleted:";
                    cin>>val;
                    cout<<"\nEnter your choice:";
                    cin>>b;
                    switch(b)
                    {
                        case 1:obj.deletmerp(val);
                                cout<<endl;
                                obj.inordert(obj.root);
                                cout<<endl;
                                obj.preordert(obj.root);
                                cout<<endl;
                                obj.postordert(obj.root);
                                cout<<endl;
                                getch();
                                break;
                        case 2:obj.deletmers(val);
                                cout<<endl;
                                obj.inordert(obj.root);
                                cout<<endl;
                                obj.preordert(obj.root);
                                cout<<endl;
                                obj.postordert(obj.root);
                                cout<<endl;
                                getch();
                                break;
                        default:cout<<"\nWrong choice is entered...";
                                getch();
                                break;
                    }
                    break;
            case 5:cout<<"\nEnter the element to be deleted:";
                    cin>>val;
                    cout<<"\nEnter your choice:";
                    cin>>b;
                    switch(b)
                    {
                        case 1:obj.deletcpyp(val);
                                cout<<endl;
                                obj.inordert(obj.root);
                                cout<<endl;
                                obj.preordert(obj.root);
                                cout<<endl;
                                obj.postordert(obj.root);
                                cout<<endl;
                                getch();
                                break;
                        case 2:obj.deletcpys(val);
                                cout<<endl;
                                obj.inordert(obj.root);
                                cout<<endl;
                                obj.preordert(obj.root);
                                cout<<endl;
                                obj.postordert(obj.root);
                                cout<<endl;
                                getch();
                                break;
                        default:cout<<"\nWrong choice is entered...";
                                getch();
                                break;
                    }
                    break;
            case 6:cout<<"\nEnter your choice:";
                    cin>>b;
                    switch(b)
                    {
                        case 1:cout<<"\nInorder display before mirror image:"<<endl;
                                obj.inordert(obj.root);
                                obj.mirror_imagei(obj.root);
                                cout<<"\nInorder display after mirror image:"<<endl;
                                obj.inordert(obj.root);
                                getch();
                                break;
                        case 2:cout<<"\nPostorder display before mirror image:"<<endl;
                                obj.postordert(obj.root);
                                obj.mirror_imagepost(obj.root);
                                cout<<"\nPostorder display after mirror image:"<<endl;
                                obj.postordert(obj.root);
                                getch();
                                break;
                        case 3:cout<<"\nPreorder display before mirror image:"<<endl;
                                obj.preordert(obj.root);
                                obj.mirror_imagepre(obj.root);
                                cout<<"\nPreorder display after mirror image:"<<endl;
                                obj.preordert(obj.root);
                                getch();
                                break;
                        default:cout<<"\nWrong choice is entered...";
                                getch();
                                break;
                    }
                    break;
            case 7:obj.count(obj.root,cl,cnl);
					cout<<"\nThe no. of leaf nodes in tree are:"<<cl;
					cout<<"\nThe no. of non-leaf nodes in tree are:"<<cnl;
					getch();
					break;
			case 8:h=obj.height(obj.root);
					cout<<"\nThe height of tree is:"<<h;
					getch();
					break;
			case 9:obj.breadthfirstraversal();
					getch();
					break;
			case 10:obj.iter_inorder();
					cout<<endl;
					obj.iter_preorder();
					cout<<endl;
					obj.iter_postorder();
					getch();
					break;
            case 11:exit(0);
                    getch();
                    break;
            default:cout<<"\nWrong choice is entered...";
                    getch();
                    break;
        }
    }while(a!=11);
    getch();
    return 0;
}
