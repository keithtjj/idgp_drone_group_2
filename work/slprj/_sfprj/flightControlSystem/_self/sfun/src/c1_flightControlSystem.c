/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
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
static emlrtRSInfo c1_emlrtRSI = { 6,  /* lineNo */
  "Image Processing System/Image Preprocessing",/* fcnName */
  "#flightControlSystem:2866"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 48,/* lineNo */
  "rgb2hsv",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\images\\rgb2hsv.m"/* pathName */
};

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_y[19200]);
static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200]);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c1_JITStateAnimation[0],
                        &chartInstance->c1_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    33U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "c1_flightControlSystem", 0, -1, 420);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c1_b_j;
  int32_T c1_c_j;
  int32_T c1_d_j;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_iy;
  int32_T c1_j;
  uint8_T c1_u[57600];
  boolean_T c1_bv[19200];
  boolean_T c1_mask2[19200];
  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 2U) != 0U) {
    for (c1_i = 0; c1_i < 19200; c1_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 2U,
        (real_T)(*chartInstance->c1_B)[c1_i]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 1U) != 0U) {
    for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 1U,
        (real_T)(*chartInstance->c1_G)[c1_i1]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 0U) != 0U) {
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 0U,
        (real_T)(*chartInstance->c1_R)[c1_i2]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_iy = -1;
  for (c1_j = 0; c1_j < 19200; c1_j++) {
    c1_c_j = c1_j;
    c1_iy++;
    c1_u[c1_iy] = (*chartInstance->c1_R)[c1_c_j];
  }

  for (c1_b_j = 0; c1_b_j < 19200; c1_b_j++) {
    c1_c_j = c1_b_j;
    c1_iy++;
    c1_u[c1_iy] = (*chartInstance->c1_G)[c1_c_j];
  }

  for (c1_d_j = 0; c1_d_j < 19200; c1_d_j++) {
    c1_c_j = c1_d_j;
    c1_iy++;
    c1_u[c1_iy] = (*chartInstance->c1_B)[c1_c_j];
  }

  rgb2hsv_tbb_uint8(&c1_u[0], 19200.0, &chartInstance->c1_hsvImage[0], true);
  c1_i3 = 0;
  for (c1_i4 = 0; c1_i4 < 160; c1_i4++) {
    for (c1_i6 = 0; c1_i6 < 120; c1_i6++) {
      chartInstance->c1_H[c1_i6 + c1_i3] = chartInstance->c1_hsvImage[c1_i6 +
        c1_i3];
    }

    c1_i3 += 120;
  }

  c1_i5 = 0;
  for (c1_i7 = 0; c1_i7 < 160; c1_i7++) {
    for (c1_i9 = 0; c1_i9 < 120; c1_i9++) {
      chartInstance->c1_S[c1_i9 + c1_i5] = chartInstance->c1_hsvImage[(c1_i9 +
        c1_i5) + 19200];
    }

    c1_i5 += 120;
  }

  c1_i8 = 0;
  for (c1_i10 = 0; c1_i10 < 160; c1_i10++) {
    for (c1_i12 = 0; c1_i12 < 120; c1_i12++) {
      chartInstance->c1_V[c1_i12 + c1_i8] = chartInstance->c1_hsvImage[(c1_i12 +
        c1_i8) + 38400];
    }

    c1_i8 += 120;
  }

  for (c1_i11 = 0; c1_i11 < 19200; c1_i11++) {
    (*chartInstance->c1_BW)[c1_i11] = (chartInstance->c1_H[c1_i11] >= 0.0);
  }

  for (c1_i13 = 0; c1_i13 < 19200; c1_i13++) {
    c1_bv[c1_i13] = (chartInstance->c1_H[c1_i13] <= 0.05);
  }

  for (c1_i14 = 0; c1_i14 < 19200; c1_i14++) {
    (*chartInstance->c1_BW)[c1_i14] = ((*chartInstance->c1_BW)[c1_i14] &&
      c1_bv[c1_i14]);
  }

  for (c1_i15 = 0; c1_i15 < 19200; c1_i15++) {
    c1_mask2[c1_i15] = (chartInstance->c1_H[c1_i15] >= 0.95);
  }

  for (c1_i16 = 0; c1_i16 < 19200; c1_i16++) {
    c1_bv[c1_i16] = (chartInstance->c1_H[c1_i16] <= 1.0);
  }

  for (c1_i17 = 0; c1_i17 < 19200; c1_i17++) {
    c1_mask2[c1_i17] = (c1_mask2[c1_i17] && c1_bv[c1_i17]);
  }

  for (c1_i18 = 0; c1_i18 < 19200; c1_i18++) {
    (*chartInstance->c1_BW)[c1_i18] = ((*chartInstance->c1_BW)[c1_i18] ||
      c1_mask2[c1_i18]);
  }

  for (c1_i19 = 0; c1_i19 < 19200; c1_i19++) {
    c1_mask2[c1_i19] = (chartInstance->c1_S[c1_i19] > 0.5);
  }

  for (c1_i20 = 0; c1_i20 < 19200; c1_i20++) {
    c1_bv[c1_i20] = (chartInstance->c1_V[c1_i20] > 0.2);
  }

  for (c1_i21 = 0; c1_i21 < 19200; c1_i21++) {
    c1_mask2[c1_i21] = (c1_mask2[c1_i21] && c1_bv[c1_i21]);
  }

  for (c1_i22 = 0; c1_i22 < 19200; c1_i22++) {
    (*chartInstance->c1_BW)[c1_i22] = ((*chartInstance->c1_BW)[c1_i22] &&
      c1_mask2[c1_i22]);
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 3U) != 0U) {
    for (c1_i23 = 0; c1_i23 < 19200; c1_i23++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 3U,
        (real_T)(*chartInstance->c1_BW)[c1_i23]);
    }
  }
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(1, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_BW, 11, 0U, 1, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  int32_T c1_i;
  boolean_T c1_bv[19200];
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "BW",
                      c1_bv);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    (*chartInstance->c1_BW)[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_y[19200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200])
{
  int32_T c1_i;
  boolean_T c1_bv[19200];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_y[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_BW = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3991489573U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2020235091U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1880551603U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1121080316U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2hsv_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOk3QNLPgkU/E5J+ASDPKRwSLiAAAC2fDNY="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "syIdSD1IeTTpblOzGWPXj1G";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE1vG0UYHjshalGpgoTaIiHBESEhkVZIHBAk8UdqKSEW6zSoFzTefb07ZHZmOx923H/AP+N",
    "ML3DkxBGOHHlnvXZc28Q766IEVlqvZ9fPvO8887wfa1LrnBA87uPZfUjIDl7v4Fknk+OtYlybOy",
    "f3t8mXxbj7NiFhQpXpiIEk/kcoI4hBBHYwYJeeWGHTLlU01RXsCprCt6Alt4ZJ4ec8EwNQIEKcI",
    "JPKeNnVLLWciYu2FaGzrM8TFiZBIi2PDnFCGp0KPv4nu5k1XbTYZApC0waITKKkjZM2p/H1LCgz",
    "aiQQXmibenOlwQQ2c0vVJ5YblnFoXULYEdpQZEGvWW9gqIGGufRWCNPBFC3TjDMqynOdUB1Ahuo",
    "wcJZF+HlqDbJX0i7a6zNBjVSM8lbKG07hJbFdjn6eoKy5N88mNU3o2zhmInbsKpuCwPWjTkpwNW",
    "jIISgaw6nwjEG3utZlvsEzXZaPwY6TZaUYtOlkV3QlbG63NUSGdEW77VA0KOfaD9uT2TEMgef2m",
    "9TQCtiJfQ+w1izqyWdUuSjwjCQr2AsLBbYhRcTK7/BwAZUn3G8weZaAs9RJCiKkeeb6bKJ1mrTa",
    "yLSBYdQ8Pi5pbxnbEQbUgIZQOvcpyjSgw7muPO1GTNM+d2hkyeSrLD0DiMpQogdWNEdSXSDHvkn",
    "2iisXCX5oiGJogoE8YbRQ3c8otyV9TjVmOCePM40Zy88uYl38VAKHNEwgcvWEcTgB7SbQpfMz1p",
    "EDXO2QmXETdKhYVjaSrIYIC4ljqTfO4ExcCDkSbSXToOgIrtEVAGYNqgSWhUMsS2rcRufLea3gR",
    "c8pq0p7llLDad9p4wgEVha3VlcJaYhR1RLYuqFDm2AD9hJLu9BMG2ynxq08BqK8H31U8+tH3y3G",
    "T2ax1NE9hTtFsQwL7JQO+nmzBz2WQn4joNhTTIbF4ex+Rq7s3q1fb7eO32oVcWRD3NM53PYKfh7",
    "M4XaLcbj3/YCzOHFJ2CjJgzHyni77ca8E36v8X8SRJdwVz9Prx3P42gq7ZO66jq+tJb62SK1Wy3",
    "H7c7h3FuxsL+B2Cs5+e/X+Jz/++sfw8PefI/pot7uJPn7y1PP9YvzBtD+bVbDhUpIvo4eHC3pwY",
    "z3uREFzrwO9Xtbnpy+Pzrvf/bB3VCn+pvc/wtNggsvzpQo7UfGu5cbUTt4B3PxfzPm7s2b+u3N6",
    "IuTPrzfDv7e/uI+r+Kq/xledHJ6/rtvbniduKi/dpJ9l8tZWRVyN/Ht58k3iNl2fbz7+r//+ujx",
    "AFn6/e4vXsXitWpdv27p+IX516MNi/NXsnbmRMB6t6NqLx9hYD1Y9/Z/o+y9P/qZ9QsvxV/zp9/",
    "zJgaB8jG365DWouN1V7v+m2SMFVK9+F7qJOjS97q+p8/cW4tuNR0xEcqQ/3Xv8+eNN6trfvyAA3",
    "Q==",
    ""
  };

  static char newstr [1429] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(706335713U));
  ssSetChecksum1(S,(1995430281U));
  ssSetChecksum2(S,(1691543362U));
  ssSetChecksum3(S,(1343232097U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
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

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
