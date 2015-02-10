#include "STX.h"

double CosSim( const vector < double >& A, const vector < double >& B ){
  if ( A.size() != B.size() ) return -2;

  double sum_ab = 0, sum_a_sq = 0, sum_b_sq = 0;

  for (int i = 0; i < A.size(); i++){
    sum_ab += A[i] * B[i]; 
    sum_a_sq += A[i] * A[i];
    sum_b_sq += B[i] * B[i];
  }

  return sum_ab / ( sqrt(sum_a_sq) * sqrt(sum_b_sq) );
}

double CosSim( const vector < double >& A, const int a_start, const int a_end, const vector < double >& B, const int b_start, const int b_end ){

  if ( (a_end - a_start) != (b_end - b_start) ) return -2;

  double sum_ab = 0, sum_a_sq = 0, sum_b_sq = 0;

  int i = a_start, j = b_start;
  for (; (i < a_end) && (j < b_end); i++, j++){
    if (isnan(A[i]) || isnan(B[j]))
      return -2;
    sum_ab += A[i] * B[j]; 
    sum_a_sq += A[i] * A[i];
    sum_b_sq += B[j] * B[j];
  }

  return sum_ab / ( sqrt(sum_a_sq) * sqrt(sum_b_sq) );
}

double Pearson ( const vector < double >& A, const int a_start, const int a_end, const vector < double >& B, const int b_start, const int b_end ){

  if ( ( a_end - a_start ) != ( b_end - b_start ) ) return -2;
  
  int i = a_start, j = b_start;
  double a_mean = 0, b_mean = 0;
  while ( ( i < a_end ) && ( j < b_end ) ){
    if ( isnan(A[i]) || isnan(B[j]) ) return -2;
    
    a_mean += A[i];
    b_mean += B[j];

    ++i; ++j;
  }

  a_mean /= (a_start - a_end);
  b_mean /= (b_start - b_end);

  double numerator = 0;
  double a_den = 0, b_den = 0;
  
  i = a_start, j = b_start;
  while ( ( i < a_end ) && ( j < b_end ) ){
    numerator += ( (A[i] - a_mean ) * ( B[j] - b_mean ));

    a_den += ( A[i] - a_mean ) * ( A[i] - a_mean );
    b_den += ( B[j] - b_mean ) * ( B[j] - b_mean );

    ++i; ++j;
  }

  return numerator / (sqrt(a_den) * sqrt(b_den));  
}
