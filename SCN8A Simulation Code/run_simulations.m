clear all
varnames = {'vara', 'varb', 'varc', 'varh', ...
'vari', 'varj', 'vark', 'varl', 'varm', 'varn', 'varo', 'varp', ...
'varq', 'var2r', 'vars', 'vart', 'varu', 'varv', 'varw', 'varx', ...
'vary', 'varz', 'var1a', 'var1b', 'var1c', 'var1d', 'var1e', 'var1f'};


%% Simulate Control Local Field Potential (LFP) and Raster Plot
load('ctrl_parameters.mat');
paramValues=ctrl_params;
rng_seed=1;
run=1;
paramValues(10)=-70.1;
system(['sed ''s/' varnames{1} '/' num2str(paramValues(1)) '/'' synapses2.hoc > temp_synapses' num2str(run) '.hoc']);
for i = 2:numel(varnames)
system(['sed -ie ''s/' varnames{i} '/' num2str(paramValues(i)) '/g'' temp_synapses' num2str(run) '.hoc']);
end
system(['sed ''s/snvar/' num2str(run) '/'' OIENetwork2.hoc > temp_OIENetwork' num2str(run) '.hoc']);
system(['sed -ie ''s/rseed/' num2str(rng_seed) '/g'' temp_OIENetwork' num2str(run) '.hoc']);
system(['/Applications/NEURON/bin/nrniv temp_OIENetwork' num2str(run) '.hoc']);
ctrl_lfp=readtable(['lfp/' num2str(run) '.txt']);
ctrl_lfp=table2array(ctrl_lfp);
ctrl_raster=collect_raster(round(paramValues(1)),round(paramValues(2)),round(paramValues(3)),run,length(ctrl_lfp));



%% Simulate Mut Local Field Potential (LFP) and Raster Plot
load('mut_parameters.mat');
paramValues=mut_params;
rng_seed=1;
run=1;
paramValues(10)=-70.1;
system(['sed ''s/' varnames{1} '/' num2str(paramValues(1)) '/'' synapses2.hoc > temp_synapses' num2str(run) '.hoc']);
for i = 2:numel(varnames)
system(['sed -ie ''s/' varnames{i} '/' num2str(paramValues(i)) '/g'' temp_synapses' num2str(run) '.hoc']);
end
system(['sed ''s/snvar/' num2str(run) '/'' OIENetwork2.hoc > temp_OIENetwork' num2str(run) '.hoc']);
system(['sed -ie ''s/rseed/' num2str(rng_seed) '/g'' temp_OIENetwork' num2str(run) '.hoc']);
system(['/Applications/NEURON/bin/nrniv temp_OIENetwork' num2str(run) '.hoc']);
mut_lfp=readtable(['lfp/' num2str(run) '.txt']);
mut_lfp=table2array(mut_lfp);
mut_raster=collect_raster(round(paramValues(1)),round(paramValues(2)),round(paramValues(3)),run,length(mut_lfp));