
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
    dataItem=nodeData;
    next= nextPtr;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
    //default
    front = NULL;
    back = NULL;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
    QueueNode *curr = other.front;

    while (curr != NULL){

    enqueue(curr->dataItem);

    curr = curr->next;

    }
    
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
    if (this != &other) {

            clear(); // Clear current queue

            QueueNode *curr = other.front;

            while (curr != NULL){
                enqueue(curr->dataItem);
                curr = curr->next;

            }

        }

        return *this;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
    clear();
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
    if(isFull()){
        throw logic_error("Cannot Enqueue, queue is full");
    }
    QueueNode* newNode = new QueueNode(newDataItem, nullptr);
    if (isEmpty()) {
        front = newNode;  // Update front if the queue was empty
    } else {
        back->next = newNode;  // Link the new node to the back of the queue
    }
    back = newNode;  // Update back to point to the new last node

}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
    QueueNode* temp = front;
    front = front->next; //reassign front
    DataType t = temp->dataItem;
    delete temp; //delete old front
	return t;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
    QueueNode* t;

    while ( front != NULL)

    {

    t = front;

    front = front->next;

    delete t;

    }
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	return (front==NULL);
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
    if(isFull()){
        throw logic_error("Cannot putFront, queue is full");
    }
    QueueNode* newNode = new QueueNode(newDataItem,front);
    front = newNode;

}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
    QueueNode* curr = front;
    while(curr->next!=NULL){
        curr=curr->next;
        
    }
	DataType temp = curr->dataItem;
	return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
    int counter;
    QueueNode* curr = front;
    while(curr->next!=NULL){
        curr=curr->next;
        counter++;
    }
    return counter;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}
