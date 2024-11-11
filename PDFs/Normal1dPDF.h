//
// Created by matxin on 11/11/24.
//

#ifndef NORMAL1DPDF_H
#define NORMAL1DPDF_H

#include "../PDF.h"

/**
 * @class Normal1dPDF
 * @brief A specific implementation of a Probability Density Function (PDF) for a 1D Normal distribution.
 *
 * This class represents a one-dimensional Normal (Gaussian) distribution, where the
 * probability density function (PDF) is defined by the standard normal distribution formula.
 *
 * This implementation provides methods to calculate the probability density, propose candidate
 * samples, and provide a valid initial candidate for sampling algorithms like Metropolis.
 */
class Normal1dPDF : public PDF<double> {
public:
    /**
    * @brief Constructs a Normal1dPDF object with a given mean and standard deviation.
    *
    * Initializes the Normal distribution with a specific mean and standard deviation.
    *
    * @param mean The mean (μ) of the Normal distribution.
    * @param stddev The standard deviation (σ) of the Normal distribution.
    */
    Normal1dPDF(double mean, double stddev);

    /**
     * @brief Calculates the probability density of a given element `x`.
     *
     * Computes the probability density of the element `x` according to the Normal distribution
     * formula. The result is the likelihood of observing the value `x` in a Normal distribution
     * with the specified mean and standard deviation.
     *
     * @param x The element for which the probability density is to be calculated.
     * @return The probability density at `x`.
     */
    double probability(double x) override;

    /**
     * @brief Generates a candidate proposal for the next sample based on the current sample.
     *
     * Proposes a new candidate sample by perturbing the current sample. The perturbation is
     * random, and the step size depends on the specific implementation (e.g., random walk).
     *
     * @param current The current sample (state) in the Markov chain.
     * @return A new candidate sample for the next iteration.
     */
    double candidate_proposal(double current) override;

    /**
     * @brief Returns a valid initial candidate sample.
     *
     * Generates and returns an initial candidate sample that is guaranteed to have a non-zero
     * probability under the Normal distribution. Typically, the initial candidate can be any valid
     * point, as long as it lies within a range where the probability is non-zero.
     *
     * @return A valid initial candidate sample.
     */
    double valid_candidate() override;

private:
    double mean; // The mean (μ) of the Normal distribution.
    double stddev; // The standard deviation (σ) of the Normal distribution.
};

#endif //NORMAL1DPDF_H

