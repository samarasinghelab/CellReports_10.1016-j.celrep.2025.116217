function [Rad_modulogram_mat, AmpFreqVector] = theta_phase_modulogram(data, srate, plot_figure)
% THETA_PHASE_MODULOGRAM Calculate phase-amplitude coupling between theta phase and gamma amplitude
%
% This function computes a modulogram showing how gamma amplitude (25-115 Hz)
% is modulated by theta phase (3-10 Hz), revealing cross-frequency coupling.
%
% Inputs:
%   data        - 1D vector of EEG/LFP data
%   srate       - Sampling rate in Hz
%   plot_figure - Boolean flag to plot the modulogram (true/false)
%
% Outputs:
%   Rad_modulogram_mat - Matrix of normalized amplitude values for each 
%                        gamma frequency (rows) and theta phase bin (columns)
%   AmpFreqVector      - Vector of gamma frequency values analyzed
%
% Dependencies:
%   Requires eegfilt.m from EEGLAB toolbox
%
% Example:
%   [modulogram, freqs] = theta_phase_modulogram(data, 1000, true);
%
% Reference:
%   Based on methods from Tort et al. (2010) J Neurophysiol

%% Define amplitude and phase frequency parameters
AmpFreqVector = 25:2:115;           % Gamma frequencies to analyze (Hz)
AmpFreq_BandWidth = 2;               % Bandwidth for gamma band-pass filter (Hz)
data_length = length(data);

% Phase binning parameters
nbin = 18;                           % Number of phase bins (20° bins)
position = zeros(1, nbin);           % Starting position of each phase bin (radians)
winsize = 2*pi/nbin;                 % Width of each phase bin (radians)

% Calculate the starting position for each phase bin
for j = 1:nbin
    position(j) = -pi + (j-1)*winsize;
end

%% Filter data and extract amplitude envelopes and phase
% Preallocate matrix for gamma amplitude envelopes
AmpFreqTransformed = zeros(length(AmpFreqVector), data_length);

% Extract amplitude envelope for each gamma frequency band
for ii = 1:length(AmpFreqVector)
    Af1 = AmpFreqVector(ii);
    Af2 = Af1 + AmpFreq_BandWidth;
    
    % Band-pass filter for gamma (suppress output with evalc)
    evalc('AmpFreq = eegfilt(data, srate, Af1, Af2);');
    
    % Get amplitude envelope using Hilbert transform
    AmpFreqTransformed(ii, :) = abs(hilbert(AmpFreq));
end

% Extract theta phase time series
evalc('PhaseFreq = eegfilt(data, srate, 3, 10);');  % Band-pass filter for theta
PhaseFreqTransformed = angle(hilbert(PhaseFreq));    % Get instantaneous phase

%% Compute phase-amplitude coupling modulogram
Rad_modulogram_mat = zeros(length(AmpFreqVector), nbin);

for jj = 1:length(AmpFreqVector)
    % Z-score normalize the amplitude envelope
    AmpNorm = (AmpFreqTransformed(jj, :) - mean(AmpFreqTransformed(jj, :))) / ...
              std(AmpFreqTransformed(jj, :));
    
    % Compute mean normalized amplitude for each phase bin
    for ibin = 1:nbin
        % Find time points within current phase bin
        indices = PhaseFreqTransformed >= position(ibin) & ...
                  PhaseFreqTransformed < position(ibin) + winsize;
        
        % Average normalized amplitude for this phase bin
        Rad_modulogram_mat(jj, ibin) = mean(AmpNorm(indices));
    end
end

%% Post-processing
% Flip matrix so high frequencies are at top
Rad_modulogram_mat = flipud(Rad_modulogram_mat);

% Ensure consistent polarity: higher amplitude at peak (center bins)
% If trough has higher amplitude than peak, flip sign
peak_amp = mean(mean(Rad_modulogram_mat(:, 5:13)));      % Center bins (around 0 phase)
trough_amp = mean([mean(mean(Rad_modulogram_mat(:, 1:4))) ...
                   mean(mean(Rad_modulogram_mat(:, 14:18)))]);  % Edge bins (around ±π)

if peak_amp < trough_amp
    Rad_modulogram_mat = Rad_modulogram_mat .* -1;
end

%% Plotting
if plot_figure
    % Find indices closest to 40, 80, and 120 Hz for Y-axis labels
    [~, ind1] = min(abs(AmpFreqVector - 40));
    [~, ind2] = min(abs(AmpFreqVector - 80));
    [~, ind3] = min(abs(AmpFreqVector - 120));
    
    % Adjust indices for flipped matrix
    ind1 = length(AmpFreqVector) - ind1 + 1;
    ind2 = length(AmpFreqVector) - ind2 + 1;
    ind3 = length(AmpFreqVector) - ind3 + 1;
    
    figure;
    colormap('jet');
    contourf(Rad_modulogram_mat, 100, 'lines', 'none')
    
    % Customize axes
    set(gca, 'YTick', [ind1 ind2 ind3], 'YTickLabel', {'40', '80', '120'});
    set(gca, 'XTick', [1 size(Rad_modulogram_mat, 2)], 'XTickLabel', {'-\pi', '\pi'})
    set(gca, 'FontSize', 20)
    
    ylabel('Gamma (Hz)')
    xlabel('Theta (3-10 Hz) Phase')
    title('Theta-Gamma Phase-Amplitude Coupling')
    colorbar
end

end