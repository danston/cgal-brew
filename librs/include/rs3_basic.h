#ifndef _rs3_basic_h
#define _rs3_basic_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define RS3_CHAR char


#define RS3_ISNULL(a) ((a)==0)
#define RS3_ISPOS(a) ((a)>0)
#define RS3_IS0NEG(a) ((a)<0)

#define RS3_MAX(a,b) (((a>b) ? a :b))

#include "rs3_config.h"


#define RS3_EXPORT extern
#define RS3_STATIC static

#define RS3_STRING char *

#define RS3_FILE FILE

#define RS3_PTR_NULL NULL
#define RS3_ISNULL_PTR(a) ((a)==NULL)

/* ******************************************************************* */
/* Boolean operators */
/* ******************************************************************* */


#define RS3_EQ(a,b) ((a)==(b))
#define RS3_NEQ(a,b) ((a)!=(b))
#define RS3_L(a,b) ((a)<(b))
#define RS3_G(a,b) ((a)>(b))
#define RS3_LEQ(a,b) ((a)<=(b))
#define RS3_GEQ(a,b) ((a)>=(b))
#define RS3_NOT(a) (!(a))
#define RS3_OR(a,b) ((a) || (b))
#define RS3_AND(a,b) ((a) && (b))
#define RS3_CMP(a,b) (((a)>(b)) ? 1 : -RS3_L(a,b))

/* ******************************************************************* */
/* GC */
/* ******************************************************************* */

#ifndef NO_RSGC 
#include "rs3_gc.h"
#define RS3_MALLOC(a) rs3_alloc(a,rs3_default_heap);
#define RS3_REALLOC(a,os,ns) rs3_realloc(a,os,ns,rs3_default_heap);
/* #define RS3_MARK rsgc_mark_heap(rs3_default_heap)*/
/* #define RS3_COLLECT rsgc_collecte_heap(rs3_default_heap)*/
/* #define RS3_UNMARK rsgc_unmark_heap(rs3_default_heap)*/
#endif
#define RS3_MEMCPY(dest,src,nb) memcpy((void *)dest,(void *)src,nb)
#define RS3_MEMSET(ptr,c,nb) memset((void *)ptr,c,nb)


/* ******************************************************************* */
/* STYLE */
/* ******************************************************************* */
#define RS3_REF(a) (&(a))
/* tabeaux */
#define RS3_ALLOC(a) (((a)->data))
#define RS3_NB_ALLOC(a) (((a)->nb_data))
#define RS3_REP(a) (((a)->rep))
#define RS3_NB(a) (((a)->nb_rep))
#define RS3_MAX_IND(a) (((a)->nb_rep))
#define RS3_ELT(a,i) (((a)->rep)[i])

/* ******************************************************************* */
/* IO */
/* ******************************************************************* */

RS3_EXPORT void RS3_OUT_ERROR(const RS3_STRING,...);
RS3_EXPORT void RS3_OUT_INFO(const RS3_UI32,const RS3_STRING,...);
RS3_EXPORT void RS3_OUT_DEBUG(const RS3_UI32,const RS3_STRING,...);
RS3_EXPORT void RS3_OUT(const RS3_STRING,...);

RS3_EXPORT void (*RS3_IO_BUF_2_STDERR)();
RS3_EXPORT void (*RS3_IO_BUF_2_STDINFO)();
RS3_EXPORT void (*RS3_IO_BUF_2_STDOUT)();
RS3_EXPORT void (*RS3_IO_BUF_2_STDDEBUG)();

RS3_EXPORT RS3_CHAR * rs3_get_io_buf_ptr();
RS3_EXPORT RS3_CHAR * rs3_get_io_err_ptr();

RS3_EXPORT void rs3_set_debug_level(const unsigned int);
RS3_EXPORT void rs3_set_verbose_level(const unsigned int);
RS3_EXPORT void rs3_set_nbthreads(const unsigned int);
RS3_EXPORT int  rs3_get_nbthreads();

RS3_EXPORT void rs3_set_default_io();
RS3_EXPORT void rs3_set_io_basic(void (*IO_BUF_2_FILE)(FILE *,const char *));

/* ******************************************************************* */
/* INITIALIZATIONS */
/* ******************************************************************* */
RS3_EXPORT void rs3_reset_error();
RS3_EXPORT void rs3_internal_reset();
RS3_EXPORT void rs3_internal_init();

RS3_EXPORT void * (*rs3_alloc) (size_t);
RS3_EXPORT void * (*rs3_realloc) (void *, size_t);
RS3_EXPORT void   (*rs3_free) (void *);

RS3_EXPORT void * (*rs3_usr_alloc) (size_t);
RS3_EXPORT void * (*rs3_usr_realloc) (void *, size_t);
RS3_EXPORT void   (*rs3_usr_free) (void *);

RS3_EXPORT void * (*rs3_gmp_usr_alloc)(size_t);
RS3_EXPORT void * (*rs3_gmp_usr_realloc)(void *, size_t, size_t);
RS3_EXPORT void   (*rs3_gmp_usr_free)(void *, size_t);

RS3_EXPORT void * rs3_gmp_alloc(size_t );
RS3_EXPORT void * rs3_gmp_realloc(void *,size_t,size_t);
RS3_EXPORT void   rs3_gmp_free(void *,size_t);

/* ******************************************************************* */
/* SESSIONS */
/* ******************************************************************* */
typedef struct {
  RSGC_HEAP default_heap;
}rs3_session_struct;

typedef rs3_session_struct rs3_session_t[1];
typedef rs3_session_struct * rs3_session_ptr;
typedef rs3_session_struct * rs3_session_srcptr;

#define RS3_SESSION rs3_session_t

RS3_EXPORT rs3_session_t rs3_default_session;

#define SESSION_DEFAULT_HEAP(h) ((h)->default_heap)

RS3_EXPORT float rs3_timediff();

/*
#include "rs3_session.h"
#include "rs3_export.h"
*/

#endif
