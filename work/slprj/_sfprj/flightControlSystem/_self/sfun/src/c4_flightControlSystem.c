/* Include files */

#include "flightControlSystem_sfun.h"
#include "c4_flightControlSystem.h"
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

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c4_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 28,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c4_g_emlrtMCI = { 53,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtMCInfo c4_h_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c4_i_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c4_j_emlrtMCI = { 21,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtMCInfo c4_k_emlrtMCI = { 225,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtMCInfo c4_l_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtMCInfo c4_m_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c4_n_emlrtMCI = { 296,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c4_o_emlrtMCI = { 386,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtMCInfo c4_p_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c4_q_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonempty.m"/* pName */
};

static emlrtMCInfo c4_r_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatencols.m"/* pName */
};

static emlrtMCInfo c4_s_emlrtMCI = { 72,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtMCInfo c4_t_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtMCInfo c4_u_emlrtMCI = { 90,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c4_v_emlrtMCI = { 198,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 10, /* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2741"          /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 16,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2741"          /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 17,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2741"          /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 205,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 115,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 127,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 814,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 888,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 962,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 990,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 1002,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 163,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 164,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 33,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 43,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 51,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 69,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 24,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 28,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 31,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 78,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 139,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 184,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 132,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 249,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 248,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 247,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 125,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 328,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 150,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_lb_emlrtRSI = { 29,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 34,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_nb_emlrtRSI = { 35,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 36,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI = { 60,/* lineNo */
  "medfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\medfilt2.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI = { 155,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI = { 179,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI = { 66,/* lineNo */
  "imhmax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\imhmax.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI = { 10,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_xb_emlrtRSI = { 14,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_yb_emlrtRSI = { 78,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_ac_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c4_bc_emlrtRSI = { 14,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c4_cc_emlrtRSI = { 33,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c4_dc_emlrtRSI = { 35,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c4_ec_emlrtRSI = { 41,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_fc_emlrtRSI = { 107,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_gc_emlrtRSI = { 109,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_hc_emlrtRSI = { 314,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ic_emlrtRSI = { 316,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_jc_emlrtRSI = { 378,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_kc_emlrtRSI = { 26,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_lc_emlrtRSI = { 101,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_mc_emlrtRSI = { 100,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_nc_emlrtRSI = { 93,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_oc_emlrtRSI = { 85,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_pc_emlrtRSI = { 84,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_qc_emlrtRSI = { 83,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_rc_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_sc_emlrtRSI = { 58,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_tc_emlrtRSI = { 39,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_uc_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_vc_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_wc_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_xc_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_yc_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_ad_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo c4_bd_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo c4_cd_emlrtRSI = { 86,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c4_dd_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c4_ed_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_fd_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_gd_emlrtRSI = { 57,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_hd_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_id_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_jd_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c4_kd_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pathName */
};

static emlrtRSInfo c4_ld_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c4_md_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo c4_nd_emlrtRSI = { 100,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c4_od_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c4_pd_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c4_qd_emlrtRSI = { 34,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_rd_emlrtRSI = { 145,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_sd_emlrtRSI = { 1511,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_td_emlrtRSI = { 1696,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ud_emlrtRSI = { 2068,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_vd_emlrtRSI = { 485,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_wd_emlrtRSI = { 1364,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_xd_emlrtRSI = { 1367,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_yd_emlrtRSI = { 1372,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ae_emlrtRSI = { 1381,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_be_emlrtRSI = { 999,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ce_emlrtRSI = { 1001,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_de_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c4_ee_emlrtRSI = { 39,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c4_fe_emlrtRSI = { 65,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c4_ge_emlrtRSI = { 1350,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c4_he_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_ie_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_je_emlrtRSI = { 273,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_ke_emlrtRSI = { 274,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_le_emlrtRSI = { 16,/* lineNo */
  "round",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pathName */
};

static emlrtRSInfo c4_me_emlrtRSI = { 38,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c4_ne_emlrtRSI = { 37,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo c4_oe_emlrtRSI = { 72,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c4_pe_emlrtRSI = { 104,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_qe_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_re_emlrtRSI = { 301,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_se_emlrtRSI = { 309,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_te_emlrtRSI = { 310,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ue_emlrtRSI = { 318,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ve_emlrtRSI = { 326,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_we_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_xe_emlrtRSI = { 381,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ye_emlrtRSI = { 409,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_af_emlrtRSI = { 416,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_bf_emlrtRSI = { 576,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_cf_emlrtRSI = { 578,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_df_emlrtRSI = { 606,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ef_emlrtRSI = { 488,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ff_emlrtRSI = { 495,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_gf_emlrtRSI = { 496,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_hf_emlrtRSI = { 503,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_if_emlrtRSI = { 550,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_jf_emlrtRSI = { 519,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_kf_emlrtRSI = { 347,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_lf_emlrtRSI = { 356,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_mf_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_nf_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_of_emlrtRSI = { 376,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_pf_emlrtRSI = { 396,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c4_qf_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c4_rf_emlrtRSI = { 6,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_sf_emlrtRSI = { 14,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_tf_emlrtRSI = { 16,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_uf_emlrtRSI = { 32,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_vf_emlrtRSI = { 35,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_wf_emlrtRSI = { 44,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_xf_emlrtRSI = { 72,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_yf_emlrtRSI = { 73,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c4_ag_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\all.m"/* pathName */
};

static emlrtRSInfo c4_bg_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c4_cg_emlrtRSI = { 9,/* lineNo */
  "angle",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\angle.m"/* pathName */
};

static emlrtRSInfo c4_dg_emlrtRSI = { 79,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_eg_emlrtRSI = { 10,/* lineNo */
  "exp",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m"/* pathName */
};

static emlrtRSInfo c4_fg_emlrtRSI = { 17,/* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo c4_gg_emlrtRSI = { 58,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_hg_emlrtRSI = { 97,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_ig_emlrtRSI = { 288,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_jg_emlrtRSI = { 381,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_kg_emlrtRSI = { 449,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_lg_emlrtRSI = { 533,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_mg_emlrtRSI = { 18,/* lineNo */
  "ifWhileCond",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ifWhileCond.m"/* pathName */
};

static emlrtRSInfo c4_ng_emlrtRSI = { 31,/* lineNo */
  "ifWhileCond",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ifWhileCond.m"/* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 523,/* lineNo */
  21,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 525,/* lineNo */
  5,                                   /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "max",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 17,/* lineNo */
  8,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741"          /* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 18,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741"          /* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI = { 43,/* lineNo */
  6,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI = { 43,/* lineNo */
  15,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_l_emlrtRTEI = { 51,/* lineNo */
  21,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI = { 363,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_n_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI = { 72,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI = { 14,/* lineNo */
  62,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI = { 14,/* lineNo */
  82,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI = { 30,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI = { 69,/* lineNo */
  21,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI = { 57,/* lineNo */
  9,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI = { 58,/* lineNo */
  9,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_hb_emlrtRTEI = { 320,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c4_ib_emlrtRTEI = { 78,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_jb_emlrtRTEI = { 79,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_kb_emlrtRTEI = { 80,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_lb_emlrtRTEI = { 81,/* lineNo */
  33,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_mb_emlrtRTEI = { 93,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_nb_emlrtRTEI = { 94,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ob_emlrtRTEI = { 96,/* lineNo */
  24,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_pb_emlrtRTEI = { 97,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_qb_emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_rb_emlrtRTEI = { 123,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_sb_emlrtRTEI = { 124,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_tb_emlrtRTEI = { 125,/* lineNo */
  28,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ub_emlrtRTEI = { 189,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_vb_emlrtRTEI = { 191,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_wb_emlrtRTEI = { 247,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_xb_emlrtRTEI = { 248,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_yb_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_ac_emlrtRTEI = { 35,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_bc_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_cc_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_dc_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ec_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_fc_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_gc_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c4_hc_emlrtRTEI = { 53,/* lineNo */
  44,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ic_emlrtRTEI = { 53,/* lineNo */
  64,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_jc_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_kc_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_lc_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_mc_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo c4_nc_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_oc_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_pc_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_qc_emlrtRTEI = { 37,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c4_rc_emlrtRTEI = { 1511,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_sc_emlrtRTEI = { 1968,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_tc_emlrtRTEI = { 1972,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_uc_emlrtRTEI = { 1991,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_vc_emlrtRTEI = { 1995,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_wc_emlrtRTEI = { 2012,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_xc_emlrtRTEI = { 2063,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_yc_emlrtRTEI = { 109,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ad_emlrtRTEI = { 477,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_bd_emlrtRTEI = { 478,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_cd_emlrtRTEI = { 17,/* lineNo */
  25,                                  /* colNo */
  "cumop",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pName */
};

static emlrtRTEInfo c4_dd_emlrtRTEI = { 485,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ed_emlrtRTEI = { 314,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_fd_emlrtRTEI = { 998,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_gd_emlrtRTEI = { 1003,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_hd_emlrtRTEI = { 999,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_id_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_jd_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_kd_emlrtRTEI = { 80,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_ld_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_md_emlrtRTEI = { 1001,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_nd_emlrtRTEI = { 1349,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_od_emlrtRTEI = { 1349,/* lineNo */
  47,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_pd_emlrtRTEI = { 1350,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_qd_emlrtRTEI = { 1351,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_rd_emlrtRTEI = { 1371,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_sd_emlrtRTEI = { 1381,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_td_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_ud_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_vd_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_wd_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_xd_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_yd_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_ae_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_be_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_ce_emlrtRTEI = { 53,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_de_emlrtRTEI = { 69,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_ee_emlrtRTEI = { 83,/* lineNo */
  32,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_fe_emlrtRTEI = { 84,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_ge_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_he_emlrtRTEI = { 100,/* lineNo */
  23,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_ie_emlrtRTEI = { 101,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_je_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_ke_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_le_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_me_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_ne_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_oe_emlrtRTEI = { 26,/* lineNo */
  20,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_pe_emlrtRTEI = { 26,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_qe_emlrtRTEI = { 26,/* lineNo */
  54,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_re_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pName */
};

static emlrtRTEInfo c4_se_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c4_te_emlrtRTEI = { 98,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c4_ue_emlrtRTEI = { 153,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c4_ve_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_we_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_xe_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_ye_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "round",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pName */
};

static emlrtRTEInfo c4_af_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c4_bf_emlrtRTEI = { 561,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_cf_emlrtRTEI = { 471,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_df_emlrtRTEI = { 509,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_ef_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_ff_emlrtRTEI = { 296,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_gf_emlrtRTEI = { 298,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_hf_emlrtRTEI = { 10,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741"          /* pName */
};

static emlrtRTEInfo c4_if_emlrtRTEI = { 10,/* lineNo */
  14,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741"          /* pName */
};

static emlrtRTEInfo c4_jf_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_kf_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c4_lf_emlrtRTEI = { 14,/* lineNo */
  76,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c4_mf_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_nf_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_of_emlrtRTEI = { 81,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_pf_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_qf_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_rf_emlrtRTEI = { 96,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_sf_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_tf_emlrtRTEI = { 123,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_uf_emlrtRTEI = { 124,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_vf_emlrtRTEI = { 125,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_wf_emlrtRTEI = { 78,/* lineNo */
  17,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_xf_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_yf_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ag_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_bg_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_cg_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_dg_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_eg_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_fg_emlrtRTEI = { 35,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_gg_emlrtRTEI = { 109,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_hg_emlrtRTEI = { 1947,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ig_emlrtRTEI = { 402,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_jg_emlrtRTEI = { 415,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_kg_emlrtRTEI = { 416,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_lg_emlrtRTEI = { 999,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_mg_emlrtRTEI = { 998,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ng_emlrtRTEI = { 1001,/* lineNo */
  34,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c4_og_emlrtRTEI = { 68,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c4_pg_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_qg_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_rg_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_sg_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_tg_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_ug_emlrtRTEI = { 114,/* lineNo */
  55,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_vg_emlrtRTEI = { 298,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  33,                                  /* colNo */
  "centers",                           /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI = { 18, /* lineNo */
  33,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  42,                                  /* colNo */
  "centersStrong",                     /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  34,                                  /* colNo */
  "centersStrong",                     /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2741",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  156,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_l_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c4_wg_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtBCInfo c4_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  110,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  110,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ob_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  84,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_emlrtECI = { -1, /* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c4_xg_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtBCInfo c4_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fc_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1373,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1381,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_b_emlrtECI = { 1,/* nDims */
  1381,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo c4_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1385,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2124,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2126,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2127,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1001,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1003,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1349,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2127,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  68,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wc_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  1352,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  314,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  998,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1349,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  999,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1371,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1371,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1350,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1351,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c4_yg_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtBCInfo c4_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_b_emlrtDCI = { 69,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ae_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_be_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_de_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ee_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_he_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ie_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  76,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_te_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI = { 83,/* lineNo */
  38,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI = { 83,/* lineNo */
  38,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_ue_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ve_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_we_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ye_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_af_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_df_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ef_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ff_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_e_emlrtDCI = { 48,/* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_jf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c4_og_emlrtRSI = { 56,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_pg_emlrtRSI = { 40,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_qg_emlrtRSI = { 11,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_rg_emlrtRSI = { 10,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c4_sg_emlrtRSI = { 58,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_tg_emlrtRSI = { 57,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_ug_emlrtRSI = { 53,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_vg_emlrtRSI = { 52,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_wg_emlrtRSI = { 10,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_xg_emlrtRSI = { 9,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_yg_emlrtRSI = { 8,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_ah_emlrtRSI = { 125,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_bh_emlrtRSI = { 37,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c4_ch_emlrtRSI = { 97,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_dh_emlrtRSI = { 26,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c4_eh_emlrtRSI = { 13,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c4_fh_emlrtRSI = { 35,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_gh_emlrtRSI = { 33,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_hh_emlrtRSI = { 124,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_ih_emlrtRSI = { 123,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_jh_emlrtRSI = { 81,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_kh_emlrtRSI = { 80,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_lh_emlrtRSI = { 79,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_mh_emlrtRSI = { 94,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_nh_emlrtRSI = { 93,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_oh_emlrtRSI = { 96,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c4_ph_emlrtRSI = { 98,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static char_T c4_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static int32_T c4_iv[324] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
  35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
  55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
  75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94,
  95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
  112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
  39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
  59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,
  115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130,
  131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
  147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160 };

static creal_T c4_dc = { 0.0,          /* re */
  0.0                                  /* im */
};

static char_T c4_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
  't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a',
  'i', 'l', 'e', 'd' };

static char_T c4_cv2[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o',
  'n', 'N', 'a', 'N' };

static char_T c4_cv3[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
  'x', 's', 'i', 'z', 'e' };

static char_T c4_cv4[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

static char_T c4_cv5[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p',
  'u', 't' };

/* Function Declarations */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_update_jit_animation_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[19200], real32_T c4_b[19200]);
static void c4_b_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[19200], real32_T c4_b[19200]);
static void c4_c_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[19200], real32_T c4_b[19200]);
static void c4_imfindcircles(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200],
  c4_coder_array_real_T_2D *c4_centers, c4_coder_array_real_T_2D *c4_r_estimated,
  c4_coder_array_real_T_2D *c4_metric);
static void c4_chaccum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], creal_T
  c4_c_accumMatrix[19200], real32_T c4_b_gradientImg[19200]);
static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp);
static void c4_eml_find(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_b_x[19200], c4_coder_array_int32_T *c4_i,
  c4_coder_array_int32_T *c4_j);
static void c4_indexShapeCheck(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T
  c4_indexSize[2]);
static void c4_sub2ind(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_varargin_1,
  c4_coder_array_real_T *c4_varargin_2, c4_coder_array_int32_T *c4_idx);
static boolean_T c4_allinrange(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_b_x, int32_T c4_hi);
static void c4_chcenters(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, creal_T c4_varargin_1[19200],
  c4_coder_array_real_T_2D *c4_centers, c4_coder_array_real_T_2D *c4_metric);
static void c4_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_a[19200]);
static void c4_regionprops(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], real_T c4_varargin_2
  [19200], c4_coder_array_sOA5t73y81YtFHGIDxk *c4_outstats);
static void c4_bwconncomp(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200],
  c4_s_8vINxG2sU0DyuufNTJYdGF *c4_CC);
static real_T c4_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_b_x,
  int32_T c4_vlen);
static real_T c4_sumColumnB4(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_b_x, int32_T c4_vstart);
static real_T c4_b_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_b_x,
  int32_T c4_vlen, int32_T c4_vstart);
static void c4_useConstantDim(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_varargin_2,
  int32_T c4_varargin_3, c4_coder_array_int32_T *c4_varargout_1);
static void c4_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_cell_wrap_34 c4_a[1], real_T
                      c4_varargin_2, c4_coder_array_cell_wrap_34_2D *c4_b);
static void c4_assertValidSizeArg(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_varargin_1);
static void c4_ind2sub(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_ndx, c4_coder_array_int32_T
  *c4_varargout_1, c4_coder_array_int32_T *c4_varargout_2);
static real_T c4_sum(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x);
static real_T c4_c_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x,
  int32_T c4_vlen);
static real_T c4_b_sumColumnB4(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_b_x, int32_T c4_vstart);
static real_T c4_d_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x,
  int32_T c4_vlen, int32_T c4_vstart);
static void c4_round(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x,
                     c4_coder_array_real_T *c4_y);
static void c4_sort(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, c4_coder_array_real_T_2D *c4_b_x,
                    c4_coder_array_real_T_2D *c4_c_x, c4_coder_array_int32_T_2D *
                    c4_idx);
static void c4_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, c4_coder_array_int32_T_2D
  *c4_b_idx, c4_coder_array_real_T_2D *c4_c_x);
static void c4_merge_block(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_coder_array_int32_T *c4_iwork, c4_coder_array_real_T
  *c4_xwork, c4_coder_array_int32_T_2D *c4_b_idx, c4_coder_array_real_T_2D
  *c4_c_x, c4_coder_array_int32_T *c4_b_iwork, c4_coder_array_real_T *c4_b_xwork);
static void c4_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
                     c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset,
                     int32_T c4_np, int32_T c4_nq, c4_coder_array_int32_T
                     *c4_iwork, c4_coder_array_real_T *c4_xwork,
                     c4_coder_array_int32_T_2D *c4_b_idx,
                     c4_coder_array_real_T_2D *c4_c_x, c4_coder_array_int32_T
                     *c4_b_iwork, c4_coder_array_real_T *c4_b_xwork);
static boolean_T c4_all(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_boolean_T *c4_b_x);
static real_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_coder_array_real_T_2D *c4_b_x,
                      c4_coder_array_int32_T_2D *c4_idx);
static void c4_b_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset);
static void c4_b_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_coder_array_int32_T *c4_iwork, c4_coder_array_real_T
  *c4_xwork);
static void c4_b_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, int32_T c4_np, int32_T
  c4_nq, c4_coder_array_int32_T *c4_iwork, c4_coder_array_real_T *c4_xwork);
static real_T c4_binary_expand_op(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, emlrtRSInfo c4_in1,
  c4_coder_array_real_T *c4_in2, c4_coder_array_real_T *c4_in3);
static void c4_array_real_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1);
static void c4_array_creal_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_creal_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_boolean_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1);
static void c4_array_int32_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_real_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_boolean_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_real32_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_coder_array_real32_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1);
static void c4_array_creal_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_creal_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1);
static void c4_array_sOA5t73y81YtFHGIDxk0fKF_S
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_coder_array_sOA5t73y81YtFHGIDxk *c4_coderArray, const emlrtRTEInfo
   *c4_srcLocation, int32_T c4_size0);
static void c4_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_coder_array_s_R6Og1x0kmqQXSF9Pw *c4_coderArray, const emlrtRTEInfo
   *c4_srcLocation, int32_T c4_size0);
static void c4_array_real_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray);
static void c4_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_pStruct);
static void c4_array_real_T_2D_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T_2D *c4_coderArray);
static void c4_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_pStruct);
static void c4_array_boolean_T_0x0_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T_0x0 *c4_pArray);
static void c4_array_real_T_Constructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray);
static void c4_array_real_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real_T_2D *c4_coderArray);
static void c4_array_real_T_1x0_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real_T_1x0 *c4_pArray);
static void c4_array_cell_wrap_34_2D_SetSize
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_coder_array_cell_wrap_34_2D *c4_coderArray, const emlrtRTEInfo
   *c4_srcLocation, int32_T c4_size0, int32_T c4_size1);
static void c4_array_cell_wrap_34_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   *c4_pStruct);
static void c4_array_cell_wrap_34_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   *c4_pStruct);
static void c4_array_int32_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1);
static void c4_array_boolean_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T_2D *c4_coderArray);
static void c4_array_int32_T_Constructor(SFc4_flightControlSystemInstanceStruct *
  chartInstance, c4_coder_array_int32_T *c4_coderArray);
static void c4_array_creal_T_Constructor(SFc4_flightControlSystemInstanceStruct *
  chartInstance, c4_coder_array_creal_T *c4_coderArray);
static void c4_array_boolean_T_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T *c4_coderArray);
static void c4_array_boolean_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T_2D *c4_coderArray);
static void c4_array_int32_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray);
static void c4_array_creal_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_creal_T *c4_coderArray);
static void c4_array_boolean_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_boolean_T *c4_coderArray);
static void c4_array_real32_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real32_T_2D *c4_coderArray);
static void c4_array_creal_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_creal_T_2D *c4_coderArray);
static void c4_array_real32_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real32_T_2D *c4_coderArray);
static void c4_array_creal_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_creal_T_2D *c4_coderArray);
static void c4_array_sOA5t73y81YtFHGIDxk0fKF_C
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_sOA5t73y81YtFHGIDxk *c4_coderArray);
static void c4_array_int32_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_int32_T_2D *c4_coderArray);
static void c4_array_sOA5t73y81YtFHGIDxk0fKF_D
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_sOA5t73y81YtFHGIDxk *c4_coderArray);
static void c4_array_int32_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_int32_T_2D *c4_coderArray);
static void c4_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_dst, const
   c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_array_real_T_1x2s_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[2], const real_T c4_src[2]);
static void c4_array_real_T_1x4s_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[4], const real_T c4_src[4]);
static void c4_array_boolean_T_0x0_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T_0x0 *c4_dst,
  const c4_coder_array_boolean_T_0x0 *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_array_boolean_T_0x0_SetSize
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, int32_T c4_size[2], const emlrtRTEInfo *c4_srcLocation, int32_T
   c4_size0, int32_T c4_size1);
static void c4_array_real_T_8x2s_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[16], const real_T c4_src[16]);
static void c4_array_real_T_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_dst, const
  c4_coder_array_real_T *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_array_real_T_2D_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_2D *c4_dst,
  const c4_coder_array_real_T_2D *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_array_real_T_1x0_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_1x0 *c4_dst,
  const c4_coder_array_real_T_1x0 *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_array_real_T_1x0_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_size[2], const
  emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T c4_size1);
static void c4_array_s_8vINxG2sU0DyuufNTJYdGF_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_8vINxG2sU0DyuufNTJYdGF *c4_pStruct);
static void c4_array_cell_wrap_34_2D_Construct
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_34_2D *c4_coderArray);
static void c4_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_s_R6Og1x0kmqQXSF9Pw *c4_coderArray);
static void c4_array_cell_wrap_34_2s_Construct
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[2]);
static void c4_b_array_s_8vINxG2sU0DyuufNTJYdGF_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_8vINxG2sU0DyuufNTJYdGF *c4_pStruct);
static void c4_array_cell_wrap_34_2D_Destructo
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_34_2D *c4_coderArray);
static void c4_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_s_R6Og1x0kmqQXSF9Pw *c4_coderArray);
static void c4_array_cell_wrap_34_2s_Destructo
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[2]);
static void c4_array_cell_wrap_34_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_34 *c4_dst, const
  c4_cell_wrap_34 *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_array_cell_wrap_34_1s_Construct
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[1]);
static void c4_array_cell_wrap_34_1s_Destructo
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[1]);
static int32_T c4_div_nzp_s32(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_numerator, int32_T c4_denominator, int32_T
  c4_EMLOvCount_src_loc, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc,
  int32_T c4_length_src_loc);
static int32_T c4__s32_s64_(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int64_T c4_b, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c4_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_doneDoubleBufferReInit = false;
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c4_postfixPredicateTree[2] = { 0, -1 };

  static const int32_T c4_condTxtEndIdx[1] = { 315 };

  static const int32_T c4_condTxtStartIdx[1] = { 299 };

  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c4_JITStateAnimation[0],
                        &chartInstance->c4_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    60U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 3U, 0U,
                  0U, 0U, 0U, 0U, 1U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "c4_flightControlSystem", 0, -1, 621);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 73, 95, 73, 95,
                    false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 295, 315, -1,
                    617, false);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 367, 386, -1,
                    613, false);
  covrtEmlMCDCInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 298, 315, 1U,
                      0U, &c4_condTxtStartIdx[0], &c4_condTxtEndIdx[0], 2U,
                      &c4_postfixPredicateTree[0], false);
}

static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c4_b_cv[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  c4_coder_array_real_T_2D c4_a__1;
  c4_coder_array_real_T_2D c4_centers;
  c4_coder_array_real_T_2D c4_metric;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_i_st;
  emlrtStack c4_j_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_centersStrong_data[2];
  real_T c4_max_metric_data[1];
  real_T c4_strongest_idx_data[1];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_offset_x;
  real_T c4_b_offset_y;
  real_T c4_b_signal;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d_b;
  real_T c4_e_b;
  int32_T c4_b_iv[2];
  int32_T c4_centersStrong_size[2];
  int32_T c4_idx_size[2];
  int32_T c4_max_metric_size[2];
  int32_T c4_strongest_idx_size[2];
  int32_T c4_x_size[2];
  int32_T c4_idx_data[1];
  int32_T c4_b_b;
  int32_T c4_b_centers;
  int32_T c4_b_i;
  int32_T c4_b_loop_ub;
  int32_T c4_c_b;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_n;
  boolean_T c4_bv[19200];
  boolean_T c4_x_data[1];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b_overflow;
  boolean_T c4_e_y;
  boolean_T c4_exitg1;
  boolean_T c4_h_b;
  boolean_T c4_i_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  c4_i_st.prev = &c4_h_st;
  c4_i_st.tls = c4_h_st.tls;
  c4_j_st.prev = &c4_i_st;
  c4_j_st.tls = c4_i_st.tls;
  if (covrtIsSigCovEnabledFcn(chartInstance->c4_covrtInstance, 0U) != 0U) {
    for (c4_i = 0; c4_i < 19200; c4_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c4_covrtInstance, 0U,
        (real_T)(*chartInstance->c4_image_in)[c4_i]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0, true);
  c4_b_offset_x = 0.0;
  c4_b_offset_y = 0.0;
  c4_b_signal = 0.0;
  c4_array_real_T_2D_Constructor(chartInstance, &c4_centers);
  c4_array_real_T_2D_Constructor(chartInstance, &c4_a__1);
  c4_array_real_T_2D_Constructor(chartInstance, &c4_metric);
  c4_b_st.site = &c4_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_bv[c4_i1] = (*chartInstance->c4_image_in)[c4_i1];
  }

  c4_imfindcircles(chartInstance, &c4_b_st, c4_bv, &c4_centers, &c4_a__1,
                   &c4_metric);
  c4_array_real_T_2D_Destructor(chartInstance, &c4_a__1);
  c4_b = (c4_centers.size[0] == 0);
  c4_b1 = (c4_centers.size[1] == 0);
  if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1, covrtEmlMcdcEval
                     (chartInstance->c4_covrtInstance, 4U, 0, 0,
                      !covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0,
         0, c4_b || c4_b1)))) {
    c4_b_st.site = &c4_b_emlrtRSI;
    c4_c_st.site = &c4_fg_emlrtRSI;
    c4_d_st.site = &c4_gg_emlrtRSI;
    c4_e_st.site = &c4_hg_emlrtRSI;
    c4_b2 = (c4_metric.size[0] == 1);
    c4_b3 = (c4_metric.size[1] == 1);
    if ((c4_b2 && c4_b3) || (c4_metric.size[0] != 1)) {
      c4_b4 = true;
    } else {
      c4_b4 = false;
    }

    if (!c4_b4) {
      c4_y = NULL;
      sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 36),
                    false);
      c4_c_y = NULL;
      sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 36),
                    false);
      sf_mex_call(&c4_e_st, &c4_u_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                  sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_e_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
    }

    if (c4_metric.size[0] < 1) {
      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      sf_mex_call(&c4_e_st, &c4_v_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                  sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_e_st, NULL, "message", 1U, 1U, 14, c4_d_y)));
    }

    c4_f_st.site = &c4_ig_emlrtRSI;
    c4_g_st.site = &c4_jg_emlrtRSI;
    c4_h_st.site = &c4_kg_emlrtRSI;
    c4_m = c4_metric.size[0];
    c4_n = c4_metric.size[1];
    c4_b_iv[1] = c4_n;
    c4_max_metric_size[1] = c4_b_iv[1];
    c4_idx_size[1] = c4_n;
    c4_loop_ub = c4_n - 1;
    for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
      c4_idx_data[0] = 1;
    }

    if (c4_n >= 1) {
      for (c4_j = 0; c4_j < 1; c4_j++) {
        c4_max_metric_data[0] = c4_metric.vector.data[0];
        c4_i_st.site = &c4_lg_emlrtRSI;
        c4_b_b = c4_m;
        c4_c_b = c4_b_b;
        if (c4_c_b < 2) {
          c4_overflow = false;
        } else {
          c4_overflow = (c4_c_b > 2147483646);
        }

        if (c4_overflow) {
          c4_j_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_j_st);
        }

        for (c4_b_i = 2; c4_b_i <= c4_m; c4_b_i++) {
          c4_a = c4_max_metric_data[0];
          c4_d_b = c4_metric.vector.data[c4_b_i - 1];
          c4_b_a = c4_a;
          c4_e_b = c4_d_b;
          c4_b_x = c4_e_b;
          c4_h_b = muDoubleScalarIsNaN(c4_b_x);
          if (c4_h_b) {
            c4_p = false;
          } else {
            c4_c_x = c4_b_a;
            c4_i_b = muDoubleScalarIsNaN(c4_c_x);
            if (c4_i_b) {
              c4_p = true;
            } else {
              c4_p = (c4_b_a < c4_e_b);
            }
          }

          if (c4_p) {
            c4_max_metric_data[0] = c4_metric.vector.data[c4_b_i - 1];
            c4_idx_data[0] = c4_b_i;
          }
        }
      }
    }

    c4_strongest_idx_size[1] = c4_idx_size[1];
    c4_b_loop_ub = c4_idx_size[1] - 1;
    for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
      c4_strongest_idx_data[0] = (real_T)c4_idx_data[0];
    }

    c4_b_st.site = &c4_c_emlrtRSI;
    c4_x_size[1] = c4_max_metric_size[1];
    c4_c_loop_ub = c4_max_metric_size[1] - 1;
    for (c4_i4 = 0; c4_i4 <= c4_c_loop_ub; c4_i4++) {
      c4_x_data[0] = (c4_max_metric_data[0] > 0.3);
    }

    c4_b5 = (c4_x_size[1] == 0);
    c4_e_y = !c4_b5;
    if (c4_e_y) {
      c4_c_st.site = &c4_mg_emlrtRSI;
      c4_e_y = true;
      c4_i5 = c4_x_size[1];
      c4_d_st.site = &c4_ng_emlrtRSI;
      c4_f_b = c4_i5;
      c4_g_b = c4_f_b;
      if (c4_g_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_g_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_e_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      c4_i10 = (uint8_T)c4_i5 - 1;
      c4_k = 0;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_k <= c4_i10)) {
        if (!c4_x_data[0]) {
          c4_e_y = false;
          c4_exitg1 = true;
        } else {
          c4_k++;
        }
      }
    }

    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 2, c4_e_y)) {
      c4_b_centers = c4_centers.size[0];
      c4_centersStrong_size[0] = c4_strongest_idx_size[1];
      c4_centersStrong_size[1] = c4_centers.size[1];
      c4_d_loop_ub = c4_centers.size[1] - 1;
      for (c4_i6 = 0; c4_i6 <= c4_d_loop_ub; c4_i6++) {
        c4_e_loop_ub = c4_strongest_idx_size[1] - 1;
        for (c4_i9 = 0; c4_i9 <= c4_e_loop_ub; c4_i9++) {
          c4_d = c4_strongest_idx_data[c4_i9];
          if (c4_d != (real_T)(int32_T)muDoubleScalarFloor(c4_d)) {
            emlrtIntegerCheckR2012b(c4_d, &c4_emlrtDCI, &c4_st);
          }

          c4_i13 = (int32_T)c4_d;
          if ((c4_i13 < 1) || (c4_i13 > c4_b_centers)) {
            emlrtDynamicBoundsCheckR2012b(c4_i13, 1, c4_b_centers, &c4_emlrtBCI,
              &c4_st);
          }

          c4_centersStrong_data[c4_i9 + c4_centersStrong_size[0] * c4_i6] =
            c4_centers.vector.data[(c4_i13 + c4_centers.size[0] * c4_i6) - 1];
        }
      }

      c4_i7 = c4__s32_s64_(chartInstance, (int64_T)c4_centersStrong_size[0] *
                           (int64_T)c4_centersStrong_size[1], 0, 1U, 522, 16);
      c4_i8 = 1;
      if ((c4_i8 < 1) || (c4_i8 > c4_i7)) {
        emlrtDynamicBoundsCheckR2012b(c4_i8, 1, c4_i7, &c4_b_emlrtBCI, &c4_st);
      }

      c4_b_offset_x = 80.0 - c4_centersStrong_data[c4_i8 - 1];
      c4_i11 = c4__s32_s64_(chartInstance, (int64_T)c4_centersStrong_size[0] *
                            (int64_T)c4_centersStrong_size[1], 0, 1U, 559, 16);
      c4_i12 = 2;
      if ((c4_i12 < 1) || (c4_i12 > c4_i11)) {
        emlrtDynamicBoundsCheckR2012b(c4_i12, 1, c4_i11, &c4_c_emlrtBCI, &c4_st);
      }

      c4_b_offset_y = c4_centersStrong_data[c4_i12 - 1] - 60.0;
      c4_b_signal = 1.0;
    }
  }

  c4_array_real_T_2D_Destructor(chartInstance, &c4_metric);
  c4_array_real_T_2D_Destructor(chartInstance, &c4_centers);
  *chartInstance->c4_offset_x = c4_b_offset_x;
  *chartInstance->c4_offset_y = c4_b_offset_y;
  *chartInstance->c4_signal = c4_b_signal;
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                    *chartInstance->c4_offset_x);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 2U,
                    *chartInstance->c4_offset_y);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 3U,
                    *chartInstance->c4_signal);
}

static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_jit_animation_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(3, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_offset_x, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", chartInstance->c4_offset_y, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", chartInstance->c4_signal, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_offset_x = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "offset_x");
  *chartInstance->c4_offset_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "offset_y");
  *chartInstance->c4_signal = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "signal");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void c4_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[19200], real32_T c4_b[19200])
{
  static real_T c4_kernel[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  static real_T c4_nonZeroKernel[25] = { 0.014418818362460822,
    0.028084023356349175, 0.0350727008055935, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.0350727008055935, 0.068312293270780214, 0.085311730190125085,
    0.068312293270780214, 0.0350727008055935, 0.028084023356349175,
    0.054700208300935887, 0.068312293270780214, 0.054700208300935887,
    0.028084023356349175, 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822 };

  static int32_T c4_idxA[328] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160,
    160 };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  real_T c4_b_j;
  real_T c4_c_i;
  int32_T c4_b_i;
  int32_T c4_d_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_j;
  real32_T c4_aTmp[20336];
  boolean_T c4_conn[25];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_e_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_b_st.site = &c4_g_emlrtRSI;
  for (c4_j = 0; c4_j < 164; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 124; c4_i++) {
      c4_c_i = (real_T)c4_i + 1.0;
      if ((c4_idxA[(int32_T)c4_c_i - 1] < 1) || (c4_idxA[(int32_T)c4_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_c_i - 1], 1, 120,
          &c4_d_emlrtBCI, &c4_b_st);
      }

      c4_d_i = c4_idxA[(int32_T)c4_b_j + 163];
      if ((c4_d_i < 1) || (c4_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c4_d_i, 1, 160, &c4_e_emlrtBCI, &c4_b_st);
      }

      c4_aTmp[((int32_T)c4_c_i + 124 * ((int32_T)c4_b_j - 1)) - 1] =
        c4_varargin_1[(c4_idxA[(int32_T)c4_c_i - 1] + 120 * (c4_d_i - 1)) - 1];
    }
  }

  c4_st.site = &c4_f_emlrtRSI;
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 124.0 + 40.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 5.0;
    }

    ippfilter_real32(&c4_aTmp[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_kernel[0], &c4_connDimsT[0], false);
  } else {
    for (c4_i1 = 0; c4_i1 < 25; c4_i1++) {
      c4_conn[c4_i1] = true;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_padSizeT[c4_i3] = 124.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_outSizeT[c4_i5] = 120.0 + 40.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_connDimsT[c4_i7] = 5.0;
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_startT[c4_i8] = 2.0;
    }

    imfilter_real32(&c4_aTmp[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_nonZeroKernel[0], 25.0, &c4_conn[0],
                    2.0, &c4_connDimsT[0], &c4_startT[0], 2.0, true, false);
  }
}

static void c4_b_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[19200], real32_T c4_b[19200])
{
  static real_T c4_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c4_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c4_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  real_T c4_b_j;
  real_T c4_c_i;
  int32_T c4_b_i;
  int32_T c4_d_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_j;
  real32_T c4_aTmp[19764];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_e_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_b_st.site = &c4_g_emlrtRSI;
  for (c4_j = 0; c4_j < 162; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 122; c4_i++) {
      c4_c_i = (real_T)c4_i + 1.0;
      if ((c4_iv[(int32_T)c4_c_i - 1] < 1) || (c4_iv[(int32_T)c4_c_i - 1] > 120))
      {
        emlrtDynamicBoundsCheckR2012b(c4_iv[(int32_T)c4_c_i - 1], 1, 120,
          &c4_d_emlrtBCI, &c4_b_st);
      }

      c4_d_i = c4_iv[(int32_T)c4_b_j + 161];
      if ((c4_d_i < 1) || (c4_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c4_d_i, 1, 160, &c4_e_emlrtBCI, &c4_b_st);
      }

      c4_aTmp[((int32_T)c4_c_i + 122 * ((int32_T)c4_b_j - 1)) - 1] =
        c4_varargin_1[(c4_iv[(int32_T)c4_c_i - 1] + 120 * (c4_d_i - 1)) - 1];
    }
  }

  c4_st.site = &c4_f_emlrtRSI;
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 122.0 + 40.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 3.0;
    }

    ippfilter_real32(&c4_aTmp[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_kernel[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 122.0 + 40.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 3.0;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 1.0;
    }

    imfilter_real32(&c4_aTmp[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_nonZeroKernel[0], 6.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_c_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_varargin_1[19200], real32_T c4_b[19200])
{
  static real_T c4_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c4_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c4_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  real_T c4_b_j;
  real_T c4_c_i;
  int32_T c4_b_i;
  int32_T c4_d_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_j;
  real32_T c4_aTmp[19764];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_e_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_b_st.site = &c4_g_emlrtRSI;
  for (c4_j = 0; c4_j < 162; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 122; c4_i++) {
      c4_c_i = (real_T)c4_i + 1.0;
      if ((c4_iv[(int32_T)c4_c_i - 1] < 1) || (c4_iv[(int32_T)c4_c_i - 1] > 120))
      {
        emlrtDynamicBoundsCheckR2012b(c4_iv[(int32_T)c4_c_i - 1], 1, 120,
          &c4_d_emlrtBCI, &c4_b_st);
      }

      c4_d_i = c4_iv[(int32_T)c4_b_j + 161];
      if ((c4_d_i < 1) || (c4_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c4_d_i, 1, 160, &c4_e_emlrtBCI, &c4_b_st);
      }

      c4_aTmp[((int32_T)c4_c_i + 122 * ((int32_T)c4_b_j - 1)) - 1] =
        c4_varargin_1[(c4_iv[(int32_T)c4_c_i - 1] + 120 * (c4_d_i - 1)) - 1];
    }
  }

  c4_st.site = &c4_f_emlrtRSI;
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 122.0 + 40.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 3.0;
    }

    ippfilter_real32(&c4_aTmp[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_kernel[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 122.0 + 40.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 3.0;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 1.0;
    }

    imfilter_real32(&c4_aTmp[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_nonZeroKernel[0], 6.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_imfindcircles(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200],
  c4_coder_array_real_T_2D *c4_centers, c4_coder_array_real_T_2D *c4_r_estimated,
  c4_coder_array_real_T_2D *c4_metric)
{
  static char_T c4_b_cv1[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c4_b_cv4[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c4_cv7[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c',
    't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c4_cv9[38] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'o', 'u', 't', 'O',
    'f', 'B', 'o', 'u', 'n', 'd', 'C', 'e', 'n', 't', 'e', 'r', 's' };

  static char_T c4_b_cv[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c4_b_cv3[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c4_b_cv5[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'i', 'n', 'c',
    'o', 'r', 'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c4_b_cv2[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c4_cv6[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c4_cv8[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  c4_coder_array_boolean_T c4_c_centers;
  c4_coder_array_boolean_T c4_d_centers;
  c4_coder_array_boolean_T_2D c4_e_x;
  c4_coder_array_creal_T c4_b_x;
  c4_coder_array_creal_T c4_f_x;
  c4_coder_array_int32_T c4_ii;
  c4_coder_array_real_T c4_e_centers;
  c4_coder_array_real_T c4_f_centers;
  c4_coder_array_real_T c4_idx2Keep;
  c4_coder_array_real_T c4_varargin_2;
  c4_coder_array_real_T_2D c4_b_centers;
  c4_coder_array_real_T_2D c4_b_metric;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  const mxArray *c4_n_y = NULL;
  const mxArray *c4_o_y = NULL;
  creal_T c4_d_x;
  real_T c4_dv[2];
  real_T c4_b_k;
  real_T c4_d;
  real_T c4_e_k;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_p_y;
  real_T c4_q_y;
  real_T c4_u;
  int32_T c4_b_iv[2];
  int32_T c4_b_ii;
  int32_T c4_b_loop_ub;
  int32_T c4_b_nx;
  int32_T c4_c_b;
  int32_T c4_c_ii;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_metric;
  int32_T c4_c_nx;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_d_nx;
  int32_T c4_e_b;
  int32_T c4_e_loop_ub;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_g_b;
  int32_T c4_g_centers;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_k;
  int32_T c4_i_loop_ub;
  int32_T c4_idx;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_nx;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b10;
  boolean_T c4_b11;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b8;
  boolean_T c4_b9;
  boolean_T c4_b_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_overflow;
  boolean_T c4_c_x;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_p;
  boolean_T c4_y;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_st.site = &c4_yg_emlrtRSI;
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers, &c4_f_emlrtRTEI,
    0, 0);
  c4_st.site = &c4_xg_emlrtRSI;
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_r_estimated,
    &c4_g_emlrtRTEI, 0, 0);
  c4_st.site = &c4_wg_emlrtRSI;
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric, &c4_h_emlrtRTEI,
    0, 0);
  c4_st.site = &c4_n_emlrtRSI;
  c4_chaccum(chartInstance, &c4_st, c4_varargin_1, chartInstance->c4_accumMatrix,
             chartInstance->c4_gradientImg);
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    chartInstance->c4_x[c4_i] = chartInstance->c4_accumMatrix[c4_i];
  }

  c4_array_creal_T_Constructor(chartInstance, &c4_b_x);
  c4_array_creal_T_SetSize(chartInstance, c4_sp, &c4_b_x, &c4_i_emlrtRTEI, 19200);
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_b_x.vector.data[c4_i1] = chartInstance->c4_x[c4_i1];
  }

  c4_y = false;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = ((c4_b_x.vector.data[(int32_T)c4_b_k - 1].re == c4_dc.re) &&
              (c4_b_x.vector.data[(int32_T)c4_b_k - 1].im == c4_dc.im));
    if (c4_c_x) {
      c4_b = true;
    } else {
      c4_d_x = c4_b_x.vector.data[(int32_T)c4_b_k - 1];
      c4_b1 = muDoubleScalarIsNaN(c4_d_x.re);
      c4_b2 = muDoubleScalarIsNaN(c4_d_x.im);
      c4_b_b = (c4_b1 || c4_b2);
      if (c4_b_b) {
        c4_b = true;
      } else {
        c4_b = false;
      }
    }

    if (!c4_b) {
      c4_y = true;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  c4_array_creal_T_Destructor(chartInstance, &c4_b_x);
  c4_array_real_T_Constructor(chartInstance, &c4_idx2Keep);
  c4_array_real_T_2D_Constructor(chartInstance, &c4_b_centers);
  c4_array_real_T_2D_Constructor(chartInstance, &c4_b_metric);
  c4_array_boolean_T_2D_Constructor(chartInstance, &c4_e_x);
  c4_array_int32_T_Constructor(chartInstance, &c4_ii);
  c4_array_real_T_Constructor(chartInstance, &c4_varargin_2);
  c4_array_creal_T_Constructor(chartInstance, &c4_f_x);
  c4_array_boolean_T_Constructor(chartInstance, &c4_c_centers);
  c4_array_boolean_T_Constructor(chartInstance, &c4_d_centers);
  c4_array_real_T_Constructor(chartInstance, &c4_e_centers);
  c4_array_real_T_Constructor(chartInstance, &c4_f_centers);
  if (!c4_y) {
  } else {
    c4_st.site = &c4_o_emlrtRSI;
    for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
      chartInstance->c4_b_accumMatrix[c4_i2] = chartInstance->
        c4_accumMatrix[c4_i2];
    }

    c4_chcenters(chartInstance, &c4_st, chartInstance->c4_b_accumMatrix,
                 &c4_b_centers, &c4_b_metric);
    c4_st.site = &c4_o_emlrtRSI;
    c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers,
      &c4_j_emlrtRTEI, c4_b_centers.size[0], c4_b_centers.size[1]);
    c4_loop_ub = c4_b_centers.size[0] * c4_b_centers.size[1] - 1;
    for (c4_i3 = 0; c4_i3 <= c4_loop_ub; c4_i3++) {
      c4_centers->vector.data[c4_i3] = c4_b_centers.vector.data[c4_i3];
    }

    c4_st.site = &c4_o_emlrtRSI;
    c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric, &c4_k_emlrtRTEI,
      c4_b_metric.size[0], c4_b_metric.size[1]);
    c4_b_loop_ub = c4_b_metric.size[0] * c4_b_metric.size[1] - 1;
    for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
      c4_metric->vector.data[c4_i4] = c4_b_metric.vector.data[c4_i4];
    }

    c4_b3 = (c4_b_centers.size[0] == 0);
    c4_b4 = (c4_b_centers.size[1] == 0);
    if (c4_b3 || c4_b4) {
    } else {
      c4_st.site = &c4_p_emlrtRSI;
      c4_b_st.site = &c4_p_emlrtRSI;
      c4_array_boolean_T_2D_SetSize(chartInstance, &c4_b_st, &c4_e_x,
        &c4_l_emlrtRTEI, c4_b_metric.size[0], c4_b_metric.size[1]);
      c4_c_loop_ub = c4_b_metric.size[0] * c4_b_metric.size[1] - 1;
      for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
        c4_e_x.vector.data[c4_i5] = (c4_b_metric.vector.data[c4_i5] >=
          0.099999999999999978);
      }

      c4_b_st.site = &c4_mf_emlrtRSI;
      c4_nx = c4_e_x.size[0] * c4_e_x.size[1];
      c4_c_st.site = &c4_nf_emlrtRSI;
      c4_c_k = c4_nx;
      c4_b_nx = c4_nx;
      c4_idx = 0;
      c4_array_int32_T_SetSize(chartInstance, &c4_c_st, &c4_ii, &c4_m_emlrtRTEI,
        c4_c_k);
      c4_d_st.site = &c4_of_emlrtRSI;
      c4_c_b = c4_b_nx;
      c4_d_b = c4_c_b;
      if (c4_d_b < 1) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_d_b > 2147483646);
      }

      if (c4_overflow) {
        c4_e_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      c4_b_ii = 1;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_b_ii - 1 <= c4_b_nx - 1)) {
        c4_c_ii = c4_b_ii;
        if (c4_e_x.vector.data[c4_c_ii - 1]) {
          c4_idx++;
          c4_ii.vector.data[c4_idx - 1] = c4_c_ii;
          if (c4_idx >= c4_c_k) {
            c4_exitg1 = true;
          } else {
            c4_b_ii++;
          }
        } else {
          c4_b_ii++;
        }
      }

      if (c4_idx > c4_c_k) {
        c4_b_y = NULL;
        sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1,
          30), false);
        sf_mex_call(&c4_c_st, &c4_o_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                    sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
      }

      if (c4_c_k == 1) {
        if (c4_idx == 0) {
          c4_array_int32_T_SetSize(chartInstance, &c4_c_st, &c4_ii,
            &c4_n_emlrtRTEI, 0);
        }
      } else {
        c4_b5 = (c4_idx < 1);
        if (c4_b5) {
          c4_i6 = 0;
        } else {
          c4_i6 = c4_idx;
        }

        c4_b_iv[0] = 1;
        c4_b_iv[1] = c4_i6;
        c4_d_st.site = &c4_pf_emlrtRSI;
        c4_indexShapeCheck(chartInstance, &c4_d_st, c4_ii.size[0], c4_b_iv);
        c4_array_int32_T_SetSize(chartInstance, &c4_c_st, &c4_ii,
          &c4_n_emlrtRTEI, c4_i6);
      }

      c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_idx2Keep,
        &c4_o_emlrtRTEI, c4_ii.size[0]);
      c4_d_loop_ub = c4_ii.size[0] - 1;
      for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
        c4_idx2Keep.vector.data[c4_i7] = (real_T)c4_ii.vector.data[c4_i7];
      }

      c4_g_centers = c4_b_centers.size[0];
      c4_st.site = &c4_vg_emlrtRSI;
      c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers,
        &c4_p_emlrtRTEI, c4_idx2Keep.size[0], c4_b_centers.size[1]);
      c4_e_loop_ub = c4_b_centers.size[1] - 1;
      for (c4_i8 = 0; c4_i8 <= c4_e_loop_ub; c4_i8++) {
        c4_f_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i9 = 0; c4_i9 <= c4_f_loop_ub; c4_i9++) {
          c4_i10 = (int32_T)c4_idx2Keep.vector.data[c4_i9];
          if ((c4_i10 < 1) || (c4_i10 > c4_g_centers)) {
            emlrtDynamicBoundsCheckR2012b(c4_i10, 1, c4_g_centers,
              &c4_j_emlrtBCI, (emlrtConstCTX)c4_sp);
          }

          c4_centers->vector.data[c4_i9 + c4_centers->size[0] * c4_i8] =
            c4_b_centers.vector.data[(c4_i10 + c4_b_centers.size[0] * c4_i8) - 1];
        }
      }

      c4_c_metric = c4_b_metric.size[0];
      c4_st.site = &c4_ug_emlrtRSI;
      c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric,
        &c4_q_emlrtRTEI, c4_idx2Keep.size[0], c4_b_metric.size[1]);
      c4_g_loop_ub = c4_b_metric.size[1] - 1;
      for (c4_i11 = 0; c4_i11 <= c4_g_loop_ub; c4_i11++) {
        c4_h_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i12 = 0; c4_i12 <= c4_h_loop_ub; c4_i12++) {
          c4_i13 = (int32_T)c4_idx2Keep.vector.data[c4_i12];
          if ((c4_i13 < 1) || (c4_i13 > c4_c_metric)) {
            emlrtDynamicBoundsCheckR2012b(c4_i13, 1, c4_c_metric, &c4_k_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_metric->vector.data[c4_i12 + c4_metric->size[0] * c4_i11] =
            c4_b_metric.vector.data[(c4_i13 + c4_b_metric.size[0] * c4_i11) - 1];
        }
      }

      c4_b6 = (c4_centers->size[0] == 0);
      c4_b7 = (c4_centers->size[1] == 0);
      if (c4_b6 || c4_b7) {
        c4_st.site = &c4_tg_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers,
          &c4_ab_emlrtRTEI, 0, 0);
        c4_st.site = &c4_sg_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric,
          &c4_bb_emlrtRTEI, 0, 0);
      } else {
        c4_st.site = &c4_q_emlrtRSI;
        c4_b_st.site = &c4_rf_emlrtRSI;
        c4_c_st.site = &c4_uf_emlrtRSI;
        c4_d_st.site = &c4_wf_emlrtRSI;
        c4_e_st.site = &c4_ac_emlrtRSI;
        c4_p = true;
        c4_d = (real_T)(c4_centers->size[0] * c4_centers->size[1]);
        c4_i14 = (int32_T)c4_d - 1;
        c4_d_k = 0;
        c4_exitg1 = false;
        while ((!c4_exitg1) && (c4_d_k <= c4_i14)) {
          c4_e_k = (real_T)c4_d_k + 1.0;
          c4_g_x = c4_centers->vector.data[(int32_T)c4_e_k - 1];
          c4_b_p = !(c4_g_x <= 0.0);
          if (c4_b_p) {
            c4_d_k++;
          } else {
            c4_p = false;
            c4_exitg1 = true;
          }
        }

        if (c4_p) {
          c4_b8 = true;
        } else {
          c4_b8 = false;
        }

        if (!c4_b8) {
          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1,
            37), false);
          c4_e_y = NULL;
          sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1, 0U, 2,
            1, 48), false);
          c4_f_y = NULL;
          sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1, 0U, 2,
            1, 24), false);
          sf_mex_call(&c4_e_st, &c4_p_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                      sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_e_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14,
                        c4_f_y)));
        }

        c4_e_st.site = &c4_ac_emlrtRSI;
        c4_b9 = (c4_centers->size[0] == 0);
        c4_b10 = (c4_centers->size[1] == 0);
        if ((!!c4_b9) || (!!c4_b10)) {
          c4_g_y = NULL;
          sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1, 0U, 2,
            1, 37), false);
          c4_h_y = NULL;
          sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv4, 10, 0U, 1, 0U, 2,
            1, 48), false);
          c4_j_y = NULL;
          sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv6, 10, 0U, 1, 0U, 2, 1,
            24), false);
          sf_mex_call(&c4_e_st, &c4_q_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                      sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_e_st, NULL, "message", 1U, 2U, 14, c4_h_y, 14,
                        c4_j_y)));
        }

        c4_e_st.site = &c4_ac_emlrtRSI;
        if (c4_centers->size[1] != 2) {
          c4_i_y = NULL;
          sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv5, 10, 0U, 1, 0U, 2,
            1, 37), false);
          c4_k_y = NULL;
          sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv7, 10, 0U, 1, 0U, 2, 1,
            48), false);
          c4_l_y = NULL;
          sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_cv8, 10, 0U, 1, 0U, 2, 1,
            24), false);
          c4_u = 2.0;
          c4_m_y = NULL;
          sf_mex_assign(&c4_m_y, sf_mex_create("y", &c4_u, 0, 0U, 0, 0U, 0),
                        false);
          sf_mex_call(&c4_e_st, &c4_r_emlrtMCI, "error", 0U, 2U, 14, c4_i_y, 14,
                      sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_e_st, NULL, "message", 1U, 3U, 14, c4_k_y, 14,
                        c4_l_y, 14, c4_m_y)));
        }

        c4_c_st.site = &c4_vf_emlrtRSI;
        c4_i15 = c4_centers->size[1];
        c4_i16 = 1;
        if ((c4_i16 < 1) || (c4_i16 > c4_i15)) {
          emlrtDynamicBoundsCheckR2012b(c4_i16, 1, c4_i15, &c4_h_emlrtBCI,
            &c4_c_st);
        }

        c4_array_boolean_T_SetSize(chartInstance, &c4_c_st, &c4_c_centers,
          &c4_r_emlrtRTEI, c4_centers->size[0]);
        c4_i_loop_ub = c4_centers->size[0] - 1;
        for (c4_i17 = 0; c4_i17 <= c4_i_loop_ub; c4_i17++) {
          c4_c_centers.vector.data[c4_i17] = (c4_centers->vector.data[c4_i17] <=
            160.0);
        }

        c4_d_st.site = &c4_xf_emlrtRSI;
        if (c4_all(chartInstance, &c4_d_st, &c4_c_centers)) {
          c4_i18 = c4_centers->size[1];
          c4_i19 = 2;
          if ((c4_i19 < 1) || (c4_i19 > c4_i18)) {
            emlrtDynamicBoundsCheckR2012b(c4_i19, 1, c4_i18, &c4_i_emlrtBCI,
              &c4_c_st);
          }

          c4_array_boolean_T_SetSize(chartInstance, &c4_c_st, &c4_d_centers,
            &c4_s_emlrtRTEI, c4_centers->size[0]);
          c4_j_loop_ub = c4_centers->size[0] - 1;
          for (c4_i22 = 0; c4_i22 <= c4_j_loop_ub; c4_i22++) {
            c4_d_centers.vector.data[c4_i22] = (c4_centers->vector.data[c4_i22 +
              c4_centers->size[0]] <= 120.0);
          }

          c4_d_st.site = &c4_yf_emlrtRSI;
          if (c4_all(chartInstance, &c4_d_st, &c4_d_centers)) {
            c4_b11 = true;
          } else {
            c4_b11 = false;
          }
        } else {
          c4_b11 = false;
        }

        if (!c4_b11) {
          c4_n_y = NULL;
          sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_cv9, 10, 0U, 1, 0U, 2, 1,
            38), false);
          c4_o_y = NULL;
          sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_cv9, 10, 0U, 1, 0U, 2, 1,
            38), false);
          sf_mex_call(&c4_c_st, &c4_s_emlrtMCI, "error", 0U, 2U, 14, c4_n_y, 14,
                      sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_o_y)));
        }

        c4_i20 = c4_centers->size[1];
        c4_i21 = 2;
        if ((c4_i21 < 1) || (c4_i21 > c4_i20)) {
          emlrtDynamicBoundsCheckR2012b(c4_i21, 1, c4_i20, &c4_f_emlrtBCI,
            &c4_st);
        }

        c4_i23 = c4_centers->size[1];
        c4_i24 = 1;
        if ((c4_i24 < 1) || (c4_i24 > c4_i23)) {
          emlrtDynamicBoundsCheckR2012b(c4_i24, 1, c4_i23, &c4_g_emlrtBCI,
            &c4_st);
        }

        c4_b_st.site = &c4_sf_emlrtRSI;
        c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_e_centers,
          &c4_t_emlrtRTEI, c4_centers->size[0]);
        c4_k_loop_ub = c4_centers->size[0] - 1;
        for (c4_i25 = 0; c4_i25 <= c4_k_loop_ub; c4_i25++) {
          c4_e_centers.vector.data[c4_i25] = c4_centers->vector.data[c4_i25 +
            c4_centers->size[0]];
        }

        c4_c_st.site = &c4_sf_emlrtRSI;
        c4_round(chartInstance, &c4_c_st, &c4_e_centers, &c4_idx2Keep);
        c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_f_centers,
          &c4_u_emlrtRTEI, c4_centers->size[0]);
        c4_l_loop_ub = c4_centers->size[0] - 1;
        for (c4_i26 = 0; c4_i26 <= c4_l_loop_ub; c4_i26++) {
          c4_f_centers.vector.data[c4_i26] = c4_centers->vector.data[c4_i26];
        }

        c4_c_st.site = &c4_sf_emlrtRSI;
        c4_round(chartInstance, &c4_c_st, &c4_f_centers, &c4_varargin_2);
        c4_c_st.site = &c4_fb_emlrtRSI;
        c4_sub2ind(chartInstance, &c4_c_st, &c4_idx2Keep, &c4_varargin_2, &c4_ii);
        c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_idx2Keep,
          &c4_v_emlrtRTEI, c4_ii.size[0]);
        c4_m_loop_ub = c4_ii.size[0] - 1;
        for (c4_i27 = 0; c4_i27 <= c4_m_loop_ub; c4_i27++) {
          c4_idx2Keep.vector.data[c4_i27] = (real_T)c4_ii.vector.data[c4_i27];
        }

        c4_b_st.site = &c4_sf_emlrtRSI;
        c4_array_creal_T_SetSize(chartInstance, &c4_b_st, &c4_f_x,
          &c4_w_emlrtRTEI, c4_idx2Keep.size[0]);
        c4_n_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i28 = 0; c4_i28 <= c4_n_loop_ub; c4_i28++) {
          c4_i29 = (int32_T)c4_idx2Keep.vector.data[c4_i28];
          if ((c4_i29 < 1) || (c4_i29 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c4_i29, 1, 19200, &c4_l_emlrtBCI,
              &c4_b_st);
          }

          c4_f_x.vector.data[c4_i28].re = chartInstance->c4_accumMatrix[c4_i29 -
            1].re;
          c4_i30 = (int32_T)c4_idx2Keep.vector.data[c4_i28];
          if ((c4_i30 < 1) || (c4_i30 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c4_i30, 1, 19200, &c4_l_emlrtBCI,
              &c4_b_st);
          }

          c4_f_x.vector.data[c4_i28].im = chartInstance->c4_accumMatrix[c4_i30 -
            1].im;
        }

        c4_c_st.site = &c4_cg_emlrtRSI;
        c4_c_nx = c4_f_x.size[0];
        c4_dv[0] = (real_T)c4_f_x.size[0];
        c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_idx2Keep,
          &c4_x_emlrtRTEI, (int32_T)c4_dv[0]);
        c4_d_st.site = &c4_dg_emlrtRSI;
        c4_e_b = c4_c_nx;
        c4_f_b = c4_e_b;
        if (c4_f_b < 1) {
          c4_b_overflow = false;
        } else {
          c4_b_overflow = (c4_f_b > 2147483646);
        }

        if (c4_b_overflow) {
          c4_e_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_f_k = 0; c4_f_k < c4_c_nx; c4_f_k++) {
          c4_g_k = c4_f_k;
          c4_d_x = c4_f_x.vector.data[c4_g_k];
          c4_p_y = c4_d_x.im;
          c4_h_x = c4_d_x.re;
          c4_q_y = muDoubleScalarAtan2(c4_p_y, c4_h_x);
          c4_idx2Keep.vector.data[c4_g_k] = c4_q_y;
        }

        c4_o_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i31 = 0; c4_i31 <= c4_o_loop_ub; c4_i31++) {
          c4_idx2Keep.vector.data[c4_i31] = (c4_idx2Keep.vector.data[c4_i31] +
            3.1415926535897931) / 6.2831853071795862;
        }

        c4_p_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i32 = 0; c4_i32 <= c4_p_loop_ub; c4_i32++) {
          c4_idx2Keep.vector.data[c4_i32] *= 0.91629073187415466;
        }

        c4_b_st.site = &c4_tf_emlrtRSI;
        c4_q_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i33 = 0; c4_i33 <= c4_q_loop_ub; c4_i33++) {
          c4_idx2Keep.vector.data[c4_i33] += 2.3025850929940459;
        }

        c4_c_st.site = &c4_eg_emlrtRSI;
        c4_d_nx = c4_idx2Keep.size[0];
        c4_d_st.site = &c4_me_emlrtRSI;
        c4_g_b = c4_d_nx;
        c4_h_b = c4_g_b;
        if (c4_h_b < 1) {
          c4_c_overflow = false;
        } else {
          c4_c_overflow = (c4_h_b > 2147483646);
        }

        if (c4_c_overflow) {
          c4_e_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_h_k = 0; c4_h_k < c4_d_nx; c4_h_k++) {
          c4_i_k = c4_h_k;
          c4_i_x = c4_idx2Keep.vector.data[c4_i_k];
          c4_j_x = c4_i_x;
          c4_j_x = muDoubleScalarExp(c4_j_x);
          c4_idx2Keep.vector.data[c4_i_k] = c4_j_x;
        }

        c4_st.site = &c4_q_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_r_estimated,
          &c4_y_emlrtRTEI, c4_idx2Keep.size[0], 1);
        c4_r_loop_ub = c4_idx2Keep.size[0] - 1;
        for (c4_i34 = 0; c4_i34 <= c4_r_loop_ub; c4_i34++) {
          c4_r_estimated->vector.data[c4_i34] = c4_idx2Keep.vector.data[c4_i34];
        }
      }
    }
  }

  c4_array_real_T_Destructor(chartInstance, &c4_f_centers);
  c4_array_real_T_Destructor(chartInstance, &c4_e_centers);
  c4_array_boolean_T_Destructor(chartInstance, &c4_d_centers);
  c4_array_boolean_T_Destructor(chartInstance, &c4_c_centers);
  c4_array_creal_T_Destructor(chartInstance, &c4_f_x);
  c4_array_real_T_Destructor(chartInstance, &c4_varargin_2);
  c4_array_int32_T_Destructor(chartInstance, &c4_ii);
  c4_array_boolean_T_2D_Destructor(chartInstance, &c4_e_x);
  c4_array_real_T_2D_Destructor(chartInstance, &c4_b_metric);
  c4_array_real_T_2D_Destructor(chartInstance, &c4_b_centers);
  c4_array_real_T_Destructor(chartInstance, &c4_idx2Keep);
}

static void c4_chaccum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], creal_T
  c4_c_accumMatrix[19200], real32_T c4_b_gradientImg[19200])
{
  static real_T c4_dv[31] = { -3.1415926535897931, -2.80702892618285,
    -2.4880320526369664, -2.1832175961030367, -1.8913779706509104,
    -1.6114535457308725, -1.3425094212849575, -1.0837165883759692,
    -0.83433651765998729, -0.59370845346824419, -0.36123886279199,
    -0.13639261495857413, 0.081314437871951473, 0.29232173816083673,
    0.49702936305866574, 0.695802590198936, 0.88897582014689291,
    1.076855961309553, 1.2597253633520085, 1.4378443695128462,
    1.6114535457308721, 1.7807756344814214, 1.9460172731378194,
    2.1073705101131148, 2.2650141466837024, 2.4191149280058131,
    2.5698286032176325, 2.7173008715239586, 2.8616682286697577,
    3.003058726128744, 3.1415926535897931 };

  static real_T c4_dv1[31] = { 62.831853071795862, 65.973445725385659,
    69.115038378975441, 72.256631032565238, 75.398223686155035,
    78.539816339744831, 81.681408993334628, 84.823001646924411,
    87.964594300514207, 91.106186954104, 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966 };

  c4_coder_array_boolean_T_2D c4_inside;
  c4_coder_array_creal_T c4_wkeep;
  c4_coder_array_creal_T_2D c4_w;
  c4_coder_array_int32_T c4_ii;
  c4_coder_array_int32_T c4_jj;
  c4_coder_array_int32_T c4_r;
  c4_coder_array_int32_T c4_xckeep;
  c4_coder_array_int32_T c4_yckeep;
  c4_coder_array_real32_T_2D c4_xc;
  c4_coder_array_real32_T_2D c4_yc;
  c4_coder_array_real_T c4_Ex;
  c4_coder_array_real_T c4_Ex_chunk;
  c4_coder_array_real_T c4_Ey;
  c4_coder_array_real_T c4_Ey_chunk;
  c4_coder_array_real_T c4_idxE;
  c4_coder_array_real_T c4_idxE_chunk;
  c4_coder_array_real_T c4_ndx;
  c4_coder_array_real_T c4_varargin_2;
  c4_coder_array_real_T_2D c4_r1;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  creal_T c4_Opca[31];
  creal_T c4_b_dc;
  creal_T c4_h_x;
  real_T c4_a1;
  real_T c4_ab_x;
  real_T c4_ai;
  real_T c4_apnd;
  real_T c4_ar;
  real_T c4_b1;
  real_T c4_b_a;
  real_T c4_b_d;
  real_T c4_b_idx1;
  real_T c4_b_idx2;
  real_T c4_b_k;
  real_T c4_b_r;
  real_T c4_b_s;
  real_T c4_b_varargin_2;
  real_T c4_b_y;
  real_T c4_bi;
  real_T c4_bim;
  real_T c4_br;
  real_T c4_brm;
  real_T c4_c;
  real_T c4_c_a;
  real_T c4_c_d;
  real_T c4_c_i;
  real_T c4_c_idx;
  real_T c4_c_y;
  real_T c4_cdiff;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d_a;
  real_T c4_d_y;
  real_T c4_dim1;
  real_T c4_e_a;
  real_T c4_e_y;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_f_y;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_g_y;
  real_T c4_h_y;
  real_T c4_i_a;
  real_T c4_i_x;
  real_T c4_i_y;
  real_T c4_j_b;
  real_T c4_j_x;
  real_T c4_j_y;
  real_T c4_k_b;
  real_T c4_k_x;
  real_T c4_kd;
  real_T c4_l_b;
  real_T c4_l_x;
  real_T c4_lenE;
  real_T c4_m_x;
  real_T c4_minval;
  real_T c4_n_x;
  real_T c4_ndbl;
  real_T c4_ni;
  real_T c4_nr;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_sgnbi;
  real_T c4_sgnbr;
  real_T c4_sizeChunk;
  real_T c4_t_x;
  real_T c4_thresh;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_x_x;
  real_T c4_y_x;
  int32_T c4_rows_to_keep_size[1];
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_b_loop_ub;
  int32_T c4_c_idx1;
  int32_T c4_c_idx2;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_idx;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_e_idx;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_first;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_h_a;
  int32_T c4_h_k;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i_k;
  int32_T c4_idx;
  int32_T c4_idx1;
  int32_T c4_idx2;
  int32_T c4_idxEdge;
  int32_T c4_idxkeep;
  int32_T c4_j_k;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_m_b;
  int32_T c4_n;
  int32_T c4_n_b;
  int32_T c4_nm1;
  int32_T c4_nm1d2;
  int32_T c4_o_y;
  int32_T c4_p_b;
  int32_T c4_q_b;
  int32_T c4_r_b;
  int32_T c4_szxc;
  real32_T c4_Gmax;
  real32_T c4_a;
  real32_T c4_b_b;
  real32_T c4_b_z;
  real32_T c4_bb_x;
  real32_T c4_c_x;
  real32_T c4_c_z;
  real32_T c4_cb_x;
  real32_T c4_d_x;
  real32_T c4_db_x;
  real32_T c4_e_x;
  real32_T c4_eb_x;
  real32_T c4_ex;
  real32_T c4_f_x;
  real32_T c4_fb_x;
  real32_T c4_g_x;
  real32_T c4_gb_x;
  real32_T c4_hb_x;
  real32_T c4_k_y;
  real32_T c4_l_y;
  real32_T c4_m_y;
  real32_T c4_n_y;
  real32_T c4_o_b;
  real32_T c4_p_y;
  real32_T c4_q_y;
  real32_T c4_r_y;
  real32_T c4_s_b;
  real32_T c4_s_y;
  real32_T c4_t;
  real32_T c4_w_x;
  real32_T c4_x1;
  real32_T c4_x2;
  real32_T c4_y;
  real32_T c4_z;
  boolean_T c4_b_x[19200];
  boolean_T c4_rows_to_keep_data[19200];
  boolean_T c4_x_data[19200];
  boolean_T c4_b;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b_b1;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_b_varargin_1;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_exitg1;
  boolean_T c4_flat;
  boolean_T c4_guard1;
  boolean_T c4_guard2;
  boolean_T c4_h_b;
  boolean_T c4_i_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  boolean_T c4_t_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_b_varargin_1 = c4_varargin_1[0];
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_b_x[c4_i] = ((int32_T)c4_varargin_1[c4_i] == (int32_T)c4_b_varargin_1);
  }

  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_x_data[c4_i1] = c4_b_x[c4_i1];
  }

  c4_flat = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    if (!c4_x_data[(int32_T)c4_b_k - 1]) {
      c4_flat = false;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (c4_flat) {
    memset(&c4_c_accumMatrix[0], 0, 19200U * sizeof(creal_T));
    memset(&c4_b_gradientImg[0], 0, 19200U * sizeof(real32_T));
  } else {
    c4_st.site = &c4_r_emlrtRSI;
    for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
      chartInstance->c4_s[c4_i2] = (real32_T)c4_varargin_1[c4_i2];
    }

    c4_b_st.site = &c4_d_emlrtRSI;
    c4_imfilter(chartInstance, &c4_b_st, chartInstance->c4_s,
                chartInstance->c4_A);
    c4_st.site = &c4_s_emlrtRSI;
    c4_b_st.site = &c4_l_emlrtRSI;
    c4_b_imfilter(chartInstance, &c4_b_st, chartInstance->c4_A,
                  chartInstance->c4_Gx);
    c4_b_st.site = &c4_m_emlrtRSI;
    c4_c_imfilter(chartInstance, &c4_b_st, chartInstance->c4_A,
                  chartInstance->c4_Gy);
    for (c4_c_k = 0; c4_c_k < 19200; c4_c_k++) {
      c4_d_k = c4_c_k;
      c4_c_x = chartInstance->c4_Gx[c4_d_k];
      c4_y = chartInstance->c4_Gy[c4_d_k];
      c4_x1 = c4_c_x;
      c4_x2 = c4_y;
      c4_a = c4_x1;
      c4_b_b = c4_x2;
      c4_z = muSingleScalarHypot(c4_a, c4_b_b);
      c4_b_gradientImg[c4_d_k] = c4_z;
    }

    c4_st.site = &c4_t_emlrtRSI;
    for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
      chartInstance->c4_s[c4_i3] = c4_b_gradientImg[c4_i3];
    }

    c4_d_x = chartInstance->c4_s[0];
    c4_e_x = c4_d_x;
    c4_b = muSingleScalarIsNaN(c4_e_x);
    c4_p = !c4_b;
    if (c4_p) {
      c4_idx = 1;
    } else {
      c4_idx = 0;
      c4_e_k = 2;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_e_k < 19201)) {
        c4_f_x = chartInstance->c4_s[c4_e_k - 1];
        c4_g_x = c4_f_x;
        c4_c_b = muSingleScalarIsNaN(c4_g_x);
        c4_b_p = !c4_c_b;
        if (c4_b_p) {
          c4_idx = c4_e_k;
          c4_exitg1 = true;
        } else {
          c4_e_k++;
        }
      }
    }

    if (c4_idx == 0) {
      c4_Gmax = chartInstance->c4_s[0];
    } else {
      c4_first = c4_idx - 1;
      c4_ex = chartInstance->c4_s[c4_first];
      c4_i4 = c4_first;
      for (c4_f_k = c4_i4 + 2; c4_f_k < 19201; c4_f_k++) {
        if (c4_ex < chartInstance->c4_s[c4_f_k - 1]) {
          c4_ex = chartInstance->c4_s[c4_f_k - 1];
        }
      }

      c4_Gmax = c4_ex;
    }

    c4_t = c4_Gmax * 0.25F;
    c4_b_st.site = &c4_x_emlrtRSI;
    for (c4_i5 = 0; c4_i5 < 19200; c4_i5++) {
      c4_b_x[c4_i5] = (c4_b_gradientImg[c4_i5] > c4_t);
    }

    c4_array_int32_T_Constructor(chartInstance, &c4_ii);
    c4_array_int32_T_Constructor(chartInstance, &c4_jj);
    c4_c_st.site = &c4_y_emlrtRSI;
    c4_eml_find(chartInstance, &c4_c_st, c4_b_x, &c4_ii, &c4_jj);
    c4_array_real_T_Constructor(chartInstance, &c4_Ey);
    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_Ey, &c4_cb_emlrtRTEI,
      c4_ii.size[0]);
    c4_loop_ub = c4_ii.size[0] - 1;
    for (c4_i6 = 0; c4_i6 <= c4_loop_ub; c4_i6++) {
      c4_Ey.vector.data[c4_i6] = (real_T)c4_ii.vector.data[c4_i6];
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_ii);
    c4_array_real_T_Constructor(chartInstance, &c4_Ex);
    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_Ex, &c4_db_emlrtRTEI,
      c4_jj.size[0]);
    c4_b_loop_ub = c4_jj.size[0] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
      c4_Ex.vector.data[c4_i7] = (real_T)c4_jj.vector.data[c4_i7];
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_jj);
    c4_array_real_T_Constructor(chartInstance, &c4_ndx);
    c4_st.site = &c4_u_emlrtRSI;
    c4_b_st.site = &c4_u_emlrtRSI;
    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_ndx, &c4_eb_emlrtRTEI,
      c4_Ey.size[0]);
    c4_c_loop_ub = c4_Ey.size[0] - 1;
    for (c4_i8 = 0; c4_i8 <= c4_c_loop_ub; c4_i8++) {
      c4_ndx.vector.data[c4_i8] = c4_Ey.vector.data[c4_i8];
    }

    c4_array_real_T_Constructor(chartInstance, &c4_varargin_2);
    c4_b_st.site = &c4_u_emlrtRSI;
    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_varargin_2,
      &c4_fb_emlrtRTEI, c4_Ex.size[0]);
    c4_d_loop_ub = c4_Ex.size[0] - 1;
    for (c4_i9 = 0; c4_i9 <= c4_d_loop_ub; c4_i9++) {
      c4_varargin_2.vector.data[c4_i9] = c4_Ex.vector.data[c4_i9];
    }

    c4_array_int32_T_Constructor(chartInstance, &c4_r);
    c4_b_st.site = &c4_fb_emlrtRSI;
    c4_sub2ind(chartInstance, &c4_b_st, &c4_ndx, &c4_varargin_2, &c4_r);
    c4_array_real_T_Destructor(chartInstance, &c4_varargin_2);
    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_ndx, &c4_v_emlrtRTEI,
      c4_r.size[0]);
    c4_e_loop_ub = c4_r.size[0] - 1;
    for (c4_i10 = 0; c4_i10 <= c4_e_loop_ub; c4_i10++) {
      c4_ndx.vector.data[c4_i10] = (real_T)c4_r.vector.data[c4_i10];
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_r);
    c4_array_real_T_Constructor(chartInstance, &c4_idxE);
    c4_st.site = &c4_u_emlrtRSI;
    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_idxE, &c4_gb_emlrtRTEI,
      c4_ndx.size[0]);
    c4_f_loop_ub = c4_ndx.size[0] - 1;
    for (c4_i11 = 0; c4_i11 <= c4_f_loop_ub; c4_i11++) {
      c4_idxE.vector.data[c4_i11] = c4_ndx.vector.data[c4_i11];
    }

    c4_array_real_T_Destructor(chartInstance, &c4_ndx);
    for (c4_i12 = 0; c4_i12 < 31; c4_i12++) {
      c4_Opca[c4_i12].re = -0.0;
      c4_Opca[c4_i12].im = c4_dv[c4_i12];
    }

    for (c4_g_k = 0; c4_g_k < 31; c4_g_k++) {
      c4_h_k = c4_g_k;
      c4_h_x = c4_Opca[c4_h_k];
      if (c4_h_x.re == 0.0) {
        c4_d = c4_h_x.im;
        c4_d2 = c4_h_x.im;
        c4_h_x.re = muDoubleScalarCos(c4_d);
        c4_h_x.im = muDoubleScalarSin(c4_d2);
      } else if (c4_h_x.im == 0.0) {
        c4_d1 = c4_h_x.re;
        c4_h_x.re = muDoubleScalarExp(c4_d1);
        c4_h_x.im = 0.0;
      } else {
        c4_i_x = c4_h_x.im;
        c4_d_b = muDoubleScalarIsInf(c4_i_x);
        c4_guard1 = false;
        if (c4_d_b) {
          c4_j_x = c4_h_x.re;
          c4_e_b = muDoubleScalarIsInf(c4_j_x);
          if (c4_e_b && (c4_h_x.re < 0.0)) {
            c4_h_x = c4_dc;
          } else {
            c4_guard1 = true;
          }
        } else {
          c4_guard1 = true;
        }

        if (c4_guard1) {
          c4_b_r = muDoubleScalarExp(c4_h_x.re / 2.0);
          c4_d3 = c4_h_x.im;
          c4_d4 = c4_h_x.im;
          c4_h_x.re = c4_b_r * (c4_b_r * muDoubleScalarCos(c4_d3));
          c4_h_x.im = c4_b_r * (c4_b_r * muDoubleScalarSin(c4_d4));
        }
      }

      c4_Opca[c4_h_k] = c4_h_x;
    }

    for (c4_i13 = 0; c4_i13 < 31; c4_i13++) {
      c4_ar = c4_Opca[c4_i13].re;
      c4_ai = c4_Opca[c4_i13].im;
      c4_br = c4_dv1[c4_i13];
      c4_bi = 0.0;
      if (c4_bi == 0.0) {
        if (c4_ai == 0.0) {
          c4_b_dc.re = c4_ar / c4_br;
          c4_b_dc.im = 0.0;
        } else if (c4_ar == 0.0) {
          c4_b_dc.re = 0.0;
          c4_b_dc.im = c4_ai / c4_br;
        } else {
          c4_b_dc.re = c4_ar / c4_br;
          c4_b_dc.im = c4_ai / c4_br;
        }
      } else if (c4_br == 0.0) {
        if (c4_ar == 0.0) {
          c4_b_dc.re = c4_ai / c4_bi;
          c4_b_dc.im = 0.0;
        } else if (c4_ai == 0.0) {
          c4_b_dc.re = 0.0;
          c4_b_dc.im = -(c4_ar / c4_bi);
        } else {
          c4_b_dc.re = c4_ai / c4_bi;
          c4_b_dc.im = -(c4_ar / c4_bi);
        }
      } else {
        c4_brm = muDoubleScalarAbs(c4_br);
        c4_bim = muDoubleScalarAbs(c4_bi);
        if (c4_brm > c4_bim) {
          c4_b_s = c4_bi / c4_br;
          c4_b_d = c4_br + c4_b_s * c4_bi;
          c4_nr = c4_ar + c4_b_s * c4_ai;
          c4_ni = c4_ai - c4_b_s * c4_ar;
          c4_b_dc.re = c4_nr / c4_b_d;
          c4_b_dc.im = c4_ni / c4_b_d;
        } else if (c4_bim == c4_brm) {
          if (c4_br > 0.0) {
            c4_sgnbr = 0.5;
          } else {
            c4_sgnbr = -0.5;
          }

          if (c4_bi > 0.0) {
            c4_sgnbi = 0.5;
          } else {
            c4_sgnbi = -0.5;
          }

          c4_nr = c4_ar * c4_sgnbr + c4_ai * c4_sgnbi;
          c4_ni = c4_ai * c4_sgnbr - c4_ar * c4_sgnbi;
          c4_b_dc.re = c4_nr / c4_brm;
          c4_b_dc.im = c4_ni / c4_brm;
        } else {
          c4_b_s = c4_br / c4_bi;
          c4_b_d = c4_bi + c4_b_s * c4_br;
          c4_nr = c4_b_s * c4_ar + c4_ai;
          c4_ni = c4_b_s * c4_ai - c4_ar;
          c4_b_dc.re = c4_nr / c4_b_d;
          c4_b_dc.im = c4_ni / c4_b_d;
        }
      }

      c4_Opca[c4_i13] = c4_b_dc;
    }

    c4_lenE = (real_T)c4_Ex.size[0];
    memset(&c4_c_accumMatrix[0], 0, 19200U * sizeof(creal_T));
    c4_i14 = (int32_T)((c4_lenE + 32257.0) / 32258.0);
    emlrtForLoopVectorCheckR2021a(1.0, 32258.0, c4_lenE, mxDOUBLE_CLASS, c4_i14,
      &c4_wg_emlrtRTEI, (emlrtConstCTX)c4_sp);
    c4_array_real_T_Constructor(chartInstance, &c4_Ex_chunk);
    c4_array_real_T_Constructor(chartInstance, &c4_Ey_chunk);
    c4_array_real_T_Constructor(chartInstance, &c4_idxE_chunk);
    c4_array_real32_T_2D_Constructor(chartInstance, &c4_xc);
    c4_array_real32_T_2D_Constructor(chartInstance, &c4_yc);
    c4_array_creal_T_2D_Constructor(chartInstance, &c4_w);
    c4_array_boolean_T_2D_Constructor(chartInstance, &c4_inside);
    c4_array_int32_T_Constructor(chartInstance, &c4_xckeep);
    c4_array_int32_T_Constructor(chartInstance, &c4_yckeep);
    c4_array_creal_T_Constructor(chartInstance, &c4_wkeep);
    c4_array_real_T_2D_Constructor(chartInstance, &c4_r1);
    for (c4_b_i = 0; c4_b_i < c4_i14; c4_b_i++) {
      c4_c_i = (real_T)c4_b_i * 32258.0 + 1.0;
      c4_b_varargin_2 = c4_lenE;
      c4_b_y = c4_b_varargin_2;
      c4_c_y = c4_b_y;
      c4_d_y = c4_c_y;
      c4_f_b = c4_d_y;
      c4_e_y = c4_f_b;
      c4_f_y = c4_e_y;
      c4_minval = c4_f_y;
      c4_st.site = &c4_v_emlrtRSI;
      c4_b_a = c4_c_i;
      c4_c_d = c4_minval;
      c4_b_st.site = &c4_gb_emlrtRSI;
      c4_c_a = c4_b_a;
      c4_g_b = c4_c_d;
      if (c4_g_b < c4_c_a) {
        c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_r1,
          &c4_ib_emlrtRTEI, 1, 0);
      } else {
        c4_k_x = c4_c_a;
        c4_h_b = muDoubleScalarIsInf(c4_k_x);
        c4_guard1 = false;
        c4_guard2 = false;
        if (c4_h_b) {
          c4_guard2 = true;
        } else {
          c4_l_x = c4_g_b;
          c4_i_b = muDoubleScalarIsInf(c4_l_x);
          if (c4_i_b) {
            c4_guard2 = true;
          } else {
            c4_guard1 = true;
          }
        }

        if (c4_guard2) {
          if (c4_c_a == c4_g_b) {
            c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_r1,
              &c4_ib_emlrtRTEI, 1, 1);
            c4_r1.vector.data[0] = rtNaN;
          } else {
            c4_guard1 = true;
          }
        }

        if (c4_guard1) {
          c4_m_x = c4_c_a;
          c4_n_x = c4_m_x;
          c4_g_y = c4_n_x;
          c4_g_y = muDoubleScalarFloor(c4_g_y);
          if (c4_g_y == c4_c_a) {
            c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_r1,
              &c4_ib_emlrtRTEI, 1, (int32_T)(c4_g_b - c4_c_a) + 1);
            c4_g_loop_ub = (int32_T)(c4_g_b - c4_c_a);
            for (c4_i17 = 0; c4_i17 <= c4_g_loop_ub; c4_i17++) {
              c4_r1.vector.data[c4_i17] = c4_c_a + (real_T)c4_i17;
            }
          } else {
            c4_c_st.site = &c4_hb_emlrtRSI;
            c4_d_a = c4_c_a;
            c4_j_b = c4_g_b;
            c4_e_a = c4_d_a;
            c4_k_b = c4_j_b;
            c4_a1 = c4_e_a;
            c4_o_x = (c4_k_b - c4_e_a) + 0.5;
            c4_p_x = c4_o_x;
            c4_ndbl = c4_p_x;
            c4_ndbl = muDoubleScalarFloor(c4_ndbl);
            c4_apnd = c4_e_a + c4_ndbl;
            c4_cdiff = c4_apnd - c4_k_b;
            c4_f_a = c4_e_a;
            c4_l_b = c4_k_b;
            c4_q_x = c4_f_a;
            c4_r_x = c4_q_x;
            c4_s_x = c4_r_x;
            c4_h_y = muDoubleScalarAbs(c4_s_x);
            c4_t_x = c4_l_b;
            c4_u_x = c4_t_x;
            c4_v_x = c4_u_x;
            c4_i_y = muDoubleScalarAbs(c4_v_x);
            c4_c = muDoubleScalarMax(c4_h_y, c4_i_y);
            c4_thresh = 4.4408920985006262E-16 * c4_c;
            c4_x_x = c4_cdiff;
            c4_y_x = c4_x_x;
            c4_ab_x = c4_y_x;
            c4_j_y = muDoubleScalarAbs(c4_ab_x);
            if (c4_j_y < c4_thresh) {
              c4_ndbl++;
              c4_b1 = c4_k_b;
            } else if (c4_cdiff > 0.0) {
              c4_b1 = c4_e_a + (c4_ndbl - 1.0);
            } else {
              c4_ndbl++;
              c4_b1 = c4_apnd;
            }

            if (c4_ndbl >= 0.0) {
              c4_n = (int32_T)muDoubleScalarFloor(c4_ndbl);
            } else {
              c4_n = 0;
            }

            c4_array_real_T_2D_SetSize(chartInstance, &c4_c_st, &c4_r1,
              &c4_hb_emlrtRTEI, 1, c4_n);
            if (c4_n > 0) {
              c4_r1.vector.data[0] = c4_a1;
              if (c4_n > 1) {
                c4_r1.vector.data[c4_n - 1] = c4_b1;
                c4_nm1 = c4_n - 1;
                c4_h_a = c4_nm1;
                c4_nm1d2 = (uint16_T)((uint32_T)(uint16_T)c4_h_a >> 1);
                c4_i44 = c4_nm1d2 - 2;
                c4_d_st.site = &c4_ib_emlrtRSI;
                c4_p_b = c4_i44 + 1;
                c4_q_b = c4_p_b;
                if (c4_q_b < 1) {
                  c4_b_overflow = false;
                } else {
                  c4_b_overflow = (c4_q_b > 2147483646);
                }

                if (c4_b_overflow) {
                  c4_e_st.site = &c4_jb_emlrtRSI;
                  c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
                }

                for (c4_i_k = 0; c4_i_k <= c4_i44; c4_i_k++) {
                  c4_j_k = c4_i_k + 1;
                  c4_kd = (real_T)c4_j_k;
                  c4_r1.vector.data[c4_j_k] = c4_a1 + c4_kd;
                  c4_r1.vector.data[(c4_n - c4_j_k) - 1] = c4_b1 - c4_kd;
                }

                c4_r_b = c4_nm1d2;
                c4_o_y = c4_r_b << 1;
                if (c4_o_y == c4_nm1) {
                  c4_r1.vector.data[c4_nm1d2] = (c4_a1 + c4_b1) / 2.0;
                } else {
                  c4_kd = (real_T)c4_nm1d2;
                  c4_r1.vector.data[c4_nm1d2] = c4_a1 + c4_kd;
                  c4_r1.vector.data[c4_nm1d2 + 1] = c4_b1 - c4_kd;
                }
              }
            }
          }
        }
      }

      c4_sizeChunk = (real_T)c4_r1.size[1];
      c4_st.site = &c4_lh_emlrtRSI;
      c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_Ex_chunk,
        &c4_jb_emlrtRTEI, (int32_T)c4_sizeChunk);
      c4_st.site = &c4_kh_emlrtRSI;
      c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_Ey_chunk,
        &c4_kb_emlrtRTEI, (int32_T)c4_sizeChunk);
      c4_st.site = &c4_jh_emlrtRSI;
      c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_idxE_chunk,
        &c4_lb_emlrtRTEI, (int32_T)c4_sizeChunk);
      c4_idxEdge = (int32_T)c4_c_i;
      c4_i15 = (int32_T)c4_sizeChunk;
      for (c4_b_idx = 0; c4_b_idx < c4_i15; c4_b_idx++) {
        c4_c_idx = (real_T)c4_b_idx + 1.0;
        c4_i16 = c4_Ex.size[0];
        if ((c4_idxEdge < 1) || (c4_idxEdge > c4_i16)) {
          emlrtDynamicBoundsCheckR2012b(c4_idxEdge, 1, c4_i16, &c4_m_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_i18 = c4_Ex_chunk.size[0];
        c4_i19 = (int32_T)c4_c_idx;
        if ((c4_i19 < 1) || (c4_i19 > c4_i18)) {
          emlrtDynamicBoundsCheckR2012b(c4_i19, 1, c4_i18, &c4_n_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_Ex_chunk.vector.data[c4_i19 - 1] = c4_Ex.vector.data[c4_idxEdge - 1];
        c4_i20 = c4_Ey.size[0];
        if ((c4_idxEdge < 1) || (c4_idxEdge > c4_i20)) {
          emlrtDynamicBoundsCheckR2012b(c4_idxEdge, 1, c4_i20, &c4_o_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_i21 = c4_Ey_chunk.size[0];
        c4_i22 = (int32_T)c4_c_idx;
        if ((c4_i22 < 1) || (c4_i22 > c4_i21)) {
          emlrtDynamicBoundsCheckR2012b(c4_i22, 1, c4_i21, &c4_p_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_Ey_chunk.vector.data[c4_i22 - 1] = c4_Ey.vector.data[c4_idxEdge - 1];
        c4_i24 = c4_idxE.size[0];
        if ((c4_idxEdge < 1) || (c4_idxEdge > c4_i24)) {
          emlrtDynamicBoundsCheckR2012b(c4_idxEdge, 1, c4_i24, &c4_q_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_i26 = c4_idxE_chunk.size[0];
        c4_i28 = (int32_T)c4_c_idx;
        if ((c4_i28 < 1) || (c4_i28 > c4_i26)) {
          emlrtDynamicBoundsCheckR2012b(c4_i28, 1, c4_i26, &c4_r_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_idxE_chunk.vector.data[c4_i28 - 1] = c4_idxE.vector.data[c4_idxEdge -
          1];
        c4_idxEdge++;
      }

      c4_dim1 = (real_T)c4_idxE_chunk.size[0];
      c4_st.site = &c4_nh_emlrtRSI;
      c4_array_real32_T_2D_SetSize(chartInstance, &c4_st, &c4_xc,
        &c4_mb_emlrtRTEI, (int32_T)c4_dim1, 31);
      c4_st.site = &c4_mh_emlrtRSI;
      c4_array_real32_T_2D_SetSize(chartInstance, &c4_st, &c4_yc,
        &c4_nb_emlrtRTEI, (int32_T)c4_dim1, 31);
      c4_st.site = &c4_oh_emlrtRSI;
      c4_array_creal_T_2D_SetSize(chartInstance, &c4_st, &c4_w, &c4_ob_emlrtRTEI,
        (int32_T)c4_dim1, 31);
      c4_st.site = &c4_ch_emlrtRSI;
      c4_array_boolean_T_2D_SetSize(chartInstance, &c4_st, &c4_inside,
        &c4_pb_emlrtRTEI, (int32_T)c4_dim1, 31);
      c4_rows_to_keep_size[0] = (int32_T)c4_dim1;
      c4_h_loop_ub = (int32_T)c4_dim1 - 1;
      if (c4_h_loop_ub >= 0) {
        memset(&c4_rows_to_keep_data[0], 0, (uint32_T)(c4_h_loop_ub + 1) *
               sizeof(boolean_T));
      }

      for (c4_idx2 = 0; c4_idx2 < 31; c4_idx2++) {
        c4_b_idx2 = (real_T)c4_idx2 + 1.0;
        c4_i23 = (int32_T)c4_dim1;
        for (c4_idx1 = 0; c4_idx1 < c4_i23; c4_idx1++) {
          c4_b_idx1 = (real_T)c4_idx1 + 1.0;
          c4_i25 = c4_idxE_chunk.size[0];
          c4_i27 = (int32_T)c4_b_idx1;
          if ((c4_i27 < 1) || (c4_i27 > c4_i25)) {
            emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_i25, &c4_s_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_w_x = chartInstance->c4_Gx[(int32_T)
            c4_idxE_chunk.vector.data[c4_i27 - 1] - 1];
          c4_i29 = c4_idxE_chunk.size[0];
          c4_i31 = (int32_T)c4_b_idx1;
          if ((c4_i31 < 1) || (c4_i31 > c4_i29)) {
            emlrtDynamicBoundsCheckR2012b(c4_i31, 1, c4_i29, &c4_t_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_k_y = c4_b_gradientImg[(int32_T)c4_idxE_chunk.vector.data[c4_i31 -
            1] - 1];
          c4_bb_x = c4_w_x;
          c4_l_y = c4_k_y;
          c4_b_z = c4_bb_x / c4_l_y;
          c4_g_a = -(10.0 + 0.5 * (real_T)((int32_T)c4_b_idx2 - 1));
          c4_o_b = c4_b_z;
          c4_m_y = (real32_T)c4_g_a * c4_o_b;
          c4_i35 = c4_Ex_chunk.size[0];
          c4_i36 = (int32_T)c4_b_idx1;
          if ((c4_i36 < 1) || (c4_i36 > c4_i35)) {
            emlrtDynamicBoundsCheckR2012b(c4_i36, 1, c4_i35, &c4_u_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_cb_x = (real32_T)c4_Ex_chunk.vector.data[c4_i36 - 1] + c4_m_y;
          c4_db_x = c4_cb_x;
          c4_n_y = c4_db_x;
          c4_n_y = muSingleScalarRound(c4_n_y);
          c4_i43 = c4_xc.size[0];
          c4_i46 = (int32_T)c4_b_idx1;
          if ((c4_i46 < 1) || (c4_i46 > c4_i43)) {
            emlrtDynamicBoundsCheckR2012b(c4_i46, 1, c4_i43, &c4_x_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_xc.vector.data[(c4_i46 + c4_xc.size[0] * ((int32_T)c4_b_idx2 - 1))
            - 1] = c4_n_y;
          c4_i50 = c4_idxE_chunk.size[0];
          c4_i51 = (int32_T)c4_b_idx1;
          if ((c4_i51 < 1) || (c4_i51 > c4_i50)) {
            emlrtDynamicBoundsCheckR2012b(c4_i51, 1, c4_i50, &c4_y_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_eb_x = chartInstance->c4_Gy[(int32_T)
            c4_idxE_chunk.vector.data[c4_i51 - 1] - 1];
          c4_i55 = c4_idxE_chunk.size[0];
          c4_i56 = (int32_T)c4_b_idx1;
          if ((c4_i56 < 1) || (c4_i56 > c4_i55)) {
            emlrtDynamicBoundsCheckR2012b(c4_i56, 1, c4_i55, &c4_cb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_p_y = c4_b_gradientImg[(int32_T)c4_idxE_chunk.vector.data[c4_i56 -
            1] - 1];
          c4_fb_x = c4_eb_x;
          c4_q_y = c4_p_y;
          c4_c_z = c4_fb_x / c4_q_y;
          c4_i_a = -(10.0 + 0.5 * (real_T)((int32_T)c4_b_idx2 - 1));
          c4_s_b = c4_c_z;
          c4_r_y = (real32_T)c4_i_a * c4_s_b;
          c4_i65 = c4_Ey_chunk.size[0];
          c4_i66 = (int32_T)c4_b_idx1;
          if ((c4_i66 < 1) || (c4_i66 > c4_i65)) {
            emlrtDynamicBoundsCheckR2012b(c4_i66, 1, c4_i65, &c4_qb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_gb_x = (real32_T)c4_Ey_chunk.vector.data[c4_i66 - 1] + c4_r_y;
          c4_hb_x = c4_gb_x;
          c4_s_y = c4_hb_x;
          c4_s_y = muSingleScalarRound(c4_s_y);
          c4_i71 = c4_yc.size[0];
          c4_i72 = (int32_T)c4_b_idx1;
          if ((c4_i72 < 1) || (c4_i72 > c4_i71)) {
            emlrtDynamicBoundsCheckR2012b(c4_i72, 1, c4_i71, &c4_rb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_yc.vector.data[(c4_i72 + c4_yc.size[0] * ((int32_T)c4_b_idx2 - 1))
            - 1] = c4_s_y;
          c4_i74 = c4_w.size[0];
          c4_i76 = (int32_T)c4_b_idx1;
          if ((c4_i76 < 1) || (c4_i76 > c4_i74)) {
            emlrtDynamicBoundsCheckR2012b(c4_i76, 1, c4_i74, &c4_sb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_w.vector.data[(c4_i76 + c4_w.size[0] * ((int32_T)c4_b_idx2 - 1)) -
            1].re = c4_Opca[(int32_T)c4_b_idx2 - 1].re;
          c4_i78 = c4_w.size[0];
          c4_i79 = (int32_T)c4_b_idx1;
          if ((c4_i79 < 1) || (c4_i79 > c4_i78)) {
            emlrtDynamicBoundsCheckR2012b(c4_i79, 1, c4_i78, &c4_sb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_w.vector.data[(c4_i79 + c4_w.size[0] * ((int32_T)c4_b_idx2 - 1)) -
            1].im = c4_Opca[(int32_T)c4_b_idx2 - 1].im;
          c4_i82 = c4_xc.size[0];
          c4_i83 = (int32_T)c4_b_idx1;
          if ((c4_i83 < 1) || (c4_i83 > c4_i82)) {
            emlrtDynamicBoundsCheckR2012b(c4_i83, 1, c4_i82, &c4_tb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_t_b = (c4_xc.vector.data[(c4_i83 + c4_xc.size[0] * ((int32_T)
                      c4_b_idx2 - 1)) - 1] >= 1.0F);
          c4_i85 = c4_xc.size[0];
          c4_i86 = (int32_T)c4_b_idx1;
          if ((c4_i86 < 1) || (c4_i86 > c4_i85)) {
            emlrtDynamicBoundsCheckR2012b(c4_i86, 1, c4_i85, &c4_ub_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_b_b1 = (c4_xc.vector.data[(c4_i86 + c4_xc.size[0] * ((int32_T)
            c4_b_idx2 - 1)) - 1] <= 160.0F);
          c4_b2 = (c4_t_b && c4_b_b1);
          c4_i87 = c4_yc.size[0];
          c4_i88 = (int32_T)c4_b_idx1;
          if ((c4_i88 < 1) || (c4_i88 > c4_i87)) {
            emlrtDynamicBoundsCheckR2012b(c4_i88, 1, c4_i87, &c4_vb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_b3 = (c4_yc.vector.data[(c4_i88 + c4_yc.size[0] * ((int32_T)
                     c4_b_idx2 - 1)) - 1] >= 1.0F);
          c4_b4 = (c4_b2 && c4_b3);
          c4_i89 = c4_yc.size[0];
          c4_i90 = (int32_T)c4_b_idx1;
          if ((c4_i90 < 1) || (c4_i90 > c4_i89)) {
            emlrtDynamicBoundsCheckR2012b(c4_i90, 1, c4_i89, &c4_wb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_b5 = (c4_yc.vector.data[(c4_i90 + c4_yc.size[0] * ((int32_T)
                     c4_b_idx2 - 1)) - 1] <= 120.0F);
          c4_i91 = c4_inside.size[0];
          c4_i92 = (int32_T)c4_b_idx1;
          if ((c4_i92 < 1) || (c4_i92 > c4_i91)) {
            emlrtDynamicBoundsCheckR2012b(c4_i92, 1, c4_i91, &c4_xb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_inside.vector.data[(c4_i92 + c4_inside.size[0] * ((int32_T)
            c4_b_idx2 - 1)) - 1] = (c4_b4 && c4_b5);
          c4_i93 = c4_inside.size[0];
          c4_i94 = (int32_T)c4_b_idx1;
          if ((c4_i94 < 1) || (c4_i94 > c4_i93)) {
            emlrtDynamicBoundsCheckR2012b(c4_i94, 1, c4_i93, &c4_yb_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          if (c4_inside.vector.data[(c4_i94 + c4_inside.size[0] * ((int32_T)
                c4_b_idx2 - 1)) - 1]) {
            c4_i95 = (int32_T)c4_b_idx1;
            if ((c4_i95 < 1) || (c4_i95 > c4_rows_to_keep_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c4_i95, 1, c4_rows_to_keep_size[0],
                &c4_ac_emlrtBCI, (emlrtConstCTX)c4_sp);
            }

            c4_rows_to_keep_data[c4_i95 - 1] = true;
          }
        }
      }

      c4_dim1 = (real_T)c4_idxE_chunk.size[0];
      c4_st.site = &c4_ih_emlrtRSI;
      c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_xckeep,
        &c4_rb_emlrtRTEI, c4_xc.size[0] * 31);
      c4_st.site = &c4_hh_emlrtRSI;
      c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_yckeep,
        &c4_sb_emlrtRTEI, c4_yc.size[0] * 31);
      c4_st.site = &c4_ah_emlrtRSI;
      c4_array_creal_T_SetSize(chartInstance, &c4_st, &c4_wkeep,
        &c4_tb_emlrtRTEI, c4_w.size[0] * 31);
      c4_idxkeep = 0;
      for (c4_c_idx2 = 0; c4_c_idx2 < 31; c4_c_idx2++) {
        c4_b_idx2 = (real_T)c4_c_idx2 + 1.0;
        c4_i30 = (int32_T)c4_dim1;
        for (c4_c_idx1 = 0; c4_c_idx1 < c4_i30; c4_c_idx1++) {
          c4_b_idx1 = (real_T)c4_c_idx1 + 1.0;
          c4_i32 = (int32_T)c4_b_idx1;
          if ((c4_i32 < 1) || (c4_i32 > c4_rows_to_keep_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c4_i32, 1, c4_rows_to_keep_size[0],
              &c4_v_emlrtBCI, (emlrtConstCTX)c4_sp);
          }

          if (c4_rows_to_keep_data[c4_i32 - 1]) {
            c4_i33 = c4_inside.size[0];
            c4_i34 = (int32_T)c4_b_idx1;
            if ((c4_i34 < 1) || (c4_i34 > c4_i33)) {
              emlrtDynamicBoundsCheckR2012b(c4_i34, 1, c4_i33, &c4_w_emlrtBCI,
                (emlrtConstCTX)c4_sp);
            }

            if (c4_inside.vector.data[(c4_i34 + c4_inside.size[0] * ((int32_T)
                  c4_b_idx2 - 1)) - 1]) {
              c4_idxkeep++;
              c4_i39 = c4_xc.size[0];
              c4_i40 = (int32_T)c4_b_idx1;
              if ((c4_i40 < 1) || (c4_i40 > c4_i39)) {
                emlrtDynamicBoundsCheckR2012b(c4_i40, 1, c4_i39, &c4_ab_emlrtBCI,
                  (emlrtConstCTX)c4_sp);
              }

              c4_i42 = c4_xckeep.size[0];
              if ((c4_idxkeep < 1) || (c4_idxkeep > c4_i42)) {
                emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1, c4_i42,
                  &c4_bb_emlrtBCI, (emlrtConstCTX)c4_sp);
              }

              c4_xckeep.vector.data[c4_idxkeep - 1] = (int32_T)
                c4_xc.vector.data[(c4_i40 + c4_xc.size[0] * ((int32_T)c4_b_idx2
                - 1)) - 1];
              c4_i48 = c4_yc.size[0];
              c4_i49 = (int32_T)c4_b_idx1;
              if ((c4_i49 < 1) || (c4_i49 > c4_i48)) {
                emlrtDynamicBoundsCheckR2012b(c4_i49, 1, c4_i48, &c4_db_emlrtBCI,
                  (emlrtConstCTX)c4_sp);
              }

              c4_i53 = c4_yckeep.size[0];
              if ((c4_idxkeep < 1) || (c4_idxkeep > c4_i53)) {
                emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1, c4_i53,
                  &c4_eb_emlrtBCI, (emlrtConstCTX)c4_sp);
              }

              c4_yckeep.vector.data[c4_idxkeep - 1] = (int32_T)
                c4_yc.vector.data[(c4_i49 + c4_yc.size[0] * ((int32_T)c4_b_idx2
                - 1)) - 1];
              c4_i57 = c4_wkeep.size[0];
              if ((c4_idxkeep < 1) || (c4_idxkeep > c4_i57)) {
                emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1, c4_i57,
                  &c4_gb_emlrtBCI, (emlrtConstCTX)c4_sp);
              }

              c4_i59 = c4_w.size[0];
              c4_i61 = (int32_T)c4_b_idx1;
              if ((c4_i61 < 1) || (c4_i61 > c4_i59)) {
                emlrtDynamicBoundsCheckR2012b(c4_i61, 1, c4_i59, &c4_fb_emlrtBCI,
                  (emlrtConstCTX)c4_sp);
              }

              c4_wkeep.vector.data[c4_idxkeep - 1].re = c4_w.vector.data[(c4_i61
                + c4_w.size[0] * ((int32_T)c4_b_idx2 - 1)) - 1].re;
              c4_i63 = c4_w.size[0];
              c4_i64 = (int32_T)c4_b_idx1;
              if ((c4_i64 < 1) || (c4_i64 > c4_i63)) {
                emlrtDynamicBoundsCheckR2012b(c4_i64, 1, c4_i63, &c4_fb_emlrtBCI,
                  (emlrtConstCTX)c4_sp);
              }

              c4_i68 = c4_wkeep.size[0];
              if ((c4_idxkeep < 1) || (c4_idxkeep > c4_i68)) {
                emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1, c4_i68,
                  &c4_gb_emlrtBCI, (emlrtConstCTX)c4_sp);
              }

              c4_wkeep.vector.data[c4_idxkeep - 1].im = c4_w.vector.data[(c4_i64
                + c4_w.size[0] * ((int32_T)c4_b_idx2 - 1)) - 1].im;
            }
          }
        }
      }

      c4_st.site = &c4_w_emlrtRSI;
      c4_szxc = c4_idxkeep;
      memset(&chartInstance->c4_out[0], 0, 19200U * sizeof(creal_T));
      c4_b_st.site = &c4_kb_emlrtRSI;
      c4_m_b = c4_szxc;
      c4_n_b = c4_m_b;
      if (c4_n_b < 1) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_n_b > 2147483646);
      }

      if (c4_overflow) {
        c4_c_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_d_idx = 0; c4_d_idx < c4_szxc; c4_d_idx++) {
        c4_e_idx = c4_d_idx + 1;
        c4_i38 = c4_yckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i38)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i38, &c4_nb_emlrtBCI,
            &c4_st);
        }

        c4_i41 = c4_yckeep.vector.data[c4_e_idx - 1];
        if ((c4_i41 < 1) || (c4_i41 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c4_i41, 1, 120, &c4_mb_emlrtBCI, &c4_st);
        }

        c4_i45 = c4_xckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i45)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i45, &c4_pb_emlrtBCI,
            &c4_st);
        }

        c4_i47 = c4_xckeep.vector.data[c4_e_idx - 1];
        if ((c4_i47 < 1) || (c4_i47 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i47, 1, 160, &c4_ob_emlrtBCI, &c4_st);
        }

        c4_i52 = c4_yckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i52)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i52, &c4_ib_emlrtBCI,
            &c4_st);
        }

        c4_i54 = c4_yckeep.vector.data[c4_e_idx - 1];
        if ((c4_i54 < 1) || (c4_i54 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c4_i54, 1, 120, &c4_hb_emlrtBCI, &c4_st);
        }

        c4_i58 = c4_xckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i58)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i58, &c4_kb_emlrtBCI,
            &c4_st);
        }

        c4_i60 = c4_xckeep.vector.data[c4_e_idx - 1];
        if ((c4_i60 < 1) || (c4_i60 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i60, 1, 160, &c4_jb_emlrtBCI, &c4_st);
        }

        c4_i62 = c4_wkeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i62)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i62, &c4_lb_emlrtBCI,
            &c4_st);
        }

        chartInstance->c4_out[(c4_i41 + 120 * (c4_i47 - 1)) - 1].re =
          chartInstance->c4_out[(c4_i54 + 120 * (c4_i60 - 1)) - 1].re +
          c4_wkeep.vector.data[c4_e_idx - 1].re;
        c4_i67 = c4_yckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i67)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i67, &c4_ib_emlrtBCI,
            &c4_st);
        }

        c4_i69 = c4_yckeep.vector.data[c4_e_idx - 1];
        if ((c4_i69 < 1) || (c4_i69 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c4_i69, 1, 120, &c4_hb_emlrtBCI, &c4_st);
        }

        c4_i70 = c4_xckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i70)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i70, &c4_kb_emlrtBCI,
            &c4_st);
        }

        c4_i73 = c4_xckeep.vector.data[c4_e_idx - 1];
        if ((c4_i73 < 1) || (c4_i73 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i73, 1, 160, &c4_jb_emlrtBCI, &c4_st);
        }

        c4_i75 = c4_wkeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i75)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i75, &c4_lb_emlrtBCI,
            &c4_st);
        }

        c4_i77 = c4_yckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i77)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i77, &c4_nb_emlrtBCI,
            &c4_st);
        }

        c4_i80 = c4_yckeep.vector.data[c4_e_idx - 1];
        if ((c4_i80 < 1) || (c4_i80 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c4_i80, 1, 120, &c4_mb_emlrtBCI, &c4_st);
        }

        c4_i81 = c4_xckeep.size[0];
        if ((c4_e_idx < 1) || (c4_e_idx > c4_i81)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i81, &c4_pb_emlrtBCI,
            &c4_st);
        }

        c4_i84 = c4_xckeep.vector.data[c4_e_idx - 1];
        if ((c4_i84 < 1) || (c4_i84 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i84, 1, 160, &c4_ob_emlrtBCI, &c4_st);
        }

        chartInstance->c4_out[(c4_i80 + 120 * (c4_i84 - 1)) - 1].im =
          chartInstance->c4_out[(c4_i69 + 120 * (c4_i73 - 1)) - 1].im +
          c4_wkeep.vector.data[c4_e_idx - 1].im;
      }

      for (c4_i37 = 0; c4_i37 < 19200; c4_i37++) {
        c4_c_accumMatrix[c4_i37].re += chartInstance->c4_out[c4_i37].re;
        c4_c_accumMatrix[c4_i37].im += chartInstance->c4_out[c4_i37].im;
      }
    }

    c4_array_real_T_Destructor(chartInstance, &c4_Ex);
    c4_array_real_T_Destructor(chartInstance, &c4_Ey);
    c4_array_real_T_2D_Destructor(chartInstance, &c4_r1);
    c4_array_creal_T_Destructor(chartInstance, &c4_wkeep);
    c4_array_int32_T_Destructor(chartInstance, &c4_yckeep);
    c4_array_int32_T_Destructor(chartInstance, &c4_xckeep);
    c4_array_boolean_T_2D_Destructor(chartInstance, &c4_inside);
    c4_array_creal_T_2D_Destructor(chartInstance, &c4_w);
    c4_array_real32_T_2D_Destructor(chartInstance, &c4_yc);
    c4_array_real32_T_2D_Destructor(chartInstance, &c4_xc);
    c4_array_real_T_Destructor(chartInstance, &c4_idxE_chunk);
    c4_array_real_T_Destructor(chartInstance, &c4_Ey_chunk);
    c4_array_real_T_Destructor(chartInstance, &c4_Ex_chunk);
    c4_array_real_T_Destructor(chartInstance, &c4_idxE);
  }
}

static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp)
{
  static char_T c4_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c4_sp, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
              (c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c4_sp, NULL,
    "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
}

static void c4_eml_find(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_b_x[19200], c4_coder_array_int32_T *c4_i,
  c4_coder_array_int32_T *c4_j)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_iv2[2];
  int32_T c4_b_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_idx;
  int32_T c4_ii;
  int32_T c4_jj;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_exitg1;
  boolean_T c4_guard1;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_ab_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_idx = 0;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_i, &c4_ub_emlrtRTEI, 19200);
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_j, &c4_vb_emlrtRTEI, 19200);
  c4_ii = 1;
  c4_jj = 1;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_jj <= 160)) {
    c4_guard1 = false;
    if (c4_b_x[(c4_ii + 120 * (c4_jj - 1)) - 1]) {
      c4_idx++;
      c4_i->vector.data[c4_idx - 1] = c4_ii;
      c4_j->vector.data[c4_idx - 1] = c4_jj;
      if (c4_idx >= 19200) {
        c4_exitg1 = true;
      } else {
        c4_guard1 = true;
      }
    } else {
      c4_guard1 = true;
    }

    if (c4_guard1) {
      c4_ii++;
      if (c4_ii > 120) {
        c4_ii = 1;
        c4_jj++;
      }
    }
  }

  c4_b = (c4_idx < 1);
  if (c4_b) {
    c4_b_i = 0;
  } else {
    c4_b_i = c4_idx;
  }

  c4_b_iv[0] = 1;
  c4_b_iv[1] = c4_b_i;
  c4_b_st.site = &c4_db_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, 19200, c4_b_iv);
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_i, &c4_wb_emlrtRTEI, c4_b_i);
  c4_b1 = (c4_idx < 1);
  if (c4_b1) {
    c4_i1 = 0;
  } else {
    c4_i1 = c4_idx;
  }

  c4_iv1[0] = 1;
  c4_iv1[1] = c4_i1;
  c4_b_st.site = &c4_cb_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, 19200, c4_iv1);
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_j, &c4_xb_emlrtRTEI, c4_i1);
  c4_b2 = (c4_idx < 1);
  if (c4_b2) {
    c4_i2 = 0;
  } else {
    c4_i2 = c4_idx;
  }

  c4_iv2[0] = 1;
  c4_iv2[1] = c4_i2;
  c4_b_st.site = &c4_bb_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, 19200, c4_iv2);
}

static void c4_indexShapeCheck(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T
  c4_indexSize[2])
{
  static char_T c4_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_size1;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_c;
  boolean_T c4_c;
  boolean_T c4_nonSingletonDimFound;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_size1 = c4_matrixSize;
  if (c4_size1 != 1) {
    c4_b = false;
  } else {
    c4_b = true;
  }

  if (c4_b) {
    c4_nonSingletonDimFound = false;
    if (c4_indexSize[1] != 1) {
      c4_nonSingletonDimFound = true;
    }

    c4_b_b = c4_nonSingletonDimFound;
    if (c4_b_b) {
      c4_c = true;
    } else {
      c4_c = false;
    }
  } else {
    c4_c = false;
  }

  c4_st.site = &c4_eb_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }
}

static void c4_sub2ind(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_varargin_1,
  c4_coder_array_real_T *c4_varargin_2, c4_coder_array_int32_T *c4_idx)
{
  static char_T c4_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c4_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  c4_coder_array_int32_T c4_b;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_varargin_1[2];
  real_T c4_b_varargin_2[2];
  real_T c4_b_k;
  real_T c4_x1;
  real_T c4_x2;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_k;
  int32_T c4_loop_ub;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  if (!c4_allinrange(chartInstance, c4_varargin_1, 120)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c4_sp, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_b_varargin_1[0] = (real_T)c4_varargin_1->size[0];
  c4_b_varargin_1[1] = 1.0;
  c4_b_varargin_2[0] = (real_T)c4_varargin_2->size[0];
  c4_b_varargin_2[1] = 1.0;
  c4_p = false;
  c4_b_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 2)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x1 = c4_b_varargin_1[(int32_T)c4_b_k - 1];
    c4_x2 = c4_b_varargin_2[(int32_T)c4_b_k - 1];
    c4_c_p = (c4_x1 == c4_x2);
    if (!c4_c_p) {
      c4_b_p = false;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (c4_b_p) {
    c4_p = true;
  }

  if (!c4_p) {
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    sf_mex_call(c4_sp, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_e_y)));
  }

  if (!c4_allinrange(chartInstance, c4_varargin_2, 160)) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c4_sp, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_f_y)));
  }

  c4_st.site = &c4_gh_emlrtRSI;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_idx, &c4_yb_emlrtRTEI,
    c4_varargin_1->size[0]);
  c4_loop_ub = c4_varargin_1->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_idx->vector.data[c4_i] = (int32_T)c4_varargin_1->vector.data[c4_i];
  }

  c4_array_int32_T_Constructor(chartInstance, &c4_b);
  c4_st.site = &c4_fh_emlrtRSI;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_b, &c4_ac_emlrtRTEI,
    c4_varargin_2->size[0]);
  c4_b_loop_ub = c4_varargin_2->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
    c4_b.vector.data[c4_i1] = (int32_T)c4_varargin_2->vector.data[c4_i1] - 1;
  }

  c4_c_loop_ub = c4_b.size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_c_loop_ub; c4_i2++) {
    c4_b.vector.data[c4_i2] *= 120;
  }

  c4_d_loop_ub = c4_idx->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_d_loop_ub; c4_i3++) {
    c4_idx->vector.data[c4_i3] += c4_b.vector.data[c4_i3];
  }

  c4_array_int32_T_Destructor(chartInstance, &c4_b);
}

static boolean_T c4_allinrange(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_b_x, int32_T c4_hi)
{
  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_p;
  (void)chartInstance;
  c4_d = (real_T)c4_b_x->size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  do {
    c4_exitg1 = 0;
    if (c4_k <= c4_i) {
      c4_b_k = (real_T)c4_k + 1.0;
      if ((c4_b_x->vector.data[(int32_T)c4_b_k - 1] >= 1.0) &&
          (c4_b_x->vector.data[(int32_T)c4_b_k - 1] <= (real_T)c4_hi)) {
        c4_b = true;
      } else {
        c4_b = false;
      }

      if (!c4_b) {
        c4_p = false;
        c4_exitg1 = 1;
      } else {
        c4_k++;
      }
    } else {
      c4_p = true;
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  return c4_p;
}

static void c4_chcenters(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, creal_T c4_varargin_1[19200],
  c4_coder_array_real_T_2D *c4_centers, c4_coder_array_real_T_2D *c4_metric)
{
  static int32_T c4_offsets[25] = { -250, -249, -248, -247, -246, -126, -125,
    -124, -123, -122, -2, -1, 0, 1, 2, 122, 123, 124, 125, 126, 246, 247, 248,
    249, 250 };

  static char_T c4_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c4_b_cv3[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c',
    'h' };

  static char_T c4_b_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c4_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  c4_coder_array_int32_T c4_r;
  c4_coder_array_int32_T_2D c4_iidx;
  c4_coder_array_real_T c4_b_centers;
  c4_coder_array_real_T c4_c_centers;
  c4_coder_array_real_T c4_ndx;
  c4_coder_array_real_T c4_varargin_2;
  c4_coder_array_real_T_2D c4_e_centers;
  c4_coder_array_real_T_2D c4_f_x;
  c4_coder_array_real_T_2D c4_j_x;
  c4_coder_array_real_T_2D c4_sortIdx;
  c4_coder_array_sOA5t73y81YtFHGIDxk c4_b_s;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  creal_T c4_b_x;
  real_T c4_domainSizeT[2];
  real_T c4_sizeB[2];
  real_T c4_startIdxT[2];
  real_T c4_a;
  real_T c4_b;
  real_T c4_b_a;
  real_T c4_b_accumMatrixRe;
  real_T c4_b_idx;
  real_T c4_c_a;
  real_T c4_c_j;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_a;
  real_T c4_d_i;
  real_T c4_d_k;
  real_T c4_d_x;
  real_T c4_e_a;
  real_T c4_e_x;
  real_T c4_f_k;
  real_T c4_g_x;
  real_T c4_h_k;
  real_T c4_h_x;
  real_T c4_x1;
  real_T c4_x2;
  real_T c4_y;
  int32_T c4_b_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_tmp_data[2];
  int32_T c4_b_sortIdx[1];
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_c;
  int32_T c4_c_c;
  int32_T c4_c_i;
  int32_T c4_c_idx;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_c;
  int32_T c4_d_centers;
  int32_T c4_d_idx;
  int32_T c4_d_j;
  int32_T c4_d_loop_ub;
  int32_T c4_e_i;
  int32_T c4_e_idx;
  int32_T c4_e_j;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_f_a;
  int32_T c4_f_i;
  int32_T c4_f_idx;
  int32_T c4_f_j;
  int32_T c4_f_loop_ub;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_g_i;
  int32_T c4_g_idx;
  int32_T c4_g_j;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_g_y;
  int32_T c4_h_b;
  int32_T c4_h_i;
  int32_T c4_h_j;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_loop_ub;
  int32_T c4_i_x;
  int32_T c4_idx;
  int32_T c4_j;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n;
  int32_T c4_nrows;
  int32_T c4_nrowx;
  boolean_T c4_bw[19200];
  boolean_T c4_x_data[19200];
  boolean_T c4_conn[9];
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_flat;
  boolean_T c4_guard1;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_st.site = &c4_rg_emlrtRSI;
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers, &c4_bc_emlrtRTEI,
    0, 0);
  c4_st.site = &c4_qg_emlrtRSI;
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric, &c4_cc_emlrtRTEI,
    0, 0);
  for (c4_k = 0; c4_k < 19200; c4_k++) {
    c4_b_k = c4_k;
    c4_b_x = c4_varargin_1[c4_b_k];
    c4_x1 = c4_b_x.re;
    c4_x2 = c4_b_x.im;
    c4_a = c4_x1;
    c4_b = c4_x2;
    c4_y = muDoubleScalarHypot(c4_a, c4_b);
    chartInstance->c4_accumMatrixRe[c4_b_k] = c4_y;
  }

  c4_b_accumMatrixRe = chartInstance->c4_accumMatrixRe[0];
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_bw[c4_i] = (chartInstance->c4_accumMatrixRe[c4_i] == c4_b_accumMatrixRe);
  }

  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_x_data[c4_i1] = c4_bw[c4_i1];
  }

  c4_flat = true;
  c4_c_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k < 19200)) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    if (!c4_x_data[(int32_T)c4_d_k - 1]) {
      c4_flat = false;
      c4_exitg1 = true;
    } else {
      c4_c_k++;
    }
  }

  if (!c4_flat) {
    c4_st.site = &c4_lb_emlrtRSI;
    c4_b_st.site = &c4_sb_emlrtRSI;
    for (c4_j = 0; c4_j < 2; c4_j++) {
      c4_c_j = (real_T)c4_j + 1.0;
      for (c4_b_i = 0; c4_b_i < 124; c4_b_i++) {
        c4_d_i = (real_T)c4_b_i + 1.0;
        chartInstance->c4_Apad[((int32_T)c4_d_i + 124 * ((int32_T)c4_c_j - 1)) -
          1] = 0.0;
      }
    }

    for (c4_b_j = 0; c4_b_j < 2; c4_b_j++) {
      for (c4_c_i = 0; c4_c_i < 124; c4_c_i++) {
        c4_d_i = (real_T)c4_c_i + 1.0;
        chartInstance->c4_Apad[((int32_T)c4_d_i + 124 * (c4_b_j + 162)) - 1] =
          0.0;
      }
    }

    for (c4_d_j = 0; c4_d_j < 160; c4_d_j++) {
      c4_c_j = (real_T)c4_d_j + 1.0;
      for (c4_e_i = 0; c4_e_i < 2; c4_e_i++) {
        c4_d_i = (real_T)c4_e_i + 1.0;
        c4_b_a = c4_c_j;
        c4_c = (int32_T)c4_b_a;
        chartInstance->c4_Apad[((int32_T)c4_d_i + 124 * (c4_c + 1)) - 1] = 0.0;
      }
    }

    for (c4_e_j = 0; c4_e_j < 160; c4_e_j++) {
      c4_c_j = (real_T)c4_e_j + 1.0;
      for (c4_f_i = 0; c4_f_i < 2; c4_f_i++) {
        c4_c_a = c4_c_j;
        c4_b_c = (int32_T)c4_c_a;
        chartInstance->c4_Apad[(c4_f_i + 124 * (c4_b_c + 1)) + 122] = 0.0;
      }
    }

    for (c4_f_j = 0; c4_f_j < 160; c4_f_j++) {
      c4_c_j = (real_T)c4_f_j + 1.0;
      for (c4_g_i = 0; c4_g_i < 120; c4_g_i++) {
        c4_d_i = (real_T)c4_g_i + 1.0;
        c4_d_a = c4_d_i;
        c4_c_c = (int32_T)c4_d_a;
        c4_e_a = c4_c_j;
        c4_d_c = (int32_T)c4_e_a;
        chartInstance->c4_Apad[(c4_c_c + 124 * (c4_d_c + 1)) + 1] =
          chartInstance->c4_accumMatrixRe[((int32_T)c4_d_i + 120 * ((int32_T)
          c4_c_j - 1)) - 1];
      }
    }

    c4_c_st.site = &c4_tb_emlrtRSI;
    c4_d_st.site = &c4_ub_emlrtRSI;
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_domainSizeT[c4_i2] = 5.0;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_startIdxT[c4_i3] = 2.0;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_sizeB[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    ordfilt2_real64(&chartInstance->c4_Apad[0], 124.0, &c4_startIdxT[0],
                    &c4_offsets[0], 25.0, &c4_domainSizeT[0], 12.0,
                    &chartInstance->c4_Hd[0], &c4_sizeB[0], true);
    c4_st.site = &c4_mb_emlrtRSI;
    c4_b_st.site = &c4_vb_emlrtRSI;
    for (c4_i5 = 0; c4_i5 < 19200; c4_i5++) {
      chartInstance->c4_marker[c4_i5] = chartInstance->c4_Hd[c4_i5] -
        0.099999999999999964;
    }

    c4_c_st.site = &c4_wb_emlrtRSI;
    c4_validateattributes(chartInstance, &c4_c_st, chartInstance->c4_marker);
    c4_c_st.site = &c4_xb_emlrtRSI;
    c4_validateattributes(chartInstance, &c4_c_st, chartInstance->c4_Hd);
    c4_c_st.site = &c4_yb_emlrtRSI;
    for (c4_i6 = 0; c4_i6 < 19200; c4_i6++) {
      chartInstance->c4_mask[c4_i6] = chartInstance->c4_Hd[c4_i6];
    }

    for (c4_i7 = 0; c4_i7 < 19200; c4_i7++) {
      chartInstance->c4_Hd[c4_i7] = chartInstance->c4_marker[c4_i7];
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_domainSizeT[c4_i8] = 120.0 + 40.0 * (real_T)c4_i8;
    }

    ippreconstruct_real64(&chartInstance->c4_Hd[0], &chartInstance->c4_mask[0],
                          &c4_domainSizeT[0], 2.0);
    c4_st.site = &c4_nb_emlrtRSI;
    c4_b_st.site = &c4_bc_emlrtRSI;
    c4_c_st.site = &c4_ac_emlrtRSI;
    c4_p = true;
    c4_e_k = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_e_k < 19200)) {
      c4_f_k = (real_T)c4_e_k + 1.0;
      c4_c_x = chartInstance->c4_Hd[(int32_T)c4_f_k - 1];
      c4_d_x = c4_c_x;
      c4_c_b = muDoubleScalarIsNaN(c4_d_x);
      c4_b_p = !c4_c_b;
      if (c4_b_p) {
        c4_e_k++;
      } else {
        c4_p = false;
        c4_exitg1 = true;
      }
    }

    if (c4_p) {
      c4_b_b = true;
    } else {
      c4_b_b = false;
    }

    if (!c4_b_b) {
      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 35),
                    false);
      c4_c_y = NULL;
      sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 46),
                    false);
      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1, 0U, 2, 1,
        18), false);
      sf_mex_call(&c4_c_st, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                  sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c4_c_st, NULL, "message", 1U, 2U, 14, c4_c_y, 14, c4_d_y)));
    }

    c4_b_st.site = &c4_cc_emlrtRSI;
    for (c4_g_k = 0; c4_g_k < 19200; c4_g_k++) {
      c4_h_k = (real_T)c4_g_k + 1.0;
      c4_e_x = chartInstance->c4_Hd[(int32_T)c4_h_k - 1];
      c4_d_b = muDoubleScalarIsNaN(c4_e_x);
      if (c4_d_b) {
        c4_e_y = NULL;
        sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1, 0U, 2, 1,
          19), false);
        c4_f_y = NULL;
        sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1, 0U, 2, 1,
          19), false);
        sf_mex_call(&c4_b_st, &c4_f_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                    sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_b_st, NULL, "message", 1U, 1U, 14, c4_f_y)));
      }
    }

    c4_b_st.site = &c4_dc_emlrtRSI;
    for (c4_i9 = 0; c4_i9 < 9; c4_i9++) {
      c4_conn[c4_i9] = true;
    }

    for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
      c4_domainSizeT[c4_i10] = 120.0 + 40.0 * (real_T)c4_i10;
    }

    for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
      c4_startIdxT[c4_i11] = 3.0;
    }

    imregionalmax_real64(&chartInstance->c4_Hd[0], &c4_bw[0], 2.0,
                         &c4_domainSizeT[0], &c4_conn[0], 2.0, &c4_startIdxT[0]);
    c4_array_sOA5t73y81YtFHGIDxk0fKF_C(chartInstance, &c4_b_s);
    c4_st.site = &c4_ob_emlrtRSI;
    c4_regionprops(chartInstance, &c4_st, c4_bw, chartInstance->c4_accumMatrixRe,
                   &c4_b_s);
    if (c4_b_s.size[0] != 0) {
      c4_st.site = &c4_pg_emlrtRSI;
      c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers,
        &c4_dc_emlrtRTEI, c4_b_s.size[0], 2);
      c4_d = (real_T)c4_b_s.size[0];
      c4_i12 = (int32_T)c4_d;
      for (c4_idx = 0; c4_idx < c4_i12; c4_idx++) {
        c4_b_idx = (real_T)c4_idx + 1.0;
        c4_i14 = c4_centers->size[0];
        c4_i15 = (int32_T)c4_b_idx;
        if ((c4_i15 < 1) || (c4_i15 > c4_i14)) {
          emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_i14, &c4_bc_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_i16 = c4_i15;
        for (c4_i17 = 0; c4_i17 < 2; c4_i17++) {
          c4_tmp_data[c4_i17] = c4_i17;
        }

        for (c4_i20 = 0; c4_i20 < 2; c4_i20++) {
          c4_b_iv[c4_i20] = 1 + c4_i20;
        }

        for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
          c4_iv1[c4_i21] = 1 + c4_i21;
        }

        emlrtSubAssignSizeCheckR2012b(&c4_b_iv[0], 2, &c4_iv1[0], 2,
          &c4_emlrtECI, (void *)c4_sp);
        c4_i22 = c4_i16 - 1;
        for (c4_i23 = 0; c4_i23 < 2; c4_i23++) {
          c4_i27 = c4_b_s.size[0];
          c4_i28 = (int32_T)c4_b_idx;
          if ((c4_i28 < 1) || (c4_i28 > c4_i27)) {
            emlrtDynamicBoundsCheckR2012b(c4_i28, 1, c4_i27, &c4_dc_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_centers->vector.data[c4_i22 + c4_centers->size[0] *
            c4_tmp_data[c4_i23]] = c4_b_s.vector.data[c4_i28 - 1].
            WeightedCentroid[c4_i23];
        }
      }

      c4_d1 = (real_T)c4_centers->size[0];
      c4_i13 = (int32_T)-((-1.0 - c4_d1) + 1.0);
      emlrtForLoopVectorCheckR2021a(c4_d1, -1.0, 1.0, mxDOUBLE_CLASS, c4_i13,
        &c4_xg_emlrtRTEI, (emlrtConstCTX)c4_sp);
      c4_array_real_T_2D_Constructor(chartInstance, &c4_f_x);
      for (c4_c_idx = 0; c4_c_idx < c4_i13; c4_c_idx++) {
        c4_b_idx = c4_d1 - (real_T)c4_c_idx;
        c4_i18 = c4_centers->size[0];
        c4_i19 = (int32_T)c4_b_idx;
        if ((c4_i19 < 1) || (c4_i19 > c4_i18)) {
          emlrtDynamicBoundsCheckR2012b(c4_i19, 1, c4_i18, &c4_cc_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_g_x = c4_centers->vector.data[c4_i19 - 1];
        c4_e_b = muDoubleScalarIsNaN(c4_g_x);
        c4_guard1 = false;
        if (c4_e_b) {
          c4_guard1 = true;
        } else {
          c4_i25 = c4_centers->size[0];
          c4_i26 = (int32_T)c4_b_idx;
          if ((c4_i26 < 1) || (c4_i26 > c4_i25)) {
            emlrtDynamicBoundsCheckR2012b(c4_i26, 1, c4_i25, &c4_ec_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_h_x = c4_centers->vector.data[(c4_i26 + c4_centers->size[0]) - 1];
          c4_f_b = muDoubleScalarIsNaN(c4_h_x);
          if (c4_f_b) {
            c4_guard1 = true;
          }
        }

        if (c4_guard1) {
          c4_st.site = &c4_pb_emlrtRSI;
          c4_b_st.site = &c4_pb_emlrtRSI;
          c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_f_x,
            &c4_fc_emlrtRTEI, c4_centers->size[0], c4_centers->size[1]);
          c4_b_loop_ub = c4_centers->size[0] * c4_centers->size[1] - 1;
          for (c4_i29 = 0; c4_i29 <= c4_b_loop_ub; c4_i29++) {
            c4_f_x.vector.data[c4_i29] = c4_centers->vector.data[c4_i29];
          }

          c4_d_idx = (int32_T)c4_b_idx;
          c4_b_st.site = &c4_he_emlrtRSI;
          c4_e_idx = c4_d_idx;
          c4_f_idx = c4_e_idx;
          c4_n = c4_f_x.size[0];
          c4_c_p = true;
          if (c4_f_idx > c4_n) {
            c4_c_p = false;
          } else {
            c4_i_x = c4_f_idx;
            c4_g_y = c4_i_x;
            if (c4_f_idx != c4_g_y) {
              c4_c_p = false;
            }
          }

          if (!c4_c_p) {
            c4_h_y = NULL;
            sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1, 0U, 2,
              1, 25), false);
            c4_i_y = NULL;
            sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1, 0U, 2,
              1, 25), false);
            sf_mex_call(&c4_b_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_h_y,
                        14, sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c4_b_st, NULL, "message", 1U, 1U, 14, c4_i_y)));
          }

          c4_b_st.site = &c4_ie_emlrtRSI;
          c4_g_idx = c4_d_idx;
          c4_nrowx = c4_f_x.size[0];
          c4_nrows = c4_nrowx - 1;
          c4_c_st.site = &c4_je_emlrtRSI;
          for (c4_g_j = 0; c4_g_j < 2; c4_g_j++) {
            c4_h_j = c4_g_j;
            c4_c_st.site = &c4_ke_emlrtRSI;
            c4_f_a = c4_g_idx;
            c4_g_b = c4_nrows;
            c4_g_a = c4_f_a;
            c4_h_b = c4_g_b;
            if (c4_g_a > c4_h_b) {
              c4_overflow = false;
            } else {
              c4_overflow = (c4_h_b > 2147483646);
            }

            if (c4_overflow) {
              c4_d_st.site = &c4_jb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
            }

            for (c4_h_i = c4_g_idx; c4_h_i <= c4_nrows; c4_h_i++) {
              c4_f_x.vector.data[(c4_h_i + c4_f_x.size[0] * c4_h_j) - 1] =
                c4_f_x.vector.data[c4_h_i + c4_f_x.size[0] * c4_h_j];
            }
          }

          if (c4_nrows > c4_nrowx) {
            c4_j_y = NULL;
            sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2,
              1, 30), false);
            c4_k_y = NULL;
            sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2,
              1, 30), false);
            sf_mex_call(&c4_b_st, &c4_n_emlrtMCI, "error", 0U, 2U, 14, c4_j_y,
                        14, sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c4_b_st, NULL, "message", 1U, 1U, 14, c4_k_y)));
          }

          c4_b2 = (c4_nrows < 1);
          if (c4_b2) {
            c4_i34 = -1;
          } else {
            c4_i34 = c4_nrows - 1;
          }

          for (c4_i36 = 0; c4_i36 < 2; c4_i36++) {
            c4_g_loop_ub = c4_i34;
            for (c4_i37 = 0; c4_i37 <= c4_g_loop_ub; c4_i37++) {
              c4_f_x.vector.data[c4_i37 + (c4_i34 + 1) * c4_i36] =
                c4_f_x.vector.data[c4_i37 + c4_f_x.size[0] * c4_i36];
            }
          }

          c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_f_x,
            &c4_gc_emlrtRTEI, c4_i34 + 1, 2);
          c4_st.site = &c4_pb_emlrtRSI;
          c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers,
            &c4_fc_emlrtRTEI, c4_f_x.size[0], 2);
          c4_h_loop_ub = (c4_f_x.size[0] << 1) - 1;
          for (c4_i38 = 0; c4_i38 <= c4_h_loop_ub; c4_i38++) {
            c4_centers->vector.data[c4_i38] = c4_f_x.vector.data[c4_i38];
          }
        }
      }

      c4_array_real_T_2D_Destructor(chartInstance, &c4_f_x);
      c4_b1 = (c4_centers->size[0] == 0);
      if (!c4_b1) {
        c4_array_real_T_Constructor(chartInstance, &c4_ndx);
        c4_st.site = &c4_qb_emlrtRSI;
        c4_array_real_T_Constructor(chartInstance, &c4_b_centers);
        c4_b_st.site = &c4_qb_emlrtRSI;
        c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_b_centers,
          &c4_hc_emlrtRTEI, c4_centers->size[0]);
        c4_loop_ub = c4_centers->size[0] - 1;
        for (c4_i24 = 0; c4_i24 <= c4_loop_ub; c4_i24++) {
          c4_b_centers.vector.data[c4_i24] = c4_centers->vector.data[c4_i24 +
            c4_centers->size[0]];
        }

        c4_b_st.site = &c4_qb_emlrtRSI;
        c4_round(chartInstance, &c4_b_st, &c4_b_centers, &c4_ndx);
        c4_array_real_T_Destructor(chartInstance, &c4_b_centers);
        c4_array_real_T_Constructor(chartInstance, &c4_c_centers);
        c4_b_st.site = &c4_qb_emlrtRSI;
        c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_c_centers,
          &c4_ic_emlrtRTEI, c4_centers->size[0]);
        c4_c_loop_ub = c4_centers->size[0] - 1;
        for (c4_i30 = 0; c4_i30 <= c4_c_loop_ub; c4_i30++) {
          c4_c_centers.vector.data[c4_i30] = c4_centers->vector.data[c4_i30];
        }

        c4_array_real_T_Constructor(chartInstance, &c4_varargin_2);
        c4_b_st.site = &c4_qb_emlrtRSI;
        c4_round(chartInstance, &c4_b_st, &c4_c_centers, &c4_varargin_2);
        c4_array_real_T_Destructor(chartInstance, &c4_c_centers);
        c4_array_int32_T_Constructor(chartInstance, &c4_r);
        c4_b_st.site = &c4_fb_emlrtRSI;
        c4_sub2ind(chartInstance, &c4_b_st, &c4_ndx, &c4_varargin_2, &c4_r);
        c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_ndx, &c4_v_emlrtRTEI,
          c4_r.size[0]);
        c4_d_loop_ub = c4_r.size[0] - 1;
        for (c4_i31 = 0; c4_i31 <= c4_d_loop_ub; c4_i31++) {
          c4_ndx.vector.data[c4_i31] = (real_T)c4_r.vector.data[c4_i31];
        }

        c4_array_int32_T_Destructor(chartInstance, &c4_r);
        c4_st.site = &c4_qb_emlrtRSI;
        c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_varargin_2,
          &c4_jc_emlrtRTEI, c4_ndx.size[0]);
        c4_e_loop_ub = c4_ndx.size[0] - 1;
        for (c4_i32 = 0; c4_i32 <= c4_e_loop_ub; c4_i32++) {
          c4_i33 = (int32_T)c4_ndx.vector.data[c4_i32];
          if ((c4_i33 < 1) || (c4_i33 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c4_i33, 1, 19200, &c4_fc_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          c4_varargin_2.vector.data[c4_i32] = chartInstance->c4_Hd[c4_i33 - 1];
        }

        c4_array_real_T_Destructor(chartInstance, &c4_ndx);
        c4_st.site = &c4_qb_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric,
          &c4_kc_emlrtRTEI, c4_varargin_2.size[0], 1);
        c4_f_loop_ub = c4_varargin_2.size[0] - 1;
        for (c4_i35 = 0; c4_i35 <= c4_f_loop_ub; c4_i35++) {
          c4_metric->vector.data[c4_i35] = c4_varargin_2.vector.data[c4_i35];
        }

        c4_array_real_T_Destructor(chartInstance, &c4_varargin_2);
        c4_st.site = &c4_rb_emlrtRSI;
        c4_array_real_T_2D_Constructor(chartInstance, &c4_j_x);
        c4_b_st.site = &c4_rb_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_j_x,
          &c4_lc_emlrtRTEI, c4_metric->size[0], c4_metric->size[1]);
        c4_i_loop_ub = c4_metric->size[0] * c4_metric->size[1] - 1;
        for (c4_i39 = 0; c4_i39 <= c4_i_loop_ub; c4_i39++) {
          c4_j_x.vector.data[c4_i39] = c4_metric->vector.data[c4_i39];
        }

        c4_array_int32_T_2D_Constructor(chartInstance, &c4_iidx);
        c4_b_st.site = &c4_ne_emlrtRSI;
        c4_b_sort(chartInstance, &c4_b_st, &c4_j_x, &c4_iidx);
        c4_array_real_T_2D_Constructor(chartInstance, &c4_sortIdx);
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_sortIdx,
          &c4_mc_emlrtRTEI, c4_iidx.size[0], 1);
        c4_j_loop_ub = c4_iidx.size[0] - 1;
        for (c4_i40 = 0; c4_i40 <= c4_j_loop_ub; c4_i40++) {
          c4_sortIdx.vector.data[c4_i40] = (real_T)c4_iidx.vector.data[c4_i40];
        }

        c4_array_int32_T_2D_Destructor(chartInstance, &c4_iidx);
        c4_st.site = &c4_rb_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_metric,
          &c4_nc_emlrtRTEI, c4_j_x.size[0], 1);
        c4_k_loop_ub = c4_j_x.size[0] - 1;
        for (c4_i41 = 0; c4_i41 <= c4_k_loop_ub; c4_i41++) {
          c4_metric->vector.data[c4_i41] = c4_j_x.vector.data[c4_i41];
        }

        c4_array_real_T_2D_Destructor(chartInstance, &c4_j_x);
        c4_d_centers = c4_centers->size[0];
        c4_b_sortIdx[0] = c4_sortIdx.size[0];
        c4_array_real_T_2D_Constructor(chartInstance, &c4_e_centers);
        c4_st.site = &c4_og_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_e_centers,
          &c4_oc_emlrtRTEI, c4_b_sortIdx[0], 2);
        for (c4_i42 = 0; c4_i42 < 2; c4_i42++) {
          c4_l_loop_ub = c4_b_sortIdx[0] - 1;
          for (c4_i43 = 0; c4_i43 <= c4_l_loop_ub; c4_i43++) {
            c4_i44 = (int32_T)c4_sortIdx.vector.data[c4_i43];
            if ((c4_i44 < 1) || (c4_i44 > c4_d_centers)) {
              emlrtDynamicBoundsCheckR2012b(c4_i44, 1, c4_d_centers,
                &c4_gc_emlrtBCI, (emlrtConstCTX)c4_sp);
            }

            c4_e_centers.vector.data[c4_i43 + c4_e_centers.size[0] * c4_i42] =
              c4_centers->vector.data[(c4_i44 + c4_centers->size[0] * c4_i42) -
              1];
          }
        }

        c4_array_real_T_2D_Destructor(chartInstance, &c4_sortIdx);
        c4_st.site = &c4_og_emlrtRSI;
        c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_centers,
          &c4_pc_emlrtRTEI, c4_e_centers.size[0], c4_e_centers.size[1]);
        c4_m_loop_ub = c4_e_centers.size[0] * c4_e_centers.size[1] - 1;
        for (c4_i45 = 0; c4_i45 <= c4_m_loop_ub; c4_i45++) {
          c4_centers->vector.data[c4_i45] = c4_e_centers.vector.data[c4_i45];
        }

        c4_array_real_T_2D_Destructor(chartInstance, &c4_e_centers);
      }
    }

    c4_array_sOA5t73y81YtFHGIDxk0fKF_D(chartInstance, &c4_b_s);
  }
}

static void c4_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_a[19200])
{
  static char_T c4_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_c_x;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_ac_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_b_x = c4_a[(int32_T)c4_b_k - 1];
    c4_c_x = c4_b_x;
    c4_b_b = muDoubleScalarIsNaN(c4_c_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_st, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }
}

static void c4_regionprops(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], real_T c4_varargin_2
  [19200], c4_coder_array_sOA5t73y81YtFHGIDxk *c4_outstats)
{
  static char_T c4_b_cv[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  c4_cell_wrap_34 c4_reshapes[2];
  c4_coder_array_boolean_T c4_tile;
  c4_coder_array_int32_T c4_b_regionLengths;
  c4_coder_array_int32_T c4_idxCount;
  c4_coder_array_int32_T c4_regionLengths;
  c4_coder_array_real_T c4_j;
  c4_coder_array_real_T c4_r;
  c4_coder_array_real_T c4_r1;
  c4_coder_array_real_T c4_regionIndices;
  c4_coder_array_real_T_2D c4_result;
  c4_coder_array_s_R6Og1x0kmqQXSF9Pw c4_stats;
  c4_sOA5t73y81YtFHGIDxk0fKF c4_b_s;
  c4_s_8vINxG2sU0DyuufNTJYdGF c4_CC;
  c4_s_R6Og1x0kmqQXSF9Pwa49FD c4_statsOneObj;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_wc[2];
  real_T c4_M;
  real_T c4_b_idx;
  real_T c4_b_k;
  real_T c4_b_n;
  real_T c4_b_numObjs;
  real_T c4_b_vIdx;
  real_T c4_c_numObjs;
  real_T c4_c_varargin_1;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d10;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d8;
  real_T c4_d9;
  real_T c4_d_k;
  real_T c4_d_numObjs;
  real_T c4_d_varargin_1;
  real_T c4_e_numObjs;
  real_T c4_f_k;
  real_T c4_h_k;
  real_T c4_j_k;
  real_T c4_numObjs;
  real_T c4_sumIntensity;
  int32_T c4_b_outsize[2];
  int32_T c4_outsize[2];
  int32_T c4_ab_loop_ub;
  int32_T c4_b_loop_ub;
  int32_T c4_b_result;
  int32_T c4_bb_loop_ub;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_cb_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_db_loop_ub;
  int32_T c4_dim;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_expected;
  int32_T c4_f_loop_ub;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  int32_T c4_i109;
  int32_T c4_i11;
  int32_T c4_i110;
  int32_T c4_i111;
  int32_T c4_i112;
  int32_T c4_i113;
  int32_T c4_i114;
  int32_T c4_i115;
  int32_T c4_i116;
  int32_T c4_i117;
  int32_T c4_i118;
  int32_T c4_i119;
  int32_T c4_i12;
  int32_T c4_i120;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i_k;
  int32_T c4_i_loop_ub;
  int32_T c4_idx;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_u_loop_ub;
  int32_T c4_vIdx;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_y_loop_ub;
  boolean_T c4_b_varargin_1[19200];
  boolean_T c4_b;
  boolean_T c4_b1;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_array_s_8vINxG2sU0DyuufNTJYdGF_(chartInstance, &c4_CC);
  c4_st.site = &c4_ec_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_b_varargin_1[c4_i] = c4_varargin_1[c4_i];
  }

  c4_bwconncomp(chartInstance, &c4_st, c4_b_varargin_1, &c4_CC);
  c4_numObjs = c4_CC.NumObjects;
  c4_st.site = &c4_fc_emlrtRSI;
  c4_b_numObjs = c4_numObjs;
  c4_b_st.site = &c4_sd_emlrtRSI;
  c4_c_numObjs = c4_b_numObjs;
  c4_c_st.site = &c4_td_emlrtRSI;
  c4_c_varargin_1 = c4_c_numObjs;
  c4_d_st.site = &c4_qd_emlrtRSI;
  c4_assertValidSizeArg(chartInstance, &c4_d_st, c4_c_varargin_1);
  c4_array_boolean_T_Constructor(chartInstance, &c4_tile);
  c4_array_boolean_T_SetSize(chartInstance, &c4_c_st, &c4_tile, &c4_qc_emlrtRTEI,
    (int32_T)c4_c_varargin_1);
  c4_loop_ub = (int32_T)c4_c_varargin_1 - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_tile.vector.data[c4_i1] = false;
  }

  c4_outsize[0] = c4_tile.size[0];
  if (c4_outsize[0] != c4_tile.size[0]) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv3, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c4_c_st, &c4_g_emlrtMCI, "error", 0U, 1U, 14, c4_y);
  }

  memset(&c4_b_s.WeightedCentroid[0], 0, sizeof(real_T) << 1);
  c4_array_sOA5t73y81YtFHGIDxk0fKF_S(chartInstance, &c4_c_st, c4_outstats,
    &c4_rc_emlrtRTEI, c4_outsize[0]);
  c4_b_loop_ub = c4_outsize[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
    c4_outstats->vector.data[c4_i2] = c4_b_s;
  }

  c4_st.site = &c4_gc_emlrtRSI;
  c4_d_numObjs = c4_numObjs;
  c4_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c4_statsOneObj);
  c4_statsOneObj.Area = 0.0;
  memset(&c4_statsOneObj.Centroid[0], 0, sizeof(real_T) << 1);
  memset(&c4_statsOneObj.BoundingBox[0], 0, sizeof(real_T) << 2);
  c4_statsOneObj.MajorAxisLength = 0.0;
  c4_statsOneObj.MinorAxisLength = 0.0;
  c4_statsOneObj.Eccentricity = 0.0;
  c4_statsOneObj.Orientation = 0.0;
  memset(&c4_statsOneObj.Image.size[0], 0, sizeof(int32_T) << 1);
  memset(&c4_statsOneObj.FilledImage.size[0], 0, sizeof(int32_T) << 1);
  c4_statsOneObj.FilledArea = 0.0;
  c4_statsOneObj.EulerNumber = 0.0;
  memset(&c4_statsOneObj.Extrema[0], 0, sizeof(real_T) << 4);
  c4_statsOneObj.EquivDiameter = 0.0;
  c4_statsOneObj.Extent = 0.0;
  c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_statsOneObj.PixelIdxList,
    &c4_uc_emlrtRTEI, 0);
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_statsOneObj.PixelList,
    &c4_vc_emlrtRTEI, 0, 2);
  c4_statsOneObj.Perimeter = 0.0;
  c4_statsOneObj.Circularity = 0.0;
  c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_statsOneObj.PixelValues,
    &c4_wc_emlrtRTEI, 0);
  memset(&c4_statsOneObj.WeightedCentroid[0], 0, sizeof(real_T) << 1);
  c4_statsOneObj.MeanIntensity = 0.0;
  c4_statsOneObj.MinIntensity = 0.0;
  c4_statsOneObj.MaxIntensity = 0.0;
  c4_statsOneObj.SubarrayIdx.size[0] = 1;
  c4_statsOneObj.SubarrayIdx.size[1] = 0;
  memset(&c4_statsOneObj.SubarrayIdxLengths[0], 0, sizeof(real_T) << 1);
  c4_b_st.site = &c4_ud_emlrtRSI;
  c4_d_varargin_1 = c4_d_numObjs;
  c4_c_st.site = &c4_qd_emlrtRSI;
  c4_assertValidSizeArg(chartInstance, &c4_c_st, c4_d_varargin_1);
  c4_array_boolean_T_SetSize(chartInstance, &c4_b_st, &c4_tile, &c4_qc_emlrtRTEI,
    (int32_T)c4_d_varargin_1);
  c4_c_loop_ub = (int32_T)c4_d_varargin_1 - 1;
  for (c4_i3 = 0; c4_i3 <= c4_c_loop_ub; c4_i3++) {
    c4_tile.vector.data[c4_i3] = false;
  }

  c4_b_outsize[0] = c4_tile.size[0];
  if (c4_b_outsize[0] != c4_tile.size[0]) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv3, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c4_b_st, &c4_g_emlrtMCI, "error", 0U, 1U, 14, c4_b_y);
  }

  c4_array_boolean_T_Destructor(chartInstance, &c4_tile);
  c4_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c4_stats);
  c4_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c4_b_st, &c4_stats,
    &c4_yc_emlrtRTEI, c4_b_outsize[0]);
  c4_d_loop_ub = c4_b_outsize[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_d_loop_ub; c4_i4++) {
    c4_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c4_b_st,
      &c4_stats.vector.data[c4_i4], &c4_statsOneObj, &c4_yc_emlrtRTEI);
  }

  c4_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c4_statsOneObj);
  c4_st.site = &c4_hc_emlrtRSI;
  c4_e_numObjs = c4_numObjs;
  c4_array_int32_T_Constructor(chartInstance, &c4_regionLengths);
  c4_array_real_T_Constructor(chartInstance, &c4_regionIndices);
  c4_array_int32_T_Constructor(chartInstance, &c4_idxCount);
  if (c4_e_numObjs != 0.0) {
    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_regionIndices,
      &c4_ad_emlrtRTEI, c4_CC.RegionIndices.size[0]);
    c4_e_loop_ub = c4_CC.RegionIndices.size[0] - 1;
    for (c4_i5 = 0; c4_i5 <= c4_e_loop_ub; c4_i5++) {
      c4_regionIndices.vector.data[c4_i5] =
        c4_CC.RegionIndices.vector.data[c4_i5];
    }

    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_regionLengths,
      &c4_bd_emlrtRTEI, c4_CC.RegionLengths.size[0]);
    c4_f_loop_ub = c4_CC.RegionLengths.size[0] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_f_loop_ub; c4_i7++) {
      c4_regionLengths.vector.data[c4_i7] =
        c4_CC.RegionLengths.vector.data[c4_i7];
    }

    c4_b_st.site = &c4_vd_emlrtRSI;
    c4_c_st.site = &c4_kd_emlrtRSI;
    c4_dim = 2;
    if (c4_regionLengths.size[0] != 1) {
      c4_dim = 1;
    }

    c4_array_int32_T_Constructor(chartInstance, &c4_b_regionLengths);
    c4_array_int32_T_SetSize(chartInstance, &c4_c_st, &c4_b_regionLengths,
      &c4_cd_emlrtRTEI, c4_regionLengths.size[0]);
    c4_g_loop_ub = c4_regionLengths.size[0] - 1;
    for (c4_i11 = 0; c4_i11 <= c4_g_loop_ub; c4_i11++) {
      c4_b_regionLengths.vector.data[c4_i11] =
        c4_regionLengths.vector.data[c4_i11];
    }

    c4_d_st.site = &c4_ld_emlrtRSI;
    c4_useConstantDim(chartInstance, &c4_d_st, &c4_b_regionLengths, c4_dim,
                      &c4_regionLengths);
    c4_array_int32_T_Destructor(chartInstance, &c4_b_regionLengths);
    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_idxCount,
      &c4_dd_emlrtRTEI, 1 + c4_regionLengths.size[0]);
    c4_idxCount.vector.data[0] = 0;
    c4_i_loop_ub = c4_regionLengths.size[0] - 1;
    for (c4_i19 = 0; c4_i19 <= c4_i_loop_ub; c4_i19++) {
      c4_idxCount.vector.data[c4_i19 + 1] = c4_regionLengths.vector.data[c4_i19];
    }

    c4_d3 = (real_T)c4_stats.size[0];
    c4_i27 = (int32_T)c4_d3;
    for (c4_g_k = 0; c4_g_k < c4_i27; c4_g_k++) {
      c4_h_k = (real_T)c4_g_k + 1.0;
      c4_i32 = c4_idxCount.size[0];
      c4_i38 = (int32_T)c4_h_k;
      if ((c4_i38 < 1) || (c4_i38 > c4_i32)) {
        emlrtDynamicBoundsCheckR2012b(c4_i38, 1, c4_i32, &c4_uc_emlrtBCI, &c4_st);
      }

      c4_i42 = c4_idxCount.vector.data[c4_i38 - 1] + 1;
      c4_i45 = c4_idxCount.size[0];
      c4_i49 = (int32_T)(c4_h_k + 1.0);
      if ((c4_i49 < 1) || (c4_i49 > c4_i45)) {
        emlrtDynamicBoundsCheckR2012b(c4_i49, 1, c4_i45, &c4_vc_emlrtBCI, &c4_st);
      }

      c4_i57 = c4_idxCount.vector.data[c4_i49 - 1];
      c4_b = (c4_i42 > c4_i57);
      if (c4_b) {
        c4_i63 = 0;
        c4_i65 = -1;
      } else {
        c4_i62 = c4_regionIndices.size[0];
        if ((c4_i42 < 1) || (c4_i42 > c4_i62)) {
          emlrtDynamicBoundsCheckR2012b(c4_i42, 1, c4_i62, &c4_hc_emlrtBCI,
            &c4_st);
        }

        c4_i63 = c4_i42 - 1;
        c4_i71 = c4_regionIndices.size[0];
        if ((c4_i57 < 1) || (c4_i57 > c4_i71)) {
          emlrtDynamicBoundsCheckR2012b(c4_i57, 1, c4_i71, &c4_ic_emlrtBCI,
            &c4_st);
        }

        c4_i65 = c4_i57 - 1;
      }

      c4_i67 = c4_stats.size[0];
      c4_i72 = (int32_T)c4_h_k;
      if ((c4_i72 < 1) || (c4_i72 > c4_i67)) {
        emlrtDynamicBoundsCheckR2012b(c4_i72, 1, c4_i67, &c4_bd_emlrtBCI, &c4_st);
      }

      c4_array_real_T_SetSize(chartInstance, &c4_st,
        &c4_stats.vector.data[c4_i72 - 1].PixelIdxList, &c4_ed_emlrtRTEI,
        (c4_i65 - c4_i63) + 1);
      c4_p_loop_ub = c4_i65 - c4_i63;
      for (c4_i82 = 0; c4_i82 <= c4_p_loop_ub; c4_i82++) {
        c4_i84 = c4_stats.size[0];
        c4_i87 = (int32_T)c4_h_k;
        if ((c4_i87 < 1) || (c4_i87 > c4_i84)) {
          emlrtDynamicBoundsCheckR2012b(c4_i87, 1, c4_i84, &c4_jd_emlrtBCI,
            &c4_st);
        }

        c4_stats.vector.data[c4_i87 - 1].PixelIdxList.vector.data[c4_i82] =
          c4_regionIndices.vector.data[c4_i63 + c4_i82];
      }
    }
  }

  c4_b_array_s_8vINxG2sU0DyuufNTJYdGF_(chartInstance, &c4_CC);
  c4_st.site = &c4_ic_emlrtRSI;
  c4_b_st.site = &c4_wd_emlrtRSI;
  c4_d = (real_T)c4_stats.size[0];
  c4_i6 = (int32_T)c4_d;
  c4_array_real_T_Constructor(chartInstance, &c4_j);
  c4_array_real_T_Constructor(chartInstance, &c4_r);
  c4_array_real_T_2D_Constructor(chartInstance, &c4_result);
  c4_array_cell_wrap_34_2s_Construct(chartInstance, c4_reshapes);
  for (c4_k = 0; c4_k < c4_i6; c4_k++) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_i8 = c4_stats.size[0];
    c4_i9 = (int32_T)c4_b_k;
    if ((c4_i9 < 1) || (c4_i9 > c4_i8)) {
      emlrtDynamicBoundsCheckR2012b(c4_i9, 1, c4_i8, &c4_cd_emlrtBCI, &c4_b_st);
    }

    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_r, &c4_fd_emlrtRTEI,
      c4_stats.vector.data[c4_i9 - 1].PixelIdxList.size[0]);
    c4_i12 = c4_stats.size[0];
    c4_i14 = (int32_T)c4_b_k;
    if ((c4_i14 < 1) || (c4_i14 > c4_i12)) {
      emlrtDynamicBoundsCheckR2012b(c4_i14, 1, c4_i12, &c4_cd_emlrtBCI, &c4_b_st);
    }

    c4_h_loop_ub = c4_stats.vector.data[c4_i14 - 1].PixelIdxList.size[0] - 1;
    for (c4_i17 = 0; c4_i17 <= c4_h_loop_ub; c4_i17++) {
      c4_i21 = c4_stats.size[0];
      c4_i23 = (int32_T)c4_b_k;
      if ((c4_i23 < 1) || (c4_i23 > c4_i21)) {
        emlrtDynamicBoundsCheckR2012b(c4_i23, 1, c4_i21, &c4_cd_emlrtBCI,
          &c4_b_st);
      }

      c4_r.vector.data[c4_i17] = c4_stats.vector.data[c4_i23 - 1].
        PixelIdxList.vector.data[c4_i17];
    }

    if (c4_r.size[0] != 0) {
      c4_c_st.site = &c4_be_emlrtRSI;
      c4_i26 = c4_stats.size[0];
      c4_i29 = (int32_T)c4_b_k;
      if ((c4_i29 < 1) || (c4_i29 > c4_i26)) {
        emlrtDynamicBoundsCheckR2012b(c4_i29, 1, c4_i26, &c4_ed_emlrtBCI,
          &c4_c_st);
      }

      c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_regionIndices,
        &c4_hd_emlrtRTEI, c4_stats.vector.data[c4_i29 - 1].PixelIdxList.size[0]);
      c4_i37 = c4_stats.size[0];
      c4_i41 = (int32_T)c4_b_k;
      if ((c4_i41 < 1) || (c4_i41 > c4_i37)) {
        emlrtDynamicBoundsCheckR2012b(c4_i41, 1, c4_i37, &c4_ed_emlrtBCI,
          &c4_c_st);
      }

      c4_l_loop_ub = c4_stats.vector.data[c4_i41 - 1].PixelIdxList.size[0] - 1;
      for (c4_i48 = 0; c4_i48 <= c4_l_loop_ub; c4_i48++) {
        c4_i52 = c4_stats.size[0];
        c4_i56 = (int32_T)c4_b_k;
        if ((c4_i56 < 1) || (c4_i56 > c4_i52)) {
          emlrtDynamicBoundsCheckR2012b(c4_i56, 1, c4_i52, &c4_ed_emlrtBCI,
            &c4_c_st);
        }

        c4_regionIndices.vector.data[c4_i48] = c4_stats.vector.data[c4_i56 - 1].
          PixelIdxList.vector.data[c4_i48];
      }

      c4_d_st.site = &c4_de_emlrtRSI;
      c4_ind2sub(chartInstance, &c4_d_st, &c4_regionIndices, &c4_regionLengths,
                 &c4_idxCount);
      c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_regionIndices,
        &c4_id_emlrtRTEI, c4_regionLengths.size[0]);
      c4_m_loop_ub = c4_regionLengths.size[0] - 1;
      for (c4_i61 = 0; c4_i61 <= c4_m_loop_ub; c4_i61++) {
        c4_regionIndices.vector.data[c4_i61] = (real_T)
          c4_regionLengths.vector.data[c4_i61];
      }

      c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_j, &c4_id_emlrtRTEI,
        c4_idxCount.size[0]);
      c4_n_loop_ub = c4_idxCount.size[0] - 1;
      for (c4_i70 = 0; c4_i70 <= c4_n_loop_ub; c4_i70++) {
        c4_j.vector.data[c4_i70] = (real_T)c4_idxCount.vector.data[c4_i70];
      }

      c4_c_st.site = &c4_ce_emlrtRSI;
      c4_d_st.site = &c4_ee_emlrtRSI;
      c4_b_result = c4_j.size[0];
      c4_outsize[0] = c4_b_result;
      c4_e_st.site = &c4_fe_emlrtRSI;
      c4_expected = c4_outsize[0];
      if (c4_j.size[0] == c4_expected) {
        c4_b1 = true;
      } else {
        c4_b1 = false;
      }

      if (!c4_b1) {
        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c4_d_y = NULL;
        sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c4_e_st, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                    sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_e_st, NULL, "message", 1U, 1U, 14, c4_d_y)));
      }

      if (c4_regionIndices.size[0] == c4_expected) {
        c4_b1 = true;
      } else {
        c4_b1 = false;
      }

      if (!c4_b1) {
        c4_e_y = NULL;
        sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        c4_f_y = NULL;
        sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1,
          39), false);
        sf_mex_call(&c4_e_st, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                    sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_e_st, NULL, "message", 1U, 1U, 14, c4_f_y)));
      }

      c4_array_real_T_SetSize(chartInstance, &c4_d_st, &c4_reshapes[0].f1,
        &c4_jd_emlrtRTEI, c4_j.size[0]);
      c4_u_loop_ub = c4_j.size[0] - 1;
      for (c4_i97 = 0; c4_i97 <= c4_u_loop_ub; c4_i97++) {
        c4_reshapes[0].f1.vector.data[c4_i97] = c4_j.vector.data[c4_i97];
      }

      c4_array_real_T_SetSize(chartInstance, &c4_d_st, &c4_reshapes[1].f1,
        &c4_jd_emlrtRTEI, c4_regionIndices.size[0]);
      c4_x_loop_ub = c4_regionIndices.size[0] - 1;
      for (c4_i100 = 0; c4_i100 <= c4_x_loop_ub; c4_i100++) {
        c4_reshapes[1].f1.vector.data[c4_i100] =
          c4_regionIndices.vector.data[c4_i100];
      }

      c4_array_real_T_SetSize(chartInstance, &c4_d_st, &c4_regionIndices,
        &c4_kd_emlrtRTEI, c4_reshapes[0].f1.size[0]);
      c4_y_loop_ub = c4_reshapes[0].f1.size[0] - 1;
      for (c4_i104 = 0; c4_i104 <= c4_y_loop_ub; c4_i104++) {
        c4_regionIndices.vector.data[c4_i104] = c4_reshapes[0]
          .f1.vector.data[c4_i104];
      }

      c4_array_real_T_SetSize(chartInstance, &c4_d_st, &c4_j, &c4_kd_emlrtRTEI,
        c4_reshapes[1].f1.size[0]);
      c4_ab_loop_ub = c4_reshapes[1].f1.size[0] - 1;
      for (c4_i107 = 0; c4_i107 <= c4_ab_loop_ub; c4_i107++) {
        c4_j.vector.data[c4_i107] = c4_reshapes[1].f1.vector.data[c4_i107];
      }

      c4_array_real_T_2D_SetSize(chartInstance, &c4_d_st, &c4_result,
        &c4_ld_emlrtRTEI, c4_regionIndices.size[0], 2);
      c4_bb_loop_ub = c4_regionIndices.size[0] - 1;
      for (c4_i110 = 0; c4_i110 <= c4_bb_loop_ub; c4_i110++) {
        c4_result.vector.data[c4_i110] = c4_regionIndices.vector.data[c4_i110];
      }

      c4_cb_loop_ub = c4_j.size[0] - 1;
      for (c4_i112 = 0; c4_i112 <= c4_cb_loop_ub; c4_i112++) {
        c4_result.vector.data[c4_i112 + c4_result.size[0]] =
          c4_j.vector.data[c4_i112];
      }

      c4_i114 = c4_stats.size[0];
      c4_i115 = (int32_T)c4_b_k;
      if ((c4_i115 < 1) || (c4_i115 > c4_i114)) {
        emlrtDynamicBoundsCheckR2012b(c4_i115, 1, c4_i114, &c4_pc_emlrtBCI,
          &c4_b_st);
      }

      c4_d10 = (real_T)c4_i115;
      c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_stats.vector.data
        [(int32_T)c4_d10 - 1].PixelList, &c4_md_emlrtRTEI, c4_result.size[0], 2);
      c4_db_loop_ub = (c4_result.size[0] << 1) - 1;
      for (c4_i120 = 0; c4_i120 <= c4_db_loop_ub; c4_i120++) {
        c4_stats.vector.data[(int32_T)c4_d10 - 1].PixelList.vector.data[c4_i120]
          = c4_result.vector.data[c4_i120];
      }
    } else {
      c4_i22 = c4_stats.size[0];
      c4_i25 = (int32_T)c4_b_k;
      if ((c4_i25 < 1) || (c4_i25 > c4_i22)) {
        emlrtDynamicBoundsCheckR2012b(c4_i25, 1, c4_i22, &c4_qc_emlrtBCI,
          &c4_b_st);
      }

      c4_d4 = (real_T)c4_i25;
      c4_array_real_T_2D_SetSize(chartInstance, &c4_b_st, &c4_stats.vector.data
        [(int32_T)c4_d4 - 1].PixelList, &c4_gd_emlrtRTEI, 0, 2);
    }
  }

  c4_array_cell_wrap_34_2s_Destructo(chartInstance, c4_reshapes);
  c4_b_st.site = &c4_xd_emlrtRSI;
  c4_d1 = (real_T)c4_stats.size[0];
  c4_i10 = (int32_T)c4_d1;
  for (c4_c_k = 0; c4_c_k < c4_i10; c4_c_k++) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_i13 = c4_stats.size[0];
    c4_i15 = (int32_T)c4_d_k;
    if ((c4_i15 < 1) || (c4_i15 > c4_i13)) {
      emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_i13, &c4_dd_emlrtBCI, &c4_b_st);
    }

    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_r, &c4_nd_emlrtRTEI,
      c4_stats.vector.data[c4_i15 - 1].PixelIdxList.size[0]);
    c4_i18 = c4_stats.size[0];
    c4_i20 = (int32_T)c4_d_k;
    if ((c4_i20 < 1) || (c4_i20 > c4_i18)) {
      emlrtDynamicBoundsCheckR2012b(c4_i20, 1, c4_i18, &c4_dd_emlrtBCI, &c4_b_st);
    }

    c4_j_loop_ub = c4_stats.vector.data[c4_i20 - 1].PixelIdxList.size[0] - 1;
    for (c4_i30 = 0; c4_i30 <= c4_j_loop_ub; c4_i30++) {
      c4_i31 = c4_stats.size[0];
      c4_i36 = (int32_T)c4_d_k;
      if ((c4_i36 < 1) || (c4_i36 > c4_i31)) {
        emlrtDynamicBoundsCheckR2012b(c4_i36, 1, c4_i31, &c4_dd_emlrtBCI,
          &c4_b_st);
      }

      c4_r.vector.data[c4_i30] = c4_stats.vector.data[c4_i36 - 1].
        PixelIdxList.vector.data[c4_i30];
    }

    c4_wc[0] = (real_T)c4_r.size[0];
    c4_i35 = c4_stats.size[0];
    c4_i40 = (int32_T)c4_d_k;
    if ((c4_i40 < 1) || (c4_i40 > c4_i35)) {
      emlrtDynamicBoundsCheckR2012b(c4_i40, 1, c4_i35, &c4_rc_emlrtBCI, &c4_b_st);
    }

    c4_i44 = c4_i40;
    c4_array_real_T_SetSize(chartInstance, &c4_b_st,
      &c4_stats.vector.data[c4_i44 - 1].PixelValues, &c4_od_emlrtRTEI, (int32_T)
      c4_wc[0]);
    c4_c_st.site = &c4_ge_emlrtRSI;
    c4_i51 = c4_stats.size[0];
    c4_i55 = (int32_T)c4_d_k;
    if ((c4_i55 < 1) || (c4_i55 > c4_i51)) {
      emlrtDynamicBoundsCheckR2012b(c4_i55, 1, c4_i51, &c4_hd_emlrtBCI, &c4_c_st);
    }

    c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_regionIndices,
      &c4_pd_emlrtRTEI, c4_stats.vector.data[c4_i55 - 1].PixelIdxList.size[0]);
    c4_i64 = c4_stats.size[0];
    c4_i66 = (int32_T)c4_d_k;
    if ((c4_i66 < 1) || (c4_i66 > c4_i64)) {
      emlrtDynamicBoundsCheckR2012b(c4_i66, 1, c4_i64, &c4_hd_emlrtBCI, &c4_c_st);
    }

    c4_o_loop_ub = c4_stats.vector.data[c4_i66 - 1].PixelIdxList.size[0] - 1;
    for (c4_i77 = 0; c4_i77 <= c4_o_loop_ub; c4_i77++) {
      c4_i78 = c4_stats.size[0];
      c4_i81 = (int32_T)c4_d_k;
      if ((c4_i81 < 1) || (c4_i81 > c4_i78)) {
        emlrtDynamicBoundsCheckR2012b(c4_i81, 1, c4_i78, &c4_hd_emlrtBCI,
          &c4_c_st);
      }

      c4_regionIndices.vector.data[c4_i77] = c4_stats.vector.data[c4_i81 - 1].
        PixelIdxList.vector.data[c4_i77];
    }

    c4_d_st.site = &c4_de_emlrtRSI;
    c4_ind2sub(chartInstance, &c4_d_st, &c4_regionIndices, &c4_regionLengths,
               &c4_idxCount);
    c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_regionIndices,
      &c4_id_emlrtRTEI, c4_regionLengths.size[0]);
    c4_r_loop_ub = c4_regionLengths.size[0] - 1;
    for (c4_i86 = 0; c4_i86 <= c4_r_loop_ub; c4_i86++) {
      c4_regionIndices.vector.data[c4_i86] = (real_T)
        c4_regionLengths.vector.data[c4_i86];
    }

    c4_array_real_T_SetSize(chartInstance, &c4_c_st, &c4_j, &c4_id_emlrtRTEI,
      c4_idxCount.size[0]);
    c4_s_loop_ub = c4_idxCount.size[0] - 1;
    for (c4_i89 = 0; c4_i89 <= c4_s_loop_ub; c4_i89++) {
      c4_j.vector.data[c4_i89] = (real_T)c4_idxCount.vector.data[c4_i89];
    }

    c4_i91 = c4_stats.size[0];
    c4_i93 = (int32_T)c4_d_k;
    if ((c4_i93 < 1) || (c4_i93 > c4_i91)) {
      emlrtDynamicBoundsCheckR2012b(c4_i93, 1, c4_i91, &c4_id_emlrtBCI, &c4_b_st);
    }

    c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_r, &c4_qd_emlrtRTEI,
      c4_stats.vector.data[c4_i93 - 1].PixelValues.size[0]);
    c4_i95 = c4_stats.size[0];
    c4_i96 = (int32_T)c4_d_k;
    if ((c4_i96 < 1) || (c4_i96 > c4_i95)) {
      emlrtDynamicBoundsCheckR2012b(c4_i96, 1, c4_i95, &c4_id_emlrtBCI, &c4_b_st);
    }

    c4_w_loop_ub = c4_stats.vector.data[c4_i96 - 1].PixelValues.size[0] - 1;
    for (c4_i99 = 0; c4_i99 <= c4_w_loop_ub; c4_i99++) {
      c4_i101 = c4_stats.size[0];
      c4_i103 = (int32_T)c4_d_k;
      if ((c4_i103 < 1) || (c4_i103 > c4_i101)) {
        emlrtDynamicBoundsCheckR2012b(c4_i103, 1, c4_i101, &c4_id_emlrtBCI,
          &c4_b_st);
      }

      c4_r.vector.data[c4_i99] = c4_stats.vector.data[c4_i103 - 1].
        PixelValues.vector.data[c4_i99];
    }

    c4_d9 = (real_T)c4_r.size[0];
    c4_i102 = (int32_T)c4_d9;
    for (c4_idx = 0; c4_idx < c4_i102; c4_idx++) {
      c4_b_idx = (real_T)c4_idx + 1.0;
      c4_i105 = c4_stats.size[0];
      c4_i106 = (int32_T)c4_d_k;
      if ((c4_i106 < 1) || (c4_i106 > c4_i105)) {
        emlrtDynamicBoundsCheckR2012b(c4_i106, 1, c4_i105, &c4_sc_emlrtBCI,
          &c4_b_st);
      }

      c4_i108 = c4_i106 - 1;
      c4_i109 = c4_regionIndices.size[0];
      c4_i111 = (int32_T)c4_b_idx;
      if ((c4_i111 < 1) || (c4_i111 > c4_i109)) {
        emlrtDynamicBoundsCheckR2012b(c4_i111, 1, c4_i109, &c4_xc_emlrtBCI,
          &c4_b_st);
      }

      c4_i113 = (int32_T)c4_regionIndices.vector.data[c4_i111 - 1];
      if ((c4_i113 < 1) || (c4_i113 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c4_i113, 1, 120, &c4_wc_emlrtBCI, &c4_b_st);
      }

      c4_i116 = c4_j.size[0];
      c4_i117 = (int32_T)c4_b_idx;
      if ((c4_i117 < 1) || (c4_i117 > c4_i116)) {
        emlrtDynamicBoundsCheckR2012b(c4_i117, 1, c4_i116, &c4_yc_emlrtBCI,
          &c4_b_st);
      }

      c4_i118 = c4_stats.vector.data[c4_i108].PixelValues.size[0];
      c4_i119 = (int32_T)c4_b_idx;
      if ((c4_i119 < 1) || (c4_i119 > c4_i118)) {
        emlrtDynamicBoundsCheckR2012b(c4_i119, 1, c4_i118, &c4_ad_emlrtBCI,
          &c4_b_st);
      }

      c4_stats.vector.data[c4_i108].PixelValues.vector.data[c4_i119 - 1] =
        c4_varargin_2[(c4_i113 + 120 * ((int32_T)c4_j.vector.data[c4_i117 - 1] -
        1)) - 1];
    }
  }

  c4_array_real_T_Destructor(chartInstance, &c4_j);
  c4_array_int32_T_Destructor(chartInstance, &c4_idxCount);
  c4_array_int32_T_Destructor(chartInstance, &c4_regionLengths);
  c4_d2 = (real_T)c4_stats.size[0];
  c4_i16 = (int32_T)c4_d2;
  c4_array_real_T_Constructor(chartInstance, &c4_r1);
  for (c4_e_k = 0; c4_e_k < c4_i16; c4_e_k++) {
    c4_f_k = (real_T)c4_e_k + 1.0;
    c4_i24 = c4_stats.size[0];
    c4_i28 = (int32_T)c4_f_k;
    if ((c4_i28 < 1) || (c4_i28 > c4_i24)) {
      emlrtDynamicBoundsCheckR2012b(c4_i28, 1, c4_i24, &c4_fd_emlrtBCI, &c4_st);
    }

    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_regionIndices,
      &c4_rd_emlrtRTEI, c4_stats.vector.data[c4_i28 - 1].PixelValues.size[0]);
    c4_i34 = c4_stats.size[0];
    c4_i39 = (int32_T)c4_f_k;
    if ((c4_i39 < 1) || (c4_i39 > c4_i34)) {
      emlrtDynamicBoundsCheckR2012b(c4_i39, 1, c4_i34, &c4_fd_emlrtBCI, &c4_st);
    }

    c4_k_loop_ub = c4_stats.vector.data[c4_i39 - 1].PixelValues.size[0] - 1;
    for (c4_i47 = 0; c4_i47 <= c4_k_loop_ub; c4_i47++) {
      c4_i50 = c4_stats.size[0];
      c4_i54 = (int32_T)c4_f_k;
      if ((c4_i54 < 1) || (c4_i54 > c4_i50)) {
        emlrtDynamicBoundsCheckR2012b(c4_i54, 1, c4_i50, &c4_gd_emlrtBCI, &c4_st);
      }

      c4_regionIndices.vector.data[c4_i47] = c4_stats.vector.data[c4_i54 - 1].
        PixelValues.vector.data[c4_i47];
    }

    c4_b_st.site = &c4_yd_emlrtRSI;
    c4_sumIntensity = c4_sum(chartInstance, &c4_b_st, &c4_regionIndices);
    c4_i59 = c4_stats.size[0];
    c4_i60 = (int32_T)c4_f_k;
    if ((c4_i60 < 1) || (c4_i60 > c4_i59)) {
      emlrtDynamicBoundsCheckR2012b(c4_i60, 1, c4_i59, &c4_jc_emlrtBCI, &c4_st);
    }

    for (c4_n = 0; c4_n < 2; c4_n++) {
      c4_b_n = (real_T)c4_n + 1.0;
      c4_i75 = c4_stats.size[0];
      c4_i76 = (int32_T)c4_f_k;
      if ((c4_i76 < 1) || (c4_i76 > c4_i75)) {
        emlrtDynamicBoundsCheckR2012b(c4_i76, 1, c4_i75, &c4_kc_emlrtBCI, &c4_st);
      }

      c4_d8 = (real_T)c4_i76;
      c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_result,
        &c4_sd_emlrtRTEI, c4_stats.vector.data[(int32_T)c4_d8 - 1].
        PixelList.size[0], 2);
      c4_q_loop_ub = (c4_stats.vector.data[(int32_T)c4_d8 - 1].PixelList.size[0]
                      << 1) - 1;
      for (c4_i85 = 0; c4_i85 <= c4_q_loop_ub; c4_i85++) {
        c4_result.vector.data[c4_i85] = c4_stats.vector.data[(int32_T)c4_d8 - 1]
          .PixelList.vector.data[c4_i85];
      }

      c4_c_n = (int32_T)c4_b_n - 1;
      c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r, &c4_sd_emlrtRTEI,
        c4_result.size[0]);
      c4_t_loop_ub = c4_result.size[0] - 1;
      for (c4_i90 = 0; c4_i90 <= c4_t_loop_ub; c4_i90++) {
        c4_r.vector.data[c4_i90] = c4_result.vector.data[c4_i90 +
          c4_result.size[0] * c4_c_n];
      }

      c4_i92 = c4_r.size[0];
      c4_i94 = c4_regionIndices.size[0];
      if ((c4_i92 != c4_i94) && ((c4_i92 != 1) && (c4_i94 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c4_i92, c4_i94, &c4_b_emlrtECI, &c4_st);
      }

      if (c4_r.size[0] == c4_regionIndices.size[0]) {
        c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r1, &c4_sd_emlrtRTEI,
          c4_r.size[0]);
        c4_v_loop_ub = c4_r.size[0] - 1;
        for (c4_i98 = 0; c4_i98 <= c4_v_loop_ub; c4_i98++) {
          c4_r1.vector.data[c4_i98] = c4_r.vector.data[c4_i98] *
            c4_regionIndices.vector.data[c4_i98];
        }

        c4_b_st.site = &c4_ae_emlrtRSI;
        c4_M = c4_sum(chartInstance, &c4_b_st, &c4_r1);
      } else {
        c4_b_st.site = &c4_ae_emlrtRSI;
        c4_M = c4_binary_expand_op(chartInstance, &c4_b_st, c4_ae_emlrtRSI,
          &c4_r, &c4_regionIndices);
      }

      c4_wc[(int32_T)c4_b_n - 1] = c4_M / c4_sumIntensity;
    }

    c4_i69 = c4_stats.size[0];
    c4_i74 = (int32_T)c4_f_k;
    if ((c4_i74 < 1) || (c4_i74 > c4_i69)) {
      emlrtDynamicBoundsCheckR2012b(c4_i74, 1, c4_i69, &c4_lc_emlrtBCI, &c4_st);
    }

    c4_d7 = (real_T)c4_i74;
    for (c4_i80 = 0; c4_i80 < 2; c4_i80++) {
      c4_stats.vector.data[(int32_T)c4_d7 - 1].WeightedCentroid[c4_i80] =
        c4_wc[c4_i80];
    }
  }

  c4_array_real_T_Destructor(chartInstance, &c4_r1);
  c4_array_real_T_2D_Destructor(chartInstance, &c4_result);
  c4_array_real_T_Destructor(chartInstance, &c4_r);
  c4_array_real_T_Destructor(chartInstance, &c4_regionIndices);
  c4_st.site = &c4_jc_emlrtRSI;
  c4_d5 = (real_T)c4_stats.size[0];
  c4_i33 = (int32_T)c4_d5;
  for (c4_i_k = 0; c4_i_k < c4_i33; c4_i_k++) {
    c4_j_k = (real_T)c4_i_k + 1.0;
    c4_i43 = c4_stats.size[0];
    c4_i46 = (int32_T)c4_j_k;
    if ((c4_i46 < 1) || (c4_i46 > c4_i43)) {
      emlrtDynamicBoundsCheckR2012b(c4_i46, 1, c4_i43, &c4_mc_emlrtBCI, &c4_st);
    }

    c4_i53 = c4_outstats->size[0];
    c4_i58 = (int32_T)c4_j_k;
    if ((c4_i58 < 1) || (c4_i58 > c4_i53)) {
      emlrtDynamicBoundsCheckR2012b(c4_i58, 1, c4_i53, &c4_nc_emlrtBCI, &c4_st);
    }

    for (c4_vIdx = 0; c4_vIdx < 2; c4_vIdx++) {
      c4_b_vIdx = (real_T)c4_vIdx + 1.0;
      c4_i68 = c4_stats.size[0];
      c4_i73 = (int32_T)c4_j_k;
      if ((c4_i73 < 1) || (c4_i73 > c4_i68)) {
        emlrtDynamicBoundsCheckR2012b(c4_i73, 1, c4_i68, &c4_oc_emlrtBCI, &c4_st);
      }

      c4_d6 = (real_T)c4_i73;
      c4_i79 = c4_outstats->size[0];
      c4_i83 = (int32_T)c4_j_k;
      if ((c4_i83 < 1) || (c4_i83 > c4_i79)) {
        emlrtDynamicBoundsCheckR2012b(c4_i83, 1, c4_i79, &c4_tc_emlrtBCI, &c4_st);
      }

      c4_i88 = c4_i83 - 1;
      c4_outstats->vector.data[c4_i88].WeightedCentroid[(int32_T)c4_b_vIdx - 1] =
        c4_stats.vector.data[(int32_T)c4_d6 - 1].WeightedCentroid[(int32_T)
        c4_b_vIdx - 1];
    }
  }

  c4_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c4_stats);
}

static void c4_bwconncomp(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200],
  c4_s_8vINxG2sU0DyuufNTJYdGF *c4_CC)
{
  c4_cell_wrap_34 c4_rv[1];
  c4_cell_wrap_34 c4_r2;
  c4_coder_array_cell_wrap_34_2D c4_r1;
  c4_coder_array_int32_T c4_b_x;
  c4_coder_array_int32_T c4_c_x;
  c4_coder_array_int32_T c4_d_x;
  c4_coder_array_int32_T c4_endRow;
  c4_coder_array_int32_T c4_idxCount;
  c4_coder_array_int32_T c4_labelForEachRun;
  c4_coder_array_int32_T c4_labelsRenumbered;
  c4_coder_array_int32_T c4_startCol;
  c4_coder_array_int32_T c4_startRow;
  c4_coder_array_real_T c4_r;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_st;
  real_T c4_b_col;
  real_T c4_b_k;
  real_T c4_b_s;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d_col;
  real_T c4_k_k;
  real_T c4_numComponents;
  real_T c4_y;
  int32_T c4_b_iv[1];
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_c;
  int32_T c4_b_dim;
  int32_T c4_b_loop_ub;
  int32_T c4_b_node;
  int32_T c4_b_p;
  int32_T c4_b_root_k;
  int32_T c4_b_root_p;
  int32_T c4_b_vlen;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_col;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_p;
  int32_T c4_c_vlen;
  int32_T c4_col;
  int32_T c4_column_offset;
  int32_T c4_currentColumn;
  int32_T c4_d_a;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_d_vlen;
  int32_T c4_dim;
  int32_T c4_e_a;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_exitg1;
  int32_T c4_f_a;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_firstRunOnPreviousColumn;
  int32_T c4_firstRunOnThisColumn;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i9;
  int32_T c4_i_k;
  int32_T c4_i_loop_ub;
  int32_T c4_ib;
  int32_T c4_idx;
  int32_T c4_inb;
  int32_T c4_j_k;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_lastRunOnPreviousColumn;
  int32_T c4_lidx;
  int32_T c4_loop_ub;
  int32_T c4_nextLabel;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_node;
  int32_T c4_numRuns;
  int32_T c4_p;
  int32_T c4_root_k;
  int32_T c4_root_p;
  int32_T c4_row;
  int32_T c4_rowidx;
  int32_T c4_runCounter;
  int32_T c4_vlen;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_d_overflow;
  boolean_T c4_i_b;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  c4_CC->Connectivity = 8.0;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_CC->ImageSize[c4_i] = 120.0 + 40.0 * (real_T)c4_i;
  }

  c4_st.site = &c4_kc_emlrtRSI;
  c4_b_st.site = &c4_tc_emlrtRSI;
  c4_numRuns = 0;
  for (c4_col = 0; c4_col < 160; c4_col++) {
    c4_b_col = (real_T)c4_col + 1.0;
    if (c4_varargin_1[120 * ((int32_T)c4_b_col - 1)]) {
      c4_numRuns++;
    }

    for (c4_k = 0; c4_k < 119; c4_k++) {
      c4_b_k = (real_T)c4_k + 2.0;
      if (c4_varargin_1[((int32_T)c4_b_k + 120 * ((int32_T)c4_b_col - 1)) - 1] &&
          (!c4_varargin_1[((int32_T)(c4_b_k - 1.0) + 120 * ((int32_T)c4_b_col -
             1)) - 1])) {
        c4_numRuns++;
      }
    }
  }

  c4_array_int32_T_Constructor(chartInstance, &c4_startRow);
  c4_array_int32_T_Constructor(chartInstance, &c4_endRow);
  c4_array_int32_T_Constructor(chartInstance, &c4_startCol);
  c4_array_int32_T_Constructor(chartInstance, &c4_labelForEachRun);
  if (c4_numRuns == 0) {
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_startRow,
      &c4_xd_emlrtRTEI, 0);
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_endRow,
      &c4_yd_emlrtRTEI, 0);
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_startCol,
      &c4_ae_emlrtRTEI, 0);
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_labelForEachRun,
      &c4_be_emlrtRTEI, 0);
    c4_numRuns = 0;
  } else {
    c4_d = (real_T)c4_numRuns;
    if (!(c4_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c4_d, &c4_e_emlrtDCI, &c4_b_st);
    }

    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_startRow,
      &c4_td_emlrtRTEI, (int32_T)muDoubleScalarFloor(c4_d));
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_endRow,
      &c4_ud_emlrtRTEI, c4_numRuns);
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_startCol,
      &c4_vd_emlrtRTEI, c4_numRuns);
    c4_c_st.site = &c4_uc_emlrtRSI;
    c4_runCounter = 1;
    for (c4_c_col = 0; c4_c_col < 160; c4_c_col++) {
      c4_d_col = (real_T)c4_c_col + 1.0;
      c4_row = 1;
      while (c4_row <= 120) {
        while ((c4_row <= 120) && (!c4_varargin_1[(c4_row + 120 * ((int32_T)
                  c4_d_col - 1)) - 1])) {
          c4_row++;
        }

        if ((c4_row <= 120) && c4_varargin_1[(c4_row + 120 * ((int32_T)c4_d_col
              - 1)) - 1]) {
          c4_i2 = c4_startCol.size[0];
          if ((c4_runCounter < 1) || (c4_runCounter > c4_i2)) {
            emlrtDynamicBoundsCheckR2012b(c4_runCounter, 1, c4_i2,
              &c4_md_emlrtBCI, &c4_c_st);
          }

          c4_startCol.vector.data[c4_runCounter - 1] = (int32_T)c4_d_col;
          c4_i3 = c4_startRow.size[0];
          if ((c4_runCounter < 1) || (c4_runCounter > c4_i3)) {
            emlrtDynamicBoundsCheckR2012b(c4_runCounter, 1, c4_i3,
              &c4_od_emlrtBCI, &c4_c_st);
          }

          c4_startRow.vector.data[c4_runCounter - 1] = c4_row;
          while ((c4_row <= 120) && c4_varargin_1[(c4_row + 120 * ((int32_T)
                   c4_d_col - 1)) - 1]) {
            c4_row++;
          }

          c4_i8 = c4_endRow.size[0];
          if ((c4_runCounter < 1) || (c4_runCounter > c4_i8)) {
            emlrtDynamicBoundsCheckR2012b(c4_runCounter, 1, c4_i8,
              &c4_sd_emlrtBCI, &c4_c_st);
          }

          c4_endRow.vector.data[c4_runCounter - 1] = c4_row - 1;
          c4_runCounter++;
        }
      }
    }

    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_labelForEachRun,
      &c4_wd_emlrtRTEI, c4_numRuns);
    c4_loop_ub = c4_numRuns - 1;
    for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
      c4_labelForEachRun.vector.data[c4_i1] = 0;
    }

    c4_c_k = 1;
    c4_currentColumn = 2;
    c4_nextLabel = 1;
    c4_firstRunOnPreviousColumn = -1;
    c4_lastRunOnPreviousColumn = 0;
    c4_firstRunOnThisColumn = 1;
    while (c4_c_k <= c4_numRuns) {
      c4_i4 = c4_startCol.size[0];
      if ((c4_c_k < 1) || (c4_c_k > c4_i4)) {
        emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i4, &c4_nd_emlrtBCI,
          &c4_b_st);
      }

      if (c4_startCol.vector.data[c4_c_k - 1] == c4_currentColumn) {
        c4_firstRunOnPreviousColumn = c4_firstRunOnThisColumn;
        c4_firstRunOnThisColumn = c4_c_k;
        c4_lastRunOnPreviousColumn = c4_c_k;
        c4_i13 = c4_startCol.size[0];
        if ((c4_c_k < 1) || (c4_c_k > c4_i13)) {
          emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i13, &c4_rd_emlrtBCI,
            &c4_b_st);
        }

        c4_currentColumn = c4_startCol.vector.data[c4_c_k - 1] + 1;
      } else {
        c4_i7 = c4_startCol.size[0];
        if ((c4_c_k < 1) || (c4_c_k > c4_i7)) {
          emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i7, &c4_pd_emlrtBCI,
            &c4_b_st);
        }

        if (c4_startCol.vector.data[c4_c_k - 1] > c4_currentColumn) {
          c4_firstRunOnPreviousColumn = -1;
          c4_lastRunOnPreviousColumn = 0;
          c4_firstRunOnThisColumn = c4_c_k;
          c4_i16 = c4_startCol.size[0];
          if ((c4_c_k < 1) || (c4_c_k > c4_i16)) {
            emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i16, &c4_td_emlrtBCI,
              &c4_b_st);
          }

          c4_currentColumn = c4_startCol.vector.data[c4_c_k - 1] + 1;
        }
      }

      if (c4_firstRunOnPreviousColumn >= 0) {
        for (c4_p = c4_firstRunOnPreviousColumn; c4_p <
             c4_lastRunOnPreviousColumn; c4_p++) {
          c4_i20 = c4_endRow.size[0];
          if ((c4_c_k < 1) || (c4_c_k > c4_i20)) {
            emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i20, &c4_be_emlrtBCI,
              &c4_b_st);
          }

          c4_i22 = c4_startRow.size[0];
          if ((c4_p < 1) || (c4_p > c4_i22)) {
            emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i22, &c4_ce_emlrtBCI,
              &c4_b_st);
          }

          if (c4_endRow.vector.data[c4_c_k - 1] >= c4_startRow.vector.data[c4_p
              - 1] - 1) {
            c4_i24 = c4_startRow.size[0];
            if ((c4_c_k < 1) || (c4_c_k > c4_i24)) {
              emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i24, &c4_de_emlrtBCI,
                &c4_b_st);
            }

            c4_i26 = c4_endRow.size[0];
            if ((c4_p < 1) || (c4_p > c4_i26)) {
              emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i26, &c4_ee_emlrtBCI,
                &c4_b_st);
            }

            if (c4_startRow.vector.data[c4_c_k - 1] <=
                c4_endRow.vector.data[c4_p - 1] + 1) {
              c4_i28 = c4_labelForEachRun.size[0];
              if ((c4_c_k < 1) || (c4_c_k > c4_i28)) {
                emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i28, &c4_fe_emlrtBCI,
                  &c4_b_st);
              }

              if (c4_labelForEachRun.vector.data[c4_c_k - 1] == 0) {
                c4_i31 = c4_labelForEachRun.size[0];
                if ((c4_p < 1) || (c4_p > c4_i31)) {
                  emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i31, &c4_ie_emlrtBCI,
                    &c4_b_st);
                }

                c4_i34 = c4_labelForEachRun.size[0];
                if ((c4_c_k < 1) || (c4_c_k > c4_i34)) {
                  emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i34,
                    &c4_je_emlrtBCI, &c4_b_st);
                }

                c4_labelForEachRun.vector.data[c4_c_k - 1] =
                  c4_labelForEachRun.vector.data[c4_p - 1];
                c4_nextLabel++;
              } else {
                c4_i30 = c4_labelForEachRun.size[0];
                if ((c4_c_k < 1) || (c4_c_k > c4_i30)) {
                  emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i30,
                    &c4_ge_emlrtBCI, &c4_b_st);
                }

                c4_i33 = c4_labelForEachRun.size[0];
                if ((c4_p < 1) || (c4_p > c4_i33)) {
                  emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i33, &c4_he_emlrtBCI,
                    &c4_b_st);
                }

                if (c4_labelForEachRun.vector.data[c4_c_k - 1] !=
                    c4_labelForEachRun.vector.data[c4_p - 1]) {
                  c4_c_st.site = &c4_vc_emlrtRSI;
                  c4_g_k = c4_c_k;
                  c4_b_p = c4_p;
                  c4_d_st.site = &c4_wc_emlrtRSI;
                  c4_node = c4_g_k;
                  c4_root_k = c4_node;
                  do {
                    c4_exitg1 = 0;
                    c4_i36 = c4_labelForEachRun.size[0];
                    if ((c4_root_k < 1) || (c4_root_k > c4_i36)) {
                      emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i36,
                        &c4_pe_emlrtBCI, &c4_d_st);
                    }

                    if (c4_root_k != c4_labelForEachRun.vector.data[c4_root_k -
                        1]) {
                      c4_i38 = c4_labelForEachRun.size[0];
                      c4_i39 = c4_labelForEachRun.size[0];
                      if ((c4_root_k < 1) || (c4_root_k > c4_i39)) {
                        emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i39,
                          &c4_re_emlrtBCI, &c4_d_st);
                      }

                      c4_i40 = c4_labelForEachRun.vector.data[c4_root_k - 1];
                      if ((c4_i40 < 1) || (c4_i40 > c4_i38)) {
                        emlrtDynamicBoundsCheckR2012b(c4_i40, 1, c4_i38,
                          &c4_qe_emlrtBCI, &c4_d_st);
                      }

                      c4_i42 = c4_labelForEachRun.size[0];
                      if ((c4_root_k < 1) || (c4_root_k > c4_i42)) {
                        emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i42,
                          &c4_se_emlrtBCI, &c4_d_st);
                      }

                      c4_labelForEachRun.vector.data[c4_root_k - 1] =
                        c4_labelForEachRun.vector.data[c4_i40 - 1];
                      c4_i44 = c4_labelForEachRun.size[0];
                      if ((c4_root_k < 1) || (c4_root_k > c4_i44)) {
                        emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i44,
                          &c4_te_emlrtBCI, &c4_d_st);
                      }

                      c4_root_k = c4_labelForEachRun.vector.data[c4_root_k - 1];
                    } else {
                      c4_exitg1 = 1;
                    }
                  } while (c4_exitg1 == 0);

                  c4_d_st.site = &c4_xc_emlrtRSI;
                  c4_b_node = c4_b_p;
                  c4_root_p = c4_b_node;
                  do {
                    c4_exitg1 = 0;
                    c4_i43 = c4_labelForEachRun.size[0];
                    if ((c4_root_p < 1) || (c4_root_p > c4_i43)) {
                      emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i43,
                        &c4_pe_emlrtBCI, &c4_d_st);
                    }

                    if (c4_root_p != c4_labelForEachRun.vector.data[c4_root_p -
                        1]) {
                      c4_i45 = c4_labelForEachRun.size[0];
                      c4_i46 = c4_labelForEachRun.size[0];
                      if ((c4_root_p < 1) || (c4_root_p > c4_i46)) {
                        emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i46,
                          &c4_re_emlrtBCI, &c4_d_st);
                      }

                      c4_i47 = c4_labelForEachRun.vector.data[c4_root_p - 1];
                      if ((c4_i47 < 1) || (c4_i47 > c4_i45)) {
                        emlrtDynamicBoundsCheckR2012b(c4_i47, 1, c4_i45,
                          &c4_qe_emlrtBCI, &c4_d_st);
                      }

                      c4_i48 = c4_labelForEachRun.size[0];
                      if ((c4_root_p < 1) || (c4_root_p > c4_i48)) {
                        emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i48,
                          &c4_se_emlrtBCI, &c4_d_st);
                      }

                      c4_labelForEachRun.vector.data[c4_root_p - 1] =
                        c4_labelForEachRun.vector.data[c4_i47 - 1];
                      c4_i52 = c4_labelForEachRun.size[0];
                      if ((c4_root_p < 1) || (c4_root_p > c4_i52)) {
                        emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i52,
                          &c4_te_emlrtBCI, &c4_d_st);
                      }

                      c4_root_p = c4_labelForEachRun.vector.data[c4_root_p - 1];
                    } else {
                      c4_exitg1 = 1;
                    }
                  } while (c4_exitg1 == 0);

                  if (c4_root_k != c4_root_p) {
                    c4_d_st.site = &c4_yc_emlrtRSI;
                    c4_b_root_k = c4_root_k;
                    c4_b_root_p = c4_root_p;
                    c4_i_k = c4_g_k;
                    c4_c_p = c4_b_p;
                    if (c4_b_root_p < c4_b_root_k) {
                      c4_i51 = c4_labelForEachRun.size[0];
                      if ((c4_b_root_k < 1) || (c4_b_root_k > c4_i51)) {
                        emlrtDynamicBoundsCheckR2012b(c4_b_root_k, 1, c4_i51,
                          &c4_ve_emlrtBCI, &c4_d_st);
                      }

                      c4_labelForEachRun.vector.data[c4_b_root_k - 1] =
                        c4_b_root_p;
                      c4_i54 = c4_labelForEachRun.size[0];
                      if ((c4_i_k < 1) || (c4_i_k > c4_i54)) {
                        emlrtDynamicBoundsCheckR2012b(c4_i_k, 1, c4_i54,
                          &c4_xe_emlrtBCI, &c4_d_st);
                      }

                      c4_labelForEachRun.vector.data[c4_i_k - 1] = c4_b_root_p;
                    } else {
                      c4_i50 = c4_labelForEachRun.size[0];
                      if ((c4_b_root_p < 1) || (c4_b_root_p > c4_i50)) {
                        emlrtDynamicBoundsCheckR2012b(c4_b_root_p, 1, c4_i50,
                          &c4_ue_emlrtBCI, &c4_d_st);
                      }

                      c4_labelForEachRun.vector.data[c4_b_root_p - 1] =
                        c4_b_root_k;
                      c4_i53 = c4_labelForEachRun.size[0];
                      if ((c4_c_p < 1) || (c4_c_p > c4_i53)) {
                        emlrtDynamicBoundsCheckR2012b(c4_c_p, 1, c4_i53,
                          &c4_we_emlrtBCI, &c4_d_st);
                      }

                      c4_labelForEachRun.vector.data[c4_c_p - 1] = c4_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c4_i17 = c4_labelForEachRun.size[0];
      if ((c4_c_k < 1) || (c4_c_k > c4_i17)) {
        emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i17, &c4_yd_emlrtBCI,
          &c4_b_st);
      }

      if (c4_labelForEachRun.vector.data[c4_c_k - 1] == 0) {
        c4_i21 = c4_labelForEachRun.size[0];
        if ((c4_c_k < 1) || (c4_c_k > c4_i21)) {
          emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i21, &c4_ae_emlrtBCI,
            &c4_b_st);
        }

        c4_labelForEachRun.vector.data[c4_c_k - 1] = c4_nextLabel;
        c4_nextLabel++;
      }

      c4_c_k++;
    }
  }

  c4_array_real_T_Constructor(chartInstance, &c4_r);
  c4_array_cell_wrap_34_2D_Construct(chartInstance, &c4_r1);
  if (c4_numRuns == 0) {
    c4_d1 = 0.0;
    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r, &c4_le_emlrtRTEI, 0);
    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_labelForEachRun,
      &c4_me_emlrtRTEI, 1);
    c4_labelForEachRun.vector.data[0] = 0;
    c4_array_cell_wrap_34_2D_SetSize(chartInstance, &c4_st, &c4_r1,
      &c4_ne_emlrtRTEI, 1, 0);
  } else {
    c4_array_int32_T_Constructor(chartInstance, &c4_labelsRenumbered);
    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_labelsRenumbered,
      &c4_ce_emlrtRTEI, c4_labelForEachRun.size[0]);
    c4_numComponents = 0.0;
    c4_b_st.site = &c4_sc_emlrtRSI;
    c4_b = c4_numRuns;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_d_k = 0; c4_d_k < c4_numRuns; c4_d_k++) {
      c4_e_k = c4_d_k + 1;
      c4_i6 = c4_labelForEachRun.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i6)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i6, &c4_qd_emlrtBCI, &c4_st);
      }

      if (c4_labelForEachRun.vector.data[c4_e_k - 1] == c4_e_k) {
        c4_numComponents++;
        c4_i11 = c4_labelsRenumbered.size[0];
        if ((c4_e_k < 1) || (c4_e_k > c4_i11)) {
          emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i11, &c4_xd_emlrtBCI,
            &c4_st);
        }

        c4_labelsRenumbered.vector.data[c4_e_k - 1] = (int32_T)c4_numComponents;
      }

      c4_i10 = c4_labelsRenumbered.size[0];
      c4_i14 = c4_labelForEachRun.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i14)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i14, &c4_vd_emlrtBCI, &c4_st);
      }

      c4_i15 = c4_labelForEachRun.vector.data[c4_e_k - 1];
      if ((c4_i15 < 1) || (c4_i15 > c4_i10)) {
        emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_i10, &c4_ud_emlrtBCI, &c4_st);
      }

      c4_i19 = c4_labelsRenumbered.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i19)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i19, &c4_wd_emlrtBCI, &c4_st);
      }

      c4_labelsRenumbered.vector.data[c4_e_k - 1] =
        c4_labelsRenumbered.vector.data[c4_i15 - 1];
    }

    if (c4_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c4_numComponents)) {
      emlrtIntegerCheckR2012b(c4_numComponents, &c4_b_emlrtDCI, &c4_st);
    }

    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_labelForEachRun,
      &c4_de_emlrtRTEI, (int32_T)c4_numComponents);
    if (c4_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c4_numComponents)) {
      emlrtIntegerCheckR2012b(c4_numComponents, &c4_b_emlrtDCI, &c4_st);
    }

    c4_c_loop_ub = (int32_T)c4_numComponents - 1;
    for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
      c4_labelForEachRun.vector.data[c4_i9] = 0;
    }

    c4_b_st.site = &c4_rc_emlrtRSI;
    c4_c_b = c4_numRuns;
    c4_d_b = c4_c_b;
    if (c4_d_b < 1) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_d_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_f_k = 0; c4_f_k < c4_numRuns; c4_f_k++) {
      c4_e_k = c4_f_k + 1;
      c4_i23 = c4_labelsRenumbered.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i23)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i23, &c4_ke_emlrtBCI, &c4_st);
      }

      c4_idx = c4_labelsRenumbered.vector.data[c4_e_k - 1];
      c4_i25 = c4_labelForEachRun.size[0];
      if ((c4_idx < 1) || (c4_idx > c4_i25)) {
        emlrtDynamicBoundsCheckR2012b(c4_idx, 1, c4_i25, &c4_le_emlrtBCI, &c4_st);
      }

      c4_i27 = c4_endRow.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i27)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i27, &c4_me_emlrtBCI, &c4_st);
      }

      c4_i29 = c4_startRow.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i29)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i29, &c4_ne_emlrtBCI, &c4_st);
      }

      c4_i32 = c4_labelForEachRun.size[0];
      if ((c4_idx < 1) || (c4_idx > c4_i32)) {
        emlrtDynamicBoundsCheckR2012b(c4_idx, 1, c4_i32, &c4_oe_emlrtBCI, &c4_st);
      }

      c4_labelForEachRun.vector.data[c4_idx - 1] =
        ((c4_labelForEachRun.vector.data[c4_idx - 1] +
          c4_endRow.vector.data[c4_e_k - 1]) - c4_startRow.vector.data[c4_e_k -
         1]) + 1;
    }

    c4_d1 = c4_numComponents;
    c4_b_st.site = &c4_qc_emlrtRSI;
    c4_c_st.site = &c4_ad_emlrtRSI;
    c4_d_st.site = &c4_bd_emlrtRSI;
    c4_vlen = c4_labelForEachRun.size[0];
    c4_e_st.site = &c4_cd_emlrtRSI;
    c4_b_vlen = c4_vlen;
    if ((c4_labelForEachRun.size[0] == 0) || (c4_b_vlen == 0)) {
      c4_y = 0.0;
    } else {
      c4_f_st.site = &c4_dd_emlrtRSI;
      c4_c_vlen = c4_b_vlen;
      c4_g_st.site = &c4_ed_emlrtRSI;
      c4_d_vlen = c4_c_vlen;
      if (c4_d_vlen < 4096) {
        c4_h_st.site = &c4_fd_emlrtRSI;
        c4_y = c4_sumColumnB(chartInstance, &c4_h_st, &c4_labelForEachRun,
                             c4_d_vlen);
      } else {
        c4_a = c4_d_vlen;
        c4_nfb = (int32_T)((uint32_T)c4_a >> 12);
        c4_inb = c4_nfb << 12;
        c4_lidx = c4_inb;
        c4_nleft = c4_d_vlen - c4_inb;
        c4_b_s = c4_sumColumnB4(chartInstance, &c4_labelForEachRun, 1);
        for (c4_ib = 2; c4_ib <= c4_nfb; c4_ib++) {
          c4_b_s += c4_sumColumnB4(chartInstance, &c4_labelForEachRun, 1 +
            ((c4_ib - 1) << 12));
        }

        if (c4_nleft > 0) {
          c4_h_st.site = &c4_gd_emlrtRSI;
          c4_b_s += c4_b_sumColumnB(chartInstance, &c4_h_st, &c4_labelForEachRun,
            c4_nleft, c4_lidx + 1);
        }

        c4_y = c4_b_s;
      }
    }

    if (!(c4_y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c4_y, &c4_d_emlrtDCI, &c4_st);
    }

    c4_d2 = c4_y;
    if (c4_d2 != (real_T)(int32_T)muDoubleScalarFloor(c4_d2)) {
      emlrtIntegerCheckR2012b(c4_d2, &c4_c_emlrtDCI, &c4_st);
    }

    c4_b_iv[0] = (int32_T)c4_d2;
    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r, &c4_ee_emlrtRTEI,
      c4_b_iv[0]);
    c4_array_int32_T_Constructor(chartInstance, &c4_b_x);
    c4_b_st.site = &c4_pc_emlrtRSI;
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_b_x, &c4_fe_emlrtRTEI,
      c4_labelForEachRun.size[0]);
    c4_f_loop_ub = c4_labelForEachRun.size[0] - 1;
    for (c4_i35 = 0; c4_i35 <= c4_f_loop_ub; c4_i35++) {
      c4_b_x.vector.data[c4_i35] = c4_labelForEachRun.vector.data[c4_i35];
    }

    c4_c_st.site = &c4_kd_emlrtRSI;
    c4_dim = 2;
    if (c4_b_x.size[0] != 1) {
      c4_dim = 1;
    }

    c4_array_int32_T_Constructor(chartInstance, &c4_c_x);
    c4_array_int32_T_SetSize(chartInstance, &c4_c_st, &c4_c_x, &c4_cd_emlrtRTEI,
      c4_b_x.size[0]);
    c4_g_loop_ub = c4_b_x.size[0] - 1;
    for (c4_i37 = 0; c4_i37 <= c4_g_loop_ub; c4_i37++) {
      c4_c_x.vector.data[c4_i37] = c4_b_x.vector.data[c4_i37];
    }

    c4_d_st.site = &c4_ld_emlrtRSI;
    c4_useConstantDim(chartInstance, &c4_d_st, &c4_c_x, c4_dim, &c4_b_x);
    c4_array_int32_T_Destructor(chartInstance, &c4_c_x);
    c4_array_int32_T_Constructor(chartInstance, &c4_idxCount);
    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_idxCount,
      &c4_ge_emlrtRTEI, 1 + c4_b_x.size[0]);
    c4_idxCount.vector.data[0] = 0;
    c4_h_loop_ub = c4_b_x.size[0] - 1;
    for (c4_i41 = 0; c4_i41 <= c4_h_loop_ub; c4_i41++) {
      c4_idxCount.vector.data[c4_i41 + 1] = c4_b_x.vector.data[c4_i41];
    }

    c4_b_st.site = &c4_oc_emlrtRSI;
    c4_e_b = c4_numRuns;
    c4_f_b = c4_e_b;
    if (c4_f_b < 1) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_f_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_h_k = 0; c4_h_k < c4_numRuns; c4_h_k++) {
      c4_e_k = c4_h_k + 1;
      c4_i49 = c4_startCol.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i49)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i49, &c4_ye_emlrtBCI, &c4_st);
      }

      c4_b_a = c4_startCol.vector.data[c4_e_k - 1] - 1;
      c4_c = c4_b_a;
      c4_c_a = c4_c;
      c4_column_offset = c4_c_a * 120;
      c4_i55 = c4_labelsRenumbered.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i55)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i55, &c4_af_emlrtBCI, &c4_st);
      }

      c4_idx = c4_labelsRenumbered.vector.data[c4_e_k - 1];
      c4_i57 = c4_startRow.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i57)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i57, &c4_bf_emlrtBCI, &c4_st);
      }

      c4_i58 = c4_startRow.vector.data[c4_e_k - 1];
      c4_i59 = c4_endRow.size[0];
      if ((c4_e_k < 1) || (c4_e_k > c4_i59)) {
        emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i59, &c4_cf_emlrtBCI, &c4_st);
      }

      c4_i60 = c4_endRow.vector.data[c4_e_k - 1];
      c4_b_st.site = &c4_nc_emlrtRSI;
      c4_d_a = c4_i58;
      c4_g_b = c4_i60;
      c4_e_a = c4_d_a;
      c4_h_b = c4_g_b;
      if (c4_e_a > c4_h_b) {
        c4_d_overflow = false;
      } else {
        c4_d_overflow = (c4_h_b > 2147483646);
      }

      if (c4_d_overflow) {
        c4_c_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_rowidx = c4_i58; c4_rowidx <= c4_i60; c4_rowidx++) {
        c4_i64 = c4_idxCount.size[0];
        if ((c4_idx < 1) || (c4_idx > c4_i64)) {
          emlrtDynamicBoundsCheckR2012b(c4_idx, 1, c4_i64, &c4_ff_emlrtBCI,
            &c4_st);
        }

        c4_f_a = c4_idxCount.vector.data[c4_idx - 1] + 1;
        c4_b_c = c4_f_a;
        c4_i66 = c4_idxCount.size[0];
        if ((c4_idx < 1) || (c4_idx > c4_i66)) {
          emlrtDynamicBoundsCheckR2012b(c4_idx, 1, c4_i66, &c4_gf_emlrtBCI,
            &c4_st);
        }

        c4_idxCount.vector.data[c4_idx - 1] = c4_b_c;
        c4_i69 = c4_r.size[0];
        c4_i71 = c4_idxCount.size[0];
        if ((c4_idx < 1) || (c4_idx > c4_i71)) {
          emlrtDynamicBoundsCheckR2012b(c4_idx, 1, c4_i71, &c4_if_emlrtBCI,
            &c4_st);
        }

        c4_i73 = c4_idxCount.vector.data[c4_idx - 1];
        if ((c4_i73 < 1) || (c4_i73 > c4_i69)) {
          emlrtDynamicBoundsCheckR2012b(c4_i73, 1, c4_i69, &c4_hf_emlrtBCI,
            &c4_st);
        }

        c4_r.vector.data[c4_i73 - 1] = (real_T)(c4_rowidx + c4_column_offset);
      }
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_labelsRenumbered);
    c4_array_cell_wrap_34_Constructor(chartInstance, &c4_r2);
    c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r2.f1, &c4_he_emlrtRTEI,
      0);
    c4_array_cell_wrap_34_1s_Construct(chartInstance, c4_rv);
    c4_array_cell_wrap_34_Copy(chartInstance, &c4_st, &c4_rv[0], &c4_r2,
      &c4_he_emlrtRTEI);
    c4_array_cell_wrap_34_Destructor(chartInstance, &c4_r2);
    c4_b_st.site = &c4_mc_emlrtRSI;
    c4_repmat(chartInstance, &c4_b_st, c4_rv, c4_numComponents, &c4_r1);
    c4_array_cell_wrap_34_1s_Destructo(chartInstance, c4_rv);
    c4_b_st.site = &c4_lc_emlrtRSI;
    c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_b_x, &c4_ie_emlrtRTEI,
      c4_labelForEachRun.size[0]);
    c4_i_loop_ub = c4_labelForEachRun.size[0] - 1;
    for (c4_i56 = 0; c4_i56 <= c4_i_loop_ub; c4_i56++) {
      c4_b_x.vector.data[c4_i56] = c4_labelForEachRun.vector.data[c4_i56];
    }

    c4_c_st.site = &c4_kd_emlrtRSI;
    c4_b_dim = 2;
    if (c4_b_x.size[0] != 1) {
      c4_b_dim = 1;
    }

    c4_array_int32_T_Constructor(chartInstance, &c4_d_x);
    c4_array_int32_T_SetSize(chartInstance, &c4_c_st, &c4_d_x, &c4_cd_emlrtRTEI,
      c4_b_x.size[0]);
    c4_j_loop_ub = c4_b_x.size[0] - 1;
    for (c4_i61 = 0; c4_i61 <= c4_j_loop_ub; c4_i61++) {
      c4_d_x.vector.data[c4_i61] = c4_b_x.vector.data[c4_i61];
    }

    c4_d_st.site = &c4_ld_emlrtRSI;
    c4_useConstantDim(chartInstance, &c4_d_st, &c4_d_x, c4_b_dim, &c4_b_x);
    c4_array_int32_T_Destructor(chartInstance, &c4_d_x);
    c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_idxCount,
      &c4_je_emlrtRTEI, 1 + c4_b_x.size[0]);
    c4_idxCount.vector.data[0] = 0;
    c4_k_loop_ub = c4_b_x.size[0] - 1;
    for (c4_i62 = 0; c4_i62 <= c4_k_loop_ub; c4_i62++) {
      c4_idxCount.vector.data[c4_i62 + 1] = c4_b_x.vector.data[c4_i62];
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_b_x);
    c4_i63 = (int32_T)c4_numComponents;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_numComponents, mxDOUBLE_CLASS,
      c4_i63, &c4_yg_emlrtRTEI, &c4_st);
    for (c4_j_k = 0; c4_j_k < c4_i63; c4_j_k++) {
      c4_k_k = (real_T)c4_j_k + 1.0;
      c4_i65 = c4_idxCount.size[0];
      c4_i67 = (int32_T)c4_k_k;
      if ((c4_i67 < 1) || (c4_i67 > c4_i65)) {
        emlrtDynamicBoundsCheckR2012b(c4_i67, 1, c4_i65, &c4_df_emlrtBCI, &c4_st);
      }

      c4_i68 = c4_idxCount.vector.data[c4_i67 - 1] + 1;
      c4_i70 = c4_idxCount.size[0];
      c4_i72 = (int32_T)(c4_k_k + 1.0);
      if ((c4_i72 < 1) || (c4_i72 > c4_i70)) {
        emlrtDynamicBoundsCheckR2012b(c4_i72, 1, c4_i70, &c4_ef_emlrtBCI, &c4_st);
      }

      c4_i74 = c4_idxCount.vector.data[c4_i72 - 1];
      c4_i_b = (c4_i68 > c4_i74);
      if (c4_i_b) {
        c4_i76 = 0;
        c4_i77 = -1;
      } else {
        c4_i75 = c4_r.size[0];
        if ((c4_i68 < 1) || (c4_i68 > c4_i75)) {
          emlrtDynamicBoundsCheckR2012b(c4_i68, 1, c4_i75, &c4_ld_emlrtBCI,
            &c4_st);
        }

        c4_i76 = c4_i68 - 1;
        c4_i79 = c4_r.size[0];
        if ((c4_i74 < 1) || (c4_i74 > c4_i79)) {
          emlrtDynamicBoundsCheckR2012b(c4_i74, 1, c4_i79, &c4_kd_emlrtBCI,
            &c4_st);
        }

        c4_i77 = c4_i74 - 1;
      }

      c4_i78 = c4_r1.size[1] - 1;
      c4_i80 = (int32_T)c4_k_k - 1;
      if ((c4_i80 < 0) || (c4_i80 > c4_i78)) {
        emlrtDynamicBoundsCheckR2012b(c4_i80, 0, c4_i78, &c4_jf_emlrtBCI, &c4_st);
      }

      c4_array_real_T_SetSize(chartInstance, &c4_st,
        &c4_r1.vector.data[c4_r1.size[0] * c4_i80].f1, &c4_ke_emlrtRTEI, (c4_i77
        - c4_i76) + 1);
      c4_l_loop_ub = c4_i77 - c4_i76;
      for (c4_i81 = 0; c4_i81 <= c4_l_loop_ub; c4_i81++) {
        c4_i82 = c4_r1.size[1] - 1;
        c4_i83 = (int32_T)c4_k_k - 1;
        if ((c4_i83 < 0) || (c4_i83 > c4_i82)) {
          emlrtDynamicBoundsCheckR2012b(c4_i83, 0, c4_i82, &c4_jf_emlrtBCI,
            &c4_st);
        }

        c4_r1.vector.data[c4_i83].f1.vector.data[c4_i81] =
          c4_r.vector.data[c4_i76 + c4_i81];
      }
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_idxCount);
  }

  c4_array_int32_T_Destructor(chartInstance, &c4_startCol);
  c4_array_int32_T_Destructor(chartInstance, &c4_endRow);
  c4_array_int32_T_Destructor(chartInstance, &c4_startRow);
  c4_CC->NumObjects = c4_d1;
  c4_st.site = &c4_kc_emlrtRSI;
  c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_CC->RegionIndices,
    &c4_oe_emlrtRTEI, c4_r.size[0]);
  c4_b_loop_ub = c4_r.size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_b_loop_ub; c4_i5++) {
    c4_CC->RegionIndices.vector.data[c4_i5] = c4_r.vector.data[c4_i5];
  }

  c4_array_real_T_Destructor(chartInstance, &c4_r);
  c4_st.site = &c4_kc_emlrtRSI;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_CC->RegionLengths,
    &c4_pe_emlrtRTEI, c4_labelForEachRun.size[0]);
  c4_d_loop_ub = c4_labelForEachRun.size[0] - 1;
  for (c4_i12 = 0; c4_i12 <= c4_d_loop_ub; c4_i12++) {
    c4_CC->RegionLengths.vector.data[c4_i12] =
      c4_labelForEachRun.vector.data[c4_i12];
  }

  c4_array_int32_T_Destructor(chartInstance, &c4_labelForEachRun);
  c4_st.site = &c4_kc_emlrtRSI;
  c4_array_cell_wrap_34_2D_SetSize(chartInstance, &c4_st, &c4_CC->PixelIdxList,
    &c4_qe_emlrtRTEI, 1, c4_r1.size[1]);
  c4_e_loop_ub = c4_r1.size[1] - 1;
  for (c4_i18 = 0; c4_i18 <= c4_e_loop_ub; c4_i18++) {
    c4_st.site = &c4_kc_emlrtRSI;
    c4_array_cell_wrap_34_Copy(chartInstance, &c4_st,
      &c4_CC->PixelIdxList.vector.data[c4_i18], &c4_r1.vector.data[c4_i18],
      &c4_qe_emlrtRTEI);
  }

  c4_array_cell_wrap_34_2D_Destructo(chartInstance, &c4_r1);
}

static real_T c4_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_b_x,
  int32_T c4_vlen)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_vlen;
  int32_T c4_b_vstart;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vstart;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_hd_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_y = (real_T)c4_b_x->vector.data[0];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_jd_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    c4_i1 = (uint16_T)c4_i;
    for (c4_f_k = 0; c4_f_k < c4_i1; c4_f_k++) {
      c4_g_k = c4_f_k;
      c4_y += (real_T)c4_b_x->vector.data[c4_g_k + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = (int32_T)((uint32_T)c4_a >> 10);
    c4_inb = c4_nfb << 10;
    c4_y = (real_T)c4_b_x->vector.data[0];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_c_k = c4_k;
      c4_y += (real_T)c4_b_x->vector.data[c4_c_k + 1];
    }

    for (c4_b_k = 2; c4_b_k <= c4_nfb; c4_b_k++) {
      c4_vstart = (c4_b_k - 1) << 10;
      c4_b_y = (real_T)c4_b_x->vector.data[c4_vstart];
      for (c4_d_k = 0; c4_d_k < 1023; c4_d_k++) {
        c4_e_k = c4_d_k;
        c4_b_y += (real_T)c4_b_x->vector.data[(c4_vstart + c4_e_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_inb;
      c4_st.site = &c4_id_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_b_vstart = c4_lidx;
      c4_c_y = (real_T)c4_b_x->vector.data[c4_b_vstart];
      c4_i2 = c4_c_vlen;
      c4_b_st.site = &c4_jd_emlrtRSI;
      c4_c_b = c4_i2;
      c4_d_b = c4_c_b;
      if (c4_d_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_d_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_h_k = 0; c4_h_k < c4_i2; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += (real_T)c4_b_x->vector.data[(c4_b_vstart + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static real_T c4_sumColumnB4(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_b_x, int32_T c4_vstart)
{
  real_T c4_psum1;
  real_T c4_psum2;
  real_T c4_psum3;
  real_T c4_psum4;
  int32_T c4_b_k;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  (void)chartInstance;
  c4_i2 = c4_vstart + 1023;
  c4_i3 = c4_vstart + 2047;
  c4_i4 = c4_vstart + 3071;
  c4_psum1 = (real_T)c4_b_x->vector.data[c4_vstart - 1];
  c4_psum2 = (real_T)c4_b_x->vector.data[c4_i2];
  c4_psum3 = (real_T)c4_b_x->vector.data[c4_i3];
  c4_psum4 = (real_T)c4_b_x->vector.data[c4_i4];
  for (c4_k = 0; c4_k < 1023; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_psum1 += (real_T)c4_b_x->vector.data[(c4_vstart + c4_b_k) - 1];
    c4_psum2 += (real_T)c4_b_x->vector.data[c4_i2 + c4_b_k];
    c4_psum3 += (real_T)c4_b_x->vector.data[c4_i3 + c4_b_k];
    c4_psum4 += (real_T)c4_b_x->vector.data[c4_i4 + c4_b_k];
  }

  return (c4_psum1 + c4_psum2) + (c4_psum3 + c4_psum4);
}

static real_T c4_b_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_b_x,
  int32_T c4_vlen, int32_T c4_vstart)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_vlen;
  int32_T c4_b_vstart;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_c_vstart;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_d_vstart;
  int32_T c4_e_k;
  int32_T c4_e_vstart;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_hd_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_b_vstart = c4_vstart - 1;
    c4_y = (real_T)c4_b_x->vector.data[c4_b_vstart];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_jd_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_f_k = 0; c4_f_k < c4_i; c4_f_k++) {
      c4_g_k = c4_f_k;
      c4_y += (real_T)c4_b_x->vector.data[(c4_b_vstart + c4_g_k) + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = (int32_T)((uint32_T)c4_a >> 10);
    c4_inb = c4_nfb << 10;
    c4_c_vstart = c4_vstart - 1;
    c4_y = (real_T)c4_b_x->vector.data[c4_c_vstart];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_c_k = c4_k;
      c4_y += (real_T)c4_b_x->vector.data[(c4_c_vstart + c4_c_k) + 1];
    }

    for (c4_b_k = 2; c4_b_k <= c4_nfb; c4_b_k++) {
      c4_d_vstart = (c4_vstart + ((c4_b_k - 1) << 10)) - 1;
      c4_b_y = (real_T)c4_b_x->vector.data[c4_d_vstart];
      for (c4_d_k = 0; c4_d_k < 1023; c4_d_k++) {
        c4_e_k = c4_d_k;
        c4_b_y += (real_T)c4_b_x->vector.data[(c4_d_vstart + c4_e_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_vstart + c4_inb;
      c4_st.site = &c4_id_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_e_vstart = c4_lidx - 1;
      c4_c_y = (real_T)c4_b_x->vector.data[c4_e_vstart];
      c4_i1 = c4_c_vlen;
      c4_b_st.site = &c4_jd_emlrtRSI;
      c4_c_b = c4_i1;
      c4_d_b = c4_c_b;
      if (c4_d_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_d_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_h_k = 0; c4_h_k < c4_i1; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += (real_T)c4_b_x->vector.data[(c4_e_vstart + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static void c4_useConstantDim(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_varargin_2,
  int32_T c4_varargin_3, c4_coder_array_int32_T *c4_varargout_1)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_nx;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  if (c4_varargin_3 == 1) {
    c4_st.site = &c4_md_emlrtRSI;
    c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_varargout_1,
      &c4_re_emlrtRTEI, c4_varargin_2->size[0]);
    c4_b_loop_ub = c4_varargin_2->size[0] - 1;
    for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
      c4_varargout_1->vector.data[c4_i1] = c4_varargin_2->vector.data[c4_i1];
    }

    c4_b_st.site = &c4_nd_emlrtRSI;
    if (c4_varargout_1->size[0] != 0) {
      c4_c_st.site = &c4_od_emlrtRSI;
      c4_nx = c4_varargout_1->size[0] - 1;
      if (c4_varargout_1->size[0] != 1) {
        c4_i2 = c4_nx;
        c4_d_st.site = &c4_pd_emlrtRSI;
        c4_b = c4_i2;
        c4_b_b = c4_b;
        if (c4_b_b < 1) {
          c4_overflow = false;
        } else {
          c4_overflow = (c4_b_b > 2147483646);
        }

        if (c4_overflow) {
          c4_e_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_k = 0; c4_k < c4_i2; c4_k++) {
          c4_b_k = c4_k;
          c4_varargout_1->vector.data[c4_b_k + 1] += c4_varargout_1->
            vector.data[c4_b_k];
        }
      }
    }
  } else {
    c4_array_int32_T_SetSize(chartInstance, c4_sp, c4_varargout_1,
      &c4_re_emlrtRTEI, c4_varargin_2->size[0]);
    c4_loop_ub = c4_varargin_2->size[0] - 1;
    for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
      c4_varargout_1->vector.data[c4_i] = c4_varargin_2->vector.data[c4_i];
    }
  }
}

static void c4_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_cell_wrap_34 c4_a[1], real_T
                      c4_varargin_2, c4_coder_array_cell_wrap_34_2D *c4_b)
{
  c4_coder_array_boolean_T_2D c4_tile;
  c4_coder_array_cell_wrap_34_2D c4_r;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_arg;
  real_T c4_b_arg;
  real_T c4_b_varargin_2;
  real_T c4_b_x;
  real_T c4_c_varargin_2;
  real_T c4_n;
  int32_T c4_outsize[2];
  int32_T c4_b_jtilecol;
  int32_T c4_b_loop_ub;
  int32_T c4_b_u;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_ibtile;
  int32_T c4_jtilecol;
  int32_T c4_loop_ub;
  int32_T c4_ntilecols;
  int32_T c4_u;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_qd_emlrtRSI;
  c4_b_varargin_2 = c4_varargin_2;
  c4_arg = c4_b_varargin_2;
  if (c4_arg != c4_arg) {
    c4_p = false;
  } else {
    c4_b_x = c4_arg;
    c4_b_b = muDoubleScalarIsInf(c4_b_x);
    if (c4_b_b) {
      c4_p = false;
    } else {
      c4_p = true;
    }
  }

  if (c4_p) {
    c4_b_arg = c4_b_varargin_2;
    if (c4_b_arg > 2.147483647E+9) {
      c4_b_p = false;
    } else {
      c4_b_p = true;
    }

    if (c4_b_p) {
      c4_c_b = true;
    } else {
      c4_c_b = false;
    }
  } else {
    c4_c_b = false;
  }

  if (!c4_c_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c4_u = MIN_int32_T;
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_u, 6, 0U, 0, 0U, 0), false);
    c4_b_u = MAX_int32_T;
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_b_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(&c4_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 3U, 14, c4_b_y, 14, c4_c_y, 14, c4_f_y)));
  }

  c4_c_varargin_2 = c4_b_varargin_2;
  if (c4_c_varargin_2 <= 0.0) {
    c4_n = 0.0;
  } else {
    c4_n = c4_c_varargin_2;
  }

  if (!(c4_n <= 2.147483647E+9)) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(&c4_st, &c4_i_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
  }

  c4_array_boolean_T_2D_Constructor(chartInstance, &c4_tile);
  c4_st.site = &c4_bh_emlrtRSI;
  c4_array_boolean_T_2D_SetSize(chartInstance, &c4_st, &c4_tile,
    &c4_qc_emlrtRTEI, 1, (int32_T)c4_varargin_2);
  c4_loop_ub = (int32_T)c4_varargin_2 - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_tile.vector.data[c4_i] = false;
  }

  c4_outsize[0] = 1;
  c4_outsize[1] = c4_tile.size[1];
  if (c4_outsize[1] != c4_tile.size[1]) {
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv3, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c4_sp, &c4_g_emlrtMCI, "error", 0U, 1U, 14, c4_g_y);
  }

  c4_array_cell_wrap_34_2D_Construct(chartInstance, &c4_r);
  c4_st.site = &c4_ph_emlrtRSI;
  c4_array_cell_wrap_34_2D_SetSize(chartInstance, &c4_st, &c4_r,
    &c4_se_emlrtRTEI, c4_outsize[0], c4_outsize[1]);
  c4_st.site = &c4_ph_emlrtRSI;
  c4_array_cell_wrap_34_2D_SetSize(chartInstance, &c4_st, c4_b, &c4_te_emlrtRTEI,
    1, c4_r.size[1]);
  c4_array_cell_wrap_34_2D_Destructo(chartInstance, &c4_r);
  if (c4_outsize[1] == 0) {
    c4_c_p = true;
  } else {
    c4_c_p = false;
  }

  if (!c4_c_p) {
    c4_ntilecols = c4_tile.size[1];
    c4_st.site = &c4_rd_emlrtRSI;
    c4_d_b = c4_ntilecols;
    c4_e_b = c4_d_b;
    if (c4_e_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_e_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_jtilecol = 0; c4_jtilecol < c4_ntilecols; c4_jtilecol++) {
      c4_b_jtilecol = c4_jtilecol;
      c4_ibtile = c4_b_jtilecol;
      c4_array_real_T_SetSize(chartInstance, c4_sp, &c4_b->vector.data
        [c4_b->size[0] * c4_ibtile].f1, &c4_ue_emlrtRTEI, c4_a[0].f1.size[0]);
      c4_b_loop_ub = c4_a[0].f1.size[0] - 1;
      for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
        c4_b->vector.data[c4_ibtile].f1.vector.data[c4_i1] = c4_a[0].
          f1.vector.data[c4_i1];
      }
    }
  }

  c4_array_boolean_T_2D_Destructor(chartInstance, &c4_tile);
}

static void c4_assertValidSizeArg(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_varargin_1)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_arg;
  real_T c4_b_arg;
  real_T c4_b_varargin_1;
  real_T c4_b_x;
  real_T c4_n;
  int32_T c4_b_u;
  int32_T c4_u;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_p;
  (void)chartInstance;
  c4_arg = c4_varargin_1;
  if (c4_arg != c4_arg) {
    c4_p = false;
  } else {
    c4_b_x = c4_arg;
    c4_b = muDoubleScalarIsInf(c4_b_x);
    if (c4_b) {
      c4_p = false;
    } else {
      c4_p = true;
    }
  }

  if (c4_p) {
    c4_b_arg = c4_varargin_1;
    if (c4_b_arg > 2.147483647E+9) {
      c4_b_p = false;
    } else {
      c4_b_p = true;
    }

    if (c4_b_p) {
      c4_b_b = true;
    } else {
      c4_b_b = false;
    }
  } else {
    c4_b_b = false;
  }

  if (!c4_b_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c4_u = MIN_int32_T;
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_u, 6, 0U, 0, 0U, 0), false);
    c4_b_u = MAX_int32_T;
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_b_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(c4_sp, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 3U, 14, c4_b_y, 14, c4_c_y, 14, c4_f_y)));
  }

  c4_b_varargin_1 = c4_varargin_1;
  if (c4_b_varargin_1 <= 0.0) {
    c4_n = 0.0;
  } else {
    c4_n = c4_b_varargin_1;
  }

  if (!(c4_n <= 2.147483647E+9)) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c4_sp, &c4_i_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_e_y)));
  }
}

static void c4_ind2sub(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_ndx, c4_coder_array_int32_T
  *c4_varargout_1, c4_coder_array_int32_T *c4_varargout_2)
{
  c4_coder_array_int32_T c4_vk;
  emlrtStack c4_st;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_loop_ub;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_eh_emlrtRSI;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_varargout_1,
    &c4_ve_emlrtRTEI, c4_ndx->size[0]);
  c4_loop_ub = c4_ndx->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_varargout_1->vector.data[c4_i] = (int32_T)c4_ndx->vector.data[c4_i];
  }

  c4_b_loop_ub = c4_varargout_1->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
    c4_varargout_1->vector.data[c4_i1]--;
  }

  c4_array_int32_T_Constructor(chartInstance, &c4_vk);
  c4_array_int32_T_SetSize(chartInstance, c4_sp, &c4_vk, &c4_we_emlrtRTEI,
    c4_varargout_1->size[0]);
  c4_c_loop_ub = c4_varargout_1->size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_c_loop_ub; c4_i2++) {
    c4_vk.vector.data[c4_i2] = c4_div_nzp_s32(chartInstance,
      c4_varargout_1->vector.data[c4_i2], 120, 0, 0U, 0, 0);
  }

  c4_st.site = &c4_dh_emlrtRSI;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_varargout_2,
    &c4_xe_emlrtRTEI, c4_vk.size[0]);
  c4_d_loop_ub = c4_vk.size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_d_loop_ub; c4_i3++) {
    c4_varargout_2->vector.data[c4_i3] = c4_vk.vector.data[c4_i3] + 1;
  }

  c4_e_loop_ub = c4_vk.size[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_e_loop_ub; c4_i4++) {
    c4_vk.vector.data[c4_i4] *= 120;
  }

  c4_f_loop_ub = c4_varargout_1->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_f_loop_ub; c4_i5++) {
    c4_varargout_1->vector.data[c4_i5] -= c4_vk.vector.data[c4_i5];
  }

  c4_array_int32_T_Destructor(chartInstance, &c4_vk);
  c4_g_loop_ub = c4_varargout_1->size[0] - 1;
  for (c4_i6 = 0; c4_i6 <= c4_g_loop_ub; c4_i6++) {
    c4_varargout_1->vector.data[c4_i6]++;
  }
}

static real_T c4_sum(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_b_s;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b_vlen;
  int32_T c4_c_vlen;
  int32_T c4_d_vlen;
  int32_T c4_ib;
  int32_T c4_inb;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vlen;
  boolean_T c4_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_st.site = &c4_ad_emlrtRSI;
  if ((c4_b_x->size[0] == 1) || (c4_b_x->size[0] != 1)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c4_st, &c4_l_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_b_st.site = &c4_bd_emlrtRSI;
  c4_vlen = c4_b_x->size[0];
  c4_c_st.site = &c4_cd_emlrtRSI;
  c4_b_vlen = c4_vlen;
  if ((c4_b_x->size[0] == 0) || (c4_b_vlen == 0)) {
    c4_y = 0.0;
  } else {
    c4_d_st.site = &c4_dd_emlrtRSI;
    c4_c_vlen = c4_b_vlen;
    c4_e_st.site = &c4_ed_emlrtRSI;
    c4_d_vlen = c4_c_vlen;
    if (c4_d_vlen < 4096) {
      c4_f_st.site = &c4_fd_emlrtRSI;
      c4_y = c4_c_sumColumnB(chartInstance, &c4_f_st, c4_b_x, c4_d_vlen);
    } else {
      c4_a = c4_d_vlen;
      c4_nfb = (int32_T)((uint32_T)c4_a >> 12);
      c4_inb = c4_nfb << 12;
      c4_lidx = c4_inb;
      c4_nleft = c4_d_vlen - c4_inb;
      c4_b_s = c4_b_sumColumnB4(chartInstance, c4_b_x, 1);
      for (c4_ib = 2; c4_ib <= c4_nfb; c4_ib++) {
        c4_b_s += c4_b_sumColumnB4(chartInstance, c4_b_x, 1 + ((c4_ib - 1) << 12));
      }

      if (c4_nleft > 0) {
        c4_f_st.site = &c4_gd_emlrtRSI;
        c4_b_s += c4_d_sumColumnB(chartInstance, &c4_f_st, c4_b_x, c4_nleft,
          c4_lidx + 1);
      }

      c4_y = c4_b_s;
    }
  }

  return c4_y;
}

static real_T c4_c_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x,
  int32_T c4_vlen)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_vlen;
  int32_T c4_b_vstart;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  int32_T c4_vstart;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_hd_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_y = c4_b_x->vector.data[0];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_jd_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    c4_i1 = (uint16_T)c4_i;
    for (c4_f_k = 0; c4_f_k < c4_i1; c4_f_k++) {
      c4_g_k = c4_f_k;
      c4_y += c4_b_x->vector.data[c4_g_k + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = (int32_T)((uint32_T)c4_a >> 10);
    c4_inb = c4_nfb << 10;
    c4_y = c4_b_x->vector.data[0];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_c_k = c4_k;
      c4_y += c4_b_x->vector.data[c4_c_k + 1];
    }

    for (c4_b_k = 2; c4_b_k <= c4_nfb; c4_b_k++) {
      c4_vstart = (c4_b_k - 1) << 10;
      c4_b_y = c4_b_x->vector.data[c4_vstart];
      for (c4_d_k = 0; c4_d_k < 1023; c4_d_k++) {
        c4_e_k = c4_d_k;
        c4_b_y += c4_b_x->vector.data[(c4_vstart + c4_e_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_inb;
      c4_st.site = &c4_id_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_b_vstart = c4_lidx;
      c4_c_y = c4_b_x->vector.data[c4_b_vstart];
      c4_i2 = c4_c_vlen;
      c4_b_st.site = &c4_jd_emlrtRSI;
      c4_c_b = c4_i2;
      c4_d_b = c4_c_b;
      if (c4_d_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_d_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_h_k = 0; c4_h_k < c4_i2; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += c4_b_x->vector.data[(c4_b_vstart + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static real_T c4_b_sumColumnB4(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_b_x, int32_T c4_vstart)
{
  real_T c4_psum1;
  real_T c4_psum2;
  real_T c4_psum3;
  real_T c4_psum4;
  int32_T c4_b_k;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  (void)chartInstance;
  c4_i2 = c4_vstart + 1023;
  c4_i3 = c4_vstart + 2047;
  c4_i4 = c4_vstart + 3071;
  c4_psum1 = c4_b_x->vector.data[c4_vstart - 1];
  c4_psum2 = c4_b_x->vector.data[c4_i2];
  c4_psum3 = c4_b_x->vector.data[c4_i3];
  c4_psum4 = c4_b_x->vector.data[c4_i4];
  for (c4_k = 0; c4_k < 1023; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_psum1 += c4_b_x->vector.data[(c4_vstart + c4_b_k) - 1];
    c4_psum2 += c4_b_x->vector.data[c4_i2 + c4_b_k];
    c4_psum3 += c4_b_x->vector.data[c4_i3 + c4_b_k];
    c4_psum4 += c4_b_x->vector.data[c4_i4 + c4_b_k];
  }

  return (c4_psum1 + c4_psum2) + (c4_psum3 + c4_psum4);
}

static real_T c4_d_sumColumnB(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x,
  int32_T c4_vlen, int32_T c4_vstart)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_y;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_vlen;
  int32_T c4_b_vstart;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_c_vlen;
  int32_T c4_c_vstart;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_d_vstart;
  int32_T c4_e_k;
  int32_T c4_e_vstart;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i_k;
  int32_T c4_inb;
  int32_T c4_k;
  int32_T c4_lidx;
  int32_T c4_nfb;
  int32_T c4_nleft;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (c4_vlen <= 1024) {
    c4_st.site = &c4_hd_emlrtRSI;
    c4_b_vlen = c4_vlen - 1;
    c4_b_vstart = c4_vstart - 1;
    c4_y = c4_b_x->vector.data[c4_b_vstart];
    c4_i = c4_b_vlen;
    c4_b_st.site = &c4_jd_emlrtRSI;
    c4_b = c4_i;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_f_k = 0; c4_f_k < c4_i; c4_f_k++) {
      c4_g_k = c4_f_k;
      c4_y += c4_b_x->vector.data[(c4_b_vstart + c4_g_k) + 1];
    }
  } else {
    c4_a = c4_vlen;
    c4_nfb = (int32_T)((uint32_T)c4_a >> 10);
    c4_inb = c4_nfb << 10;
    c4_c_vstart = c4_vstart - 1;
    c4_y = c4_b_x->vector.data[c4_c_vstart];
    for (c4_k = 0; c4_k < 1023; c4_k++) {
      c4_c_k = c4_k;
      c4_y += c4_b_x->vector.data[(c4_c_vstart + c4_c_k) + 1];
    }

    for (c4_b_k = 2; c4_b_k <= c4_nfb; c4_b_k++) {
      c4_d_vstart = (c4_vstart + ((c4_b_k - 1) << 10)) - 1;
      c4_b_y = c4_b_x->vector.data[c4_d_vstart];
      for (c4_d_k = 0; c4_d_k < 1023; c4_d_k++) {
        c4_e_k = c4_d_k;
        c4_b_y += c4_b_x->vector.data[(c4_d_vstart + c4_e_k) + 1];
      }

      c4_y += c4_b_y;
    }

    if (c4_vlen > c4_inb) {
      c4_nleft = c4_vlen - c4_inb;
      c4_lidx = c4_vstart + c4_inb;
      c4_st.site = &c4_id_emlrtRSI;
      c4_c_vlen = c4_nleft - 1;
      c4_e_vstart = c4_lidx - 1;
      c4_c_y = c4_b_x->vector.data[c4_e_vstart];
      c4_i1 = c4_c_vlen;
      c4_b_st.site = &c4_jd_emlrtRSI;
      c4_c_b = c4_i1;
      c4_d_b = c4_c_b;
      if (c4_d_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_d_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_h_k = 0; c4_h_k < c4_i1; c4_h_k++) {
        c4_i_k = c4_h_k;
        c4_c_y += c4_b_x->vector.data[(c4_e_vstart + c4_i_k) + 1];
      }

      c4_y += c4_c_y;
    }
  }

  return c4_y;
}

static void c4_round(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_coder_array_real_T *c4_b_x,
                     c4_coder_array_real_T *c4_y)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_c_x;
  real_T c4_d_x;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_i;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_nx;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_le_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_array_real_T_SetSize(chartInstance, &c4_st, c4_y, &c4_ye_emlrtRTEI,
    c4_b_x->size[0]);
  c4_loop_ub = c4_b_x->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_y->vector.data[c4_i] = c4_b_x->vector.data[c4_i];
  }

  c4_nx = c4_y->size[0];
  c4_b_st.site = &c4_me_emlrtRSI;
  c4_b = c4_nx;
  c4_b_b = c4_b;
  if (c4_b_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_jb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  for (c4_k = 0; c4_k < c4_nx; c4_k++) {
    c4_b_k = c4_k;
    c4_c_x = c4_y->vector.data[c4_b_k];
    c4_d_x = c4_c_x;
    c4_d_x = muDoubleScalarRound(c4_d_x);
    c4_y->vector.data[c4_b_k] = c4_d_x;
  }
}

static void c4_sort(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, c4_coder_array_real_T_2D *c4_b_x,
                    c4_coder_array_real_T_2D *c4_c_x, c4_coder_array_int32_T_2D *
                    c4_idx)
{
  int32_T c4_i;
  int32_T c4_loop_ub;
  c4_array_real_T_2D_SetSize(chartInstance, c4_sp, c4_c_x, &c4_af_emlrtRTEI,
    c4_b_x->size[0], 1);
  c4_loop_ub = c4_b_x->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_c_x->vector.data[c4_i] = c4_b_x->vector.data[c4_i];
  }

  c4_b_sort(chartInstance, c4_sp, c4_c_x, c4_idx);
}

static void c4_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, c4_coder_array_int32_T_2D
  *c4_b_idx, c4_coder_array_real_T_2D *c4_c_x)
{
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_array_int32_T_2D_SetSize(chartInstance, c4_sp, c4_b_idx, &c4_bf_emlrtRTEI,
    c4_idx->size[0], 1);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_idx->vector.data[c4_i] = c4_idx->vector.data[c4_i];
  }

  c4_array_real_T_2D_SetSize(chartInstance, c4_sp, c4_c_x, &c4_bf_emlrtRTEI,
    c4_b_x->size[0], 1);
  c4_b_loop_ub = c4_b_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
    c4_c_x->vector.data[c4_i1] = c4_b_x->vector.data[c4_i1];
  }

  c4_b_merge_pow2_block(chartInstance, c4_sp, c4_b_idx, c4_c_x, c4_offset);
}

static void c4_merge_block(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_coder_array_int32_T *c4_iwork, c4_coder_array_real_T
  *c4_xwork, c4_coder_array_int32_T_2D *c4_b_idx, c4_coder_array_real_T_2D
  *c4_c_x, c4_coder_array_int32_T *c4_b_iwork, c4_coder_array_real_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_array_int32_T_2D_SetSize(chartInstance, c4_sp, c4_b_idx, &c4_cf_emlrtRTEI,
    c4_idx->size[0], 1);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_idx->vector.data[c4_i] = c4_idx->vector.data[c4_i];
  }

  c4_array_real_T_2D_SetSize(chartInstance, c4_sp, c4_c_x, &c4_cf_emlrtRTEI,
    c4_b_x->size[0], 1);
  c4_b_loop_ub = c4_b_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
    c4_c_x->vector.data[c4_i1] = c4_b_x->vector.data[c4_i1];
  }

  c4_array_int32_T_SetSize(chartInstance, c4_sp, c4_b_iwork, &c4_cf_emlrtRTEI,
    c4_iwork->size[0]);
  c4_c_loop_ub = c4_iwork->size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_c_loop_ub; c4_i2++) {
    c4_b_iwork->vector.data[c4_i2] = c4_iwork->vector.data[c4_i2];
  }

  c4_array_real_T_SetSize(chartInstance, c4_sp, c4_b_xwork, &c4_cf_emlrtRTEI,
    c4_xwork->size[0]);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_d_loop_ub; c4_i3++) {
    c4_b_xwork->vector.data[c4_i3] = c4_xwork->vector.data[c4_i3];
  }

  c4_b_merge_block(chartInstance, c4_sp, c4_b_idx, c4_c_x, c4_offset, c4_n,
                   c4_preSortLevel, c4_b_iwork, c4_b_xwork);
}

static void c4_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
                     c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset,
                     int32_T c4_np, int32_T c4_nq, c4_coder_array_int32_T
                     *c4_iwork, c4_coder_array_real_T *c4_xwork,
                     c4_coder_array_int32_T_2D *c4_b_idx,
                     c4_coder_array_real_T_2D *c4_c_x, c4_coder_array_int32_T
                     *c4_b_iwork, c4_coder_array_real_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_array_int32_T_2D_SetSize(chartInstance, c4_sp, c4_b_idx, &c4_df_emlrtRTEI,
    c4_idx->size[0], 1);
  c4_loop_ub = c4_idx->size[0] - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_b_idx->vector.data[c4_i] = c4_idx->vector.data[c4_i];
  }

  c4_array_real_T_2D_SetSize(chartInstance, c4_sp, c4_c_x, &c4_df_emlrtRTEI,
    c4_b_x->size[0], 1);
  c4_b_loop_ub = c4_b_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_b_loop_ub; c4_i1++) {
    c4_c_x->vector.data[c4_i1] = c4_b_x->vector.data[c4_i1];
  }

  c4_array_int32_T_SetSize(chartInstance, c4_sp, c4_b_iwork, &c4_df_emlrtRTEI,
    c4_iwork->size[0]);
  c4_c_loop_ub = c4_iwork->size[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_c_loop_ub; c4_i2++) {
    c4_b_iwork->vector.data[c4_i2] = c4_iwork->vector.data[c4_i2];
  }

  c4_array_real_T_SetSize(chartInstance, c4_sp, c4_b_xwork, &c4_df_emlrtRTEI,
    c4_xwork->size[0]);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_d_loop_ub; c4_i3++) {
    c4_b_xwork->vector.data[c4_i3] = c4_xwork->vector.data[c4_i3];
  }

  c4_b_merge(chartInstance, c4_sp, c4_b_idx, c4_c_x, c4_offset, c4_np, c4_nq,
             c4_b_iwork, c4_b_xwork);
}

static boolean_T c4_all(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_boolean_T *c4_b_x)
{
  static char_T c4_b_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_a;
  real_T c4_vlen;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_d_b;
  int32_T c4_i2;
  int32_T c4_ix;
  int32_T c4_vspread;
  boolean_T c4_b;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_y;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_st.site = &c4_ag_emlrtRSI;
  if ((c4_b_x->size[0] == 1) || (c4_b_x->size[0] != 1)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c4_st, &c4_t_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_y = true;
  c4_vlen = (real_T)c4_b_x->size[0];
  c4_a = c4_vlen;
  c4_c = (int32_T)c4_a;
  c4_b_a = c4_c - 1;
  c4_vspread = c4_b_a;
  c4_b_b = c4_vspread;
  c4_i2 = c4_b_b;
  c4_c_a = c4_i2 + 1;
  c4_i2 = c4_c_a;
  c4_b_st.site = &c4_bg_emlrtRSI;
  c4_c_b = c4_i2;
  c4_d_b = c4_c_b;
  if (c4_d_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_d_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_jb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  c4_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_ix + 1 <= c4_i2)) {
    if (!c4_b_x->vector.data[c4_ix]) {
      c4_y = false;
      c4_exitg1 = true;
    } else {
      c4_ix++;
    }
  }

  return c4_y;
}

const mxArray *sf_c4_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId);
  sf_mex_destroy(&c4_nullptr);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_d;
  real_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_coder_array_real_T_2D *c4_b_x,
                      c4_coder_array_int32_T_2D *c4_idx)
{
  c4_coder_array_int32_T c4_iwork;
  c4_coder_array_real_T c4_xwork;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  real_T c4_x4[4];
  real_T c4_dv[2];
  real_T c4_c_x;
  int32_T c4_idx4[4];
  int32_T c4_perm[4];
  int32_T c4_b_b;
  int32_T c4_b_i1;
  int32_T c4_b_i2;
  int32_T c4_b_i3;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_b_nNaNs;
  int32_T c4_b_nNonNaN;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_c_n;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i_b;
  int32_T c4_i_k;
  int32_T c4_ib;
  int32_T c4_itmp;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_m_b;
  int32_T c4_n;
  int32_T c4_nBlocks;
  int32_T c4_nLastBlock;
  int32_T c4_nNaNs;
  int32_T c4_nNonNaN;
  int32_T c4_n_b;
  int32_T c4_o_b;
  int32_T c4_p_b;
  int32_T c4_preSortLevel;
  int32_T c4_quartetOffset;
  int32_T c4_tailOffset;
  int32_T c4_wOffset;
  boolean_T c4_b;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_d_b;
  boolean_T c4_d_overflow;
  boolean_T c4_e_overflow;
  boolean_T c4_f_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_oe_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_dv[c4_i] = (real_T)c4_b_x->size[c4_i];
  }

  c4_array_int32_T_2D_SetSize(chartInstance, &c4_st, c4_idx, &c4_ef_emlrtRTEI,
    (int32_T)c4_dv[0], 1);
  c4_loop_ub = (int32_T)c4_dv[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_idx->vector.data[c4_i1] = 0;
  }

  c4_b = (c4_b_x->size[0] == 0);
  if (!c4_b) {
    c4_b_st.site = &c4_pe_emlrtRSI;
    c4_array_int32_T_Constructor(chartInstance, &c4_iwork);
    c4_array_real_T_Constructor(chartInstance, &c4_xwork);
    for (c4_k = 0; c4_k < 1; c4_k++) {
      c4_b_st.site = &c4_qe_emlrtRSI;
      c4_n = c4_b_x->size[0];
      c4_array_int32_T_SetSize(chartInstance, &c4_b_st, &c4_iwork,
        &c4_ff_emlrtRTEI, c4_idx->size[0]);
      c4_b_loop_ub = c4_idx->size[0] - 1;
      for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
        c4_iwork.vector.data[c4_i2] = 0;
      }

      c4_dv[0] = (real_T)c4_b_x->size[0];
      c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_xwork,
        &c4_gf_emlrtRTEI, (int32_T)c4_dv[0]);
      c4_c_st.site = &c4_re_emlrtRSI;
      c4_b_n = c4_b_x->size[0];
      memset(&c4_x4[0], 0, sizeof(real_T) << 2);
      memset(&c4_idx4[0], 0, sizeof(int32_T) << 2);
      c4_nNaNs = 0;
      c4_ib = 0;
      c4_d_st.site = &c4_xe_emlrtRSI;
      c4_b_b = c4_b_n;
      c4_c_b = c4_b_b;
      if (c4_c_b < 1) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_c_b > 2147483646);
      }

      if (c4_overflow) {
        c4_e_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      for (c4_b_k = 0; c4_b_k < c4_b_n; c4_b_k++) {
        c4_c_k = c4_b_k;
        c4_c_x = c4_b_x->vector.data[c4_c_k];
        c4_d_b = muDoubleScalarIsNaN(c4_c_x);
        if (c4_d_b) {
          c4_idx->vector.data[(c4_b_n - c4_nNaNs) - 1] = c4_c_k + 1;
          c4_xwork.vector.data[(c4_b_n - c4_nNaNs) - 1] = c4_b_x->
            vector.data[c4_c_k];
          c4_nNaNs++;
        } else {
          c4_ib++;
          c4_idx4[c4_ib - 1] = c4_c_k + 1;
          c4_x4[c4_ib - 1] = c4_b_x->vector.data[c4_c_k];
          if (c4_ib == 4) {
            c4_quartetOffset = c4_c_k - c4_nNaNs;
            if (c4_x4[0] >= c4_x4[1]) {
              c4_b_i1 = 1;
              c4_b_i2 = 2;
            } else {
              c4_b_i1 = 2;
              c4_b_i2 = 1;
            }

            if (c4_x4[2] >= c4_x4[3]) {
              c4_i3 = 3;
              c4_i4 = 4;
            } else {
              c4_i3 = 4;
              c4_i4 = 3;
            }

            if (c4_x4[c4_b_i1 - 1] >= c4_x4[c4_i3 - 1]) {
              if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_i3 - 1]) {
                c4_perm[0] = c4_b_i1;
                c4_perm[1] = c4_b_i2;
                c4_perm[2] = c4_i3;
                c4_perm[3] = c4_i4;
              } else if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_i4 - 1]) {
                c4_perm[0] = c4_b_i1;
                c4_perm[1] = c4_i3;
                c4_perm[2] = c4_b_i2;
                c4_perm[3] = c4_i4;
              } else {
                c4_perm[0] = c4_b_i1;
                c4_perm[1] = c4_i3;
                c4_perm[2] = c4_i4;
                c4_perm[3] = c4_b_i2;
              }
            } else if (c4_x4[c4_b_i1 - 1] >= c4_x4[c4_i4 - 1]) {
              if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_i4 - 1]) {
                c4_perm[0] = c4_i3;
                c4_perm[1] = c4_b_i1;
                c4_perm[2] = c4_b_i2;
                c4_perm[3] = c4_i4;
              } else {
                c4_perm[0] = c4_i3;
                c4_perm[1] = c4_b_i1;
                c4_perm[2] = c4_i4;
                c4_perm[3] = c4_b_i2;
              }
            } else {
              c4_perm[0] = c4_i3;
              c4_perm[1] = c4_i4;
              c4_perm[2] = c4_b_i1;
              c4_perm[3] = c4_b_i2;
            }

            c4_idx->vector.data[c4_quartetOffset - 3] = c4_idx4[c4_perm[0] - 1];
            c4_idx->vector.data[c4_quartetOffset - 2] = c4_idx4[c4_perm[1] - 1];
            c4_idx->vector.data[c4_quartetOffset - 1] = c4_idx4[c4_perm[2] - 1];
            c4_idx->vector.data[c4_quartetOffset] = c4_idx4[c4_perm[3] - 1];
            c4_b_x->vector.data[c4_quartetOffset - 3] = c4_x4[c4_perm[0] - 1];
            c4_b_x->vector.data[c4_quartetOffset - 2] = c4_x4[c4_perm[1] - 1];
            c4_b_x->vector.data[c4_quartetOffset - 1] = c4_x4[c4_perm[2] - 1];
            c4_b_x->vector.data[c4_quartetOffset] = c4_x4[c4_perm[3] - 1];
            c4_ib = 0;
          }
        }
      }

      c4_wOffset = (c4_b_n - c4_nNaNs) - 1;
      if (c4_ib > 0) {
        c4_c_n = c4_ib;
        memset(&c4_perm[0], 0, sizeof(int32_T) << 2);
        if (c4_c_n == 1) {
          c4_perm[0] = 1;
        } else if (c4_c_n == 2) {
          if (c4_x4[0] >= c4_x4[1]) {
            c4_perm[0] = 1;
            c4_perm[1] = 2;
          } else {
            c4_perm[0] = 2;
            c4_perm[1] = 1;
          }
        } else if (c4_x4[0] >= c4_x4[1]) {
          if (c4_x4[1] >= c4_x4[2]) {
            c4_perm[0] = 1;
            c4_perm[1] = 2;
            c4_perm[2] = 3;
          } else if (c4_x4[0] >= c4_x4[2]) {
            c4_perm[0] = 1;
            c4_perm[1] = 3;
            c4_perm[2] = 2;
          } else {
            c4_perm[0] = 3;
            c4_perm[1] = 1;
            c4_perm[2] = 2;
          }
        } else if (c4_x4[0] >= c4_x4[2]) {
          c4_perm[0] = 2;
          c4_perm[1] = 1;
          c4_perm[2] = 3;
        } else if (c4_x4[1] >= c4_x4[2]) {
          c4_perm[0] = 2;
          c4_perm[1] = 3;
          c4_perm[2] = 1;
        } else {
          c4_perm[0] = 3;
          c4_perm[1] = 2;
          c4_perm[2] = 1;
        }

        c4_d_st.site = &c4_ye_emlrtRSI;
        c4_g_b = c4_ib;
        c4_h_b = c4_g_b;
        if (c4_h_b < 1) {
          c4_c_overflow = false;
        } else {
          c4_c_overflow = (c4_h_b > 2147483646);
        }

        if (c4_c_overflow) {
          c4_e_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        c4_b_i3 = (uint8_T)c4_ib;
        for (c4_e_k = 0; c4_e_k < c4_b_i3; c4_e_k++) {
          c4_c_k = c4_e_k;
          c4_idx->vector.data[((c4_wOffset - c4_ib) + c4_c_k) + 1] =
            c4_idx4[c4_perm[c4_c_k] - 1];
          c4_b_x->vector.data[((c4_wOffset - c4_ib) + c4_c_k) + 1] =
            c4_x4[c4_perm[c4_c_k] - 1];
        }
      }

      c4_m = c4_nNaNs >> 1;
      c4_d_st.site = &c4_af_emlrtRSI;
      c4_e_b = c4_m;
      c4_f_b = c4_e_b;
      if (c4_f_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_f_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_e_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      for (c4_d_k = 0; c4_d_k < c4_m; c4_d_k++) {
        c4_c_k = c4_d_k + 1;
        c4_itmp = c4_idx->vector.data[c4_wOffset + c4_c_k];
        c4_idx->vector.data[c4_wOffset + c4_c_k] = c4_idx->vector.data[c4_b_n -
          c4_c_k];
        c4_idx->vector.data[c4_b_n - c4_c_k] = c4_itmp;
        c4_b_x->vector.data[c4_wOffset + c4_c_k] = c4_xwork.vector.data[c4_b_n -
          c4_c_k];
        c4_b_x->vector.data[c4_b_n - c4_c_k] = c4_xwork.vector.data[c4_wOffset +
          c4_c_k];
      }

      if ((c4_nNaNs & 1) != 0) {
        c4_b_x->vector.data[(c4_wOffset + c4_m) + 1] = c4_xwork.vector.data
          [(c4_wOffset + c4_m) + 1];
      }

      c4_nNonNaN = c4_n - c4_nNaNs;
      c4_preSortLevel = 2;
      if (c4_nNonNaN > 1) {
        if (c4_n >= 256) {
          c4_nBlocks = c4_nNonNaN >> 8;
          if (c4_nBlocks > 0) {
            c4_c_st.site = &c4_se_emlrtRSI;
            c4_i_b = c4_nBlocks;
            c4_j_b = c4_i_b;
            if (c4_j_b < 1) {
              c4_d_overflow = false;
            } else {
              c4_d_overflow = (c4_j_b > 2147483646);
            }

            if (c4_d_overflow) {
              c4_d_st.site = &c4_jb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
            }

            for (c4_m_b = 0; c4_m_b < c4_nBlocks; c4_m_b++) {
              c4_n_b = c4_m_b;
              c4_c_st.site = &c4_te_emlrtRSI;
              c4_b_merge_pow2_block(chartInstance, &c4_c_st, c4_idx, c4_b_x,
                                    c4_n_b << 8);
            }

            c4_tailOffset = c4_nBlocks << 8;
            c4_nLastBlock = c4_nNonNaN - c4_tailOffset;
            if (c4_nLastBlock > 0) {
              c4_c_st.site = &c4_ue_emlrtRSI;
              c4_b_merge_block(chartInstance, &c4_c_st, c4_idx, c4_b_x,
                               c4_tailOffset, c4_nLastBlock, 2, &c4_iwork,
                               &c4_xwork);
            }

            c4_preSortLevel = 8;
          }
        }

        c4_c_st.site = &c4_ve_emlrtRSI;
        c4_b_merge_block(chartInstance, &c4_c_st, c4_idx, c4_b_x, 0, c4_nNonNaN,
                         c4_preSortLevel, &c4_iwork, &c4_xwork);
      }

      if ((c4_nNaNs > 0) && (c4_nNonNaN > 0)) {
        c4_c_st.site = &c4_we_emlrtRSI;
        c4_b_nNonNaN = c4_nNonNaN - 1;
        c4_b_nNaNs = c4_nNaNs - 1;
        c4_d_st.site = &c4_kf_emlrtRSI;
        c4_k_b = c4_b_nNaNs + 1;
        c4_l_b = c4_k_b;
        if (c4_l_b < 1) {
          c4_e_overflow = false;
        } else {
          c4_e_overflow = (c4_l_b > 2147483646);
        }

        if (c4_e_overflow) {
          c4_e_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_f_k = 0; c4_f_k <= c4_b_nNaNs; c4_f_k++) {
          c4_h_k = c4_f_k;
          c4_xwork.vector.data[c4_h_k] = c4_b_x->vector.data[(c4_b_nNonNaN +
            c4_h_k) + 1];
          c4_iwork.vector.data[c4_h_k] = c4_idx->vector.data[(c4_b_nNonNaN +
            c4_h_k) + 1];
        }

        for (c4_g_k = c4_b_nNonNaN + 1; c4_g_k >= 1; c4_g_k--) {
          c4_b_x->vector.data[c4_b_nNaNs + c4_g_k] = c4_b_x->vector.data[c4_g_k
            - 1];
          c4_idx->vector.data[c4_b_nNaNs + c4_g_k] = c4_idx->vector.data[c4_g_k
            - 1];
        }

        c4_d_st.site = &c4_lf_emlrtRSI;
        c4_o_b = c4_b_nNaNs + 1;
        c4_p_b = c4_o_b;
        if (c4_p_b < 1) {
          c4_f_overflow = false;
        } else {
          c4_f_overflow = (c4_p_b > 2147483646);
        }

        if (c4_f_overflow) {
          c4_e_st.site = &c4_jb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_i_k = 0; c4_i_k <= c4_b_nNaNs; c4_i_k++) {
          c4_h_k = c4_i_k;
          c4_b_x->vector.data[c4_h_k] = c4_xwork.vector.data[c4_h_k];
          c4_idx->vector.data[c4_h_k] = c4_iwork.vector.data[c4_h_k];
        }
      }
    }

    c4_array_real_T_Destructor(chartInstance, &c4_xwork);
    c4_array_int32_T_Destructor(chartInstance, &c4_iwork);
  }
}

static void c4_b_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_xwork[256];
  int32_T c4_iwork[256];
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_blockOffset;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_exitg1;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_nPairs;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_b = 0; c4_b < 6; c4_b++) {
    c4_bLen = 1 << (c4_b + 2);
    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = 256 >> (c4_b + 3);
    c4_st.site = &c4_bf_emlrtRSI;
    c4_b_b = c4_nPairs;
    c4_c_b = c4_b_b;
    if (c4_c_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    c4_i = (uint8_T)c4_nPairs;
    for (c4_k = 0; c4_k < c4_i; c4_k++) {
      c4_b_k = c4_k;
      c4_blockOffset = (c4_offset + c4_b_k * c4_bLen2) - 1;
      c4_st.site = &c4_cf_emlrtRSI;
      c4_d_b = c4_bLen2;
      c4_e_b = c4_d_b;
      if (c4_e_b < 1) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_b_st.site = &c4_jb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      c4_i1 = (uint16_T)c4_bLen2;
      for (c4_j = 0; c4_j < c4_i1; c4_j++) {
        c4_b_j = c4_j;
        c4_iwork[c4_b_j] = c4_idx->vector.data[(c4_blockOffset + c4_b_j) + 1];
        c4_xwork[c4_b_j] = c4_b_x->vector.data[(c4_blockOffset + c4_b_j) + 1];
      }

      c4_p = 0;
      c4_q = c4_bLen;
      c4_iout = c4_blockOffset;
      do {
        c4_exitg1 = 0;
        c4_iout++;
        if (c4_xwork[c4_p] >= c4_xwork[c4_q]) {
          c4_idx->vector.data[c4_iout] = c4_iwork[c4_p];
          c4_b_x->vector.data[c4_iout] = c4_xwork[c4_p];
          if (c4_p + 1 < c4_bLen) {
            c4_p++;
          } else {
            c4_exitg1 = 1;
          }
        } else {
          c4_idx->vector.data[c4_iout] = c4_iwork[c4_q];
          c4_b_x->vector.data[c4_iout] = c4_xwork[c4_q];
          if (c4_q + 1 < c4_bLen2) {
            c4_q++;
          } else {
            c4_offset1 = c4_iout - c4_p;
            c4_st.site = &c4_df_emlrtRSI;
            c4_a = c4_p + 1;
            c4_f_b = c4_bLen;
            c4_b_a = c4_a;
            c4_g_b = c4_f_b;
            if (c4_b_a > c4_g_b) {
              c4_c_overflow = false;
            } else {
              c4_c_overflow = (c4_g_b > 2147483646);
            }

            if (c4_c_overflow) {
              c4_b_st.site = &c4_jb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
            }

            for (c4_c_j = c4_p + 1; c4_c_j <= c4_bLen; c4_c_j++) {
              c4_idx->vector.data[c4_offset1 + c4_c_j] = c4_iwork[c4_c_j - 1];
              c4_b_x->vector.data[c4_offset1 + c4_c_j] = c4_xwork[c4_c_j - 1];
            }

            c4_exitg1 = 1;
          }
        }
      } while (c4_exitg1 == 0);
    }
  }
}

static void c4_b_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_coder_array_int32_T *c4_iwork, c4_coder_array_real_T
  *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_k;
  int32_T c4_nBlocks;
  int32_T c4_nPairs;
  int32_T c4_nTail;
  int32_T c4_tailOffset;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_nBlocks = c4_n >> c4_preSortLevel;
  c4_bLen = 1 << c4_preSortLevel;
  while (c4_nBlocks > 1) {
    if ((c4_nBlocks & 1) != 0) {
      c4_nBlocks--;
      c4_tailOffset = c4_bLen * c4_nBlocks;
      c4_nTail = c4_n - c4_tailOffset;
      if (c4_nTail > c4_bLen) {
        c4_st.site = &c4_ef_emlrtRSI;
        c4_b_merge(chartInstance, &c4_st, c4_idx, c4_b_x, c4_offset +
                   c4_tailOffset, c4_bLen, c4_nTail - c4_bLen, c4_iwork,
                   c4_xwork);
      }
    }

    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = c4_nBlocks >> 1;
    c4_st.site = &c4_ff_emlrtRSI;
    c4_b = c4_nPairs;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 0; c4_k < c4_nPairs; c4_k++) {
      c4_b_k = c4_k;
      c4_st.site = &c4_gf_emlrtRSI;
      c4_b_merge(chartInstance, &c4_st, c4_idx, c4_b_x, c4_offset + c4_b_k *
                 c4_bLen2, c4_bLen, c4_bLen, c4_iwork, c4_xwork);
    }

    c4_bLen = c4_bLen2;
    c4_nBlocks = c4_nPairs;
  }

  if (c4_n > c4_bLen) {
    c4_st.site = &c4_hf_emlrtRSI;
    c4_b_merge(chartInstance, &c4_st, c4_idx, c4_b_x, c4_offset, c4_bLen, c4_n -
               c4_bLen, c4_iwork, c4_xwork);
  }
}

static void c4_b_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_int32_T_2D *c4_idx,
  c4_coder_array_real_T_2D *c4_b_x, int32_T c4_offset, int32_T c4_np, int32_T
  c4_nq, c4_coder_array_int32_T *c4_iwork, c4_coder_array_real_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_a;
  int32_T c4_b;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_exitg1;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_n;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  int32_T c4_qend;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  if (c4_nq != 0) {
    c4_n = c4_np + c4_nq;
    c4_st.site = &c4_jf_emlrtRSI;
    c4_b = c4_n;
    c4_b_b = c4_b;
    if (c4_b_b < 1) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_jb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_j = 0; c4_j < c4_n; c4_j++) {
      c4_b_j = c4_j;
      c4_iwork->vector.data[c4_b_j] = c4_idx->vector.data[c4_offset + c4_b_j];
      c4_xwork->vector.data[c4_b_j] = c4_b_x->vector.data[c4_offset + c4_b_j];
    }

    c4_p = 0;
    c4_q = c4_np;
    c4_qend = c4_np + c4_nq;
    c4_iout = c4_offset - 1;
    do {
      c4_exitg1 = 0;
      c4_iout++;
      if (c4_xwork->vector.data[c4_p] >= c4_xwork->vector.data[c4_q]) {
        c4_idx->vector.data[c4_iout] = c4_iwork->vector.data[c4_p];
        c4_b_x->vector.data[c4_iout] = c4_xwork->vector.data[c4_p];
        if (c4_p + 1 < c4_np) {
          c4_p++;
        } else {
          c4_exitg1 = 1;
        }
      } else {
        c4_idx->vector.data[c4_iout] = c4_iwork->vector.data[c4_q];
        c4_b_x->vector.data[c4_iout] = c4_xwork->vector.data[c4_q];
        if (c4_q + 1 < c4_qend) {
          c4_q++;
        } else {
          c4_offset1 = c4_iout - c4_p;
          c4_st.site = &c4_if_emlrtRSI;
          c4_a = c4_p + 1;
          c4_c_b = c4_np;
          c4_b_a = c4_a;
          c4_d_b = c4_c_b;
          if (c4_b_a > c4_d_b) {
            c4_b_overflow = false;
          } else {
            c4_b_overflow = (c4_d_b > 2147483646);
          }

          if (c4_b_overflow) {
            c4_b_st.site = &c4_jb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
          }

          for (c4_c_j = c4_p + 1; c4_c_j <= c4_np; c4_c_j++) {
            c4_idx->vector.data[c4_offset1 + c4_c_j] = c4_iwork->
              vector.data[c4_c_j - 1];
            c4_b_x->vector.data[c4_offset1 + c4_c_j] = c4_xwork->
              vector.data[c4_c_j - 1];
          }

          c4_exitg1 = 1;
        }
      }
    } while (c4_exitg1 == 0);
  }
}

static real_T c4_binary_expand_op(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, emlrtRSInfo c4_in1,
  c4_coder_array_real_T *c4_in2, c4_coder_array_real_T *c4_in3)
{
  c4_coder_array_real_T c4_b_in2;
  emlrtStack c4_st;
  real_T c4_out1;
  int32_T c4_aux_0_0;
  int32_T c4_aux_1_0;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  int32_T c4_stride_0_0;
  int32_T c4_stride_1_0;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_array_real_T_Constructor(chartInstance, &c4_b_in2);
  if (c4_in3->size[0] == 1) {
    c4_i = c4_in2->size[0];
  } else {
    c4_i = c4_in3->size[0];
  }

  c4_array_real_T_SetSize(chartInstance, c4_sp, &c4_b_in2, &c4_sd_emlrtRTEI,
    c4_i);
  c4_stride_0_0 = (c4_in2->size[0] != 1);
  c4_stride_1_0 = (c4_in3->size[0] != 1);
  c4_aux_0_0 = 0;
  c4_aux_1_0 = 0;
  if (c4_in3->size[0] == 1) {
    c4_i1 = c4_in2->size[0];
  } else {
    c4_i1 = c4_in3->size[0];
  }

  c4_loop_ub = c4_i1 - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_b_in2.vector.data[c4_i2] = c4_in2->vector.data[c4_aux_0_0] *
      c4_in3->vector.data[c4_aux_1_0];
    c4_aux_1_0 += c4_stride_1_0;
    c4_aux_0_0 += c4_stride_0_0;
  }

  c4_st.site = &c4_in1;
  c4_out1 = c4_sum(chartInstance, &c4_st, &c4_b_in2);
  c4_array_real_T_Destructor(chartInstance, &c4_b_in2);
  return c4_out1;
}

static void c4_array_real_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1)
{
  real_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_creal_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_creal_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  creal_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (creal_T *)emlrtMallocMex(sizeof(creal_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(creal_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_boolean_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  boolean_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_int32_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  int32_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_real_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  real_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_boolean_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  boolean_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_real32_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_coder_array_real32_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  real32_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (real32_T *)emlrtMallocMex(sizeof(real32_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(real32_T)
             * (uint32_T)c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_creal_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_creal_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1)
{
  creal_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (creal_T *)emlrtMallocMex(sizeof(creal_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(creal_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_sOA5t73y81YtFHGIDxk0fKF_S
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_coder_array_sOA5t73y81YtFHGIDxk *c4_coderArray, const emlrtRTEInfo
   *c4_srcLocation, int32_T c4_size0)
{
  c4_sOA5t73y81YtFHGIDxk0fKF *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (c4_sOA5t73y81YtFHGIDxk0fKF *)emlrtMallocMex(sizeof
      (c4_sOA5t73y81YtFHGIDxk0fKF) * (uint32_T)c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof
             (c4_sOA5t73y81YtFHGIDxk0fKF) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_coder_array_s_R6Og1x0kmqQXSF9Pw *c4_coderArray, const emlrtRTEInfo
   *c4_srcLocation, int32_T c4_size0)
{
  c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_newData;
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel < c4_coderArray->vector.numel) {
    for (c4_i = c4_newNumel; c4_i < c4_coderArray->vector.numel; c4_i++) {
      c4_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
        &c4_coderArray->vector.data[c4_i]);
    }
  }

  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (c4_s_R6Og1x0kmqQXSF9Pwa49FD *)emlrtMallocMex(sizeof
      (c4_s_R6Og1x0kmqQXSF9Pwa49FD) * (uint32_T)c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof
             (c4_s_R6Og1x0kmqQXSF9Pwa49FD) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  for (c4_b_i = c4_coderArray->vector.numel; c4_b_i < c4_newNumel; c4_b_i++) {
    c4_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
      &c4_coderArray->vector.data[c4_b_i]);
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_real_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_pStruct)
{
  c4_array_real_T_Destructor(chartInstance, &c4_pStruct->PixelIdxList);
  c4_array_real_T_2D_Destructor(chartInstance, &c4_pStruct->PixelList);
  c4_array_real_T_Destructor(chartInstance, &c4_pStruct->PixelValues);
}

static void c4_array_real_T_2D_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T_2D *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_pStruct)
{
  c4_array_boolean_T_0x0_Constructor(chartInstance, &c4_pStruct->Image);
  c4_array_boolean_T_0x0_Constructor(chartInstance, &c4_pStruct->FilledImage);
  c4_array_real_T_Constructor(chartInstance, &c4_pStruct->PixelIdxList);
  c4_array_real_T_2D_Constructor(chartInstance, &c4_pStruct->PixelList);
  c4_array_real_T_Constructor(chartInstance, &c4_pStruct->PixelValues);
  c4_array_real_T_1x0_Constructor(chartInstance, &c4_pStruct->SubarrayIdx);
}

static void c4_array_boolean_T_0x0_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T_0x0 *c4_pArray)
{
  (void)chartInstance;
  c4_pArray->size[0] = 0;
  c4_pArray->size[1] = 0;
}

static void c4_array_real_T_Constructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (real_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_real_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real_T_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (real_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_array_real_T_1x0_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real_T_1x0 *c4_pArray)
{
  (void)chartInstance;
  c4_pArray->size[0] = 0;
  c4_pArray->size[1] = 0;
}

static void c4_array_cell_wrap_34_2D_SetSize
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_coder_array_cell_wrap_34_2D *c4_coderArray, const emlrtRTEInfo
   *c4_srcLocation, int32_T c4_size0, int32_T c4_size1)
{
  c4_cell_wrap_34 *c4_newData;
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel < c4_coderArray->vector.numel) {
    for (c4_i = c4_newNumel; c4_i < c4_coderArray->vector.numel; c4_i++) {
      c4_array_cell_wrap_34_Destructor(chartInstance,
        &c4_coderArray->vector.data[c4_i]);
    }
  }

  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (c4_cell_wrap_34 *)emlrtMallocMex(sizeof(c4_cell_wrap_34) *
      (uint32_T)c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(c4_cell_wrap_34) *
             (uint32_T)c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  for (c4_b_i = c4_coderArray->vector.numel; c4_b_i < c4_newNumel; c4_b_i++) {
    c4_array_cell_wrap_34_Constructor(chartInstance, &c4_coderArray->
      vector.data[c4_b_i]);
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_cell_wrap_34_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   *c4_pStruct)
{
  c4_array_real_T_Destructor(chartInstance, &c4_pStruct->f1);
}

static void c4_array_cell_wrap_34_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   *c4_pStruct)
{
  c4_array_real_T_Constructor(chartInstance, &c4_pStruct->f1);
}

static void c4_array_int32_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  int32_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_boolean_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (boolean_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_array_int32_T_Constructor(SFc4_flightControlSystemInstanceStruct *
  chartInstance, c4_coder_array_int32_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (int32_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_creal_T_Constructor(SFc4_flightControlSystemInstanceStruct *
  chartInstance, c4_coder_array_creal_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (creal_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_boolean_T_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (boolean_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_boolean_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T_2D *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_int32_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_creal_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_creal_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (creal_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_boolean_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_boolean_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_real32_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real32_T_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (real32_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_array_creal_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_creal_T_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (creal_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_array_real32_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real32_T_2D *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (real32_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_creal_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_creal_T_2D *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (creal_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_sOA5t73y81YtFHGIDxk0fKF_C
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_sOA5t73y81YtFHGIDxk *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (c4_sOA5t73y81YtFHGIDxk0fKF *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_int32_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_int32_T_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (int32_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_array_sOA5t73y81YtFHGIDxk0fKF_D
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_sOA5t73y81YtFHGIDxk *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data !=
       (c4_sOA5t73y81YtFHGIDxk0fKF *)NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_int32_T_2D_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_int32_T_2D *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_dst, const
   c4_s_R6Og1x0kmqQXSF9Pwa49FD *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_dst->Area = c4_src->Area;
  c4_array_real_T_1x2s_Copy(chartInstance, c4_dst->Centroid, c4_src->Centroid);
  c4_array_real_T_1x4s_Copy(chartInstance, c4_dst->BoundingBox,
    c4_src->BoundingBox);
  c4_dst->MajorAxisLength = c4_src->MajorAxisLength;
  c4_dst->MinorAxisLength = c4_src->MinorAxisLength;
  c4_dst->Eccentricity = c4_src->Eccentricity;
  c4_dst->Orientation = c4_src->Orientation;
  c4_array_boolean_T_0x0_Copy(chartInstance, c4_sp, &c4_dst->Image,
    &c4_src->Image, c4_srcLocation);
  c4_array_boolean_T_0x0_Copy(chartInstance, c4_sp, &c4_dst->FilledImage,
    &c4_src->FilledImage, c4_srcLocation);
  c4_dst->FilledArea = c4_src->FilledArea;
  c4_dst->EulerNumber = c4_src->EulerNumber;
  c4_array_real_T_8x2s_Copy(chartInstance, c4_dst->Extrema, c4_src->Extrema);
  c4_dst->EquivDiameter = c4_src->EquivDiameter;
  c4_dst->Extent = c4_src->Extent;
  c4_array_real_T_Copy(chartInstance, c4_sp, &c4_dst->PixelIdxList,
                       &c4_src->PixelIdxList, c4_srcLocation);
  c4_array_real_T_2D_Copy(chartInstance, c4_sp, &c4_dst->PixelList,
    &c4_src->PixelList, c4_srcLocation);
  c4_dst->Perimeter = c4_src->Perimeter;
  c4_dst->Circularity = c4_src->Circularity;
  c4_array_real_T_Copy(chartInstance, c4_sp, &c4_dst->PixelValues,
                       &c4_src->PixelValues, c4_srcLocation);
  c4_array_real_T_1x2s_Copy(chartInstance, c4_dst->WeightedCentroid,
    c4_src->WeightedCentroid);
  c4_dst->MeanIntensity = c4_src->MeanIntensity;
  c4_dst->MinIntensity = c4_src->MinIntensity;
  c4_dst->MaxIntensity = c4_src->MaxIntensity;
  c4_array_real_T_1x0_Copy(chartInstance, c4_sp, &c4_dst->SubarrayIdx,
    &c4_src->SubarrayIdx, c4_srcLocation);
  c4_array_real_T_1x2s_Copy(chartInstance, c4_dst->SubarrayIdxLengths,
    c4_src->SubarrayIdxLengths);
}

static void c4_array_real_T_1x2s_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[2], const real_T c4_src[2])
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_dst[c4_i] = c4_src[c4_i];
  }
}

static void c4_array_real_T_1x4s_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[4], const real_T c4_src[4])
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_dst[c4_i] = c4_src[c4_i];
  }
}

static void c4_array_boolean_T_0x0_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T_0x0 *c4_dst,
  const c4_coder_array_boolean_T_0x0 *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_array_boolean_T_0x0_SetSize(chartInstance, c4_sp, c4_dst->size,
    c4_srcLocation, c4_src->size[0], c4_src->size[1]);
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c4_src->size[0], c4_srcLocation, (void *)c4_sp), (size_t)
                     (uint32_T)c4_src->size[1], c4_srcLocation, (void *)c4_sp);
}

static void c4_array_boolean_T_0x0_SetSize
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, int32_T c4_size[2], const emlrtRTEInfo *c4_srcLocation, int32_T
   c4_size0, int32_T c4_size1)
{
  (void)chartInstance;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c4_size[0], c4_srcLocation, (void *)c4_sp), (size_t)
                     (uint32_T)c4_size[1], c4_srcLocation, (void *)c4_sp);
  c4_size[0] = c4_size0;
  c4_size[1] = c4_size1;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c4_size[0], c4_srcLocation, (void *)c4_sp), (size_t)
                     (uint32_T)c4_size[1], c4_srcLocation, (void *)c4_sp);
}

static void c4_array_real_T_8x2s_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[16], const real_T c4_src[16])
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 16; c4_i++) {
    c4_dst[c4_i] = c4_src[c4_i];
  }
}

static void c4_array_real_T_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_dst, const
  c4_coder_array_real_T *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  c4_array_real_T_SetSize(chartInstance, c4_sp, c4_dst, c4_srcLocation,
    c4_src->size[0]);
  for (c4_i = 0; c4_i < c4_src->vector.numel; c4_i++) {
    c4_dst->vector.data[c4_i] = c4_src->vector.data[c4_i];
  }
}

static void c4_array_real_T_2D_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_2D *c4_dst,
  const c4_coder_array_real_T_2D *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  c4_array_real_T_2D_SetSize(chartInstance, c4_sp, c4_dst, c4_srcLocation,
    c4_src->size[0], c4_src->size[1]);
  for (c4_i = 0; c4_i < c4_src->vector.numel; c4_i++) {
    c4_dst->vector.data[c4_i] = c4_src->vector.data[c4_i];
  }
}

static void c4_array_real_T_1x0_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_1x0 *c4_dst,
  const c4_coder_array_real_T_1x0 *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_array_real_T_1x0_SetSize(chartInstance, c4_sp, c4_dst->size, c4_srcLocation,
    c4_src->size[0], c4_src->size[1]);
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c4_src->size[0], c4_srcLocation, (void *)c4_sp), (size_t)
                     (uint32_T)c4_src->size[1], c4_srcLocation, (void *)c4_sp);
}

static void c4_array_real_T_1x0_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_size[2], const
  emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T c4_size1)
{
  (void)chartInstance;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c4_size[0], c4_srcLocation, (void *)c4_sp), (size_t)
                     (uint32_T)c4_size[1], c4_srcLocation, (void *)c4_sp);
  c4_size[0] = c4_size0;
  c4_size[1] = c4_size1;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c4_size[0], c4_srcLocation, (void *)c4_sp), (size_t)
                     (uint32_T)c4_size[1], c4_srcLocation, (void *)c4_sp);
}

static void c4_array_s_8vINxG2sU0DyuufNTJYdGF_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_8vINxG2sU0DyuufNTJYdGF *c4_pStruct)
{
  c4_array_real_T_Constructor(chartInstance, &c4_pStruct->RegionIndices);
  c4_array_int32_T_Constructor(chartInstance, &c4_pStruct->RegionLengths);
  c4_array_cell_wrap_34_2D_Construct(chartInstance, &c4_pStruct->PixelIdxList);
}

static void c4_array_cell_wrap_34_2D_Construct
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_34_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (c4_cell_wrap_34 *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_s_R6Og1x0kmqQXSF9Pw *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (c4_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_cell_wrap_34_2s_Construct
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[2])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_array_cell_wrap_34_Constructor(chartInstance, &c4_pMatrix[c4_i]);
  }
}

static void c4_b_array_s_8vINxG2sU0DyuufNTJYdGF_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_8vINxG2sU0DyuufNTJYdGF *c4_pStruct)
{
  c4_array_real_T_Destructor(chartInstance, &c4_pStruct->RegionIndices);
  c4_array_int32_T_Destructor(chartInstance, &c4_pStruct->RegionLengths);
  c4_array_cell_wrap_34_2D_Destructo(chartInstance, &c4_pStruct->PixelIdxList);
}

static void c4_array_cell_wrap_34_2D_Destructo
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_34_2D *c4_coderArray)
{
  int32_T c4_i;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data !=
       (c4_cell_wrap_34 *)NULL)) {
    for (c4_i = 0; c4_i < c4_coderArray->vector.numel; c4_i++) {
      c4_array_cell_wrap_34_Destructor(chartInstance,
        &c4_coderArray->vector.data[c4_i]);
    }

    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_s_R6Og1x0kmqQXSF9Pw *c4_coderArray)
{
  int32_T c4_i;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data !=
       (c4_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL)) {
    for (c4_i = 0; c4_i < c4_coderArray->vector.numel; c4_i++) {
      c4_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
        &c4_coderArray->vector.data[c4_i]);
    }

    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_cell_wrap_34_2s_Destructo
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[2])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_array_cell_wrap_34_Destructor(chartInstance, &c4_pMatrix[c4_i]);
  }
}

static void c4_array_cell_wrap_34_Copy(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_34 *c4_dst, const
  c4_cell_wrap_34 *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_array_real_T_Copy(chartInstance, c4_sp, &c4_dst->f1, &c4_src->f1,
                       c4_srcLocation);
}

static void c4_array_cell_wrap_34_1s_Construct
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[1])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 1; c4_i++) {
    c4_array_cell_wrap_34_Constructor(chartInstance, &c4_pMatrix[c4_i]);
  }
}

static void c4_array_cell_wrap_34_1s_Destructo
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_34
   c4_pMatrix[1])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 1; c4_i++) {
    c4_array_cell_wrap_34_Destructor(chartInstance, &c4_pMatrix[c4_i]);
  }
}

static int32_T c4_div_nzp_s32(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_numerator, int32_T c4_denominator, int32_T
  c4_EMLOvCount_src_loc, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc,
  int32_T c4_length_src_loc)
{
  int32_T c4_quotient;
  uint32_T c4_absDenominator;
  uint32_T c4_absNumerator;
  uint32_T c4_tempAbsQuotient;
  boolean_T c4_quotientNeedsNegation;
  (void)chartInstance;
  (void)c4_EMLOvCount_src_loc;
  (void)c4_ssid_src_loc;
  (void)c4_offset_src_loc;
  (void)c4_length_src_loc;
  if (c4_numerator < 0) {
    c4_absNumerator = ~(uint32_T)c4_numerator + 1U;
  } else {
    c4_absNumerator = (uint32_T)c4_numerator;
  }

  if (c4_denominator < 0) {
    c4_absDenominator = ~(uint32_T)c4_denominator + 1U;
  } else {
    c4_absDenominator = (uint32_T)c4_denominator;
  }

  c4_quotientNeedsNegation = ((c4_numerator < 0) != (c4_denominator < 0));
  c4_tempAbsQuotient = c4_absNumerator / c4_absDenominator;
  if (c4_quotientNeedsNegation) {
    c4_quotient = -(int32_T)c4_tempAbsQuotient;
  } else {
    c4_quotient = (int32_T)c4_tempAbsQuotient;
  }

  return c4_quotient;
}

static int32_T c4__s32_s64_(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int64_T c4_b, int32_T c4_EMLOvCount_src_loc, uint32_T
  c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc)
{
  int32_T c4_a;
  (void)c4_EMLOvCount_src_loc;
  c4_a = (int32_T)c4_b;
  if ((int64_T)c4_a != c4_b) {
    sf_data_overflow_error(chartInstance->S, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
  }

  return c4_a;
}

static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_image_in = (boolean_T (*)[19200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c4_offset_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_offset_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c4_signal = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2788723732U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1559194969U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3771285459U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4155047052U);
}

mxArray *sf_c4_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,5);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  return(mxcell3p);
}

mxArray *sf_c4_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippfilter_real32");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDewMTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4oOtnwaKfA0m/AJSfn5ZWnFoSX8EHFR9Yfy"
    "hQ6o/KweEPGaL8wYbmDxC/ODM9LzEH4n4QAAATwhxT"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "soA1eeCkBIG91cTOymCZNy";
}

static void sf_opaque_initialize_c4_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_flightControlSystem(void *chartInstanceVar)
{
  enable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_flightControlSystem(void *chartInstanceVar)
{
  disable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE+P20QUd3aXVYvKqkiI9tCKHrkgdVuQQEK0WScpkXa7Ec4WqZdlYj/bo4xn3PmTxD3xZbh",
    "w4isAHwBOiI/AkSNH3jjebOQNWdsB7RZLXu+z85v33s/v39hp9Y8cPPbw/OOu4+zi9QaeW878eK",
    "uQW0vn/P6O83khD952HD8mUvd5KJz6hy8CiIB7JgzprCaWm2RAJElUA72cJPAVKMGMpoLXM57yE",
    "CRwHxdIhdS19CqaGEb5uGe4bzWrr2Pqx14sDAsOcEESHHOW/ZPe1OgBauxQCb7uAQQ6lsJEcY+R",
    "aD0LUk/dGPyxMkltrhRoz6TWVXVkmKYpg+4M/D5XmiAL6hJ/PU00uHpWO0Ko8s7QIkkZJbw61zF",
    "RHqQYHRpO0gD/HhuN7FXUi/pGlBMtJCWsmzDXRnhF7IChnUcY1qw2zzrRHRiZKKI8suxKkwBH/z",
    "FOKnAVumICkkRwzGvmoPWuO8tf8CIuq+dg34Zloxw0yfytqEbYXG93ggyphnp7PncJY6oedijSQ",
    "5gAy/V3iCYNsHP9NcBK0WAoXhBps6BmJhlOXxkosK7gAa3+hiclVF5wn2PxrACniQ0pCJDmhemL",
    "hS6LSaO0SFxMo87hYUV9F7F9rkGGxIfKtU8SqgANzuOqpt6AKjJiFo0s6dzLyisAbwx1VGh4Zyr",
    "kGDmuW2TPubKZUA8NQQQd0JAXjC5G9wvCTEWbE4UVzobHicKKVU8vYm3+NAL7xI8hsP2EMjgCZR",
    "dQlesz9pE2ejuhOuuA8iVNq2aSURBgI7EsDbMUTviYiynvSZF4xUSwJq4AsGoQybEtHGBbklkPj",
    "a9mtYRXQxtZTcazhGhGRjY2ngHHzmJ9tZ2Q+JhVXY6jGxq0Cdajr7G1c0WVxnEq6+Y5EOTz6N1W",
    "vXn03UJ+vMilvhpKfFME2zDHSak9yoc9GNIE8hsewZliLhaH1fvQOdd7c2u93i38r9UQ52yI+3I",
    "Jt7OCn/eXcLcL2f/4NGQ0im0R1lIwL0Pek4t23KrA9yr7yzjnAu6c57Prh0v41gq9ztJ1k/fzdA",
    "n3TknPTgm3W3D28/3Xw9/uf/td+5fRT9//+uPpJvq/2a4Xz3uFfO9sPlt0sMmFIt80HpRo7wO44",
    "4P+s8/2/eFxlrgvn2fz9X7YWm/vdsnes/sP8NRY4PJ6Kf1+UOy1rEzMfA9g1/90yd7dS/i4uRRP",
    "jvPnk83w7z0t41fxdaPEl5VFGOJW6HS2HL9X58eDTf3Irocf9yr5sVvyYzffW0bclve9N6h+X1W",
    "/uEo7q/STVkPctvPf9a9/E7epf3X75Jv++4dr6oFT+v3ta+xH+dp0Xrpufv3u1JtnPijkLxbfMt",
    "yYsmDFbqp4jBuecNXT/0l8/1WTvzuF3LX8FR9jXz5uY//LcPs0354WtwfSfgdcPJJA1Oo96lX0I",
    "WfFPL6q398q5beVp5QHYqo+2n/0yaNN+trfPncQmA==",
    ""
  };

  static char newstr [1469] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c4_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1417289155U));
  ssSetChecksum1(S,(2776636886U));
  ssSetChecksum2(S,(3261255489U));
  ssSetChecksum3(S,(1606537386U));
}

static void mdlRTW_c4_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_flightControlSystem(SimStruct *S)
{
  SFc4_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc4_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc4_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_flightControlSystem(chartInstance);
}

void c4_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
