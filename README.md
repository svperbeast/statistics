# statistics functions

A simple statistics header-only implementation:

* mean
* median
* range
* dot
* sum of squares
* de-mean
* variance
* standard deviation

# examples

## header inclusion

    #include "statistics.hpp"

## test values

    float testvals[] = {2, 4, 9, 14};

## mean

    float m = sts::mean(std::begin(testvals), std::end(testvals));

## de-mean

    std::vector<float> dems;
    sts::de_mean(std::begin(testvals), std::end(testvals),
            std::back_inserter(dems));
