//
// Created by matxin on 11/11/24.
//
#include <math.h>
#include "Normal1dPDF.h"


/**
 * @brief Constructor for Normal1dPDF.
 * Initializes the Normal distribution with the given mean and standard deviation.
 */
Normal1dPDF::Normal1dPDF(double mean, double stddev) : mean(mean), stddev(stddev) {}

/**
 * @brief Calculates the probability density of `x` under the Normal distribution.
 * Uses the standard Gaussian formula: P(x) = (1 / (σ√2π)) * exp(-0.5 * ((x - μ) / σ)²)
 */
double Normal1dPDF::probability(double x) {
    double exponent = -0.5 * pow((x - mean) / stddev, 2);
    double log_prob = -log(stddev * sqrt(2 * M_PI)) + exponent;
    return exp(log_prob);
}

/**
 * @brief Proposes a new candidate sample by perturbing the current sample.
 * Adds a random perturbation to the current value within the range [-1, 1].
 */
double Normal1dPDF::candidate_proposal(double current) {
    return current + (double(rand()) / double(RAND_MAX) * 2 - 1);
}

/**
 * @brief Returns a valid initial candidate sample.
 *
 * Typically, returns a value with a non-zero probability under the Normal distribution.
 * In this case, the initial candidate is chosen to be the mean of the distribution,
 * which is a valid point as the probability density is highest at the mean.
 */
double Normal1dPDF::valid_candidate() {
    return mean;
}