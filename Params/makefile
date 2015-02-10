params: Parameters.h Parameters.cc
	${GXX} -fpic -c Parameters.cc -o Params.o -std=c++0x
	${GXX} -shared Params.o ../Files/files.o -o libParams.so 
