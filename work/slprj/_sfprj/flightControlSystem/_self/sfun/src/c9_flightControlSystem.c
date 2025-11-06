/* Include files */

#include "flightControlSystem_sfun.h"
#include "c9_flightControlSystem.h"
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
static emlrtRSInfo c9_emlrtRSI = { 6,  /* lineNo */
  "Image Processing System/image preprocess/MATLAB Function",/* fcnName */
  "#flightControlSystem:2754"          /* pathName */
};

static emlrtRSInfo c9_b_emlrtRSI = { 48,/* lineNo */
  "rgb2hsv",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\images\\rgb2hsv.m"/* pathName */
};

/* Function Declarations */
static void initialize_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void enable_c9_flightControlSystem(SFc9_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void c9_update_jit_animation_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void c9_do_animation_call_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance, const mxArray *c9_st);
static void c9_emlrt_marshallIn(SFc9_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier,
  boolean_T c9_y[19200]);
static void c9_b_emlrt_marshallIn(SFc9_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T c9_y[19200]);
static void init_dsm_address_info(SFc9_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc9_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c9_doneDoubleBufferReInit = false;
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c9_decisionTxtEndIdx = 0U;
  static const uint32_T c9_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c9_JITStateAnimation[0],
                        &chartInstance->c9_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c9_covrtInstance, 1U, 0U, 1U,
    60U);
  covrtChartInitFcn(chartInstance->c9_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c9_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c9_decisionTxtStartIdx, &c9_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c9_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c9_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 0U,
                     "c9_flightControlSystem", 0, -1, 419);
}

static void mdl_cleanup_runtime_resources_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c9_covrtInstance);
}

static void enable_c9_flightControlSystem(SFc9_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c9_b_j;
  int32_T c9_c_j;
  int32_T c9_d_j;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i2;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_iy;
  int32_T c9_j;
  uint8_T c9_u[57600];
  boolean_T c9_bv[19200];
  boolean_T c9_mask2[19200];
  if (covrtIsSigCovEnabledFcn(chartInstance->c9_covrtInstance, 2U) != 0U) {
    for (c9_i = 0; c9_i < 19200; c9_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c9_covrtInstance, 2U,
        (real_T)(*chartInstance->c9_B)[c9_i]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c9_covrtInstance, 1U) != 0U) {
    for (c9_i1 = 0; c9_i1 < 19200; c9_i1++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c9_covrtInstance, 1U,
        (real_T)(*chartInstance->c9_G)[c9_i1]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c9_covrtInstance, 0U) != 0U) {
    for (c9_i2 = 0; c9_i2 < 19200; c9_i2++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c9_covrtInstance, 0U,
        (real_T)(*chartInstance->c9_R)[c9_i2]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_JITTransitionAnimation[0] = 0U;
  chartInstance->c9_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c9_covrtInstance, 4U, 0, 0);
  c9_iy = -1;
  for (c9_j = 0; c9_j < 19200; c9_j++) {
    c9_c_j = c9_j;
    c9_iy++;
    c9_u[c9_iy] = (*chartInstance->c9_R)[c9_c_j];
  }

  for (c9_b_j = 0; c9_b_j < 19200; c9_b_j++) {
    c9_c_j = c9_b_j;
    c9_iy++;
    c9_u[c9_iy] = (*chartInstance->c9_G)[c9_c_j];
  }

  for (c9_d_j = 0; c9_d_j < 19200; c9_d_j++) {
    c9_c_j = c9_d_j;
    c9_iy++;
    c9_u[c9_iy] = (*chartInstance->c9_B)[c9_c_j];
  }

  rgb2hsv_tbb_uint8(&c9_u[0], 19200.0, &chartInstance->c9_hsvImage[0], true);
  c9_i3 = 0;
  for (c9_i4 = 0; c9_i4 < 160; c9_i4++) {
    for (c9_i6 = 0; c9_i6 < 120; c9_i6++) {
      chartInstance->c9_H[c9_i6 + c9_i3] = chartInstance->c9_hsvImage[c9_i6 +
        c9_i3];
    }

    c9_i3 += 120;
  }

  c9_i5 = 0;
  for (c9_i7 = 0; c9_i7 < 160; c9_i7++) {
    for (c9_i9 = 0; c9_i9 < 120; c9_i9++) {
      chartInstance->c9_S[c9_i9 + c9_i5] = chartInstance->c9_hsvImage[(c9_i9 +
        c9_i5) + 19200];
    }

    c9_i5 += 120;
  }

  c9_i8 = 0;
  for (c9_i10 = 0; c9_i10 < 160; c9_i10++) {
    for (c9_i12 = 0; c9_i12 < 120; c9_i12++) {
      chartInstance->c9_V[c9_i12 + c9_i8] = chartInstance->c9_hsvImage[(c9_i12 +
        c9_i8) + 38400];
    }

    c9_i8 += 120;
  }

  for (c9_i11 = 0; c9_i11 < 19200; c9_i11++) {
    (*chartInstance->c9_BW)[c9_i11] = (chartInstance->c9_H[c9_i11] >= 0.0);
  }

  for (c9_i13 = 0; c9_i13 < 19200; c9_i13++) {
    c9_bv[c9_i13] = (chartInstance->c9_H[c9_i13] <= 0.05);
  }

  for (c9_i14 = 0; c9_i14 < 19200; c9_i14++) {
    (*chartInstance->c9_BW)[c9_i14] = ((*chartInstance->c9_BW)[c9_i14] &&
      c9_bv[c9_i14]);
  }

  for (c9_i15 = 0; c9_i15 < 19200; c9_i15++) {
    c9_mask2[c9_i15] = (chartInstance->c9_H[c9_i15] >= 0.95);
  }

  for (c9_i16 = 0; c9_i16 < 19200; c9_i16++) {
    c9_bv[c9_i16] = (chartInstance->c9_H[c9_i16] <= 1.0);
  }

  for (c9_i17 = 0; c9_i17 < 19200; c9_i17++) {
    c9_mask2[c9_i17] = (c9_mask2[c9_i17] && c9_bv[c9_i17]);
  }

  for (c9_i18 = 0; c9_i18 < 19200; c9_i18++) {
    (*chartInstance->c9_BW)[c9_i18] = ((*chartInstance->c9_BW)[c9_i18] ||
      c9_mask2[c9_i18]);
  }

  for (c9_i19 = 0; c9_i19 < 19200; c9_i19++) {
    c9_mask2[c9_i19] = (chartInstance->c9_S[c9_i19] > 0.5);
  }

  for (c9_i20 = 0; c9_i20 < 19200; c9_i20++) {
    c9_bv[c9_i20] = (chartInstance->c9_V[c9_i20] > 0.2);
  }

  for (c9_i21 = 0; c9_i21 < 19200; c9_i21++) {
    c9_mask2[c9_i21] = (c9_mask2[c9_i21] && c9_bv[c9_i21]);
  }

  for (c9_i22 = 0; c9_i22 < 19200; c9_i22++) {
    (*chartInstance->c9_BW)[c9_i22] = ((*chartInstance->c9_BW)[c9_i22] &&
      c9_mask2[c9_i22]);
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c9_covrtInstance, 3U) != 0U) {
    for (c9_i23 = 0; c9_i23 < 19200; c9_i23++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c9_covrtInstance, 3U,
        (real_T)(*chartInstance->c9_BW)[c9_i23]);
    }
  }
}

static void ext_mode_exec_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_jit_animation_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_do_animation_call_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c9_b_y = NULL;
  const mxArray *c9_st = NULL;
  const mxArray *c9_y = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(1, 1), false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", *chartInstance->c9_BW, 11, 0U, 1, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_flightControlSystem
  (SFc9_flightControlSystemInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  int32_T c9_i;
  boolean_T c9_bv[19200];
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "BW",
                      c9_bv);
  for (c9_i = 0; c9_i < 19200; c9_i++) {
    (*chartInstance->c9_BW)[c9_i] = c9_bv[c9_i];
  }

  sf_mex_destroy(&c9_u);
  sf_mex_destroy(&c9_st);
}

const mxArray *sf_c9_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static void c9_emlrt_marshallIn(SFc9_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier,
  boolean_T c9_y[19200])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_nullptr);
}

static void c9_b_emlrt_marshallIn(SFc9_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T c9_y[19200])
{
  int32_T c9_i;
  boolean_T c9_bv[19200];
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c9_i = 0; c9_i < 19200; c9_i++) {
    c9_y[c9_i] = c9_bv[c9_i];
  }

  sf_mex_destroy(&c9_u);
}

static void init_dsm_address_info(SFc9_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c9_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c9_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c9_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_BW = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c9_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(559174277U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2766618911U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1581963210U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2505499516U);
}

mxArray *sf_c9_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c9_flightControlSystem_jit_fallback_info(void)
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

mxArray *sf_c9_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOk3QNLPgkU/E5J+ASDPKRwSLiAAAC2fDNY="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s7TeshT3LRVjfCivDOUAegE";
}

static void sf_opaque_initialize_c9_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c9_flightControlSystem
    ((SFc9_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_flightControlSystem(void *chartInstanceVar)
{
  enable_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_flightControlSystem(void *chartInstanceVar)
{
  disable_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c9_flightControlSystem
    ((SFc9_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c9_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c9_flightControlSystem
      ((SFc9_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c9_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc9_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c9_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c9_flightControlSystem((SFc9_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_flightControlSystem
      ((SFc9_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c9_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWN1u40QUnqSlYtGyWiTEgoQEl9wgwVYIkNDSNj8QqaXROu1KcIEm9rE92/GMd36ShheAB+E",
    "FeAvuuEJCXPAAiAu420vOOE6aTULrcUAta8lxxs4358w33/lxSKN3RPC4g2f/HiE7eH0RzyaZHi",
    "+U48bCOb2/TT4px/2XCAlTqkxPxJL4H6GMIAER2Dhm555YYbM+VTTTNewKmsFD0JJbw6Twc56JG",
    "BSIECfIpTJedjXLLGfirGtF6CzrRykL0yCVlkcHOCGNjgWf/JPd3Jo+WmwzBaHpAkQmVdImaZfT",
    "5HIWlBm3UgjPtM28udJgApu7peojyw3LOXTOIewJbSiyoK9Yb2CogZY591YI08EMLbOcMyqqc51",
    "SHUCO6jBwkkf4eWwNslfRLtobMkGNVIzyTsZbTuEVsX2Ofh6hrLk3zyYzbRjaJGEicewqm4HA9a",
    "NOKnAVt+QIFE3gWHjGoFtd57zY4Lkuq8dgz8myVgzabLoruha2sNsZIUO6pt1uKFqUc+2HHcj8E",
    "EbAC/ttamgN7NS+B1hrFg3kKVUuCjwjyQr2xEKJbUkRseo7PFpCFQn3C0yeFeAsc5KCCGmeuz6f",
    "6CpNWm1k1sIwah8eVrS3iu0JAyqmIVTOfYoyDehwoStPuxHTdMgdGlkyxSorzwCiNpTo2Ir2WKo",
    "z5Ng3yV5w5SLBDw1RAm0wUCSMDqr7lHJb0edMY4Zz8jjRmLH87CLWxU8tcEjDFCJXTxiHI9BuAl",
    "05P2Md2cfVjpiZtEGHiuVVI8lqiLCQOJYGkxxOxJmQY9FVMgvKjuASXQFg1qBKYFk4wLKkJl10v",
    "prXCp4MnLLqtGcZNZwOnTY+A4GVxa3VVUIaYlR1BLZu6NAm2IB9g6VdaKYNtlOTThEDUdGPvt7w",
    "60dfKce781jq6YHCnaJYhgV2SvvDotmDAcuguBFQ7Cmmw/Jwdt8jF3ZvNS+328RvjZo4siHu8wX",
    "c9hp+XlvA3S3H4cdfx5wlqUvCRkkeTJD3bNWP2xX4Xuf/Mo6s4C54nl3fWcA31tglC9er+Npa4W",
    "uLNBqNAre3gHt5yc72Em6n5Oz7n/74avDrd/Tbv3774envb/y8iT5+9NTznXL85qw/m1ew0UqSr",
    "6KHe0t6cGP94QB0Otg9fHj6OG6xUfv4ZB+STq34m91/G0+DCa7IlyrsReW7lhtTO30HcPN/tODv",
    "zhXz31rQEyF/froZ/tW95X1cx1fzGb6a5ODRs7q96XniuvLSdfpZJW9t1cQ1yH+XJ/9N3Kbr883",
    "H//ffX5YHyNLv797gdSxf69blm7auX4hfHXqrHD+YvzO3UsajNV17+Rgb63jd0+dE3089+Zv1CR",
    "3HX/mn35e7+4LyCbbp09eg8nZfuf+b5o8UUL3+Xeg66tDsundFnb+9FN9uPGYikmP97vv3P7i/S",
    "V37G5NSA5Y=",
    ""
  };

  static char newstr [1437] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c9_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c9_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1542246308U));
  ssSetChecksum1(S,(1636358740U));
  ssSetChecksum2(S,(2984178055U));
  ssSetChecksum3(S,(3575245560U));
}

static void mdlRTW_c9_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c9_flightControlSystem(SimStruct *S)
{
  SFc9_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc9_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc9_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc9_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c9_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c9_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c9_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_flightControlSystem;
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

  mdl_setup_runtime_resources_c9_flightControlSystem(chartInstance);
}

void c9_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c9_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
