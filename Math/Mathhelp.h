#ifndef MATH_RPI
#define MATH_RPI

using namespace std;

template <class T = unsigned long>
T binomial_coefficient(unsigned long n, unsigned long k) {
  unsigned long i; T b;
  if ( 0 == k || n == k ) {
    return 1;
  }

  if ( k > n ){
    return 0;
  }

  if ( k > ( n - k ) ){
    k = n - k;
  }

  if ( 1 == k ) return n;

  b = 1;
  
  for ( i = 1; i <= k; ++i){
    b *= (n - (k - i) );
    if ( b < 0 ) return -1;
    b /= i;
  }

  return b;
}

#endif
