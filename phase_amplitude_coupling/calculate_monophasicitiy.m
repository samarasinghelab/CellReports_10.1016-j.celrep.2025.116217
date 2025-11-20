function monophasicity = calculate_monophasicity(x, srate)
% CALCULATE_MONOPHASICITY Quantify the monophasicity of theta-gamma phase-amplitude coupling
%
% This function measures the degree to which different gamma frequency bands
% couple to the same phase of theta oscillations. Higher monophasicity indicates
% that multiple gamma frequencies are modulated by a common theta phase, suggesting
% a unified oscillatory mechanism. Lower values suggest different gamma bands
% couple to different theta phases (polyphasic coupling).
%
% The metric is computed as the median correlation between phase preference
% profiles across different gamma frequencies.
%
% Inputs:
%   x     - 1D vector of EEG/LFP data
%   srate - Sampling rate in Hz
%
% Outputs:
%   monophasicity - Scalar value representing the median correlation between
%                   gamma frequency bands' theta phase preferences (range: -1 to 1)
%                   Higher values indicate more monophasic coupling
%
% Dependencies:
%   Requires theta_phase_modulogram.m function
%
% Example:
%   data = randn(1, 10000);           % Example data
%   mono_score = calculate_monophasicity(data, 1000);  % 1000 Hz sampling rate
%
% Reference:
%   McCrimmon, C. M. & Toker, D., et al. (2025). "Cortical versus hippocampal 
%   network dysfunction in a human brain assembloid model of epilepsy and 
%   intellectual disability." Cell Reports.

%% Compute theta-gamma phase-amplitude coupling modulogram
% Generate modulogram: rows = gamma frequencies, columns = theta phase bins
theta_gamma_modulogram = theta_phase_modulogram(x, srate, false);

%% Calculate pairwise correlations between gamma frequency profiles
% Each row represents how a specific gamma frequency's amplitude varies
% across theta phase bins. Correlation measures similarity of phase preference.
c = corr(theta_gamma_modulogram');

% Remove diagonal (self-correlations) by setting to NaN
c(logical(eye(size(c)))) = NaN;

%% Compute monophasicity as median correlation
% Use median to get robust central tendency of all pairwise correlations
% High positive values: gamma bands couple to similar theta phases (monophasic)
% Values near zero: gamma bands couple to different theta phases (polyphasic)
monophasicity = nanmedian(c(:));

end