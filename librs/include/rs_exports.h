#ifndef _rs_export_h_
#define _rs_export_h_

#if defined (__cplusplus)
#include <iosfwd>   /* for std::istream, std::ostream, std::string */
#else
#include <stdio.h>
#include <stdarg.h>
#endif


#ifdef RS_EXPORT_DLL
#if defined(WIN32) || defined(WIN64)
#define RSLNK_EXPORT __declspec(dllexport)
#ifndef _MSC_VER
#define RSLNK_DECL(a) __attribute__((stdcall)) _ ## a 
#define GMP_RSLNK_DECL(a) __attribute__((cdecl)) _ ## a 
#define RSLNK_CALL(a) _ ## a
#else 
#define RSLNK_DECL(a) __stdcall a
#define GMP_RSLNK_DECL(a) __cdecl a
#define RSLNK_CALL(a) a
#endif
#else
#define RSLNK_EXPORT extern
#define RSLNK_DECL(a) a
#define GMP_RSLNK_DECL(a) a
#define RSLNK_CALL(a) a
#endif
#else
#define RSLNK_EXPORT extern
#define RSLNK_DECL(a) a 
#define GMP_RSLNK_DECL(a) a 
#define RSLNK_CALL(a) a
#endif

#if 0

#if (defined(WIN32) || defined(WIN64)) 
#if defined(WIN64)
#define RSLNK_PTR_OUT __int64
#define RSLNK_PTR_IN __int64
#else
#define RSLNK_PTR_OUT __int32
#define RSLNK_PTR_IN __int32
#endif
#else
#define RSLNK_PTR_OUT long int
#define RSLNK_PTR_IN long int
#endif

#endif

typedef void * RSLNK_PTR_OUT;
typedef void * RSLNK_PTR_IN;

#define TO_RSPTR_OUT(a) ((RSLNK_PTR_OUT) (a))
#define TO_RSPTR_IN(a) ((RSLNK_PTR_IN) (a))

#define RS_MAXDEN -1073741824

#ifdef __cplusplus
extern "C" {
#endif

RSLNK_EXPORT void RSLNK_DECL(set_push_gmp_alloc_fnct)(void (*fnct_push)(
															   void *(*alloc_func) (size_t),
															   void *(*realloc_func) (void *, size_t, size_t),
															   void (*free_func) (void *, size_t)));

RSLNK_EXPORT void RSLNK_DECL(set_pop_gmp_alloc_fnct)(void (*fnct_pop)());

RSLNK_EXPORT void RSLNK_DECL(set_push_error_fnct)(void (*fnct_push)(void *));
RSLNK_EXPORT void RSLNK_DECL(set_pop_error_fnct)(void (*fnct_pop)());
	
RSLNK_EXPORT void RSLNK_DECL(set_rs_groebner)(void (*fnct_gb)());

RSLNK_EXPORT void RSLNK_DECL(rs_restore_gmp_alloc)();
RSLNK_EXPORT void RSLNK_DECL(rs_set_gmp_alloc)();

RSLNK_EXPORT void RSLNK_DECL(rs_export_collect)();
RSLNK_EXPORT void RSLNK_DECL(rs_export_mark)();
RSLNK_EXPORT void RSLNK_DECL(rs_export_unmark)();
RSLNK_EXPORT void RSLNK_DECL(rs_export_preserve_grob)();

RSLNK_EXPORT void RSLNK_DECL(rs_infos)();
RSLNK_EXPORT void RSLNK_DECL(rs_unstable)();
RSLNK_EXPORT void RSLNK_DECL(rs_stable)();

RSLNK_EXPORT void RSLNK_DECL(rs3_enable)();
RSLNK_EXPORT void RSLNK_DECL(rs3_disable)();

RSLNK_EXPORT  char * RSLNK_DECL(rs_get_import_buff)();

RSLNK_EXPORT void RSLNK_DECL(set_rs_output)(void (*fnct_out)(FILE *f,const char *a,...));
RSLNK_EXPORT void RSLNK_DECL(set_rs_check_interrupt)(void (*fnct_inter)());
RSLNK_EXPORT void RSLNK_DECL(set_rs_default_output)();
RSLNK_EXPORT void RSLNK_DECL(set_rs_dont_use_signal)();

RSLNK_EXPORT void RSLNK_DECL(set_rs_nbprimes)(const int p);
RSLNK_EXPORT void RSLNK_DECL(set_rs_precisol)(const int p);
RSLNK_EXPORT int RSLNK_DECL(get_rs_precisol)();

RSLNK_EXPORT int RSLNK_DECL(get_rs_hybrid_limit)();
RSLNK_EXPORT void RSLNK_DECL(set_rs_hybrid_limit)(const int p);
RSLNK_EXPORT void RSLNK_DECL(set_rs_precision_level)(const int p);  
RSLNK_EXPORT int RSLNK_DECL(get_rs_precision_level)();

RSLNK_EXPORT int RSLNK_DECL(rs_get_sepvar)();
RSLNK_EXPORT void RSLNK_DECL(rs_set_sepvar)(const int v);
RSLNK_EXPORT int RSLNK_DECL(rs_get_sepvect)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_sep_vector)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_sep_vector_elt)(const int);
RSLNK_EXPORT void RSLNK_DECL(rs_set_dim_sep_vector)(const int);

RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_constraints_dens)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_constraints_dens_elt)(const int);
RSLNK_EXPORT void RSLNK_DECL(rs_set_dim_constraints_dens)(const int);

RSLNK_EXPORT void RSLNK_DECL(rs_set_sepvect)(const int v);
RSLNK_EXPORT int RSLNK_DECL(rs_get_degrad)();
RSLNK_EXPORT int RSLNK_DECL(rs_get_dimquo)();
RSLNK_EXPORT int RSLNK_DECL(rs_get_iszdim)();
RSLNK_EXPORT int RSLNK_DECL(rs_get_shape_lemma)();

RSLNK_EXPORT void RSLNK_DECL(set_rs_verbose)(const int p);

RSLNK_EXPORT void RSLNK_DECL(set_rs_max_nb_roots)(const int p);

RSLNK_EXPORT int RSLNK_DECL(get_rs_max_nb_roots)();

RSLNK_EXPORT void RSLNK_DECL(unset_rs_max_nb_roots)();

RSLNK_EXPORT float RSLNK_DECL(rs_get_time)();

RSLNK_EXPORT char * RSLNK_DECL(rs_rat_2_mpfi_str)(const char *n,const char *d,const int prec);

RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_grob)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_rr)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_ineqs_m)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_restrict_m)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_saturate_m)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_up)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_rur_ext)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_rur_den)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_rur_num_vars)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_rur_num_ineqs)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_ineqs_u)();

RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_todo_interv_u_mpfi)();
RSLNK_EXPORT void RSLNK_DECL(rs_import_todo_interv_u_mpfi)(RSLNK_PTR_IN,RSLNK_PTR_IN);
RSLNK_EXPORT void RSLNK_DECL(rs_import_todo_interv_u_rn_bz)(RSLNK_PTR_IN,const int,RSLNK_PTR_IN,const int);

RSLNK_EXPORT void RSLNK_DECL(rs_import_todo_interv_u_doubles)(const double left,const double right);

RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_sols_eqs)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_sols_eqs_u)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_sols_ineqs)();
RSLNK_EXPORT char *  RSLNK_DECL(rs_get_error)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_tci_pol)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_tci_abs)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_tci_ords)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_tci_abs_r)();
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_tci_ords_r)();
RSLNK_EXPORT void RSLNK_DECL(set_tci_params)(const int prec_res,const double x_min,const double x_max,const double y_min,const double y_max,const int nbp,const int prec_arith);


/* call refine */

RSLNK_EXPORT void RSLNK_DECL(rs_refine_u)(const int root_pos, const int prec);

RSLNK_EXPORT void RSLNK_DECL(rs_refine_coord)(const int root_pos, const int coord_pos, const int prec);


/* init rs */
RSLNK_EXPORT void RSLNK_DECL(rs_init_rs)();

/* free all the memory dynamically allocated by RS */
RSLNK_EXPORT void RSLNK_DECL(rs_free_memory)();

/* reset rs default variables */
RSLNK_EXPORT void RSLNK_DECL(rs_reset_all)();

/* exports a pointer to rs_bz data structure */
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_mpfi)();
/* exports a string from a bz */
RSLNK_EXPORT char * RSLNK_DECL(rs_export_mpfi_str)(RSLNK_PTR_IN a);
RSLNK_EXPORT void RSLNK_DECL(rs_import_mpfi_d)(RSLNK_PTR_IN a,const double b);
RSLNK_EXPORT void RSLNK_DECL(rs_import_mpfi_r_r)(RSLNK_PTR_IN a,RSLNK_PTR_IN num1,RSLNK_PTR_IN den1,RSLNK_PTR_IN num2,RSLNK_PTR_IN den2,const long int prec);
RSLNK_EXPORT void RSLNK_DECL(rs_import_mpfi_r)(RSLNK_PTR_IN a,RSLNK_PTR_IN num1,RSLNK_PTR_IN den1,const long int prec);
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_ibfr_mpfi)(RSLNK_PTR_IN a);
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_mpfi_left_mantissa)(RSLNK_PTR_IN a);
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_mpfi_right_mantissa)(RSLNK_PTR_IN a);
RSLNK_EXPORT int RSLNK_DECL(rs_export_mpfi_left_exp)(RSLNK_PTR_IN a);
RSLNK_EXPORT int RSLNK_DECL(rs_export_mpfi_right_exp)(RSLNK_PTR_IN a);

/* exports a pointer to rs_bz data structure */
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_gmp)();
/* import a gmp data structure (2) into a bz (1) */
RSLNK_EXPORT void RSLNK_DECL(rs_import_bz_gmp)(RSLNK_PTR_IN a,RSLNK_PTR_IN b);
RSLNK_EXPORT void RSLNK_DECL(rs_import_bz_i)(RSLNK_PTR_IN a,long b);
/*RSLNK_EXPORT void RSLNK_DECL(rs_import_bz_gmp)(RSLNK_PTR_IN a,RSLNK_PTR_IN b);*/
/* import a string (2) into a bz (1) */
RSLNK_EXPORT void RSLNK_DECL(rs_import_bz_str)(RSLNK_PTR_IN a,const char *s);
/* exports a string from a bz */
RSLNK_EXPORT char * RSLNK_DECL(rs_export_bz_str)(RSLNK_PTR_IN a);
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_bz_gmp)(RSLNK_PTR_IN a);

RSLNK_EXPORT void RSLNK_DECL(rs_import_ibfr_mpfr)(RSLNK_PTR_IN a,RSLNK_PTR_IN b);
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_ibfr_mpfr)(RSLNK_PTR_IN a);

/* exports the pointer to the default pp_ring */
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_ppring_ref)();
/* sets the variable string (2) of any variable (3) of the default */
RSLNK_EXPORT void RSLNK_DECL(rs_import_ppring_var)(const int i,const char *v);
/* initializes the number of variables(2) of the default pp_ring */
RSLNK_EXPORT void RSLNK_DECL(rs_init_ppring_nb)(const int n,const char *o);
/* exports the number of variables of the default pp_ring*/
RSLNK_EXPORT int RSLNK_DECL(rs_export_ppring_nb)();
/* exports the ith variable of the default pp_ring*/
RSLNK_EXPORT char* RSLNK_DECL(rs_export_ppring_var)(const int i);
/* exports the ith variable of the default pp_ring*/
RSLNK_EXPORT char** RSLNK_DECL(rs_export_ppring_vars)();

/* exports the pointer to the default pp_ring */
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_get_default_uppring_ref)();
/* sets the variable string (2) of any variable (3) of the default */
RSLNK_EXPORT void RSLNK_DECL(rs_import_uppring)(char *v);
/* exports the ith variable of the default pp_ring*/
RSLNK_EXPORT char* RSLNK_DECL(rs_export_uppring_var)();

/* exports the pointer to a new pp data structure */
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_pp)();
/* sets the degree (3) of the ith (2) variable of the default ppring */
RSLNK_EXPORT void RSLNK_DECL(rs_set_pp_deg)(RSLNK_PTR_IN a, const int i, const int d);
/* gets the degree of the ith (2) variable of the default pp_ring*/
RSLNK_EXPORT int  RSLNK_DECL(rs_export_pp_deg)(RSLNK_PTR_IN a, const int i);
/* exports the pointer to a new mon data structure */

RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_mon_pp_bz)();
/* sets the coefficient (2) and the pp (3) of a monomial (1) */
RSLNK_EXPORT void RSLNK_DECL(rs_dset_mon_pp_bz)(RSLNK_PTR_IN a,RSLNK_PTR_IN c,RSLNK_PTR_IN p);
/* exports the pointer to the coeff of a monomial*/
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_mon_pp_bz_coeff)(RSLNK_PTR_IN a);
/* exports the pointer to the pp of a monomial*/
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_mon_pp_bz_pp)(RSLNK_PTR_IN a);

RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_mon_upp_bz)();
/* sets the coefficient (2) and the pp (3) of a monomial (1) */
RSLNK_EXPORT void RSLNK_DECL(rs_dset_mon_upp_bz)(RSLNK_PTR_IN a,RSLNK_PTR_IN c,const int p);
/* exports the pointer to the coeff of a monomial*/
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_mon_upp_bz_coeff)(RSLNK_PTR_IN a);
/* exports the pointer to the pp of a monomial*/
RSLNK_EXPORT int RSLNK_DECL(rs_export_mon_upp_bz_deg)(RSLNK_PTR_IN a);

/* VECTORS */

#define rs_genere_exports_vect(lt) \
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_vect_ ## lt  )(const int); \
RSLNK_EXPORT int RSLNK_DECL(rs_export_dim_vect_ ## lt  )(RSLNK_PTR_IN); \
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_elt_vect_ ## lt  )(RSLNK_PTR_IN,const int); \
RSLNK_EXPORT void RSLNK_DECL(rs_import_elt_vect_ ## lt  )(RSLNK_PTR_IN,RSLNK_PTR_IN,const int);

rs_genere_exports_vect(ibfr)
rs_genere_exports_vect(bz)

/* LISTS */
#define rs_genere_exports_list(lt) \
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_new_list_ ## lt  )(); \
RSLNK_EXPORT void RSLNK_DECL(rs_reinit_list_  ## lt  )(RSLNK_PTR_IN p); \
RSLNK_EXPORT void RSLNK_DECL(rs_dappend_list_ ## lt  )(RSLNK_PTR_IN p,RSLNK_PTR_IN m); \
RSLNK_EXPORT int RSLNK_DECL(rs_export_list_ ## lt ## _nb)(RSLNK_PTR_IN p); \
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_list_ ## lt ## _firstnode)(RSLNK_PTR_IN p); \
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_list_ ## lt ## _nextnode)(RSLNK_PTR_IN p); \
RSLNK_EXPORT RSLNK_PTR_OUT RSLNK_DECL(rs_export_list_ ## lt ## _monnode)(RSLNK_PTR_IN p);

rs_genere_exports_list(mon_pp_bz)
rs_genere_exports_list(smp_bz)
rs_genere_exports_list(mon_upp_bz)
rs_genere_exports_list(sup_bz)
rs_genere_exports_list(vect_ibfr)

/* reinitialise les variables globales de RS et retourne leur nombre */
RSLNK_EXPORT void RSLNK_DECL(rs_run_algo)(char *);

/* libere la memoire de RS et le ramene dans un etat stable */
RSLNK_EXPORT void RSLNK_DECL(rs_interrupt)(const int,void *);

void RSLNK_DECL(rs_num_solve_u)(double * dpol, const int d, double * dres, int * nb);

#ifdef USE_RS3
  /* rs_exports pour rs3 */
  /* #include "rs3_export.h"*/
#endif
#ifdef __cplusplus
}
#endif

#endif
