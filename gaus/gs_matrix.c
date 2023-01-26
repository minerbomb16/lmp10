#include "gs_matrix.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>

void gs_matrixx (matrix_t * c, double s) {
    int i, j;
    int cn = c->cn;
    int rn = c->rn;
    double *e = c->e;
    int close = 1;

    //Przeksztalcenie macierzy
    for (i = 0; i < rn; i++) {
        double tmp = e[i*cn+cn-1];
        e[i*cn+cn-1] = 0;
        double dz = e[i*cn+i];
        e[i*cn+i] = -tmp;
        for (j = 0; j < cn - 1; j++) {
            e[i*cn+j] = e[i*cn+j] / (-dz);
        }
    }

    //GS
    while (close) {
        for (i = 0; i < rn; i++) {
            double wyn = e[i*cn+i];
            for (j = 0; j < cn - 1; j++) {
                if(i != j) {
                    wyn += e[i*cn+j] * e[j*cn+cn-1];
                }
            }
            e[i*cn+cn-1] = wyn;
        }

        //Sprawdzenie dokladnoscii
        int count = 0;
        for (i = 0; i < rn; i++) {
            double spr = e[i*cn+i];
            for (j = 0; j < cn - 1; j++) {
                if (i != j) {
                    spr += e[i*cn+j] * e[j*cn+cn-1];
                }
            }
            if (fabs(spr-e[i*cn+cn-1]) < s) {
                count++;
            }
        }
        if(count == rn) {
            close = 0;
        }
    }

}
