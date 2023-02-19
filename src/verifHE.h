#include "HEAAN/Scheme.h"

using namespace std;
using namespace NTL;

typedef unsigned char uchar;
typedef unsigned int uint32;

class vScheme : public Scheme {
    public:
    //----------------------------------------------------------------------------------
	//   HOMOMORPHIC OPERATIONS for Verfication
	//----------------------------------------------------------------------------------

	void vnegate(Ciphertext& res, Ciphertext& cipher);

	void vadd(Ciphertext& res, Ciphertext& cipher1, Ciphertext& cipher2);

	void vaddConst(Ciphertext& res, Ciphertext& cipher, complex<double> cnst, long logp);

	void vsub(Ciphertext& res, Ciphertext& cipher1, Ciphertext& cipher2);

	void vimult(Ciphertext& res, Ciphertext& cipher);

	void vidiv(Ciphertext& res, Ciphertext& cipher);

	void vmult(Ciphertext& res, Ciphertext& cipher1, Ciphertext& cipher2);

	void vsquare(Ciphertext& res, Ciphertext& cipher);

	void vmultByConst(Ciphertext& res, Ciphertext& cipher, complex<double> cnst, long logp);

	void vmultByConstVecSlot(Ciphertext& res, Ciphertext& cipher, long logp);

	void vmultByPoly(Ciphertext& res, Ciphertext& cipher, ZZ* poly, long logp);

	void vmultByMonomial(Ciphertext& res, Ciphertext& cipher, const long degree);

	void vleftShift(Ciphertext& res, Ciphertext& cipher, long bits);

	void vdoubleAndEqual(Ciphertext& cipher);

	void vdivByPo2(Ciphertext& res, Ciphertext& cipher, long bits);

}