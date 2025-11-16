/*
 * flightControlSystem_data.c
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

/* Block parameters (default storage) */
P_flightControlSystem_T flightControlSystem_P = {
  /* Variable: Sensors
   * Referenced by:
   *   '<S256>/SaturationSonar'
   *   '<S310>/Constant'
   */
  {
    { 1.00596, 1.00383, 0.99454 },

    { 0.99861, 1.00644, 0.99997 },

    {
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0 },
      190.0,
      0.707,

      { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

      { 0.09, -0.06, 0.33699999999999974 },

      { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
      190.0,
      0.707,

      { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

      { -0.0095, -0.0075, 0.0015 },

      { 0.0, 0.0, 0.0 },

      { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

      { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

      { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

      { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
        1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
    },

    {
      1.0,
      41.0
    },
    -99.0,
    -9.0,

    {
      { -99.0, 0.0, 0.0, -9.0 },
      0.0,

      { 3.5, 70.0 }
    },
    1.0,
    1.225,
    12.01725,
    101270.95,

    { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
      1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
    0.44,
    1.0
  },

  /* Mask Parameter: DrawShapes_opacity
   * Referenced by: '<S2>/Draw Shapes'
   */
  1.0,

  /* Expression: [19, 19, 19]
   * Referenced by: '<S2>/circle_pts'
   */
  { 19.0, 19.0, 19.0 },

  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0  */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 15000000
   * Referenced by: '<S2>/speed_const'
   */
  1.5E+7,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0,

  /* Start of '<Root>/Control System' */
  {
    /* Mask Parameter: outlierBelowFloor_const
     * Referenced by: '<S258>/Constant'
     */
    0.0,

    /* Mask Parameter: outlierJump_const
     * Referenced by: '<S313>/Constant'
     */
    0.1,

    /* Mask Parameter: currentEstimateVeryOffFromPressure_const
     * Referenced by: '<S311>/Constant'
     */
    0.8,

    /* Mask Parameter: currentStateVeryOffsonarflt_const
     * Referenced by: '<S312>/Constant'
     */
    0.4,

    /* Mask Parameter: Checkerrorcondition_const
     * Referenced by: '<S235>/Constant'
     */
    -1.0,

    /* Mask Parameter: u0continuousOFerrors_const
     * Referenced by: '<S234>/Constant'
     */
    50.0,

    /* Mask Parameter: Angularvelocitycontrolloop_D
     * Referenced by: '<S100>/Derivative Gain'
     */
    { 0.00012F, 9.72E-5F },

    /* Mask Parameter: Angularvelocitycontrolloop_I
     * Referenced by: '<S104>/Integral Gain'
     */
    { 0.006F, 0.00486F },

    /* Mask Parameter: Velocitycontroller_I
     * Referenced by: '<S213>/Integral Gain'
     */
    0.1F,

    /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
     * Referenced by: '<S448>/UD'
     */
    0.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForFilter
     * Referenced by: '<S102>/Filter'
     */
    0.0F,

    /* Mask Parameter: Velocitycontroller_InitialConditionForIntegrator
     * Referenced by: '<S216>/Integrator'
     */
    0.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_InitialConditionForIntegrator
     * Referenced by: '<S107>/Integrator'
     */
    0.0F,

    /* Mask Parameter: Positioncontroller_LowerSaturationLimit
     * Referenced by: '<S169>/Saturation'
     */
    -0.5F,

    /* Mask Parameter: Velocitycontroller_LowerSaturationLimit
     * Referenced by:
     *   '<S223>/Saturation'
     *   '<S208>/DeadZone'
     */
    -0.34906584F,

    /* Mask Parameter: Angularvelocitycontrolloop_LowerSaturationLimit
     * Referenced by:
     *   '<S114>/Saturation'
     *   '<S99>/DeadZone'
     */
    -0.02F,

    /* Mask Parameter: Angularvelocitycontrolloop_N
     * Referenced by: '<S110>/Filter Coefficient'
     */
    { 70.0F, 70.0F },

    /* Mask Parameter: Positioncontroller_P
     * Referenced by: '<S167>/Proportional Gain'
     */
    0.7F,

    /* Mask Parameter: Velocitycontroller_P
     * Referenced by: '<S221>/Proportional Gain'
     */
    0.2F,

    /* Mask Parameter: Anglecontrolloop_P
     * Referenced by: '<S58>/Proportional Gain'
     */
    4.0F,

    /* Mask Parameter: Angularvelocitycontrolloop_P
     * Referenced by: '<S112>/Proportional Gain'
     */
    { 0.003F, 0.00243F },

    /* Mask Parameter: Positioncontroller_UpperSaturationLimit
     * Referenced by: '<S169>/Saturation'
     */
    0.5F,

    /* Mask Parameter: Velocitycontroller_UpperSaturationLimit
     * Referenced by:
     *   '<S223>/Saturation'
     *   '<S208>/DeadZone'
     */
    0.34906584F,

    /* Mask Parameter: Angularvelocitycontrolloop_UpperSaturationLimit
     * Referenced by:
     *   '<S114>/Saturation'
     *   '<S99>/DeadZone'
     */
    0.02F,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S315>/Constant'
     */
    6.867F,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S316>/Constant'
     */
    12.753F,

    /* Mask Parameter: maxp_const
     * Referenced by: '<S451>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxq_const
     * Referenced by: '<S453>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxw1_const
     * Referenced by: '<S455>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxw2_const
     * Referenced by: '<S456>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxdw1_const
     * Referenced by: '<S449>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxdw2_const
     * Referenced by: '<S450>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxp2_const
     * Referenced by: '<S452>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxq2_const
     * Referenced by: '<S454>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxw3_const
     * Referenced by: '<S457>/Constant'
     */
    5.0F,

    /* Mask Parameter: maxw4_const
     * Referenced by: '<S458>/Constant'
     */
    5.0F,

    /* Mask Parameter: minHeightforOF_const
     * Referenced by: '<S459>/Constant'
     */
    -0.4F,

    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S443>/Constant'
     */
    -0.4F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
     * Referenced by: '<S445>/Constant'
     */
    0.0F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
     * Referenced by: '<S446>/Constant'
     */
    0.0F,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S238>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S240>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S239>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S241>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant_const_j
     * Referenced by: '<S236>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant1_const_e
     * Referenced by: '<S237>/Constant'
     */
    10.0F,

    /* Mask Parameter: WrapToZero_Threshold
     * Referenced by: '<S249>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_k
     * Referenced by: '<S516>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_e
     * Referenced by: '<S435>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: CompareToConstant_const_l
     * Referenced by: '<S431>/Constant'
     */
    1U,

    /* Mask Parameter: CompareToConstant_const_h
     * Referenced by: '<S513>/Constant'
     */
    800U,

    /* Mask Parameter: WrapToZero_Threshold_c
     * Referenced by: '<S16>/FixPt Switch'
     */
    65535U,

    /* Mask Parameter: CompareToConstant_const_c
     * Referenced by: '<S13>/Constant'
     */
    100U,

    /* Expression: 0
     * Referenced by: '<S4>/ '
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S307>/L*(y[k]-yhat[k|k-1])'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S309>/deltax'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S429>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S251>/Delay2'
     */
    0.0,

    /* Expression: pInitialization.X0
     * Referenced by: '<S255>/X0'
     */
    { -0.046, 0.0 },

    /* Expression: -inf
     * Referenced by: '<S256>/SaturationSonar'
     */
    0.0,

    /* Expression: Estimator.alt.filterSonarNum
     * Referenced by: '<S256>/sonarFilter_IIR'
     */
    { 3.7568380197512489E-6, 1.1270514059253748E-5, 1.1270514059253748E-5,
      3.7568380197512489E-6 },

    /* Expression: Estimator.alt.filterSonarDen
     * Referenced by: '<S256>/sonarFilter_IIR'
     */
    { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

    /* Expression: 0
     * Referenced by: '<S256>/sonarFilter_IIR'
     */
    0.0,

    /* Expression: pInitialization.M
     * Referenced by: '<S259>/KalmanGainM'
     */
    { 0.026241420641871391, 0.069776736071492484 },

    /* Expression: pInitialization.C
     * Referenced by: '<S255>/C'
     */
    { 1.0, 0.0 },

    /* Expression: pInitialization.M
     * Referenced by: '<S322>/KalmanGainM'
     */
    { 0.0011869299883613858, -3.2868164179504482E-5 },

    /* Expression: pInitialization.M
     * Referenced by: '<S376>/KalmanGainM'
     */
    { 0.0011869299883613858, -3.2868164179504482E-5 },

    /* Expression: pInitialization.M
     * Referenced by: '<S460>/KalmanGainM'
     */
    { 0.066408162001371465, 0.0, -0.021605460397766958, 0.0, 0.0,
      0.066408162001371465, 0.0, -0.021605460397766958 },

    /* Expression: pInitialization.L
     * Referenced by: '<S460>/KalmanGainL'
     */
    { 0.066516189303360257, 4.5053399924773407E-19, -0.021605460397767236,
      2.4451005888416897E-19, -1.4532182529622698E-18, 0.066516189303360257,
      4.1595130505436516E-18, -0.021605460397767229 },

    /* Expression: [0 0 -g]
     * Referenced by: '<S438>/gravity'
     */
    { 0.0, 0.0, -9.81 },

    /* Expression: 1
     * Referenced by: '<S438>/gainaccinput1'
     */
    1.0,

    /* Expression: -1.1
     * Referenced by: '<S5>/Constant'
     */
    -1.1,

    /* Expression: 0
     * Referenced by: '<S3>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S12>/Switch'
     */
    0.0,

    /* Expression: pInitialization.A
     * Referenced by: '<S255>/A'
     */
    { 1.0, 0.0, 0.005, 1.0 },

    /* Expression: [0 0 g]
     * Referenced by: '<S251>/gravity'
     */
    { 0.0, 0.0, 9.81 },

    /* Expression: pInitialization.L
     * Referenced by: '<S376>/KalmanGainL'
     */
    { 0.0011870943291822833, -3.2868164179504543E-5 },

    /* Expression: pInitialization.L
     * Referenced by: '<S322>/KalmanGainL'
     */
    { 0.0011870943291822833, -3.2868164179504543E-5 },

    /* Expression: pInitialization.B
     * Referenced by: '<S255>/B'
     */
    { 0.0, 0.005 },

    /* Expression: pInitialization.D
     * Referenced by: '<S255>/D'
     */
    0.0,

    /* Expression: pInitialization.L
     * Referenced by: '<S259>/KalmanGainL'
     */
    { 0.026590304322228815, 0.06977673607149136 },

    /* Expression: 200*3
     * Referenced by: '<S4>/Wait  3 Seconds'
     */
    600.0,

    /* Expression: 0.0
     * Referenced by: '<S4>/Delay One Step'
     */
    0.0,

    /* Expression: 0.5
     * Referenced by: '<S4>/0.5 meters'
     */
    0.5,

    /* Expression: pInitialization.Z
     * Referenced by: '<S460>/CovarianceZ'
     */
    { 1.3281632400274295, 0.0, -0.43210920795533914, 0.0, 0.0,
      1.3281632400274295, 0.0, -0.43210920795533914, -0.43210920795533914, 0.0,
      6.147349862376486, 0.0, 0.0, -0.43210920795533914, 0.0, 6.147349862376486
    },

    /* Expression: pInitialization.Z
     * Referenced by: '<S259>/CovarianceZ'
     */
    { 0.0026241420641871386, 0.0069776736071492486, 0.0069776736071492486,
      0.037607692935053887 },

    /* Expression: pInitialization.P0
     * Referenced by: '<S255>/P0'
     */
    { 0.0026948589925820136, 0.0071657120718245319, 0.0071657120718245319,
      0.038107692935053894 },

    /* Expression: pInitialization.Z
     * Referenced by: '<S322>/CovarianceZ'
     */
    { 1097.3834951566071, -30.388465402648372, -30.388465402648375,
      7.2223686232287516 },

    /* Expression: pInitialization.Z
     * Referenced by: '<S376>/CovarianceZ'
     */
    { 1097.3834951566071, -30.388465402648372, -30.388465402648375,
      7.2223686232287516 },

    /* Expression: pInitialization.G
     * Referenced by: '<S255>/G'
     */
    { 0.0, 1.0 },

    /* Expression: 1
     * Referenced by: '<S5>/Constant1'
     */
    1.0,

    /* Expression: pInitialization.H
     * Referenced by: '<S255>/H'
     */
    0.0,

    /* Expression: pInitialization.N
     * Referenced by: '<S255>/N'
     */
    0.0,

    /* Expression: pInitialization.Q
     * Referenced by: '<S255>/Q'
     */
    0.0005,

    /* Expression: pInitialization.R
     * Referenced by: '<S255>/R'
     */
    0.1,

    /* Expression: Controller.takeoffGain
     * Referenced by: '<S7>/takeoff_gain1'
     */
    0.45F,

    /* Computed Parameter: P_z1_Gain
     * Referenced by: '<S7>/P_z1'
     */
    0.8F,

    /* Computed Parameter: D_z1_Gain
     * Referenced by: '<S7>/D_z1'
     */
    0.5F,

    /* Computed Parameter: Pitchcorrection_Value
     * Referenced by: '<S9>/Pitch correction'
     */
    0.002F,

    /* Computed Parameter: zerocorrection_Value
     * Referenced by: '<S9>/zero correction'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain
     * Referenced by: '<S10>/Gain'
     */
    { -1.0F, 1.0F },

    /* Computed Parameter: Gain1_Gain
     * Referenced by: '<S12>/Gain1'
     */
    { 0.8F, -0.8F, 0.8F, -0.8F },

    /* Computed Parameter: Gain2_Gain
     * Referenced by: '<S12>/Gain2'
     */
    { 1.0F, -1.0F, 1.0F, -1.0F },

    /* Computed Parameter: _Value_i
     * Referenced by: '<S4>/    '
     */
    0.0F,

    /* Computed Parameter: Gain_Gain_k
     * Referenced by: '<S429>/Gain'
     */
    0.00228F,

    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S433>/Out1'
     */
    0.0F,

    /* Computed Parameter: Lykyhatkk1_Y0_c
     * Referenced by: '<S510>/L*(y[k]-yhat[k|k-1])'
     */
    0.0F,

    /* Computed Parameter: deltax_Y0_k
     * Referenced by: '<S512>/deltax'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain_p
     * Referenced by: '<S442>/Gain'
     */
    -1.0F,

    /* Computed Parameter: opticalFlowErrorCorrect_Gain
     * Referenced by: '<S442>/opticalFlowErrorCorrect'
     */
    1.15F,

    /* Expression: Controller.Q2Ts
     * Referenced by: '<S9>/TorqueTotalThrustToThrustPerMotor'
     */
    { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
      -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F,
      5.66592F, 5.66592F, -5.66592F },

    /* Computed Parameter: A_Value_a
     * Referenced by: '<S441>/A'
     */
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -0.005F, 0.0F, 1.0F, 0.0F,
      0.0F, -0.005F, 0.0F, 1.0F },

    /* Computed Parameter: SimplyIntegrateVelocity_gainval
     * Referenced by: '<S437>/SimplyIntegrateVelocity'
     */
    0.005F,

    /* Computed Parameter: SimplyIntegrateVelocity_IC
     * Referenced by: '<S437>/SimplyIntegrateVelocity'
     */
    0.0F,

    /* Computed Parameter: invertzaxisGain_Gain
     * Referenced by: '<S251>/invertzaxisGain'
     */
    -1.0F,

    /* Computed Parameter: prsToAltGain_Gain
     * Referenced by: '<S251>/prsToAltGain'
     */
    0.0832137167F,

    /* Computed Parameter: pressureFilter_IIR_NumCoef
     * Referenced by: '<S256>/pressureFilter_IIR'
     */
    { 3.75683794E-6F, 1.12705138E-5F, 1.12705138E-5F, 3.75683794E-6F },

    /* Computed Parameter: pressureFilter_IIR_DenCoef
     * Referenced by: '<S256>/pressureFilter_IIR'
     */
    { 1.0F, -2.93717074F, 2.87629962F, -0.939098954F },

    /* Computed Parameter: pressureFilter_IIR_InitialStates
     * Referenced by: '<S256>/pressureFilter_IIR'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S319>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC
     * Referenced by: '<S319>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: X0_Value_i
     * Referenced by: '<S321>/X0'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
     * Referenced by: '<S253>/Assuming that the  preflight calibration was done at level orientation'
     */
    { 0.0F, 0.0F, 9.81F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: inverseIMU_gain_Gain
     * Referenced by: '<S253>/inverseIMU_gain'
     */
    { 0.994075298F, 0.996184587F, 1.00549F, 1.00139189F, 0.993601203F, 1.00003F
    },

    /* Computed Parameter: FIR_IMUaccel_InitialStates
     * Referenced by: '<S253>/FIR_IMUaccel'
     */
    0.0F,

    /* Computed Parameter: FIR_IMUaccel_Coefficients
     * Referenced by: '<S253>/FIR_IMUaccel'
     */
    { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
      0.0264077242F },

    /* Computed Parameter: Gain2_Gain_p
     * Referenced by: '<S317>/Gain2'
     */
    0.101936802F,

    /* Computed Parameter: Constant_Value_h
     * Referenced by: '<S320>/Constant'
     */
    2.0F,

    /* Computed Parameter: C_Value_h
     * Referenced by: '<S321>/C'
     */
    { 1.0F, 0.0F },

    /* Computed Parameter: X0_Value_iy
     * Referenced by: '<S375>/X0'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: C_Value_i
     * Referenced by: '<S375>/C'
     */
    { 1.0F, 0.0F },

    /* Computed Parameter: LPFFcutoff40Hz1_NumCoef
     * Referenced by: '<S253>/LPF Fcutoff = 40Hz1'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPFFcutoff40Hz1_DenCoef
     * Referenced by: '<S253>/LPF Fcutoff = 40Hz1'
     */
    { 2.5915494F, -0.591549456F },

    /* Computed Parameter: LPFFcutoff40Hz1_InitialStates
     * Referenced by: '<S253>/LPF Fcutoff = 40Hz1'
     */
    0.0F,

    /* Computed Parameter: LPFFcutoff40Hz_NumCoef
     * Referenced by: '<S253>/LPF Fcutoff = 40Hz'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPFFcutoff40Hz_DenCoef
     * Referenced by: '<S253>/LPF Fcutoff = 40Hz'
     */
    { 2.5915494F, -0.591549456F },

    /* Computed Parameter: LPFFcutoff40Hz_InitialStates
     * Referenced by: '<S253>/LPF Fcutoff = 40Hz'
     */
    0.0F,

    /* Computed Parameter: IIR_IMUgyro_r_NumCoef
     * Referenced by: '<S253>/IIR_IMUgyro_r'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIR_IMUgyro_r_DenCoef
     * Referenced by: '<S253>/IIR_IMUgyro_r'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIR_IMUgyro_r_InitialStates
     * Referenced by: '<S253>/IIR_IMUgyro_r'
     */
    0.0F,

    /* Computed Parameter: Constant_Value_j
     * Referenced by: '<S319>/Constant'
     */
    0.0F,

    /* Computed Parameter: X0_Value_c
     * Referenced by: '<S441>/X0'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: C_Value_i2
     * Referenced by: '<S441>/C'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Gain1_Gain_n
     * Referenced by: '<S439>/Gain1'
     */
    -1.0F,

    /* Computed Parameter: IIRgyroz_NumCoef
     * Referenced by: '<S440>/IIRgyroz'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIRgyroz_DenCoef
     * Referenced by: '<S440>/IIRgyroz'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIRgyroz_InitialStates
     * Referenced by: '<S440>/IIRgyroz'
     */
    0.0F,

    /* Computed Parameter: TSamp_WtEt
     * Referenced by: '<S448>/TSamp'
     */
    200.0F,

    /* Computed Parameter: Delay_InitialCondition
     * Referenced by: '<S436>/Delay'
     */
    0.0F,

    /* Computed Parameter: Delay1_InitialCondition
     * Referenced by: '<S6>/Delay1'
     */
    0.0F,

    /* Computed Parameter: B_Value_f
     * Referenced by: '<S441>/B'
     */
    { 0.005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005F, 0.0F, 0.0F },

    /* Computed Parameter: D_Value_h
     * Referenced by: '<S441>/D'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S216>/Integrator'
     */
    0.005F,

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
     * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    { 1.0F, 1.0F },

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
     * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    { 8.95774746F, -6.95774698F },

    /* Computed Parameter: LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l
     * Referenced by: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
     */
    0.0F,

    /* Computed Parameter: Integrator_gainval_i
     * Referenced by: '<S107>/Integrator'
     */
    0.005F,

    /* Computed Parameter: Filter_gainval
     * Referenced by: '<S102>/Filter'
     */
    0.005F,

    /* Computed Parameter: w1_Value
     * Referenced by: '<S7>/w1'
     */
    -0.61803F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval_n
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC_h
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    2.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    -2.0F,

    /* Computed Parameter: SaturationThrust1_UpperSat
     * Referenced by: '<S7>/SaturationThrust1'
     */
    1.20204329F,

    /* Computed Parameter: SaturationThrust1_LowerSat
     * Referenced by: '<S7>/SaturationThrust1'
     */
    -1.20204329F,

    /* Computed Parameter: Saturation_UpperSat
     * Referenced by: '<S11>/Saturation'
     */
    0.52359879F,

    /* Computed Parameter: Saturation_LowerSat
     * Referenced by: '<S11>/Saturation'
     */
    -0.52359879F,

    /* Computed Parameter: P_yaw_Gain
     * Referenced by: '<S11>/P_yaw'
     */
    0.004F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval_d
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC_b
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: D_yaw_Gain
     * Referenced by: '<S11>/D_yaw'
     */
    0.0012F,

    /* Computed Parameter: Gain_Gain_b
     * Referenced by: '<S12>/Gain'
     */
    -1530.72681F,

    /* Expression: Vehicle.Motor.maxLimit
     * Referenced by: '<S12>/Saturation'
     */
    500.0F,

    /* Expression: Vehicle.Motor.minLimit
     * Referenced by: '<S12>/Saturation'
     */
    10.0F,

    /* Computed Parameter: A_Value_k
     * Referenced by: '<S321>/A'
     */
    { 1.0F, 0.0F, -0.005F, 1.0F },

    /* Computed Parameter: A_Value_ah
     * Referenced by: '<S375>/A'
     */
    { 1.0F, 0.0F, -0.005F, 1.0F },

    /* Computed Parameter: B_Value_g
     * Referenced by: '<S375>/B'
     */
    { 0.005F, 0.0F },

    /* Computed Parameter: D_Value_k
     * Referenced by: '<S375>/D'
     */
    0.0F,

    /* Computed Parameter: B_Value_o
     * Referenced by: '<S321>/B'
     */
    { 0.005F, 0.0F },

    /* Computed Parameter: D_Value_kg
     * Referenced by: '<S321>/D'
     */
    0.0F,

    /* Computed Parameter: Clamping_zero_Value
     * Referenced by: '<S97>/Clamping_zero'
     */
    0.0F,

    /* Computed Parameter: Constant1_Value_n
     * Referenced by: '<S97>/Constant1'
     */
    0.0F,

    /* Computed Parameter: Clamping_zero_Value_m
     * Referenced by: '<S206>/Clamping_zero'
     */
    0.0F,

    /* Computed Parameter: Constant1_Value_c
     * Referenced by: '<S206>/Constant1'
     */
    0.0F,

    /* Computed Parameter: I_yaw_Gain
     * Referenced by: '<S11>/I_yaw'
     */
    0.002F,

    /* Computed Parameter: I_pr_Gain
     * Referenced by: '<S7>/I_pr'
     */
    0.24F,

    /* Computed Parameter: Gain_Gain_o
     * Referenced by: '<S4>/Gain'
     */
    1.0F,

    /* Computed Parameter: Gain1_Gain_p
     * Referenced by: '<S4>/Gain1'
     */
    1.0F,

    /* Computed Parameter: P0_Value_e
     * Referenced by: '<S441>/P0'
     */
    { 1.42263806F, 0.0F, -0.462845951F, 0.0F, 0.0F, 1.42263806F, 0.0F,
      -0.462845951F, -0.462845951F, 0.0F, 6.15735F, 0.0F, 0.0F, -0.462845951F,
      0.0F, 6.15735F },

    /* Computed Parameter: G_Value_i
     * Referenced by: '<S441>/G'
     */
    { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_m
     * Referenced by: '<S441>/Q'
     */
    { 0.09F, 0.0F, 0.0F, 0.0F, 0.0F, 0.09F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.01F },

    /* Computed Parameter: H_Value_i
     * Referenced by: '<S441>/H'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: N_Value_i
     * Referenced by: '<S441>/N'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: P0_Value_h
     * Referenced by: '<S321>/P0'
     */
    { 1098.6875F, -30.4245777F, -30.4245777F, 7.22336864F },

    /* Computed Parameter: G_Value_m
     * Referenced by: '<S321>/G'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_j
     * Referenced by: '<S321>/Q'
     */
    { 1.0F, 0.0F, 0.0F, 0.001F },

    /* Computed Parameter: P0_Value_l
     * Referenced by: '<S375>/P0'
     */
    { 1098.6875F, -30.4245777F, -30.4245777F, 7.22336864F },

    /* Computed Parameter: G_Value_g
     * Referenced by: '<S375>/G'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: Q_Value_p
     * Referenced by: '<S375>/Q'
     */
    { 1.0F, 0.0F, 0.0F, 0.001F },

    /* Computed Parameter: R_Value_h
     * Referenced by: '<S441>/R'
     */
    { 20.0F, 0.0F, 0.0F, 20.0F },

    /* Computed Parameter: H_Value_a
     * Referenced by: '<S321>/H'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: N_Value_f
     * Referenced by: '<S321>/N'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: H_Value_o
     * Referenced by: '<S375>/H'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: N_Value_b
     * Referenced by: '<S375>/N'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: R_Value_a
     * Referenced by: '<S321>/R'
     */
    924556.188F,

    /* Computed Parameter: R_Value_l
     * Referenced by: '<S375>/R'
     */
    924556.188F,

    /* Computed Parameter: Output_InitialCondition
     * Referenced by: '<S432>/Output'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_f
     * Referenced by: '<S514>/Output'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_h
     * Referenced by: '<S242>/Output'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value
     * Referenced by: '<S248>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_a
     * Referenced by: '<S249>/Constant'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_p
     * Referenced by: '<S515>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_e
     * Referenced by: '<S516>/Constant'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_m
     * Referenced by: '<S434>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_jy
     * Referenced by: '<S435>/Constant'
     */
    0U,

    /* Computed Parameter: Output_InitialCondition_fi
     * Referenced by: '<S14>/Output'
     */
    0U,

    /* Computed Parameter: FixPtConstant_Value_g
     * Referenced by: '<S15>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S16>/Constant'
     */
    0U,

    /* Computed Parameter: controlModePosVsOrient_Value
     * Referenced by: '<S1>/controlModePosVsOrient'
     */
    true,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S508>/isSqrtUsed'
     */
    false,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S305>/isSqrtUsed'
     */
    false,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S370>/isSqrtUsed'
     */
    false,

    /* Expression: pInitialization.isSqrtUsed
     * Referenced by: '<S424>/isSqrtUsed'
     */
    false,

    /* Computed Parameter: Constant_Value_km
     * Referenced by: '<S97>/Constant'
     */
    1,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S97>/Constant2'
     */
    -1,

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S97>/Constant3'
     */
    1,

    /* Computed Parameter: Constant4_Value
     * Referenced by: '<S97>/Constant4'
     */
    -1,

    /* Computed Parameter: Constant_Value_p
     * Referenced by: '<S206>/Constant'
     */
    1,

    /* Computed Parameter: Constant2_Value_f
     * Referenced by: '<S206>/Constant2'
     */
    -1,

    /* Computed Parameter: Constant3_Value_d
     * Referenced by: '<S206>/Constant3'
     */
    1,

    /* Computed Parameter: Constant4_Value_p
     * Referenced by: '<S206>/Constant4'
     */
    -1,

    /* Computed Parameter: Disabletemperaturecompensation_CurrentSetting
     * Referenced by: '<S429>/Disable temperature compensation'
     */
    1U,

    /* Computed Parameter: ManualSwitch_CurrentSetting
     * Referenced by: '<S9>/Manual Switch'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S4>/Merge'
     */
    0U,

    /* Start of '<S402>/Enabled Subsystem' */
    {
      /* Computed Parameter: deltax_Y0
       * Referenced by: '<S428>/deltax'
       */
      0.0F
    }
    ,

    /* End of '<S402>/Enabled Subsystem' */

    /* Start of '<S395>/MeasurementUpdate' */
    {
      /* Computed Parameter: Lykyhatkk1_Y0
       * Referenced by: '<S426>/L*(y[k]-yhat[k|k-1])'
       */
      0.0F
    }
    ,

    /* End of '<S395>/MeasurementUpdate' */

    /* Start of '<S348>/Enabled Subsystem' */
    {
      /* Computed Parameter: deltax_Y0
       * Referenced by: '<S374>/deltax'
       */
      0.0F
    }
    ,

    /* End of '<S348>/Enabled Subsystem' */

    /* Start of '<S341>/MeasurementUpdate' */
    {
      /* Computed Parameter: Lykyhatkk1_Y0
       * Referenced by: '<S372>/L*(y[k]-yhat[k|k-1])'
       */
      0.0F
    }
    ,

    /* End of '<S341>/MeasurementUpdate' */

    /* Start of '<S4>/Normal condition' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S245>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Normal condition' */

    /* Start of '<S4>/Ultrasound improper' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S246>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Ultrasound improper' */

    /* Start of '<S4>/No optical flow ' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S244>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/No optical flow ' */

    /* Start of '<S4>/estimator//Optical flow error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S247>/Constant'
       */
      99U
    }
    ,

    /* End of '<S4>/estimator//Optical flow error' */

    /* Start of '<S4>/Geofencing error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S243>/Constant'
       */
      1U
    }
    /* End of '<S4>/Geofencing error' */
  }
  /* End of '<Root>/Control System' */
};
