"""
setup.py file for SWIG python bindings
"""

from distutils.core import setup, Extension


cameron_module = Extension('_cameron',
                           sources=[
                               'mypackage/cameron.c',
                               'mypackage/cameron_wrap.c',
                            ],
                        )

demo_module = Extension('_demo',
                           sources=[
                               'mypackage/demo.c',
                               'mypackage/demo_wrap.c',
                            ],
                        )


setup (name = 'libvnc',
       version = '0.1',
       author      = "SWIG Docs",
       description = """SWIG python bindings for LibVNC""",
       ext_modules = [cameron_module, demo_module],
       py_modules = ["cameron","demo"],
)