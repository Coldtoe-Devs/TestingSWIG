# Notes on Generating Bindings

Swig generates bindings for a whole lot of languages, including python. Once you get one figured out, someone should be able to tell SWIG to generate java/perl/ruby etc with **very** minimal effort.

This repo is for learning SWIG, getting it as automated as possible, and learning how SWIG want's you to handle pointers. (From what I can tell so far, you declare how to cast the pointers in the *.i files)

## To download SWIG

Go to `http://www.swig.org/download.html`.

Then install the latest:

```bash
tar -zxf swig-4.0.2.tar.gz
cd swig-4.0.2
./configure
make
sudo make install
# DONE!!
```

## Generate Python Bindings

```bash
<cd to root of this repo>
cmake .
make all
```

Then you can run python!

```python
from mypackage import cameron
cameron.add3(6)
>>> 9
# NOTE: there's cameron.getArray(), which should return something like [0,1,2,3,4,5,6,7,8,9]. Haven't got pointers figured out yet though. Basic functions like the one above work great.
```

## Developers: To add another file to the library

If you need to add another .h and .c pair to `mypackage`:

1) Create a file.i file with it. Same name as the .c and .h, with these contents:

    I think this is where `casting a pointer` logic goes, so we might not be able to generate these files automatically:

    ```txt
    %module <name>
    %{                // This adds the include to the generated wrapper.
    #include "<name>.h"
    %}
    %include "<name>.h"    // This *processes* the include and makes wrappers.
    ```

2) Add this block to the end of the CMakeLists.txt

    NOTE: There HAS to be a way to automate/for-loop this, based on a include list. I just haven't looked.

    ```txt
    swig_add_library(<name> TYPE SHARED LANGUAGE python SOURCES mypackage/<name>.i mypackage/<name>.c)
    # NOTE the underscore before the name!!!
    set_target_properties(_<name> PROPERTIES LIBRARY_OUTPUT_DIRECTORY "mypackage/")
    SWIG_LINK_LIBRARIES(<name> ${PYTHON_LIBRARIES})
    ```

## Main TODO's to figure out

- How to handle C pointers, and declare how to cast them in SWIG.

- How to simplify CMakeLists.txt, so you don't need 3 lines of code for each .c/.h pair.

- Add another `mypackage` directory, along with a shared directory they both import from. Make sure SWIG can handle libvnc's use case of a `common` dir that two libraries import from.
