/* INCLUDE/config.h.  Generated automatically by configure.  */
/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/


/* Define if your compiler is missing the appropriate function prototype */

/* #undef CC_PROTO_PRINTF */
/* #undef CC_PROTO_GETHOSTNAME */
/* #undef CC_PROTO_GETRUSAGE */

/* Define if you want to use posix threads */
/* #undef CC_POSIXTHREADS */

/* Define if <signal.h> needs to be included before <pthreads.h> */
/* #undef CC_SIGNAL_BEFORE_PTHREAD */

/* Define to empty if the keyword `const' does not work.  */
/* #undef const */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define to `unsigned char' if <sys/types.h> doesn't define.  */
/* #undef u_char */

/* Define to `int' if the builtin type `void' does not work.  */
/* #undef void */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define one of the following three to specify the type of signal
 * handling to use. */
#define  CCSIGNAL_SIGACTION 1 /* sigaction(), preferred */
/* #undef  CCSIGNAL_SIGNAL */    /* signal() */
/* #undef  CCSIGNAL_NONE */      /* no signal handling */

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME 1

/* Define if you have the socket function.  */
#define HAVE_SOCKET 1

/* Define if you have the strdup function.  */
#define HAVE_STRDUP 1

/* Define if you have the getrusage function.  */
#define HAVE_GETRUSAGE 1

/* Define if you have the times function.  */
#define HAVE_TIMES 1

/* Define if you have the clock function.  */
#define HAVE_CLOCK 1

/* Define if you have the sleep function.  */
#define HAVE_SLEEP 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <math.h> header file.  */
#define HAVE_MATH_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <errno.h> header file.  */
#define HAVE_ERRNO_H 1

/* Define if you have the <assert.h> header file.  */
#define HAVE_ASSERT_H 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <time.h> header file.  */
#define HAVE_TIME_H 1

/* Define if you have the <stddef.h> header file.  */
#define HAVE_STDDEF_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <malloc.h> header file.  */
#define HAVE_MALLOC_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/resource.h> header file.  */
#define HAVE_SYS_RESOURCE_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <signal.h> header file.  */
#define HAVE_SIGNAL_H 1

/* Define if you have the <sys/socket.h> header file.  */
#define HAVE_SYS_SOCKET_H 1

/* Define if you have the <netdb.h> header file.  */
#define HAVE_NETDB_H 1

/* Define if you have the <netinet/in.h> header file.  */
#define HAVE_NETINET_IN_H 1

/* Define if you have the <sys/param.h> header file.  */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <sys/times.h> header file.  */
#define HAVE_SYS_TIMES_H 1

/* Define if your compiler supports attribute modifiers  */
/* such as __attribute__ ((unused)) (gcc 2.8.1 does)     */
#define CC_ATTRIBUTE 1

/* Define if your header files use non-Ansi casts for SIG_ERR, SIG_IGN, */
/* or SIG_DFL */
/* #undef CC_BADSIGDEF_CAST */

/* Some machine (o/s) specific problems */

/* Define if unistd.h uses __vfork but does not prototype it */
/* This happens under Irix 6 */
/* #undef CC_PROTO___VFORK */

/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/

#ifndef __MACHDEFS_H
#define __MACHDEFS_H

#define NDEBUG


#ifdef CC_POSIXTHREADS
#ifdef CC_SIGNAL_BEFORE_PTHREAD
#include <signal.h>
#endif
#include <pthread.h>
#endif

#include <stdio.h>

#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif
#ifdef HAVE_MATH_H
# include <math.h>
#endif
#ifdef HAVE_STRING_H
# include <string.h>
#else
# ifdef HAVE_STRINGS_H
#  include <strings.h>
# endif
#endif
#ifdef HAVE_ERRNO_H
# include <errno.h>
#endif
#ifdef HAVE_ASSERT_H
# include <assert.h>
#endif
#ifdef TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# ifdef HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  ifdef HAVE_TIME_H
#   include <time.h>
#  endif
# endif
#endif
#ifdef HAVE_STDDEF_H
# include <stddef.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#ifdef HAVE_MALLOC_H
# include <malloc.h>
#endif
#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif
#ifdef HAVE_SYS_RESOURCE_H
# include <sys/resource.h>
#endif
#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#endif
#ifdef HAVE_SIGNAL_H
# include <signal.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#ifdef HAVE_NETDB_H
# include <netdb.h>
#endif
#ifdef HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif

#ifdef HAVE_SOCKET
#define CC_NETREADY
#endif

#ifdef CC_ATTRIBUTE
#define CC_UNUSED __attribute__ ((unused))
#else
#define CC_UNUSED
#endif

#ifdef CC_PROTO_PRINTF
/* assume that if you're missing printf, you're missing a bunch */
extern int
    printf (const char *, ...),
    fprintf (FILE *, const char *, ...),
    fflush (FILE *),
    scanf (const char *, ...),
    sscanf (const char *, const char *, ...),
    fscanf (FILE *, const char *, ...),
    fclose (FILE *),
    ungetc (int, FILE *),
    _filbuf (FILE *),
    time (int *);
#ifdef CC_NETREADY
extern int
    socket (int, int, int),
    connect (int, const struct sockaddr *, int),
    accept (int, struct sockaddr *, int *),
    bind (int, const struct sockaddr *, int),
    listen (int, int);
#endif
extern void
   *memset (void *, int, size_t),
    perror (const char *);
#endif

#ifdef CC_PROTO_RENAME
extern int
    rename (const char *, const char *);
#endif

#ifdef CC_PROTO_GETHOSTNAME
extern int
    gethostname (char *, int);
#endif

#ifdef CC_PROTO_GETRUSAGE
extern int
    getrusage (int, struct rusage *);
#endif

#ifdef CC_PROTO___VFORK
extern pid_t
    __vfork (void);
#endif

#ifndef NULL
#define NULL (0)
#endif

#ifndef INT_MAX
#define INT_MAX ((int) (~(((unsigned) 1) << ((8*sizeof(int))-1))))
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef SEEK_SET
#ifdef L_SET
#define SEEK_SET L_SET
#else
#define SEEK_SET 0
#endif
#endif

#ifdef CC_BADSIGDEF_CAST

#undef SIG_ERR
#undef SIG_DFL
#undef SIG_IGN
#define SIG_ERR ((void(*)(int))-1)
#define SIG_DFL ((void(*)(int))0)
#define SIG_IGN ((void(*)(int))1)

#endif

#endif  /* __MACHDEFS_H */
/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/*                      PROTOTYPES FOR FILES IN UTIL                        */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*    EXPORTED FUNCTIONS:                                                   */
/*                                                                          */
/*  CC_SAFE_MALLOC(nnum,type)                                               */
/*    int nnum (the number of objects to be malloced)                       */
/*    data type (the sort of objects to be malloced)                        */
/*    RETURNS a pointer to the allocated space. If out of memory,           */
/*            it prints an error message and returns NULL.                  */
/*                                                                          */
/*  CC_FREE(object,type)                                                    */
/*    type *object (pointer to previously allocated space)                  */
/*    data type (the sort of object)                                        */
/*    ACTION: frees the memory and sets the object to NULL.                 */
/*                                                                          */
/*  CC_IFFREE(object,type)                                                  */
/*    type *object (pointer to previously allocated space)                  */
/*    data type (the sort of object)                                        */
/*    ACTION: if *object is not NULL, frees the memory and sets             */
/*            the object to NULL.                                           */
/*                                                                          */
/*  CC_PTR_ALLOC_ROUTINE (type, functionname, chunklist, freelist)          */
/*    data type (the sort of objects)                                       */
/*    string functionname (the generated function)                          */
/*    CCbigchunkptr *chunklist (used to accumulate bigchunks)               */
/*    type *freelist (used for the linked list of objects)                  */
/*    ACTION: Generates a function ("functionname") that returns            */
/*            (type *) objects, keeping the free ones on freelist           */
/*            and getting its space from calls to                           */
/*            CCutil_bigchunkalloc.                                         */
/*                                                                          */
/*  CC_PTR_FREE_ROUTINE (type, functionname, freelist)                      */
/*    Parameters as above.                                                  */
/*    ACTION: Generates a function that adds an object to the               */
/*            freelist.                                                     */
/*                                                                          */
/*  CC_PTR_FREE_LIST_ROUTINE (type, functionname, freefunction)             */
/*    Parameters defined as above, with freefunction the function           */
/*    generated by CC_PTR_FREE_ROUTINE.                                     */
/*    ACTION: Generates a function to free a linked list of                 */
/*            objects using calls to freefunction.                          */
/*                                                                          */
/*  CC_PTR_FREE_WORLD_ROUTINE (type, functionname, chunklist, freelist)     */
/*    Parameters defined as above.                                          */
/*    ACTION: Generates a function that returns all of the                  */
/*            memory used in the CC_PTR_ALLOC_ROUTINE allocations           */
/*            back to the global supply of CCbigchunkptrs.                  */
/*                                                                          */
/*  CC_PTR_LEAKS_ROUTINE (type, name, chunklist, freelist, field,           */
/*      fieldtype)                                                          */
/*    As above, with "field" the name of a "fieldtype" field in the         */
/*    object type that can be set to 0 or to 1.                             */
/*    ACTION: Generates a function that checks to see that we have          */
/*            not leaked any of the objects.                                */
/*                                                                          */
/*  CC_PTR_STATUS_ROUTINE (type, name, chunklist, freelist)                 */
/*       ACTION: Like LEAKS, but does not check for duplicates (and so      */
/*               does not corrupt the objects).                             */
/*                                                                          */
/*    NOTES:                                                                */
/*       These routines use the functions in allocrus.c.  The PTR macros    */
/*    generate the functions for allocating objects for linked lists. They  */
/*    get their raw memory from the bigchunk supply, so foo_free_world      */
/*    (generated by CC_PTR_FREE_WORLD_ROUTINE) should be called for each    */
/*    type of linked object "foo" when closing down the local memory.       */
/*       To use these functions, put the macros near the top of the file    */
/*    before any calls to the functions (since the macros also write the    */
/*    function prototypes). If you use CC_PTR_FREE_LIST_ROUTINE for foo,    */
/*    you must also use CC_PTR_FREE_ROUTINE, and                            */
/*    CC_PTR_FREE_LIST_ROUTINE must be listed after CC_PTR_FREE_ROUTINE     */
/*    (to get the prototype).                                               */
/*                                                                          */
/****************************************************************************/

#ifndef __UTIL_H
#define __UTIL_H


#define CCutil_MAXDOUBLE (1e30)
#define CCutil_MAXINT    (2147483647)

#define CCcheck_rval(rval,msg) {                                          \
    if ((rval)) {                                                          \
        fprintf (stderr, "%s\n", (msg));                                   \
        goto CLEANUP;                                                      \
    }                                                                      \
}

#define CCcheck_NULL(item,msg) {                                           \
    if ((!item)) {                                                         \
        fprintf (stderr, "%s\n", (msg));                                   \
        rval = 1;                                                          \
        goto CLEANUP;                                                      \
    }                                                                      \
}


#define CC_SBUFFER_SIZE (4000)
#define CC_SFNAME_SIZE (32)

typedef struct CC_SFILE {
    int           status;
    int           desc;
    int           type;
    int           chars_in_buffer;
    int           current_buffer_char;     /* only used for reading */
    int           bits_in_last_char;       /* writing: number of empty bits in
                                            * buffer[chars_in_buffer];
                                            * reading: number of full bits in
                                            * buffer[?] */
    int           pos;
    char          fname[CC_SFNAME_SIZE];
    char          hname[CC_SFNAME_SIZE];
    unsigned char buffer[CC_SBUFFER_SIZE];
} CC_SFILE;

#ifdef CC_NETREADY
typedef struct CC_SPORT {
    unsigned short port;
    int t;
} CC_SPORT;
#endif /* CC_NETREADY */

typedef struct CCrandstate {
    int a;
    int b;
    int arr[55];
} CCrandstate;

/****************************************************************************/
/*                                                                          */
/*                             allocrus.c                                   */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*                   MEMORY ALLOCATION MACROS                               */
/*                                                                          */
/*                           TSP CODE                                       */
/*                                                                          */
/*                                                                          */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                        */
/*  Date: February 24, 1995 (cofeb24)                                       */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#define CC_SAFE_MALLOC(nnum,type)                                          \
    (type *) CCutil_allocrus (((size_t) (nnum)) * sizeof (type))

#define CC_FREE(object,type) {                                             \
    CCutil_freerus ((void *) (object));                                    \
    object = (type *) NULL;                                                \
}

#define CC_IFFREE(object,type) {                                           \
    if ((object)) CC_FREE ((object),type);                                 \
}

#define CC_PTRWORLD_ALLOC_ROUTINE(type, ptr_alloc_r, ptr_bulkalloc_r)        \
                                                                             \
static int ptr_bulkalloc_r (CCptrworld *world, int nalloc)                   \
{                                                                            \
    CCbigchunkptr *bp;                                                       \
    int i;                                                                   \
    int count = CC_BIGCHUNK / sizeof ( type );                               \
    type *p;                                                                 \
                                                                             \
    while (nalloc > 0) {                                                     \
        bp = CCutil_bigchunkalloc ();                                        \
        if (bp == (CCbigchunkptr *) NULL) {                                  \
            fprintf (stderr, "ptr alloc failed\n");                          \
            return 1;                                                        \
        }                                                                    \
        bp->next = world->chunklist ;                                        \
        world->chunklist = bp;                                               \
                                                                             \
        p = ( type * ) bp->this_one;                                         \
        for (i=count-2; i>=0; i--) {                                         \
            p[i].next = &p[i+1];                                             \
        }                                                                    \
        p[count - 1].next = (type *) world->freelist;                        \
        world->freelist = (void *) p;                                        \
        nalloc -= count;                                                     \
    }                                                                        \
    return 0;                                                                \
}                                                                            \
                                                                             \
static type *ptr_alloc_r (CCptrworld *world)                                 \
{                                                                            \
    type *p;                                                                 \
                                                                             \
    if (world->freelist == (void *) NULL) {                                  \
        if (ptr_bulkalloc_r (world, 1)) {                                    \
            fprintf (stderr, "ptr alloc failed\n");                          \
            return ( type * ) NULL;                                          \
        }                                                                    \
    }                                                                        \
    p = (type *) world->freelist ;                                           \
    world->freelist = (void *) p->next;                                      \
                                                                             \
    return p;                                                                \
}

#define CC_PTRWORLD_FREE_ROUTINE(type, ptr_free_r)                           \
                                                                             \
static void ptr_free_r (CCptrworld *world, type *p)                          \
{                                                                            \
    p->next = (type *) world->freelist ;                                     \
    world->freelist = (void *) p;                                            \
}

#define CC_PTRWORLD_LISTADD_ROUTINE(type, entrytype, ptr_listadd_r, ptr_alloc_r) \
                                                                             \
static int ptr_listadd_r (type **list, entrytype x, CCptrworld *world)       \
{                                                                            \
    if (list != (type **) NULL) {                                            \
        type *p = ptr_alloc_r (world);                                       \
                                                                             \
        if (p == (type *) NULL) {                                            \
            fprintf (stderr, "ptr list add failed\n");                       \
            return 1;                                                        \
        }                                                                    \
        p->this = x;                                                         \
        p->next = *list;                                                     \
        *list = p;                                                           \
    }                                                                        \
    return 0;                                                                \
}

#define CC_PTRWORLD_LISTFREE_ROUTINE(type, ptr_listfree_r, ptr_free_r)       \
                                                                             \
static void ptr_listfree_r (CCptrworld *world, type *p)                      \
{                                                                            \
    type *next;                                                              \
                                                                             \
    while (p != (type *) NULL) {                                             \
        next = p->next;                                                      \
        ptr_free_r (world, p);                                               \
        p = next;                                                            \
    }                                                                        \
}

#define CC_PTRWORLD_LEAKS_ROUTINE(type, ptr_leaks_r, field, fieldtype)       \
                                                                             \
static int ptr_leaks_r (CCptrworld *world, int *total, int *onlist)          \
{                                                                            \
    int count = CC_BIGCHUNK / sizeof ( type );                               \
    int duplicates = 0;                                                      \
    type * p;                                                                \
    CCbigchunkptr *bp;                                                       \
                                                                             \
    *total = 0;                                                              \
    *onlist = 0;                                                             \
                                                                             \
    for (bp = world->chunklist ; bp; bp = bp->next)                          \
        (*total) += count;                                                   \
                                                                             \
    for (p = (type *) world->freelist ; p; p = p->next) {                    \
        (*onlist)++;                                                         \
        p-> field = ( fieldtype ) 0;                                         \
    }                                                                        \
    for (p = (type *) world->freelist ; p; p = p->next) {                    \
        if ((unsigned long) p-> field == (unsigned long) (size_t) 1)                           \
            duplicates++;                                                    \
        else                                                                 \
            p-> field = ( fieldtype ) (size_t) 1;                            \
    }                                                                        \
    if (duplicates) {                                                        \
        fprintf (stderr, "WARNING: %d duplicates on ptr free list \n",       \
                 duplicates);                                                \
    }                                                                        \
    return *total - *onlist;                                                 \
}

#define CC_PTRWORLD_ROUTINES(type, ptr_alloc_r, ptr_bulkalloc_r, ptr_free_r) \
CC_PTRWORLD_ALLOC_ROUTINE (type, ptr_alloc_r, ptr_bulkalloc_r)               \
CC_PTRWORLD_FREE_ROUTINE (type, ptr_free_r)

#define CC_PTRWORLD_LIST_ROUTINES(type, entrytype, ptr_alloc_r, ptr_bulkalloc_r, ptr_free_r, ptr_listadd_r, ptr_listfree_r) \
CC_PTRWORLD_ROUTINES (type, ptr_alloc_r, ptr_bulkalloc_r, ptr_free_r)        \
CC_PTRWORLD_LISTADD_ROUTINE (type, entrytype, ptr_listadd_r, ptr_alloc_r)    \
CC_PTRWORLD_LISTFREE_ROUTINE (type, ptr_listfree_r, ptr_free_r)

#define CC_BIGCHUNK ((int) ((1<<16) - sizeof (CCbigchunkptr) - 16))

struct CCbigchunk;

typedef struct CCbigchunkptr {
    void                 *this_one;
    struct CCbigchunk    *this_chunk;
    struct CCbigchunkptr *next;
} CCbigchunkptr;


typedef struct CCptrworld {
    int refcount;
    void *freelist;
    CCbigchunkptr *chunklist;
} CCptrworld;



void
   *CCutil_allocrus (size_t size),
   *CCutil_reallocrus (void *ptr, size_t size),
    CCutil_freerus (void *p),
    CCutil_bigchunkfree (CCbigchunkptr *bp),
    CCptrworld_init (CCptrworld *world),
    CCptrworld_add (CCptrworld *world),
    CCptrworld_delete (CCptrworld *world);

int
    CCutil_reallocrus_scale (void **pptr, int *pnnum, int count, double scale,
        size_t size),
    CCutil_reallocrus_count (void **pptr, int count, size_t size);

CCbigchunkptr
    *CCutil_bigchunkalloc (void);




/****************************************************************************/
/*                                                                          */
/*                             bgetopt.c                                    */
/*                                                                          */
/****************************************************************************/


int
    CCutil_bix_getopt (int argc, char **argv, const char *def, int *p_optind,
        char **p_optarg);


#define CC_BIX_GETOPT_UNKNOWN -3038



/****************************************************************************/
/*                                                                          */
/*                             dheaps_i.c                                   */
/*                                                                          */
/****************************************************************************/

typedef struct CCdheap {
    double  *key;
    int     *entry;
    int     *loc;
    int     total_space;
    int     size;
} CCdheap;


void
    CCutil_dheap_free (CCdheap *h),
    CCutil_dheap_delete (CCdheap *h, int i),
    CCutil_dheap_changekey (CCdheap *h, int i, double newkey);

int
    CCutil_dheap_init (CCdheap *h, int k),
    CCutil_dheap_resize (CCdheap *h, int newsize),
    CCutil_dheap_findmin (CCdheap *h),
    CCutil_dheap_deletemin (CCdheap *h),
    CCutil_dheap_insert (CCdheap *h, int i);



/****************************************************************************/
/*                                                                          */
/*                             edgeutil.c                                   */
/*                                                                          */
/****************************************************************************/

typedef struct CCelist {
    int  ecount;
    int *ends;
} CCelist;

typedef struct CCelistl {
    int  ecount;
    int *ends;
    int *len;
} CCelistl;

typedef struct CCelistw {
    int     ecount;
    int    *ends;
    double *weight;
} CCelistw;

typedef struct CCelistlw {
    int     ecount;
    int    *ends;
    int    *len;
    double *weight;
} CCelistlw;

void
    CCelist_init (CCelist *elist),
    CCelistl_init (CCelistl *elist),
    CCelistw_init (CCelistw *elist),
    CCelistlw_init (CCelistlw *elist),
    CCelist_free (CCelist *elist),
    CCelistl_free (CCelistl *elist),
    CCelistw_free (CCelistw *elist),
    CCelistlw_free (CCelistlw *elist);

int
    CCelist_alloc (CCelist *elist, int ecount),
    CCelistl_alloc (CCelistl *elist, int ecount),
    CCelistw_alloc (CCelistw *elist, int ecount),
    CCelistlw_alloc (CCelistlw *elist, int ecount),
    CCutil_edge_to_cycle (int ncount, int *elist, int *yesno, int *cyc);





/****************************************************************************/
/*                                                                          */
/*                             edgelen.c                                    */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*  Before defining CCUTIL_EDGELEN_FUNCTIONPTR, read the notes at the top   */
/*  of edgelen.c, and carefully consider the consequences.  You probably    */
/*  do not want CCUTIL_EDGELEN_FUNCTIONPTR defined.                         */
/*                                                                          */
/****************************************************************************/

#undef  CCUTIL_EDGELEN_FUNCTIONPTR

typedef struct CCdata_user {
    double  *x;
    double  *y;
} CCdata_user;

typedef struct CCdata_rhvector {
    int dist_00;
    int dist_01;
    int dist_02;
    int dist_12;
    int dist_22;
    double p;   
    int rhlength;
    char *space;
    char **vectors;
} CCdata_rhvector;

typedef struct CCdatagroup {
    int    (*edgelen) (int i, int j, struct CCdatagroup *dat);
    double  *x;
    double  *y;
    double  *z;
    int    **adj;
    int     *adjspace;
    int    **len;
    int     *lenspace;
    int     *degree;
    int      norm;
    int      dsjrand_param;
    int      default_len;     /* for edges not in sparse graph   */
    int      sparse_ecount;   /* number of edges in sparse graph */
    double   gridsize;        /* for toroidal norm */
    double   dsjrand_factor;
    CCdata_rhvector rhdat;
    CCdata_user     userdat;
    int      ndepot;          /* used with the subdivision code   */
    int      orig_ncount;     /* just ncount-ndepot               */
    int     *depotcost;       /* cost from each node to the depot */
    int     *orig_names;      /* the nodes names from full problem */
} CCdatagroup;



#ifdef CCUTIL_EDGELEN_FUNCTIONPTR
extern int
  (*CCutil_dat_edgelen) (int i, int j, CCdatagroup *dat);
#else  /* CCUTIL_EDGELEN_FUNCTIONPTR */
int
    CCutil_dat_edgelen (int i, int j, CCdatagroup *dat);
#endif /* CCUTIL_EDGELEN_FUNCTIONPTR */

int
    CCutil_dat_setnorm (CCdatagroup *dat, int norm);

void
    CCutil_dat_getnorm (CCdatagroup *dat, int *norm),
    CCutil_dsjrand_init (CCdatagroup *dat, int maxdist, int seed),
    CCutil_init_datagroup (CCdatagroup *dat),
    CCutil_freedatagroup (CCdatagroup *dat);


#define CC_KD_NORM_TYPE    128            /* Kdtrees work      */
#define CC_X_NORM_TYPE     256            /* Old nearest works */
#define CC_JUNK_NORM_TYPE  512            /* Nothing works     */

#define CC_D2_NORM_SIZE      1024         /* x,y coordinates   */
#define CC_D3_NORM_SIZE      2048         /* x,y,z coordinates */
#define CC_MATRIX_NORM_SIZE  4096         /* adj matrix        */

#define CC_NORM_BITS      (CC_KD_NORM_TYPE | CC_X_NORM_TYPE | \
                           CC_JUNK_NORM_TYPE)
#define CC_NORM_SIZE_BITS (CC_D2_NORM_SIZE | CC_D3_NORM_SIZE | \
                           CC_MATRIX_NORM_SIZE)

#define CC_MAXNORM        (0 |   CC_KD_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_EUCLIDEAN_CEIL (1 |   CC_KD_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_EUCLIDEAN      (2 |   CC_KD_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_EUCLIDEAN_3D   (3 |    CC_X_NORM_TYPE |     CC_D3_NORM_SIZE)
#define CC_USER           (4 | CC_JUNK_NORM_TYPE |                   0)
#define CC_ATT            (5 |    CC_X_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_GEOGRAPHIC     (6 |    CC_X_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_MATRIXNORM     (7 | CC_JUNK_NORM_TYPE | CC_MATRIX_NORM_SIZE)
#define CC_DSJRANDNORM    (8 | CC_JUNK_NORM_TYPE |                   0)
#define CC_CRYSTAL        (9 |    CC_X_NORM_TYPE |     CC_D3_NORM_SIZE)
#define CC_SPARSE        (10 | CC_JUNK_NORM_TYPE |                   0)
#define CC_RHMAP1        (11 | CC_JUNK_NORM_TYPE |                   0)
#define CC_RHMAP2        (12 | CC_JUNK_NORM_TYPE |                   0)
#define CC_RHMAP3        (13 | CC_JUNK_NORM_TYPE |                   0)
#define CC_RHMAP4        (14 | CC_JUNK_NORM_TYPE |                   0)
#define CC_RHMAP5        (15 | CC_JUNK_NORM_TYPE |                   0)
#define CC_EUCTOROIDAL   (16 | CC_JUNK_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_GEOM          (17 |    CC_X_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_MANNORM       (18 |   CC_KD_NORM_TYPE |     CC_D2_NORM_SIZE)
#define CC_SUBDIVISION   (99 | CC_JUNK_NORM_TYPE |                   0)

#define CC_GEOGRAPHIC_SCALE (6378.388 * 3.14 / 180.0)    /*  see edgelen.c  */
#define CC_GEOM_SCALE (6378388.0 * 3.14 / 180.0)         /*  see edgelen.c  */
#define CC_ATT_SCALE (.31622)                            /*  sqrt(1/10)     */

/* Distances CC_RHMAP1 through CC_RHMAP5 are for an application to          */
/* radiation hybrid mapping in genetics, explained in: Agarwala R,          */
/* Applegate DL,  Maglott D, Schuler GD, Schaffer AA: A Fast and Scalable   */
/* Radiation Hybrid Map Construction and Integration Strategy. Genome       */
/* Research, 10:350-364, 2000.  The correspondence to the distance function */
/* terms used in that paper is: CC_RMAP1 (weighted_ocb), CC_RHMAP2          */
/* (normalized_mle), CC_RHMAP3 (base_mle), CC_RHMAP4 (extended_mle),        */
/* CC_RHMAP5 (normalized_ocb)                                               */

/* For X-NORMS, scales are such that |x[i] - x[j]| * scale <= edgelen(i,j). */
/* Geographic is slightly off, since the fractional part of x[i] is really  */
/* really minutes, not fractional degrees.                                  */




/****************************************************************************/
/*                                                                          */
/*                             edgemap.c                                    */
/*                                                                          */
/****************************************************************************/

typedef struct CCutil_edgeinf {
    int                   ends[2];
    int                   val;
    struct CCutil_edgeinf *next;
} CCutil_edgeinf;

typedef struct CCutil_edgehash {
    CCutil_edgeinf **table;
    CCptrworld      edgeinf_world;
    unsigned int    size;
    unsigned int    mult;
} CCutil_edgehash;


int
    CCutil_edgehash_init (CCutil_edgehash *h, int size),
    CCutil_edgehash_add (CCutil_edgehash *h, int end1, int end2, int val),
    CCutil_edgehash_set (CCutil_edgehash *h, int end1, int end2, int val),
    CCutil_edgehash_del (CCutil_edgehash *h, int end1, int end2),
    CCutil_edgehash_find (CCutil_edgehash *h, int end1, int end2, int *val),
    CCutil_edgehash_getall (CCutil_edgehash *h, int *ecount, int **elist,
        int **elen);

void
    CCutil_edgehash_delall (CCutil_edgehash *h),
    CCutil_edgehash_free (CCutil_edgehash *h);


/****************************************************************************/
/*                                                                          */
/*                             eunion.c                                     */
/*                                                                          */
/****************************************************************************/

int
    CCutil_edge_file_union (int ncount, int nfiles, char **flist, int *ecount,
        int **elist, int **elen, int *foundtour, double *besttourlen);



/****************************************************************************/
/*                                                                          */
/*                             fastread.c                                   */
/*                                                                          */
/****************************************************************************/


int
    CCutil_readint (FILE *f);





/****************************************************************************/
/*                                                                          */
/*                             genhash.c                                    */
/*                                                                          */
/****************************************************************************/

struct CCgenhash_elem;

typedef struct CCgenhash {
    int                     nelem;
    int                     maxelem;
    int                     size;
    int                   (*hcmp) (void *key1, void *key2, void *u_data);
    unsigned int          (*hfunc) (void *key, void *u_data);
    void                   *u_data;
    double                  maxdensity;
    double                  lowdensity;
    CCptrworld              elem_world;
    struct CCgenhash_elem **table;
} CCgenhash;

typedef struct CCgenhash_iter {
    int                    i;
    struct CCgenhash_elem *next;
} CCgenhash_iter;


int
    CCutil_genhash_init (CCgenhash *h, int size, int (*hcmp) (void *key1,
        void *key2, void *u_data), unsigned int (*hfunc) (void *key,
        void *u_data), void *u_data, double maxdensity, double lowdensity),
    CCutil_genhash_insert (CCgenhash *h, void *key, void *data),
    CCutil_genhash_insert_h (CCgenhash *h, unsigned int hashval, void *key,
        void *data),
    CCutil_genhash_replace (CCgenhash *h, void *key, void *data),
    CCutil_genhash_replace_h (CCgenhash *h, unsigned int hashval, void *key,
        void *data),
    CCutil_genhash_delete (CCgenhash *h, void *key),
    CCutil_genhash_delete_h (CCgenhash *h, unsigned int hashval, void *key);

unsigned int
    CCutil_genhash_hash (CCgenhash *h, void *key);

void
   *CCutil_genhash_lookup (CCgenhash *h, void *key),
   *CCutil_genhash_lookup_h (CCgenhash *h, unsigned int hashval, void *key),
   *CCutil_genhash_next (CCgenhash *h, CCgenhash_iter *iter, void **key,
        int *keysize);

void
    CCutil_genhash_u_data (CCgenhash *h, void *u_data),
    CCutil_genhash_free (CCgenhash *h, void (*freefunc)(void *key, void *data,
        void *u_data)),
    CCutil_genhash_start (CCgenhash *h, CCgenhash_iter *iter);





/****************************************************************************/
/*                                                                          */
/*                             getdata.c                                    */
/*                                                                          */
/****************************************************************************/

#define  CC_MASTER_NO_DAT  100
#define  CC_MASTER_DAT     101

void
    CCutil_cycle_len (int ncount, CCdatagroup *dat, int *cycle, double *len);

int
    CCutil_getdata (char *datname, int binary_in, int innorm, int *ncount,
        CCdatagroup *dat, int gridsize, int allow_dups, CCrandstate *rstate),
    CCutil_writedata (char *datname, int binary_out, int ncount,
        CCdatagroup *dat),
    CCutil_putmaster (char *mastername, int ncount, CCdatagroup *dat,
        int *perm),
    CCutil_writemaster (CC_SFILE *out, int ncount, CCdatagroup *dat,
        int *perm),
    CCutil_getmaster (char *mastername, int *ncount, CCdatagroup *dat,
        int **perm),
    CCutil_readmaster (CC_SFILE *in, int *ncount, CCdatagroup *dat,
        int **perm),
    CCutil_getnodeweights (char *weightname, int ncount, int weight_limit,
        double **wcoord, CCrandstate *rstate),
    CCutil_gettsplib (char *datname, int *ncount, CCdatagroup *dat),
    CCutil_writetsplib (const char *fname, int ncount, CCdatagroup *dat),
    CCutil_datagroup_perm (int ncount, CCdatagroup *dat, int *perm),
    CCutil_copy_datagroup (int ncount, CCdatagroup *indat, CCdatagroup *outdat),
    CCutil_getedgelist (int ncount, char *fname, int *ecount, int **elist,
        int **elen, int binary_in),
    CCutil_getedgelist_n (int *ncount, char *fname, int *ecount, int **elist,
        int **elen, int binary_in),
    CCutil_genedgelist (int ncount, int ecount, int **elist, int **elen,
        CCdatagroup *dat, int maxlen, CCrandstate *rstate),
    CCutil_getcycle_tsplib (int ncount, char *cyclename, int *outcycle),
    CCutil_getcycle_edgelist (int ncount, char *cyclename, int *outcycle,
        int binary_in),
    CCutil_getcycle (int ncount, char *cyclename, int *outcycle,
        int binary_in),
    CCutil_getedges_double (int *ncount, char *fname, int *ecount, int **elist,
        double **elen, int binary_in),
    CCutil_writeedges (int ncount, char *outedgename, int ecount, int *elist,
        CCdatagroup *dat, int binary_out),
    CCutil_writecycle_edgelist (int ncount, char *outedgename, int *cycle,
        CCdatagroup *dat, int binary_out),
    CCutil_writecycle (int ncount, char *outcyclename, int *cycle,
        int binary_out),
    CCutil_writeedges_int (int ncount, char *outedgename, int ecount,
        int *elist, int *elen, int binary_out),
    CCutil_writeedges_double (int ncount, char *outedgename, int ecount,
        int *elist, double *elen, int binary_out),
    CCutil_tri2dat (int ncount, int *elen, CCdatagroup *dat),
    CCutil_graph2dat_matrix (int ncount, int ecount, int *elist, int *elen,
        int defaultlen, CCdatagroup *dat),
    CCutil_graph2dat_sparse (int ncount, int ecount, int *elist, int *elen,
        int defaultlen, CCdatagroup *dat),
    CCutil_get_sparse_dat_edges (int ncount, CCdatagroup *dat, int *ecount,
        int **elist, int **elen),
    CCutil_sparse_strip_edges (CCdatagroup *dat, int in_ecount, int *in_elist,
        int *in_elen, int *ecount, int **elist, int **elen),
    CCutil_sparse_real_tour (int ncount, CCdatagroup *dat, int *cyc,
        int *yesno);




/****************************************************************************/
/*                                                                          */
/*                             priority.c                                   */
/*                                                                          */
/****************************************************************************/

typedef struct CCpriority {
    CCdheap   heap;
    union CCpri_data {
        void *data;
        int  next;
    } *pri_info;
    int     space;
    int     freelist;
} CCpriority;


void
    CCutil_priority_free (CCpriority *pri),
    CCutil_priority_delete (CCpriority *pri, int handle),
    CCutil_priority_changekey (CCpriority *pri, int handle, double newkey),
   *CCutil_priority_findmin (CCpriority *pri, double *keyval),
   *CCutil_priority_deletemin (CCpriority *pri, double *keyval);

int
    CCutil_priority_init (CCpriority *pri, int k),
    CCutil_priority_insert (CCpriority *pri, void *data, double keyval);



/****************************************************************************/
/*                                                                          */
/*                             safe_io.c                                    */
/*                                                                          */
/****************************************************************************/


CC_SFILE
    *CCutil_sopen (const char *f, const char *s),
    *CCutil_sdopen (int d, const char *s);

int
    CCutil_swrite (CC_SFILE *f, char *buf, int size),
    CCutil_swrite_bits (CC_SFILE *f, int x, int xbits),
    CCutil_swrite_ubits (CC_SFILE *f, unsigned int x, int xbits),
    CCutil_swrite_char (CC_SFILE *f, char x),
    CCutil_swrite_string (CC_SFILE *f, const char *x),
    CCutil_swrite_short (CC_SFILE *f, short x),
    CCutil_swrite_ushort (CC_SFILE *f, unsigned short x),
    CCutil_swrite_int (CC_SFILE *f, int x),
    CCutil_swrite_uint (CC_SFILE *f, unsigned int x),
    CCutil_swrite_double (CC_SFILE *f, double x),
    CCutil_sread (CC_SFILE *f, char *buf, int size),
    CCutil_sread_bits (CC_SFILE *f, int *x, int xbits),
    CCutil_sread_ubits (CC_SFILE *f, unsigned int *x, int xbits),
    CCutil_sread_char (CC_SFILE *f, char *x),
    CCutil_sread_string (CC_SFILE *f, char *x, int maxlen),
    CCutil_sread_short (CC_SFILE *f, short *x),
    CCutil_sread_ushort (CC_SFILE *f, unsigned short *x),
    CCutil_sread_short_r (CC_SFILE *f, short *x),
    CCutil_sread_int (CC_SFILE *f, int *x),
    CCutil_sread_uint (CC_SFILE *f, unsigned int *x),
    CCutil_sread_int_r (CC_SFILE *f, int *x),
    CCutil_sread_double (CC_SFILE *f, double *x),
    CCutil_sread_double_r (CC_SFILE *f, double *x),
    CCutil_sflush (CC_SFILE *f),
    CCutil_stell (CC_SFILE *f),
    CCutil_sseek (CC_SFILE *f, int offset),
    CCutil_srewind (CC_SFILE *f),
    CCutil_sclose (CC_SFILE *f),
    CCutil_sbits (unsigned int x),
    CCutil_sdelete_file (const char *fname),
    CCutil_sdelete_file_backup (const char *fname);

#ifdef CC_NETREADY
CC_SFILE
   *CCutil_snet_open (const char *hname, unsigned short p),
   *CCutil_snet_receive (CC_SPORT *s);

CC_SPORT
   *CCutil_snet_listen (unsigned short p);

void
    CCutil_snet_unlisten (CC_SPORT *s);

#endif /* CC_NETREADY */





/****************************************************************************/
/*                                                                          */
/*                             signal.c                                     */
/*                                                                          */
/****************************************************************************/

#define CCutil_SIGHUP                1  /* HangUp */
#define CCutil_SIGINT                2  /* Interrupt */
#define CCutil_SIGQUIT               3  /* Quit */
#define CCutil_SIGILL                4  /* Illegal instruction */
#define CCutil_SIGTRAP               5  /* Trace trap */
#define CCutil_SIGABRT               6  /* Abort */
#define CCutil_SIGEMT                7  /* Emulator trap */
#define CCutil_SIGFPE                8  /* Floating point exception */
#define CCutil_SIGKILL               9  /* Kill process */
#define CCutil_SIGBUS               10  /* Bus error */
#define CCutil_SIGSEGV              11  /* Segmentation fault */
#define CCutil_SIGSYS               12  /* Illegal argument to system call */
#define CCutil_SIGPIPE              13  /* Pipe */
#define CCutil_SIGALRM              14  /* Alarm */
#define CCutil_SIGTERM              15  /* Terminate */
#define CCutil_SIGUSR1              16  /* User signal 1 */
#define CCutil_SIGUSR2              17  /* User signal 2 */
#define CCutil_SIGCHLD              18  /* Child condition change */
#define CCutil_SIGPWR               19  /* Power fail */
#define CCutil_SIGWINCH             20  /* Window size changes */
#define CCutil_SIGURG               21  /* Urgent condition on IO channel*/
#define CCutil_SIGIO                22  /* IO possible */
#define CCutil_SIGSTOP              23  /* Stop */
#define CCutil_SIGTSTP              24  /* Tty stop */
#define CCutil_SIGCONT              25  /* Continue */
#define CCutil_SIGTTIN              26  /* Tty background read */
#define CCutil_SIGTTOU              27  /* Tty background write */
#define CCutil_SIGVTALRM            28  /* Virtual timer alarm */
#define CCutil_SIGPROF              29  /* Profiling timer alarm */
#define CCutil_SIGXCPU              30  /* CPU limit exceeded */
#define CCutil_SIGXFSZ              31  /* File size limit exceeded */
#define CCutil_SIGSTKFLT            32  /* Stack fault */
#define CCutil_SIGIOT               33  /* IOT instruction */
#define CCutil_SIGPOLL              34  /* Pollable event */
#define CCutil_SIGMSG               35  /* Message available */
#define CCutil_SIGDANGER            36  /* System crash imminent */
#define CCutil_SIGMIGRATE           37  /* Migrate process */
#define CCutil_SIGPRE               38  /* Programming exception */
#define CCutil_SIGVIRT              39  /* Second virtual time alarm */
#define CCutil_MAXSIG               39


typedef void (*CCutil_handler)(int signum);

int
    CCutil_signal_handler (int ccsignum, CCutil_handler handler),
    CCutil_signal_default (int ccsignum),
    CCutil_signal_ignore (int ccsignum),
    CCutil_sig_to_ccsig (int signum);

void
    CCutil_signal_init (void),
    CCutil_handler_fatal (int signum),
    CCutil_handler_warn (int signum),
    CCutil_handler_exit (int signum);




/****************************************************************************/
/*                                                                          */
/*                             sortrus.c                                    */
/*                                                                          */
/****************************************************************************/


void
    CCutil_int_array_quicksort (int *len, int n),
    CCutil_int_perm_quicksort (int *perm, int *len, int n),
    CCutil_double_perm_quicksort (int *perm, double *len, int n),
    CCutil_rselect (int *arr, int l, int r, int m, double *coord,
        CCrandstate *rstate);

char
    *CCutil_linked_radixsort (char *data, char *datanext, char *dataval,
        int valsize);


/****************************************************************************/
/*                                                                          */
/*                             subdiv.c                                     */
/*                                                                          */
/****************************************************************************/

#define CC_SUBDIV_PORT  ((unsigned short) 32141)
#define CC_SUBGATE_PORT ((unsigned short) 32143)
#define CCutil_FILE_NAME_LEN  (128)

typedef struct CCsubdiv {
    double xrange[2];
    double yrange[2];
    int    cnt;
    int    id;
    double bound;
    int    status;
} CCsubdiv;

typedef struct CCsubdiv_lkh {
    int id;
    int cnt;
    int start;
    double origlen;
    double newlen;
    int    status;
} CCsubdiv_lkh;


int
    CCutil_karp_partition (int ncount, CCdatagroup *dat, int partsize,
        int *p_scount, CCsubdiv **p_slist, int ***partlist,
        CCrandstate *rstate),
    CCutil_write_subdivision_index (char *problabel, int ncount, int scount,
        CCsubdiv *slist),
    CCutil_read_subdivision_index (char *index_name, char **p_problabel,
        int *p_ncount, int *p_scount, CCsubdiv **p_slist),
    CCutil_write_subdivision_lkh_index (char *problabel, int ncount,
        int scount, CCsubdiv_lkh *slist, double tourlen),
    CCutil_read_subdivision_lkh_index (char *index_name, char **p_problabel,
        int *p_ncount, int *p_scount, CCsubdiv_lkh **p_slist,
        double *p_tourlen);


/****************************************************************************/
/*                                                                          */
/*                             urandom.c                                    */
/*                                                                          */
/****************************************************************************/

/* since urandom's generator does everything modulo CC_PRANDMAX, if two
 * seeds are congruent mod x and x|CC_PRANDMAX, then the resulting numbers
 * will be congruent mod x.  One example was if CC_PRANDMAX = 1000000000 and
 * urandom is used to generate a point set from a 1000x1000 grid, seeds
 * congruent mod 1000 generate the same point set.
 *
 * For this reason, we use 1000000007 (a prime)
 */
#define CC_PRANDMAX 1000000007

void
   CCutil_sprand (int seed, CCrandstate *r);

int
   CCutil_lprand (CCrandstate *r);

double
   CCutil_normrand (CCrandstate *r);





/****************************************************************************/
/*                                                                          */
/*                             util.c                                       */
/*                                                                          */
/****************************************************************************/
int CCutil_receive_distarr(const unsigned int *distarr, unsigned int ncount,
                           CCdatagroup *dat);

char
   *CCutil_strchr (char *s, int c),
   *CCutil_strrchr (char *s, int c),
   *CCutil_strdup (const char *s),
   *CCutil_strdup2 (const char *s);

const char
   *CCutil_strchr_c (const char *s, int c),
   *CCutil_strrchr_c (const char *s, int c);

unsigned int
    CCutil_nextprime (unsigned int x);

int
    CCutil_our_gcd (int a, int b),
    CCutil_our_lcm (int a, int b),
    CCutil_print_command (int ac, char **av);

void
    CCutil_readstr (FILE *f, char *s, int len),
    CCutil_printlabel (void);





/****************************************************************************/
/*                                                                          */
/*                             zeit.c                                       */
/*                                                                          */
/****************************************************************************/

typedef struct CCutil_timer {
    double  szeit;
    double  cum_zeit;
    char    name[40];
    int     count;
} CCutil_timer;


double
    CCutil_zeit (void),
    CCutil_real_zeit (void),
    CCutil_stop_timer (CCutil_timer *t, int printit),
    CCutil_total_timer (CCutil_timer *t, int printit);


void
    CCutil_init_timer (CCutil_timer *t, const char *name),
    CCutil_start_timer (CCutil_timer *t),
    CCutil_suspend_timer (CCutil_timer *t),
    CCutil_resume_timer (CCutil_timer *t);



#endif /* __UTIL_H */
/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/

#ifndef __HELDKARP_H
#define __HELDKARP_H

#define HELDKARP_ERROR -1
#define HELDKARP_SEARCHLIMITEXCEEDED 1


int CCheldkarp_small(int ncount, CCdatagroup *dat, double *upbound,
                     double *optval, int *foundtour, int anytour,
                     int *tour_elist, int nodelimit, int silent),
    CCheldkarp_small_elist(int ncount, int ecount, int *elist, int *elen,
                           double *upbound, double *optval, int *foundtour,
                           int anytour, int *tour_elist, int nodelimit,
                           int silent);
int CCtsp_heldkarp(const unsigned int *distarr, unsigned int *route, unsigned int ncount);

#endif /* __HELDKARP_H */
/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/

#ifndef  __LINKERN_H
#define  __LINKERN_H


#define CC_LK_RANDOM_KICK    (0)
#define CC_LK_GEOMETRIC_KICK (1)
#define CC_LK_CLOSE_KICK     (2)
#define CC_LK_WALK_KICK      (3)



int
    CClinkern_tour (int ncount, CCdatagroup *dat, int ecount,
        int *elist, int stallcount, int repeatcount, int *incycle,
        int *outcycle, double *val, int silent, double time_bound,
        double length_bound, char *saveit_name, int kicktype,
        CCrandstate *rstate),
    CClinkern_path (int ncount, CCdatagroup *dat, int ecount,
        int *elist, int nkicks, int *inpath, int *outpath, double *val,
        int silent, CCrandstate *rstate),
    CClinkern_fixed (int ncount, CCdatagroup *dat, int ecount, int *elist,
        int nkicks, int *incycle, int *outcycle, double *val, int fcount,
        int *flist, int silent, CCrandstate *rstate);

#endif  /* __LINKERN_H */


/****************************************************************************/
/*                                                                          */
/*                  FLIPPER HEADER (TWO-LIST)                               */
/*                                                                          */
/****************************************************************************/


#ifndef __FLIPPER_H
#define __FLIPPER_H

typedef struct CClk_parentnode {
    struct CClk_parentnode *adj[2];
    struct CClk_childnode  *ends[2];
    int                     size;
    int                     id;
    int                     rev;
} CClk_parentnode;

typedef struct CClk_childnode {
    struct CClk_parentnode *parent;
    struct CClk_childnode  *adj[2];
    int                     id;
    int                     name;
} CClk_childnode;

typedef struct CClk_flipper {
    CClk_parentnode        *parents;
    CClk_childnode         *children;
    int                     reversed;
    int                     nsegments;
    int                     groupsize;
    int                     split_cutoff;
} CClk_flipper;



int
    CClinkern_flipper_init (CClk_flipper *f, int ncount, int *cyc),
    CClinkern_flipper_next (CClk_flipper *f, int x),
    CClinkern_flipper_prev (CClk_flipper *f, int x),
    CClinkern_flipper_sequence (CClk_flipper *f, int x, int y, int z);
void
    CClinkern_flipper_flip (CClk_flipper *F, int x, int y),
    CClinkern_flipper_cycle (CClk_flipper *F, int *x),
    CClinkern_flipper_finish (CClk_flipper *F);

#endif  /* __FLIPPER_H */
/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*    EXPORTED FUNCTIONS:                                                   */
/*                                                                          */
/*  CC_SWAP(a,b,t)                                                          */
/*    swaps a and b, using t as temporary space.  a, b, and t should all    */
/*    be the same type.                                                     */
/*                                                                          */
/*  CC_OURABS(a)                                                            */
/*    returns the absolute value of a.                                      */
/*                                                                          */
/****************************************************************************/

#ifndef  __MACRORUS_H
#define  __MACRORUS_H

#define CC_SWAP(a,b,t) (((t)=(a)),((a)=(b)),((b)=(t)))

#define CC_OURABS(a) (((a) >= 0) ? (a) : -(a))

#endif  /* __MACRORUS_H */
/****************************************************************************/
/*                                                                          */
/*  This file is part of CONCORDE                                           */
/*                                                                          */
/*  (c) Copyright 1995--1999 by David Applegate, Robert Bixby,              */
/*  Vasek Chvatal, and William Cook                                         */
/*                                                                          */
/*  Permission is granted for academic research use.  For other uses,       */
/*  contact the authors for licensing options.                              */
/*                                                                          */
/*  Use at your own risk.  We make no guarantees about the                  */
/*  correctness or usefulness of this code.                                 */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/*                      PROTOTYPES FOR FILES IN EDGEGEN                     */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/

#ifndef __EDGEGEN_H
#define __EDGEGEN_H



/****************************************************************************/
/*                                                                          */
/*                             edgegen.c                                    */
/*                                                                          */
/****************************************************************************/

typedef struct CCedgegengroup {
    struct {
        int count;
        int quadnearest;
        int nearest;
        int nearest_start;
        int greedy_start;
        int boruvka_start;
        int qboruvka_start;
        int random_start;
        int nkicks;
    } linkern;

    struct {
        int twoopt_count;
        int twoopt5_count;
        int threeopt_count;
        int greedy;
        int boruvka;
        int qboruvka;
        int nearest_count;
        int random_count;
    } tour;

    struct {
        int wantit;
        int basic;
        int priced;
    } f2match;

    struct {
        int number;
        int basic;
        int priced;
    } f2match_nearest;

    int    random;
    int    nearest;
    int    quadnearest;
    int    want_tree;
    int    nearest_twomatch_count;
    int    delaunay;
    int    mlinkern;
} CCedgegengroup;



int
    CCedgegen_read (char *egname, CCedgegengroup *plan),
    CCedgegen_edges (CCedgegengroup *plan, int ncount, CCdatagroup *dat,
        double *wcoord, int *ecount, int **elist, int silent,
        CCrandstate *rstate);
void
    CCedgegen_init_edgegengroup (CCedgegengroup *plan);




/****************************************************************************/
/*                                                                          */
/*                             xnear.c                                      */
/*                                                                          */
/****************************************************************************/

typedef struct CCxnear {
    struct CCdatagroup dat;
    double            *w;
    int               *nodenames;
    int               *invnames;
} CCxnear;



int
    CCedgegen_x_k_nearest (int ncount, int num, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ecount, int **elist, int silent),
    CCedgegen_x_quadrant_k_nearest (int ncount, int num, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ecount, int **elist, int silent),
    CCedgegen_x_node_k_nearest (CCxnear *xn, int n, int nearnum, int ncount,
        int *list),
    CCedgegen_x_node_quadrant_k_nearest (CCxnear *xn, int n, int nearnum,
        int ncount, int *list),
    CCedgegen_x_node_nearest (CCxnear *xn, int ncount, int ni, char *marks),
    CCedgegen_x_nearest_neighbor_tour (int ncount, int start, CCdatagroup *dat,
        int *outcycle, double *val),
    CCedgegen_x_greedy_tour (int ncount, CCdatagroup *dat, int *outcycle,
        double *val, int ecount, int *elist, int silent),
    CCedgegen_x_qboruvka_tour (int ncount, CCdatagroup *dat, int *outcycle,
        double *val, int ecount, int *elist, int silent),
    CCedgegen_junk_k_nearest (int ncount, int num, CCdatagroup *dat,
        double *wcoord, int wantlist, int *ecount, int **elist, int silent),
    CCedgegen_junk_node_k_nearest (CCdatagroup *dat, double *wcoord, int n,
        int nearnum, int ncount, int *list),
    CCedgegen_junk_node_nearest (CCdatagroup *dat, double *wcoord, int ncount,
        int n, char *marks),
    CCedgegen_junk_nearest_neighbor_tour (int ncount, int start,
        CCdatagroup *dat, int *outcycle, double *val, int silent),
    CCedgegen_junk_greedy_tour (int ncount, CCdatagroup *dat, int *outcycle,
        double *val, int ecount, int *elist, int silent),
    CCedgegen_junk_qboruvka_tour (int ncount, CCdatagroup *dat, int *outcycle,
        double *val, int ecount, int *elist, int silent),
    CCedgegen_xnear_build (int ncount, CCdatagroup *dat, double *wcoord,
        CCxnear *xn);

void
    CCedgegen_xnear_free (CCxnear *xn);


#endif  /* __EDGEGEN_H */
