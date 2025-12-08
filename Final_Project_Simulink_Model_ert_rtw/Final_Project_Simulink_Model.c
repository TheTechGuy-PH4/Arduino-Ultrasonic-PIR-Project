/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_Project_Simulink_Model.c
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

#include "Final_Project_Simulink_Model.h"
#include "rtwtypes.h"
#include "Final_Project_Simulink_Model_private.h"

/* Block signals (default storage) */
B_Final_Project_Simulink_Mode_T Final_Project_Simulink_Model_B;

/* Block states (default storage) */
DW_Final_Project_Simulink_Mod_T Final_Project_Simulink_Model_DW;

/* Real-time model */
static RT_MODEL_Final_Project_Simuli_T Final_Project_Simulink_Model_M_;
RT_MODEL_Final_Project_Simuli_T *const Final_Project_Simulink_Model_M =
  &Final_Project_Simulink_Model_M_;

/* Model step function */
void Final_Project_Simulink_Model_step(void)
{
  uint32_T duration;
  boolean_T rtb_GreenLightCondition;

  /* MATLABSystem: '<Root>/#1 - Ultrasonic Sensor' */
  if (Final_Project_Simulink_Model_DW.obj_g.TunablePropsChanged) {
    Final_Project_Simulink_Model_DW.obj_g.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 11, 12, 10);

  /* MATLABSystem: '<Root>/#1 - Ultrasonic Sensor' */
  Final_Project_Simulink_Model_B.uUltrasonicSensor = (real_T)duration * 0.000343
    / 2.0;

  /* MATLABSystem: '<Root>/#2 - PIR Motion Sensor' */
  rtb_GreenLightCondition = readDigitalPin(2);

  /* Logic: '<Root>/Green Light Condition' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLABSystem: '<Root>/#2 - PIR Motion Sensor'
   *  RelationalOperator: '<S1>/Compare'
   * */
  rtb_GreenLightCondition = ((Final_Project_Simulink_Model_B.uUltrasonicSensor <
    Final_Project_Simulink_Model_P.DistanceThreshold_const) &&
    rtb_GreenLightCondition);

  /* MATLABSystem: '<Root>/Green Light - Digital Output' */
  writeDigitalPin(9, (uint8_T)rtb_GreenLightCondition);

  /* MATLABSystem: '<Root>/Red Light - Digital Output' incorporates:
   *  Logic: '<Root>/Red Light Condition'
   */
  writeDigitalPin(10, (uint8_T)!rtb_GreenLightCondition);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Final_Project_Simulink_Model_M->Timing.clockTick0++;
}

/* Model initialize function */
void Final_Project_Simulink_Model_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Final_Project_Simulink_Model_M, 60.0);

  /* External mode info */
  Final_Project_Simulink_Model_M->Sizes.checksums[0] = (1912595532U);
  Final_Project_Simulink_Model_M->Sizes.checksums[1] = (3653077900U);
  Final_Project_Simulink_Model_M->Sizes.checksums[2] = (818983021U);
  Final_Project_Simulink_Model_M->Sizes.checksums[3] = (1394533461U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Final_Project_Simulink_Model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_Project_Simulink_Model_M->extModeInfo,
      &Final_Project_Simulink_Model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_Project_Simulink_Model_M->extModeInfo,
                        Final_Project_Simulink_Model_M->Sizes.checksums);
    rteiSetTFinalTicks(Final_Project_Simulink_Model_M->extModeInfo, 600);
  }

  /* Start for MATLABSystem: '<Root>/#1 - Ultrasonic Sensor' */
  Final_Project_Simulink_Model_DW.obj_g.isInitialized = 1L;
  MW_UltrasonicSetup(11, 12);
  Final_Project_Simulink_Model_DW.obj_g.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/#2 - PIR Motion Sensor' */
  Final_Project_Simulink_Model_DW.obj.matlabCodegenIsDeleted = false;
  Final_Project_Simulink_Model_DW.obj.isInitialized = 1L;
  digitalIOSetup(2, 0);
  Final_Project_Simulink_Model_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Green Light - Digital Output' */
  Final_Project_Simulink_Model_DW.obj_l.matlabCodegenIsDeleted = false;
  Final_Project_Simulink_Model_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(9, 1);
  Final_Project_Simulink_Model_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Red Light - Digital Output' */
  Final_Project_Simulink_Model_DW.obj_i.matlabCodegenIsDeleted = false;
  Final_Project_Simulink_Model_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(10, 1);
  Final_Project_Simulink_Model_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void Final_Project_Simulink_Model_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/#2 - PIR Motion Sensor' */
  if (!Final_Project_Simulink_Model_DW.obj.matlabCodegenIsDeleted) {
    Final_Project_Simulink_Model_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/#2 - PIR Motion Sensor' */

  /* Terminate for MATLABSystem: '<Root>/Green Light - Digital Output' */
  if (!Final_Project_Simulink_Model_DW.obj_l.matlabCodegenIsDeleted) {
    Final_Project_Simulink_Model_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Green Light - Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Red Light - Digital Output' */
  if (!Final_Project_Simulink_Model_DW.obj_i.matlabCodegenIsDeleted) {
    Final_Project_Simulink_Model_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Red Light - Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
