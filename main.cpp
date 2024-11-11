#include <iostream>
#include <cmath>
#include <random>

#include "MetropolisSampling.h"
#include "PDFs/Normal1dPDF.h"

/**
 * @brief Main function to demonstrate the usage of the Metropolis Sampling algorithm.
 *
 * This program runs a Metropolis sampling process on a 1D Normal distribution
 * (with mean 0 and standard deviation 10). The `MetropolisSampling` class is used
 * to perform sampling with a thinning of 10 million iterations before accepting each sample.
 * It outputs the first 10 accepted samples from the distribution.
 */
int main() {
    // Initialize the MetropolisSampling object with a Normal1dPDF distribution and a thinning factor of 10000000
    MetropolisSampling<double> metropolis = MetropolisSampling(new Normal1dPDF(0, 10), 10000000);

    // Generate and print the first 10 samples from the Metropolis sampler
    for (int i = 0; i < 10; i++) {
        printf("%f\n", metropolis.get_next_sample());
    }
}
