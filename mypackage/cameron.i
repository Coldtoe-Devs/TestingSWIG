%module cameron
%{                // This adds the include to the generated wrapper.
#include "cameron.h"
%}
%include "cameron.h"    // This *processes* the include and makes wrappers.