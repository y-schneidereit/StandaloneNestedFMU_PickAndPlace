#include "NestedPickAndPlace_macros.h"
#include "NestedPickAndPlace.h"
#include "NestedPickAndPlace_private.h"

DW_NestedPickAndPlace_T NestedPickAndPlace_DW;
ExtU_NestedPickAndPlace_T NestedPickAndPlace_U;
ExtY_NestedPickAndPlace_T NestedPickAndPlace_Y;
static RT_MODEL_NestedPickAndPlace_T NestedPickAndPlace_M_;
RT_MODEL_NestedPickAndPlace_T *const NestedPickAndPlace_M =
  &NestedPickAndPlace_M_;
void NestedPickAndPlace_step(void)
{
  real_T realValue;
  real_T realValue_0;
  real_T realValue_1;
  real_T realValue_2;
  real_T realValue_3;
  real_T realValue_4;
  real_T realValue_5;
  real_T realValue_6;
  real_T realValue_7;
  real_T realValue_8;
  real_T realValue_9;
  real_T realValue_a;
  real_T realValue_b;
  real_T realValue_c;
  real_T realValue_d;
  real_T realValue_e;
  real_T realValue_f;
  real_T realValue_g;
  real_T realValue_h;
  real_T realValue_i;
  real_T realValue_j;
  real_T realValue_k;
  real_T realValue_l;
  real_T rtb_PickAndPlace_FMU_o2;
  real_T rtb_PickAndPlace_FMU_o3;
  real_T rtb_PickAndPlace_FMU_o4;
  real_T rtb_PickAndPlace_FMU_o5;
  real_T rtb_PickAndPlace_FMU_o6;
  real_T rtb_PickAndPlace_FMU_o7;
  real_T rtb_PickAndPlace_FMU_o8;
  real_T stepError;
  if (NestedPickAndPlace_DW.PickAndPlace_FMU_FmuIsInitializ == 0) {
    NestedPickAndPlace_DW.PickAndPlace_FMU_FmuPrevTime =
      (((NestedPickAndPlace_M->Timing.clockTick0+
         NestedPickAndPlace_M->Timing.clockTickH0* 4294967296.0)) * 0.5);
    FMU2_enterInitializationMode
      (&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct);
    realValue = NestedPickAndPlace_U.ZAchseCommandSignal;
    FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 0, 1,
                 &realValue);
    realValue_0 = NestedPickAndPlace_U.ZAchseOverrideSignal;
    FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 1, 1,
                 &realValue_0);
    realValue_1 = NestedPickAndPlace_U.YAchseCommandSignal;
    FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 2, 1,
                 &realValue_1);
    realValue_2 = NestedPickAndPlace_U.YAchseOverrideSignal;
    FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 3, 1,
                 &realValue_2);
    FMU2_exitInitializationMode
      (&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct);
    NestedPickAndPlace_DW.PickAndPlace_FMU_FmuIsInitializ = 1;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 4, 1,
                 &realValue_5);
    stepError = realValue_5;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 5, 1,
                 &realValue_7);
    rtb_PickAndPlace_FMU_o2 = realValue_7;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 6, 1,
                 &realValue_a);
    rtb_PickAndPlace_FMU_o3 = realValue_a;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 7, 1,
                 &realValue_d);
    rtb_PickAndPlace_FMU_o4 = realValue_d;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 8, 1,
                 &realValue_g);
    rtb_PickAndPlace_FMU_o5 = realValue_g;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 9, 1,
                 &realValue_i);
    rtb_PickAndPlace_FMU_o6 = realValue_i;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 10, 1,
                 &realValue_k);
    rtb_PickAndPlace_FMU_o7 = realValue_k;
    FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 11, 1,
                 &realValue_l);
    rtb_PickAndPlace_FMU_o8 = realValue_l;
  } else {
    real_T stepsize;
    stepsize = (((NestedPickAndPlace_M->Timing.clockTick0+
                  NestedPickAndPlace_M->Timing.clockTickH0* 4294967296.0)) * 0.5)
      - NestedPickAndPlace_DW.PickAndPlace_FMU_FmuPrevTime;
    if (stepsize > 0.0) {
      stepError = stepsize - 0.5;
      if (stepsize - 0.5 < 0.0) {
        stepError = 0.5 - stepsize;
      }

      if (stepError < 1.1920928955078125E-7) {
        stepsize = 0.5;
      }

      FMU2_doStep(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct,
                  NestedPickAndPlace_DW.PickAndPlace_FMU_FmuPrevTime, stepsize,
                  1);
      NestedPickAndPlace_DW.PickAndPlace_FMU_FmuPrevTime += stepsize;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 4, 1,
                   &realValue_3);
      stepError = realValue_3;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 5, 1,
                   &realValue_4);
      rtb_PickAndPlace_FMU_o2 = realValue_4;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 6, 1,
                   &realValue_6);
      rtb_PickAndPlace_FMU_o3 = realValue_6;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 7, 1,
                   &realValue_9);
      rtb_PickAndPlace_FMU_o4 = realValue_9;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 8, 1,
                   &realValue_c);
      rtb_PickAndPlace_FMU_o5 = realValue_c;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 9, 1,
                   &realValue_f);
      rtb_PickAndPlace_FMU_o6 = realValue_f;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 10, 1,
                   &realValue_h);
      rtb_PickAndPlace_FMU_o7 = realValue_h;
      FMU2_getReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 11, 1,
                   &realValue_j);
      rtb_PickAndPlace_FMU_o8 = realValue_j;
    }
  }

  NestedPickAndPlace_Y.ZAchseDisplacement = stepError;
  NestedPickAndPlace_Y.ZAchseVelocity = rtb_PickAndPlace_FMU_o2;
  NestedPickAndPlace_Y.ZAchseAcceleration = rtb_PickAndPlace_FMU_o3;
  NestedPickAndPlace_Y.ZAchseDesiredSignal = rtb_PickAndPlace_FMU_o4;
  NestedPickAndPlace_Y.YAchseDisplacement = rtb_PickAndPlace_FMU_o5;
  NestedPickAndPlace_Y.YAchseVelocity = rtb_PickAndPlace_FMU_o6;
  NestedPickAndPlace_Y.YAchseAcceleration = rtb_PickAndPlace_FMU_o7;
  NestedPickAndPlace_Y.YAchseDesiredSignal = rtb_PickAndPlace_FMU_o8;
  rtb_PickAndPlace_FMU_o8 = NestedPickAndPlace_U.ZAchseCommandSignal;
  FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 0, 1,
               &rtb_PickAndPlace_FMU_o8);
  realValue_8 = NestedPickAndPlace_U.ZAchseOverrideSignal;
  FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 1, 1,
               &realValue_8);
  realValue_b = NestedPickAndPlace_U.YAchseCommandSignal;
  FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 2, 1,
               &realValue_b);
  realValue_e = NestedPickAndPlace_U.YAchseOverrideSignal;
  FMU2_setReal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 3, 1,
               &realValue_e);
  fmu_LogOutput();
  NestedPickAndPlace_M->Timing.clockTick0++;
  if (!NestedPickAndPlace_M->Timing.clockTick0) {
    NestedPickAndPlace_M->Timing.clockTickH0++;
  }
}

void NestedPickAndPlace_initialize(void)
{
  (void) memset((void *)NestedPickAndPlace_M, 0,
                sizeof(RT_MODEL_NestedPickAndPlace_T));
  (void) memset((void *)&NestedPickAndPlace_DW, 0,
                sizeof(DW_NestedPickAndPlace_T));
  (void)memset(&NestedPickAndPlace_U, 0, sizeof(ExtU_NestedPickAndPlace_T));
  (void)memset(&NestedPickAndPlace_Y, 0, sizeof(ExtY_NestedPickAndPlace_T));

  {
    const char_T *dllLoc;
    const char_T *fmuInstanceName;
    const char_T *fmuLoc;
    boolean_T fmuLogging;
    boolean_T fmuVisible;
    const void *fmu2callbacks;
    dllLoc = fmu_nestedDLLLocation("99c5064ff1d4d5df87e5290e4964ba39", NULL,
      "msfmu.dll");
    fmuInstanceName = fmu_instanceName();
    fmuLoc = fmu_nestedResourceLocation("99c5064ff1d4d5df87e5290e4964ba39", NULL,
      0);
    fmu2callbacks = fmu_callback();
    fmuVisible = fmu_fmuVisible();
    fmuLogging = fmu_fmuLogging();
    NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct = FMU2_fmuInitializeCS
      (dllLoc, fmuInstanceName,
       "{Altair-MotionView: 19926_PicknPlace2__MKS.fmu: 1645625003.7462988}",
       fmuLoc, NULL, 0, 0, 0, fmu2callbacks, fmuVisible, fmuLogging);
    createParamIdxToOffset(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 1);
    createEnumValueList(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 0);
    setParamIdxToOffsetByIdx(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct,
      0, -1);
  }

  NestedPickAndPlace_DW.PickAndPlace_FMU_FmuIsInitializ = 0;
  FMU2_setStringVal(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, 0, 1,
                    "19926_PicknPlace2__MKS.mrf");
  FMU2_setupExperiment(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct, false,
                       0.001, (((NestedPickAndPlace_M->Timing.clockTick0+
    NestedPickAndPlace_M->Timing.clockTickH0* 4294967296.0)) * 0.5), false,
                       1000.0);
}

void NestedPickAndPlace_terminate(void)
{
  if (NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct != NULL) {
    FMU2_terminate(&NestedPickAndPlace_DW.PickAndPlace_FMU_FmuStruct);
  }
}
