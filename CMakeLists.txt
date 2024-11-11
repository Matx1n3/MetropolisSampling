cmake_minimum_required(VERSION 3.28)
project(metropolis_sampling)

set(CMAKE_CXX_STANDARD 17)

add_executable(metropolis_sampling main.cpp
        MetropolisSampling.h
        PDF.h
        PDFs/Normal1dPDF.cpp
        PDFs/Normal1dPDF.h
)
