/*
 * flightControlSystem.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 9.25
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Nov  6 17:22:05 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "rtwtypes.h"
#include "flightControlSystem_types.h"
#include "flightControlSystem_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include <float.h>
#include <stdlib.h>
#include <stddef.h>
#include "zero_crossing_types.h"
#include "flightControlSystem_dt.h"

/* Named constants for MATLAB Function: '<S370>/SqrtUsedFcn' */
#define flightControlSystem_CALL_EVENT (-1)

/* Named constants for MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)' */
#define flightControlSystem_CALL_EVENT_a (-1)

/* Named constants for Chart: '<S5>/Chart' */
#define flightControlSystem_IN_Circle2 (1U)
#define flightControlSystem_IN_Hover   (2U)
#define flightControlSystem_IN_Line_track (3U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_land3   (4U)

/* Named constants for MATLAB Function: '<S2>/MATLAB Function' */
#define flightControlSystem_CALL_EVENT_ax (-1)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S12>/MotorDirections' */
uint8_T flag_outport;                  /* '<S4>/Merge' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_flightControlSystem_T flightControlSystem_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
static RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;

/* Forward declaration for local functions */
static real_T flightControlSystem_mod(real_T x);
static real_T flightControlSystem_line_drawer(real_T x2, real_T y2, const
  boolean_T u[19200], real_T compare);
static void flightControlSystem_nearest_edge(real_T x, real_T y, real_T *X,
  real_T *Y);
static void flightControlSystem_emxInit_real_T
  (emxArray_real_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_imfilter(const real32_T varargin_1[19200],
  real32_T b[19200]);
static void flightControlSystem_conv2(const real_T a[19764], const real_T b[9],
  real_T c[19200]);
static void flightControlSystem_imfilter_k(const real32_T varargin_1[19200],
  real32_T b[19200]);
static void flightControlSystem_imfilter_k3(const real32_T varargin_1[19200],
  real32_T b[19200]);
static void flightControlSystem_emxInit_int32_T
  (emxArray_int32_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxEnsureCapacity_int32_T
  (emxArray_int32_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_eml_find(const boolean_T x[19200],
  emxArray_int32_T_flightControlSystem_T *i,
  emxArray_int32_T_flightControlSystem_T *j);
static void flightControlSystem_emxInit_real32_T
  (emxArray_real32_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxInit_creal_T
  (emxArray_creal_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxInit_boolean_T
  (emxArray_boolean_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxEnsureCapacity_real32_T
  (emxArray_real32_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxEnsureCapacity_creal_T
  (emxArray_creal_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxEnsureCapacity_boolean_T
  (emxArray_boolean_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxFree_int32_T
  (emxArray_int32_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxFree_creal_T
  (emxArray_creal_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxFree_boolean_T
  (emxArray_boolean_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxFree_real32_T
  (emxArray_real32_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_chaccum(const boolean_T varargin_1[19200],
  creal_T accumMatrix[19200], real32_T gradientImg[19200]);
static real_T flightControlSystem_median25(real_T vec[25]);
static real_T flightControlSystem_rt_remd_snf(real_T u0, real_T u1);
static void flightControlSystem_NeighborhoodProcessor_computeParameters(const
  int32_T imSize[2], const boolean_T nhConn[9], int32_T loffsets[9], int32_T
  linds[9], int32_T soffsets[18], int32_T interiorStart[2], int32_T interiorEnd
  [2]);
static void flightControlSystem_bsxfun(const int32_T a[18], const int32_T b[2],
  int32_T c[18]);
static real_T flightControlSystem_maximum(const real_T x_data[], const int32_T
  *x_size);
static void flightControlSystem_imhmax(const real_T b_I[19200], real_T J[19200]);
static boolean_T flightControlSystem_isequal(const boolean_T varargin_1[19200],
  const boolean_T varargin_2[19200]);
static void flightControlSystem_imregionalmax(const real_T varargin_1[19200],
  boolean_T BW[19200]);
static void flightControlSystem_emxInit_sOA5t73y81YtFHGIDxk0fKF
  (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T **pEmxArray, int32_T
   numDimensions);
static void flightControlSystem_emxInit_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T **pEmxArray, int32_T
   numDimensions);
static void flightControlSystem_emxInit_int16_T
  (emxArray_int16_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxInit_int8_T
  (emxArray_int8_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxEnsureCapacity_int8_T
  (emxArray_int8_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxInit_uint8_T
  (emxArray_uint8_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxEnsureCapacity_uint8_T
  (emxArray_uint8_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxEnsureCapacity_int16_T
  (emxArray_int16_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxFree_uint8_T
  (emxArray_uint8_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxFree_int8_T
  (emxArray_int8_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxInitStruct_cell_wrap_36
  (cell_wrap_36_flightControlSystem_T *pStruct);
static void flightControlSystem_emxExpand_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T *emxArray, int32_T fromIndex,
   int32_T toIndex);
static void flightControlSystem_emxFree_real_T
  (emxArray_real_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxFreeStruct_cell_wrap_36
  (cell_wrap_36_flightControlSystem_T *pStruct);
static void flightControlSystem_emxTrim_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T *emxArray, int32_T fromIndex,
   int32_T toIndex);
static void flightControlSystem_emxEnsureCapacity_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxEnsureCapacity_real_T
  (emxArray_real_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxFree_int16_T
  (emxArray_int16_T_flightControlSystem_T **pEmxArray);
static void flightControlSystem_emxCopy_real_T
  (emxArray_real_T_flightControlSystem_T **dst,
   emxArray_real_T_flightControlSystem_T * const *src);
static void flightControlSystem_emxCopyStruct_cell_wrap_36
  (cell_wrap_36_flightControlSystem_T *dst, const
   cell_wrap_36_flightControlSystem_T *src);
static void flightControlSystem_emxFree_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T **pEmxArray);
static void flightControlSystem_bwconncomp(const boolean_T varargin_1[19200],
  real_T *CC_Connectivity, real_T CC_ImageSize[2], real_T *CC_NumObjects,
  emxArray_real_T_flightControlSystem_T *CC_RegionIndices,
  emxArray_int32_T_flightControlSystem_T *CC_RegionLengths,
  emxArray_cell_wrap_36_flightControlSystem_T *CC_PixelIdxList);
static void flightControlSystem_emxEnsureCapacity_sOA5t73y81YtF
  (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *emxArray, int32_T
   oldNumel);
static void flightControlSystem_emxInitStruct_s_R6Og1x0kmqQXSF9
  (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *pStruct);
static void flightControlSystem_emxInit_s_R6Og1x0kmqQXSF9Pwa49F
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T **pEmxArray, int32_T
   numDimensions);
static void flightControlSystem_emxExpand_s_R6Og1x0kmqQXSF9Pwa4
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray, int32_T
   fromIndex, int32_T toIndex);
static void flightControlSystem_emxFreeStruct_s_R6Og1x0kmqQXSF9
  (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *pStruct);
static void flightControlSystem_emxTrim_s_R6Og1x0kmqQXSF9Pwa49F
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray, int32_T
   fromIndex, int32_T toIndex);
static void flightControlSystem_emxEnsureCapacity_s_R6Og1x0kmqQ
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray, int32_T
   oldNumel);
static void flightControlSystem_emxCopyMatrix_real_T(real_T dst[2], const real_T
  src[2]);
static void flightControlSystem_emxCopyMatrix_real_T1(real_T dst[4], const
  real_T src[4]);
static void flightControlSystem_emxCopy_boolean_T_0x0
  (emxArray_boolean_T_0x0_flightControlSystem_T *dst, const
   emxArray_boolean_T_0x0_flightControlSystem_T *src);
static void flightControlSystem_emxCopyMatrix_real_T2(real_T dst[16], const
  real_T src[16]);
static void flightControlSystem_emxCopy_real_T_1x0
  (emxArray_real_T_1x0_flightControlSystem_T *dst, const
   emxArray_real_T_1x0_flightControlSystem_T *src);
static void flightControlSystem_emxCopyStruct_s_R6Og1x0kmqQXSF9
  (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *dst, const
   s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *src);
static real_T flightControlSystem_sum(const
  emxArray_real_T_flightControlSystem_T *x);
static void flightControlSystem_binary_expand_op(real_T in1[2], int32_T in2,
  const emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *in3, int32_T in4,
  real_T in5);
static void flightControlSystem_emxFree_s_R6Og1x0kmqQXSF9Pwa49F
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T **pEmxArray);
static void flightControlSystem_regionprops(const boolean_T varargin_1[19200],
  const real_T varargin_2[19200],
  emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *outstats);
static void flightControlSystem_merge(emxArray_int32_T_flightControlSystem_T
  *idx, emxArray_real_T_flightControlSystem_T *x, int32_T offset, int32_T np,
  int32_T nq, emxArray_int32_T_flightControlSystem_T *iwork,
  emxArray_real_T_flightControlSystem_T *xwork);
static void flightControlSystem_merge_block
  (emxArray_int32_T_flightControlSystem_T *idx,
   emxArray_real_T_flightControlSystem_T *x, int32_T offset, int32_T n, int32_T
   preSortLevel, emxArray_int32_T_flightControlSystem_T *iwork,
   emxArray_real_T_flightControlSystem_T *xwork);
static void flightControlSystem_sort(emxArray_real_T_flightControlSystem_T *x,
  emxArray_int32_T_flightControlSystem_T *idx);
static void flightControlSystem_emxFree_sOA5t73y81YtFHGIDxk0fKF
  (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T **pEmxArray);
static void flightControlSystem_chcenters(const creal_T varargin_1[19200],
  emxArray_real_T_flightControlSystem_T *centers,
  emxArray_real_T_flightControlSystem_T *metric);
static void flightControlSystem_emxInit_uint32_T
  (emxArray_uint32_T_flightControlSystem_T **pEmxArray, int32_T numDimensions);
static void flightControlSystem_emxEnsureCapacity_uint32_T
  (emxArray_uint32_T_flightControlSystem_T *emxArray, int32_T oldNumel);
static void flightControlSystem_emxFree_uint32_T
  (emxArray_uint32_T_flightControlSystem_T **pEmxArray);
static void rate_monotonic_scheduler(void);
int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    tempAbsQuotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
                       numerator) / (denominator < 0 ? ~(uint32_T)denominator +
      1U : (uint32_T)denominator);
    quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(flightControlSystem_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (flightControlSystem_M->Timing.TaskCounters.TID[1])++;
  if ((flightControlSystem_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.2s, 0.0s] */
    flightControlSystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/Geofencing error'
 *    '<S4>/estimator//Optical flow error'
 *    '<S4>/No optical flow '
 *    '<S4>/Ultrasound improper'
 *    '<S4>/Normal condition'
 */
void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP)
{
  /* SignalConversion generated from: '<S243>/Out1' incorporates:
   *  Constant: '<S243>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * System initialize for atomic system:
 *    '<S370>/SqrtUsedFcn'
 *    '<S424>/SqrtUsedFcn'
 */
void flightControlSystem_SqrtUsedFcn_Init(DW_SqrtUsedFcn_flightControlSystem_T
  *localDW)
{
  localDW->doneDoubleBufferReInit = false;
  localDW->sfEvent = flightControlSystem_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S370>/SqrtUsedFcn'
 *    '<S424>/SqrtUsedFcn'
 */
void flightControlSystem_SqrtUsedFcn(DW_SqrtUsedFcn_flightControlSystem_T
  *localDW)
{
  localDW->sfEvent = flightControlSystem_CALL_EVENT;
}

/*
 * System initialize for enable system:
 *    '<S341>/MeasurementUpdate'
 *    '<S395>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Init
  (B_MeasurementUpdate_flightControlSystem_T *localB,
   P_MeasurementUpdate_flightControlSystem_T *localP)
{
  /* SystemInitialize for Product: '<S372>/Product3' incorporates:
   *  Outport: '<S372>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;
  localB->Product3[1] = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S341>/MeasurementUpdate'
 *    '<S395>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Disable
  (B_MeasurementUpdate_flightControlSystem_T *localB,
   DW_MeasurementUpdate_flightControlSystem_T *localDW,
   P_MeasurementUpdate_flightControlSystem_T *localP)
{
  /* Disable for Product: '<S372>/Product3' incorporates:
   *  Outport: '<S372>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;
  localB->Product3[1] = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Start for enable system:
 *    '<S341>/MeasurementUpdate'
 *    '<S395>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Start
  (DW_MeasurementUpdate_flightControlSystem_T *localDW)
{
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S341>/MeasurementUpdate'
 *    '<S395>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[2], real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T
  rtu_xhatkk1[2], real32_T rtu_Dk, real32_T rtu_uk,
  B_MeasurementUpdate_flightControlSystem_T *localB,
  DW_MeasurementUpdate_flightControlSystem_T *localDW,
  P_MeasurementUpdate_flightControlSystem_T *localP)
{
  real32_T rtb_Sum_l;

  /* Outputs for Enabled SubSystem: '<S341>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S372>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Sum: '<S372>/Sum' incorporates:
     *  Product: '<S372>/C[k]*xhat[k|k-1]'
     *  Product: '<S372>/D[k]*u[k]'
     *  Sum: '<S372>/Add1'
     */
    rtb_Sum_l = rtu_yk - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1
      [1]) + rtu_Dk * rtu_uk);

    /* Product: '<S372>/Product3' */
    localB->Product3[0] = rtu_Lk[0] * rtb_Sum_l;
    localB->Product3[1] = rtu_Lk[1] * rtb_Sum_l;
    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC);
  } else if (localDW->MeasurementUpdate_MODE) {
    flightControlSystem_MeasurementUpdate_Disable(localB, localDW, localP);
  }

  /* End of Outputs for SubSystem: '<S341>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S348>/Enabled Subsystem'
 *    '<S402>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Init
  (B_EnabledSubsystem_flightControlSystem_T *localB,
   P_EnabledSubsystem_flightControlSystem_T *localP)
{
  /* SystemInitialize for Product: '<S374>/Product2' incorporates:
   *  Outport: '<S374>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;
  localB->Product2[1] = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S348>/Enabled Subsystem'
 *    '<S402>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Disable
  (B_EnabledSubsystem_flightControlSystem_T *localB,
   DW_EnabledSubsystem_flightControlSystem_T *localDW,
   P_EnabledSubsystem_flightControlSystem_T *localP)
{
  /* Disable for Product: '<S374>/Product2' incorporates:
   *  Outport: '<S374>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;
  localB->Product2[1] = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S348>/Enabled Subsystem'
 *    '<S402>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Start
  (DW_EnabledSubsystem_flightControlSystem_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S348>/Enabled Subsystem'
 *    '<S402>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[2], const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T
  rtu_xhatkk1[2], B_EnabledSubsystem_flightControlSystem_T *localB,
  DW_EnabledSubsystem_flightControlSystem_T *localDW,
  P_EnabledSubsystem_flightControlSystem_T *localP)
{
  real32_T rtb_Add1;

  /* Outputs for Enabled SubSystem: '<S348>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S374>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S374>/Add1' incorporates:
     *  Product: '<S374>/Product'
     */
    rtb_Add1 = rtu_yk - (rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1[1]);

    /* Product: '<S374>/Product2' */
    localB->Product2[0] = rtu_Mk[0] * rtb_Add1;
    localB->Product2[1] = rtu_Mk[1] * rtb_Add1;
    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
  } else if (localDW->EnabledSubsystem_MODE) {
    flightControlSystem_EnabledSubsystem_Disable(localB, localDW, localP);
  }

  /* End of Outputs for SubSystem: '<S348>/Enabled Subsystem' */
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* SetupRuntimeResources for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_SetupRTR(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 12 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 12 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Control System/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estimatedStates",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }
}

/* System initialize for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Init
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW,
   P_ControlSystem_flightControlSystem_T *localP)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] =
    localP->SimplyIntegrateVelocity_IC;
  localDW->SimplyIntegrateVelocity_DSTATE[1] =
    localP->SimplyIntegrateVelocity_IC;
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Reshape: '<S255>/Reshapexhat' incorporates:
   *  Delay: '<S251>/Delay2'
   */
  localDW->Delay2_DSTATE = localP->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S255>/MemoryX' */
  localDW->icLoad = true;

  /* InitializeConditions for DiscreteFilter: '<S256>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S256>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S256>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localP->sonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteIntegrator: '<S319>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteFir: '<S253>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = localP->FIR_IMUaccel_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFir: '<S253>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S321>/MemoryX' */
  localDW->icLoad_p = true;

  /* InitializeConditions for Delay: '<S375>/MemoryX' */
  localDW->icLoad_k = true;

  /* InitializeConditions for Sum: '<S515>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S514>/Output'
   */
  localDW->Output_DSTATE = localP->Output_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localP->LPFFcutoff40Hz1_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localP->LPFFcutoff40Hz_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S253>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = localP->IIR_IMUgyro_r_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S253>/IIR_IMUgyro_r' */

  /* InitializeConditions for Sum: '<S434>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S432>/Output'
   */
  localDW->Output_DSTATE_i = localP->Output_InitialCondition_e;

  /* InitializeConditions for Delay: '<S441>/MemoryX' */
  localDW->icLoad_o = true;

  /* InitializeConditions for DiscreteFilter: '<S440>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = localP->IIRgyroz_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S440>/IIRgyroz' */

  /* InitializeConditions for Sum: '<S15>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S14>/Output'
   */
  localDW->Output_DSTATE_a = localP->Output_InitialCondition_f;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_c = localP->DiscreteTimeIntegrator_IC_h;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_d = localP->DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for Sum: '<S248>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S242>/Output'
   */
  localDW->Output_DSTATE_g = localP->Output_InitialCondition_h;

  /* InitializeConditions for Sum: '<S4>/Add' incorporates:
   *  Delay: '<S4>/Delay One Step'
   */
  localDW->DelayOneStep_DSTATE = localP->DelayOneStep_InitialCondition;

  /* SystemInitialize for MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)' */
  localDW->doneDoubleBufferReInit_j = false;
  localDW->sfEvent_p = flightControlSystem_CALL_EVENT_a;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  flag_outport = localP->Merge_InitialOutput;

  /* SystemInitialize for Chart: '<S5>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->sfEvent_j = flightControlSystem_CALL_EVENT_a;
  localB->z = 0.0;
  localB->x = 0.0;
  localB->y = 0.0;
  localDW->is_active_c3_flightControlSystem = 0U;
  localDW->is_c3_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for MATLAB Function: '<S305>/SqrtUsedFcn' */
  localDW->doneDoubleBufferReInit_i = false;
  localDW->sfEvent_n = flightControlSystem_CALL_EVENT_a;

  /* InitializeConditions for UnitDelay: '<S448>/UD' incorporates:
   *  Sum: '<S448>/Diff'
   */
  localDW->UD_DSTATE[0] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S436>/Delay' */
  localDW->Delay_DSTATE[0] = localP->Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Integrator' */
  localDW->Integrator_DSTATE[0] =
    localP->Velocitycontroller_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l;

  /* InitializeConditions for DiscreteIntegrator: '<S107>/Integrator' */
  localDW->Integrator_DSTATE_d[0] =
    localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Filter' */
  localDW->Filter_DSTATE[0] =
    localP->Angularvelocitycontrolloop_InitialConditionForFilter;

  /* SystemInitialize for Enabled SubSystem: '<S277>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S307>/Product3' incorporates:
   *  Outport: '<S307>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S277>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S283>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S309>/Product2' incorporates:
   *  Outport: '<S309>/deltax'
   */
  localB->Product2[0] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S283>/Enabled Subsystem' */

  /* InitializeConditions for UnitDelay: '<S448>/UD' incorporates:
   *  Sum: '<S448>/Diff'
   */
  localDW->UD_DSTATE[1] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S436>/Delay' */
  localDW->Delay_DSTATE[1] = localP->Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Integrator' */
  localDW->Integrator_DSTATE[1] =
    localP->Velocitycontroller_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l;

  /* InitializeConditions for DiscreteIntegrator: '<S107>/Integrator' */
  localDW->Integrator_DSTATE_d[1] =
    localP->Angularvelocitycontrolloop_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Filter' */
  localDW->Filter_DSTATE[1] =
    localP->Angularvelocitycontrolloop_InitialConditionForFilter;

  /* SystemInitialize for Enabled SubSystem: '<S277>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S307>/Product3' incorporates:
   *  Outport: '<S307>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[1] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S277>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S283>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S309>/Product2' incorporates:
   *  Outport: '<S309>/deltax'
   */
  localB->Product2[1] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S283>/Enabled Subsystem' */

  /* SystemInitialize for MATLAB Function: '<S370>/SqrtUsedFcn' */
  flightControlSystem_SqrtUsedFcn_Init(&localDW->sf_SqrtUsedFcn_h);

  /* SystemInitialize for Enabled SubSystem: '<S341>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_n,
    &localP->MeasurementUpdate_n);

  /* End of SystemInitialize for SubSystem: '<S341>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S348>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_d,
    &localP->EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S348>/Enabled Subsystem' */

  /* SystemInitialize for MATLAB Function: '<S424>/SqrtUsedFcn' */
  flightControlSystem_SqrtUsedFcn_Init(&localDW->sf_SqrtUsedFcn_e);

  /* SystemInitialize for Enabled SubSystem: '<S395>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_j,
    &localP->MeasurementUpdate_j);

  /* End of SystemInitialize for SubSystem: '<S395>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S402>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_n,
    &localP->EnabledSubsystem_n);

  /* End of SystemInitialize for SubSystem: '<S402>/Enabled Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S429>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S433>/In1' incorporates:
   *  Outport: '<S433>/Out1'
   */
  localB->In1 = localP->Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S429>/Triggered Subsystem' */

  /* SystemInitialize for MATLAB Function: '<S508>/SqrtUsedFcn' */
  localDW->doneDoubleBufferReInit = false;
  localDW->sfEvent = flightControlSystem_CALL_EVENT_a;

  /* SystemInitialize for Enabled SubSystem: '<S479>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S510>/Product3' incorporates:
   *  Outport: '<S510>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[0] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S479>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S486>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S512>/Product2' incorporates:
   *  Outport: '<S512>/deltax'
   */
  localB->Product2_k[0] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S486>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S479>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S510>/Product3' incorporates:
   *  Outport: '<S510>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[1] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S479>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S486>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S512>/Product2' incorporates:
   *  Outport: '<S512>/deltax'
   */
  localB->Product2_k[1] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S486>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S479>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S510>/Product3' incorporates:
   *  Outport: '<S510>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[2] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S479>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S486>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S512>/Product2' incorporates:
   *  Outport: '<S512>/deltax'
   */
  localB->Product2_k[2] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S486>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S479>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S510>/Product3' incorporates:
   *  Outport: '<S510>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[3] = localP->Lykyhatkk1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S479>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S486>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S512>/Product2' incorporates:
   *  Outport: '<S512>/deltax'
   */
  localB->Product2_k[3] = localP->deltax_Y0_k;

  /* End of SystemInitialize for SubSystem: '<S486>/Enabled Subsystem' */
}

/* Start for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Start
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW,
   P_ControlSystem_flightControlSystem_T *localP)
{
  /* Start for Enabled SubSystem: '<S283>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE_l = false;

  /* End of Start for SubSystem: '<S283>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S348>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Start(&localDW->EnabledSubsystem_d);

  /* End of Start for SubSystem: '<S348>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S402>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Start(&localDW->EnabledSubsystem_n);

  /* End of Start for SubSystem: '<S402>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S486>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S486>/Enabled Subsystem' */

  /* Start for Constant: '<S5>/speed' */
  localB->speed = localP->speed_Value;

  /* Start for Enabled SubSystem: '<S277>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE_c = false;

  /* End of Start for SubSystem: '<S277>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S341>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Start(&localDW->MeasurementUpdate_n);

  /* End of Start for SubSystem: '<S341>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S395>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Start(&localDW->MeasurementUpdate_j);

  /* End of Start for SubSystem: '<S395>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S479>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S479>/MeasurementUpdate' */
}

/* Output and update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds, const
  SensorsBus *rtu_Sensors, const real_T rtu_VisionbasedData[5],
  B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW,
  P_ControlSystem_flightControlSystem_T *localP,
  ZCE_ControlSystem_flightControlSystem_T *localZCE)
{
  real32_T rtb_DeadZone_idx_0;
  real32_T rtb_DeadZone_idx_1;
  real32_T rtb_Saturation_n_0;
  real32_T rtb_Sum_d_idx_0;
  real32_T rtb_Sum_d_idx_1;
  real32_T rtb_sincos_o2_j_idx_0_tmp;
  real32_T rtb_sincos_o2_j_idx_1_tmp;
  real32_T rtb_sincos_o2_j_idx_2_tmp;
  real32_T rtb_sincos_o2_m_idx_0_tmp;
  real32_T rtb_sincos_o2_m_idx_1_tmp;
  real32_T rtb_sincos_o2_m_idx_2_tmp;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_Compare_ls;
  boolean_T rtb_Compare_o;
  boolean_T rtb_LogicalOperator_m;

  /* DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  if (localP->controlModePosVsOrient_Value &&
      (localDW->SimplyIntegrateVelocity_PrevResetState <= 0)) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] =
      localP->SimplyIntegrateVelocity_IC;
    localDW->SimplyIntegrateVelocity_DSTATE[1] =
      localP->SimplyIntegrateVelocity_IC;
  }

  /* DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' */
  localB->SimplyIntegrateVelocity[0] = localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->SimplyIntegrateVelocity[1] = localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* Gain: '<S251>/invertzaxisGain' */
  localB->invertzaxisGain = (real_T)localP->invertzaxisGain_Gain *
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;

  /* RelationalOperator: '<S258>/Compare' incorporates:
   *  Constant: '<S258>/Constant'
   *  Delay: '<S251>/Delay2'
   */
  localB->Compare = (localDW->Delay2_DSTATE > localP->outlierBelowFloor_const);

  /* Delay: '<S255>/MemoryX' incorporates:
   *  Constant: '<S255>/X0'
   *  DataTypeConversion: '<S255>/DataTypeConversionReset'
   *  Reshape: '<S255>/ReshapeX0'
   */
  localDW->icLoad = (localB->Compare || localDW->icLoad);
  if (localDW->icLoad) {
    localDW->MemoryX_DSTATE[0] = localP->X0_Value[0];
    localDW->MemoryX_DSTATE[1] = localP->X0_Value[1];
  }

  /* DataTypeConversion: '<S253>/Data Type Conversion' */
  for (localB->i = 0; localB->i < 8; localB->i++) {
    localB->DataTypeConversion_m[localB->i] = rtu_Sensors->
      SensorCalibration[localB->i];
  }

  /* End of DataTypeConversion: '<S253>/Data Type Conversion' */

  /* Sum: '<S253>/Sum2' */
  localB->DiscreteTimeIntegrator_k5 =
    rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
    localB->DataTypeConversion_m[6];

  /* DiscreteFilter: '<S256>/pressureFilter_IIR' incorporates:
   *  Gain: '<S251>/prsToAltGain'
   */
  localB->DiscreteTimeIntegrator_k5 = (((localP->prsToAltGain_Gain *
    localB->DiscreteTimeIntegrator_k5 - localDW->pressureFilter_IIR_states[0] *
    localP->pressureFilter_IIR_DenCoef[1]) - localDW->pressureFilter_IIR_states
    [1] * localP->pressureFilter_IIR_DenCoef[2]) -
    localDW->pressureFilter_IIR_states[2] * localP->pressureFilter_IIR_DenCoef[3])
    / localP->pressureFilter_IIR_DenCoef[0];
  localB->rtb_sincos_o2_idx_1 = ((localP->pressureFilter_IIR_NumCoef[0] *
    localB->DiscreteTimeIntegrator_k5 + localDW->pressureFilter_IIR_states[0] *
    localP->pressureFilter_IIR_NumCoef[1]) + localDW->pressureFilter_IIR_states
    [1] * localP->pressureFilter_IIR_NumCoef[2]) +
    localDW->pressureFilter_IIR_states[2] * localP->pressureFilter_IIR_NumCoef[3];

  /* DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localB->sonarFilter_IIR_tmp = (((localB->invertzaxisGain -
    localDW->sonarFilter_IIR_states[0] * localP->sonarFilter_IIR_DenCoef[1]) -
    localDW->sonarFilter_IIR_states[1] * localP->sonarFilter_IIR_DenCoef[2]) -
    localDW->sonarFilter_IIR_states[2] * localP->sonarFilter_IIR_DenCoef[3]) /
    localP->sonarFilter_IIR_DenCoef[0];

  /* Saturate: '<S256>/SaturationSonar' */
  if (localB->invertzaxisGain > -flightControlSystem_P.Sensors.altSensorMin) {
    localB->rtb_Add_a_idx_1 = -flightControlSystem_P.Sensors.altSensorMin;
  } else if (localB->invertzaxisGain < localP->SaturationSonar_LowerSat) {
    localB->rtb_Add_a_idx_1 = localP->SaturationSonar_LowerSat;
  } else {
    localB->rtb_Add_a_idx_1 = localB->invertzaxisGain;
  }

  /* Logic: '<S256>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S256>/Absestdiff'
   *  Abs: '<S256>/Absestdiff1'
   *  Abs: '<S256>/Absestdiff2'
   *  Constant: '<S310>/Constant'
   *  Constant: '<S311>/Constant'
   *  Constant: '<S312>/Constant'
   *  Constant: '<S313>/Constant'
   *  Delay: '<S251>/Delay2'
   *  DiscreteFilter: '<S256>/pressureFilter_IIR'
   *  DiscreteFilter: '<S256>/sonarFilter_IIR'
   *  Logic: '<S256>/NOT'
   *  Logic: '<S256>/findingoutliers'
   *  Logic: '<S256>/newupdateneeded'
   *  RelationalOperator: '<S310>/Compare'
   *  RelationalOperator: '<S311>/Compare'
   *  RelationalOperator: '<S312>/Compare'
   *  RelationalOperator: '<S313>/Compare'
   *  Saturate: '<S256>/SaturationSonar'
   *  Sum: '<S256>/Add'
   *  Sum: '<S256>/Add1'
   *  Sum: '<S256>/Add2'
   */
  localB->nicemeasurementornewupdateneeded = ((fabs(localDW->Delay2_DSTATE -
    localB->rtb_Add_a_idx_1) <= localP->outlierJump_const) &&
    (localB->invertzaxisGain < -flightControlSystem_P.Sensors.altSensorMin) &&
    ((!(fabs(localB->rtb_sincos_o2_idx_1 - localDW->Delay2_DSTATE) >=
        localP->currentEstimateVeryOffFromPressure_const)) || (!(fabs
    ((((localP->sonarFilter_IIR_NumCoef[0] * localB->sonarFilter_IIR_tmp +
        localDW->sonarFilter_IIR_states[0] * localP->sonarFilter_IIR_NumCoef[1])
       + localDW->sonarFilter_IIR_states[1] * localP->sonarFilter_IIR_NumCoef[2])
      + localDW->sonarFilter_IIR_states[2] * localP->sonarFilter_IIR_NumCoef[3])
     - localDW->Delay2_DSTATE) >= localP->currentStateVeryOffsonarflt_const))));

  /* Outputs for Enabled SubSystem: '<S283>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S309>/Enable'
   */
  /* DataTypeConversion: '<S255>/DataTypeConversionEnable' */
  if (localB->nicemeasurementornewupdateneeded) {
    localDW->EnabledSubsystem_MODE_l = true;

    /* Sum: '<S309>/Add1' incorporates:
     *  Constant: '<S255>/C'
     *  Delay: '<S255>/MemoryX'
     *  Product: '<S309>/Product'
     *  Reshape: '<S255>/Reshapey'
     */
    localB->Sum_k = localB->invertzaxisGain - (localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]);

    /* Product: '<S309>/Product2' incorporates:
     *  Constant: '<S259>/KalmanGainM'
     *  DataTypeConversion: '<S300>/Conversion'
     */
    localB->Product2[0] = localP->KalmanGainM_Value[0] * localB->Sum_k;
    localB->Product2[1] = localP->KalmanGainM_Value[1] * localB->Sum_k;
    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC_c);
  } else if (localDW->EnabledSubsystem_MODE_l) {
    /* Disable for Product: '<S309>/Product2' incorporates:
     *  Outport: '<S309>/deltax'
     */
    localB->Product2[0] = localP->deltax_Y0;
    localB->Product2[1] = localP->deltax_Y0;
    localDW->EnabledSubsystem_MODE_l = false;
  }

  /* End of Outputs for SubSystem: '<S283>/Enabled Subsystem' */

  /* Reshape: '<S255>/Reshapexhat' incorporates:
   *  Delay: '<S255>/MemoryX'
   *  Sum: '<S283>/Add'
   */
  localDW->Delay2_DSTATE = localB->Product2[0] + localDW->MemoryX_DSTATE[0];

  /* DataTypeConversion: '<S365>/Conversion' incorporates:
   *  Constant: '<S322>/KalmanGainM'
   */
  localB->Conversion_g[0] = (real32_T)localP->KalmanGainM_Value_l[0];

  /* Sum: '<S283>/Add' incorporates:
   *  Delay: '<S255>/MemoryX'
   */
  localB->rtb_Add_a_idx_1 = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* DataTypeConversion: '<S365>/Conversion' incorporates:
   *  Constant: '<S322>/KalmanGainM'
   */
  localB->Conversion_g[1] = (real32_T)localP->KalmanGainM_Value_l[1];

  /* DataTypeConversion: '<S251>/Data Type Conversion' incorporates:
   *  Reshape: '<S255>/Reshapexhat'
   */
  localB->DataTypeConversion = (real32_T)localDW->Delay2_DSTATE;

  /* Bias: '<S253>/Assuming that the  preflight calibration was done at level orientation' */
  for (localB->i = 0; localB->i < 6; localB->i++) {
    localB->Sum1_p[localB->i] = localB->DataTypeConversion_m[localB->i] +
      localP->
      Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[localB->i];
  }

  /* End of Bias: '<S253>/Assuming that the  preflight calibration was done at level orientation' */

  /* Sum: '<S253>/Sum1' */
  localB->inverseIMU_gain[0] = rtu_Sensors->HALSensors.HAL_acc_SI.x -
    localB->Sum1_p[0];
  localB->inverseIMU_gain[1] = rtu_Sensors->HALSensors.HAL_acc_SI.y -
    localB->Sum1_p[1];
  localB->inverseIMU_gain[2] = rtu_Sensors->HALSensors.HAL_acc_SI.z -
    localB->Sum1_p[2];
  localB->inverseIMU_gain[3] = rtu_Sensors->HALSensors.HAL_gyro_SI.x -
    localB->Sum1_p[3];
  localB->inverseIMU_gain[4] = rtu_Sensors->HALSensors.HAL_gyro_SI.y -
    localB->Sum1_p[4];
  localB->inverseIMU_gain[5] = rtu_Sensors->HALSensors.HAL_gyro_SI.z -
    localB->Sum1_p[5];
  for (localB->i = 0; localB->i < 6; localB->i++) {
    /* Gain: '<S253>/inverseIMU_gain' incorporates:
     *  Sum: '<S253>/Sum1'
     */
    localB->inverseIMU_gain[localB->i] *= localP->inverseIMU_gain_Gain[localB->i];
  }

  /* DiscreteFir: '<S253>/FIR_IMUaccel' */
  localB->rtb_sincos_o2_idx_0 = localB->inverseIMU_gain[0] *
    localP->FIR_IMUaccel_Coefficients[0];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->rtb_sincos_o2_idx_0 += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->rtb_sincos_o2_idx_0 += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[0] = localB->rtb_sincos_o2_idx_0;
  localB->rtb_sincos_o2_idx_0 = localP->FIR_IMUaccel_Coefficients[0] *
    localB->inverseIMU_gain[1];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->rtb_sincos_o2_idx_0 += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->rtb_sincos_o2_idx_0 += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[1] = localB->rtb_sincos_o2_idx_0;
  localB->rtb_sincos_o2_idx_0 = localP->FIR_IMUaccel_Coefficients[0] *
    localB->inverseIMU_gain[2];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->rtb_sincos_o2_idx_0 += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->rtb_sincos_o2_idx_0 += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[2] = localB->rtb_sincos_o2_idx_0;

  /* Gain: '<S317>/Gain2' */
  localB->Abs2 = localP->Gain2_Gain * localB->FIR_IMUaccel[0];

  /* Trigonometry: '<S317>/Trigonometric Function1' */
  if (localB->Abs2 > 1.0F) {
    localB->Abs2 = 1.0F;
  } else if (localB->Abs2 < -1.0F) {
    localB->Abs2 = -1.0F;
  }

  /* Trigonometry: '<S317>/Trigonometric Function1' */
  localB->TrigonometricFunction1 = (real32_T)asin(localB->Abs2);

  /* Delay: '<S321>/MemoryX' incorporates:
   *  Constant: '<S321>/X0'
   *  Reshape: '<S321>/ReshapeX0'
   */
  if (localDW->icLoad_p) {
    localDW->MemoryX_DSTATE_g[0] = localP->X0_Value_i[0];
    localDW->MemoryX_DSTATE_g[1] = localP->X0_Value_i[1];
  }

  /* Math: '<S320>/Math Function' incorporates:
   *  Constant: '<S320>/Constant'
   *  DataTypeConversion: '<S320>/Data Type Conversion2'
   *  DiscreteFir: '<S253>/FIR_IMUaccel'
   */
  localB->Abs2 = (real32_T)floor(localP->Constant_Value_h);
  if ((localB->FIR_IMUaccel[0] < 0.0F) && (localP->Constant_Value_h >
       localB->Abs2)) {
    localB->Abs3 = -rt_powf_snf(-localB->FIR_IMUaccel[0],
      localP->Constant_Value_h);
  } else {
    localB->Abs3 = rt_powf_snf(localB->FIR_IMUaccel[0], localP->Constant_Value_h);
  }

  if ((localB->FIR_IMUaccel[1] < 0.0F) && (localP->Constant_Value_h >
       localB->Abs2)) {
    localB->Abs4 = -rt_powf_snf(-localB->FIR_IMUaccel[1],
      localP->Constant_Value_h);
  } else {
    localB->Abs4 = rt_powf_snf(localB->FIR_IMUaccel[1], localP->Constant_Value_h);
  }

  if ((localB->rtb_sincos_o2_idx_0 < 0.0F) && (localP->Constant_Value_h >
       localB->Abs2)) {
    localB->Gain_m = -rt_powf_snf(-localB->rtb_sincos_o2_idx_0,
      localP->Constant_Value_h);
  } else {
    localB->Gain_m = rt_powf_snf(localB->rtb_sincos_o2_idx_0,
      localP->Constant_Value_h);
  }

  /* Sqrt: '<S320>/Sqrt' incorporates:
   *  Math: '<S320>/Math Function'
   *  Sum: '<S320>/Sum of Elements'
   */
  localB->Abs2 = (real32_T)sqrt((localB->Abs3 + localB->Abs4) + localB->Gain_m);

  /* Logic: '<S252>/Logical Operator' incorporates:
   *  Constant: '<S315>/Constant'
   *  Constant: '<S316>/Constant'
   *  RelationalOperator: '<S315>/Compare'
   *  RelationalOperator: '<S316>/Compare'
   */
  localB->LogicalOperator = (int16_T)((localB->Abs2 >
    localP->CompareToConstant_const) && (localB->Abs2 <
    localP->CompareToConstant1_const));

  /* Outputs for Enabled SubSystem: '<S348>/Enabled Subsystem' */
  /* DataTypeConversion: '<S321>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S321>/C'
   *  Delay: '<S321>/MemoryX'
   *  Reshape: '<S321>/Reshapey'
   */
  flightControlSystem_EnabledSubsystem((localB->LogicalOperator != 0),
    localB->Conversion_g, localP->C_Value_h, localB->TrigonometricFunction1,
    localDW->MemoryX_DSTATE_g, &localB->EnabledSubsystem_d,
    &localDW->EnabledSubsystem_d, &localP->EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S348>/Enabled Subsystem' */

  /* DataTypeConversion: '<S419>/Conversion' incorporates:
   *  Constant: '<S376>/KalmanGainM'
   */
  localB->Conversion_g[0] = (real32_T)localP->KalmanGainM_Value_a[0];
  localB->Conversion_g[1] = (real32_T)localP->KalmanGainM_Value_a[1];

  /* Trigonometry: '<S318>/Trigonometric Function' incorporates:
   *  DiscreteFir: '<S253>/FIR_IMUaccel'
   *  Product: '<S318>/Divide'
   */
  localB->TrigonometricFunction = (real32_T)atan(localB->FIR_IMUaccel[1] /
    localB->rtb_sincos_o2_idx_0);

  /* Delay: '<S375>/MemoryX' incorporates:
   *  Constant: '<S375>/X0'
   *  Reshape: '<S375>/ReshapeX0'
   */
  if (localDW->icLoad_k) {
    localDW->MemoryX_DSTATE_m[0] = localP->X0_Value_iy[0];
    localDW->MemoryX_DSTATE_m[1] = localP->X0_Value_iy[1];
  }

  /* Outputs for Enabled SubSystem: '<S402>/Enabled Subsystem' */
  /* DataTypeConversion: '<S375>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S375>/C'
   *  Delay: '<S375>/MemoryX'
   *  Reshape: '<S375>/Reshapey'
   */
  flightControlSystem_EnabledSubsystem((localB->LogicalOperator != 0),
    localB->Conversion_g, localP->C_Value_i, localB->TrigonometricFunction,
    localDW->MemoryX_DSTATE_m, &localB->EnabledSubsystem_n,
    &localDW->EnabledSubsystem_n, &localP->EnabledSubsystem_n);

  /* End of Outputs for SubSystem: '<S402>/Enabled Subsystem' */

  /* DataTypeConversion: '<S252>/Data Type Conversion3' incorporates:
   *  Delay: '<S321>/MemoryX'
   *  Delay: '<S375>/MemoryX'
   *  DiscreteIntegrator: '<S319>/Discrete-Time Integrator'
   *  Sum: '<S348>/Add'
   *  Sum: '<S402>/Add'
   */
  localB->DataTypeConversion3[0] = localDW->DiscreteTimeIntegrator_DSTATE;
  localB->DataTypeConversion3[1] = localB->EnabledSubsystem_d.Product2[0] +
    localDW->MemoryX_DSTATE_g[0];
  localB->DataTypeConversion3[2] = localB->EnabledSubsystem_n.Product2[0] +
    localDW->MemoryX_DSTATE_m[0];

  /* Switch: '<S442>/Switch' incorporates:
   *  Constant: '<S513>/Constant'
   *  Gain: '<S442>/opticalFlowErrorCorrect'
   *  RelationalOperator: '<S513>/Compare'
   *  UnitDelay: '<S514>/Output'
   */
  if (localDW->Output_DSTATE < localP->CompareToConstant_const_h) {
    localB->u_l[0] = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    localB->u_l[1] = rtu_Sensors->VisionSensors.opticalFlow_data[1];
    localB->u_l[2] = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    /* Gain: '<S442>/Gain' */
    localB->Gain_m = localP->Gain_Gain_p * localB->DataTypeConversion;

    /* Product: '<S442>/ ' */
    localB->LPFFcutoff40Hz_tmp = rtu_Sensors->VisionSensors.opticalFlow_data[0] *
      localB->Gain_m;
    localB->u_l[0] = localP->opticalFlowErrorCorrect_Gain *
      localB->LPFFcutoff40Hz_tmp;

    /* Product: '<S442>/ ' incorporates:
     *  Gain: '<S442>/opticalFlowErrorCorrect'
     */
    localB->LPFFcutoff40Hz_tmp = rtu_Sensors->VisionSensors.opticalFlow_data[1] *
      localB->Gain_m;
    localB->u_l[1] = localP->opticalFlowErrorCorrect_Gain *
      localB->LPFFcutoff40Hz_tmp;

    /* Product: '<S442>/ ' incorporates:
     *  Gain: '<S442>/opticalFlowErrorCorrect'
     */
    localB->LPFFcutoff40Hz_tmp = rtu_Sensors->VisionSensors.opticalFlow_data[2] *
      localB->Gain_m;
    localB->u_l[2] = localP->opticalFlowErrorCorrect_Gain *
      localB->LPFFcutoff40Hz_tmp;
  }

  /* End of Switch: '<S442>/Switch' */

  /* Abs: '<S439>/Abs' */
  localB->Abs1 = (real32_T)fabs(localB->DataTypeConversion);

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localB->Gain_m = (localB->inverseIMU_gain[3] - localP->
                    LPFFcutoff40Hz1_DenCoef[1] * localDW->LPFFcutoff40Hz1_states)
    / localP->LPFFcutoff40Hz1_DenCoef[0];

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localB->p = localP->LPFFcutoff40Hz1_NumCoef[0] * localB->Gain_m +
    localP->LPFFcutoff40Hz1_NumCoef[1] * localDW->LPFFcutoff40Hz1_states;

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localB->LPFFcutoff40Hz_tmp = (localB->inverseIMU_gain[4] -
    localP->LPFFcutoff40Hz_DenCoef[1] * localDW->LPFFcutoff40Hz_states) /
    localP->LPFFcutoff40Hz_DenCoef[0];

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localB->q = localP->LPFFcutoff40Hz_NumCoef[0] * localB->LPFFcutoff40Hz_tmp +
    localP->LPFFcutoff40Hz_NumCoef[1] * localDW->LPFFcutoff40Hz_states;

  /* DiscreteFilter: '<S253>/IIR_IMUgyro_r' */
  rtb_Sum_d_idx_0 = localB->inverseIMU_gain[5];
  for (localB->j = 0; localB->j < 5; localB->j++) {
    rtb_Sum_d_idx_0 -= localP->IIR_IMUgyro_r_DenCoef[localB->j + 1] *
      localDW->IIR_IMUgyro_r_states[localB->j];
  }

  localB->IIR_IMUgyro_r_tmp = rtb_Sum_d_idx_0 / localP->IIR_IMUgyro_r_DenCoef[0];
  localB->numAccum = localP->IIR_IMUgyro_r_NumCoef[0] *
    localB->IIR_IMUgyro_r_tmp;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->numAccum += localP->IIR_IMUgyro_r_NumCoef[localB->j + 1] *
      localDW->IIR_IMUgyro_r_states[localB->j];
  }

  /* RelationalOperator: '<S431>/Compare' incorporates:
   *  Constant: '<S431>/Constant'
   *  UnitDelay: '<S432>/Output'
   */
  rtb_Compare_ls = (localDW->Output_DSTATE_i ==
                    localP->CompareToConstant_const_l);

  /* Outputs for Triggered SubSystem: '<S429>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S433>/Trigger'
   */
  if (((localZCE->TriggeredSubsystem_Trig_ZCE == POS_ZCSIG) != (int32_T)
       rtb_Compare_ls) && (localZCE->TriggeredSubsystem_Trig_ZCE !=
       UNINITIALIZED_ZCSIG)) {
    /* SignalConversion generated from: '<S433>/In1' */
    localB->In1 = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature;
    localDW->TriggeredSubsystem_SubsysRanBC = 4;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE = rtb_Compare_ls;

  /* End of Outputs for SubSystem: '<S429>/Triggered Subsystem' */

  /* ManualSwitch: '<S429>/Disable temperature compensation' incorporates:
   *  Constant: '<S429>/Constant'
   *  Gain: '<S429>/Gain'
   */
  if (localP->Disabletemperaturecompensation_CurrentSetting == 1) {
    /* Sum: '<S429>/Subtract' */
    localB->Subtract_c = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature -
      localB->In1;
    localB->Sum_k = localP->Gain_Gain_k * localB->Subtract_c;
  } else {
    localB->Sum_k = localP->Constant_Value;
  }

  /* End of ManualSwitch: '<S429>/Disable temperature compensation' */

  /* Sum: '<S429>/Subtract1' incorporates:
   *  DataTypeConversion: '<S429>/Data Type Conversion1'
   *  DiscreteFilter: '<S253>/IIR_IMUgyro_r'
   */
  localB->Subtract_c = localB->numAccum - (real32_T)localB->Sum_k;

  /* Sum: '<S252>/Subtract' incorporates:
   *  Constant: '<S319>/Constant'
   *  Delay: '<S321>/MemoryX'
   *  Delay: '<S375>/MemoryX'
   *  Sum: '<S348>/Add'
   *  Sum: '<S402>/Add'
   */
  localB->Subtract[0] = localB->p - (localB->EnabledSubsystem_n.Product2[1] +
    localDW->MemoryX_DSTATE_m[1]);
  localB->Subtract[1] = localB->q - (localB->EnabledSubsystem_d.Product2[1] +
    localDW->MemoryX_DSTATE_g[1]);
  localB->Subtract[2] = localB->Subtract_c - localP->Constant_Value_j;

  /* Sum: '<S436>/angular velocity compensation' incorporates:
   *  Gain: '<S439>/Gain1'
   *  Product: '<S439>/prod'
   */
  localB->angularvelocitycompensation[0] = localB->Abs1 * localB->Subtract[1] *
    localP->Gain1_Gain + localB->u_l[0];
  localB->angularvelocitycompensation[1] = localB->Abs1 * localB->Subtract[0] +
    localB->u_l[1];

  /* Delay: '<S441>/MemoryX' incorporates:
   *  Constant: '<S441>/X0'
   *  Reshape: '<S441>/ReshapeX0'
   */
  if (localDW->icLoad_o) {
    localDW->MemoryX_DSTATE_l[0] = localP->X0_Value_c[0];
    localDW->MemoryX_DSTATE_l[1] = localP->X0_Value_c[1];
    localDW->MemoryX_DSTATE_l[2] = localP->X0_Value_c[2];
    localDW->MemoryX_DSTATE_l[3] = localP->X0_Value_c[3];
  }

  /* SignalConversion generated from: '<S440>/IIRgyroz' */
  localB->DataTypeConversion_o[0] = localB->p;
  localB->DataTypeConversion_o[1] = localB->q;
  for (localB->i = 0; localB->i < 2; localB->i++) {
    /* DiscreteFilter: '<S440>/IIRgyroz' */
    localB->memOffset = localB->i * 5;
    rtb_Sum_d_idx_0 = localB->DataTypeConversion_o[localB->i];
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_Sum_d_idx_0 -= localP->IIRgyroz_DenCoef[localB->j + 1] *
        localDW->IIRgyroz_states[localB->memOffset + localB->j];
    }

    localB->Abs1 = rtb_Sum_d_idx_0 / localP->IIRgyroz_DenCoef[0];
    localDW->IIRgyroz_tmp[localB->i] = localB->Abs1;
    localB->numAccum = localP->IIRgyroz_NumCoef[0] * localB->Abs1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      localB->numAccum += localP->IIRgyroz_NumCoef[localB->j + 1] *
        localDW->IIRgyroz_states[localB->memOffset + localB->j];
    }

    /* SampleTimeMath: '<S448>/TSamp' incorporates:
     *  DiscreteFilter: '<S440>/IIRgyroz'
     *
     * About '<S448>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *   */
    localB->Abs1 = localB->numAccum * localP->TSamp_WtEt;
    localB->DataTypeConversion_o[localB->i] = localB->Abs1;

    /* Sum: '<S448>/Diff' incorporates:
     *  UnitDelay: '<S448>/UD'
     */
    localDW->UD_DSTATE[localB->i] = localB->Abs1 - localDW->UD_DSTATE[localB->i];

    /* Sum: '<S440>/Add' incorporates:
     *  Delay: '<S436>/Delay'
     */
    localB->Conversion_g[localB->i] = localB->u_l[localB->i] -
      localDW->Delay_DSTATE[localB->i];
  }

  /* Abs: '<S440>/Abs' incorporates:
   *  Abs: '<S440>/Abs4'
   */
  localB->Abs1 = (real32_T)fabs(localB->p);

  /* Abs: '<S440>/Abs1' incorporates:
   *  Abs: '<S440>/Abs5'
   */
  rtb_Sum_d_idx_0 = (real32_T)fabs(localB->q);

  /* Logic: '<S440>/Logical Operator3' incorporates:
   *  Abs: '<S440>/Abs'
   *  Abs: '<S440>/Abs1'
   *  Abs: '<S440>/Abs2'
   *  Abs: '<S440>/Abs3'
   *  Abs: '<S440>/Abs6'
   *  Abs: '<S440>/Abs7'
   *  Abs: '<S440>/Abs8'
   *  Abs: '<S440>/Abs9'
   *  Constant: '<S449>/Constant'
   *  Constant: '<S450>/Constant'
   *  Constant: '<S451>/Constant'
   *  Constant: '<S452>/Constant'
   *  Constant: '<S453>/Constant'
   *  Constant: '<S454>/Constant'
   *  Constant: '<S455>/Constant'
   *  Constant: '<S456>/Constant'
   *  Constant: '<S457>/Constant'
   *  Constant: '<S458>/Constant'
   *  Constant: '<S459>/Constant'
   *  Logic: '<S440>/Logical Operator'
   *  Logic: '<S440>/Logical Operator1'
   *  Logic: '<S440>/Logical Operator2'
   *  RelationalOperator: '<S449>/Compare'
   *  RelationalOperator: '<S450>/Compare'
   *  RelationalOperator: '<S451>/Compare'
   *  RelationalOperator: '<S452>/Compare'
   *  RelationalOperator: '<S453>/Compare'
   *  RelationalOperator: '<S454>/Compare'
   *  RelationalOperator: '<S455>/Compare'
   *  RelationalOperator: '<S456>/Compare'
   *  RelationalOperator: '<S457>/Compare'
   *  RelationalOperator: '<S458>/Compare'
   *  RelationalOperator: '<S459>/Compare'
   */
  localB->LogicalOperator3 = (((((real32_T)fabs(localB->DataTypeConversion3[1]) <=
    localP->maxp_const) && ((real32_T)fabs(localB->DataTypeConversion3[2]) <=
    localP->maxq_const) && (localB->Abs1 <= localP->maxw1_const) &&
    (rtb_Sum_d_idx_0 <= localP->maxw2_const) && ((real32_T)fabs
    (localDW->UD_DSTATE[0]) <= localP->maxdw1_const) && ((real32_T)fabs
    (localDW->UD_DSTATE[1]) <= localP->maxdw2_const)) || ((localB->Abs1 <=
    localP->maxp2_const) && (rtb_Sum_d_idx_0 <= localP->maxq2_const))) &&
    ((real32_T)fabs(localB->Conversion_g[0]) <= localP->maxw3_const) &&
    ((real32_T)fabs(localB->Conversion_g[1]) <= localP->maxw4_const) &&
    (localB->DataTypeConversion <= localP->minHeightforOF_const));

  /* Outputs for Enabled SubSystem: '<S486>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S512>/Enable'
   */
  /* DataTypeConversion: '<S441>/DataTypeConversionEnable' */
  if (localB->LogicalOperator3) {
    localDW->EnabledSubsystem_MODE = true;

    /* Delay: '<S441>/MemoryX' incorporates:
     *  Constant: '<S441>/C'
     *  Product: '<S512>/Product'
     */
    localB->Abs3 = localDW->MemoryX_DSTATE_l[1];
    localB->Abs4 = localDW->MemoryX_DSTATE_l[0];
    localB->Abs2 = localDW->MemoryX_DSTATE_l[2];
    localB->Abs5 = localDW->MemoryX_DSTATE_l[3];

    /* Sum: '<S512>/Add1' incorporates:
     *  Constant: '<S441>/C'
     *  Delay: '<S441>/MemoryX'
     *  Product: '<S512>/Product'
     *  Reshape: '<S441>/Reshapey'
     */
    for (localB->i = 0; localB->i < 2; localB->i++) {
      localB->fv1[localB->i] = localB->angularvelocitycompensation[localB->i] -
        (((localP->C_Value_i2[localB->i + 2] * localB->Abs3 + localP->
           C_Value_i2[localB->i] * localB->Abs4) + localP->C_Value_i2[localB->i
          + 4] * localB->Abs2) + localP->C_Value_i2[localB->i + 6] *
         localB->Abs5);
    }

    /* End of Sum: '<S512>/Add1' */

    /* Product: '<S512>/Product2' incorporates:
     *  Constant: '<S460>/KalmanGainM'
     *  DataTypeConversion: '<S503>/Conversion'
     */
    localB->Abs3 = localB->fv1[1];
    localB->Abs4 = localB->fv1[0];
    for (localB->i = 0; localB->i < 4; localB->i++) {
      /* Product: '<S512>/Product2' incorporates:
       *  Constant: '<S460>/KalmanGainM'
       *  DataTypeConversion: '<S503>/Conversion'
       */
      localB->Product2_k[localB->i] = (real32_T)localP->
        KalmanGainM_Value_i[localB->i + 4] * localB->Abs3 + (real32_T)
        localP->KalmanGainM_Value_i[localB->i] * localB->Abs4;
    }

    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
  } else if (localDW->EnabledSubsystem_MODE) {
    /* Disable for Product: '<S512>/Product2' incorporates:
     *  Outport: '<S512>/deltax'
     */
    localB->Product2_k[0] = localP->deltax_Y0_k;
    localB->Product2_k[1] = localP->deltax_Y0_k;
    localB->Product2_k[2] = localP->deltax_Y0_k;
    localB->Product2_k[3] = localP->deltax_Y0_k;
    localDW->EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S486>/Enabled Subsystem' */

  /* Reshape: '<S441>/Reshapexhat' incorporates:
   *  Delay: '<S441>/MemoryX'
   *  Sum: '<S486>/Add'
   */
  localB->Reshapexhat[0] = localB->Product2_k[0] + localDW->MemoryX_DSTATE_l[0];
  localB->Reshapexhat[1] = localB->Product2_k[1] + localDW->MemoryX_DSTATE_l[1];
  localB->Reshapexhat[2] = localB->Product2_k[2] + localDW->MemoryX_DSTATE_l[2];
  localB->Reshapexhat[3] = localB->Product2_k[3] + localDW->MemoryX_DSTATE_l[3];

  /* Trigonometry: '<S257>/sincos' incorporates:
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   *  Trigonometry: '<S444>/sincos'
   *  Trigonometry: '<S517>/sincos'
   */
  rtb_sincos_o2_m_idx_0_tmp = (real32_T)sin(localB->DataTypeConversion3[0]);
  rtb_sincos_o2_j_idx_0_tmp = (real32_T)cos(localB->DataTypeConversion3[0]);
  rtb_sincos_o2_m_idx_1_tmp = (real32_T)sin(localB->DataTypeConversion3[1]);
  rtb_sincos_o2_j_idx_1_tmp = (real32_T)cos(localB->DataTypeConversion3[1]);
  rtb_sincos_o2_m_idx_2_tmp = (real32_T)sin(localB->DataTypeConversion3[2]);
  rtb_sincos_o2_j_idx_2_tmp = (real32_T)cos(localB->DataTypeConversion3[2]);

  /* Fcn: '<S257>/Fcn11' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[0] = rtb_sincos_o2_j_idx_0_tmp *
    rtb_sincos_o2_j_idx_1_tmp;

  /* Fcn: '<S257>/Fcn21' incorporates:
   *  Fcn: '<S257>/Fcn22'
   *  Trigonometry: '<S257>/sincos'
   */
  localB->Abs3 = rtb_sincos_o2_m_idx_1_tmp * rtb_sincos_o2_m_idx_2_tmp;
  localB->VectorConcatenate[1] = localB->Abs3 * rtb_sincos_o2_j_idx_0_tmp -
    rtb_sincos_o2_m_idx_0_tmp * rtb_sincos_o2_j_idx_2_tmp;

  /* Fcn: '<S257>/Fcn31' incorporates:
   *  Fcn: '<S257>/Fcn32'
   *  Trigonometry: '<S257>/sincos'
   */
  localB->Abs4 = rtb_sincos_o2_m_idx_1_tmp * rtb_sincos_o2_j_idx_2_tmp;
  localB->VectorConcatenate[2] = localB->Abs4 * rtb_sincos_o2_j_idx_0_tmp +
    rtb_sincos_o2_m_idx_0_tmp * rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S257>/Fcn12' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[3] = rtb_sincos_o2_m_idx_0_tmp *
    rtb_sincos_o2_j_idx_1_tmp;

  /* Fcn: '<S257>/Fcn22' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[4] = localB->Abs3 * rtb_sincos_o2_m_idx_0_tmp +
    rtb_sincos_o2_j_idx_0_tmp * rtb_sincos_o2_j_idx_2_tmp;

  /* Fcn: '<S257>/Fcn32' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[5] = localB->Abs4 * rtb_sincos_o2_m_idx_0_tmp -
    rtb_sincos_o2_j_idx_0_tmp * rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S257>/Fcn13' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[6] = -rtb_sincos_o2_m_idx_1_tmp;

  /* Fcn: '<S257>/Fcn23' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[7] = rtb_sincos_o2_j_idx_1_tmp *
    rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S257>/Fcn33' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[8] = rtb_sincos_o2_j_idx_1_tmp *
    rtb_sincos_o2_j_idx_2_tmp;

  /* SignalConversion generated from: '<S251>/Product1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localB->Sum_k = localDW->Delay1_DSTATE[0];
  localB->unnamed_idx_1 = localDW->Delay1_DSTATE[1];

  /* Product: '<S251>/Product1' incorporates:
   *  Reshape: '<S255>/Reshapexhat'
   *  Reshape: '<S314>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S251>/Product1'
   */
  for (localB->i = 0; localB->i < 3; localB->i++) {
    localB->rtb_VectorConcatenate_c[localB->i] = (localB->
      VectorConcatenate[localB->i + 3] * localB->unnamed_idx_1 +
      localB->VectorConcatenate[localB->i] * localB->Sum_k) +
      localB->VectorConcatenate[localB->i + 6] * localB->rtb_Add_a_idx_1;
  }

  /* End of Product: '<S251>/Product1' */

  /* DataTypeConversion: '<S251>/Data Type Conversion2' */
  localB->DataTypeConversion2 = (real32_T)localB->rtb_VectorConcatenate_c[2];

  /* SignalConversion generated from: '<S1>/To Workspace' */
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localB->SimplyIntegrateVelocity[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localB->SimplyIntegrateVelocity[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[2] =
    localB->DataTypeConversion;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] =
    localB->DataTypeConversion3[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[4] =
    localB->DataTypeConversion3[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[5] =
    localB->DataTypeConversion3[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Reshapexhat[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Reshapexhat[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] =
    localB->DataTypeConversion2;
  localB->TmpSignalConversionAtToWorkspaceInport1[9] = localB->Subtract[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[10] = localB->Subtract[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[11] = localB->Subtract[2];

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspaceInport1[0]);
  }

  /* BusAssignment: '<S1>/Control Mode Update' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   */
  localB->rtb_sincos_o2_j_idx_0 = rtu_ReferenceValueServerCmds->orient_ref[0];
  localB->rtb_sincos_o2_j_idx_1 = rtu_ReferenceValueServerCmds->orient_ref[1];
  localB->rtb_sincos_o2_j_idx_2 = rtu_ReferenceValueServerCmds->orient_ref[2];

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_ls = (localDW->Output_DSTATE_a < localP->CompareToConstant_const_c);

  /* Sum: '<S15>/FixPt Sum1' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  UnitDelay: '<S14>/Output'
   */
  localDW->Output_DSTATE_a += localP->FixPtConstant_Value_g;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if ((!rtb_Compare_ls) && (localDW->DiscreteTimeIntegrator_PrevResetState == 1))
  {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_IC_h;
  }

  /* Constant: '<S5>/speed' */
  localB->speed = localP->speed_Value;

  /* Chart: '<S5>/Chart' */
  if (localDW->temporalCounter_i1 < 1023) {
    localDW->temporalCounter_i1++;
  }

  localDW->sfEvent_j = flightControlSystem_CALL_EVENT_a;
  if (localDW->is_active_c3_flightControlSystem == 0) {
    localDW->is_active_c3_flightControlSystem = 1U;
    localDW->temporalCounter_i1 = 0U;
    localDW->is_c3_flightControlSystem = flightControlSystem_IN_Hover;
  } else {
    switch (localDW->is_c3_flightControlSystem) {
     case flightControlSystem_IN_Circle2:
      if ((rtu_VisionbasedData[3] > -0.005) && (rtu_VisionbasedData[3] < 0.005) &&
          ((rtu_VisionbasedData[2] > -0.005) && (rtu_VisionbasedData[2] < 0.005))
          && (localDW->temporalCounter_i1 >= 600)) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_land3;
      } else {
        localB->x -= rtu_VisionbasedData[2] * localB->speed * 0.003;
        localB->y -= rtu_VisionbasedData[3] * localB->speed * 0.003;
        localB->z = -1.1;
      }
      break;

     case flightControlSystem_IN_Hover:
      if (localDW->temporalCounter_i1 >= 1000) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Line_track;
      } else {
        localB->z = -1.1;
        localB->x = 0.0;
        localB->y = 0.0;
      }
      break;

     case flightControlSystem_IN_Line_track:
      if ((localDW->temporalCounter_i1 >= 600) && (rtu_VisionbasedData[4] != 0.0))
      {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circle2;
      } else {
        localB->x += rtu_VisionbasedData[0] * localB->speed * 0.003;
        localB->y += rtu_VisionbasedData[1] * localB->speed * 0.003;
        localB->z = -1.1;
      }
      break;

     default:
      /* case IN_land3: */
      localB->z = 0.0;
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Sum: '<S7>/Sum2' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  localB->Abs1 = (real32_T)localB->z - localB->DataTypeConversion;

  /* MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)' */
  localDW->sfEvent_p = flightControlSystem_CALL_EVENT_a;

  /* Sum: '<S10>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  localB->Abs3 = (real32_T)localB->x - localB->SimplyIntegrateVelocity[0];
  localB->Abs2 = (real32_T)localB->y - localB->SimplyIntegrateVelocity[1];

  /* Saturate: '<S169>/Saturation' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  localB->Abs4 = (rtb_sincos_o2_j_idx_0_tmp * localB->Abs3 +
                  rtb_sincos_o2_m_idx_0_tmp * localB->Abs2) *
    localP->Positioncontroller_P;
  if (localB->Abs4 > localP->Positioncontroller_UpperSaturationLimit) {
    localB->Abs4 = localP->Positioncontroller_UpperSaturationLimit;
  } else if (localB->Abs4 < localP->Positioncontroller_LowerSaturationLimit) {
    localB->Abs4 = localP->Positioncontroller_LowerSaturationLimit;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  Saturate: '<S169>/Saturation'
   */
  localB->I_yaw = localB->Abs4 - localB->Reshapexhat[0];
  localB->Conversion_g[0] = localB->I_yaw;

  /* Sum: '<S225>/Sum' incorporates:
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Gain: '<S221>/Proportional Gain'
   */
  rtb_Sum_d_idx_1 = localP->Velocitycontroller_P * localB->I_yaw +
    localDW->Integrator_DSTATE[0];
  rtb_Sum_d_idx_0 = rtb_Sum_d_idx_1;

  /* Saturate: '<S223>/Saturation' */
  if (rtb_Sum_d_idx_1 > localP->Velocitycontroller_UpperSaturationLimit) {
    rtb_Sum_d_idx_1 = localP->Velocitycontroller_UpperSaturationLimit;
  } else if (rtb_Sum_d_idx_1 < localP->Velocitycontroller_LowerSaturationLimit)
  {
    rtb_Sum_d_idx_1 = localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' incorporates:
   *  Saturate: '<S223>/Saturation'
   */
  localB->Abs4 = (rtb_Sum_d_idx_1 -
                  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
                  [0] *
                  localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
                  [1]) /
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[0] =
    localB->Abs4;
  localB->numAccum =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    localB->Abs4 +
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1];

  /* Saturate: '<S169>/Saturation' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  localB->Abs4 = (-rtb_sincos_o2_m_idx_0_tmp * localB->Abs3 +
                  rtb_sincos_o2_j_idx_0_tmp * localB->Abs2) *
    localP->Positioncontroller_P;
  if (localB->Abs4 > localP->Positioncontroller_UpperSaturationLimit) {
    localB->Abs4 = localP->Positioncontroller_UpperSaturationLimit;
  } else if (localB->Abs4 < localP->Positioncontroller_LowerSaturationLimit) {
    localB->Abs4 = localP->Positioncontroller_LowerSaturationLimit;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  Saturate: '<S169>/Saturation'
   */
  localB->I_yaw = localB->Abs4 - localB->Reshapexhat[1];

  /* Sum: '<S225>/Sum' incorporates:
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Gain: '<S221>/Proportional Gain'
   */
  rtb_Sum_d_idx_1 = localP->Velocitycontroller_P * localB->I_yaw +
    localDW->Integrator_DSTATE[1];

  /* Saturate: '<S223>/Saturation' */
  if (rtb_Sum_d_idx_1 > localP->Velocitycontroller_UpperSaturationLimit) {
    localB->Abs3 = localP->Velocitycontroller_UpperSaturationLimit;
  } else if (rtb_Sum_d_idx_1 < localP->Velocitycontroller_LowerSaturationLimit)
  {
    localB->Abs3 = localP->Velocitycontroller_LowerSaturationLimit;
  } else {
    localB->Abs3 = rtb_Sum_d_idx_1;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' incorporates:
   *  Saturate: '<S223>/Saturation'
   */
  localB->Abs4 = (localB->Abs3 -
                  localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
                  [1] *
                  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
                  [1]) /
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[1] =
    localB->Abs4;

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   *  DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   *  Gain: '<S10>/Gain'
   */
  if (localP->controlModePosVsOrient_Value) {
    localB->rtb_sincos_o2_j_idx_1 = localP->Gain_Gain[0] * localB->numAccum;
    localB->rtb_sincos_o2_j_idx_2 =
      (localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0]
       * localB->Abs4 +
       localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1]
       * localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
       [1]) * localP->Gain_Gain[1];
  }

  /* End of Switch: '<S3>/Switch_refAtt' */

  /* Sum: '<S8>/Sum1' incorporates:
   *  Gain: '<S58>/Proportional Gain'
   *  Sum: '<S8>/Sum19'
   */
  localB->rtb_sincos_o2_j_idx_1 = (localB->rtb_sincos_o2_j_idx_1 -
    localB->DataTypeConversion3[1]) * localP->Anglecontrolloop_P -
    localB->Subtract[1];
  localB->rtb_sincos_o2_j_idx_2 = (localB->rtb_sincos_o2_j_idx_2 -
    localB->DataTypeConversion3[2]) * localP->Anglecontrolloop_P -
    localB->Subtract[0];

  /* Sum: '<S11>/Sum1' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   */
  localB->Abs2 = localB->rtb_sincos_o2_j_idx_0 - localB->DataTypeConversion3[0];

  /* Saturate: '<S11>/Saturation' */
  if (localB->Abs2 > localP->Saturation_UpperSat) {
    localB->Abs2 = localP->Saturation_UpperSat;
  } else if (localB->Abs2 < localP->Saturation_LowerSat) {
    localB->Abs2 = localP->Saturation_LowerSat;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Gain: '<S110>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S102>/Filter'
   *  Gain: '<S100>/Derivative Gain'
   *  Sum: '<S102>/SumD'
   */
  localB->numAccum = (localP->Angularvelocitycontrolloop_D[0] *
                      localB->rtb_sincos_o2_j_idx_1 - localDW->Filter_DSTATE[0])
    * localP->Angularvelocitycontrolloop_N[0];
  localB->rtb_sincos_o2_j_idx_0 = localB->numAccum;

  /* Sum: '<S116>/Sum' incorporates:
   *  DiscreteIntegrator: '<S107>/Integrator'
   *  Gain: '<S100>/Derivative Gain'
   *  Gain: '<S112>/Proportional Gain'
   */
  localB->Abs5 = (localP->Angularvelocitycontrolloop_P[0] *
                  localB->rtb_sincos_o2_j_idx_1 + localDW->Integrator_DSTATE_d[0])
    + localB->numAccum;

  /* DeadZone: '<S99>/DeadZone' incorporates:
   *  Saturate: '<S114>/Saturation'
   */
  if (localB->Abs5 > localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    rtb_DeadZone_idx_0 = localB->Abs5 -
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
    rtb_Saturation_n_0 = localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else {
    if (localB->Abs5 >= localP->Angularvelocitycontrolloop_LowerSaturationLimit)
    {
      rtb_DeadZone_idx_0 = 0.0F;
    } else {
      rtb_DeadZone_idx_0 = localB->Abs5 -
        localP->Angularvelocitycontrolloop_LowerSaturationLimit;
    }

    if (localB->Abs5 < localP->Angularvelocitycontrolloop_LowerSaturationLimit)
    {
      rtb_Saturation_n_0 =
        localP->Angularvelocitycontrolloop_LowerSaturationLimit;
    } else {
      rtb_Saturation_n_0 = localB->Abs5;
    }
  }

  /* Gain: '<S104>/Integral Gain' incorporates:
   *  Gain: '<S100>/Derivative Gain'
   */
  localB->rtb_sincos_o2_j_idx_1 *= localP->Angularvelocitycontrolloop_I[0];

  /* DeadZone: '<S208>/DeadZone' */
  if (rtb_Sum_d_idx_0 > localP->Velocitycontroller_UpperSaturationLimit) {
    rtb_Sum_d_idx_0 -= localP->Velocitycontroller_UpperSaturationLimit;
  } else if (rtb_Sum_d_idx_0 >= localP->Velocitycontroller_LowerSaturationLimit)
  {
    rtb_Sum_d_idx_0 = 0.0F;
  } else {
    rtb_Sum_d_idx_0 -= localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* Gain: '<S213>/Integral Gain' */
  localB->Conversion_g[0] *= localP->Velocitycontroller_I;

  /* Gain: '<S110>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S102>/Filter'
   *  Gain: '<S100>/Derivative Gain'
   *  Sum: '<S102>/SumD'
   */
  localB->numAccum = (localP->Angularvelocitycontrolloop_D[1] *
                      localB->rtb_sincos_o2_j_idx_2 - localDW->Filter_DSTATE[1])
    * localP->Angularvelocitycontrolloop_N[1];

  /* Sum: '<S116>/Sum' incorporates:
   *  DiscreteIntegrator: '<S107>/Integrator'
   *  Gain: '<S100>/Derivative Gain'
   *  Gain: '<S112>/Proportional Gain'
   */
  localB->Abs5 = (localP->Angularvelocitycontrolloop_P[1] *
                  localB->rtb_sincos_o2_j_idx_2 + localDW->Integrator_DSTATE_d[1])
    + localB->numAccum;

  /* DeadZone: '<S99>/DeadZone' incorporates:
   *  Saturate: '<S114>/Saturation'
   */
  if (localB->Abs5 > localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    rtb_DeadZone_idx_1 = localB->Abs5 -
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
    localB->Abs5 = localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else {
    if (localB->Abs5 >= localP->Angularvelocitycontrolloop_LowerSaturationLimit)
    {
      rtb_DeadZone_idx_1 = 0.0F;
    } else {
      rtb_DeadZone_idx_1 = localB->Abs5 -
        localP->Angularvelocitycontrolloop_LowerSaturationLimit;
    }

    if (localB->Abs5 < localP->Angularvelocitycontrolloop_LowerSaturationLimit)
    {
      localB->Abs5 = localP->Angularvelocitycontrolloop_LowerSaturationLimit;
    }
  }

  /* Gain: '<S104>/Integral Gain' incorporates:
   *  Gain: '<S100>/Derivative Gain'
   */
  localB->rtb_sincos_o2_j_idx_2 *= localP->Angularvelocitycontrolloop_I[1];

  /* DeadZone: '<S208>/DeadZone' incorporates:
   *  Sum: '<S225>/Sum'
   */
  if (rtb_Sum_d_idx_1 > localP->Velocitycontroller_UpperSaturationLimit) {
    rtb_Sum_d_idx_1 -= localP->Velocitycontroller_UpperSaturationLimit;
  } else if (rtb_Sum_d_idx_1 >= localP->Velocitycontroller_LowerSaturationLimit)
  {
    rtb_Sum_d_idx_1 = 0.0F;
  } else {
    rtb_Sum_d_idx_1 -= localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* Gain: '<S213>/Integral Gain' incorporates:
   *  Sum: '<S10>/Sum19'
   */
  localB->Conversion_g[1] = localP->Velocitycontroller_I * localB->I_yaw;

  /* Gain: '<S11>/I_yaw' */
  localB->I_yaw = localP->I_yaw_Gain * localB->Abs2;

  /* Switch: '<S7>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S7>/w1'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/D_z1'
   *  Gain: '<S7>/P_z1'
   *  Gain: '<S7>/takeoff_gain1'
   *  Sum: '<S7>/Sum1'
   */
  if (rtb_Compare_ls) {
    localB->Abs3 = localP->takeoff_gain1_Gain * localP->w1_Value;
  } else {
    localB->Abs3 = (localP->P_z1_Gain * localB->Abs1 +
                    localDW->DiscreteTimeIntegrator_DSTATE_c) -
      localP->D_z1_Gain * localB->DataTypeConversion2;
  }

  /* Sum: '<S7>/Sum5' incorporates:
   *  Constant: '<S7>/w1'
   *  Switch: '<S7>/TakeoffOrControl_Switch1'
   */
  localB->Abs4 = localP->w1_Value + localB->Abs3;

  /* Saturate: '<S7>/SaturationThrust1' */
  if (localB->Abs4 > localP->SaturationThrust1_UpperSat) {
    localB->Abs4 = localP->SaturationThrust1_UpperSat;
  } else if (localB->Abs4 < localP->SaturationThrust1_LowerSat) {
    localB->Abs4 = localP->SaturationThrust1_LowerSat;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_yaw'
   *  Gain: '<S11>/P_yaw'
   *  Sum: '<S11>/Sum2'
   */
  localB->Abs2 = (localP->P_yaw_Gain * localB->Abs2 +
                  localDW->DiscreteTimeIntegrator_DSTATE_d) - localP->D_yaw_Gain
    * localB->Subtract[2];

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S9>/Pitch correction'
   *  Constant: '<S9>/zero correction'
   *  ManualSwitch: '<S9>/Manual Switch'
   */
  if (localP->ManualSwitch_CurrentSetting == 1) {
    localB->Abs3 = localP->Pitchcorrection_Value;
  } else {
    localB->Abs3 = localP->zerocorrection_Value;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  ManualSwitch: '<S9>/Manual Switch'
   *  Saturate: '<S114>/Saturation'
   *  Sum: '<S9>/Add'
   */
  localB->Abs3 += rtb_Saturation_n_0;
  for (localB->i = 0; localB->i < 4; localB->i++) {
    /* Saturate: '<S12>/Saturation5' incorporates:
     *  Constant: '<S9>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S12>/ThrustToMotorCommand'
     *  Product: '<S9>/Product'
     *  Saturate: '<S114>/Saturation'
     *  Saturate: '<S7>/SaturationThrust1'
     */
    rtb_Saturation_n_0 = (((localP->
      TorqueTotalThrustToThrustPerMotor_Value[localB->i + 4] * localB->Abs2 +
      localP->TorqueTotalThrustToThrustPerMotor_Value[localB->i] * localB->Abs4)
      + localP->TorqueTotalThrustToThrustPerMotor_Value[localB->i + 8] *
      localB->Abs3) + localP->TorqueTotalThrustToThrustPerMotor_Value[localB->i
                          + 12] * localB->Abs5) *
      localP->ThrustToMotorCommand_Gain;
    if (rtb_Saturation_n_0 > localP->Saturation5_UpperSat) {
      rtb_Saturation_n_0 = localP->Saturation5_UpperSat;
    } else if (rtb_Saturation_n_0 < localP->Saturation5_LowerSat) {
      rtb_Saturation_n_0 = localP->Saturation5_LowerSat;
    }

    /* Gain: '<S12>/MotorDirections' incorporates:
     *  Saturate: '<S12>/Saturation5'
     */
    motors_outport[localB->i] = localP->MotorDirections_Gain[localB->i] *
      rtb_Saturation_n_0;
  }

  /* RelationalOperator: '<S4>/GreaterThan' incorporates:
   *  Constant: '<S4>/Wait  3 Seconds'
   *  UnitDelay: '<S242>/Output'
   */
  rtb_LogicalOperator_m = (localDW->Output_DSTATE_g > localP->Wait3Seconds_Value);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   */
  if (rtb_LogicalOperator_m) {
    localB->Sum_k = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->Sum_k = localP->_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S235>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S235>/Compare'
   */
  localDW->DelayOneStep_DSTATE = (real_T)(localB->Sum_k ==
    localP->Checkerrorcondition_const) * localDW->DelayOneStep_DSTATE + (real_T)
    (localB->Sum_k == localP->Checkerrorcondition_const);

  /* Gain: '<S4>/Gain' */
  localB->Abs2 = localP->Gain_Gain_o *
    rtu_Sensors->VisionSensors.opticalFlow_data[0];

  /* Gain: '<S4>/Gain1' */
  localB->Abs3 = localP->Gain1_Gain_p *
    rtu_Sensors->VisionSensors.opticalFlow_data[1];

  /* Abs: '<S4>/Abs4' */
  localB->Abs4 = (real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]);

  /* Abs: '<S4>/Abs5' */
  localB->Abs5 = (real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[1]);

  /* Sum: '<S248>/FixPt Sum1' incorporates:
   *  Constant: '<S248>/FixPt Constant'
   *  UnitDelay: '<S242>/Output'
   */
  localDW->Output_DSTATE_g += localP->FixPtConstant_Value;

  /* If: '<S4>/If' incorporates:
   *  Abs: '<S4>/Abs'
   *  Abs: '<S4>/Abs  '
   *  Abs: '<S4>/Abs1'
   *  Abs: '<S4>/Abs2'
   *  Abs: '<S4>/Abs3'
   *  Constant: '<S234>/Constant'
   *  Constant: '<S236>/Constant'
   *  Constant: '<S237>/Constant'
   *  Constant: '<S238>/Constant'
   *  Constant: '<S239>/Constant'
   *  Constant: '<S240>/Constant'
   *  Constant: '<S241>/Constant'
   *  Constant: '<S4>/0.5 meters'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S234>/Compare'
   *  RelationalOperator: '<S236>/Compare'
   *  RelationalOperator: '<S237>/Compare'
   *  RelationalOperator: '<S238>/Compare'
   *  RelationalOperator: '<S239>/Compare'
   *  RelationalOperator: '<S240>/Compare'
   *  RelationalOperator: '<S241>/Compare'
   *  RelationalOperator: '<S4>/GreaterThan  '
   *  Sum: '<S4>/Subtract'
   *  Sum: '<S4>/Subtract1'
   *  Switch: '<S4>/         '
   */
  if (((real32_T)fabs(localB->SimplyIntegrateVelocity[0]) >
       localP->CompareToConstant_const_j) || ((real32_T)fabs
       (localB->SimplyIntegrateVelocity[1]) > localP->CompareToConstant1_const_e))
  {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S243>/Action Port'
     */
    flightControlSystem_Geofencingerror(&flag_outport, &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if (((localB->Abs4 > localP->CompareToConstant4_const) && ((real32_T)
               fabs(localB->Abs2 - localB->Reshapexhat[0]) >
               localP->CompareToConstant2_const)) || (((real32_T)fabs
               (localB->Abs3 - localB->Reshapexhat[1]) >
               localP->CompareToConstant3_const) && (localB->Abs5 >
               localP->CompareToConstant5_const))) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    flightControlSystem_Geofencingerror(&flag_outport,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localDW->DelayOneStep_DSTATE > localP->u0continuousOFerrors_const)
  {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S244>/Action Port'
     */
    flightControlSystem_Geofencingerror(&flag_outport, &localP->Noopticalflow);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else {
    if (rtb_LogicalOperator_m) {
      /* Switch: '<S4>/         ' incorporates:
       *  DiscreteFilter: '<S256>/pressureFilter_IIR'
       *  Sum: '<S4>/Difference between  sonar and pressure'
       */
      localB->Abs3 = localB->DataTypeConversion - localB->rtb_sincos_o2_idx_1;
    } else {
      /* Switch: '<S4>/         ' incorporates:
       *  Constant: '<S4>/    '
       */
      localB->Abs3 = localP->_Value_i;
    }

    if ((real32_T)fabs(localB->Abs3) > localP->u5meters_Value) {
      /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
       *  ActionPort: '<S246>/Action Port'
       */
      flightControlSystem_Geofencingerror(&flag_outport,
        &localP->Ultrasoundimproper);

      /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
       *  ActionPort: '<S245>/Action Port'
       */
      flightControlSystem_Geofencingerror(&flag_outport,
        &localP->Normalcondition);

      /* End of Outputs for SubSystem: '<S4>/Normal condition' */
    }
  }

  /* End of If: '<S4>/If' */

  /* MATLAB Function: '<S305>/SqrtUsedFcn' */
  localDW->sfEvent_n = flightControlSystem_CALL_EVENT_a;

  /* Product: '<S251>/Product' incorporates:
   *  Math: '<S251>/Math Function'
   */
  localB->rtb_sincos_o2_idx_1 = localB->FIR_IMUaccel[1];
  localB->Abs3 = localB->FIR_IMUaccel[0];
  for (localB->i = 0; localB->i < 3; localB->i++) {
    /* Sum: '<S251>/Sum' incorporates:
     *  Constant: '<S251>/gravity'
     *  DiscreteFir: '<S253>/FIR_IMUaccel'
     *  Reshape: '<S314>/Reshape (9) to [3x3] column-major'
     */
    localB->Sum[localB->i] = ((localB->VectorConcatenate[3 * localB->i + 1] *
      localB->rtb_sincos_o2_idx_1 + localB->VectorConcatenate[3 * localB->i] *
      localB->Abs3) + localB->VectorConcatenate[3 * localB->i + 2] *
      localB->rtb_sincos_o2_idx_0) + localP->gravity_Value[localB->i];
  }

  /* End of Product: '<S251>/Product' */

  /* Outputs for Enabled SubSystem: '<S277>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S307>/Enable'
   */
  /* DataTypeConversion: '<S255>/DataTypeConversionEnable' */
  if (localB->nicemeasurementornewupdateneeded) {
    localDW->MeasurementUpdate_MODE_c = true;

    /* Sum: '<S307>/Sum' incorporates:
     *  Constant: '<S255>/C'
     *  Constant: '<S255>/D'
     *  Delay: '<S255>/MemoryX'
     *  Product: '<S307>/C[k]*xhat[k|k-1]'
     *  Product: '<S307>/D[k]*u[k]'
     *  Reshape: '<S255>/Reshapeu'
     *  Reshape: '<S255>/Reshapey'
     *  Sum: '<S307>/Add1'
     */
    localB->Sum_k = localB->invertzaxisGain - ((localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]) + localP->D_Value * localB->Sum[2]);

    /* Product: '<S307>/Product3' incorporates:
     *  Constant: '<S259>/KalmanGainL'
     *  DataTypeConversion: '<S299>/Conversion'
     */
    localB->Product3[0] = localP->KalmanGainL_Value[0] * localB->Sum_k;
    localB->Product3[1] = localP->KalmanGainL_Value[1] * localB->Sum_k;
    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC_m);
  } else if (localDW->MeasurementUpdate_MODE_c) {
    /* Disable for Product: '<S307>/Product3' incorporates:
     *  Outport: '<S307>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3[0] = localP->Lykyhatkk1_Y0;
    localB->Product3[1] = localP->Lykyhatkk1_Y0;
    localDW->MeasurementUpdate_MODE_c = false;
  }

  /* End of Outputs for SubSystem: '<S277>/MeasurementUpdate' */

  /* DataTypeConversion: '<S364>/Conversion' incorporates:
   *  Constant: '<S322>/KalmanGainL'
   */
  localB->Saturation_n[0] = (real32_T)localP->KalmanGainL_Value_l[0];
  localB->Saturation_n[1] = (real32_T)localP->KalmanGainL_Value_l[1];

  /* DataTypeConversion: '<S367>/Conversion' incorporates:
   *  Constant: '<S322>/CovarianceZ'
   */
  localB->Conversion_a[0] = (real32_T)localP->CovarianceZ_Value_b[0];
  localB->Conversion_a[1] = (real32_T)localP->CovarianceZ_Value_b[1];
  localB->Conversion_a[2] = (real32_T)localP->CovarianceZ_Value_b[2];
  localB->Conversion_a[3] = (real32_T)localP->CovarianceZ_Value_b[3];

  /* MATLAB Function: '<S370>/SqrtUsedFcn' incorporates:
   *  Constant: '<S370>/isSqrtUsed'
   */
  flightControlSystem_SqrtUsedFcn(&localDW->sf_SqrtUsedFcn_h);

  /* Outputs for Enabled SubSystem: '<S341>/MeasurementUpdate' */
  /* DataTypeConversion: '<S321>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S321>/C'
   *  Constant: '<S321>/D'
   *  Delay: '<S321>/MemoryX'
   *  Reshape: '<S321>/Reshapeu'
   *  Reshape: '<S321>/Reshapey'
   */
  flightControlSystem_MeasurementUpdate((localB->LogicalOperator != 0),
    localB->Saturation_n, localB->TrigonometricFunction1, localP->C_Value_h,
    localDW->MemoryX_DSTATE_g, localP->D_Value_k, localB->q,
    &localB->MeasurementUpdate_n, &localDW->MeasurementUpdate_n,
    &localP->MeasurementUpdate_n);

  /* End of Outputs for SubSystem: '<S341>/MeasurementUpdate' */

  /* DataTypeConversion: '<S418>/Conversion' incorporates:
   *  Constant: '<S376>/KalmanGainL'
   */
  localB->Saturation_n[0] = (real32_T)localP->KalmanGainL_Value_p[0];
  localB->Saturation_n[1] = (real32_T)localP->KalmanGainL_Value_p[1];

  /* DataTypeConversion: '<S421>/Conversion' incorporates:
   *  Constant: '<S376>/CovarianceZ'
   */
  localB->Conversion_a[0] = (real32_T)localP->CovarianceZ_Value_m[0];
  localB->Conversion_a[1] = (real32_T)localP->CovarianceZ_Value_m[1];
  localB->Conversion_a[2] = (real32_T)localP->CovarianceZ_Value_m[2];
  localB->Conversion_a[3] = (real32_T)localP->CovarianceZ_Value_m[3];

  /* MATLAB Function: '<S424>/SqrtUsedFcn' incorporates:
   *  Constant: '<S424>/isSqrtUsed'
   */
  flightControlSystem_SqrtUsedFcn(&localDW->sf_SqrtUsedFcn_e);

  /* Outputs for Enabled SubSystem: '<S395>/MeasurementUpdate' */
  /* DataTypeConversion: '<S375>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S375>/C'
   *  Constant: '<S375>/D'
   *  Delay: '<S375>/MemoryX'
   *  Reshape: '<S375>/Reshapeu'
   *  Reshape: '<S375>/Reshapey'
   */
  flightControlSystem_MeasurementUpdate((localB->LogicalOperator != 0),
    localB->Saturation_n, localB->TrigonometricFunction, localP->C_Value_i,
    localDW->MemoryX_DSTATE_m, localP->D_Value_ke, localB->p,
    &localB->MeasurementUpdate_j, &localDW->MeasurementUpdate_j,
    &localP->MeasurementUpdate_j);

  /* End of Outputs for SubSystem: '<S395>/MeasurementUpdate' */

  /* Sum: '<S434>/FixPt Sum1' incorporates:
   *  Constant: '<S434>/FixPt Constant'
   *  UnitDelay: '<S432>/Output'
   */
  localDW->Output_DSTATE_i += localP->FixPtConstant_Value_m;

  /* Fcn: '<S444>/Fcn11' */
  localB->VectorConcatenate[0] = rtb_sincos_o2_j_idx_0_tmp *
    rtb_sincos_o2_j_idx_1_tmp;

  /* Fcn: '<S444>/Fcn21' incorporates:
   *  Fcn: '<S444>/Fcn22'
   */
  localB->Abs3 = rtb_sincos_o2_m_idx_1_tmp * rtb_sincos_o2_m_idx_2_tmp;
  localB->VectorConcatenate[1] = localB->Abs3 * rtb_sincos_o2_j_idx_0_tmp -
    rtb_sincos_o2_m_idx_0_tmp * rtb_sincos_o2_j_idx_2_tmp;

  /* Fcn: '<S444>/Fcn31' incorporates:
   *  Fcn: '<S444>/Fcn32'
   */
  localB->Abs4 = rtb_sincos_o2_m_idx_1_tmp * rtb_sincos_o2_j_idx_2_tmp;
  localB->VectorConcatenate[2] = localB->Abs4 * rtb_sincos_o2_j_idx_0_tmp +
    rtb_sincos_o2_m_idx_0_tmp * rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S444>/Fcn12' */
  localB->VectorConcatenate[3] = rtb_sincos_o2_m_idx_0_tmp *
    rtb_sincos_o2_j_idx_1_tmp;

  /* Fcn: '<S444>/Fcn22' */
  localB->VectorConcatenate[4] = localB->Abs3 * rtb_sincos_o2_m_idx_0_tmp +
    rtb_sincos_o2_j_idx_0_tmp * rtb_sincos_o2_j_idx_2_tmp;

  /* Fcn: '<S444>/Fcn32' */
  localB->VectorConcatenate[5] = localB->Abs4 * rtb_sincos_o2_m_idx_0_tmp -
    rtb_sincos_o2_j_idx_0_tmp * rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S444>/Fcn13' */
  localB->VectorConcatenate[6] = -rtb_sincos_o2_m_idx_1_tmp;

  /* Fcn: '<S444>/Fcn23' */
  localB->VectorConcatenate[7] = rtb_sincos_o2_j_idx_1_tmp *
    rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S444>/Fcn33' */
  localB->VectorConcatenate[8] = rtb_sincos_o2_j_idx_1_tmp *
    rtb_sincos_o2_j_idx_2_tmp;

  /* RelationalOperator: '<S443>/Compare' incorporates:
   *  Constant: '<S443>/Constant'
   */
  rtb_Compare_o = (localB->DataTypeConversion <=
                   localP->DeactivateAccelerationIfOFisnotusedduetolowaltitude_const);

  /* Logic: '<S438>/Logical Operator' incorporates:
   *  Constant: '<S445>/Constant'
   *  Constant: '<S446>/Constant'
   *  RelationalOperator: '<S445>/Compare'
   *  RelationalOperator: '<S446>/Compare'
   */
  rtb_LogicalOperator_m = ((localB->u_l[0] !=
    localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con) ||
    (localB->u_l[1] !=
     localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co));

  /* Product: '<S438>/Product1' incorporates:
   *  Constant: '<S438>/gravity'
   */
  localB->rtb_Add_a_idx_1 = localP->gravity_Value_p[1];
  localB->Sum_k = localP->gravity_Value_p[0];
  localB->unnamed_idx_1 = localP->gravity_Value_p[2];

  /* Sum: '<S438>/Add' incorporates:
   *  Constant: '<S438>/gravity'
   *  Product: '<S438>/Product1'
   *  Reshape: '<S447>/Reshape (9) to [3x3] column-major'
   */
  for (localB->i = 0; localB->i < 3; localB->i++) {
    localB->rtb_VectorConcatenate_c[localB->i] = localB->FIR_IMUaccel[localB->i]
      - ((localB->VectorConcatenate[localB->i + 3] * localB->rtb_Add_a_idx_1 +
          localB->VectorConcatenate[localB->i] * localB->Sum_k) +
         localB->VectorConcatenate[localB->i + 6] * localB->unnamed_idx_1);
  }

  /* End of Sum: '<S438>/Add' */

  /* Product: '<S438>/Product' incorporates:
   *  Gain: '<S438>/gainaccinput1'
   */
  localB->Product[0] = (real32_T)(localP->gainaccinput1_Gain *
    localB->rtb_VectorConcatenate_c[0]) * (real32_T)rtb_LogicalOperator_m *
    (real32_T)rtb_Compare_o;
  localB->Product[1] = (real32_T)(localP->gainaccinput1_Gain *
    localB->rtb_VectorConcatenate_c[1]) * (real32_T)rtb_LogicalOperator_m *
    (real32_T)rtb_Compare_o;

  /* MATLAB Function: '<S508>/SqrtUsedFcn' */
  localDW->sfEvent = flightControlSystem_CALL_EVENT_a;

  /* Outputs for Enabled SubSystem: '<S479>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S510>/Enable'
   */
  /* DataTypeConversion: '<S441>/DataTypeConversionEnable' */
  if (localB->LogicalOperator3) {
    localDW->MeasurementUpdate_MODE = true;

    /* Delay: '<S441>/MemoryX' incorporates:
     *  Constant: '<S441>/C'
     *  Product: '<S510>/C[k]*xhat[k|k-1]'
     */
    localB->Abs3 = localDW->MemoryX_DSTATE_l[1];
    localB->Abs4 = localDW->MemoryX_DSTATE_l[0];
    localB->Abs2 = localDW->MemoryX_DSTATE_l[2];
    localB->Abs5 = localDW->MemoryX_DSTATE_l[3];

    /* Reshape: '<S441>/Reshapeu' incorporates:
     *  Constant: '<S441>/D'
     *  Product: '<S510>/D[k]*u[k]'
     */
    localB->rtb_sincos_o2_idx_0 = localB->Product[1];
    localB->rtb_sincos_o2_idx_1 = localB->Product[0];
    for (localB->i = 0; localB->i < 2; localB->i++) {
      /* Sum: '<S510>/Sum' incorporates:
       *  Constant: '<S441>/C'
       *  Constant: '<S441>/D'
       *  Delay: '<S441>/MemoryX'
       *  Product: '<S510>/C[k]*xhat[k|k-1]'
       *  Product: '<S510>/D[k]*u[k]'
       *  Reshape: '<S441>/Reshapeu'
       *  Reshape: '<S441>/Reshapey'
       *  Sum: '<S510>/Add1'
       */
      localB->fv1[localB->i] = localB->angularvelocitycompensation[localB->i] -
        ((((localP->C_Value_i2[localB->i + 2] * localB->Abs3 +
            localP->C_Value_i2[localB->i] * localB->Abs4) + localP->
           C_Value_i2[localB->i + 4] * localB->Abs2) + localP->C_Value_i2
          [localB->i + 6] * localB->Abs5) + (localP->D_Value_h[localB->i + 2] *
          localB->rtb_sincos_o2_idx_0 + localP->D_Value_h[localB->i] *
          localB->rtb_sincos_o2_idx_1));
    }

    /* Product: '<S510>/Product3' incorporates:
     *  Constant: '<S460>/KalmanGainL'
     *  DataTypeConversion: '<S502>/Conversion'
     */
    localB->Abs3 = localB->fv1[1];
    localB->Abs4 = localB->fv1[0];
    for (localB->i = 0; localB->i < 4; localB->i++) {
      /* Product: '<S510>/Product3' incorporates:
       *  Constant: '<S460>/KalmanGainL'
       *  DataTypeConversion: '<S502>/Conversion'
       */
      localB->Product3_a[localB->i] = (real32_T)localP->
        KalmanGainL_Value_k[localB->i + 4] * localB->Abs3 + (real32_T)
        localP->KalmanGainL_Value_k[localB->i] * localB->Abs4;
    }

    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC);
  } else if (localDW->MeasurementUpdate_MODE) {
    /* Disable for Product: '<S510>/Product3' incorporates:
     *  Outport: '<S510>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3_a[0] = localP->Lykyhatkk1_Y0_c;
    localB->Product3_a[1] = localP->Lykyhatkk1_Y0_c;
    localB->Product3_a[2] = localP->Lykyhatkk1_Y0_c;
    localB->Product3_a[3] = localP->Lykyhatkk1_Y0_c;
    localDW->MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S479>/MeasurementUpdate' */

  /* Sum: '<S515>/FixPt Sum1' incorporates:
   *  Constant: '<S515>/FixPt Constant'
   *  UnitDelay: '<S514>/Output'
   */
  localDW->Output_DSTATE += localP->FixPtConstant_Value_p;

  /* Fcn: '<S517>/Fcn11' */
  localB->VectorConcatenate[0] = rtb_sincos_o2_j_idx_0_tmp *
    rtb_sincos_o2_j_idx_1_tmp;

  /* Fcn: '<S517>/Fcn21' incorporates:
   *  Fcn: '<S517>/Fcn22'
   */
  localB->Abs3 = rtb_sincos_o2_m_idx_1_tmp * rtb_sincos_o2_m_idx_2_tmp;
  localB->VectorConcatenate[1] = localB->Abs3 * rtb_sincos_o2_j_idx_0_tmp -
    rtb_sincos_o2_m_idx_0_tmp * rtb_sincos_o2_j_idx_2_tmp;

  /* Fcn: '<S517>/Fcn31' incorporates:
   *  Fcn: '<S517>/Fcn32'
   */
  localB->Abs4 = rtb_sincos_o2_m_idx_1_tmp * rtb_sincos_o2_j_idx_2_tmp;
  localB->VectorConcatenate[2] = localB->Abs4 * rtb_sincos_o2_j_idx_0_tmp +
    rtb_sincos_o2_m_idx_0_tmp * rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S517>/Fcn12' */
  localB->VectorConcatenate[3] = rtb_sincos_o2_m_idx_0_tmp *
    rtb_sincos_o2_j_idx_1_tmp;

  /* Fcn: '<S517>/Fcn22' */
  localB->VectorConcatenate[4] = localB->Abs3 * rtb_sincos_o2_m_idx_0_tmp +
    rtb_sincos_o2_j_idx_0_tmp * rtb_sincos_o2_j_idx_2_tmp;

  /* Fcn: '<S517>/Fcn32' */
  localB->VectorConcatenate[5] = localB->Abs4 * rtb_sincos_o2_m_idx_0_tmp -
    rtb_sincos_o2_j_idx_0_tmp * rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S517>/Fcn13' */
  localB->VectorConcatenate[6] = -rtb_sincos_o2_m_idx_1_tmp;

  /* Fcn: '<S517>/Fcn23' */
  localB->VectorConcatenate[7] = rtb_sincos_o2_j_idx_1_tmp *
    rtb_sincos_o2_m_idx_2_tmp;

  /* Fcn: '<S517>/Fcn33' */
  localB->VectorConcatenate[8] = rtb_sincos_o2_j_idx_1_tmp *
    rtb_sincos_o2_j_idx_2_tmp;

  /* SignalConversion generated from: '<S437>/Product' */
  localB->rtb_sincos_o2_idx_0 = localB->Reshapexhat[0];
  localB->Abs2 = localB->Reshapexhat[1];

  /* Product: '<S437>/Product' incorporates:
   *  Math: '<S437>/Math Function'
   *  Reshape: '<S518>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S437>/Product'
   */
  for (localB->i = 0; localB->i < 3; localB->i++) {
    localB->FIR_IMUaccel[localB->i] = (localB->VectorConcatenate[3 * localB->i +
      1] * localB->Abs2 + localB->VectorConcatenate[3 * localB->i] *
      localB->rtb_sincos_o2_idx_0) + localB->VectorConcatenate[3 * localB->i + 2]
      * localB->DataTypeConversion2;
  }

  /* End of Product: '<S437>/Product' */

  /* Update for DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_PrevResetState = (int8_T)
    localP->controlModePosVsOrient_Value;

  /* Update for Delay: '<S255>/MemoryX' */
  localDW->icLoad = false;

  /* Update for DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] +=
    localP->SimplyIntegrateVelocity_gainval * localB->FIR_IMUaccel[0];

  /* Product: '<S277>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S255>/A'
   *  Delay: '<S255>/MemoryX'
   */
  localB->Sum_k = localP->A_Value[0] * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1] * localP->A_Value[2];

  /* Update for DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[1] +=
    localP->SimplyIntegrateVelocity_gainval * localB->FIR_IMUaccel[1];

  /* Product: '<S277>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S255>/A'
   *  Delay: '<S255>/MemoryX'
   */
  localB->unnamed_idx_1 = localDW->MemoryX_DSTATE[0] * localP->A_Value[1] +
    localDW->MemoryX_DSTATE[1] * localP->A_Value[3];

  /* Update for Delay: '<S255>/MemoryX' incorporates:
   *  Constant: '<S255>/B'
   *  Product: '<S277>/A[k]*xhat[k|k-1]'
   *  Product: '<S277>/B[k]*u[k]'
   *  Product: '<S307>/Product3'
   *  Reshape: '<S255>/Reshapeu'
   *  Sum: '<S277>/Add'
   */
  localDW->MemoryX_DSTATE[0] = (localP->B_Value[0] * localB->Sum[2] +
    localB->Sum_k) + localB->Product3[0];

  /* Update for DiscreteFilter: '<S256>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localDW->sonarFilter_IIR_states[1];

  /* Update for Delay: '<S255>/MemoryX' incorporates:
   *  Constant: '<S255>/B'
   *  Product: '<S277>/A[k]*xhat[k|k-1]'
   *  Product: '<S277>/B[k]*u[k]'
   *  Product: '<S307>/Product3'
   *  Reshape: '<S255>/Reshapeu'
   *  Sum: '<S277>/Add'
   */
  localDW->MemoryX_DSTATE[1] = (localP->B_Value[1] * localB->Sum[2] +
    localB->unnamed_idx_1) + localB->Product3[1];

  /* Update for DiscreteFilter: '<S256>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];

  /* Update for DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = localDW->sonarFilter_IIR_states[0];

  /* Update for DiscreteFilter: '<S256>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] = localB->DiscreteTimeIntegrator_k5;

  /* Update for DiscreteFilter: '<S256>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = localB->sonarFilter_IIR_tmp;

  /* Update for DiscreteIntegrator: '<S319>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE +=
    localP->DiscreteTimeIntegrator_gainval * localB->Subtract_c;

  /* Update for DiscreteFir: '<S253>/FIR_IMUaccel' */
  /* Update circular buffer index */
  localDW->FIR_IMUaccel_circBuf--;
  if (localDW->FIR_IMUaccel_circBuf < 0) {
    localDW->FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf] =
    localB->inverseIMU_gain[0];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 5] =
    localB->inverseIMU_gain[1];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 10] =
    localB->inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S253>/FIR_IMUaccel' */

  /* Update for Delay: '<S321>/MemoryX' */
  localDW->icLoad_p = false;

  /* Product: '<S341>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S321>/A'
   *  Delay: '<S321>/MemoryX'
   */
  localB->rtb_sincos_o2_idx_0 = localP->A_Value_k[0] * localDW->
    MemoryX_DSTATE_g[0] + localDW->MemoryX_DSTATE_g[1] * localP->A_Value_k[2];
  localB->Abs2 = localDW->MemoryX_DSTATE_g[0] * localP->A_Value_k[1] +
    localDW->MemoryX_DSTATE_g[1] * localP->A_Value_k[3];

  /* Update for Delay: '<S375>/MemoryX' */
  localDW->icLoad_k = false;

  /* Update for Delay: '<S321>/MemoryX' incorporates:
   *  Constant: '<S321>/B'
   *  Product: '<S341>/A[k]*xhat[k|k-1]'
   *  Product: '<S341>/B[k]*u[k]'
   *  Product: '<S372>/Product3'
   *  Reshape: '<S321>/Reshapeu'
   *  Sum: '<S341>/Add'
   */
  localDW->MemoryX_DSTATE_g[0] = (localP->B_Value_o[0] * localB->q +
    localB->rtb_sincos_o2_idx_0) + localB->MeasurementUpdate_n.Product3[0];

  /* Product: '<S395>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S375>/A'
   *  Delay: '<S375>/MemoryX'
   */
  localB->rtb_sincos_o2_idx_0 = localP->A_Value_a[0] * localDW->
    MemoryX_DSTATE_m[0] + localDW->MemoryX_DSTATE_m[1] * localP->A_Value_a[2];

  /* Update for Delay: '<S321>/MemoryX' incorporates:
   *  Constant: '<S321>/B'
   *  Product: '<S341>/A[k]*xhat[k|k-1]'
   *  Product: '<S341>/B[k]*u[k]'
   *  Product: '<S372>/Product3'
   *  Reshape: '<S321>/Reshapeu'
   *  Sum: '<S341>/Add'
   */
  localDW->MemoryX_DSTATE_g[1] = (localP->B_Value_o[1] * localB->q +
    localB->Abs2) + localB->MeasurementUpdate_n.Product3[1];

  /* Product: '<S395>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S375>/A'
   *  Delay: '<S375>/MemoryX'
   */
  localB->Abs2 = localDW->MemoryX_DSTATE_m[0] * localP->A_Value_a[1] +
    localDW->MemoryX_DSTATE_m[1] * localP->A_Value_a[3];

  /* Update for Delay: '<S375>/MemoryX' incorporates:
   *  Constant: '<S375>/B'
   *  Product: '<S395>/A[k]*xhat[k|k-1]'
   *  Product: '<S395>/B[k]*u[k]'
   *  Product: '<S426>/Product3'
   *  Reshape: '<S375>/Reshapeu'
   *  Sum: '<S395>/Add'
   */
  localDW->MemoryX_DSTATE_m[0] = (localP->B_Value_g[0] * localB->p +
    localB->rtb_sincos_o2_idx_0) + localB->MeasurementUpdate_j.Product3[0];
  localDW->MemoryX_DSTATE_m[1] = (localP->B_Value_g[1] * localB->p +
    localB->Abs2) + localB->MeasurementUpdate_j.Product3[1];

  /* Switch: '<S516>/FixPt Switch' */
  if (localDW->Output_DSTATE > localP->WrapToZero_Threshold_k) {
    /* Sum: '<S515>/FixPt Sum1' incorporates:
     *  Constant: '<S516>/Constant'
     *  UnitDelay: '<S514>/Output'
     */
    localDW->Output_DSTATE = localP->Constant_Value_e;
  }

  /* End of Switch: '<S516>/FixPt Switch' */

  /* Update for DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localB->Gain_m;

  /* Update for DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localB->LPFFcutoff40Hz_tmp;

  /* Update for DiscreteFilter: '<S253>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localB->IIR_IMUgyro_r_tmp;

  /* Switch: '<S435>/FixPt Switch' */
  if (localDW->Output_DSTATE_i > localP->WrapToZero_Threshold_e) {
    /* Sum: '<S434>/FixPt Sum1' incorporates:
     *  Constant: '<S435>/Constant'
     *  UnitDelay: '<S432>/Output'
     */
    localDW->Output_DSTATE_i = localP->Constant_Value_jy;
  }

  /* End of Switch: '<S435>/FixPt Switch' */

  /* Update for Delay: '<S441>/MemoryX' */
  localDW->icLoad_o = false;

  /* Reshape: '<S441>/Reshapeu' incorporates:
   *  Constant: '<S441>/B'
   *  Product: '<S479>/B[k]*u[k]'
   */
  localB->rtb_sincos_o2_idx_0 = localB->Product[1];
  localB->rtb_sincos_o2_idx_1 = localB->Product[0];

  /* Delay: '<S441>/MemoryX' incorporates:
   *  Constant: '<S441>/A'
   *  Product: '<S479>/A[k]*xhat[k|k-1]'
   */
  localB->Abs3 = localDW->MemoryX_DSTATE_l[1];
  localB->Abs4 = localDW->MemoryX_DSTATE_l[0];
  localB->Abs2 = localDW->MemoryX_DSTATE_l[2];
  localB->Abs5 = localDW->MemoryX_DSTATE_l[3];
  for (localB->i = 0; localB->i < 4; localB->i++) {
    /* Product: '<S479>/B[k]*u[k]' incorporates:
     *  Constant: '<S441>/B'
     *  Reshape: '<S441>/Reshapeu'
     */
    localB->Conversion_a[localB->i] = localP->B_Value_f[localB->i + 4] *
      localB->rtb_sincos_o2_idx_0 + localP->B_Value_f[localB->i] *
      localB->rtb_sincos_o2_idx_1;

    /* Product: '<S479>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S441>/A'
     *  Delay: '<S441>/MemoryX'
     */
    localB->fv[localB->i] = ((localP->A_Value_a4[localB->i + 4] * localB->Abs3 +
      localP->A_Value_a4[localB->i] * localB->Abs4) + localP->A_Value_a4
      [localB->i + 8] * localB->Abs2) + localP->A_Value_a4[localB->i + 12] *
      localB->Abs5;
  }

  /* Update for Delay: '<S441>/MemoryX' incorporates:
   *  Sum: '<S479>/Add'
   */
  localDW->MemoryX_DSTATE_l[0] = (localB->Conversion_a[0] + localB->fv[0]) +
    localB->Product3_a[0];
  localDW->MemoryX_DSTATE_l[1] = (localB->Conversion_a[1] + localB->fv[1]) +
    localB->Product3_a[1];
  localDW->MemoryX_DSTATE_l[2] = (localB->Conversion_a[2] + localB->fv[2]) +
    localB->Product3_a[2];
  localDW->MemoryX_DSTATE_l[3] = (localB->Conversion_a[3] + localB->fv[3]) +
    localB->Product3_a[3];
  for (localB->i = 0; localB->i < 2; localB->i++) {
    /* Update for DiscreteFilter: '<S440>/IIRgyroz' */
    localB->memOffset = localB->i * 5;
    localDW->IIRgyroz_states[localB->memOffset + 4] = localDW->
      IIRgyroz_states[localB->memOffset + 3];
    localDW->IIRgyroz_states[localB->memOffset + 3] = localDW->
      IIRgyroz_states[localB->memOffset + 2];
    localDW->IIRgyroz_states[localB->memOffset + 2] = localDW->
      IIRgyroz_states[localB->memOffset + 1];
    localDW->IIRgyroz_states[localB->memOffset + 1] = localDW->
      IIRgyroz_states[localB->memOffset];
    localDW->IIRgyroz_states[localB->memOffset] = localDW->IIRgyroz_tmp
      [localB->i];

    /* Update for UnitDelay: '<S448>/UD' incorporates:
     *  Sum: '<S448>/Diff'
     */
    localDW->UD_DSTATE[localB->i] = localB->DataTypeConversion_o[localB->i];

    /* Update for Delay: '<S436>/Delay' */
    localB->DiscreteTimeIntegrator_k5 = localB->Reshapexhat[localB->i];
    localDW->Delay_DSTATE[localB->i] = localB->DiscreteTimeIntegrator_k5;

    /* Update for Delay: '<S6>/Delay1' */
    localDW->Delay1_DSTATE[localB->i] = localB->DiscreteTimeIntegrator_k5;
  }

  /* Switch: '<S16>/FixPt Switch' */
  if (localDW->Output_DSTATE_a > localP->WrapToZero_Threshold_c) {
    /* Sum: '<S15>/FixPt Sum1' incorporates:
     *  Constant: '<S16>/Constant'
     *  UnitDelay: '<S14>/Output'
     */
    localDW->Output_DSTATE_a = localP->Constant_Value_k;
  }

  /* End of Switch: '<S16>/FixPt Switch' */

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_c += localP->I_pr_Gain * localB->Abs1 *
    localP->DiscreteTimeIntegrator_gainval_n;
  if (localDW->DiscreteTimeIntegrator_DSTATE_c >
      localP->DiscreteTimeIntegrator_UpperSat) {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_UpperSat;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_c <
             localP->DiscreteTimeIntegrator_LowerSat) {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_LowerSat;
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)rtb_Compare_ls;

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Switch: '<S206>/Switch1' incorporates:
   *  Constant: '<S206>/Clamping_zero'
   *  Constant: '<S206>/Constant'
   *  Constant: '<S206>/Constant2'
   *  RelationalOperator: '<S206>/fix for DT propagation issue'
   */
  if (rtb_Sum_d_idx_0 > localP->Clamping_zero_Value_m) {
    tmp = localP->Constant_Value_p;
  } else {
    tmp = localP->Constant2_Value_f;
  }

  /* Switch: '<S206>/Switch2' incorporates:
   *  Constant: '<S206>/Clamping_zero'
   *  Constant: '<S206>/Constant3'
   *  Constant: '<S206>/Constant4'
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  RelationalOperator: '<S206>/fix for DT propagation issue1'
   */
  if (localB->Conversion_g[0] > localP->Clamping_zero_Value_m) {
    tmp_0 = localP->Constant3_Value_d;
  } else {
    tmp_0 = localP->Constant4_Value_p;
  }

  /* Switch: '<S206>/Switch' incorporates:
   *  Constant: '<S206>/Clamping_zero'
   *  Constant: '<S206>/Constant1'
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Logic: '<S206>/AND3'
   *  RelationalOperator: '<S206>/Equal1'
   *  RelationalOperator: '<S206>/Relational Operator'
   *  Switch: '<S206>/Switch1'
   *  Switch: '<S206>/Switch2'
   */
  if ((localP->Clamping_zero_Value_m != rtb_Sum_d_idx_0) && (tmp == tmp_0)) {
    localB->Abs3 = localP->Constant1_Value_c;
  } else {
    localB->Abs3 = localB->Conversion_g[0];
  }

  /* Update for DiscreteIntegrator: '<S216>/Integrator' incorporates:
   *  Switch: '<S206>/Switch'
   */
  localDW->Integrator_DSTATE[0] += localP->Integrator_gainval * localB->Abs3;

  /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[0];

  /* Switch: '<S97>/Switch1' incorporates:
   *  Constant: '<S97>/Clamping_zero'
   *  Constant: '<S97>/Constant'
   *  Constant: '<S97>/Constant2'
   *  RelationalOperator: '<S97>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_idx_0 > localP->Clamping_zero_Value) {
    tmp = localP->Constant_Value_km;
  } else {
    tmp = localP->Constant2_Value;
  }

  /* Switch: '<S97>/Switch2' incorporates:
   *  Constant: '<S97>/Clamping_zero'
   *  Constant: '<S97>/Constant3'
   *  Constant: '<S97>/Constant4'
   *  Gain: '<S104>/Integral Gain'
   *  RelationalOperator: '<S97>/fix for DT propagation issue1'
   */
  if (localB->rtb_sincos_o2_j_idx_1 > localP->Clamping_zero_Value) {
    tmp_0 = localP->Constant3_Value;
  } else {
    tmp_0 = localP->Constant4_Value;
  }

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Clamping_zero'
   *  Constant: '<S97>/Constant1'
   *  Logic: '<S97>/AND3'
   *  RelationalOperator: '<S97>/Equal1'
   *  RelationalOperator: '<S97>/Relational Operator'
   *  Switch: '<S97>/Switch1'
   *  Switch: '<S97>/Switch2'
   */
  if ((localP->Clamping_zero_Value != rtb_DeadZone_idx_0) && (tmp == tmp_0)) {
    localB->rtb_sincos_o2_j_idx_1 = localP->Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S107>/Integrator' incorporates:
   *  Switch: '<S97>/Switch'
   */
  localDW->Integrator_DSTATE_d[0] += localP->Integrator_gainval_i *
    localB->rtb_sincos_o2_j_idx_1;

  /* Update for DiscreteIntegrator: '<S102>/Filter' */
  localDW->Filter_DSTATE[0] += localP->Filter_gainval *
    localB->rtb_sincos_o2_j_idx_0;

  /* Switch: '<S206>/Switch1' incorporates:
   *  Constant: '<S206>/Clamping_zero'
   *  Constant: '<S206>/Constant'
   *  Constant: '<S206>/Constant2'
   *  RelationalOperator: '<S206>/fix for DT propagation issue'
   */
  if (rtb_Sum_d_idx_1 > localP->Clamping_zero_Value_m) {
    tmp = localP->Constant_Value_p;
  } else {
    tmp = localP->Constant2_Value_f;
  }

  /* Switch: '<S206>/Switch2' incorporates:
   *  Constant: '<S206>/Clamping_zero'
   *  Constant: '<S206>/Constant3'
   *  Constant: '<S206>/Constant4'
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  RelationalOperator: '<S206>/fix for DT propagation issue1'
   */
  if (localB->Conversion_g[1] > localP->Clamping_zero_Value_m) {
    tmp_0 = localP->Constant3_Value_d;
  } else {
    tmp_0 = localP->Constant4_Value_p;
  }

  /* Switch: '<S206>/Switch' incorporates:
   *  Constant: '<S206>/Clamping_zero'
   *  Constant: '<S206>/Constant1'
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Logic: '<S206>/AND3'
   *  RelationalOperator: '<S206>/Equal1'
   *  RelationalOperator: '<S206>/Relational Operator'
   *  Switch: '<S206>/Switch1'
   *  Switch: '<S206>/Switch2'
   */
  if ((localP->Clamping_zero_Value_m != rtb_Sum_d_idx_1) && (tmp == tmp_0)) {
    localB->Abs3 = localP->Constant1_Value_c;
  } else {
    localB->Abs3 = localB->Conversion_g[1];
  }

  /* Update for DiscreteIntegrator: '<S216>/Integrator' incorporates:
   *  Switch: '<S206>/Switch'
   */
  localDW->Integrator_DSTATE[1] += localP->Integrator_gainval * localB->Abs3;

  /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[1];

  /* Switch: '<S97>/Switch1' incorporates:
   *  Constant: '<S97>/Clamping_zero'
   *  Constant: '<S97>/Constant'
   *  Constant: '<S97>/Constant2'
   *  RelationalOperator: '<S97>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_idx_1 > localP->Clamping_zero_Value) {
    tmp = localP->Constant_Value_km;
  } else {
    tmp = localP->Constant2_Value;
  }

  /* Switch: '<S97>/Switch2' incorporates:
   *  Constant: '<S97>/Clamping_zero'
   *  Constant: '<S97>/Constant3'
   *  Constant: '<S97>/Constant4'
   *  Gain: '<S104>/Integral Gain'
   *  RelationalOperator: '<S97>/fix for DT propagation issue1'
   */
  if (localB->rtb_sincos_o2_j_idx_2 > localP->Clamping_zero_Value) {
    tmp_0 = localP->Constant3_Value;
  } else {
    tmp_0 = localP->Constant4_Value;
  }

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Clamping_zero'
   *  Constant: '<S97>/Constant1'
   *  Logic: '<S97>/AND3'
   *  RelationalOperator: '<S97>/Equal1'
   *  RelationalOperator: '<S97>/Relational Operator'
   *  Switch: '<S97>/Switch1'
   *  Switch: '<S97>/Switch2'
   */
  if ((localP->Clamping_zero_Value != rtb_DeadZone_idx_1) && (tmp == tmp_0)) {
    localB->rtb_sincos_o2_j_idx_2 = localP->Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S107>/Integrator' incorporates:
   *  Switch: '<S97>/Switch'
   */
  localDW->Integrator_DSTATE_d[1] += localP->Integrator_gainval_i *
    localB->rtb_sincos_o2_j_idx_2;

  /* Update for DiscreteIntegrator: '<S102>/Filter' incorporates:
   *  Gain: '<S110>/Filter Coefficient'
   */
  localDW->Filter_DSTATE[1] += localP->Filter_gainval * localB->numAccum;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_d +=
    localP->DiscreteTimeIntegrator_gainval_d * localB->I_yaw;

  /* Switch: '<S249>/FixPt Switch' */
  if (localDW->Output_DSTATE_g > localP->WrapToZero_Threshold) {
    /* Sum: '<S248>/FixPt Sum1' incorporates:
     *  Constant: '<S249>/Constant'
     *  UnitDelay: '<S242>/Output'
     */
    localDW->Output_DSTATE_g = localP->Constant_Value_a;
  }

  /* End of Switch: '<S249>/FixPt Switch' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Main control' */
static real_T flightControlSystem_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 160.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (r < 0.0) {
      r += 160.0;
    }
  }

  return r;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function2' */
static real_T flightControlSystem_line_drawer(real_T x2, real_T y2, const
  boolean_T u[19200], real_T compare)
{
  real_T distance;
  real_T dx;
  real_T m;
  real_T range;
  real_T slope_error;
  real_T x;
  real_T y;
  int32_T b_x;
  int32_T b_y1;
  int32_T swapepd;
  int32_T x1;
  int32_T xk;
  int32_T yk;
  boolean_T exitg1;
  boolean_T guard1;
  b_y1 = 80;
  x1 = 60;
  swapepd = 0;
  if (fabs(y2 - 80.0) > fabs(x2 - 60.0)) {
    swapepd = 1;
    x1 = 80;
    b_y1 = 60;
    dx = y2;
    m = x2;
    x2 = y2;
    y2 = m;
    xk = 1;
    yk = 1;
    if (dx < 80.0) {
      xk = -1;
    }

    if (m < 60.0) {
      yk = -1;
    }
  } else {
    xk = -1;
    yk = -1;
    if (x2 > 60.0) {
      xk = 1;
    }

    if (y2 > 80.0) {
      yk = 1;
    }
  }

  dx = fabs(x2 - (real_T)x1);
  distance = 0.0;
  m = fabs(y2 - (real_T)b_y1) * 2.0;
  slope_error = m - 2.0 * dx;
  y = b_y1;
  range = 1.0;
  b_y1 = (int32_T)(((real_T)(xk - x1) + x2) / (real_T)xk);
  b_x = 0;
  exitg1 = false;
  while ((!exitg1) && (b_x <= b_y1 - 1)) {
    x = (real_T)b_x * (real_T)xk + (real_T)x1;
    guard1 = false;
    if (swapepd == 1) {
      if (u[(((int32_T)x - 1) * 120 + (int32_T)y) - 1] == compare) {
        distance = range;
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else if (u[(((int32_T)y - 1) * 120 + (int32_T)x) - 1] == compare) {
      distance = range;
      exitg1 = true;
    } else {
      guard1 = true;
    }

    if (guard1) {
      range++;
      slope_error += m;
      if (slope_error > 0.0) {
        y += (real_T)yk;
        slope_error -= 2.0 * dx;
      }

      b_x++;
    }
  }

  return distance;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function2' */
static void flightControlSystem_nearest_edge(real_T x, real_T y, real_T *X,
  real_T *Y)
{
  real_T below_d;
  real_T left_d;
  real_T right_d;
  real_T tmp;
  real_T tmp_0;
  real_T top_d;
  *X = x;
  *Y = y;
  top_d = fabs(1.0 - x);
  below_d = fabs(120.0 - x);
  left_d = fabs(1.0 - y);
  right_d = fabs(160.0 - y);
  if (top_d < below_d) {
    tmp = top_d;
  } else {
    tmp = below_d;
  }

  if (left_d < right_d) {
    tmp_0 = left_d;
  } else {
    tmp_0 = right_d;
  }

  if (tmp < tmp_0) {
    if (top_d < below_d) {
      *X = 1.0;
    } else {
      *X = 120.0;
    }
  } else if (left_d < right_d) {
    *Y = 1.0;
  } else {
    *Y = 160.0;
  }

  if (*X < 1.0) {
    *X = 1.0;
  }

  if (*Y < 1.0) {
    *Y = 1.0;
  }
}

static void flightControlSystem_emxInit_real_T
  (emxArray_real_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_flightControlSystem_T *emxArray;
  *pEmxArray = (emxArray_real_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_real_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (flightControlSystem_B.i_c = 0; flightControlSystem_B.i_c < numDimensions;
       flightControlSystem_B.i_c++) {
    emxArray->size[flightControlSystem_B.i_c] = 0;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_imfilter(const real32_T varargin_1[19200],
  real32_T b[19200])
{
  real_T bij;
  int32_T aColOffset;
  int32_T bColOffset;
  int32_T bTmp_tmp;
  int32_T b_i;
  int32_T cColOffset;
  int32_T ia;
  int32_T ib;
  int32_T j;
  int32_T jb;
  static const uint8_T c[328] = { 1U, 1U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U,
    10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U,
    25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U,
    40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U, 51U, 52U, 53U, 54U,
    55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U, 64U, 65U, 66U, 67U, 68U, 69U,
    70U, 71U, 72U, 73U, 74U, 75U, 76U, 77U, 78U, 79U, 80U, 81U, 82U, 83U, 84U,
    85U, 86U, 87U, 88U, 89U, 90U, 91U, 92U, 93U, 94U, 95U, 96U, 97U, 98U, 99U,
    100U, 101U, 102U, 103U, 104U, 105U, 106U, 107U, 108U, 109U, 110U, 111U, 112U,
    113U, 114U, 115U, 116U, 117U, 118U, 119U, 120U, 120U, 120U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U,
    1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U,
    18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U,
    33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U,
    48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U,
    63U, 64U, 65U, 66U, 67U, 68U, 69U, 70U, 71U, 72U, 73U, 74U, 75U, 76U, 77U,
    78U, 79U, 80U, 81U, 82U, 83U, 84U, 85U, 86U, 87U, 88U, 89U, 90U, 91U, 92U,
    93U, 94U, 95U, 96U, 97U, 98U, 99U, 100U, 101U, 102U, 103U, 104U, 105U, 106U,
    107U, 108U, 109U, 110U, 111U, 112U, 113U, 114U, 115U, 116U, 117U, 118U, 119U,
    120U, 121U, 122U, 123U, 124U, 125U, 126U, 127U, 128U, 129U, 130U, 131U, 132U,
    133U, 134U, 135U, 136U, 137U, 138U, 139U, 140U, 141U, 142U, 143U, 144U, 145U,
    146U, 147U, 148U, 149U, 150U, 151U, 152U, 153U, 154U, 155U, 156U, 157U, 158U,
    159U, 160U, 160U, 160U };

  static const real_T d[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  for (j = 0; j < 164; j++) {
    for (cColOffset = 0; cColOffset < 124; cColOffset++) {
      flightControlSystem_B.aTmp_k[cColOffset + 124 * j] = varargin_1[((c[j +
        164] - 1) * 120 + c[cColOffset]) - 1];
    }
  }

  for (j = 0; j < 20336; j++) {
    flightControlSystem_B.a[j] = flightControlSystem_B.aTmp_k[j];
  }

  memset(&flightControlSystem_B.bTmp[0], 0, 19200U * sizeof(real_T));
  for (j = 0; j < 160; j++) {
    cColOffset = j * 120;
    for (jb = 0; jb < 5; jb++) {
      aColOffset = (j + jb) * 124;
      bColOffset = 24 - jb * 5;
      for (ib = 0; ib < 5; ib++) {
        bij = d[bColOffset - ib];
        ia = aColOffset + ib;
        for (b_i = 0; b_i < 120; b_i++) {
          bTmp_tmp = cColOffset + b_i;
          flightControlSystem_B.bTmp[bTmp_tmp] += flightControlSystem_B.a[ia +
            b_i] * bij;
        }
      }
    }
  }

  for (j = 0; j < 19200; j++) {
    b[j] = (real32_T)flightControlSystem_B.bTmp[j];
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_conv2(const real_T a[19764], const real_T b[9],
  real_T c[19200])
{
  memset(&c[0], 0, 19200U * sizeof(real_T));
  for (flightControlSystem_B.j_a = 0; flightControlSystem_B.j_a < 160;
       flightControlSystem_B.j_a++) {
    flightControlSystem_B.cColOffset = flightControlSystem_B.j_a * 120;
    for (flightControlSystem_B.jb = 0; flightControlSystem_B.jb < 3;
         flightControlSystem_B.jb++) {
      flightControlSystem_B.aColOffset = (flightControlSystem_B.j_a +
        flightControlSystem_B.jb) * 122;
      flightControlSystem_B.bColOffset = 8 - flightControlSystem_B.jb * 3;
      for (flightControlSystem_B.ib_j = 0; flightControlSystem_B.ib_j < 3;
           flightControlSystem_B.ib_j++) {
        flightControlSystem_B.bij = b[flightControlSystem_B.bColOffset -
          flightControlSystem_B.ib_j];
        flightControlSystem_B.ia = flightControlSystem_B.aColOffset +
          flightControlSystem_B.ib_j;
        for (flightControlSystem_B.i_j = 0; flightControlSystem_B.i_j < 120;
             flightControlSystem_B.i_j++) {
          flightControlSystem_B.c_tmp = flightControlSystem_B.cColOffset +
            flightControlSystem_B.i_j;
          c[flightControlSystem_B.c_tmp] += a[flightControlSystem_B.ia +
            flightControlSystem_B.i_j] * flightControlSystem_B.bij;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_imfilter_k(const real32_T varargin_1[19200],
  real32_T b[19200])
{
  int32_T i;
  int32_T j;
  static const uint8_T d[324] = { 1U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U,
    11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U,
    26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U,
    41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U,
    56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U, 64U, 65U, 66U, 67U, 68U, 69U, 70U,
    71U, 72U, 73U, 74U, 75U, 76U, 77U, 78U, 79U, 80U, 81U, 82U, 83U, 84U, 85U,
    86U, 87U, 88U, 89U, 90U, 91U, 92U, 93U, 94U, 95U, 96U, 97U, 98U, 99U, 100U,
    101U, 102U, 103U, 104U, 105U, 106U, 107U, 108U, 109U, 110U, 111U, 112U, 113U,
    114U, 115U, 116U, 117U, 118U, 119U, 120U, 120U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 2U, 3U, 4U,
    5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U,
    21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U,
    36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U,
    51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U, 64U, 65U,
    66U, 67U, 68U, 69U, 70U, 71U, 72U, 73U, 74U, 75U, 76U, 77U, 78U, 79U, 80U,
    81U, 82U, 83U, 84U, 85U, 86U, 87U, 88U, 89U, 90U, 91U, 92U, 93U, 94U, 95U,
    96U, 97U, 98U, 99U, 100U, 101U, 102U, 103U, 104U, 105U, 106U, 107U, 108U,
    109U, 110U, 111U, 112U, 113U, 114U, 115U, 116U, 117U, 118U, 119U, 120U, 121U,
    122U, 123U, 124U, 125U, 126U, 127U, 128U, 129U, 130U, 131U, 132U, 133U, 134U,
    135U, 136U, 137U, 138U, 139U, 140U, 141U, 142U, 143U, 144U, 145U, 146U, 147U,
    148U, 149U, 150U, 151U, 152U, 153U, 154U, 155U, 156U, 157U, 158U, 159U, 160U,
    160U };

  static const real_T c[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0, 1.0
  };

  for (j = 0; j < 162; j++) {
    for (i = 0; i < 122; i++) {
      flightControlSystem_B.aTmp_c[i + 122 * j] = varargin_1[((d[j + 162] - 1) *
        120 + d[i]) - 1];
    }
  }

  for (j = 0; j < 19764; j++) {
    flightControlSystem_B.aTmp[j] = flightControlSystem_B.aTmp_c[j];
  }

  flightControlSystem_conv2(flightControlSystem_B.aTmp, c,
    flightControlSystem_B.dv);
  for (j = 0; j < 19200; j++) {
    b[j] = (real32_T)flightControlSystem_B.dv[j];
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_imfilter_k3(const real32_T varargin_1[19200],
  real32_T b[19200])
{
  static const uint8_T d[324] = { 1U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U,
    11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U,
    26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U,
    41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U,
    56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U, 64U, 65U, 66U, 67U, 68U, 69U, 70U,
    71U, 72U, 73U, 74U, 75U, 76U, 77U, 78U, 79U, 80U, 81U, 82U, 83U, 84U, 85U,
    86U, 87U, 88U, 89U, 90U, 91U, 92U, 93U, 94U, 95U, 96U, 97U, 98U, 99U, 100U,
    101U, 102U, 103U, 104U, 105U, 106U, 107U, 108U, 109U, 110U, 111U, 112U, 113U,
    114U, 115U, 116U, 117U, 118U, 119U, 120U, 120U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 2U, 3U, 4U,
    5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U,
    21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U,
    36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U,
    51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U, 64U, 65U,
    66U, 67U, 68U, 69U, 70U, 71U, 72U, 73U, 74U, 75U, 76U, 77U, 78U, 79U, 80U,
    81U, 82U, 83U, 84U, 85U, 86U, 87U, 88U, 89U, 90U, 91U, 92U, 93U, 94U, 95U,
    96U, 97U, 98U, 99U, 100U, 101U, 102U, 103U, 104U, 105U, 106U, 107U, 108U,
    109U, 110U, 111U, 112U, 113U, 114U, 115U, 116U, 117U, 118U, 119U, 120U, 121U,
    122U, 123U, 124U, 125U, 126U, 127U, 128U, 129U, 130U, 131U, 132U, 133U, 134U,
    135U, 136U, 137U, 138U, 139U, 140U, 141U, 142U, 143U, 144U, 145U, 146U, 147U,
    148U, 149U, 150U, 151U, 152U, 153U, 154U, 155U, 156U, 157U, 158U, 159U, 160U,
    160U };

  static const real_T c[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0, 1.0
  };

  for (flightControlSystem_B.j = 0; flightControlSystem_B.j < 162;
       flightControlSystem_B.j++) {
    for (flightControlSystem_B.i = 0; flightControlSystem_B.i < 122;
         flightControlSystem_B.i++) {
      flightControlSystem_B.aTmp_b[flightControlSystem_B.i + 122 *
        flightControlSystem_B.j] = varargin_1[((d[flightControlSystem_B.j + 162]
        - 1) * 120 + d[flightControlSystem_B.i]) - 1];
    }
  }

  for (flightControlSystem_B.j = 0; flightControlSystem_B.j < 19764;
       flightControlSystem_B.j++) {
    flightControlSystem_B.aTmp_m[flightControlSystem_B.j] =
      flightControlSystem_B.aTmp_b[flightControlSystem_B.j];
  }

  flightControlSystem_conv2(flightControlSystem_B.aTmp_m, c,
    flightControlSystem_B.dv1);
  for (flightControlSystem_B.j = 0; flightControlSystem_B.j < 19200;
       flightControlSystem_B.j++) {
    b[flightControlSystem_B.j] = (real32_T)
      flightControlSystem_B.dv1[flightControlSystem_B.j];
  }
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T b;
  real32_T y;
  a = (real32_T)fabs(u0);
  b = (real32_T)fabs(u1);
  if (a < b) {
    a /= b;
    y = (real32_T)sqrt(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = (real32_T)sqrt(b * b + 1.0F) * a;
  } else if (rtIsNaNF(b)) {
    y = (rtNaNF);
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

static void flightControlSystem_emxInit_int32_T
  (emxArray_int32_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_int32_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxEnsureCapacity_int32_T
  (emxArray_int32_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_eml_find(const boolean_T x[19200],
  emxArray_int32_T_flightControlSystem_T *i,
  emxArray_int32_T_flightControlSystem_T *j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  boolean_T exitg1;
  boolean_T guard1;
  idx = 0;
  ii = i->size[0];
  i->size[0] = 19200;
  flightControlSystem_emxEnsureCapacity_int32_T(i, ii);
  ii = j->size[0];
  j->size[0] = 19200;
  flightControlSystem_emxEnsureCapacity_int32_T(j, ii);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 160)) {
    guard1 = false;
    if (x[((jj - 1) * 120 + ii) - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      j->data[idx - 1] = jj;
      if (idx >= 19200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 120) {
        ii = 1;
        jj++;
      }
    }
  }

  if (idx < 1) {
    i->size[0] = 0;
    j->size[0] = 0;
  } else {
    ii = i->size[0];
    i->size[0] = idx;
    flightControlSystem_emxEnsureCapacity_int32_T(i, ii);
    ii = j->size[0];
    j->size[0] = idx;
    flightControlSystem_emxEnsureCapacity_int32_T(j, ii);
  }
}

static void flightControlSystem_emxInit_real32_T
  (emxArray_real32_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real32_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real32_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_real32_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxInit_creal_T
  (emxArray_creal_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_creal_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_creal_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_creal_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxInit_boolean_T
  (emxArray_boolean_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_boolean_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxEnsureCapacity_real32_T
  (emxArray_real32_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(real32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxEnsureCapacity_creal_T
  (emxArray_creal_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(creal_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(creal_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (creal_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxEnsureCapacity_boolean_T
  (emxArray_boolean_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

static void flightControlSystem_emxFree_int32_T
  (emxArray_int32_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxFree_creal_T
  (emxArray_creal_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_creal_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxFree_boolean_T
  (emxArray_boolean_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxFree_real32_T
  (emxArray_real32_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (real32_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real32_T_flightControlSystem_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_chaccum(const boolean_T varargin_1[19200],
  creal_T accumMatrix[19200], real32_T gradientImg[19200])
{
  emxArray_boolean_T_flightControlSystem_T *inside;
  emxArray_creal_T_flightControlSystem_T *w;
  emxArray_creal_T_flightControlSystem_T *wkeep;
  emxArray_int32_T_flightControlSystem_T *Ex_chunk;
  emxArray_int32_T_flightControlSystem_T *Ey_chunk;
  emxArray_int32_T_flightControlSystem_T *idxE_chunk;
  emxArray_int32_T_flightControlSystem_T *ii;
  emxArray_int32_T_flightControlSystem_T *jj;
  emxArray_int32_T_flightControlSystem_T *ndx;
  emxArray_int32_T_flightControlSystem_T *xckeep;
  emxArray_int32_T_flightControlSystem_T *yckeep;
  emxArray_real32_T_flightControlSystem_T *xc;
  emxArray_real32_T_flightControlSystem_T *yc;
  static const real_T j[31] = { -3.1415926535897931, -2.80702892618285,
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

  static const real_T l[31] = { 62.831853071795862, 65.973445725385659,
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

  boolean_T exitg1;
  flightControlSystem_B.c_idx_b = varargin_1[0];
  for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e < 19200;
       flightControlSystem_B.d_e++) {
    flightControlSystem_B.rows_to_keep_data[flightControlSystem_B.d_e] =
      (varargin_1[flightControlSystem_B.d_e] == flightControlSystem_B.c_idx_b);
  }

  flightControlSystem_B.flat_p = true;
  flightControlSystem_B.c_idx_b = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.c_idx_b < 19200)) {
    if (!flightControlSystem_B.rows_to_keep_data[flightControlSystem_B.c_idx_b])
    {
      flightControlSystem_B.flat_p = false;
      exitg1 = true;
    } else {
      flightControlSystem_B.c_idx_b++;
    }
  }

  if (flightControlSystem_B.flat_p) {
    memset(&accumMatrix[0], 0, 19200U * sizeof(creal_T));
    memset(&gradientImg[0], 0, 19200U * sizeof(real32_T));
  } else {
    for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e < 19200;
         flightControlSystem_B.d_e++) {
      flightControlSystem_B.varargin_1[flightControlSystem_B.d_e] =
        varargin_1[flightControlSystem_B.d_e];
    }

    flightControlSystem_imfilter(flightControlSystem_B.varargin_1,
      flightControlSystem_B.b_I);
    flightControlSystem_imfilter_k(flightControlSystem_B.b_I,
      flightControlSystem_B.varargin_1);
    flightControlSystem_imfilter_k3(flightControlSystem_B.b_I,
      flightControlSystem_B.Gy);
    for (flightControlSystem_B.c_idx_b = 0; flightControlSystem_B.c_idx_b <
         19200; flightControlSystem_B.c_idx_b++) {
      gradientImg[flightControlSystem_B.c_idx_b] = rt_hypotf_snf
        (flightControlSystem_B.varargin_1[flightControlSystem_B.c_idx_b],
         flightControlSystem_B.Gy[flightControlSystem_B.c_idx_b]);
    }

    if (!rtIsNaNF(gradientImg[0])) {
      flightControlSystem_B.c_idx_b = 1;
    } else {
      flightControlSystem_B.c_idx_b = 0;
      flightControlSystem_B.b_k_j = 2;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.b_k_j < 19201)) {
        if (!rtIsNaNF(gradientImg[flightControlSystem_B.b_k_j - 1])) {
          flightControlSystem_B.c_idx_b = flightControlSystem_B.b_k_j;
          exitg1 = true;
        } else {
          flightControlSystem_B.b_k_j++;
        }
      }
    }

    if (flightControlSystem_B.c_idx_b == 0) {
      flightControlSystem_B.Gmax = gradientImg[0];
    } else {
      flightControlSystem_B.Gmax = gradientImg[flightControlSystem_B.c_idx_b - 1];
      for (flightControlSystem_B.b_k_j = flightControlSystem_B.c_idx_b + 1;
           flightControlSystem_B.b_k_j < 19201; flightControlSystem_B.b_k_j++) {
        flightControlSystem_B.t = gradientImg[flightControlSystem_B.b_k_j - 1];
        if (flightControlSystem_B.Gmax < flightControlSystem_B.t) {
          flightControlSystem_B.Gmax = flightControlSystem_B.t;
        }
      }
    }

    flightControlSystem_B.t = flightControlSystem_B.Gmax * 0.25F;
    for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e < 19200;
         flightControlSystem_B.d_e++) {
      flightControlSystem_B.rows_to_keep_data[flightControlSystem_B.d_e] =
        (gradientImg[flightControlSystem_B.d_e] > flightControlSystem_B.t);
    }

    flightControlSystem_emxInit_int32_T(&ii, 1);
    flightControlSystem_emxInit_int32_T(&jj, 1);
    flightControlSystem_eml_find(flightControlSystem_B.rows_to_keep_data, ii, jj);
    flightControlSystem_emxInit_int32_T(&ndx, 1);
    flightControlSystem_B.loop_ub_f = ii->size[0];
    flightControlSystem_B.Ex_chunk_tmp = ndx->size[0];
    ndx->size[0] = ii->size[0];
    flightControlSystem_emxEnsureCapacity_int32_T(ndx,
      flightControlSystem_B.Ex_chunk_tmp);
    for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e <
         flightControlSystem_B.loop_ub_f; flightControlSystem_B.d_e++) {
      ndx->data[flightControlSystem_B.d_e] = (jj->data[flightControlSystem_B.d_e]
        - 1) * 120 + ii->data[flightControlSystem_B.d_e];
    }

    for (flightControlSystem_B.c_idx_b = 0; flightControlSystem_B.c_idx_b < 31;
         flightControlSystem_B.c_idx_b++) {
      flightControlSystem_B.Opca_im = j[flightControlSystem_B.c_idx_b];
      flightControlSystem_B.Opca_re = cos(flightControlSystem_B.Opca_im);
      flightControlSystem_B.Opca_im = sin(flightControlSystem_B.Opca_im);
      flightControlSystem_B.br = l[flightControlSystem_B.c_idx_b];
      if (flightControlSystem_B.Opca_im == 0.0) {
        flightControlSystem_B.Opca[flightControlSystem_B.c_idx_b].re =
          flightControlSystem_B.Opca_re / flightControlSystem_B.br;
        flightControlSystem_B.Opca[flightControlSystem_B.c_idx_b].im = 0.0;
      } else if (flightControlSystem_B.Opca_re == 0.0) {
        flightControlSystem_B.Opca[flightControlSystem_B.c_idx_b].re = 0.0;
        flightControlSystem_B.Opca[flightControlSystem_B.c_idx_b].im =
          flightControlSystem_B.Opca_im / flightControlSystem_B.br;
      } else {
        flightControlSystem_B.Opca[flightControlSystem_B.c_idx_b].re =
          flightControlSystem_B.Opca_re / flightControlSystem_B.br;
        flightControlSystem_B.Opca[flightControlSystem_B.c_idx_b].im =
          flightControlSystem_B.Opca_im / flightControlSystem_B.br;
      }
    }

    memset(&flightControlSystem_B.accumMatrix_tmp[0], 0, 19200U * sizeof(creal_T));
    memset(&accumMatrix[0], 0, 19200U * sizeof(creal_T));
    flightControlSystem_B.c_idx_b = (int32_T)(((real_T)jj->size[0] + 32257.0) /
      32258.0);
    flightControlSystem_emxInit_int32_T(&Ex_chunk, 1);
    flightControlSystem_emxInit_int32_T(&Ey_chunk, 1);
    flightControlSystem_emxInit_int32_T(&idxE_chunk, 1);
    flightControlSystem_emxInit_real32_T(&xc, 2);
    flightControlSystem_emxInit_real32_T(&yc, 2);
    flightControlSystem_emxInit_creal_T(&w, 2);
    flightControlSystem_emxInit_boolean_T(&inside, 2);
    flightControlSystem_emxInit_int32_T(&xckeep, 1);
    flightControlSystem_emxInit_int32_T(&yckeep, 1);
    flightControlSystem_emxInit_creal_T(&wkeep, 1);
    for (flightControlSystem_B.b_k_j = 0; flightControlSystem_B.b_k_j <
         flightControlSystem_B.c_idx_b; flightControlSystem_B.b_k_j++) {
      flightControlSystem_B.idxkeep = flightControlSystem_B.b_k_j * 32258 + 1;
      if (jj->size[0] < flightControlSystem_B.idxkeep) {
        flightControlSystem_B.c_size_idx_1 = 0;
      } else {
        flightControlSystem_B.loop_ub_f = jj->size[0] -
          flightControlSystem_B.idxkeep;
        flightControlSystem_B.c_size_idx_1 = flightControlSystem_B.loop_ub_f + 1;
      }

      flightControlSystem_B.Ex_chunk_tmp = Ex_chunk->size[0];
      Ex_chunk->size[0] = flightControlSystem_B.c_size_idx_1;
      flightControlSystem_emxEnsureCapacity_int32_T(Ex_chunk,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = Ey_chunk->size[0];
      Ey_chunk->size[0] = flightControlSystem_B.c_size_idx_1;
      flightControlSystem_emxEnsureCapacity_int32_T(Ey_chunk,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = idxE_chunk->size[0];
      idxE_chunk->size[0] = flightControlSystem_B.c_size_idx_1;
      flightControlSystem_emxEnsureCapacity_int32_T(idxE_chunk,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.d_e = flightControlSystem_B.c_size_idx_1 - 1;
      for (flightControlSystem_B.loop_ub_f = 0; flightControlSystem_B.loop_ub_f <=
           flightControlSystem_B.d_e; flightControlSystem_B.loop_ub_f++) {
        flightControlSystem_B.Ex_chunk_tmp = (flightControlSystem_B.idxkeep +
          flightControlSystem_B.loop_ub_f) - 1;
        Ex_chunk->data[flightControlSystem_B.loop_ub_f] = jj->
          data[flightControlSystem_B.Ex_chunk_tmp];
        Ey_chunk->data[flightControlSystem_B.loop_ub_f] = ii->
          data[flightControlSystem_B.Ex_chunk_tmp];
        idxE_chunk->data[flightControlSystem_B.loop_ub_f] = ndx->
          data[flightControlSystem_B.Ex_chunk_tmp];
      }

      flightControlSystem_B.Ex_chunk_tmp = xc->size[0] * xc->size[1];
      xc->size[0] = flightControlSystem_B.c_size_idx_1;
      xc->size[1] = 31;
      flightControlSystem_emxEnsureCapacity_real32_T(xc,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = yc->size[0] * yc->size[1];
      yc->size[0] = flightControlSystem_B.c_size_idx_1;
      yc->size[1] = 31;
      flightControlSystem_emxEnsureCapacity_real32_T(yc,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = w->size[0] * w->size[1];
      w->size[0] = flightControlSystem_B.c_size_idx_1;
      w->size[1] = 31;
      flightControlSystem_emxEnsureCapacity_creal_T(w,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = inside->size[0] * inside->size[1];
      inside->size[0] = flightControlSystem_B.c_size_idx_1;
      inside->size[1] = 31;
      flightControlSystem_emxEnsureCapacity_boolean_T(inside,
        flightControlSystem_B.Ex_chunk_tmp);
      if (flightControlSystem_B.c_size_idx_1 - 1 >= 0) {
        memset(&flightControlSystem_B.rows_to_keep_data[0], 0, (uint32_T)
               flightControlSystem_B.c_size_idx_1 * sizeof(boolean_T));
      }

      for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e < 31;
           flightControlSystem_B.d_e++) {
        for (flightControlSystem_B.idxkeep = 0; flightControlSystem_B.idxkeep <
             flightControlSystem_B.c_size_idx_1; flightControlSystem_B.idxkeep++)
        {
          flightControlSystem_B.loop_ub_f = idxE_chunk->
            data[flightControlSystem_B.idxkeep];
          flightControlSystem_B.Gmax = (real32_T)-(0.5 * (real_T)
            flightControlSystem_B.d_e + 10.0);
          flightControlSystem_B.xc_tmp =
            gradientImg[flightControlSystem_B.loop_ub_f - 1];
          flightControlSystem_B.t = rt_roundf_snf
            (flightControlSystem_B.varargin_1[flightControlSystem_B.loop_ub_f -
             1] / flightControlSystem_B.xc_tmp * flightControlSystem_B.Gmax +
             (real32_T)Ex_chunk->data[flightControlSystem_B.idxkeep]);
          xc->data[flightControlSystem_B.idxkeep + xc->size[0] *
            flightControlSystem_B.d_e] = flightControlSystem_B.t;
          flightControlSystem_B.Gmax = rt_roundf_snf
            (flightControlSystem_B.Gy[flightControlSystem_B.loop_ub_f - 1] /
             flightControlSystem_B.xc_tmp * flightControlSystem_B.Gmax +
             (real32_T)Ey_chunk->data[flightControlSystem_B.idxkeep]);
          yc->data[flightControlSystem_B.idxkeep + yc->size[0] *
            flightControlSystem_B.d_e] = flightControlSystem_B.Gmax;
          w->data[flightControlSystem_B.idxkeep + w->size[0] *
            flightControlSystem_B.d_e] =
            flightControlSystem_B.Opca[flightControlSystem_B.d_e];
          flightControlSystem_B.flat_p = ((flightControlSystem_B.t >= 1.0F) &&
            (flightControlSystem_B.t <= 160.0F) && (flightControlSystem_B.Gmax >=
            1.0F) && (flightControlSystem_B.Gmax <= 120.0F));
          inside->data[flightControlSystem_B.idxkeep + inside->size[0] *
            flightControlSystem_B.d_e] = flightControlSystem_B.flat_p;
          if (flightControlSystem_B.flat_p) {
            flightControlSystem_B.rows_to_keep_data[flightControlSystem_B.idxkeep]
              = true;
          }
        }
      }

      flightControlSystem_B.d_e = xc->size[0] * 31;
      flightControlSystem_B.Ex_chunk_tmp = xckeep->size[0];
      xckeep->size[0] = flightControlSystem_B.d_e;
      flightControlSystem_emxEnsureCapacity_int32_T(xckeep,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = yckeep->size[0];
      yckeep->size[0] = flightControlSystem_B.d_e;
      flightControlSystem_emxEnsureCapacity_int32_T(yckeep,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.Ex_chunk_tmp = wkeep->size[0];
      wkeep->size[0] = flightControlSystem_B.d_e;
      flightControlSystem_emxEnsureCapacity_creal_T(wkeep,
        flightControlSystem_B.Ex_chunk_tmp);
      flightControlSystem_B.idxkeep = -1;
      for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e < 31;
           flightControlSystem_B.d_e++) {
        for (flightControlSystem_B.loop_ub_f = 0;
             flightControlSystem_B.loop_ub_f <
             flightControlSystem_B.c_size_idx_1; flightControlSystem_B.loop_ub_f
             ++) {
          if (flightControlSystem_B.rows_to_keep_data[flightControlSystem_B.loop_ub_f]
              && inside->data[inside->size[0] * flightControlSystem_B.d_e +
              flightControlSystem_B.loop_ub_f]) {
            flightControlSystem_B.idxkeep++;
            xckeep->data[flightControlSystem_B.idxkeep] = (int32_T)xc->data
              [xc->size[0] * flightControlSystem_B.d_e +
              flightControlSystem_B.loop_ub_f];
            yckeep->data[flightControlSystem_B.idxkeep] = (int32_T)yc->data
              [yc->size[0] * flightControlSystem_B.d_e +
              flightControlSystem_B.loop_ub_f];
            wkeep->data[flightControlSystem_B.idxkeep] = w->data[w->size[0] *
              flightControlSystem_B.d_e + flightControlSystem_B.loop_ub_f];
          }
        }
      }

      memcpy(&flightControlSystem_B.out[0],
             &flightControlSystem_B.accumMatrix_tmp[0], 19200U * sizeof(creal_T));
      for (flightControlSystem_B.loop_ub_f = 0; flightControlSystem_B.loop_ub_f <=
           flightControlSystem_B.idxkeep; flightControlSystem_B.loop_ub_f++) {
        flightControlSystem_B.d_e = ((xckeep->
          data[flightControlSystem_B.loop_ub_f] - 1) * 120 + yckeep->
          data[flightControlSystem_B.loop_ub_f]) - 1;
        flightControlSystem_B.out[flightControlSystem_B.d_e].re += wkeep->
          data[flightControlSystem_B.loop_ub_f].re;
        flightControlSystem_B.out[flightControlSystem_B.d_e].im += wkeep->
          data[flightControlSystem_B.loop_ub_f].im;
      }

      for (flightControlSystem_B.d_e = 0; flightControlSystem_B.d_e < 19200;
           flightControlSystem_B.d_e++) {
        accumMatrix[flightControlSystem_B.d_e].re +=
          flightControlSystem_B.out[flightControlSystem_B.d_e].re;
        accumMatrix[flightControlSystem_B.d_e].im +=
          flightControlSystem_B.out[flightControlSystem_B.d_e].im;
      }
    }

    flightControlSystem_emxFree_int32_T(&jj);
    flightControlSystem_emxFree_int32_T(&ii);
    flightControlSystem_emxFree_int32_T(&ndx);
    flightControlSystem_emxFree_creal_T(&wkeep);
    flightControlSystem_emxFree_int32_T(&yckeep);
    flightControlSystem_emxFree_int32_T(&xckeep);
    flightControlSystem_emxFree_boolean_T(&inside);
    flightControlSystem_emxFree_creal_T(&w);
    flightControlSystem_emxFree_real32_T(&yc);
    flightControlSystem_emxFree_real32_T(&xc);
    flightControlSystem_emxFree_int32_T(&idxE_chunk);
    flightControlSystem_emxFree_int32_T(&Ey_chunk);
    flightControlSystem_emxFree_int32_T(&Ex_chunk);
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static real_T flightControlSystem_median25(real_T vec[25])
{
  real_T temp;
  if (vec[0] > vec[1]) {
    temp = vec[0];
    vec[0] = vec[1];
    vec[1] = temp;
  }

  if (vec[3] > vec[4]) {
    temp = vec[3];
    vec[3] = vec[4];
    vec[4] = temp;
  }

  if (vec[2] > vec[4]) {
    temp = vec[2];
    vec[2] = vec[4];
    vec[4] = temp;
  }

  if (vec[2] > vec[3]) {
    temp = vec[2];
    vec[2] = vec[3];
    vec[3] = temp;
  }

  if (vec[6] > vec[7]) {
    temp = vec[6];
    vec[6] = vec[7];
    vec[7] = temp;
  }

  if (vec[5] > vec[7]) {
    temp = vec[5];
    vec[5] = vec[7];
    vec[7] = temp;
  }

  if (vec[5] > vec[6]) {
    temp = vec[5];
    vec[5] = vec[6];
    vec[6] = temp;
  }

  if (vec[9] > vec[10]) {
    temp = vec[9];
    vec[9] = vec[10];
    vec[10] = temp;
  }

  if (vec[8] > vec[10]) {
    temp = vec[8];
    vec[8] = vec[10];
    vec[10] = temp;
  }

  if (vec[8] > vec[9]) {
    temp = vec[8];
    vec[8] = vec[9];
    vec[9] = temp;
  }

  if (vec[12] > vec[13]) {
    temp = vec[12];
    vec[12] = vec[13];
    vec[13] = temp;
  }

  if (vec[11] > vec[13]) {
    temp = vec[11];
    vec[11] = vec[13];
    vec[13] = temp;
  }

  if (vec[11] > vec[12]) {
    temp = vec[11];
    vec[11] = vec[12];
    vec[12] = temp;
  }

  if (vec[15] > vec[16]) {
    temp = vec[15];
    vec[15] = vec[16];
    vec[16] = temp;
  }

  if (vec[14] > vec[16]) {
    temp = vec[14];
    vec[14] = vec[16];
    vec[16] = temp;
  }

  if (vec[14] > vec[15]) {
    temp = vec[14];
    vec[14] = vec[15];
    vec[15] = temp;
  }

  if (vec[18] > vec[19]) {
    temp = vec[18];
    vec[18] = vec[19];
    vec[19] = temp;
  }

  if (vec[17] > vec[19]) {
    temp = vec[17];
    vec[17] = vec[19];
    vec[19] = temp;
  }

  if (vec[17] > vec[18]) {
    temp = vec[17];
    vec[17] = vec[18];
    vec[18] = temp;
  }

  if (vec[21] > vec[22]) {
    temp = vec[21];
    vec[21] = vec[22];
    vec[22] = temp;
  }

  if (vec[20] > vec[22]) {
    temp = vec[20];
    vec[20] = vec[22];
    vec[22] = temp;
  }

  if (vec[20] > vec[21]) {
    temp = vec[20];
    vec[20] = vec[21];
    vec[21] = temp;
  }

  if (vec[23] > vec[24]) {
    temp = vec[23];
    vec[23] = vec[24];
    vec[24] = temp;
  }

  if (vec[2] > vec[5]) {
    temp = vec[2];
    vec[2] = vec[5];
    vec[5] = temp;
  }

  if (vec[3] > vec[6]) {
    temp = vec[3];
    vec[3] = vec[6];
    vec[6] = temp;
  }

  if (vec[0] > vec[6]) {
    temp = vec[0];
    vec[0] = vec[6];
    vec[6] = temp;
  }

  if (vec[0] > vec[3]) {
    temp = vec[0];
    vec[0] = vec[3];
    vec[3] = temp;
  }

  if (vec[4] > vec[7]) {
    temp = vec[4];
    vec[4] = vec[7];
    vec[7] = temp;
  }

  if (vec[1] > vec[7]) {
    temp = vec[1];
    vec[1] = vec[7];
    vec[7] = temp;
  }

  if (vec[1] > vec[4]) {
    temp = vec[1];
    vec[1] = vec[4];
    vec[4] = temp;
  }

  if (vec[11] > vec[14]) {
    temp = vec[11];
    vec[11] = vec[14];
    vec[14] = temp;
  }

  if (vec[8] > vec[14]) {
    temp = vec[8];
    vec[8] = vec[14];
    vec[14] = temp;
  }

  if (vec[8] > vec[11]) {
    temp = vec[8];
    vec[8] = vec[11];
    vec[11] = temp;
  }

  if (vec[12] > vec[15]) {
    temp = vec[12];
    vec[12] = vec[15];
    vec[15] = temp;
  }

  if (vec[9] > vec[15]) {
    temp = vec[9];
    vec[9] = vec[15];
    vec[15] = temp;
  }

  if (vec[9] > vec[12]) {
    temp = vec[9];
    vec[9] = vec[12];
    vec[12] = temp;
  }

  if (vec[13] > vec[16]) {
    temp = vec[13];
    vec[13] = vec[16];
    vec[16] = temp;
  }

  if (vec[10] > vec[16]) {
    temp = vec[10];
    vec[10] = vec[16];
    vec[16] = temp;
  }

  if (vec[10] > vec[13]) {
    temp = vec[10];
    vec[10] = vec[13];
    vec[13] = temp;
  }

  if (vec[20] > vec[23]) {
    temp = vec[20];
    vec[20] = vec[23];
    vec[23] = temp;
  }

  if (vec[17] > vec[23]) {
    temp = vec[17];
    vec[17] = vec[23];
    vec[23] = temp;
  }

  if (vec[17] > vec[20]) {
    temp = vec[17];
    vec[17] = vec[20];
    vec[20] = temp;
  }

  if (vec[21] > vec[24]) {
    temp = vec[21];
    vec[21] = vec[24];
    vec[24] = temp;
  }

  if (vec[18] > vec[24]) {
    temp = vec[18];
    vec[18] = vec[24];
    vec[24] = temp;
  }

  if (vec[18] > vec[21]) {
    temp = vec[18];
    vec[18] = vec[21];
    vec[21] = temp;
  }

  if (vec[19] > vec[22]) {
    temp = vec[19];
    vec[19] = vec[22];
    vec[22] = temp;
  }

  if (vec[8] > vec[17]) {
    vec[17] = vec[8];
  }

  if (vec[9] > vec[18]) {
    temp = vec[9];
    vec[9] = vec[18];
    vec[18] = temp;
  }

  if (vec[0] > vec[18]) {
    temp = vec[0];
    vec[0] = vec[18];
    vec[18] = temp;
  }

  if (vec[0] > vec[9]) {
    vec[9] = vec[0];
  }

  if (vec[10] > vec[19]) {
    temp = vec[10];
    vec[10] = vec[19];
    vec[19] = temp;
  }

  if (vec[1] > vec[19]) {
    temp = vec[1];
    vec[1] = vec[19];
    vec[19] = temp;
  }

  if (vec[1] > vec[10]) {
    temp = vec[1];
    vec[1] = vec[10];
    vec[10] = temp;
  }

  if (vec[11] > vec[20]) {
    temp = vec[11];
    vec[11] = vec[20];
    vec[20] = temp;
  }

  if (vec[2] > vec[20]) {
    temp = vec[2];
    vec[2] = vec[20];
    vec[20] = temp;
  }

  if (vec[2] > vec[11]) {
    vec[11] = vec[2];
  }

  if (vec[12] > vec[21]) {
    temp = vec[12];
    vec[12] = vec[21];
    vec[21] = temp;
  }

  if (vec[3] > vec[21]) {
    temp = vec[3];
    vec[3] = vec[21];
    vec[21] = temp;
  }

  if (vec[3] > vec[12]) {
    temp = vec[3];
    vec[3] = vec[12];
    vec[12] = temp;
  }

  if (vec[13] > vec[22]) {
    temp = vec[13];
    vec[13] = vec[22];
    vec[22] = temp;
  }

  if (vec[4] > vec[22]) {
    vec[4] = vec[22];
  }

  if (vec[4] > vec[13]) {
    temp = vec[4];
    vec[4] = vec[13];
    vec[13] = temp;
  }

  if (vec[14] > vec[23]) {
    temp = vec[14];
    vec[14] = vec[23];
    vec[23] = temp;
  }

  if (vec[5] > vec[23]) {
    temp = vec[5];
    vec[5] = vec[23];
    vec[23] = temp;
  }

  if (vec[5] > vec[14]) {
    temp = vec[5];
    vec[5] = vec[14];
    vec[14] = temp;
  }

  if (vec[15] > vec[24]) {
    temp = vec[15];
    vec[15] = vec[24];
    vec[24] = temp;
  }

  if (vec[6] > vec[24]) {
    vec[6] = vec[24];
  }

  if (vec[6] > vec[15]) {
    temp = vec[6];
    vec[6] = vec[15];
    vec[15] = temp;
  }

  if (vec[7] > vec[16]) {
    vec[7] = vec[16];
  }

  if (vec[7] > vec[19]) {
    vec[7] = vec[19];
  }

  if (vec[13] > vec[21]) {
    vec[13] = vec[21];
  }

  if (vec[15] > vec[23]) {
    vec[15] = vec[23];
  }

  if (vec[7] > vec[13]) {
    vec[7] = vec[13];
  }

  if (vec[7] > vec[15]) {
    vec[7] = vec[15];
  }

  if (vec[1] > vec[9]) {
    vec[9] = vec[1];
  }

  if (vec[3] > vec[11]) {
    vec[11] = vec[3];
  }

  if (vec[5] > vec[17]) {
    vec[17] = vec[5];
  }

  if (vec[11] > vec[17]) {
    vec[17] = vec[11];
  }

  if (vec[9] > vec[17]) {
    vec[17] = vec[9];
  }

  if (vec[4] > vec[10]) {
    temp = vec[4];
    vec[4] = vec[10];
    vec[10] = temp;
  }

  if (vec[6] > vec[12]) {
    temp = vec[6];
    vec[6] = vec[12];
    vec[12] = temp;
  }

  if (vec[7] > vec[14]) {
    temp = vec[7];
    vec[7] = vec[14];
    vec[14] = temp;
  }

  if (vec[4] > vec[6]) {
    temp = vec[4];
    vec[4] = vec[6];
    vec[6] = temp;
  }

  if (vec[4] > vec[7]) {
    vec[7] = vec[4];
  }

  if (vec[12] > vec[14]) {
    temp = vec[12];
    vec[12] = vec[14];
    vec[14] = temp;
  }

  if (vec[10] > vec[14]) {
    vec[10] = vec[14];
  }

  if (vec[6] > vec[7]) {
    temp = vec[6];
    vec[6] = vec[7];
    vec[7] = temp;
  }

  if (vec[10] > vec[12]) {
    temp = vec[10];
    vec[10] = vec[12];
    vec[12] = temp;
  }

  if (vec[6] > vec[10]) {
    temp = vec[6];
    vec[6] = vec[10];
    vec[10] = temp;
  }

  if (vec[6] > vec[17]) {
    vec[17] = vec[6];
  }

  if (vec[12] > vec[17]) {
    temp = vec[12];
    vec[12] = vec[17];
    vec[17] = temp;
  }

  if (vec[7] > vec[17]) {
    vec[7] = vec[17];
  }

  if (vec[7] > vec[10]) {
    temp = vec[7];
    vec[7] = vec[10];
    vec[10] = temp;
  }

  if (vec[12] > vec[18]) {
    temp = vec[12];
    vec[12] = vec[18];
    vec[18] = temp;
  }

  if (vec[7] > vec[12]) {
    vec[12] = vec[7];
  }

  if (vec[10] > vec[18]) {
    vec[10] = vec[18];
  }

  if (vec[12] > vec[20]) {
    temp = vec[12];
    vec[12] = vec[20];
    vec[20] = temp;
  }

  if (vec[10] > vec[20]) {
    vec[10] = vec[20];
  }

  if (vec[10] > vec[12]) {
    vec[12] = vec[10];
  }

  return vec[12];
}

static real_T flightControlSystem_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      flightControlSystem_B.q = ceil(u1);
    } else {
      flightControlSystem_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != flightControlSystem_B.q)) {
      flightControlSystem_B.q = fabs(u0 / u1);
      if (!(fabs(flightControlSystem_B.q - floor(flightControlSystem_B.q + 0.5))
            > DBL_EPSILON * flightControlSystem_B.q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_NeighborhoodProcessor_computeParameters(const
  int32_T imSize[2], const boolean_T nhConn[9], int32_T loffsets[9], int32_T
  linds[9], int32_T soffsets[18], int32_T interiorStart[2], int32_T interiorEnd
  [2])
{
  flightControlSystem_B.pixelsPerImPage1_idx_1 = imSize[0];
  interiorStart[0] = 2;
  interiorEnd[0] = imSize[0] - 1;
  interiorStart[1] = 2;
  interiorEnd[1] = imSize[1] - 1;
  flightControlSystem_B.nz = nhConn[0];
  for (flightControlSystem_B.c_k = 0; flightControlSystem_B.c_k < 8;
       flightControlSystem_B.c_k++) {
    flightControlSystem_B.nz += nhConn[flightControlSystem_B.c_k + 1];
  }

  if (flightControlSystem_B.nz != 0) {
    flightControlSystem_B.indx = 0;
    for (flightControlSystem_B.c_k = 0; flightControlSystem_B.c_k < 9;
         flightControlSystem_B.c_k++) {
      if (nhConn[flightControlSystem_B.c_k]) {
        flightControlSystem_B.r_tmp = (int32_T)flightControlSystem_rt_remd_snf
          (((real_T)flightControlSystem_B.c_k + 1.0) - 1.0, 3.0);
        soffsets[flightControlSystem_B.indx] = flightControlSystem_B.r_tmp + 1;
        flightControlSystem_B.nz = (int32_T)((((real_T)
          (flightControlSystem_B.c_k - flightControlSystem_B.r_tmp) - 1.0) + 1.0)
          / 3.0);
        soffsets[flightControlSystem_B.indx + 9] = flightControlSystem_B.nz + 1;
        linds[flightControlSystem_B.indx] = ((int8_T)flightControlSystem_B.nz *
          3 + flightControlSystem_B.r_tmp) + 1;
        loffsets[flightControlSystem_B.indx] = ((int8_T)flightControlSystem_B.nz
          * flightControlSystem_B.pixelsPerImPage1_idx_1 +
          flightControlSystem_B.r_tmp) + 1;
        flightControlSystem_B.indx++;
      }
    }

    for (flightControlSystem_B.nz = 0; flightControlSystem_B.nz < 9;
         flightControlSystem_B.nz++) {
      loffsets[flightControlSystem_B.nz] = (loffsets[flightControlSystem_B.nz] -
        flightControlSystem_B.pixelsPerImPage1_idx_1) - 2;
    }

    memcpy(&flightControlSystem_B.a_f[0], &soffsets[0], 18U * sizeof(int32_T));
    for (flightControlSystem_B.c_k = 0; flightControlSystem_B.c_k < 9;
         flightControlSystem_B.c_k++) {
      soffsets[flightControlSystem_B.c_k] =
        flightControlSystem_B.a_f[flightControlSystem_B.c_k] - 2;
      soffsets[flightControlSystem_B.c_k + 9] =
        flightControlSystem_B.a_f[flightControlSystem_B.c_k + 9] - 2;
    }
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_bsxfun(const int32_T a[18], const int32_T b[2],
  int32_T c[18])
{
  int32_T b_0;
  int32_T b_1;
  int32_T b_k;
  b_0 = b[0];
  b_1 = b[1];
  for (b_k = 0; b_k < 9; b_k++) {
    c[b_k] = a[b_k] + b_0;
    c[b_k + 9] = a[b_k + 9] + b_1;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static real_T flightControlSystem_maximum(const real_T x_data[], const int32_T
  *x_size)
{
  real_T ex;
  boolean_T exitg1;
  flightControlSystem_B.last = *x_size;
  if (*x_size <= 2) {
    if (*x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[*x_size - 1];
      if ((x_data[0] < ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
      } else {
        ex = x_data[0];
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      flightControlSystem_B.idx = 1;
    } else {
      flightControlSystem_B.idx = 0;
      flightControlSystem_B.k_j = 2;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.k_j <=
                           flightControlSystem_B.last)) {
        if (!rtIsNaN(x_data[flightControlSystem_B.k_j - 1])) {
          flightControlSystem_B.idx = flightControlSystem_B.k_j;
          exitg1 = true;
        } else {
          flightControlSystem_B.k_j++;
        }
      }
    }

    if (flightControlSystem_B.idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[flightControlSystem_B.idx - 1];
      for (flightControlSystem_B.k_j = flightControlSystem_B.idx + 1;
           flightControlSystem_B.k_j <= flightControlSystem_B.last;
           flightControlSystem_B.k_j++) {
        flightControlSystem_B.x = x_data[flightControlSystem_B.k_j - 1];
        if (ex < flightControlSystem_B.x) {
          ex = flightControlSystem_B.x;
        }
      }
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_imhmax(const real_T b_I[19200], real_T J[19200])
{
  boolean_T exitg1;
  for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 19200;
       flightControlSystem_B.i_m3++) {
    flightControlSystem_B.b_I_b = b_I[flightControlSystem_B.i_m3];
    J[flightControlSystem_B.i_m3] = flightControlSystem_B.b_I_b -
      0.099999999999999964;
    if (flightControlSystem_B.b_I_b - 0.099999999999999964 >
        flightControlSystem_B.b_I_b) {
      J[flightControlSystem_B.i_m3] = flightControlSystem_B.b_I_b;
    }
  }

  for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
       flightControlSystem_B.i_m3++) {
    flightControlSystem_B.c_g[flightControlSystem_B.i_m3] = 0;
  }

  memset(&flightControlSystem_B.d[0], 0, 18U * sizeof(int32_T));
  flightControlSystem_B.pixelSub_d[0] = 120;
  flightControlSystem_B.pixelSub_d[1] = 160;
  for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
       flightControlSystem_B.i_m3++) {
    flightControlSystem_B.isInside_l[flightControlSystem_B.i_m3] = true;
  }

  flightControlSystem_NeighborhoodProcessor_computeParameters
    (flightControlSystem_B.pixelSub_d, flightControlSystem_B.isInside_l,
     flightControlSystem_B.c_g, flightControlSystem_B.imnhInds_,
     flightControlSystem_B.d, flightControlSystem_B.e_l, flightControlSystem_B.f);
  for (flightControlSystem_B.stackTop = 0; flightControlSystem_B.stackTop <
       19200; flightControlSystem_B.stackTop++) {
    flightControlSystem_B.c_ind = flightControlSystem_B.stackTop - 120 * div_s32
      (flightControlSystem_B.stackTop, 120);
    flightControlSystem_B.i_m3 = flightControlSystem_B.stackTop -
      flightControlSystem_B.c_ind;
    if (flightControlSystem_B.i_m3 >= 0) {
      flightControlSystem_B.d_x = flightControlSystem_B.i_m3;
    } else {
      flightControlSystem_B.d_x = -flightControlSystem_B.i_m3;
    }

    flightControlSystem_B.d_ind = flightControlSystem_B.d_x / 120;
    flightControlSystem_B.d_x -= flightControlSystem_B.d_ind * 120;
    if (flightControlSystem_B.d_x >= 60) {
      flightControlSystem_B.d_ind++;
    }

    if (flightControlSystem_B.i_m3 < 0) {
      flightControlSystem_B.d_ind = -flightControlSystem_B.d_ind;
    }

    flightControlSystem_B.pixelSub_d[0] = flightControlSystem_B.c_ind + 1;
    flightControlSystem_B.pixelSub_d[1] = flightControlSystem_B.d_ind + 1;
    flightControlSystem_bsxfun(flightControlSystem_B.d,
      flightControlSystem_B.pixelSub_d, flightControlSystem_B.imnhSubs_g);
    flightControlSystem_B.d_x = 0;
    for (flightControlSystem_B.c_ind = 0; flightControlSystem_B.c_ind < 9;
         flightControlSystem_B.c_ind++) {
      flightControlSystem_B.isInside_l[flightControlSystem_B.c_ind] = true;
      flightControlSystem_B.d_ind = 0;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.d_ind < 2)) {
        flightControlSystem_B.i_m3 = flightControlSystem_B.imnhSubs_g[9 *
          flightControlSystem_B.d_ind + flightControlSystem_B.c_ind];
        if ((flightControlSystem_B.i_m3 < 1) || (flightControlSystem_B.i_m3 > 40
             * flightControlSystem_B.d_ind + 120)) {
          flightControlSystem_B.isInside_l[flightControlSystem_B.c_ind] = false;
          exitg1 = true;
        } else {
          flightControlSystem_B.d_ind++;
        }
      }

      if (flightControlSystem_B.isInside_l[flightControlSystem_B.c_ind]) {
        flightControlSystem_B.d_x++;
      }
    }

    flightControlSystem_B.d_ind = flightControlSystem_B.d_x;
    flightControlSystem_B.d_x = 0;
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
         flightControlSystem_B.i_m3++) {
      if (flightControlSystem_B.isInside_l[flightControlSystem_B.i_m3]) {
        flightControlSystem_B.tmp_data_d[flightControlSystem_B.d_x] = (int8_T)
          flightControlSystem_B.i_m3;
        flightControlSystem_B.d_x++;
      }
    }

    flightControlSystem_B.J_size = flightControlSystem_B.d_ind;
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 <
         flightControlSystem_B.d_ind; flightControlSystem_B.i_m3++) {
      flightControlSystem_B.J_data[flightControlSystem_B.i_m3] =
        J[flightControlSystem_B.c_g[flightControlSystem_B.tmp_data_d[flightControlSystem_B.i_m3]]
        + flightControlSystem_B.stackTop];
    }

    flightControlSystem_B.u0 = flightControlSystem_maximum
      (flightControlSystem_B.J_data, &flightControlSystem_B.J_size);
    flightControlSystem_B.b_I_b = b_I[flightControlSystem_B.stackTop];
    if ((flightControlSystem_B.u0 <= flightControlSystem_B.b_I_b) || rtIsNaN
        (flightControlSystem_B.b_I_b)) {
      J[flightControlSystem_B.stackTop] = flightControlSystem_B.u0;
    } else {
      J[flightControlSystem_B.stackTop] = flightControlSystem_B.b_I_b;
    }
  }

  flightControlSystem_B.stackTop = -1;
  for (flightControlSystem_B.c_ind = 19199; flightControlSystem_B.c_ind >= 0;
       flightControlSystem_B.c_ind--) {
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
         flightControlSystem_B.i_m3++) {
      flightControlSystem_B.imnhInds_[flightControlSystem_B.i_m3] =
        (flightControlSystem_B.c_g[flightControlSystem_B.i_m3] +
         flightControlSystem_B.c_ind) + 1;
    }

    flightControlSystem_B.i_m3 = flightControlSystem_B.c_ind - 120 * div_s32
      (flightControlSystem_B.c_ind, 120);
    flightControlSystem_B.d_x = flightControlSystem_B.c_ind -
      flightControlSystem_B.i_m3;
    if (flightControlSystem_B.d_x >= 0) {
      flightControlSystem_B.d_ind = flightControlSystem_B.d_x;
    } else {
      flightControlSystem_B.d_ind = -flightControlSystem_B.d_x;
    }

    flightControlSystem_B.b_z = flightControlSystem_B.d_ind / 120;
    flightControlSystem_B.d_ind -= flightControlSystem_B.b_z * 120;
    if (flightControlSystem_B.d_ind >= 60) {
      flightControlSystem_B.b_z++;
    }

    if (flightControlSystem_B.d_x < 0) {
      flightControlSystem_B.b_z = -flightControlSystem_B.b_z;
    }

    flightControlSystem_B.pixelSub_d[0] = flightControlSystem_B.i_m3 + 1;
    flightControlSystem_B.pixelSub_d[1] = flightControlSystem_B.b_z + 1;
    flightControlSystem_bsxfun(flightControlSystem_B.d,
      flightControlSystem_B.pixelSub_d, flightControlSystem_B.imnhSubs_g);
    flightControlSystem_B.d_x = 0;
    for (flightControlSystem_B.d_ind = 0; flightControlSystem_B.d_ind < 9;
         flightControlSystem_B.d_ind++) {
      flightControlSystem_B.isInside_l[flightControlSystem_B.d_ind] = true;
      flightControlSystem_B.b_z = 0;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.b_z < 2)) {
        flightControlSystem_B.i_m3 = flightControlSystem_B.imnhSubs_g[9 *
          flightControlSystem_B.b_z + flightControlSystem_B.d_ind];
        if ((flightControlSystem_B.i_m3 < 1) || (flightControlSystem_B.i_m3 > 40
             * flightControlSystem_B.b_z + 120)) {
          flightControlSystem_B.isInside_l[flightControlSystem_B.d_ind] = false;
          exitg1 = true;
        } else {
          flightControlSystem_B.b_z++;
        }
      }

      if (flightControlSystem_B.isInside_l[flightControlSystem_B.d_ind]) {
        flightControlSystem_B.d_x++;
      }
    }

    flightControlSystem_B.d_ind = flightControlSystem_B.d_x;
    flightControlSystem_B.d_x = 0;
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
         flightControlSystem_B.i_m3++) {
      if (flightControlSystem_B.isInside_l[flightControlSystem_B.i_m3]) {
        flightControlSystem_B.tmp_data_j[flightControlSystem_B.d_x] = (int8_T)
          flightControlSystem_B.i_m3;
        flightControlSystem_B.d_x++;
      }
    }

    flightControlSystem_B.J_size = flightControlSystem_B.d_ind;
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 <
         flightControlSystem_B.d_ind; flightControlSystem_B.i_m3++) {
      flightControlSystem_B.J_data[flightControlSystem_B.i_m3] =
        J[flightControlSystem_B.c_g[flightControlSystem_B.tmp_data_j[flightControlSystem_B.i_m3]]
        + flightControlSystem_B.c_ind];
    }

    flightControlSystem_B.u0 = flightControlSystem_maximum
      (flightControlSystem_B.J_data, &flightControlSystem_B.J_size);
    flightControlSystem_B.b_I_b = b_I[flightControlSystem_B.c_ind];
    if ((flightControlSystem_B.u0 <= flightControlSystem_B.b_I_b) || rtIsNaN
        (flightControlSystem_B.b_I_b)) {
      J[flightControlSystem_B.c_ind] = flightControlSystem_B.u0;
    } else {
      J[flightControlSystem_B.c_ind] = flightControlSystem_B.b_I_b;
    }

    flightControlSystem_B.d_x = 0;
    exitg1 = false;
    while ((!exitg1) && (flightControlSystem_B.d_x <=
                         flightControlSystem_B.d_ind - 1)) {
      flightControlSystem_B.i_m3 =
        flightControlSystem_B.imnhInds_[flightControlSystem_B.tmp_data_j[flightControlSystem_B.d_x]]
        - 1;
      flightControlSystem_B.u0 = J[flightControlSystem_B.i_m3];
      if ((flightControlSystem_B.u0 < J[flightControlSystem_B.c_ind]) &&
          (flightControlSystem_B.u0 < b_I[flightControlSystem_B.i_m3])) {
        flightControlSystem_B.stackTop++;
        flightControlSystem_B.locationStack[flightControlSystem_B.stackTop] =
          flightControlSystem_B.c_ind + 1;
        exitg1 = true;
      } else {
        flightControlSystem_B.d_x++;
      }
    }
  }

  while (flightControlSystem_B.stackTop + 1 > 0) {
    flightControlSystem_B.c_ind =
      flightControlSystem_B.locationStack[flightControlSystem_B.stackTop] - 1;
    flightControlSystem_B.stackTop--;
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
         flightControlSystem_B.i_m3++) {
      flightControlSystem_B.imnhInds_[flightControlSystem_B.i_m3] =
        (flightControlSystem_B.c_g[flightControlSystem_B.i_m3] +
         flightControlSystem_B.c_ind) + 1;
    }

    flightControlSystem_B.i_m3 = flightControlSystem_B.c_ind - 120 * div_s32
      (flightControlSystem_B.c_ind, 120);
    flightControlSystem_B.d_x = flightControlSystem_B.c_ind -
      flightControlSystem_B.i_m3;
    if (flightControlSystem_B.d_x >= 0) {
      flightControlSystem_B.d_ind = flightControlSystem_B.d_x;
    } else if (flightControlSystem_B.d_x == MIN_int32_T) {
      flightControlSystem_B.d_ind = MAX_int32_T;
    } else {
      flightControlSystem_B.d_ind = -flightControlSystem_B.d_x;
    }

    flightControlSystem_B.b_z = flightControlSystem_B.d_ind / 120;
    flightControlSystem_B.d_ind -= flightControlSystem_B.b_z * 120;
    if (flightControlSystem_B.d_ind >= 60) {
      flightControlSystem_B.b_z++;
    }

    if (flightControlSystem_B.d_x < 0) {
      flightControlSystem_B.b_z = -flightControlSystem_B.b_z;
    }

    flightControlSystem_B.pixelSub_d[0] = flightControlSystem_B.i_m3 + 1;
    flightControlSystem_B.pixelSub_d[1] = flightControlSystem_B.b_z + 1;
    flightControlSystem_bsxfun(flightControlSystem_B.d,
      flightControlSystem_B.pixelSub_d, flightControlSystem_B.imnhSubs_g);
    flightControlSystem_B.d_x = 0;
    for (flightControlSystem_B.d_ind = 0; flightControlSystem_B.d_ind < 9;
         flightControlSystem_B.d_ind++) {
      flightControlSystem_B.isInside_l[flightControlSystem_B.d_ind] = true;
      flightControlSystem_B.b_z = 0;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.b_z < 2)) {
        flightControlSystem_B.i_m3 = flightControlSystem_B.imnhSubs_g[9 *
          flightControlSystem_B.b_z + flightControlSystem_B.d_ind];
        if ((flightControlSystem_B.i_m3 < 1) || (flightControlSystem_B.i_m3 > 40
             * flightControlSystem_B.b_z + 120)) {
          flightControlSystem_B.isInside_l[flightControlSystem_B.d_ind] = false;
          exitg1 = true;
        } else {
          flightControlSystem_B.b_z++;
        }
      }

      if (flightControlSystem_B.isInside_l[flightControlSystem_B.d_ind]) {
        flightControlSystem_B.d_x++;
      }
    }

    flightControlSystem_B.b_z = flightControlSystem_B.d_x;
    flightControlSystem_B.d_x = 0;
    for (flightControlSystem_B.i_m3 = 0; flightControlSystem_B.i_m3 < 9;
         flightControlSystem_B.i_m3++) {
      if (flightControlSystem_B.isInside_l[flightControlSystem_B.i_m3]) {
        flightControlSystem_B.b_tmp_data[flightControlSystem_B.d_x] = (int8_T)
          flightControlSystem_B.i_m3;
        flightControlSystem_B.d_x++;
      }
    }

    for (flightControlSystem_B.d_x = 0; flightControlSystem_B.d_x <
         flightControlSystem_B.b_z; flightControlSystem_B.d_x++) {
      flightControlSystem_B.d_ind =
        flightControlSystem_B.b_tmp_data[flightControlSystem_B.d_x];
      flightControlSystem_B.u0 =
        J[flightControlSystem_B.imnhInds_[flightControlSystem_B.d_ind] - 1];
      if (flightControlSystem_B.u0 < J[flightControlSystem_B.c_ind]) {
        flightControlSystem_B.b_I_b =
          b_I[flightControlSystem_B.imnhInds_[flightControlSystem_B.d_ind] - 1];
        if (flightControlSystem_B.u0 != flightControlSystem_B.b_I_b) {
          flightControlSystem_B.u0 = J[flightControlSystem_B.c_ind];
          if ((flightControlSystem_B.u0 <= flightControlSystem_B.b_I_b) ||
              rtIsNaN(flightControlSystem_B.b_I_b)) {
            J[flightControlSystem_B.imnhInds_[flightControlSystem_B.d_ind] - 1] =
              flightControlSystem_B.u0;
          } else {
            J[flightControlSystem_B.imnhInds_[flightControlSystem_B.d_ind] - 1] =
              flightControlSystem_B.b_I_b;
          }

          flightControlSystem_B.stackTop++;
          flightControlSystem_B.locationStack[flightControlSystem_B.stackTop] =
            flightControlSystem_B.imnhInds_[flightControlSystem_B.d_ind];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static boolean_T flightControlSystem_isequal(const boolean_T varargin_1[19200],
  const boolean_T varargin_2[19200])
{
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 19200)) {
    if (varargin_1[k] != varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_imregionalmax(const real_T varargin_1[19200],
  boolean_T BW[19200])
{
  boolean_T exitg1;
  for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
       flightControlSystem_B.i_md++) {
    flightControlSystem_B.b[flightControlSystem_B.i_md] = 0;
    flightControlSystem_B.imnhInds[flightControlSystem_B.i_md] = 0;
  }

  memset(&flightControlSystem_B.c[0], 0, 18U * sizeof(int32_T));
  for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 19200;
       flightControlSystem_B.i_md++) {
    BW[flightControlSystem_B.i_md] = true;
  }

  flightControlSystem_B.continuePropagation = true;
  flightControlSystem_B.iv[0] = 120;
  flightControlSystem_B.iv[1] = 160;
  for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
       flightControlSystem_B.i_md++) {
    flightControlSystem_B.bv[flightControlSystem_B.i_md] = true;
  }

  while (flightControlSystem_B.continuePropagation) {
    memcpy(&flightControlSystem_B.bwpre[0], &BW[0], 19200U * sizeof(boolean_T));
    flightControlSystem_NeighborhoodProcessor_computeParameters
      (flightControlSystem_B.iv, flightControlSystem_B.bv,
       flightControlSystem_B.b, flightControlSystem_B.imnhInds,
       flightControlSystem_B.c, flightControlSystem_B.d_g,
       flightControlSystem_B.e);
    flightControlSystem_B.secondIndRange_idx_0 = flightControlSystem_B.d_g[1];
    flightControlSystem_B.secondIndRange_idx_1 = flightControlSystem_B.e[1];
    flightControlSystem_B.firstIndRange_idx_0 = flightControlSystem_B.d_g[0];
    flightControlSystem_B.firstIndRange_idx_1 = flightControlSystem_B.e[0];
    for (flightControlSystem_B.b_pind =
         flightControlSystem_B.secondIndRange_idx_0;
         flightControlSystem_B.b_pind <=
         flightControlSystem_B.secondIndRange_idx_1;
         flightControlSystem_B.b_pind++) {
      for (flightControlSystem_B.ind = flightControlSystem_B.firstIndRange_idx_0;
           flightControlSystem_B.ind <=
           flightControlSystem_B.firstIndRange_idx_1; flightControlSystem_B.ind
           ++) {
        flightControlSystem_B.pind = ((flightControlSystem_B.b_pind - 1) * 120 +
          flightControlSystem_B.ind) - 1;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          flightControlSystem_B.imnhInds[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.i_md] +
             flightControlSystem_B.pind) + 1;
        }

        flightControlSystem_B.fparamsAugmented_pixel =
          varargin_1[flightControlSystem_B.pind];
        flightControlSystem_B.out_[flightControlSystem_B.ind - 1] =
          flightControlSystem_B.bwpre[flightControlSystem_B.pind];
        if (flightControlSystem_B.bwpre[flightControlSystem_B.pind]) {
          flightControlSystem_B.i_md = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.i_md < 9)) {
            flightControlSystem_B.d2 =
              varargin_1[flightControlSystem_B.imnhInds[flightControlSystem_B.i_md]
              - 1];
            if (flightControlSystem_B.d2 >
                flightControlSystem_B.fparamsAugmented_pixel) {
              flightControlSystem_B.out_[flightControlSystem_B.ind - 1] = false;
              exitg1 = true;
            } else if ((flightControlSystem_B.d2 ==
                        flightControlSystem_B.fparamsAugmented_pixel) &&
                       (!flightControlSystem_B.bwpre[flightControlSystem_B.imnhInds
                        [flightControlSystem_B.i_md] - 1])) {
              flightControlSystem_B.out_[flightControlSystem_B.ind - 1] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.i_md++;
            }
          }
        }
      }

      memcpy(&BW[flightControlSystem_B.b_pind * 120 + -120],
             &flightControlSystem_B.out_[0], 120U * sizeof(boolean_T));
    }

    if (flightControlSystem_B.d_g[1] - 1 <= 160) {
      flightControlSystem_B.secondIndRange_idx_0 = flightControlSystem_B.d_g[1]
        - 1;
    } else {
      flightControlSystem_B.secondIndRange_idx_0 = 160;
    }

    for (flightControlSystem_B.firstIndRange_idx_0 = 0;
         flightControlSystem_B.firstIndRange_idx_0 <
         flightControlSystem_B.secondIndRange_idx_0;
         flightControlSystem_B.firstIndRange_idx_0++) {
      for (flightControlSystem_B.firstIndRange_idx_1 = 0;
           flightControlSystem_B.firstIndRange_idx_1 < 120;
           flightControlSystem_B.firstIndRange_idx_1++) {
        flightControlSystem_B.b_pind = flightControlSystem_B.firstIndRange_idx_0
          * 120 + flightControlSystem_B.firstIndRange_idx_1;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          flightControlSystem_B.imnhInds[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.i_md] +
             flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.i_md = flightControlSystem_B.b_pind - 120 *
          div_s32(flightControlSystem_B.b_pind, 120);
        flightControlSystem_B.secondIndRange_idx_1 =
          flightControlSystem_B.b_pind - flightControlSystem_B.i_md;
        if (flightControlSystem_B.secondIndRange_idx_1 >= 0) {
          flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        } else if (flightControlSystem_B.secondIndRange_idx_1 == MIN_int32_T) {
          flightControlSystem_B.ind = MAX_int32_T;
        } else {
          flightControlSystem_B.ind =
            -flightControlSystem_B.secondIndRange_idx_1;
        }

        flightControlSystem_B.pind = flightControlSystem_B.ind / 120;
        flightControlSystem_B.ind -= flightControlSystem_B.pind * 120;
        if (flightControlSystem_B.ind >= 60) {
          flightControlSystem_B.pind++;
        }

        if (flightControlSystem_B.secondIndRange_idx_1 < 0) {
          flightControlSystem_B.pind = -flightControlSystem_B.pind;
        }

        flightControlSystem_B.pixelSub[0] = flightControlSystem_B.i_md + 1;
        flightControlSystem_B.pixelSub[1] = flightControlSystem_B.pind + 1;
        flightControlSystem_bsxfun(flightControlSystem_B.c,
          flightControlSystem_B.pixelSub, flightControlSystem_B.imnhSubs);
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.ind = 0; flightControlSystem_B.ind < 9;
             flightControlSystem_B.ind++) {
          flightControlSystem_B.isInside[flightControlSystem_B.ind] = true;
          flightControlSystem_B.pind = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.pind < 2)) {
            flightControlSystem_B.i_md = flightControlSystem_B.imnhSubs[9 *
              flightControlSystem_B.pind + flightControlSystem_B.ind];
            if ((flightControlSystem_B.i_md < 1) || (flightControlSystem_B.i_md >
                 40 * flightControlSystem_B.pind + 120)) {
              flightControlSystem_B.isInside[flightControlSystem_B.ind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.pind++;
            }
          }

          if (flightControlSystem_B.isInside[flightControlSystem_B.ind]) {
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          if (flightControlSystem_B.isInside[flightControlSystem_B.i_md]) {
            flightControlSystem_B.tmp_data[flightControlSystem_B.secondIndRange_idx_1]
              = (int8_T)flightControlSystem_B.i_md;
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md <
             flightControlSystem_B.ind; flightControlSystem_B.i_md++) {
          flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.tmp_data[flightControlSystem_B.i_md]]
             + flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.fparamsAugmented_pixel =
          varargin_1[flightControlSystem_B.b_pind];
        BW[flightControlSystem_B.b_pind] =
          flightControlSystem_B.bwpre[flightControlSystem_B.b_pind];
        if (flightControlSystem_B.bwpre[flightControlSystem_B.b_pind]) {
          flightControlSystem_B.i_md = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.i_md <=
                               flightControlSystem_B.ind - 1)) {
            flightControlSystem_B.d2 =
              varargin_1[flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md]
              - 1];
            if (flightControlSystem_B.d2 >
                flightControlSystem_B.fparamsAugmented_pixel) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else if ((flightControlSystem_B.d2 ==
                        flightControlSystem_B.fparamsAugmented_pixel) &&
                       (!flightControlSystem_B.bwpre[flightControlSystem_B.imnhInds
                        [flightControlSystem_B.tmp_data[flightControlSystem_B.i_md]]
                        - 1])) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.i_md++;
            }
          }
        }
      }
    }

    flightControlSystem_B.secondIndRange_idx_0 = flightControlSystem_B.e[1] + 1;
    if (flightControlSystem_B.e[1] + 1 < 1) {
      flightControlSystem_B.secondIndRange_idx_0 = 1;
    }

    for (flightControlSystem_B.firstIndRange_idx_0 =
         flightControlSystem_B.secondIndRange_idx_0;
         flightControlSystem_B.firstIndRange_idx_0 < 161;
         flightControlSystem_B.firstIndRange_idx_0++) {
      for (flightControlSystem_B.firstIndRange_idx_1 = 0;
           flightControlSystem_B.firstIndRange_idx_1 < 120;
           flightControlSystem_B.firstIndRange_idx_1++) {
        flightControlSystem_B.b_pind =
          (flightControlSystem_B.firstIndRange_idx_0 - 1) * 120 +
          flightControlSystem_B.firstIndRange_idx_1;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          flightControlSystem_B.imnhInds[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.i_md] +
             flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.i_md = flightControlSystem_B.b_pind - 120 *
          div_s32(flightControlSystem_B.b_pind, 120);
        flightControlSystem_B.secondIndRange_idx_1 =
          flightControlSystem_B.b_pind - flightControlSystem_B.i_md;
        if (flightControlSystem_B.secondIndRange_idx_1 >= 0) {
          flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        } else {
          flightControlSystem_B.ind =
            -flightControlSystem_B.secondIndRange_idx_1;
        }

        flightControlSystem_B.pind = flightControlSystem_B.ind / 120;
        flightControlSystem_B.ind -= flightControlSystem_B.pind * 120;
        if (flightControlSystem_B.ind >= 60) {
          flightControlSystem_B.pind++;
        }

        if (flightControlSystem_B.secondIndRange_idx_1 < 0) {
          flightControlSystem_B.pind = -flightControlSystem_B.pind;
        }

        flightControlSystem_B.pixelSub[0] = flightControlSystem_B.i_md + 1;
        flightControlSystem_B.pixelSub[1] = flightControlSystem_B.pind + 1;
        flightControlSystem_bsxfun(flightControlSystem_B.c,
          flightControlSystem_B.pixelSub, flightControlSystem_B.imnhSubs);
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.ind = 0; flightControlSystem_B.ind < 9;
             flightControlSystem_B.ind++) {
          flightControlSystem_B.isInside[flightControlSystem_B.ind] = true;
          flightControlSystem_B.pind = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.pind < 2)) {
            flightControlSystem_B.i_md = flightControlSystem_B.imnhSubs[9 *
              flightControlSystem_B.pind + flightControlSystem_B.ind];
            if ((flightControlSystem_B.i_md < 1) || (flightControlSystem_B.i_md >
                 40 * flightControlSystem_B.pind + 120)) {
              flightControlSystem_B.isInside[flightControlSystem_B.ind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.pind++;
            }
          }

          if (flightControlSystem_B.isInside[flightControlSystem_B.ind]) {
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          if (flightControlSystem_B.isInside[flightControlSystem_B.i_md]) {
            flightControlSystem_B.tmp_data_m[flightControlSystem_B.secondIndRange_idx_1]
              = (int8_T)flightControlSystem_B.i_md;
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md <
             flightControlSystem_B.ind; flightControlSystem_B.i_md++) {
          flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.tmp_data_m[flightControlSystem_B.i_md]]
             + flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.fparamsAugmented_pixel =
          varargin_1[flightControlSystem_B.b_pind];
        BW[flightControlSystem_B.b_pind] =
          flightControlSystem_B.bwpre[flightControlSystem_B.b_pind];
        if (flightControlSystem_B.bwpre[flightControlSystem_B.b_pind]) {
          flightControlSystem_B.i_md = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.i_md <=
                               flightControlSystem_B.ind - 1)) {
            flightControlSystem_B.d2 =
              varargin_1[flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md]
              - 1];
            if (flightControlSystem_B.d2 >
                flightControlSystem_B.fparamsAugmented_pixel) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else if ((flightControlSystem_B.d2 ==
                        flightControlSystem_B.fparamsAugmented_pixel) &&
                       (!flightControlSystem_B.bwpre[flightControlSystem_B.imnhInds
                        [flightControlSystem_B.tmp_data_m[flightControlSystem_B.i_md]]
                        - 1])) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.i_md++;
            }
          }
        }
      }
    }

    if (flightControlSystem_B.d_g[0] - 1 <= 120) {
      flightControlSystem_B.secondIndRange_idx_0 = flightControlSystem_B.d_g[0]
        - 1;
    } else {
      flightControlSystem_B.secondIndRange_idx_0 = 120;
    }

    for (flightControlSystem_B.firstIndRange_idx_0 = 0;
         flightControlSystem_B.firstIndRange_idx_0 < 160;
         flightControlSystem_B.firstIndRange_idx_0++) {
      for (flightControlSystem_B.firstIndRange_idx_1 = 0;
           flightControlSystem_B.firstIndRange_idx_1 <
           flightControlSystem_B.secondIndRange_idx_0;
           flightControlSystem_B.firstIndRange_idx_1++) {
        flightControlSystem_B.b_pind = flightControlSystem_B.firstIndRange_idx_0
          * 120 + flightControlSystem_B.firstIndRange_idx_1;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          flightControlSystem_B.imnhInds[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.i_md] +
             flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.i_md = flightControlSystem_B.b_pind - 120 *
          div_s32(flightControlSystem_B.b_pind, 120);
        flightControlSystem_B.secondIndRange_idx_1 =
          flightControlSystem_B.b_pind - flightControlSystem_B.i_md;
        if (flightControlSystem_B.secondIndRange_idx_1 >= 0) {
          flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        } else if (flightControlSystem_B.secondIndRange_idx_1 == MIN_int32_T) {
          flightControlSystem_B.ind = MAX_int32_T;
        } else {
          flightControlSystem_B.ind =
            -flightControlSystem_B.secondIndRange_idx_1;
        }

        flightControlSystem_B.pind = flightControlSystem_B.ind / 120;
        flightControlSystem_B.ind -= flightControlSystem_B.pind * 120;
        if (flightControlSystem_B.ind >= 60) {
          flightControlSystem_B.pind++;
        }

        if (flightControlSystem_B.secondIndRange_idx_1 < 0) {
          flightControlSystem_B.pind = -flightControlSystem_B.pind;
        }

        flightControlSystem_B.d_g[0] = flightControlSystem_B.i_md + 1;
        flightControlSystem_B.d_g[1] = flightControlSystem_B.pind + 1;
        flightControlSystem_bsxfun(flightControlSystem_B.c,
          flightControlSystem_B.d_g, flightControlSystem_B.imnhSubs);
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.ind = 0; flightControlSystem_B.ind < 9;
             flightControlSystem_B.ind++) {
          flightControlSystem_B.isInside[flightControlSystem_B.ind] = true;
          flightControlSystem_B.pind = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.pind < 2)) {
            flightControlSystem_B.i_md = flightControlSystem_B.imnhSubs[9 *
              flightControlSystem_B.pind + flightControlSystem_B.ind];
            if ((flightControlSystem_B.i_md < 1) || (flightControlSystem_B.i_md >
                 40 * flightControlSystem_B.pind + 120)) {
              flightControlSystem_B.isInside[flightControlSystem_B.ind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.pind++;
            }
          }

          if (flightControlSystem_B.isInside[flightControlSystem_B.ind]) {
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          if (flightControlSystem_B.isInside[flightControlSystem_B.i_md]) {
            flightControlSystem_B.tmp_data_n[flightControlSystem_B.secondIndRange_idx_1]
              = (int8_T)flightControlSystem_B.i_md;
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md <
             flightControlSystem_B.ind; flightControlSystem_B.i_md++) {
          flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.tmp_data_n[flightControlSystem_B.i_md]]
             + flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.fparamsAugmented_pixel =
          varargin_1[flightControlSystem_B.b_pind];
        BW[flightControlSystem_B.b_pind] =
          flightControlSystem_B.bwpre[flightControlSystem_B.b_pind];
        if (flightControlSystem_B.bwpre[flightControlSystem_B.b_pind]) {
          flightControlSystem_B.i_md = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.i_md <=
                               flightControlSystem_B.ind - 1)) {
            flightControlSystem_B.d2 =
              varargin_1[flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md]
              - 1];
            if (flightControlSystem_B.d2 >
                flightControlSystem_B.fparamsAugmented_pixel) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else if ((flightControlSystem_B.d2 ==
                        flightControlSystem_B.fparamsAugmented_pixel) &&
                       (!flightControlSystem_B.bwpre[flightControlSystem_B.imnhInds
                        [flightControlSystem_B.tmp_data_n[flightControlSystem_B.i_md]]
                        - 1])) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.i_md++;
            }
          }
        }
      }
    }

    flightControlSystem_B.secondIndRange_idx_0 = flightControlSystem_B.e[0] + 1;
    if (flightControlSystem_B.e[0] + 1 < 1) {
      flightControlSystem_B.secondIndRange_idx_0 = 1;
    }

    for (flightControlSystem_B.firstIndRange_idx_0 = 0;
         flightControlSystem_B.firstIndRange_idx_0 < 160;
         flightControlSystem_B.firstIndRange_idx_0++) {
      for (flightControlSystem_B.firstIndRange_idx_1 =
           flightControlSystem_B.secondIndRange_idx_0;
           flightControlSystem_B.firstIndRange_idx_1 < 121;
           flightControlSystem_B.firstIndRange_idx_1++) {
        flightControlSystem_B.b_pind =
          (flightControlSystem_B.firstIndRange_idx_0 * 120 +
           flightControlSystem_B.firstIndRange_idx_1) - 1;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          flightControlSystem_B.imnhInds[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.i_md] +
             flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.i_md = flightControlSystem_B.b_pind - 120 *
          div_s32(flightControlSystem_B.b_pind, 120);
        flightControlSystem_B.secondIndRange_idx_1 =
          flightControlSystem_B.b_pind - flightControlSystem_B.i_md;
        if (flightControlSystem_B.secondIndRange_idx_1 >= 0) {
          flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        } else {
          flightControlSystem_B.ind =
            -flightControlSystem_B.secondIndRange_idx_1;
        }

        flightControlSystem_B.pind = flightControlSystem_B.ind / 120;
        flightControlSystem_B.ind -= flightControlSystem_B.pind * 120;
        if (flightControlSystem_B.ind >= 60) {
          flightControlSystem_B.pind++;
        }

        if (flightControlSystem_B.secondIndRange_idx_1 < 0) {
          flightControlSystem_B.pind = -flightControlSystem_B.pind;
        }

        flightControlSystem_B.e[0] = flightControlSystem_B.i_md + 1;
        flightControlSystem_B.e[1] = flightControlSystem_B.pind + 1;
        flightControlSystem_bsxfun(flightControlSystem_B.c,
          flightControlSystem_B.e, flightControlSystem_B.imnhSubs);
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.ind = 0; flightControlSystem_B.ind < 9;
             flightControlSystem_B.ind++) {
          flightControlSystem_B.isInside[flightControlSystem_B.ind] = true;
          flightControlSystem_B.pind = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.pind < 2)) {
            flightControlSystem_B.i_md = flightControlSystem_B.imnhSubs[9 *
              flightControlSystem_B.pind + flightControlSystem_B.ind];
            if ((flightControlSystem_B.i_md < 1) || (flightControlSystem_B.i_md >
                 40 * flightControlSystem_B.pind + 120)) {
              flightControlSystem_B.isInside[flightControlSystem_B.ind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.pind++;
            }
          }

          if (flightControlSystem_B.isInside[flightControlSystem_B.ind]) {
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        flightControlSystem_B.ind = flightControlSystem_B.secondIndRange_idx_1;
        flightControlSystem_B.secondIndRange_idx_1 = 0;
        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md < 9;
             flightControlSystem_B.i_md++) {
          if (flightControlSystem_B.isInside[flightControlSystem_B.i_md]) {
            flightControlSystem_B.tmp_data_p[flightControlSystem_B.secondIndRange_idx_1]
              = (int8_T)flightControlSystem_B.i_md;
            flightControlSystem_B.secondIndRange_idx_1++;
          }
        }

        for (flightControlSystem_B.i_md = 0; flightControlSystem_B.i_md <
             flightControlSystem_B.ind; flightControlSystem_B.i_md++) {
          flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md] =
            (flightControlSystem_B.b[flightControlSystem_B.tmp_data_p[flightControlSystem_B.i_md]]
             + flightControlSystem_B.b_pind) + 1;
        }

        flightControlSystem_B.fparamsAugmented_pixel =
          varargin_1[flightControlSystem_B.b_pind];
        BW[flightControlSystem_B.b_pind] =
          flightControlSystem_B.bwpre[flightControlSystem_B.b_pind];
        if (flightControlSystem_B.bwpre[flightControlSystem_B.b_pind]) {
          flightControlSystem_B.i_md = 0;
          exitg1 = false;
          while ((!exitg1) && (flightControlSystem_B.i_md <=
                               flightControlSystem_B.ind - 1)) {
            flightControlSystem_B.d2 =
              varargin_1[flightControlSystem_B.b_imnhInds_data[flightControlSystem_B.i_md]
              - 1];
            if (flightControlSystem_B.d2 >
                flightControlSystem_B.fparamsAugmented_pixel) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else if ((flightControlSystem_B.d2 ==
                        flightControlSystem_B.fparamsAugmented_pixel) &&
                       (!flightControlSystem_B.bwpre[flightControlSystem_B.imnhInds
                        [flightControlSystem_B.tmp_data_p[flightControlSystem_B.i_md]]
                        - 1])) {
              BW[flightControlSystem_B.b_pind] = false;
              exitg1 = true;
            } else {
              flightControlSystem_B.i_md++;
            }
          }
        }
      }
    }

    flightControlSystem_B.continuePropagation = !flightControlSystem_isequal
      (flightControlSystem_B.bwpre, BW);
  }
}

static void flightControlSystem_emxInit_sOA5t73y81YtFHGIDxk0fKF
  (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *)malloc
    (sizeof(emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxInit_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_cell_wrap_36_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_36_flightControlSystem_T *)malloc(sizeof
    (emxArray_cell_wrap_36_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_36_flightControlSystem_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxInit_int16_T
  (emxArray_int16_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int16_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int16_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_int16_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (int16_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxInit_int8_T
  (emxArray_int8_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int8_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int8_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_int8_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (int8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxEnsureCapacity_int8_T
  (emxArray_int8_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(int8_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int8_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxInit_uint8_T
  (emxArray_uint8_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_uint8_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_uint8_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_uint8_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (uint8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxEnsureCapacity_uint8_T
  (emxArray_uint8_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(uint8_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(uint8_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (uint8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxEnsureCapacity_int16_T
  (emxArray_int16_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(int16_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int16_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int16_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxFree_uint8_T
  (emxArray_uint8_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (uint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxFree_int8_T
  (emxArray_int8_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (int8_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxInitStruct_cell_wrap_36
  (cell_wrap_36_flightControlSystem_T *pStruct)
{
  flightControlSystem_emxInit_real_T(&pStruct->f1, 1);
}

static void flightControlSystem_emxExpand_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T *emxArray, int32_T fromIndex,
   int32_T toIndex)
{
  for (flightControlSystem_B.i_m = fromIndex; flightControlSystem_B.i_m <
       toIndex; flightControlSystem_B.i_m++) {
    flightControlSystem_emxInitStruct_cell_wrap_36(&emxArray->
      data[flightControlSystem_B.i_m]);
  }
}

static void flightControlSystem_emxFree_real_T
  (emxArray_real_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxFreeStruct_cell_wrap_36
  (cell_wrap_36_flightControlSystem_T *pStruct)
{
  flightControlSystem_emxFree_real_T(&pStruct->f1);
}

static void flightControlSystem_emxTrim_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T *emxArray, int32_T fromIndex,
   int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    flightControlSystem_emxFreeStruct_cell_wrap_36(&emxArray->data[i]);
  }
}

static void flightControlSystem_emxEnsureCapacity_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  flightControlSystem_B.newNumel = 1;
  for (flightControlSystem_B.i_n = 0; flightControlSystem_B.i_n <
       emxArray->numDimensions; flightControlSystem_B.i_n++) {
    flightControlSystem_B.newNumel *= emxArray->size[flightControlSystem_B.i_n];
  }

  if (flightControlSystem_B.newNumel > emxArray->allocatedSize) {
    flightControlSystem_B.i_n = emxArray->allocatedSize;
    if (flightControlSystem_B.i_n < 16) {
      flightControlSystem_B.i_n = 16;
    }

    while (flightControlSystem_B.i_n < flightControlSystem_B.newNumel) {
      if (flightControlSystem_B.i_n > 1073741823) {
        flightControlSystem_B.i_n = MAX_int32_T;
      } else {
        flightControlSystem_B.i_n <<= 1;
      }
    }

    newData = calloc((uint32_T)flightControlSystem_B.i_n, sizeof
                     (cell_wrap_36_flightControlSystem_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_36_flightControlSystem_T)
             * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cell_wrap_36_flightControlSystem_T *)newData;
    emxArray->allocatedSize = flightControlSystem_B.i_n;
    emxArray->canFreeData = true;
  }

  if (oldNumel > flightControlSystem_B.newNumel) {
    flightControlSystem_emxTrim_cell_wrap_36(emxArray,
      flightControlSystem_B.newNumel, oldNumel);
  } else if (oldNumel < flightControlSystem_B.newNumel) {
    flightControlSystem_emxExpand_cell_wrap_36(emxArray, oldNumel,
      flightControlSystem_B.newNumel);
  }
}

static void flightControlSystem_emxEnsureCapacity_real_T
  (emxArray_real_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  flightControlSystem_B.newNumel_c = 1;
  for (flightControlSystem_B.i_ct = 0; flightControlSystem_B.i_ct <
       emxArray->numDimensions; flightControlSystem_B.i_ct++) {
    flightControlSystem_B.newNumel_c *= emxArray->
      size[flightControlSystem_B.i_ct];
  }

  if (flightControlSystem_B.newNumel_c > emxArray->allocatedSize) {
    flightControlSystem_B.i_ct = emxArray->allocatedSize;
    if (flightControlSystem_B.i_ct < 16) {
      flightControlSystem_B.i_ct = 16;
    }

    while (flightControlSystem_B.i_ct < flightControlSystem_B.newNumel_c) {
      if (flightControlSystem_B.i_ct > 1073741823) {
        flightControlSystem_B.i_ct = MAX_int32_T;
      } else {
        flightControlSystem_B.i_ct <<= 1;
      }
    }

    newData = malloc((uint32_T)flightControlSystem_B.i_ct * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = flightControlSystem_B.i_ct;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxFree_int16_T
  (emxArray_int16_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int16_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (int16_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int16_T_flightControlSystem_T *)NULL;
  }
}

static void flightControlSystem_emxCopy_real_T
  (emxArray_real_T_flightControlSystem_T **dst,
   emxArray_real_T_flightControlSystem_T * const *src)
{
  flightControlSystem_B.numElDst = 1;
  flightControlSystem_B.numElSrc = 1;
  for (flightControlSystem_B.i_h = 0; flightControlSystem_B.i_h < (*dst)
       ->numDimensions; flightControlSystem_B.i_h++) {
    flightControlSystem_B.numElDst *= (*dst)->size[flightControlSystem_B.i_h];
    flightControlSystem_B.numElSrc *= (*src)->size[flightControlSystem_B.i_h];
  }

  for (flightControlSystem_B.i_h = 0; flightControlSystem_B.i_h < (*dst)
       ->numDimensions; flightControlSystem_B.i_h++) {
    (*dst)->size[flightControlSystem_B.i_h] = (*src)->
      size[flightControlSystem_B.i_h];
  }

  flightControlSystem_emxEnsureCapacity_real_T(*dst,
    flightControlSystem_B.numElDst);
  for (flightControlSystem_B.i_h = 0; flightControlSystem_B.i_h <
       flightControlSystem_B.numElSrc; flightControlSystem_B.i_h++) {
    (*dst)->data[flightControlSystem_B.i_h] = (*src)->
      data[flightControlSystem_B.i_h];
  }
}

static void flightControlSystem_emxCopyStruct_cell_wrap_36
  (cell_wrap_36_flightControlSystem_T *dst, const
   cell_wrap_36_flightControlSystem_T *src)
{
  flightControlSystem_emxCopy_real_T(&dst->f1, &src->f1);
}

static void flightControlSystem_emxFree_cell_wrap_36
  (emxArray_cell_wrap_36_flightControlSystem_T **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_cell_wrap_36_flightControlSystem_T *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_36_flightControlSystem_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        flightControlSystem_emxFreeStruct_cell_wrap_36(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_36_flightControlSystem_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_bwconncomp(const boolean_T varargin_1[19200],
  real_T *CC_Connectivity, real_T CC_ImageSize[2], real_T *CC_NumObjects,
  emxArray_real_T_flightControlSystem_T *CC_RegionIndices,
  emxArray_int32_T_flightControlSystem_T *CC_RegionLengths,
  emxArray_cell_wrap_36_flightControlSystem_T *CC_PixelIdxList)
{
  emxArray_cell_wrap_36_flightControlSystem_T *c;
  emxArray_int16_T_flightControlSystem_T *b;
  emxArray_int32_T_flightControlSystem_T *idxCount;
  emxArray_int32_T_flightControlSystem_T *labelsRenumbered;
  emxArray_int32_T_flightControlSystem_T *x;
  emxArray_int8_T_flightControlSystem_T *endRow;
  emxArray_int8_T_flightControlSystem_T *startRow;
  emxArray_uint8_T_flightControlSystem_T *startCol;
  CC_ImageSize[0] = 120.0;
  CC_ImageSize[1] = 160.0;
  flightControlSystem_B.numRuns = 0;
  for (flightControlSystem_B.runCounter = 0; flightControlSystem_B.runCounter <
       160; flightControlSystem_B.runCounter++) {
    if (varargin_1[120 * flightControlSystem_B.runCounter]) {
      flightControlSystem_B.numRuns++;
    }

    for (flightControlSystem_B.row = 0; flightControlSystem_B.row < 119;
         flightControlSystem_B.row++) {
      flightControlSystem_B.currentColumn = 120 *
        flightControlSystem_B.runCounter + flightControlSystem_B.row;
      if (varargin_1[flightControlSystem_B.currentColumn + 1] &&
          (!varargin_1[flightControlSystem_B.currentColumn])) {
        flightControlSystem_B.numRuns++;
      }
    }
  }

  flightControlSystem_emxInit_int16_T(&b, 1);
  flightControlSystem_emxInit_cell_wrap_36(&c, 2);
  if (flightControlSystem_B.numRuns == 0) {
    *CC_NumObjects = 0.0;
    b->size[0] = 0;
    flightControlSystem_B.currentColumn = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    flightControlSystem_emxEnsureCapacity_int32_T(CC_RegionLengths,
      flightControlSystem_B.currentColumn);
    CC_RegionLengths->data[0] = 0;
    c->size[0] = 1;
    c->size[1] = 0;
  } else {
    flightControlSystem_emxInit_int8_T(&startRow, 1);
    flightControlSystem_B.currentColumn = startRow->size[0];
    startRow->size[0] = flightControlSystem_B.numRuns;
    flightControlSystem_emxEnsureCapacity_int8_T(startRow,
      flightControlSystem_B.currentColumn);
    flightControlSystem_emxInit_int8_T(&endRow, 1);
    flightControlSystem_B.currentColumn = endRow->size[0];
    endRow->size[0] = flightControlSystem_B.numRuns;
    flightControlSystem_emxEnsureCapacity_int8_T(endRow,
      flightControlSystem_B.currentColumn);
    flightControlSystem_emxInit_uint8_T(&startCol, 1);
    flightControlSystem_B.currentColumn = startCol->size[0];
    startCol->size[0] = flightControlSystem_B.numRuns;
    flightControlSystem_emxEnsureCapacity_uint8_T(startCol,
      flightControlSystem_B.currentColumn);
    flightControlSystem_B.runCounter = 0;
    for (flightControlSystem_B.currentColumn = 0;
         flightControlSystem_B.currentColumn < 160;
         flightControlSystem_B.currentColumn++) {
      flightControlSystem_B.row = 1;
      while (flightControlSystem_B.row <= 120) {
        while ((flightControlSystem_B.row <= 120) && (!varargin_1[(120 *
                 flightControlSystem_B.currentColumn + flightControlSystem_B.row)
                - 1])) {
          flightControlSystem_B.row++;
        }

        if ((flightControlSystem_B.row <= 120) && varargin_1[(120 *
             flightControlSystem_B.currentColumn + flightControlSystem_B.row) -
            1]) {
          startCol->data[flightControlSystem_B.runCounter] = (uint8_T)
            (flightControlSystem_B.currentColumn + 1);
          startRow->data[flightControlSystem_B.runCounter] = (int8_T)
            flightControlSystem_B.row;
          while ((flightControlSystem_B.row <= 120) && varargin_1[(120 *
                  flightControlSystem_B.currentColumn +
                  flightControlSystem_B.row) - 1]) {
            flightControlSystem_B.row++;
          }

          endRow->data[flightControlSystem_B.runCounter] = (int8_T)
            (flightControlSystem_B.row - 1);
          flightControlSystem_B.runCounter++;
        }
      }
    }

    flightControlSystem_B.currentColumn = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = flightControlSystem_B.numRuns;
    flightControlSystem_emxEnsureCapacity_int32_T(CC_RegionLengths,
      flightControlSystem_B.currentColumn);
    if (flightControlSystem_B.numRuns - 1 >= 0) {
      memset(&CC_RegionLengths->data[0], 0, (uint32_T)
             flightControlSystem_B.numRuns * sizeof(int32_T));
    }

    flightControlSystem_B.runCounter = 0;
    flightControlSystem_B.currentColumn = 1;
    flightControlSystem_B.row = 1;
    flightControlSystem_B.firstRunOnPreviousColumn = -1;
    flightControlSystem_B.lastRunOnPreviousColumn = -1;
    flightControlSystem_B.firstRunOnThisColumn = 0;
    while (flightControlSystem_B.runCounter + 1 <= flightControlSystem_B.numRuns)
    {
      if (flightControlSystem_B.currentColumn + 1 == startCol->
          data[flightControlSystem_B.runCounter]) {
        flightControlSystem_B.firstRunOnPreviousColumn =
          flightControlSystem_B.firstRunOnThisColumn + 1;
        flightControlSystem_B.firstRunOnThisColumn =
          flightControlSystem_B.runCounter;
        flightControlSystem_B.lastRunOnPreviousColumn =
          flightControlSystem_B.runCounter;
        flightControlSystem_B.currentColumn = startCol->
          data[flightControlSystem_B.runCounter];
      } else if (startCol->data[flightControlSystem_B.runCounter] >
                 flightControlSystem_B.currentColumn + 1) {
        flightControlSystem_B.firstRunOnPreviousColumn = -1;
        flightControlSystem_B.lastRunOnPreviousColumn = -1;
        flightControlSystem_B.firstRunOnThisColumn =
          flightControlSystem_B.runCounter;
        flightControlSystem_B.currentColumn = startCol->
          data[flightControlSystem_B.runCounter];
      }

      if (flightControlSystem_B.firstRunOnPreviousColumn >= 0) {
        flightControlSystem_B.p_o =
          flightControlSystem_B.firstRunOnPreviousColumn - 1;
        while (flightControlSystem_B.p_o + 1 <=
               flightControlSystem_B.lastRunOnPreviousColumn) {
          if ((endRow->data[flightControlSystem_B.runCounter] >= startRow->
               data[flightControlSystem_B.p_o] - 1) && (startRow->
               data[flightControlSystem_B.runCounter] <= endRow->
               data[flightControlSystem_B.p_o] + 1)) {
            if (CC_RegionLengths->data[flightControlSystem_B.runCounter] == 0) {
              CC_RegionLengths->data[flightControlSystem_B.runCounter] =
                CC_RegionLengths->data[flightControlSystem_B.p_o];
              flightControlSystem_B.row++;
            } else if (CC_RegionLengths->data[flightControlSystem_B.runCounter]
                       != CC_RegionLengths->data[flightControlSystem_B.p_o]) {
              flightControlSystem_B.root_k = flightControlSystem_B.runCounter;
              while (flightControlSystem_B.root_k + 1 != CC_RegionLengths->
                     data[flightControlSystem_B.root_k]) {
                CC_RegionLengths->data[flightControlSystem_B.root_k] =
                  CC_RegionLengths->data[CC_RegionLengths->
                  data[flightControlSystem_B.root_k] - 1];
                flightControlSystem_B.root_k = CC_RegionLengths->
                  data[flightControlSystem_B.root_k] - 1;
              }

              flightControlSystem_B.root_p = flightControlSystem_B.p_o;
              while (flightControlSystem_B.root_p + 1 != CC_RegionLengths->
                     data[flightControlSystem_B.root_p]) {
                CC_RegionLengths->data[flightControlSystem_B.root_p] =
                  CC_RegionLengths->data[CC_RegionLengths->
                  data[flightControlSystem_B.root_p] - 1];
                flightControlSystem_B.root_p = CC_RegionLengths->
                  data[flightControlSystem_B.root_p] - 1;
              }

              if (flightControlSystem_B.root_k + 1 !=
                  flightControlSystem_B.root_p + 1) {
                if (flightControlSystem_B.root_p + 1 <
                    flightControlSystem_B.root_k + 1) {
                  CC_RegionLengths->data[flightControlSystem_B.root_k] =
                    flightControlSystem_B.root_p + 1;
                  CC_RegionLengths->data[flightControlSystem_B.runCounter] =
                    flightControlSystem_B.root_p + 1;
                } else {
                  CC_RegionLengths->data[flightControlSystem_B.root_p] =
                    flightControlSystem_B.root_k + 1;
                  CC_RegionLengths->data[flightControlSystem_B.p_o] =
                    flightControlSystem_B.root_k + 1;
                }
              }
            }
          }

          flightControlSystem_B.p_o++;
        }
      }

      if (CC_RegionLengths->data[flightControlSystem_B.runCounter] == 0) {
        CC_RegionLengths->data[flightControlSystem_B.runCounter] =
          flightControlSystem_B.row;
        flightControlSystem_B.row++;
      }

      flightControlSystem_B.runCounter++;
    }

    flightControlSystem_emxInit_int32_T(&labelsRenumbered, 1);
    flightControlSystem_B.currentColumn = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = CC_RegionLengths->size[0];
    flightControlSystem_emxEnsureCapacity_int32_T(labelsRenumbered,
      flightControlSystem_B.currentColumn);
    flightControlSystem_B.numComponents = 0U;
    for (flightControlSystem_B.runCounter = 0; flightControlSystem_B.runCounter <
         flightControlSystem_B.numRuns; flightControlSystem_B.runCounter++) {
      flightControlSystem_B.currentColumn = CC_RegionLengths->
        data[flightControlSystem_B.runCounter];
      if (flightControlSystem_B.runCounter + 1 ==
          flightControlSystem_B.currentColumn) {
        flightControlSystem_B.numComponents++;
        labelsRenumbered->data[flightControlSystem_B.runCounter] = (int32_T)
          flightControlSystem_B.numComponents;
      }

      labelsRenumbered->data[flightControlSystem_B.runCounter] =
        labelsRenumbered->data[flightControlSystem_B.currentColumn - 1];
    }

    flightControlSystem_B.currentColumn = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = (int32_T)flightControlSystem_B.numComponents;
    flightControlSystem_emxEnsureCapacity_int32_T(CC_RegionLengths,
      flightControlSystem_B.currentColumn);
    flightControlSystem_B.runCounter = (int32_T)
      flightControlSystem_B.numComponents;
    if (flightControlSystem_B.runCounter - 1 >= 0) {
      memset(&CC_RegionLengths->data[0], 0, (uint32_T)
             flightControlSystem_B.runCounter * sizeof(int32_T));
    }

    for (flightControlSystem_B.currentColumn = 0;
         flightControlSystem_B.currentColumn < flightControlSystem_B.numRuns;
         flightControlSystem_B.currentColumn++) {
      flightControlSystem_B.row = labelsRenumbered->
        data[flightControlSystem_B.currentColumn];
      CC_RegionLengths->data[flightControlSystem_B.row - 1] =
        ((CC_RegionLengths->data[flightControlSystem_B.row - 1] + endRow->
          data[flightControlSystem_B.currentColumn]) - startRow->
         data[flightControlSystem_B.currentColumn]) + 1;
    }

    *CC_NumObjects = flightControlSystem_B.numComponents;
    if (CC_RegionLengths->size[0] == 0) {
      flightControlSystem_B.y_o = 0.0;
    } else {
      if (CC_RegionLengths->size[0] <= 1024) {
        flightControlSystem_B.firstRunOnPreviousColumn = (int32_T)
          flightControlSystem_B.numComponents;
        flightControlSystem_B.row = 0;
        flightControlSystem_B.currentColumn = 1;
      } else {
        flightControlSystem_B.firstRunOnPreviousColumn = 1024;
        flightControlSystem_B.currentColumn = (int32_T)((uint32_T)
          CC_RegionLengths->size[0] >> 10);
        flightControlSystem_B.row = CC_RegionLengths->size[0] -
          (flightControlSystem_B.currentColumn << 10);
        if (flightControlSystem_B.row > 0) {
          flightControlSystem_B.currentColumn++;
        } else {
          flightControlSystem_B.row = 1024;
        }
      }

      flightControlSystem_B.y_o = CC_RegionLengths->data[0];
      for (flightControlSystem_B.lastRunOnPreviousColumn = 2;
           flightControlSystem_B.lastRunOnPreviousColumn <=
           flightControlSystem_B.firstRunOnPreviousColumn;
           flightControlSystem_B.lastRunOnPreviousColumn++) {
        flightControlSystem_B.y_o += (real_T)CC_RegionLengths->
          data[flightControlSystem_B.lastRunOnPreviousColumn - 1];
      }

      for (flightControlSystem_B.firstRunOnPreviousColumn = 2;
           flightControlSystem_B.firstRunOnPreviousColumn <=
           flightControlSystem_B.currentColumn;
           flightControlSystem_B.firstRunOnPreviousColumn++) {
        flightControlSystem_B.lastRunOnPreviousColumn =
          (flightControlSystem_B.firstRunOnPreviousColumn - 1) << 10;
        flightControlSystem_B.bsum = CC_RegionLengths->
          data[flightControlSystem_B.lastRunOnPreviousColumn];
        if (flightControlSystem_B.firstRunOnPreviousColumn ==
            flightControlSystem_B.currentColumn) {
          flightControlSystem_B.firstRunOnThisColumn = flightControlSystem_B.row;
        } else {
          flightControlSystem_B.firstRunOnThisColumn = 1024;
        }

        for (flightControlSystem_B.p_o = 2; flightControlSystem_B.p_o <=
             flightControlSystem_B.firstRunOnThisColumn;
             flightControlSystem_B.p_o++) {
          flightControlSystem_B.bsum += (real_T)CC_RegionLengths->data
            [(flightControlSystem_B.lastRunOnPreviousColumn +
              flightControlSystem_B.p_o) - 1];
        }

        flightControlSystem_B.y_o += flightControlSystem_B.bsum;
      }
    }

    flightControlSystem_B.currentColumn = b->size[0];
    b->size[0] = (int32_T)flightControlSystem_B.y_o;
    flightControlSystem_emxEnsureCapacity_int16_T(b,
      flightControlSystem_B.currentColumn);
    flightControlSystem_emxInit_int32_T(&x, 1);
    if (CC_RegionLengths->size[0] != 1) {
      flightControlSystem_B.currentColumn = x->size[0];
      x->size[0] = (int32_T)flightControlSystem_B.numComponents;
      flightControlSystem_emxEnsureCapacity_int32_T(x,
        flightControlSystem_B.currentColumn);
      if (flightControlSystem_B.runCounter - 1 >= 0) {
        memcpy(&x->data[0], &CC_RegionLengths->data[0], (uint32_T)
               flightControlSystem_B.runCounter * sizeof(int32_T));
      }

      if ((CC_RegionLengths->size[0] != 0) && (CC_RegionLengths->size[0] != 1))
      {
        for (flightControlSystem_B.currentColumn = 0;
             flightControlSystem_B.currentColumn <=
             flightControlSystem_B.runCounter - 2;
             flightControlSystem_B.currentColumn++) {
          x->data[flightControlSystem_B.currentColumn + 1] += x->
            data[flightControlSystem_B.currentColumn];
        }
      }
    } else {
      flightControlSystem_B.currentColumn = x->size[0];
      x->size[0] = 1;
      flightControlSystem_emxEnsureCapacity_int32_T(x,
        flightControlSystem_B.currentColumn);
      x->data[0] = CC_RegionLengths->data[0];
    }

    flightControlSystem_emxInit_int32_T(&idxCount, 1);
    flightControlSystem_B.currentColumn = idxCount->size[0];
    idxCount->size[0] = x->size[0] + 1;
    flightControlSystem_emxEnsureCapacity_int32_T(idxCount,
      flightControlSystem_B.currentColumn);
    idxCount->data[0] = 0;
    flightControlSystem_B.row = x->size[0];
    if (flightControlSystem_B.row - 1 >= 0) {
      memcpy(&idxCount->data[1], &x->data[0], (uint32_T)
             flightControlSystem_B.row * sizeof(int32_T));
    }

    for (flightControlSystem_B.currentColumn = 0;
         flightControlSystem_B.currentColumn < flightControlSystem_B.numRuns;
         flightControlSystem_B.currentColumn++) {
      flightControlSystem_B.row = (startCol->
        data[flightControlSystem_B.currentColumn] - 1) * 120;
      flightControlSystem_B.firstRunOnPreviousColumn = labelsRenumbered->
        data[flightControlSystem_B.currentColumn] - 1;
      flightControlSystem_B.lastRunOnPreviousColumn = startRow->
        data[flightControlSystem_B.currentColumn];
      flightControlSystem_B.firstRunOnThisColumn = endRow->
        data[flightControlSystem_B.currentColumn];
      for (flightControlSystem_B.p_o =
           flightControlSystem_B.lastRunOnPreviousColumn;
           flightControlSystem_B.p_o <=
           flightControlSystem_B.firstRunOnThisColumn; flightControlSystem_B.p_o
           ++) {
        idxCount->data[flightControlSystem_B.firstRunOnPreviousColumn]++;
        b->data[idxCount->data[flightControlSystem_B.firstRunOnPreviousColumn] -
          1] = (int16_T)(flightControlSystem_B.p_o + flightControlSystem_B.row);
      }
    }

    flightControlSystem_emxFree_uint8_T(&startCol);
    flightControlSystem_emxFree_int8_T(&endRow);
    flightControlSystem_emxFree_int8_T(&startRow);
    flightControlSystem_emxFree_int32_T(&labelsRenumbered);
    flightControlSystem_B.currentColumn = c->size[0] * c->size[1];
    c->size[0] = 1;
    c->size[1] = (int32_T)flightControlSystem_B.numComponents;
    flightControlSystem_emxEnsureCapacity_cell_wrap_36(c,
      flightControlSystem_B.currentColumn);
    if ((int32_T)flightControlSystem_B.numComponents != 0) {
      for (flightControlSystem_B.numRuns = 0; flightControlSystem_B.numRuns <
           flightControlSystem_B.runCounter; flightControlSystem_B.numRuns++) {
        c->data[flightControlSystem_B.numRuns].f1->size[0] = 0;
      }
    }

    if (CC_RegionLengths->size[0] != 1) {
      flightControlSystem_B.currentColumn = x->size[0];
      x->size[0] = (int32_T)flightControlSystem_B.numComponents;
      flightControlSystem_emxEnsureCapacity_int32_T(x,
        flightControlSystem_B.currentColumn);
      if (flightControlSystem_B.runCounter - 1 >= 0) {
        memcpy(&x->data[0], &CC_RegionLengths->data[0], (uint32_T)
               flightControlSystem_B.runCounter * sizeof(int32_T));
      }

      if ((CC_RegionLengths->size[0] != 0) && (CC_RegionLengths->size[0] != 1))
      {
        for (flightControlSystem_B.numRuns = 0; flightControlSystem_B.numRuns <=
             flightControlSystem_B.runCounter - 2; flightControlSystem_B.numRuns
             ++) {
          x->data[flightControlSystem_B.numRuns + 1] += x->
            data[flightControlSystem_B.numRuns];
        }
      }
    } else {
      flightControlSystem_B.currentColumn = x->size[0];
      x->size[0] = 1;
      flightControlSystem_emxEnsureCapacity_int32_T(x,
        flightControlSystem_B.currentColumn);
      x->data[0] = CC_RegionLengths->data[0];
    }

    flightControlSystem_B.currentColumn = idxCount->size[0];
    idxCount->size[0] = x->size[0] + 1;
    flightControlSystem_emxEnsureCapacity_int32_T(idxCount,
      flightControlSystem_B.currentColumn);
    idxCount->data[0] = 0;
    flightControlSystem_B.row = x->size[0];
    if (flightControlSystem_B.row - 1 >= 0) {
      memcpy(&idxCount->data[1], &x->data[0], (uint32_T)
             flightControlSystem_B.row * sizeof(int32_T));
    }

    flightControlSystem_emxFree_int32_T(&x);
    for (flightControlSystem_B.numRuns = 0; flightControlSystem_B.numRuns <
         flightControlSystem_B.runCounter; flightControlSystem_B.numRuns++) {
      flightControlSystem_B.firstRunOnPreviousColumn = idxCount->
        data[flightControlSystem_B.numRuns];
      flightControlSystem_B.currentColumn = idxCount->
        data[flightControlSystem_B.numRuns + 1];
      if (flightControlSystem_B.firstRunOnPreviousColumn + 1 >
          flightControlSystem_B.currentColumn) {
        flightControlSystem_B.firstRunOnPreviousColumn = 0;
        flightControlSystem_B.currentColumn = 0;
      }

      flightControlSystem_B.row = flightControlSystem_B.currentColumn -
        flightControlSystem_B.firstRunOnPreviousColumn;
      flightControlSystem_B.currentColumn = c->
        data[flightControlSystem_B.numRuns].f1->size[0];
      c->data[flightControlSystem_B.numRuns].f1->size[0] =
        flightControlSystem_B.row;
      flightControlSystem_emxEnsureCapacity_real_T(c->
        data[flightControlSystem_B.numRuns].f1,
        flightControlSystem_B.currentColumn);
      for (flightControlSystem_B.currentColumn = 0;
           flightControlSystem_B.currentColumn < flightControlSystem_B.row;
           flightControlSystem_B.currentColumn++) {
        c->data[flightControlSystem_B.numRuns].f1->
          data[flightControlSystem_B.currentColumn] = b->
          data[flightControlSystem_B.firstRunOnPreviousColumn +
          flightControlSystem_B.currentColumn];
      }
    }

    flightControlSystem_emxFree_int32_T(&idxCount);
  }

  flightControlSystem_B.row = b->size[0];
  flightControlSystem_B.currentColumn = CC_RegionIndices->size[0];
  CC_RegionIndices->size[0] = b->size[0];
  flightControlSystem_emxEnsureCapacity_real_T(CC_RegionIndices,
    flightControlSystem_B.currentColumn);
  for (flightControlSystem_B.currentColumn = 0;
       flightControlSystem_B.currentColumn < flightControlSystem_B.row;
       flightControlSystem_B.currentColumn++) {
    CC_RegionIndices->data[flightControlSystem_B.currentColumn] = b->
      data[flightControlSystem_B.currentColumn];
  }

  flightControlSystem_emxFree_int16_T(&b);
  flightControlSystem_B.currentColumn = CC_PixelIdxList->size[0] *
    CC_PixelIdxList->size[1];
  CC_PixelIdxList->size[0] = 1;
  flightControlSystem_B.row = c->size[1];
  CC_PixelIdxList->size[1] = c->size[1];
  flightControlSystem_emxEnsureCapacity_cell_wrap_36(CC_PixelIdxList,
    flightControlSystem_B.currentColumn);
  for (flightControlSystem_B.currentColumn = 0;
       flightControlSystem_B.currentColumn < flightControlSystem_B.row;
       flightControlSystem_B.currentColumn++) {
    flightControlSystem_emxCopyStruct_cell_wrap_36(&CC_PixelIdxList->
      data[flightControlSystem_B.currentColumn], &c->
      data[flightControlSystem_B.currentColumn]);
  }

  flightControlSystem_emxFree_cell_wrap_36(&c);
  *CC_Connectivity = 8.0;
}

static void flightControlSystem_emxEnsureCapacity_sOA5t73y81YtF
  (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *emxArray, int32_T
   oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof
                     (sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof
             (sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T) * (uint32_T)
             oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxInitStruct_s_R6Og1x0kmqQXSF9
  (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *pStruct)
{
  pStruct->Image.size[0] = 0;
  pStruct->Image.size[1] = 0;
  pStruct->FilledImage.size[0] = 0;
  pStruct->FilledImage.size[1] = 0;
  flightControlSystem_emxInit_real_T(&pStruct->PixelIdxList, 1);
  flightControlSystem_emxInit_real_T(&pStruct->PixelList, 2);
  flightControlSystem_emxInit_real_T(&pStruct->PixelValues, 1);
  pStruct->SubarrayIdx.size[0] = 0;
  pStruct->SubarrayIdx.size[1] = 0;
}

static void flightControlSystem_emxInit_s_R6Og1x0kmqQXSF9Pwa49F
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T **pEmxArray, int32_T
   numDimensions)
{
  emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *)malloc
    (sizeof(emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxExpand_s_R6Og1x0kmqQXSF9Pwa4
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray, int32_T
   fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    flightControlSystem_emxInitStruct_s_R6Og1x0kmqQXSF9(&emxArray->data[i]);
  }
}

static void flightControlSystem_emxFreeStruct_s_R6Og1x0kmqQXSF9
  (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *pStruct)
{
  flightControlSystem_emxFree_real_T(&pStruct->PixelIdxList);
  flightControlSystem_emxFree_real_T(&pStruct->PixelList);
  flightControlSystem_emxFree_real_T(&pStruct->PixelValues);
}

static void flightControlSystem_emxTrim_s_R6Og1x0kmqQXSF9Pwa49F
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray, int32_T
   fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    flightControlSystem_emxFreeStruct_s_R6Og1x0kmqQXSF9(&emxArray->data[i]);
  }
}

static void flightControlSystem_emxEnsureCapacity_s_R6Og1x0kmqQ
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *emxArray, int32_T
   oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof
                     (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof
             (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T) * (uint32_T)
             oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    flightControlSystem_emxTrim_s_R6Og1x0kmqQXSF9Pwa49F(emxArray, newNumel,
      oldNumel);
  } else if (oldNumel < newNumel) {
    flightControlSystem_emxExpand_s_R6Og1x0kmqQXSF9Pwa4(emxArray, oldNumel,
      newNumel);
  }
}

static void flightControlSystem_emxCopyMatrix_real_T(real_T dst[2], const real_T
  src[2])
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    dst[i] = src[i];
  }
}

static void flightControlSystem_emxCopyMatrix_real_T1(real_T dst[4], const
  real_T src[4])
{
  int32_T i;
  for (i = 0; i < 4; i++) {
    dst[i] = src[i];
  }
}

static void flightControlSystem_emxCopy_boolean_T_0x0
  (emxArray_boolean_T_0x0_flightControlSystem_T *dst, const
   emxArray_boolean_T_0x0_flightControlSystem_T *src)
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    dst->size[i] = src->size[i];
  }
}

static void flightControlSystem_emxCopyMatrix_real_T2(real_T dst[16], const
  real_T src[16])
{
  memcpy(&dst[0], &src[0], sizeof(real_T) << 4U);
}

static void flightControlSystem_emxCopy_real_T_1x0
  (emxArray_real_T_1x0_flightControlSystem_T *dst, const
   emxArray_real_T_1x0_flightControlSystem_T *src)
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    dst->size[i] = src->size[i];
  }
}

static void flightControlSystem_emxCopyStruct_s_R6Og1x0kmqQXSF9
  (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *dst, const
   s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *src)
{
  dst->Area = src->Area;
  flightControlSystem_emxCopyMatrix_real_T(dst->Centroid, src->Centroid);
  flightControlSystem_emxCopyMatrix_real_T1(dst->BoundingBox, src->BoundingBox);
  dst->MajorAxisLength = src->MajorAxisLength;
  dst->MinorAxisLength = src->MinorAxisLength;
  dst->Eccentricity = src->Eccentricity;
  dst->Orientation = src->Orientation;
  flightControlSystem_emxCopy_boolean_T_0x0(&dst->Image, &src->Image);
  flightControlSystem_emxCopy_boolean_T_0x0(&dst->FilledImage, &src->FilledImage);
  dst->FilledArea = src->FilledArea;
  dst->EulerNumber = src->EulerNumber;
  flightControlSystem_emxCopyMatrix_real_T2(dst->Extrema, src->Extrema);
  dst->EquivDiameter = src->EquivDiameter;
  dst->Extent = src->Extent;
  flightControlSystem_emxCopy_real_T(&dst->PixelIdxList, &src->PixelIdxList);
  flightControlSystem_emxCopy_real_T(&dst->PixelList, &src->PixelList);
  dst->Perimeter = src->Perimeter;
  dst->Circularity = src->Circularity;
  flightControlSystem_emxCopy_real_T(&dst->PixelValues, &src->PixelValues);
  flightControlSystem_emxCopyMatrix_real_T(dst->WeightedCentroid,
    src->WeightedCentroid);
  dst->MeanIntensity = src->MeanIntensity;
  dst->MinIntensity = src->MinIntensity;
  dst->MaxIntensity = src->MaxIntensity;
  flightControlSystem_emxCopy_real_T_1x0(&dst->SubarrayIdx, &src->SubarrayIdx);
  flightControlSystem_emxCopyMatrix_real_T(dst->SubarrayIdxLengths,
    src->SubarrayIdxLengths);
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static real_T flightControlSystem_sum(const
  emxArray_real_T_flightControlSystem_T *x)
{
  real_T bsum;
  real_T y;
  int32_T b_k;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    if (x->size[0] <= 1024) {
      firstBlockLength = x->size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int32_T)((uint32_T)x->size[0] >> 10);
      lastBlockLength = x->size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    y = x->data[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
      y += x->data[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x->data[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      for (b_k = 2; b_k <= hi; b_k++) {
        bsum += x->data[(xblockoffset + b_k) - 1];
      }

      y += bsum;
    }
  }

  return y;
}

static void flightControlSystem_binary_expand_op(real_T in1[2], int32_T in2,
  const emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *in3, int32_T in4,
  real_T in5)
{
  emxArray_real_T_flightControlSystem_T *in3_0;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  i = in3->data[in4].PixelList->size[0];
  flightControlSystem_emxInit_real_T(&in3_0, 1);
  stride_1_0 = in3->data[in4].PixelValues->size[0];
  loop_ub = stride_1_0 == 1 ? i : stride_1_0;
  stride_0_0 = in3_0->size[0];
  in3_0->size[0] = loop_ub;
  flightControlSystem_emxEnsureCapacity_real_T(in3_0, stride_0_0);
  stride_0_0 = (i != 1);
  stride_1_0 = (stride_1_0 != 1);
  for (i = 0; i < loop_ub; i++) {
    in3_0->data[i] = in3->data[in4].PixelList->data[i * stride_0_0 + in3->
      data[in4].PixelList->size[0] * in2] * in3->data[in4].PixelValues->data[i *
      stride_1_0];
  }

  in1[in2] = flightControlSystem_sum(in3_0) / in5;
  flightControlSystem_emxFree_real_T(&in3_0);
}

static void flightControlSystem_emxFree_s_R6Og1x0kmqQXSF9Pwa49F
  (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T **pEmxArray)
{
  int32_T i;
  int32_T numEl;
  if (*pEmxArray != (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *)
      NULL) {
    if ((*pEmxArray)->data != (s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *)
        NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        flightControlSystem_emxFreeStruct_s_R6Og1x0kmqQXSF9(&(*pEmxArray)->
          data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_regionprops(const boolean_T varargin_1[19200],
  const real_T varargin_2[19200],
  emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *outstats)
{
  emxArray_cell_wrap_36_flightControlSystem_T *expl_temp;
  emxArray_int32_T_flightControlSystem_T *CC_RegionLengths;
  emxArray_int32_T_flightControlSystem_T *idxCount;
  emxArray_real_T_flightControlSystem_T *CC_RegionIndices;
  emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T *stats;
  flightControlSystem_emxInit_real_T(&CC_RegionIndices, 1);
  flightControlSystem_emxInit_int32_T(&CC_RegionLengths, 1);
  flightControlSystem_emxInit_cell_wrap_36(&expl_temp, 2);
  flightControlSystem_bwconncomp(varargin_1, &flightControlSystem_B.sumIntensity,
    flightControlSystem_B.wc, &flightControlSystem_B.CC_NumObjects,
    CC_RegionIndices, CC_RegionLengths, expl_temp);
  flightControlSystem_emxFree_cell_wrap_36(&expl_temp);
  flightControlSystem_B.outsize_idx_0_tmp_tmp = (int32_T)
    flightControlSystem_B.CC_NumObjects;
  flightControlSystem_B.s.WeightedCentroid[0] = 0.0;
  flightControlSystem_B.s.WeightedCentroid[1] = 0.0;
  flightControlSystem_B.j_n = outstats->size[0];
  outstats->size[0] = (int32_T)flightControlSystem_B.CC_NumObjects;
  flightControlSystem_emxEnsureCapacity_sOA5t73y81YtF(outstats,
    flightControlSystem_B.j_n);
  for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
       flightControlSystem_B.outsize_idx_0_tmp_tmp; flightControlSystem_B.j_n++)
  {
    outstats->data[flightControlSystem_B.j_n] = flightControlSystem_B.s;
  }

  flightControlSystem_emxInitStruct_s_R6Og1x0kmqQXSF9(&flightControlSystem_B.a_p);
  flightControlSystem_B.a_p.Area = 0.0;
  flightControlSystem_B.a_p.Centroid[0] = 0.0;
  flightControlSystem_B.a_p.Centroid[1] = 0.0;
  flightControlSystem_B.a_p.BoundingBox[0] = 0.0;
  flightControlSystem_B.a_p.BoundingBox[1] = 0.0;
  flightControlSystem_B.a_p.BoundingBox[2] = 0.0;
  flightControlSystem_B.a_p.BoundingBox[3] = 0.0;
  flightControlSystem_B.a_p.MajorAxisLength = 0.0;
  flightControlSystem_B.a_p.MinorAxisLength = 0.0;
  flightControlSystem_B.a_p.Eccentricity = 0.0;
  flightControlSystem_B.a_p.Orientation = 0.0;
  flightControlSystem_B.a_p.Image.size[0] = 0;
  flightControlSystem_B.a_p.Image.size[1] = 0;
  flightControlSystem_B.a_p.FilledImage.size[0] = 0;
  flightControlSystem_B.a_p.FilledImage.size[1] = 0;
  flightControlSystem_B.a_p.FilledArea = 0.0;
  flightControlSystem_B.a_p.EulerNumber = 0.0;
  memset(&flightControlSystem_B.a_p.Extrema[0], 0, sizeof(real_T) << 4U);
  flightControlSystem_B.a_p.EquivDiameter = 0.0;
  flightControlSystem_B.a_p.Extent = 0.0;
  flightControlSystem_B.a_p.PixelIdxList->size[0] = 0;
  flightControlSystem_B.a_p.PixelList->size[0] = 0;
  flightControlSystem_B.a_p.PixelList->size[1] = 2;
  flightControlSystem_B.a_p.Perimeter = 0.0;
  flightControlSystem_B.a_p.Circularity = 0.0;
  flightControlSystem_B.a_p.PixelValues->size[0] = 0;
  flightControlSystem_B.a_p.WeightedCentroid[0] = 0.0;
  flightControlSystem_B.a_p.WeightedCentroid[1] = 0.0;
  flightControlSystem_B.a_p.MeanIntensity = 0.0;
  flightControlSystem_B.a_p.MinIntensity = 0.0;
  flightControlSystem_B.a_p.MaxIntensity = 0.0;
  flightControlSystem_B.a_p.SubarrayIdx.size[0] = 1;
  flightControlSystem_B.a_p.SubarrayIdx.size[1] = 0;
  flightControlSystem_B.a_p.SubarrayIdxLengths[0] = 0.0;
  flightControlSystem_B.a_p.SubarrayIdxLengths[1] = 0.0;
  flightControlSystem_emxInit_s_R6Og1x0kmqQXSF9Pwa49F(&stats, 1);
  flightControlSystem_B.j_n = stats->size[0];
  stats->size[0] = (int32_T)flightControlSystem_B.CC_NumObjects;
  flightControlSystem_emxEnsureCapacity_s_R6Og1x0kmqQ(stats,
    flightControlSystem_B.j_n);
  for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
       flightControlSystem_B.outsize_idx_0_tmp_tmp; flightControlSystem_B.j_n++)
  {
    flightControlSystem_emxCopyStruct_s_R6Og1x0kmqQXSF9(&stats->
      data[flightControlSystem_B.j_n], &flightControlSystem_B.a_p);
  }

  flightControlSystem_emxFreeStruct_s_R6Og1x0kmqQXSF9(&flightControlSystem_B.a_p);
  flightControlSystem_emxInit_int32_T(&idxCount, 1);
  if (flightControlSystem_B.CC_NumObjects != 0.0) {
    if ((CC_RegionLengths->size[0] != 1) && (CC_RegionLengths->size[0] != 0) &&
        (CC_RegionLengths->size[0] != 1)) {
      flightControlSystem_B.j_n = CC_RegionLengths->size[0];
      for (flightControlSystem_B.f_k = 0; flightControlSystem_B.f_k <=
           flightControlSystem_B.j_n - 2; flightControlSystem_B.f_k++) {
        CC_RegionLengths->data[flightControlSystem_B.f_k + 1] +=
          CC_RegionLengths->data[flightControlSystem_B.f_k];
      }
    }

    flightControlSystem_B.j_n = idxCount->size[0];
    idxCount->size[0] = CC_RegionLengths->size[0] + 1;
    flightControlSystem_emxEnsureCapacity_int32_T(idxCount,
      flightControlSystem_B.j_n);
    idxCount->data[0] = 0;
    flightControlSystem_B.loop_ub_i = CC_RegionLengths->size[0];
    if (flightControlSystem_B.loop_ub_i - 1 >= 0) {
      memcpy(&idxCount->data[1], &CC_RegionLengths->data[0], (uint32_T)
             flightControlSystem_B.loop_ub_i * sizeof(int32_T));
    }

    for (flightControlSystem_B.k_o = 0; flightControlSystem_B.k_o <
         flightControlSystem_B.outsize_idx_0_tmp_tmp; flightControlSystem_B.k_o
         ++) {
      flightControlSystem_B.f_k = idxCount->data[flightControlSystem_B.k_o];
      flightControlSystem_B.j_n = idxCount->data[flightControlSystem_B.k_o + 1];
      if (flightControlSystem_B.f_k + 1 > flightControlSystem_B.j_n) {
        flightControlSystem_B.f_k = 0;
        flightControlSystem_B.j_n = 0;
      }

      flightControlSystem_B.loop_ub_i = flightControlSystem_B.j_n -
        flightControlSystem_B.f_k;
      flightControlSystem_B.j_n = stats->data[flightControlSystem_B.k_o].
        PixelIdxList->size[0];
      stats->data[flightControlSystem_B.k_o].PixelIdxList->size[0] =
        flightControlSystem_B.loop_ub_i;
      flightControlSystem_emxEnsureCapacity_real_T(stats->
        data[flightControlSystem_B.k_o].PixelIdxList, flightControlSystem_B.j_n);
      for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
           flightControlSystem_B.loop_ub_i; flightControlSystem_B.j_n++) {
        stats->data[flightControlSystem_B.k_o].PixelIdxList->
          data[flightControlSystem_B.j_n] = CC_RegionIndices->
          data[flightControlSystem_B.f_k + flightControlSystem_B.j_n];
      }
    }
  }

  for (flightControlSystem_B.f_k = 0; flightControlSystem_B.f_k <
       flightControlSystem_B.outsize_idx_0_tmp_tmp; flightControlSystem_B.f_k++)
  {
    flightControlSystem_B.loop_ub_i = stats->data[flightControlSystem_B.f_k].
      PixelIdxList->size[0];
    if (flightControlSystem_B.loop_ub_i != 0) {
      flightControlSystem_B.j_n = CC_RegionLengths->size[0];
      CC_RegionLengths->size[0] = flightControlSystem_B.loop_ub_i;
      flightControlSystem_emxEnsureCapacity_int32_T(CC_RegionLengths,
        flightControlSystem_B.j_n);
      flightControlSystem_B.j_n = idxCount->size[0];
      idxCount->size[0] = flightControlSystem_B.loop_ub_i;
      flightControlSystem_emxEnsureCapacity_int32_T(idxCount,
        flightControlSystem_B.j_n);
      flightControlSystem_B.j_n = stats->data[flightControlSystem_B.f_k].
        PixelList->size[0] * stats->data[flightControlSystem_B.f_k]
        .PixelList->size[1];
      stats->data[flightControlSystem_B.f_k].PixelList->size[0] =
        flightControlSystem_B.loop_ub_i;
      stats->data[flightControlSystem_B.f_k].PixelList->size[1] = 2;
      flightControlSystem_emxEnsureCapacity_real_T(stats->
        data[flightControlSystem_B.f_k].PixelList, flightControlSystem_B.j_n);
      for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
           flightControlSystem_B.loop_ub_i; flightControlSystem_B.j_n++) {
        CC_RegionLengths->data[flightControlSystem_B.j_n] = (int32_T)stats->
          data[flightControlSystem_B.f_k].PixelIdxList->
          data[flightControlSystem_B.j_n] - 1;
        idxCount->data[flightControlSystem_B.j_n] = CC_RegionLengths->
          data[flightControlSystem_B.j_n] / 120;
        stats->data[flightControlSystem_B.f_k].PixelList->
          data[flightControlSystem_B.j_n] = (real_T)idxCount->
          data[flightControlSystem_B.j_n] + 1.0;
      }

      for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
           flightControlSystem_B.loop_ub_i; flightControlSystem_B.j_n++) {
        stats->data[flightControlSystem_B.f_k].PixelList->
          data[flightControlSystem_B.j_n + idxCount->size[0]] =
          (CC_RegionLengths->data[flightControlSystem_B.j_n] - idxCount->
           data[flightControlSystem_B.j_n] * 120) + 1;
      }
    } else {
      stats->data[flightControlSystem_B.f_k].PixelList->size[0] = 0;
      stats->data[flightControlSystem_B.f_k].PixelList->size[1] = 2;
    }
  }

  for (flightControlSystem_B.k_o = 0; flightControlSystem_B.k_o <
       flightControlSystem_B.outsize_idx_0_tmp_tmp; flightControlSystem_B.k_o++)
  {
    flightControlSystem_B.loop_ub_i = stats->data[flightControlSystem_B.k_o].
      PixelIdxList->size[0];
    flightControlSystem_B.j_n = stats->data[flightControlSystem_B.k_o].
      PixelValues->size[0];
    stats->data[flightControlSystem_B.k_o].PixelValues->size[0] =
      flightControlSystem_B.loop_ub_i;
    flightControlSystem_emxEnsureCapacity_real_T(stats->
      data[flightControlSystem_B.k_o].PixelValues, flightControlSystem_B.j_n);
    flightControlSystem_B.j_n = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = flightControlSystem_B.loop_ub_i;
    flightControlSystem_emxEnsureCapacity_int32_T(CC_RegionLengths,
      flightControlSystem_B.j_n);
    flightControlSystem_B.j_n = idxCount->size[0];
    idxCount->size[0] = flightControlSystem_B.loop_ub_i;
    flightControlSystem_emxEnsureCapacity_int32_T(idxCount,
      flightControlSystem_B.j_n);
    for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
         flightControlSystem_B.loop_ub_i; flightControlSystem_B.j_n++) {
      CC_RegionLengths->data[flightControlSystem_B.j_n] = (int32_T)stats->
        data[flightControlSystem_B.k_o].PixelIdxList->
        data[flightControlSystem_B.j_n] - 1;
      flightControlSystem_B.CC_RegionLengths = CC_RegionLengths->
        data[flightControlSystem_B.j_n];
      flightControlSystem_B.f_k = flightControlSystem_B.CC_RegionLengths / 120;
      idxCount->data[flightControlSystem_B.j_n] = flightControlSystem_B.f_k;
      CC_RegionLengths->data[flightControlSystem_B.j_n] =
        (flightControlSystem_B.CC_RegionLengths - flightControlSystem_B.f_k *
         120) + 1;
      idxCount->data[flightControlSystem_B.j_n]++;
    }

    flightControlSystem_B.j_n = stats->data[flightControlSystem_B.k_o].
      PixelValues->size[0];
    for (flightControlSystem_B.f_k = 0; flightControlSystem_B.f_k <
         flightControlSystem_B.j_n; flightControlSystem_B.f_k++) {
      stats->data[flightControlSystem_B.k_o].PixelValues->
        data[flightControlSystem_B.f_k] = varargin_2[((idxCount->
        data[flightControlSystem_B.f_k] - 1) * 120 + CC_RegionLengths->
        data[flightControlSystem_B.f_k]) - 1];
    }
  }

  flightControlSystem_emxFree_int32_T(&idxCount);
  flightControlSystem_emxFree_int32_T(&CC_RegionLengths);
  for (flightControlSystem_B.f_k = 0; flightControlSystem_B.f_k <
       flightControlSystem_B.outsize_idx_0_tmp_tmp; flightControlSystem_B.f_k++)
  {
    flightControlSystem_B.sumIntensity = flightControlSystem_sum(stats->
      data[flightControlSystem_B.f_k].PixelValues);
    for (flightControlSystem_B.k_o = 0; flightControlSystem_B.k_o < 2;
         flightControlSystem_B.k_o++) {
      flightControlSystem_B.loop_ub_i = stats->data[flightControlSystem_B.f_k].
        PixelList->size[0];
      if (flightControlSystem_B.loop_ub_i == stats->
          data[flightControlSystem_B.f_k].PixelValues->size[0]) {
        flightControlSystem_B.j_n = CC_RegionIndices->size[0];
        CC_RegionIndices->size[0] = flightControlSystem_B.loop_ub_i;
        flightControlSystem_emxEnsureCapacity_real_T(CC_RegionIndices,
          flightControlSystem_B.j_n);
        for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
             flightControlSystem_B.loop_ub_i; flightControlSystem_B.j_n++) {
          CC_RegionIndices->data[flightControlSystem_B.j_n] = stats->
            data[flightControlSystem_B.f_k].PixelList->data[stats->
            data[flightControlSystem_B.f_k].PixelList->size[0] *
            flightControlSystem_B.k_o + flightControlSystem_B.j_n] * stats->
            data[flightControlSystem_B.f_k].PixelValues->
            data[flightControlSystem_B.j_n];
        }

        flightControlSystem_B.wc[flightControlSystem_B.k_o] =
          flightControlSystem_sum(CC_RegionIndices) /
          flightControlSystem_B.sumIntensity;
      } else {
        flightControlSystem_binary_expand_op(flightControlSystem_B.wc,
          flightControlSystem_B.k_o, stats, flightControlSystem_B.f_k,
          flightControlSystem_B.sumIntensity);
      }
    }

    stats->data[flightControlSystem_B.f_k].WeightedCentroid[0] =
      flightControlSystem_B.wc[0];
    stats->data[flightControlSystem_B.f_k].WeightedCentroid[1] =
      flightControlSystem_B.wc[1];
  }

  flightControlSystem_emxFree_real_T(&CC_RegionIndices);
  flightControlSystem_B.f_k = stats->size[0];
  for (flightControlSystem_B.j_n = 0; flightControlSystem_B.j_n <
       flightControlSystem_B.f_k; flightControlSystem_B.j_n++) {
    outstats->data[flightControlSystem_B.j_n].WeightedCentroid[0] = stats->
      data[flightControlSystem_B.j_n].WeightedCentroid[0];
    outstats->data[flightControlSystem_B.j_n].WeightedCentroid[1] = stats->
      data[flightControlSystem_B.j_n].WeightedCentroid[1];
  }

  flightControlSystem_emxFree_s_R6Og1x0kmqQXSF9Pwa49F(&stats);
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_merge(emxArray_int32_T_flightControlSystem_T
  *idx, emxArray_real_T_flightControlSystem_T *x, int32_T offset, int32_T np,
  int32_T nq, emxArray_int32_T_flightControlSystem_T *iwork,
  emxArray_real_T_flightControlSystem_T *xwork)
{
  int32_T exitg1;
  if (nq != 0) {
    flightControlSystem_B.offset1_d = np + nq;
    for (flightControlSystem_B.q_bn = 0; flightControlSystem_B.q_bn <
         flightControlSystem_B.offset1_d; flightControlSystem_B.q_bn++) {
      flightControlSystem_B.iout = offset + flightControlSystem_B.q_bn;
      iwork->data[flightControlSystem_B.q_bn] = idx->
        data[flightControlSystem_B.iout];
      xwork->data[flightControlSystem_B.q_bn] = x->
        data[flightControlSystem_B.iout];
    }

    flightControlSystem_B.p_h = 0;
    flightControlSystem_B.q_bn = np;
    flightControlSystem_B.iout = offset - 1;
    do {
      exitg1 = 0;
      flightControlSystem_B.iout++;
      if (xwork->data[flightControlSystem_B.p_h] >= xwork->
          data[flightControlSystem_B.q_bn]) {
        idx->data[flightControlSystem_B.iout] = iwork->
          data[flightControlSystem_B.p_h];
        x->data[flightControlSystem_B.iout] = xwork->
          data[flightControlSystem_B.p_h];
        if (flightControlSystem_B.p_h + 1 < np) {
          flightControlSystem_B.p_h++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[flightControlSystem_B.iout] = iwork->
          data[flightControlSystem_B.q_bn];
        x->data[flightControlSystem_B.iout] = xwork->
          data[flightControlSystem_B.q_bn];
        if (flightControlSystem_B.q_bn + 1 < flightControlSystem_B.offset1_d) {
          flightControlSystem_B.q_bn++;
        } else {
          flightControlSystem_B.offset1_d = flightControlSystem_B.iout -
            flightControlSystem_B.p_h;
          for (flightControlSystem_B.q_bn = flightControlSystem_B.p_h + 1;
               flightControlSystem_B.q_bn <= np; flightControlSystem_B.q_bn++) {
            flightControlSystem_B.iout = flightControlSystem_B.offset1_d +
              flightControlSystem_B.q_bn;
            idx->data[flightControlSystem_B.iout] = iwork->
              data[flightControlSystem_B.q_bn - 1];
            x->data[flightControlSystem_B.iout] = xwork->
              data[flightControlSystem_B.q_bn - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_merge_block
  (emxArray_int32_T_flightControlSystem_T *idx,
   emxArray_real_T_flightControlSystem_T *x, int32_T offset, int32_T n, int32_T
   preSortLevel, emxArray_int32_T_flightControlSystem_T *iwork,
   emxArray_real_T_flightControlSystem_T *xwork)
{
  flightControlSystem_B.nPairs = n >> preSortLevel;
  flightControlSystem_B.bLen = 1 << preSortLevel;
  while (flightControlSystem_B.nPairs > 1) {
    if (((uint32_T)flightControlSystem_B.nPairs & 1U) != 0U) {
      flightControlSystem_B.nPairs--;
      flightControlSystem_B.tailOffset = flightControlSystem_B.bLen *
        flightControlSystem_B.nPairs;
      flightControlSystem_B.nTail = n - flightControlSystem_B.tailOffset;
      if (flightControlSystem_B.nTail > flightControlSystem_B.bLen) {
        flightControlSystem_merge(idx, x, offset +
          flightControlSystem_B.tailOffset, flightControlSystem_B.bLen,
          flightControlSystem_B.nTail - flightControlSystem_B.bLen, iwork, xwork);
      }
    }

    flightControlSystem_B.nTail = flightControlSystem_B.bLen << 1;
    flightControlSystem_B.nPairs >>= 1;
    for (flightControlSystem_B.tailOffset = 0; flightControlSystem_B.tailOffset <
         flightControlSystem_B.nPairs; flightControlSystem_B.tailOffset++) {
      flightControlSystem_merge(idx, x, offset +
        flightControlSystem_B.tailOffset * flightControlSystem_B.nTail,
        flightControlSystem_B.bLen, flightControlSystem_B.bLen, iwork, xwork);
    }

    flightControlSystem_B.bLen = flightControlSystem_B.nTail;
  }

  if (n > flightControlSystem_B.bLen) {
    flightControlSystem_merge(idx, x, offset, flightControlSystem_B.bLen, n -
      flightControlSystem_B.bLen, iwork, xwork);
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_sort(emxArray_real_T_flightControlSystem_T *x,
  emxArray_int32_T_flightControlSystem_T *idx)
{
  emxArray_int32_T_flightControlSystem_T *b_idx;
  emxArray_int32_T_flightControlSystem_T *iwork;
  emxArray_real_T_flightControlSystem_T *b_x;
  emxArray_real_T_flightControlSystem_T *xwork;
  int32_T exitg1;
  flightControlSystem_B.loop_ub = x->size[0];
  flightControlSystem_B.ib = idx->size[0] * idx->size[1];
  idx->size[0] = x->size[0];
  idx->size[1] = 1;
  flightControlSystem_emxEnsureCapacity_int32_T(idx, flightControlSystem_B.ib);
  if (flightControlSystem_B.loop_ub - 1 >= 0) {
    memset(&idx->data[0], 0, (uint32_T)flightControlSystem_B.loop_ub * sizeof
           (int32_T));
  }

  if (x->size[0] != 0) {
    flightControlSystem_emxInit_int32_T(&iwork, 1);
    flightControlSystem_emxInit_real_T(&xwork, 1);
    flightControlSystem_emxInit_int32_T(&b_idx, 2);
    flightControlSystem_emxInit_real_T(&b_x, 2);
    for (flightControlSystem_B.k_n = 0; flightControlSystem_B.k_n < 1;
         flightControlSystem_B.k_n++) {
      flightControlSystem_B.loop_ub = x->size[0];
      flightControlSystem_B.ib = xwork->size[0];
      xwork->size[0] = x->size[0];
      flightControlSystem_emxEnsureCapacity_real_T(xwork,
        flightControlSystem_B.ib);
      flightControlSystem_B.idx_tmp = idx->size[0];
      flightControlSystem_B.ib = b_idx->size[0] * b_idx->size[1];
      b_idx->size[0] = idx->size[0];
      b_idx->size[1] = 1;
      flightControlSystem_emxEnsureCapacity_int32_T(b_idx,
        flightControlSystem_B.ib);
      if (flightControlSystem_B.idx_tmp - 1 >= 0) {
        memcpy(&b_idx->data[0], &idx->data[0], (uint32_T)
               flightControlSystem_B.idx_tmp * sizeof(int32_T));
      }

      flightControlSystem_B.ib = b_x->size[0] * b_x->size[1];
      b_x->size[0] = x->size[0];
      b_x->size[1] = 1;
      flightControlSystem_emxEnsureCapacity_real_T(b_x, flightControlSystem_B.ib);
      if (flightControlSystem_B.loop_ub - 1 >= 0) {
        memcpy(&b_x->data[0], &x->data[0], (uint32_T)
               flightControlSystem_B.loop_ub * sizeof(real_T));
      }

      flightControlSystem_B.n = x->size[0] - 1;
      flightControlSystem_B.x4[0] = 0.0;
      flightControlSystem_B.idx4[0] = 0;
      flightControlSystem_B.x4[1] = 0.0;
      flightControlSystem_B.idx4[1] = 0;
      flightControlSystem_B.x4[2] = 0.0;
      flightControlSystem_B.idx4[2] = 0;
      flightControlSystem_B.x4[3] = 0.0;
      flightControlSystem_B.idx4[3] = 0;
      flightControlSystem_B.loop_ub = 0;
      flightControlSystem_B.ib = 0;
      for (flightControlSystem_B.b_k = 0; flightControlSystem_B.b_k <=
           flightControlSystem_B.n; flightControlSystem_B.b_k++) {
        if (rtIsNaN(b_x->data[flightControlSystem_B.b_k])) {
          flightControlSystem_B.quartetOffset = flightControlSystem_B.n -
            flightControlSystem_B.loop_ub;
          b_idx->data[flightControlSystem_B.quartetOffset] =
            flightControlSystem_B.b_k + 1;
          xwork->data[flightControlSystem_B.quartetOffset] = b_x->
            data[flightControlSystem_B.b_k];
          flightControlSystem_B.loop_ub++;
        } else {
          flightControlSystem_B.ib++;
          flightControlSystem_B.idx4[flightControlSystem_B.ib - 1] =
            flightControlSystem_B.b_k + 1;
          flightControlSystem_B.x4[flightControlSystem_B.ib - 1] = b_x->
            data[flightControlSystem_B.b_k];
          if (flightControlSystem_B.ib == 4) {
            flightControlSystem_B.quartetOffset = flightControlSystem_B.b_k -
              flightControlSystem_B.loop_ub;
            if (flightControlSystem_B.x4[0] >= flightControlSystem_B.x4[1]) {
              flightControlSystem_B.ib = 1;
              flightControlSystem_B.i2 = 2;
            } else {
              flightControlSystem_B.ib = 2;
              flightControlSystem_B.i2 = 1;
            }

            if (flightControlSystem_B.x4[2] >= flightControlSystem_B.x4[3]) {
              flightControlSystem_B.i3 = 3;
              flightControlSystem_B.i4 = 4;
            } else {
              flightControlSystem_B.i3 = 4;
              flightControlSystem_B.i4 = 3;
            }

            flightControlSystem_B.d_l =
              flightControlSystem_B.x4[flightControlSystem_B.ib - 1];
            flightControlSystem_B.d1 =
              flightControlSystem_B.x4[flightControlSystem_B.i3 - 1];
            if (flightControlSystem_B.d_l >= flightControlSystem_B.d1) {
              flightControlSystem_B.d_l =
                flightControlSystem_B.x4[flightControlSystem_B.i2 - 1];
              if (flightControlSystem_B.d_l >= flightControlSystem_B.d1) {
                flightControlSystem_B.nLastBlock = flightControlSystem_B.ib;
                flightControlSystem_B.bLen2 = flightControlSystem_B.i2;
                flightControlSystem_B.ib = flightControlSystem_B.i3;
                flightControlSystem_B.i2 = flightControlSystem_B.i4;
              } else if (flightControlSystem_B.d_l >=
                         flightControlSystem_B.x4[flightControlSystem_B.i4 - 1])
              {
                flightControlSystem_B.nLastBlock = flightControlSystem_B.ib;
                flightControlSystem_B.bLen2 = flightControlSystem_B.i3;
                flightControlSystem_B.ib = flightControlSystem_B.i2;
                flightControlSystem_B.i2 = flightControlSystem_B.i4;
              } else {
                flightControlSystem_B.nLastBlock = flightControlSystem_B.ib;
                flightControlSystem_B.bLen2 = flightControlSystem_B.i3;
                flightControlSystem_B.ib = flightControlSystem_B.i4;
              }
            } else {
              flightControlSystem_B.d1 =
                flightControlSystem_B.x4[flightControlSystem_B.i4 - 1];
              if (flightControlSystem_B.d_l >= flightControlSystem_B.d1) {
                if (flightControlSystem_B.x4[flightControlSystem_B.i2 - 1] >=
                    flightControlSystem_B.d1) {
                  flightControlSystem_B.nLastBlock = flightControlSystem_B.i3;
                  flightControlSystem_B.bLen2 = flightControlSystem_B.ib;
                  flightControlSystem_B.ib = flightControlSystem_B.i2;
                  flightControlSystem_B.i2 = flightControlSystem_B.i4;
                } else {
                  flightControlSystem_B.nLastBlock = flightControlSystem_B.i3;
                  flightControlSystem_B.bLen2 = flightControlSystem_B.ib;
                  flightControlSystem_B.ib = flightControlSystem_B.i4;
                }
              } else {
                flightControlSystem_B.nLastBlock = flightControlSystem_B.i3;
                flightControlSystem_B.bLen2 = flightControlSystem_B.i4;
              }
            }

            b_idx->data[flightControlSystem_B.quartetOffset - 3] =
              flightControlSystem_B.idx4[flightControlSystem_B.nLastBlock - 1];
            b_idx->data[flightControlSystem_B.quartetOffset - 2] =
              flightControlSystem_B.idx4[flightControlSystem_B.bLen2 - 1];
            b_idx->data[flightControlSystem_B.quartetOffset - 1] =
              flightControlSystem_B.idx4[flightControlSystem_B.ib - 1];
            b_idx->data[flightControlSystem_B.quartetOffset] =
              flightControlSystem_B.idx4[flightControlSystem_B.i2 - 1];
            b_x->data[flightControlSystem_B.quartetOffset - 3] =
              flightControlSystem_B.x4[flightControlSystem_B.nLastBlock - 1];
            b_x->data[flightControlSystem_B.quartetOffset - 2] =
              flightControlSystem_B.x4[flightControlSystem_B.bLen2 - 1];
            b_x->data[flightControlSystem_B.quartetOffset - 1] =
              flightControlSystem_B.x4[flightControlSystem_B.ib - 1];
            b_x->data[flightControlSystem_B.quartetOffset] =
              flightControlSystem_B.x4[flightControlSystem_B.i2 - 1];
            flightControlSystem_B.ib = 0;
          }
        }
      }

      flightControlSystem_B.b_k = x->size[0] - flightControlSystem_B.loop_ub;
      if (flightControlSystem_B.ib > 0) {
        flightControlSystem_B.perm[1] = 0;
        flightControlSystem_B.perm[2] = 0;
        flightControlSystem_B.perm[3] = 0;
        if (flightControlSystem_B.ib == 1) {
          flightControlSystem_B.perm[0] = 1;
        } else if (flightControlSystem_B.ib == 2) {
          if (flightControlSystem_B.x4[0] >= flightControlSystem_B.x4[1]) {
            flightControlSystem_B.perm[0] = 1;
            flightControlSystem_B.perm[1] = 2;
          } else {
            flightControlSystem_B.perm[0] = 2;
            flightControlSystem_B.perm[1] = 1;
          }
        } else if (flightControlSystem_B.x4[0] >= flightControlSystem_B.x4[1]) {
          if (flightControlSystem_B.x4[1] >= flightControlSystem_B.x4[2]) {
            flightControlSystem_B.perm[0] = 1;
            flightControlSystem_B.perm[1] = 2;
            flightControlSystem_B.perm[2] = 3;
          } else if (flightControlSystem_B.x4[0] >= flightControlSystem_B.x4[2])
          {
            flightControlSystem_B.perm[0] = 1;
            flightControlSystem_B.perm[1] = 3;
            flightControlSystem_B.perm[2] = 2;
          } else {
            flightControlSystem_B.perm[0] = 3;
            flightControlSystem_B.perm[1] = 1;
            flightControlSystem_B.perm[2] = 2;
          }
        } else if (flightControlSystem_B.x4[0] >= flightControlSystem_B.x4[2]) {
          flightControlSystem_B.perm[0] = 2;
          flightControlSystem_B.perm[1] = 1;
          flightControlSystem_B.perm[2] = 3;
        } else if (flightControlSystem_B.x4[1] >= flightControlSystem_B.x4[2]) {
          flightControlSystem_B.perm[0] = 2;
          flightControlSystem_B.perm[1] = 3;
          flightControlSystem_B.perm[2] = 1;
        } else {
          flightControlSystem_B.perm[0] = 3;
          flightControlSystem_B.perm[1] = 2;
          flightControlSystem_B.perm[2] = 1;
        }

        flightControlSystem_B.i3 = (uint8_T)flightControlSystem_B.ib;
        for (flightControlSystem_B.i2 = 0; flightControlSystem_B.i2 <
             flightControlSystem_B.i3; flightControlSystem_B.i2++) {
          flightControlSystem_B.nLastBlock =
            flightControlSystem_B.perm[flightControlSystem_B.i2];
          flightControlSystem_B.quartetOffset = (flightControlSystem_B.b_k -
            flightControlSystem_B.ib) + flightControlSystem_B.i2;
          b_idx->data[flightControlSystem_B.quartetOffset] =
            flightControlSystem_B.idx4[flightControlSystem_B.nLastBlock - 1];
          b_x->data[flightControlSystem_B.quartetOffset] =
            flightControlSystem_B.x4[flightControlSystem_B.nLastBlock - 1];
        }
      }

      flightControlSystem_B.ib = flightControlSystem_B.loop_ub >> 1;
      for (flightControlSystem_B.nLastBlock = 0;
           flightControlSystem_B.nLastBlock < flightControlSystem_B.ib;
           flightControlSystem_B.nLastBlock++) {
        flightControlSystem_B.i2 = flightControlSystem_B.b_k +
          flightControlSystem_B.nLastBlock;
        flightControlSystem_B.i3 = b_idx->data[flightControlSystem_B.i2];
        flightControlSystem_B.quartetOffset = flightControlSystem_B.n -
          flightControlSystem_B.nLastBlock;
        b_idx->data[flightControlSystem_B.i2] = b_idx->
          data[flightControlSystem_B.quartetOffset];
        b_idx->data[flightControlSystem_B.quartetOffset] =
          flightControlSystem_B.i3;
        b_x->data[flightControlSystem_B.i2] = xwork->
          data[flightControlSystem_B.quartetOffset];
        b_x->data[flightControlSystem_B.quartetOffset] = xwork->
          data[flightControlSystem_B.i2];
      }

      if (((uint32_T)flightControlSystem_B.loop_ub & 1U) != 0U) {
        flightControlSystem_B.quartetOffset = flightControlSystem_B.b_k +
          flightControlSystem_B.ib;
        b_x->data[flightControlSystem_B.quartetOffset] = xwork->
          data[flightControlSystem_B.quartetOffset];
      }

      flightControlSystem_B.ib = iwork->size[0];
      iwork->size[0] = idx->size[0];
      flightControlSystem_emxEnsureCapacity_int32_T(iwork,
        flightControlSystem_B.ib);
      if (flightControlSystem_B.idx_tmp - 1 >= 0) {
        memset(&iwork->data[0], 0, (uint32_T)flightControlSystem_B.idx_tmp *
               sizeof(int32_T));
      }

      flightControlSystem_B.quartetOffset = 2;
      if (flightControlSystem_B.b_k > 1) {
        if (x->size[0] >= 256) {
          flightControlSystem_B.n = flightControlSystem_B.b_k >> 8;
          if (flightControlSystem_B.n > 0) {
            for (flightControlSystem_B.nLastBlock = 0;
                 flightControlSystem_B.nLastBlock < flightControlSystem_B.n;
                 flightControlSystem_B.nLastBlock++) {
              flightControlSystem_B.i3 = (flightControlSystem_B.nLastBlock << 8)
                - 1;
              for (flightControlSystem_B.ib = 0; flightControlSystem_B.ib < 6;
                   flightControlSystem_B.ib++) {
                flightControlSystem_B.i4 = 1 << (flightControlSystem_B.ib + 2);
                flightControlSystem_B.bLen2 = flightControlSystem_B.i4 << 1;
                flightControlSystem_B.d_ln = 256 >> (flightControlSystem_B.ib +
                  3);
                for (flightControlSystem_B.i2 = 0; flightControlSystem_B.i2 <
                     flightControlSystem_B.d_ln; flightControlSystem_B.i2++) {
                  flightControlSystem_B.quartetOffset =
                    (flightControlSystem_B.i2 * flightControlSystem_B.bLen2 +
                     flightControlSystem_B.i3) + 1;
                  for (flightControlSystem_B.p = 0; flightControlSystem_B.p <
                       flightControlSystem_B.bLen2; flightControlSystem_B.p++) {
                    flightControlSystem_B.q_b =
                      flightControlSystem_B.quartetOffset +
                      flightControlSystem_B.p;
                    flightControlSystem_B.b_iwork[flightControlSystem_B.p] =
                      b_idx->data[flightControlSystem_B.q_b];
                    flightControlSystem_B.b_xwork[flightControlSystem_B.p] =
                      b_x->data[flightControlSystem_B.q_b];
                  }

                  flightControlSystem_B.p = 0;
                  flightControlSystem_B.q_b = flightControlSystem_B.i4;
                  flightControlSystem_B.quartetOffset--;
                  do {
                    exitg1 = 0;
                    flightControlSystem_B.quartetOffset++;
                    if (flightControlSystem_B.b_xwork[flightControlSystem_B.p] >=
                        flightControlSystem_B.b_xwork[flightControlSystem_B.q_b])
                    {
                      b_idx->data[flightControlSystem_B.quartetOffset] =
                        flightControlSystem_B.b_iwork[flightControlSystem_B.p];
                      b_x->data[flightControlSystem_B.quartetOffset] =
                        flightControlSystem_B.b_xwork[flightControlSystem_B.p];
                      if (flightControlSystem_B.p + 1 < flightControlSystem_B.i4)
                      {
                        flightControlSystem_B.p++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx->data[flightControlSystem_B.quartetOffset] =
                        flightControlSystem_B.b_iwork[flightControlSystem_B.q_b];
                      b_x->data[flightControlSystem_B.quartetOffset] =
                        flightControlSystem_B.b_xwork[flightControlSystem_B.q_b];
                      if (flightControlSystem_B.q_b + 1 <
                          flightControlSystem_B.bLen2) {
                        flightControlSystem_B.q_b++;
                      } else {
                        flightControlSystem_B.offset1 =
                          flightControlSystem_B.quartetOffset -
                          flightControlSystem_B.p;
                        for (flightControlSystem_B.q_b = flightControlSystem_B.p
                             + 1; flightControlSystem_B.q_b <=
                             flightControlSystem_B.i4; flightControlSystem_B.q_b
                             ++) {
                          flightControlSystem_B.quartetOffset =
                            flightControlSystem_B.offset1 +
                            flightControlSystem_B.q_b;
                          b_idx->data[flightControlSystem_B.quartetOffset] =
                            flightControlSystem_B.b_iwork[flightControlSystem_B.q_b
                            - 1];
                          b_x->data[flightControlSystem_B.quartetOffset] =
                            flightControlSystem_B.b_xwork[flightControlSystem_B.q_b
                            - 1];
                        }

                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }

            flightControlSystem_B.n <<= 8;
            flightControlSystem_B.nLastBlock = flightControlSystem_B.b_k -
              flightControlSystem_B.n;
            if (flightControlSystem_B.nLastBlock > 0) {
              flightControlSystem_B.ib = iwork->size[0];
              iwork->size[0] = idx->size[0];
              flightControlSystem_emxEnsureCapacity_int32_T(iwork,
                flightControlSystem_B.ib);
              if (flightControlSystem_B.idx_tmp - 1 >= 0) {
                memset(&iwork->data[0], 0, (uint32_T)
                       flightControlSystem_B.idx_tmp * sizeof(int32_T));
              }

              flightControlSystem_merge_block(b_idx, b_x,
                flightControlSystem_B.n, flightControlSystem_B.nLastBlock, 2,
                iwork, xwork);
            }

            flightControlSystem_B.quartetOffset = 8;
          }
        }

        flightControlSystem_merge_block(b_idx, b_x, 0, flightControlSystem_B.b_k,
          flightControlSystem_B.quartetOffset, iwork, xwork);
      }

      if ((flightControlSystem_B.loop_ub > 0) && (flightControlSystem_B.b_k > 0))
      {
        for (flightControlSystem_B.idx_tmp = 0; flightControlSystem_B.idx_tmp <
             flightControlSystem_B.loop_ub; flightControlSystem_B.idx_tmp++) {
          flightControlSystem_B.quartetOffset = flightControlSystem_B.b_k +
            flightControlSystem_B.idx_tmp;
          xwork->data[flightControlSystem_B.idx_tmp] = b_x->
            data[flightControlSystem_B.quartetOffset];
          iwork->data[flightControlSystem_B.idx_tmp] = b_idx->
            data[flightControlSystem_B.quartetOffset];
        }

        for (flightControlSystem_B.idx_tmp = flightControlSystem_B.b_k;
             flightControlSystem_B.idx_tmp >= 1; flightControlSystem_B.idx_tmp--)
        {
          flightControlSystem_B.quartetOffset = (flightControlSystem_B.loop_ub +
            flightControlSystem_B.idx_tmp) - 1;
          b_x->data[flightControlSystem_B.quartetOffset] = b_x->
            data[flightControlSystem_B.idx_tmp - 1];
          b_idx->data[flightControlSystem_B.quartetOffset] = b_idx->
            data[flightControlSystem_B.idx_tmp - 1];
        }

        memcpy(&b_x->data[0], &xwork->data[0], (uint32_T)
               flightControlSystem_B.loop_ub * sizeof(real_T));
        memcpy(&b_idx->data[0], &iwork->data[0], (uint32_T)
               flightControlSystem_B.loop_ub * sizeof(int32_T));
      }

      flightControlSystem_B.loop_ub = b_idx->size[0];
      flightControlSystem_B.ib = idx->size[0] * idx->size[1];
      idx->size[0] = b_idx->size[0];
      idx->size[1] = 1;
      flightControlSystem_emxEnsureCapacity_int32_T(idx,
        flightControlSystem_B.ib);
      if (flightControlSystem_B.loop_ub - 1 >= 0) {
        memcpy(&idx->data[0], &b_idx->data[0], (uint32_T)
               flightControlSystem_B.loop_ub * sizeof(int32_T));
      }

      flightControlSystem_B.loop_ub = b_x->size[0];
      flightControlSystem_B.ib = x->size[0] * x->size[1];
      x->size[0] = b_x->size[0];
      x->size[1] = 1;
      flightControlSystem_emxEnsureCapacity_real_T(x, flightControlSystem_B.ib);
      if (flightControlSystem_B.loop_ub - 1 >= 0) {
        memcpy(&x->data[0], &b_x->data[0], (uint32_T)
               flightControlSystem_B.loop_ub * sizeof(real_T));
      }
    }

    flightControlSystem_emxFree_real_T(&b_x);
    flightControlSystem_emxFree_int32_T(&b_idx);
    flightControlSystem_emxFree_real_T(&xwork);
    flightControlSystem_emxFree_int32_T(&iwork);
  }
}

static void flightControlSystem_emxFree_sOA5t73y81YtFHGIDxk0fKF
  (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *)
      NULL) {
    if (((*pEmxArray)->data != (sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T *)
         NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static void flightControlSystem_chcenters(const creal_T varargin_1[19200],
  emxArray_real_T_flightControlSystem_T *centers,
  emxArray_real_T_flightControlSystem_T *metric)
{
  emxArray_int32_T_flightControlSystem_T *d_idx;
  emxArray_int32_T_flightControlSystem_T *iidx;
  emxArray_real_T_flightControlSystem_T *b_metric;
  emxArray_real_T_flightControlSystem_T *b_varargin_1;
  emxArray_real_T_flightControlSystem_T *centers_0;
  emxArray_real_T_flightControlSystem_T *varargin_2;
  emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T *s;
  boolean_T exitg1;
  centers->size[0] = 0;
  centers->size[1] = 0;
  metric->size[0] = 0;
  metric->size[1] = 0;
  for (flightControlSystem_B.k = 0; flightControlSystem_B.k < 19200;
       flightControlSystem_B.k++) {
    flightControlSystem_B.accumMatrixRe[flightControlSystem_B.k] = rt_hypotd_snf
      (varargin_1[flightControlSystem_B.k].re,
       varargin_1[flightControlSystem_B.k].im);
  }

  flightControlSystem_B.accumMatrixRe_d = flightControlSystem_B.accumMatrixRe[0];
  for (flightControlSystem_B.inImg_tmp = 0; flightControlSystem_B.inImg_tmp <
       19200; flightControlSystem_B.inImg_tmp++) {
    flightControlSystem_B.bw[flightControlSystem_B.inImg_tmp] =
      (flightControlSystem_B.accumMatrixRe[flightControlSystem_B.inImg_tmp] ==
       flightControlSystem_B.accumMatrixRe_d);
  }

  flightControlSystem_B.flat = true;
  flightControlSystem_B.k = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.k < 19200)) {
    if (!flightControlSystem_B.bw[flightControlSystem_B.k]) {
      flightControlSystem_B.flat = false;
      exitg1 = true;
    } else {
      flightControlSystem_B.k++;
    }
  }

  if (!flightControlSystem_B.flat) {
    for (flightControlSystem_B.k = 0; flightControlSystem_B.k < 124;
         flightControlSystem_B.k++) {
      flightControlSystem_B.inImg[flightControlSystem_B.k] = 0.0;
      flightControlSystem_B.inImg[flightControlSystem_B.k + 20088] = 0.0;
      flightControlSystem_B.inImg[flightControlSystem_B.k + 124] = 0.0;
      flightControlSystem_B.inImg[flightControlSystem_B.k + 20212] = 0.0;
    }

    for (flightControlSystem_B.k = 0; flightControlSystem_B.k < 160;
         flightControlSystem_B.k++) {
      flightControlSystem_B.inImg_tmp = (flightControlSystem_B.k + 2) * 124;
      flightControlSystem_B.inImg[flightControlSystem_B.inImg_tmp] = 0.0;
      flightControlSystem_B.inImg[flightControlSystem_B.inImg_tmp + 122] = 0.0;
      flightControlSystem_B.inImg[flightControlSystem_B.inImg_tmp + 1] = 0.0;
      flightControlSystem_B.inImg[flightControlSystem_B.inImg_tmp + 123] = 0.0;
      memcpy(&flightControlSystem_B.inImg[flightControlSystem_B.inImg_tmp + 2],
             &flightControlSystem_B.accumMatrixRe[flightControlSystem_B.k * 120],
             120U * sizeof(real_T));
    }

    for (flightControlSystem_B.k = 0; flightControlSystem_B.k < 160;
         flightControlSystem_B.k++) {
      for (flightControlSystem_B.g_i = 0; flightControlSystem_B.g_i < 120;
           flightControlSystem_B.g_i++) {
        for (flightControlSystem_B.inImg_tmp = 0;
             flightControlSystem_B.inImg_tmp < 5;
             flightControlSystem_B.inImg_tmp++) {
          for (flightControlSystem_B.nrows = 0; flightControlSystem_B.nrows < 5;
               flightControlSystem_B.nrows++) {
            flightControlSystem_B.inImg_c[flightControlSystem_B.nrows + 5 *
              flightControlSystem_B.inImg_tmp] = flightControlSystem_B.inImg
              [((flightControlSystem_B.inImg_tmp + flightControlSystem_B.k) *
                124 + flightControlSystem_B.nrows) + flightControlSystem_B.g_i];
          }
        }

        flightControlSystem_B.Hd[flightControlSystem_B.g_i + 120 *
          flightControlSystem_B.k] = flightControlSystem_median25
          (flightControlSystem_B.inImg_c);
      }
    }

    memcpy(&flightControlSystem_B.Hd_c[0], &flightControlSystem_B.Hd[0], 19200U *
           sizeof(real_T));
    flightControlSystem_imhmax(flightControlSystem_B.Hd_c,
      flightControlSystem_B.Hd);
    flightControlSystem_imregionalmax(flightControlSystem_B.Hd,
      flightControlSystem_B.bw);
    flightControlSystem_emxInit_sOA5t73y81YtFHGIDxk0fKF(&s, 1);
    flightControlSystem_regionprops(flightControlSystem_B.bw,
      flightControlSystem_B.accumMatrixRe, s);
    if (s->size[0] != 0) {
      flightControlSystem_B.k = s->size[0];
      flightControlSystem_B.nrows = centers->size[0] * centers->size[1];
      centers->size[0] = s->size[0];
      centers->size[1] = 2;
      flightControlSystem_emxEnsureCapacity_real_T(centers,
        flightControlSystem_B.nrows);
      for (flightControlSystem_B.inImg_tmp = 0; flightControlSystem_B.inImg_tmp <
           flightControlSystem_B.k; flightControlSystem_B.inImg_tmp++) {
        centers->data[flightControlSystem_B.inImg_tmp] = s->
          data[flightControlSystem_B.inImg_tmp].WeightedCentroid[0];
        centers->data[flightControlSystem_B.inImg_tmp + centers->size[0]] =
          s->data[flightControlSystem_B.inImg_tmp].WeightedCentroid[1];
      }

      flightControlSystem_B.g_i = centers->size[0] - 1;
      for (flightControlSystem_B.c_idx = 0; flightControlSystem_B.c_idx <
           flightControlSystem_B.k; flightControlSystem_B.c_idx++) {
        flightControlSystem_B.inImg_tmp = flightControlSystem_B.g_i -
          flightControlSystem_B.c_idx;
        if (rtIsNaN(centers->data[flightControlSystem_B.inImg_tmp]) || rtIsNaN
            (centers->data[flightControlSystem_B.inImg_tmp + centers->size[0]]))
        {
          flightControlSystem_B.nrows = centers->size[0];
          for (flightControlSystem_B.b_j = 0; flightControlSystem_B.b_j < 2;
               flightControlSystem_B.b_j++) {
            for (flightControlSystem_B.b_i = flightControlSystem_B.inImg_tmp + 1;
                 flightControlSystem_B.b_i < flightControlSystem_B.nrows;
                 flightControlSystem_B.b_i++) {
              centers->data[(flightControlSystem_B.b_i + centers->size[0] *
                             flightControlSystem_B.b_j) - 1] = centers->
                data[centers->size[0] * flightControlSystem_B.b_j +
                flightControlSystem_B.b_i];
            }
          }

          if (centers->size[0] - 1 < 1) {
            flightControlSystem_B.inImg_tmp = -1;
            flightControlSystem_B.nrows = -1;
          } else {
            flightControlSystem_B.inImg_tmp = centers->size[0] - 2;
            flightControlSystem_B.nrows = centers->size[0] - 2;
          }

          flightControlSystem_B.b_j = flightControlSystem_B.nrows + 1;
          for (flightControlSystem_B.nrows = 0; flightControlSystem_B.nrows < 2;
               flightControlSystem_B.nrows++) {
            for (flightControlSystem_B.b_i = 0; flightControlSystem_B.b_i <
                 flightControlSystem_B.b_j; flightControlSystem_B.b_i++) {
              centers->data[flightControlSystem_B.b_i +
                (flightControlSystem_B.inImg_tmp + 1) *
                flightControlSystem_B.nrows] = centers->data[centers->size[0] *
                flightControlSystem_B.nrows + flightControlSystem_B.b_i];
            }
          }

          flightControlSystem_B.nrows = centers->size[0] * centers->size[1];
          centers->size[0] = flightControlSystem_B.inImg_tmp + 1;
          centers->size[1] = 2;
          flightControlSystem_emxEnsureCapacity_real_T(centers,
            flightControlSystem_B.nrows);
        }
      }

      if (centers->size[0] != 0) {
        flightControlSystem_emxInit_real_T(&b_varargin_1, 1);
        flightControlSystem_B.b_j = centers->size[0];
        flightControlSystem_B.nrows = b_varargin_1->size[0];
        b_varargin_1->size[0] = centers->size[0];
        flightControlSystem_emxEnsureCapacity_real_T(b_varargin_1,
          flightControlSystem_B.nrows);
        flightControlSystem_emxInit_real_T(&varargin_2, 1);
        flightControlSystem_B.nrows = varargin_2->size[0];
        varargin_2->size[0] = centers->size[0];
        flightControlSystem_emxEnsureCapacity_real_T(varargin_2,
          flightControlSystem_B.nrows);
        flightControlSystem_emxInit_int32_T(&d_idx, 1);
        flightControlSystem_B.nrows = d_idx->size[0];
        d_idx->size[0] = centers->size[0];
        flightControlSystem_emxEnsureCapacity_int32_T(d_idx,
          flightControlSystem_B.nrows);
        flightControlSystem_emxInit_real_T(&b_metric, 2);
        flightControlSystem_B.nrows = b_metric->size[0] * b_metric->size[1];
        b_metric->size[0] = centers->size[0];
        b_metric->size[1] = 1;
        flightControlSystem_emxEnsureCapacity_real_T(b_metric,
          flightControlSystem_B.nrows);
        for (flightControlSystem_B.k = 0; flightControlSystem_B.k <
             flightControlSystem_B.b_j; flightControlSystem_B.k++) {
          b_varargin_1->data[flightControlSystem_B.k] = rt_roundd_snf
            (centers->data[flightControlSystem_B.k + centers->size[0]]);
          varargin_2->data[flightControlSystem_B.k] = rt_roundd_snf
            (centers->data[flightControlSystem_B.k]);
          d_idx->data[flightControlSystem_B.k] = ((int32_T)varargin_2->
            data[flightControlSystem_B.k] - 1) * 120 + (int32_T)
            b_varargin_1->data[flightControlSystem_B.k];
          b_metric->data[flightControlSystem_B.k] =
            flightControlSystem_B.Hd[d_idx->data[flightControlSystem_B.k] - 1];
        }

        flightControlSystem_emxFree_int32_T(&d_idx);
        flightControlSystem_emxFree_real_T(&varargin_2);
        flightControlSystem_emxFree_real_T(&b_varargin_1);
        flightControlSystem_emxInit_int32_T(&iidx, 2);
        flightControlSystem_sort(b_metric, iidx);
        flightControlSystem_B.b_j = b_metric->size[0];
        flightControlSystem_B.nrows = metric->size[0] * metric->size[1];
        metric->size[0] = b_metric->size[0];
        metric->size[1] = 1;
        flightControlSystem_emxEnsureCapacity_real_T(metric,
          flightControlSystem_B.nrows);
        if (flightControlSystem_B.b_j - 1 >= 0) {
          memcpy(&metric->data[0], &b_metric->data[0], (uint32_T)
                 flightControlSystem_B.b_j * sizeof(real_T));
        }

        flightControlSystem_emxFree_real_T(&b_metric);
        flightControlSystem_B.k = iidx->size[0];
        flightControlSystem_emxInit_real_T(&centers_0, 2);
        flightControlSystem_B.nrows = centers_0->size[0] * centers_0->size[1];
        centers_0->size[0] = iidx->size[0];
        centers_0->size[1] = 2;
        flightControlSystem_emxEnsureCapacity_real_T(centers_0,
          flightControlSystem_B.nrows);
        for (flightControlSystem_B.inImg_tmp = 0;
             flightControlSystem_B.inImg_tmp < 2;
             flightControlSystem_B.inImg_tmp++) {
          for (flightControlSystem_B.nrows = 0; flightControlSystem_B.nrows <
               flightControlSystem_B.k; flightControlSystem_B.nrows++) {
            centers_0->data[flightControlSystem_B.nrows + centers_0->size[0] *
              flightControlSystem_B.inImg_tmp] = centers->data[(centers->size[0]
              * flightControlSystem_B.inImg_tmp + iidx->
              data[flightControlSystem_B.nrows]) - 1];
          }
        }

        flightControlSystem_B.nrows = centers->size[0] * centers->size[1];
        centers->size[0] = iidx->size[0];
        flightControlSystem_emxFree_int32_T(&iidx);
        centers->size[1] = 2;
        flightControlSystem_emxEnsureCapacity_real_T(centers,
          flightControlSystem_B.nrows);
        flightControlSystem_B.g_i = centers_0->size[0] << 1;
        if (flightControlSystem_B.g_i - 1 >= 0) {
          memcpy(&centers->data[0], &centers_0->data[0], (uint32_T)
                 flightControlSystem_B.g_i * sizeof(real_T));
        }

        flightControlSystem_emxFree_real_T(&centers_0);
      }
    }

    flightControlSystem_emxFree_sOA5t73y81YtFHGIDxk0fKF(&s);
  }
}

static void flightControlSystem_emxInit_uint32_T
  (emxArray_uint32_T_flightControlSystem_T **pEmxArray, int32_T numDimensions)
{
  emxArray_uint32_T_flightControlSystem_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_uint32_T_flightControlSystem_T *)malloc(sizeof
    (emxArray_uint32_T_flightControlSystem_T));
  emxArray = *pEmxArray;
  emxArray->data = (uint32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void flightControlSystem_emxEnsureCapacity_uint32_T
  (emxArray_uint32_T_flightControlSystem_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(uint32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(uint32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (uint32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void flightControlSystem_emxFree_uint32_T
  (emxArray_uint32_T_flightControlSystem_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint32_T_flightControlSystem_T *)NULL) {
    if (((*pEmxArray)->data != (uint32_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint32_T_flightControlSystem_T *)NULL;
  }
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  int32_T i;
  int32_T tmp;

  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.MeasurementUpdate_n.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC);

  /* RateTransition: '<Root>/Rate Transition' */
  tmp = flightControlSystem_DW.RateTransition_ActiveBufIdx * 5;
  for (i = 0; i < 5; i++) {
    /* RateTransition: '<Root>/Rate Transition' */
    flightControlSystem_B.RateTransition[i] =
      flightControlSystem_DW.RateTransition_Buffer[i + tmp];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Control System' */
  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_ControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, flightControlSystem_B.RateTransition,
    &flightControlSystem_B.ControlSystem, &flightControlSystem_DW.ControlSystem,
    &flightControlSystem_P.ControlSystem,
    &flightControlSystem_PrevZCX.ControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)flightControlSystem_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }

    if (rtmGetStopRequested(flightControlSystem_M)) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++flightControlSystem_M->Timing.clockTick0)) {
    ++flightControlSystem_M->Timing.clockTickH0;
  }

  flightControlSystem_M->Timing.taskTime0 =
    flightControlSystem_M->Timing.clockTick0 *
    flightControlSystem_M->Timing.stepSize0 +
    flightControlSystem_M->Timing.clockTickH0 *
    flightControlSystem_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void flightControlSystem_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  emxArray_boolean_T_flightControlSystem_T *x;
  emxArray_int32_T_flightControlSystem_T *ii;
  emxArray_real_T_flightControlSystem_T *centers;
  emxArray_real_T_flightControlSystem_T *centers_0;
  emxArray_real_T_flightControlSystem_T *metric;
  emxArray_real_T_flightControlSystem_T *metric_0;
  emxArray_uint32_T_flightControlSystem_T *idx2Keep;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard11;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  MW_Build_RGB(&imRGB[0], &flightControlSystem_B.R[0], &flightControlSystem_B.G
               [0], &flightControlSystem_B.B[0]);

  /* MATLAB Function: '<S525>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S2>/PARROT Image Conversion'
   */
  flightControlSystem_DW.sfEvent_f = flightControlSystem_CALL_EVENT_ax;
  for (flightControlSystem_B.W = 0; flightControlSystem_B.W < 19200;
       flightControlSystem_B.W++) {
    flightControlSystem_B.u[flightControlSystem_B.W] =
      flightControlSystem_B.R[flightControlSystem_B.W];
    flightControlSystem_B.u[flightControlSystem_B.W + 19200] =
      flightControlSystem_B.G[flightControlSystem_B.W];
    flightControlSystem_B.u[flightControlSystem_B.W + 38400] =
      flightControlSystem_B.B[flightControlSystem_B.W];
  }

  for (flightControlSystem_B.xk = 0; flightControlSystem_B.xk < 57600;
       flightControlSystem_B.xk++) {
    flightControlSystem_B.Xin[flightControlSystem_B.xk] = (real_T)
      flightControlSystem_B.u[flightControlSystem_B.xk] / 255.0;
  }

  for (flightControlSystem_B.xk = 0; flightControlSystem_B.xk < 19200;
       flightControlSystem_B.xk++) {
    flightControlSystem_B.tmp =
      flightControlSystem_B.Xin[flightControlSystem_B.xk];
    flightControlSystem_B.way_x_n =
      flightControlSystem_B.Xin[flightControlSystem_B.xk + 19200];
    flightControlSystem_B.way_y_d =
      flightControlSystem_B.Xin[flightControlSystem_B.xk + 38400];
    flightControlSystem_B.xi = flightControlSystem_B.tmp;
    flightControlSystem_B.delta = flightControlSystem_B.tmp;
    if (flightControlSystem_B.tmp < flightControlSystem_B.way_x_n) {
      flightControlSystem_B.xi = flightControlSystem_B.way_x_n;
    }

    if (flightControlSystem_B.tmp > flightControlSystem_B.way_x_n) {
      flightControlSystem_B.delta = flightControlSystem_B.way_x_n;
    }

    if (flightControlSystem_B.xi < flightControlSystem_B.way_y_d) {
      flightControlSystem_B.xi = flightControlSystem_B.way_y_d;
    }

    if (flightControlSystem_B.delta > flightControlSystem_B.way_y_d) {
      flightControlSystem_B.delta = flightControlSystem_B.way_y_d;
    }

    flightControlSystem_B.delta = flightControlSystem_B.xi -
      flightControlSystem_B.delta;
    flightControlSystem_B.iter_y = flightControlSystem_B.delta;
    if (flightControlSystem_B.delta == 0.0) {
      flightControlSystem_B.iter_y = 1.0;
    }

    flightControlSystem_B.way_y = 0.0;
    if (flightControlSystem_B.tmp == flightControlSystem_B.xi) {
      flightControlSystem_B.way_y = (flightControlSystem_B.way_x_n -
        flightControlSystem_B.way_y_d) / flightControlSystem_B.iter_y;
    }

    if (flightControlSystem_B.way_x_n == flightControlSystem_B.xi) {
      flightControlSystem_B.way_y = (flightControlSystem_B.way_y_d -
        flightControlSystem_B.tmp) / flightControlSystem_B.iter_y + 2.0;
    }

    if (flightControlSystem_B.way_y_d == flightControlSystem_B.xi) {
      flightControlSystem_B.way_y = (flightControlSystem_B.tmp -
        flightControlSystem_B.way_x_n) / flightControlSystem_B.iter_y + 4.0;
    }

    flightControlSystem_B.way_y /= 6.0;
    if (flightControlSystem_B.way_y < 0.0) {
      flightControlSystem_B.way_y++;
    }

    flightControlSystem_B.tmp = flightControlSystem_B.iter_y /
      flightControlSystem_B.xi;
    if (flightControlSystem_B.delta == 0.0) {
      flightControlSystem_B.way_y = 0.0;
      flightControlSystem_B.tmp = 0.0;
    }

    if (!(flightControlSystem_B.xi != 0.0)) {
      flightControlSystem_B.tmp = 0.0;
    }

    flightControlSystem_B.BW[flightControlSystem_B.xk] =
      ((((flightControlSystem_B.way_y >= 0.0) && (flightControlSystem_B.way_y <=
          0.05)) || ((flightControlSystem_B.way_y >= 0.95) &&
                     (flightControlSystem_B.way_y <= 1.0))) &&
       ((flightControlSystem_B.tmp > 0.5) && (flightControlSystem_B.xi > 0.2)));
  }

  /* End of MATLAB Function: '<S525>/MATLAB Function' */

  /* MATLAB Function: '<S2>/opposite_way' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   */
  flightControlSystem_DW.sfEvent_d = flightControlSystem_CALL_EVENT_ax;
  if ((flightControlSystem_DW.xy[0] == 0.0) || (flightControlSystem_DW.xy[1] ==
       0.0)) {
    flightControlSystem_B.way_x_n = 0.0;
    flightControlSystem_B.way_y_d = 0.0;
  } else {
    flightControlSystem_B.way_x_n = ((60.0 - flightControlSystem_DW.xy[0]) +
      60.0) + 1.0;
    flightControlSystem_B.way_y_d = ((80.0 - flightControlSystem_DW.xy[1]) +
      80.0) + 1.0;
  }

  /* End of MATLAB Function: '<S2>/opposite_way' */

  /* MATLAB Function: '<S2>/MATLAB Function4' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  flightControlSystem_DW.sfEvent_b = flightControlSystem_CALL_EVENT_ax;
  flightControlSystem_B.W = -1;
  if (flightControlSystem_B.way_x_n == 1.0) {
    flightControlSystem_B.tmp = flightControlSystem_B.way_y_d -
      flightControlSystem_P.Constant1_Value;
    if (flightControlSystem_B.tmp < 1.0) {
      flightControlSystem_B.xi = 1.0 - flightControlSystem_B.tmp;
      flightControlSystem_B.tmp = 1.0;
    } else {
      flightControlSystem_B.xi = 1.0;
    }

    flightControlSystem_B.way_y_d += flightControlSystem_P.Constant1_Value;
    if (flightControlSystem_B.way_y_d > 160.0) {
      flightControlSystem_B.way_x_n = flightControlSystem_B.way_y_d - 160.0;
      flightControlSystem_B.way_y_d = 160.0;
    } else {
      flightControlSystem_B.way_x_n = 1.0;
    }
  } else {
    guard1 = false;
    if (flightControlSystem_B.way_x_n == 120.0) {
      flightControlSystem_B.W = 3;
      guard1 = true;
    } else if (flightControlSystem_B.way_y_d == 1.0) {
      flightControlSystem_B.xi = flightControlSystem_B.way_x_n +
        flightControlSystem_P.Constant1_Value;
      if (flightControlSystem_B.xi > 120.0) {
        flightControlSystem_B.tmp = flightControlSystem_B.xi - 120.0;
        flightControlSystem_B.xi = 120.0;
      } else {
        flightControlSystem_B.tmp = 1.0;
      }

      flightControlSystem_B.way_x_n -= flightControlSystem_P.Constant1_Value;
      if (flightControlSystem_B.way_x_n < 1.0) {
        flightControlSystem_B.way_y_d = fabs(flightControlSystem_B.way_x_n) +
          1.0;
        flightControlSystem_B.way_x_n = 1.0;
      } else {
        flightControlSystem_B.way_y_d = 1.0;
      }
    } else if (flightControlSystem_B.way_y_d == 160.0) {
      flightControlSystem_B.xi = flightControlSystem_B.way_x_n -
        flightControlSystem_P.Constant1_Value;
      if (flightControlSystem_B.xi < 1.0) {
        flightControlSystem_B.tmp = flightControlSystem_B.xi + 160.0;
        flightControlSystem_B.xi = 1.0;
      } else {
        flightControlSystem_B.tmp = 160.0;
      }

      flightControlSystem_B.way_x_n += flightControlSystem_P.Constant1_Value;
      if (flightControlSystem_B.way_x_n > 120.0) {
        flightControlSystem_B.way_y_d = 160.0 - (flightControlSystem_B.way_x_n -
          120.0);
        flightControlSystem_B.way_x_n = 120.0;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (flightControlSystem_B.W == 3) {
        flightControlSystem_B.tmp = flightControlSystem_B.way_y_d +
          flightControlSystem_P.Constant1_Value;
        if (flightControlSystem_B.tmp > 160.0) {
          flightControlSystem_B.xi = 120.0 - (flightControlSystem_B.tmp - 160.0);
          flightControlSystem_B.tmp = 160.0;
        } else {
          flightControlSystem_B.xi = flightControlSystem_B.way_x_n;
        }

        flightControlSystem_B.way_y_d -= flightControlSystem_P.Constant1_Value;
        if (flightControlSystem_B.way_y_d < 1.0) {
          flightControlSystem_B.way_x_n = flightControlSystem_B.way_y_d + 120.0;
          flightControlSystem_B.way_y_d = 1.0;
        }
      } else {
        flightControlSystem_B.xi = 1.0;
        flightControlSystem_B.tmp = 1.0;
        flightControlSystem_B.way_x_n = 1.0;
        flightControlSystem_B.way_y_d = 2.0;
      }
    }
  }

  /* MATLAB Function: '<S2>/Main control' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read'
   *  MATLAB Function: '<S2>/center_vector_x'
   *  MATLAB Function: '<S2>/center_vector_y'
   */
  flightControlSystem_DW.sfEvent_g = flightControlSystem_CALL_EVENT_ax;
  flightControlSystem_B.compare_tmp = !flightControlSystem_B.BW[9539];
  flightControlSystem_B.W = 0;
  flightControlSystem_B.delta = 1.0;
  flightControlSystem_B.way_y = 1.0;
  if ((flightControlSystem_DW.xy[0] == 0.0) || (flightControlSystem_DW.xy[1] ==
       0.0)) {
    flightControlSystem_B.W = 1;
  } else if (flightControlSystem_B.BW[(((int32_T)flightControlSystem_DW.xy[1] -
               1) * 120 + (int32_T)flightControlSystem_DW.xy[0]) - 1]) {
    if ((flightControlSystem_DW.xy[0] == 1.0) || (flightControlSystem_DW.xy[0] ==
         120.0)) {
      flightControlSystem_B.iter_y = flightControlSystem_DW.xy[1];
      flightControlSystem_B.way_y = flightControlSystem_DW.xy[0];
      flightControlSystem_B.x1 = 1;
      flightControlSystem_B.swapepd = 0;
      flightControlSystem_B.delta = 0.0;
      exitg1 = false;
      while ((!exitg1) && flightControlSystem_B.BW[(((int32_T)
               flightControlSystem_B.iter_y - 1) * 120 + (int32_T)
              flightControlSystem_B.way_y) - 1]) {
        if (flightControlSystem_B.swapepd == 0) {
          flightControlSystem_B.iter_y += (real_T)flightControlSystem_B.x1;
        } else {
          flightControlSystem_B.way_y += (real_T)flightControlSystem_B.x1;
        }

        flightControlSystem_B.delta++;
        if (flightControlSystem_B.iter_y > 160.0) {
          flightControlSystem_B.iter_y = 160.0;
          flightControlSystem_B.swapepd = 1;
          if (flightControlSystem_B.way_y == 120.0) {
            flightControlSystem_B.x1 = -1;
          } else if (flightControlSystem_B.way_y == 1.0) {
            flightControlSystem_B.x1 = 1;
          }
        }

        if ((flightControlSystem_B.way_y < 1.0) || (flightControlSystem_B.way_y >
             120.0)) {
          exitg1 = true;
        }
      }

      flightControlSystem_B.m = flightControlSystem_B.delta;
      flightControlSystem_B.iter_y = flightControlSystem_DW.xy[1];
      flightControlSystem_B.way_y = flightControlSystem_DW.xy[0];
      flightControlSystem_B.x1 = -1;
      flightControlSystem_B.swapepd = 0;
      flightControlSystem_B.delta = 0.0;
      exitg1 = false;
      while ((!exitg1) && flightControlSystem_B.BW[(((int32_T)
               flightControlSystem_B.iter_y - 1) * 120 + (int32_T)
              flightControlSystem_B.way_y) - 1]) {
        if (flightControlSystem_B.swapepd == 0) {
          flightControlSystem_B.iter_y += (real_T)flightControlSystem_B.x1;
        } else {
          flightControlSystem_B.way_y += (real_T)flightControlSystem_B.x1;
        }

        flightControlSystem_B.delta++;
        if (flightControlSystem_B.iter_y < 1.0) {
          flightControlSystem_B.iter_y = 1.0;
          flightControlSystem_B.swapepd = 1;
          if (flightControlSystem_B.way_y == 120.0) {
            flightControlSystem_B.x1 = -1;
          } else if (flightControlSystem_B.way_y == 1.0) {
            flightControlSystem_B.x1 = 1;
          }
        }

        if ((flightControlSystem_B.way_y < 1.0) || (flightControlSystem_B.way_y >
             120.0)) {
          exitg1 = true;
        }
      }

      flightControlSystem_B.way_y = 0.0;
      flightControlSystem_B.delta = flightControlSystem_B.m -
        flightControlSystem_B.delta;
      flightControlSystem_B.iter_y = fabs(flightControlSystem_B.delta);
      if ((flightControlSystem_B.iter_y >= 7.0) && (flightControlSystem_B.iter_y
           < 25.0)) {
        flightControlSystem_B.m = rt_roundd_snf(flightControlSystem_B.delta /
          2.0);
      } else {
        flightControlSystem_B.m = 0.0;
      }
    } else {
      flightControlSystem_B.way_y = flightControlSystem_DW.xy[0];
      flightControlSystem_B.iter_y = flightControlSystem_DW.xy[1];
      flightControlSystem_B.x1 = -1;
      flightControlSystem_B.swapepd = 1;
      flightControlSystem_B.delta = 0.0;
      exitg1 = false;
      while ((!exitg1) && flightControlSystem_B.BW[(((int32_T)
               flightControlSystem_B.iter_y - 1) * 120 + (int32_T)
              flightControlSystem_B.way_y) - 1]) {
        if (flightControlSystem_B.swapepd == 0) {
          flightControlSystem_B.iter_y += (real_T)flightControlSystem_B.x1;
        } else {
          flightControlSystem_B.way_y += (real_T)flightControlSystem_B.x1;
        }

        flightControlSystem_B.delta++;
        if (flightControlSystem_B.way_y < 1.0) {
          flightControlSystem_B.way_y = 1.0;
          flightControlSystem_B.swapepd = 0;
          if (flightControlSystem_B.iter_y == 1.0) {
            flightControlSystem_B.x1 = 1;
          } else if (flightControlSystem_B.iter_y == 160.0) {
            flightControlSystem_B.x1 = -1;
          }
        }

        if ((flightControlSystem_B.iter_y > 160.0) ||
            (flightControlSystem_B.iter_y < 1.0)) {
          exitg1 = true;
        }
      }

      flightControlSystem_B.m = flightControlSystem_B.delta;
      flightControlSystem_B.way_y = flightControlSystem_DW.xy[0];
      flightControlSystem_B.iter_y = flightControlSystem_DW.xy[1];
      flightControlSystem_B.x1 = 1;
      flightControlSystem_B.swapepd = 1;
      flightControlSystem_B.delta = 0.0;
      exitg1 = false;
      while ((!exitg1) && flightControlSystem_B.BW[(((int32_T)
               flightControlSystem_B.iter_y - 1) * 120 + (int32_T)
              flightControlSystem_B.way_y) - 1]) {
        if (flightControlSystem_B.swapepd == 0) {
          flightControlSystem_B.iter_y += (real_T)flightControlSystem_B.x1;
        } else {
          flightControlSystem_B.way_y += (real_T)flightControlSystem_B.x1;
        }

        flightControlSystem_B.delta++;
        if (flightControlSystem_B.way_y > 120.0) {
          flightControlSystem_B.swapepd = 0;
          flightControlSystem_B.way_y = 120.0;
          if (flightControlSystem_B.iter_y == 1.0) {
            flightControlSystem_B.x1 = 1;
          } else if (flightControlSystem_B.iter_y == 160.0) {
            flightControlSystem_B.x1 = -1;
          }
        }

        if ((flightControlSystem_B.iter_y > 160.0) ||
            (flightControlSystem_B.iter_y < 1.0)) {
          exitg1 = true;
        }
      }

      flightControlSystem_B.delta -= flightControlSystem_B.m;
      flightControlSystem_B.m = 0.0;
      flightControlSystem_B.iter_y = fabs(flightControlSystem_B.delta);
      if ((flightControlSystem_B.iter_y >= 7.0) && (flightControlSystem_B.iter_y
           < 25.0)) {
        flightControlSystem_B.way_y = rt_roundd_snf(flightControlSystem_B.delta /
          2.0);
      } else {
        flightControlSystem_B.way_y = 0.0;
      }
    }

    flightControlSystem_B.delta = flightControlSystem_DW.xy[0] +
      flightControlSystem_B.way_y;
    flightControlSystem_B.way_y = flightControlSystem_DW.xy[1] +
      flightControlSystem_B.m;
    if (flightControlSystem_B.way_y > 160.0) {
      if (flightControlSystem_B.delta == 120.0) {
        flightControlSystem_B.delta = 120.0 - flightControlSystem_mod
          (flightControlSystem_B.way_y);
      } else if (flightControlSystem_B.delta == 1.0) {
        flightControlSystem_B.delta = flightControlSystem_mod
          (flightControlSystem_B.way_y);
      }

      flightControlSystem_B.way_y = 160.0;
    } else if (flightControlSystem_B.way_y < 1.0) {
      if (flightControlSystem_B.delta == 120.0) {
        flightControlSystem_B.delta = 120.0 - fabs(flightControlSystem_B.way_y);
      } else if (flightControlSystem_B.delta == 1.0) {
        flightControlSystem_B.delta = fabs(flightControlSystem_B.way_y);
      }

      flightControlSystem_B.way_y = 1.0;
    } else if (flightControlSystem_B.delta < 1.0) {
      if (flightControlSystem_B.way_y == 160.0) {
        flightControlSystem_B.way_y = 160.0 - fabs(flightControlSystem_B.delta);
      } else if (flightControlSystem_B.way_y == 1.0) {
        flightControlSystem_B.way_y = fabs(flightControlSystem_B.delta);
      }

      flightControlSystem_B.delta = 1.0;
    } else if (flightControlSystem_B.delta > 120.0) {
      if (flightControlSystem_B.way_y == 160.0) {
        flightControlSystem_B.way_y = 160.0 - (flightControlSystem_B.delta -
          120.0);
      } else if (flightControlSystem_B.way_y == 1.0) {
        flightControlSystem_B.way_y = flightControlSystem_B.delta - 120.0;
      }

      flightControlSystem_B.delta = 120.0;
    }
  } else if (flightControlSystem_B.BW[9539]) {
    flightControlSystem_B.iter_y = flightControlSystem_DW.xy[0];
    flightControlSystem_B.m = flightControlSystem_DW.xy[1];
    flightControlSystem_B.b_y1 = 80;
    flightControlSystem_B.x1 = 60;
    flightControlSystem_B.swapepd = 0;
    if (fabs(flightControlSystem_DW.xy[1] - 80.0) > fabs
        (flightControlSystem_DW.xy[0] - 60.0)) {
      flightControlSystem_B.swapepd = 1;
      flightControlSystem_B.x1 = 80;
      flightControlSystem_B.b_y1 = 60;
      flightControlSystem_B.iter_y = flightControlSystem_DW.xy[1];
      flightControlSystem_B.m = flightControlSystem_DW.xy[0];
      flightControlSystem_B.xk = 1;
      flightControlSystem_B.yk = 1;
      if (flightControlSystem_DW.xy[1] < 80.0) {
        flightControlSystem_B.xk = -1;
      }

      if (flightControlSystem_DW.xy[0] < 60.0) {
        flightControlSystem_B.yk = -1;
      }
    } else {
      flightControlSystem_B.xk = -1;
      flightControlSystem_B.yk = -1;
      if (flightControlSystem_DW.xy[0] > 60.0) {
        flightControlSystem_B.xk = 1;
      }

      if (flightControlSystem_DW.xy[1] > 80.0) {
        flightControlSystem_B.yk = 1;
      }
    }

    flightControlSystem_B.delta = fabs(flightControlSystem_B.iter_y - (real_T)
      flightControlSystem_B.x1);
    flightControlSystem_B.way_y = 0.0;
    flightControlSystem_B.m = fabs(flightControlSystem_B.m - (real_T)
      flightControlSystem_B.b_y1) * 2.0;
    flightControlSystem_B.slope_error = flightControlSystem_B.m - 2.0 *
      flightControlSystem_B.delta;
    flightControlSystem_B.y = flightControlSystem_B.b_y1;
    flightControlSystem_B.range = 1.0;
    flightControlSystem_B.b_y1 = (int32_T)(((real_T)(flightControlSystem_B.xk -
      flightControlSystem_B.x1) + flightControlSystem_B.iter_y) / (real_T)
      flightControlSystem_B.xk);
    flightControlSystem_B.b_x = 0;
    exitg1 = false;
    while ((!exitg1) && (flightControlSystem_B.b_x <= flightControlSystem_B.b_y1
                         - 1)) {
      flightControlSystem_B.iter_y = (real_T)flightControlSystem_B.b_x * (real_T)
        flightControlSystem_B.xk + (real_T)flightControlSystem_B.x1;
      guard11 = false;
      if (flightControlSystem_B.swapepd == 1) {
        if (flightControlSystem_B.BW[(((int32_T)flightControlSystem_B.iter_y - 1)
             * 120 + (int32_T)flightControlSystem_B.y) - 1] ==
            flightControlSystem_B.compare_tmp) {
          flightControlSystem_B.way_y = flightControlSystem_B.range;
          exitg1 = true;
        } else {
          guard11 = true;
        }
      } else if (flightControlSystem_B.BW[(((int32_T)flightControlSystem_B.y - 1)
                  * 120 + (int32_T)flightControlSystem_B.iter_y) - 1] ==
                 flightControlSystem_B.compare_tmp) {
        flightControlSystem_B.way_y = flightControlSystem_B.range;
        exitg1 = true;
      } else {
        guard11 = true;
      }

      if (guard11) {
        flightControlSystem_B.range++;
        flightControlSystem_B.slope_error += flightControlSystem_B.m;
        if (flightControlSystem_B.slope_error > 0.0) {
          flightControlSystem_B.y += (real_T)flightControlSystem_B.yk;
          flightControlSystem_B.slope_error -= 2.0 * flightControlSystem_B.delta;
        }

        flightControlSystem_B.b_x++;
      }
    }

    if (flightControlSystem_B.way_y < flightControlSystem_P.Constant_Value) {
      flightControlSystem_B.W = 1;
    }

    flightControlSystem_B.delta = flightControlSystem_DW.xy[0];
    flightControlSystem_B.way_y = flightControlSystem_DW.xy[1];
  } else {
    flightControlSystem_B.W = 1;
    flightControlSystem_B.delta = flightControlSystem_DW.xy[0];
    flightControlSystem_B.way_y = flightControlSystem_DW.xy[1];
  }

  /* MATLAB Function: '<S2>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function4'
   */
  flightControlSystem_DW.sfEvent_p = flightControlSystem_CALL_EVENT_ax;
  flightControlSystem_B.m = 1.0;
  flightControlSystem_B.iter_y = 2.0;
  if (flightControlSystem_B.W != 0) {
    if (flightControlSystem_B.BW[9539]) {
      flightControlSystem_B.y = 0.0;
      flightControlSystem_B.mx_endless_x[0] = 0.0;
      flightControlSystem_B.mx_endless_y[0] = 0.0;
      flightControlSystem_B.mx_t[0] = 0.0;
      flightControlSystem_B.mx_endless_x[1] = 0.0;
      flightControlSystem_B.mx_endless_y[1] = 0.0;
      flightControlSystem_B.mx_t[1] = 0.0;
      flightControlSystem_B.last_endless = false;
      flightControlSystem_B.swapepd = -1;
      flightControlSystem_B.xk = -1;
      if (flightControlSystem_B.xi == 1.0) {
        flightControlSystem_B.xk = 1;
      } else if (flightControlSystem_B.xi == 120.0) {
        flightControlSystem_B.xk = 3;
      } else if (flightControlSystem_B.tmp == 1.0) {
        flightControlSystem_B.xk = 2;
      } else if (flightControlSystem_B.tmp == 160.0) {
        flightControlSystem_B.xk = 4;
      }

      flightControlSystem_B.x1 = 1;
      if ((flightControlSystem_B.xk == 1) || (flightControlSystem_B.xk == 4)) {
        flightControlSystem_B.x1 = -1;
      }

      exitg1 = false;
      while ((!exitg1) && ((flightControlSystem_B.xi !=
                            flightControlSystem_B.way_x_n) ||
                           (flightControlSystem_B.tmp !=
                            flightControlSystem_B.way_y_d))) {
        flightControlSystem_B.slope_error = flightControlSystem_line_drawer
          (flightControlSystem_B.xi, flightControlSystem_B.tmp,
           flightControlSystem_B.BW, 0.0);
        guard11 = false;
        if (flightControlSystem_B.slope_error == 0.0) {
          if (!flightControlSystem_B.last_endless) {
            flightControlSystem_B.last_endless = true;
            flightControlSystem_B.swapepd++;
          }

          if (flightControlSystem_B.swapepd + 1 > 2) {
            exitg1 = true;
          } else {
            flightControlSystem_B.mx_endless_x[flightControlSystem_B.swapepd] +=
              flightControlSystem_B.xi;
            flightControlSystem_B.mx_endless_y[flightControlSystem_B.swapepd] +=
              flightControlSystem_B.tmp;
            flightControlSystem_B.mx_t[flightControlSystem_B.swapepd]++;
            guard11 = true;
          }
        } else {
          flightControlSystem_B.last_endless = false;
          if (flightControlSystem_B.slope_error > flightControlSystem_B.y) {
            flightControlSystem_B.y = flightControlSystem_B.slope_error;
            flightControlSystem_B.m = flightControlSystem_B.xi;
            flightControlSystem_B.iter_y = flightControlSystem_B.tmp;
          }

          guard11 = true;
        }

        if (guard11) {
          if ((flightControlSystem_B.xi == 1.0) || (flightControlSystem_B.xi ==
               120.0)) {
            flightControlSystem_B.tmp += (real_T)flightControlSystem_B.x1;
          } else {
            flightControlSystem_B.xi += (real_T)flightControlSystem_B.x1;
          }

          if (flightControlSystem_B.xi < 1.0) {
            flightControlSystem_B.tmp = 159.0;
            flightControlSystem_B.xi = 1.0;
            flightControlSystem_B.x1 = -1;
          } else if (flightControlSystem_B.xi > 120.0) {
            flightControlSystem_B.xi = 120.0;
            flightControlSystem_B.tmp = 2.0;
            flightControlSystem_B.x1 = 1;
          } else if (flightControlSystem_B.tmp < 1.0) {
            flightControlSystem_B.tmp = 1.0;
            flightControlSystem_B.xi = 2.0;
            flightControlSystem_B.x1 = 1;
          } else if (flightControlSystem_B.tmp > 160.0) {
            flightControlSystem_B.tmp = 160.0;
            flightControlSystem_B.xi = 119.0;
            flightControlSystem_B.x1 = -1;
          }
        }
      }

      if (flightControlSystem_B.swapepd + 1 == 1) {
        flightControlSystem_nearest_edge(rt_roundd_snf
          (flightControlSystem_B.mx_endless_x[0] / flightControlSystem_B.mx_t[0]),
          rt_roundd_snf(flightControlSystem_B.mx_endless_y[0] /
                        flightControlSystem_B.mx_t[0]), &flightControlSystem_B.m,
          &flightControlSystem_B.iter_y);
        flightControlSystem_DW.prev_endless_x = ((60.0 - flightControlSystem_B.m)
          + 60.0) + 1.0;
        flightControlSystem_DW.prev_endless_x_not_empty = true;
        flightControlSystem_DW.prev_endless_y = ((80.0 -
          flightControlSystem_B.iter_y) + 80.0) + 1.0;
        flightControlSystem_DW.prev_endless_y_not_empty = true;
      } else if (flightControlSystem_B.swapepd + 1 == 2) {
        if (!flightControlSystem_DW.prev_endless_x_not_empty) {
          flightControlSystem_nearest_edge(rt_roundd_snf
            (flightControlSystem_B.mx_endless_x[0] / flightControlSystem_B.mx_t
             [0]), rt_roundd_snf(flightControlSystem_B.mx_endless_y[0] /
            flightControlSystem_B.mx_t[0]), &flightControlSystem_B.m,
            &flightControlSystem_B.iter_y);
          flightControlSystem_DW.prev_endless_x = ((60.0 -
            flightControlSystem_B.m) + 60.0) + 1.0;
          flightControlSystem_DW.prev_endless_x_not_empty = true;
          flightControlSystem_DW.prev_endless_y = ((80.0 -
            flightControlSystem_B.iter_y) + 80.0) + 1.0;
          flightControlSystem_DW.prev_endless_y_not_empty = true;
        } else {
          flightControlSystem_nearest_edge(rt_roundd_snf
            (flightControlSystem_B.mx_endless_x[0] / flightControlSystem_B.mx_t
             [0]), rt_roundd_snf(flightControlSystem_B.mx_endless_y[0] /
            flightControlSystem_B.mx_t[0]), &flightControlSystem_B.xi,
            &flightControlSystem_B.tmp);
          flightControlSystem_nearest_edge(rt_roundd_snf
            (flightControlSystem_B.mx_endless_x[1] / flightControlSystem_B.mx_t
             [1]), rt_roundd_snf(flightControlSystem_B.mx_endless_y[1] /
            flightControlSystem_B.mx_t[1]), &flightControlSystem_B.m,
            &flightControlSystem_B.iter_y);
          flightControlSystem_B.way_x_n = flightControlSystem_DW.prev_endless_x
            - flightControlSystem_B.xi;
          flightControlSystem_B.way_y_d = flightControlSystem_DW.prev_endless_y
            - flightControlSystem_B.tmp;
          flightControlSystem_B.slope_error =
            flightControlSystem_DW.prev_endless_x - flightControlSystem_B.m;
          flightControlSystem_B.y = flightControlSystem_DW.prev_endless_y -
            flightControlSystem_B.iter_y;
          if (sqrt(flightControlSystem_B.way_x_n * flightControlSystem_B.way_x_n
                   + flightControlSystem_B.way_y_d *
                   flightControlSystem_B.way_y_d) > sqrt
              (flightControlSystem_B.slope_error *
               flightControlSystem_B.slope_error + flightControlSystem_B.y *
               flightControlSystem_B.y)) {
            flightControlSystem_B.m = flightControlSystem_B.xi;
            flightControlSystem_B.iter_y = flightControlSystem_B.tmp;
          }

          flightControlSystem_DW.prev_endless_x = ((60.0 -
            flightControlSystem_B.m) + 60.0) + 1.0;
          flightControlSystem_DW.prev_endless_y = ((80.0 -
            flightControlSystem_B.iter_y) + 80.0) + 1.0;
        }
      }
    } else {
      flightControlSystem_B.xi = 2.0;
      flightControlSystem_B.tmp = 1.0;
      flightControlSystem_B.way_x_n = 100.0;
      flightControlSystem_B.x1 = 1;
      while ((flightControlSystem_B.xi != 1.0) || (flightControlSystem_B.tmp !=
              1.0)) {
        flightControlSystem_B.slope_error = flightControlSystem_line_drawer
          (flightControlSystem_B.xi, flightControlSystem_B.tmp,
           flightControlSystem_B.BW, 1.0);
        if ((flightControlSystem_B.slope_error > 0.0) &&
            (flightControlSystem_B.slope_error < flightControlSystem_B.way_x_n))
        {
          flightControlSystem_B.way_x_n = flightControlSystem_B.slope_error;
          flightControlSystem_B.m = flightControlSystem_B.xi;
          flightControlSystem_B.iter_y = flightControlSystem_B.tmp;
        }

        if ((flightControlSystem_B.xi == 1.0) || (flightControlSystem_B.xi ==
             120.0)) {
          flightControlSystem_B.tmp += (real_T)flightControlSystem_B.x1;
        } else {
          flightControlSystem_B.xi += (real_T)flightControlSystem_B.x1;
        }

        if (flightControlSystem_B.tmp < 1.0) {
          flightControlSystem_B.tmp = 1.0;
          flightControlSystem_B.xi = 2.0;
          flightControlSystem_B.x1 = 1;
        } else if (flightControlSystem_B.tmp > 160.0) {
          flightControlSystem_B.tmp = 160.0;
          flightControlSystem_B.xi = 119.0;
          flightControlSystem_B.x1 = -1;
        }
      }
    }
  }

  /* Switch: '<S2>/switch_way' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function2'
   */
  if (flightControlSystem_B.W > flightControlSystem_P.switch_way_Threshold) {
    flightControlSystem_B.delta = flightControlSystem_B.m;
    flightControlSystem_B.way_y = flightControlSystem_B.iter_y;
  }

  /* End of Switch: '<S2>/switch_way' */

  /* MATLAB Function: '<S2>/write_or_not' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   *  MATLAB Function: '<S2>/Main control'
   *  Switch: '<S2>/switch_way'
   */
  flightControlSystem_DW.sfEvent = flightControlSystem_CALL_EVENT_ax;
  if (flightControlSystem_B.BW[9539]) {
    flightControlSystem_B.xi = flightControlSystem_B.delta;
    flightControlSystem_B.iter_y = flightControlSystem_B.way_y;
  } else {
    flightControlSystem_B.xi = flightControlSystem_DW.xy[0];
    flightControlSystem_B.iter_y = flightControlSystem_DW.xy[1];
  }

  /* DataStoreWrite: '<S2>/Data Store Write' */
  flightControlSystem_DW.xy[0] = flightControlSystem_B.xi;
  flightControlSystem_DW.xy[1] = flightControlSystem_B.iter_y;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  flightControlSystem_DW.sfEvent_l = flightControlSystem_CALL_EVENT_ax;
  flightControlSystem_B.offset_x = 0.0;
  flightControlSystem_B.xi = 0.0;
  flightControlSystem_B.W = 0;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_emxInit_real_T(&centers, 2);

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLAB Function: '<S2>/MATLAB Function' */
  centers->size[0] = 0;
  centers->size[1] = 0;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_emxInit_real_T(&metric, 2);

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLAB Function: '<S2>/MATLAB Function' */
  metric->size[0] = 0;
  metric->size[1] = 0;
  flightControlSystem_chaccum(flightControlSystem_B.BW,
    flightControlSystem_B.accumMatrix, flightControlSystem_B.gradientImg);
  flightControlSystem_B.last_endless = false;
  flightControlSystem_B.x1 = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.x1 < 19200)) {
    if (((flightControlSystem_B.accumMatrix[flightControlSystem_B.x1].re == 0.0)
         && (flightControlSystem_B.accumMatrix[flightControlSystem_B.x1].im ==
             0.0)) || (rtIsNaN
                       (flightControlSystem_B.accumMatrix[flightControlSystem_B.x1]
                        .re) || rtIsNaN
                       (flightControlSystem_B.accumMatrix[flightControlSystem_B.x1]
                        .im))) {
      flightControlSystem_B.x1++;
    } else {
      flightControlSystem_B.last_endless = true;
      exitg1 = true;
    }
  }

  if (flightControlSystem_B.last_endless) {
    flightControlSystem_chcenters(flightControlSystem_B.accumMatrix, centers,
      metric);
    if ((centers->size[0] != 0) && (centers->size[1] != 0)) {
      flightControlSystem_emxInit_boolean_T(&x, 2);
      flightControlSystem_B.xk = x->size[0] * x->size[1];
      x->size[0] = metric->size[0];
      flightControlSystem_B.x1 = metric->size[1];
      x->size[1] = metric->size[1];
      flightControlSystem_emxEnsureCapacity_boolean_T(x,
        flightControlSystem_B.xk);
      flightControlSystem_B.yk = metric->size[0] * metric->size[1];
      for (flightControlSystem_B.xk = 0; flightControlSystem_B.xk <
           flightControlSystem_B.yk; flightControlSystem_B.xk++) {
        x->data[flightControlSystem_B.xk] = (metric->
          data[flightControlSystem_B.xk] >= 0.099999999999999978);
      }

      flightControlSystem_B.swapepd = 0;
      flightControlSystem_emxInit_int32_T(&ii, 1);
      flightControlSystem_B.xk = ii->size[0];
      ii->size[0] = flightControlSystem_B.yk;
      flightControlSystem_emxEnsureCapacity_int32_T(ii, flightControlSystem_B.xk);
      flightControlSystem_B.xk = 0;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.xk <= flightControlSystem_B.yk
                           - 1)) {
        if (x->data[flightControlSystem_B.xk]) {
          flightControlSystem_B.swapepd++;
          ii->data[flightControlSystem_B.swapepd - 1] = flightControlSystem_B.xk
            + 1;
          if (flightControlSystem_B.swapepd >= flightControlSystem_B.yk) {
            exitg1 = true;
          } else {
            flightControlSystem_B.xk++;
          }
        } else {
          flightControlSystem_B.xk++;
        }
      }

      flightControlSystem_emxFree_boolean_T(&x);
      if (flightControlSystem_B.yk == 1) {
        if (flightControlSystem_B.swapepd == 0) {
          ii->size[0] = 0;
        }
      } else if (flightControlSystem_B.swapepd < 1) {
        ii->size[0] = 0;
      } else {
        flightControlSystem_B.xk = ii->size[0];
        ii->size[0] = flightControlSystem_B.swapepd;
        flightControlSystem_emxEnsureCapacity_int32_T(ii,
          flightControlSystem_B.xk);
      }

      flightControlSystem_emxInit_uint32_T(&idx2Keep, 1);
      flightControlSystem_B.swapepd = ii->size[0];
      flightControlSystem_B.xk = idx2Keep->size[0];
      idx2Keep->size[0] = ii->size[0];
      flightControlSystem_emxEnsureCapacity_uint32_T(idx2Keep,
        flightControlSystem_B.xk);
      for (flightControlSystem_B.xk = 0; flightControlSystem_B.xk <
           flightControlSystem_B.swapepd; flightControlSystem_B.xk++) {
        idx2Keep->data[flightControlSystem_B.xk] = (uint32_T)ii->
          data[flightControlSystem_B.xk];
      }

      flightControlSystem_B.b_y1 = centers->size[1];
      flightControlSystem_emxInit_real_T(&centers_0, 2);
      flightControlSystem_B.xk = centers_0->size[0] * centers_0->size[1];
      centers_0->size[0] = ii->size[0];
      centers_0->size[1] = centers->size[1];
      flightControlSystem_emxEnsureCapacity_real_T(centers_0,
        flightControlSystem_B.xk);
      for (flightControlSystem_B.xk = 0; flightControlSystem_B.xk <
           flightControlSystem_B.b_y1; flightControlSystem_B.xk++) {
        for (flightControlSystem_B.yk = 0; flightControlSystem_B.yk <
             flightControlSystem_B.swapepd; flightControlSystem_B.yk++) {
          centers_0->data[flightControlSystem_B.yk + centers_0->size[0] *
            flightControlSystem_B.xk] = centers->data[(centers->size[0] *
            flightControlSystem_B.xk + (int32_T)idx2Keep->
            data[flightControlSystem_B.yk]) - 1];
        }
      }

      flightControlSystem_B.xk = centers->size[0] * centers->size[1];
      centers->size[0] = ii->size[0];
      centers->size[1] = flightControlSystem_B.b_y1;
      flightControlSystem_emxEnsureCapacity_real_T(centers,
        flightControlSystem_B.xk);
      flightControlSystem_B.yk = centers_0->size[0] * centers_0->size[1];
      if (flightControlSystem_B.yk - 1 >= 0) {
        memcpy(&centers->data[0], &centers_0->data[0], (uint32_T)
               flightControlSystem_B.yk * sizeof(real_T));
      }

      flightControlSystem_emxFree_real_T(&centers_0);
      flightControlSystem_emxInit_real_T(&metric_0, 2);
      flightControlSystem_B.xk = metric_0->size[0] * metric_0->size[1];
      metric_0->size[0] = ii->size[0];
      metric_0->size[1] = metric->size[1];
      flightControlSystem_emxEnsureCapacity_real_T(metric_0,
        flightControlSystem_B.xk);
      for (flightControlSystem_B.xk = 0; flightControlSystem_B.xk <
           flightControlSystem_B.x1; flightControlSystem_B.xk++) {
        for (flightControlSystem_B.yk = 0; flightControlSystem_B.yk <
             flightControlSystem_B.swapepd; flightControlSystem_B.yk++) {
          metric_0->data[flightControlSystem_B.yk] = metric->data[(int32_T)
            idx2Keep->data[flightControlSystem_B.yk] - 1];
        }
      }

      flightControlSystem_B.xk = metric->size[0] * metric->size[1];
      metric->size[0] = ii->size[0];
      flightControlSystem_emxFree_int32_T(&ii);
      metric->size[1] = flightControlSystem_B.x1;
      flightControlSystem_emxEnsureCapacity_real_T(metric,
        flightControlSystem_B.xk);
      flightControlSystem_B.yk = metric_0->size[0] * metric_0->size[1];
      if (flightControlSystem_B.yk - 1 >= 0) {
        memcpy(&metric->data[0], &metric_0->data[0], (uint32_T)
               flightControlSystem_B.yk * sizeof(real_T));
      }

      flightControlSystem_emxFree_real_T(&metric_0);
      if (idx2Keep->size[0] == 0) {
        centers->size[0] = 0;
        centers->size[1] = 0;
        metric->size[0] = 0;
        metric->size[1] = 0;
      }

      flightControlSystem_emxFree_uint32_T(&idx2Keep);
    }
  }

  if ((centers->size[0] != 0) && (centers->size[1] != 0)) {
    flightControlSystem_B.xk = metric->size[0];
    flightControlSystem_B.swapepd = metric->size[1];
    if (metric->size[1] - 1 >= 0) {
      flightControlSystem_B.iindx_data = 1;
    }

    if (metric->size[1] >= 1) {
      flightControlSystem_B.yk = 0;
      flightControlSystem_B.ex_data = metric->data[0];
      for (flightControlSystem_B.x1 = 2; flightControlSystem_B.x1 <=
           flightControlSystem_B.xk; flightControlSystem_B.x1++) {
        flightControlSystem_B.tmp = flightControlSystem_B.ex_data;
        flightControlSystem_B.way_x_n = metric->data[flightControlSystem_B.x1 -
          1];
        if ((!rtIsNaN(flightControlSystem_B.way_x_n)) && (rtIsNaN
             (flightControlSystem_B.tmp) || (flightControlSystem_B.tmp <
              flightControlSystem_B.way_x_n))) {
          flightControlSystem_B.ex_data = flightControlSystem_B.way_x_n;
          flightControlSystem_B.iindx_data = flightControlSystem_B.x1;
        }
      }
    }

    if (metric->size[1] - 1 >= 0) {
      flightControlSystem_B.x1 = 0;
      flightControlSystem_B.strongest_idx_data = (uint32_T)
        flightControlSystem_B.iindx_data;
      flightControlSystem_B.b_x_data = (flightControlSystem_B.ex_data > 0.3);
    }

    flightControlSystem_B.last_endless = (metric->size[1] != 0);
    if (flightControlSystem_B.last_endless) {
      flightControlSystem_B.x1 = 0;
      exitg1 = false;
      while ((!exitg1) && (flightControlSystem_B.x1 <=
                           flightControlSystem_B.swapepd - 1)) {
        if (!flightControlSystem_B.b_x_data) {
          flightControlSystem_B.last_endless = false;
          exitg1 = true;
        } else {
          flightControlSystem_B.x1 = 1;
        }
      }
    }

    if (flightControlSystem_B.last_endless) {
      flightControlSystem_B.W = (int32_T)
        flightControlSystem_B.strongest_idx_data - 1;
      flightControlSystem_B.offset_x = 80.0 - centers->
        data[flightControlSystem_B.W];
      flightControlSystem_B.xi = centers->data[(int32_T)(1U / (uint32_T)
        metric->size[1]) * centers->size[0] + flightControlSystem_B.W] - 60.0;
      flightControlSystem_B.W = 1;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_emxFree_real_T(&metric);
  flightControlSystem_emxFree_real_T(&centers);

  /* MATLAB Function: '<S2>/speed_calculator' */
  flightControlSystem_DW.sfEvent_i = flightControlSystem_CALL_EVENT_ax;

  /* MATLAB Function: '<S2>/center_vector_x' */
  flightControlSystem_DW.sfEvent_a = flightControlSystem_CALL_EVENT_ax;
  flightControlSystem_B.swapepd = 0;
  flightControlSystem_B.xk = -160;
  flightControlSystem_B.x1 = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.x1 < 21)) {
    if (flightControlSystem_B.BW[(79 - flightControlSystem_B.x1) * 120 + 59] ==
        flightControlSystem_B.compare_tmp) {
      flightControlSystem_B.swapepd = 80 - flightControlSystem_B.x1;
      exitg1 = true;
    } else {
      flightControlSystem_B.x1++;
    }
  }

  flightControlSystem_B.x1 = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.x1 < 21)) {
    if (flightControlSystem_B.BW[(flightControlSystem_B.x1 + 79) * 120 + 59] ==
        flightControlSystem_B.compare_tmp) {
      flightControlSystem_B.xk = flightControlSystem_B.x1 - 80;
      exitg1 = true;
    } else {
      flightControlSystem_B.x1++;
    }
  }

  flightControlSystem_B.tmp = 0.0;
  if ((flightControlSystem_B.swapepd != 0) && (flightControlSystem_B.xk + 160 !=
       0) && flightControlSystem_B.BW[9539]) {
    flightControlSystem_B.x1 = flightControlSystem_B.xk +
      flightControlSystem_B.swapepd;
    if (flightControlSystem_B.x1 > 0) {
      if (flightControlSystem_B.x1 < 5) {
        flightControlSystem_B.iter_y = 2.0E-6;
      } else if (flightControlSystem_B.x1 < 10) {
        flightControlSystem_B.iter_y = 3.0E-6;
      } else if (flightControlSystem_B.x1 < 15) {
        flightControlSystem_B.iter_y = 4.0E-6;
      } else if (flightControlSystem_B.x1 < 20) {
        flightControlSystem_B.iter_y = 5.0E-6;
      } else {
        flightControlSystem_B.iter_y = 6.0E-6;
      }
    } else if (flightControlSystem_B.x1 < -20) {
      flightControlSystem_B.iter_y = -6.0E-6;
    } else if (flightControlSystem_B.x1 < -15) {
      flightControlSystem_B.iter_y = -5.0E-6;
    } else if (flightControlSystem_B.x1 < -10) {
      flightControlSystem_B.iter_y = -4.0E-6;
    } else if (flightControlSystem_B.x1 < -5) {
      flightControlSystem_B.iter_y = -3.0E-6;
    } else if (flightControlSystem_B.x1 < -1) {
      flightControlSystem_B.iter_y = -2.0E-6;
    } else {
      flightControlSystem_B.iter_y = -1.0E-6;
    }

    flightControlSystem_B.tmp = flightControlSystem_B.iter_y * 20.0;
  }

  /* MATLAB Function: '<S2>/center_vector_y' */
  flightControlSystem_DW.sfEvent_m = flightControlSystem_CALL_EVENT_ax;
  flightControlSystem_B.swapepd = 0;
  flightControlSystem_B.xk = 0;
  flightControlSystem_B.x1 = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.x1 < 21)) {
    if (flightControlSystem_B.BW[9539 - flightControlSystem_B.x1] ==
        flightControlSystem_B.compare_tmp) {
      flightControlSystem_B.swapepd = 60 - flightControlSystem_B.x1;
      exitg1 = true;
    } else {
      flightControlSystem_B.x1++;
    }
  }

  flightControlSystem_B.x1 = 0;
  exitg1 = false;
  while ((!exitg1) && (flightControlSystem_B.x1 < 21)) {
    if (flightControlSystem_B.BW[flightControlSystem_B.x1 + 9539] ==
        flightControlSystem_B.compare_tmp) {
      flightControlSystem_B.xk = flightControlSystem_B.x1 + 60;
      exitg1 = true;
    } else {
      flightControlSystem_B.x1++;
    }
  }

  flightControlSystem_B.way_x_n = 0.0;
  if ((flightControlSystem_B.swapepd != 0) && (flightControlSystem_B.xk != 0) &&
      flightControlSystem_B.BW[9539]) {
    flightControlSystem_B.x1 = 120 - (flightControlSystem_B.swapepd +
      flightControlSystem_B.xk);
    if (flightControlSystem_B.x1 > 0) {
      if (flightControlSystem_B.x1 <= 1) {
        flightControlSystem_B.iter_y = 1.0E-6;
      } else if (flightControlSystem_B.x1 < 5) {
        flightControlSystem_B.iter_y = 2.0E-6;
      } else if (flightControlSystem_B.x1 < 10) {
        flightControlSystem_B.iter_y = 3.0E-6;
      } else {
        flightControlSystem_B.iter_y = 5.0E-6;
      }
    } else if (flightControlSystem_B.x1 < -15) {
      flightControlSystem_B.iter_y = -5.0E-6;
    } else if (flightControlSystem_B.x1 < -10) {
      flightControlSystem_B.iter_y = -4.0E-6;
    } else if (flightControlSystem_B.x1 <= -5) {
      flightControlSystem_B.iter_y = -3.0E-6;
    } else if (flightControlSystem_B.x1 < -1) {
      flightControlSystem_B.iter_y = -2.0E-6;
    } else {
      flightControlSystem_B.iter_y = -1.0E-6;
    }

    flightControlSystem_B.way_x_n = flightControlSystem_B.iter_y * 20.0;
  }

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  MATLAB Function: '<S2>/speed_calculator'
   *  MATLAB Function: '<S2>/write_or_not'
   *  Sum: '<S2>/Add_x'
   *  Sum: '<S2>/Add_y'
   */
  flightControlSystem_DW.RateTransition_Buffer
    [(flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 5] = (60.0 -
    flightControlSystem_B.delta) + flightControlSystem_B.tmp;
  flightControlSystem_DW.RateTransition_Buffer[1 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 5] =
    (flightControlSystem_B.way_y - 80.0) + flightControlSystem_B.way_x_n;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_DW.RateTransition_Buffer[2 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 5] =
    flightControlSystem_B.offset_x;
  flightControlSystem_DW.RateTransition_Buffer[3 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 5] =
    flightControlSystem_B.xi;
  flightControlSystem_DW.RateTransition_Buffer[4 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 5] =
    flightControlSystem_B.W;
  flightControlSystem_DW.RateTransition_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0);
  rtExtModeUpload(1, (real_T)(((flightControlSystem_M->Timing.clockTick1+
    flightControlSystem_M->Timing.clockTickH1* 4294967296.0)) * 0.2));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  flightControlSystem_M->Timing.clockTick1++;
  if (!flightControlSystem_M->Timing.clockTick1) {
    flightControlSystem_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  flightControlSystem_P.ControlSystem.SaturationSonar_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  rtmSetTFinal(flightControlSystem_M, 100.0);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightControlSystem_Y.Actuators[0],
        &flightControlSystem_Y.Flag
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_UINT8
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "motors",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators",
        "flightControlSystem/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* External mode info */
  flightControlSystem_M->Sizes.checksums[0] = (2527937286U);
  flightControlSystem_M->Sizes.checksums[1] = (2026100765U);
  flightControlSystem_M->Sizes.checksums[2] = (1997352618U);
  flightControlSystem_M->Sizes.checksums[3] = (1500484846U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[45];
    flightControlSystem_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Noopticalflow.Geofencingerror_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Normalcondition.Geofencingerror_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Geofencingerror_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_m;
    systemRan[18] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_c;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.MeasurementUpdate_n.MeasurementUpdate_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.MeasurementUpdate_j.MeasurementUpdate_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.TriggeredSubsystem_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(flightControlSystem_M->extModeInfo,
      &flightControlSystem_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(flightControlSystem_M->extModeInfo,
                        flightControlSystem_M->Sizes.checksums);
    rteiSetTPtr(flightControlSystem_M->extModeInfo, rtmGetTPtr
                (flightControlSystem_M));
  }

  /* block I/O */
  (void) memset(((void *) &flightControlSystem_B), 0,
                sizeof(B_flightControlSystem_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void)memset(&flightControlSystem_Y, 0, sizeof(ExtY_flightControlSystem_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    flightControlSystem_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 46;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* SetupRuntimeResources for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_SetupRTR(flightControlSystem_M,
    &flightControlSystem_DW.ControlSystem);

  /* End of SetupRuntimeResources for SubSystem: '<Root>/Control System' */

  /* Start for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Start(&flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem, &flightControlSystem_P.ControlSystem);

  /* End of Start for SubSystem: '<Root>/Control System' */

  /* Start for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
  flightControlSystem_DW.objisempty = true;
  flightControlSystem_DW.obj.isInitialized = 1;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
  flightControlSystem_DW.xy[0] =
    flightControlSystem_P.DataStoreMemory_InitialValue[0];
  flightControlSystem_DW.xy[1] =
    flightControlSystem_P.DataStoreMemory_InitialValue[1];

  /* End of Start for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_PrevZCX.ControlSystem.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    for (i = 0; i < 5; i++) {
      flightControlSystem_DW.RateTransition_Buffer[i] =
        flightControlSystem_P.RateTransition_InitialCondition;
    }

    /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
    flightControlSystem_ControlSystem_Init(&flightControlSystem_B.ControlSystem,
      &flightControlSystem_DW.ControlSystem,
      &flightControlSystem_P.ControlSystem);

    /* End of SystemInitialize for SubSystem: '<Root>/Control System' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function' */
    flightControlSystem_DW.doneDoubleBufferReInit_bw = false;
    flightControlSystem_DW.sfEvent_l = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function2' */
    flightControlSystem_DW.prev_endless_x_not_empty = false;
    flightControlSystem_DW.prev_endless_y_not_empty = false;
    flightControlSystem_DW.doneDoubleBufferReInit_g = false;
    flightControlSystem_DW.sfEvent_p = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function4' */
    flightControlSystem_DW.doneDoubleBufferReInit_b = false;
    flightControlSystem_DW.sfEvent_b = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/Main control' */
    flightControlSystem_DW.doneDoubleBufferReInit_dl = false;
    flightControlSystem_DW.sfEvent_g = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/center_vector_x' */
    flightControlSystem_DW.doneDoubleBufferReInit_ey = false;
    flightControlSystem_DW.sfEvent_a = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/center_vector_y' */
    flightControlSystem_DW.doneDoubleBufferReInit_e = false;
    flightControlSystem_DW.sfEvent_m = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S525>/MATLAB Function' */
    flightControlSystem_DW.doneDoubleBufferReInit_d = false;
    flightControlSystem_DW.sfEvent_f = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/opposite_way' */
    flightControlSystem_DW.doneDoubleBufferReInit_f = false;
    flightControlSystem_DW.sfEvent_d = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/speed_calculator' */
    flightControlSystem_DW.doneDoubleBufferReInit_c = false;
    flightControlSystem_DW.sfEvent_i = flightControlSystem_CALL_EVENT_ax;

    /* SystemInitialize for MATLAB Function: '<S2>/write_or_not' */
    flightControlSystem_DW.doneDoubleBufferReInit = false;
    flightControlSystem_DW.sfEvent = flightControlSystem_CALL_EVENT_ax;

    /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
  }
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
