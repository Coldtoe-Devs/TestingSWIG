# Notes on Generating Bindings

(Using `SWIG`)

To compile:

```bash
gcc -Wall mypackage/cameron.c mypackage/demo.c mypackage/main.c -o test
./test
```

To download SWIG:

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

## Generate helper *_wrap.c files

```bash
swig -python mypackage/demo.i
swig -python mypackage/cameron.i
# Now inside mypackage: creates demo_wrap.c and demo.py! Same file variants for "cameron.c" too.
```

## Generate wrapped C code

```bash
# Needs the *_wrap.c files from last step
python setup.py build_ext --inplace
```

This generates the _module.*.so inside project root. Need to move into mypackage, then you can:

```python
import mypackage.cameron as cameron
cameron.add3(6)
>>> 9
```

This is great!! "mypackage" will be "libvirtclient", so it can still be separate from "libvirtserver".

## Add this all to a cmake project

TODO
