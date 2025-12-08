/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Project_Simulink_Model.h
 *
 * Code generated for Simulink model 'Final_Project_Simulink_Model'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Dec  8 15:47:45 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Final_Project_Simulink_Model_h_
#define Final_Project_Simulink_Model_h_
#ifndef Final_Project_Simulink_Model_COMMON_INCLUDES_
#define Final_Project_Simulink_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_Ultrasonic.h"
#include "MW_arduino_digitalio.h"
#endif                       /* Final_Project_Simulink_Model_COMMON_INCLUDES_ */

#include "Final_Project_Simulink_Model_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T uUltrasonicSensor;            /* '<Root>/#1 - Ultrasonic Sensor' */
} B_Final_Project_Simulink_Mode_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/#2 - PIR Motion Sensor' */
  codertarget_arduinobase_blo_d_T obj_i;/* '<Root>/Red Light - Digital Output' */
  codertarget_arduinobase_blo_d_T obj_l;
                                     /* '<Root>/Green Light - Digital Output' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/#1 - Ultrasonic Sensor' */
  struct {
    void *LoggedData;
  } UltrasonicSensorLiveDistancem_P;
                            /* '<Root>/Ultrasonic Sensor - Live Distance (m)' */
} DW_Final_Project_Simulink_Mod_T;

/* Parameters (default storage) */
struct P_Final_Project_Simulink_Mode_T_ {
  real_T DistanceThreshold_const;     /* Mask Parameter: DistanceThreshold_const
                                       * Referenced by: '<S1>/Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_Final_Project_Simulin_T {
  const char_T *errorStatus;
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
    uint32_T clockTick0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Final_Project_Simulink_Mode_T Final_Project_Simulink_Model_P;

/* Block signals (default storage) */
extern B_Final_Project_Simulink_Mode_T Final_Project_Simulink_Model_B;

/* Block states (default storage) */
extern DW_Final_Project_Simulink_Mod_T Final_Project_Simulink_Model_DW;

/* Model entry point functions */
extern void Final_Project_Simulink_Model_initialize(void);
extern void Final_Project_Simulink_Model_step(void);
extern void Final_Project_Simulink_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_Project_Simuli_T *const Final_Project_Simulink_Model_M;
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
 * '<Root>' : 'Final_Project_Simulink_Model'
 * '<S1>'   : 'Final_Project_Simulink_Model/Distance Threshold'
 */
#endif                                 /* Final_Project_Simulink_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
