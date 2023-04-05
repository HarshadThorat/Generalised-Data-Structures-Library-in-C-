#include<iostream>
using namespace std;
#pragma pack(1)

template<class T>
struct snode
{
    T data;
    struct snode *next;
};


template<class T>
struct dnode
{
    T data;
    struct dnode *next;
    struct dnode *prev;
};


////////////////////////////////////////////////////////////////////
//             SINGLY LINEAR LINKEDLIST
////////////////////////////////////////////////////////////////////



template<class T>
class SinglyLL
{
    public:
        struct snode<T> * First;

        SinglyLL();
        void InsertFirst(T No);
        void InsertLast(T no);
        void InsertAtPosition(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);


        void Display();
        int Count();
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T No)
{
    struct snode<T> * newn = new struct snode<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template<class T>
void SinglyLL<T>:: InsertLast(T no)
{
    struct snode<T> * newn = new struct snode<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct snode<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

template<class T>
void SinglyLL<T> :: InsertAtPosition(T no, int ipos)
{
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct snode<T> * newn = new struct snode<T>;
        struct snode<T> * temp = First;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyLL<T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct snode<T> * temp = First;

        First = First->next;
        delete temp;
    }
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct snode<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template<class T>
void SinglyLL<T> :: DeleteAtPosition(int ipos)
{
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct snode<T> * temp1 = First;
        struct snode<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        } 
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template<class T>
void SinglyLL<T> :: Display()
{
    struct snode<T> *temp = First;
    cout<<"Elements of the Linked List are : "<<"\n";

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |-> ";
        temp = temp->next;
    } 
    cout<<"NULL\n";
}

template<class T>
int SinglyLL<T> :: Count()
{
    struct snode<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    } 
    return iCnt;;
}

////////////////////////////////////////////////////////////////////
//             SINGLY CIRCULAR LINKEDLIST
////////////////////////////////////////////////////////////////////


template<class T>
class SinglyCL
{
    public:
        struct snode<T> * First;
        struct snode<T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
}; 

template<class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct snode<T> * newn = new struct snode<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct snode<T> * newn = new struct snode<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T> :: InsertAtPosition(T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct snode<T> * newn = NULL;
    struct snode<T> * temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct snode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }

}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;   //*Last = NULL;  
    }
    else
    {
        (First) = (First)->next;
        delete((Last)->next);
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    struct snode<T> * temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;     
    }
    else
    {
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete(Last);  //free(temp->next)
        (Last) = temp;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T> :: DeleteAtPosition(int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct snode<T> * temp1 = NULL;
    struct snode<T> * temp2 = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }
}

template<class T>
void SinglyCL<T> :: Display()
{
    cout<<"Elements of Linked list are : "<<"\n";
    struct snode<T> * temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
    struct snode<T> * temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}



////////////////////////////////////////////////////////////////////
//             DOUBLY LINEAR LINKEDLIST
////////////////////////////////////////////////////////////////////



template<class T>
class DoublyLL
{
    public:
        struct dnode<T> * First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct dnode<T> * newn = new struct dnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev= newn;
        First = newn;
    }
}


template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct dnode<T> * newn = new struct dnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct dnode<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void DoublyLL<T> :: InsertAtPosition(T no,int ipos)
{
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct dnode<T> * newn = new struct dnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct dnode<T> * temp = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}


template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next; 
        delete First->prev;
        First->prev = NULL;
    }
}


template<class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct dnode<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }   
        delete temp->next;
        temp->next = NULL;
    }
}

template<class T>
void DoublyLL<T> :: DeleteAtPosition(int ipos)
{
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct dnode<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        
        struct dnode<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
}

template<class T>
void DoublyLL<T> :: Display()
{
    cout<<"Elements of the Linked List are : "<<"\n";
    struct dnode<T> * temp = First;

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


template<class T>
int DoublyLL<T> :: Count()
{
    int iCnt = 0;

    struct dnode<T> * temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}




////////////////////////////////////////////////////////////////////
//             DOUBLY CIRCULAR LINKEDLIST
////////////////////////////////////////////////////////////////////




template<class T>
class DoublyCL
{
    public:
        struct dnode<T> * First;
        struct dnode<T> * Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();
};

template<class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void DoublyCL<T> ::  InsertFirst(T no)
{
    struct dnode<T> * newn = new struct dnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = Last =  newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;

    }
    (First)->prev = Last;
    (Last)->next = First;

}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct dnode<T> * newn = new struct dnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = Last =  newn;

    }
    else
    {
        (Last)->next = newn;
        newn->prev = Last;
        Last = newn;

    }
    (First)->prev = Last;
    (Last)->next = First;

}

template<class T>
void DoublyCL<T> :: InsertAtPosition(T no,int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct dnode<T> * newn = NULL;
    struct dnode<T> * temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos < 1)
    {
        InsertFirst(no);
    }
    else if(ipos > NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(iCnt = 1; iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev= newn;

        temp->next = newn;
        newn->prev = temp;
    }
}


template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL  && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = (First)->next;
        delete First->prev;       //free((Last)->next); 
        (First)->prev = Last;
        (Last)->next = First;
    }
    
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{

    if(First == NULL  && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = (Last)->prev;
        delete First->prev;      //free((*Last)->next);
        (First)->prev = Last;
        (Last)->next = First;
    }   
}


template<class T>
void DoublyCL<T> :: DeleteAtPosition(int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct dnode<T> * temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos < 1)
    {
        DeleteFirst();
    }
    else if(ipos > NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(iCnt = 1; iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
    }
}

template<class T>
void DoublyCL<T> :: Display()
{
    struct dnode<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of linked list are : "<<"\n"; 

    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;

    }while( temp != Last->next );
    cout<<"NULL\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct dnode<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while((temp != Last->next));
    return iCnt;
}




////////////////////////////////////////////////////////////////////
//             STACK
////////////////////////////////////////////////////////////////////




template<class T>
class Stack
{
    public:
        struct snode<T> * First;

        Stack();

        void Push(T no);   //InsertFirst
        T Pop();           //DeleteFirst
        void Display();
        int Count();
};


template<class T>
Stack<T> :: Stack()
{
    First = NULL;
}

template<class T>
void Stack<T> :: Push(T no)
{
    struct snode<T> * newn = new struct snode<T>;

    newn->data= no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn; 
    }
} 

template<class T>
T Stack<T> :: Pop()
{
    if(First == NULL)
    {
        cout<<"Unable Poped elements as stack is empty\n";
        return (T)-1;
    }
    else
    {
        struct snode<T> * temp = First;

        First = First->next;
        delete temp;     
    }
}

template<class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        cout<<"Elements of the Stack are : \n";
        struct snode<T> * temp = First;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" |-> "; 
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

template<class T>
int Stack<T> :: Count()
{
    int iCnt = 0;

    struct snode<T> * temp = First;

    while(temp != NULL)
    {
        iCnt++; 
        temp = temp->next;
    }
    return iCnt;

}



////////////////////////////////////////////////////////////////////
//             QUEUE
////////////////////////////////////////////////////////////////////



template<class T>
class Queue
{
    public:
        struct snode<T> * First;

        Queue();

        void EnQueue(int no);  //InsertLast
        int DeQueue();         //DeleteFirst
        void Display();
        int Count();
};


template<class T>
Queue<T> :: Queue()
{
    First = NULL;
}

template<class T>
void Queue<T> :: EnQueue(int no)
{

    struct snode<T> * newn = new struct snode<T>;
    struct snode<T> *  temp = First;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }     
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }         
        temp->next = newn;
    }
}

template<class T>
int Queue<T> :: DeQueue()
{
    if(First == NULL)
    {
        cout<<"Unable to Pop the elements as stack is empty\n";
        return -1;
    }
    else
    {
        struct snode<T> * temp = First;

        First = First->next;
        delete temp;
    }
}

template<class T>
void Queue<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is Empty "<<"\n";
    }
    else
    {
        cout<<"Elements of the stack are : "<<"\n";

        struct snode<T> * temp = First;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" |-> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

template<class T>
int Queue<T> :: Count()
{
    
    int iCnt = 0;

    struct snode<T> * temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;

}


/////////////////////////////////////////////////////////////////////////
//             MAIN FUNCTON IS STARTED
//////////////////////////////////////////////////////////////////////


int main()
{
    int iRet = 0;
    cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Singly Linear Linked List\n";

	cout<<"\nInteger data type\n";


    SinglyLL <int>si1obj;

    si1obj.InsertFirst(51);
    si1obj.InsertFirst(21);
    si1obj.InsertFirst(11);
    si1obj.InsertLast(101);
    si1obj.InsertLast(111);
    si1obj.InsertLast(121);
    si1obj.InsertAtPosition(105,5);
    si1obj.DeleteAtPosition(5);
    si1obj.DeleteFirst();
    si1obj.DeleteLast();
    si1obj.Display();
    iRet = si1obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\nCharecter data type\n";

    SinglyLL <char>sc2obj;

	sc2obj.InsertFirst('a');
    sc2obj.InsertFirst('b');
    sc2obj.InsertFirst('a');
    sc2obj.InsertLast('e');
    sc2obj.InsertLast('f');
    sc2obj.InsertLast('g');
    sc2obj.InsertAtPosition('d',5);
    sc2obj.DeleteAtPosition(5);
    sc2obj.DeleteFirst();
    sc2obj.DeleteLast();
    sc2obj.Display();
    iRet = sc2obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Singly Circular Linked List\n";

	cout<<"\nInteger data type\n";

    SinglyCL <int>si3obj;

    si3obj.InsertFirst(51);
    si3obj.InsertFirst(21);
    si3obj.InsertFirst(11);
    si3obj.InsertLast(101);
    si3obj.InsertLast(111);
    si3obj.InsertLast(121);
    si3obj.InsertAtPosition(105,5);
    si3obj.DeleteAtPosition(5);
    si3obj.DeleteFirst();
    si3obj.DeleteLast();
    si3obj.Display();
    iRet = si3obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\nCharecter data type\n";

    SinglyCL <char>sc4obj;

	sc4obj.InsertFirst('a');
    sc4obj.InsertFirst('b');
    sc4obj.InsertFirst('a');
    sc4obj.InsertLast('e');
    sc4obj.InsertLast('f');
    sc4obj.InsertLast('g');
    sc4obj.InsertAtPosition('d',5);
    sc4obj.DeleteAtPosition(5);
    sc4obj.DeleteFirst();
    sc4obj.DeleteLast();
    sc4obj.Display();
    iRet = sc4obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


    cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Doubly Linear Linked List\n";

	cout<<"\nInteger data type\n";


    DoublyLL <int>di5obj;

    di5obj.InsertFirst(51);
    di5obj.InsertFirst(21);
    di5obj.InsertFirst(11);
    di5obj.InsertLast(101);
    di5obj.InsertLast(111);
    di5obj.InsertLast(121);
    di5obj.InsertAtPosition(105,5);
    di5obj.DeleteAtPosition(5);
    di5obj.DeleteFirst();
    di5obj.DeleteLast();
    di5obj.Display();
    iRet = di5obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\nCharecter data type\n";

    DoublyLL <char>dc6obj;

	dc6obj.InsertFirst('a');
    dc6obj.InsertFirst('b');
    dc6obj.InsertFirst('a');
    dc6obj.InsertLast('e');
    dc6obj.InsertLast('f');
    dc6obj.InsertLast('g');
    dc6obj.InsertAtPosition('d',5);
    dc6obj.DeleteAtPosition(5);
    dc6obj.DeleteFirst();
    dc6obj.DeleteLast();
    dc6obj.Display();
    iRet = dc6obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Doubly Circular Linked List\n";

	cout<<"\nInteger data type\n";

    DoublyCL <int>di7obj;

    di7obj.InsertFirst(51);
    di7obj.InsertFirst(21);
    di7obj.InsertFirst(11);
    di7obj.InsertLast(101);
    di7obj.InsertLast(111);
    di7obj.InsertLast(121);
    di7obj.InsertAtPosition(105,5);
    di7obj.DeleteAtPosition(5);
    di7obj.DeleteFirst();
    di7obj.DeleteLast();
    di7obj.Display();
    iRet = di7obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\nCharecter data type\n";

    DoublyCL <char>dc8obj;

	dc8obj.InsertFirst('a');
    dc8obj.InsertFirst('b');
    dc8obj.InsertFirst('a');
    dc8obj.InsertLast('e');
    dc8obj.InsertLast('f');
    dc8obj.InsertLast('g');
    dc8obj.InsertAtPosition('d',5);
    dc8obj.DeleteAtPosition(5);
    dc8obj.DeleteFirst();
    dc8obj.DeleteLast();
    dc8obj.Display();
    iRet = dc8obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Stack Data Structure\n";
	cout<<"\nInteger data type\n";

    Stack <int>Sobj;
    
    Sobj.Push(101);
    Sobj.Push(51);
    Sobj.Push(21);
    Sobj.Push(11);
    Sobj.Display();
    iRet = Sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    Sobj.Pop();
    Sobj.Display();
    iRet = Sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    cout<<"\nCharacter data type\n";

    Stack <char>Cobj;
    
    Cobj.Push('d');
    Cobj.Push('c');
    Cobj.Push('b');
    Cobj.Push('a');
    Cobj.Display();
    iRet = Cobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    Cobj.Pop();
    Cobj.Display();
    iRet = Cobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";


	cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Queue Data Structure\n";
	cout<<"\nInteger data type\n";

    Queue <int>Qiobj;
    
    Qiobj.EnQueue(101);
    Qiobj.EnQueue(51);
    Qiobj.EnQueue(21);
    Qiobj.EnQueue(11);
    Qiobj.Display();
    iRet = Qiobj.Count();
    cout<<"DeQueue element is : "<<iRet<<"\n";
    
    Qiobj.DeQueue();
    Qiobj.Display();
    iRet = Qiobj.Count();
    cout<<"DeQueue element is : "<<iRet<<"\n";
    
    cout<<"\nCharacter data type\n";

    Queue <char>Qcobj;
    
    Qcobj.EnQueue('a');
    Qcobj.EnQueue('b');
    Qcobj.EnQueue('c');
    Qcobj.EnQueue('d');
    Qcobj.Display();
    iRet = Qcobj.Count();
    cout<<"DeQueue element is : "<<iRet<<"\n";
    
    Qcobj.DeQueue();
    Qcobj.Display();
    iRet = Qcobj.Count();
    cout<<"DeQueue element is : "<<iRet<<"\n";
    
}
