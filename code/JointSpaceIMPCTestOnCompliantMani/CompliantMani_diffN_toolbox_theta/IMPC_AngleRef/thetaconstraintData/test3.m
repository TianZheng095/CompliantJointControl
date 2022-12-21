load('Np3Nc3_q.mat');
load('Np3Nc3_time.mat');
load('Np5Nc3_q.mat');
load('Np5Nc3_time.mat');
load('Np10Nc3_q.mat');
load('Np10Nc3_time.mat');
load('Np5Nc5_q.mat');
load('Np5Nc5_time.mat');
load('Np10Nc5_q.mat');
load('Np10Nc5_time.mat');
load('Np10Nc10_q.mat');
load('Np10Nc10_time.mat');
load('Np15Nc10_q.mat');
load('Np15Nc10_time.mat');
load('Np15Nc15_q.mat');
load('Np15Nc15_time.mat');

Np = [3,5,10,5,10,10,15,15]';
Nc = [3,3, 3,5, 5,10,10,15]';
error = [Np3Nc3_q.max,Np5Nc3_q.max,Np10Nc3_q.max,Np5Nc5_q.max, ...
         Np10Nc5_q.max,Np10Nc10_q.max,Np15Nc10_q.max,Np15Nc15_q.max]'-50;
figure(1);
plot3(Np,Nc,error);title('max extended q');


time = [Np3Nc3_time.mean,Np5Nc3_time.mean,Np10Nc3_time.mean,Np5Nc5_time.mean, ...
        Np10Nc5_time.mean,Np10Nc10_time.mean,Np15Nc10_time.mean,Np15Nc15_time.mean]';
figure(2);
plot3(Np,Nc,time);title('computing time');