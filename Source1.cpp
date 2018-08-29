// USC Knots Project but in C this time
#include flint-2.5.2 // Need to figure out exactly which files I need or put this into a header file

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
		x = {0, 1, 2, 0, 0, 0, 0, 1, 2, 1284}    -> FromDigits[{0, 0, 1, 6, 7, 6}, 9]
		y = {3, 1, 0, 0, 0, 1, 1, 1, 0, 1589133} -> FromDigits[{2, 8, 8, 1, 7, 8, 3}, 9]
		#of  8s 7s 6s 5s 4s 3s 2s 1s 0s
			
	xy = {0, 0, 1, 6, 7, 6, 2, 8, 8, 1, 7, 8, 3} base9 -> FromDigits stuff
	   = {3, 4, 4, 0, 0, 1, 1, 2, 2, 9^7*1284+1589133} -> Encoding Non-commutative Words

	WE NEED TO CHANGE THIS TO MAKE IT MORE EFFICIENT EITHER 
		WITH LINKED LISTS OR SOMETHING

	CHECK OUT MATHEMATICA/NCAlgebra: FromDigits[], IntegerDigits[]
*/

// Combinatorica Stuff
int mInversions();
int mPermutationQ();
int mToInversionVector();

// Package Variables
int a,b,c,q;

void swDetq(int *q, int *m, int *nCrs);

void swDetq_k(int s, int mLength);

void rbRep(int *q, int *braid, int *vars /*???*/);

int sSubMatrices(int *m);

void simpleWalkCalculator(int *braid, int *NCvars, int q);
void simpleWalkCalculator(int *knot, int *NCvars, int q);
void simpleWalkCalculator(int *brd, int *NCvars, int q);

int scriptEPos(int q, int n, int cr, int ad);
int scriptENeg(int q, int n, int cr, int ad);

int monomialBuilder(int *a, int *b, int *c);

int braidMonomialHelper(int ncPart[], int ncrs[], int signs[]);
int bmhc(int bmhLocalMonomial[], int nCrs[], int signs[]);

int bmec(int *monomial, int ncrs[], int signs[], int q);
int braidMonomialExponentCounter(int *monomialRule, int ncrs[], int signs[], int q);

int duplicateReduction(int ncrs[], int numColors);
int duplicateReduction(int *walklist_NCPoly, int ncrs[], int numColors);

// DRC?

int cj(int q, int nc, int *braidKnot);
int cj(int q, int nc, int *braidBR);
int cj(int q, int nc, int *braidList);

int cjScriptE(int cr, int ad, int position);


