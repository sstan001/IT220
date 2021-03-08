/**
 * @file color-transfert
 * @brief transfert color from source image to target image.
 *        Method from Reinhard et al. : 
 *        Erik Reinhard, Michael Ashikhmin, Bruce Gooch and Peter Shirley, 
 *        'Color Transfer between Images', IEEE CGA special issue on 
 *        Applied Perception, Vol 21, No 5, pp 34-41, September - October 2001
 */

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <bcl.h>

#define D 3

float RGB2LMS[D][D] = {
  {0.3811, 0.5783, 0.0402}, 
  {0.1967, 0.7244, 0.0782},  
  {0.0241, 0.1288, 0.8444}
};

float LMS2RGB[D][D] = {
  {4.4679, -3.5873, 0.1193}, 
  {-1.2186, 2.3809, -0.1624},  
  {0.0497, -0.2439, 1.2045}
};

float RGB2LAB[D][D] = {
  {0.5774, 0.5774, 0.5774}, 
  {0.4082, 0.4082, -0.8165},  
  {0.7071, -0.7071, 0}
};

float LAB2RGB[D][D] = {
  {0.5774, 0.4082, 0.7071}, 
  {0.5774, 0.4082, -0.7071},  
  {0.5774, -0.8165, 0}
};
/*
void rgb2lab(void *** ims, int rows_ims, int cols_ims){

    for(int i = 0 ; i < rows_ims ; i++){
        for(int j = 0 ; j < cols_ims ; j++){
            for(int k = 0 ; 1 < 3 ; k++){
                ims[i][j][k] = 0;
            }
        }
    }   
}

void lab2rgb(pnm ims){
    ims;
}
*/

void
process(char *ims_name, char *imt_name, char* imd_name){
    pnm ims = pnm_load(ims_name);
    int rows_ims = pnm_get_height(ims);
    int cols_ims = pnm_get_width(ims);

    float * ims_data = malloc(sizeof(float)*rows_ims*cols_ims*3);
    float (* ims_col)[rows_ims] = (float (*)[rows_ims]) ims_data;
    float (*ims_tab)[cols_ims] = (float (*)[cols_ims])ims_col;
    
    /*
    for(int i = 0 ; i < rows_ims ; i++){
        for(int j = 0 ; j < cols_ims ; j++){
            for()
            ims_tab[i][j][k] = 0;
        }
    }


    //rgb2lab(ims_data, rows_ims, cols_ims);
    
    pnm imt = pnm_load(imt_name);
    int rows_imt = pnm_get_height(imt);
    int cols_imt = pnm_get_width(imt);
    
    pnm imd = pnm_new(rows_imt, cols_imt, PnmRawPpm);
    */
    free(ims_data);

}

void
usage (char *s){
  fprintf(stderr, "Usage: %s <ims> <imt> <imd> \n", s);
  exit(EXIT_FAILURE);
}

#define PARAM 3
int
main(int argc, char *argv[]){
  if (argc != PARAM+1) usage(argv[0]);
  process(argv[1], argv[2], argv[3]);
  return EXIT_SUCCESS;
}
