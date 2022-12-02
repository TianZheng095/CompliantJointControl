/* Include files */

#include "CGMRES_sfun.h"
#include "c8_CGMRES.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c8_emlrtRSI = { 4,  /* lineNo */
  "get_c",                             /* fcnName */
  "C:\\Users\\16967\\Desktop\\Master bei der TUM\\Studium\\LSR\\Masterarbeit\\IMPC_PriController\\test\\get_c.m"/* pathName */
};

static emlrtRSInfo c8_b_emlrtRSI = { 7,/* lineNo */
  "get_c",                             /* fcnName */
  "C:\\Users\\16967\\Desktop\\Master bei der TUM\\Studium\\LSR\\Masterarbeit\\IMPC_PriController\\test\\get_c.m"/* pathName */
};

static emlrtRSInfo c8_c_emlrtRSI = { 5,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

static emlrtRSInfo c8_d_emlrtRSI = { 9,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

static emlrtRSInfo c8_e_emlrtRSI = { 10,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

static emlrtRSInfo c8_f_emlrtRSI = { 13,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

static emlrtRSInfo c8_g_emlrtRSI = { 19,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

static emlrtRSInfo c8_h_emlrtRSI = { 26,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

static emlrtRSInfo c8_i_emlrtRSI = { 102,/* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo c8_j_emlrtRSI = { 232,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c8_k_emlrtRSI = { 57,/* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c8_l_emlrtRSI = { 90,/* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c8_m_emlrtRSI = { 49,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

static emlrtRSInfo c8_n_emlrtRSI = { 78,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

static emlrtRSInfo c8_o_emlrtRSI = { 13,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_p_emlrtRSI = { 137,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_q_emlrtRSI = { 116,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_r_emlrtRSI = { 111,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_s_emlrtRSI = { 104,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_t_emlrtRSI = { 68,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_u_emlrtRSI = { 21,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_v_emlrtRSI = { 22,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_w_emlrtRSI = { 173,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_x_emlrtRSI = { 180,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_y_emlrtRSI = { 183,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_ab_emlrtRSI = { 190,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_bb_emlrtRSI = { 27,/* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c8_cb_emlrtRSI = { 30,/* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo c8_db_emlrtRSI = { 58,/* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo c8_eb_emlrtRSI = { 45,/* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo c8_fb_emlrtRSI = { 45,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c8_gb_emlrtRSI = { 15,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo c8_hb_emlrtRSI = { 41,/* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c8_ib_emlrtRSI = { 21,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c8_jb_emlrtRSI = { 59,/* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c8_kb_emlrtRSI = { 77,/* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c8_lb_emlrtRSI = { 51,/* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo c8_mb_emlrtRSI = { 42,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_nb_emlrtRSI = { 46,/* lineNo */
  "inv",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m"/* pathName */
};

static emlrtRSInfo c8_ob_emlrtRSI = { 190,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_pb_emlrtRSI = { 192,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_qb_emlrtRSI = { 196,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_rb_emlrtRSI = { 198,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_sb_emlrtRSI = { 210,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_tb_emlrtRSI = { 212,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_ub_emlrtRSI = { 35,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_vb_emlrtRSI = { 42,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_wb_emlrtRSI = { 45,/* lineNo */
  "matrix_to_integer_power",           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\private\\matrix_to_integer_power.m"/* pathName */
};

static emlrtRSInfo c8_xb_emlrtRSI = { 269,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c8_yb_emlrtRSI = { 275,/* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo c8_ac_emlrtRSI = { 56,/* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo c8_bc_emlrtRSI = { 13,/* lineNo */
  "sparse",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pathName */
};

static emlrtRSInfo c8_cc_emlrtRSI = { 1437,/* lineNo */
  "sparse",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo c8_dc_emlrtRSI = { 156,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c8_ec_emlrtRSI = { 287,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c8_fc_emlrtRSI = { 307,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c8_gc_emlrtRSI = { 310,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c8_hc_emlrtRSI = { 453,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c8_ic_emlrtRSI = { 351,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRTEInfo c8_emlrtRTEI = { 4,/* lineNo */
  5,                                   /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595"                        /* pName */
};

static emlrtRTEInfo c8_b_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595"                        /* pName */
};

static emlrtRTEInfo c8_c_emlrtRTEI = { 5,/* lineNo */
  5,                                   /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595"                        /* pName */
};

static emlrtRTEInfo c8_d_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595"                        /* pName */
};

static emlrtRTEInfo c8_e_emlrtRTEI = { 7,/* lineNo */
  5,                                   /* colNo */
  "get_c",                             /* fName */
  "C:\\Users\\16967\\Desktop\\Master bei der TUM\\Studium\\LSR\\Masterarbeit\\IMPC_PriController\\test\\get_c.m"/* pName */
};

static emlrtRTEInfo c8_f_emlrtRTEI = { 4,/* lineNo */
  12,                                  /* colNo */
  "get_c",                             /* fName */
  "C:\\Users\\16967\\Desktop\\Master bei der TUM\\Studium\\LSR\\Masterarbeit\\IMPC_PriController\\test\\get_c.m"/* pName */
};

static emlrtRTEInfo c8_g_emlrtRTEI = { 232,/* lineNo */
  13,                                  /* colNo */
  "mtimes",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pName */
};

static emlrtRTEInfo c8_h_emlrtRTEI = { 4,/* lineNo */
  8,                                   /* colNo */
  "get_c",                             /* fName */
  "C:\\Users\\16967\\Desktop\\Master bei der TUM\\Studium\\LSR\\Masterarbeit\\IMPC_PriController\\test\\get_c.m"/* pName */
};

static emlrtRTEInfo c8_i_emlrtRTEI = { 2,/* lineNo */
  5,                                   /* colNo */
  "get_c",                             /* fName */
  "C:\\Users\\16967\\Desktop\\Master bei der TUM\\Studium\\LSR\\Masterarbeit\\IMPC_PriController\\test\\get_c.m"/* pName */
};

static emlrtDCInfo c8_emlrtDCI = { 4,  /* lineNo */
  28,                                  /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595",                       /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c8_emlrtBCI = { 1,  /* iFirst */
  9001,                                /* iLast */
  4,                                   /* lineNo */
  28,                                  /* colNo */
  "Xprime_r_lev2",                     /* aName */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595",                       /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c8_b_emlrtDCI = { 4,/* lineNo */
  32,                                  /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595",                       /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c8_b_emlrtBCI = { 1,/* iFirst */
  9001,                                /* iLast */
  4,                                   /* lineNo */
  32,                                  /* colNo */
  "Xprime_r_lev2",                     /* aName */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595",                       /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c8_emlrtECI = { -1, /* nDims */
  10,                                  /* lineNo */
  25,                                  /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595"                        /* pName */
};

static emlrtDCInfo c8_c_emlrtDCI = { 19,/* lineNo */
  5,                                   /* colNo */
  "Subsystem/MATLAB Function1",        /* fName */
  "#CGMRES:595",                       /* pName */
  4                                    /* checkKind */
};

static emlrtRSInfo c8_jc_emlrtRSI = { 4,/* lineNo */
  "Subsystem/MATLAB Function1",        /* fcnName */
  "#CGMRES:595"                        /* pathName */
};

/* Function Declarations */
static void initialize_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void initialize_params_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void enable_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void disable_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void c8_update_jit_animation_state_c8_CGMRES(SFc8_CGMRESInstanceStruct
  *chartInstance);
static void c8_do_animation_call_c8_CGMRES(SFc8_CGMRESInstanceStruct
  *chartInstance);
static void ext_mode_exec_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_CGMRES(SFc8_CGMRESInstanceStruct
  *chartInstance);
static void set_sim_state_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_st);
static void finalize_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void sf_gateway_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void mdl_start_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void c8_chartstep_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance,
  const emlrtStack *c8_sp);
static void initSimStructsc8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance);
static void c8_get_c(SFc8_CGMRESInstanceStruct *chartInstance, const emlrtStack *
                     c8_sp, real_T c8_A_z[169], real_T c8_z_0[13],
                     c8_emxArray_real_T *c8_c);
static void c8_nbits(SFc8_CGMRESInstanceStruct *chartInstance, int32_T c8_n,
                     int32_T *c8_log2n, int32_T *c8_nbitson);
static void c8_matrix_to_integer_power(SFc8_CGMRESInstanceStruct *chartInstance,
  const emlrtStack *c8_sp, real_T c8_a[169], real_T c8_b, real_T c8_c[169]);
static void c8_check_forloop_overflow_error(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp);
static void c8_warning(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp);
static void c8_kron(SFc8_CGMRESInstanceStruct *chartInstance, real_T c8_A[16],
                    real_T c8_B[6], real_T c8_K[96]);
static void c8_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance, const
  mxArray *c8_c_tau_lev2, const char_T *c8_identifier, real_T c8_y[3]);
static void c8_b_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[3]);
static uint8_T c8_c_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_CGMRES, const char_T *c8_identifier);
static uint8_T c8_d_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static const mxArray *c8_chart_data_browse_helper(SFc8_CGMRESInstanceStruct
  *chartInstance, int32_T c8_ssIdNumber);
static void c8_emxEnsureCapacity_real_T(SFc8_CGMRESInstanceStruct *chartInstance,
  const emlrtStack *c8_sp, c8_emxArray_real_T *c8_emxArray, int32_T c8_oldNumel,
  const emlrtRTEInfo *c8_srcLocation);
static void c8_emxEnsureCapacity_int32_T(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_emxArray_int32_T *c8_emxArray,
  int32_T c8_oldNumel, const emlrtRTEInfo *c8_srcLocation);
static void c8_emxInit_real_T(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, c8_emxArray_real_T **c8_pEmxArray, int32_T c8_numDimensions,
  const emlrtRTEInfo *c8_srcLocation);
static void c8_emxInitStruct_coder_internal_sp(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_coder_internal_sparse *c8_pStruct,
  const emlrtRTEInfo *c8_srcLocation);
static void c8_emxInit_int32_T(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, c8_emxArray_int32_T **c8_pEmxArray, int32_T
  c8_numDimensions, const emlrtRTEInfo *c8_srcLocation);
static void c8_emxFree_real_T(SFc8_CGMRESInstanceStruct *chartInstance,
  c8_emxArray_real_T **c8_pEmxArray);
static void c8_emxFreeStruct_coder_internal_sp(SFc8_CGMRESInstanceStruct
  *chartInstance, c8_coder_internal_sparse *c8_pStruct);
static void c8_emxFree_int32_T(SFc8_CGMRESInstanceStruct *chartInstance,
  c8_emxArray_int32_T **c8_pEmxArray);
static void c8_emxEnsureCapacity_real_T1(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_emxArray_real_T *c8_emxArray,
  int32_T c8_oldNumel, const emlrtRTEInfo *c8_srcLocation);
static void c8_emxInit_real_T1(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, c8_emxArray_real_T **c8_pEmxArray, int32_T c8_numDimensions,
  const emlrtRTEInfo *c8_srcLocation);
static int32_T c8__s32_minus__(SFc8_CGMRESInstanceStruct *chartInstance, int32_T
  c8_b, int32_T c8_c, int32_T c8_EMLOvCount_src_loc, uint32_T c8_ssid_src_loc,
  int32_T c8_offset_src_loc, int32_T c8_length_src_loc);
static int32_T c8__s32_add__(SFc8_CGMRESInstanceStruct *chartInstance, int32_T
  c8_b, int32_T c8_c, int32_T c8_EMLOvCount_src_loc, uint32_T c8_ssid_src_loc,
  int32_T c8_offset_src_loc, int32_T c8_length_src_loc);
static int32_T c8__s32_s64_(SFc8_CGMRESInstanceStruct *chartInstance, int64_T
  c8_b, int32_T c8_EMLOvCount_src_loc, uint32_T c8_ssid_src_loc, int32_T
  c8_offset_src_loc, int32_T c8_length_src_loc);
static void init_dsm_address_info(SFc8_CGMRESInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc8_CGMRESInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_CGMRES = 0U;
}

static void initialize_params_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_jit_animation_state_c8_CGMRES(SFc8_CGMRESInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c8_do_animation_call_c8_CGMRES(SFc8_CGMRESInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_CGMRES(SFc8_CGMRESInstanceStruct
  *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(2, 1), false);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", *chartInstance->c8_tau_lev2, 0, 0U,
    1U, 0U, 1, 3), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y",
    &chartInstance->c8_is_active_c8_CGMRES, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv[3];
  int32_T c8_b_i;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                      "tau_lev2", c8_dv);
  for (c8_b_i = 0; c8_b_i < 3; c8_b_i++) {
    (*chartInstance->c8_tau_lev2)[c8_b_i] = c8_dv[c8_b_i];
  }

  chartInstance->c8_is_active_c8_CGMRES = c8_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 1)), "is_active_c8_CGMRES");
  sf_mex_destroy(&c8_u);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c8_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c8_covrtInstance);
}

static void sf_gateway_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  emlrtStack c8_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  int32_T c8_b_i;
  int32_T c8_i1;
  int32_T c8_i2;
  int32_T c8_i3;
  int32_T c8_i4;
  int32_T c8_i5;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  int32_T c8_i10;
  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  c8_st.tls = chartInstance->c8_fEmlrtCtx;
  chartInstance->c8_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c8_b_i = 0; c8_b_i < 3; c8_b_i++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 13U,
                      (*chartInstance->c8_b_tau_lev2)[c8_b_i]);
  }

  for (c8_i1 = 0; c8_i1 < 12; c8_i1++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 12U,
                      (*chartInstance->c8_dTau_lev1)[c8_i1]);
  }

  for (c8_i2 = 0; c8_i2 < 169; c8_i2++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 11U,
                      (*chartInstance->c8_A_z_lev2)[c8_i2]);
  }

  for (c8_i3 = 0; c8_i3 < 240; c8_i3++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 10U,
                      (*chartInstance->c8_L_lev2)[c8_i3]);
  }

  for (c8_i4 = 0; c8_i4 < 624; c8_i4++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 9U,
                      (*chartInstance->c8_W_lev2)[c8_i4]);
  }

  for (c8_i5 = 0; c8_i5 < 208; c8_i5++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 8U,
                      (*chartInstance->c8_G_lev2)[c8_i5]);
  }

  for (c8_i6 = 0; c8_i6 < 208; c8_i6++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 7U,
                      (*chartInstance->c8_K_lev2)[c8_i6]);
  }

  for (c8_i7 = 0; c8_i7 < 160; c8_i7++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 6U,
                      (*chartInstance->c8_P_f2miubar)[c8_i7]);
  }

  for (c8_i8 = 0; c8_i8 < 240; c8_i8++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 5U,
                      (*chartInstance->c8_P_f2taubar)[c8_i8]);
  }

  covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 4U, *chartInstance->c8_i);
  for (c8_i9 = 0; c8_i9 < 9001; c8_i9++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 3U,
                      (*chartInstance->c8_Xprime_r_lev2)[c8_i9]);
  }

  for (c8_i10 = 0; c8_i10 < 13; c8_i10++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 2U,
                      (*chartInstance->c8_z_lev2)[c8_i10]);
  }

  for (c8_i11 = 0; c8_i11 < 6; c8_i11++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 1U, (*chartInstance->c8_J)
                      [c8_i11]);
  }

  for (c8_i12 = 0; c8_i12 < 9; c8_i12++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 0U,
                      (*chartInstance->c8_M_bar_inv)[c8_i12]);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_CGMRES(chartInstance, &c8_st);
  c8_do_animation_call_c8_CGMRES(chartInstance);
  for (c8_i13 = 0; c8_i13 < 3; c8_i13++) {
    covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 14U,
                      (*chartInstance->c8_tau_lev2)[c8_i13]);
  }
}

static void mdl_start_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  static const uint32_T c8_decisionTxtStartIdx = 0U;
  static const uint32_T c8_decisionTxtEndIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)c8_chart_data_browse_helper);
  chartInstance->c8_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c8_covrtInstance, 1U, 0U, 1U,
    61U);
  covrtChartInitFcn(chartInstance->c8_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c8_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c8_decisionTxtStartIdx, &c8_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c8_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c8_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c8_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 713);
  covrtEmlInitFcn(chartInstance->c8_covrtInstance,
                  "C:/Users/16967/Desktop/Master bei der TUM/Studium/LSR/Masterarbeit/IMPC_PriController/test/get_c.m",
                  14U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c8_covrtInstance, 14U, 0U, 0U, "get_c", 0,
                     -1, 116);
  covrtEmlForInitFcn(chartInstance->c8_covrtInstance, 14U, 0U, 0U, 47, 61, 91);
}

static void c8_chartstep_c8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance,
  const emlrtStack *c8_sp)
{
  emlrtStack c8_st;
  emlrtStack c8_b_st;
  emlrtStack c8_c_st;
  emlrtStack c8_d_st;
  int32_T c8_b_i;
  int32_T c8_i1;
  real_T c8_At[9];
  int32_T c8_i2;
  real_T c8_b_J[6];
  real_T c8_c_i;
  real_T c8_b_z_lev2[13];
  int32_T c8_i3;
  int32_T c8_i4;
  real_T c8_b_P_f2taubar[240];
  int32_T c8_i5;
  real_T c8_A2[160];
  int32_T c8_i6;
  real_T c8_b_K_lev2[208];
  int32_T c8_i7;
  real_T c8_b_G_lev2[208];
  int32_T c8_i8;
  real_T c8_b_W_lev2[624];
  int32_T c8_i9;
  real_T c8_A1[240];
  int32_T c8_i10;
  real_T c8_b_A_z_lev2[169];
  int32_T c8_i11;
  real_T c8_Bt[12];
  real_T c8_c_tau_lev2[3];
  real_T c8_d;
  real_T c8_d1;
  boolean_T c8_b;
  boolean_T c8_b1;
  boolean_T c8_b2;
  boolean_T c8_b3;
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  int32_T c8_i15;
  c8_emxArray_real_T *c8_v_lev2;
  int32_T c8_i16;
  int32_T c8_loop_ub;
  int32_T c8_i17;
  c8_emxArray_real_T *c8_c_lev2;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  int32_T c8_i23;
  int32_T c8_i24;
  int32_T c8_i25;
  real_T c8_b_Bt[6];
  int32_T c8_i26;
  real_T c8_b_At[6];
  real_T c8_dv[16];
  real_T c8_U[96];
  static real_T c8_dv1[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c8_i27;
  int32_T c8_i28;
  char_T c8_TRANSB1;
  char_T c8_TRANSA1;
  real_T c8_alpha1;
  real_T c8_beta1;
  ptrdiff_t c8_m_t;
  ptrdiff_t c8_n_t;
  ptrdiff_t c8_k_t;
  ptrdiff_t c8_lda_t;
  ptrdiff_t c8_ldb_t;
  ptrdiff_t c8_ldc_t;
  real_T c8_y[240];
  int32_T c8_i29;
  int32_T c8_i30;
  char_T c8_b_TRANSB1;
  char_T c8_b_TRANSA1;
  real_T c8_b_alpha1;
  real_T c8_b_beta1;
  ptrdiff_t c8_b_m_t;
  ptrdiff_t c8_b_n_t;
  ptrdiff_t c8_b_k_t;
  ptrdiff_t c8_b_lda_t;
  ptrdiff_t c8_b_ldb_t;
  ptrdiff_t c8_b_ldc_t;
  real_T c8_b_y[48];
  int32_T c8_innerDimB;
  int32_T c8_b_innerDimB;
  boolean_T c8_innerDimOk;
  const mxArray *c8_c_y = NULL;
  const mxArray *c8_d_y = NULL;
  int32_T c8_d_i;
  int32_T c8_i31;
  static char_T c8_cv[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 'n',
    'e', 'r', 'd', 'i', 'm' };

  static char_T c8_cv1[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D', 'y',
    'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p', 'a',
    'n', 's', 'i', 'o', 'n' };

  const mxArray *c8_e_y = NULL;
  const mxArray *c8_f_y = NULL;
  int32_T c8_k;
  int32_T c8_e_i;
  real_T c8_g_y[4];
  int32_T c8_i32;
  int32_T c8_b_k;
  int32_T c8_i33;
  int32_T c8_i34;
  int32_T c8_aoffset;
  real_T c8_temp;
  int32_T c8_f_i;
  int32_T c8_i35;
  real_T c8_b_b1[12];
  int32_T c8_i36;
  int32_T c8_i37;
  char_T c8_c_TRANSB1;
  char_T c8_c_TRANSA1;
  real_T c8_c_alpha1;
  real_T c8_c_beta1;
  ptrdiff_t c8_c_m_t;
  ptrdiff_t c8_c_n_t;
  ptrdiff_t c8_c_k_t;
  ptrdiff_t c8_c_lda_t;
  ptrdiff_t c8_c_ldb_t;
  ptrdiff_t c8_c_ldc_t;
  int32_T c8_i38;
  int32_T c8_i39;
  int32_T c8_i40;
  int32_T c8_i41;
  int32_T c8_i42;
  int32_T c8_i43;
  real_T c8_b_b2[8];
  int32_T c8_i44;
  int32_T c8_i45;
  real_T c8_c_At[96];
  int32_T c8_i46;
  int32_T c8_i47;
  int32_T c8_i48;
  int32_T c8_i49;
  int32_T c8_i50;
  int32_T c8_i51;
  real_T c8_As[400];
  int32_T c8_i52;
  int32_T c8_i53;
  int32_T c8_i54;
  real_T c8_outBuff[20];
  c8_coder_internal_sparse c8_b_As;
  int32_T c8_n;
  int32_T c8_c_k;
  real_T c8_b_n;
  real_T c8_d_k;
  int32_T c8_nnzInt;
  int32_T c8_a;
  int32_T c8_b_a;
  int32_T c8_numalloc;
  int32_T c8_i55;
  real_T c8_d2;
  real_T c8_d3;
  int32_T c8_b_loop_ub;
  int32_T c8_i56;
  int32_T c8_i57;
  int32_T c8_i58;
  int32_T c8_i59;
  real_T c8_d4;
  real_T c8_d5;
  int32_T c8_c_loop_ub;
  int32_T c8_i60;
  int32_T c8_ctr;
  int32_T c8_col;
  int32_T c8_b_col;
  int32_T c8_row;
  int32_T c8_b_row;
  int32_T c8_c_n;
  real_T c8_xrc;
  cs_di* c8_cxA;
  cs_dis * c8_S;
  cs_din * c8_N;
  int32_T c8_d_n;
  cs_di* c8_b_cxA;
  int32_T c8_i61;
  cs_dis * c8_b_S;
  cs_din * c8_b_N;
  const mxArray *c8_h_y = NULL;
  real_T c8_u[3];
  real_T c8_tol;
  int32_T c8_i62;
  int32_T c8_i63;
  c8_st.prev = c8_sp;
  c8_st.tls = c8_sp->tls;
  c8_b_st.prev = &c8_st;
  c8_b_st.tls = c8_st.tls;
  c8_c_st.prev = &c8_b_st;
  c8_c_st.tls = c8_b_st.tls;
  c8_d_st.prev = &c8_c_st;
  c8_d_st.tls = c8_c_st.tls;
  for (c8_b_i = 0; c8_b_i < 9; c8_b_i++) {
    c8_At[c8_b_i] = (*chartInstance->c8_M_bar_inv)[c8_b_i];
  }

  for (c8_i1 = 0; c8_i1 < 6; c8_i1++) {
    c8_b_J[c8_i1] = (*chartInstance->c8_J)[c8_i1];
  }

  for (c8_i2 = 0; c8_i2 < 13; c8_i2++) {
    c8_b_z_lev2[c8_i2] = (*chartInstance->c8_z_lev2)[c8_i2];
  }

  c8_c_i = *chartInstance->c8_i;
  for (c8_i3 = 0; c8_i3 < 240; c8_i3++) {
    c8_b_P_f2taubar[c8_i3] = (*chartInstance->c8_P_f2taubar)[c8_i3];
  }

  for (c8_i4 = 0; c8_i4 < 160; c8_i4++) {
    c8_A2[c8_i4] = (*chartInstance->c8_P_f2miubar)[c8_i4];
  }

  for (c8_i5 = 0; c8_i5 < 208; c8_i5++) {
    c8_b_K_lev2[c8_i5] = (*chartInstance->c8_K_lev2)[c8_i5];
  }

  for (c8_i6 = 0; c8_i6 < 208; c8_i6++) {
    c8_b_G_lev2[c8_i6] = (*chartInstance->c8_G_lev2)[c8_i6];
  }

  for (c8_i7 = 0; c8_i7 < 624; c8_i7++) {
    c8_b_W_lev2[c8_i7] = (*chartInstance->c8_W_lev2)[c8_i7];
  }

  for (c8_i8 = 0; c8_i8 < 240; c8_i8++) {
    c8_A1[c8_i8] = (*chartInstance->c8_L_lev2)[c8_i8];
  }

  for (c8_i9 = 0; c8_i9 < 169; c8_i9++) {
    c8_b_A_z_lev2[c8_i9] = (*chartInstance->c8_A_z_lev2)[c8_i9];
  }

  for (c8_i10 = 0; c8_i10 < 12; c8_i10++) {
    c8_Bt[c8_i10] = (*chartInstance->c8_dTau_lev1)[c8_i10];
  }

  for (c8_i11 = 0; c8_i11 < 3; c8_i11++) {
    c8_c_tau_lev2[c8_i11] = (*chartInstance->c8_b_tau_lev2)[c8_i11];
  }

  covrtEmlFcnEval(chartInstance->c8_covrtInstance, 4U, 0, 0);
  c8_d = c8_c_i + 1.0;
  c8_d1 = (c8_c_i + 5.0) - 1.0;
  c8_b = (c8_d > c8_d1);
  c8_b1 = c8_b;
  c8_b2 = false;
  c8_b3 = (c8_b1 || c8_b2);
  if (c8_b3) {
    c8_i13 = 1;
    c8_i14 = 0;
  } else {
    c8_i12 = (int32_T)emlrtIntegerCheckR2012b(c8_d, &c8_emlrtDCI, c8_sp);
    c8_i13 = emlrtDynamicBoundsCheckR2012b(c8_i12, 1, 9001, &c8_emlrtBCI, c8_sp);
    c8_i15 = (int32_T)emlrtIntegerCheckR2012b(c8_d1, &c8_b_emlrtDCI, c8_sp);
    c8_i14 = emlrtDynamicBoundsCheckR2012b(c8_i15, 1, 9001, &c8_b_emlrtBCI,
      c8_sp);
  }

  c8_emxInit_real_T(chartInstance, c8_sp, &c8_v_lev2, 1, &c8_emlrtRTEI);
  c8_i16 = c8_v_lev2->size[0];
  c8_v_lev2->size[0] = (c8_i14 - c8_i13) + 1;
  c8_st.site = &c8_jc_emlrtRSI;
  c8_emxEnsureCapacity_real_T(chartInstance, &c8_st, c8_v_lev2, c8_i16,
    &c8_emlrtRTEI);
  c8_loop_ub = c8_i14 - c8_i13;
  for (c8_i17 = 0; c8_i17 <= c8_loop_ub; c8_i17++) {
    c8_v_lev2->data[c8_i17] = (*chartInstance->c8_Xprime_r_lev2)[(c8_i13 +
      c8_i17) - 1];
  }

  c8_emxInit_real_T(chartInstance, c8_sp, &c8_c_lev2, 1, &c8_c_emlrtRTEI);
  c8_st.site = &c8_c_emlrtRSI;
  c8_get_c(chartInstance, &c8_st, c8_b_A_z_lev2, c8_b_z_lev2, c8_c_lev2);
  c8_i18 = 0;
  for (c8_i19 = 0; c8_i19 < 2; c8_i19++) {
    c8_i21 = 0;
    for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
      c8_b_Bt[c8_i22 + c8_i18] = c8_b_J[c8_i21 + c8_i19];
      c8_i21 += 2;
    }

    c8_i18 += 3;
  }

  for (c8_i20 = 0; c8_i20 < 3; c8_i20++) {
    c8_i24 = 0;
    for (c8_i25 = 0; c8_i25 < 2; c8_i25++) {
      c8_b_At[c8_i24 + c8_i20] = 0.0;
      c8_i27 = 0;
      for (c8_i28 = 0; c8_i28 < 3; c8_i28++) {
        c8_b_At[c8_i24 + c8_i20] += c8_At[c8_i27 + c8_i20] * c8_b_Bt[c8_i28 +
          c8_i24];
        c8_i27 += 3;
      }

      c8_i24 += 3;
    }
  }

  for (c8_i23 = 0; c8_i23 < 6; c8_i23++) {
    c8_b_J[c8_i23] = c8_b_At[c8_i23];
  }

  for (c8_i26 = 0; c8_i26 < 16; c8_i26++) {
    c8_dv[c8_i26] = c8_dv1[c8_i26];
  }

  c8_kron(chartInstance, c8_dv, c8_b_J, c8_U);
  c8_st.site = &c8_d_emlrtRSI;
  c8_b_st.site = &c8_i_emlrtRSI;
  c8_c_st.site = &c8_j_emlrtRSI;
  c8_TRANSB1 = 'N';
  c8_TRANSA1 = 'N';
  c8_alpha1 = 1.0;
  c8_beta1 = 0.0;
  c8_m_t = (ptrdiff_t)12;
  c8_n_t = (ptrdiff_t)20;
  c8_k_t = (ptrdiff_t)8;
  c8_lda_t = (ptrdiff_t)12;
  c8_ldb_t = (ptrdiff_t)8;
  c8_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_TRANSA1, &c8_TRANSB1, &c8_m_t, &c8_n_t, &c8_k_t, &c8_alpha1, &c8_U[0],
        &c8_lda_t, &c8_A2[0], &c8_ldb_t, &c8_beta1, &c8_y[0], &c8_ldc_t);
  for (c8_i29 = 0; c8_i29 < 240; c8_i29++) {
    c8_A1[c8_i29] += c8_y[c8_i29];
  }

  c8_i30 = c8_v_lev2->size[0];
  emlrtSizeEqCheck1DR2012b(c8_i30, 4, &c8_emlrtECI, c8_sp);
  c8_st.site = &c8_e_emlrtRSI;
  c8_b_st.site = &c8_i_emlrtRSI;
  c8_c_st.site = &c8_j_emlrtRSI;
  c8_b_TRANSB1 = 'N';
  c8_b_TRANSA1 = 'N';
  c8_b_alpha1 = 1.0;
  c8_b_beta1 = 0.0;
  c8_b_m_t = (ptrdiff_t)12;
  c8_b_n_t = (ptrdiff_t)4;
  c8_b_k_t = (ptrdiff_t)52;
  c8_b_lda_t = (ptrdiff_t)12;
  c8_b_ldb_t = (ptrdiff_t)52;
  c8_b_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_b_TRANSA1, &c8_b_TRANSB1, &c8_b_m_t, &c8_b_n_t, &c8_b_k_t,
        &c8_b_alpha1, &c8_b_W_lev2[0], &c8_b_lda_t, &c8_b_G_lev2[0], &c8_b_ldb_t,
        &c8_b_beta1, &c8_b_y[0], &c8_b_ldc_t);
  c8_st.site = &c8_e_emlrtRSI;
  c8_innerDimB = c8_c_lev2->size[0];
  c8_b_st.site = &c8_ac_emlrtRSI;
  c8_b_innerDimB = c8_innerDimB;
  c8_innerDimOk = (52 == c8_b_innerDimB);
  if (!c8_innerDimOk) {
    if (c8_c_lev2->size[0] == 1) {
      c8_d_y = NULL;
      sf_mex_assign(&c8_d_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      c8_f_y = NULL;
      sf_mex_assign(&c8_f_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call(&c8_b_st, "error", 0U, 2U, 14, c8_d_y, 14, sf_mex_call
                  (&c8_b_st, "getString", 1U, 1U, 14, sf_mex_call(&c8_b_st,
        "message", 1U, 1U, 14, c8_f_y)));
    } else {
      c8_c_y = NULL;
      sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 15),
                    false);
      c8_e_y = NULL;
      sf_mex_assign(&c8_e_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 15),
                    false);
      sf_mex_call(&c8_b_st, "error", 0U, 2U, 14, c8_c_y, 14, sf_mex_call
                  (&c8_b_st, "getString", 1U, 1U, 14, sf_mex_call(&c8_b_st,
        "message", 1U, 1U, 14, c8_e_y)));
    }
  }

  if (c8_innerDimB == 1) {
    for (c8_i31 = 0; c8_i31 < 4; c8_i31++) {
      c8_g_y[c8_i31] = 0.0;
      c8_i32 = 0;
      for (c8_i34 = 0; c8_i34 < 52; c8_i34++) {
        c8_g_y[c8_i31] += c8_b_K_lev2[c8_i32 + c8_i31] * c8_c_lev2->data[c8_i34];
        c8_i32 += 4;
      }
    }
  } else {
    for (c8_d_i = 0; c8_d_i < 4; c8_d_i++) {
      c8_e_i = c8_d_i;
      c8_g_y[c8_e_i] = 0.0;
    }

    for (c8_k = 0; c8_k < 52; c8_k++) {
      c8_b_k = c8_k;
      c8_aoffset = c8__s32_s64_(chartInstance, (int64_T)c8__s32_minus__
        (chartInstance, c8_b_k + 1, 1, 0, 1U, 360, 13) * 4LL, 0, 1U, 360, 13);
      c8_temp = c8_c_lev2->data[c8_b_k];
      for (c8_f_i = 0; c8_f_i < 4; c8_f_i++) {
        c8_e_i = c8_f_i;
        c8_g_y[c8_e_i] += c8_temp * c8_b_K_lev2[c8__s32_add__(chartInstance,
          c8_aoffset, c8_e_i + 1, 0, 1U, 360, 13) - 1];
      }
    }
  }

  c8_emxFree_real_T(chartInstance, &c8_c_lev2);
  for (c8_i33 = 0; c8_i33 < 4; c8_i33++) {
    c8_g_y[c8_i33] = c8_v_lev2->data[c8_i33] - c8_g_y[c8_i33];
  }

  c8_emxFree_real_T(chartInstance, &c8_v_lev2);
  for (c8_i35 = 0; c8_i35 < 12; c8_i35++) {
    c8_b_b1[c8_i35] = 0.0;
    c8_i36 = 0;
    for (c8_i37 = 0; c8_i37 < 4; c8_i37++) {
      c8_b_b1[c8_i35] += c8_b_y[c8_i36 + c8_i35] * c8_g_y[c8_i37];
      c8_i36 += 12;
    }
  }

  c8_st.site = &c8_f_emlrtRSI;
  c8_b_st.site = &c8_i_emlrtRSI;
  c8_c_st.site = &c8_j_emlrtRSI;
  c8_c_TRANSB1 = 'N';
  c8_c_TRANSA1 = 'T';
  c8_c_alpha1 = 1.0;
  c8_c_beta1 = 0.0;
  c8_c_m_t = (ptrdiff_t)8;
  c8_c_n_t = (ptrdiff_t)20;
  c8_c_k_t = (ptrdiff_t)12;
  c8_c_lda_t = (ptrdiff_t)12;
  c8_c_ldb_t = (ptrdiff_t)12;
  c8_c_ldc_t = (ptrdiff_t)8;
  dgemm(&c8_c_TRANSA1, &c8_c_TRANSB1, &c8_c_m_t, &c8_c_n_t, &c8_c_k_t,
        &c8_c_alpha1, &c8_U[0], &c8_c_lda_t, &c8_b_P_f2taubar[0], &c8_c_ldb_t,
        &c8_c_beta1, &c8_A2[0], &c8_c_ldc_t);
  c8_i38 = 0;
  for (c8_i39 = 0; c8_i39 < 12; c8_i39++) {
    c8_i41 = 0;
    for (c8_i42 = 0; c8_i42 < 8; c8_i42++) {
      c8_c_At[c8_i42 + c8_i38] = c8_U[c8_i41 + c8_i39];
      c8_i41 += 12;
    }

    c8_i38 += 8;
  }

  for (c8_i40 = 0; c8_i40 < 8; c8_i40++) {
    c8_b_b2[c8_i40] = 0.0;
    c8_i45 = 0;
    for (c8_i47 = 0; c8_i47 < 12; c8_i47++) {
      c8_b_b2[c8_i40] += c8_c_At[c8_i45 + c8_i40] * c8_Bt[c8_i47];
      c8_i45 += 8;
    }
  }

  c8_i43 = 0;
  c8_i44 = 0;
  for (c8_i46 = 0; c8_i46 < 20; c8_i46++) {
    for (c8_i49 = 0; c8_i49 < 12; c8_i49++) {
      c8_As[c8_i49 + c8_i43] = c8_A1[c8_i49 + c8_i44];
    }

    c8_i43 += 20;
    c8_i44 += 12;
  }

  c8_i48 = 0;
  c8_i50 = 0;
  for (c8_i51 = 0; c8_i51 < 20; c8_i51++) {
    for (c8_i53 = 0; c8_i53 < 8; c8_i53++) {
      c8_As[(c8_i53 + c8_i48) + 12] = c8_A2[c8_i53 + c8_i50];
    }

    c8_i48 += 20;
    c8_i50 += 8;
  }

  for (c8_i52 = 0; c8_i52 < 12; c8_i52++) {
    c8_outBuff[c8_i52] = c8_b_b1[c8_i52];
  }

  for (c8_i54 = 0; c8_i54 < 8; c8_i54++) {
    c8_outBuff[c8_i54 + 12] = c8_b_b2[c8_i54];
  }

  c8_emxInitStruct_coder_internal_sp(chartInstance, c8_sp, &c8_b_As,
    &c8_d_emlrtRTEI);
  c8_st.site = &c8_g_emlrtRSI;
  c8_b_st.site = &c8_bc_emlrtRSI;
  c8_n = 0;
  for (c8_c_k = 0; c8_c_k < 400; c8_c_k++) {
    c8_d_k = (real_T)c8_c_k + 1.0;
    if (c8_As[(int32_T)c8_d_k - 1] != 0.0) {
      c8_b_a = c8_n + 1;
      c8_n = c8_b_a;
    }
  }

  c8_b_n = (real_T)c8_n;
  c8_nnzInt = (int32_T)c8_b_n;
  c8_a = c8_nnzInt;
  if (c8_a >= 1) {
    c8_numalloc = c8_a;
  } else {
    c8_numalloc = 1;
  }

  c8_i55 = c8_b_As.d->size[0];
  c8_d2 = (real_T)c8_numalloc;
  c8_b_As.d->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c8_d2,
    &c8_c_emlrtDCI, &c8_b_st);
  c8_emxEnsureCapacity_real_T(chartInstance, &c8_b_st, c8_b_As.d, c8_i55,
    &c8_b_emlrtRTEI);
  c8_d3 = (real_T)c8_numalloc;
  c8_b_loop_ub = (int32_T)emlrtNonNegativeCheckR2012b(c8_d3, &c8_c_emlrtDCI,
    &c8_b_st) - 1;
  for (c8_i56 = 0; c8_i56 <= c8_b_loop_ub; c8_i56++) {
    c8_b_As.d->data[c8_i56] = 0.0;
  }

  c8_i57 = c8_b_As.colidx->size[0];
  c8_b_As.colidx->size[0] = 21;
  c8_emxEnsureCapacity_int32_T(chartInstance, &c8_b_st, c8_b_As.colidx, c8_i57,
    &c8_b_emlrtRTEI);
  for (c8_i58 = 0; c8_i58 < 21; c8_i58++) {
    c8_b_As.colidx->data[c8_i58] = 0;
  }

  c8_b_As.colidx->data[0] = 1;
  c8_i59 = c8_b_As.rowidx->size[0];
  c8_d4 = (real_T)c8_numalloc;
  c8_b_As.rowidx->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c8_d4,
    &c8_c_emlrtDCI, &c8_b_st);
  c8_emxEnsureCapacity_int32_T(chartInstance, &c8_b_st, c8_b_As.rowidx, c8_i59,
    &c8_b_emlrtRTEI);
  c8_d5 = (real_T)c8_numalloc;
  c8_c_loop_ub = (int32_T)emlrtNonNegativeCheckR2012b(c8_d5, &c8_c_emlrtDCI,
    &c8_b_st) - 1;
  for (c8_i60 = 0; c8_i60 <= c8_c_loop_ub; c8_i60++) {
    c8_b_As.rowidx->data[c8_i60] = 0;
  }

  c8_b_As.rowidx->data[0] = 1;
  c8_ctr = 0;
  for (c8_col = 0; c8_col < 20; c8_col++) {
    c8_b_col = c8_col;
    for (c8_row = 0; c8_row < 20; c8_row++) {
      c8_b_row = c8_row;
      c8_xrc = c8_As[c8_b_row + 20 * c8_b_col];
      if (c8_xrc != 0.0) {
        c8_b_As.rowidx->data[c8_ctr] = c8_b_row + 1;
        c8_b_As.d->data[c8_ctr] = c8_xrc;
        c8_ctr++;
      }
    }

    c8_b_As.colidx->data[c8_b_col + 1] = c8_ctr + 1;
  }

  c8_st.site = &c8_h_emlrtRSI;
  c8_b_st.site = &c8_cc_emlrtRSI;
  c8_c_st.site = &c8_dc_emlrtRSI;
  c8_d_st.site = &c8_ec_emlrtRSI;
  c8_c_n = c8_b_As.colidx->data[c8_b_As.colidx->size[0] - 1];
  c8_cxA = makeCXSparseMatrix(c8_c_n - 1, 20, 20, &c8_b_As.colidx->data[0],
    &c8_b_As.rowidx->data[0], &c8_b_As.d->data[0]);
  c8_S = cs_di_sqr(2, c8_cxA, 0);
  c8_N = cs_di_lu(c8_cxA, c8_S, 1);
  cs_di_spfree(c8_cxA);
  if (c8_N == NULL) {
    c8_d_st.site = &c8_fc_emlrtRSI;
    c8_warning(chartInstance, &c8_d_st);
    cs_di_sfree(c8_S);
    cs_di_nfree(c8_N);
    c8_d_n = c8_b_As.colidx->data[c8_b_As.colidx->size[0] - 1];
    c8_b_cxA = makeCXSparseMatrix(c8_d_n - 1, 20, 20, &c8_b_As.colidx->data[0],
      &c8_b_As.rowidx->data[0], &c8_b_As.d->data[0]);
    c8_b_S = cs_di_sqr(2, c8_b_cxA, 1);
    c8_b_N = cs_di_qr(c8_b_cxA, c8_b_S);
    cs_di_spfree(c8_b_cxA);
    qr_rank_di(c8_b_N, &c8_tol);
    solve_from_qr_di(c8_b_N, c8_b_S, (double *)&c8_outBuff[0], 20, 20);
    cs_di_sfree(c8_b_S);
    cs_di_nfree(c8_b_N);
  } else {
    solve_from_lu_di(c8_N, c8_S, (double *)&c8_outBuff[0], 20);
    cs_di_sfree(c8_S);
    cs_di_nfree(c8_N);
  }

  c8_emxFreeStruct_coder_internal_sp(chartInstance, &c8_b_As);
  sf_mex_printf("%s =\\n", "ans");
  for (c8_i61 = 0; c8_i61 < 3; c8_i61++) {
    c8_u[c8_i61] = c8_outBuff[c8_i61];
  }

  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_call(c8_sp, "disp", 0U, 1U, 14, c8_h_y);
  for (c8_i62 = 0; c8_i62 < 3; c8_i62++) {
    c8_c_tau_lev2[c8_i62] += c8_outBuff[c8_i62];
  }

  for (c8_i63 = 0; c8_i63 < 3; c8_i63++) {
    (*chartInstance->c8_tau_lev2)[c8_i63] = c8_c_tau_lev2[c8_i63];
  }
}

static void initSimStructsc8_CGMRES(SFc8_CGMRESInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_get_c(SFc8_CGMRESInstanceStruct *chartInstance, const emlrtStack *
                     c8_sp, real_T c8_A_z[169], real_T c8_z_0[13],
                     c8_emxArray_real_T *c8_c)
{
  emlrtStack c8_st;
  emlrtStack c8_b_st;
  emlrtStack c8_c_st;
  c8_emxArray_real_T *c8_A;
  c8_emxArray_real_T *c8_b_A;
  int32_T c8_b_i;
  real_T c8_c_i;
  real_T c8_b;
  int32_T c8_mA;
  real_T c8_b_b;
  int32_T c8_d_i;
  int32_T c8_m;
  const mxArray *c8_y = NULL;
  int32_T c8_i1;
  int32_T c8_lda;
  static char_T c8_cv[37] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 'p', 'o', 'w', 'e', 'r', '_', 'n', 'e', 'e', 'd',
    'C', 'o', 'm', 'p', 'l', 'e', 'x', 'I', 'n', 'p', 'u', 't' };

  int32_T c8_mc;
  int32_T c8_loop_ub;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_A_z[169];
  int32_T c8_ldc;
  int32_T c8_i2;
  real_T c8_b_c[169];
  char_T c8_TRANSB1;
  char_T c8_TRANSA1;
  int32_T c8_i3;
  real_T c8_alpha1;
  real_T c8_beta1;
  int32_T c8_var;
  ptrdiff_t c8_m_t;
  ptrdiff_t c8_n_t;
  int32_T c8_i4;
  ptrdiff_t c8_k_t;
  int32_T c8_b_var;
  int32_T c8_i5;
  int32_T c8_b_loop_ub;
  ptrdiff_t c8_lda_t;
  int32_T c8_i6;
  ptrdiff_t c8_ldb_t;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_c_var;
  ptrdiff_t c8_ldc_t;
  int32_T c8_i9;
  int32_T c8_c_loop_ub;
  int32_T c8_i10;
  c8_st.prev = c8_sp;
  c8_st.tls = c8_sp->tls;
  c8_b_st.prev = &c8_st;
  c8_b_st.tls = c8_st.tls;
  c8_c_st.prev = &c8_b_st;
  c8_c_st.tls = c8_b_st.tls;
  c8_emxInit_real_T1(chartInstance, c8_sp, &c8_A, 2, &c8_i_emlrtRTEI);
  covrtEmlFcnEval(chartInstance->c8_covrtInstance, 14U, 0, 0);
  c8_A->size[0] = 0;
  c8_A->size[1] = 13;
  c8_emxInit_real_T1(chartInstance, c8_sp, &c8_b_A, 2, &c8_f_emlrtRTEI);
  for (c8_b_i = 0; c8_b_i < 4; c8_b_i++) {
    c8_c_i = 1.0 + (real_T)c8_b_i;
    covrtEmlForEval(chartInstance->c8_covrtInstance, 14U, 0, 0, 1);
    c8_st.site = &c8_emlrtRSI;
    c8_b = c8_c_i;
    c8_b_st.site = &c8_m_emlrtRSI;
    c8_b_b = c8_b;
    if (c8_b_b == c8_b_b) {
      for (c8_i1 = 0; c8_i1 < 169; c8_i1++) {
        c8_b_A_z[c8_i1] = c8_A_z[c8_i1];
      }

      c8_c_st.site = &c8_n_emlrtRSI;
      c8_matrix_to_integer_power(chartInstance, &c8_c_st, c8_b_A_z, c8_b_b,
        c8_b_c);
    } else {
      c8_y = NULL;
      sf_mex_assign(&c8_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 37),
                    false);
      c8_b_y = NULL;
      sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 37),
                    false);
      sf_mex_call(&c8_b_st, "error", 0U, 2U, 14, c8_y, 14, sf_mex_call(&c8_b_st,
        "getString", 1U, 1U, 14, sf_mex_call(&c8_b_st, "message", 1U, 1U, 14,
        c8_b_y)));
    }

    c8_i3 = c8_b_A->size[0] * c8_b_A->size[1];
    c8_b_A->size[0] = c8_A->size[0] + 13;
    c8_b_A->size[1] = 13;
    c8_st.site = &c8_emlrtRSI;
    c8_emxEnsureCapacity_real_T1(chartInstance, &c8_st, c8_b_A, c8_i3,
      &c8_f_emlrtRTEI);
    for (c8_i4 = 0; c8_i4 < 13; c8_i4++) {
      c8_b_loop_ub = c8_A->size[0] - 1;
      for (c8_i6 = 0; c8_i6 <= c8_b_loop_ub; c8_i6++) {
        c8_b_A->data[c8_i6 + c8_b_A->size[0] * c8_i4] = c8_A->data[c8_i6 +
          c8_A->size[0] * c8_i4];
      }
    }

    for (c8_i5 = 0; c8_i5 < 13; c8_i5++) {
      for (c8_i8 = 0; c8_i8 < 13; c8_i8++) {
        c8_b_A->data[(c8_i8 + c8_A->size[0]) + c8_b_A->size[0] * c8_i5] =
          c8_b_c[c8_i8 + 13 * c8_i5];
      }
    }

    c8_i7 = c8_A->size[0] * c8_A->size[1];
    c8_A->size[0] = c8_b_A->size[0];
    c8_A->size[1] = 13;
    c8_st.site = &c8_emlrtRSI;
    c8_emxEnsureCapacity_real_T1(chartInstance, &c8_st, c8_A, c8_i7,
      &c8_h_emlrtRTEI);
    c8_c_loop_ub = c8_b_A->size[0] * c8_b_A->size[1] - 1;
    for (c8_i10 = 0; c8_i10 <= c8_c_loop_ub; c8_i10++) {
      c8_A->data[c8_i10] = c8_b_A->data[c8_i10];
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c8_emxFree_real_T(chartInstance, &c8_b_A);
  covrtEmlForEval(chartInstance->c8_covrtInstance, 14U, 0, 0, 0);
  c8_st.site = &c8_b_emlrtRSI;
  c8_b_st.site = &c8_i_emlrtRSI;
  c8_mA = c8_A->size[0];
  if (c8_mA == 0) {
    c8_d_i = c8_c->size[0];
    c8_c->size[0] = c8_mA;
    c8_emxEnsureCapacity_real_T(chartInstance, &c8_b_st, c8_c, c8_d_i,
      &c8_e_emlrtRTEI);
    c8_loop_ub = c8_mA - 1;
    for (c8_i2 = 0; c8_i2 <= c8_loop_ub; c8_i2++) {
      c8_c->data[c8_i2] = 0.0;
    }
  } else {
    c8_c_st.site = &c8_j_emlrtRSI;
    c8_m = c8_mA;
    c8_lda = c8_mA;
    c8_mc = c8_mA;
    c8_ldc = c8_mA;
    c8_TRANSB1 = 'N';
    c8_TRANSA1 = 'N';
    c8_alpha1 = 1.0;
    c8_beta1 = 0.0;
    c8_var = c8_m;
    c8_m_t = (ptrdiff_t)c8_var;
    c8_n_t = (ptrdiff_t)1;
    c8_k_t = (ptrdiff_t)13;
    c8_b_var = c8_lda;
    c8_lda_t = (ptrdiff_t)c8_b_var;
    c8_ldb_t = (ptrdiff_t)13;
    c8_c_var = c8_ldc;
    c8_ldc_t = (ptrdiff_t)c8_c_var;
    c8_i9 = c8_c->size[0];
    c8_c->size[0] = c8_mc;
    c8_emxEnsureCapacity_real_T(chartInstance, &c8_c_st, c8_c, c8_i9,
      &c8_g_emlrtRTEI);
    dgemm(&c8_TRANSA1, &c8_TRANSB1, &c8_m_t, &c8_n_t, &c8_k_t, &c8_alpha1,
          &c8_A->data[0], &c8_lda_t, &c8_z_0[0], &c8_ldb_t, &c8_beta1,
          &c8_c->data[0], &c8_ldc_t);
  }

  c8_emxFree_real_T(chartInstance, &c8_A);
}

const mxArray *sf_c8_CGMRES_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  const char * c8_data[4] = {
    "789ce553dd4ec230142e04885e68b8f2569ec0ea0d46ef48fd81842528432f8cc1c18ed2b0aeb3eb10bdf7da17f1417c041fc7c1d8a88dcd4c506f3c4973faed"
    "6bcf77ce970e155a560121b48992d8ad2479235ec5785517df8be873e87cc190d328a352764fe55f1679c87d09539900df6190dd7439a3bee34bfb31002420e4",
    "de04dc39734b3db0298336574093c6809d28540666d46c4f46301c772386c4285c76e8a920f3e346991729f396bef043e5f5d0fdd0cfcdf48a2be8a5f5cb46bd"
    "84b903d91ffea05ec5a897302e8f061e2cf5de56d4030d23ed5cca5f1d5f9343dc0b418478af7e50dfc747108e250fb0e58412446d00b4e6c6d9ee59b82b2397",
    "460cb7bbe70bda11312f71cbea907e475012bf4ec13d0f0496104a3c777187a17c1f537ff2e632fd37eb682dddbe3e6fbf37fe506f1eff456f6aa8f7dd77b965"
    "d0ab6a3cf1ad805c064ff6856c50797ae6df470f4db2eca393a393d70732e0dfaeff01e908621f",
    "" };

  c8_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c8_data[0], 1608U, &c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_nbits(SFc8_CGMRESInstanceStruct *chartInstance, int32_T c8_n,
                     int32_T *c8_log2n, int32_T *c8_nbitson)
{
  (void)chartInstance;
  *c8_nbitson = 0;
  *c8_log2n = 0;
  while (c8_n > 0) {
    (*c8_log2n)++;
    if ((c8_n & 1) != 0) {
      (*c8_nbitson)++;
    }

    c8_n >>= 1;
  }
}

static void c8_matrix_to_integer_power(SFc8_CGMRESInstanceStruct *chartInstance,
  const emlrtStack *c8_sp, real_T c8_a[169], real_T c8_b, real_T c8_c[169])
{
  emlrtStack c8_st;
  emlrtStack c8_b_st;
  emlrtStack c8_c_st;
  int32_T c8_b_i;
  real_T c8_b_b;
  real_T c8_b_a[169];
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_y;
  int32_T c8_n;
  int32_T c8_nb;
  int32_T c8_nbitson;
  boolean_T c8_first;
  boolean_T c8_aBufferInUse;
  boolean_T c8_lsb;
  int32_T c8_i1;
  int32_T c8_i2;
  char_T c8_TRANSB1;
  char_T c8_TRANSA1;
  boolean_T c8_cBufferInUse;
  int32_T c8_j;
  real_T c8_alpha1;
  real_T c8_beta1;
  boolean_T c8_b_cBufferInUse;
  int32_T c8_b_j;
  ptrdiff_t c8_m_t;
  int32_T c8_i3;
  ptrdiff_t c8_n_t;
  ptrdiff_t c8_k_t;
  int32_T c8_c_b;
  ptrdiff_t c8_lda_t;
  int32_T c8_d_b;
  ptrdiff_t c8_ldb_t;
  ptrdiff_t c8_ldc_t;
  boolean_T c8_overflow;
  int32_T c8_k;
  boolean_T c8_b_aBufferInUse;
  int32_T c8_i4;
  int32_T c8_i5;
  boolean_T c8_c_cBufferInUse;
  boolean_T c8_assignToBuffer;
  char_T c8_b_TRANSB1;
  char_T c8_c_TRANSB1;
  real_T c8_aBuffer[169];
  boolean_T c8_c_aBufferInUse;
  boolean_T c8_d_aBufferInUse;
  boolean_T c8_e_aBufferInUse;
  char_T c8_b_TRANSA1;
  char_T c8_c_TRANSA1;
  boolean_T c8_f_aBufferInUse;
  boolean_T c8_d_cBufferInUse;
  real_T c8_b_alpha1;
  real_T c8_c_alpha1;
  real_T c8_b_beta1;
  real_T c8_c_beta1;
  char_T c8_d_TRANSB1;
  char_T c8_e_TRANSB1;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  ptrdiff_t c8_b_m_t;
  ptrdiff_t c8_c_m_t;
  char_T c8_d_TRANSA1;
  char_T c8_e_TRANSA1;
  char_T c8_f_TRANSB1;
  char_T c8_g_TRANSB1;
  char_T c8_h_TRANSB1;
  char_T c8_i_TRANSB1;
  ptrdiff_t c8_b_n_t;
  ptrdiff_t c8_c_n_t;
  real_T c8_d_alpha1;
  real_T c8_e_alpha1;
  char_T c8_f_TRANSA1;
  char_T c8_g_TRANSA1;
  char_T c8_h_TRANSA1;
  char_T c8_i_TRANSA1;
  real_T c8_cBuffer[169];
  ptrdiff_t c8_b_k_t;
  ptrdiff_t c8_c_k_t;
  real_T c8_d_beta1;
  real_T c8_e_beta1;
  real_T c8_f_alpha1;
  real_T c8_g_alpha1;
  real_T c8_h_alpha1;
  real_T c8_i_alpha1;
  ptrdiff_t c8_b_lda_t;
  ptrdiff_t c8_c_lda_t;
  ptrdiff_t c8_d_m_t;
  ptrdiff_t c8_e_m_t;
  real_T c8_f_beta1;
  real_T c8_g_beta1;
  real_T c8_h_beta1;
  real_T c8_i_beta1;
  ptrdiff_t c8_b_ldb_t;
  ptrdiff_t c8_c_ldb_t;
  ptrdiff_t c8_d_n_t;
  ptrdiff_t c8_e_n_t;
  ptrdiff_t c8_f_m_t;
  ptrdiff_t c8_g_m_t;
  ptrdiff_t c8_h_m_t;
  ptrdiff_t c8_i_m_t;
  ptrdiff_t c8_b_ldc_t;
  ptrdiff_t c8_c_ldc_t;
  ptrdiff_t c8_d_k_t;
  ptrdiff_t c8_e_k_t;
  ptrdiff_t c8_f_n_t;
  ptrdiff_t c8_g_n_t;
  ptrdiff_t c8_h_n_t;
  ptrdiff_t c8_i_n_t;
  ptrdiff_t c8_d_lda_t;
  ptrdiff_t c8_e_lda_t;
  ptrdiff_t c8_f_k_t;
  ptrdiff_t c8_g_k_t;
  ptrdiff_t c8_h_k_t;
  ptrdiff_t c8_i_k_t;
  ptrdiff_t c8_d_ldb_t;
  ptrdiff_t c8_e_ldb_t;
  ptrdiff_t c8_f_lda_t;
  ptrdiff_t c8_g_lda_t;
  ptrdiff_t c8_h_lda_t;
  ptrdiff_t c8_i_lda_t;
  ptrdiff_t c8_d_ldc_t;
  ptrdiff_t c8_e_ldc_t;
  ptrdiff_t c8_f_ldb_t;
  ptrdiff_t c8_g_ldb_t;
  ptrdiff_t c8_h_ldb_t;
  ptrdiff_t c8_i_ldb_t;
  ptrdiff_t c8_f_ldc_t;
  ptrdiff_t c8_g_ldc_t;
  ptrdiff_t c8_h_ldc_t;
  ptrdiff_t c8_i_ldc_t;
  c8_st.prev = c8_sp;
  c8_st.tls = c8_sp->tls;
  c8_st.site = &c8_o_emlrtRSI;
  c8_b_st.prev = &c8_st;
  c8_b_st.tls = c8_st.tls;
  c8_c_st.prev = &c8_b_st;
  c8_c_st.tls = c8_b_st.tls;
  for (c8_b_i = 0; c8_b_i < 169; c8_b_i++) {
    c8_b_a[c8_b_i] = c8_a[c8_b_i];
  }

  c8_b_b = c8_b;
  c8_x = c8_b_b;
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_y = muDoubleScalarAbs(c8_c_x);
  c8_n = (int32_T)c8_y;
  c8_nbits(chartInstance, c8_n, &c8_nb, &c8_nbitson);
  if (c8_n <= 2) {
    if (c8_b_b == 2.0) {
      c8_b_st.site = &c8_t_emlrtRSI;
      c8_TRANSB1 = 'N';
      c8_TRANSA1 = 'N';
      c8_alpha1 = 1.0;
      c8_beta1 = 0.0;
      c8_m_t = (ptrdiff_t)13;
      c8_n_t = (ptrdiff_t)13;
      c8_k_t = (ptrdiff_t)13;
      c8_lda_t = (ptrdiff_t)13;
      c8_ldb_t = (ptrdiff_t)13;
      c8_ldc_t = (ptrdiff_t)13;
      dgemm(&c8_TRANSA1, &c8_TRANSB1, &c8_m_t, &c8_n_t, &c8_k_t, &c8_alpha1,
            &c8_b_a[0], &c8_lda_t, &c8_b_a[0], &c8_ldb_t, &c8_beta1, &c8_c[0],
            &c8_ldc_t);
    } else if (c8_b_b == 1.0) {
      for (c8_i2 = 0; c8_i2 < 169; c8_i2++) {
        c8_c[c8_i2] = c8_b_a[c8_i2];
      }
    } else {
      for (c8_i1 = 0; c8_i1 < 169; c8_i1++) {
        c8_c[c8_i1] = 0.0;
      }

      for (c8_j = 0; c8_j < 13; c8_j++) {
        c8_b_j = c8_j;
        c8_c[c8_b_j + 13 * c8_b_j] = 1.0;
      }
    }
  } else {
    c8_first = true;
    c8_aBufferInUse = false;
    c8_lsb = ((c8_nbitson & 1) != 0);
    if (!c8_lsb) {
      c8_cBufferInUse = true;
    } else {
      c8_cBufferInUse = false;
    }

    c8_b_cBufferInUse = c8_cBufferInUse;
    c8_i3 = c8_nb - 2;
    c8_b_st.site = &c8_s_emlrtRSI;
    c8_c_b = c8_i3 + 1;
    c8_d_b = c8_c_b;
    if (1 > c8_d_b) {
      c8_overflow = false;
    } else {
      c8_overflow = (c8_d_b > 2147483646);
    }

    if (c8_overflow) {
      c8_c_st.site = &c8_ib_emlrtRSI;
      c8_check_forloop_overflow_error(chartInstance, &c8_c_st);
    }

    for (c8_k = 0; c8_k <= c8_i3; c8_k++) {
      if ((c8_n & 1) != 0) {
        if (c8_first) {
          c8_first = false;
          c8_assignToBuffer = c8_b_cBufferInUse;
          c8_e_aBufferInUse = c8_aBufferInUse;
          if (c8_assignToBuffer) {
            if (c8_e_aBufferInUse) {
              for (c8_i9 = 0; c8_i9 < 169; c8_i9++) {
                c8_cBuffer[c8_i9] = c8_aBuffer[c8_i9];
              }
            } else {
              for (c8_i8 = 0; c8_i8 < 169; c8_i8++) {
                c8_cBuffer[c8_i8] = c8_b_a[c8_i8];
              }
            }
          } else if (c8_e_aBufferInUse) {
            for (c8_i7 = 0; c8_i7 < 169; c8_i7++) {
              c8_c[c8_i7] = c8_aBuffer[c8_i7];
            }
          } else {
            for (c8_i6 = 0; c8_i6 < 169; c8_i6++) {
              c8_c[c8_i6] = c8_b_a[c8_i6];
            }
          }
        } else {
          c8_b_st.site = &c8_r_emlrtRSI;
          c8_c_cBufferInUse = c8_b_cBufferInUse;
          c8_d_aBufferInUse = c8_aBufferInUse;
          c8_d_cBufferInUse = c8_c_cBufferInUse;
          if (c8_d_aBufferInUse) {
            if (c8_d_cBufferInUse) {
              c8_i_TRANSB1 = 'N';
              c8_i_TRANSA1 = 'N';
              c8_i_alpha1 = 1.0;
              c8_i_beta1 = 0.0;
              c8_i_m_t = (ptrdiff_t)13;
              c8_i_n_t = (ptrdiff_t)13;
              c8_i_k_t = (ptrdiff_t)13;
              c8_i_lda_t = (ptrdiff_t)13;
              c8_i_ldb_t = (ptrdiff_t)13;
              c8_i_ldc_t = (ptrdiff_t)13;
              dgemm(&c8_i_TRANSA1, &c8_i_TRANSB1, &c8_i_m_t, &c8_i_n_t,
                    &c8_i_k_t, &c8_i_alpha1, &c8_cBuffer[0], &c8_i_lda_t,
                    &c8_aBuffer[0], &c8_i_ldb_t, &c8_i_beta1, &c8_c[0],
                    &c8_i_ldc_t);
            } else {
              c8_h_TRANSB1 = 'N';
              c8_h_TRANSA1 = 'N';
              c8_h_alpha1 = 1.0;
              c8_h_beta1 = 0.0;
              c8_h_m_t = (ptrdiff_t)13;
              c8_h_n_t = (ptrdiff_t)13;
              c8_h_k_t = (ptrdiff_t)13;
              c8_h_lda_t = (ptrdiff_t)13;
              c8_h_ldb_t = (ptrdiff_t)13;
              c8_h_ldc_t = (ptrdiff_t)13;
              dgemm(&c8_h_TRANSA1, &c8_h_TRANSB1, &c8_h_m_t, &c8_h_n_t,
                    &c8_h_k_t, &c8_h_alpha1, &c8_c[0], &c8_h_lda_t, &c8_aBuffer
                    [0], &c8_h_ldb_t, &c8_h_beta1, &c8_cBuffer[0], &c8_h_ldc_t);
            }
          } else if (c8_d_cBufferInUse) {
            c8_g_TRANSB1 = 'N';
            c8_g_TRANSA1 = 'N';
            c8_g_alpha1 = 1.0;
            c8_g_beta1 = 0.0;
            c8_g_m_t = (ptrdiff_t)13;
            c8_g_n_t = (ptrdiff_t)13;
            c8_g_k_t = (ptrdiff_t)13;
            c8_g_lda_t = (ptrdiff_t)13;
            c8_g_ldb_t = (ptrdiff_t)13;
            c8_g_ldc_t = (ptrdiff_t)13;
            dgemm(&c8_g_TRANSA1, &c8_g_TRANSB1, &c8_g_m_t, &c8_g_n_t, &c8_g_k_t,
                  &c8_g_alpha1, &c8_cBuffer[0], &c8_g_lda_t, &c8_b_a[0],
                  &c8_g_ldb_t, &c8_g_beta1, &c8_c[0], &c8_g_ldc_t);
          } else {
            c8_f_TRANSB1 = 'N';
            c8_f_TRANSA1 = 'N';
            c8_f_alpha1 = 1.0;
            c8_f_beta1 = 0.0;
            c8_f_m_t = (ptrdiff_t)13;
            c8_f_n_t = (ptrdiff_t)13;
            c8_f_k_t = (ptrdiff_t)13;
            c8_f_lda_t = (ptrdiff_t)13;
            c8_f_ldb_t = (ptrdiff_t)13;
            c8_f_ldc_t = (ptrdiff_t)13;
            dgemm(&c8_f_TRANSA1, &c8_f_TRANSB1, &c8_f_m_t, &c8_f_n_t, &c8_f_k_t,
                  &c8_f_alpha1, &c8_c[0], &c8_f_lda_t, &c8_b_a[0], &c8_f_ldb_t,
                  &c8_f_beta1, &c8_cBuffer[0], &c8_f_ldc_t);
          }

          c8_d_cBufferInUse = !c8_d_cBufferInUse;
          c8_b_cBufferInUse = c8_d_cBufferInUse;
        }
      }

      c8_n >>= 1;
      c8_b_st.site = &c8_q_emlrtRSI;
      c8_c_aBufferInUse = c8_aBufferInUse;
      c8_f_aBufferInUse = c8_c_aBufferInUse;
      if (c8_f_aBufferInUse) {
        c8_e_TRANSB1 = 'N';
        c8_e_TRANSA1 = 'N';
        c8_e_alpha1 = 1.0;
        c8_e_beta1 = 0.0;
        c8_e_m_t = (ptrdiff_t)13;
        c8_e_n_t = (ptrdiff_t)13;
        c8_e_k_t = (ptrdiff_t)13;
        c8_e_lda_t = (ptrdiff_t)13;
        c8_e_ldb_t = (ptrdiff_t)13;
        c8_e_ldc_t = (ptrdiff_t)13;
        dgemm(&c8_e_TRANSA1, &c8_e_TRANSB1, &c8_e_m_t, &c8_e_n_t, &c8_e_k_t,
              &c8_e_alpha1, &c8_aBuffer[0], &c8_e_lda_t, &c8_aBuffer[0],
              &c8_e_ldb_t, &c8_e_beta1, &c8_b_a[0], &c8_e_ldc_t);
      } else {
        c8_d_TRANSB1 = 'N';
        c8_d_TRANSA1 = 'N';
        c8_d_alpha1 = 1.0;
        c8_d_beta1 = 0.0;
        c8_d_m_t = (ptrdiff_t)13;
        c8_d_n_t = (ptrdiff_t)13;
        c8_d_k_t = (ptrdiff_t)13;
        c8_d_lda_t = (ptrdiff_t)13;
        c8_d_ldb_t = (ptrdiff_t)13;
        c8_d_ldc_t = (ptrdiff_t)13;
        dgemm(&c8_d_TRANSA1, &c8_d_TRANSB1, &c8_d_m_t, &c8_d_n_t, &c8_d_k_t,
              &c8_d_alpha1, &c8_b_a[0], &c8_d_lda_t, &c8_b_a[0], &c8_d_ldb_t,
              &c8_d_beta1, &c8_aBuffer[0], &c8_d_ldc_t);
      }

      c8_f_aBufferInUse = !c8_f_aBufferInUse;
      c8_aBufferInUse = c8_f_aBufferInUse;
    }

    if (c8_first) {
      if (c8_aBufferInUse) {
        for (c8_i5 = 0; c8_i5 < 169; c8_i5++) {
          c8_c[c8_i5] = c8_aBuffer[c8_i5];
        }
      } else {
        for (c8_i4 = 0; c8_i4 < 169; c8_i4++) {
          c8_c[c8_i4] = c8_b_a[c8_i4];
        }
      }
    } else {
      c8_b_st.site = &c8_p_emlrtRSI;
      c8_b_aBufferInUse = c8_aBufferInUse;
      if (c8_b_aBufferInUse) {
        c8_c_TRANSB1 = 'N';
        c8_c_TRANSA1 = 'N';
        c8_c_alpha1 = 1.0;
        c8_c_beta1 = 0.0;
        c8_c_m_t = (ptrdiff_t)13;
        c8_c_n_t = (ptrdiff_t)13;
        c8_c_k_t = (ptrdiff_t)13;
        c8_c_lda_t = (ptrdiff_t)13;
        c8_c_ldb_t = (ptrdiff_t)13;
        c8_c_ldc_t = (ptrdiff_t)13;
        dgemm(&c8_c_TRANSA1, &c8_c_TRANSB1, &c8_c_m_t, &c8_c_n_t, &c8_c_k_t,
              &c8_c_alpha1, &c8_cBuffer[0], &c8_c_lda_t, &c8_aBuffer[0],
              &c8_c_ldb_t, &c8_c_beta1, &c8_c[0], &c8_c_ldc_t);
      } else {
        c8_b_TRANSB1 = 'N';
        c8_b_TRANSA1 = 'N';
        c8_b_alpha1 = 1.0;
        c8_b_beta1 = 0.0;
        c8_b_m_t = (ptrdiff_t)13;
        c8_b_n_t = (ptrdiff_t)13;
        c8_b_k_t = (ptrdiff_t)13;
        c8_b_lda_t = (ptrdiff_t)13;
        c8_b_ldb_t = (ptrdiff_t)13;
        c8_b_ldc_t = (ptrdiff_t)13;
        dgemm(&c8_b_TRANSA1, &c8_b_TRANSB1, &c8_b_m_t, &c8_b_n_t, &c8_b_k_t,
              &c8_b_alpha1, &c8_cBuffer[0], &c8_b_lda_t, &c8_b_a[0], &c8_b_ldb_t,
              &c8_b_beta1, &c8_c[0], &c8_b_ldc_t);
      }
    }
  }
}

static void c8_check_forloop_overflow_error(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp)
{
  const mxArray *c8_y = NULL;
  static char_T c8_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  static char_T c8_cv1[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c8_sp, "error", 0U, 2U, 14, c8_y, 14, sf_mex_call(c8_sp,
    "getString", 1U, 1U, 14, sf_mex_call(c8_sp, "message", 1U, 2U, 14, c8_b_y,
    14, c8_c_y)));
}

static void c8_warning(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp)
{
  const mxArray *c8_y = NULL;
  static char_T c8_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c8_b_y = NULL;
  static char_T c8_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c8_c_y = NULL;
  static char_T c8_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_msgID, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  sf_mex_call(c8_sp, "feval", 0U, 2U, 14, c8_y, 14, sf_mex_call(c8_sp, "feval",
    1U, 2U, 14, c8_b_y, 14, c8_c_y));
}

static void c8_kron(SFc8_CGMRESInstanceStruct *chartInstance, real_T c8_A[16],
                    real_T c8_B[6], real_T c8_K[96])
{
  int32_T c8_kidx;
  int32_T c8_j1;
  int32_T c8_b_j1;
  int32_T c8_j2;
  int32_T c8_b_j2;
  int32_T c8_i1;
  int32_T c8_b_i1;
  int32_T c8_i2;
  int32_T c8_b_i2;
  int32_T c8_a;
  (void)chartInstance;
  c8_kidx = -1;
  for (c8_j1 = 0; c8_j1 < 4; c8_j1++) {
    c8_b_j1 = c8_j1;
    for (c8_j2 = 0; c8_j2 < 2; c8_j2++) {
      c8_b_j2 = c8_j2;
      for (c8_i1 = 0; c8_i1 < 4; c8_i1++) {
        c8_b_i1 = c8_i1;
        for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
          c8_b_i2 = c8_i2;
          c8_a = c8_kidx + 1;
          c8_kidx = c8_a;
          c8_K[c8_kidx] = c8_A[c8_b_i1 + (c8_b_j1 << 2)] * c8_B[c8_b_i2 + 3 *
            c8_b_j2];
        }
      }
    }
  }
}

static void c8_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance, const
  mxArray *c8_c_tau_lev2, const char_T *c8_identifier, real_T c8_y[3])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_c_tau_lev2), &c8_thisId,
                        c8_y);
  sf_mex_destroy(&c8_c_tau_lev2);
}

static void c8_b_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[3])
{
  real_T c8_dv[3];
  int32_T c8_b_i;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_b_i = 0; c8_b_i < 3; c8_b_i++) {
    c8_y[c8_b_i] = c8_dv[c8_b_i];
  }

  sf_mex_destroy(&c8_u);
}

static uint8_T c8_c_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_CGMRES, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_CGMRES), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_CGMRES);
  return c8_y;
}

static uint8_T c8_d_emlrt_marshallIn(SFc8_CGMRESInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_b_u;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b_u, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_b_u;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static const mxArray *c8_chart_data_browse_helper(SFc8_CGMRESInstanceStruct
  *chartInstance, int32_T c8_ssIdNumber)
{
  const mxArray *c8_mxData = NULL;
  real_T c8_d;
  c8_mxData = NULL;
  switch (c8_ssIdNumber) {
   case 34U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_M_bar_inv, 0, 0U, 1U, 0U, 2, 3, 3), false);
    break;

   case 35U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", *chartInstance->c8_J, 0,
      0U, 1U, 0U, 2, 2, 3), false);
    break;

   case 24U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_tau_lev2, 0, 0U, 1U, 0U, 1, 3), false);
    break;

   case 4U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", *chartInstance->c8_z_lev2,
      0, 0U, 1U, 0U, 1, 13), false);
    break;

   case 14U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_Xprime_r_lev2, 0, 0U, 1U, 0U, 1, 9001), false);
    break;

   case 23U:
    c8_d = *chartInstance->c8_i;
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", &c8_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 6U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_P_f2taubar, 0, 0U, 1U, 0U, 2, 12, 20), false);
    break;

   case 11U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_P_f2miubar, 0, 0U, 1U, 0U, 2, 8, 20), false);
    break;

   case 29U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", *chartInstance->c8_K_lev2,
      0, 0U, 1U, 0U, 2, 4, 52), false);
    break;

   case 30U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", *chartInstance->c8_G_lev2,
      0, 0U, 1U, 0U, 2, 52, 4), false);
    break;

   case 31U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", *chartInstance->c8_W_lev2,
      0, 0U, 1U, 0U, 2, 12, 52), false);
    break;

   case 38U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData", *chartInstance->c8_L_lev2,
      0, 0U, 1U, 0U, 2, 12, 20), false);
    break;

   case 32U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_A_z_lev2, 0, 0U, 1U, 0U, 2, 13, 13), false);
    break;

   case 36U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_dTau_lev1, 0, 0U, 1U, 0U, 1, 12), false);
    break;

   case 37U:
    sf_mex_assign(&c8_mxData, sf_mex_create("mxData",
      *chartInstance->c8_b_tau_lev2, 0, 0U, 1U, 0U, 1, 3), false);
    break;
  }

  return c8_mxData;
}

static void c8_emxEnsureCapacity_real_T(SFc8_CGMRESInstanceStruct *chartInstance,
  const emlrtStack *c8_sp, c8_emxArray_real_T *c8_emxArray, int32_T c8_oldNumel,
  const emlrtRTEInfo *c8_srcLocation)
{
  int32_T c8_newNumel;
  int32_T c8_b_i;
  int32_T c8_newCapacity;
  void *c8_newData;
  (void)chartInstance;
  if (c8_oldNumel < 0) {
    c8_oldNumel = 0;
  }

  c8_newNumel = 1;
  for (c8_b_i = 0; c8_b_i < c8_emxArray->numDimensions; c8_b_i++) {
    c8_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c8_newNumel, (uint32_T)
      c8_emxArray->size[c8_b_i], c8_srcLocation, c8_sp);
  }

  if (c8_newNumel > c8_emxArray->allocatedSize) {
    c8_newCapacity = c8_emxArray->allocatedSize;
    if (c8_newCapacity < 16) {
      c8_newCapacity = 16;
    }

    while (c8_newCapacity < c8_newNumel) {
      if (c8_newCapacity > 1073741823) {
        c8_newCapacity = MAX_int32_T;
      } else {
        c8_newCapacity <<= 1;
      }
    }

    c8_newData = emlrtCallocMex((uint32_T)c8_newCapacity, sizeof(real_T));
    if (c8_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
    }

    if (c8_emxArray->data != NULL) {
      memcpy(c8_newData, c8_emxArray->data, sizeof(real_T) * (uint32_T)
             c8_oldNumel);
      if (c8_emxArray->canFreeData) {
        emlrtFreeMex(c8_emxArray->data);
      }
    }

    c8_emxArray->data = (real_T *)c8_newData;
    c8_emxArray->allocatedSize = c8_newCapacity;
    c8_emxArray->canFreeData = true;
  }
}

static void c8_emxEnsureCapacity_int32_T(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_emxArray_int32_T *c8_emxArray,
  int32_T c8_oldNumel, const emlrtRTEInfo *c8_srcLocation)
{
  int32_T c8_newNumel;
  int32_T c8_b_i;
  int32_T c8_newCapacity;
  void *c8_newData;
  (void)chartInstance;
  if (c8_oldNumel < 0) {
    c8_oldNumel = 0;
  }

  c8_newNumel = 1;
  for (c8_b_i = 0; c8_b_i < c8_emxArray->numDimensions; c8_b_i++) {
    c8_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c8_newNumel, (uint32_T)
      c8_emxArray->size[c8_b_i], c8_srcLocation, c8_sp);
  }

  if (c8_newNumel > c8_emxArray->allocatedSize) {
    c8_newCapacity = c8_emxArray->allocatedSize;
    if (c8_newCapacity < 16) {
      c8_newCapacity = 16;
    }

    while (c8_newCapacity < c8_newNumel) {
      if (c8_newCapacity > 1073741823) {
        c8_newCapacity = MAX_int32_T;
      } else {
        c8_newCapacity <<= 1;
      }
    }

    c8_newData = emlrtCallocMex((uint32_T)c8_newCapacity, sizeof(int32_T));
    if (c8_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
    }

    if (c8_emxArray->data != NULL) {
      memcpy(c8_newData, c8_emxArray->data, sizeof(int32_T) * (uint32_T)
             c8_oldNumel);
      if (c8_emxArray->canFreeData) {
        emlrtFreeMex(c8_emxArray->data);
      }
    }

    c8_emxArray->data = (int32_T *)c8_newData;
    c8_emxArray->allocatedSize = c8_newCapacity;
    c8_emxArray->canFreeData = true;
  }
}

static void c8_emxInit_real_T(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, c8_emxArray_real_T **c8_pEmxArray, int32_T c8_numDimensions,
  const emlrtRTEInfo *c8_srcLocation)
{
  c8_emxArray_real_T *c8_emxArray;
  int32_T c8_b_i;
  (void)chartInstance;
  *c8_pEmxArray = (c8_emxArray_real_T *)emlrtMallocMex(sizeof(c8_emxArray_real_T));
  if ((void *)*c8_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
  }

  c8_emxArray = *c8_pEmxArray;
  c8_emxArray->data = (real_T *)NULL;
  c8_emxArray->numDimensions = c8_numDimensions;
  c8_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c8_numDimensions);
  if ((void *)c8_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
  }

  c8_emxArray->allocatedSize = 0;
  c8_emxArray->canFreeData = true;
  for (c8_b_i = 0; c8_b_i < c8_numDimensions; c8_b_i++) {
    c8_emxArray->size[c8_b_i] = 0;
  }
}

static void c8_emxInitStruct_coder_internal_sp(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_coder_internal_sparse *c8_pStruct,
  const emlrtRTEInfo *c8_srcLocation)
{
  c8_emxInit_real_T(chartInstance, c8_sp, &c8_pStruct->d, 1, c8_srcLocation);
  c8_emxInit_int32_T(chartInstance, c8_sp, &c8_pStruct->colidx, 1,
                     c8_srcLocation);
  c8_emxInit_int32_T(chartInstance, c8_sp, &c8_pStruct->rowidx, 1,
                     c8_srcLocation);
}

static void c8_emxInit_int32_T(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, c8_emxArray_int32_T **c8_pEmxArray, int32_T
  c8_numDimensions, const emlrtRTEInfo *c8_srcLocation)
{
  c8_emxArray_int32_T *c8_emxArray;
  int32_T c8_b_i;
  (void)chartInstance;
  *c8_pEmxArray = (c8_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c8_emxArray_int32_T));
  if ((void *)*c8_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
  }

  c8_emxArray = *c8_pEmxArray;
  c8_emxArray->data = (int32_T *)NULL;
  c8_emxArray->numDimensions = c8_numDimensions;
  c8_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c8_numDimensions);
  if ((void *)c8_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
  }

  c8_emxArray->allocatedSize = 0;
  c8_emxArray->canFreeData = true;
  for (c8_b_i = 0; c8_b_i < c8_numDimensions; c8_b_i++) {
    c8_emxArray->size[c8_b_i] = 0;
  }
}

static void c8_emxFree_real_T(SFc8_CGMRESInstanceStruct *chartInstance,
  c8_emxArray_real_T **c8_pEmxArray)
{
  (void)chartInstance;
  if (*c8_pEmxArray != (c8_emxArray_real_T *)NULL) {
    if (((*c8_pEmxArray)->data != (real_T *)NULL) && (*c8_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c8_pEmxArray)->data);
    }

    emlrtFreeMex((*c8_pEmxArray)->size);
    emlrtFreeMex(*c8_pEmxArray);
    *c8_pEmxArray = (c8_emxArray_real_T *)NULL;
  }
}

static void c8_emxFreeStruct_coder_internal_sp(SFc8_CGMRESInstanceStruct
  *chartInstance, c8_coder_internal_sparse *c8_pStruct)
{
  c8_emxFree_real_T(chartInstance, &c8_pStruct->d);
  c8_emxFree_int32_T(chartInstance, &c8_pStruct->colidx);
  c8_emxFree_int32_T(chartInstance, &c8_pStruct->rowidx);
}

static void c8_emxFree_int32_T(SFc8_CGMRESInstanceStruct *chartInstance,
  c8_emxArray_int32_T **c8_pEmxArray)
{
  (void)chartInstance;
  if (*c8_pEmxArray != (c8_emxArray_int32_T *)NULL) {
    if (((*c8_pEmxArray)->data != (int32_T *)NULL) && (*c8_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c8_pEmxArray)->data);
    }

    emlrtFreeMex((*c8_pEmxArray)->size);
    emlrtFreeMex(*c8_pEmxArray);
    *c8_pEmxArray = (c8_emxArray_int32_T *)NULL;
  }
}

static void c8_emxEnsureCapacity_real_T1(SFc8_CGMRESInstanceStruct
  *chartInstance, const emlrtStack *c8_sp, c8_emxArray_real_T *c8_emxArray,
  int32_T c8_oldNumel, const emlrtRTEInfo *c8_srcLocation)
{
  int32_T c8_newNumel;
  int32_T c8_b_i;
  int32_T c8_newCapacity;
  void *c8_newData;
  (void)chartInstance;
  if (c8_oldNumel < 0) {
    c8_oldNumel = 0;
  }

  c8_newNumel = 1;
  for (c8_b_i = 0; c8_b_i < c8_emxArray->numDimensions; c8_b_i++) {
    c8_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c8_newNumel, (uint32_T)
      c8_emxArray->size[c8_b_i], c8_srcLocation, c8_sp);
  }

  if (c8_newNumel > c8_emxArray->allocatedSize) {
    c8_newCapacity = c8_emxArray->allocatedSize;
    if (c8_newCapacity < 16) {
      c8_newCapacity = 16;
    }

    while (c8_newCapacity < c8_newNumel) {
      if (c8_newCapacity > 1073741823) {
        c8_newCapacity = MAX_int32_T;
      } else {
        c8_newCapacity <<= 1;
      }
    }

    c8_newData = emlrtCallocMex((uint32_T)c8_newCapacity, sizeof(real_T));
    if (c8_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
    }

    if (c8_emxArray->data != NULL) {
      memcpy(c8_newData, c8_emxArray->data, sizeof(real_T) * (uint32_T)
             c8_oldNumel);
      if (c8_emxArray->canFreeData) {
        emlrtFreeMex(c8_emxArray->data);
      }
    }

    c8_emxArray->data = (real_T *)c8_newData;
    c8_emxArray->allocatedSize = c8_newCapacity;
    c8_emxArray->canFreeData = true;
  }
}

static void c8_emxInit_real_T1(SFc8_CGMRESInstanceStruct *chartInstance, const
  emlrtStack *c8_sp, c8_emxArray_real_T **c8_pEmxArray, int32_T c8_numDimensions,
  const emlrtRTEInfo *c8_srcLocation)
{
  c8_emxArray_real_T *c8_emxArray;
  int32_T c8_b_i;
  (void)chartInstance;
  *c8_pEmxArray = (c8_emxArray_real_T *)emlrtMallocMex(sizeof(c8_emxArray_real_T));
  if ((void *)*c8_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
  }

  c8_emxArray = *c8_pEmxArray;
  c8_emxArray->data = (real_T *)NULL;
  c8_emxArray->numDimensions = c8_numDimensions;
  c8_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c8_numDimensions);
  if ((void *)c8_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c8_srcLocation, c8_sp);
  }

  c8_emxArray->allocatedSize = 0;
  c8_emxArray->canFreeData = true;
  for (c8_b_i = 0; c8_b_i < c8_numDimensions; c8_b_i++) {
    c8_emxArray->size[c8_b_i] = 0;
  }
}

static int32_T c8__s32_minus__(SFc8_CGMRESInstanceStruct *chartInstance, int32_T
  c8_b, int32_T c8_c, int32_T c8_EMLOvCount_src_loc, uint32_T c8_ssid_src_loc,
  int32_T c8_offset_src_loc, int32_T c8_length_src_loc)
{
  int32_T c8_a;
  (void)c8_EMLOvCount_src_loc;
  c8_a = c8_b - c8_c;
  if (((c8_b ^ c8_a) & (c8_b ^ c8_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c8_ssid_src_loc, c8_offset_src_loc,
      c8_length_src_loc);
  }

  return c8_a;
}

static int32_T c8__s32_add__(SFc8_CGMRESInstanceStruct *chartInstance, int32_T
  c8_b, int32_T c8_c, int32_T c8_EMLOvCount_src_loc, uint32_T c8_ssid_src_loc,
  int32_T c8_offset_src_loc, int32_T c8_length_src_loc)
{
  int32_T c8_a;
  (void)c8_EMLOvCount_src_loc;
  c8_a = c8_b + c8_c;
  if (((c8_a ^ c8_b) & (c8_a ^ c8_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c8_ssid_src_loc, c8_offset_src_loc,
      c8_length_src_loc);
  }

  return c8_a;
}

static int32_T c8__s32_s64_(SFc8_CGMRESInstanceStruct *chartInstance, int64_T
  c8_b, int32_T c8_EMLOvCount_src_loc, uint32_T c8_ssid_src_loc, int32_T
  c8_offset_src_loc, int32_T c8_length_src_loc)
{
  int32_T c8_a;
  (void)c8_EMLOvCount_src_loc;
  c8_a = (int32_T)c8_b;
  if ((int64_T)c8_a != c8_b) {
    sf_data_overflow_error(chartInstance->S, c8_ssid_src_loc, c8_offset_src_loc,
      c8_length_src_loc);
  }

  return c8_a;
}

static void init_dsm_address_info(SFc8_CGMRESInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc8_CGMRESInstanceStruct *chartInstance)
{
  chartInstance->c8_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c8_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c8_M_bar_inv = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_J = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_tau_lev2 = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_z_lev2 = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c8_Xprime_r_lev2 = (real_T (*)[9001])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c8_i = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c8_P_f2taubar = (real_T (*)[240])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c8_P_f2miubar = (real_T (*)[160])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c8_K_lev2 = (real_T (*)[208])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c8_G_lev2 = (real_T (*)[208])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c8_W_lev2 = (real_T (*)[624])ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c8_L_lev2 = (real_T (*)[240])ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c8_A_z_lev2 = (real_T (*)[169])ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c8_dTau_lev1 = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c8_b_tau_lev2 = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c8_CGMRES_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1358664915U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(626504719U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2756110239U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3379412611U);
}

mxArray *sf_c8_CGMRES_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,3);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 2, mxCreateString("coder.internal.CXSparseAPI"));
  return(mxcell3p);
}

mxArray *sf_c8_CGMRES_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_functions");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("CXSparseAPI_passToCX");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c8_CGMRES_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_CGMRES(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Fg7o+lmw6OdA0i8A5ZcklsbnpJYZ8UHFKXOHgg"
    "Nl+iH2exDwhzCaP0D8zOL4xOSSzLLU+GSLeGd33yDXYLh5IAAAUdoZWg=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_CGMRES_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sAmtGVl4AQnR0Xa5NRykdqF";
}

static void sf_opaque_initialize_c8_CGMRES(void *chartInstanceVar)
{
  initialize_params_c8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
  initialize_c8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_CGMRES(void *chartInstanceVar)
{
  enable_c8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_CGMRES(void *chartInstanceVar)
{
  disable_c8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_CGMRES(void *chartInstanceVar)
{
  sf_gateway_c8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_CGMRES(SimStruct* S)
{
  return get_sim_state_c8_CGMRES((SFc8_CGMRESInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_CGMRES(SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_CGMRES((SFc8_CGMRESInstanceStruct*)sf_get_chart_instance_ptr
    (S), st);
}

static void sf_opaque_terminate_c8_CGMRES(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_CGMRESInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CGMRES_optimization_info();
    }

    finalize_c8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_CGMRES((SFc8_CGMRESInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_CGMRES(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_CGMRES((SFc8_CGMRESInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc8_CGMRES((SFc8_CGMRESInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c8_CGMRES_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [16] = {
    "eNrtVt1OE0EU3jZIIEEkIdEbL7gxekmMJtwYC/3BJi0gC+hdM+yediednVnmp8BT6Bto4o0v4Tu",
    "ZeKGXntm2tGx3t5QGEhMnmW5n+51vvvMzZ+oU6k0HxyrOz48cZxGfSziLTn88GKwLY7P/fsF5Pl",
    "h/QxA34QGRJFRO7uAkhENQghlNBa/ztkiFUd4GCdxDbCSkzmJTNDSM8m7NcM/yqQ8B9QI3EIb5O",
    "2hL/H3OLpEtMvoAeSpUgqdrAL4OpDCdoMZI50qx1OflALyuMmGeCwq0ayIrSzUN0zRiUL0Ar86V",
    "JqhYjbS5mmgo64tMN62nyh0CRRgxSniqtwFRLkQYYA3HkY+f+0ajU0mYFxCpdyAgPVAN2o05BYc",
    "kJ1X4wynlRAtJCauGrGwNJ7UdMNTTFD6wnICgth0JpBsJynV2/t0aelrl5JRBBU5NJ5vNhTNjk3",
    "9C4RxkZtzaZdEDSTqwzzM3jQNSvYizdVUlkzBNQzghctvD/CnwM6sXK0e5BPMER2iRBYPYybo6k",
    "rSH4c1kM2HdVua0I2PCfrLVNFjMVu1BXhau2GoeLxPGVCbsSEQN6AGLWStEk3xYnzUdF0kRkQ5W",
    "rY9BtiVeFtynE7nwjNIiLGO5VRqNPewU6eJGsDrXINvEg7Rzq7wAfMMAHcXOpOPtUkh9qmy2pqA",
    "GOZ2GclTb8Mq5kF10NOfYj1ywOcgEhqqD0cfaPVZY5nkwG/2puGGf33RGfX7lBn1+aJd8vhjjKa",
    "TwOGNPiy+N4ZeL1/GriX2Lw3fXxiTPw8S+Cwkei1vD+fvLDnx98+vHxrPHp5+WjkrJOCT1FCb0F",
    "OLv1u57cbZ7cujb02FDuirX3kSVWOy7MV0LKfxPxvjXBmu1HerdE/Zq+z0/3PxIXu8dXnb9s1rM",
    "96eQr7eY0Dt8v2E742UU9zklvbo/uMDtmpj+tWb5t8b0Lk6Jx/LgfX/8fDuf/VYpaZ8Wr6VEvOx",
    "aE9Ni0Hs5Xs+317FRms/+ZnlfT/ixHt+DLYK3Wg9a3larvNs8rLoT5/S2dT6rnXPPdv+Kzv9xuX",
    "v/Vm7Yh29jV5jz3rwvu3n9m/U+nxW/mdPfnAR+bY597ho/7/+gWfB/AeOzXXk=",
    ""
  };

  static char newstr [1113] = "";
  newstr[0] = '\0';
  for (i = 0; i < 16; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c8_CGMRES(SimStruct *S)
{
  const char* newstr = sf_c8_CGMRES_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1698865143U));
  ssSetChecksum1(S,(3186834848U));
  ssSetChecksum2(S,(1645618464U));
  ssSetChecksum3(S,(1079249039U));
}

static void mdlRTW_c8_CGMRES(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_CGMRES(SimStruct *S)
{
  SFc8_CGMRESInstanceStruct *chartInstance;
  chartInstance = (SFc8_CGMRESInstanceStruct *)utMalloc(sizeof
    (SFc8_CGMRESInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc8_CGMRESInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_CGMRES;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_CGMRES;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_CGMRES;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_CGMRES;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_CGMRES;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_CGMRES;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_CGMRES;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_CGMRES;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_CGMRES;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_CGMRES;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_CGMRES;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c8_JITStateAnimation,
    chartInstance->c8_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_start_c8_CGMRES(chartInstance);
}

void c8_CGMRES_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_CGMRES(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_CGMRES(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_CGMRES(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_CGMRES_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
