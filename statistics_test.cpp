#include "statistics.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>

int main()
{
    using namespace sts;

    /* Test values:
     * mean = 42.5555555556
     * median = 30
     * range = 202
     * dot = 47753
     * sum of squares = 47753
     * de means = [
     * -41.55555555555556,
     * -40.55555555555556,
     * -39.55555555555556,
     * -2.555555555555557,
     * -12.555555555555557,
     * 160.44444444444446,
     * -9.555555555555557,
     * -21.555555555555557,
     * 7.444444444444443
     *  ]
     * variance = 3931.77777778
     * standard_deviation = 62.7038896543
     */
    std::vector<double> emptyv;
    double testvals[] = {1, 2, 3, 40, 30, 203, 33, 21, 50};
    double epsilon = 1e-5;

    assert(fabs(
        mean(std::begin(emptyv), std::end(emptyv)) - 0.0) <= epsilon);

    assert(fabs(
        mean(std::begin(testvals), std::end(testvals)) - 42.5555555556) <=
        epsilon);

    assert(fabs(
        median(std::begin(testvals), std::end(testvals)) - 30.0) <= epsilon);

    assert(fabs(
        median(std::begin(emptyv), std::end(emptyv)) - 0.0) <= epsilon);

    assert(fabs(
        range(std::begin(testvals), std::end(testvals)) - 202.0) <= epsilon);

    assert(fabs(
        range(std::begin(emptyv), std::end(emptyv)) - 0.0) <= epsilon);

    assert(fabs(
        dot(std::begin(testvals), std::end(testvals),
            std::begin(testvals), std::end(testvals)) - 47753.0) <= epsilon);

    assert(fabs(
        dot(std::begin(emptyv), std::end(emptyv),
            std::begin(emptyv), std::end(emptyv)) - 0.0) <= epsilon);

    assert(fabs(
        sum_of_squares(std::begin(testvals), std::end(testvals)) - 47753.0) <=
        epsilon);

    assert(fabs(
        sum_of_squares(std::begin(emptyv), std::end(emptyv)) - 0.0) <= epsilon);

    std::vector<double> dems;
    de_mean(std::begin(testvals), std::end(testvals),
            std::back_inserter(dems));
    assert(fabs(dems[0] - -41.55555555555556) <= epsilon);
    assert(fabs(dems[1] - -40.55555555555556) <= epsilon);
    assert(fabs(dems[2] - -39.55555555555556) <= epsilon);
    assert(fabs(dems[3] - -2.555555555555557) <= epsilon);
    assert(fabs(dems[4] - -12.555555555555557) <= epsilon);
    assert(fabs(dems[5] - 160.44444444444446) <= epsilon);
    assert(fabs(dems[6] - -9.555555555555557) <= epsilon);
    assert(fabs(dems[7] - -21.555555555555557) <= epsilon);
    assert(fabs(dems[8] - 7.444444444444443) <= epsilon);

    std::vector<double> emptydems;
    de_mean(std::begin(emptyv), std::end(emptyv),
            std::back_inserter(emptydems));
    assert(emptydems.size() == 0);

    assert(fabs(
        variance(std::begin(testvals), std::end(testvals)) - 3931.77777778) <=
        epsilon);

    assert(fabs(
        variance(std::begin(emptyv), std::end(emptyv)) - 0.0) <= epsilon);

    assert(fabs(
        standard_deviation(std::begin(testvals), std::end(testvals)) -
        62.7038896543) <= epsilon);

    assert(fabs(
        standard_deviation(std::begin(emptyv), std::end(emptyv)) - 0.0) <=
        epsilon);

    return 0;
}
