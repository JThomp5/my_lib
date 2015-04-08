#ifndef RPI_PL
#define RPI_PL

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class PowerLaw {
 public:
  PowerLaw ( double exponent, double min_val = 0, double max_val = 100 ): exp(exponent), mn(pow(min_val, exponent + 1)), mx(pow(max_val, exponent + 1)) {
    if ( !seeded ) {
      srand(time(NULL));
      seeded = true;
    }
  }
  
  double Sample ( ) {    
    return pow ( ( (mx - mn) * (((double)rand()) / (double)RAND_MAX) + mn ), 1. / (exp + 1.) );
  }

  double getExp ( ) { return exp; }
  double getMin ( ) { return mn; }
  double getMax ( ) { return mx; }
 
 private:
  double exp, mn, mx;
  static bool seeded;
};

class DiscPowerLaw {
 public:
  DiscPowerLaw ( double exponent, double min_val = 0, double max_val = 100 ) : exp(exponent), mn(min_val), mx (max_val) {
    if ( !seeded ) {
      srand ( time (NULL) );
      seeded = true;
    }
    
    CDF.push_back ( pow ( mn, exp ) );
    
    for ( uint i = mn + 1; i <= mx; i++ ){
      CDF.push_back( CDF[i-mn-1] + pow ( i, exp ) );
    }
    
    double factorize = 1.0 / CDF[CDF.size() - 1];
    for ( uint i = 0; i <= CDF.size(); i++ ){
      CDF[i] *= factorize;
    }
  }
  
  uint Sample ( ) { 
    double choice = ( (double)rand() / (double)RAND_MAX );
    
    uint i = 0;
    while ( (i < CDF.size() - 1) && ( CDF[i] < choice ) ){
      i++;
    }
    
    return mn + i;
  }

  private:
    double exp;
    uint mn, mx;
    static bool seeded;
    vector < double > CDF;
};

#endif
