# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include "BucketSort.h"

using namespace std ;

struct Data {
  int num ;
  Data() : num( 0 ) {} // constructor
  Data( int n ) : num( n ) {} // constructor
} ; // struct Data

int GetNonNegativeInt( int value ) ;
int GetNonNegativeInt( Data data ) ;

int* GetFileData( string fileName, int& size ) ;
Data* IntPtrToDataPtr( int* intPtr, int size ) ;
void Print( int* intPtr, int size ) ;
void Print( Data* dataPtr, int size ) ;

int main() {

  int size = 0 ;
  int* intPtr = GetFileData( "test_data//input50a.txt", size ) ;
  Data* dataPtr = IntPtrToDataPtr( intPtr, size ) ;

  BucketSort<int>* intBS = new BucketSort<int>( GetNonNegativeInt ) ;
  BucketSort<Data>* dataBS = new BucketSort<Data>( GetNonNegativeInt ) ;

  intBS->Sort( intPtr, size ) ;
  dataBS->Sort( dataPtr, size ) ;

  Print( intPtr, size ) ;
  Print( dataPtr, size ) ;

  delete[] intPtr ;
  intPtr = NULL ;
  delete[] dataPtr ;
  dataPtr = NULL ;

  delete intBS ;
  intBS = NULL ;
  delete dataBS ;
  dataBS = NULL ;

} // main()

int GetNonNegativeInt( int value ) {

  return value ;

} // IntSmallerEqual()

int GetNonNegativeInt( Data data ) {

  return data.num ;

} // DataSmallerEqual()

int* GetFileData( string fileName, int& size ) {

  size = 0 ;

  fstream inFile( fileName.c_str(), ios::in ) ;

  if ( !inFile ) {
    cout << "File not exist !" << endl ;
    return NULL ;
  } // if

  string intro = "" ;
  int num = 0 ;
  vector<int> numBox ;
  int* numPtr = NULL ;

  getline( inFile, intro ) ; // first line is an introduction  

  while ( inFile >> num ) {
    numBox.push_back( num ) ;
  } // while

  inFile.close() ;

  size = numBox.size() ;

  cout << "Data Size : " << size << endl ;

  numPtr = new int[size] ;

  for ( int i = 0 ; i < size ; i++ ) {
    numPtr[i] = numBox[i] ;
  } // for

  return numPtr ;

} // GetFileData()

Data* IntPtrToDataPtr( int* intPtr, int size ) {

  if ( intPtr == NULL ) {
    return NULL ;
  } // if

  Data* dataPtr = new Data[size] ;

  for ( int i = 0 ; i < size ; i++ ) {
    dataPtr[i] = Data( intPtr[i] ) ;
  } // for

  return dataPtr ;

} // IntPtrToDataPtr()

void Print( int* intPtr, int size ) {

  cout << "---------- intPtr ----------" << endl ;

  bool smallToBig = true ;

  if ( intPtr != NULL ) {

    for ( int i = 0 ; i < size ; i++ ) {

      cout << intPtr[i] << " " ;

      if ( i != 0 && intPtr[i - 1] > intPtr[i] ) {
        smallToBig = false ;
      } // if

    } // for    

  } // if
  else {
    cout << "NULL pointer !" ;
  } // else

  cout << endl ;

  cout << "----------------------------" << endl ;

  cout << "Small To Big : " << ( smallToBig ? "True" : "False" ) << endl ;

} // Print()

void Print( Data* dataPtr, int size ) {

  cout << "---------- dataPtr ----------" << endl ;

  bool smallToBig = true ;

  if ( dataPtr != NULL ) {

    for ( int i = 0 ; i < size ; i++ ) {

      cout << dataPtr[i].num << " " ;

      if ( i != 0 && dataPtr[i - 1].num > dataPtr[i].num ) {
        smallToBig = false ;
      } // if

    } // for    

  } // if
  else {
    cout << "NULL pointer !" ;
  } // else

  cout << endl ;

  cout << "-----------------------------" << endl ;

  cout << "Small To Big : " << ( smallToBig ? "True" : "False" ) << endl ;

} // Print()


