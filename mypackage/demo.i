%module demo
%{                // This adds the include to the generated wrapper.
#include "demo.h"
%}
%include "demo.h"    // This *processes* the include and makes wrappers.