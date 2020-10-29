#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first,*second,*third=NULL,*head=NULL; //all four pointers are global

struct Dnode
{
    struct Dnode *prev;
    int data;
    struct Dnode *next;
}*dfirst=NULL;

void create()
{
    int n,i;
    struct Node *t,*last;
    first = new Node;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the data of the nodes : ";
    cin>>first->data;
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        cin>>t->data;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2()
{
    int n,i;
    struct Node *t,*last;
    second = new Node;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the data of the nodes : ";
    cin>>second->data;
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=new Node;
        cin>>t->data;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display()
{
    struct Node *t= new Node;
    t=first;
    while(t!=NULL)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<"NULL"<<endl;
}

void nnodes()
{
    int c=0;
    struct Node *t= new Node;
    t=first;
    while(t)
    {
        c++;
        t=t->next;
    }
    cout<<"No. of nodes = "<<c<<endl;
}

int nodes()
{
    int c=0;
    struct Node *t= new Node;
    t=first;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}

void sum()
{
    int s=0;
    struct Node *t= new Node;
    t=first;
    while(t)
    {
        s+=t->data;
        t=t->next;
    }
    cout<<"Sum = "<<s<<endl;
}

void maxi()
{
    int x=INT_MIN;
    struct Node *t= new Node;
    t=first;
    while(t)
    {
        if(x<t->data);
            x=t->data;
        t=t->next;
    }
    cout<<"Max = "<<x<<endl;
}

void searchit()
{
    int c;
    cout<<"Enter key to search : ";
    cin>>c;
    struct Node *t= new Node;
    t=first;
    while(t)
    {
        if(c==t->data)
            {
            cout<<"Found"<<endl;
            return;
            }
        else
            t=t->next;
    }
    cout<<"Not Found"<<endl;
}

void moveHead()
{
    int c;
    cout<<"Enter key to search : ";
    cin>>c;
    struct Node *t,*q;
    t= new Node;
    t=first;q=NULL;
    if(t->data==c)
        return;
    while(t)
    {
        if(c==t->data)
        {
            q->next=t->next;
            t->next=first;
            first=t;
        }
        q=t;
        t=t->next;
    }
}

void insertit()
{
    int n;
    cout<<"Enter the position to insert the node : ";
    cin>>n;
    struct Node *t,*q;
    t=new Node;q=new Node;
    q=first;
    cout<<"Enter data of the node : ";
    cin>>t->data;
    t->next=NULL;
    if(n==1)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<n-2;i++)
            q=q->next;
        t->next=q->next;
        q->next=t;

    }
}

void insertLast()
{
    struct Node *t= new Node;
    struct Node *last=first;
    cout<<"Enter data of the node : ";
    cin>>t->data;
    t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
        while(last->next)
        {
            last=last->next;
        }
        last->next=t;
        last=t;
    }
}

void insertSort()
{
    struct Node *t,*p,*q;
    t=new Node;p=new Node;q=new Node;
     p=first;q=NULL;
    cout<<"Enter data of the node : ";
    cin>>t->data;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else if(t->data<first->data)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while(p->data<t->data)
        {
            q=p;
            p=p->next;
            if(!p)
            {
                q->next=t;
                return;
            }
        }
        t->next=q->next;
        q->next=t;
    }
}

void Deleteit()
{
    int n;
    cout<<"Enter the position of node to delete : ";
    cin>>n;
    struct Node *p,*q;
    p=first;q=NULL;
    if(n==1)
    {
        first=first->next;
        delete p;
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
    }
}

void isSorted()
{
    int x=INT_MIN;
    struct Node *t = new Node;
    t=first;
    while(t)
    {
        if(t->data<x)
            {
                cout<<"Not Sorted!"<<endl;
                return;
            }
        x=t->data;
        t=t->next;
    }
    cout<<"Sorted!"<<endl;
}

void removeDuplicate()
{
    struct Node *q=first;
    struct Node *p=first->next;
    while(p)
    {
        if(p->data!=q->data)
        {
            q=p;
            p=p->next;
        }
        else
        {
            q->next=p->next;
            delete p;
            p=q->next;
        }
    }
}

void Reverseit()
{
    struct Node *p=first;
    int a[nodes()],i=0;
    while(p)
    {
        a[i++]=p->data;
        p=p->next;
    }
    p=first;i--;
    while(p)
    {
        p->data=a[i--];
        p=p->next;
    }
}

void concat()
{
    create();
    create2();
    struct Node *p=first;
    while(p->next!=NULL)
        p=p->next;
    p->next=second;
    second=NULL;
}

void mergeit()
{
    create();
    create2();
    struct Node *last = new Node;
    last=NULL;

    if(first->data <= second->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
    {
        third=last=second;
        second=second->next;
        last->next=NULL;
    }

    while(first && second)
    {
        if(first->data <= second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
    else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }

    if(first)
        last->next=first;
    else
        last->next=second;

    first=third;
}

void isLoop()
{
    struct Node *p=first;
    struct Node *q=first;

    while(p && q && q->next)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
            cout<<"Loop detected";
    }
    cout<<"No Loop"<<endl;
}

void createcll()
{
    struct Node *t,*last;
    int n;
    cout<<"Enter the number of node : ";
    cin>>n;
    head = new Node;
    cout<<"Enter data of the nodes : ";
    cin>>head->data;
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new Node;
        cin>>t->data;
        t->next=head;
        last->next=t;
        last=t;
    }
}

void displaycll()
{
    struct Node *t=new Node;
    t=head;
    if(head==NULL)
        cout<<"head->NULL"<<endl;
    else
    {
        do{
        cout<<t->data<<"->";
        t=t->next;
        }while(t!=head);
        cout<<"head"<<endl;
    }
}

void insertcll()
{
    cout<<"Enter the position to enter the node : ";
    int n;
    cin>>n;
    struct Node *t,*p;
    t=new Node;
    cout<<"Enter node's data : ";
    cin>>t->data;
    p=head;
    if(head==NULL)
    {
        head=t;
        head->next=head;
    }
    else if(n==1)
    {
        while(p->next!=head)
            p=p->next;
        p->next=t;
        t->next=head;
        head=t;
    }
    else
    {
        for(int i=0;i<n-2;i++)
                p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

void nnodescll()
{
    int c=0;
    struct Node *t= new Node;
    t=head;
    if(head==NULL)
        cout<<"No. of nodes = "<<c<<endl;
    else
    {
        do
        {
            c++;
            t=t->next;
        }while(t!=head);
        cout<<"No. of nodes = "<<c<<endl;
    }
}

int nodescll()
{
    int c=0;
    struct Node *t= new Node;
    t=head;
    do
    {
        c++;
        t=t->next;
    }while(t!=head);
    return c;
}

void deletecll()
{
    struct Node *p,*q;
    p=head;q=NULL;
    int n;
    cout<<"Enter the position of the node to delete : ";
    cin>>n;
    if(head==NULL)
        return;
    else if(n==1)
    {
        while(p->next!=head)
            p=p->next;
        p->next=head->next;
        delete head;
        head=p->next;
    }
    else
    {
        for(int i=0;i<n-2;i++)
            {p=p->next;}
        q=p->next;
        p->next=q->next;
        delete p;
    }
}

void createdll()
{
    int n,i;
    struct Dnode *t,*last;
    dfirst = new Dnode;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the data of the nodes : ";
    cin>>dfirst->data;
    dfirst->next=NULL;
    dfirst->prev=NULL;
    last=dfirst;
    for(i=1;i<n;i++)
    {
        t=new Dnode;
        cin>>t->data;
        last->next=t;
        t->next=NULL;
        t->prev=last;
        last=t;
    }
}

void displaydll()
{
    struct Dnode *p = dfirst;
    cout<<"NULL<-"<<p->data;
    p=p->next;
    while(p)
    {
        cout<<"<=>"<<p->data;
        p=p->next;
    }
    cout<<"->NULL"<<endl;
}

void nnodesdll()
{
    struct Dnode *p = dfirst;
    int c=0;
    while(p)
    {   c++;
        p=p->next;
    }
    cout<<"Total no. of nodes = "<<c<<endl;
}

void insertdll()
{
    cout<<"Enter the position to enter the node : ";
    int n;
    cin>>n;
    struct Dnode *t,*p;
    t=new Dnode;
    cout<<"Enter node's data : ";
    cin>>t->data;
    t->next=NULL;t->prev=NULL;
    p=dfirst;
    if(dfirst==NULL)
        dfirst=t;
    else if(n==1)
    {
        t->next=dfirst;
        dfirst->prev=t;
        dfirst=t;
    }
    else
    {
        for(int i=0;i<n-2;i++)
            p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}

void deletedll()
{
    int n;
    cout<<"Enter the position of node to delete : ";
    cin>>n;
    struct Dnode *p;
    p=dfirst;

    if(dfirst==NULL)
        return;
    else if(n==1)
    {
        dfirst=dfirst->next;
        dfirst->prev=NULL;
        delete p;
    }
    else
    {
        for(int i=0;i<n-1;i++)
            p=p->next;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        delete p;
    }
}

void reversedll()
{
    struct Dnode *p=dfirst;
    struct Dnode *t;
    while(p)
    {
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            dfirst=p;
    }
}

void middle_node()
{
    double c= nodes();
    c=ceil(c/2);
    struct Node *p=first;
    for(int i=0;i<c-1;i++)
        p=p->next;
    cout<<"Middle Node : "<<p->data;
}

int main()
{
    int n;
    do{
    cout<<endl<<"*******Menu*******"<<endl;
    cout<<"1.  Create"<<endl;
    cout<<"2.  Display"<<endl;
    cout<<"3.  No. of Nodes"<<endl;
    cout<<"4.  Sum of all nodes"<<endl;
    cout<<"5.  Max"<<endl;
    cout<<"6.  Search"<<endl;
    cout<<"7.  Move to Head"<<endl;
    cout<<"8.  Insert"<<endl;
    cout<<"9.  Insert at last"<<endl;
    cout<<"10. Insert in Sorted Linked List"<<endl;
    cout<<"11. Delete"<<endl;
    cout<<"12. Sorted or not?"<<endl;
    cout<<"13. Remove Duplicate"<<endl;
    cout<<"14. Reverse"<<endl;
    cout<<"15. Concat"<<endl;
    cout<<"16. Merge"<<endl;
    cout<<"17. Detect Loop"<<endl;
    cout<<"18. Create a Circular Linked List"<<endl;
    cout<<"19. Display Circular Linked List"<<endl;
    cout<<"20. Insert in a Circular Linked List"<<endl;
    cout<<"21. No. of Nodes in Circular Linked List"<<endl;
    cout<<"22. Delete a node in a Circular Linked List"<<endl;
    cout<<"23. Create a Doubly Linked List"<<endl;
    cout<<"24. Display Doubly Linked List"<<endl;
    cout<<"25. No. of Nodes in Doubly Linked List"<<endl;
    cout<<"26. Insert in a Doubly Linked List"<<endl;\
    cout<<"27. Delete a node in a Doubly Linked List"<<endl;
    cout<<"28. Reverse a Doubly Linked List"<<endl;
    cout<<"29. Find the middle node of a Linked List"<<endl;
    cout<<"30. Exit"<<endl;
    cout<<endl<<"Enter your choice : ";

    cin>>n;

    switch(n)
        {
        case 1 : create();
                    break;
        case 2 : display();
                    break;
        case 3 : nnodes();
                    break;
        case 4 : sum();
                    break;
        case 5 : maxi();
                    break;
        case 6 : searchit();
                    break;
        case 7 : moveHead();
                    break;
        case 8 : insertit();
                    break;
        case 9 : insertLast();
                    break;
        case 10 : insertSort();
                    break;
        case 11 : Deleteit();
                    break;
        case 12 : isSorted();
                    break;
        case 13 : removeDuplicate();
                    break;
        case 14 : Reverseit();
                    break;
        case 15 : concat();
                    break;
        case 16 : mergeit();
                    break;
        case 17 : isLoop();
                    break;
        case 18 : createcll();
                    break;
        case 19 : displaycll();
                    break;
        case 20 : insertcll();
                    break;
        case 21 : nnodescll();
                    break;
        case 22 : deletecll();
                    break;
        case 23 : createdll();
                    break;
        case 24 : displaydll();
                    break;
        case 25 : nnodesdll();
                    break;
        case 26 : insertdll();
                    break;
        case 27 : deletedll();
                    break;
        case 28 : reversedll();
                    break;
        case 29 : middle_node();
                    break;
        case 30 :   break;
        default: cout<<"Try Again";
                    break;
        }
    }while(n!=30);
    cout<<endl<<"*************** Thank you! ***************"<<endl;
    return 0;
}