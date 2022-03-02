#include <stdio.h>

// model specific constants
# define GUID "{c51cfa80-b55d-4da4-e515-6444d8f4bda2}"

#ifndef FMI2_FUNCTION_PREFIX
#define FMI2_FUNCTION_PREFIX NestedPickAndPlace_
#endif

// no runtime resources
#define RESOURCE_LOCATION "file:///C:/Users/schyan01/git/fmu_nestedpickandplace/NestedPickAndPlace/resources" // absolut path to the unziped fmu
#include "fmi2Functions.h"

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

	fmi2Status status = fmi2OK;

	fmi2CallbackFunctions callbacks = {cb_logMessage, cb_allocateMemory, cb_freeMemory, NULL, NULL};
	
	fmi2Component c = NestedPickAndPlace_fmi2Instantiate("instance1", fmi2CoSimulation, GUID, RESOURCE_LOCATION, &callbacks, fmi2False, fmi2False);
	
	if (!c) return 1;
	
	fmi2Real Time = 0;
	fmi2Real stepSize = 1;
	
	// Informs the FMU to setup the experiment. Must be called after fmi2Instantiate and befor fmi2EnterInitializationMode
	CHECK_STATUS(NestedPickAndPlace_fmi2SetupExperiment(c, fmi2False, 0, Time, fmi2False, 0));
	
	// Informs the FMU to enter Initialization Mode.
	CHECK_STATUS(NestedPickAndPlace_fmi2EnterInitializationMode(c));
	
TERMINATE:

	// clean up
	if (status < fmi2Fatal) {
		NestedPickAndPlace_fmi2FreeInstance(c);
	}
	
	return status;
}
