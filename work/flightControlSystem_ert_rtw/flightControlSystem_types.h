/*
 * flightControlSystem_types.h
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

#ifndef flightControlSystem_types_h_
#define flightControlSystem_types_h_
#include "rtwtypes.h"
#include "C:\ProgramData\MATLAB\SupportPackages\R2024b\toolbox\target\supportpackages\parrot\include\HAL.h"
#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_

typedef struct {
  real32_T opticalFlow_data[3];
  real32_T posVIS_data[4];
  real32_T usePosVIS_flag;
} extraSensorData_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_

typedef struct {
  extraSensorData_t VisionSensors;
  HAL_acquisition_t HALSensors;
  real32_T SensorCalibration[8];
} SensorsBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eF5OUT33sX0T9pzS8027m_
#define DEFINED_TYPEDEF_FOR_struct_eF5OUT33sX0T9pzS8027m_

typedef struct {
  real_T cg[3];
  real_T location[3];
  real_T accNatFreq;
  real_T accDamping;
  real_T accScaleCross[9];
  real_T accBias[3];
  real_T accLimits[6];
  real_T gyroNatFreq;
  real_T gyroDamping;
  real_T gyroScaleCross[9];
  real_T gyroBias[3];
  real_T gyroGBias[3];
  real_T gyroLimits[6];
  real_T noiseSeeds[6];
  real_T noiseWeights[6];
  real_T noisePower[6];
} struct_eF5OUT33sX0T9pzS8027m;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_FIfaVnupBjYAxo1EdNiDlF_
#define DEFINED_TYPEDEF_FOR_struct_FIfaVnupBjYAxo1EdNiDlF_

typedef struct {
  real_T noisePower;
  real_T noiseSeeds;
} struct_FIfaVnupBjYAxo1EdNiDlF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eFnp8sKFNJLN84XLbLzaFF_
#define DEFINED_TYPEDEF_FOR_struct_eFnp8sKFNJLN84XLbLzaFF_

typedef struct {
  real_T posVISNoVisionAvail[4];
  real_T usePosVISFlag;
  real_T batteryStatus[2];
} struct_eFnp8sKFNJLN84XLbLzaFF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8SSZ93PxvPkADZcA4gG8MD_
#define DEFINED_TYPEDEF_FOR_struct_8SSZ93PxvPkADZcA4gG8MD_

typedef struct {
  real_T IMUAccelGain[3];
  real_T IMUGyroGain[3];
  struct_eF5OUT33sX0T9pzS8027m IMU;
  struct_FIfaVnupBjYAxo1EdNiDlF Sonar;
  real_T NO_VIS_X;
  real_T NO_VIS_YAW;
  struct_eFnp8sKFNJLN84XLbLzaFF dummy;
  real_T sensorDelay;
  real_T airDensity;
  real_T altToPrsGain;
  real_T altToPrsBias;
  real_T inverseIMUGain[6];
  real_T altSensorMin;
  real_T velocityToOpticalFlowGain;
} struct_8SSZ93PxvPkADZcA4gG8MD;

#endif

#ifndef struct_tag_5e8GnIx8R8RPYwO85WQu3D
#define struct_tag_5e8GnIx8R8RPYwO85WQu3D

struct tag_5e8GnIx8R8RPYwO85WQu3D
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_5e8GnIx8R8RPYwO85WQu3D */

#ifndef typedef_parrot_ImageProcess_flightControlSystem_T
#define typedef_parrot_ImageProcess_flightControlSystem_T

typedef struct tag_5e8GnIx8R8RPYwO85WQu3D
  parrot_ImageProcess_flightControlSystem_T;

#endif                   /* typedef_parrot_ImageProcess_flightControlSystem_T */

/* Custom Type definition for MATLAB Function: '<S2>/MATLAB Function' */
#ifndef struct_tag_sOA5t73y81YtFHGIDxk0fKF
#define struct_tag_sOA5t73y81YtFHGIDxk0fKF

struct tag_sOA5t73y81YtFHGIDxk0fKF
{
  real_T WeightedCentroid[2];
};

#endif                                 /* struct_tag_sOA5t73y81YtFHGIDxk0fKF */

#ifndef typedef_sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T
#define typedef_sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T

typedef struct tag_sOA5t73y81YtFHGIDxk0fKF
  sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T;

#endif               /* typedef_sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T */

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

#endif                                 /* struct_emxArray_real_T */

#ifndef typedef_emxArray_real_T_flightControlSystem_T
#define typedef_emxArray_real_T_flightControlSystem_T

typedef struct emxArray_real_T emxArray_real_T_flightControlSystem_T;

#endif                       /* typedef_emxArray_real_T_flightControlSystem_T */

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_uint32_T */

#ifndef typedef_emxArray_uint32_T_flightControlSystem_T
#define typedef_emxArray_uint32_T_flightControlSystem_T

typedef struct emxArray_uint32_T emxArray_uint32_T_flightControlSystem_T;

#endif                     /* typedef_emxArray_uint32_T_flightControlSystem_T */

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

#endif                                 /* struct_emxArray_int32_T */

#ifndef typedef_emxArray_int32_T_flightControlSystem_T
#define typedef_emxArray_int32_T_flightControlSystem_T

typedef struct emxArray_int32_T emxArray_int32_T_flightControlSystem_T;

#endif                      /* typedef_emxArray_int32_T_flightControlSystem_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_boolean_T */

#ifndef typedef_emxArray_boolean_T_flightControlSystem_T
#define typedef_emxArray_boolean_T_flightControlSystem_T

typedef struct emxArray_boolean_T emxArray_boolean_T_flightControlSystem_T;

#endif                    /* typedef_emxArray_boolean_T_flightControlSystem_T */

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real32_T */

#ifndef typedef_emxArray_real32_T_flightControlSystem_T
#define typedef_emxArray_real32_T_flightControlSystem_T

typedef struct emxArray_real32_T emxArray_real32_T_flightControlSystem_T;

#endif                     /* typedef_emxArray_real32_T_flightControlSystem_T */

#ifndef typedef_emxArray_creal_T_flightControlSystem_T
#define typedef_emxArray_creal_T_flightControlSystem_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T_flightControlSystem_T;

#endif                      /* typedef_emxArray_creal_T_flightControlSystem_T */

#ifndef struct_emxArray_tag_sOA5t73y81YtFHGIDx
#define struct_emxArray_tag_sOA5t73y81YtFHGIDx

struct emxArray_tag_sOA5t73y81YtFHGIDx
{
  sOA5t73y81YtFHGIDxk0fKF_flightControlSystem_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                              /* struct_emxArray_tag_sOA5t73y81YtFHGIDx */

#ifndef typedef_emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T
#define typedef_emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T

typedef struct emxArray_tag_sOA5t73y81YtFHGIDx
  emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T;

#endif       /* typedef_emxArray_sOA5t73y81YtFHGIDxk0fK_flightControlSystem_T */

#ifndef struct_tag_Xor1beQa71R3Egpz66x3XD
#define struct_tag_Xor1beQa71R3Egpz66x3XD

struct tag_Xor1beQa71R3Egpz66x3XD
{
  emxArray_real_T_flightControlSystem_T *f1;
};

#endif                                 /* struct_tag_Xor1beQa71R3Egpz66x3XD */

#ifndef typedef_cell_wrap_36_flightControlSystem_T
#define typedef_cell_wrap_36_flightControlSystem_T

typedef struct tag_Xor1beQa71R3Egpz66x3XD cell_wrap_36_flightControlSystem_T;

#endif                          /* typedef_cell_wrap_36_flightControlSystem_T */

#ifndef struct_emxArray_tag_Xor1beQa71R3Egpz66
#define struct_emxArray_tag_Xor1beQa71R3Egpz66

struct emxArray_tag_Xor1beQa71R3Egpz66
{
  cell_wrap_36_flightControlSystem_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                              /* struct_emxArray_tag_Xor1beQa71R3Egpz66 */

#ifndef typedef_emxArray_cell_wrap_36_flightControlSystem_T
#define typedef_emxArray_cell_wrap_36_flightControlSystem_T

typedef struct emxArray_tag_Xor1beQa71R3Egpz66
  emxArray_cell_wrap_36_flightControlSystem_T;

#endif                 /* typedef_emxArray_cell_wrap_36_flightControlSystem_T */

#ifndef struct_emxArray_int16_T
#define struct_emxArray_int16_T

struct emxArray_int16_T
{
  int16_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_int16_T */

#ifndef typedef_emxArray_int16_T_flightControlSystem_T
#define typedef_emxArray_int16_T_flightControlSystem_T

typedef struct emxArray_int16_T emxArray_int16_T_flightControlSystem_T;

#endif                      /* typedef_emxArray_int16_T_flightControlSystem_T */

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T

struct emxArray_int8_T
{
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_int8_T */

#ifndef typedef_emxArray_int8_T_flightControlSystem_T
#define typedef_emxArray_int8_T_flightControlSystem_T

typedef struct emxArray_int8_T emxArray_int8_T_flightControlSystem_T;

#endif                       /* typedef_emxArray_int8_T_flightControlSystem_T */

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_uint8_T */

#ifndef typedef_emxArray_uint8_T_flightControlSystem_T
#define typedef_emxArray_uint8_T_flightControlSystem_T

typedef struct emxArray_uint8_T emxArray_uint8_T_flightControlSystem_T;

#endif                      /* typedef_emxArray_uint8_T_flightControlSystem_T */

#ifndef struct_emxArray_boolean_T_0x0
#define struct_emxArray_boolean_T_0x0

struct emxArray_boolean_T_0x0
{
  int32_T size[2];
};

#endif                                 /* struct_emxArray_boolean_T_0x0 */

#ifndef typedef_emxArray_boolean_T_0x0_flightControlSystem_T
#define typedef_emxArray_boolean_T_0x0_flightControlSystem_T

typedef struct emxArray_boolean_T_0x0
  emxArray_boolean_T_0x0_flightControlSystem_T;

#endif                /* typedef_emxArray_boolean_T_0x0_flightControlSystem_T */

#ifndef struct_emxArray_real_T_1x0
#define struct_emxArray_real_T_1x0

struct emxArray_real_T_1x0
{
  int32_T size[2];
};

#endif                                 /* struct_emxArray_real_T_1x0 */

#ifndef typedef_emxArray_real_T_1x0_flightControlSystem_T
#define typedef_emxArray_real_T_1x0_flightControlSystem_T

typedef struct emxArray_real_T_1x0 emxArray_real_T_1x0_flightControlSystem_T;

#endif                   /* typedef_emxArray_real_T_1x0_flightControlSystem_T */

/* Custom Type definition for MATLAB Function: '<S2>/MATLAB Function' */
#ifndef struct_tag_R6Og1x0kmqQXSF9Pwa49FD
#define struct_tag_R6Og1x0kmqQXSF9Pwa49FD

struct tag_R6Og1x0kmqQXSF9Pwa49FD
{
  real_T Area;
  real_T Centroid[2];
  real_T BoundingBox[4];
  real_T MajorAxisLength;
  real_T MinorAxisLength;
  real_T Eccentricity;
  real_T Orientation;
  emxArray_boolean_T_0x0_flightControlSystem_T Image;
  emxArray_boolean_T_0x0_flightControlSystem_T FilledImage;
  real_T FilledArea;
  real_T EulerNumber;
  real_T Extrema[16];
  real_T EquivDiameter;
  real_T Extent;
  emxArray_real_T_flightControlSystem_T *PixelIdxList;
  emxArray_real_T_flightControlSystem_T *PixelList;
  real_T Perimeter;
  real_T Circularity;
  emxArray_real_T_flightControlSystem_T *PixelValues;
  real_T WeightedCentroid[2];
  real_T MeanIntensity;
  real_T MinIntensity;
  real_T MaxIntensity;
  emxArray_real_T_1x0_flightControlSystem_T SubarrayIdx;
  real_T SubarrayIdxLengths[2];
};

#endif                                 /* struct_tag_R6Og1x0kmqQXSF9Pwa49FD */

#ifndef typedef_s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T
#define typedef_s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T

typedef struct tag_R6Og1x0kmqQXSF9Pwa49FD
  s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T;

#endif              /* typedef_s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T */

#ifndef struct_emxArray_tag_R6Og1x0kmqQXSF9Pwa
#define struct_emxArray_tag_R6Og1x0kmqQXSF9Pwa

struct emxArray_tag_R6Og1x0kmqQXSF9Pwa
{
  s_R6Og1x0kmqQXSF9Pwa49FD_flightControlSystem_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                              /* struct_emxArray_tag_R6Og1x0kmqQXSF9Pwa */

#ifndef typedef_emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T
#define typedef_emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T

typedef struct emxArray_tag_R6Og1x0kmqQXSF9Pwa
  emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T;

#endif       /* typedef_emxArray_s_R6Og1x0kmqQXSF9Pwa49_flightControlSystem_T */

/* Parameters for system: '<S4>/Geofencing error' */
typedef struct P_Geofencingerror_flightControlSystem_T_
  P_Geofencingerror_flightControlSystem_T;

/* Parameters for system: '<S341>/MeasurementUpdate' */
typedef struct P_MeasurementUpdate_flightControlSystem_T_
  P_MeasurementUpdate_flightControlSystem_T;

/* Parameters for system: '<S348>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_flightControlSystem_T_
  P_EnabledSubsystem_flightControlSystem_T;

/* Parameters for system: '<Root>/Control System' */
typedef struct P_ControlSystem_flightControlSystem_T_
  P_ControlSystem_flightControlSystem_T;

/* Parameters (default storage) */
typedef struct P_flightControlSystem_T_ P_flightControlSystem_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_flightControlSystem_T RT_MODEL_flightControlSystem_T;

#endif                                 /* flightControlSystem_types_h_ */
