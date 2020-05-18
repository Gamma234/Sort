#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class InsertionSort {

private:

  bool ( *mCompare ) ( Type data1, Type data2 ) ;

public:

  InsertionSort( bool ( *compare ) ( Type data1, Type data2 ) ) ; // constructor
  ~InsertionSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class InsertionSort

template<class Type>
InsertionSort<Type>::InsertionSort( bool ( *compare ) ( Type data1, Type data2 ) ) { // constructor

  mCompare = compare ;

} // InsertionSort<Type>::InsertionSort()

template<class Type>
InsertionSort<Type>::~InsertionSort() { // destructor

  mCompare = NULL ;

} // InsertionSort<Type>::~InsertionSort()

template<class Type>
void InsertionSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  for ( int i = 1 ; i < size ; i++ ) {

    Type temp = dataPtr[i] ;

    int j = i - 1 ;

    for ( ; j >= 0 && mCompare( dataPtr[j], temp ) ; j-- ) {
      dataPtr[j + 1] = dataPtr[j] ;
    } // for

    dataPtr[j + 1] = temp ;

  } // for

} // InsertionSort<Type>::Sort()

#endif // INSERTION_SORT_H_INCLUDED

