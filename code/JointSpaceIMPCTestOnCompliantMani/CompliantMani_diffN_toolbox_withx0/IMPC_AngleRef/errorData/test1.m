load('Np3Nc3_error.mat');
load('Np3Nc3_time.mat');
load('Np5Nc3_error.mat');
load('Np5Nc3_time.mat');
load('Np5Nc5_error.mat');
load('Np5Nc5_time.mat');
load('Np10Nc10_error.mat');
load('Np10Nc10_time.mat');
load('Np12Nc12_error.mat');
load('Np12Nc12_time.mat');
load('Np15Nc15_error.mat');
load('Np15Nc15_time.mat');
load('Np20Nc20_error.mat');
load('Np20Nc20_time.mat');

Np = [3,5,5,10,12,15,20]';
Nc = [3,3,5,10,12,15,20]';
error = [Np3Nc3_error.std,Np5Nc3_error.std,Np5Nc5_error.std, ...
         Np10Nc10_error.std,Np12Nc12_error.std,Np15Nc15_error.std, ...
         Np20Nc20_error.std]';
figure(1);
plot3(Np,Nc,error);


time = [Np3Nc3_time.mean,Np5Nc3_time.mean,Np5Nc5_time.mean, ...
         Np10Nc10_time.mean,Np12Nc12_time.mean,Np15Nc15_time.mean, ...
         Np20Nc20_time.mean]';
figure(2);
plot3(Np,Nc,time);