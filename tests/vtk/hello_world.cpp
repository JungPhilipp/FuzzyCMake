#include <catch/catch.hpp>
#include <easyloggingpp/easylogging++.h>

#include <fuzzy/vtk/fuzzyHelloWorld.h>

#include <vtkSmartPointer.h>
#include <vtkDataObjectGenerator.h>

TEST_CASE("Hello World") {

  auto generator = vtkSmartPointer<vtkDataObjectGenerator>::New();
  generator->Update();

  auto hello = vtkSmartPointer<fuzzyHelloWorld>::New();
  hello->SetInputConnection(generator->GetOutputPort());
  hello->SetDoSomething(true);
  hello->Update();

  ///Get output data
  auto output = hello->GetOutput();
  ///Require non-NULL output
  REQUIRE(output);

  ///Use as input for another filter
  auto hello2 = vtkSmartPointer<fuzzyHelloWorld>::New();
  hello2->SetInputConnection(hello->GetOutputPort());
  hello2->SetDoSomething(true);
  hello2->Update();

}