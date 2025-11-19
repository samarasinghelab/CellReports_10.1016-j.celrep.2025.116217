load('fig_2.mat');

anesthesia_ind = 425;
seizure_ind = 469;
wake_ind = 313;

colors = {[255 109 182]./255, [145 73 1]./255,'b'};
shapes = {'+', '*','filled',};

inds = [seizure_ind anesthesia_ind wake_ind];

% Figure 2A
f=figure('Position', [317 3 847 326]);
set(f,'defaultLegendAutoUpdate','off');
subplot(1,3,1); scatter(lyapunov_exponents,univariate_lzc,10,[190 190 190]/255,'filled'); title('Univariate LZc');
ylabel('Information-richness')
set(gca,'FontName', 'Arial', 'FontSize', 12)
hold on;
subplot(1,3,2); scatter(lyapunov_exponents,joint_lzc,10,[190 190 190]/255,'filled'); title('Joint LZc');
xlabel('Largest Lyapunov Exponent')
set(gca,'FontName', 'Arial', 'FontSize', 12)
hold on;
subplot(1,3,3); scatter(lyapunov_exponents,concatenated_lzc,10,[190 190 190]/255,'filled'); title('Concatenated LZc');
set(gca,'FontName', 'Arial', 'FontSize', 12)
hold on;
for i = 1:3
    subplot(1,3,1);
    scatter(lyapunov_exponents(inds(i)), univariate_lzc(inds(i)),200,colors{i}, shapes{i},'LineWidth',4); hold on;
    subplot(1,3,2);
    scatter(lyapunov_exponents(inds(i)), joint_lzc(inds(i)),200,colors{i}, shapes{i},'LineWidth',4); hold on;
    subplot(1,3,3);
    scatter(lyapunov_exponents(inds(i)), concatenated_lzc(inds(i)),200,colors{i}, shapes{i},'LineWidth',4); hold on;
end
legend({'Parameter Sweep', 'Generalized Seizure', 'Anesthesia', 'Waking'})
for i = 1:3
    subplot(1,3,1);
    xline(0,'r','LineWidth',.7);
    subplot(1,3,2);
    xline(0,'r','LineWidth',.7);
    subplot(1,3,3);
    xline(0,'r','LineWidth',.7);
end



% Figure 2B
figure('Position', [317 3 847 326])
subplot(1,3,1); scatter(k_statistic,univariate_lzc,10,[190 190 190]/255,'filled'); title('Univariate LZc'); xlim([-.3 1.2]);
ylabel('Information-richness')
set(gca,'FontName', 'Arial', 'FontSize', 12)
hold on;
subplot(1,3,2); scatter(k_statistic,joint_lzc,10,[190 190 190]/255,'filled'); title('Joint LZc'); xlim([-.3 1.2]);
xlabel('K (0-1 Chaos Test)')
set(gca,'FontName', 'Arial', 'FontSize', 12)
hold on;
subplot(1,3,3); scatter(k_statistic,concatenated_lzc,10,[190 190 190]/255,'filled'); title('Concatenated LZc'); xlim([-.3 1.2]);
set(gca,'FontName', 'Arial', 'FontSize', 12)
hold on;
for i = 1:3
    subplot(1,3,1);
    scatter(k_statistic(inds(i)), univariate_lzc(inds(i)),200,colors{i}, shapes{i},'LineWidth',4); hold on;
    subplot(1,3,2);
    scatter(k_statistic(inds(i)), joint_lzc(inds(i)),200,colors{i}, shapes{i},'LineWidth',4); hold on;
    subplot(1,3,3);
    scatter(k_statistic(inds(i)), concatenated_lzc(inds(i)),200,colors{i}, shapes{i},'LineWidth',4); hold on;
end
legend({'Parameter Sweep', 'Generalized Seizure', 'Anesthesia', 'Waking'})