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
/*               CODE FOR TESTING ITERATED LIN-KERNIGHAN                    */
/*                                                                          */
/*                             TSP CODE                                     */
/*                                                                          */
/*                                                                          */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                        */
/*  Date: March 17, 1995                                                    */
/*                                                                          */
/*  For a short description see usage ()                                    */
/*                                                                          */
/****************************************************************************/

#include "edgegen.h"
#include "linkern.h"
#include "machdefs.h"
#include "macrorus.h"
#include "util.h"

#define BIGDOUBLE (1e30)

#define LK_RANDOM (0)
#define LK_NEIGHBOR (1)
#define LK_GREEDY (2)
#define LK_BORUVKA (3)
#define LK_QBORUVKA (4)

static int seed = 0;
static int run_silently = 1;
static int kick_type = CC_LK_WALK_KICK;
static int tour_type = LK_QBORUVKA;

int CCtsp_lk(const unsigned int *distarr, unsigned int *route,
             unsigned int ncount, int stallcount) {
    int k, rval;
    double val;
    int tempcount, *templist;
    int *incycle = (int *)NULL, *outcycle = (int *)NULL;
    CCdatagroup dat;
    CCrandstate rstate;

    // Default values
    int in_repeater = ncount;
    double time_bound = -1.0;
    double length_bound = -1.0;
    int quadtry = 2;

    CCutil_sprand(seed, &rstate);

    CCutil_init_datagroup(&dat);
    rval = CCutil_receive_distarr(distarr, ncount, &dat);
    if (rval) {
        fprintf(stderr, "CCutil_receive_distarr_failed\n");
        goto CLEANUP;
    }

    incycle = CC_SAFE_MALLOC(ncount, int);
    if (!incycle) {
        rval = 1;
        goto CLEANUP;
    }

    if (CCedgegen_junk_k_nearest(ncount, 4 * quadtry, &dat, (double *)NULL, 1,
                                 &tempcount, &templist, run_silently)) {
        fprintf(stderr, "CCedgegen_junk_k_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }
    if (CCedgegen_junk_qboruvka_tour(ncount, &dat, incycle, &val, tempcount,
                                     templist, run_silently)) {
        fprintf(stderr, "CCedgegen_junk_qboruvka_tour failed\n");
        rval = 1;
        goto CLEANUP;
    }

    outcycle = CC_SAFE_MALLOC(ncount, int);
    if (!outcycle) {
        rval = 1;
        goto CLEANUP;
    }

    if (CClinkern_tour(ncount, &dat, tempcount, templist, stallcount,
                       in_repeater, incycle, outcycle, &val, run_silently,
                       time_bound, length_bound, (char *)NULL, kick_type,
                       &rstate)) {
        fprintf(stderr, "CClinkern_tour failed\n");
        rval = 1;
        goto CLEANUP;
    }
    for (int i = 0; i < ncount; i++) {
        route[i] = (unsigned int)outcycle[i];
    }
    fflush(stdout);

CLEANUP:

#ifndef BIG_PROBLEM
    CC_IFFREE(templist, int);
#endif
    CC_IFFREE(incycle, int);
    CC_IFFREE(outcycle, int);
    CCutil_freedatagroup(&dat);
    if (rval) {
        return -1;
    } else {
        return (int)val;
    }
}
