//
// Created by matxin on 11/11/24.
//

#ifndef PDF_H
#define PDF_H

/**
 * @class PDF
 * @brief Abstract base class representing a Probability Density Function (PDF).
 *
 * This is an abstract class that defines the basic interface for any probability
 * distribution function (PDF) used in sampling algorithms, such as Metropolis
 * Sampling. It defines methods to calculate the probability of a given element,
 * generate candidate proposals for the next sample, and obtain a valid initial sample.
 *
 * Subclasses must implement these methods to define a specific distribution.
 *
 * @tparam element The type of elements being sampled (e.g., `double` for real-valued distributions).
 */
template <typename element>
class PDF {
public:
    /**
     * @brief Calculates the probability of a given element.
     *
     * This method should return the probability density (or mass) of the given element
     * according to the specific PDF.
     *
     * @param x The element for which the probability density is to be calculated.
     * @return The probability density of the element.
     */
    virtual double probability(element x) = 0;

    /**
      * @brief Proposes a candidate sample based on the current state.
      *
      * This method generates a candidate sample based on the current state. The step size
      * for the proposal should be small enough to avoid large, rejected proposals but large
      * enough to efficiently explore the target PDF.
      *
      * @param current The current state or sample from which the proposal will be generated.
      * @return A new proposed candidate element.
      */
    virtual element candidate_proposal(element current) = 0;

    /**
     * @brief Returns a valid initial candidate sample.
     *
     * This method generates and returns a valid initial candidate sample for the sampling process.
     * The first candidate should be a valid point where the probability density is non-zero to avoid
     * issues with undefined acceptance probabilities in algorithms like Metropolis sampling.
     *
     * @return A valid initial candidate element.
     */
    virtual element valid_candidate() = 0;

    /**
     * @brief Virtual destructor for the base class.
     *
     * The virtual destructor ensures that derived class destructors are called correctly when
     * objects of derived types are deleted through a base class pointer.
     */
    virtual ~PDF() = default;
};

#endif //PDF_H
