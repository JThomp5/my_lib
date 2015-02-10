/**
* Class to help read in multiple command line (flagged) parameters
*
*	TO DO:
* 		Error Messages
*/

#ifndef ICE_PARAM
#define ICE_PARAM
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdlib.h>
#include "../Files/StringEx.h"

using namespace std;

typedef short unsigned int sui;
typedef long unsigned int lui;

/**
 * @class Parameters
 * 
 * Structure to help make reading command line arguments quick and easy
 */
class Parameters{
	public:
	  /** @fn Parameters()
	   * 
	   * Empty Constructor
	   */
		Parameters(){
			
		}
		
	    /** @fn ~Parameters()
	   * 
	   * Empty Destructor
	   */
		~Parameters(){
			
		}
		
		void Read(int argc, char** argv);
		
		/**
		 * @fn template <class T> void set (T* var, string tag, T dflt)
		 * @param var Pointer to variable to set to parameter
		 * @param tag Command line flag to look for
		 * @param dflt Default value to set var to
		 */
		template <class T>
		void set (T* var, string tag, T dflt){
		        if ((it_lookup = lookup.find(tag)) != lookup.end())
		        {
			  (*var) = str_to<T>(it_lookup->second[0]);
			}
			else
			  (*var) = dflt;			
		}
		
		template <class T>
		T get ( string tag ){
		  if ( ( it_lookup = lookup.find ( tag ) ) != lookup.end() ){
		    return str_to < T > ( it_lookup->second[0] );
		  } else {
		    cerr << "Could not retrieve " << tag << endl;
		    exit( 54 );
		  }
		}

		template <class T>
		T get ( string tag, T dflt ){
		  if ( ( it_lookup = lookup.find ( tag ) ) != lookup.end() ){
		    return str_to < T > ( it_lookup->second[0] );
		  } else {
		    return dflt;
		  }
		}
		
		/**
		 * @fn template <class T> void set (T* var, string tag)
		 * @param var Pointer to variable to set to parameter
		 * @param tag Command line flag to look for
		 * 
		 * Will throw an exception if the flag is not found in the parameters
		 */
		template <class T>
		void set (T* var, string tag){
			if ((it_lookup = lookup.find(tag)) != lookup.end())
			{
			  (*var) = str_to<T>(it_lookup->second[0]);
			}
			else	
			  throw "Invalid Parameters";
		}
		
		/**
		 * @fn void boolset (bool* var, string tag)
		 * @param var Pointer to variable to set to parameter
		 * @param tag Command line flag to look for
		 * 
		 * Will set the boolean to true if the flag is found. False otherwise.
		 */
		void boolset (bool* var, string tag){
		  if ((it_lookup = lookup.find(tag)) != lookup.end())
			{
			  (*var) = true;
			}
			else{
			  (*var) = false;
			}
		}
		
		template < class T >
		void set_new_var ( string key, T value ){
		  vector < string > temp;
		  temp.push_back ( to_str < T > ( value ) );
		  if ( ( it_lookup = lookup.find ( key ) ) != lookup.end() ) {
		    it_lookup->second = temp;
		  } else {
		    lookup.insert ( pair < string, vector < string > > ( key, temp ) );
		  }
		} 
		
	private:
		map <string, vector < string > > lookup;
		map <string, vector < string > >::iterator it_lookup;
};
#endif
