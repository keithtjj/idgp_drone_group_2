/*
 * flightControlSystem.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 9.61
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sun Nov 16 18:28:41 2025
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
#include <string.h>
#include "zero_crossing_types.h"
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S5>/Chart' */
#define flightControlSystem_IN_Circle  ((uint8_T)1U)
#define flightControlSystem_IN_Circle1 ((uint8_T)2U)
#define flightControlSystem_IN_Cruise_height ((uint8_T)3U)
#define flightControlSystem_IN_Drop_off ((uint8_T)4U)
#define flightControlSystem_IN_Hover   ((uint8_T)5U)
#define flightControlSystem_IN_Line_track ((uint8_T)6U)
#define flightControlSystem_IN_Line_track1 ((uint8_T)7U)
#define flightControlSystem_IN_Line_track2 ((uint8_T)8U)
#define flightControlSystem_IN_Line_track3 ((uint8_T)9U)
#define flightControlSystem_IN_Lower   ((uint8_T)10U)
#define flightControlSystem_IN_Lower_Hover ((uint8_T)11U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_land1   ((uint8_T)12U)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<Root>/Control System' */
uint8_T flag_outport;                  /* '<Root>/Control System' */

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
static void rate_monotonic_scheduler(void);

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
  real32_T rtb_Sum;

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
    rtb_Sum = rtu_yk - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1[1])
                        + rtu_Dk * rtu_uk);

    /* Product: '<S372>/Product3' */
    localB->Product3[0] = rtu_Lk[0] * rtb_Sum;
    localB->Product3[1] = rtu_Lk[1] * rtb_Sum;
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

  /* InitializeConditions for Delay: '<S321>/MemoryX' */
  localDW->icLoad_p = true;

  /* InitializeConditions for DiscreteFir: '<S253>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = localP->FIR_IMUaccel_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFir: '<S253>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S375>/MemoryX' */
  localDW->icLoad_k = true;

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
  localDW->Output_DSTATE = localP->Output_InitialCondition;

  /* InitializeConditions for Delay: '<S441>/MemoryX' */
  localDW->icLoad_o = true;

  /* InitializeConditions for Sum: '<S515>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S514>/Output'
   */
  localDW->Output_DSTATE_n = localP->Output_InitialCondition_f;

  /* InitializeConditions for DiscreteFilter: '<S440>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = localP->IIRgyroz_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S440>/IIRgyroz' */

  /* InitializeConditions for Sum: '<S15>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S14>/Output'
   */
  localDW->Output_DSTATE_a = localP->Output_InitialCondition_fi;

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

  /* SystemInitialize for Merge: '<S4>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Chart: '<S5>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localB->z = 0.0;
  localB->x = 0.0;
  localB->y = 0.0;
  localB->motor_gain = 0.0;
  localDW->is_active_c3_flightControlSystem = 0U;
  localDW->is_c3_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;

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

  /* SystemInitialize for Enabled SubSystem: '<S341>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_n,
    &localP->MeasurementUpdate_n);

  /* End of SystemInitialize for SubSystem: '<S341>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S348>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_d,
    &localP->EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S348>/Enabled Subsystem' */

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
  (DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* Start for Enabled SubSystem: '<S283>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE_i = false;

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

  /* Start for Enabled SubSystem: '<S479>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S479>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S395>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Start(&localDW->MeasurementUpdate_j);

  /* End of Start for SubSystem: '<S395>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S341>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Start(&localDW->MeasurementUpdate_n);

  /* End of Start for SubSystem: '<S341>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S277>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE_h = false;

  /* End of Start for SubSystem: '<S277>/MeasurementUpdate' */

  /* Start for MATLABSystem: '<S5>/Grabber' */
  localDW->objisempty = true;
}

/* Output and update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds, const
  SensorsBus *rtu_Sensors, const real_T rtu_VisionbasedData[6],
  B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW,
  P_ControlSystem_flightControlSystem_T *localP,
  ZCE_ControlSystem_flightControlSystem_T *localZCE)
{
  real32_T MemoryX_DSTATE_l;
  real32_T MemoryX_DSTATE_l_0;
  real32_T numAccum;
  real32_T rtb_SaturationThrust1_tmp;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_VectorConcatenate_tmp_1;
  real32_T rtb_VectorConcatenate_tmp_2;
  real32_T rtb_VectorConcatenate_tmp_3;
  real32_T rtb_sincos_o1_b_tmp;
  real32_T rtb_sincos_o2_idx_0;
  int8_T tmp_0;
  int8_T tmp_1;
  uint8_T tmp;
  boolean_T rtb_Compare_fc;
  boolean_T rtb_Compare_ls;
  boolean_T rtb_GreaterThan;

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

  /* Gain: '<S251>/invertzaxisGain' */
  localB->invertzaxisGain = (real_T)localP->invertzaxisGain_Gain *
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S253>/Data Type Conversion' */
  for (localB->i = 0; localB->i < 8; localB->i++) {
    localB->DataTypeConversion_g[localB->i] = rtu_Sensors->
      SensorCalibration[localB->i];
  }

  /* End of DataTypeConversion: '<S253>/Data Type Conversion' */

  /* Sum: '<S253>/Sum2' */
  localB->DiscreteTimeIntegrator_k5 =
    rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
    localB->DataTypeConversion_g[6];

  /* DiscreteFilter: '<S256>/pressureFilter_IIR' incorporates:
   *  Gain: '<S251>/prsToAltGain'
   */
  localB->DiscreteTimeIntegrator_k5 = (((localP->prsToAltGain_Gain *
    localB->DiscreteTimeIntegrator_k5 - localDW->pressureFilter_IIR_states[0] *
    localP->pressureFilter_IIR_DenCoef[1]) - localDW->pressureFilter_IIR_states
    [1] * localP->pressureFilter_IIR_DenCoef[2]) -
    localDW->pressureFilter_IIR_states[2] * localP->pressureFilter_IIR_DenCoef[3])
    / localP->pressureFilter_IIR_DenCoef[0];
  numAccum = ((localP->pressureFilter_IIR_NumCoef[0] *
               localB->DiscreteTimeIntegrator_k5 +
               localDW->pressureFilter_IIR_states[0] *
               localP->pressureFilter_IIR_NumCoef[1]) +
              localDW->pressureFilter_IIR_states[1] *
              localP->pressureFilter_IIR_NumCoef[2]) +
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
    ((!(fabs(numAccum - localDW->Delay2_DSTATE) >=
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
    localDW->EnabledSubsystem_MODE_i = true;

    /* Sum: '<S309>/Add1' incorporates:
     *  Constant: '<S255>/C'
     *  Delay: '<S255>/MemoryX'
     *  Product: '<S309>/Product'
     *  Reshape: '<S255>/Reshapey'
     */
    localB->u_h = localB->invertzaxisGain - (localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]);

    /* Product: '<S309>/Product2' incorporates:
     *  Constant: '<S259>/KalmanGainM'
     *  DataTypeConversion: '<S300>/Conversion'
     */
    localB->Product2[0] = localP->KalmanGainM_Value[0] * localB->u_h;
    localB->Product2[1] = localP->KalmanGainM_Value[1] * localB->u_h;
  } else if (localDW->EnabledSubsystem_MODE_i) {
    /* Disable for Product: '<S309>/Product2' incorporates:
     *  Outport: '<S309>/deltax'
     */
    localB->Product2[0] = localP->deltax_Y0;
    localB->Product2[1] = localP->deltax_Y0;
    localDW->EnabledSubsystem_MODE_i = false;
  }

  /* End of Outputs for SubSystem: '<S283>/Enabled Subsystem' */

  /* Reshape: '<S255>/Reshapexhat' incorporates:
   *  Delay: '<S255>/MemoryX'
   *  Sum: '<S283>/Add'
   */
  localDW->Delay2_DSTATE = localB->Product2[0] + localDW->MemoryX_DSTATE[0];

  /* Sum: '<S283>/Add' incorporates:
   *  Delay: '<S255>/MemoryX'
   */
  localB->rtb_Add_a_idx_1 = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* Delay: '<S321>/MemoryX' incorporates:
   *  Constant: '<S321>/X0'
   *  Reshape: '<S321>/ReshapeX0'
   */
  if (localDW->icLoad_p) {
    localDW->MemoryX_DSTATE_g[0] = localP->X0_Value_i[0];
    localDW->MemoryX_DSTATE_g[1] = localP->X0_Value_i[1];
  }

  /* Bias: '<S253>/Assuming that the  preflight calibration was done at level orientation' */
  for (localB->i = 0; localB->i < 6; localB->i++) {
    localB->Sum1_p[localB->i] = localB->DataTypeConversion_g[localB->i] +
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
  for (localB->j = 0; localB->j < 6; localB->j++) {
    /* Gain: '<S253>/inverseIMU_gain' incorporates:
     *  Sum: '<S253>/Sum1'
     */
    localB->inverseIMU_gain[localB->j] *= localP->inverseIMU_gain_Gain[localB->j];
  }

  /* DiscreteFir: '<S253>/FIR_IMUaccel' */
  localB->Abs = localB->inverseIMU_gain[0] * localP->FIR_IMUaccel_Coefficients[0];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[0] = localB->Abs;

  /* Math: '<S320>/Math Function' incorporates:
   *  Constant: '<S320>/Constant'
   *  DiscreteFir: '<S253>/FIR_IMUaccel'
   */
  rtb_VectorConcatenate_tmp = (real32_T)floor(localP->Constant_Value_h);
  if ((localB->Abs < 0.0F) && (localP->Constant_Value_h >
       rtb_VectorConcatenate_tmp)) {
    localB->rtb_Subtract_p_idx_0 = -rt_powf_snf(-localB->Abs,
      localP->Constant_Value_h);
  } else {
    localB->rtb_Subtract_p_idx_0 = rt_powf_snf(localB->Abs,
      localP->Constant_Value_h);
  }

  /* DiscreteFir: '<S253>/FIR_IMUaccel' */
  localB->Abs = localP->FIR_IMUaccel_Coefficients[0] * localB->inverseIMU_gain[1];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 5] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[1] = localB->Abs;

  /* Math: '<S320>/Math Function' incorporates:
   *  Constant: '<S320>/Constant'
   *  DiscreteFir: '<S253>/FIR_IMUaccel'
   */
  if ((localB->Abs < 0.0F) && (localP->Constant_Value_h >
       rtb_VectorConcatenate_tmp)) {
    localB->rtb_Subtract_p_idx_1 = -rt_powf_snf(-localB->Abs,
      localP->Constant_Value_h);
  } else {
    localB->rtb_Subtract_p_idx_1 = rt_powf_snf(localB->Abs,
      localP->Constant_Value_h);
  }

  /* DiscreteFir: '<S253>/FIR_IMUaccel' */
  localB->Abs = localP->FIR_IMUaccel_Coefficients[0] * localB->inverseIMU_gain[2];
  localB->i = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    localB->Abs += localDW->FIR_IMUaccel_states[localB->j + 10] *
      localP->FIR_IMUaccel_Coefficients[localB->i];
    localB->i++;
    localB->j++;
  }

  localB->FIR_IMUaccel[2] = localB->Abs;

  /* Gain: '<S317>/Gain2' */
  localB->Add_i = localP->Gain2_Gain_p * localB->FIR_IMUaccel[0];

  /* Trigonometry: '<S317>/Trigonometric Function1' */
  if (localB->Add_i > 1.0F) {
    localB->Add_i = 1.0F;
  } else if (localB->Add_i < -1.0F) {
    localB->Add_i = -1.0F;
  }

  /* Trigonometry: '<S317>/Trigonometric Function1' */
  localB->TrigonometricFunction1 = (real32_T)asin(localB->Add_i);

  /* Math: '<S320>/Math Function' incorporates:
   *  Constant: '<S320>/Constant'
   *  DiscreteFir: '<S253>/FIR_IMUaccel'
   */
  if ((localB->Abs < 0.0F) && (localP->Constant_Value_h >
       rtb_VectorConcatenate_tmp)) {
    rtb_VectorConcatenate_tmp = -rt_powf_snf(-localB->Abs,
      localP->Constant_Value_h);
  } else {
    rtb_VectorConcatenate_tmp = rt_powf_snf(localB->Abs,
      localP->Constant_Value_h);
  }

  /* Sqrt: '<S320>/Sqrt' incorporates:
   *  Math: '<S320>/Math Function'
   *  Sum: '<S320>/Sum of Elements'
   */
  localB->Add_i = (real32_T)sqrt((localB->rtb_Subtract_p_idx_0 +
    localB->rtb_Subtract_p_idx_1) + rtb_VectorConcatenate_tmp);

  /* Logic: '<S252>/Logical Operator' incorporates:
   *  Constant: '<S315>/Constant'
   *  Constant: '<S316>/Constant'
   *  RelationalOperator: '<S315>/Compare'
   *  RelationalOperator: '<S316>/Compare'
   */
  localB->LogicalOperator = (int16_T)((localB->Add_i >
    localP->CompareToConstant_const) && (localB->Add_i <
    localP->CompareToConstant1_const));

  /* DataTypeConversion: '<S365>/Conversion' incorporates:
   *  Constant: '<S322>/KalmanGainM'
   */
  localB->Conversion_g[0] = (real32_T)localP->KalmanGainM_Value_l[0];
  localB->Conversion_g[1] = (real32_T)localP->KalmanGainM_Value_l[1];

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

  /* Delay: '<S375>/MemoryX' incorporates:
   *  Constant: '<S375>/X0'
   *  Reshape: '<S375>/ReshapeX0'
   */
  if (localDW->icLoad_k) {
    localDW->MemoryX_DSTATE_m[0] = localP->X0_Value_iy[0];
    localDW->MemoryX_DSTATE_m[1] = localP->X0_Value_iy[1];
  }

  /* Trigonometry: '<S318>/Trigonometric Function' incorporates:
   *  DiscreteFir: '<S253>/FIR_IMUaccel'
   *  Product: '<S318>/Divide'
   */
  localB->TrigonometricFunction = (real32_T)atan(localB->FIR_IMUaccel[1] /
    localB->Abs);

  /* DataTypeConversion: '<S419>/Conversion' incorporates:
   *  Constant: '<S376>/KalmanGainM'
   */
  localB->Conversion_i[0] = (real32_T)localP->KalmanGainM_Value_a[0];
  localB->Conversion_i[1] = (real32_T)localP->KalmanGainM_Value_a[1];

  /* Outputs for Enabled SubSystem: '<S402>/Enabled Subsystem' */
  /* DataTypeConversion: '<S375>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S375>/C'
   *  Delay: '<S375>/MemoryX'
   *  Reshape: '<S375>/Reshapey'
   */
  flightControlSystem_EnabledSubsystem((localB->LogicalOperator != 0),
    localB->Conversion_i, localP->C_Value_i, localB->TrigonometricFunction,
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

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localB->Add_i = (localB->inverseIMU_gain[3] - localP->LPFFcutoff40Hz1_DenCoef
                   [1] * localDW->LPFFcutoff40Hz1_states) /
    localP->LPFFcutoff40Hz1_DenCoef[0];

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localB->p = localP->LPFFcutoff40Hz1_NumCoef[0] * localB->Add_i +
    localP->LPFFcutoff40Hz1_NumCoef[1] * localDW->LPFFcutoff40Hz1_states;

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localB->LPFFcutoff40Hz_tmp = (localB->inverseIMU_gain[4] -
    localP->LPFFcutoff40Hz_DenCoef[1] * localDW->LPFFcutoff40Hz_states) /
    localP->LPFFcutoff40Hz_DenCoef[0];

  /* DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localB->q = localP->LPFFcutoff40Hz_NumCoef[0] * localB->LPFFcutoff40Hz_tmp +
    localP->LPFFcutoff40Hz_NumCoef[1] * localDW->LPFFcutoff40Hz_states;

  /* DiscreteFilter: '<S253>/IIR_IMUgyro_r' */
  localB->Gain_m = localB->inverseIMU_gain[5];
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->Gain_m -= localP->IIR_IMUgyro_r_DenCoef[localB->j + 1] *
      localDW->IIR_IMUgyro_r_states[localB->j];
  }

  localB->IIR_IMUgyro_r_tmp = localB->Gain_m / localP->IIR_IMUgyro_r_DenCoef[0];
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
  rtb_Compare_ls = (localDW->Output_DSTATE == localP->CompareToConstant_const_l);

  /* Outputs for Triggered SubSystem: '<S429>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S433>/Trigger'
   */
  if (((localZCE->TriggeredSubsystem_Trig_ZCE == POS_ZCSIG) != (int32_T)
       rtb_Compare_ls) && (localZCE->TriggeredSubsystem_Trig_ZCE !=
       UNINITIALIZED_ZCSIG)) {
    /* SignalConversion generated from: '<S433>/In1' */
    localB->In1 = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE = rtb_Compare_ls;

  /* End of Outputs for SubSystem: '<S429>/Triggered Subsystem' */

  /* ManualSwitch: '<S429>/Disable temperature compensation' incorporates:
   *  Constant: '<S429>/Constant'
   *  Gain: '<S429>/Gain'
   */
  if (localP->Disabletemperaturecompensation_CurrentSetting == 1) {
    /* Sum: '<S429>/Subtract' */
    localB->Subtract = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature -
      localB->In1;
    localB->u_h = localP->Gain_Gain_k * localB->Subtract;
  } else {
    localB->u_h = localP->Constant_Value;
  }

  /* End of ManualSwitch: '<S429>/Disable temperature compensation' */

  /* Sum: '<S429>/Subtract1' incorporates:
   *  DataTypeConversion: '<S429>/Data Type Conversion1'
   *  DiscreteFilter: '<S253>/IIR_IMUgyro_r'
   */
  localB->Subtract = localB->numAccum - (real32_T)localB->u_h;

  /* Sum: '<S252>/Subtract' incorporates:
   *  Constant: '<S319>/Constant'
   *  Delay: '<S321>/MemoryX'
   *  Delay: '<S375>/MemoryX'
   *  Sum: '<S348>/Add'
   *  Sum: '<S402>/Add'
   */
  localB->rtb_Subtract_p_idx_0 = localB->p -
    (localB->EnabledSubsystem_n.Product2[1] + localDW->MemoryX_DSTATE_m[1]);
  localB->rtb_Subtract_p_idx_1 = localB->q -
    (localB->EnabledSubsystem_d.Product2[1] + localDW->MemoryX_DSTATE_g[1]);
  localB->rtb_Subtract_p_idx_2 = localB->Subtract - localP->Constant_Value_j;

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

  /* Switch: '<S442>/Switch' incorporates:
   *  Constant: '<S513>/Constant'
   *  Gain: '<S442>/opticalFlowErrorCorrect'
   *  RelationalOperator: '<S513>/Compare'
   *  UnitDelay: '<S514>/Output'
   */
  if (localDW->Output_DSTATE_n < localP->CompareToConstant_const_h) {
    localB->u_l[0] = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    localB->u_l[1] = rtu_Sensors->VisionSensors.opticalFlow_data[1];
    localB->u_l[2] = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    /* Gain: '<S442>/Gain' incorporates:
     *  DataTypeConversion: '<S251>/Data Type Conversion'
     *  Reshape: '<S255>/Reshapexhat'
     */
    localB->Gain_m = localP->Gain_Gain_p * (real32_T)localDW->Delay2_DSTATE;

    /* Product: '<S442>/ ' */
    localB->SaturationThrust1 = rtu_Sensors->VisionSensors.opticalFlow_data[0] *
      localB->Gain_m;
    localB->u_l[0] = localP->opticalFlowErrorCorrect_Gain *
      localB->SaturationThrust1;

    /* Product: '<S442>/ ' incorporates:
     *  Gain: '<S442>/opticalFlowErrorCorrect'
     */
    localB->SaturationThrust1 = rtu_Sensors->VisionSensors.opticalFlow_data[1] *
      localB->Gain_m;
    localB->u_l[1] = localP->opticalFlowErrorCorrect_Gain *
      localB->SaturationThrust1;

    /* Product: '<S442>/ ' incorporates:
     *  Gain: '<S442>/opticalFlowErrorCorrect'
     */
    localB->SaturationThrust1 = rtu_Sensors->VisionSensors.opticalFlow_data[2] *
      localB->Gain_m;
    localB->u_l[2] = localP->opticalFlowErrorCorrect_Gain *
      localB->SaturationThrust1;
  }

  /* End of Switch: '<S442>/Switch' */

  /* Abs: '<S439>/Abs' incorporates:
   *  DataTypeConversion: '<S251>/Data Type Conversion'
   *  Reshape: '<S255>/Reshapexhat'
   */
  localB->SaturationThrust1 = (real32_T)fabs((real32_T)localDW->Delay2_DSTATE);

  /* DataTypeConversion: '<S439>/Data Type Conversion' incorporates:
   *  Gain: '<S439>/Gain1'
   *  Product: '<S439>/prod'
   */
  localB->Add_k[0] = localB->SaturationThrust1 * localB->rtb_Subtract_p_idx_1 *
    localP->Gain1_Gain_n;
  localB->Add_k[1] = localB->SaturationThrust1 * localB->rtb_Subtract_p_idx_0;

  /* SignalConversion generated from: '<S440>/IIRgyroz' */
  localB->Conversion_g[0] = localB->p;
  localB->Conversion_g[1] = localB->q;
  for (localB->i = 0; localB->i < 2; localB->i++) {
    /* Sum: '<S436>/angular velocity compensation' */
    localB->SaturationThrust1 = localB->u_l[localB->i];

    /* Sum: '<S436>/angular velocity compensation' */
    localB->angularvelocitycompensation[localB->i] = localB->SaturationThrust1 +
      localB->Add_k[localB->i];

    /* DiscreteFilter: '<S440>/IIRgyroz' */
    localB->memOffset = localB->i * 5;
    localB->Gain_m = localB->Conversion_g[localB->i];
    for (localB->j = 0; localB->j < 5; localB->j++) {
      localB->Gain_m -= localP->IIRgyroz_DenCoef[localB->j + 1] *
        localDW->IIRgyroz_states[localB->memOffset + localB->j];
    }

    localB->Gain_m /= localP->IIRgyroz_DenCoef[0];
    localDW->IIRgyroz_tmp[localB->i] = localB->Gain_m;
    localB->numAccum = localP->IIRgyroz_NumCoef[0] * localB->Gain_m;
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
    localB->Gain_m = localB->numAccum * localP->TSamp_WtEt;
    localB->Conversion_i[localB->i] = localB->Gain_m;

    /* Sum: '<S448>/Diff' incorporates:
     *  UnitDelay: '<S448>/UD'
     */
    localDW->UD_DSTATE[localB->i] = localB->Gain_m - localDW->UD_DSTATE
      [localB->i];

    /* Sum: '<S440>/Add' incorporates:
     *  Delay: '<S436>/Delay'
     */
    localB->Add_k[localB->i] = localB->SaturationThrust1 - localDW->
      Delay_DSTATE[localB->i];
  }

  /* Abs: '<S440>/Abs' incorporates:
   *  Abs: '<S440>/Abs4'
   */
  localB->SaturationThrust1 = (real32_T)fabs(localB->p);

  /* Abs: '<S440>/Abs1' incorporates:
   *  Abs: '<S440>/Abs5'
   */
  localB->Gain_m = (real32_T)fabs(localB->q);

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
   *  DataTypeConversion: '<S251>/Data Type Conversion'
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
   *  Reshape: '<S255>/Reshapexhat'
   */
  localB->LogicalOperator3 = (((((real32_T)fabs(localB->DataTypeConversion3[1]) <=
    localP->maxp_const) && ((real32_T)fabs(localB->DataTypeConversion3[2]) <=
    localP->maxq_const) && (localB->SaturationThrust1 <= localP->maxw1_const) &&
    (localB->Gain_m <= localP->maxw2_const) && ((real32_T)fabs
    (localDW->UD_DSTATE[0]) <= localP->maxdw1_const) && ((real32_T)fabs
    (localDW->UD_DSTATE[1]) <= localP->maxdw2_const)) ||
    ((localB->SaturationThrust1 <= localP->maxp2_const) && (localB->Gain_m <=
    localP->maxq2_const))) && ((real32_T)fabs(localB->Add_k[0]) <=
    localP->maxw3_const) && ((real32_T)fabs(localB->Add_k[1]) <=
    localP->maxw4_const) && ((real32_T)localDW->Delay2_DSTATE <=
    localP->minHeightforOF_const));

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
    localB->Gain_m = localDW->MemoryX_DSTATE_l[1];
    MemoryX_DSTATE_l = localDW->MemoryX_DSTATE_l[0];
    MemoryX_DSTATE_l_0 = localDW->MemoryX_DSTATE_l[2];
    localB->numAccum = localDW->MemoryX_DSTATE_l[3];

    /* Sum: '<S512>/Add1' incorporates:
     *  Constant: '<S441>/C'
     *  Delay: '<S441>/MemoryX'
     *  Product: '<S512>/Product'
     *  Reshape: '<S441>/Reshapey'
     */
    for (localB->j = 0; localB->j < 2; localB->j++) {
      localB->Add_k[localB->j] = localB->angularvelocitycompensation[localB->j]
        - (((localP->C_Value_i2[localB->j + 2] * localB->Gain_m +
             localP->C_Value_i2[localB->j] * MemoryX_DSTATE_l) +
            localP->C_Value_i2[localB->j + 4] * MemoryX_DSTATE_l_0) +
           localP->C_Value_i2[localB->j + 6] * localB->numAccum);
    }

    /* End of Sum: '<S512>/Add1' */

    /* Product: '<S512>/Product2' incorporates:
     *  Constant: '<S460>/KalmanGainM'
     *  DataTypeConversion: '<S503>/Conversion'
     */
    rtb_VectorConcatenate_tmp = localB->Add_k[1];
    localB->Gain_m = localB->Add_k[0];
    for (localB->j = 0; localB->j < 4; localB->j++) {
      /* Product: '<S512>/Product2' incorporates:
       *  Constant: '<S460>/KalmanGainM'
       *  DataTypeConversion: '<S503>/Conversion'
       */
      localB->Product2_k[localB->j] = (real32_T)localP->
        KalmanGainM_Value_i[localB->j + 4] * rtb_VectorConcatenate_tmp +
        (real32_T)localP->KalmanGainM_Value_i[localB->j] * localB->Gain_m;
    }
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

  /* Sum: '<S486>/Add' incorporates:
   *  Delay: '<S441>/MemoryX'
   */
  localB->Add_o[0] = localB->Product2_k[0] + localDW->MemoryX_DSTATE_l[0];
  localB->Add_o[1] = localB->Product2_k[1] + localDW->MemoryX_DSTATE_l[1];
  localB->Add_o[2] = localB->Product2_k[2] + localDW->MemoryX_DSTATE_l[2];
  localB->Add_o[3] = localB->Product2_k[3] + localDW->MemoryX_DSTATE_l[3];

  /* Trigonometry: '<S257>/sincos' incorporates:
   *  DiscreteIntegrator: '<S319>/Discrete-Time Integrator'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   *  Trigonometry: '<S517>/sincos'
   */
  rtb_SaturationThrust1_tmp = (real32_T)sin
    (localDW->DiscreteTimeIntegrator_DSTATE);
  rtb_sincos_o1_b_tmp = (real32_T)cos(localDW->DiscreteTimeIntegrator_DSTATE);
  localB->Gain_m = (real32_T)sin(localB->DataTypeConversion3[1]);
  MemoryX_DSTATE_l = (real32_T)cos(localB->DataTypeConversion3[1]);
  MemoryX_DSTATE_l_0 = (real32_T)sin(localB->DataTypeConversion3[2]);
  localB->numAccum = (real32_T)cos(localB->DataTypeConversion3[2]);

  /* Fcn: '<S257>/Fcn11' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[0] = rtb_sincos_o1_b_tmp * MemoryX_DSTATE_l;

  /* Fcn: '<S257>/Fcn21' incorporates:
   *  Fcn: '<S257>/Fcn22'
   *  Fcn: '<S517>/Fcn21'
   *  Fcn: '<S517>/Fcn22'
   *  Trigonometry: '<S257>/sincos'
   */
  rtb_VectorConcatenate_tmp = localB->Gain_m * MemoryX_DSTATE_l_0;
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o1_b_tmp
    - rtb_SaturationThrust1_tmp * localB->numAccum;

  /* Fcn: '<S257>/Fcn31' incorporates:
   *  Fcn: '<S257>/Fcn32'
   *  Fcn: '<S517>/Fcn31'
   *  Fcn: '<S517>/Fcn32'
   *  Trigonometry: '<S257>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = localB->Gain_m * localB->numAccum;
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o1_b_tmp + rtb_SaturationThrust1_tmp * MemoryX_DSTATE_l_0;

  /* Fcn: '<S257>/Fcn12' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[3] = rtb_SaturationThrust1_tmp * MemoryX_DSTATE_l;

  /* Fcn: '<S257>/Fcn22' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
    rtb_SaturationThrust1_tmp + rtb_sincos_o1_b_tmp * localB->numAccum;

  /* Fcn: '<S257>/Fcn32' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_SaturationThrust1_tmp - rtb_sincos_o1_b_tmp * MemoryX_DSTATE_l_0;

  /* Fcn: '<S257>/Fcn13' incorporates:
   *  Trigonometry: '<S257>/sincos'
   */
  localB->VectorConcatenate[6] = -localB->Gain_m;

  /* Fcn: '<S257>/Fcn23' incorporates:
   *  Fcn: '<S517>/Fcn23'
   *  Trigonometry: '<S257>/sincos'
   */
  rtb_VectorConcatenate_tmp_2 = MemoryX_DSTATE_l * MemoryX_DSTATE_l_0;
  localB->VectorConcatenate[7] = rtb_VectorConcatenate_tmp_2;

  /* Fcn: '<S257>/Fcn33' incorporates:
   *  Fcn: '<S517>/Fcn33'
   *  Trigonometry: '<S257>/sincos'
   */
  rtb_VectorConcatenate_tmp_3 = MemoryX_DSTATE_l * localB->numAccum;
  localB->VectorConcatenate[8] = rtb_VectorConcatenate_tmp_3;

  /* DataTypeConversion: '<S251>/Data Type Conversion1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localB->u_h = localDW->Delay1_DSTATE[0];
  localB->unnamed_idx_1_tmp = localDW->Delay1_DSTATE[1];

  /* Product: '<S251>/Product1' incorporates:
   *  DataTypeConversion: '<S251>/Data Type Conversion1'
   *  Reshape: '<S255>/Reshapexhat'
   *  Reshape: '<S314>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S251>/Product1'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->SaturationThrust1 = localB->VectorConcatenate[localB->j + 3];
    rtb_sincos_o2_idx_0 = localB->VectorConcatenate[localB->j];
    localB->rtb_VectorConcatenate_tmp = localB->VectorConcatenate[localB->j + 6]
      * localB->rtb_Add_a_idx_1;
    localB->rtb_VectorConcatenate_m[localB->j] = (localB->SaturationThrust1 *
      localB->unnamed_idx_1_tmp + rtb_sincos_o2_idx_0 * localB->u_h) +
      localB->rtb_VectorConcatenate_tmp;
    localB->rtb_VectorConcatenate_c[localB->j] = (localB->SaturationThrust1 *
      localB->unnamed_idx_1_tmp + rtb_sincos_o2_idx_0 * localB->u_h) +
      localB->rtb_VectorConcatenate_tmp;
  }

  /* End of Product: '<S251>/Product1' */

  /* DataTypeConversion: '<S251>/Data Type Conversion2' */
  localB->SaturationThrust1 = (real32_T)localB->rtb_VectorConcatenate_m[2];

  /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
   *  DataTypeConversion: '<S251>/Data Type Conversion'
   *  DataTypeConversion: '<S251>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S319>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity'
   *  Reshape: '<S255>/Reshapexhat'
   *  Reshape: '<S441>/Reshapexhat'
   */
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localDW->SimplyIntegrateVelocity_DSTATE[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[2] = (real32_T)
    localDW->Delay2_DSTATE;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] =
    localDW->DiscreteTimeIntegrator_DSTATE;
  localB->TmpSignalConversionAtToWorkspaceInport1[4] =
    localB->DataTypeConversion3[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[5] =
    localB->DataTypeConversion3[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Add_o[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Add_o[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] = (real32_T)
    localB->rtb_VectorConcatenate_c[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[9] =
    localB->rtb_Subtract_p_idx_0;
  localB->TmpSignalConversionAtToWorkspaceInport1[10] =
    localB->rtb_Subtract_p_idx_1;
  localB->TmpSignalConversionAtToWorkspaceInport1[11] =
    localB->rtb_Subtract_p_idx_2;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspaceInport1[0]);
  }

  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* Math: '<S251>/Math Function' incorporates:
     *  Reshape: '<S314>/Reshape (9) to [3x3] column-major'
     */
    localB->MathFunction[3 * localB->j] = localB->VectorConcatenate[localB->j];
    localB->MathFunction[3 * localB->j + 1] = localB->VectorConcatenate
      [localB->j + 3];
    localB->MathFunction[3 * localB->j + 2] = localB->VectorConcatenate
      [localB->j + 6];

    /* Trigonometry: '<S444>/sincos' */
    rtb_sincos_o2_idx_0 = localB->DataTypeConversion3[localB->j];
    localB->sincos_o1_b[localB->j] = (real32_T)sin(rtb_sincos_o2_idx_0);
    localB->DataTypeConversion_b[localB->j] = (real32_T)cos(rtb_sincos_o2_idx_0);
  }

  /* Fcn: '<S444>/Fcn11' */
  localB->VectorConcatenate[0] = localB->DataTypeConversion_b[0] *
    localB->DataTypeConversion_b[1];

  /* Fcn: '<S444>/Fcn21' incorporates:
   *  Fcn: '<S444>/Fcn22'
   */
  rtb_sincos_o2_idx_0 = localB->sincos_o1_b[1] * localB->sincos_o1_b[2];
  localB->VectorConcatenate[1] = rtb_sincos_o2_idx_0 *
    localB->DataTypeConversion_b[0] - localB->sincos_o1_b[0] *
    localB->DataTypeConversion_b[2];

  /* Fcn: '<S444>/Fcn31' incorporates:
   *  Fcn: '<S444>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_1 = localB->sincos_o1_b[1] *
    localB->DataTypeConversion_b[2];
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_1 *
    localB->DataTypeConversion_b[0] + localB->sincos_o1_b[0] *
    localB->sincos_o1_b[2];

  /* Fcn: '<S444>/Fcn12' */
  localB->VectorConcatenate[3] = localB->sincos_o1_b[0] *
    localB->DataTypeConversion_b[1];

  /* Fcn: '<S444>/Fcn22' */
  localB->VectorConcatenate[4] = rtb_sincos_o2_idx_0 * localB->sincos_o1_b[0] +
    localB->DataTypeConversion_b[0] * localB->DataTypeConversion_b[2];

  /* Fcn: '<S444>/Fcn32' */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_1 *
    localB->sincos_o1_b[0] - localB->DataTypeConversion_b[0] *
    localB->sincos_o1_b[2];

  /* Fcn: '<S444>/Fcn13' */
  localB->VectorConcatenate[6] = -localB->sincos_o1_b[1];

  /* Fcn: '<S444>/Fcn23' */
  localB->VectorConcatenate[7] = localB->DataTypeConversion_b[1] *
    localB->sincos_o1_b[2];

  /* Fcn: '<S444>/Fcn33' */
  localB->VectorConcatenate[8] = localB->DataTypeConversion_b[1] *
    localB->DataTypeConversion_b[2];

  /* Reshape: '<S447>/Reshape (9) to [3x3] column-major' */
  for (localB->i = 0; localB->i < 9; localB->i++) {
    localB->Reshape9to3x3columnmajor[localB->i] = localB->
      VectorConcatenate[localB->i];
  }

  /* End of Reshape: '<S447>/Reshape (9) to [3x3] column-major' */

  /* Fcn: '<S517>/Fcn11' */
  localB->VectorConcatenate[0] = rtb_sincos_o1_b_tmp * MemoryX_DSTATE_l;

  /* Fcn: '<S517>/Fcn21' */
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o1_b_tmp
    - rtb_SaturationThrust1_tmp * localB->numAccum;

  /* Fcn: '<S517>/Fcn31' */
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o1_b_tmp + rtb_SaturationThrust1_tmp * MemoryX_DSTATE_l_0;

  /* Fcn: '<S517>/Fcn12' */
  localB->VectorConcatenate[3] = rtb_SaturationThrust1_tmp * MemoryX_DSTATE_l;

  /* Fcn: '<S517>/Fcn22' */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
    rtb_SaturationThrust1_tmp + rtb_sincos_o1_b_tmp * localB->numAccum;

  /* Fcn: '<S517>/Fcn32' */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_SaturationThrust1_tmp - rtb_sincos_o1_b_tmp * MemoryX_DSTATE_l_0;

  /* Fcn: '<S517>/Fcn13' */
  localB->VectorConcatenate[6] = -localB->Gain_m;

  /* Fcn: '<S517>/Fcn23' */
  localB->VectorConcatenate[7] = rtb_VectorConcatenate_tmp_2;

  /* Fcn: '<S517>/Fcn33' */
  localB->VectorConcatenate[8] = rtb_VectorConcatenate_tmp_3;

  /* RelationalOperator: '<S443>/Compare' incorporates:
   *  Constant: '<S443>/Constant'
   *  DataTypeConversion: '<S251>/Data Type Conversion'
   *  Reshape: '<S255>/Reshapexhat'
   */
  rtb_Compare_ls = ((real32_T)localDW->Delay2_DSTATE <=
                    localP->DeactivateAccelerationIfOFisnotusedduetolowaltitude_const);

  /* Logic: '<S438>/Logical Operator' incorporates:
   *  Constant: '<S445>/Constant'
   *  Constant: '<S446>/Constant'
   *  RelationalOperator: '<S445>/Compare'
   *  RelationalOperator: '<S446>/Compare'
   */
  rtb_Compare_fc = ((localB->u_l[0] !=
                     localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con)
                    || (localB->u_l[1] !=
                        localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co));

  /* Product: '<S438>/Product1' incorporates:
   *  Constant: '<S438>/gravity'
   */
  localB->rtb_Add_a_idx_1 = localP->gravity_Value[1];
  localB->u_h = localP->gravity_Value[0];
  localB->unnamed_idx_1_tmp = localP->gravity_Value[2];

  /* Sum: '<S438>/Add' incorporates:
   *  Constant: '<S438>/gravity'
   *  Product: '<S438>/Product1'
   *  Reshape: '<S447>/Reshape (9) to [3x3] column-major'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_VectorConcatenate_c[localB->j] = localB->FIR_IMUaccel[localB->j]
      - ((localB->Reshape9to3x3columnmajor[localB->j + 3] *
          localB->rtb_Add_a_idx_1 + localB->Reshape9to3x3columnmajor[localB->j] *
          localB->u_h) + localB->Reshape9to3x3columnmajor[localB->j + 6] *
         localB->unnamed_idx_1_tmp);
  }

  /* End of Sum: '<S438>/Add' */

  /* Product: '<S438>/Product' incorporates:
   *  Gain: '<S438>/gainaccinput1'
   */
  localB->Product[0] = (real32_T)(localP->gainaccinput1_Gain *
    localB->rtb_VectorConcatenate_c[0]) * (real32_T)rtb_Compare_fc * (real32_T)
    rtb_Compare_ls;
  localB->Product[1] = (real32_T)(localP->gainaccinput1_Gain *
    localB->rtb_VectorConcatenate_c[1]) * (real32_T)rtb_Compare_fc * (real32_T)
    rtb_Compare_ls;

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
    localB->Gain_m = localDW->MemoryX_DSTATE_l[1];
    MemoryX_DSTATE_l = localDW->MemoryX_DSTATE_l[0];
    MemoryX_DSTATE_l_0 = localDW->MemoryX_DSTATE_l[2];
    localB->numAccum = localDW->MemoryX_DSTATE_l[3];

    /* Reshape: '<S441>/Reshapeu' incorporates:
     *  Constant: '<S441>/D'
     *  Product: '<S510>/D[k]*u[k]'
     */
    rtb_VectorConcatenate_tmp = localB->Product[1];
    rtb_VectorConcatenate_tmp_0 = localB->Product[0];
    for (localB->j = 0; localB->j < 2; localB->j++) {
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
      localB->Add_k[localB->j] = localB->angularvelocitycompensation[localB->j]
        - ((((localP->C_Value_i2[localB->j + 2] * localB->Gain_m +
              localP->C_Value_i2[localB->j] * MemoryX_DSTATE_l) +
             localP->C_Value_i2[localB->j + 4] * MemoryX_DSTATE_l_0) +
            localP->C_Value_i2[localB->j + 6] * localB->numAccum) +
           (localP->D_Value_h[localB->j + 2] * rtb_VectorConcatenate_tmp +
            localP->D_Value_h[localB->j] * rtb_VectorConcatenate_tmp_0));
    }

    /* Product: '<S510>/Product3' incorporates:
     *  Constant: '<S460>/KalmanGainL'
     *  DataTypeConversion: '<S502>/Conversion'
     */
    rtb_VectorConcatenate_tmp = localB->Add_k[1];
    localB->Gain_m = localB->Add_k[0];
    for (localB->j = 0; localB->j < 4; localB->j++) {
      /* Product: '<S510>/Product3' incorporates:
       *  Constant: '<S460>/KalmanGainL'
       *  DataTypeConversion: '<S502>/Conversion'
       */
      localB->Product3_a[localB->j] = (real32_T)localP->KalmanGainL_Value
        [localB->j + 4] * rtb_VectorConcatenate_tmp + (real32_T)
        localP->KalmanGainL_Value[localB->j] * localB->Gain_m;
    }
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

  /* BusAssignment: '<S1>/Control Mode Update' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   */
  localB->u_l[1] = rtu_ReferenceValueServerCmds->orient_ref[1];
  localB->u_l[2] = rtu_ReferenceValueServerCmds->orient_ref[2];

  /* Chart: '<S5>/Chart' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataTypeConversion: '<S251>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Reshape: '<S255>/Reshapexhat'
   */
  if (localDW->temporalCounter_i1 < 1023) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c3_flightControlSystem == 0) {
    localDW->is_active_c3_flightControlSystem = 1U;
    localDW->temporalCounter_i1 = 0U;
    localDW->is_c3_flightControlSystem = flightControlSystem_IN_Hover;
  } else {
    switch (localDW->is_c3_flightControlSystem) {
     case flightControlSystem_IN_Circle:
      if ((rtu_VisionbasedData[2] >= -5.0) && (rtu_VisionbasedData[2] <= 5.0) &&
          ((rtu_VisionbasedData[3] >= -5.0) && (rtu_VisionbasedData[3] <= 5.0)) &&
          (rtu_VisionbasedData[4] != 0.0)) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Lower;
      } else {
        localB->motor_gain = 0.0;
        localB->x += rtu_VisionbasedData[2] * rtu_VisionbasedData[5];
        localB->y += rtu_VisionbasedData[3] * rtu_VisionbasedData[5];
        localB->z = localP->Constant_Value_g;
      }
      break;

     case flightControlSystem_IN_Circle1:
      if ((rtu_VisionbasedData[2] >= -5.0) && (rtu_VisionbasedData[2] <= 5.0) &&
          ((rtu_VisionbasedData[3] >= -5.0) && (rtu_VisionbasedData[3] <= 5.0)) &&
          (rtu_VisionbasedData[4] != 0.0)) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_land1;
      } else {
        localB->motor_gain = 0.0;
        localB->x += rtu_VisionbasedData[2] * rtu_VisionbasedData[5];
        localB->y += rtu_VisionbasedData[3] * rtu_VisionbasedData[5];
        localB->z = localP->Constant_Value_g;
      }
      break;

     case flightControlSystem_IN_Cruise_height:
      if (localDW->temporalCounter_i1 >= 600) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Line_track2;
      } else {
        localB->motor_gain = 0.0;
        localB->z = localP->Constant_Value_g;
      }
      break;

     case flightControlSystem_IN_Drop_off:
      localB->motor_gain = 1.0;
      localB->z = 0.0;
      break;

     case flightControlSystem_IN_Hover:
      if (localDW->temporalCounter_i1 >= 1000) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Line_track;
      } else {
        localB->z = localP->Constant_Value_g;
        localB->x = 0.0;
        localB->y = 0.0;
        localB->motor_gain = 0.0;
      }
      break;

     case flightControlSystem_IN_Line_track:
      if (rtu_VisionbasedData[4] == 0.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Line_track1;
      } else {
        localB->x += rtu_VisionbasedData[0] * rtu_VisionbasedData[5];
        localB->y += rtu_VisionbasedData[1] * rtu_VisionbasedData[5];
        localB->z = localP->Constant_Value_g;
        localB->motor_gain = 0.0;
      }
      break;

     case flightControlSystem_IN_Line_track1:
      if (rtu_VisionbasedData[4] != 0.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circle;
      } else {
        localB->x += 0.0005;
        localB->y += rtu_VisionbasedData[1] * rtu_VisionbasedData[5];
        localB->z = localP->Constant_Value_g;
        localB->motor_gain = 0.0;
      }
      break;

     case flightControlSystem_IN_Line_track2:
      if (rtu_VisionbasedData[4] == 0.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Line_track3;
      } else {
        localB->x += rtu_VisionbasedData[0] * rtu_VisionbasedData[5];
        localB->y += rtu_VisionbasedData[1] * rtu_VisionbasedData[5];
        localB->z = localP->Constant_Value_g;
      }
      break;

     case flightControlSystem_IN_Line_track3:
      if (rtu_VisionbasedData[4] != 0.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circle1;
      } else {
        localB->x += rtu_VisionbasedData[0] * rtu_VisionbasedData[5];
        localB->y += rtu_VisionbasedData[1] * rtu_VisionbasedData[5];
        localB->z = localP->Constant_Value_g;
      }
      break;

     case flightControlSystem_IN_Lower:
      if (localB->z >= -0.6) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Lower_Hover;
      } else {
        localB->motor_gain = 0.0;
        localB->z += 0.0015;
      }
      break;

     case flightControlSystem_IN_Lower_Hover:
      if (localDW->temporalCounter_i1 >= 600) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_flightControlSystem =
          flightControlSystem_IN_Cruise_height;
      } else {
        localB->motor_gain = 0.0;
        localB->z = -0.5;
      }
      break;

     default:
      /* case IN_land1: */
      if ((real32_T)localDW->Delay2_DSTATE >= -0.3) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Drop_off;
      } else {
        localB->motor_gain = 0.0;
        localB->z = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Sum: '<S10>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity'
   */
  rtb_VectorConcatenate_tmp_2 = (real32_T)localB->x -
    localDW->SimplyIntegrateVelocity_DSTATE[0];
  rtb_VectorConcatenate_tmp_3 = (real32_T)localB->y -
    localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* Saturate: '<S169>/Saturation' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  MemoryX_DSTATE_l_0 = (rtb_sincos_o1_b_tmp * rtb_VectorConcatenate_tmp_2 +
                        rtb_SaturationThrust1_tmp * rtb_VectorConcatenate_tmp_3)
    * localP->Positioncontroller_P;
  if (MemoryX_DSTATE_l_0 > localP->Positioncontroller_UpperSaturationLimit) {
    MemoryX_DSTATE_l_0 = localP->Positioncontroller_UpperSaturationLimit;
  } else if (MemoryX_DSTATE_l_0 <
             localP->Positioncontroller_LowerSaturationLimit) {
    MemoryX_DSTATE_l_0 = localP->Positioncontroller_LowerSaturationLimit;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  Reshape: '<S441>/Reshapexhat'
   *  Saturate: '<S169>/Saturation'
   */
  localB->Gain_m = MemoryX_DSTATE_l_0 - localB->Add_o[0];
  localB->Add_k[0] = localB->Gain_m;

  /* Sum: '<S225>/Sum' incorporates:
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Gain: '<S221>/Proportional Gain'
   */
  MemoryX_DSTATE_l = localP->Velocitycontroller_P * localB->Gain_m +
    localDW->Integrator_DSTATE[0];
  localB->Conversion_g[0] = MemoryX_DSTATE_l;

  /* Saturate: '<S223>/Saturation' */
  if (MemoryX_DSTATE_l > localP->Velocitycontroller_UpperSaturationLimit) {
    MemoryX_DSTATE_l = localP->Velocitycontroller_UpperSaturationLimit;
  } else if (MemoryX_DSTATE_l < localP->Velocitycontroller_LowerSaturationLimit)
  {
    MemoryX_DSTATE_l = localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' incorporates:
   *  Saturate: '<S223>/Saturation'
   */
  MemoryX_DSTATE_l_0 = (MemoryX_DSTATE_l -
                        localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
                        [0] *
                        localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
                        [1]) /
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[0] =
    MemoryX_DSTATE_l_0;
  localB->numAccum =
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    MemoryX_DSTATE_l_0 +
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] *
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1];

  /* Saturate: '<S169>/Saturation' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  MemoryX_DSTATE_l_0 = (-rtb_SaturationThrust1_tmp * rtb_VectorConcatenate_tmp_2
                        + rtb_sincos_o1_b_tmp * rtb_VectorConcatenate_tmp_3) *
    localP->Positioncontroller_P;
  if (MemoryX_DSTATE_l_0 > localP->Positioncontroller_UpperSaturationLimit) {
    MemoryX_DSTATE_l_0 = localP->Positioncontroller_UpperSaturationLimit;
  } else if (MemoryX_DSTATE_l_0 <
             localP->Positioncontroller_LowerSaturationLimit) {
    MemoryX_DSTATE_l_0 = localP->Positioncontroller_LowerSaturationLimit;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S167>/Proportional Gain'
   *  Reshape: '<S441>/Reshapexhat'
   *  Saturate: '<S169>/Saturation'
   */
  localB->Gain_m = MemoryX_DSTATE_l_0 - localB->Add_o[1];

  /* Sum: '<S225>/Sum' incorporates:
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Gain: '<S221>/Proportional Gain'
   */
  MemoryX_DSTATE_l = localP->Velocitycontroller_P * localB->Gain_m +
    localDW->Integrator_DSTATE[1];

  /* Saturate: '<S223>/Saturation' */
  if (MemoryX_DSTATE_l > localP->Velocitycontroller_UpperSaturationLimit) {
    rtb_VectorConcatenate_tmp = localP->Velocitycontroller_UpperSaturationLimit;
  } else if (MemoryX_DSTATE_l < localP->Velocitycontroller_LowerSaturationLimit)
  {
    rtb_VectorConcatenate_tmp = localP->Velocitycontroller_LowerSaturationLimit;
  } else {
    rtb_VectorConcatenate_tmp = MemoryX_DSTATE_l;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' incorporates:
   *  Saturate: '<S223>/Saturation'
   */
  MemoryX_DSTATE_l_0 = (rtb_VectorConcatenate_tmp -
                        localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
                        [1] *
                        localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
                        [1]) /
    localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c[0];
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[1] =
    MemoryX_DSTATE_l_0;

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   *  Constant: '<S1>/controlModePosVsOrient'
   *  DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   *  Gain: '<S10>/Gain'
   */
  if (localP->controlModePosVsOrient_Value) {
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] =
      localP->Gain_Gain[0] * localB->numAccum;
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] =
      (localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0]
       * MemoryX_DSTATE_l_0 +
       localP->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1]
       * localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
       [1]) * localP->Gain_Gain[1];
  } else {
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] =
      localB->u_l[1];
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] =
      localB->u_l[2];
  }

  /* End of Switch: '<S3>/Switch_refAtt' */

  /* Gain: '<S58>/Proportional Gain' incorporates:
   *  Sum: '<S8>/Sum19'
   */
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] =
    (localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] -
     localB->DataTypeConversion3[1]) * localP->Anglecontrolloop_P;
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] =
    (localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] -
     localB->DataTypeConversion3[2]) * localP->Anglecontrolloop_P;

  /* Sum: '<S8>/Sum1' */
  MemoryX_DSTATE_l_0 =
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0];
  localB->numAccum =
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1];
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] =
    MemoryX_DSTATE_l_0 - localB->rtb_Subtract_p_idx_1;
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] =
    localB->numAccum - localB->rtb_Subtract_p_idx_0;

  /* Gain: '<S110>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S102>/Filter'
   *  Gain: '<S100>/Derivative Gain'
   *  Sum: '<S102>/SumD'
   */
  localB->rtb_Subtract_p_idx_0 = (localP->Angularvelocitycontrolloop_D[0] *
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] -
    localDW->Filter_DSTATE[0]) * localP->Angularvelocitycontrolloop_N[0];
  localB->Saturation[0] = localB->rtb_Subtract_p_idx_0;

  /* Sum: '<S116>/Sum' incorporates:
   *  DiscreteIntegrator: '<S107>/Integrator'
   *  Gain: '<S100>/Derivative Gain'
   *  Gain: '<S112>/Proportional Gain'
   */
  localB->numAccum = (localP->Angularvelocitycontrolloop_P[0] *
                      localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr
                      [0] + localDW->Integrator_DSTATE_d[0]) +
    localB->rtb_Subtract_p_idx_0;
  localB->DeadZone_k[0] = localB->numAccum;

  /* Saturate: '<S114>/Saturation' */
  if (localB->numAccum > localP->Angularvelocitycontrolloop_UpperSaturationLimit)
  {
    rtb_VectorConcatenate_tmp_0 =
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->numAccum <
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    rtb_VectorConcatenate_tmp_0 =
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  } else {
    rtb_VectorConcatenate_tmp_0 = localB->numAccum;
  }

  /* Gain: '<S110>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S102>/Filter'
   *  Gain: '<S100>/Derivative Gain'
   *  Sum: '<S102>/SumD'
   */
  localB->rtb_Subtract_p_idx_0 = (localP->Angularvelocitycontrolloop_D[1] *
    localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] -
    localDW->Filter_DSTATE[1]) * localP->Angularvelocitycontrolloop_N[1];
  localB->Saturation[1] = localB->rtb_Subtract_p_idx_0;

  /* Sum: '<S116>/Sum' incorporates:
   *  DiscreteIntegrator: '<S107>/Integrator'
   *  Gain: '<S100>/Derivative Gain'
   *  Gain: '<S112>/Proportional Gain'
   */
  localB->numAccum = (localP->Angularvelocitycontrolloop_P[1] *
                      localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr
                      [1] + localDW->Integrator_DSTATE_d[1]) +
    localB->rtb_Subtract_p_idx_0;

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_ls = (localDW->Output_DSTATE_a < localP->CompareToConstant_const_c);

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if ((!rtb_Compare_ls) && (localDW->DiscreteTimeIntegrator_PrevResetState == 1))
  {
    localDW->DiscreteTimeIntegrator_DSTATE_c =
      localP->DiscreteTimeIntegrator_IC_h;
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  DataTypeConversion: '<S251>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Reshape: '<S255>/Reshapexhat'
   */
  localB->rtb_Subtract_p_idx_0 = (real32_T)localB->z - (real32_T)
    localDW->Delay2_DSTATE;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<S3>/Constant'
   *  DiscreteIntegrator: '<S319>/Discrete-Time Integrator'
   */
  localB->rtb_Subtract_p_idx_1 = (real32_T)localP->Constant_Value_n -
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S11>/Saturation' */
  if (localB->rtb_Subtract_p_idx_1 > localP->Saturation_UpperSat) {
    localB->rtb_Subtract_p_idx_1 = localP->Saturation_UpperSat;
  } else if (localB->rtb_Subtract_p_idx_1 < localP->Saturation_LowerSat) {
    localB->rtb_Subtract_p_idx_1 = localP->Saturation_LowerSat;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Switch: '<S7>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S7>/w1'
   *  DataTypeConversion: '<S251>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/D_z1'
   *  Gain: '<S7>/P_z1'
   *  Gain: '<S7>/takeoff_gain1'
   *  Sum: '<S7>/Sum1'
   */
  if (rtb_Compare_ls) {
    rtb_VectorConcatenate_tmp = localP->takeoff_gain1_Gain * localP->w1_Value;
  } else {
    rtb_VectorConcatenate_tmp = (localP->P_z1_Gain *
      localB->rtb_Subtract_p_idx_0 + localDW->DiscreteTimeIntegrator_DSTATE_c) -
      localP->D_z1_Gain * (real32_T)localB->rtb_VectorConcatenate_m[2];
  }

  /* Sum: '<S7>/Sum5' incorporates:
   *  Constant: '<S7>/w1'
   *  Switch: '<S7>/TakeoffOrControl_Switch1'
   */
  MemoryX_DSTATE_l_0 = localP->w1_Value + rtb_VectorConcatenate_tmp;

  /* Saturate: '<S7>/SaturationThrust1' */
  if (MemoryX_DSTATE_l_0 > localP->SaturationThrust1_UpperSat) {
    MemoryX_DSTATE_l_0 = localP->SaturationThrust1_UpperSat;
  } else if (MemoryX_DSTATE_l_0 < localP->SaturationThrust1_LowerSat) {
    MemoryX_DSTATE_l_0 = localP->SaturationThrust1_LowerSat;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_yaw'
   *  Gain: '<S11>/P_yaw'
   *  Sum: '<S11>/Sum2'
   */
  localB->rtb_Subtract_p_idx_2 = (localP->P_yaw_Gain *
    localB->rtb_Subtract_p_idx_1 + localDW->DiscreteTimeIntegrator_DSTATE_d) -
    localP->D_yaw_Gain * localB->rtb_Subtract_p_idx_2;

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S9>/Pitch correction'
   *  Constant: '<S9>/zero correction'
   *  ManualSwitch: '<S9>/Manual Switch'
   */
  if (localP->ManualSwitch_CurrentSetting == 1) {
    rtb_VectorConcatenate_tmp = localP->Pitchcorrection_Value;
  } else {
    rtb_VectorConcatenate_tmp = localP->zerocorrection_Value;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  ManualSwitch: '<S9>/Manual Switch'
   *  Saturate: '<S114>/Saturation'
   *  Sum: '<S9>/Add'
   */
  rtb_VectorConcatenate_tmp += rtb_VectorConcatenate_tmp_0;

  /* Saturate: '<S114>/Saturation' */
  if (localB->numAccum > localP->Angularvelocitycontrolloop_UpperSaturationLimit)
  {
    /* SignalConversion generated from: '<S9>/Product' */
    rtb_VectorConcatenate_tmp_0 =
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->numAccum <
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    /* SignalConversion generated from: '<S9>/Product' */
    rtb_VectorConcatenate_tmp_0 =
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  } else {
    /* SignalConversion generated from: '<S9>/Product' */
    rtb_VectorConcatenate_tmp_0 = localB->numAccum;
  }

  for (localB->j = 0; localB->j < 4; localB->j++) {
    /* Saturate: '<S12>/Saturation' incorporates:
     *  Constant: '<S9>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S12>/Gain'
     *  Product: '<S9>/Product'
     *  Saturate: '<S7>/SaturationThrust1'
     */
    rtb_VectorConcatenate_tmp_2 =
      (((localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 4] *
         localB->rtb_Subtract_p_idx_2 +
         localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j] *
         MemoryX_DSTATE_l_0) + localP->
        TorqueTotalThrustToThrustPerMotor_Value[localB->j + 8] *
        rtb_VectorConcatenate_tmp) +
       localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 12] *
       rtb_VectorConcatenate_tmp_0) * localP->Gain_Gain_b;
    if (rtb_VectorConcatenate_tmp_2 > localP->Saturation_UpperSat_n) {
      localB->Switch[localB->j] = localP->Saturation_UpperSat_n;
    } else if (rtb_VectorConcatenate_tmp_2 < localP->Saturation_LowerSat_i) {
      localB->Switch[localB->j] = localP->Saturation_LowerSat_i;
    } else {
      localB->Switch[localB->j] = rtb_VectorConcatenate_tmp_2;
    }

    /* End of Saturate: '<S12>/Saturation' */
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   */
  if (localB->motor_gain > localP->Switch_Threshold) {
    /* Switch: '<S12>/Switch' incorporates:
     *  Gain: '<S12>/Gain1'
     *  Saturate: '<S12>/Saturation'
     */
    localB->Switch[0] *= localP->Gain1_Gain[0];
    localB->Switch[1] *= localP->Gain1_Gain[1];
    localB->Switch[2] *= localP->Gain1_Gain[2];
    localB->Switch[3] *= localP->Gain1_Gain[3];
  } else {
    /* Switch: '<S12>/Switch' incorporates:
     *  Gain: '<S12>/Gain2'
     *  Saturate: '<S12>/Saturation'
     */
    localB->Switch[0] *= localP->Gain2_Gain[0];
    localB->Switch[1] *= localP->Gain2_Gain[1];
    localB->Switch[2] *= localP->Gain2_Gain[2];
    localB->Switch[3] *= localP->Gain2_Gain[3];
  }

  /* End of Switch: '<S12>/Switch' */

  /* Product: '<S251>/Product' */
  localB->rtb_Subtract_p_idx_2 = localB->FIR_IMUaccel[1];
  MemoryX_DSTATE_l_0 = localB->FIR_IMUaccel[0];
  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* Sum: '<S251>/Sum' incorporates:
     *  Constant: '<S251>/gravity'
     *  DiscreteFir: '<S253>/FIR_IMUaccel'
     *  Math: '<S251>/Math Function'
     *  Product: '<S251>/Product'
     */
    localB->Sum[localB->j] = ((localB->MathFunction[localB->j + 3] *
      localB->rtb_Subtract_p_idx_2 + localB->MathFunction[localB->j] *
      MemoryX_DSTATE_l_0) + localB->MathFunction[localB->j + 6] * localB->Abs) +
      localP->gravity_Value_j[localB->j];
  }

  /* DataTypeConversion: '<S418>/Conversion' incorporates:
   *  Constant: '<S376>/KalmanGainL'
   */
  localB->Akxhatkk1_o[0] = (real32_T)localP->KalmanGainL_Value_p[0];
  localB->Akxhatkk1_o[1] = (real32_T)localP->KalmanGainL_Value_p[1];

  /* Outputs for Enabled SubSystem: '<S395>/MeasurementUpdate' */
  /* DataTypeConversion: '<S375>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S375>/C'
   *  Constant: '<S375>/D'
   *  Delay: '<S375>/MemoryX'
   *  Reshape: '<S375>/Reshapeu'
   *  Reshape: '<S375>/Reshapey'
   */
  flightControlSystem_MeasurementUpdate((localB->LogicalOperator != 0),
    localB->Akxhatkk1_o, localB->TrigonometricFunction, localP->C_Value_i,
    localDW->MemoryX_DSTATE_m, localP->D_Value_k, localB->p,
    &localB->MeasurementUpdate_j, &localDW->MeasurementUpdate_j,
    &localP->MeasurementUpdate_j);

  /* End of Outputs for SubSystem: '<S395>/MeasurementUpdate' */

  /* DataTypeConversion: '<S364>/Conversion' incorporates:
   *  Constant: '<S322>/KalmanGainL'
   */
  localB->Akxhatkk1_o[0] = (real32_T)localP->KalmanGainL_Value_l[0];
  localB->Akxhatkk1_o[1] = (real32_T)localP->KalmanGainL_Value_l[1];

  /* Outputs for Enabled SubSystem: '<S341>/MeasurementUpdate' */
  /* DataTypeConversion: '<S321>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S321>/C'
   *  Constant: '<S321>/D'
   *  Delay: '<S321>/MemoryX'
   *  Reshape: '<S321>/Reshapeu'
   *  Reshape: '<S321>/Reshapey'
   */
  flightControlSystem_MeasurementUpdate((localB->LogicalOperator != 0),
    localB->Akxhatkk1_o, localB->TrigonometricFunction1, localP->C_Value_h,
    localDW->MemoryX_DSTATE_g, localP->D_Value_kg, localB->q,
    &localB->MeasurementUpdate_n, &localDW->MeasurementUpdate_n,
    &localP->MeasurementUpdate_n);

  /* End of Outputs for SubSystem: '<S341>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S277>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S307>/Enable'
   */
  /* DataTypeConversion: '<S255>/DataTypeConversionEnable' */
  if (localB->nicemeasurementornewupdateneeded) {
    localDW->MeasurementUpdate_MODE_h = true;

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
    localB->u_h = localB->invertzaxisGain - ((localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]) + localP->D_Value * localB->Sum[2]);

    /* Product: '<S307>/Product3' incorporates:
     *  Constant: '<S259>/KalmanGainL'
     *  DataTypeConversion: '<S299>/Conversion'
     */
    localB->Product3[0] = localP->KalmanGainL_Value_b[0] * localB->u_h;
    localB->Product3[1] = localP->KalmanGainL_Value_b[1] * localB->u_h;
  } else if (localDW->MeasurementUpdate_MODE_h) {
    /* Disable for Product: '<S307>/Product3' incorporates:
     *  Outport: '<S307>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3[0] = localP->Lykyhatkk1_Y0;
    localB->Product3[1] = localP->Lykyhatkk1_Y0;
    localDW->MeasurementUpdate_MODE_h = false;
  }

  /* End of Outputs for SubSystem: '<S277>/MeasurementUpdate' */

  /* DeadZone: '<S99>/DeadZone' */
  if (localB->DeadZone_k[0] >
      localP->Angularvelocitycontrolloop_UpperSaturationLimit) {
    localB->DeadZone_k[0] -=
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->DeadZone_k[0] >=
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    localB->DeadZone_k[0] = 0.0F;
  } else {
    localB->DeadZone_k[0] -=
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  }

  /* Gain: '<S104>/Integral Gain' */
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[0] *=
    localP->Angularvelocitycontrolloop_I[0];

  /* DeadZone: '<S208>/DeadZone' */
  if (localB->Conversion_g[0] > localP->Velocitycontroller_UpperSaturationLimit)
  {
    localB->Conversion_g[0] -= localP->Velocitycontroller_UpperSaturationLimit;
  } else if (localB->Conversion_g[0] >=
             localP->Velocitycontroller_LowerSaturationLimit) {
    localB->Conversion_g[0] = 0.0F;
  } else {
    localB->Conversion_g[0] -= localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* Gain: '<S213>/Integral Gain' */
  localB->Add_k[0] *= localP->Velocitycontroller_I;

  /* DeadZone: '<S99>/DeadZone' incorporates:
   *  Sum: '<S116>/Sum'
   */
  if (localB->numAccum > localP->Angularvelocitycontrolloop_UpperSaturationLimit)
  {
    localB->DeadZone_k[1] = localB->numAccum -
      localP->Angularvelocitycontrolloop_UpperSaturationLimit;
  } else if (localB->numAccum >=
             localP->Angularvelocitycontrolloop_LowerSaturationLimit) {
    localB->DeadZone_k[1] = 0.0F;
  } else {
    localB->DeadZone_k[1] = localB->numAccum -
      localP->Angularvelocitycontrolloop_LowerSaturationLimit;
  }

  /* Gain: '<S104>/Integral Gain' */
  localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr[1] *=
    localP->Angularvelocitycontrolloop_I[1];

  /* DeadZone: '<S208>/DeadZone' incorporates:
   *  Sum: '<S225>/Sum'
   */
  if (MemoryX_DSTATE_l > localP->Velocitycontroller_UpperSaturationLimit) {
    localB->Conversion_g[1] = MemoryX_DSTATE_l -
      localP->Velocitycontroller_UpperSaturationLimit;
  } else if (MemoryX_DSTATE_l >= localP->Velocitycontroller_LowerSaturationLimit)
  {
    localB->Conversion_g[1] = 0.0F;
  } else {
    localB->Conversion_g[1] = MemoryX_DSTATE_l -
      localP->Velocitycontroller_LowerSaturationLimit;
  }

  /* Gain: '<S213>/Integral Gain' incorporates:
   *  Sum: '<S10>/Sum19'
   */
  localB->Add_k[1] = localP->Velocitycontroller_I * localB->Gain_m;

  /* Sum: '<S15>/FixPt Sum1' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  UnitDelay: '<S14>/Output'
   */
  localDW->Output_DSTATE_a += localP->FixPtConstant_Value_g;

  /* Gain: '<S4>/Gain' */
  localB->Abs = localP->Gain_Gain_o *
    rtu_Sensors->VisionSensors.opticalFlow_data[0];

  /* Sum: '<S4>/Subtract' incorporates:
   *  Reshape: '<S441>/Reshapexhat'
   */
  localB->rtb_Subtract_p_idx_2 = localB->Abs - localB->Add_o[0];

  /* Abs: '<S4>/Abs4' */
  localB->Abs = (real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]);

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Abs: '<S4>/Abs2'
   *  Constant: '<S238>/Constant'
   *  Constant: '<S240>/Constant'
   *  RelationalOperator: '<S238>/Compare'
   *  RelationalOperator: '<S240>/Compare'
   */
  rtb_Compare_fc = ((localB->Abs > localP->CompareToConstant4_const) &&
                    ((real32_T)fabs(localB->rtb_Subtract_p_idx_2) >
                     localP->CompareToConstant2_const));

  /* Gain: '<S4>/Gain1' */
  localB->Abs = localP->Gain1_Gain_p *
    rtu_Sensors->VisionSensors.opticalFlow_data[1];

  /* Sum: '<S4>/Subtract1' incorporates:
   *  Reshape: '<S441>/Reshapexhat'
   */
  localB->rtb_Subtract_p_idx_2 = localB->Abs - localB->Add_o[1];

  /* Abs: '<S4>/Abs5' */
  localB->Abs = (real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[1]);

  /* RelationalOperator: '<S4>/GreaterThan' incorporates:
   *  Constant: '<S4>/Wait  3 Seconds'
   *  UnitDelay: '<S242>/Output'
   */
  rtb_GreaterThan = (localDW->Output_DSTATE_g > localP->Wait3Seconds_Value);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   */
  if (rtb_GreaterThan) {
    localB->u_h = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->u_h = localP->_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S235>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S235>/Compare'
   */
  localDW->DelayOneStep_DSTATE = (real_T)(localB->u_h ==
    localP->Checkerrorcondition_const) * localDW->DelayOneStep_DSTATE + (real_T)
    (localB->u_h == localP->Checkerrorcondition_const);

  /* If: '<S4>/If' incorporates:
   *  Abs: '<S4>/Abs'
   *  Abs: '<S4>/Abs  '
   *  Abs: '<S4>/Abs1'
   *  Abs: '<S4>/Abs3'
   *  Constant: '<S234>/Constant'
   *  Constant: '<S236>/Constant'
   *  Constant: '<S237>/Constant'
   *  Constant: '<S239>/Constant'
   *  Constant: '<S241>/Constant'
   *  Constant: '<S4>/0.5 meters'
   *  DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S234>/Compare'
   *  RelationalOperator: '<S236>/Compare'
   *  RelationalOperator: '<S237>/Compare'
   *  RelationalOperator: '<S239>/Compare'
   *  RelationalOperator: '<S241>/Compare'
   *  RelationalOperator: '<S4>/GreaterThan  '
   *  Switch: '<S4>/         '
   */
  if (((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[0]) >
       localP->CompareToConstant_const_j) || ((real32_T)fabs
       (localDW->SimplyIntegrateVelocity_DSTATE[1]) >
       localP->CompareToConstant1_const_e)) {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S243>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge, &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if (rtb_Compare_fc || (((real32_T)fabs(localB->rtb_Subtract_p_idx_2) >
               localP->CompareToConstant3_const) && (localB->Abs >
               localP->CompareToConstant5_const))) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localDW->DelayOneStep_DSTATE > localP->u0continuousOFerrors_const)
  {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S244>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge, &localP->Noopticalflow);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else {
    if (rtb_GreaterThan) {
      /* Switch: '<S4>/         ' incorporates:
       *  DataTypeConversion: '<S251>/Data Type Conversion'
       *  DiscreteFilter: '<S256>/pressureFilter_IIR'
       *  Reshape: '<S255>/Reshapexhat'
       *  Sum: '<S4>/Difference between  sonar and pressure'
       */
      rtb_VectorConcatenate_tmp = (real32_T)localDW->Delay2_DSTATE - numAccum;
    } else {
      /* Switch: '<S4>/         ' incorporates:
       *  Constant: '<S4>/    '
       */
      rtb_VectorConcatenate_tmp = localP->_Value_i;
    }

    if ((real32_T)fabs(rtb_VectorConcatenate_tmp) > localP->u5meters_Value) {
      /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
       *  ActionPort: '<S246>/Action Port'
       */
      flightControlSystem_Geofencingerror(&localB->Merge,
        &localP->Ultrasoundimproper);

      /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
       *  ActionPort: '<S245>/Action Port'
       */
      flightControlSystem_Geofencingerror(&localB->Merge,
        &localP->Normalcondition);

      /* End of Outputs for SubSystem: '<S4>/Normal condition' */
    }
  }

  /* End of If: '<S4>/If' */

  /* Sum: '<S248>/FixPt Sum1' incorporates:
   *  Constant: '<S248>/FixPt Constant'
   *  UnitDelay: '<S242>/Output'
   */
  localDW->Output_DSTATE_g += localP->FixPtConstant_Value;

  /* Sum: '<S515>/FixPt Sum1' incorporates:
   *  Constant: '<S515>/FixPt Constant'
   *  UnitDelay: '<S514>/Output'
   */
  localDW->Output_DSTATE_n += localP->FixPtConstant_Value_p;

  /* Sum: '<S434>/FixPt Sum1' incorporates:
   *  Constant: '<S434>/FixPt Constant'
   *  UnitDelay: '<S432>/Output'
   */
  localDW->Output_DSTATE += localP->FixPtConstant_Value_m;

  /* MATLABSystem: '<S5>/Grabber' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  localB->rtb_Add_a_idx_1 = rt_roundd_snf(localP->Constant1_Value);
  if (localB->rtb_Add_a_idx_1 < 256.0) {
    if (localB->rtb_Add_a_idx_1 >= 0.0) {
      tmp = (uint8_T)localB->rtb_Add_a_idx_1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_PARROT_Grabber(tmp);

  /* End of MATLABSystem: '<S5>/Grabber' */

  /* SignalConversion generated from: '<S437>/Product' incorporates:
   *  Reshape: '<S441>/Reshapexhat'
   */
  numAccum = localB->Add_o[0];
  localB->Abs = localB->Add_o[1];

  /* Product: '<S437>/Product' incorporates:
   *  Math: '<S437>/Math Function'
   *  Reshape: '<S518>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S437>/Product'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->FIR_IMUaccel[localB->j] = (localB->VectorConcatenate[3 * localB->j +
      1] * localB->Abs + localB->VectorConcatenate[3 * localB->j] * numAccum) +
      localB->VectorConcatenate[3 * localB->j + 2] * localB->SaturationThrust1;
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
  localB->u_h = localP->A_Value[0] * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1] * localP->A_Value[2];

  /* Update for DiscreteIntegrator: '<S437>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[1] +=
    localP->SimplyIntegrateVelocity_gainval * localB->FIR_IMUaccel[1];

  /* Product: '<S277>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S255>/A'
   *  Delay: '<S255>/MemoryX'
   */
  localB->unnamed_idx_1_tmp = localDW->MemoryX_DSTATE[0] * localP->A_Value[1] +
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
    localB->u_h) + localB->Product3[0];

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
    localB->unnamed_idx_1_tmp) + localB->Product3[1];

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
    localP->DiscreteTimeIntegrator_gainval * localB->Subtract;

  /* Update for Delay: '<S321>/MemoryX' */
  localDW->icLoad_p = false;

  /* Product: '<S341>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S321>/A'
   *  Delay: '<S321>/MemoryX'
   */
  localB->DiscreteTimeIntegrator_k5 = localP->A_Value_k[0] *
    localDW->MemoryX_DSTATE_g[0] + localDW->MemoryX_DSTATE_g[1] *
    localP->A_Value_k[2];
  localB->rtb_Subtract_p_idx_2 = localDW->MemoryX_DSTATE_g[0] *
    localP->A_Value_k[1] + localDW->MemoryX_DSTATE_g[1] * localP->A_Value_k[3];

  /* Update for Delay: '<S321>/MemoryX' incorporates:
   *  Constant: '<S321>/B'
   *  Product: '<S341>/A[k]*xhat[k|k-1]'
   *  Product: '<S341>/B[k]*u[k]'
   *  Product: '<S372>/Product3'
   *  Reshape: '<S321>/Reshapeu'
   *  Sum: '<S341>/Add'
   */
  localDW->MemoryX_DSTATE_g[0] = (localP->B_Value_o[0] * localB->q +
    localB->DiscreteTimeIntegrator_k5) + localB->MeasurementUpdate_n.Product3[0];
  localDW->MemoryX_DSTATE_g[1] = (localP->B_Value_o[1] * localB->q +
    localB->rtb_Subtract_p_idx_2) + localB->MeasurementUpdate_n.Product3[1];

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

  /* Update for Delay: '<S375>/MemoryX' */
  localDW->icLoad_k = false;

  /* Product: '<S395>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S375>/A'
   *  Delay: '<S375>/MemoryX'
   */
  localB->DiscreteTimeIntegrator_k5 = localP->A_Value_ah[0] *
    localDW->MemoryX_DSTATE_m[0] + localDW->MemoryX_DSTATE_m[1] *
    localP->A_Value_ah[2];
  localB->rtb_Subtract_p_idx_2 = localDW->MemoryX_DSTATE_m[0] *
    localP->A_Value_ah[1] + localDW->MemoryX_DSTATE_m[1] * localP->A_Value_ah[3];

  /* Update for Delay: '<S375>/MemoryX' incorporates:
   *  Constant: '<S375>/B'
   *  Product: '<S395>/A[k]*xhat[k|k-1]'
   *  Product: '<S395>/B[k]*u[k]'
   *  Product: '<S426>/Product3'
   *  Reshape: '<S375>/Reshapeu'
   *  Sum: '<S395>/Add'
   */
  localDW->MemoryX_DSTATE_m[0] = (localP->B_Value_g[0] * localB->p +
    localB->DiscreteTimeIntegrator_k5) + localB->MeasurementUpdate_j.Product3[0];
  localDW->MemoryX_DSTATE_m[1] = (localP->B_Value_g[1] * localB->p +
    localB->rtb_Subtract_p_idx_2) + localB->MeasurementUpdate_j.Product3[1];

  /* Update for DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localB->Add_i;

  /* Update for DiscreteTransferFcn: '<S253>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localB->LPFFcutoff40Hz_tmp;

  /* Update for DiscreteFilter: '<S253>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localB->IIR_IMUgyro_r_tmp;

  /* Switch: '<S435>/FixPt Switch' */
  if (localDW->Output_DSTATE > localP->WrapToZero_Threshold_e) {
    /* Sum: '<S434>/FixPt Sum1' incorporates:
     *  Constant: '<S435>/Constant'
     *  UnitDelay: '<S432>/Output'
     */
    localDW->Output_DSTATE = localP->Constant_Value_jy;
  }

  /* End of Switch: '<S435>/FixPt Switch' */

  /* Update for Delay: '<S441>/MemoryX' */
  localDW->icLoad_o = false;

  /* Reshape: '<S441>/Reshapeu' incorporates:
   *  Constant: '<S441>/B'
   *  Product: '<S479>/B[k]*u[k]'
   */
  rtb_VectorConcatenate_tmp = localB->Product[1];
  rtb_VectorConcatenate_tmp_0 = localB->Product[0];

  /* Delay: '<S441>/MemoryX' incorporates:
   *  Constant: '<S441>/A'
   *  Product: '<S479>/A[k]*xhat[k|k-1]'
   */
  localB->Gain_m = localDW->MemoryX_DSTATE_l[1];
  MemoryX_DSTATE_l = localDW->MemoryX_DSTATE_l[0];
  MemoryX_DSTATE_l_0 = localDW->MemoryX_DSTATE_l[2];
  localB->numAccum = localDW->MemoryX_DSTATE_l[3];
  for (localB->j = 0; localB->j < 4; localB->j++) {
    /* Product: '<S479>/B[k]*u[k]' incorporates:
     *  Constant: '<S441>/B'
     *  Reshape: '<S441>/Reshapeu'
     */
    localB->fv[localB->j] = localP->B_Value_f[localB->j + 4] *
      rtb_VectorConcatenate_tmp + localP->B_Value_f[localB->j] *
      rtb_VectorConcatenate_tmp_0;

    /* Product: '<S479>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S441>/A'
     *  Delay: '<S441>/MemoryX'
     */
    localB->fv1[localB->j] = ((localP->A_Value_a[localB->j + 4] * localB->Gain_m
      + localP->A_Value_a[localB->j] * MemoryX_DSTATE_l) + localP->
      A_Value_a[localB->j + 8] * MemoryX_DSTATE_l_0) + localP->A_Value_a
      [localB->j + 12] * localB->numAccum;
  }

  /* Update for Delay: '<S441>/MemoryX' incorporates:
   *  Sum: '<S479>/Add'
   */
  localDW->MemoryX_DSTATE_l[0] = (localB->fv[0] + localB->fv1[0]) +
    localB->Product3_a[0];
  localDW->MemoryX_DSTATE_l[1] = (localB->fv[1] + localB->fv1[1]) +
    localB->Product3_a[1];
  localDW->MemoryX_DSTATE_l[2] = (localB->fv[2] + localB->fv1[2]) +
    localB->Product3_a[2];
  localDW->MemoryX_DSTATE_l[3] = (localB->fv[3] + localB->fv1[3]) +
    localB->Product3_a[3];

  /* Switch: '<S516>/FixPt Switch' */
  if (localDW->Output_DSTATE_n > localP->WrapToZero_Threshold_k) {
    /* Sum: '<S515>/FixPt Sum1' incorporates:
     *  Constant: '<S516>/Constant'
     *  UnitDelay: '<S514>/Output'
     */
    localDW->Output_DSTATE_n = localP->Constant_Value_e;
  }

  /* End of Switch: '<S516>/FixPt Switch' */
  for (localB->j = 0; localB->j < 2; localB->j++) {
    /* Update for DiscreteFilter: '<S440>/IIRgyroz' */
    localB->memOffset = localB->j * 5;
    localDW->IIRgyroz_states[localB->memOffset + 4] = localDW->
      IIRgyroz_states[localB->memOffset + 3];
    localDW->IIRgyroz_states[localB->memOffset + 3] = localDW->
      IIRgyroz_states[localB->memOffset + 2];
    localDW->IIRgyroz_states[localB->memOffset + 2] = localDW->
      IIRgyroz_states[localB->memOffset + 1];
    localDW->IIRgyroz_states[localB->memOffset + 1] = localDW->
      IIRgyroz_states[localB->memOffset];
    localDW->IIRgyroz_states[localB->memOffset] = localDW->IIRgyroz_tmp
      [localB->j];

    /* Update for UnitDelay: '<S448>/UD' incorporates:
     *  Sum: '<S448>/Diff'
     */
    localDW->UD_DSTATE[localB->j] = localB->Conversion_i[localB->j];

    /* Reshape: '<S441>/Reshapexhat' */
    localB->DiscreteTimeIntegrator_k5 = localB->Add_o[localB->j];

    /* Update for Delay: '<S436>/Delay' incorporates:
     *  Reshape: '<S441>/Reshapexhat'
     */
    localDW->Delay_DSTATE[localB->j] = localB->DiscreteTimeIntegrator_k5;

    /* Update for Delay: '<S6>/Delay1' incorporates:
     *  Reshape: '<S441>/Reshapexhat'
     */
    localDW->Delay1_DSTATE[localB->j] = localB->DiscreteTimeIntegrator_k5;

    /* RelationalOperator: '<S206>/fix for DT propagation issue' incorporates:
     *  DiscreteIntegrator: '<S216>/Integrator'
     */
    MemoryX_DSTATE_l = localB->Conversion_g[localB->j];

    /* Switch: '<S206>/Switch1' incorporates:
     *  Constant: '<S206>/Clamping_zero'
     *  Constant: '<S206>/Constant'
     *  Constant: '<S206>/Constant2'
     *  RelationalOperator: '<S206>/fix for DT propagation issue'
     */
    if (MemoryX_DSTATE_l > localP->Clamping_zero_Value_m) {
      tmp_0 = localP->Constant_Value_p;
    } else {
      tmp_0 = localP->Constant2_Value_f;
    }

    /* RelationalOperator: '<S206>/fix for DT propagation issue1' incorporates:
     *  DiscreteIntegrator: '<S216>/Integrator'
     */
    localB->Gain_m = localB->Add_k[localB->j];

    /* Switch: '<S206>/Switch2' incorporates:
     *  Constant: '<S206>/Clamping_zero'
     *  Constant: '<S206>/Constant3'
     *  Constant: '<S206>/Constant4'
     *  RelationalOperator: '<S206>/fix for DT propagation issue1'
     */
    if (localB->Gain_m > localP->Clamping_zero_Value_m) {
      tmp_1 = localP->Constant3_Value_d;
    } else {
      tmp_1 = localP->Constant4_Value_p;
    }

    /* Switch: '<S206>/Switch' incorporates:
     *  Constant: '<S206>/Clamping_zero'
     *  Constant: '<S206>/Constant1'
     *  Logic: '<S206>/AND3'
     *  RelationalOperator: '<S206>/Equal1'
     *  RelationalOperator: '<S206>/Relational Operator'
     *  Switch: '<S206>/Switch1'
     *  Switch: '<S206>/Switch2'
     */
    if ((localP->Clamping_zero_Value_m != MemoryX_DSTATE_l) && (tmp_0 == tmp_1))
    {
      localB->Gain_m = localP->Constant1_Value_c;
    }

    /* Update for DiscreteIntegrator: '<S216>/Integrator' incorporates:
     *  Switch: '<S206>/Switch'
     */
    localDW->Integrator_DSTATE[localB->j] += localP->Integrator_gainval *
      localB->Gain_m;

    /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
    localDW->
      LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[localB->j]
      = localDW->
      LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j[localB->j];

    /* RelationalOperator: '<S97>/fix for DT propagation issue' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator'
     */
    localB->numAccum = localB->DeadZone_k[localB->j];

    /* Switch: '<S97>/Switch1' incorporates:
     *  Constant: '<S97>/Clamping_zero'
     *  Constant: '<S97>/Constant'
     *  Constant: '<S97>/Constant2'
     *  RelationalOperator: '<S97>/fix for DT propagation issue'
     */
    if (localB->numAccum > localP->Clamping_zero_Value) {
      tmp_0 = localP->Constant_Value_km;
    } else {
      tmp_0 = localP->Constant2_Value;
    }

    /* RelationalOperator: '<S97>/fix for DT propagation issue1' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator'
     */
    localB->DiscreteTimeIntegrator_k5 =
      localB->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontr
      [localB->j];

    /* Switch: '<S97>/Switch2' incorporates:
     *  Constant: '<S97>/Clamping_zero'
     *  Constant: '<S97>/Constant3'
     *  Constant: '<S97>/Constant4'
     *  RelationalOperator: '<S97>/fix for DT propagation issue1'
     */
    if (localB->DiscreteTimeIntegrator_k5 > localP->Clamping_zero_Value) {
      tmp_1 = localP->Constant3_Value;
    } else {
      tmp_1 = localP->Constant4_Value;
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
    if ((localP->Clamping_zero_Value != localB->numAccum) && (tmp_0 == tmp_1)) {
      localB->DiscreteTimeIntegrator_k5 = localP->Constant1_Value_n;
    }

    /* Update for DiscreteIntegrator: '<S107>/Integrator' incorporates:
     *  Switch: '<S97>/Switch'
     */
    localDW->Integrator_DSTATE_d[localB->j] += localP->Integrator_gainval_i *
      localB->DiscreteTimeIntegrator_k5;

    /* Update for DiscreteIntegrator: '<S102>/Filter' */
    localDW->Filter_DSTATE[localB->j] += localP->Filter_gainval *
      localB->Saturation[localB->j];
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
  localDW->DiscreteTimeIntegrator_DSTATE_c += localP->I_pr_Gain *
    localB->rtb_Subtract_p_idx_0 * localP->DiscreteTimeIntegrator_gainval_n;
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

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/I_yaw'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_d += localP->I_yaw_Gain *
    localB->rtb_Subtract_p_idx_1 * localP->DiscreteTimeIntegrator_gainval_d;

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

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_B.i = flightControlSystem_DW.RateTransition_ActiveBufIdx *
    6;
  for (flightControlSystem_B.i1 = 0; flightControlSystem_B.i1 < 6;
       flightControlSystem_B.i1++) {
    flightControlSystem_B.RateTransition[flightControlSystem_B.i1] =
      flightControlSystem_DW.RateTransition_Buffer[flightControlSystem_B.i1 +
      flightControlSystem_B.i];
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

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

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[0] = flightControlSystem_B.ControlSystem.Switch[0];

  /* Outport: '<Root>/Actuators' incorporates:
   *  SignalConversion generated from: '<Root>/Control System'
   */
  flightControlSystem_Y.Actuators[0] =
    flightControlSystem_B.ControlSystem.Switch[0];

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[1] = flightControlSystem_B.ControlSystem.Switch[1];

  /* Outport: '<Root>/Actuators' incorporates:
   *  SignalConversion generated from: '<Root>/Control System'
   */
  flightControlSystem_Y.Actuators[1] =
    flightControlSystem_B.ControlSystem.Switch[1];

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[2] = flightControlSystem_B.ControlSystem.Switch[2];

  /* Outport: '<Root>/Actuators' incorporates:
   *  SignalConversion generated from: '<Root>/Control System'
   */
  flightControlSystem_Y.Actuators[2] =
    flightControlSystem_B.ControlSystem.Switch[2];

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[3] = flightControlSystem_B.ControlSystem.Switch[3];

  /* Outport: '<Root>/Actuators' incorporates:
   *  SignalConversion generated from: '<Root>/Control System'
   */
  flightControlSystem_Y.Actuators[3] =
    flightControlSystem_B.ControlSystem.Switch[3];

  /* SignalConversion generated from: '<Root>/Control System' */
  flag_outport = flightControlSystem_B.ControlSystem.Merge;

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
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
  real_T bsum;
  real_T rtb_speed_circle;
  int32_T b_k;
  int32_T b_x_tmp;
  int32_T colNext;
  int32_T i;
  int32_T i_0;
  int32_T idxPix;
  int32_T ii;
  int32_T inCol;
  int32_T inIdx;
  int32_T jj;
  int32_T n;
  int32_T rtb_speed_line;
  boolean_T exitg1;
  boolean_T guard1;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  MW_Build_RGB(&imRGB[0], &flightControlSystem_B.uv[0],
               &flightControlSystem_B.uv1[0], &flightControlSystem_B.uv2[0]);

  /* MATLAB Function: '<S2>/Image Preprocessing' incorporates:
   *  MATLABSystem: '<S2>/PARROT Image Conversion'
   */
  for (ii = 0; ii < 19200; ii++) {
    flightControlSystem_B.u[ii] = flightControlSystem_B.uv[ii];
    flightControlSystem_B.u[ii + 19200] = flightControlSystem_B.uv1[ii];
    flightControlSystem_B.u[ii + 38400] = flightControlSystem_B.uv2[ii];
  }

  for (b_k = 0; b_k < 57600; b_k++) {
    flightControlSystem_B.Xin[b_k] = (real_T)flightControlSystem_B.u[b_k] /
      255.0;
  }

  for (b_k = 0; b_k < 19200; b_k++) {
    flightControlSystem_B.tmp = flightControlSystem_B.Xin[b_k];
    flightControlSystem_B.dist = flightControlSystem_B.Xin[b_k + 19200];
    bsum = flightControlSystem_B.Xin[b_k + 38400];
    rtb_speed_circle = flightControlSystem_B.tmp;
    flightControlSystem_B.delta = flightControlSystem_B.tmp;
    if (flightControlSystem_B.tmp < flightControlSystem_B.dist) {
      rtb_speed_circle = flightControlSystem_B.dist;
    }

    if (flightControlSystem_B.tmp > flightControlSystem_B.dist) {
      flightControlSystem_B.delta = flightControlSystem_B.dist;
    }

    if (rtb_speed_circle < bsum) {
      rtb_speed_circle = bsum;
    }

    if (flightControlSystem_B.delta > bsum) {
      flightControlSystem_B.delta = bsum;
    }

    flightControlSystem_B.delta = rtb_speed_circle - flightControlSystem_B.delta;
    flightControlSystem_B.s = flightControlSystem_B.delta;
    if (flightControlSystem_B.delta == 0.0) {
      flightControlSystem_B.s = 1.0;
    }

    flightControlSystem_B.h = 0.0;
    if (flightControlSystem_B.tmp == rtb_speed_circle) {
      flightControlSystem_B.h = (flightControlSystem_B.dist - bsum) /
        flightControlSystem_B.s;
    }

    if (flightControlSystem_B.dist == rtb_speed_circle) {
      flightControlSystem_B.h = (bsum - flightControlSystem_B.tmp) /
        flightControlSystem_B.s + 2.0;
    }

    if (bsum == rtb_speed_circle) {
      flightControlSystem_B.h = (flightControlSystem_B.tmp -
        flightControlSystem_B.dist) / flightControlSystem_B.s + 4.0;
    }

    flightControlSystem_B.h /= 6.0;
    if (flightControlSystem_B.h < 0.0) {
      flightControlSystem_B.h++;
    }

    flightControlSystem_B.tmp = flightControlSystem_B.s / rtb_speed_circle;
    if (flightControlSystem_B.delta == 0.0) {
      flightControlSystem_B.h = 0.0;
      flightControlSystem_B.tmp = 0.0;
    }

    if (!(rtb_speed_circle != 0.0)) {
      flightControlSystem_B.tmp = 0.0;
    }

    flightControlSystem_B.BW_b[b_k] = ((((flightControlSystem_B.h >= 0.0) &&
      (flightControlSystem_B.h <= 0.05)) || ((flightControlSystem_B.h >= 0.95) &&
      (flightControlSystem_B.h <= 1.0))) && ((flightControlSystem_B.tmp > 0.5) &&
      (rtb_speed_circle > 0.2)));
  }

  /* End of MATLAB Function: '<S2>/Image Preprocessing' */

  /* S-Function (svipmorphop): '<S2>/Dilation' */
  memset(&flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[0], 0, 20625U * sizeof
         (boolean_T));
  for (inIdx = 0; inIdx < 19200; inIdx++) {
    if (flightControlSystem_B.BW_b[inIdx]) {
      inCol = inIdx / 120;
      inCol = (inIdx - inCol * 120) + inCol * 125;
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW; i++) {
        flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[inCol +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[i]] = true;
      }
    }
  }

  inIdx = 126;
  inCol = 0;
  for (n = 0; n < 160; n++) {
    memcpy(&flightControlSystem_B.BW[inCol],
           &flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[inIdx], 120U * sizeof
           (boolean_T));
    inIdx += 125;
    inCol += 120;
  }

  /* End of S-Function (svipmorphop): '<S2>/Dilation' */

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes' incorporates:
   *  Constant: '<S2>/circle_pts'
   *  Constant: '<S2>/circle_size'
   */
  /* Copy the image from input to output. */
  memcpy(&flightControlSystem_B.DrawShapes[0],
         &flightControlSystem_P.circle_size_Value[0], 1444U * sizeof(real_T));

  /* Calculate FillColor times Opacity. */
  flightControlSystem_DW.DrawShapes_DW_FillColorAdd =
    flightControlSystem_P.DrawShapes_opacity;

  /* Calculate One minus Opacity. */
  flightControlSystem_DW.DrawShapes_DW_OneMOpacity = 1.0 -
    flightControlSystem_P.DrawShapes_opacity;

  /* Update view port. */
  /* Draw all circles. */
  flightControlSystem_B.dist = fabs(flightControlSystem_P.circle_pts_Value[1]);
  if (flightControlSystem_B.dist < 4.503599627370496E+15) {
    if (flightControlSystem_B.dist >= 0.5) {
      rtb_speed_circle = floor(flightControlSystem_P.circle_pts_Value[1] + 0.5);
    } else {
      rtb_speed_circle = flightControlSystem_P.circle_pts_Value[1] * 0.0;
    }
  } else {
    rtb_speed_circle = flightControlSystem_P.circle_pts_Value[1];
  }

  flightControlSystem_B.dist = fabs(flightControlSystem_P.circle_pts_Value[0]);
  if (flightControlSystem_B.dist < 4.503599627370496E+15) {
    if (flightControlSystem_B.dist >= 0.5) {
      flightControlSystem_B.tmp = floor(flightControlSystem_P.circle_pts_Value[0]
        + 0.5);
    } else {
      flightControlSystem_B.tmp = flightControlSystem_P.circle_pts_Value[0] *
        0.0;
    }
  } else {
    flightControlSystem_B.tmp = flightControlSystem_P.circle_pts_Value[0];
  }

  bsum = fabs(flightControlSystem_P.circle_pts_Value[2]);
  if (bsum < 4.503599627370496E+15) {
    if (bsum >= 0.5) {
      bsum = floor(flightControlSystem_P.circle_pts_Value[2] + 0.5);
    } else {
      bsum = flightControlSystem_P.circle_pts_Value[2] * 0.0;
    }
  } else {
    bsum = flightControlSystem_P.circle_pts_Value[2];
  }

  if (((int32_T)bsum >= 0) && ((int32_T)rtb_speed_circle - 1 >= -(int32_T)bsum) &&
      ((int32_T)rtb_speed_circle - 1 <= (int32_T)bsum + 37) && ((int32_T)
       flightControlSystem_B.tmp - 1 >= -(int32_T)bsum) && ((int32_T)
       flightControlSystem_B.tmp - 1 <= (int32_T)bsum + 37)) {
    inIdx = -(int32_T)bsum;
    inCol = -2 * (int32_T)bsum;
    n = (int32_T)bsum;
    if (((int32_T)flightControlSystem_B.tmp - 1 >= 0) && ((int32_T)
         flightControlSystem_B.tmp - 1 <= 37)) {
      i = ((int32_T)rtb_speed_circle - (int32_T)bsum) - 1;
      if (i < 0) {
        i = 0;
      }

      ii = ((int32_T)rtb_speed_circle + (int32_T)bsum) - 1;
      if (ii > 37) {
        ii = 37;
      }

      if (i <= ii) {
        if (flightControlSystem_B.dist < 4.503599627370496E+15) {
          if (flightControlSystem_B.dist >= 0.5) {
            flightControlSystem_B.dist = floor
              (flightControlSystem_P.circle_pts_Value[0] + 0.5);
          } else {
            flightControlSystem_B.dist = flightControlSystem_P.circle_pts_Value
              [0] * 0.0;
          }
        } else {
          flightControlSystem_B.dist = flightControlSystem_P.circle_pts_Value[0];
        }

        idxPix = ((int32_T)flightControlSystem_B.dist - 1) * 38 + i;
        while (i <= ii) {
          flightControlSystem_B.DrawShapes[idxPix] *=
            flightControlSystem_DW.DrawShapes_DW_OneMOpacity;
          flightControlSystem_B.DrawShapes[idxPix] +=
            flightControlSystem_DW.DrawShapes_DW_FillColorAdd;
          idxPix++;
          i++;
        }
      }
    }

    if (1 - (int32_T)bsum >= 0) {
      n = (int32_T)bsum - 1;
      inCol += 2;
      inIdx = inCol - (int32_T)bsum;
    }

    jj = 1;
    rtb_speed_line = 3;
    colNext = n;
    while ((jj <= n) || (((int32_T)bsum == 1) && (jj <= 1))) {
      idxPix = ((int32_T)flightControlSystem_B.tmp - jj) - 1;
      if ((idxPix >= 0) && (idxPix <= 37)) {
        i = ((int32_T)rtb_speed_circle - n) - 1;
        if (i < 0) {
          i = 0;
        }

        ii = ((int32_T)rtb_speed_circle + n) - 1;
        if (ii > 37) {
          ii = 37;
        }

        if (i <= ii) {
          idxPix = idxPix * 38 + i;
          while (i <= ii) {
            flightControlSystem_B.DrawShapes[idxPix] *=
              flightControlSystem_DW.DrawShapes_DW_OneMOpacity;
            flightControlSystem_B.DrawShapes[idxPix] +=
              flightControlSystem_DW.DrawShapes_DW_FillColorAdd;
            idxPix++;
            i++;
          }
        }
      }

      idxPix = ((int32_T)flightControlSystem_B.tmp + jj) - 1;
      if ((idxPix >= 0) && (idxPix <= 37)) {
        i = ((int32_T)rtb_speed_circle - n) - 1;
        if (i < 0) {
          i = 0;
        }

        ii = ((int32_T)rtb_speed_circle + n) - 1;
        if (ii > 37) {
          ii = 37;
        }

        if (i <= ii) {
          idxPix = idxPix * 38 + i;
          while (i <= ii) {
            flightControlSystem_B.DrawShapes[idxPix] *=
              flightControlSystem_DW.DrawShapes_DW_OneMOpacity;
            flightControlSystem_B.DrawShapes[idxPix] +=
              flightControlSystem_DW.DrawShapes_DW_FillColorAdd;
            idxPix++;
            i++;
          }
        }
      }

      if (inIdx + 4 >= 0) {
        colNext--;
        inCol += 2;
        inIdx += inCol;
      }

      rtb_speed_line += 2;
      inIdx += rtb_speed_line;
      if (((n != colNext) && (jj < n)) || (jj + 1 == n)) {
        idxPix = ((int32_T)flightControlSystem_B.tmp - n) - 1;
        if ((idxPix >= 0) && (idxPix <= 37)) {
          i = ((int32_T)rtb_speed_circle - jj) - 1;
          if (i < 0) {
            i = 0;
          }

          ii = ((int32_T)rtb_speed_circle + jj) - 1;
          if (ii > 37) {
            ii = 37;
          }

          if (i <= ii) {
            idxPix = idxPix * 38 + i;
            while (i <= ii) {
              flightControlSystem_B.DrawShapes[idxPix] *=
                flightControlSystem_DW.DrawShapes_DW_OneMOpacity;
              flightControlSystem_B.DrawShapes[idxPix] +=
                flightControlSystem_DW.DrawShapes_DW_FillColorAdd;
              idxPix++;
              i++;
            }
          }
        }

        idxPix = ((int32_T)flightControlSystem_B.tmp + n) - 1;
        if ((idxPix >= 0) && (idxPix <= 37)) {
          i = ((int32_T)rtb_speed_circle - jj) - 1;
          if (i < 0) {
            i = 0;
          }

          ii = ((int32_T)rtb_speed_circle + jj) - 1;
          if (ii > 37) {
            ii = 37;
          }

          if (i <= ii) {
            idxPix = idxPix * 38 + i;
            while (i <= ii) {
              flightControlSystem_B.DrawShapes[idxPix] *=
                flightControlSystem_DW.DrawShapes_DW_OneMOpacity;
              flightControlSystem_B.DrawShapes[idxPix] +=
                flightControlSystem_DW.DrawShapes_DW_FillColorAdd;
              idxPix++;
              i++;
            }
          }
        }
      }

      jj++;
      n = colNext;
    }
  }

  /* End of S-Function (svipdrawshapes): '<S2>/Draw Shapes' */

  /* MATLAB Function: '<S2>/Boundary Detection' incorporates:
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes'
   *  S-Function (svipmorphop): '<S2>/Dilation'
   */
  inIdx = 0;
  inCol = 0;
  n = 0;
  rtb_speed_circle = 0.0;
  for (b_k = 0; b_k < 160; b_k++) {
    for (i_0 = 0; i_0 < 60; i_0++) {
      flightControlSystem_B.x[i_0 + 60 * b_k] = flightControlSystem_B.BW[120 *
        b_k + i_0];
    }
  }

  i = -1;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 160)) {
    guard1 = false;
    if (flightControlSystem_B.x[((jj - 1) * 60 + ii) - 1]) {
      i++;
      flightControlSystem_B.b_i_data[i] = ii;
      flightControlSystem_B.b_j_data[i] = (uint8_T)jj;
      if (i + 1 >= 9600) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 60) {
        ii = 1;
        jj++;
      }
    }
  }

  if (i + 1 < 1) {
    i = -1;
    b_k = -1;
  } else {
    b_k = i;
  }

  ii = b_k + 1;
  if (i + 1 == 0) {
    flightControlSystem_B.tmp = 0.0;
    jj = 0;
    rtb_speed_line = 50;
  } else {
    if (i + 1 <= 2) {
      if (i + 1 == 1) {
        i = 0;
      } else if (flightControlSystem_B.b_i_data[0] <=
                 flightControlSystem_B.b_i_data[i]) {
        i = 0;
      }
    } else {
      jj = flightControlSystem_B.b_i_data[0];
      i = 0;
      for (rtb_speed_line = 2; rtb_speed_line <= ii; rtb_speed_line++) {
        colNext = flightControlSystem_B.b_i_data[rtb_speed_line - 1];
        if (jj > colNext) {
          jj = colNext;
          i = rtb_speed_line - 1;
        }
      }
    }

    flightControlSystem_B.tmp = 60.0 - (real_T)flightControlSystem_B.b_i_data[i];
    jj = flightControlSystem_B.b_j_data[i] - 80;
    rtb_speed_line = 100;
    flightControlSystem_B.dist = 0.0;
    colNext = 0;
    idxPix = -61;
    for (i = 0; i < 82; i++) {
      for (ii = 0; ii < 122; ii++) {
        for (b_k = 0; b_k < 38; b_k++) {
          for (i_0 = 0; i_0 < 38; i_0++) {
            b_x_tmp = 38 * b_k + i_0;
            flightControlSystem_B.b_x[b_x_tmp] = ((int32_T)
              flightControlSystem_B.BW[((ii + b_k) * 120 + i) + i_0] ==
              (flightControlSystem_B.DrawShapes[b_x_tmp] != 0.0));
          }
        }

        flightControlSystem_B.delta = flightControlSystem_B.b_x[0];
        for (b_k = 0; b_k < 1023; b_k++) {
          flightControlSystem_B.delta += (real_T)flightControlSystem_B.b_x[b_k +
            1];
        }

        bsum = flightControlSystem_B.b_x[1024];
        for (b_k = 0; b_k < 419; b_k++) {
          bsum += (real_T)flightControlSystem_B.b_x[b_k + 1025];
        }

        bsum += flightControlSystem_B.delta;
        if (bsum > flightControlSystem_B.dist) {
          flightControlSystem_B.dist = bsum;
          colNext = i + 1;
          idxPix = ii - 60;
        }
      }
    }

    if (flightControlSystem_B.dist >= 1300.0) {
      n = 1;
      inIdx = 41 - colNext;
      inCol = idxPix;
      flightControlSystem_B.dist = sqrt((41 - colNext) * (41 - colNext) + idxPix
        * idxPix);
      rtb_speed_circle = 2.0 * flightControlSystem_B.dist;
      if (flightControlSystem_B.dist < 30.0) {
        rtb_speed_circle *= 20.0;
      }

      if (!(rtb_speed_circle <= 120.0)) {
        rtb_speed_circle = 120.0;
      }
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  MATLAB Function: '<S2>/Boundary Detection'
   */
  flightControlSystem_DW.RateTransition_Buffer
    [(flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] =
    flightControlSystem_B.tmp;
  flightControlSystem_DW.RateTransition_Buffer[1 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = jj;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_DW.RateTransition_Buffer[2 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = inIdx;
  flightControlSystem_DW.RateTransition_Buffer[3 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = inCol;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_DW.RateTransition_Buffer[4 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = n;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Switch: '<S2>/Switch' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  if (!(n > flightControlSystem_P.Switch_Threshold)) {
    rtb_speed_circle = rtb_speed_line;
  }

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Constant: '<S2>/speed_const'
   *  Product: '<S2>/Divide'
   *  Switch: '<S2>/Switch'
   */
  flightControlSystem_DW.RateTransition_Buffer[5 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] =
    rtb_speed_circle / flightControlSystem_P.speed_const_Value;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_DW.RateTransition_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0);
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

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  {
    int32_T idxOffsets;
    int32_T m;
    int32_T n;

    /* SetupRuntimeResources for Atomic SubSystem: '<Root>/Control System' */
    flightControlSystem_ControlSystem_SetupRTR(flightControlSystem_M,
      &flightControlSystem_DW.ControlSystem);

    /* End of SetupRuntimeResources for SubSystem: '<Root>/Control System' */

    /* Start for Atomic SubSystem: '<Root>/Control System' */
    flightControlSystem_ControlSystem_Start
      (&flightControlSystem_DW.ControlSystem);

    /* End of Start for SubSystem: '<Root>/Control System' */

    /* Start for Atomic SubSystem: '<Root>/Image Processing System' */
    /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
    flightControlSystem_DW.objisempty = true;
    flightControlSystem_DW.obj.isInitialized = 1;

    /* Start for S-Function (svipmorphop): '<S2>/Dilation' */
    idxOffsets = 0;
    flightControlSystem_DW.Dilation_NUMNONZ_DW = 0;
    for (n = 0; n < 3; n++) {
      for (m = 0; m < 3; m++) {
        flightControlSystem_DW.Dilation_DILATE_OFF_DW[idxOffsets] = n * 125 + m;
        idxOffsets = flightControlSystem_DW.Dilation_NUMNONZ_DW + 1;
        flightControlSystem_DW.Dilation_NUMNONZ_DW++;
      }
    }

    /* End of Start for S-Function (svipmorphop): '<S2>/Dilation' */

    /* Start for S-Function (svipdrawshapes): '<S2>/Draw Shapes' */
    /* Calculate FillColor times Opacity. */
    flightControlSystem_DW.DrawShapes_DW_FillColorAdd =
      flightControlSystem_P.DrawShapes_opacity;

    /* Calculate One minus Opacity. */
    flightControlSystem_DW.DrawShapes_DW_OneMOpacity = 1.0 -
      flightControlSystem_P.DrawShapes_opacity;

    /* End of Start for SubSystem: '<Root>/Image Processing System' */
  }

  flightControlSystem_PrevZCX.ControlSystem.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    for (i = 0; i < 6; i++) {
      flightControlSystem_DW.RateTransition_Buffer[i] =
        flightControlSystem_P.RateTransition_InitialCondition;
    }

    /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
    flightControlSystem_ControlSystem_Init(&flightControlSystem_B.ControlSystem,
      &flightControlSystem_DW.ControlSystem,
      &flightControlSystem_P.ControlSystem);

    /* End of SystemInitialize for SubSystem: '<Root>/Control System' */
  }
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
