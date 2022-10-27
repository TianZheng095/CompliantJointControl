% clc; close all; clear; 

%% Basic Parameters
N = 10;
Ts = 0.001; 
coe = 0.0001;

Inertial = coe*exJoint.I_l;
Inertial_inv = inv(Inertial);
M_bar = Inertial;
M_bar_inv = Inertial_inv;
K_b = exJoint.k_b;

D_bar = exJoint.I_m+exJoint.I_g;
D_bar = coe*D_bar;
D_bar_inv = inv(D_bar);



% Q_diag = [500;10;
%            50; 1;];
% R_diag = 5;
% Q = diag(Q_diag);
% R = diag(R_diag);


%% Initial set of manipulator
q_ini = deg2rad(0);
qd_ini = 0; 
q_bar_ini = [q_ini;qd_ini];

tau_ini = deg2rad(0);
taud_ini = 0; 
tau_bar_ini = [tau_ini;taud_ini];  


%% Reference Trajectory
% plot_ref = 1;

% amp_max = pi/2;
% % n_ref_2pi = 5000;
% n_ref_times = 5;
n_ref_time = 5000;
n_ini_stop = 5000;

% Xr = Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref);
yr = Get_y_ref_step(Ts, n_ini_stop,n_ref_time);

%% Parameters used for QP
% Nominal state model 
g = 9.81;
L = exJoint.len/100/2;
a21 = -(exJoint.m*g*L)/M_bar-exJoint.k_b/M_bar;
a23 = exJoint.k_b/M_bar;
a41 = exJoint.k_b/D_bar;
a43 = -exJoint.k_b/D_bar;
A = eye(4)+Ts*[0     1     0     0;
               a21   0     a23   0;
               0     0     0     1;
               a41   0     a43   0];
B = Ts*[0;
        0;
        0;
      D_bar_inv];

C = [1,0,0,0];
C2 = [0,1,0,0];


H_y = Formulate_N_RecurMat(N, A,B,C);%NxN

R = 1;

P_y0 = Formulate_N_PowerMatVector(0,N, A,C);%Nx4

P_y1 = Formulate_N_PowerMatVector(1,N, A,C);%Nx4

H_q_dot0 = Formulate_N_RecurMat(N, A,B,C2);%NxN

P_q_dot0 = Formulate_N_PowerMatVector(0,N, A,C2);%Nx4

P_q_dot1 = Formulate_N_PowerMatVector(1,N, A,C2);%Nx4

H = 2*(H_y'*H_y+R);


% H = R_tilde+B_tilde'*L_lev1*B_tilde;%9x9


%% Inequality constraints
% joint angle constraints
q1_max = deg2rad(114.59); 
% q1_max = deg2rad(63.03); 


q_max = q1_max;
q_min = -q_max;

% joint velocity constraints
qd1_max = deg2rad(114.59); 
% qd1_max = deg2rad(45.84); 


qd_max = qd1_max;
qd_min = -qd_max;

% joint toruqe constraints
I_bar = kron(tril(ones(N)),eye(1));%NxN

tau_max = 40000;
tau_min = -tau_max;
dtau_max = 20000;
dtau_min = -dtau_max;

tau_max_bar = tau_max*ones(N,1);
tau_min_bar = tau_min*ones(N,1);
dtau_max_bar = dtau_max*ones(N,1);
dtau_min_bar = dtau_min*ones(N,1);

% Matrix representation of inequality constraints

L11_tilde = P_y0;%NxN
L12_tilde = P_y1;%NxN
L21_tilde = P_q_dot0;%NxN
L22_tilde = P_q_dot1;%NxN
W1 = H_y;%NxN
W2 = H_q_dot0;%NxN


%% Parameters used for qpOASES
% H
H_QP = reshape(H,(N)^2,1);

% lb & ub
lb_QP = dtau_min_bar;
ub_QP = dtau_max_bar;

% with qd constraints
[m,n]=size([W1;W2;I_bar]);
A_QP = reshape([W1;W2;I_bar]',m*n,1);

lbA_QP_ini = [ repmat(q_min,N,1);
              repmat(qd_min,N,1);
                       tau_min_bar];
ubA_QP_ini = [ repmat(q_max,N,1);
              repmat(qd_max,N,1);
                       tau_max_bar];
                 
                 
%% Initialization for simulink
tau_sim_ini = 0;

q_sim_ini = q_ini;
q_bar_sim_ini = q_bar_ini;

theta_sim_ini = tau_ini;
tau_bar_sim_ini = tau_bar_ini;

X_bar_sim_ini = [q_bar_sim_ini;tau_bar_sim_ini];

T_run = Ts*(n_ini_stop+n_ref_time-N-5);



%%% End of file


















