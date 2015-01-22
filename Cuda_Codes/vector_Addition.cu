/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
// The program takes two equal size vectors as input and outputs their vector sum

#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

void CUDA_SAFE_CALL(cudaError_t call)
{
    cudaError_t ret = call;
    switch(ret)
    {
        case cudaSuccess:
            break;
        default:
        {
            printf("%s in %s at line %d\n",cudaGetErrorString(ret), __FILE__, __LINE__);
            exit(-1);
            break;
        }
    }
    return;
}

__global__ void vecAdd(float *in1, float *in2, float *out, int len) 
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if(i<len)
		out[i]=in1[i]+in2[i];

	return;
}

int main(int argc, char **argv) 
{
	int inputLength;
	float *hostInput1;
	float *hostInput2;
	float *hostOutput;
	float *deviceInput1;
	float *deviceInput2;
	float *deviceOutput;

	hostInput1 = ( float * )malloc(inputLength * sizeof(float));
	hostInput2 = ( float * )malloc(inputLength * sizeof(float));
	hostOutput = ( float * )malloc(inputLength * sizeof(float));

	scanf("%d ",&inputLength);

	for(int i=0;i<inputLength)
		scanf("%f ",&hostInput1[i]);

	for(int i=0;i<inputLength)
		scanf("%f ",&hostInput2[i]);	

	CUDA_SAFE_CALL( cudaMalloc ( (void**) &deviceInput1, inputLength * sizeof(float)) );
	CUDA_SAFE_CALL( cudaMalloc ( (void**) &deviceInput2, inputLength * sizeof(float)) );
	CUDA_SAFE_CALL( cudaMalloc ( (void**) &deviceOutput, inputLength * sizeof(float)) );

	CUDA_SAFE_CALL( cudaMemcpy ( deviceInput1, hostInput1, inputLength * sizeof(float), cudaMemcpyHostToDevice) );  
	CUDA_SAFE_CALL( cudaMemcpy ( deviceInput2, hostInput2, inputLength * sizeof(float), cudaMemcpyHostToDevice) );  

	cudaDeviceProp deviceProp;
	CUDA_SAFE_CALL( cudaGetDeviceProperties(&deviceProp, 0) );
	dim3 DimGrid ( ceil(inputLength/(float)deviceProp.maxThreadsDim[0]), 1, 1);
	dim3 DimBlock ( deviceProp.maxThreadsDim[0], 1, 1);

	vecAdd <<< DimGrid, DimBlock >>> (deviceInput1, deviceInput2, deviceOutput, inputLength);
	cudaDeviceSynchronize();
	CUDA_SAFE_CALL( cudaMemcpy ( hostOutput, deviceOutput, inputLength * sizeof(float), cudaMemcpyDeviceToHost) );  

	CUDA_SAFE_CALL( cudaFree (deviceInput1) );
	CUDA_SAFE_CALL( cudaFree (deviceInput2) );
	CUDA_SAFE_CALL( cudaFree (deviceOutput) );

	for(int i=0;i<inputLength;i++)
		printf("%f ",hostOutput[i]);
	printf("\n");

	free(hostInput1);
	free(hostInput2);
	free(hostOutput);

	return 0;
}

