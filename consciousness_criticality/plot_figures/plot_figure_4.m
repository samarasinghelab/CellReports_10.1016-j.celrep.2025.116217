load('fig_4.mat');

colors = {[255 109 182]./255, [145 73 1]./255,  [35 253 35]./255};
shapes = {'+', '*', 's'};

% Figure 4A
x=[unconscious_c' conscious_c'];
figure('Position',[99 3 450 350]); 
boxplot(x,'symbol','');
hold on;
scatter(ones(1,3),unconscious_c(1:3),250,colors{1},shapes{1});%,'filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
scatter(ones(1,5),unconscious_c(4:8),100,colors{2},shapes{2});%,'filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
scatter(ones(1,4),unconscious_c(9:12),100,'r','filled');%,'filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
legend({'Generalized seizure', 'GABAergic anesthesia', 'DOC'},'AutoUpdate','off')
scatter(ones(1,12)+1,conscious_c,100,'b','filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
set(gca,'XTickLabel', {'Unconscious', 'Conscious'},'FontSize', 15);
ylabel({'Estimated Proximity to Criticality',' (\alpha=0.85)'})
for i = 1:12
plot([1 2],[unconscious_c(i) conscious_c(i)],'Color', [0, 0, 0, 0.3])
end

% Figure 4B
x=[unconscious_univariate_lzc' conscious_univariate_lzc'];
figure('Position',[99 3 450 350]); 
boxplot(x,'symbol','');
hold on;
scatter(ones(1,3),unconscious_univariate_lzc(1:3),250,colors{1},shapes{1});%,'filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
scatter(ones(1,5),unconscious_univariate_lzc(4:8),100,colors{2},shapes{2});%,'filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
scatter(ones(1,4),unconscious_univariate_lzc(9:12),100,'r','filled');%,'filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
legend({'Generalized seizure', 'GABAergic anesthesia', 'DOC'},'AutoUpdate','off')
scatter(ones(1,12)+1,conscious_univariate_lzc,100,'b','filled','MarkerFaceAlpha',0.9');%,'jitter','on','jitterAmount',0.08);
ylabel('Univariate LZ-complexity')
set(gca,'XTickLabel', {'Unconscious', 'Conscious'},'FontSize', 15);
for i = 1:12
plot([1 2],[unconscious_univariate_lzc(i) conscious_univariate_lzc(i)],'Color', [0, 0, 0, 0.3])
end


% Figure 4C
figure('Position',[99 3 450 350]); 
xlim([0 1]);
scatter(unconscious_c(1:3),unconscious_univariate_lzc(1:3),200,colors{1},shapes{1});
hold on;
scatter(unconscious_c(4:8),unconscious_univariate_lzc(4:8),200,colors{2},shapes{2});
scatter(unconscious_c(9:12),unconscious_univariate_lzc(9:12),200,'r','filled');
scatter(conscious_c,conscious_univariate_lzc,200,'b','s','filled')
f=fit([conscious_c unconscious_c]',[conscious_univariate_lzc unconscious_univariate_lzc]','poly1');
xlim([0 1])
plot(f)
xlabel({'Estimated Proximity to Criticality',' (\alpha=0.85)'})
ylabel('Univariate LZ-complexity')
legend({'Generalized seizures', 'GABAergic anesthesia', 'DOC','Conscious'},'FontSize', 14)
set(gca,'FontSize', 18)



% Figure 4D
l=8;
figure('Position',[99 3 450 350]); 
set(0, 'DefaultFigureRenderer', 'painters');
errorbar(.4:1:(l/2), doc_c_median(1:2:l),doc_c_sem(1:2:l),'vertical', 'o','MarkerSize',9,'MarkerEdgeColor', 'r','MarkerFaceColor', 'r')
ylim([.92*min(doc_c_median) 1.1*max(doc_c_median)]);
hold on;
errorbar(.6:1:(l/2), doc_c_median(2:2:l),doc_c_sem(2:2:l),'vertical', 'o','MarkerSize',9, 'MarkerEdgeColor', 'b', 'MarkerFaceColor', 'b')
for i = 1:(l/2)
    lab{i} = num2str(i);
end
xtick = .5:1:(l/2);
set(gca,'XTick', xtick, 'XTickLabel', lab,'box', 'off','FontSize', 16)
xlabel('Subjects');
ylabel({'Estimated Proximity to Criticality', '(\alpha=0.85)'});
legend({'Likely Comatose (Verbal GCS<4 and Motor GCS<5)', 'Conscious (Verbal GCS\geq4 or Motor GCS\geq5)'});
