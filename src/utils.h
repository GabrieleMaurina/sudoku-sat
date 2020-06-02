#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cryptominisat5/cryptominisat.h>

#define sint uint8_t
#define ssint uint16_t

#define f(i,j) for(sint i=0; i<j; ++i)
#define f19(i) for(sint i=1; i<10; ++i)
#define f9(i) for(sint i=0; i<9; ++i)
#define fg(i,j) for(sint i=0; i<3; ++i) for(sint j=0; j<3; ++j)
#define l(i,j,k) for(sint i=j; i<k; ++i)

using namespace std;
using namespace CMSat;

#endif
