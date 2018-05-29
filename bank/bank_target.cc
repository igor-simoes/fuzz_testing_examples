#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;


bool fuzzMe(const u_int8_t* data, size_t size){
    return 0;
}


extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* data, size_t size){
    fuzzMe(data, size);
    return 0;
}
