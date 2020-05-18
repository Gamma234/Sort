#ifndef RADIX_SORT_H_INCLUDED
#define RADIX_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class RadixSort {

private:

  int ( *mGetNonNegativeInt ) ( Type data ) ;

  int FindMaxValue( int* nonNegativeNum, int size ) ;

public:

  RadixSort( int ( *getNonNegativeInt ) ( Type data ) ) ; // constructor
  ~RadixSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class RadixSort

template<class Type>
RadixSort<Type>::RadixSort( int ( *getNonNegativeInt ) ( Type data ) ) { // constructor

  mGetNonNegativeInt = getNonNegativeInt ;

} // RadixSort<Type>::RadixSort()

template<class Type>
RadixSort<Type>::~RadixSort() { // destructor

  mGetNonNegativeInt = NULL ;

} // RadixSort<Type>::~RadixSort()

template<class Type>
void RadixSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  int* nonNegativeNum = new int[size] ;
  int maxValue = 0 ;
  Type** dataBox = new Type*[10] ;
  int** numBox = new int*[10] ;
  int order[10] ;

  for ( int i = 0 ; i < size ; i++ ) {
    nonNegativeNum[i] = mGetNonNegativeInt( dataPtr[i] ) ;
  } // for

  for ( int i = 0 ; i < 10 ; i++ ) {
    dataBox[i] = new Type[size] ;
    numBox[i] = new int[size] ;
    order[i] = 0 ;
  } // for

  maxValue = FindMaxValue( nonNegativeNum, size ) ;

  for ( int mul = 1 ; maxValue / mul != 0 ; mul *= 10 ) {

    for ( int i = 0 ; i < size ; i++ ) {

      int index = ( nonNegativeNum[i] / mul ) % 10 ; // from 0 to 9

      dataBox[index][order[index]] = dataPtr[i] ;
      numBox[index][order[index]] = nonNegativeNum[i] ;

      order[index]++ ;

    } // for

    int dataIndex = 0 ;

    for ( int i = 0 ; i < 10 ; i++ ) {

      if ( order[i] != 0 ) {

        for ( int j = 0 ; j < order[i] ; j++, dataIndex++ ) {
          dataPtr[dataIndex] = dataBox[i][j] ;
          nonNegativeNum[dataIndex] = numBox[i][j] ;
        } // for

        order[i] = 0 ;

      } // if

    } // for

  } // for  

  delete[] nonNegativeNum ;
  nonNegativeNum = NULL ;

  for ( int i = 0 ; i < 10 ; i++ ) {
    delete[] dataBox[i] ;
    dataBox[i] = NULL ;
    delete[] numBox[i] ;
    numBox[i] = NULL ;
  } // for

  delete[] dataBox ;
  dataBox = NULL ;
  delete[] numBox ;
  numBox = NULL ;

} // RadixSort<Type>::Sort()

template<class Type>
int RadixSort<Type>::FindMaxValue( int* nonNegativeNum, int size ) {

  int maxValue = nonNegativeNum[0] ;

  for ( int i = 1 ; i < size ; i++ ) {

    if ( maxValue < nonNegativeNum[i] ) {
      maxValue = nonNegativeNum[i] ;
    } // if

  } // for

  return maxValue ;

} // RadixSort<Type>::FindMaxValue() 

#endif // RADIX_SORT_H_INCLUDED

