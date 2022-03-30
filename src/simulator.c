#include <stdio.h>
#include <windows.h>

#include "fmi2Functions.h"

// model specific constants
#define GUID "{c51cfa80-b55d-4da4-e515-6444d8f4bda2}"
#define RESOURCE_LOCATION "file:///C:/Users/schyan01/github/StandaloneNestedFMU/NestedPickAndPlace/resources/99c5064ff1d4d5df87e5290e4964ba39/resources" // absolut path to the unziped fmu

// callback functions
static void cb_logMessage(fmi2ComponentEnvironment componentEnvironment, fmi2String instanceName, fmi2Status status, fmi2String category, fmi2String message, ...) {
	printf("%s\n", message);
}

static void* cb_allocateMemory(size_t nobj, size_t size) {
	return calloc(nobj, size);
}

static void cb_freeMemory(void* obj) {
	free(obj);
}

#define CHECK_STATUS(S) { status = S; if (status != fmi2OK) goto TERMINATE; }

int main(int argc, char *argv[]) {
	HMODULE libraryHandle = LoadLibraryA("C:\\Users\\schyan01\\github\\StandaloneNestedFMU_PickAndPlace\\NestedPickAndPlace\\binaries\\win64\\NestedPickAndPlace.dll");

	if (!libraryHandle)
	{
		return EXIT_FAILURE;
	}

	fmi2InstantiateTYPE* InstantiatePtr = NULL;
	fmi2FreeInstanceTYPE* FreeInstancePtr = NULL;
	fmi2SetupExperimentTYPE* SetupExperimentPtr = NULL;
	fmi2EnterInitializationModeTYPE* EnterInitializationModePtr = NULL;
	fmi2ExitInitializationModeTYPE* ExitInitializationModePtr = NULL;
	fmi2TerminateTYPE* TerminatePtr = NULL;
	fmi2SetRealTYPE* SetRealPtr = NULL;
	fmi2GetRealTYPE* GetRealPtr = NULL;
	fmi2DoStepTYPE* DoStepPtr = NULL;
	fmi2GetTypesPlatformTYPE* GetTypesPlatform = NULL;
	fmi2GetVersionTYPE* GetVersion = NULL;

	InstantiatePtr = GetProcAddress(libraryHandle, "fmi2Instantiate");
	FreeInstancePtr = GetProcAddress(libraryHandle, "fmi2FreeInstance");
	SetupExperimentPtr = GetProcAddress(libraryHandle, "fmi2SetupExperiment");
	EnterInitializationModePtr = GetProcAddress(libraryHandle, "fmi2EnterInitializationMode");
	ExitInitializationModePtr = GetProcAddress(libraryHandle, "fmi2ExitInitializationMode");
	TerminatePtr = GetProcAddress(libraryHandle, "fmi2Terminate");
	SetRealPtr = GetProcAddress(libraryHandle, "fmi2SetReal");
	GetRealPtr = GetProcAddress(libraryHandle, "fmi2GetReal");
	DoStepPtr = GetProcAddress(libraryHandle, "fmi2DoStep");
	GetTypesPlatform = GetProcAddress(libraryHandle, "fmi2GetTypesPlatform");
	GetVersion = GetProcAddress(libraryHandle, "fmi2GetVersion");

	if (NULL == InstantiatePtr || NULL == FreeInstancePtr || NULL == SetupExperimentPtr || NULL == EnterInitializationModePtr || NULL == ExitInitializationModePtr || NULL == TerminatePtr
		|| NULL == SetRealPtr || NULL == GetRealPtr || NULL == DoStepPtr || NULL == GetTypesPlatform || NULL == GetVersion)
	{
		return EXIT_FAILURE;
	}

	fmi2Status status = fmi2OK;

	fmi2CallbackFunctions callbacks = {cb_logMessage, cb_allocateMemory, cb_freeMemory, NULL, NULL};

	fmi2String platform = GetTypesPlatform();
	printf("%s\n", platform);

	fmi2String version = GetVersion();
	printf("%s\n", version);
	
	fmi2Component c = InstantiatePtr("instance1", fmi2CoSimulation, GUID, RESOURCE_LOCATION, &callbacks, fmi2False, fmi2False);
	
	if (!c) return 1;
	
	fmi2Real Time = 0;
	fmi2Real stepSize = 1;
	
	// Informs the FMU to setup the experiment. Must be called after fmi2Instantiate and befor fmi2EnterInitializationMode
	CHECK_STATUS(SetupExperimentPtr(c, fmi2False, 0, Time, fmi2False, 0));
	
	// Informs the FMU to enter Initialization Mode.
	//CHECK_STATUS(EnterInitializationModePtr(c));
	
TERMINATE:
	TerminatePtr(c);
	// clean up
	if (status < fmi2Fatal) {
		FreeInstancePtr(c);
	}

	FreeLibrary(libraryHandle);
	
	return status;
}
