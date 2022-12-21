load('Nc5Np5_error.mat');
load('Nc5Np5_time.mat');
load('Nc5Np8_error.mat');
load('Nc5Np8_time.mat');
load('Nc5Np10_error.mat');
load('Nc5Np10_time.mat');
load('Nc8Np8_error.mat');
load('Nc8Np8_time.mat');
load('Nc8Np10_error.mat');
load('Nc8Np10_time.mat');
load('Nc8Np12_error.mat');
load('Nc8Np12_time.mat');


Nc = [5,5,5,8,8,8]';
Np = [5,8,10,8,10,12]';
extend = [Nc5Np5_error_extend,Nc5Np8_error_extend,Nc5Np10_error_extend, ...
    Nc8Np8_error_extend,Nc8Np10_error_extend,Nc8Np12_error_extend]';
figure(1);
plot3(Nc,Np,extend);title('max extended q');

error = [Nc5Np5_error_rmse,Nc5Np8_error_rmse,Nc5Np10_error_rmse, ...
    Nc8Np8_error_rmse,Nc8Np10_error_rmse,Nc8Np12_error_rmse]';
figure(2);
plot3(Nc,Np,error);title('position error rmse (without where qref>qmax)');

time = [Nc5Np5_time_mean,Nc5Np8_time_mean,Nc5Np10_time_mean, ...
    Nc8Np8_time_mean,Nc8Np10_time_mean,Nc8Np12_time_mean]';
figure(3);
plot3(Nc,Np,time);title('average computing time');