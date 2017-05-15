#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sacio.h"

int main(int argc, char *argv[]) {
    int i;
    float *data1, *data2, xy_sqa =  0., x_sqa = 0., y_sqa = 0., x_y = 0., cof;
    SACHEAD hd1, hd2;

    if ( argc != 3 ) {
        fprintf(stderr,"Usage: cal_cof <sacfile1> <sacfile2>\n");
        fprintf(stderr,"       return coeffient of sacfile1 and sacfile2\n");
        exit(1);
    }

    data1 = read_sac(argv[1],&hd1);
    data2 = read_sac(argv[2],&hd2);

    for ( i = 0; i < hd1.npts; i ++ ) {
        x_y += data1[i]*data2[i];
        x_sqa += data1[i]*data1[i];
        y_sqa += data2[i]*data2[i];
    }

    xy_sqa = sqrt(x_sqa*y_sqa);
    if ( xy_sqa == 0. ) cof = 0.;
    else cof = x_y / xy_sqa;
    printf("The coefficient of %s and %s is %f\n", argv[1], argv[2], cof);
    return 0;
}
