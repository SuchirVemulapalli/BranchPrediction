# BranchPrediction

Pipelining in terms of computer architecture can best be described as fetching sequential instructions and holding them in a buffer close to the processor while the processor is performing arithmetic operations on the current instruction. Pipelining allows for the number of instructions executed within a given time period to be greatly increased. However, whenever a branch is taken, the instructions in the buffer are useless since the instructions are no longer executing sequentially. The pipeline must now be loaded with a new set of instructions in a process known as flushing the pipes. This process is extremely inefficient and greatly reduces the number of instructions that can be processed within a given time frame. Thus, any approach that seeks to reduce the amount of the times the pipeline needs to be flushed is essential.

Branch prediction, the process by which a processor predicts whether a branch will be taken or not, is the solution.

This repository will eventually be expanded to contain more projects on branch prediction simulation as I continue to make them. 
