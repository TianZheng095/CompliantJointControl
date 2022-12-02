%% Analyze results
clc; close all;

% Load test data
load('Np20_Nc10_q.mat'); load('Np20_Nc10_qd.mat'); load('Np20_Nc10_qdd.mat'); load('Np20_Nc10_T.mat'); 
Np20_Nc10_q = Np20_Nc10_q(2:end,:); Np20_Nc10_qd = Np20_Nc10_qd(2:end,:); Np20_Nc10_qdd = Np20_Nc10_qdd(2:end,:); Np20_Nc10_T = Np20_Nc10_T(2:end,:); 
load('Np20_Nc20_q.mat'); load('Np20_Nc20_qd.mat'); load('Np20_Nc20_qdd.mat'); load('Np20_Nc20_T.mat'); 
Np20_Nc20_q = Np20_Nc20_q(2:end,:); Np20_Nc20_qd = Np20_Nc20_qd(2:end,:); Np20_Nc20_qdd = Np20_Nc20_qdd(2:end,:); Np20_Nc20_T = Np20_Nc20_T(2:end,:); 
load('Np30_Nc10_q.mat'); load('Np30_Nc10_qd.mat'); load('Np30_Nc10_qdd.mat'); load('Np30_Nc10_T.mat'); 
Np30_Nc10_q = Np30_Nc10_q(2:end,:); Np30_Nc10_qd = Np30_Nc10_qd(2:end,:); Np30_Nc10_qdd = Np30_Nc10_qdd(2:end,:); Np30_Nc10_T = Np30_Nc10_T(2:end,:); 
load('Np30_Nc30_q.mat'); load('Np30_Nc30_qd.mat'); load('Np30_Nc30_qdd.mat'); load('Np30_Nc30_T.mat'); 
Np30_Nc30_q = Np30_Nc30_q(2:end,:); Np30_Nc30_qd = Np30_Nc30_qd(2:end,:); Np30_Nc30_qdd = Np30_Nc30_qdd(2:end,:); Np30_Nc30_T = Np30_Nc30_T(2:end,:); 


% Basic parameters
n_plot = min([max(size(Np20_Nc10_q)),max(size(Np20_Nc20_q)),max(size(Np30_Nc10_q)),max(size(Np30_Nc30_q))]);
t = 1:n_plot;
const_trans2degree = 180/pi;

% Plot degree & degree velocity of joints & 
% figure;
f_degree_joints_error = figure(1);
% set(f_degree_joints_error,'visible','off');
subplot(3,1,1); 
plot(t,[const_trans2degree*(Np20_Nc10_q(1,1:n_plot)-Xr(1,1:n_plot)); ...
    const_trans2degree*(Np20_Nc20_q(1,1:n_plot)-Xr(1,1:n_plot)); ...
    const_trans2degree*(Np30_Nc10_q(1,1:n_plot)-Xr(1,1:n_plot)); ...
    const_trans2degree*(Np30_Nc30_q(1,1:n_plot)-Xr(1,1:n_plot))]);
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30');  
title('e of q');
subplot(3,1,2); 
plot(t,[const_trans2degree*(Np20_Nc10_qd(1,1:n_plot)-Xr(2,1:n_plot)); ...
    const_trans2degree*(Np20_Nc20_qd(1,1:n_plot)-Xr(2,1:n_plot)); ...
    const_trans2degree*(Np30_Nc10_qd(1,1:n_plot)-Xr(2,1:n_plot)); ...
    const_trans2degree*(Np30_Nc30_qd(1,1:n_plot)-Xr(2,1:n_plot))]); 
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30');  
title('e of qd');
subplot(3,1,3); 
plot(t,[const_trans2degree*(Np20_Nc10_qdd(1,1:n_plot)-joint_dd_ref(1:n_plot)); ...
    const_trans2degree*(Np20_Nc20_qdd(1,1:n_plot)-joint_dd_ref(1:n_plot)); ...
    const_trans2degree*(Np30_Nc10_qdd(1,1:n_plot)-joint_dd_ref(1:n_plot)); ...
    const_trans2degree*(Np30_Nc30_qdd(1,1:n_plot)-joint_dd_ref(1:n_plot))]); 
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30');  
title('e of qdd');

% Plot degree & degree velocity of joints & 
% figure;
f_degree_joints = figure(2);
% set(f_degree_joints,'visible','off');
subplot(3,1,1); 
plot(t,[const_trans2degree*Np20_Nc10_q(1,1:n_plot); ...
    const_trans2degree*Np20_Nc20_q(1,1:n_plot); ...
    const_trans2degree*Np30_Nc10_q(1,1:n_plot); ...
    const_trans2degree*Np30_Nc30_q(1,1:n_plot); ...
    const_trans2degree*Xr(1,1:n_plot)]); 
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30','reference');  
title('q');
subplot(3,1,2); 
plot(t,[const_trans2degree*Np20_Nc10_qd(1,1:n_plot); ...
    const_trans2degree*Np20_Nc20_qd(1,1:n_plot); ...
    const_trans2degree*Np30_Nc10_qd(1,1:n_plot); ...
    const_trans2degree*Np30_Nc30_qd(1,1:n_plot); ...
    const_trans2degree*Xr(2,1:n_plot)]); 
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30','reference');  
title('qd');

subplot(3,1,3); 
plot(t,[const_trans2degree*Np20_Nc10_qdd(1,1:n_plot); ...
    const_trans2degree*Np20_Nc20_qdd(1,1:n_plot); ...
    const_trans2degree*Np30_Nc10_qdd(1,1:n_plot); ...
    const_trans2degree*Np30_Nc30_qdd(1,1:n_plot); ...
    const_trans2degree*joint_dd_ref(1:n_plot)]); 
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30','reference');  
title('qdd');


% Plot control signals
% figure;
f_tau = figure(3);
% set(f_tau,'visible','off');
plot(t,[Np20_Nc10_T(1,1:n_plot); ...
    Np20_Nc20_T(1,1:n_plot); ...
    Np30_Nc10_T(1,1:n_plot); ...
    Np30_Nc30_T(1,1:n_plot)]); 
legend('Np=20;Nc=10','Np=20;Nc=20','Np=30;Nc=10', 'Np=30;Nc=30','reference');  
title('motor torque');