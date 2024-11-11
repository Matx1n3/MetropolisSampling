# Metropolis Sampling

This project implements the Metropolis-Hastings algorithm for sampling from a probability 
distribution function (PDF). It supports optional thinning, which allows skipping samples
in between accepted ones to reduce autocorrelation, thus simulating an independent sampler.

## Features

- **Metropolis-Hastings Sampler**: Samples from a given PDF using the Metropolis-Hastings algorithm.
- **Thinning**: Allows skipping a specified number of samples between accepted ones to reduce autocorrelation.
- **Custom PDFs**: Easily extendable to any PDF by implementing the `PDF` interface.

## Installation

1. Clone the repository.
2. Compile using a C++ compiler (e.g., `g++`).
