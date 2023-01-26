#include "gs_matrix.h"
#include "piv_ge_solver.h"
#include <stdlib.h>




/*
int
piv_ge_solver (matrix_t * eqs)
{
  if (eqs != NULL) {
    pivot_ge_in_situ_matrix (eqs);
    if (bs_matrix (eqs) == 0) {
      return 0;
    }
    else {
      return 1;
    }
  }
  else
    return 1;
}
*/

int
piv_ge_solver (matrix_t * eqs, double accuracy)
{
    printf("piv_ge_solver\n");
    if (eqs != NULL) {
        if (accuracy == -1){
            printf("In use: Gauss function\n");
            pivot_ge_in_situ_matrix (eqs);
            if (bs_matrix (eqs) == 0) {
                return 0;
            }
            else {
                return 1;
            }
            return 0;
        } else {
            printf("In use: Gauss-Seidel function\n");
            gs_matrixx(eqs, accuracy);
            return 0;
        }
    } else return 1;
}
