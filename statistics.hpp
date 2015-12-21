#ifndef STATISTICS_INCLUDED
#define STATISTICS_INCLUDED

#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>

namespace sts {

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
mean(InputIt first, InputIt last)
{
    typename std::iterator_traits<InputIt>::value_type sum{};
    typename std::iterator_traits<InputIt>::difference_type n{};

    n = std::distance(first, last);

    for (; first != last; ++first) {
        sum += *first;
    }
    return (sum / n);
}

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
median(InputIt first, InputIt last)
{
    // copy input to a vector to use RandomAccessIterator and
    // do not modifiy input.
    std::vector<typename std::iterator_traits<InputIt>::value_type> sorted;
    std::copy(first, last, std::back_inserter(sorted));
    std::sort(sorted.begin(), sorted.end());

    typename std::vector<
        typename std::iterator_traits<InputIt> >::size_type n = sorted.size();
    int midpoint = n / 2;

    if ((n % 2) == 1) {
        return sorted[midpoint];
    } else {
        int lo = midpoint - 1;
        int hi = midpoint;
        return ((sorted[lo] + sorted[hi]) / 2);
    }
}

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
range(InputIt first, InputIt last)
{
    std::vector<typename std::iterator_traits<InputIt>::value_type> sorted;
    std::copy(first, last, std::back_inserter(sorted));
    std::sort(sorted.begin(), sorted.end());
    // return (last elm - first elm) from sorted values.
    return (sorted[sorted.size()-1] - sorted[0]);
}

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
dot(InputIt first1, InputIt last1, InputIt first2, InputIt last2)
{
    typename std::iterator_traits<InputIt>::value_type sum{};

    typename std::iterator_traits<InputIt>::difference_type n = std::min(
            std::distance(first1, last1),
            std::distance(first2, last2));

    for (typename std::iterator_traits<InputIt>::difference_type i = 0;
            i < n; ++i) {
        sum += ((*first1) * (*first2));
        ++first1;
        ++first2;
    }
    return sum;
}

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
sum_of_squares(InputIt first, InputIt last)
{
    return dot(first, last, first, last);
}

template <typename InputIt, typename OutputIt>
OutputIt de_mean(InputIt first, InputIt last, OutputIt output)
{
    typename std::iterator_traits<InputIt>::value_type bar(mean(first, last));
    for (; first != last; ++first) {
        *output++ = *first - bar;
    }
    return output;
}

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
variance(InputIt first, InputIt last)
{
    std::vector<
        typename std::iterator_traits<InputIt>::value_type > deviations;
    de_mean(first, last, std::back_inserter(deviations));

    typename std::iterator_traits<InputIt>::difference_type n =
        std::distance(first, last);
    if (n > 2) {
        n -= 1;
    }
    return (sum_of_squares(deviations.begin(), deviations.end()) / n);
}

template <typename InputIt>
typename std::iterator_traits<InputIt>::value_type
standard_deviation(InputIt first, InputIt last)
{
    return std::sqrt(variance(first, last));
}

} // namespace sts

#endif // !STATISTICS_INCLUDED
