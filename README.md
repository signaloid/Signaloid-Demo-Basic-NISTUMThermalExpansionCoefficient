[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-v6.png#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/signaloid/Signaloid-Demo-Basic-NISTUMThermalExpansionCoefficient#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-v6.png#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/signaloid/Signaloid-Demo-Basic-NISTUMThermalExpansionCoefficient#gh-light-mode-only)

# MICRO Benchmark: Thermal Expansion Coefficient

Benchmark from Tsoutsouras et al. MICRO paper[^0] for comparison against the NIST Uncertainty Machine[^1].

Calculates the thermal expansion coefficient of a rod using its initial length $L_a$ , final lengths $L_b$ and the temperature difference $∆T$.
The inputs parameters are modeled as Student’s-t random variables.

## Inputs

The samples are stored in a text file.
The first line of the file is the number of samples that follow.
See the source code to know which files are used and how.

[^0]: Vasileios Tsoutsouras, Orestis Kaparounakis, Bilgesu Arif Bilgin, Chatura Samarakoon, James Timothy Meech, Jan Heck, Phillip Stanley-Marbell: The Laplace Microarchitecture for Tracking Data Uncertainty and Its Implementation in a RISC-V Processor. MICRO 2021: 1254-1269

[^1]: Thomas Lafarge and Antonio Possolo. 2015. NIST Uncertainty Machine–User’s Manual. National Institute of Standards and Technology, Gaithersburg (2015).
