#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int compare(const void *a, const void * b){
   return ( *(char *)a - *(char *)b );
}

void swap(char* a, char* b) {
   char t = *a;
   *a = *b;
   *b = t;
}

int finduBound(char str[], char first, int l, int h) {
   int ubound = l;
   for (int i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ubound])
   		ubound = i;
   
   return ubound;
}
void generatePermutaion ( char str[] ) {
   int size = strlen(str);
   qsort( str, size, sizeof( str[0] ), compare );
   bool isFinished = false;
   while ( ! isFinished ) {
      cout<<str<<"\t";
      int i;
      for ( i = size - 2; i >= 0; --i )
         if (str[i] < str[i+1])
            break;
         if ( i == -1 )
            isFinished = true;
      else {
         int ubound = finduBound( str, str[i], i + 1, size - 1 );
         swap( &str[i], &str[ubound] );
         qsort( str + i + 1, size - i - 1, sizeof(str[0]), compare );
      }
   }
}
int main() {
   char str[] = "eat";
   cout<<"Permutation in Sorted order :\n";
   generatePermutaion(str);
   return 0;
}
