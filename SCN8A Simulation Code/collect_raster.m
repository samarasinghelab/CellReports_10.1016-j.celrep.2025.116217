function raster = collect_raster(ocelln,icelln,ecelln,run,raster_length)

oraster=zeros(ocelln,raster_length);
for j = 1:ocelln
    data=readtable(['raster/' num2str(run) 'Ocell' num2str(j-1) '0.txt']);
    dat1=data.Var1;
    oraster(j,round(dat1))=1;
end

iraster=zeros(icelln,raster_length);
for j = 1:icelln
    data=readtable(['raster/' num2str(run) 'Icell' num2str(j-1) '0.txt']);
    dat1=data.Var1;
    iraster(j,round(dat1))=1;
end

eraster=zeros(ecelln,raster_length);
for j = 1:ecelln
    data=readtable(['raster/' num2str(run) 'Ecell' num2str(j-1) '0.txt']);
    if ismember('Var1', data.Properties.VariableNames)
        dat1=data.Var1;
        eraster(j,round(dat1))=1;
    end
end

raster=[oraster; iraster; eraster];