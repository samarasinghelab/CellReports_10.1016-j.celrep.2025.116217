
load('fig_3.mat');
colors = {[255 109 182]./255, [145 73 1]./255,  [35 253 35]./255};
shapes = {'+', '*', 's'};
figure('Position', [317 3 847 326]);
for i = 1:3
    subplot(1,3,1); scatter(normalized_k_statistic{i},normalized_univariate_lzc{i},90,colors{i},shapes{i}); title('Univariate LZc');
    set(gca,'FontName', 'Arial', 'FontSize', 12)
    hold on;
    subplot(1,3,2); scatter(normalized_k_statistic{i},normalized_joint_lzc{i},90,colors{i},shapes{i}); title('Joint LZc');
    set(gca,'FontName', 'Arial', 'FontSize', 12)
    hold on;
    subplot(1,3,3); scatter(normalized_k_statistic{i},normalized_concatenated_lzc{i},90,colors{i},shapes{i}); title('Concatenated LZc'); 
    set(gca,'FontName', 'Arial', 'FontSize', 12)
    hold on;
    clear k km k3 k4 lus lmjs lmcs nons
end
subplot(1,3,1); scatter(1,1,120,'b', 'filled'); xlim([0 1.2]); ylim([.6 1.2])
subplot(1,3,2); scatter(1,1,120,'b', 'filled'); xlim([0 1.2]);ylim([.6 1.2])
subplot(1,3,3); scatter(1,1,120,'b', 'filled'); xlim([0 1.2]); ylim([.6 1.2])
legend({'Generalized Seizures', 'Anesthesia', 'LSD','Waking'})