% clc; close all; clear; 

%% Basic Parameters
N = 20;
Nc = 20;
Ts = 0.001; 


M_coe = 0.1;
M_bar = M_coe*1;
M_bar_inv = inv(M_bar);


Kb_coe = 1;
K_b = Kb_coe*362;


D_coe = 0.1;
D_bar = D_coe*0.598;
D_bar_inv = inv(D_bar);




Q_const_pos_error= 5000;
Q_const_vel_error= 10;
Q_const_theta_error = 0;
R_const = 0.01;


var_u = 0;
var_y = 0;

% % Linear viscous friction
% d_m = 0.0036;  %% Motor Damping [Nms/rad]
% d_g = 2.2000;  %% Gearbox damping [Nms/rad]
% d_l = 1.0000;  %% Torsion bar damping [Nms/rad]
% 
% % Linear internal viscous friction
% d_gl = 1.0000;  %% Torsion bar internal damping [Nms/rad] (not identified)

d_m_plus_d_g = 0;  
d_l = 0.0000;  
d_gl = 0.0000;

%% Initial set of manipulator
q_ini = deg2rad(0);
qd_ini = 0; 
q_bar_ini = [q_ini;qd_ini];

tau_ini = 0;  


%% Reference Trajectory
plot_ref = 1;

amp_max = pi/2;
n_ref_2pi = 5000;
n_ref_times = 5;
n_ini_stop = 5000;
mm = M_bar*(1/(K_b*Ts*Ts));

Xr= Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref,mm);


%% Parameters used for QP
% Nominal state model 
A1_a22 = 2-M_bar_inv*K_b*Ts*Ts;
% A1_a32 = D_bar_inv*Ts*Ts;
% A1_a33 = 2-D_bar_inv*Ts*Ts;
% A1 = [1    Ts            0;
%       0   A1_a22   M_bar_inv*K_b*Ts*Ts;
%       0   A1_a32       A1_a33];
A1 = [1    Ts            0;
      0   A1_a22   M_bar_inv*K_b*Ts*Ts;
      0    0             2];
A2 = [0    0    0;
      0   -1    0;
      0    0   -1];
B1 = [0;
      0;
      D_bar_inv*Ts];
  
A = [    A1       A2;
     eye(3) zeros(3)];
B = [        B1;
     zeros(3,1)];

A_tilde = Formulate_N_PowerMatVector(N, A);%6Nx6
B_tilde = Formulate_N_RecurMat_Nc(N,Nc, A,B);%6NxNc
R_tilde = Formulate_N_BlkdiagMat(Nc, R_const);%NxN


K1_bar = [1 0 0 0 0 0];%1x6
K2_bar = [0 1 0 0 0 0];%1x6
K3_bar = [0 0 1 0 0 0];


U1_bar = K1_bar'*Q_const_pos_error*K1_bar;%6x6
Q1_tilde = Formulate_N_BlkdiagMat(N, U1_bar);%6Nx6N
U2_bar = K2_bar'*Q_const_vel_error*K2_bar;%6x6
Q2_tilde = Formulate_N_BlkdiagMat(N, U2_bar);%6Nx6N
U3_bar = K3_bar'*Q_const_theta_error*K3_bar;%6x6
Q3_tilde = Formulate_N_BlkdiagMat(N, U3_bar);%6Nx6N

Ud1_bar = Q_const_pos_error*K1_bar;%1x6
QB1_tilde = Formulate_N_BlkdiagMat(N, Ud1_bar)*B_tilde;%Nx6N * 6NxN = NxNc
AQB1_tilde = A_tilde'*Q1_tilde*B_tilde;%6xNc
Ud2_bar = Q_const_vel_error*K2_bar;%1x6
QB2_tilde = Formulate_N_BlkdiagMat(N, Ud2_bar)*B_tilde;%Nx6N * 6NxN = NxNc
AQB2_tilde = A_tilde'*Q2_tilde*B_tilde;%6xNc
Ud3_bar = Q_const_theta_error*K3_bar;%1x6
QB3_tilde = Formulate_N_BlkdiagMat(N, Ud3_bar)*B_tilde;%Nx6N * 6NxN = NxNc
AQB3_tilde = A_tilde'*Q3_tilde*B_tilde;%6xNc


% H = R_tilde+B_tilde'*Q1_tilde*B_tilde+B_tilde'*Q2_tilde*B_tilde+B_tilde'*Q3_tilde*B_tilde;%NxN
H = R_tilde+B_tilde'*Q1_tilde*B_tilde+B_tilde'*Q2_tilde*B_tilde;%NxN
H = 2*H;



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
I_bar = kron(tril(ones(Nc)),1);%NxN

tau_max = 200;%50 is too small
tau_min = -tau_max;
dtau_max = 100;
dtau_min = -dtau_max;

tau_max_bar = tau_max*ones((Nc),1);
tau_min_bar = tau_min*ones((Nc),1);
dtau_max_bar = dtau_max*ones((Nc),1);
dtau_min_bar = dtau_min*ones((Nc),1);

% Matrix representation of inequality constraints
L1 = [eye(1) zeros(1,5)];
L2 = [zeros(1,1) eye(1) zeros(1,4)];

L1_bar = Formulate_N_BlkdiagMat(N, L1); %Nx6N
L2_bar = Formulate_N_BlkdiagMat(N, L2); %Nx6N

L1_tilde = L1_bar*A_tilde; %Nx6
L2_tilde = L2_bar*A_tilde; %Nx6
W1 = L1_bar*B_tilde;%NxNc
W2 = L2_bar*B_tilde;%NxNc


%% Parameters used for qpOASES
% H
H_QP = reshape(H,((Nc))^2,1);

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
                 
%% Parameters used for manipulator
B_mani = [0;
          0;
          0;
          D_bar_inv];


%% Initialization for simulink
tau_sim_ini = 0;
q_sim_ini = q_ini;
q_bar_sim_ini = q_bar_ini;
theta_d_sim_ini = q_ini;
X_bar_sim_ini = [q_bar_sim_ini;theta_d_sim_ini];

T_run = Ts*(n_ini_stop+n_ref_times*n_ref_2pi-N-5);



%%% End of file


















