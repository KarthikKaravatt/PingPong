#pragma once
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class MyClass {
public:
  MyClass();
  MyClass(MyClass &&) = default;
  MyClass(const MyClass &) = default;
  MyClass &operator=(MyClass &&) = default;
  MyClass &operator=(const MyClass &) = default;
  ~MyClass();

private:
  
  
};

