% clc; close all; clear; 

%% Basic Parameters
N = 10;
Ts = 0.001; 
Inertial = exJoint_rigid.I_m+exJoint_rigid.I_g + exJoint_rigid.I_l;
Inertial_inv = inv(Inertial);
g_bar = diag([Inertial_inv;Inertial_inv;Inertial_inv]);
% g_bar = diag([14;32;80]);
% g_bar = diag([30;30;30]);
% M_bar_inv=diag([60;60;60]);
% Weighting matrix used for OCP
% Q_diag = [15000;15000;15000;100;100;100;
%            1000; 1000; 1000;  0;  0;  0];
% R_diag = [10;10;10];
Q_diag = [500;500;500;10;10;10;
           50; 50; 50;  1;  1;  1];
R_diag = [5;5;5];
Q = diag(Q_diag);
R = diag(R_diag);


%% Initial set of manipulator
q_ini = deg2rad([0;0;0]);
qd_ini = [0;0;0]; 
q_bar_ini = [q_ini;qd_ini];

tau_ini = [0;0;0];  


%% Reference Trajectory
plot_ref = 1;

amp_max = pi/2;
n_ref_2pi = 5000;
n_ref_times = 5;
n_ini_stop = 5000;

Xr = Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref);


%% Parameters used for QP
% Nominal state model 
A1 = [eye(3)   Ts*eye(3);
      zeros(3)  2*eye(3)];
A2 = blkdiag(zeros(3),-eye(3));
B1 = [zeros(3);
      g_bar*Ts];
  
A = [    A1       A2;
     eye(6) zeros(6)];
B = [        B1;
     zeros(6,3)];

A_tilde = Formulate_N_PowerMatVector(N-1, A);
B_tilde = Formulate_N_RecurMat(N-1, A,B);
Q_tilde = Formulate_N_BlkdiagMat(N-1, Q);
R_tilde = Formulate_N_BlkdiagMat(N-1, R);

QB_tilde = Q_tilde*B_tilde;
AQB_tilde = A_tilde'*Q_tilde*B_tilde;
H = R_tilde+B_tilde'*Q_tilde*B_tilde;


%% Inequality constraints
% joint angle constraints
q1_max = deg2rad(114.59); 
% q1_max = deg2rad(63.03); 
q2_max = q1_max;
q3_max = q1_max;

q_max = [q1_max;q2_max;q3_max];
q_min = -q_max;

% joint velocity constraints
qd1_max = deg2rad(114.59); 
% qd1_max = deg2rad(45.84); 
qd2_max = qd1_max;
qd3_max = qd1_max;

qd_max = [qd1_max;qd2_max;qd3_max];
qd_min = -qd_max;

% joint toruqe constraints
I_bar = kron(tril(ones(N-1)),eye(3));

tau_max = 4;
tau_min = -tau_max;
dtau_max = 2;
dtau_min = -dtau_max;

tau_max_bar = tau_max*ones(3*(N-1),1);
tau_min_bar = tau_min*ones(3*(N-1),1);
dtau_max_bar = dtau_max*ones(3*(N-1),1);
dtau_min_bar = dtau_min*ones(3*(N-1),1);

% Matrix representation of inequality constraints
L1 = [eye(3) zeros(3,9)];
L2 = [zeros(3,3) eye(3) zeros(3,6)];

L1_bar = Formulate_N_BlkdiagMat(N-1, L1); 
L2_bar = Formulate_N_BlkdiagMat(N-1, L2);

L1_tilde = L1_bar*A_tilde; 
L2_tilde = L2_bar*A_tilde; 
W1 = L1_bar*B_tilde;
W2 = L2_bar*B_tilde;


%% Parameters used for qpOASES
% H
H_QP = reshape(H,(3*(N-1))^2,1);

% lb & ub
lb_QP = dtau_min_bar;
ub_QP = dtau_max_bar;

% with qd constraints
[m,n]=size([W1;W2;I_bar]);
A_QP = reshape([W1;W2;I_bar]',m*n,1);

lbA_QP_ini = [ repmat(q_min,N-1,1);
              repmat(qd_min,N-1,1);
                       tau_min_bar];
ubA_QP_ini = [ repmat(q_max,N-1,1);
              repmat(qd_max,N-1,1);
                       tau_max_bar];
                 
                 
%% Initialization for simulink
tau_sim_ini = [0;0;0];
q_sim_ini = q_ini;
q_bar_sim_ini = q_bar_ini;

T_run = Ts*(n_ini_stop+n_ref_times*n_ref_2pi-N-5);



%%% End of file


















