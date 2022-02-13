# Performance Overview

## Bottlenecks

We utilized [gprof](https://sourceware.org/binutils/docs/gprof/) and 
[Intel VTune Profiler](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler.html#gs.ih3i5y)
to identify areas of the code that would be most improved by parallelizing the code.   

## OpenMP

The biggest performance improvement we found was to utilize multiple cores in the areas of code that were identified as
bottlenecks. 

For running a single simulation, we found that incorporating OpenMP into our code yielded significant improvements on a 
multi-core workstation.

## MPI

The original VIPRA code (written in C) incorporated MPI for parallelization. We found that the ergonomics of running on 
a local workstation benefited more from OpenMP than what would be used with MPI, but that does not preclude the use of
MPI.

If you want to use MPI, you can utilize a hybrid approach where each node utilizes multiple cores through OpenMP. See
https://openmp.org/wp-content/uploads/HybridPP_Slides.pdf for an example.

To effectively turn off OpenMP, you can set the environment variable OMP_NUM_THREADS to 1. For example,

```bash
OMP_NUM_THREADS=1 ./generated_main
```

## Compiler Flags

We found _significant_ performance improvements simply by setting the GCC optimization flag to level 3.

## Compilers

We did not find any significant performance improvement between building with [GCC](https://gcc.gnu.org/) and the Intel
compiler [ICC](https://www.intel.com/content/www/us/en/developer/tools/oneapi/toolkits.html#gs.ih14s6).

## Human Behavior Model

Due to the dynamic nature of human behaviors, the performance of the simulation drops quite a bit when running with 
behaviors enabled. The compiler can optimize the math for the CALM pedestrian model, but as soon as you introduce the 
Human Behavior Model the performance begins to degrade.

Based on observations, the more human behaviors you model, the slower the simulation runs.