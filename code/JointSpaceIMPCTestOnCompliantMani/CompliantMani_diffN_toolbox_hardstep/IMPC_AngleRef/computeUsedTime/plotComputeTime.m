clc; close all; clear all;

numPlot = 3981;

load('UsingTime_IMPC_Np20_Nc10.mat'); 
load('UsingTime_IMPC_Np20_Nc20.mat'); 
load('UsingTime_IMPC_Np30_Nc10.mat'); 
load('UsingTime_IMPC_Np30_Nc30.mat'); 
% load('UsingTime_HIMPC_N20.mat'); 

figure;
t = 2:numPlot;

plot(t, [UsingTime_IMPC_Np20_Nc10(2,2:numPlot); ...
         UsingTime_IMPC_Np20_Nc20(2,2:numPlot); ...
         UsingTime_IMPC_Np30_Nc10(2,2:numPlot); ...
         UsingTime_IMPC_Np30_Nc30(2,2:numPlot)]);
     
     
legend('Np=20;Nc=10', 'Np=20;Nc=20', 'Np=30;Nc=10','Np=30;Nc=30');  

% hold on
% load('UsingTime_HIMPC_N5_betterCPU.mat'); 
% plot(t, UsingTime_HIMPC_N5(2,1:numPlot));


 
% plot(t, UsingTime_IMPC_Np20_Nc10(2,2:numPlot));
% legend('Np=20;Nc=10');