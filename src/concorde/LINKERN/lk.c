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
static int nearnum = 0;
static int quadtry = 2;
static int run_silently = 1;
static int kick_type = CC_LK_WALK_KICK;
static int tour_type = LK_QBORUVKA;

int CCtsp_lk(const unsigned int *distarr, unsigned int *route,
             unsigned int ncount) {
    int k;
    double val, best;
    int tempcount, *templist;
    int *incycle = (int *)NULL, *outcycle = (int *)NULL;
    CCdatagroup dat;
    int rval = 0;
    CCrandstate rstate;

    // Default values
    int in_repeater = ncount;
    int number_runs = 1;
    double time_bound = -1.0;
    double length_bound = -1.0;

    seed = (int)CCutil_real_zeit();
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

    if (!nearnum)
        nearnum = 4 * quadtry;
    if (CCedgegen_junk_k_nearest(ncount, nearnum, &dat, (double *)NULL, 1,
                                 &tempcount, &templist, run_silently)) {
        fprintf(stderr, "CCedgegen_junk_k_nearest failed\n");
        rval = 1;
        goto CLEANUP;
    }
    if (tour_type == LK_GREEDY) {
        if (CCedgegen_junk_greedy_tour(ncount, &dat, incycle, &val, tempcount,
                                       templist, run_silently)) {
            fprintf(stderr, "CCedgegen_junk_greedy_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else if (tour_type == LK_QBORUVKA) {
        if (CCedgegen_junk_qboruvka_tour(ncount, &dat, incycle, &val, tempcount,
                                         templist, run_silently)) {
            fprintf(stderr, "CCedgegen_junk_qboruvka_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    } else {
        if (CCedgegen_junk_nearest_neighbor_tour(
                ncount, CCutil_lprand(&rstate) % ncount, &dat, incycle, &val,
                run_silently)) {
            fprintf(stderr, "CCedgegen_junk_nearest_neighbor_tour failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    outcycle = CC_SAFE_MALLOC(ncount, int);
    if (!outcycle) {
        rval = 1;
        goto CLEANUP;
    }

    if (number_runs) {
        k = 0;
        best = BIGDOUBLE;
        do {
            if (CClinkern_tour(ncount, &dat, tempcount, templist, 100000000,
                               in_repeater, incycle, outcycle, &val,
                               run_silently, time_bound, length_bound,
                               (char *)NULL, kick_type, &rstate)) {
                fprintf(stderr, "CClinkern_tour failed\n");
                rval = 1;
                goto CLEANUP;
            }
            if (val < best) {
                best = val;
            }
        } while (++k < number_runs);
    } else {
        best = val;
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
        return (int)best;
    }
}
