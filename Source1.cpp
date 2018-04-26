// USC Knots Project but in C this time
#include "fmpz_poly.h"

const fmpz_poly_t SQRT_Q, INV_SQRT_Q; // Base Ring Z[sqrt(q), sqrt(q)^-1]
const int NCRS; //The length of each run's input list

/*
	--- Input ---
	1. Either a Complex # or Q
	2. NC -> Ends up controlling a while loop (# of "Colors")
	3. A list in one of the following styles

	--- Input Styles ---
	Style 1: beta = {+-a, +-b, ..., +-j} -> Positive and Negative Integers
	Style 2: beta = {{a, +-1},{b, +-1}, ... , {j,+-1}} -> {pos#, sign}
	Style 3: beta = Knot[a,b] -> Hashtable that maps to Style 2
*/

/*
	Step 1: From input -> set 3 structures/info
		>> m = max[Abs[Beta]] + 1 -> How many strands in the braid/knot
		>> w = Sum(signs of Beta) -> How "twisty" is our braid?
		>> numCrossings {NCrs} = length(Beta) -> How many crossings are in the braid?
*/

/* 
	NCPoly structure is a data structure
	>> {List, sparseArray[]}
				L> x[] = List of size 3*NCrs + 1
	>> x[] = {3NCrs spaces tell how many copies of the ith term exist 
			  , flintBigInt stores the order}
	>> flintBigInt is Base 3NCrs

	Ex. Let NCrs = 3, BigInt = 1284 
		1284 in base 3NCrs = {1, 6, 7, 6}
		x = {0, 1, 2, 0, 0, 0, 0, 1, 2, 1284}
*/

void swDetq(int q[], int m[], int nCrs) {}

void swDetq_k(int s, int mLength) {}

void rbRep(int q[], int braid[][], int vars[] /*???*/) {}

int[] sSubMatrices(int m[]) {}

int[] braidMonomialHelper(int ncPart[], int ncrs[], int signs[]) {}

int[] bmhc(int bmhLocalMonomial[], int nCrs[], int signs[])[]

int duplicateReduction(int nCrs[], numColors) {
	return 0;
}


