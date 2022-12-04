%% Analyze results
clc; close all;

% Load test data
load('Data\q.mat'); load('Data\qd.mat'); load('Data\qdd.mat'); load('Data\T.mat'); 
q = q(2:end,:); qd = qd(2:end,:); qdd = qdd(2:end,:); T = T(2:end,:); 

% Basic parameters
n_plot = max(size(q));
const_trans2degree = 180/pi;

% Plot degree & degree velocity of joints & 
% figure;
f_degree_joints_error = figure(1);
% set(f_degree_joints_error,'visible','off');
subplot(3,1,1); plot(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)),'-r'); title('e of q');
subplot(3,1,2); plot(const_trans2degree*(qd(1,1:n_plot)-Xr(2,1:n_plot)),'-r'); title('e of qd');
subplot(3,1,3); plot(const_trans2degree*(qdd(1,1:n_plot)-joint_dd_ref(1:n_plot)),'-r'); title('e of qdd');

% Plot degree & degree velocity of joints & 
% figure;
f_degree_joints = figure(2);
% set(f_degree_joints,'visible','off');
subplot(3,1,1); plot(const_trans2degree*q(1,1:n_plot),'-r'); title('q');
hold on 
plot(const_trans2degree*Xr(1,1:n_plot),'-b'); 
subplot(3,1,2); plot(const_trans2degree*qd(1,1:n_plot),'-r'); title('qd');
hold on 
plot(const_trans2degree*Xr(2,1:n_plot),'-b'); 
subplot(3,1,3); plot(const_trans2degree*qdd(1,1:n_plot),'-r'); title('qdd');
hold on 
plot(const_trans2degree*joint_dd_ref(1:n_plot),'-b'); 

% Plot control signals
% figure;
f_tau = figure(3);
% set(f_tau,'visible','off');
plot(T(1,1:n_plot),'-b'); title('motor torque');


load('UsingTime_IMPC_Np10_Nc3.mat'); 
time = figure(4);
% set(time,'visible','off');
time_n_plot = max(size(UsingTime_IMPC_Np10_Nc3));
plot(UsingTime_IMPC_Np10_Nc3(2,2:time_n_plot));title('computing time');

% 
% 
% % error = sqrt(mean(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)).^2));
% error_max = max(abs(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot))));
% 
% if error_max<threashold
%     flag = 1;
% else
%     flag = 0;
% end
