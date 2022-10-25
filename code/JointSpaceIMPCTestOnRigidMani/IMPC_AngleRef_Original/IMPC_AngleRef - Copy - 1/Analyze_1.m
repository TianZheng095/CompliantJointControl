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
subplot(3,1,1); plot(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)),'-r'); title('e of q1');
subplot(3,1,2); plot(const_trans2degree*(q(2,1:n_plot)-Xr(2,1:n_plot)),'-r'); title('e of q2');
subplot(3,1,3); plot(const_trans2degree*(q(3,1:n_plot)-Xr(3,1:n_plot)),'-r'); title('e of q3'); 
figure;
subplot(3,1,1); plot(const_trans2degree*(qd(1,1:n_plot)-Xr(4,1:n_plot)),'-r'); title('e of qd1');
subplot(3,1,2); plot(const_trans2degree*(qd(2,1:n_plot)-Xr(5,1:n_plot)),'-r'); title('e of qd2');
subplot(3,1,3); plot(const_trans2degree*(qd(3,1:n_plot)-Xr(6,1:n_plot)),'-r'); title('e of qd3'); 

% Plot degree & degree velocity of joints & 
figure;
subplot(3,1,1); plot(const_trans2degree*q(1,1:n_plot),'-r'); title('q of 1st joint');
subplot(3,1,2); plot(const_trans2degree*q(2,1:n_plot),'-r'); title('q of 2nd joint'); 
subplot(3,1,3); plot(const_trans2degree*q(3,1:n_plot),'-r'); title('q of 3rd joint'); 
figure;
subplot(3,1,1); plot(const_trans2degree*qd(1,1:n_plot),'-b'); title('qd of 1st joint');
subplot(3,1,2); plot(const_trans2degree*qd(2,1:n_plot),'-b'); title('qd of 2nd joint');
subplot(3,1,3); plot(const_trans2degree*qd(3,1:n_plot),'-b'); title('qd of 3rd joint');

% Plot control signals
figure;
subplot(3,1,1); plot(T(1,1:n_plot),'-b'); title('u of 1st joint');
subplot(3,1,2); plot(T(2,1:n_plot),'-b'); title('u of 2nd joint');
subplot(3,1,3); plot(T(3,1:n_plot),'-b'); title('u of 3rd joint');




























































