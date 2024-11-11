//
// Created by matxin on 11/11/24.
//

#ifndef METROPOLISSAMPLING_H
#define METROPOLISSAMPLING_H

#include "PDF.h"

/**
 * @class MetropolisSampling
 * @brief A class to perform Metropolis Sampling with optional thinning.
 *
 * This class implements the Metropolis algorithm, a Markov Chain Monte Carlo (MCMC) method to sample from
 * a target probability distribution function (PDF). It supports thinning to reduce autocorrelation in the
 * generated samples by skipping a specified number of intermediate samples.
 *
 * @tparam element The data type for the elements being sampled (e.g., double for real-valued sampling).
 */
template <typename element>
class MetropolisSampling {
public:
    /**
    * @brief Constructor for MetropolisSampling with thinning option.
    *
    * Initializes the sampler with a given probability distribution function (PDF) and a specified thinning interval.
    * The initial sample is set to a valid candidate from the PDF.
    *
    * @param p A pointer to a PDF<element> object representing the target probability distribution.
    * @param thinning The thinning interval, specifying the number of samples to skip between saved samples.
    */
    explicit MetropolisSampling(PDF<element>* p, int thinning) : pdf(p) {
        if (thinning < 0) {
            throw std::invalid_argument("Thinning interval 'k' must greater than 0.");
        }
        actual = pdf->valid_candidate();
        k = thinning;
    }

    /**
    * @brief Constructor for MetropolisSampling without thinning.
    *
    * Initializes the sampler with a given probability distribution function (PDF) and sets the thinning interval to 0.
    * This means no thinning will be applied, and every sample will be kept.
    *
    * @param p A pointer to a PDF<element> object representing the target probability distribution.
    */
    explicit MetropolisSampling(PDF<element>* p) : pdf(p) {
        actual = pdf->valid_candidate();
        k = 0;
    }

    /**
    * @brief Generates the next sample using Metropolis sampling with optional thinning.
    *
    * If a thinning interval is set, this method runs the `run` method to skip the specified number of samples.
    * Then, it generates the next proposal sample and decides whether to accept it based on the acceptance ratio.
    *
    * @return The next sampled element from the target PDF.
    */
    element get_next_sample() {
        if (k > 0) {
            // Perform thinning by running the Metropolis algorithm for `k` steps
            run(k);
        }
        element proposal = pdf->candidate_proposal(actual);
        double alpha = pdf->probability(proposal) / pdf->probability(actual);

        if (alpha >= 1) {
            actual = proposal;
        } else {
            double u = static_cast<double>(rand()) / RAND_MAX;

            if (u < alpha) {
                actual = proposal;
            }
        }
        return actual;
    }

private:
    PDF<element>* pdf;  // Pointer to the target PDF from which to sample.
    element actual; // The current sample in the Markov chain.
    int k;  // Thinning interval; skips `k` samples between each saved sample.

    /**
     * @brief Runs the Metropolis algorithm for a specified number of iterations.
     *
     * This method generates samples by proposing new candidates and accepting them based on the acceptance ratio.
     * The sampled points are not saved directly but allow updating the `actual` sample.
     *
     * @param iterations The number of iterations to run the Metropolis algorithm.
     */
    void run(int iterations) {
        element proposal;
        double alpha, u;

        for (int i = 0; i < iterations; i++) {

            proposal = pdf->candidate_proposal(actual);
            alpha = pdf->probability(proposal) / pdf->probability(actual);

            if (alpha >= 1) {
                actual = proposal;
            } else {
                u = static_cast<double>(rand()) / RAND_MAX;

                if (u < alpha) {
                    actual = proposal;
                }
            }
        }
    }
};

#endif //METROPOLISSAMPLING_H
