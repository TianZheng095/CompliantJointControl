#ifndef __c8_CGMRES_h__
#define __c8_CGMRES_h__

/* Type Definitions */
#include "cs.h"
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_c8_emxArray_real_T
#define typedef_c8_emxArray_real_T

typedef struct emxArray_real_T c8_emxArray_real_T;

#endif                                 /*typedef_c8_emxArray_real_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_c8_emxArray_int32_T
#define typedef_c8_emxArray_int32_T

typedef struct emxArray_int32_T c8_emxArray_int32_T;

#endif                                 /*typedef_c8_emxArray_int32_T*/

#ifndef typedef_c8_coder_internal_sparse
#define typedef_c8_coder_internal_sparse

typedef struct {
  c8_emxArray_real_T *d;
  c8_emxArray_int32_T *colidx;
  c8_emxArray_int32_T *rowidx;
  int32_T maxnz;
} c8_coder_internal_sparse;

#endif                                 /*typedef_c8_coder_internal_sparse*/

#ifndef typedef_SFc8_CGMRESInstanceStruct
#define typedef_SFc8_CGMRESInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c8_sfEvent;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_CGMRES;
  uint8_T c8_JITStateAnimation[1];
  uint8_T c8_JITTransitionAnimation[1];
  void *c8_RuntimeVar;
  uint32_T c8_mlFcnLineNumber;
  void *c8_fcnDataPtrs[27];
  char_T *c8_dataNames[27];
  uint32_T c8_numFcnVars;
  uint32_T c8_ssIds[27];
  uint32_T c8_statuses[27];
  void *c8_outMexFcns[27];
  void *c8_inMexFcns[27];
  CovrtStateflowInstance *c8_covrtInstance;
  void *c8_fEmlrtCtx;
  real_T (*c8_M_bar_inv)[9];
  real_T (*c8_J)[6];
  real_T (*c8_tau_lev2)[3];
  real_T (*c8_z_lev2)[13];
  real_T (*c8_Xprime_r_lev2)[9001];
  real_T *c8_i;
  real_T (*c8_P_f2taubar)[240];
  real_T (*c8_P_f2miubar)[160];
  real_T (*c8_K_lev2)[208];
  real_T (*c8_G_lev2)[208];
  real_T (*c8_W_lev2)[624];
  real_T (*c8_L_lev2)[240];
  real_T (*c8_A_z_lev2)[169];
  real_T (*c8_dTau_lev1)[12];
  real_T (*c8_b_tau_lev2)[3];
} SFc8_CGMRESInstanceStruct;

#endif                                 /*typedef_SFc8_CGMRESInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_CGMRES_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_CGMRES_get_check_sum(mxArray *plhs[]);
extern void c8_CGMRES_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
