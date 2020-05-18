#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class HeapSort {

private:

  bool ( *mCompare ) ( Type data1, Type data2 ) ;

  void Heapify( Type* dataPtr, int index, int heapSize ) ;
  void BuildHeap( Type* dataPtr, int size ) ;

public:

  HeapSort( bool ( *compare ) ( Type data1, Type data2 ) ) ; // constructor
  ~HeapSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class HeapSort

template<class Type>
HeapSort<Type>::HeapSort( bool ( *compare ) ( Type data1, Type data2 ) ) { // constructor

  mCompare = compare ;

} // HeapSort<Type>::HeapSort()

template<class Type>
HeapSort<Type>::~HeapSort() { // destructor

  mCompare = NULL ;

} // HeapSort<Type>::~HeapSort()

template<class Type>
void HeapSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  int heapSize = size ;

  BuildHeap( dataPtr, size ) ;

  for ( int i = size - 1 ; i > 0 ; i-- ) {

    Type temp = dataPtr[0] ;
    dataPtr[0] = dataPtr[i] ;
    dataPtr[i] = temp ;

    heapSize-- ;

    Heapify( dataPtr, 0, heapSize ) ;

  } // for

} // HeapSort<Type>::Sort()

template<class Type>
void HeapSort<Type>::Heapify( Type* dataPtr, int index, int heapSize ) {

  int leftChildIndex = index * 2 + 1 ;
  int rightChildIndex = leftChildIndex + 1 ;
  int largestIndex = index ;

  if ( leftChildIndex < heapSize && mCompare( dataPtr[largestIndex], dataPtr[leftChildIndex] ) ) {
    largestIndex = leftChildIndex ;
  } // if

  if ( rightChildIndex < heapSize && mCompare( dataPtr[largestIndex], dataPtr[rightChildIndex] ) ) {
    largestIndex = rightChildIndex ;
  } // if

  if ( largestIndex != index ) {

    Type temp = dataPtr[index] ;
    dataPtr[index] = dataPtr[largestIndex] ;
    dataPtr[largestIndex] = temp ;

    Heapify( dataPtr, largestIndex, heapSize ) ;

  } // if

} // HeapSort<Type>::Heapify()

template<class Type>
void HeapSort<Type>::BuildHeap( Type* dataPtr, int size ) {

  for ( int i = size / 2 - 1 ; i >= 0 ; i-- ) {
    Heapify( dataPtr, i, size ) ;
  } // for

} // HeapSort<Type>::BuildHeap()

#endif // HEAP_SORT_H_INCLUDED

