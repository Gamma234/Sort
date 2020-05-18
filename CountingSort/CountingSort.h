#ifndef COUNTING_SORT_H_INCLUDED
#define COUNTING_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class CountingSort {

private:

  int ( *mGetNonNegativeInt ) ( Type data ) ;

  int FindMaxValue( Type* dataPtr, int size ) ;

public:

  CountingSort( int ( *getNonNegativeInt ) ( Type data ) ) ; // constructor
  ~CountingSort() ; // destructor

  void Sort( Type* dataPtr, Type* sortedPtr, int size ) ;

} ; // class CountingSort

template<class Type>
CountingSort<Type>::CountingSort( int ( *getNonNegativeInt ) ( Type data ) ) { // constructor

  mGetNonNegativeInt = getNonNegativeInt ;

} // CountingSort<Type>::CountingSort()

template<class Type>
CountingSort<Type>::~CountingSort() { // destructor

  mGetNonNegativeInt = NULL ;

} // CountingSort<Type>::~CountingSort()

template<class Type>
void CountingSort<Type>::Sort( Type* dataPtr, Type* sortedPtr, int size ) {

  if ( dataPtr == NULL || sortedPtr == NULL ) {
    return ;
  } // if

  int maxValue = FindMaxValue( dataPtr, size ) ;
  int* counting = new int[maxValue + 1] ;

  for ( int i = 0 ; i < maxValue + 1 ; i++ ) {
    /* initialize to 0 */
    counting[i] = 0 ;
  } // for

  for ( int i = 0 ; i < size ; i++ ) {
    /* count the numbers of every value */
    counting[mGetNonNegativeInt( dataPtr[i] )]++ ;
  } // for

  for ( int i = 1 ; i < maxValue + 1 ; i++ ) {
    /* accumulate the number from begin to end */
    counting[i] = counting[i] + counting[i - 1] ;
  } // for

  int index = 0 ;

  for ( int i = size - 1 ; i >= 0 ; i-- ) {
    index = mGetNonNegativeInt( dataPtr[i] ) ;
    sortedPtr[counting[index] - 1] = dataPtr[i] ;
    counting[index]-- ;
  } // for

  delete[] counting ;
  counting = NULL ;

} // CountingSort<Type>::Sort()

template<class Type>
int CountingSort<Type>::FindMaxValue( Type* dataPtr, int size ) {

  int maxValue = mGetNonNegativeInt( dataPtr[0] ) ;
  int compareValue = 0 ;

  for ( int i = 1 ; i < size ; i++ ) {

    compareValue = mGetNonNegativeInt( dataPtr[i] ) ;

    if ( maxValue < compareValue ) {
      maxValue = compareValue ;
    } // if

  } // for

  return maxValue ;

} // CountingSort<Type>::FindMaxValue() 

#endif // COUNTING_SORT_H_INCLUDED

