# AI From Scratch #

On my mission to understand AI better every day, I have created this repository in order to implement most common AI algorithms in standard C. I will document my journey on the commit history and on this readme.

### math.h ###

As a challenge to me I wanted to implement all functions I would need by hand without using math.h. For the linear layers this is vector-vector and vector-matrix multiplication. Originally I was thinking of defining NaN and the infinities myself, but seeing as NaN for 32-bit integers is defined as 1111 1xxx xxxx xxxx xxxx xxxx xxxx and me not knowing how to create a macro that accepts all potential values, I decided to just use the definitions from math.h for now. Might change in the future :) 

### layer implementations ###
The layers are implemented close to how they would be implemented in a OOP-Language. This is probably not the C-way to do it but I'm hoping that it will allow me to save code in the long run by making the layer structures similar and the executing function uniform. I'm still wondering how I will be able to implement this with higher dimensional inputs like images, but that'll be a problem for future me.
