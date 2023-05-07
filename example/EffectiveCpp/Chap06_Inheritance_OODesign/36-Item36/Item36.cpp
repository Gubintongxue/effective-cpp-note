#include "MyClass3.h"

int main()
{
	// x is an object of type D.
	D x;

	// pB is statically bound to type B.
	// but: dynamically bound to type D.
	B* pB = &x;

	// call D::mf() through pointer to D.
	pB->mf();


	// pD is statically bound to type D.
	// but: dynamically bound to type D.
	D* pD = &x;

	// call D::mf() through pointer to D.
	pD->mf();
	return 0;
}