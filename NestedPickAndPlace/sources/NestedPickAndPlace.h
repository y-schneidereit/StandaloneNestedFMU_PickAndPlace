#ifndef RTW_HEADER_NestedPickAndPlace_h_
#define RTW_HEADER_NestedPickAndPlace_h_
#include <string.h>
#ifndef NestedPickAndPlace_COMMON_INCLUDES_
#define NestedPickAndPlace_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "RTWCG_FMU2_target.h"
#endif

#include "NestedPickAndPlace_types.h"

#include "multiword_types.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real_T PickAndPlace_FMU_FmuPrevTime;
  void* PickAndPlace_FMU_FmuStruct;
  void *PickAndPlace_FMU_PWORK[3];
  int32_T PickAndPlace_FMU_FmuIsInitializ;
} DW_NestedPickAndPlace_T;

typedef struct {
  real_T ZAchseCommandSignal;
  real_T ZAchseOverrideSignal;
  real_T YAchseCommandSignal;
  real_T YAchseOverrideSignal;
} ExtU_NestedPickAndPlace_T;

typedef struct {
  real_T ZAchseDisplacement;
  real_T ZAchseVelocity;
  real_T ZAchseAcceleration;
  real_T ZAchseDesiredSignal;
  real_T YAchseDisplacement;
  real_T YAchseVelocity;
  real_T YAchseAcceleration;
  real_T YAchseDesiredSignal;
} ExtY_NestedPickAndPlace_T;

struct tag_RTM_NestedPickAndPlace_T {
  const char_T *errorStatus;
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

extern DW_NestedPickAndPlace_T NestedPickAndPlace_DW;
extern ExtU_NestedPickAndPlace_T NestedPickAndPlace_U;
extern ExtY_NestedPickAndPlace_T NestedPickAndPlace_Y;
extern void NestedPickAndPlace_initialize(void);
extern void NestedPickAndPlace_step(void);
extern void NestedPickAndPlace_terminate(void);
extern RT_MODEL_NestedPickAndPlace_T *const NestedPickAndPlace_M;
extern void fmu_LogOutput();

#endif
