#include "fuzzyHelloWorld.h"

#include <vtkCommand.h>
#include <vtkInformation.h>
#include <vtkInformationVector.h>
#include <vtkObjectFactory.h>
#include <vtkStreamingDemandDrivenPipeline.h>
#include <vtkSmartPointer.h>
#include <vtkDataObject.h>
#include <vtkImageData.h>

#include <easyloggingpp/easylogging++.h>

vtkStandardNewMacro(fuzzyHelloWorld);

fuzzyHelloWorld::fuzzyHelloWorld() {
  this->SetNumberOfInputPorts(1);
  this->SetNumberOfOutputPorts(1);
}

fuzzyHelloWorld::~fuzzyHelloWorld() = default;

int fuzzyHelloWorld::FillInputPortInformation(int port, vtkInformation *info) {
  if (port == 0) {
    info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkImageData");
  }
  return 1;
}

int fuzzyHelloWorld::FillOutputPortInformation(int port, vtkInformation *info) {
  if (port == 0) {
    info->Set(vtkDataObject::DATA_TYPE_NAME(), "vtkImageData");
  }
  return 1;
}

int fuzzyHelloWorld::RequestData(
    vtkInformation *vtkNotUsed(request),
    vtkInformationVector **inputVector,
    vtkInformationVector *outputVector) {
  auto input = vtkImageData::GetData(inputVector[0], 0);
  auto output = vtkImageData::GetData(outputVector, 0);

  if (!input or !output)
    return 0;

  LOG(INFO) << "Start Computation";
  if (DoSomething) {
    TIMED_SCOPE(_timer, "Time Computation");
    /// Do some computation here
  }

  LOG(INFO) << "Computation DONE";

  ///Copy output
  output->ShallowCopy(input);

  return 1;
}
