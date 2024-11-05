# Analysis

## The chaos method:

A method for approximating attractor fractal shapes:
*   Attractors are fractals that are formed by a set of simple transformations that can be iteratively applied to an origin point, generating a cloud of points. When the infinite series of these iterative transformations converge, interesting shapes can emerge.
*   The chaos method, rather than iteratively applying these transformations, increasing the number of points exponentially with every step, does the following:
    *   Have an array of points all set at the origin.
    *   For each point, randomly choose a transformation rule to apply.
    *   Repeat.
    *   This reduces computation complexity, while yielding "noisier" results (there are gaps).
    *   This is okay because we can deal with noise and also because it greatly simplifies the algorithm we'll implement.
    
## Computation and Rendering:

Compute shaders:
*   These will be important for us since they allow us to do lots of computation on the GPU, to then pass to the rendering portion.
    *   This means no CPU -> GPU memory overhead.

Rendering:
*   
