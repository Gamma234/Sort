#ifndef BUCKET_SORT_H_INCLUDED
#define BUCKET_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class BucketSort {

private:

  int ( *mGetNonNegativeInt ) ( Type data ) ;

  struct Node {
    Type data ;
    int dataNonNegativeInt ;
    Node* next ;
    Node() : next( NULL ), dataNonNegativeInt( -1 ) {} // constructor
    Node( Type d, int n ) : data( d ), dataNonNegativeInt( n ), next( NULL ) {} // constructor
  }** mListPtr ; // struct Node

  void FindMinMaxValue( int* nonNegativeNum, int& min, int& max, int size ) ;
  void InsertList( int index, Type newData, int nonNegativeInt ) ;
  void CreateList( int listSize ) ;
  void ReleaseList( int listSize ) ;

public:

  BucketSort( int ( *getNonNegativeInt ) ( Type data ) ) ; // constructor
  ~BucketSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class BucketSort

template<class Type>
BucketSort<Type>::BucketSort( int ( *getNonNegativeInt ) ( Type data ) ) { // constructor

  mGetNonNegativeInt = getNonNegativeInt ;
  mListPtr = NULL ;

} // BucketSort<Type>::BucketSort()

template<class Type>
BucketSort<Type>::~BucketSort() { // destructor

  mGetNonNegativeInt = NULL ;
  mListPtr = NULL ;

} // BucketSort<Type>::~BucketSort()

template<class Type>
void BucketSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  int listSize = 10, rangeSize = 0 ;
  int min = 0, max = 0 ;
  int* nonNegativeNum = new int[size] ;

  for ( int i = 0 ; i < size ; i++ ) {
    nonNegativeNum[i] = mGetNonNegativeInt( dataPtr[i] ) ;
  } // for
  
  FindMinMaxValue( nonNegativeNum, min, max, size ) ;

  rangeSize = ( max - min + 1 ) / listSize ;

  if ( rangeSize == 0 ) {
    rangeSize = 1 ;
  } // if

  CreateList( listSize ) ;

  for ( int i = 0, index = 0 ; i < size ; i++ ) {
    index = ( nonNegativeNum[i] - min ) / rangeSize ;
    InsertList( ( index < listSize ? index : listSize - 1 ), dataPtr[i], nonNegativeNum[i] ) ;
  } // for

  for ( int i = 0, dataIndex = 0 ; i < listSize ; i++ ) {
    if ( mListPtr[i] != NULL ) {
      for ( Node* cur = mListPtr[i] ; cur != NULL ; cur = cur->next, dataIndex++ ) {
        dataPtr[dataIndex] = cur->data ;
      } // for
    } // if
  } // for

  ReleaseList( listSize ) ;

  delete[] nonNegativeNum ;
  nonNegativeNum = NULL ;

} // BucketSort<Type>::Sort()

template<class Type>
void BucketSort<Type>::FindMinMaxValue( int* nonNegativeNum, int& min, int& max, int size ) {

  min = nonNegativeNum[0] ;
  max = nonNegativeNum[0] ;

  for ( int i = 1 ; i < size ; i++ ) {

    if ( min > nonNegativeNum[i] ) {
      min = nonNegativeNum[i] ;
    } // if

    if ( max < nonNegativeNum[i] ) {
      max = nonNegativeNum[i] ;
    } // if

  } // for

} // BucketSort<Type>::FindMaxValue() 

template<class Type>
void BucketSort<Type>::InsertList( int index, Type newData, int nonNegativeInt ) {

  if ( mListPtr[index] == NULL ) {
    mListPtr[index] = new Node( newData, nonNegativeInt ) ;
  } // if
  else {

    Node* pre = NULL ;
    Node* cur = mListPtr[index] ;

    for ( ; cur != NULL ; pre = cur, cur = cur->next ) {

      if ( nonNegativeInt <= cur->dataNonNegativeInt ) {

        if ( pre == NULL ) {
          mListPtr[index] = new Node( newData, nonNegativeInt ) ;
          mListPtr[index]->next = cur ;
        } // if
        else {
          pre->next = new Node( newData, nonNegativeInt ) ;
          pre->next->next = cur ;
        } // else 

        return ;

      } // if

    } // for

    pre->next = new Node( newData, nonNegativeInt ) ;

  } // else

} // BucketSort<Type>::InsertList()

template<class Type>
void BucketSort<Type>::CreateList( int listSize ) {

  mListPtr = new Node * [listSize] ;

  for ( int i = 0 ; i < listSize ; i++ ) {
    mListPtr[i] = NULL ;
  } // for

} // BucketSort<Type>::CreateList()

template<class Type>
void BucketSort<Type>::ReleaseList( int listSize ) {

  for ( int i = 0 ; i < listSize ; i++ ) {
    if ( mListPtr[i] != NULL ) {
      for ( Node* nextPtr = NULL ; mListPtr[i] != NULL ; mListPtr[i] = nextPtr ) {
        nextPtr = mListPtr[i]->next ;
        delete mListPtr[i] ;
      } // for
    } // if
  } // for

  delete[] mListPtr;
  mListPtr = NULL;
  
} // BucketSort<Type>::ReleaseList()

#endif // BUCKET_SORT_H_INCLUDED

