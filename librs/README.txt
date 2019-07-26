RS library packages

RS is freely distributable for non-commercial use. For details, read the license.
Fabrice Rouillier's software page contains information about RS and related software.

Installation instructions

This library depends on GMP, MPFR and MPFI libraries. A compiled version of the latter is included in the bundle. 
The compressed archive contains two directories, one for the include files and one for the compiled libraries. 
The CGAL configuration scripts look for the environment variables RS_INC_DIR (the include directory) and RS_LIB_DIR (the library directory). 
If you did not install MPFI in a standard library directory, you may define the environment variables MPFI_INC_DIR and MPFI_LIB_DIR, 
pointing to the same places than the above variables.
