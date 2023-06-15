/*
 *	Copyright (c) 2021, Orestis Kaparounakis.
 *
 *	All rights reserved.
 *
 *	Redistribution and use in source and binary forms, with or without
 *	modification, are permitted provided that the following conditions
 *	are met:
 *	*	Redistributions of source code must retain the above
 *		copyright notice, this list of conditions and the following
 *		disclaimer.
 *	*	Redistributions in binary form must reproduce the above
 *		copyright notice, this list of conditions and the following
 *		disclaimer in the documentation and/or other materials
 *		provided with the distribution.
 *	*	Neither the name of the author nor the names of its
 *		contributors may be used to endorse or promote products
 *		derived from this software without specific prior written
 *		permission.
 *
 *	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *	FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *	COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *	POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <uxhw.h>

const double pi = 3.14159265359;

double loadDoubleDistFromPath(double *  var, const char *  filename);

int
main(int argc, char *argv[])
{
	/*
	 *	Variables
	 */
	double initialLength, initialTemperature, finalLength, finalTemperature, thermalExpansionCoef;

	/*
	 *	Load all samples from their respective files
	 */
	initialLength = loadDoubleDistFromPath(NULL, "samples-studentst-tec_initialLength.csv");
	printf("initialLength = %f\n", initialLength);

	initialTemperature = loadDoubleDistFromPath(NULL, "samples-studentst-tec_initialTemperature.csv");
	printf("initialTemperature = %f\n", initialTemperature);

	finalLength = loadDoubleDistFromPath(NULL, "samples-studentst-tec_finalLength.csv");
	printf("finalLength = %f\n", finalLength);

	finalTemperature = loadDoubleDistFromPath(NULL, "samples-studentst-tec_finalTemperature.csv");
	printf("finalTemperature = %f\n", finalTemperature);

	/*
	 *	Perform calculations as specified by the NIST Uncertainty Machine example
	 */
	thermalExpansionCoef = (finalLength - initialLength) / (initialLength * (finalTemperature - initialTemperature));

	/*
	 *	Printthe result
	 */
	printf("thermalExpansionCoef = %lf\n", thermalExpansionCoef);

	/*
	 * Finished.
	 */
	return EXIT_SUCCESS;
}

double
loadDoubleDistFromPath(double *  var, const char *  filename)
{
	FILE *		inp;
	int			sampleCount;
	double *	samples;
	double		returnValue;

	inp = fopen(filename, "r");
	if (inp == NULL)
	{
		printf("Could not open input file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fscanf(inp, "%d\n", &sampleCount);

	printf("Number of samples from %s: %d\n", filename, sampleCount);

	samples = calloc(sampleCount, sizeof(double));
	if (samples == NULL)
	{
		perror("error: could not allocate memory for samples");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < sampleCount; i++)
	{
		fscanf(inp, "%lf\n", &samples[i]);
	}

	if (var == NULL )
	{
		returnValue = UxHwDoubleDistFromSamples(samples, sampleCount);
	}
	else
	{
		(*var) = UxHwDoubleDistFromSamples(samples, sampleCount);
	}

	if (fclose(inp) != 0)
	{
		perror("warning: could not close input file");
	}

	free(samples);

	return returnValue;
}
