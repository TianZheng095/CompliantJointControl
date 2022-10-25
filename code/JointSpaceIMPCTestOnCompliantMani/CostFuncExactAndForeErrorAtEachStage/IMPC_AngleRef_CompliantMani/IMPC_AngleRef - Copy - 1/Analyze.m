%% Analyze results
clc; close all;

% Load test data
load('Data\q.mat'); load('Data\qd.mat'); load('Data\T.mat'); 
q = q(2:end,:); qd = qd(2:end,:); T = T(2:end,:); 

% Basic parameters
n_plot = max(size(q));
const_trans2degree = 180/pi;

% Plot degree & degree velocity of joints & 
figure;
subplot(2,1,1); plot(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)),'-r'); title('e of q');
subplot(2,1,2); plot(const_trans2degree*(qd(1,1:n_plot)-Xr(2,1:n_plot)),'-r'); title('e of qd');


% Plot degree & degree velocity of joints & 
figure;
subplot(2,1,1); plot(const_trans2degree*q(1,1:n_plot),'-r'); title('q');
hold on 
plot(const_trans2degree*Xr(1,1:n_plot),'-b'); 
subplot(2,1,2); plot(const_trans2degree*qd(1,1:n_plot),'-r'); title('qd');
hold on 
plot(const_trans2degree*Xr(2,1:n_plot),'-b'); 

% Plot control signals
figure;
plot(T(1,1:n_plot),'-b'); title('u of link joint');





























































