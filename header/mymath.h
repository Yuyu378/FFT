//	
// Jan 28, 2023
// Feb 01, 2023
// 
// mymath.h
// 

#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <stdbool.h>

#ifndef PI
#define PI (3.1415926535897932384626433832795028841971693993751058209749445923)
#endif // !PI

// Complex --------------------------------------------------------------------

#ifndef J
#define J _Cbuild(0., 1.)
#endif // !J

void cprint(_Dcomplex a);

void cswap(_Dcomplex* a, _Dcomplex* b);

_Dcomplex cadd(_Dcomplex a, _Dcomplex b);

_Dcomplex csub(_Dcomplex a, _Dcomplex b);

_Dcomplex cmul(_Dcomplex a, _Dcomplex b);

_Dcomplex cdiv(_Dcomplex a, _Dcomplex b);

// Numeric --------------------------------------------------------------------

bool isPowerOf2(unsigned num);

unsigned nextPowerOf2(unsigned num);

bool isprime(unsigned num);

unsigned* factor(unsigned num);

/// <summary>
/// Extended Euclidean algorithm
/// <para> ax + by = gcd(a, b) </para><para>.</para>
/// <para> Son Function: </para>
/// <see cref="   exgcd()"/>
/// </summary>
/// <param name="a"> : unsigned </param>
/// <param name="b"> : unsigned </param>
/// <param name="x"> : unsigned pointer </param>
/// <param name="y"> : unsigned pointer </param>
/// <returns>
/// Greatest Common Divisor
/// <para> will change input parameter x, y (*Important) </para>
/// </returns>
int extendedEuclidean(unsigned a, unsigned b, int* x, int* y);

/// <summary>
/// Extended Euclidean algorithm
/// <para> ax + by = gcd(a, b) </para><para>.</para>
/// <para> Father Function: </para>
/// <see cref="   extendedEuclidean()"/>
/// </summary>
/// <param name="a"> : unsigned </param>
/// <param name="b"> : unsigned </param>
/// <returns>
/// array : [n, x, y, g]
/// <para> n : size of return array, always be 4 </para>
/// <para> x : Bezout coefficient </para>
/// <para> y : Bezout coefficient </para>
/// <para> g : greatest common divisor </para>
/// </returns>
int* exgcd(unsigned a, unsigned b);

/// <summary>
/// The sub-function required to find the primitive root in Radar's algorithm
/// </summary>
/// <param name="g"> : unsigned </param>
/// <param name="k"> : unsigned </param>
/// <param name="n"> : unsigned </param>
/// <returns> a = pow(g, k) mod n </returns>
unsigned expModuloN(unsigned g, unsigned k, unsigned n);

/// <summary>
/// The sub-function required to get bijective function in Radar's algorithm
/// <para>.</para>
/// <para> since </para>
/// <para> ax + ny = gcd(a, n) = 1, </para> 
/// <para> ax - 1 = (-y)n, </para>
/// <para> ax = 1 (mod n), </para>
/// <para> that is, x = pow(a, -1) (mod n), </para>
/// <para> where x is a Modular multiplicative inverse </para>
/// <para>.</para>
/// <para> *Important: If a >= n, modular inverse must not exist. </para>
/// </summary>
/// <param name="a"> : unsigned </param>
/// <param name="n"> : unsigned </param>
/// <returns> minimum positive integer solution x = pow(a, -1) (mod n) </returns>
unsigned expModuloNInverse(unsigned a, unsigned n);

bool isPrimitiveRoot(unsigned g, unsigned p);

unsigned findPrimitiveRoot(unsigned n);
