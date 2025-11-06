#ifndef __c9_flightControlSystem_h__
#define __c9_flightControlSystem_h__

/* Forward Declarations */
#ifndef c9_typedef_c9_cell_1
#define c9_typedef_c9_cell_1

typedef struct c9_tag_lfyg79q6Kpk0jaJgYJuk8C c9_cell_1;

#endif                                 /* c9_typedef_c9_cell_1 */

#ifndef c9_typedef_c9_cell_wrap_2
#define c9_typedef_c9_cell_wrap_2

typedef struct c9_tag_uwJsGEKtvfiUxcdf0z0AYH c9_cell_wrap_2;

#endif                                 /* c9_typedef_c9_cell_wrap_2 */

#ifndef c9_typedef_c9_s_WSTEAPgNJmllMDXoFTifcF
#define c9_typedef_c9_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c9_tag_WSTEAPgNJmllMDXoFTifcF c9_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* c9_typedef_c9_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef c9_typedef_c9_s_MY3jsqmREaTzOC09vCGedD
#define c9_typedef_c9_s_MY3jsqmREaTzOC09vCGedD

typedef struct c9_tag_MY3jsqmREaTzOC09vCGedD c9_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* c9_typedef_c9_s_MY3jsqmREaTzOC09vCGedD */

/* Type Definitions */
#ifndef c9_struct_c9_tag_lfyg79q6Kpk0jaJgYJuk8C
#define c9_struct_c9_tag_lfyg79q6Kpk0jaJgYJuk8C

struct c9_tag_lfyg79q6Kpk0jaJgYJuk8C
{
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
};

#endif                                 /* c9_struct_c9_tag_lfyg79q6Kpk0jaJgYJuk8C */

#ifndef c9_typedef_c9_cell_1
#define c9_typedef_c9_cell_1

typedef struct c9_tag_lfyg79q6Kpk0jaJgYJuk8C c9_cell_1;

#endif                                 /* c9_typedef_c9_cell_1 */

#ifndef c9_struct_c9_tag_uwJsGEKtvfiUxcdf0z0AYH
#define c9_struct_c9_tag_uwJsGEKtvfiUxcdf0z0AYH

struct c9_tag_uwJsGEKtvfiUxcdf0z0AYH
{
  char_T f1[4];
};

#endif                                 /* c9_struct_c9_tag_uwJsGEKtvfiUxcdf0z0AYH */

#ifndef c9_typedef_c9_cell_wrap_2
#define c9_typedef_c9_cell_wrap_2

typedef struct c9_tag_uwJsGEKtvfiUxcdf0z0AYH c9_cell_wrap_2;

#endif                                 /* c9_typedef_c9_cell_wrap_2 */

#ifndef c9_struct_c9_tag_WSTEAPgNJmllMDXoFTifcF
#define c9_struct_c9_tag_WSTEAPgNJmllMDXoFTifcF

struct c9_tag_WSTEAPgNJmllMDXoFTifcF
{
  c9_cell_1 _data;
};

#endif                                 /* c9_struct_c9_tag_WSTEAPgNJmllMDXoFTifcF */

#ifndef c9_typedef_c9_s_WSTEAPgNJmllMDXoFTifcF
#define c9_typedef_c9_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c9_tag_WSTEAPgNJmllMDXoFTifcF c9_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* c9_typedef_c9_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef c9_struct_c9_tag_MY3jsqmREaTzOC09vCGedD
#define c9_struct_c9_tag_MY3jsqmREaTzOC09vCGedD

struct c9_tag_MY3jsqmREaTzOC09vCGedD
{
  c9_cell_wrap_2 _data;
};

#endif                                 /* c9_struct_c9_tag_MY3jsqmREaTzOC09vCGedD */

#ifndef c9_typedef_c9_s_MY3jsqmREaTzOC09vCGedD
#define c9_typedef_c9_s_MY3jsqmREaTzOC09vCGedD

typedef struct c9_tag_MY3jsqmREaTzOC09vCGedD c9_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* c9_typedef_c9_s_MY3jsqmREaTzOC09vCGedD */

#ifndef typedef_SFc9_flightControlSystemInstanceStruct
#define typedef_SFc9_flightControlSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c9_sfEvent;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_JITStateAnimation[1];
  uint8_T c9_JITTransitionAnimation[1];
  real_T c9_hsvImage[57600];
  real_T c9_H[19200];
  real_T c9_S[19200];
  real_T c9_V[19200];
  CovrtStateflowInstance *c9_covrtInstance;
  void *c9_fEmlrtCtx;
  uint8_T (*c9_R)[19200];
  boolean_T (*c9_BW)[19200];
  uint8_T (*c9_G)[19200];
  uint8_T (*c9_B)[19200];
} SFc9_flightControlSystemInstanceStruct;

#endif                                 /* typedef_SFc9_flightControlSystemInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_flightControlSystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c9_flightControlSystem_get_check_sum(mxArray *plhs[]);
extern void c9_flightControlSystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
