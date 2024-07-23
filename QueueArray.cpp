
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
    maxSize = maxNumber;
    dataItems = new DataType[maxNumber];
    front = 0;
    back = -1;

}
//copy constructor
template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
    maxSize = other.maxSize;
    front = other.front;
    back = other.back;
    //delete old data
    delete[] dataItems;
    
    //create new data
    dataItems = new DataType[maxSize];
    //deep copy all elements
    for(int i = 0 ; i <maxSize; i++){
        dataItems[i]= other.dataItems[i];
        
    }
    
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
    if(this!=&other){
        maxSize = other.maxSize;
        front = other.front;
        back = other.back;
        //delete old data
        delete[] dataItems;
        
        //create new data
        dataItems = new DataType[maxSize];
        //deep copy all elements
        for(int i = 0 ; i <maxSize; i++){
            dataItems[i]= other.dataItems[i];
            
        }
        
    }
    return *this; //return the current array
    
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
    delete[] dataItems;
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
    //enqueue -> add to rear
   //check if array is full
    if(isFull()){
        throw logic_error("Cannot Enqueue, array is full");
    }
    else if(back==maxSize-1){
        back = 0;//circle arround
        dataItems[back]= newDataItem;

    }
    else{ //if its not empty
        back+=1; // otherwise back is increased
        dataItems[back]= newDataItem;

    }

    
    
    
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
    //dequeue -> remove from front
    //check if array is empty
    if(isEmpty()){
        throw logic_error("Cannot Dequeue, array is empty");

    }
    //otherwise access the front item to return
	DataType temp = dataItems[front];
    //we dont physically remove this element, only move the front up one
    if(front == maxSize-1){ //if the front is currently at the end off array, move it to index 0
        front = 0;
    }
    else if(front==back){ //the queue will be empty after we dequeue
        clear();
    }
    else{ //otherwise increment
        front++;
    }
    //return the previous front element
	return temp;
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
    //reset front and back, delete old array and create new
    front = 0;
    back = -1;
    delete[] dataItems;
    dataItems = new DataType[maxSize];
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
    //when the front and back are the same
    if(back==-1){

        //and return true;
        return true;
    }
    //otherwise its false
	return false;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
    //when thse conditions are met it is full
    if(((back + 1) % maxSize == front) && !isEmpty()){
        return true;
    }
    //otherwise there is still space to enqueue
	return false;
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
    if (isFull()) {
        throw logic_error("Cannot putFront, queue is full");
    }
    if (isEmpty() || front == 0) {
        // If empty or front at beginning, move front to the end
        front = maxSize - 1;
    }
    else {
            // Move front backward
            front--;
        }
    
    // Insert new data item at the front
    dataItems[front] = newDataItem;
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
	DataType temp = dataItems[back];
	return temp;
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
    if (isEmpty()) {
        return 0; // Return 0 if the queue is empty
    } 
    else if (front <= back) {
        return (back - front) + 1; // Return the count of elements in the queue
    } 
    else {
        return (maxSize - front) + (back + 1); // Handle wrap around 
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}
