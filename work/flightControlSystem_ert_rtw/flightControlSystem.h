/*
 * flightControlSystem.h
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

#ifndef flightControlSystem_h_
#define flightControlSystem_h_
#ifndef flightControlSystem_COMMON_INCLUDES_
#define flightControlSystem_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rsedu_image.h"
#endif                                /* flightControlSystem_COMMON_INCLUDES_ */

#include "flightControlSystem_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S4>/Geofencing error' */
typedef struct {
  int8_T Geofencingerror_SubsysRanBC;  /* '<S4>/Geofencing error' */
} DW_Geofencingerror_flightControlSystem_T;

/* Block states (default storage) for system '<S370>/SqrtUsedFcn' */
typedef struct {
  int32_T sfEvent;                     /* '<S370>/SqrtUsedFcn' */
  boolean_T doneDoubleBufferReInit;    /* '<S370>/SqrtUsedFcn' */
} DW_SqrtUsedFcn_flightControlSystem_T;

/* Block signals for system '<S341>/MeasurementUpdate' */
typedef struct {
  real32_T Product3[2];                /* '<S372>/Product3' */
} B_MeasurementUpdate_flightControlSystem_T;

/* Block states (default storage) for system '<S341>/MeasurementUpdate' */
typedef struct {
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S341>/MeasurementUpdate' */
  boolean_T MeasurementUpdate_MODE;    /* '<S341>/MeasurementUpdate' */
} DW_MeasurementUpdate_flightControlSystem_T;

/* Block signals for system '<S348>/Enabled Subsystem' */
typedef struct {
  real32_T Product2[2];                /* '<S374>/Product2' */
} B_EnabledSubsystem_flightControlSystem_T;

/* Block states (default storage) for system '<S348>/Enabled Subsystem' */
typedef struct {
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S348>/Enabled Subsystem' */
  boolean_T EnabledSubsystem_MODE;     /* '<S348>/Enabled Subsystem' */
} DW_EnabledSubsystem_flightControlSystem_T;

/* Block signals for system '<Root>/Control System' */
typedef struct {
  real32_T VectorConcatenate[9];       /* '<S518>/Vector Concatenate' */
  real32_T DataTypeConversion_m[8];    /* '<S253>/Data Type Conversion' */
  real_T rtb_VectorConcatenate_c[3];
  real32_T Sum1_p[6];                  /* '<S253>/Sum1' */
  real32_T Reshapexhat[4];             /* '<S441>/Reshapexhat' */
  real32_T Conversion_a[4];            /* '<S367>/Conversion' */
  real32_T fv[4];
  real32_T FIR_IMUaccel[3];            /* '<S253>/FIR_IMUaccel' */
  real32_T u_l[3];                     /* '<S442>/ ' */
  real_T invertzaxisGain;              /* '<S251>/invertzaxisGain' */
  real_T speed;                        /* '<S5>/speed' */
  real_T Sum[3];                       /* '<S251>/Sum' */
  real_T Product2[2];                  /* '<S309>/Product2' */
  real_T Product3[2];                  /* '<S307>/Product3' */
  real_T z;                            /* '<S5>/Chart' */
  real_T x;                            /* '<S5>/Chart' */
  real_T y;                            /* '<S5>/Chart' */
  real_T sonarFilter_IIR_tmp;
  real_T Sum_k;                        /* '<S307>/Sum' */
  real_T rtb_Add_a_idx_1;
  real_T unnamed_idx_1;
  real32_T SimplyIntegrateVelocity[2]; /* '<S437>/SimplyIntegrateVelocity' */
  real32_T Conversion_g[2];            /* '<S365>/Conversion' */
  real32_T DataTypeConversion_o[2];    /* '<S439>/Data Type Conversion' */
  real32_T Saturation_n[2];            /* '<S114>/Saturation' */
  real32_T fv1[2];
  real32_T DataTypeConversion;         /* '<S251>/Data Type Conversion' */
  real32_T inverseIMU_gain[6];         /* '<S253>/inverseIMU_gain' */
  real32_T TrigonometricFunction1;     /* '<S317>/Trigonometric Function1' */
  real32_T TrigonometricFunction;      /* '<S318>/Trigonometric Function' */
  real32_T DataTypeConversion3[3];     /* '<S252>/Data Type Conversion3' */
  real32_T p;                          /* '<S253>/LPF Fcutoff = 40Hz1' */
  real32_T q;                          /* '<S253>/LPF Fcutoff = 40Hz' */
  real32_T Subtract[3];                /* '<S252>/Subtract' */
  real32_T angularvelocitycompensation[2];
                                    /* '<S436>/angular velocity compensation' */
  real32_T DataTypeConversion2;        /* '<S251>/Data Type Conversion2' */
  real32_T TmpSignalConversionAtToWorkspaceInport1[12];/* '<S1>/State Estimator' */
  real32_T Product[2];                 /* '<S438>/Product' */
  real32_T Product2_k[4];              /* '<S512>/Product2' */
  real32_T Product3_a[4];              /* '<S510>/Product3' */
  real32_T In1;                        /* '<S433>/In1' */
  real32_T numAccum;
  real32_T DiscreteTimeIntegrator_k5;  /* '<S319>/Discrete-Time Integrator' */
  real32_T Abs2;                       /* '<S4>/Abs2' */
  real32_T Abs1;                       /* '<S4>/Abs1' */
  real32_T Gain_m;                     /* '<S442>/Gain' */
  real32_T Subtract_c;                 /* '<S429>/Subtract' */
  real32_T I_yaw;                      /* '<S11>/I_yaw' */
  real32_T Abs3;                       /* '<S4>/Abs3' */
  real32_T Abs4;                       /* '<S4>/Abs4' */
  real32_T Abs5;                       /* '<S4>/Abs5' */
  real32_T LPFFcutoff40Hz_tmp;
  real32_T IIR_IMUgyro_r_tmp;
  real32_T rtb_sincos_o2_j_idx_0;
  real32_T rtb_sincos_o2_j_idx_1;
  real32_T rtb_sincos_o2_j_idx_2;
  real32_T rtb_sincos_o2_idx_0;
  real32_T rtb_sincos_o2_idx_1;
  int32_T j;
  int32_T memOffset;
  int32_T i;
  int16_T LogicalOperator;             /* '<S252>/Logical Operator' */
  boolean_T Compare;                   /* '<S258>/Compare' */
  boolean_T nicemeasurementornewupdateneeded;
                                /* '<S256>/nicemeasurementor newupdateneeded' */
  boolean_T LogicalOperator3;          /* '<S440>/Logical Operator3' */
  B_EnabledSubsystem_flightControlSystem_T EnabledSubsystem_n;/* '<S402>/Enabled Subsystem' */
  B_MeasurementUpdate_flightControlSystem_T MeasurementUpdate_j;/* '<S395>/MeasurementUpdate' */
  B_EnabledSubsystem_flightControlSystem_T EnabledSubsystem_d;/* '<S348>/Enabled Subsystem' */
  B_MeasurementUpdate_flightControlSystem_T MeasurementUpdate_n;/* '<S341>/MeasurementUpdate' */
} B_ControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Control System' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<S251>/Delay2' */
  real_T MemoryX_DSTATE[2];            /* '<S255>/MemoryX' */
  real_T sonarFilter_IIR_states[3];    /* '<S256>/sonarFilter_IIR' */
  real_T DelayOneStep_DSTATE;          /* '<S4>/Delay One Step' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S437>/SimplyIntegrateVelocity' */
  real32_T pressureFilter_IIR_states[3];/* '<S256>/pressureFilter_IIR' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S319>/Discrete-Time Integrator' */
  real32_T FIR_IMUaccel_states[15];    /* '<S253>/FIR_IMUaccel' */
  real32_T MemoryX_DSTATE_g[2];        /* '<S321>/MemoryX' */
  real32_T MemoryX_DSTATE_m[2];        /* '<S375>/MemoryX' */
  real32_T LPFFcutoff40Hz1_states;     /* '<S253>/LPF Fcutoff = 40Hz1' */
  real32_T LPFFcutoff40Hz_states;      /* '<S253>/LPF Fcutoff = 40Hz' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S253>/IIR_IMUgyro_r' */
  real32_T MemoryX_DSTATE_l[4];        /* '<S441>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S440>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S448>/UD' */
  real32_T Delay_DSTATE[2];            /* '<S436>/Delay' */
  real32_T Delay1_DSTATE[2];           /* '<S6>/Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S7>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE[2];       /* '<S216>/Integrator' */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[2];
  /* '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  real32_T Integrator_DSTATE_d[2];     /* '<S107>/Integrator' */
  real32_T Filter_DSTATE[2];           /* '<S102>/Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S11>/Discrete-Time Integrator' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S253>/FIR_IMUaccel' */
  uint32_T Output_DSTATE;              /* '<S514>/Output' */
  uint32_T Output_DSTATE_i;            /* '<S432>/Output' */
  uint32_T Output_DSTATE_g;            /* '<S242>/Output' */
  real32_T FIR_IMUaccel_simContextBuf[30];/* '<S253>/FIR_IMUaccel' */
  real32_T FIR_IMUaccel_simRevCoeff[6];/* '<S253>/FIR_IMUaccel' */
  real32_T IIRgyroz_tmp[2];            /* '<S440>/IIRgyroz' */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[2];
  /* '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  int32_T sfEvent;                     /* '<S508>/SqrtUsedFcn' */
  int32_T sfEvent_n;                   /* '<S305>/SqrtUsedFcn' */
  int32_T sfEvent_j;                   /* '<S5>/Chart' */
  int32_T sfEvent_p;
               /* '<S10>/Position error transformation (Earth to Body frame)' */
  uint32_T is_c3_flightControlSystem;  /* '<S5>/Chart' */
  uint16_T Output_DSTATE_a;            /* '<S14>/Output' */
  uint16_T temporalCounter_i1;         /* '<S5>/Chart' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S437>/SimplyIntegrateVelocity' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S7>/Discrete-Time Integrator' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S486>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S479>/MeasurementUpdate' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S429>/Triggered Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC_c;/* '<S283>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC_m;/* '<S277>/MeasurementUpdate' */
  uint8_T is_active_c3_flightControlSystem;/* '<S5>/Chart' */
  boolean_T icLoad;                    /* '<S255>/MemoryX' */
  boolean_T icLoad_p;                  /* '<S321>/MemoryX' */
  boolean_T icLoad_k;                  /* '<S375>/MemoryX' */
  boolean_T icLoad_o;                  /* '<S441>/MemoryX' */
  boolean_T doneDoubleBufferReInit;    /* '<S508>/SqrtUsedFcn' */
  boolean_T doneDoubleBufferReInit_i;  /* '<S305>/SqrtUsedFcn' */
  boolean_T doneDoubleBufferReInit_j;
               /* '<S10>/Position error transformation (Earth to Body frame)' */
  boolean_T EnabledSubsystem_MODE;     /* '<S486>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S479>/MeasurementUpdate' */
  boolean_T EnabledSubsystem_MODE_l;   /* '<S283>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE_c;  /* '<S277>/MeasurementUpdate' */
  DW_EnabledSubsystem_flightControlSystem_T EnabledSubsystem_n;/* '<S402>/Enabled Subsystem' */
  DW_MeasurementUpdate_flightControlSystem_T MeasurementUpdate_j;/* '<S395>/MeasurementUpdate' */
  DW_SqrtUsedFcn_flightControlSystem_T sf_SqrtUsedFcn_e;/* '<S424>/SqrtUsedFcn' */
  DW_EnabledSubsystem_flightControlSystem_T EnabledSubsystem_d;/* '<S348>/Enabled Subsystem' */
  DW_MeasurementUpdate_flightControlSystem_T MeasurementUpdate_n;/* '<S341>/MeasurementUpdate' */
  DW_SqrtUsedFcn_flightControlSystem_T sf_SqrtUsedFcn_h;/* '<S370>/SqrtUsedFcn' */
  DW_Geofencingerror_flightControlSystem_T Normalcondition;/* '<S4>/Normal condition' */
  DW_Geofencingerror_flightControlSystem_T Ultrasoundimproper;/* '<S4>/Ultrasound improper' */
  DW_Geofencingerror_flightControlSystem_T Noopticalflow;/* '<S4>/No optical flow ' */
  DW_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S4>/estimator//Optical flow error' */
  DW_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S4>/Geofencing error' */
} DW_ControlSystem_flightControlSystem_T;

/* Zero-crossing (trigger) state for system '<Root>/Control System' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S429>/Triggered Subsystem' */
} ZCE_ControlSystem_flightControlSystem_T;

/* Block signals (default storage) */
typedef struct {
  real_T Xin[57600];
  creal_T accumMatrix[19200];
  creal_T out[19200];
  creal_T accumMatrix_tmp[19200];
  real_T a[20336];
  real_T inImg[20336];
  real_T aTmp[19764];
  real_T aTmp_m[19764];
  int32_T locationStack[38400];
  real_T bTmp[19200];
  real_T dv[19200];
  real_T dv1[19200];
  real_T accumMatrixRe[19200];
  real_T Hd[19200];
  real_T Hd_c[19200];
  real32_T aTmp_k[20336];
  real32_T aTmp_c[19764];
  real32_T aTmp_b[19764];
  real32_T gradientImg[19200];
  real32_T Gy[19200];
  real32_T b_I[19200];
  real32_T varargin_1[19200];
  uint8_T u[57600];
  boolean_T rows_to_keep_data[19200];
  boolean_T bw[19200];
  boolean_T bwpre[19200];
  real_T b_xwork[256];
  int32_T b_iwork[256];
  creal_T Opca[31];
  s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T a_p;
  real_T inImg_c[25];
  boolean_T out_[120];
  real_T J_data[9];
  int32_T c[18];
  int32_T imnhSubs[18];
  int32_T a_f[18];
  int32_T d[18];
  int32_T imnhSubs_g[18];
  real_T RateTransition[5];            /* '<Root>/Rate Transition' */
  int32_T b[9];
  int32_T imnhInds[9];
  int32_T b_imnhInds_data[9];
  int32_T c_g[9];
  int32_T imnhInds_[9];
  real_T x4[4];
  int32_T idx4[4];
  int32_T perm[4];
  real_T mx_endless_x[2];
  real_T mx_endless_y[2];
  real_T mx_t[2];
  real_T wc[2];
  sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T s;
  boolean_T isInside[9];
  int8_T tmp_data[9];
  int8_T tmp_data_m[9];
  int8_T tmp_data_n[9];
  int8_T tmp_data_p[9];
  boolean_T bv[9];
  boolean_T isInside_l[9];
  int8_T tmp_data_j[9];
  int8_T b_tmp_data[9];
  int8_T tmp_data_d[9];
  real_T offset_x;                     /* '<S2>/MATLAB Function' */
  uint8_T R[19200];                    /* '<S2>/PARROT Image Conversion' */
  uint8_T G[19200];                    /* '<S2>/PARROT Image Conversion' */
  uint8_T B[19200];                    /* '<S2>/PARROT Image Conversion' */
  boolean_T BW[19200];                 /* '<S525>/MATLAB Function' */
  real_T delta;
  real_T tmp;
  real_T way_y;
  real_T iter_y;
  real_T m;
  real_T slope_error;
  real_T y;
  real_T range;
  real_T xi;
  real_T ex_data;
  real_T way_x_n;
  real_T way_y_d;
  real_T accumMatrixRe_d;
  real_T d_l;
  real_T d1;
  real_T br;
  real_T Opca_re;
  real_T Opca_im;
  real_T bij;
  real_T CC_NumObjects;
  real_T sumIntensity;
  real_T y_o;
  real_T bsum;
  real_T fparamsAugmented_pixel;
  real_T d2;
  real_T q;
  real_T u0;
  real_T b_I_b;
  real_T x;
  int32_T d_g[2];
  int32_T e[2];
  int32_T iv[2];
  int32_T pixelSub[2];
  int32_T e_l[2];
  int32_T f[2];
  int32_T pixelSub_d[2];
  real32_T Gmax;
  real32_T t;
  real32_T xc_tmp;
  int32_T W;
  int32_T swapepd;
  int32_T xk;
  int32_T yk;
  int32_T b_x;
  int32_T x1;
  int32_T b_y1;
  int32_T iindx_data;
  int32_T c_idx;
  int32_T k;
  int32_T nrows;
  int32_T b_j;
  int32_T b_i;
  int32_T g_i;
  int32_T inImg_tmp;
  int32_T k_n;
  int32_T nLastBlock;
  int32_T n;
  int32_T ib;
  int32_T quartetOffset;
  int32_T b_k;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T bLen2;
  int32_T p;
  int32_T q_b;
  int32_T offset1;
  int32_T d_ln;
  int32_T loop_ub;
  int32_T idx_tmp;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  int32_T nPairs;
  int32_T p_h;
  int32_T q_bn;
  int32_T iout;
  int32_T offset1_d;
  int32_T idxkeep;
  int32_T d_e;
  int32_T c_idx_b;
  int32_T b_k_j;
  int32_T loop_ub_f;
  int32_T Ex_chunk_tmp;
  int32_T c_size_idx_1;
  int32_T j;
  int32_T i;
  int32_T cColOffset;
  int32_T aColOffset;
  int32_T bColOffset;
  int32_T ia;
  int32_T j_a;
  int32_T jb;
  int32_T ib_j;
  int32_T i_j;
  int32_T c_tmp;
  int32_T k_o;
  int32_T j_n;
  int32_T f_k;
  int32_T loop_ub_i;
  int32_T CC_RegionLengths;
  int32_T outsize_idx_0_tmp_tmp;
  int32_T numRuns;
  int32_T currentColumn;
  int32_T firstRunOnPreviousColumn;
  int32_T lastRunOnPreviousColumn;
  int32_T firstRunOnThisColumn;
  int32_T p_o;
  int32_T runCounter;
  int32_T row;
  int32_T root_k;
  int32_T root_p;
  int32_T newNumel;
  int32_T i_n;
  int32_T i_m;
  int32_T i_c;
  int32_T pind;
  int32_T b_pind;
  int32_T i_md;
  int32_T ind;
  int32_T secondIndRange_idx_0;
  int32_T secondIndRange_idx_1;
  int32_T firstIndRange_idx_0;
  int32_T firstIndRange_idx_1;
  int32_T indx;
  int32_T nz;
  int32_T c_k;
  int32_T r_tmp;
  int32_T pixelsPerImPage1_idx_1;
  int32_T stackTop;
  int32_T b_z;
  int32_T d_x;
  int32_T c_ind;
  int32_T d_ind;
  int32_T i_m3;
  int32_T J_size;
  int32_T last;
  int32_T idx;
  int32_T k_j;
  int32_T i_h;
  int32_T numElDst;
  int32_T numElSrc;
  int32_T newNumel_c;
  int32_T i_ct;
  uint32_T strongest_idx_data;
  uint32_T numComponents;
  boolean_T last_endless;
  boolean_T b_x_data;
  boolean_T compare_tmp;
  boolean_T flat;
  boolean_T flat_p;
  boolean_T continuePropagation;
  B_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} B_flightControlSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile real_T RateTransition_Buffer[10];/* '<Root>/Rate Transition' */
  real_T xy[2];                        /* '<S2>/Data Store Memory' */
  real_T prev_endless_x;               /* '<S2>/MATLAB Function2' */
  real_T prev_endless_y;               /* '<S2>/MATLAB Function2' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  int32_T sfEvent;                     /* '<S2>/write_or_not' */
  int32_T sfEvent_i;                   /* '<S2>/speed_calculator' */
  int32_T sfEvent_d;                   /* '<S2>/opposite_way' */
  int32_T sfEvent_f;                   /* '<S525>/MATLAB Function' */
  int32_T sfEvent_m;                   /* '<S2>/center_vector_y' */
  int32_T sfEvent_a;                   /* '<S2>/center_vector_x' */
  int32_T sfEvent_g;                   /* '<S2>/Main control' */
  int32_T sfEvent_b;                   /* '<S2>/MATLAB Function4' */
  int32_T sfEvent_p;                   /* '<S2>/MATLAB Function2' */
  int32_T sfEvent_l;                   /* '<S2>/MATLAB Function' */
  parrot_ImageProcess_flightControlSystem_T obj;/* '<S2>/PARROT Image Conversion' */
  volatile int8_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/write_or_not' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S2>/speed_calculator' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S2>/opposite_way' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S525>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S2>/center_vector_y' */
  boolean_T doneDoubleBufferReInit_ey; /* '<S2>/center_vector_x' */
  boolean_T objisempty;                /* '<S2>/PARROT Image Conversion' */
  boolean_T doneDoubleBufferReInit_dl; /* '<S2>/Main control' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S2>/MATLAB Function4' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S2>/MATLAB Function2' */
  boolean_T prev_endless_x_not_empty;  /* '<S2>/MATLAB Function2' */
  boolean_T prev_endless_y_not_empty;  /* '<S2>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_bw; /* '<S2>/MATLAB Function' */
  DW_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} DW_flightControlSystem_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} PrevZCX_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flightControlSystem_T;

/* Parameters for system: '<S4>/Geofencing error' */
struct P_Geofencingerror_flightControlSystem_T_ {
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S243>/Constant'
                                        */
};

/* Parameters for system: '<S341>/MeasurementUpdate' */
struct P_MeasurementUpdate_flightControlSystem_T_ {
  real32_T Lykyhatkk1_Y0;              /* Computed Parameter: Lykyhatkk1_Y0
                                        * Referenced by: '<S372>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S348>/Enabled Subsystem' */
struct P_EnabledSubsystem_flightControlSystem_T_ {
  real32_T deltax_Y0;                  /* Computed Parameter: deltax_Y0
                                        * Referenced by: '<S374>/deltax'
                                        */
};

/* Parameters for system: '<Root>/Control System' */
struct P_ControlSystem_flightControlSystem_T_ {
  real_T outlierBelowFloor_const;     /* Mask Parameter: outlierBelowFloor_const
                                       * Referenced by: '<S258>/Constant'
                                       */
  real_T outlierJump_const;            /* Mask Parameter: outlierJump_const
                                        * Referenced by: '<S313>/Constant'
                                        */
  real_T currentEstimateVeryOffFromPressure_const;
                     /* Mask Parameter: currentEstimateVeryOffFromPressure_const
                      * Referenced by: '<S311>/Constant'
                      */
  real_T currentStateVeryOffsonarflt_const;
                            /* Mask Parameter: currentStateVeryOffsonarflt_const
                             * Referenced by: '<S312>/Constant'
                             */
  real_T Checkerrorcondition_const; /* Mask Parameter: Checkerrorcondition_const
                                     * Referenced by: '<S235>/Constant'
                                     */
  real_T u0continuousOFerrors_const;
                                   /* Mask Parameter: u0continuousOFerrors_const
                                    * Referenced by: '<S234>/Constant'
                                    */
  real32_T Angularvelocitycontrolloop_D[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_D
                                  * Referenced by: '<S100>/Derivative Gain'
                                  */
  real32_T Angularvelocitycontrolloop_I[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_I
                                  * Referenced by: '<S104>/Integral Gain'
                                  */
  real32_T Velocitycontroller_I;       /* Mask Parameter: Velocitycontroller_I
                                        * Referenced by: '<S213>/Integral Gain'
                                        */
  real32_T DiscreteDerivative_ICPrevScaledInput;
                         /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                          * Referenced by: '<S448>/UD'
                          */
  real32_T Angularvelocitycontrolloop_InitialConditionForFilter;
         /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForFilter
          * Referenced by: '<S102>/Filter'
          */
  real32_T Velocitycontroller_InitialConditionForIntegrator;
             /* Mask Parameter: Velocitycontroller_InitialConditionForIntegrator
              * Referenced by: '<S216>/Integrator'
              */
  real32_T Angularvelocitycontrolloop_InitialConditionForIntegrator;
     /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForIntegrator
      * Referenced by: '<S107>/Integrator'
      */
  real32_T Positioncontroller_LowerSaturationLimit;
                      /* Mask Parameter: Positioncontroller_LowerSaturationLimit
                       * Referenced by: '<S169>/Saturation'
                       */
  real32_T Velocitycontroller_LowerSaturationLimit;
                      /* Mask Parameter: Velocitycontroller_LowerSaturationLimit
                       * Referenced by:
                       *   '<S223>/Saturation'
                       *   '<S208>/DeadZone'
                       */
  real32_T Angularvelocitycontrolloop_LowerSaturationLimit;
              /* Mask Parameter: Angularvelocitycontrolloop_LowerSaturationLimit
               * Referenced by:
               *   '<S114>/Saturation'
               *   '<S99>/DeadZone'
               */
  real32_T Angularvelocitycontrolloop_N[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_N
                                  * Referenced by: '<S110>/Filter Coefficient'
                                  */
  real32_T Positioncontroller_P;       /* Mask Parameter: Positioncontroller_P
                                        * Referenced by: '<S167>/Proportional Gain'
                                        */
  real32_T Velocitycontroller_P;       /* Mask Parameter: Velocitycontroller_P
                                        * Referenced by: '<S221>/Proportional Gain'
                                        */
  real32_T Anglecontrolloop_P;         /* Mask Parameter: Anglecontrolloop_P
                                        * Referenced by: '<S58>/Proportional Gain'
                                        */
  real32_T Angularvelocitycontrolloop_P[2];
                                 /* Mask Parameter: Angularvelocitycontrolloop_P
                                  * Referenced by: '<S112>/Proportional Gain'
                                  */
  real32_T Positioncontroller_UpperSaturationLimit;
                      /* Mask Parameter: Positioncontroller_UpperSaturationLimit
                       * Referenced by: '<S169>/Saturation'
                       */
  real32_T Velocitycontroller_UpperSaturationLimit;
                      /* Mask Parameter: Velocitycontroller_UpperSaturationLimit
                       * Referenced by:
                       *   '<S223>/Saturation'
                       *   '<S208>/DeadZone'
                       */
  real32_T Angularvelocitycontrolloop_UpperSaturationLimit;
              /* Mask Parameter: Angularvelocitycontrolloop_UpperSaturationLimit
               * Referenced by:
               *   '<S114>/Saturation'
               *   '<S99>/DeadZone'
               */
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S315>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S316>/Constant'
                                      */
  real32_T maxp_const;                 /* Mask Parameter: maxp_const
                                        * Referenced by: '<S451>/Constant'
                                        */
  real32_T maxq_const;                 /* Mask Parameter: maxq_const
                                        * Referenced by: '<S453>/Constant'
                                        */
  real32_T maxw1_const;                /* Mask Parameter: maxw1_const
                                        * Referenced by: '<S455>/Constant'
                                        */
  real32_T maxw2_const;                /* Mask Parameter: maxw2_const
                                        * Referenced by: '<S456>/Constant'
                                        */
  real32_T maxdw1_const;               /* Mask Parameter: maxdw1_const
                                        * Referenced by: '<S449>/Constant'
                                        */
  real32_T maxdw2_const;               /* Mask Parameter: maxdw2_const
                                        * Referenced by: '<S450>/Constant'
                                        */
  real32_T maxp2_const;                /* Mask Parameter: maxp2_const
                                        * Referenced by: '<S452>/Constant'
                                        */
  real32_T maxq2_const;                /* Mask Parameter: maxq2_const
                                        * Referenced by: '<S454>/Constant'
                                        */
  real32_T maxw3_const;                /* Mask Parameter: maxw3_const
                                        * Referenced by: '<S457>/Constant'
                                        */
  real32_T maxw4_const;                /* Mask Parameter: maxw4_const
                                        * Referenced by: '<S458>/Constant'
                                        */
  real32_T minHeightforOF_const;       /* Mask Parameter: minHeightforOF_const
                                        * Referenced by: '<S459>/Constant'
                                        */
  real32_T CompareToConstant_const_j;
                                    /* Mask Parameter: CompareToConstant_const_j
                                     * Referenced by: '<S236>/Constant'
                                     */
  real32_T CompareToConstant1_const_e;
                                   /* Mask Parameter: CompareToConstant1_const_e
                                    * Referenced by: '<S237>/Constant'
                                    */
  real32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S238>/Constant'
                                      */
  real32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S239>/Constant'
                                      */
  real32_T CompareToConstant4_const; /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S240>/Constant'
                                      */
  real32_T CompareToConstant5_const; /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S241>/Constant'
                                      */
  real32_T DeactivateAccelerationIfOFisnotusedduetolowaltitude_const;
    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S443>/Constant'
     */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con;
  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
   * Referenced by: '<S445>/Constant'
   */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co;
  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
   * Referenced by: '<S446>/Constant'
   */
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S249>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_e;     /* Mask Parameter: WrapToZero_Threshold_e
                                        * Referenced by: '<S435>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_k;     /* Mask Parameter: WrapToZero_Threshold_k
                                        * Referenced by: '<S516>/FixPt Switch'
                                        */
  uint32_T CompareToConstant_const_h;
                                    /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S513>/Constant'
                                     */
  uint32_T CompareToConstant_const_l;
                                    /* Mask Parameter: CompareToConstant_const_l
                                     * Referenced by: '<S431>/Constant'
                                     */
  uint16_T WrapToZero_Threshold_c;     /* Mask Parameter: WrapToZero_Threshold_c
                                        * Referenced by: '<S16>/FixPt Switch'
                                        */
  uint16_T CompareToConstant_const_c;
                                    /* Mask Parameter: CompareToConstant_const_c
                                     * Referenced by: '<S13>/Constant'
                                     */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S4>/ '
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S307>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S309>/deltax'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S429>/Constant'
                                        */
  real_T KalmanGainM_Value[2];         /* Expression: pInitialization.M
                                        * Referenced by: '<S259>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S255>/C'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S251>/Delay2'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S255>/X0'
                                        */
  real_T SaturationSonar_LowerSat;     /* Expression: -inf
                                        * Referenced by: '<S256>/SaturationSonar'
                                        */
  real_T sonarFilter_IIR_NumCoef[4]; /* Expression: Estimator.alt.filterSonarNum
                                      * Referenced by: '<S256>/sonarFilter_IIR'
                                      */
  real_T sonarFilter_IIR_DenCoef[4]; /* Expression: Estimator.alt.filterSonarDen
                                      * Referenced by: '<S256>/sonarFilter_IIR'
                                      */
  real_T sonarFilter_IIR_InitialStates;/* Expression: 0
                                        * Referenced by: '<S256>/sonarFilter_IIR'
                                        */
  real_T KalmanGainM_Value_l[2];       /* Expression: pInitialization.M
                                        * Referenced by: '<S322>/KalmanGainM'
                                        */
  real_T KalmanGainM_Value_a[2];       /* Expression: pInitialization.M
                                        * Referenced by: '<S376>/KalmanGainM'
                                        */
  real_T KalmanGainM_Value_i[8];       /* Expression: pInitialization.M
                                        * Referenced by: '<S460>/KalmanGainM'
                                        */
  real_T speed_Value;                  /* Expression: 0.01
                                        * Referenced by: '<S5>/speed'
                                        */
  real_T Wait3Seconds_Value;           /* Expression: 200*3
                                        * Referenced by: '<S4>/Wait  3 Seconds'
                                        */
  real_T DelayOneStep_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S4>/Delay One Step'
                                        */
  real_T u5meters_Value;               /* Expression: 0.5
                                        * Referenced by: '<S4>/0.5 meters'
                                        */
  real_T A_Value[4];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S255>/A'
                                        */
  real_T B_Value[2];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S255>/B'
                                        */
  real_T CovarianceZ_Value[4];         /* Expression: pInitialization.Z
                                        * Referenced by: '<S259>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value[2];         /* Expression: pInitialization.L
                                        * Referenced by: '<S259>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S255>/D'
                                        */
  real_T P0_Value[4];                  /* Expression: pInitialization.P0
                                        * Referenced by: '<S255>/P0'
                                        */
  real_T G_Value[2];                   /* Expression: pInitialization.G
                                        * Referenced by: '<S255>/G'
                                        */
  real_T H_Value;                      /* Expression: pInitialization.H
                                        * Referenced by: '<S255>/H'
                                        */
  real_T N_Value;                      /* Expression: pInitialization.N
                                        * Referenced by: '<S255>/N'
                                        */
  real_T gravity_Value[3];             /* Expression: [0 0 g]
                                        * Referenced by: '<S251>/gravity'
                                        */
  real_T Q_Value;                      /* Expression: pInitialization.Q
                                        * Referenced by: '<S255>/Q'
                                        */
  real_T R_Value;                      /* Expression: pInitialization.R
                                        * Referenced by: '<S255>/R'
                                        */
  real_T CovarianceZ_Value_b[4];       /* Expression: pInitialization.Z
                                        * Referenced by: '<S322>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value_l[2];       /* Expression: pInitialization.L
                                        * Referenced by: '<S322>/KalmanGainL'
                                        */
  real_T CovarianceZ_Value_m[4];       /* Expression: pInitialization.Z
                                        * Referenced by: '<S376>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value_p[2];       /* Expression: pInitialization.L
                                        * Referenced by: '<S376>/KalmanGainL'
                                        */
  real_T gravity_Value_p[3];           /* Expression: [0 0 -g]
                                        * Referenced by: '<S438>/gravity'
                                        */
  real_T gainaccinput1_Gain;           /* Expression: 1
                                        * Referenced by: '<S438>/gainaccinput1'
                                        */
  real_T CovarianceZ_Value_p[16];      /* Expression: pInitialization.Z
                                        * Referenced by: '<S460>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value_k[8];       /* Expression: pInitialization.L
                                        * Referenced by: '<S460>/KalmanGainL'
                                        */
  real32_T takeoff_gain1_Gain;         /* Expression: Controller.takeoffGain
                                        * Referenced by: '<S7>/takeoff_gain1'
                                        */
  real32_T P_z1_Gain;                  /* Computed Parameter: P_z1_Gain
                                        * Referenced by: '<S7>/P_z1'
                                        */
  real32_T D_z1_Gain;                  /* Computed Parameter: D_z1_Gain
                                        * Referenced by: '<S7>/D_z1'
                                        */
  real32_T Pitchcorrection_Value;   /* Computed Parameter: Pitchcorrection_Value
                                     * Referenced by: '<S9>/Pitch correction'
                                     */
  real32_T zerocorrection_Value;     /* Computed Parameter: zerocorrection_Value
                                      * Referenced by: '<S9>/zero correction'
                                      */
  real32_T Gain_Gain[2];               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S10>/Gain'
                                        */
  real32_T _Value_i;                   /* Computed Parameter: _Value_i
                                        * Referenced by: '<S4>/    '
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S429>/Gain'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S433>/Out1'
                                        */
  real32_T Lykyhatkk1_Y0_c;            /* Computed Parameter: Lykyhatkk1_Y0_c
                                        * Referenced by: '<S510>/L*(y[k]-yhat[k|k-1])'
                                        */
  real32_T deltax_Y0_k;                /* Computed Parameter: deltax_Y0_k
                                        * Referenced by: '<S512>/deltax'
                                        */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S442>/Gain'
                                        */
  real32_T opticalFlowErrorCorrect_Gain;
                             /* Computed Parameter: opticalFlowErrorCorrect_Gain
                              * Referenced by: '<S442>/opticalFlowErrorCorrect'
                              */
  real32_T SimplyIntegrateVelocity_gainval;
                          /* Computed Parameter: SimplyIntegrateVelocity_gainval
                           * Referenced by: '<S437>/SimplyIntegrateVelocity'
                           */
  real32_T SimplyIntegrateVelocity_IC;
                               /* Computed Parameter: SimplyIntegrateVelocity_IC
                                * Referenced by: '<S437>/SimplyIntegrateVelocity'
                                */
  real32_T invertzaxisGain_Gain;     /* Computed Parameter: invertzaxisGain_Gain
                                      * Referenced by: '<S251>/invertzaxisGain'
                                      */
  real32_T prsToAltGain_Gain;          /* Computed Parameter: prsToAltGain_Gain
                                        * Referenced by: '<S251>/prsToAltGain'
                                        */
  real32_T pressureFilter_IIR_NumCoef[4];
                               /* Computed Parameter: pressureFilter_IIR_NumCoef
                                * Referenced by: '<S256>/pressureFilter_IIR'
                                */
  real32_T pressureFilter_IIR_DenCoef[4];
                               /* Computed Parameter: pressureFilter_IIR_DenCoef
                                * Referenced by: '<S256>/pressureFilter_IIR'
                                */
  real32_T pressureFilter_IIR_InitialStates;
                         /* Computed Parameter: pressureFilter_IIR_InitialStates
                          * Referenced by: '<S256>/pressureFilter_IIR'
                          */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S319>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S319>/Discrete-Time Integrator'
                                 */
  real32_T C_Value_h[2];               /* Computed Parameter: C_Value_h
                                        * Referenced by: '<S321>/C'
                                        */
  real32_T Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[6];
  /* Computed Parameter: Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
   * Referenced by: '<S253>/Assuming that the  preflight calibration was done at level orientation'
   */
  real32_T inverseIMU_gain_Gain[6];  /* Computed Parameter: inverseIMU_gain_Gain
                                      * Referenced by: '<S253>/inverseIMU_gain'
                                      */
  real32_T FIR_IMUaccel_InitialStates;
                               /* Computed Parameter: FIR_IMUaccel_InitialStates
                                * Referenced by: '<S253>/FIR_IMUaccel'
                                */
  real32_T FIR_IMUaccel_Coefficients[6];
                                /* Computed Parameter: FIR_IMUaccel_Coefficients
                                 * Referenced by: '<S253>/FIR_IMUaccel'
                                 */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S317>/Gain2'
                                        */
  real32_T X0_Value_i[2];              /* Computed Parameter: X0_Value_i
                                        * Referenced by: '<S321>/X0'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S320>/Constant'
                                        */
  real32_T C_Value_i[2];               /* Computed Parameter: C_Value_i
                                        * Referenced by: '<S375>/C'
                                        */
  real32_T X0_Value_iy[2];             /* Computed Parameter: X0_Value_iy
                                        * Referenced by: '<S375>/X0'
                                        */
  real32_T C_Value_i2[8];              /* Computed Parameter: C_Value_i2
                                        * Referenced by: '<S441>/C'
                                        */
  real32_T LPFFcutoff40Hz1_NumCoef[2];
                                  /* Computed Parameter: LPFFcutoff40Hz1_NumCoef
                                   * Referenced by: '<S253>/LPF Fcutoff = 40Hz1'
                                   */
  real32_T LPFFcutoff40Hz1_DenCoef[2];
                                  /* Computed Parameter: LPFFcutoff40Hz1_DenCoef
                                   * Referenced by: '<S253>/LPF Fcutoff = 40Hz1'
                                   */
  real32_T LPFFcutoff40Hz1_InitialStates;
                            /* Computed Parameter: LPFFcutoff40Hz1_InitialStates
                             * Referenced by: '<S253>/LPF Fcutoff = 40Hz1'
                             */
  real32_T LPFFcutoff40Hz_NumCoef[2];
                                   /* Computed Parameter: LPFFcutoff40Hz_NumCoef
                                    * Referenced by: '<S253>/LPF Fcutoff = 40Hz'
                                    */
  real32_T LPFFcutoff40Hz_DenCoef[2];
                                   /* Computed Parameter: LPFFcutoff40Hz_DenCoef
                                    * Referenced by: '<S253>/LPF Fcutoff = 40Hz'
                                    */
  real32_T LPFFcutoff40Hz_InitialStates;
                             /* Computed Parameter: LPFFcutoff40Hz_InitialStates
                              * Referenced by: '<S253>/LPF Fcutoff = 40Hz'
                              */
  real32_T IIR_IMUgyro_r_NumCoef[6];/* Computed Parameter: IIR_IMUgyro_r_NumCoef
                                     * Referenced by: '<S253>/IIR_IMUgyro_r'
                                     */
  real32_T IIR_IMUgyro_r_DenCoef[6];/* Computed Parameter: IIR_IMUgyro_r_DenCoef
                                     * Referenced by: '<S253>/IIR_IMUgyro_r'
                                     */
  real32_T IIR_IMUgyro_r_InitialStates;
                              /* Computed Parameter: IIR_IMUgyro_r_InitialStates
                               * Referenced by: '<S253>/IIR_IMUgyro_r'
                               */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S319>/Constant'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S439>/Gain1'
                                        */
  real32_T X0_Value_c[4];              /* Computed Parameter: X0_Value_c
                                        * Referenced by: '<S441>/X0'
                                        */
  real32_T IIRgyroz_NumCoef[6];        /* Computed Parameter: IIRgyroz_NumCoef
                                        * Referenced by: '<S440>/IIRgyroz'
                                        */
  real32_T IIRgyroz_DenCoef[6];        /* Computed Parameter: IIRgyroz_DenCoef
                                        * Referenced by: '<S440>/IIRgyroz'
                                        */
  real32_T IIRgyroz_InitialStates; /* Computed Parameter: IIRgyroz_InitialStates
                                    * Referenced by: '<S440>/IIRgyroz'
                                    */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S448>/TSamp'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S436>/Delay'
                                    */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S6>/Delay1'
                                   */
  real32_T DiscreteTimeIntegrator_gainval_n;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
                          * Referenced by: '<S7>/Discrete-Time Integrator'
                          */
  real32_T DiscreteTimeIntegrator_IC_h;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_h
                               * Referenced by: '<S7>/Discrete-Time Integrator'
                               */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real32_T I_pr_Gain;                  /* Computed Parameter: I_pr_Gain
                                        * Referenced by: '<S7>/I_pr'
                                        */
  real32_T w1_Value;                   /* Computed Parameter: w1_Value
                                        * Referenced by: '<S7>/w1'
                                        */
  real32_T SaturationThrust1_UpperSat;
                               /* Computed Parameter: SaturationThrust1_UpperSat
                                * Referenced by: '<S7>/SaturationThrust1'
                                */
  real32_T SaturationThrust1_LowerSat;
                               /* Computed Parameter: SaturationThrust1_LowerSat
                                * Referenced by: '<S7>/SaturationThrust1'
                                */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S216>/Integrator'
                                        */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[2];
  /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
   * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[2];
  /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
   * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   */
  real32_T LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l;
  /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l
   * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S97>/Clamping_zero'
                                       */
  real32_T Integrator_gainval_i;     /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S107>/Integrator'
                                      */
  real32_T Filter_gainval;             /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S102>/Filter'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S97>/Constant1'
                                        */
  real32_T TorqueTotalThrustToThrustPerMotor_Value[16];/* Expression: Controller.Q2Ts
                                                        * Referenced by: '<S9>/TorqueTotalThrustToThrustPerMotor'
                                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S11>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S11>/Saturation'
                                       */
  real32_T P_yaw_Gain;                 /* Computed Parameter: P_yaw_Gain
                                        * Referenced by: '<S11>/P_yaw'
                                        */
  real32_T DiscreteTimeIntegrator_gainval_d;
                         /* Computed Parameter: DiscreteTimeIntegrator_gainval_d
                          * Referenced by: '<S11>/Discrete-Time Integrator'
                          */
  real32_T DiscreteTimeIntegrator_IC_b;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_b
                               * Referenced by: '<S11>/Discrete-Time Integrator'
                               */
  real32_T D_yaw_Gain;                 /* Computed Parameter: D_yaw_Gain
                                        * Referenced by: '<S11>/D_yaw'
                                        */
  real32_T Clamping_zero_Value_m;   /* Computed Parameter: Clamping_zero_Value_m
                                     * Referenced by: '<S206>/Clamping_zero'
                                     */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S206>/Constant1'
                                        */
  real32_T I_yaw_Gain;                 /* Computed Parameter: I_yaw_Gain
                                        * Referenced by: '<S11>/I_yaw'
                                        */
  real32_T ThrustToMotorCommand_Gain;
                                /* Computed Parameter: ThrustToMotorCommand_Gain
                                 * Referenced by: '<S12>/ThrustToMotorCommand'
                                 */
  real32_T Saturation5_UpperSat;       /* Expression: Vehicle.Motor.maxLimit
                                        * Referenced by: '<S12>/Saturation5'
                                        */
  real32_T Saturation5_LowerSat;       /* Expression: Vehicle.Motor.minLimit
                                        * Referenced by: '<S12>/Saturation5'
                                        */
  real32_T MotorDirections_Gain[4];  /* Computed Parameter: MotorDirections_Gain
                                      * Referenced by: '<S12>/MotorDirections'
                                      */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S4>/Gain'
                                        */
  real32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real32_T A_Value_k[4];               /* Computed Parameter: A_Value_k
                                        * Referenced by: '<S321>/A'
                                        */
  real32_T B_Value_o[2];               /* Computed Parameter: B_Value_o
                                        * Referenced by: '<S321>/B'
                                        */
  real32_T D_Value_k;                  /* Computed Parameter: D_Value_k
                                        * Referenced by: '<S321>/D'
                                        */
  real32_T P0_Value_h[4];              /* Computed Parameter: P0_Value_h
                                        * Referenced by: '<S321>/P0'
                                        */
  real32_T G_Value_m[4];               /* Computed Parameter: G_Value_m
                                        * Referenced by: '<S321>/G'
                                        */
  real32_T H_Value_a[2];               /* Computed Parameter: H_Value_a
                                        * Referenced by: '<S321>/H'
                                        */
  real32_T N_Value_f[2];               /* Computed Parameter: N_Value_f
                                        * Referenced by: '<S321>/N'
                                        */
  real32_T Q_Value_j[4];               /* Computed Parameter: Q_Value_j
                                        * Referenced by: '<S321>/Q'
                                        */
  real32_T R_Value_a;                  /* Computed Parameter: R_Value_a
                                        * Referenced by: '<S321>/R'
                                        */
  real32_T A_Value_a[4];               /* Computed Parameter: A_Value_a
                                        * Referenced by: '<S375>/A'
                                        */
  real32_T B_Value_g[2];               /* Computed Parameter: B_Value_g
                                        * Referenced by: '<S375>/B'
                                        */
  real32_T D_Value_ke;                 /* Computed Parameter: D_Value_ke
                                        * Referenced by: '<S375>/D'
                                        */
  real32_T P0_Value_l[4];              /* Computed Parameter: P0_Value_l
                                        * Referenced by: '<S375>/P0'
                                        */
  real32_T G_Value_g[4];               /* Computed Parameter: G_Value_g
                                        * Referenced by: '<S375>/G'
                                        */
  real32_T H_Value_o[2];               /* Computed Parameter: H_Value_o
                                        * Referenced by: '<S375>/H'
                                        */
  real32_T N_Value_b[2];               /* Computed Parameter: N_Value_b
                                        * Referenced by: '<S375>/N'
                                        */
  real32_T Q_Value_p[4];               /* Computed Parameter: Q_Value_p
                                        * Referenced by: '<S375>/Q'
                                        */
  real32_T R_Value_l;                  /* Computed Parameter: R_Value_l
                                        * Referenced by: '<S375>/R'
                                        */
  real32_T A_Value_a4[16];             /* Computed Parameter: A_Value_a4
                                        * Referenced by: '<S441>/A'
                                        */
  real32_T B_Value_f[8];               /* Computed Parameter: B_Value_f
                                        * Referenced by: '<S441>/B'
                                        */
  real32_T D_Value_h[4];               /* Computed Parameter: D_Value_h
                                        * Referenced by: '<S441>/D'
                                        */
  real32_T P0_Value_e[16];             /* Computed Parameter: P0_Value_e
                                        * Referenced by: '<S441>/P0'
                                        */
  real32_T G_Value_i[16];              /* Computed Parameter: G_Value_i
                                        * Referenced by: '<S441>/G'
                                        */
  real32_T H_Value_i[8];               /* Computed Parameter: H_Value_i
                                        * Referenced by: '<S441>/H'
                                        */
  real32_T N_Value_i[8];               /* Computed Parameter: N_Value_i
                                        * Referenced by: '<S441>/N'
                                        */
  real32_T Q_Value_m[16];              /* Computed Parameter: Q_Value_m
                                        * Referenced by: '<S441>/Q'
                                        */
  real32_T R_Value_h[4];               /* Computed Parameter: R_Value_h
                                        * Referenced by: '<S441>/R'
                                        */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S514>/Output'
                                   */
  uint32_T Output_InitialCondition_e;
                                /* Computed Parameter: Output_InitialCondition_e
                                 * Referenced by: '<S432>/Output'
                                 */
  uint32_T Output_InitialCondition_h;
                                /* Computed Parameter: Output_InitialCondition_h
                                 * Referenced by: '<S242>/Output'
                                 */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S248>/FixPt Constant'
                                       */
  uint32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S249>/Constant'
                                        */
  uint32_T FixPtConstant_Value_m;   /* Computed Parameter: FixPtConstant_Value_m
                                     * Referenced by: '<S434>/FixPt Constant'
                                     */
  uint32_T Constant_Value_jy;          /* Computed Parameter: Constant_Value_jy
                                        * Referenced by: '<S435>/Constant'
                                        */
  uint32_T FixPtConstant_Value_p;   /* Computed Parameter: FixPtConstant_Value_p
                                     * Referenced by: '<S515>/FixPt Constant'
                                     */
  uint32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S516>/Constant'
                                        */
  uint16_T Output_InitialCondition_f;
                                /* Computed Parameter: Output_InitialCondition_f
                                 * Referenced by: '<S14>/Output'
                                 */
  uint16_T FixPtConstant_Value_g;   /* Computed Parameter: FixPtConstant_Value_g
                                     * Referenced by: '<S15>/FixPt Constant'
                                     */
  uint16_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S16>/Constant'
                                        */
  boolean_T controlModePosVsOrient_Value;
                             /* Computed Parameter: controlModePosVsOrient_Value
                              * Referenced by: '<S1>/controlModePosVsOrient'
                              */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S305>/isSqrtUsed'
                                        */
  boolean_T isSqrtUsed_Value_f;        /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S370>/isSqrtUsed'
                                        */
  boolean_T isSqrtUsed_Value_j;        /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S424>/isSqrtUsed'
                                        */
  boolean_T isSqrtUsed_Value_l;        /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S508>/isSqrtUsed'
                                        */
  int8_T Constant_Value_km;            /* Computed Parameter: Constant_Value_km
                                        * Referenced by: '<S97>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S97>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S97>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S97>/Constant4'
                                        */
  int8_T Constant_Value_p;             /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S206>/Constant'
                                        */
  int8_T Constant2_Value_f;            /* Computed Parameter: Constant2_Value_f
                                        * Referenced by: '<S206>/Constant2'
                                        */
  int8_T Constant3_Value_d;            /* Computed Parameter: Constant3_Value_d
                                        * Referenced by: '<S206>/Constant3'
                                        */
  int8_T Constant4_Value_p;            /* Computed Parameter: Constant4_Value_p
                                        * Referenced by: '<S206>/Constant4'
                                        */
  uint8_T Disabletemperaturecompensation_CurrentSetting;
            /* Computed Parameter: Disabletemperaturecompensation_CurrentSetting
             * Referenced by: '<S429>/Disable temperature compensation'
             */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S9>/Manual Switch'
                               */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S4>/Merge'
                                       */
  P_EnabledSubsystem_flightControlSystem_T EnabledSubsystem_n;/* '<S402>/Enabled Subsystem' */
  P_MeasurementUpdate_flightControlSystem_T MeasurementUpdate_j;/* '<S395>/MeasurementUpdate' */
  P_EnabledSubsystem_flightControlSystem_T EnabledSubsystem_d;/* '<S348>/Enabled Subsystem' */
  P_MeasurementUpdate_flightControlSystem_T MeasurementUpdate_n;/* '<S341>/MeasurementUpdate' */
  P_Geofencingerror_flightControlSystem_T Normalcondition;/* '<S4>/Normal condition' */
  P_Geofencingerror_flightControlSystem_T Ultrasoundimproper;/* '<S4>/Ultrasound improper' */
  P_Geofencingerror_flightControlSystem_T Noopticalflow;/* '<S4>/No optical flow ' */
  P_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S4>/estimator//Optical flow error' */
  P_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S4>/Geofencing error' */
};

/* Parameters (default storage) */
struct P_flightControlSystem_T_ {
  struct_8SSZ93PxvPkADZcA4gG8MD Sensors;/* Variable: Sensors
                                         * Referenced by:
                                         *   '<S256>/SaturationSonar'
                                         *   '<S310>/Constant'
                                         */
  real_T Constant1_Value;              /* Expression: 70
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 16
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T switch_way_Threshold;         /* Expression: 0
                                        * Referenced by: '<S2>/switch_way'
                                        */
  real_T DataStoreMemory_InitialValue[2];/* Expression: [0 0]
                                          * Referenced by: '<S2>/Data Store Memory'
                                          */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<Root>/Rate Transition'
                                          */
  P_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_flightControlSystem_T flightControlSystem_P;

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_flightControlSystem_T flightControlSystem_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S12>/MotorDirections' */
extern uint8_T flag_outport;           /* '<S4>/Merge' */

/* External function called from main */
extern void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void flightControlSystem_initialize(void);
extern void flightControlSystem_step0(void);/* Sample time: [0.005s, 0.0s] */
extern void flightControlSystem_step1(void);/* Sample time: [0.2s, 0.0s] */
extern void flightControlSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightControlSystem_T *const flightControlSystem_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Control System'
 * '<S2>'   : 'flightControlSystem/Image Processing System'
 * '<S3>'   : 'flightControlSystem/Control System/Controller'
 * '<S4>'   : 'flightControlSystem/Control System/Crash Predictor Flags'
 * '<S5>'   : 'flightControlSystem/Control System/Path Planning'
 * '<S6>'   : 'flightControlSystem/Control System/State Estimator'
 * '<S7>'   : 'flightControlSystem/Control System/Controller/Altitude Controller'
 * '<S8>'   : 'flightControlSystem/Control System/Controller/Attitude Controller'
 * '<S9>'   : 'flightControlSystem/Control System/Controller/ControlMixer'
 * '<S10>'  : 'flightControlSystem/Control System/Controller/Position Controller'
 * '<S11>'  : 'flightControlSystem/Control System/Controller/Yaw Controller'
 * '<S12>'  : 'flightControlSystem/Control System/Controller/thrustsToMotorCommands'
 * '<S13>'  : 'flightControlSystem/Control System/Controller/Altitude Controller/Compare To Constant'
 * '<S14>'  : 'flightControlSystem/Control System/Controller/Altitude Controller/Counter Free-Running'
 * '<S15>'  : 'flightControlSystem/Control System/Controller/Altitude Controller/Counter Free-Running/Increment Real World'
 * '<S16>'  : 'flightControlSystem/Control System/Controller/Altitude Controller/Counter Free-Running/Wrap To Zero'
 * '<S17>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop'
 * '<S18>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop'
 * '<S19>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Anti-windup'
 * '<S20>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/D Gain'
 * '<S21>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/External Derivative'
 * '<S22>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Filter'
 * '<S23>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Filter ICs'
 * '<S24>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/I Gain'
 * '<S25>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain'
 * '<S26>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain Fdbk'
 * '<S27>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Integrator'
 * '<S28>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Integrator ICs'
 * '<S29>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/N Copy'
 * '<S30>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/N Gain'
 * '<S31>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/P Copy'
 * '<S32>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Parallel P Gain'
 * '<S33>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Reset Signal'
 * '<S34>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Saturation'
 * '<S35>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Saturation Fdbk'
 * '<S36>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Sum'
 * '<S37>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Sum Fdbk'
 * '<S38>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode'
 * '<S39>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode Sum'
 * '<S40>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Integral'
 * '<S41>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Ngain'
 * '<S42>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/postSat Signal'
 * '<S43>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/preInt Signal'
 * '<S44>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/preSat Signal'
 * '<S45>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Anti-windup/Disabled'
 * '<S46>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/D Gain/Disabled'
 * '<S47>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/External Derivative/Disabled'
 * '<S48>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Filter/Disabled'
 * '<S49>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Filter ICs/Disabled'
 * '<S50>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/I Gain/Disabled'
 * '<S51>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain/Passthrough'
 * '<S52>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Ideal P Gain Fdbk/Disabled'
 * '<S53>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Integrator/Disabled'
 * '<S54>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Integrator ICs/Disabled'
 * '<S55>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/N Copy/Disabled wSignal Specification'
 * '<S56>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/N Gain/Disabled'
 * '<S57>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/P Copy/Disabled'
 * '<S58>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Parallel P Gain/Internal Parameters'
 * '<S59>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Reset Signal/Disabled'
 * '<S60>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Saturation/Passthrough'
 * '<S61>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Saturation Fdbk/Disabled'
 * '<S62>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Sum/Passthrough_P'
 * '<S63>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Sum Fdbk/Disabled'
 * '<S64>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode/Disabled'
 * '<S65>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tracking Mode Sum/Passthrough'
 * '<S66>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Integral/TsSignalSpecification'
 * '<S67>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/Tsamp - Ngain/Passthrough'
 * '<S68>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/postSat Signal/Forward_Path'
 * '<S69>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/preInt Signal/Internal PreInt'
 * '<S70>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angle control loop/preSat Signal/Forward_Path'
 * '<S71>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup'
 * '<S72>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/D Gain'
 * '<S73>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/External Derivative'
 * '<S74>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Filter'
 * '<S75>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Filter ICs'
 * '<S76>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/I Gain'
 * '<S77>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain'
 * '<S78>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain Fdbk'
 * '<S79>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator'
 * '<S80>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator ICs'
 * '<S81>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/N Copy'
 * '<S82>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/N Gain'
 * '<S83>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/P Copy'
 * '<S84>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Parallel P Gain'
 * '<S85>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Reset Signal'
 * '<S86>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation'
 * '<S87>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation Fdbk'
 * '<S88>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Sum'
 * '<S89>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Sum Fdbk'
 * '<S90>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode'
 * '<S91>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode Sum'
 * '<S92>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Integral'
 * '<S93>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Ngain'
 * '<S94>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/postSat Signal'
 * '<S95>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/preInt Signal'
 * '<S96>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/preSat Signal'
 * '<S97>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup/Disc. Clamping Parallel'
 * '<S98>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S99>'  : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S100>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/D Gain/Internal Parameters'
 * '<S101>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/External Derivative/Error'
 * '<S102>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Filter/Disc. Forward Euler Filter'
 * '<S103>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Filter ICs/Internal IC - Filter'
 * '<S104>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/I Gain/Internal Parameters'
 * '<S105>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain/Passthrough'
 * '<S106>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Ideal P Gain Fdbk/Disabled'
 * '<S107>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator/Discrete'
 * '<S108>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Integrator ICs/Internal IC'
 * '<S109>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/N Copy/Disabled'
 * '<S110>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/N Gain/Internal Parameters'
 * '<S111>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/P Copy/Disabled'
 * '<S112>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Parallel P Gain/Internal Parameters'
 * '<S113>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Reset Signal/Disabled'
 * '<S114>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation/Enabled'
 * '<S115>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Saturation Fdbk/Disabled'
 * '<S116>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Sum/Sum_PID'
 * '<S117>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Sum Fdbk/Disabled'
 * '<S118>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode/Disabled'
 * '<S119>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tracking Mode Sum/Passthrough'
 * '<S120>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Integral/TsSignalSpecification'
 * '<S121>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/Tsamp - Ngain/Passthrough'
 * '<S122>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/postSat Signal/Forward_Path'
 * '<S123>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/preInt Signal/Internal PreInt'
 * '<S124>' : 'flightControlSystem/Control System/Controller/Attitude Controller/Angular velocity control loop/preSat Signal/Forward_Path'
 * '<S125>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller'
 * '<S126>' : 'flightControlSystem/Control System/Controller/Position Controller/Position error transformation (Earth to Body frame)'
 * '<S127>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller'
 * '<S128>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Anti-windup'
 * '<S129>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/D Gain'
 * '<S130>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/External Derivative'
 * '<S131>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Filter'
 * '<S132>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Filter ICs'
 * '<S133>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/I Gain'
 * '<S134>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Ideal P Gain'
 * '<S135>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Ideal P Gain Fdbk'
 * '<S136>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Integrator'
 * '<S137>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Integrator ICs'
 * '<S138>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/N Copy'
 * '<S139>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/N Gain'
 * '<S140>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/P Copy'
 * '<S141>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Parallel P Gain'
 * '<S142>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Reset Signal'
 * '<S143>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Saturation'
 * '<S144>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Saturation Fdbk'
 * '<S145>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Sum'
 * '<S146>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Sum Fdbk'
 * '<S147>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tracking Mode'
 * '<S148>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tracking Mode Sum'
 * '<S149>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tsamp - Integral'
 * '<S150>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tsamp - Ngain'
 * '<S151>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/postSat Signal'
 * '<S152>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/preInt Signal'
 * '<S153>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/preSat Signal'
 * '<S154>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Anti-windup/Disabled'
 * '<S155>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/D Gain/Disabled'
 * '<S156>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/External Derivative/Disabled'
 * '<S157>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Filter/Disabled'
 * '<S158>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Filter ICs/Disabled'
 * '<S159>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/I Gain/Disabled'
 * '<S160>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Ideal P Gain/Passthrough'
 * '<S161>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Ideal P Gain Fdbk/Disabled'
 * '<S162>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Integrator/Disabled'
 * '<S163>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Integrator ICs/Disabled'
 * '<S164>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/N Copy/Disabled wSignal Specification'
 * '<S165>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/N Gain/Disabled'
 * '<S166>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/P Copy/Disabled'
 * '<S167>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Parallel P Gain/Internal Parameters'
 * '<S168>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Reset Signal/Disabled'
 * '<S169>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Saturation/Enabled'
 * '<S170>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Saturation Fdbk/Disabled'
 * '<S171>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Sum/Passthrough_P'
 * '<S172>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Sum Fdbk/Disabled'
 * '<S173>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tracking Mode/Disabled'
 * '<S174>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tracking Mode Sum/Passthrough'
 * '<S175>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tsamp - Integral/TsSignalSpecification'
 * '<S176>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/Tsamp - Ngain/Passthrough'
 * '<S177>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/postSat Signal/Forward_Path'
 * '<S178>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/preInt Signal/Internal PreInt'
 * '<S179>' : 'flightControlSystem/Control System/Controller/Position Controller/Position controller/preSat Signal/Forward_Path'
 * '<S180>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Anti-windup'
 * '<S181>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/D Gain'
 * '<S182>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/External Derivative'
 * '<S183>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Filter'
 * '<S184>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Filter ICs'
 * '<S185>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/I Gain'
 * '<S186>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Ideal P Gain'
 * '<S187>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Ideal P Gain Fdbk'
 * '<S188>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Integrator'
 * '<S189>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Integrator ICs'
 * '<S190>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/N Copy'
 * '<S191>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/N Gain'
 * '<S192>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/P Copy'
 * '<S193>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Parallel P Gain'
 * '<S194>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Reset Signal'
 * '<S195>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Saturation'
 * '<S196>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Saturation Fdbk'
 * '<S197>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Sum'
 * '<S198>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Sum Fdbk'
 * '<S199>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tracking Mode'
 * '<S200>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tracking Mode Sum'
 * '<S201>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tsamp - Integral'
 * '<S202>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tsamp - Ngain'
 * '<S203>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/postSat Signal'
 * '<S204>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/preInt Signal'
 * '<S205>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/preSat Signal'
 * '<S206>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Anti-windup/Disc. Clamping Parallel'
 * '<S207>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S208>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S209>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/D Gain/Disabled'
 * '<S210>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/External Derivative/Disabled'
 * '<S211>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Filter/Disabled'
 * '<S212>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Filter ICs/Disabled'
 * '<S213>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/I Gain/Internal Parameters'
 * '<S214>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Ideal P Gain/Passthrough'
 * '<S215>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Ideal P Gain Fdbk/Disabled'
 * '<S216>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Integrator/Discrete'
 * '<S217>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Integrator ICs/Internal IC'
 * '<S218>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/N Copy/Disabled wSignal Specification'
 * '<S219>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/N Gain/Disabled'
 * '<S220>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/P Copy/Disabled'
 * '<S221>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Parallel P Gain/Internal Parameters'
 * '<S222>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Reset Signal/Disabled'
 * '<S223>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Saturation/Enabled'
 * '<S224>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Saturation Fdbk/Disabled'
 * '<S225>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Sum/Sum_PI'
 * '<S226>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Sum Fdbk/Disabled'
 * '<S227>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tracking Mode/Disabled'
 * '<S228>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tracking Mode Sum/Passthrough'
 * '<S229>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tsamp - Integral/TsSignalSpecification'
 * '<S230>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/Tsamp - Ngain/Passthrough'
 * '<S231>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/postSat Signal/Forward_Path'
 * '<S232>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/preInt Signal/Internal PreInt'
 * '<S233>' : 'flightControlSystem/Control System/Controller/Position Controller/Velocity controller/preSat Signal/Forward_Path'
 * '<S234>' : 'flightControlSystem/Control System/Crash Predictor Flags/50 continuous  OF errors '
 * '<S235>' : 'flightControlSystem/Control System/Crash Predictor Flags/Check error condition'
 * '<S236>' : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant'
 * '<S237>' : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant1'
 * '<S238>' : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant2'
 * '<S239>' : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant3'
 * '<S240>' : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant4'
 * '<S241>' : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant5'
 * '<S242>' : 'flightControlSystem/Control System/Crash Predictor Flags/Counter Free-Running'
 * '<S243>' : 'flightControlSystem/Control System/Crash Predictor Flags/Geofencing error'
 * '<S244>' : 'flightControlSystem/Control System/Crash Predictor Flags/No optical flow '
 * '<S245>' : 'flightControlSystem/Control System/Crash Predictor Flags/Normal condition'
 * '<S246>' : 'flightControlSystem/Control System/Crash Predictor Flags/Ultrasound improper'
 * '<S247>' : 'flightControlSystem/Control System/Crash Predictor Flags/estimator//Optical flow error'
 * '<S248>' : 'flightControlSystem/Control System/Crash Predictor Flags/Counter Free-Running/Increment Real World'
 * '<S249>' : 'flightControlSystem/Control System/Crash Predictor Flags/Counter Free-Running/Wrap To Zero'
 * '<S250>' : 'flightControlSystem/Control System/Path Planning/Chart'
 * '<S251>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator'
 * '<S252>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator'
 * '<S253>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing'
 * '<S254>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator'
 * '<S255>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude'
 * '<S256>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/OutlierHandling'
 * '<S257>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/Rotation Angles to Direction Cosine Matrix'
 * '<S258>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/outlierBelowFloor'
 * '<S259>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculatePL'
 * '<S260>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculateYhat'
 * '<S261>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CovarianceOutputConfigurator'
 * '<S262>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionA'
 * '<S263>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionB'
 * '<S264>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionC'
 * '<S265>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionD'
 * '<S266>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionG'
 * '<S267>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionH'
 * '<S268>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionN'
 * '<S269>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionP'
 * '<S270>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionP0'
 * '<S271>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionQ'
 * '<S272>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionR'
 * '<S273>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionX'
 * '<S274>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionX0'
 * '<S275>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/DataTypeConversionu'
 * '<S276>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/MemoryP'
 * '<S277>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/Observer'
 * '<S278>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/ReducedQRN'
 * '<S279>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/Reshapeyhat'
 * '<S280>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/ScalarExpansionP0'
 * '<S281>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/ScalarExpansionQ'
 * '<S282>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/ScalarExpansionR'
 * '<S283>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/UseCurrentEstimator'
 * '<S284>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkA'
 * '<S285>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkB'
 * '<S286>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkC'
 * '<S287>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkD'
 * '<S288>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkEnable'
 * '<S289>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkG'
 * '<S290>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkH'
 * '<S291>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkN'
 * '<S292>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkP0'
 * '<S293>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkQ'
 * '<S294>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkR'
 * '<S295>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkReset'
 * '<S296>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checkX0'
 * '<S297>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checku'
 * '<S298>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/checky'
 * '<S299>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculatePL/DataTypeConversionL'
 * '<S300>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculatePL/DataTypeConversionM'
 * '<S301>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculatePL/DataTypeConversionP'
 * '<S302>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculatePL/DataTypeConversionZ'
 * '<S303>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculatePL/Ground'
 * '<S304>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CalculateYhat/Ground'
 * '<S305>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CovarianceOutputConfigurator/decideOutput'
 * '<S306>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S307>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/Observer/MeasurementUpdate'
 * '<S308>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/ReducedQRN/Ground'
 * '<S309>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/KalmanFilter_altitude/UseCurrentEstimator/Enabled Subsystem'
 * '<S310>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/OutlierHandling/check for min altitude'
 * '<S311>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/OutlierHandling/currentEstimateVeryOffFromPressure'
 * '<S312>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/OutlierHandling/currentStateVeryOffsonarflt'
 * '<S313>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/OutlierHandling/outlierJump'
 * '<S314>' : 'flightControlSystem/Control System/State Estimator/Altitude Estimator/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S315>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Compare To Constant'
 * '<S316>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Compare To Constant1'
 * '<S317>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman'
 * '<S318>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman'
 * '<S319>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Yaw_integrator'
 * '<S320>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/norm(accelerometer)'
 * '<S321>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter'
 * '<S322>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculatePL'
 * '<S323>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculateYhat'
 * '<S324>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CovarianceOutputConfigurator'
 * '<S325>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionA'
 * '<S326>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionB'
 * '<S327>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionC'
 * '<S328>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionD'
 * '<S329>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionG'
 * '<S330>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionH'
 * '<S331>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionN'
 * '<S332>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionP'
 * '<S333>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionP0'
 * '<S334>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionQ'
 * '<S335>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionR'
 * '<S336>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionReset'
 * '<S337>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionX'
 * '<S338>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionX0'
 * '<S339>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/DataTypeConversionu'
 * '<S340>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/MemoryP'
 * '<S341>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/Observer'
 * '<S342>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/ReducedQRN'
 * '<S343>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/Reset'
 * '<S344>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/Reshapeyhat'
 * '<S345>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/ScalarExpansionP0'
 * '<S346>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/ScalarExpansionQ'
 * '<S347>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/ScalarExpansionR'
 * '<S348>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/UseCurrentEstimator'
 * '<S349>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkA'
 * '<S350>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkB'
 * '<S351>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkC'
 * '<S352>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkD'
 * '<S353>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkEnable'
 * '<S354>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkG'
 * '<S355>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkH'
 * '<S356>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkN'
 * '<S357>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkP0'
 * '<S358>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkQ'
 * '<S359>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkR'
 * '<S360>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkReset'
 * '<S361>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checkX0'
 * '<S362>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checku'
 * '<S363>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/checky'
 * '<S364>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S365>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S366>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S367>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S368>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculatePL/Ground'
 * '<S369>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CalculateYhat/Ground'
 * '<S370>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S371>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S372>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/Observer/MeasurementUpdate'
 * '<S373>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/ReducedQRN/Ground'
 * '<S374>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Pitch_Kalman/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S375>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter'
 * '<S376>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculatePL'
 * '<S377>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculateYhat'
 * '<S378>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CovarianceOutputConfigurator'
 * '<S379>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionA'
 * '<S380>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionB'
 * '<S381>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionC'
 * '<S382>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionD'
 * '<S383>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionG'
 * '<S384>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionH'
 * '<S385>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionN'
 * '<S386>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionP'
 * '<S387>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionP0'
 * '<S388>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionQ'
 * '<S389>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionR'
 * '<S390>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionReset'
 * '<S391>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionX'
 * '<S392>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionX0'
 * '<S393>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/DataTypeConversionu'
 * '<S394>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/MemoryP'
 * '<S395>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/Observer'
 * '<S396>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/ReducedQRN'
 * '<S397>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/Reset'
 * '<S398>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/Reshapeyhat'
 * '<S399>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/ScalarExpansionP0'
 * '<S400>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/ScalarExpansionQ'
 * '<S401>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/ScalarExpansionR'
 * '<S402>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/UseCurrentEstimator'
 * '<S403>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkA'
 * '<S404>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkB'
 * '<S405>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkC'
 * '<S406>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkD'
 * '<S407>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkEnable'
 * '<S408>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkG'
 * '<S409>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkH'
 * '<S410>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkN'
 * '<S411>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkP0'
 * '<S412>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkQ'
 * '<S413>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkR'
 * '<S414>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkReset'
 * '<S415>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checkX0'
 * '<S416>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checku'
 * '<S417>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/checky'
 * '<S418>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S419>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S420>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S421>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S422>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculatePL/Ground'
 * '<S423>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CalculateYhat/Ground'
 * '<S424>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S425>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S426>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/Observer/MeasurementUpdate'
 * '<S427>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/ReducedQRN/Ground'
 * '<S428>' : 'flightControlSystem/Control System/State Estimator/Attitude Estimator/Roll_Kalman/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S429>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/Temperature Compensation'
 * '<S430>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/sensordata_group'
 * '<S431>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Compare To Constant'
 * '<S432>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Counter Free-Running'
 * '<S433>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Triggered Subsystem'
 * '<S434>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Counter Free-Running/Increment Real World'
 * '<S435>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/Temperature Compensation/Counter Free-Running/Wrap To Zero'
 * '<S436>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity'
 * '<S437>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorXYPosition'
 * '<S438>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling'
 * '<S439>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/Angular velocity compensation for optical flow'
 * '<S440>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling'
 * '<S441>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy'
 * '<S442>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/xy velocity w//o angular velocity compensation'
 * '<S443>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
 * '<S444>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
 * '<S445>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
 * '<S446>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
 * '<S447>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S448>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/DiscreteDerivative'
 * '<S449>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxdw1'
 * '<S450>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxdw2'
 * '<S451>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxp'
 * '<S452>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxp2'
 * '<S453>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxq'
 * '<S454>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxq2'
 * '<S455>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw1'
 * '<S456>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw2'
 * '<S457>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw3'
 * '<S458>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/maxw4'
 * '<S459>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/DataHandling/minHeightforOF'
 * '<S460>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL'
 * '<S461>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat'
 * '<S462>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator'
 * '<S463>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionA'
 * '<S464>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionB'
 * '<S465>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionC'
 * '<S466>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionD'
 * '<S467>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionG'
 * '<S468>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionH'
 * '<S469>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionN'
 * '<S470>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP'
 * '<S471>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
 * '<S472>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
 * '<S473>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionR'
 * '<S474>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionReset'
 * '<S475>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX'
 * '<S476>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
 * '<S477>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionu'
 * '<S478>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/MemoryP'
 * '<S479>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Observer'
 * '<S480>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN'
 * '<S481>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Reset'
 * '<S482>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Reshapeyhat'
 * '<S483>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
 * '<S484>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
 * '<S485>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionR'
 * '<S486>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
 * '<S487>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkA'
 * '<S488>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkB'
 * '<S489>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkC'
 * '<S490>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkD'
 * '<S491>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkEnable'
 * '<S492>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkG'
 * '<S493>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkH'
 * '<S494>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkN'
 * '<S495>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkP0'
 * '<S496>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkQ'
 * '<S497>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkR'
 * '<S498>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkReset'
 * '<S499>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checkX0'
 * '<S500>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checku'
 * '<S501>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/checky'
 * '<S502>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
 * '<S503>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
 * '<S504>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
 * '<S505>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
 * '<S506>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/Ground'
 * '<S507>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat/Ground'
 * '<S508>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput'
 * '<S509>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S510>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
 * '<S511>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN/Ground'
 * '<S512>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
 * '<S513>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/xy velocity w//o angular velocity compensation/Compare To Constant'
 * '<S514>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/xy velocity w//o angular velocity compensation/Counter Free-Running'
 * '<S515>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/xy velocity w//o angular velocity compensation/Counter Free-Running/Increment Real World'
 * '<S516>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorVelocity/xy velocity w//o angular velocity compensation/Counter Free-Running/Wrap To Zero'
 * '<S517>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
 * '<S518>' : 'flightControlSystem/Control System/State Estimator/XY Position Estimator/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S519>' : 'flightControlSystem/Image Processing System/MATLAB Function'
 * '<S520>' : 'flightControlSystem/Image Processing System/MATLAB Function2'
 * '<S521>' : 'flightControlSystem/Image Processing System/MATLAB Function4'
 * '<S522>' : 'flightControlSystem/Image Processing System/Main control'
 * '<S523>' : 'flightControlSystem/Image Processing System/center_vector_x'
 * '<S524>' : 'flightControlSystem/Image Processing System/center_vector_y'
 * '<S525>' : 'flightControlSystem/Image Processing System/image preprocess'
 * '<S526>' : 'flightControlSystem/Image Processing System/opposite_way'
 * '<S527>' : 'flightControlSystem/Image Processing System/speed_calculator'
 * '<S528>' : 'flightControlSystem/Image Processing System/write_or_not'
 * '<S529>' : 'flightControlSystem/Image Processing System/image preprocess/MATLAB Function'
 */
#endif                                 /* flightControlSystem_h_ */
