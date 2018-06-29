        #ifndef _QUADRATIC_PROBING_H_
        #define _QUADRATIC_PROBING_H_

		#include <cstring>

        // QuadraticProbing Hash table class
        //
        // CONSTRUCTION: an initialization for ITEM_NOT_FOUND
        //               and an approximate initial size or default of 101
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // void remove( x )       --> Remove x
        // Hashable find( x )     --> Return item that matches x
        // void makeEmpty( )      --> Remove all items
        // int hash( String str, int tableSize )
        //                        --> Static method to hash strings

        class QuadraticHashTable
        {
          public:
            explicit QuadraticHashTable( char * , int size = 101 );


            bool find( char * x ) const;

            //void makeEmpty( );
            void insert( char * x );
            //void remove( const HashedObj & x );
			//void print();

            const QuadraticHashTable & operator=( const QuadraticHashTable & rhs );


            char * array[300997];
            int currentSize;
            
            bool isPrime( int n ) const;
            int nextPrime( int n ) const;
            bool isActive( int currentPos ) const;
            int findPos( char * x ) const;
            int hash( const char* key, int tableSize ) const;
            int hash( int key, int tableSize ) const;
            //void rehash( );
			
		};


        
        #endif
