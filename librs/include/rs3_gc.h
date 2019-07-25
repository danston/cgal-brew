#ifndef _rs3_gc_h
#define _rs3_gc_h

typedef unsigned int RSGC_UI;
typedef int RSGC_I;

typedef int RSGC_HEAP;

typedef char * RSGC_PTR;

#define rsgc_default_heap 0
#define rsgc_temp_heap 1

#define rs3_default_heap rsgc_default_heap
#define rs3_temp_heap rsgc_temp_heap

extern void * rsgc_alloc(const RSGC_UI,const RSGC_HEAP);
extern void * rsgc_realloc(void* ,const RSGC_UI,const RSGC_UI,const RSGC_HEAP);
extern void rsgc_init_heap(const RSGC_HEAP);
extern void rsgc_mark_heap(const RSGC_HEAP);
extern void rsgc_unmark_heap(const RSGC_HEAP);
extern void rsgc_collecte_heap(const RSGC_HEAP);

extern void rsgc_set_object(const RSGC_HEAP,RSGC_PTR *,const RSGC_UI,const RSGC_UI);

#endif
