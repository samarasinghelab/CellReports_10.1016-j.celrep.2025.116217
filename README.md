# Research Code & Data Repository

This repository contains the source code, simulation scripts, and data analysis tools associated with research publications by Toker et al. The codebase is organized by project folder.

## Repository Structure

```text
├── phase_amplitude_coupling/    # LFP Analysis: PAC, Waveform Shape, & Filtering
├── SCN8A Simulation Code/       # Neural simulations (NEURON/MATLAB)
├── chaos/                       # The Chaos Decision Tree Algorithm
└── consciousness_criticality/   # Criticality & Complexity Metrics
```

-----

## 1\. Phase-Amplitude Coupling & LFP Analysis

**Folder:** `phase_amplitude_coupling/`

This folder contains MATLAB scripts used to analyze Local Field Potentials (LFP). These tools focus on quantifying cross-frequency interactions and waveform shape properties.

### Included Files

  * **`theta_phase_modulogram.m`:** Performs phase-amplitude coupling (PAC) analysis. It specifically calculates the modulation index to assess how the phase of low-frequency oscillations (e.g., theta) modulates the amplitude of high-frequency signals.
  * **`calculate_monophasicity.m`:** Computes the "monophasicity" of a signal, a metric used to describe the isolated coupling behavior of neural oscillations.
  * **`eegfilt.m`:** A standard routine for filtering EEG/LFP data, used as a preprocessing step for the analyses above.

-----

## 2\. Consciousness & Criticality Metrics

**Folder:** `consciousness_criticality/`

This code implements the dynamical systems methods described in **Toker et al, "Consciousness is supported by near-critical slow cortical electrodynamics" (PNAS, 2022)**.

### Description

This directory contains scripts for quantifying dynamical complexity and the proximity to edge-of-chaos criticality.

  * **`criticality.m`:** Time-series estimate of proximity to edge-of-chaos criticality.
  * **`chaos_test.m`:** The modified 0-1 chaos test.
  * **`stochastic_test.m`:** Modified stochasticity test.
  * **`fJLZC.m`:** Lempel-Ziv complexity calculation.
  * **`select_low_pass_freq.m`:** Helper for selecting filter cutoffs.

### Reference

> Toker, D., et al. (2022). Consciousness is supported by near-critical slow cortical electrodynamics. *Proceedings of the National Academy of Sciences*.

### External Links

  * **Original Repository (Figshare):** [View on Figshare](https://figshare.com/articles/software/Consciousness_is_supported_by_near-critical_cortical_electrodynamics/12949355)
  * **Alternative GitHub:** [Consciousness-is-supported-by-near-critical-slow-cortical-electrodynamics](https://www.google.com/search?q=https://github.com/danieltoker1/Consciousness-is-supported-by-near-critical-slow-cortical-electrodynamics)

-----

## 3\. The Chaos Decision Tree Algorithm

**Folder:** `chaos/`

This code implements the **Chaos Decision Tree Algorithm**, used to quickly and automatically determine if a time-series is stochastic, periodic, or chaotic.

### Description

The algorithm utilizes surrogate testing, de-noising, and the modified 0-1 test for chaos to identify systems with exponential sensitivity to initial conditions. The repository also includes code to simulate a variety of stochastic, periodic, and chaotic datasets for testing purposes.

### Reference

> Toker, D., Sommer, F. T., & D’Esposito, M. (2020). A simple method for detecting chaos in nature. *Communications Biology*, 3(1), 11.

### External Links

  * **Original Repository (Figshare):** [View on Figshare](https://figshare.com/s/80891dfb34c6ee9c8b34)
  * **Alternative GitHub:** [The-Chaos-Decision-Tree-Algorithm](https://github.com/danieltoker1/The-Chaos-Decision-Tree-Algorithm)

-----

## 4\. SCN8A Simulation Code (Assembloid Models)

**Folder:** `SCN8A Simulation Code/`

Code relating to the modeling of cortical versus hippocampal network dysfunction in human brain assembloid models of epilepsy.

### Description

This directory contains **NEURON** (`.hoc`, `.mod`) and **MATLAB** (`.m`) scripts for simulating neural network activity.

  * **Mechanism files:** `IcellWangBuzsaki.mod`, `ecellolufsen_inap_inactivation.mod`
  * **Network setup:** `OIENetwork2.hoc`, `synapses.hoc`
  * **Execution:** `run_simulations.m`

### External Links

  * **Data Repository:** [View on Figshare](https://www.google.com/search?q=https://figshare.com/articles/software/Modeling_Cortical_Versus_Hippocampal_Network_Dysfunction_in_a_Human_Brain_Assembloid_Model_of_Epilepsy_and_Intellectual_Disability/26339662%3Ffile%3D47812873)

-----

## Requirements

  * **MATLAB:** The LFP analysis, PAC, and Chaos scripts (`.m`) are written for MATLAB.
  * **MEX Compiler:** Some functions in the criticality folder (e.g., `complexity.mexa64`) are compiled C/C++ executables for MATLAB and may require recompilation depending on your operating system.
  * **NEURON Simulation Environment:** Required for running the `.hoc` and `.mod` files in the `SCN8A Simulation Code` directory.
