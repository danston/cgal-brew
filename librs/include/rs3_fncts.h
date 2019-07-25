#ifndef _rs3_fncts_h
#define _rs3_fncts_h

#ifdef __cplusplus
extern "C" {
#endif

#include "gmp.h"
#if (!defined __MPFI_H__ && !defined _mpfi_h)
#include "mpfi.h"
#endif
#include "rs3_basic.h"

/* Various initializations */

extern void rs3_set_usr_memory_fncts(void *(*alloc_func) (size_t),
				     void *(*realloc_func) (void *, size_t),
				     void (*free_func) (void *));

extern void rs3_set_gmp_usr_memory_fncts(void *(*alloc_func) (size_t),
					 void *(*realloc_func) (void *, size_t,size_t),
					 void (*free_func) (void *,size_t));

extern void rs3_internal_init();
extern void rs3_set_default_io();
extern void rs3_set_debug_level(const unsigned int);
extern void rs3_set_io_basic(void (*IO_BUF_2_FILE)(FILE *,const char  *));

/* up_mz_gcd */

extern int _i_rs3_up_mz_gcd(mpz_t *,const mpz_t *,const int,const mpz_t *,const int);
extern int rs3_up_mz_gcd(mpz_t **,const mpz_t *,const int,const mpz_t *,const int);

/* up_mz_sfp */
extern int _i_rs3_up_mz_sfp(mpz_t * p,const int d_p);
extern int rs3_up_mz_sfp(mpz_t **res,const mpz_t *a,const int amax);

/* refine univariate roots */

/* The following function takes 
          an isolating interval v, 
          a squarefree polynomial dp of degree d_dp and 

refines v until the first prec_res bits of the mantissa of the left and right bounds of v are equal 

If force_den is not 0 then it also refines until the derivative of dp do not vanish over the interval

If force_kanto is not 0, then it refines at least until kantorovitch criterion for using Newton's method is valid.

Note that the refinement is linear until kantorovitch test is true, then it is quadratic.

The precision of the result is at least prec_res but can be much more especially when force_kanto is set to 1
*/

extern int rs3_refine_u_root(mpfi_t v,const mpz_t *dp, const int d_dp, const int prec_res, const int force_den, const int force_kanto);

extern int rs3_refine_up_val(mpfi_t val,mpfi_t v,const mpz_t *dp, const int d_dp, const mpz_t * f,const int d_f,const int prec_res);

extern int rs3_is_root_of_sfp(const mpfi_t interv,const mpz_t * p, const int d);

extern int rs3_refine_eval_u(mpz_t *ext, const int d_ext,const mpz_t * den, const int d_den,
				const mpz_t **nums, const int * d_nums, 
				const int nbvars, mpfi_t * sols_u, const int nb_sols, 
				mpfi_t **vs,mpfi_t * v_dens, const int prec_out,
			     const int ext_is_sf,const int ensure_signs,const int ensure_kanto);

/* the difference between _i_rs3_** and rs3_** functions is the memory mannagment. _i_rs3_** functions are supposed to be used inside rs3
   while the rs3_* functions keep track of the user memory functions to allocate the results */
    
extern int _i_rs3_refine_u_root(mpfi_t v,const mpz_t *dp, const int d_dp, const int prec_res, const int force_den, const int force_kanto);

extern int _i_rs3_refine_up_val(mpfi_t val,mpfi_t v,const mpz_t *dp, const int d_dp, const mpz_t * f,const int d_f,const int prec_res);

extern int _i_rs3_is_root_of_sfp(const mpfi_t interv,const mpz_t * p, const int d);

extern int _i_rs3_refine_eval_u(mpz_t *ext, const int d_ext,const mpz_t * den, const int d_den,
				const mpz_t **nums, const int * d_nums, 
				const int nbvars, mpfi_t * sols_u, const int nb_sols, 
				mpfi_t **vs,mpfi_t * v_dens, const int prec_out,
				const int ext_is_sf,const int ensure_signs,const int ensure_kanto);

/* test functions */

extern int rs3_test_isolate_over_u(mpz_t *ext, const int d_ext,const mpz_t * den, const int d_den,
				   const mpz_t **nums, const int * d_nums, 
				   const mpz_t *sep, const int nbvars,
				   mpfi_t sol_u, mpfi_t *v,mpfi_t v_den, const int , const int);

extern void mif_out(const mpfi_t a);

#ifdef __cplusplus
}
#endif

#endif
