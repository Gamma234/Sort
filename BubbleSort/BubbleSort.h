#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class BubbleSort {

private :

  bool ( *mCompare ) ( Type data1, Type data2 ) ;

public :

  BubbleSort( bool ( *compare ) ( Type data1, Type data2 ) ) ; // constructor
  ~BubbleSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class BubbleSort

template<class Type>
BubbleSort<Type>::BubbleSort( bool ( *compare ) ( Type data1, Type data2 ) ) { // constructor

  mCompare = compare ;

} // BubbleSort<Type>::BubbleSort()

template<class Type>
BubbleSort<Type>::~BubbleSort() { // destructor

  mCompare = NULL ;

} // BubbleSort<Type>::~BubbleSort()

template<class Type>
void BubbleSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  for ( int i = 0 ; i < size - 1 ; i++ ) {
    for ( int j = 0 ; j < size - 1 - i ; j++ ) {
      if ( mCompare( dataPtr[j], dataPtr[j + 1] ) ) {
        Type temp = dataPtr[j] ;
        dataPtr[j] = dataPtr[j + 1] ;
        dataPtr[j + 1] = temp ;
      } // if
    } // for 
  } // for

} // BubbleSort<Type>::Sort()

#endif // BUBBLE_SORT_H_INCLUDED

