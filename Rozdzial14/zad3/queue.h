#ifndef QUEUE_H_
#define QUEUE_H_


template <class Type>
class QueueTp
{
    private:        
        struct Node { Type item; struct Node * next;};
        enum {Q_SIZE = 10};
        Node * front;       
        Node * rear;        
        int items;          
        const int qsize;        
        QueueTp(const QueueTp & q) : qsize(0) { }
        QueueTp & operator=(const QueueTp & q) { return *this;}
    public:
        QueueTp(int qs = Q_SIZE);        
        ~QueueTp();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Type &item); 
        bool dequeue(Type &item);       
};

template <class Type>
QueueTp<Type>::QueueTp(int qs) : qsize(qs)
{
    front = rear = nullptr;      
    items = 0;
}

template <class Type>
QueueTp<Type>::~QueueTp()
{
    Node * temp;
    while (front != nullptr)    
    {
        temp = front;         
        front = front->next;  
        delete temp;          
    }
}

template <class Type>
bool QueueTp<Type>::isempty() const
{
    return items == 0;
}

template <class Type>
bool QueueTp<Type>::isfull() const
{
    return items == qsize;
}

template <class Type>
int QueueTp<Type>::queuecount() const
{
    return items;
}

template <class Type>
bool QueueTp<Type>::enqueue(const Type & item)
{
    if (isfull())
        return false;
    Node * add = new Node;     
    add->item = item;          
    add->next = nullptr;          
    items++;
    if (front == nullptr)         
        front = add;           
    else
        rear->next = add;      
    rear = add;                
    return true;
}

template <class Type>
bool QueueTp<Type>::dequeue(Type & item)
{
    if (front == nullptr)
        return false;
    item = front->item;    
    items--;
    Node * temp = front;   
    front = front->next;   
    delete temp;           
    if (items == 0)
        rear = nullptr;
    return true;
}

#endif

