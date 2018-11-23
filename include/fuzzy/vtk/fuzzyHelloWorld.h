#ifndef LIBFUZZY_VTK_FUZZYHELLOWORLD_H_
#define LIBFUZZY_VTK_FUZZYHELLOWORLD_H_

#include <vtkImageAlgorithm.h>

/**
 * @brief
 */
class fuzzyHelloWorld : public vtkImageAlgorithm {
 public:
  static fuzzyHelloWorld *New();
 vtkTypeMacro(fuzzyHelloWorld, vtkImageAlgorithm);


  /**
  * @brief Do something if this is enabled
  */
  //@{ //Disables CLion code formatter
  vtkGetMacro(DoSomething, bool);
  vtkSetMacro(DoSomething, bool);
  //@}

 protected:
  bool DoSomething{false};
  fuzzyHelloWorld();
  ~fuzzyHelloWorld() override;

  int FillInputPortInformation(int port, vtkInformation *info) override;
  int FillOutputPortInformation(int port, vtkInformation *info) override;

  int RequestData(
      vtkInformation *request,
      vtkInformationVector **inputVector,
      vtkInformationVector *outputVector)
  override;

 private:
  fuzzyHelloWorld(const fuzzyHelloWorld &); // Not implemented.
  void operator=(const fuzzyHelloWorld &); // Not implemented.
};

#endif //LIBFUZZY_VTK_FUZZYHELLOWORLD_H_
