# (N,2) Correlated Branch Predictor

This C++ program takes an arbitrary branch target address determined by user input and collects N bits (N is determined by user input) of that address. These N bits are used to index and modify both a Local History Table and a 2-bit finite state machine within a Local Pattern Table to predict whether a branch will be taken or not. The program prints the predicted outcomes and computes accuracy of the prediction in comparison to the actual outcomes.

Over time, correlated branch predictors will be more accurate than naive or traditional branch prediction implementations due to the fact that it considers the recent behavior of previous branches.

Acknowledgments:

https://www.geeksforgeeks.org/correlating-branch-prediction/

https://www.youtube.com/watch?v=ivLZ8VRucNQ



